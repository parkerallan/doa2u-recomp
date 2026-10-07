/* Cooperative fiber scheduler — see xbox_fiber.h. */
#include "xbox_fiber.h"
#include "xbox_det.h"

/* CRI watchdog thread routine that never needs a slice; 0 = none. */
uint32_t g_xbox_cri_watchdog_routine = 0;
#include "xbox_memory_layout.h"          /* xbox_HeapAlloc */

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* Recompiler symbols (declared locally to avoid pulling the heavy recomp
 * headers into the kernel library). */
extern uint32_t g_eax, g_ecx, g_edx, g_esp;
extern uint32_t g_ebx, g_esi, g_edi;
extern uint32_t g_seh_ebp;
extern ptrdiff_t g_xbox_mem_offset;

typedef void (*recomp_func_t)(void);
extern recomp_func_t recomp_lookup(uint32_t xbox_va);
extern recomp_func_t recomp_lookup_manual(uint32_t xbox_va);

#define FMEM32(va) (*(volatile uint32_t *)((uintptr_t)(va) + g_xbox_mem_offset))

#define MAX_FIBERS         64
#define WORKER_STACK_SIZE  0x40000      /* 256 KB Xbox stack per worker */
#define WORKER_NATIVE_STK  (8u << 20)   /* 8 MB native fiber stack */
#define CORO_STACK_SIZE    0x20000      /* fallback when the caller asks for nothing */
/* Floor for a game-task Xbox stack. The game asks CreateFiber for 0x4000 (16 KB)
 * per task; this doubles that for headroom and is still 4x less than the
 * 128 KB we used to force. The old fixed 128 KB cost 2.6 MB across the 21
 * title-screen tasks and ran the 49 MB guest heap dry (97.9% used), which is
 * what killed the process after the movie. */
#define CORO_STACK_MIN     0x8000
#define CORO_NATIVE_STK    (24u << 20)  /* 24 MB native stack per coroutine (recomp
                                         * turns each Xbox call into a native call, so
                                         * the game's deep boot-screen call trees need
                                         * a large C stack — matches the main thread) */

typedef enum { FIB_FREE = 0, FIB_READY, FIB_RUNNING, FIB_WAITING, FIB_DONE,
               FIB_DORMANT /* direct-switched coroutine, parked */ } FibState;

typedef struct {
    LPVOID   handle;        /* Windows fiber */
    FibState state;
    uint32_t start_routine; /* Xbox VA (worker entry) */
    uint32_t ctx1, ctx2;
    uint32_t stack_top;     /* Xbox VA of this thread's stack top */
    uint32_t stack_size;    /* bytes allocated for it (recycle only if big enough) */
    uint32_t wait_event;    /* Xbox VA of the event this fiber is blocked on (FIB_WAITING) */
    uint32_t xhandle;       /* unique fake NT thread handle (0xBEEFxxxx) — waits/wakes
                             * on thread handles (join, suspend/resume) must target ONE
                             * thread; a shared handle deadlocked the Sofdec player. */
    int      is_coroutine;  /* direct-switched (XAPI fiber), never round-robin scheduled */
    int      resume_to;     /* fiber to park back into when this one finishes/yields */
    /* saved recompiler register-globals */
    uint32_t r_eax, r_ecx, r_edx, r_esp, r_ebx, r_esi, r_edi, r_sehebp;
    /* saved x87 FPU state (g_fp_stack/g_fp_top are process globals) */
    double   r_fp_stack[8];
    int      r_fp_top;
} Fiber;

static Fiber g_fib[MAX_FIBERS];
static int   g_nfib   = 0;
static int   g_cur    = 0;
static int   g_active = 0;
/* Directed handoff (xbox_fiber_run_thread): when >= 0, the next time the
 * running fiber parks (yield/block/exit) control returns STRAIGHT to this
 * fiber instead of round-robin. This gives NtResumeThread its hardware
 * semantics ("the resumed thread runs now") without letting every other
 * fiber take a turn mid-caller — general yields from the main fiber inside
 * the server pump re-entered CRI code and broke playback (bisected). */
static int   g_direct_return = -1;

extern double g_fp_stack[8];
extern int    g_fp_top;

