all:
	gcc -g -framework libspotify -lmicrohttpd -o futify appkey.c spotify.c main.c

clean:
	rm -f futify
