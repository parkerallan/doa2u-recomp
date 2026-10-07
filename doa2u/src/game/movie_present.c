/**
 * Movie-surface presenter (see NOTES.md, "Opening movie").
 *
 * During Sofdec movie playback the game never calls D3DDevice_Present: on
 * Xbox it CSCs each frame straight into the front-buffer flip pair
 * (0x258C000/0x2A24000) and the display just scans them out. Our host
 * swapchain therefore stays black even though frames decode. This module
 * uploads the CSC'd 32bpp frame into a dynamic D3D11 texture, draws it as a
 * fullscreen triangle into the swapchain backbuffer (720x480 anamorphic ->
 * 640x480 window), and presents.
 *
 * DOA2U: the movie is selected when the guest opens a .sfd file
 * (doa3_movie_select, from the kernel file-open notification) and presented
 * once per guest frame by doa2u_movie_tick (D3DDevice_Swap / vblank wait).
 * The picture and the ADX track are decoded here, on the host, from the same
 * file the guest's Sofdec player reads.
 */
#define COBJMACROS
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "../apu/apu_xaudio2.h"

#define PL_MPEG_IMPLEMENTATION
#include "pl_mpeg.h"

#pragma comment(lib, "d3dcompiler.lib")



extern ID3D11Device        *d3d8_GetD3D11Device(void);
extern ID3D11DeviceContext *d3d8_GetD3D11Context(void);
extern ID3D11RenderTargetView *d3d8_GetDefaultRTV(void);
extern ID3D11Texture2D     *d3d8_GetGuestTexture(void);
extern UINT                 d3d8_GetBackbufferWidth(void);
extern UINT                 d3d8_GetBackbufferHeight(void);
extern void                 d3d8_PresentFrame(void);
extern void                 d3d8_RestoreDefaultTarget(void);

static ID3D11Texture2D          *s_tex;
static ID3D11ShaderResourceView *s_srv;
static ID3D11VertexShader       *s_vs;
static ID3D11PixelShader        *s_ps;
static ID3D11SamplerState       *s_smp;
static int s_w, s_h, s_failed;
static int s_host_stopped;
/* Set once the bundled decoder runs out of frames: the movie file is over.
 * doa3_pump_cri_servers uses it to complete the movie through the game's own
 * PLAYEND path when the guest Sofdec stalls and never publishes one. */
int g_doa3_host_movie_ended = 0;
static plm_video_t *s_host_video;
static unsigned char *s_host_frame;
static unsigned s_host_frames;

/* Decoder thread. The story endings are ~22 Mbit/s and pl_mpeg needs 25-35 ms
 * a frame for them -- a whole 30 fps frame period. Decoding them on the game
 * thread cut the pump to ~7 calls/s and the ending played in 5-frame jumps.
 * The thread decodes ahead into a ring; the game thread only picks the frame
 * the audio clock says is due. The slot behind `head` is the frame on screen
 * and is never written while queued frames exist, so the producer stops at
 * DEC_SLOTS - 1 queued frames. */
enum { DEC_SLOTS = 8, DEC_FRAME_SIZE = 720 * 480 * 4 };
static struct {
    HANDLE             thread;
    SRWLOCK            lock;
    CONDITION_VARIABLE room;
    unsigned char     *slot[DEC_SLOTS];
    unsigned           head, count;  /* queued frames, oldest at head */
    int                eof, quit;
} s_dec;

static DWORD WINAPI movie_decode_thread(LPVOID unused)
{
    (void)unused;
    for (;;) {
        plm_frame_t *frame;
        unsigned char *dst;
        AcquireSRWLockExclusive(&s_dec.lock);
        while (!s_dec.quit && s_dec.count >= DEC_SLOTS - 1)
            SleepConditionVariableSRW(&s_dec.room, &s_dec.lock, INFINITE, 0);
        if (s_dec.quit) { ReleaseSRWLockExclusive(&s_dec.lock); break; }
        dst = s_dec.slot[(s_dec.head + s_dec.count) % DEC_SLOTS];
        ReleaseSRWLockExclusive(&s_dec.lock);

        frame = plm_video_decode(s_host_video);
        if (frame)
            plm_frame_to_bgra(frame, dst, 720 * 4);

        AcquireSRWLockExclusive(&s_dec.lock);
        if (frame) s_dec.count++;
        else       s_dec.eof = 1;
        ReleaseSRWLockExclusive(&s_dec.lock);
        if (!frame) break;
    }
    return 0;
}

static int movie_decoder_start(void)
{
    for (int i = 0; i < DEC_SLOTS; i++)
        if (!s_dec.slot[i] && !(s_dec.slot[i] = (unsigned char *)malloc(DEC_FRAME_SIZE)))
            return 0;
    InitializeSRWLock(&s_dec.lock);
    InitializeConditionVariable(&s_dec.room);
    s_dec.head = s_dec.count = 0;
    s_dec.eof = s_dec.quit = 0;
    s_dec.thread = CreateThread(NULL, 0, movie_decode_thread, NULL, 0, NULL);
    return s_dec.thread != NULL;
}

