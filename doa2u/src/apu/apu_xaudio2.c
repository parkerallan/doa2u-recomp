/**
 * XAudio2 Audio Output Backend
 *
 * Provides low-latency audio output via XAudio2 (Win7+).
 * Called from the APU monitor frame to submit mixed samples.
 * Falls back gracefully if XAudio2 is unavailable.
 */

#define COBJMACROS
#include <windows.h>
#include <xaudio2.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "apu_xaudio2.h"

#pragma comment(lib, "xaudio2.lib")
#pragma comment(lib, "ole32.lib")

#define XA2_SAMPLE_RATE   48000
#define XA2_CHANNELS      2
#define XA2_BUF_SAMPLES   1024   /* ~21ms per submission */
#define XA2_NUM_BUFS      6   /* ~128 ms of slack; the APU thread now waits instead of dropping */
#define XA2_MOVIE_BUF_SAMPLES 2048
#define XA2_MOVIE_NUM_BUFS 4

static IXAudio2               *g_xa2 = NULL;
static IXAudio2MasteringVoice *g_xa2_master = NULL;
static IXAudio2SourceVoice    *g_xa2_source = NULL;
static int16_t                 g_xa2_bufs[XA2_NUM_BUFS][XA2_BUF_SAMPLES][2];
static int                     g_xa2_next_buf = 0;
static int                     g_xa2_initialized = 0;
static int                     g_xa2_frames_written = 0;
static IXAudio2SourceVoice    *g_xa2_movie_source = NULL;
static int16_t                 g_xa2_movie_bufs[XA2_MOVIE_NUM_BUFS][XA2_MOVIE_BUF_SAMPLES][2];
static int                     g_xa2_movie_next_buf = 0;

int xa2_init(void)
{
    HRESULT hr;
    WAVEFORMATEX wfx = { 0 };

    hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (FAILED(hr) && hr != (HRESULT)0x80010106 /* RPC_E_CHANGED_MODE */ && hr != S_FALSE) {
        return 0;
    }

    hr = XAudio2Create(&g_xa2, 0, XAUDIO2_DEFAULT_PROCESSOR);
    if (FAILED(hr) || !g_xa2) {
        return 0;
    }

    hr = IXAudio2_CreateMasteringVoice(g_xa2, &g_xa2_master,
        XA2_CHANNELS, XA2_SAMPLE_RATE, 0, NULL, NULL, 0);
    if (FAILED(hr)) {
        IXAudio2_Release(g_xa2);
        g_xa2 = NULL;
        return 0;
    }

    wfx.wFormatTag      = WAVE_FORMAT_PCM;
    wfx.nChannels       = XA2_CHANNELS;
    wfx.nSamplesPerSec  = XA2_SAMPLE_RATE;
    wfx.wBitsPerSample  = 16;
    wfx.nBlockAlign     = XA2_CHANNELS * 2;
    wfx.nAvgBytesPerSec = XA2_SAMPLE_RATE * wfx.nBlockAlign;

    hr = IXAudio2_CreateSourceVoice(g_xa2, &g_xa2_source,
        &wfx, 0, XAUDIO2_DEFAULT_FREQ_RATIO, NULL, NULL, NULL);
    if (FAILED(hr)) {
        g_xa2_master->lpVtbl->DestroyVoice(g_xa2_master);
        IXAudio2_Release(g_xa2);
        g_xa2 = NULL;
        return 0;
    }

    IXAudio2SourceVoice_Start(g_xa2_source, 0, XAUDIO2_COMMIT_NOW);

    g_xa2_next_buf = 0;
    g_xa2_initialized = 1;
    g_xa2_frames_written = 0;

    return 1;
}

void xa2_shutdown(void)
{
    if (!g_xa2_initialized) return;

    xa2_movie_stop();
    if (g_xa2_source) {
        IXAudio2SourceVoice_Stop(g_xa2_source, 0, XAUDIO2_COMMIT_NOW);
        IXAudio2SourceVoice_FlushSourceBuffers(g_xa2_source);
        g_xa2_source->lpVtbl->DestroyVoice(g_xa2_source);
        g_xa2_source = NULL;
    }
    if (g_xa2_master) {
        g_xa2_master->lpVtbl->DestroyVoice(g_xa2_master);
        g_xa2_master = NULL;
    }
    if (g_xa2) {
        IXAudio2_Release(g_xa2);
        g_xa2 = NULL;
    }

    g_xa2_initialized = 0;
}

/* Buffers currently queued on the source voice (-1 when inactive). */
int xa2_queued(void)
{
    XAUDIO2_VOICE_STATE state;
    if (!g_xa2_initialized || !g_xa2_source) return -1;
    IXAudio2SourceVoice_GetState(g_xa2_source, &state, XAUDIO2_VOICE_NOSAMPLESPLAYED);
    return (int)state.BuffersQueued;
}
int xa2_is_active(void)
{
    return g_xa2_initialized;
}

/* Submit a buffer of mixed samples to XAudio2.
 * Called from APU frame thread. Returns 1 if buffer was submitted. */
