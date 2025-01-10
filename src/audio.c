#include "../include/audio.h"
#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <alsa/asoundlib.h>

#define SAMPLE_RATE 44100

snd_pcm_t* global_handle;

void play_note(float frequency, float duration, float amplitude) {
  
  int err;
  snd_pcm_hw_params_t* params;
  unsigned int rate = SAMPLE_RATE;
  snd_pcm_uframes_t frames = 512;
  int channels = 1;
  int total_samples = (int)(SAMPLE_RATE * duration);
  short* buffer;
  float phase = 0.0f;
  float phase_increment = 2.0f*M_PI*frequency / SAMPLE_RATE;

  if ((err = snd_pcm_open(&global_handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
    fprintf(stderr, "Unable to open PCM device: %s\n", snd_strerror(err));
    exit(1);
  }

  snd_pcm_hw_params_alloca(&params);
  snd_pcm_hw_params_any(global_handle, params);
  snd_pcm_hw_params_set_access(global_handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);
  snd_pcm_hw_params_set_format(global_handle, params, SND_PCM_FORMAT_S16_LE);
  snd_pcm_hw_params_set_channels(global_handle, params, channels);
  snd_pcm_hw_params_set_rate_near(global_handle, params, &rate, NULL);
  snd_pcm_hw_params_set_period_size_near(global_handle, params, &frames, NULL);

  if ((err = snd_pcm_hw_params(global_handle, params)) < 0) {
    fprintf(stderr, "Unable to set HW parameters: %s\n", snd_strerror(err));
    exit(1);
  }

  buffer = (short *) malloc(frames * channels * sizeof(short));

  for (int i=0; i<total_samples; i++) {
    buffer[i%frames] = (short)(amplitude * 32767.0 * sin(phase));
    phase += phase_increment;
    if (i%frames == frames-1) {
      if ((err = snd_pcm_writei(global_handle, buffer, frames)) < 0) {
        snd_pcm_prepare(global_handle);
      }
    }
  }

  snd_pcm_drain(global_handle);
  snd_pcm_close(global_handle);
  free(buffer);
}