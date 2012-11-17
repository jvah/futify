#include <assert.h>
#include <event2/buffer.h>

#include "spotify_http_callbacks.h"

static void
handle_request(struct evhttp_request *req, void *arg)
{
	spotify_t *spotify = arg;
	struct evbuffer *buf = evbuffer_new();

	assert(spotify);

	evhttp_connection_set_timeout(evhttp_request_get_connection(req), 1);
	evhttp_add_header(evhttp_request_get_output_headers(req), "Server", "Futify");

	evhttp_send_reply(req, HTTP_NOTFOUND, "Not Found", buf);
}

void
spotify_http_callbacks(spotify_t *spotify, struct evhttp *evhttp)
{
	assert(spotify);
	assert(evhttp);

	evhttp_set_gencb(evhttp, &handle_request, spotify);
}
