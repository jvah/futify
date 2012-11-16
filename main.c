#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include "spotify.h"

static spotify_t *spotify;

static void
siginthandler(int param)
{
	spotify_stop(spotify);
}

int
main(int argc, char *argv[])
{
	int error;

	if (argc <= 2) {
		fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
		return -1;
	}

	signal(SIGINT, siginthandler);
	spotify = spotify_init(argv[1], argv[2], &error);
	if (!spotify) {
		fprintf(stderr, "Spotify failed to initialize\n");
		return -2;
	}
	spotify_run(spotify);
	spotify_destroy(spotify);

	return 0;
}