static void save_regs(Fiber *f)
{
    f->r_eax = g_eax; f->r_ecx = g_ecx; f->r_edx = g_edx; f->r_esp = g_esp;
    f->r_ebx = g_ebx; f->r_esi = g_esi; f->r_edi = g_edi; f->r_sehebp = g_seh_ebp;
    memcpy(f->r_fp_stack, g_fp_stack, sizeof(g_fp_stack));
    f->r_fp_top = g_fp_top;
}
static void load_regs(Fiber *f)
{
    g_eax = f->r_eax; g_ecx = f->r_ecx; g_edx = f->r_edx; g_esp = f->r_esp;
    g_ebx = f->r_ebx; g_esi = f->r_esi; g_edi = f->r_edi; g_seh_ebp = f->r_sehebp;
    memcpy(g_fp_stack, f->r_fp_stack, sizeof(g_fp_stack));
    g_fp_top = f->r_fp_top;
}

/* Next runnable (READY) fiber after `from`, round-robin. -1 if none. */
/* Post-movie only: the movie phase relies on the older round-robin resumption of
 * game tasks (a task waits for the movie by yielding, and the primary must run
 * in between); its verified timing is left as it was. */
extern volatile int g_doa2u_post_movie;
static int pick_next(int from)
{
    for (int k = 1; k <= g_nfib; k++) {
        int i = (from + k) % g_nfib;
        /* XAPI fibers (game tasks) resume only when the game switches to them,
         * never by round-robin: two runnable tasks were being resumed in index
         * order after a vblank wait, so the render record builder and the
         * walker interleaved in a way the game never does and the walker spun
         * on a half-rebuilt list (the intro-scene freeze). */
        if (g_fib[i].is_coroutine && g_doa2u_post_movie) continue;
        if (g_fib[i].state == FIB_READY) return i;
    }
    return -1;
}

static void CALLBACK fiber_trampoline(LPVOID p)
{
    Fiber *f = (Fiber *)p;
    /* Set up the Xbox stack exactly like PsCreateSystemThreadEx does for the
     * main thread: push ctx2, ctx1, and a dummy return address, then call the
     * start routine. */
    g_esp = f->stack_top;
    g_esp -= 4; FMEM32(g_esp) = f->ctx2;
    g_esp -= 4; FMEM32(g_esp) = f->ctx1;
    g_esp -= 4; FMEM32(g_esp) = 0;            /* dummy return address */

    recomp_func_t fn = recomp_lookup_manual(f->start_routine);
    if (!fn) fn = recomp_lookup(f->start_routine);
    if (fn) fn();

    /* The start routine returned → this fiber has exited. */
    f->state = FIB_DONE;

    if (f->is_coroutine) {
        /* Direct-switched coroutine: hand control back to whoever ran us. */
        for (;;) {
            int r = f->resume_to;
            if (r < 0 || r >= g_nfib || g_fib[r].state == FIB_FREE || g_fib[r].state == FIB_DONE)
                r = 0;
            g_cur = r;
            if (g_fib[r].state != FIB_WAITING) g_fib[r].state = FIB_RUNNING;
            load_regs(&g_fib[r]);
            SwitchToFiber(g_fib[r].handle);
        }
    }

    fprintf(stderr, "[FIBER] thread 0x%08X exited\n", f->start_routine);
    fflush(stderr);

    /* Hand control to another runnable fiber (or the primary). We never resume. */
    for (;;) {
        int n = pick_next(g_cur);
        if (n < 0) n = 0;                     /* fall back to the primary fiber */
        g_cur = n; g_fib[n].state = FIB_RUNNING; load_regs(&g_fib[n]);
        SwitchToFiber(g_fib[n].handle);
    }
}

void xbox_fiber_init(void)
{
    if (g_active) return;
    LPVOID prim = ConvertThreadToFiber(NULL);
    if (!prim) prim = GetCurrentFiber();      /* already a fiber */
    memset(g_fib, 0, sizeof(g_fib));
    g_fib[0].handle = prim;
    g_fib[0].state  = FIB_RUNNING;
    g_nfib = 1;
    g_cur  = 0;
    g_active = 1;
    fprintf(stderr, "[FIBER] primary fiber initialized\n");
    fflush(stderr);
}

int xbox_fiber_active(void) { return g_active; }

/* Run the workers until none is ready (at most `cap` laps). Netplay
 * sessions use this wherever the game gives its workers time, so how much
 * work they finish never depends on how much was queued. */
void xbox_fiber_run_workers_idle(int cap)
{
    extern int xbox_fiber_workers_ready(void);
    xbox_fiber_yield();
    while (--cap > 0 && xbox_fiber_workers_ready()) xbox_fiber_yield();
}

