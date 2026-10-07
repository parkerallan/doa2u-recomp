/* Dead or Alive 2 Ultimate - manual / overridden functions (DOA2.xbe, XDK 5849).
 * Each sub_X here replaces the generated body, renamed sub_X_gen by postprocess.py. */

#define RECOMP_GENERATED_CODE
#include "gen/recomp_funcs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

extern uint32_t xbox_HeapAlloc(uint32_t size, uint32_t alignment);
extern void xbox_fiber_yield(void);
extern int  xbox_fiber_active(void);
extern void xbox_fiber_wake(uint32_t event_va);
extern int  xbox_fiber_is_primary(void);
extern int  xbox_fiber_is_coroutine(void);

/* ── Guest addresses (DOA2.xbe) ─────────────────────────────────────── */
#define D3D_G_PDEVICE        0x003554F8u   /* D3D_g_pDevice */
#define D3D_FAKE_CHANNEL     0x00355000u   /* XDK's GPU-less FIFO control block (+0x40 PUT, +0x44 GET) */
#define DEV_VBLANK_EVENT_OFS 0x1DBCu       /* D3DDevice__m_VerticalBlankEvent_OFFSET */
#define DEV_VBLANK_CB_OFS    0x1DB8u       /* D3DDevice__m_VBlankCallback_OFFSET */
#define DEV_SWAP_CB_OFS      0x1DB4u       /* D3DDevice__m_SwapCallback_OFFSET */
#define DSOUND_LO            0x00363360u   /* DSOUND section (APU interrupt routines live here) */
#define DSOUND_HI            0x00380EA4u

/* ── Flags carried across a generated-fragment boundary ─────────────── */
/* Exact x86 flag semantics for CMP (a - b) and TEST (a & b) at the operand
 * width the compare used; see RC_SETF_* in recomp_types.h. */
uint32_t g_flg_a, g_flg_b;
int g_flg_w = 4, g_flg_test;

int rc_flg_cc(int cc)
{
    uint32_t mask = (g_flg_w == 1) ? 0xFFu : (g_flg_w == 2) ? 0xFFFFu : 0xFFFFFFFFu;
    uint32_t sign = (g_flg_w == 1) ? 0x80u : (g_flg_w == 2) ? 0x8000u : 0x80000000u;
    uint32_t a = g_flg_a & mask, b = g_flg_b & mask, r;
    int zf, sf, cf = 0, of = 0, pf, i, ones = 0;
    unsigned lo;

    if (g_flg_test) {
        r = (a & b) & mask;
    } else {
        r = (a - b) & mask;
        cf = (a < b);
        of = ((((a ^ b) & (a ^ r)) & sign) != 0);
    }
    zf = (r == 0);
    sf = ((r & sign) != 0);
    lo = (unsigned)(r & 0xFFu);
    for (i = 0; i < 8; i++) if (lo & (1u << i)) ones++;
    pf = ((ones & 1) == 0);

    switch (cc) {
    case 0:  return zf;
    case 1:  return !zf;
    case 2:  return cf;
    case 3:  return !cf;
    case 4:  return cf || zf;
    case 5:  return !cf && !zf;
    case 6:  return sf != of;
    case 7:  return sf == of;
    case 8:  return zf || (sf != of);
    case 9:  return !zf && (sf == of);
    case 10: return sf;
    case 11: return !sf;
    case 12: return of;
    case 13: return !of;
    case 14: return pf;
    case 15: return !pf;
    default: return 0;
    }
}

/* ── Unresolved indirect calls ──────────────────────────────────────── */
/* Indirect call/jump to a target with no translated body: log each target once. */
#define ICALL_SEEN_MAX 256
static uint32_t s_icall_seen[ICALL_SEEN_MAX];
static int s_icall_seen_n;

static int icall_first_time(uint32_t va)
{
    int i;
    for (i = 0; i < s_icall_seen_n; i++) if (s_icall_seen[i] == va) return 0;
    if (s_icall_seen_n < ICALL_SEEN_MAX) s_icall_seen[s_icall_seen_n++] = va;
    return 1;
}

/* Native callers are logged as image RVAs; resolve them against
 * build/release/DOA2U.map ("Rva+Base", base 0x140000000). */
static unsigned long long caller_rva(void *ra)
{
    return (unsigned long long)((uintptr_t)ra - (uintptr_t)GetModuleHandleA(NULL));
}

