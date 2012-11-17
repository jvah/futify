#ifndef SPOTIFY_EVENTS_H
#define SPOTIFY_EVENTS_H

#include <event2/event.h>

#include "spotify.h"

typedef struct spotify_events_s spotify_events_t;

int spotify_events_init(spotify_t *spotify, spotify_events_t *events, struct event_base *event_base);
void spotify_events_destroy(spotify_events_t *events);

void spotify_events_register();

#endif