/* Any worker (not the primary, not a game-task coroutine) ready to run. */
int xbox_fiber_workers_ready(void)
{
    int i;
    for (i = 1; i < g_nfib; i++) {
        if (g_fib[i].is_coroutine && g_doa2u_post_movie) continue;
        /* The CRI watchdog (sub_0016A530) is a pure yield loop and is always
         * READY; counting it meant "until idle" always ran to its cap, and
         * within that budget the file server's progress on a load depended
         * on how much music streaming was queued ahead of it. */
        if (g_xbox_cri_watchdog_routine && g_fib[i].ctx1 == g_xbox_cri_watchdog_routine) continue;
        if (g_fib[i].state == FIB_READY) return 1;
    }
    return 0;
}

int xbox_fiber_spawn(uint32_t start_routine, uint32_t ctx1, uint32_t ctx2,
                     uint32_t xhandle, int suspended)
{
    if (!g_active || g_nfib >= MAX_FIBERS) return 0;
    int i = g_nfib;
    Fiber *f = &g_fib[i];
    memset(f, 0, sizeof(*f));
    f->handle = CreateFiber(WORKER_NATIVE_STK, fiber_trampoline, f);
    if (!f->handle) {
        fprintf(stderr, "[FIBER] CreateFiber failed for 0x%08X\n", start_routine);
        return 0;
    }
    uint32_t base = xbox_HeapAllocHigh(WORKER_STACK_SIZE, 16); /* DOA2U: CPU-only, keep the GPU-addressable low heap for the game */
    f->start_routine = start_routine;
    f->ctx1 = ctx1; f->ctx2 = ctx2;
    f->stack_top = base + WORKER_STACK_SIZE - 16;
    f->xhandle = xhandle;
    /* NOTE: CreateSuspended is intentionally IGNORED (fiber starts READY).
     * Honoring it parked the CRI ADX workers and the whole boot pipeline
     * (partition loads) deadlocked behind their handshake; the workers
     * self-pace via NtSuspendThread once running, which works. */
    (void)suspended;
    f->state = FIB_READY;
    g_nfib++;
    fprintf(stderr, "[FIBER] spawned #%d routine=0x%08X ctx1=0x%08X stack_top=0x%08X handle=0x%08X%s\n",
            i, start_routine, ctx1, f->stack_top, xhandle, suspended ? " (suspended)" : "");
    fflush(stderr);
    return 1;
}

void xbox_fiber_yield(void)
{
    if (!g_active) return;
    int me = g_cur;
    int n = -1;
    if (g_direct_return >= 0 && g_direct_return != me) {
        n = g_direct_return;                  /* directed handoff: return to the caller */
        g_direct_return = -1;
        g_fib[n].state = FIB_READY;
    } else if (g_fib[me].is_coroutine && g_doa2u_post_movie) {
        /* Rotate through the workers. Scanning from `me` always lands on the
         * first READY worker after the task -- the CRI watchdog (#1) -- so a
         * task spinning on a CRI handshake (sub_0016A4C0, waiting for the
         * server #4 to clear 0xB24D3C) ping-ponged with the watchdog forever
         * and the server never ran: the story-mode pre-FMV freeze (hang dump
         * 2026-10-01). */
        static int s_rr;
        n = pick_next(s_rr);
        if (n >= 0) s_rr = n;
    } else {
        n = pick_next(me);
    }
    if (g_fib[me].is_coroutine && g_doa2u_post_movie) {
        /* A game task yielding (vblank wait, sleep): let one worker run and
         * come straight back here -- the task is not schedulable by anyone
         * else (see pick_next). */
        if (n < 0) return;
        g_direct_return = me;
    }
    if (n < 0) {
        /* Nobody else is READY.
         *
         * If fibers are parked on events this is a circular wait: whoever
         * would signal them cannot run, because we are the only runnable
         * fiber and we merely spin. xbox_fiber_block() already breaks that
         * by releasing every waiter to re-check its own condition, but a
         * pure yield-loop never reaches that path -- and the CRI watchdog
         * override (sub_0016A530) is exactly such a loop. Post-movie the
         * whole game parked behind it: the primary fiber and two CRI
         * workers sat on event 0x260830 while the watchdog span forever.
         *
         * Apply the same release, but only after enough fruitless yields
         * that this cannot be ordinary scheduling. */
        static unsigned s_idle;
        int waiters = 0, i;
        for (i = 0; i < g_nfib; i++)
            if (g_fib[i].state == FIB_WAITING) waiters++;
        if (!waiters) { s_idle = 0; return; }
        if (++s_idle < 200000u) return;
        s_idle = 0;
        for (i = 0; i < g_nfib; i++)
            if (g_fib[i].state == FIB_WAITING) {
                g_fib[i].state = FIB_READY; g_fib[i].wait_event = 0;
            }
        {   static int logged;
            if (logged < 8) { logged++;
                fprintf(stderr, "[FIBER] yield-spin deadlock: released %d waiter(s)\n",
                        waiters);
                fflush(stderr); } }
        n = pick_next(me);
        if (n < 0) return;
    }

    save_regs(&g_fib[me]);
    if (g_fib[me].state == FIB_RUNNING) g_fib[me].state = FIB_READY;
    g_cur = n; g_fib[n].state = FIB_RUNNING; load_regs(&g_fib[n]);
    SwitchToFiber(g_fib[n].handle);
    /* Resumed: the switcher already restored our register-globals. */
    g_cur = me; g_fib[me].state = FIB_RUNNING;
}