int xa2_submit_samples(const int16_t *samples, int num_samples)
{
    XAUDIO2_VOICE_STATE state;
    XAUDIO2_BUFFER xbuf;
    int idx;
    int copy_samples;

    if (!g_xa2_initialized || !g_xa2_source) return 0;

    IXAudio2SourceVoice_GetState(g_xa2_source, &state, XAUDIO2_VOICE_NOSAMPLESPLAYED);
    if ((int)state.BuffersQueued >= XA2_NUM_BUFS) return 0;

    idx = g_xa2_next_buf;
    copy_samples = (num_samples > XA2_BUF_SAMPLES) ? XA2_BUF_SAMPLES : num_samples;
    memcpy(g_xa2_bufs[idx], samples, copy_samples * XA2_CHANNELS * sizeof(int16_t));

    memset(&xbuf, 0, sizeof(xbuf));
    xbuf.AudioBytes = copy_samples * XA2_CHANNELS * sizeof(int16_t);
    xbuf.pAudioData = (const BYTE *)g_xa2_bufs[idx];

    IXAudio2SourceVoice_SubmitSourceBuffer(g_xa2_source, &xbuf, NULL);
    {   /* DOA3 DIAG: DOA3_WAVCAP=<path> appends the submitted 48 kHz s16 stereo
         * stream to a raw file (first 60 s) so the output can be inspected. */
        static FILE *s_cap = NULL; static int s_cap_tried = 0; static unsigned s_cap_samples = 0;
        if (!s_cap_tried) { const char *cp = getenv("DOA3_WAVCAP"); s_cap_tried = 1; if (cp) s_cap = fopen(cp, "wb"); }
        if (s_cap && s_cap_samples < 48000u * 130u) {
            fwrite(samples, XA2_CHANNELS * sizeof(int16_t), copy_samples, s_cap); fflush(s_cap);
            s_cap_samples += copy_samples;
        }
    }

    {   /* Output meter: is the APU mix actually carrying sound? Peak sample
         * and non-silent buffer count over each ~2 s window. */
        static DWORD s_next = 0; static unsigned s_bufs = 0, s_loud = 0, s_starved = 0; static int s_peak = 0;
        int i, n = copy_samples * XA2_CHANNELS;
        for (i = 0; i < n; i++) { int v = samples[i]; if (v < 0) v = -v; if (v > s_peak) s_peak = v; }
        s_bufs++; if (state.BuffersQueued == 0) s_starved++;
        if (s_peak > 64) s_loud++;
        if (GetTickCount() >= s_next) {
            s_next = GetTickCount() + 2000;
            
            s_bufs = s_loud = s_starved = 0; s_peak = 0;
        }
    }

    g_xa2_next_buf = (idx + 1) % XA2_NUM_BUFS;
    g_xa2_frames_written++;
    return 1;
}

int xa2_get_buffer_size(void)
{
    return XA2_BUF_SAMPLES;
}

int xa2_movie_start(void)
{
    WAVEFORMATEX wfx = { 0 };
    HRESULT hr;

    if (!g_xa2_initialized || !g_xa2 || g_xa2_movie_source)
        return g_xa2_movie_source != NULL;

    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = XA2_CHANNELS;
    wfx.nSamplesPerSec = XA2_SAMPLE_RATE;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = XA2_CHANNELS * sizeof(int16_t);
    wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;
    hr = IXAudio2_CreateSourceVoice(g_xa2, &g_xa2_movie_source,
        &wfx, 0, XAUDIO2_DEFAULT_FREQ_RATIO, NULL, NULL, NULL);
    if (FAILED(hr)) {
        g_xa2_movie_source = NULL;
        return 0;
    }
    g_xa2_movie_next_buf = 0;
    IXAudio2SourceVoice_Start(g_xa2_movie_source, 0, XAUDIO2_COMMIT_NOW);
    return 1;
}

int xa2_movie_submit(const int16_t *samples, int num_samples, int end_of_stream)
{
    XAUDIO2_VOICE_STATE state;
    XAUDIO2_BUFFER xbuf;
    int idx;

    if (!g_xa2_movie_source || !samples || num_samples <= 0 ||
        num_samples > XA2_MOVIE_BUF_SAMPLES)
        return 0;
    IXAudio2SourceVoice_GetState(g_xa2_movie_source, &state, XAUDIO2_VOICE_NOSAMPLESPLAYED);
    if (state.BuffersQueued >= XA2_MOVIE_NUM_BUFS)
        return 0;

    idx = g_xa2_movie_next_buf;
    memcpy(g_xa2_movie_bufs[idx], samples,
        (size_t)num_samples * XA2_CHANNELS * sizeof(int16_t));
    memset(&xbuf, 0, sizeof(xbuf));
    xbuf.AudioBytes = num_samples * XA2_CHANNELS * sizeof(int16_t);
    xbuf.pAudioData = (const BYTE *)g_xa2_movie_bufs[idx];
    if (end_of_stream)
        xbuf.Flags = XAUDIO2_END_OF_STREAM;
    if (FAILED(IXAudio2SourceVoice_SubmitSourceBuffer(g_xa2_movie_source, &xbuf, NULL)))
        return 0;
    g_xa2_movie_next_buf = (idx + 1) % XA2_MOVIE_NUM_BUFS;
    return 1;
}

uint64_t xa2_movie_samples_played(void)
{
    XAUDIO2_VOICE_STATE state;
    if (!g_xa2_movie_source)
        return 0;
    IXAudio2SourceVoice_GetState(g_xa2_movie_source, &state, 0);
    return state.SamplesPlayed;
}

void xa2_movie_stop(void)
{
    if (!g_xa2_movie_source)
        return;
    IXAudio2SourceVoice_Stop(g_xa2_movie_source, 0, XAUDIO2_COMMIT_NOW);
    IXAudio2SourceVoice_FlushSourceBuffers(g_xa2_movie_source);
    g_xa2_movie_source->lpVtbl->DestroyVoice(g_xa2_movie_source);
    g_xa2_movie_source = NULL;
}