void recomp_icall_fail_log(uint32_t va)
{
    if (icall_first_time(va)) {
        void *bt[4];
        USHORT n = CaptureStackBackTrace(1, 4, bt, NULL);
        USHORT i;
        fprintf(stderr, "[ICALL] unresolved target 0x%08X (esp=%08X) from rva", va, esp);
        for (i = 0; i < n; i++) fprintf(stderr, " %llX", caller_rva(bt[i]));
        fprintf(stderr, "\n");
        fflush(stderr);
    }
}

void recomp_itail_fail_log(uint32_t va)
{
    if (icall_first_time(va | 0x80000000u)) {
        fprintf(stderr, "[ITAILF] unresolved tail target 0x%08X (esp=%08X)\n", va, esp);
        fflush(stderr);
    }
}

/* Manual entry points that have no generated counterpart (none yet). The
 * dispatch table already binds every sub_XXXXXXXX defined in this file. */
static const struct {
    uint32_t      xbox_va;
    recomp_func_t func;
} g_manual_funcs[] = {
    { 0u, 0 },  /* sentinel */
};
#define NUM_MANUAL_FUNCS (sizeof(g_manual_funcs) / sizeof(g_manual_funcs[0]))

recomp_func_t recomp_lookup_manual(uint32_t xbox_va)
{
    size_t i;
    for (i = 0; i < NUM_MANUAL_FUNCS; i++)
        if (g_manual_funcs[i].func && g_manual_funcs[i].xbox_va == xbox_va)
            return g_manual_funcs[i].func;
    return NULL;
}

/* ── Call targets with no valid code (data decoded as code) ─────────── */
/* Garbage call targets (operands decoded from data): consume the return slot and log. */
#define GARBAGE_TARGET(va) \
    void sub_##va(void) { \
        fprintf(stderr, "[GARBAGE] call to non-code target 0x" #va "\n"); \
        esp += 4; \
    }
GARBAGE_TARGET(02888C16)
GARBAGE_TARGET(97336EEB)
GARBAGE_TARGET(003C14DA)
GARBAGE_TARGET(003C14EA)
GARBAGE_TARGET(E91CEB10)
GARBAGE_TARGET(E970EB1C)
GARBAGE_TARGET(EE2A2E3C)

/* ── Runtime symbols the shared libraries expect from the game layer ── */
volatile int g_doa3_post_movie = 0;      /* fiber timeslicing gate (kept off) */
void (*g_kernel_ptinfo_hook)(const char *where);   /* NtReadFile diagnostic hook (unused) */
uint32_t g_doa3_offrt_offs[8]; int g_doa3_offrt_n;
/* Worker timeslice: every 4 ms the game thread hands the CRI server fibers a slice,
 * standing in for preemption (the game's load waits never block). */
int doa3_workers_may_run(void) { return 1; }
int doa3_guest_display_size(unsigned *w, unsigned *h) { (void)w; (void)h; return 0; }

/* APU interrupt delivery: run the DirectSound ISR and its DPCs as guest calls. */
void doa3_apu_deliver_irq(void)
{
    typedef struct MCPXAPUState MCPXAPUState;
    extern int mcpx_apu_take_irq(void);
    extern int xbox_kernel_get_isr(int, uint32_t *, uint32_t *, uint32_t *);
    extern int xbox_kernel_pop_dpc(uint32_t *, uint32_t *, uint32_t *);
    static int s_delivering = 0;
    uint32_t obj, routine, ctx, dpc, a1, a2;
    int i;
    if (s_delivering) return;
    if (!mcpx_apu_take_irq()) return;
    s_delivering = 1;
    for (i = 0; xbox_kernel_get_isr(i, &obj, &routine, &ctx); i++) {
        recomp_func_t fn;
        if (routine < DSOUND_LO || routine >= DSOUND_HI) continue;
        fn = recomp_lookup_manual(routine);
        if (!fn) fn = recomp_lookup(routine);
        if (!fn) continue;
        {
            uint32_t saved_esp = esp;
            PUSH32(esp, ctx);
            PUSH32(esp, obj);
            PUSH32(esp, 0);
            fn();
            esp = saved_esp;
        }
    }
    while (xbox_kernel_pop_dpc(&dpc, &a1, &a2)) {
        uint32_t droutine = MEM32(dpc + 12), dctx = MEM32(dpc + 16);
        recomp_func_t fn = recomp_lookup_manual(droutine);
        if (!fn) fn = recomp_lookup(droutine);
        if (!fn) continue;
        {
            uint32_t saved_esp = esp;
            PUSH32(esp, a2);
            PUSH32(esp, a1);
            PUSH32(esp, dctx);
            PUSH32(esp, dpc);
            PUSH32(esp, 0);
            fn();
            esp = saved_esp;
        }
    }
    s_delivering = 0;
}