/* Stop the decoder thread and release the decoder (movie over, skipped, or
 * replaced by the next one). */
static void movie_decoder_stop(void)
{
    if (s_dec.thread) {
        AcquireSRWLockExclusive(&s_dec.lock);
        s_dec.quit = 1;
        ReleaseSRWLockExclusive(&s_dec.lock);
        WakeAllConditionVariable(&s_dec.room);
        WaitForSingleObject(s_dec.thread, INFINITE);
        CloseHandle(s_dec.thread);
        s_dec.thread = NULL;
    }
    if (s_host_video) { plm_video_destroy(s_host_video); s_host_video = NULL; }
}
static int16_t *s_host_audio;
static uint32_t s_host_audio_samples;
static uint32_t s_host_audio_submitted;
static int s_host_audio_active;
static int s_host_audio_done;             /* voice played its END_OF_STREAM */
static uint64_t s_host_audio_last_played;
static LARGE_INTEGER s_host_start, s_host_frequency;

/* The .sfd the game is starting (file name only, from sub_0009DF60's index)
 * and whether the presenter still has to be re-armed for it. The presenter used to be one-shot and
 * hardcoded to ninja.sfd: after the intro it stayed stopped, and the intro's
 * g_doa3_host_movie_ended made doa3_pump_cri_servers force PLAYEND on the
 * story ending the moment it reached PLAYING -- the ending was skipped and
 * the game went straight back to the title. */
static char s_movie_name[MAX_PATH] = "";
static int  s_movie_pending;
static int  s_movie_active;           /* a movie is selected and not finished */

/* guest_path is the Xbox path the game opened ("d:\doa2\doa2_op.sfd"); the
 * presenter reads assets\<path after the drive>. */
void doa3_movie_select(const char *guest_path)
{
    const char *name = guest_path, *p;
    for (p = guest_path; *p; p++)
        if (*p == ':') name = p + 1;
    while (*name == '\\' || *name == '/') name++;
    if (s_movie_active && _stricmp(s_movie_name, name) == 0)
        return;                       /* the guest reopening the file it plays */
    extern void movie_prep_start(const char *name);
    snprintf(s_movie_name, sizeof s_movie_name, "%s", name);
    s_movie_pending = 1;
    s_movie_active = 1;
    g_doa3_host_movie_ended = 0;      /* the previous movie's end is not this one's */
    movie_prep_start(s_movie_name);   /* read + decode in the background now */
    fprintf(stderr, "[HOSTFMV] selected %s\n", s_movie_name);
    fflush(stderr);
}

/* The guest movie handle just entered PLAYING: if a new movie was started
 * since the last one finished, restart the presenter on it. Done here rather
 * than at start time so a movie that never reaches PLAYING cannot leave the
 * presenter owning (blanking) the screen. */
void doa3_movie_arm(void)
{
    if (!s_movie_pending) return;
    s_movie_pending = 0;
    if (!s_host_stopped) return;      /* first movie: presenter is still fresh */
    movie_decoder_stop();
    s_host_frame = NULL;
    /* Fresh voice: a movie that played to its end leaves its voice alive,
     * and xa2_movie_start would reuse it with SamplesPlayed still counting
     * from the previous movie -- the video clock started minutes ahead and
     * the next movie raced to catch up. */
    xa2_movie_stop();
    free(s_host_audio); s_host_audio = NULL;
    s_host_audio_samples = s_host_audio_submitted = 0;
    s_host_audio_active = 0;
    s_host_audio_done = 0; s_host_audio_last_played = 0;
    s_host_frames = 0;
    g_doa3_host_movie_ended = 0;
    s_host_stopped = 0;
}

static const char s_hlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct V { float4 p : SV_Position; float2 uv : TEXCOORD0; };\n"
    "V vsmain(uint id : SV_VertexID) {\n"
    "  V o; float2 uv = float2((id << 1) & 2, id & 2);\n"
    "  o.p = float4(uv * float2(2, -2) + float2(-1, 1), 0, 1); o.uv = uv; return o;\n"
    "}\n"
    "float4 psmain(V i) : SV_Target { return float4(t.Sample(s, i.uv).rgb, 1); }\n";

