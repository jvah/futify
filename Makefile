all:
	gcc -g -framework libspotify -levent -levent_pthreads -o futify appkey.c spotify.c main.c

clean:
	rm -f futify