/* ── Game hooks called by the kernel bridge ─────────────────────────── */

/* Every guest file open. A .sfd is a movie the guest is about to play:
 * hand it to the host presenter (movie_present.c). */
void game_on_file_open(const char *xbox_path)
{
    size_t n = strlen(xbox_path);
    static int s_logged = 0;
    if (s_logged < 200) {
        s_logged++;
        fprintf(stderr, "[FILE] open %s\n", xbox_path);
        fflush(stderr);
    }
    (void)n;
}

/* mwPlyStartFname (0x0031BBB0): the host presenter shows the movie with its ADX track
 * while the guest player runs alongside. */
void sub_0031BBB0(void)
{
    extern void sub_0031BBB0_gen(void);
    extern void doa3_movie_select(const char *guest_path);
    uint32_t fname = MEM32(esp + 8);
    if (fname) {
        char name[MAX_PATH];
        int i;
        for (i = 0; i < MAX_PATH - 1 && MEM8(fname + i); i++) name[i] = (char)MEM8(fname + i);
        name[i] = 0;
        fprintf(stderr, "[MOVIE] mwPlyStartFname(0x%08X, \"%s\")\n", MEM32(esp + 4), name);
        fflush(stderr);
        doa3_movie_select(name);
    }
    sub_0031BBB0_gen();
}

/* Modelled vblank: the game may wait on vblank during movies without calling Swap,
 * so the presenter is ticked here too. */
void game_pump_vblank_servers(void)
{
    extern void doa2u_movie_tick(void);
    extern int doa2u_movie_active(void);
    extern volatile LONG g_doa3_heartbeat;
    static LARGE_INTEGER s_last, s_freq;
    LARGE_INTEGER now;
    if (!doa2u_movie_active()) return;
    /* at most one presenter tick per 1/60 s from this path */
    if (!s_freq.QuadPart) QueryPerformanceFrequency(&s_freq);
    QueryPerformanceCounter(&now);
    if (s_last.QuadPart && (now.QuadPart - s_last.QuadPart) * 60 < s_freq.QuadPart) return;
    s_last = now;
    InterlockedIncrement(&g_doa3_heartbeat);
    doa2u_movie_tick();
}

/* ── XAPI fibers -> host cooperative fibers ─────────────────────────── */
/* XAPI fibers backed by host coroutines (xbox_fiber.c), as in DOA3; handles are
 * 0xF1BE0000|index, anything else means back to the dispatcher. */
extern int  xbox_fiber_create_dormant(uint32_t routine_va, uint32_t param, uint32_t stack_size);
extern void xbox_fiber_destroy(int idx);
extern void xbox_fiber_switch_direct(int idx);
#define XFIBER_TAG  0xF1BE0000u

void sub_002BB76A(void)   /* CreateFiber(stack_size, start_routine, param), stdcall ret 12 */
{
    uint32_t stack_sz = MEM32(esp + 4);
    uint32_t routine  = MEM32(esp + 8);
    uint32_t param    = MEM32(esp + 0xC);
    int idx = xbox_fiber_create_dormant(routine, param, stack_sz);
    eax = (idx > 0) ? (XFIBER_TAG | (uint32_t)idx) : 0;
    esp += 16;
}

void sub_002BB7F6(void)   /* DeleteFiber(handle), stdcall ret 4 */
{
    uint32_t h = MEM32(esp + 4);
    if ((h & 0xFFFF0000u) == XFIBER_TAG)
        xbox_fiber_destroy((int)(h & 0xFFFF));
    esp += 8;
}

void sub_002BB809(void)   /* SwitchToFiber(handle), stdcall ret 4 */
{
    uint32_t h = MEM32(esp + 4);
    esp += 8;                 /* finish the call first, then transfer */
    if ((h & 0xFFFF0000u) == XFIBER_TAG) {
        xbox_fiber_switch_direct((int)(h & 0xFFFF));
    } else {
        extern void xbox_fiber_yield_back(void);
        xbox_fiber_yield_back();
    }
}