static int movie_present_init(ID3D11Device *dev, int w, int h)
{
    ID3DBlob *vsb = NULL, *psb = NULL, *err = NULL;
    if (FAILED(D3DCompile(s_hlsl, sizeof(s_hlsl) - 1, "movie_vs", NULL, NULL,
                          "vsmain", "vs_4_0", 0, 0, &vsb, &err)) ||
        FAILED(D3DCompile(s_hlsl, sizeof(s_hlsl) - 1, "movie_ps", NULL, NULL,
                          "psmain", "ps_4_0", 0, 0, &psb, &err))) {
        fprintf(stderr, "[MVPRES] shader compile failed: %s\n",
                err ? (const char *)ID3D10Blob_GetBufferPointer(err) : "?");
        fflush(stderr);
        return 0;
    }
    if (FAILED(ID3D11Device_CreateVertexShader(dev,
            ID3D10Blob_GetBufferPointer(vsb), ID3D10Blob_GetBufferSize(vsb),
            NULL, &s_vs)) ||
        FAILED(ID3D11Device_CreatePixelShader(dev,
            ID3D10Blob_GetBufferPointer(psb), ID3D10Blob_GetBufferSize(psb),
            NULL, &s_ps)))
        return 0;
    ID3D10Blob_Release(vsb);
    ID3D10Blob_Release(psb);

    D3D11_TEXTURE2D_DESC td;
    memset(&td, 0, sizeof(td));
    td.Width = w; td.Height = h;
    td.MipLevels = 1; td.ArraySize = 1;
    td.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DYNAMIC;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    td.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    if (FAILED(ID3D11Device_CreateTexture2D(dev, &td, NULL, &s_tex)))
        return 0;
    if (FAILED(ID3D11Device_CreateShaderResourceView(dev,
            (ID3D11Resource *)s_tex, NULL, &s_srv)))
        return 0;

    D3D11_SAMPLER_DESC sd;
    memset(&sd, 0, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = sd.AddressV = sd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    if (FAILED(ID3D11Device_CreateSamplerState(dev, &sd, &s_smp)))
        return 0;

    s_w = w; s_h = h;
    fprintf(stderr, "[MVPRES] initialized (%dx%d -> window)\n", w, h);
    fflush(stderr);
    return 1;
}

static unsigned s_frames = 0;

static int movie_extract_streams(const char *path, uint8_t **video, size_t *video_size,
                                 uint8_t **audio, size_t *audio_size)
{
    FILE *file = fopen(path, "rb");
    uint8_t *input = NULL, *video_output = NULL, *audio_output = NULL;
    long file_size;
    size_t input_size, read_size, position = 0;
    size_t video_output_size = 0, audio_output_size = 0;

    if (!file || fseek(file, 0, SEEK_END) != 0 ||
        (file_size = ftell(file)) <= 0 || fseek(file, 0, SEEK_SET) != 0)
        goto fail;
    input_size = (size_t)file_size;
    input = (uint8_t *)malloc(input_size);
    video_output = (uint8_t *)malloc(input_size);
    audio_output = (uint8_t *)malloc(input_size);
    if (!input || !video_output || !audio_output)
        goto fail;
    read_size = fread(input, 1, input_size, file);
    fclose(file);
    file = NULL;
    if (read_size != input_size)
        goto fail;

    while (position + 6 <= input_size) {
        size_t packet_end, payload;
        uint8_t stream_id;
        while (position + 3 < input_size &&
               (input[position] != 0 || input[position + 1] != 0 ||
                input[position + 2] != 1))
            position++;
        if (position + 6 > input_size)
            break;
        stream_id = input[position + 3];
        if (stream_id != 0xE0 && stream_id != 0xC0) {
            if (stream_id == 0xBA) {
                if ((input[position + 4] & 0xC0) == 0x40) {
                    if (position + 14 > input_size)
                        goto fail;
                    position += 14u + (input[position + 13] & 7u);
                } else {
                    position += 12;
                }
            } else if (stream_id == 0xB9) {
                position += 4;
            } else {
                packet_end = position + 6u +
                    ((size_t)input[position + 4] << 8) + input[position + 5];
                if (packet_end > input_size || packet_end <= position + 6)
                    goto fail;
                position = packet_end;
            }
            continue;
        }
        packet_end = position + 6u +
            ((size_t)input[position + 4] << 8) + input[position + 5];
        if (packet_end > input_size || packet_end <= position + 6)
            goto fail;
        payload = position + 6;
        while (payload < packet_end && input[payload] == 0xFF)
            payload++;
        if (payload + 1 < packet_end && (input[payload] & 0xC0) == 0x40)
            payload += 2;
        if (payload >= packet_end)
            goto fail;
        if ((input[payload] & 0xF0) == 0x20)
            payload += 5;
        else if ((input[payload] & 0xF0) == 0x30)
            payload += 10;
        else if (input[payload] == 0x0F)
            payload++;
        else if ((input[payload] & 0xC0) == 0x80 && payload + 2 < packet_end)
            payload += 3u + input[payload + 2];
        else
            goto fail;
        if (payload > packet_end)
            goto fail;
        if (stream_id == 0xE0) {
            memcpy(video_output + video_output_size, input + payload, packet_end - payload);
            video_output_size += packet_end - payload;
        } else {
            memcpy(audio_output + audio_output_size, input + payload, packet_end - payload);
            audio_output_size += packet_end - payload;
        }
        position = packet_end;
    }
    free(input);
    if (!video_output_size) {
        free(video_output);
        free(audio_output);
        return 0;
    }
    *video = video_output;
    *video_size = video_output_size;
    *audio = audio_output;
    *audio_size = audio_output_size;
    return 1;

fail:
    if (file)
        fclose(file);
    free(input);
    free(video_output);
    free(audio_output);
    return 0;
}

static uint16_t read_be16(const uint8_t *data)
{
    return ((uint16_t)data[0] << 8) | data[1];
}

static uint32_t read_be32(const uint8_t *data)
{
    return ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) |
           ((uint32_t)data[2] << 8) | data[3];
}

