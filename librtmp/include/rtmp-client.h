#ifndef _rtmp_client_h_
#define _rtmp_client_h_

#if defined(__cplusplus)
extern "C" {
#endif

	void* rtmp_client_create(const char* url);
	void rtmp_client_destroy(void* p);

	// @param[in] audio: AAC AudioSpecificConfig
	// @param[in] abytes: AudioSpecificConfig length in bytes
	// @param[in] video: H264 AVCDecoderConfigurationRecord
	// @param[in] vbytes: AVCDecoderConfigurationRecord length in bytes
	int rtmp_client_send_first(void* rtmp, const void* audio, unsigned int abytes, const void* video, unsigned int vbytes);

	// @param[in] video: H264 packet(include startcode(00 00 00 01))
	// @param[in] bytes: video length in bytes
	int rtmp_client_send_video(void* rtmp, const void* video, unsigned int bytes, long pts);

	// @param[in] audio: AAC audio packet(include AAC packet header(ADTS))
	// @param[in] bytes: video length in bytes
	int rtmp_client_send_audio(void* rtmp, const void* audio, unsigned int bytes, long pts);

	void rtmp_client_getserver(void* rtmp, char ip[65]);

	// create AudioSpecificConfig from AAC data
	int rtmp_client_make_AudioSpecificConfig(void* out, const void* audio, unsigned int bytes);

	// creaate AVCDecoderConfigurationRecord from H.264 sps/pps nalu(all nalu must start with 00 00 00 01)
	int rtmp_client_make_AVCDecoderConfigurationRecord(void* out, const void* video, unsigned int bytes);

#if defined(__cplusplus)
}
#endif
#endif /* !_rtmp_client_h_ */