/* ── CRT memcpy (0x00335A80) ────────────────────────────────────────── */
/* memcpy/memmove (0x335A80): its jump-table tail can't be lifted; overlap-safe native copy. */
void sub_00335A80(void)
{
    uint32_t dst = MEM32(esp + 4), src = MEM32(esp + 8), n = MEM32(esp + 0xC);
    if (n)
        memmove((void *)XBOX_PTR(dst), (const void *)XBOX_PTR(src), n);
    eax = dst;
    esp += 4;
}

/* ── D3D (XDK 5849) push buffer, fences and present ─────────────────── */
/* No GPU behind the push-buffer ring: KickOff translates new commands to D3D11 and
 * retires them like the XDK's GPU-less branch (GET == PUT, all fences done). */
static uint32_t g_pb_parsed = 0;     /* next push-buffer word not yet translated */

/* Translate [from, to). Stops at a JUMP/CALL/RETURN (wrap) and returns the
 * address it stopped at. */
static uint32_t pb_translate(uint32_t from, uint32_t to)
{
    extern int pgraph_d3d11_method(int subchannel, uint32_t method, uint32_t param);
    uint32_t pos = from;
    while (pos + 4 <= to) {
        uint32_t word = MEM32(pos);
        if (word == 0) { pos += 4; continue; }
        if ((word & 3) == 1 || (word & 0xE0000003u) == 0x20000000u || word == 0x00020000u ||
            (word & 3) == 2)
            return pos;                          /* jump / call / return: end of run */
        {
            uint32_t kind = word & 0xE0030003u;
            if (kind == 0 || kind == 0x40000000u) {   /* increasing / non-increasing */
                uint32_t count   = (word >> 18) & 0x7FF;
                uint32_t method  = word & 0x1FFC;
                uint32_t subchan = (word >> 13) & 7;
                uint32_t i;
                pos += 4;
                if (pos + count * 4 > to) return to;
                for (i = 0; i < count; i++) {
                    uint32_t param = MEM32(pos); pos += 4;
                    pgraph_d3d11_method((int)subchan,
                                        (kind == 0) ? method + i * 4 : method, param);
                }
            } else {
                pos += 4;
            }
        }
    }
    return pos;
}

static void pb_translate_pending(uint32_t dev, uint32_t cursor)
{
    uint32_t base = MEM32(dev + 0x24), end = MEM32(dev + 0x28);
    if (!base || end <= base || cursor < base || cursor > end)
        return;                                  /* not the ring (recording etc.) */
    if (g_pb_parsed < base || g_pb_parsed > end)
        g_pb_parsed = base;
    if (cursor >= g_pb_parsed) {
        uint32_t stop = pb_translate(g_pb_parsed, cursor);
        if (stop < cursor && cursor - stop > 4) {
            /* stopped on a jump before the cursor: the ring wrapped and the
             * cursor is past the base again */
            pb_translate(base, cursor);
        }
    } else {
        pb_translate(g_pb_parsed, end);          /* old tail up to its JUMP */
        pb_translate(base, cursor);              /* new head */
    }
    g_pb_parsed = cursor;
}

void sub_00349E80(void)   /* CDevice_KickOff(this = ecx), ret */
{
    uint32_t dev = ecx;
    if (dev) {
        uint32_t flags  = MEM32(dev + 8);
        uint32_t cursor = (flags & 4) ? MEM32(dev + 0x770) : MEM32(dev);
        pb_translate_pending(dev, cursor);
        MEM32(dev + 0x1C20) = D3D_FAKE_CHANNEL;
        MEM32(D3D_FAKE_CHANNEL + 0x40) = cursor & 0x0FFFFFFFu;   /* DMA_PUT */
        MEM32(D3D_FAKE_CHANNEL + 0x44) = cursor & 0x0FFFFFFFu;   /* DMA_GET == PUT */
        {
            uint32_t done = MEM32(dev + 0x30);
            if (done) MEM32(done) = MEM32(dev + 0x2C) - 2;       /* every inserted fence retired */
        }
        MEM32(dev + 0x1DE4) = MEM32(dev + 0x2478);
    }
    esp += 4;
}

/* Publish the D3D vblank event / counter to the kernel bridge once the device
 * exists (KeWaitForSingleObject on it is modelled as "vblank fired"). */