static int16_t clamp_sample(int sample)
{
    if (sample < -32768) return -32768;
    if (sample > 32767) return 32767;
    return (int16_t)sample;
}

static int movie_decode_adx(const uint8_t *data, size_t size,
                            int16_t **pcm, uint32_t *sample_count)
{
    uint32_t samples, rate, frame_count;
    uint16_t data_offset, highpass;
    uint8_t channels, block_size;
    size_t position;
    int history[2][2] = { 0 };
    int coefficient1, coefficient2;
    double x, y, z;
    int16_t *output;

    if (size < 24 || read_be16(data) != 0x8000 || data[4] != 3 ||
        data[6] != 4 || data[7] != 2)
        return 0;
    data_offset = read_be16(data + 2);
    block_size = data[5];
    channels = data[7];
    rate = read_be32(data + 8);
    samples = read_be32(data + 12);
    highpass = read_be16(data + 16);
    position = (size_t)data_offset + 4;
    frame_count = (samples + 31) / 32;
    if (rate != 48000 || block_size != 18 || position > size ||
        (size - position) / (block_size * channels) < frame_count)
        return 0;

    output = (int16_t *)malloc((size_t)samples * channels * sizeof(int16_t));
    if (!output)
        return 0;
    x = sqrt(2.0) - cos(2.0 * 3.14159265358979323846 * highpass / rate);
    y = sqrt(2.0) - 1.0;
    z = (x - sqrt((x + y) * (x - y))) / y;
    coefficient1 = (int)(z * 2.0 * 4096.0 + 0.5);
    coefficient2 = (int)(-z * z * 4096.0 - 0.5);

    for (uint32_t frame = 0; frame < frame_count; frame++) {
        for (unsigned channel = 0; channel < channels; channel++) {
            const uint8_t *block = data + position +
                ((size_t)frame * channels + channel) * block_size;
            int scale = read_be16(block);
            for (unsigned index = 0; index < 32; index++) {
                int nibble = (index & 1) ? (block[2 + index / 2] & 15) :
                                           (block[2 + index / 2] >> 4);
                int sample;
                uint32_t output_index = frame * 32 + index;
                if (nibble >= 8) nibble -= 16;
                sample = nibble * scale +
                    ((coefficient1 * history[channel][0] +
                      coefficient2 * history[channel][1]) >> 12);
                sample = clamp_sample(sample);
                history[channel][1] = history[channel][0];
                history[channel][0] = sample;
                if (output_index < samples)
                    output[(size_t)output_index * channels + channel] = (int16_t)sample;
            }
        }
    }
    *pcm = output;
    *sample_count = samples;
    return 1;
}

static void movie_queue_audio(void)
{
    while (s_host_audio_active && s_host_audio_submitted < s_host_audio_samples) {
        uint32_t remaining = s_host_audio_samples - s_host_audio_submitted;
        int count = remaining > 2048 ? 2048 : (int)remaining;
        int end = s_host_audio_submitted + count == s_host_audio_samples;
        if (!xa2_movie_submit(s_host_audio + (size_t)s_host_audio_submitted * 2,
                              count, end))
            break;
        s_host_audio_submitted += count;
    }
    if (s_host_audio_submitted == s_host_audio_samples) {
        free(s_host_audio);
        s_host_audio = NULL;
    }
}

/* Movie preparation off the game thread. Reading a 150-245 MB ending,
 * demuxing it and decoding its whole ADX track used to happen inside the
 * first movie_host_frame call, on the game thread -- the stall at the start
 * of every story ending. doa3_movie_select starts it the moment the game
 * calls its movie starter; by PLAYING it is done or nearly so. */
static struct {
    HANDLE   thread;
    char     name[MAX_PATH];
    char     asset[MAX_PATH];
    int      ok;
    uint8_t *video;
    size_t   video_size;
    int16_t *pcm;
    uint32_t samples;
    int      pcm_ok;
} s_prep;

