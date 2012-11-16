all:
	gcc -g -framework libspotify -levent -o futify appkey.c spotify.c main.c

clean:
	rm -f futify