static void d3d_publish_vblank(uint32_t dev)
{
    extern uint32_t g_xbox_vblank_event_va;
    if (dev && !g_xbox_vblank_event_va) {
        g_xbox_vblank_event_va = dev + DEV_VBLANK_EVENT_OFS;
        fprintf(stderr, "[D3D] device 0x%08X, vblank event 0x%08X\n", dev, g_xbox_vblank_event_va);
        fflush(stderr);
    }
}

/* D3DDevice_Swap (0x0034AF80): run the real Swap, present (or tick the movie),
 * then model the vblank (event + callback). */
void sub_0034AF80(void)
{
    extern void sub_0034AF80_gen(void);
    extern void pgraph_d3d11_flush(void);
    extern void doa3_present_frame(void);
    extern void doa2u_movie_tick(void);
    extern int  doa2u_movie_active(void);
    uint32_t sv_esi = esi, sv_edi = edi, sv_ebx = ebx;
    uint32_t dev;
    sub_0034AF80_gen();
    {   /* 60 Hz pacing: wait for the next 1/60 s boundary; resync if a frame or more behind. */
        static LARGE_INTEGER s_freq, s_next;
        LARGE_INTEGER now;
        if (!s_freq.QuadPart) { QueryPerformanceFrequency(&s_freq); timeBeginPeriod(1); }
        QueryPerformanceCounter(&now);
        if (!s_next.QuadPart || now.QuadPart - s_next.QuadPart > s_freq.QuadPart / 60)
            s_next = now;
        while (now.QuadPart < s_next.QuadPart) {
            LONGLONG left_ms = (s_next.QuadPart - now.QuadPart) * 1000 / s_freq.QuadPart;
            if (left_ms > 2) Sleep((DWORD)(left_ms - 1));
            QueryPerformanceCounter(&now);
        }
        s_next.QuadPart += s_freq.QuadPart / 60;
    }
    {
        uint32_t ret_eax = eax, ret_esp = esp;
        dev = MEM32(D3D_G_PDEVICE);
        d3d_publish_vblank(dev);
        {   /* DOA3 host-EOF trigger: the guest Sofdec parks in PLAYING at a movie's end, so once
             * the presenter hits EOF set SFD state 6 / mwPly state 3 (PLAYEND). */
            extern int g_doa3_host_movie_ended;
            uint32_t mp = MEM32(0xA942D8);                 /* mwPly handle */
            if (g_doa3_host_movie_ended && mp >= 0x1000 && mp < 0x8000000u &&
                MEM32(mp + 8) == 2) {
                uint32_t sfd = MEM32(mp + 0x40);
                if (sfd >= 0x1000 && sfd < 0x8000000u && MEM32(sfd + 0x48) == 4) {
                    MEM32(sfd + 0x48) = 6;                 /* SFD handle: PLAYEND */
                    MEM32(mp + 8) = 3;                     /* movie object: finished */
                }
            }
        }
        if (doa2u_movie_active()) {
            extern volatile LONG g_doa3_heartbeat;
            InterlockedIncrement(&g_doa3_heartbeat);
            doa2u_movie_tick();
        } else {
            pgraph_d3d11_flush();
            doa3_present_frame();
        }
        if (dev) {
            uint32_t ev = dev + DEV_VBLANK_EVENT_OFS;
            uint32_t cb = MEM32(dev + DEV_VBLANK_CB_OFS);
            MEM32(ev + 4) = 1;                      /* KEVENT.SignalState */
            xbox_fiber_wake(ev);
            if (cb) {
                recomp_func_t fn = recomp_lookup_manual(cb);
                if (!fn) fn = recomp_lookup(cb);
                if (fn) {
                    /* D3DVBLANKDATA { VBlank, Swap, Flags } in guest memory */
                    static uint32_t s_vbdata = 0, s_vbcount = 0;
                    uint32_t saved = esp;
                    if (!s_vbdata) s_vbdata = xbox_HeapAlloc(16, 16);
                    if (s_vbdata) {
                        MEM32(s_vbdata) = ++s_vbcount;
                        MEM32(s_vbdata + 4) = s_vbcount;
                        MEM32(s_vbdata + 8) = 0;
                    }
                    PUSH32(esp, s_vbdata);
                    PUSH32(esp, 0);                 /* dummy return */
                    fn();
                    esp = saved;
                }
            }
        }
        eax = ret_eax; esp = ret_esp;
    }
    esi = sv_esi; edi = sv_edi; ebx = sv_ebx;
}