/* Time-based scheduling point for the worker threads.
 *
 * The scheduler is cooperative, so the CRI worker threads (vblank-paced ADX
 * and file servers, and the I/O completion worker) only run when the game
 * thread parks. After the movie the game loop never blocks in the kernel,
 * and while it loads a scene it does not present either, so the workers ran
 * only when a deadlock breaker fired: the music stream got one file read
 * every few seconds and the voice replayed its 341 ms ring buffer in between
 * (measured: prim_yields=1..3 per 2 s, writes in 2 s bursts). On hardware
 * those threads are woken by the vblank interrupt regardless of what the
 * game thread is doing. Model that with a periodic lap through the READY
 * fibers from the primary, taken from the kernel-call path (which the game
 * thread hits constantly) but never while it is inside the CRI server pump
 * or holds the CRI lock, so no server is re-entered. */
volatile int g_fib_slice_due = 0;
static DWORD WINAPI fib_slice_timer(LPVOID p)
{
    (void)p;
    /* No effect while a netplay session schedules the slices (xbox_det.c). */
    for (;;) { Sleep(4); xbox_det_host_slice_timer(); }
}
void xbox_fiber_timeslice(void)
{
    extern int doa2u_workers_may_run(void);
    static HANDLE s_timer;
    if (!g_active) return;
    if (g_cur != 0) {
        /* A worker at a slice point after its 4 ms hands the CPU back (polling CRI servers kept
         * it forever); XAPI coroutines switch explicitly and are left alone. */
        if (g_fib_slice_due && !g_fib[g_cur].is_coroutine) {
            g_fib_slice_due = 0;
            xbox_fiber_yield();
        }
        return;
    }
    if (!s_timer) s_timer = CreateThread(NULL, 0, fib_slice_timer, NULL, 0, NULL);
    if (!g_fib_slice_due) return;
    if (!doa2u_workers_may_run()) return;
    g_fib_slice_due = 0;
    {   /* One lap per 4 ms tick that elapsed since the last slice, capped.
         * While a scene loads the game thread sits in host D3D11 calls for
         * tens of ms at a time (no hook can run there); a timer-driven
         * thread would have run once per tick in the meantime, so catch up
         * on the missed ticks instead of granting a single lap. */
        static LARGE_INTEGER s_last, s_freq;
        LARGE_INTEGER now; int laps = 1;
        if (!s_freq.QuadPart) QueryPerformanceFrequency(&s_freq);
        QueryPerformanceCounter(&now);
        if (s_last.QuadPart) {
            long long ticks /* ms; a worker iteration is ~4 laps */ = (now.QuadPart - s_last.QuadPart) * 1000 / s_freq.QuadPart;
            if (ticks > laps) laps = (int)(ticks > 64 ? 64 : ticks);
        }
        s_last = now;
        /* Netplay session: a fixed lap budget per lockstep frame, never the
         * wall clock, so both machines run their workers identically. */
        if (g_xbox_det_active) {
            /* Then keep going until every worker has blocked: whatever file
             * or decode work is pending finishes inside this frame, so a
             * load completes on the same frame however much music streaming
             * was queued ahead of it (that amount depends on where the menu
             * music was when the session started). */
            laps = xbox_det_slice_laps();
            while (laps-- > 0) xbox_fiber_yield();
            xbox_fiber_run_workers_idle(1024);
            laps = 0;
        }
        while (laps-- > 0) xbox_fiber_yield();
    }
}

