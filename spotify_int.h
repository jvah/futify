#ifndef SPOTIFY_INT_H
#define SPOTIFY_INT_H

#include "spotify.h"
#include "spotify_events.h"

spotify_events_t *spotify_get_events(spotify_t *spotify);
void spotify_process_events(spotify_t *spotify, int *next_timeout);

#endif
