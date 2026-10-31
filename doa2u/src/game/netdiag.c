#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "netdiag.h"

#define SLOW_MS 50.0

static FILE *s_f;
static int s_started;
static LARGE_INTEGER s_freq, s_t0, s_last_frame, s_last_summary, s_last_tx;
static volatile LONGLONG s_last_rx, s_rx_gap_qpc;   /* host NIC thread writes these */
static struct {
    unsigned frames, waits, timeouts, tx, rx, held, slow_frames, slow_waits;
    double max_frame_ms, wait_ms, max_wait_ms, max_lat_ms;
    uint32_t max_wait_caller, max_wait_obj;
} s;

/* Last packets either way, dumped when the game goes silent: shows what arrived just before. */
#define RING_N 128
struct netdiag_pkt { LONGLONG t; uint16_t len, sport, dport; char dir; uint32_t caller; uint8_t pay[24]; };
static struct netdiag_pkt s_ring[RING_N];
static volatile LONG s_ring_pos;

static void ring_add(char dir, const uint8_t *frame, uint32_t len, LONGLONG t)
{
    LONG i = (InterlockedIncrement(&s_ring_pos) - 1) % RING_N;
    uint16_t sp = 0, dp = 0;
    if (len >= 42 && frame[12] == 8 && frame[13] == 0 && frame[23] == 17) {
        sp = (uint16_t)(frame[34] << 8 | frame[35]);
        dp = (uint16_t)(frame[36] << 8 | frame[37]);
    }
    s_ring[i].t = t; s_ring[i].len = (uint16_t)len; s_ring[i].sport = sp; s_ring[i].dport = dp; s_ring[i].dir = dir;
    s_ring[i].caller = 0;
}

/* Game thread: the plaintext the game handed to XNET sendto ('s') or got from recvfrom ('r'). */
void doa2u_netdiag_plain(char dir, uint32_t caller, const uint8_t *buf, uint32_t len)
{
    LARGE_INTEGER t;
    LONG i;
    if (!s_started) return;
    QueryPerformanceCounter(&t);
    i = (InterlockedIncrement(&s_ring_pos) - 1) % RING_N;
    s_ring[i].t = t.QuadPart; s_ring[i].len = (uint16_t)len; s_ring[i].sport = s_ring[i].dport = 0;
    s_ring[i].dir = dir; s_ring[i].caller = caller;
    memset(s_ring[i].pay, 0, sizeof s_ring[i].pay);
    memcpy(s_ring[i].pay, buf, len < sizeof s_ring[i].pay ? len : sizeof s_ring[i].pay);
}

static void ring_dump(int n)
{
    LONG end = s_ring_pos, i;
    LONGLONG prev = 0;
    if (n > RING_N) n = RING_N;
    for (i = end - n; i < end; i++) {
        const struct netdiag_pkt *e = &s_ring[((i % RING_N) + RING_N) % RING_N];
        if (i < 0 || !e->t) continue;
        fprintf(s_f, "    %9.3f %c %4u %5u->%-5u +%.1f\n", (double)(e->t - s_t0.QuadPart) / (double)s_freq.QuadPart,
                e->dir, e->len, e->sport, e->dport, prev ? (double)(e->t - prev) * 1000.0 / (double)s_freq.QuadPart : 0.0);
        prev = e->t;
    }
}

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
    if (s_f) fprintf(s_f, "# t(s) | frames maxframe_ms | waits timeouts wait_ms max_wait_ms (obj caller) | tx rx held lat_ms\n");
}

void doa2u_netdiag_tx(const uint8_t *frame, uint32_t len)
{
    LARGE_INTEGER t;
    double ts, gap;
    open_log();
    s.tx++;
    ts = now_s(&t);
    gap = s_last_tx.QuadPart ? since_ms(s_last_tx, t) : 0.0;
    s_last_tx = t;
    ring_add('T', frame, len, t.QuadPart);
    if (gap > SLOW_MS && s_f) {
        fprintf(s_f, "%9.3f tx silence %.1f ms (game sent nothing)\n", ts, gap);
        if (gap >= 100.0 && gap < 1000.0) ring_dump(40);
    }
}

/* Host NIC thread: a frame arrived from the socket. Only the gap is noted; the log line
 * is written on the game thread in doa2u_netdiag_rx. */
void doa2u_netdiag_rx_arrive(const uint8_t *frame, uint32_t len, LONGLONG qpc)
{
    LONGLONG prev = s_last_rx;
    s_last_rx = qpc;
    ring_add('R', frame, len, qpc);
    if (prev && s_f && (double)(qpc - prev) * 1000.0 / (double)s_freq.QuadPart > SLOW_MS)
        s_rx_gap_qpc = prev;
}

void doa2u_netdiag_rx(int delivered, int held, LONGLONG oldest_arrival)
{
    LARGE_INTEGER t;
    LONGLONG gap_from = s_rx_gap_qpc;
    double lat;
    s.rx += (unsigned)delivered;
    s.held += (unsigned)held;
    if (!s_f) return;
    if (gap_from) {
        s_rx_gap_qpc = 0;
        fprintf(s_f, "%9.3f rx silence %.1f ms (nothing arrived from the peer/network)\n",
                (double)(gap_from - s_t0.QuadPart) / (double)s_freq.QuadPart,
                (double)(s_last_rx - gap_from) * 1000.0 / (double)s_freq.QuadPart);
    }
    if (delivered) {
        QueryPerformanceCounter(&t);
        lat = (double)(t.QuadPart - oldest_arrival) * 1000.0 / (double)s_freq.QuadPart;
        if (lat > s.max_lat_ms) s.max_lat_ms = lat;
        if (lat > SLOW_MS) fprintf(s_f, "%9.3f rx delivery late %.1f ms (frame sat in the NIC queue)\n", now_s(&t), lat);
    }
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
        fprintf(s_f, "%9.3f | %3u %6.1f | %4u %4u %7.1f %6.1f (%08X %08X) | %4u %4u %3u %6.1f\n", ts,
                s.frames, s.max_frame_ms, s.waits, s.timeouts, s.wait_ms, s.max_wait_ms,
                s.max_wait_obj, s.max_wait_caller, s.tx, s.rx, s.held, s.max_lat_ms);
        fflush(s_f);
        memset(&s, 0, sizeof s);
        s_last_summary = t;
    }
}