/* ── CRT _cinit (0x002BD44C) ────────────────────────────────────────── */
/* _cinit: run _FPinit and the __xi/__xc initializer tables, restoring the callee-saved
 * registers after each (one initializer leaks esi). */
static void cinit_call(uint32_t fn_va, uint32_t slot)
{
    recomp_func_t fn = recomp_lookup_manual(fn_va);
    uint32_t sv_esp = esp, sv_esi = esi, sv_edi = edi, sv_ebx = ebx;
    if (!fn) fn = recomp_lookup(fn_va);
    if (!fn) {
        fprintf(stderr, "[CINIT] slot 0x%08X: no body for 0x%08X\n", slot, fn_va);
        return;
    }
    PUSH32(esp, 0);
    fn();
    if (esp != sv_esp || esi != sv_esi || edi != sv_edi || ebx != sv_ebx)
        fprintf(stderr, "[CINIT] slot 0x%08X fn 0x%08X broke the ABI: esp %+d esi %08X->%08X "
                        "edi %08X->%08X ebx %08X->%08X\n", slot, fn_va, (int)(esp - sv_esp),
                sv_esi, esi, sv_edi, edi, sv_ebx, ebx);
    esp = sv_esp; esi = sv_esi; edi = sv_edi; ebx = sv_ebx;
}

void sub_002BD44C(void)
{
    static const uint32_t tables[2][2] = {
        { 0x004976B4u, 0x004976CCu },   /* C initializers */
        { 0x00497590u, 0x004976B0u },   /* C++ constructors */
    };
    uint32_t fp = MEM32(0x007C969Cu), p;
    int t;
    if (fp) cinit_call(fp, 0x007C969Cu);
    for (t = 0; t < 2; t++)
        for (p = tables[t][0]; p < tables[t][1]; p += 4) {
            uint32_t fn = MEM32(p);
            if (fn && fn != 0xFFFFFFFFu) cinit_call(fn, p);
        }
    fflush(stderr);
    esp += 4;   /* ret */
}

/* ADXF_GetPtStat (0x2FBAE0, DOA3 sub_00169150): the post-install mount spins on it
 * without yielding; pulse vblank and yield to the CRI workers until it's done. */
void sub_002FBAE0(void)
{
    extern void sub_002FBAE0_gen(void);
    extern uint32_t g_xbox_vblank_event_va;
    sub_002FBAE0_gen();
    if (eax != 3) {
        if (g_xbox_vblank_event_va) {
            MEM32(g_xbox_vblank_event_va + 4) = 1;  /* vblank KEVENT.SignalState */
            xbox_fiber_wake(g_xbox_vblank_event_va);
        }
        {   /* no presents happen during this spin -- service the window so it
             * doesn't go "Not Responding" under the user's clicks */
            extern void doa3_pump_messages(void);
            static unsigned s_mp2 = 0;
            if ((++s_mp2 & 63) == 0) doa3_pump_messages();
        }
        if (xbox_fiber_active())
            xbox_fiber_yield();
    }
}

/* ── Startup hook (main.c, before the entry point) ──────────────────── */
/* Legal screen (0xD92C0) stubbed. On a first boot, wait here a game frame at a time
 * for the HDD cache copy (it pauses during movies), then go on to the Team Ninja FMV. */
void sub_000D92C0(void)
{
    extern uint32_t g_xbox_cache_install_routine;
    extern int xbox_fiber_thread_alive(uint32_t ctx1);
    while (MEM32(0x8A9908) && g_xbox_cache_install_routine &&
           xbox_fiber_thread_alive(g_xbox_cache_install_routine)) {
        PUSH32(esp, 1);
        PUSH32(esp, 0);
        sub_000FA3D0();
        esp += 4;
    }
    esp += 4;   /* ret */
}

void doa2u_game_init(void)
{
    /* The device is the static 0x355500, so its vblank event is known before the first Swap. */
    extern uint32_t g_xbox_vblank_event_va;
    extern uint32_t g_xbox_cache_install_routine;
    extern volatile int g_fib_slice_due;
    g_xbox_vblank_event_va = 0x00355500u + DEV_VBLANK_EVENT_OFS;
    /* First-boot HDD cache copy worker (DOA3: 0x0009D440), started by sub_000F7390. */
    g_xbox_cache_install_routine = 0x000F70C0u;
    g_fib_slice_due = 1;   /* first slice check starts the 4 ms slice timer */
}
