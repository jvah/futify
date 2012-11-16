static void
stop_event_cb(evutil_socket_t fd, short events, void *arg)
{
	spotify_t *spotify = arg;
	event_base_loopbreak(spotify->event_base);
}

static void
process_event_cb(evutil_socket_t fd, short events, void *arg)
{
	spotify_t *spotify = arg;
	int next_timeout = 0;
	struct timeval timeout;

	do {
		sp_session_process_events(spotify->session, &next_timeout);
	} while (next_timeout == 0);

	timeout.tv_sec = next_timeout/1000;
	timeout.tv_usec = (next_timeout%1000)*1000;
	event_add(spotify->process_event, &timeout);
}

static void
register_event_callbacks(spotify_t *spotify)
{
	struct timeval forever;

	spotify->stop_event = event_new(spotify->event_base, SIGINT, EV_SIGNAL, stop_event_cb, spotify);
	event_add(spotify->stop_event, NULL);

	spotify->process_event = event_new(spotify->event_base, -1, 0, process_event_cb, spotify);
	event_add(spotify->process_event, NULL);
}