void xbox_fiber_block(uint32_t event_va)
{
    if (!g_active) return;
    int me = g_cur;
    g_fib[me].wait_event = event_va;
    g_fib[me].state = FIB_WAITING;
    save_regs(&g_fib[me]);

    int n = -1;
    if (g_direct_return >= 0 && g_direct_return != me) {
        n = g_direct_return;                  /* directed handoff: return to the caller */
        g_direct_return = -1;
        g_fib[n].state = FIB_READY;
    } else {
        n = pick_next(me);
    }
    if (n < 0 && g_xbox_det_active) { xbox_fiber_wake(XBOX_DET_VBLANK_KEY); n = pick_next(me); }
    if (n < 0) {
        /* Nobody runnable. Wake all waiters to avoid a hard deadlock; they will
         * re-check their own condition and block again if still unsatisfied. */
        for (int i = 0; i < g_nfib; i++)
            if (g_fib[i].state == FIB_WAITING) { g_fib[i].state = FIB_READY; g_fib[i].wait_event = 0; }
        n = pick_next(me);
        if (n < 0) { g_fib[me].state = FIB_RUNNING; g_fib[me].wait_event = 0; return; }
    }
    g_cur = n; g_fib[n].state = FIB_RUNNING; load_regs(&g_fib[n]);
    SwitchToFiber(g_fib[n].handle);
    /* Woken: the switcher restored our register-globals. */
    g_cur = me; g_fib[me].state = FIB_RUNNING; g_fib[me].wait_event = 0;
}

void xbox_fiber_wake(uint32_t event_va)
{
    (void)xbox_fiber_wake_count(event_va);
}

/* Like xbox_fiber_wake, but reports how many fibers were actually woken (the
 * NtResumeThread bridge uses 0 == "this resume would be lost" — see
 * xbox_fiber_credit_resume). */
int xbox_fiber_wake_count(uint32_t event_va)
{
    int n = 0;
    if (!g_active) return 0;
    for (int i = 0; i < g_nfib; i++)
        if (g_fib[i].state == FIB_WAITING && (event_va == 0 || g_fib[i].wait_event == event_va)) {
            g_fib[i].state = FIB_READY;
            g_fib[i].wait_event = 0;
            n++;
        }
    return n;
}

void xbox_fiber_exit(void)
{
    if (!g_active) return;
    int me = g_cur;
    if (me == 0) return;                      /* primary thread: let it return normally */
    g_fib[me].state = FIB_DONE;
    fprintf(stderr, "[FIBER] fiber #%d (0x%08X) terminated\n", me, g_fib[me].start_routine);
    fflush(stderr);
    /* Signal the thread object: wake any fiber joined on our handle. */
    if (g_fib[me].xhandle)
        xbox_fiber_wake(g_fib[me].xhandle);
    int n = -1;
    if (g_direct_return >= 0 && g_direct_return != me) {
        n = g_direct_return;
        g_direct_return = -1;
        g_fib[n].state = FIB_READY;
    } else {
        n = pick_next(me);
    }
    if (n < 0) n = 0;                         /* fall back to the primary fiber */
    g_cur = n; g_fib[n].state = FIB_RUNNING; load_regs(&g_fib[n]);
    SwitchToFiber(g_fib[n].handle);
    /* never reached */
}

/* NOTE (item 100): "resume credits" (mark a READY/RUNNING fiber so its next
 * self-suspend re-checks instead of parking, closing the cooperative model's
 * enlarged resume-vs-park race) were implemented here TWICE (unconditional,
 * then only-when-wake-found-nobody) and BOTH collapsed playback: the ADXM
 * protocol legitimately retries resumes against a running server hundreds of
 * times per frame, so any credit keeps the sfdec servers from ever parking
 * and one worker monopolizes the scheduler. Lost resumes are healed by those
 * same protocol retries; the one case where retries stop (main parked in the
 * mount poll) is covered by the gated [MOUNTNUDGE] spurious wake there. */

/* Directed resume: run the parked fiber(s) matching this thread handle NOW,
 * returning to the caller as soon as the target parks again. Falls back to a
 * plain wake when no matching fiber is parked. Returns 1 if a switch
 * happened. Only intended for the primary fiber (NtResumeThread bridge). */
