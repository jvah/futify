all:
	gcc -g -Wall -framework libspotify -levent -levent_pthreads -ljansson -o futify appkey.c spotify.c spotify_events.c spotify_session_callbacks.c spotify_http_callbacks.c main.c

clean:
	rm -f futify
