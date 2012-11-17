#ifndef SPOTIFY_EVENTS_INT_H
#define SPOTIFY_EVENTS_INT_H

#include "spotify_events.h"

struct spotify_events_s {
	struct event *stop_event;
	struct event *process_event;
};

#endif