/* Is a spawned (non-coroutine) thread whose start context is ctx1 still
 * running? the game joins exactly one such thread: its cache-install worker
 * (routine 0x0009D440), see bridge_NtWaitForSingleObject. */
int xbox_fiber_thread_alive(uint32_t ctx1)
{
    for (int i = 0; i < g_nfib; i++) {
        Fiber *f = &g_fib[i];
        if (f->is_coroutine) continue;
        if (f->ctx1 != ctx1) continue;
        if (f->state == FIB_FREE || f->state == FIB_DONE) continue;
        return 1;
    }
    return 0;
}

int xbox_fiber_run_thread(uint32_t xhandle)
{
    if (!g_active) return 0;
    int me = g_cur;
    for (int i = 0; i < g_nfib; i++) {
        if (i == me) continue;
        Fiber *f = &g_fib[i];
        if (f->is_coroutine) continue;
        if (f->state != FIB_READY &&
            !(f->state == FIB_WAITING &&
              (f->wait_event == xhandle || xhandle == 0)))
            continue;
        if (xhandle && f->xhandle != xhandle && f->wait_event != xhandle)
            continue;
        f->state = FIB_READY;
        f->wait_event = 0;
        save_regs(&g_fib[me]);
        if (g_fib[me].state == FIB_RUNNING) g_fib[me].state = FIB_READY;
        g_direct_return = me;
        g_cur = i; f->state = FIB_RUNNING; load_regs(f);
        SwitchToFiber(f->handle);
        /* target parked; the direct-return path switched back to us */
        g_cur = me; g_fib[me].state = FIB_RUNNING;
        g_direct_return = -1;
        return 1;
    }
    return 0;
}

/* Diagnostic: one-line-per-fiber state dump (for lock-spin forensics). */
void xbox_fiber_dump_states(void)
{
    fprintf(stderr, "[FIBSTATE] cur=%d n=%d:", g_cur, g_nfib);
    for (int i = 0; i < g_nfib; i++)
        fprintf(stderr, " #%d{st=%d rt=%X wait=%X co=%d}",
                i, (int)g_fib[i].state, g_fib[i].start_routine,
                g_fib[i].wait_event, g_fib[i].is_coroutine);
    fprintf(stderr, "%c", 10);
    fflush(stderr);
}

/* Any non-coroutine fiber ready to run? (decode-budget loop exit test) */
int xbox_fiber_any_ready(void)
{
    if (!g_active) return 0;
    for (int i = 0; i < g_nfib; i++)
        if (i != g_cur && g_fib[i].state == FIB_READY && !g_fib[i].is_coroutine)
            return 1;
    return 0;
}

int xbox_fiber_is_primary(void)
{
    return g_active && g_cur == 0;
}

uint32_t xbox_fiber_current_ctx1(void) { return g_active ? g_fib[g_cur].ctx1 : 0; }

int xbox_fiber_current(void)
{
    return g_cur;
}

/* True if the current fiber is a direct-switched coroutine (XAPI game task). */
int xbox_fiber_is_coroutine(void)
{
    return g_active && g_fib[g_cur].is_coroutine;
}

/* ── Direct-switched coroutines (XAPI CreateFiber/SwitchToFiber backing) ── */

