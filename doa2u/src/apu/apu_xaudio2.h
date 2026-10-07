/**
 * XAudio2 Audio Output Backend
 */
#ifndef APU_XAUDIO2_H
#define APU_XAUDIO2_H

#include <stdint.h>

/* Initialize XAudio2. Returns 1 on success, 0 on failure. */
int xa2_init(void);

/* Shut down XAudio2 and release all resources. */
void xa2_shutdown(void);

/* Returns 1 if XAudio2 is active. */
int xa2_is_active(void);

/* Submit interleaved stereo 16-bit samples. Returns 1 if accepted. */
int xa2_submit_samples(const int16_t *samples, int num_samples);

/* Get the preferred buffer size in samples. */
int xa2_get_buffer_size(void);

/* Dedicated 48 kHz stereo voice for host-decoded movie audio. */
int xa2_movie_start(void);
int xa2_movie_submit(const int16_t *samples, int num_samples, int end_of_stream);
uint64_t xa2_movie_samples_played(void);
void xa2_movie_stop(void);

#endif /* APU_XAUDIO2_H */