static DWORD WINAPI movie_prep_thread(LPVOID unused)
{
    char paths[1][MAX_PATH];
    uint8_t *audio = NULL;
    size_t audio_size = 0;
    (void)unused;
    snprintf(paths[0], MAX_PATH, "assets\\%s", s_prep.name);
    for (int i = 0; i < 1 && !s_prep.ok; i++) {
        if (GetFileAttributesA(paths[i]) == INVALID_FILE_ATTRIBUTES) continue;
        snprintf(s_prep.asset, MAX_PATH, "%s", paths[i]);
        s_prep.ok = movie_extract_streams(paths[i], &s_prep.video, &s_prep.video_size,
                                          &audio, &audio_size);
    }
    if (s_prep.ok)
        s_prep.pcm_ok = movie_decode_adx(audio, audio_size, &s_prep.pcm, &s_prep.samples);
    free(audio);
    return 0;
}

static void movie_prep_discard(void)
{
    if (s_prep.thread) {
        WaitForSingleObject(s_prep.thread, INFINITE);
        CloseHandle(s_prep.thread);
    }
    free(s_prep.video);
    free(s_prep.pcm);
    memset(&s_prep, 0, sizeof s_prep);
}

void movie_prep_start(const char *name)
{
    movie_prep_discard();
    snprintf(s_prep.name, sizeof s_prep.name, "%s", name);
    s_prep.thread = CreateThread(NULL, 0, movie_prep_thread, NULL, 0, NULL);
    if (!s_prep.thread)
        movie_prep_thread(NULL);          /* no thread: prepare inline */
}

/* Wait for the preparation of `name` to finish; 1 if its streams are ready. */
static int movie_prep_take(const char *name)
{
    if (_stricmp(s_prep.name, name) != 0)
        movie_prep_start(name);
    if (s_prep.thread) {
        WaitForSingleObject(s_prep.thread, INFINITE);
        CloseHandle(s_prep.thread);
        s_prep.thread = NULL;
    }
    return s_prep.ok;
}

static const void *movie_host_frame(void)
{
    enum { WIDTH = 720, HEIGHT = 480 };
    if (s_host_stopped)
        return NULL;
    if (!s_host_video) {
        plm_buffer_t *video_buffer;
        if (!movie_prep_take(s_movie_name)) {
            fprintf(stderr, "[HOSTFMV] %s video stream not found\n", s_movie_name);
            movie_prep_discard();
            s_host_stopped = 1;
            return NULL;
        }
        video_buffer = plm_buffer_create_with_memory(s_prep.video, s_prep.video_size, TRUE);
        s_prep.video = NULL;              /* owned by the buffer now */
        s_host_video = plm_video_create_with_buffer(video_buffer, TRUE);
        if (!s_host_video || !plm_video_has_header(s_host_video) ||
            plm_video_get_width(s_host_video) != WIDTH ||
            plm_video_get_height(s_host_video) != HEIGHT ||
            !movie_decoder_start()) {
            fprintf(stderr, "[HOSTFMV] decoder startup failed\n");
            movie_decoder_stop();
            movie_prep_discard();
            s_host_stopped = 1;
            return NULL;
        }
        /* Let the first frame land before the audio clock starts, as when
         * it was decoded inline here. */
        for (int i = 0; i < 500; i++) {
            int ready;
            AcquireSRWLockShared(&s_dec.lock);
            ready = s_dec.count || s_dec.eof;
            ReleaseSRWLockShared(&s_dec.lock);
            if (ready) break;
            Sleep(1);
        }
        QueryPerformanceFrequency(&s_host_frequency);
        QueryPerformanceCounter(&s_host_start);
        if (s_prep.pcm_ok && xa2_movie_start()) {
            s_host_audio = s_prep.pcm;
            s_host_audio_samples = s_prep.samples;
            s_prep.pcm = NULL;            /* owned by the presenter now */
            s_host_audio_active = 1;
            movie_queue_audio();
            fprintf(stderr, "[HOSTFMV] ADX audio started (%u samples, 48 kHz stereo)\n",
                s_host_audio_samples);
        } else {
            fprintf(stderr, "[HOSTFMV] ADX audio unavailable; using video clock\n");
        }
        fprintf(stderr, "[HOSTFMV] embedded presenter streaming %s at %.2f fps\n",
            s_prep.asset, plm_video_get_framerate(s_host_video));
        fflush(stderr);
        movie_prep_discard();
    }
    {
        LARGE_INTEGER now;
        unsigned target;
        movie_queue_audio();
        QueryPerformanceCounter(&now);
        if (s_host_audio_active) {
            uint64_t played = xa2_movie_samples_played();
            /* XAudio2 resets SamplesPlayed to 0 after END_OF_STREAM; treat that as audio done so
             * the video tail still plays and the movie ends. */
            if (s_host_audio_submitted >= s_host_audio_samples &&
                played < s_host_audio_last_played)
                s_host_audio_done = 1;
            s_host_audio_last_played = played;
            target = (s_host_audio_done || played >= s_host_audio_samples) ? UINT_MAX :
                (unsigned)(played * 30 / 48000);
        } else
            target = (unsigned)(((now.QuadPart - s_host_start.QuadPart) * 30) /
                                s_host_frequency.QuadPart);
        {
            int popped = 0, ended;
            AcquireSRWLockExclusive(&s_dec.lock);
            while (s_host_frames <= target && s_dec.count) {
                s_host_frame = s_dec.slot[s_dec.head];
                s_dec.head = (s_dec.head + 1) % DEC_SLOTS;
                s_dec.count--;
                s_host_frames++;
                popped = 1;
            }
            ended = s_host_frames <= target && !s_dec.count && s_dec.eof;
            ReleaseSRWLockExclusive(&s_dec.lock);
            if (popped)
                WakeConditionVariable(&s_dec.room);
            if (ended) {
                fprintf(stderr, "[HOSTFMV] presenter ended at frame %u\n", s_host_frames);
                fflush(stderr);
                movie_decoder_stop();
                s_host_stopped = 1;
                g_doa3_host_movie_ended = 1;
            }
        }
    }
    return s_host_frames ? s_host_frame : NULL;
}

