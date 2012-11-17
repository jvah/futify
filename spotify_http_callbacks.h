#ifndef SPOTIFY_HTTP_CALLBACKS_H
#define SPOTIFY_HTTP_CALLBACKS_H

#include "spotify.h"
#include <event2/http.h>

void spotify_http_callbacks(spotify_t *spotify, struct evhttp *evhttp);

#endif
