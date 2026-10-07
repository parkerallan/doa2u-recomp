/**
 * xbox_det.h - deterministic time for lockstep netplay sessions.
 *
 * While a session is active every guest-visible clock is derived from the
 * lockstep frame counter instead of the host, so two machines fed the same
 * inputs see the same time values at the same frames:
 *
 *   KeTickCount            base_ms  + frames * 1000 / 60
 *   KeQueryPerformanceCounter  base_qpc + frames * freq / 60  (+ that fiber's poll boost)
 *   KeQuerySystemTime      base_ft  + frames * 10000000 / 60
 *
 * Worker-fiber timeslicing is taken off the 4 ms host timer as well: at each
 * lockstep frame the workers get a fixed number of laps and then run until
 * all of them have blocked (xbox_fiber_timeslice); otherwise they only run
 * when a guest thread waits.
 *
 * Nothing here changes behaviour outside a session. When a session ends the
 * host clocks resume with an offset, so no guest clock ever runs backwards.
 */
#ifndef XBOX_DET_H
#define XBOX_DET_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XBOX_DET_LAPS_PER_FRAME  4     /* the host timer's 4 ms period at 60 Hz */
#define XBOX_DET_VBLANK_KEY      0xDE7FB1A0u   /* wait key for workers parked on the vblank in a session */

/* Session clock bases. The host of a session chooses them and sends them to
 * the other side; a local session takes the current host values. */
typedef struct {
    uint32_t tick_ms;     /* KeTickCount at frame 0 */
    uint64_t qpc;         /* guest QPC at frame 0 */
    uint64_t filetime;    /* KeQuerySystemTime at frame 0 (100 ns units) */
} xbox_det_bases;

extern volatile int g_xbox_det_active;

/* Current guest-visible values (real or deterministic), for building bases. */
void     xbox_det_current_bases(xbox_det_bases *out);

void     xbox_det_begin(const xbox_det_bases *b);
void     xbox_det_end(void);

/* One lockstep frame: advance the clocks, publish KeTickCount, and schedule
 * this frame's worker laps. Called from the game thread only. */
void     xbox_det_frame(void);
uint64_t xbox_det_frames(void);

/* Clock sources used by the kernel bridges. */
uint32_t xbox_det_tick_ms(void);
uint64_t xbox_det_qpc(void);
uint64_t xbox_det_filetime(void);

/* Guest file opens/reads, counted so a netplay session can start only once
 * the game's loading has gone quiet. */
void     xbox_det_note_io(void);
uint32_t xbox_det_io_count(void);

/* Hot-poll time boost (kernel_bridge QPC) accumulated within the session. */
void     xbox_det_add_qpc_boost(uint64_t delta);

/* Changes on every begin/end, so callers can reset per-session state. */
uint32_t xbox_det_epoch(void);

/* Kernel calls made by the calling fiber this session (hot-poll detection). */
uint32_t xbox_det_fiber_kcalls(void);

/* Diagnostics: guest kernel calls, and the game thread's hot-poll boost. */
uint32_t xbox_det_kcalls(void);
uint64_t xbox_det_boost(void);

/* Offsets applied to the host clocks after a session so they stay monotonic. */
uint32_t xbox_det_tick_offset(void);
uint64_t xbox_det_qpc_offset(void);

/* Host-side writers that must not race a session start. */
void     xbox_det_publish_host_tick(uint32_t host_ms);  /* 1 ms tick thread */
void     xbox_det_host_slice_timer(void);                /* 4 ms slice timer */

/* Called on every guest kernel call (game thread). */
void     xbox_det_on_kernel_call(unsigned ordinal);


/* Worker laps for the slice that is due now (deterministic in a session). */
int      xbox_det_slice_laps(void);

#ifdef __cplusplus
}
#endif

#endif /* XBOX_DET_H */