static void movie_upload(ID3D11DeviceContext *ctx, const void *src, int pitch)
{
    D3D11_MAPPED_SUBRESOURCE map;
    if (FAILED(ID3D11DeviceContext_Map(ctx, (ID3D11Resource *)s_tex, 0,
                                       D3D11_MAP_WRITE_DISCARD, 0, &map)))
        return;
    for (int y = 0; y < s_h; y++)
        memcpy((char *)map.pData + (size_t)y * map.RowPitch,
               (const char *)src + (size_t)y * pitch, (size_t)s_w * 4);
    ID3D11DeviceContext_Unmap(ctx, (ID3D11Resource *)s_tex, 0);
}

/* Redraw the last uploaded movie frame and present. Called from the server
 * pump (~60Hz) so the window keeps showing the movie instead of reverting
 * to black when no new frame arrives (decode is slower than realtime, and
 * after a stall/teardown nothing else presents). */
/* One-shot capture of the presented backbuffer to a 24-bit BMP, so the actual
 * rendered frame can be inspected without screen capture. */
/* Hand the screen back to the game when the movie ends.
 *
 * Nothing here presented after the movie, but nothing cleared either, so the
 * swapchain kept flipping between the buffers still holding the last decoded
 * movie frames -- which looks like the FMV replaying at random in low quality.
 * Blank every buffer once and stop the presenter so the game owns the screen. */
/* True while the host presenter still owns the screen (the intro movie is
 * being played by this module, not by the guest's own draws). Guest geometry
 * submitted in that window must not be composited over the movie. */
int doa3_movie_host_owns_screen(void)
{
    return s_movie_active && !s_host_stopped;
}

/* Draw the uploaded movie frame into the guest frame buffer, inside a centred
 * 4:3 area. The guest target is 16:9 in widescreen mode; the movie is 4:3 and
 * must not be stretched, so it is pillarboxed there and fills the target at
 * 4:3. The present path then scales the guest frame into the window. The
 * translator's full-target viewport is put back afterwards. */
