#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "netdiag.h"

#define SLOW_MS 50.0

static FILE *s_f;
static int s_started;
static LARGE_INTEGER s_freq, s_t0, s_last_frame, s_last_summary;
static struct {
    unsigned frames, waits, timeouts, tx, rx, held, slow_frames, slow_waits;
    double max_frame_ms, wait_ms, max_wait_ms;
    uint32_t max_wait_caller, max_wait_obj;
} s;

static double since_ms(LARGE_INTEGER a, LARGE_INTEGER b) { return (double)(b.QuadPart - a.QuadPart) * 1000.0 / (double)s_freq.QuadPart; }

static double now_s(LARGE_INTEGER *out)
{
    QueryPerformanceCounter(out);
    return since_ms(s_t0, *out) / 1000.0;
}

static void open_log(void)
{
    if (s_f || s_started) return;
    s_started = 1;
    QueryPerformanceFrequency(&s_freq);
    QueryPerformanceCounter(&s_t0);
    s_last_frame = s_last_summary = s_t0;
    s_f = fopen("doa2u_net.log", "w");
    if (s_f) fprintf(s_f, "# t(s) | frames maxframe_ms | waits timeouts wait_ms max_wait_ms (obj caller) | tx rx held\n");
}

void doa2u_netdiag_tx(void)
{
    open_log();
    s.tx++;
}

void doa2u_netdiag_rx(int delivered, int held)
{
    s.rx += (unsigned)delivered;
    s.held += (unsigned)held;
}

void doa2u_netdiag_wait(uint32_t obj, uint32_t caller, double ms, int timed_out)
{
    LARGE_INTEGER t;
    if (!s_f) return;
    s.waits++; s.timeouts += timed_out ? 1 : 0; s.wait_ms += ms;
    if (ms > s.max_wait_ms) { s.max_wait_ms = ms; s.max_wait_caller = caller; s.max_wait_obj = obj; }
    if (ms > SLOW_MS) {
        s.slow_waits++;
        fprintf(s_f, "%9.3f wait %.1f ms obj %08X from %08X%s\n", now_s(&t), ms, obj, caller, timed_out ? " TIMEOUT" : "");
    }
}

void doa2u_netdiag_frame(void)
{
    LARGE_INTEGER t;
    double dt, ts;
    if (!s_f) return;
    ts = now_s(&t);
    dt = since_ms(s_last_frame, t);
    s_last_frame = t;
    s.frames++;
    if (dt > s.max_frame_ms) s.max_frame_ms = dt;
    if (dt > SLOW_MS) { s.slow_frames++; fprintf(s_f, "%9.3f frame gap %.1f ms\n", ts, dt); }
    if (since_ms(s_last_summary, t) >= 1000.0) {
        fprintf(s_f, "%9.3f | %3u %6.1f | %4u %4u %7.1f %6.1f (%08X %08X) | %4u %4u %3u\n", ts,
                s.frames, s.max_frame_ms, s.waits, s.timeouts, s.wait_ms, s.max_wait_ms,
                s.max_wait_obj, s.max_wait_caller, s.tx, s.rx, s.held);
        fflush(s_f);
        memset(&s, 0, sizeof s);
        s_last_summary = t;
    }
}
