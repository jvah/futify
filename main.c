#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include <event2/event.h>
#include <event2/thread.h>

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
	int ret;

	if (argc <= 2) {
		fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
		return -1;
	}

#if defined(EVTHREAD_USE_PTHREADS_IMPLEMENTED)
        if (evthread_use_pthreads()) {
                return -2;
        }
#elif defined(EVTHREAD_USE_WINDOWS_THREADS_IMPLEMENTED)
        if (evthread_use_windows_threads()) {
                return -3;
        }
#else
# error "The libevent threading support not available"
#endif

	signal(SIGINT, siginthandler);
	spotify = spotify_init(&error);
	if (!spotify) {
		fprintf(stderr, "Spotify failed to initialize\n");
		return -4;
	}
	spotify_login(spotify, argv[1], argv[2]);
	ret = spotify_run(spotify);
	if (ret) {
		fprintf(stderr, "Event loop returned %d\n", ret);
	}
	spotify_logout(spotify);
	spotify_destroy(spotify);

	return 0;
}
