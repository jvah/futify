static void
stop_event_cb(evutil_socket_t fd, short events, void *arg)
{
	spotify_t *spotify = arg;
	event_base_loopbreak(spotify->event_base);
}

static void
register_event_callbacks(spotify_t *spotify)
{
	struct timeval forever;

	/* This is a libevent hack, should be removed with libevent 2.1.
         * http://stackoverflow.com/questions/7645217/user-triggered-event-in-libevent */
	forever.tv_sec = 100000000;
	forever.tv_usec = 0;

	spotify->stop_event = event_new(spotify->event_base, -1, 0, stop_event_cb, spotify);
	event_add(spotify->stop_event, &forever);
}
