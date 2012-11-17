#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "spotify_api.h"

/* We need access to spotify_get_events and events struct */
#include "spotify_int.h"
#include "spotify_events_int.h"

static void
logged_in(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
logged_out(sp_session *session)
{
	spotify_t *spotify;

	fprintf(stderr, "Log out successful...\n");
	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
metadata_updated(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
connection_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
message_to_user(sp_session *session, const char *message)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
notify_main_thread(sp_session *session)
{
	spotify_t *spotify;
	spotify_events_t *events;

	spotify = sp_session_userdata(session);
	assert(spotify);
	events = spotify_get_events(spotify);
	event_active(events->process_event, 0, 0);
}

static int
music_delivery(sp_session *session, const sp_audioformat *format, const void *frames, int num_frames)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
play_token_lost(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
log_message(sp_session *session, const char *data)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);

	fprintf(stderr, "%s", data);
}

static void
end_of_track(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
streaming_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
userinfo_updated(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
start_playback(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
stop_playback(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
get_audio_buffer_stats(sp_session *session, sp_audio_buffer_stats *stats)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
offline_status_updated(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
offline_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
credentials_blob_updated(sp_session *session, const char *blob)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
connectionstate_updated(sp_session *session)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
scrobble_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

static void
private_session_mode_changed(sp_session *session, bool is_private)
{
	spotify_t *spotify;

	spotify = sp_session_userdata(session);
	assert(spotify);
}

void
spotify_api_set_callbacks(sp_session_callbacks *callbacks)
{
	assert(callbacks);

	callbacks->logged_in = &logged_in;
	callbacks->logged_out = &logged_out;
	callbacks->metadata_updated = &metadata_updated;
	callbacks->connection_error = &connection_error;
	callbacks->message_to_user = &message_to_user;
	callbacks->notify_main_thread = &notify_main_thread;
	callbacks->music_delivery = &music_delivery;
	callbacks->play_token_lost = &play_token_lost;
	callbacks->log_message = &log_message;
	callbacks->end_of_track = &end_of_track;
	callbacks->streaming_error = &streaming_error;
	callbacks->userinfo_updated = &userinfo_updated;
	callbacks->start_playback = &start_playback;
	callbacks->stop_playback = &stop_playback;
	callbacks->get_audio_buffer_stats = &get_audio_buffer_stats;
	callbacks->offline_status_updated = &offline_status_updated;
	callbacks->offline_error = &offline_error;
	callbacks->credentials_blob_updated = &credentials_blob_updated;
	callbacks->connectionstate_updated = &connectionstate_updated;
	callbacks->scrobble_error = &scrobble_error;
	callbacks->private_session_mode_changed = &private_session_mode_changed;
}


