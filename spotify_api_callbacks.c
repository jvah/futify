static void
logged_in(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
logged_out(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
metadata_updated(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
connection_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
message_to_user(sp_session *session, const char *message)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
notify_main_thread(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static int
music_delivery(sp_session *session, const sp_audioformat *format, const void *frames, int num_frames)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
play_token_lost(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
log_message(sp_session *session, const char *data)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);

	fprintf(stderr, "%s", data);
}
static void
end_of_track(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
streaming_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
userinfo_updated(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
start_playback(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
stop_playback(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
get_audio_buffer_stats(sp_session *session, sp_audio_buffer_stats *stats)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
offline_status_updated(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
offline_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
credentials_blob_updated(sp_session *session, const char *blob)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
connectionstate_updated(sp_session *session)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
scrobble_error(sp_session *session, sp_error error)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}
static void
private_session_mode_changed(sp_session *session, bool is_private)
{
	spotify_t *spotify;

	assert(spotify);
	spotify = sp_session_userdata(session);
}

static sp_session_callbacks callbacks = {
	&logged_in,
	&logged_out,
	&metadata_updated,
	&connection_error,
	&message_to_user,
	&notify_main_thread,
	&music_delivery,
	&play_token_lost,
	&log_message,
	&end_of_track,
	&streaming_error,
	&userinfo_updated,
	&start_playback,
	&stop_playback,
	&get_audio_buffer_stats,
	&offline_status_updated,
	&offline_error,
	&credentials_blob_updated,
	&connectionstate_updated,
	&scrobble_error,
	&private_session_mode_changed
};


