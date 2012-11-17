#ifndef SPOTIFY_H
#define SPOTIFY_H

typedef struct spotify_s spotify_t;

spotify_t *spotify_init(int *error);
void spotify_destroy(spotify_t *spotify);

void spotify_login(spotify_t *spotify, const char *username, const char *password);
void spotify_logout(spotify_t *spotify);

int spotify_run(spotify_t *spotify);
void spotify_stop(spotify_t *spotify);

void spotify_listen(spotify_t *spotify);
void spotify_unlisten(spotify_t *spotify);

#endif
