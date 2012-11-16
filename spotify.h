#ifndef SPOTIFY_H
#define SPOTIFY_H

typedef struct spotify_s spotify_t;

spotify_t *spotify_init(const char *username, const char *password, int *error);
void spotify_destroy(spotify_t *spotify);

void spotify_run(spotify_t *spotify);
void spotify_stop(spotify_t *spotify);

#endif
