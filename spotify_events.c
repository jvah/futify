#include <signal.h>
#include <assert.h>

#include "spotify_int.h"
#include "spotify_events_int.h"

static void
stop_event_cb(evutil_socket_t fd, short event_flags, void *arg)
{
	spotify_t *spotify = arg;

	assert(spotify);
	spotify_stop(spotify);
}

static void
process_event_cb(evutil_socket_t fd, short event_flags, void *arg)
{
	spotify_t *spotify = arg;
	spotify_events_t *events;
	int next_timeout = 0;
	struct timeval timeout;

	assert(spotify);
	do {
		spotify_process_events(spotify, &next_timeout);
	} while (next_timeout == 0);

	timeout.tv_sec = next_timeout/1000;
	timeout.tv_usec = (next_timeout%1000)*1000;

	events = spotify_get_events(spotify);
	event_add(events->process_event, &timeout);
}

int
spotify_events_init(spotify_t *spotify, spotify_events_t *events, struct event_base *event_base)
{
	events->stop_event = event_new(event_base, SIGINT, EV_SIGNAL, stop_event_cb, spotify);
	event_add(events->stop_event, NULL);

	events->process_event = event_new(event_base, -1, 0, process_event_cb, spotify);
	event_add(events->process_event, NULL);
}

void
spotify_events_destroy(spotify_events_t *events)
{
}

void
spotify_events_register()
{
}

