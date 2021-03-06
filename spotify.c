#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "spotify_int.h"
#include "spotify_events_int.h"
#include "spotify_session_callbacks.h"
#include "spotify_http_callbacks.h"

#include <event2/event.h>
#include <event2/http.h>

#define USER_AGENT "Futify"
#define VERSION "0.1"

struct spotify_s {
	struct event_base *event_base;
	spotify_events_t events;
	struct evhttp *evhttp;

	sp_session *session;
};

spotify_t *
spotify_init(int *error)
{
	spotify_t *spotify;
	sp_session_config config;
	sp_session_callbacks callbacks;
	sp_error sp_error;

	memset(&config, 0, sizeof(sp_session_config));
	memset(&sp_error, 0, sizeof(sp_error));

	if (error) *error = 0;
	spotify = calloc(1, sizeof(spotify_t));
	if (!spotify) {
		if (error) *error = 1;
		return NULL;
	}

	spotify->event_base = event_base_new();
	if (!spotify->event_base) {
		if (error) *error = 2;
		return NULL;
	}
	spotify_events_init(spotify, &spotify->events, spotify->event_base);

	/// The application key is specific to each project, and allows Spotify
	/// to produce statistics on how our service is used.
	extern const char g_appkey[];
	/// The size of the application key.
	extern const size_t g_appkey_size;

	// Always do this. It allows libspotify to check for
	// header/library inconsistencies.
	config.api_version = SPOTIFY_API_VERSION;

	// The path of the directory to store the cache. This must be specified.
	// Please read the documentation on preferred values.
	config.cache_location = "tmp";

	// The path of the directory to store the settings. 
	// This must be specified.
	// Please read the documentation on preferred values.
	config.settings_location = "tmp";

	// The key of the application. They are generated by Spotify,
	// and are specific to each application using libspotify.
	config.application_key = g_appkey;
	config.application_key_size = g_appkey_size;

	// This identifies the application using some
	// free-text string [1, 255] characters.
	config.user_agent = USER_AGENT" "VERSION;

	// Register the callbacks.
	spotify_session_callbacks(&callbacks);
	config.callbacks = &callbacks;

	// Set the userdata to our spotify handle
	config.userdata = spotify;

	sp_error = sp_session_create(&config, &spotify->session);
	if (sp_error != SP_ERROR_OK) {
		fprintf(stderr, "failed to create session: %s\n",
		                sp_error_message(sp_error));

		if (error) *error = 0x20;
		free(spotify);
		return NULL;
	}
	return spotify;
}

void
spotify_login(spotify_t *spotify, const char *username, const char *password)
{
	sp_error error;

	if (!spotify) {
		return;
	}
	error = sp_session_login(spotify->session, username, password, 0, NULL);
	if (error != SP_ERROR_OK) {
		fprintf(stderr, "failed to login: %s\n",
		                sp_error_message(error));
	}
}

void
spotify_logout(spotify_t *spotify)
{
	sp_connectionstate state;
	int next_timeout;
	sp_error error;

	if (!spotify) {
		return;
	}
	error = sp_session_logout(spotify->session);
	if (error != SP_ERROR_OK) {
		fprintf(stderr, "failed to logout: %s\n",
		                sp_error_message(error));
	}

	/* FIXME: Slightly ugly loop, but we are out of event queue... */
	state = sp_session_connectionstate(spotify->session);
	while (state != SP_CONNECTION_STATE_LOGGED_OUT) {
		/* Process libspotify event queue */
		spotify_process_events(spotify, &next_timeout);

		/* Sleep for 1ms and check connectionstate again */
		usleep(1000);
		state = sp_session_connectionstate(spotify->session);
	}
}

void
spotify_destroy(spotify_t *spotify)
{
	if (spotify) {
		sp_session_release(spotify->session);
		spotify_events_destroy(&spotify->events);
		event_base_free(spotify->event_base);
	}
	free(spotify);
}

int
spotify_run(spotify_t *spotify)
{
	if (!spotify) {
		return -1;
	}
	return event_base_dispatch(spotify->event_base);
}

void
spotify_stop(spotify_t *spotify)
{
	if (spotify) {
		event_base_loopbreak(spotify->event_base);
	}
}



spotify_events_t *
spotify_get_events(spotify_t *spotify)
{
	spotify_events_t *events = NULL;
	if (spotify) {
		events = &spotify->events;
	}
	return events;
}

void
spotify_process_events(spotify_t *spotify, int *next_timeout)
{
	do {
		sp_session_process_events(spotify->session, next_timeout);
	} while (*next_timeout == 0);
}

void
spotify_listen(spotify_t *spotify)
{
	if (!spotify || spotify->evhttp) {
		return;
	}

	spotify->evhttp = evhttp_new(spotify->event_base);
	spotify_http_callbacks(spotify, spotify->evhttp);
	if (evhttp_bind_socket(spotify->evhttp, "0.0.0.0", 9000) == -1) {
		fprintf(stderr, "Error binding to socket\n");
		spotify_unlisten(spotify);
	}
}

void
spotify_unlisten(spotify_t *spotify)
{
	if (!spotify || !spotify->evhttp) {
		return;
	}

	evhttp_free(spotify->evhttp);
	spotify->evhttp = NULL;
}