int xbox_fiber_create_dormant(uint32_t routine_va, uint32_t param,
                              uint32_t stack_size)
{
    if (!g_active) return -1;
    int i;
    /* Reuse a free/finished slot (game tasks are created and deleted per screen). */
    for (i = 1; i < MAX_FIBERS; i++)
        if (i >= g_nfib || g_fib[i].state == FIB_FREE) break;
    if (i >= MAX_FIBERS) {
        fprintf(stderr, "[FIBER] coroutine pool exhausted\n");
        return -1;
    }
    Fiber *f = &g_fib[i];
    if (f->handle) { DeleteFiber(f->handle); f->handle = NULL; }
    uint32_t keep_stack = f->stack_top;    /* reuse the Xbox stack of a recycled slot */
    uint32_t keep_size  = f->stack_size;
    if (!stack_size) stack_size = CORO_STACK_SIZE;
    if (stack_size < CORO_STACK_MIN) stack_size = CORO_STACK_MIN;
    stack_size = (stack_size + 15u) & ~15u;
    /* A recycled slot's stack is only reusable if it is big enough. */
    if (keep_stack && keep_size < stack_size) { keep_stack = 0; keep_size = 0; }
    memset(f, 0, sizeof(*f));
    f->handle = CreateFiber(CORO_NATIVE_STK, fiber_trampoline, f);
    if (!f->handle) return -1;
    if (!keep_stack) {
        /* On failure xbox_HeapAlloc returns 0. The old code still computed
         * base + size - 16 from it, handing the fiber a stack pointer at
         * 0x1FFF0 -- inside the XBE image -- so the task silently shredded
         * the game's own code and the process died with no exception to
         * catch. Fail the create instead, loudly. */
        uint32_t base = xbox_HeapAllocHigh(stack_size, 16); /* DOA2U: CPU-only stack -> high heap */
        if (!base) {
            fprintf(stderr, "[FIBER] OUT OF GUEST HEAP: cannot allocate %u-byte "
                            "Xbox stack for task routine 0x%08X (slot %d)\n",
                    stack_size, routine_va, i);
            fflush(stderr);
            DeleteFiber(f->handle); f->handle = NULL;
            f->state = FIB_FREE;
            return -1;
        }
        keep_stack = base + stack_size - 16;
        keep_size  = stack_size;
    }
    f->stack_top  = keep_stack;
    f->stack_size = keep_size;
    f->start_routine = routine_va;
    f->ctx1 = param;
    f->ctx2 = 0;
    f->is_coroutine = 1;
    f->resume_to = 0;
    f->state = FIB_DORMANT;
    if (i >= g_nfib) g_nfib = i + 1;
    return i;
}

void xbox_fiber_destroy(int idx)
{
    if (idx <= 0 || idx >= g_nfib) return;
    Fiber *f = &g_fib[idx];
    if (!f->is_coroutine) return;             /* never destroy scheduler threads */
    if (f->handle) { DeleteFiber(f->handle); f->handle = NULL; }
    f->state = FIB_FREE;                       /* stack_top kept for reuse */
    f->is_coroutine = 0;
}

/* A coroutine yielding back to whoever direct-switched into it (its resume_to).
 * No-op on the primary/scheduler fibers. */
void xbox_fiber_yield_back(void)
{
    if (!g_active) return;
    Fiber *me = &g_fib[g_cur];
    if (!me->is_coroutine) return;
    int r = me->resume_to;
    if (r < 0 || r >= g_nfib || !g_fib[r].handle ||
        g_fib[r].state == FIB_FREE || g_fib[r].state == FIB_DONE)
        r = 0;
    int self = g_cur;
    me->state = FIB_DORMANT;
    save_regs(me);
    g_cur = r;
    g_fib[r].state = FIB_RUNNING;
    load_regs(&g_fib[r]);
    SwitchToFiber(g_fib[r].handle);
    /* Resumed (switched back into this task). */
    g_cur = self;
    g_fib[self].state = FIB_RUNNING;
}

void xbox_fiber_switch_direct(int idx)
{
    if (!g_active || idx < 0 || idx >= g_nfib || idx == g_cur) return;
    Fiber *t = &g_fib[idx];
    if (t->state == FIB_FREE || t->state == FIB_DONE || !t->handle) return;
    int me = g_cur;
    g_fib[me].state = FIB_DORMANT;             /* park; only a direct switch resumes us */
    save_regs(&g_fib[me]);
    t->resume_to = me;
    g_cur = idx;
    t->state = FIB_RUNNING;
    load_regs(t);
    SwitchToFiber(t->handle);
    /* Switched back: our registers were restored by whoever resumed us. */
    g_cur = me;
    g_fib[me].state = FIB_RUNNING;
}

int xbox_fiber_count(void)
{
    int c = 0;
    for (int i = 0; i < g_nfib; i++)
        if (g_fib[i].state == FIB_READY || g_fib[i].state == FIB_RUNNING) c++;
    return c;
}

void xbox_fiber_dump(void)
{
    static const char *S[] = { "FREE", "READY", "RUNNING", "WAITING", "DONE", "DORMANT" };
    fprintf(stderr, "[FIBER-DUMP] %d fibers, cur=%d:\n", g_nfib, g_cur);
    for (int i = 0; i < g_nfib; i++)
        fprintf(stderr, "   #%d routine=0x%08X state=%s wait_event=0x%08X\n",
                i, g_fib[i].start_routine, S[g_fib[i].state], g_fib[i].wait_event);
    fflush(stderr);
}
