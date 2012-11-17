all:
	gcc -g -framework libspotify -levent -levent_pthreads -o futify appkey.c spotify.c spotify_api.c spotify_events.c main.c

clean:
	rm -f futify