static void movie_draw_to_guest(ID3D11DeviceContext *ctx)
{
    ID3D11RenderTargetView *rtv = d3d8_GetDefaultRTV();
    const FLOAT black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    FLOAT gw = (FLOAT)d3d8_GetBackbufferWidth(), gh = (FLOAT)d3d8_GetBackbufferHeight();
    D3D11_VIEWPORT vp;
    if (!rtv || gw <= 0.0f || gh <= 0.0f) return;
    vp.Height = gh;
    vp.Width = gh * 4.0f / 3.0f;
    if (vp.Width > gw) vp.Width = gw;
    vp.TopLeftX = (FLOAT)(int)((gw - vp.Width) * 0.5f);
    vp.TopLeftY = 0.0f;
    vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;

    ID3D11DeviceContext_OMSetRenderTargets(ctx, 1, &rtv, NULL);
    ID3D11DeviceContext_ClearRenderTargetView(ctx, rtv, black);
    ID3D11DeviceContext_RSSetViewports(ctx, 1, &vp);
    ID3D11DeviceContext_IASetInputLayout(ctx, NULL);
    ID3D11DeviceContext_IASetPrimitiveTopology(ctx,
        D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    ID3D11DeviceContext_VSSetShader(ctx, s_vs, NULL, 0);
    ID3D11DeviceContext_PSSetShader(ctx, s_ps, NULL, 0);
    ID3D11DeviceContext_PSSetShaderResources(ctx, 0, 1, &s_srv);
    ID3D11DeviceContext_PSSetSamplers(ctx, 0, 1, &s_smp);
    ID3D11DeviceContext_Draw(ctx, 3, 0);
}

static void movie_restore_guest_viewport(ID3D11DeviceContext *ctx)
{
    D3D11_VIEWPORT vp;
    vp.TopLeftX = 0.0f; vp.TopLeftY = 0.0f;
    vp.Width = (FLOAT)d3d8_GetBackbufferWidth();
    vp.Height = (FLOAT)d3d8_GetBackbufferHeight();
    vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;
    ID3D11DeviceContext_RSSetViewports(ctx, 1, &vp);
}

/* True only while the presenter has actually started showing a movie and
 * has not finished: the game leaving the movie early (START during the
 * intro) must stop it, but the same game path runs before any movie exists
 * and must not pre-stop a presenter that has not begun. */
int doa3_movie_presenter_active(void)
{
    return s_tex != NULL && !s_host_stopped;
}

void doa3_movie_present_finish(void)
{
    ID3D11DeviceContext *ctx = d3d8_GetD3D11Context();
    ID3D11RenderTargetView *rtv = d3d8_GetDefaultRTV();
    int i;
    if (s_host_stopped && !s_tex)
        return;
    s_host_stopped = 1;
    s_movie_active = 0;
    movie_decoder_stop();             /* skipped with START: stop decoding */
    if (!ctx || !rtv || !s_tex)
        return;
    /* clear each buffer in the chain, not just the current one */
    for (i = 0; i < 3; i++) {
        const FLOAT black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        ID3D11DeviceContext_ClearRenderTargetView(ctx, rtv, black);
        d3d8_PresentFrame();
    }
    movie_restore_guest_viewport(ctx);
    d3d8_RestoreDefaultTarget();
    fprintf(stderr, "[MVPRES] movie finished -- screen released to the game\n");
    fflush(stderr);
}

void doa3_capture_backbuffer(const char *path)
{
    ID3D11Device *dev = d3d8_GetD3D11Device();
    ID3D11DeviceContext *ctx = d3d8_GetD3D11Context();
    ID3D11Texture2D *bb = d3d8_GetGuestTexture(), *stg = NULL;
    D3D11_TEXTURE2D_DESC td, sd;
    D3D11_MAPPED_SUBRESOURCE map;
    if (!dev || !ctx || !bb) return;
    ID3D11Texture2D_AddRef(bb);
    ID3D11Texture2D_GetDesc(bb, &td);
    sd = td;
    sd.Usage = D3D11_USAGE_STAGING;
    sd.BindFlags = 0;
    sd.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    sd.MiscFlags = 0;
    if (FAILED(ID3D11Device_CreateTexture2D(dev, &sd, NULL, &stg))) {
        ID3D11Texture2D_Release(bb);
        return;
    }
    ID3D11DeviceContext_CopyResource(ctx, (ID3D11Resource *)stg, (ID3D11Resource *)bb);
    if (SUCCEEDED(ID3D11DeviceContext_Map(ctx, (ID3D11Resource *)stg, 0,
                                          D3D11_MAP_READ, 0, &map))) {
        FILE *f = fopen(path, "wb");
        if (f) {
            int w = (int)td.Width, h = (int)td.Height;
            int stride = (w * 3 + 3) & ~3;
            unsigned char hdr[54];
            unsigned size = 54u + (unsigned)(stride * h);
            memset(hdr, 0, sizeof hdr);
            hdr[0] = 'B'; hdr[1] = 'M';
            memcpy(hdr + 2, &size, 4);
            { unsigned off = 54; memcpy(hdr + 10, &off, 4); }
            { unsigned ih = 40; memcpy(hdr + 14, &ih, 4); }
            memcpy(hdr + 18, &w, 4);
            memcpy(hdr + 22, &h, 4);
            { unsigned short pl = 1, bc = 24;
              memcpy(hdr + 26, &pl, 2); memcpy(hdr + 28, &bc, 2); }
            fwrite(hdr, 1, sizeof hdr, f);
            {
                unsigned char *row = (unsigned char *)calloc(1, (size_t)stride);
                for (int y = h - 1; y >= 0; y--) {
                    const unsigned char *src =
                        (const unsigned char *)map.pData + (size_t)y * map.RowPitch;
                    /* The swap chain is DXGI_FORMAT_R8G8B8A8_UNORM, i.e.
                     * memory order R,G,B,A -- not BGRA as this loop used to
                     * assume. A 24-bit BMP stores B,G,R, so copying straight
                     * through swapped red and blue and every captured frame
                     * read back the wrong colour (the FMV end card came out
                     * blue in the dumps while the window showed it red). */
                    for (int x = 0; x < w; x++) {      /* RGBA -> BGR */
                        row[x * 3 + 0] = src[x * 4 + 2];   /* B <- R */
                        row[x * 3 + 1] = src[x * 4 + 1];   /* G */
                        row[x * 3 + 2] = src[x * 4 + 0];   /* R <- B */
                    }
                    fwrite(row, 1, (size_t)stride, f);
                }
                free(row);
            }
            fclose(f);
            fprintf(stderr, "[CAPTURE] wrote %s (%ux%u)\n", path, td.Width, td.Height);
            fflush(stderr);
        }
        ID3D11DeviceContext_Unmap(ctx, (ID3D11Resource *)stg, 0);
    }
    ID3D11Texture2D_Release(stg);
    ID3D11Texture2D_Release(bb);
}

void doa3_movie_repaint(void)
{
    ID3D11DeviceContext *ctx = d3d8_GetD3D11Context();
    if (s_host_stopped || !ctx || !s_tex || s_failed || !s_frames)
        return;
    {
        const void *host = movie_host_frame();
        if (s_host_stopped) {
            doa3_movie_present_finish();
            return;
        }
        if (host)
            movie_upload(ctx, host, 720 * 4);
    }

    movie_draw_to_guest(ctx);
    d3d8_PresentFrame();
    movie_restore_guest_viewport(ctx);
    /* Hand the output merger back with the depth buffer attached. The
     * movie binds its own render-target view and no depth-stencil view;
     * leaving that bound means every guest draw afterwards runs with no
     * depth test and no depth writes, so the stage comes out in
     * submission order and whatever is drawn last -- the sky backdrop --
     * covers the temple, the ground and the walls. */
    d3d8_RestoreDefaultTarget();
}

void doa3_present_movie_surface(const void *src, int w, int h, int pitch)
{
    ID3D11Device *dev = d3d8_GetD3D11Device();
    ID3D11DeviceContext *ctx = d3d8_GetD3D11Context();
    if (s_host_stopped || !dev || !ctx || !src || s_failed)
        return;
    if (!s_tex) {
        if (!movie_present_init(dev, w, h)) {
            s_failed = 1;
            fprintf(stderr, "[MVPRES] init FAILED — movie present disabled\n");
            fflush(stderr);
            return;
        }
    }
    if (w != s_w || h != s_h)
        return;

    {
        const void *host = movie_host_frame();
        if (s_host_stopped) {
            doa3_movie_present_finish();
            return;
        }
        if (host) {
            src = host;
            pitch = w * 4;
        }
    }
    movie_upload(ctx, src, pitch);

    movie_draw_to_guest(ctx);
    d3d8_PresentFrame();                   /* message pump + vsync present */
    movie_restore_guest_viewport(ctx);
    d3d8_RestoreDefaultTarget();           /* see doa3_present_movie_frame */

    s_frames++;
}

/* DOA2U: present the current movie frame (once per guest frame); a newly selected
 * movie restarts the presenter. */
void doa2u_movie_tick(void)
{
    ID3D11Device *dev = d3d8_GetD3D11Device();
    ID3D11DeviceContext *ctx = d3d8_GetD3D11Context();
    const void *host;
    if (!s_movie_active || !dev || !ctx || s_failed)
        return;
    if (s_movie_pending) {
        s_movie_pending = 0;
        movie_decoder_stop();
        s_host_frame = NULL;
        xa2_movie_stop();
        free(s_host_audio); s_host_audio = NULL;
        s_host_audio_samples = s_host_audio_submitted = 0;
        s_host_audio_active = 0;
        s_host_audio_done = 0; s_host_audio_last_played = 0;
        s_host_frames = 0;
        s_host_stopped = 0;
    }
    if (!s_tex && !movie_present_init(dev, 720, 480)) {
        s_failed = 1;
        fprintf(stderr, "[MVPRES] init FAILED -- movie present disabled\n");
        fflush(stderr);
        return;
    }
    host = movie_host_frame();
    if (s_host_stopped) {
        doa3_movie_present_finish();
        return;
    }
    if (!host)
        return;
    movie_upload(ctx, host, 720 * 4);
    movie_draw_to_guest(ctx);
    d3d8_PresentFrame();
    movie_restore_guest_viewport(ctx);
    d3d8_RestoreDefaultTarget();
    s_frames++;
}

/* DOA2U: the guest stopped its movie (closed the file / skipped). */
void doa2u_movie_stop(void)
{
    if (!s_movie_active)
        return;
    xa2_movie_stop();
    doa3_movie_present_finish();
}

int doa2u_movie_active(void)
{
    /* A movie selected after the previous one finished counts as active, so the tick
     * that starts it runs. */
    return s_movie_active && (!s_host_stopped || s_movie_pending);
}
