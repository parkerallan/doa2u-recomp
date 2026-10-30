/* Dead or Alive 2 Ultimate - manual / overridden functions (DOA2.xbe, XDK 5849).
 * Each sub_X here replaces the generated body, renamed sub_X_gen by postprocess.py. */

#define RECOMP_GENERATED_CODE
#include "gen/recomp_funcs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <mmsystem.h>
#include "../../kernel/perf.h"
#include "../../ui/video_settings.h"
#pragma comment(lib, "winmm.lib")

extern uint32_t xbox_HeapAlloc(uint32_t size, uint32_t alignment);
extern void xbox_fiber_yield(void);
extern int  xbox_fiber_active(void);
extern void xbox_fiber_wake(uint32_t event_va);
extern int  xbox_fiber_is_primary(void);
extern int  xbox_fiber_is_coroutine(void);

/* ── Guest addresses (DOA2.xbe) ─────────────────────────────────────── */
#define D3D_G_PDEVICE        0x00358ED8u   /* D3D_g_pDevice */
#define D3D_FAKE_CHANNEL     0x003589E0u   /* XDK's GPU-less FIFO control block (+0x40 PUT, +0x44 GET) */
static void rt_sync(void);
extern void nv2a_pgraph_set_reg(uint32_t addr, uint32_t val);
#define DEV_VBLANK_EVENT_OFS 0x1DBCu       /* D3DDevice__m_VerticalBlankEvent_OFFSET */
#define DEV_VBLANK_CB_OFS    0x1DB8u       /* D3DDevice__m_VBlankCallback_OFFSET */
#define DEV_SWAP_CB_OFS      0x1DB4u       /* D3DDevice__m_SwapCallback_OFFSET */
#define DSOUND_LO            0x00366D40u   /* DSOUND section (APU interrupt routines live here) */
#define DSOUND_HI            0x00384884u

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
GARBAGE_TARGET(003C4EBA)
GARBAGE_TARGET(003C4ECA)
GARBAGE_TARGET(10B04273)
GARBAGE_TARGET(247E66EE)
GARBAGE_TARGET(2633A713)
GARBAGE_TARGET(433A5795)
GARBAGE_TARGET(553A57AD)
GARBAGE_TARGET(842B1F11)
GARBAGE_TARGET(BC336B0C)
GARBAGE_TARGET(E8BFE9CF)
GARBAGE_TARGET(E92EE9DB)
GARBAGE_TARGET(E93EE9E7)
GARBAGE_TARGET(EE2A1C3E)
GARBAGE_TARGET(F488295D)

/* ── Runtime symbols the shared libraries expect from the game layer ── */
volatile int g_doa2u_post_movie = 0;      /* fiber timeslicing gate (kept off) */
void (*g_kernel_ptinfo_hook)(const char *where);   /* NtReadFile diagnostic hook (unused) */
uint32_t g_doa2u_offrt_offs[32]; int g_doa2u_offrt_n;

/* D3DDevice_SetRenderTarget (0x003481B0): record the colour offset of every
 * texture surface used as a render target (D3DSurface.Parent at +0x14 is set
 * only for texture surfaces), so the pgraph translator routes it offscreen.
 * The stage glow target is 720x480 with the frame buffer's pitch, and without
 * this its clear landed on the back buffer and blacked out the scene. */
void sub_003481B0(void)
{
    extern void sub_003481B0_gen(void);
    uint32_t surf = MEM32(esp + 4);
    sub_003481B0_gen();
    if (surf && MEM32(surf + 0x14)) {
        uint32_t data = MEM32(surf + 4) & 0x07FFFFFFu;
        static int s_next = 0;   /* oldest entry, once the table is full */
        int k, seen = 0;
        for (k = 0; k < g_doa2u_offrt_n; k++) if (g_doa2u_offrt_offs[k] == data) seen = 1;
        if (!seen && g_doa2u_offrt_n < 32) g_doa2u_offrt_offs[g_doa2u_offrt_n++] = data;
        else if (!seen) { g_doa2u_offrt_offs[s_next] = data; s_next = (s_next + 1) % 32; }
    }
}
/* Worker timeslice: every 4 ms the game thread hands the CRI server fibers a slice,
 * standing in for preemption (the game's load waits never block). */
int doa2u_workers_may_run(void) { return 1; }
/* A worker that entered the CRI server (guard 0xF32078) or took its file lock keeps the CPU:
 * the load coroutine spins on both without yielding, so a handoff there never comes back. */
static int s_cri_owner[2] = { -1, -1 }, s_cri_set_in[2];
static const uint32_t s_cri_flag[2] = { 0xF32078u, 0xF31390u };
void doa2u_fiber_switch_in(int idx)
{
    int k;
    for (k = 0; k < 2; k++) {
        if (!MEM32(s_cri_flag[k])) s_cri_owner[k] = -1;
        s_cri_set_in[k] = MEM32(s_cri_flag[k]) != 0;
    }
    (void)idx;
}
void doa2u_fiber_switch_out(int idx)
{
    int k;
    for (k = 0; k < 2; k++)
        if (MEM32(s_cri_flag[k]) && !s_cri_set_in[k] && s_cri_owner[k] < 0) s_cri_owner[k] = idx;
}
int doa2u_worker_may_yield(int idx)
{
    int k, ok = 1;
    for (k = 0; k < 2; k++) {
        if (!MEM32(s_cri_flag[k])) { s_cri_owner[k] = -1; continue; }
        if (!s_cri_set_in[k] && s_cri_owner[k] < 0) s_cri_owner[k] = idx;   /* set during this run */
        if (s_cri_owner[k] == idx) ok = 0;
    }
    return ok;
}
/* Display size from the guest's D3DPRESENT_PARAMETERS (0x00E6BC40), the space of
 * 2D overlay coordinates. Returns 0 before CreateDevice fills it. */
int doa2u_guest_display_size(unsigned *w, unsigned *h)
{
    uint32_t dw = MEM32(0x00E6BC40u), dh = MEM32(0x00E6BC44u);
    if (dw < 64u || dw > 4096u || dh < 64u || dh > 4096u) return 0;
    *w = (unsigned)dw; *h = (unsigned)dh;
    return 1;
}

/* APU interrupt delivery: run the DirectSound ISR and its DPCs as guest calls. */
void doa2u_apu_deliver_irq(void)
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

/* XNET's IP checksum (0x00396B7C, stdcall initial, buf, len): hand-written adc chain entered
 * through a jump table mid-loop; lifted it lost every carry. Same ones'-complement sum here. */
void sub_00396B7C(void)
{
    uint32_t init = MEM32(esp + 4), buf = MEM32(esp + 8), len = MEM32(esp + 12), i;
    uint64_t s = 0;
    for (i = 0; i + 1 < len; i += 2)
        s += (uint32_t)MEM8(buf + i) | ((uint32_t)MEM8(buf + i + 1) << 8);
    if (len & 1)
        s += MEM8(buf + len - 1);
    while (s >> 16)
        s = (s & 0xFFFF) + (s >> 16);
    s += init & 0xFFFF;                     /* add ax, initial; adc eax, 0 */
    s = (s & 0xFFFF) + (s >> 16);
    eax = (uint32_t)s;
    esp += 16;                              /* ret 12 */
}

/* ── Insignia account wizard (game thread) ────────────────────────────── */
/* Runs the dashboard's /xuacs requests through DOA2's own XOnline code: a console-only
 * logon with service 5 (UACS), then XRL uploads via 0x3A7C45, the routine xmatch uses. */
#define XO_CXO          0x00F31074u   /* CXo* the XOnline export stubs load */
#define XO_TASK_DONE    0x001500F0u   /* XONLINETASK_S_SUCCESS; 0x1500F1 = results */
#define XO_LOGON_UP     0x001510F0u   /* XONLINE_S_LOGON_CONNECTION_ESTABLISHED */
enum { WIZ_IDLE, WIZ_LOGON, WIZ_RESERVE, WIZ_VOUCHER, WIZ_OFFER, WIZ_DETAILS, WIZ_CREATE, WIZ_CLOSE };

static uint32_t guest_call(void (*fn)(void), uint32_t this_ecx, int n, const uint32_t *args)
{
    uint32_t r_eax = eax, r_ecx = ecx, r_edx = edx, r_ebx = ebx, r_esi = esi,
             r_edi = edi, r_esp = esp, r_seh = g_seh_ebp, ret;
    int i;
    for (i = n - 1; i >= 0; i--) PUSH32(esp, args[i]);
    PUSH32(esp, 0);
    ecx = this_ecx;
    fn();
    ret = eax;
    eax = r_eax; ecx = r_ecx; edx = r_edx; ebx = r_ebx; esi = r_esi;
    edi = r_edi; esp = r_esp; g_seh_ebp = r_seh;
    return ret;
}

/* u16 length + UTF-8 (ASCII here), as the dashboard's string writer 0x120ADF. */
static uint32_t put_str(uint32_t dst, const char *s)
{
    uint32_t n = (uint32_t)strlen(s), i;
    MEM16(dst) = (uint16_t)n;
    for (i = 0; i < n; i++) MEM8(dst + 2 + i) = (uint8_t)s[i];
    return dst + 2 + n;
}

extern void xbox_log(int level, const char *subsystem, const char *fmt, ...);

/* The dashboard's requests carry the dashboard's identity: for the wizard's own logon
 * the XBE certificate reads as xonlinedash (title FFFE0000, version 0x185EAD00). */
#define DASH_TITLE_ID     0xFFFE0000u
#define DASH_TITLE_VER    0x185EAD00u
static uint32_t s_cert_title, s_cert_ver, s_xonl_flags;
static void wiz_dash_identity(int on)
{
    /* The Kerberos "Xbox Version=1.00.5849.q" stamp is the XONLINES entry of the XBE
     * library table (QFE in the flags' low bits): 7 in the game, 3 in the dashboard. */
    uint32_t cert = MEM32(0x10118), lib = MEM32(0x10164), n = MEM32(0x10160), i, xonl = 0;
    for (i = 0; i < n && i < 32; i++)
        if (MEM32(lib + i * 16) == 0x4C4E4F58u && MEM32(lib + i * 16 + 4) == 0x53454E49u) xonl = lib + i * 16 + 14;
    if (on) {
        s_cert_title = MEM32(cert + 8); s_cert_ver = MEM32(cert + 0xAC);
        MEM32(cert + 8) = DASH_TITLE_ID; MEM32(cert + 0xAC) = DASH_TITLE_VER;
        if (xonl) { s_xonl_flags = MEM16(xonl); MEM16(xonl) = (uint16_t)((s_xonl_flags & 0xE000u) | 3u); }
    } else {
        MEM32(cert + 8) = s_cert_title; MEM32(cert + 0xAC) = s_cert_ver;
        if (xonl) MEM16(xonl) = (uint16_t)s_xonl_flags;
    }
}

/* One XRL request on the wizard's logon: path, body, reply size; the task in s_req. */
static uint32_t wiz_send(uint32_t cxo, uint32_t mem, int svc, const char *route, uint32_t body,
                         uint32_t body_len, uint32_t reply_len, uint32_t *task)
{
    uint32_t path = mem + 0x2E00, i, hr;
    for (i = 0; route[i]; i++) MEM8(path + i) = (uint8_t)route[i];
    MEM8(path + i) = 0;
    MEM32(mem + 8) = reply_len;
    memset(XBOX_PTR(mem + 0x400), 0, 0x2000);
    {   uint32_t a[13] = { (uint32_t)svc, 0, path, mem + 0x400, mem + 8, 0, 0, body, body_len, 30000, 0, 0, mem + 0xC };
        hr = guest_call(sub_003A7C45, cxo, 13, a);
    }
    *task = MEM32(mem + 0xC);
    return hr;
}

void doa2u_insignia_wizard_step(void)
{
    extern int  insignia_wizard_take(int *, char *, size_t, char *, size_t, char *, size_t);
    extern void insignia_wizard_report(int, const char *, ...);
    extern uint32_t xbox_HeapAlloc(uint32_t size, uint32_t alignment);
    extern BOOL xbox_hdd_set_online_account(const uint8_t*, const char*, const uint8_t*, const char*, const char*);
    static int s_state = WIZ_IDLE, s_recover;
    static char s_gt[16], s_code[32], s_email[128];
    static uint32_t s_mem, s_logon, s_req, s_offer[2];
    const int country = 103;                                /* the dashboard's country byte: United States */
    uint32_t cxo = MEM32(XO_CXO), hr, body, p, i;

    if (s_state == WIZ_IDLE) {
        if (!insignia_wizard_take(&s_recover, s_gt, sizeof s_gt, s_code, sizeof s_code, s_email, sizeof s_email))
            return;
        {   /* As the dashboard's code entry (0x5B713): no spaces, dashes or dots, 25 characters. */
            char c[32]; size_t n = 0;
            for (i = 0; s_code[i] && n < sizeof c - 1; i++)
                if (isalnum((unsigned char)s_code[i])) c[n++] = (char)toupper((unsigned char)s_code[i]);
            c[n] = 0;
            if (!s_recover && n != 25) { insignia_wizard_report(3, "The subscription code has 25 characters."); return; }
            if (s_recover && n != 16) { insignia_wizard_report(3, "The card number has 16 digits."); return; }
            strcpy_s(s_code, sizeof s_code, c);
        }
        /* The logon itself creates the machine account on a fresh HDD (MACS reply, 0x39C776). */
        if (!cxo) {
            insignia_wizard_report(3, "Open the game's Online screen first.");
            return;
        }
        if (!s_mem && !(s_mem = xbox_HeapAlloc(0x3000, 16))) {
            insignia_wizard_report(3, "Out of guest memory.");
            return;
        }
        memset(XBOX_PTR(s_mem), 0, 0x3000);
        /* As the dashboard's account logon (xonlinedash 0x6AB81): services 4, 5 (UACS), 11, 20
         * and one all-zero XONLINE_USER (0x70 bytes, at +0x800). */
        MEM32(s_mem + 0x10) = 4; MEM32(s_mem + 0x14) = 5; MEM32(s_mem + 0x18) = 0xB; MEM32(s_mem + 0x1C) = 0x14;
        wiz_dash_identity(1);
        {   uint32_t a[5] = { s_mem + 0x800, s_mem + 0x10, 4, 0, s_mem + 4 };
            hr = guest_call(sub_00397581, 0, 5, a);
        }
        if ((int32_t)hr < 0) {
            wiz_dash_identity(0);
            insignia_wizard_report(3, "Sign-in failed to start (%08X).", hr);
            return;
        }
        s_logon = MEM32(s_mem + 4);
        insignia_wizard_report(1, "Signing in to Insignia...");
        s_state = WIZ_LOGON;
        return;
    }

    /* Pump the logon or the request in flight. As the dashboard's UACS wrapper (0x120B3B), a
     * request is finished once XOnlineTaskContinue returns non-zero, and that is its result. */
    {
        uint32_t task = s_state == WIZ_LOGON ? s_logon : s_req, a1[1] = { task };
        hr = guest_call(sub_00397560, 0, 1, a1);
        if (s_state == WIZ_LOGON) {
            if (hr == XO_LOGON_UP) hr = 0;
            else if ((int32_t)hr >= 0 && hr != XO_TASK_DONE && hr != XO_TASK_DONE + 1) return;
        } else {
            if (hr == 0) return;
            xbox_log(2, "INSIGNIA", "step %d -> %08X", s_state, hr);
            guest_call(sub_0039756B, 0, 1, a1);             /* XOnlineTaskClose */
        }
        if ((int32_t)hr < 0 && s_state != WIZ_CREATE && s_state != WIZ_DETAILS) {
            insignia_wizard_report(3, "%s failed (%08X).", s_state == WIZ_LOGON ? "Sign-in" :
                                   s_state == WIZ_RESERVE ? "Gamertag check" : "Subscription code check", hr);
            s_state = WIZ_CLOSE;
        } else if (s_state == WIZ_OFFER) {
            /* The dashboard (0x5FE4B) takes the offer id from the reply's first 8 bytes; Insignia
             * answers this step with 1, and offer id 0 gets its free offer. */
            s_offer[0] = hr == XO_TASK_DONE ? MEM32(s_mem + 0x400) : 0;
            s_offer[1] = hr == XO_TASK_DONE ? MEM32(s_mem + 0x404) : 0;
        } else if (s_state == WIZ_CREATE) {
            const char *why = hr == 0x80154007u ? "Insignia rejected the subscription code for this e-mail." :
                              hr == 0x80154009u ? "This subscription code was already used." :
                              hr == 0x820003F3u ? "Insignia rejected the gamertag." :
                              hr == 0x80151006u ? "Insignia found no account with this gamertag and card number." : NULL;
            if (why) insignia_wizard_report(3, "%s (%08X)", why, hr);
            else if (hr == XO_TASK_DONE && (MEM32(s_mem + 0x400) | MEM32(s_mem + 0x404))) {
                /* The 68-byte reply, as the dashboard's 0x121F40 reads it: XUID, key, domain, realm. */
                uint8_t r[68]; char domain[21] = {0}, realm[25] = {0};
                for (i = 0; i < 68; i++) r[i] = MEM8(s_mem + 0x400 + i);
                memcpy(domain, r + 0x18, 20); memcpy(realm, r + 0x2C, 24);
                if (xbox_hdd_set_online_account(r, s_gt, r + 8, domain, realm))
                    insignia_wizard_report(2, "%s is ready. Sign in on the Online screen.", s_gt);
                else insignia_wizard_report(3, "%s exists on Insignia but could not be saved here.", s_gt);
            }
            else insignia_wizard_report(3, "Insignia answered %08X.", hr);
            s_state = WIZ_CLOSE;
        }
    }

    body = s_mem + 0x100;
    memset(XBOX_PTR(body), 0, 0x300);
    if (s_state == WIZ_LOGON && s_recover) {
        /* Account Recovery, as the dashboard's 0x12287B builds it: PUID, then gamertag, three
         * short fields, phone, full name and the card number; the reply is the account. */
        const char *strs[7] = { s_gt, "", "", "", "4255551212", s_gt, s_code };
        MEM32(body) = MEM32(cxo + 0x24); MEM32(body + 4) = MEM32(cxo + 0x28);
        for (p = body + 8, i = 0; i < 7; i++) p = put_str(p, strs[i]);
        hr = wiz_send(cxo, s_mem, 5, "/xuacs/restoreaccount.ashx", body, p - body, 0x244, &s_req);
        insignia_wizard_report(1, "Recovering the account...");
        s_state = WIZ_CREATE;
    } else if (s_state == WIZ_LOGON) {
        /* The dashboard's step 1 (0x5B33F): reservename, as 0x121DBC builds it: PUID, country,
         * u16 5 (alternatives wanted), the gamertag; reply 5 * 20 + 0x202 bytes. */
        MEM32(body) = MEM32(cxo + 0x24); MEM32(body + 4) = MEM32(cxo + 0x28);
        MEM8(body + 8) = (uint8_t)country;
        MEM16(body + 9) = 5;
        p = put_str(body + 0xB, s_gt);
        hr = wiz_send(cxo, s_mem, 5, "/xuacs/reservename.ashx", body, p - body, 0x266, &s_req);
        insignia_wizard_report(1, "Checking the gamertag...");
        s_state = WIZ_RESERVE;
    } else if (s_state == WIZ_RESERVE || s_state == WIZ_VOUCHER) {
        /* The code screen runs step 0xD, verifyvoucher (0x1216EB); its completion (0x5FE05)
         * chains step 0x28, verifyvouchergetoffer. Both carry {country, code} in 0x4E bytes. */
        MEM8(body) = (uint8_t)country;
        put_str(body + 1, s_code);
        hr = wiz_send(cxo, s_mem, 5, s_state == WIZ_RESERVE ? "/xuacs/verifyvoucher.ashx" : "/xuacs/verifyvouchergetoffer.ashx",
                      body, 0x4E, 0x400, &s_req);
        insignia_wizard_report(1, "Checking the subscription code...");
        s_state = s_state == WIZ_RESERVE ? WIZ_VOUCHER : WIZ_OFFER;
    } else if (s_state == WIZ_OFFER) {
        /* OfferingDetailsNoUser on service 4, as the dashboard's 0x11A5DB builds it: country,
         * PUID, title id, offer id, u32 language - 1, u16 language. */
        MEM8(body) = (uint8_t)country;
        MEM32(body + 1) = MEM32(cxo + 0x24); MEM32(body + 5) = MEM32(cxo + 0x28);
        MEM32(body + 9) = DASH_TITLE_ID;
        MEM32(body + 0xD) = s_offer[0]; MEM32(body + 0x11) = s_offer[1];
        MEM32(body + 0x15) = 0; MEM16(body + 0x19) = 1;
        hr = wiz_send(cxo, s_mem, 4, "/xbos/OfferingDetailsNoUser.ashx", body, 0x1B, 0x400, &s_req);
        insignia_wizard_report(1, "Fetching the offer...");
        s_state = WIZ_DETAILS;
    } else if (s_state == WIZ_DETAILS) {
        /* createowneracct, as the dashboard's 0x12248A builds it: PUID, 0, birth date, two
         * opt-in bytes, country, u16 language, card type, card expiry, then 19 strings. */
        SYSTEMTIME st = { 1990, 1, 0, 1, 0, 0, 0, 0 }; FILETIME ft;
        const char *strs[19] = { s_gt, s_gt, "", "1 Main St", "", "Redmond", "WA", "98052",
                                 "4255551212", "425", "5551212", s_email, s_gt, "4111111111111111",
                                 s_email, s_email, s_email, s_email, s_code };
        MEM32(body) = MEM32(cxo + 0x24); MEM32(body + 4) = MEM32(cxo + 0x28);
        SystemTimeToFileTime(&st, &ft);
        MEM32(body + 0xC) = ft.dwLowDateTime; MEM32(body + 0x10) = ft.dwHighDateTime;
        MEM8(body + 0x14) = 1; MEM8(body + 0x15) = 1;
        MEM8(body + 0x16) = (uint8_t)country;
        MEM16(body + 0x17) = 1;
        MEM8(body + 0x19) = 0;
        st.wYear = 2030; st.wDay = 15;
        SystemTimeToFileTime(&st, &ft);
        MEM32(body + 0x1A) = ft.dwLowDateTime; MEM32(body + 0x1E) = ft.dwHighDateTime;
        for (p = body + 0x22, i = 0; i < 19; i++) p = put_str(p, strs[i]);
        hr = wiz_send(cxo, s_mem, 5, "/xuacs/createowneracct.ashx", body, p - body, 0x244, &s_req);
        insignia_wizard_report(1, "Creating the account...");
        s_state = WIZ_CREATE;
    }
    if (s_state != WIZ_CLOSE && s_state != WIZ_IDLE) {
        if ((int32_t)hr >= 0) return;
        insignia_wizard_report(3, "The request could not be sent (%08X).", hr);
    }
    {   uint32_t a1[1] = { s_logon };
        if (s_logon) guest_call(sub_0039756B, 0, 1, a1);    /* end the console logon */
    }
    s_logon = 0;
    s_state = WIZ_IDLE;
    wiz_dash_identity(0);
}

/* Once per frame: due kernel timers (XNET's 200 ms tick), the NIC's IRQ 4 ISR
 * (vector 0x34, 0x38CD74) and then the queued DPCs; guest registers preserved. */
void doa2u_nic_deliver(void)
{
    extern void xbox_kernel_fire_timers(void);
    extern int nic_poll_irq(void);
    extern int xbox_kernel_find_isr(uint32_t, uint32_t *, uint32_t *, uint32_t *);
    extern int xbox_kernel_pop_dpc(uint32_t *, uint32_t *, uint32_t *);
    uint32_t r_eax = eax, r_ecx = ecx, r_edx = edx, r_ebx = ebx, r_esi = esi,
             r_edi = edi, r_esp = esp, r_seh = g_seh_ebp;
    uint32_t obj, routine, ctx, dpc, a1, a2;
    recomp_func_t fn;

    xbox_kernel_fire_timers();
    if (nic_poll_irq() && xbox_kernel_find_isr(0x34, &obj, &routine, &ctx)) {
        fn = recomp_lookup_manual(routine);
        if (!fn) fn = recomp_lookup(routine);
        if (fn) {
            PUSH32(esp, ctx);
            PUSH32(esp, obj);
            PUSH32(esp, 0);
            fn();
            esp = r_esp;
        }
    }
    while (xbox_kernel_pop_dpc(&dpc, &a1, &a2)) {
        uint32_t droutine = MEM32(dpc + 12), dctx = MEM32(dpc + 16);
        fn = recomp_lookup_manual(droutine);
        if (!fn) fn = recomp_lookup(droutine);
        if (!fn) continue;
        PUSH32(esp, a2);
        PUSH32(esp, a1);
        PUSH32(esp, dctx);
        PUSH32(esp, dpc);
        PUSH32(esp, 0);
        fn();
        esp = r_esp;
    }
    doa2u_insignia_wizard_step();
    eax = r_eax; ecx = r_ecx; edx = r_edx; ebx = r_ebx; esi = r_esi;
    edi = r_edi; esp = r_esp; g_seh_ebp = r_seh;
}

/* DirectSound's wait for a voice to go off (0x0036DD6C, thiscall ecx = voice):
 * spins on flag 0x8000 at +0x12, which the APU ISR clears when the hardware
 * reports the voice stopped. On the console that interrupt arrives during the
 * spin; here interrupts were only delivered at Present, so every voice waited
 * out sub_0036D554's 500 ms timeout and a stage change froze for seconds.
 * Deliver the interrupt from inside the wait; guest registers are preserved. */
void sub_0036DD6C(void)
{
    uint32_t v = ecx;
    if (MEM8(v + 0x12) & 1) {
        while (MEM16(v + 0x12) & 0x8000) {
            uint32_t r_eax = eax, r_edx = edx, r_ebx = ebx, r_esi = esi,
                     r_edi = edi, r_esp = esp, r_seh = g_seh_ebp;
            doa2u_apu_deliver_irq();
            eax = r_eax; edx = r_edx; ebx = r_ebx; esi = r_esi;
            edi = r_edi; esp = r_esp; g_seh_ebp = r_seh;
            if (!(MEM16(v + 0x12) & 0x8000)) break;
            ecx = v;
            PUSH32(esp, 0);
            sub_0036D554();                 /* keeps the driver's 500 ms timeout */
            if (MEM16(v + 0x12) & 0x8000) Sleep(1);
        }
    }
    ecx = v;
    esp += 4;                               /* ret */
}

/* XAPI non-roamable signature key (0x002BB5E5, stdcall ctx, digest, out): HMAC keyed by
 * XboxHDKey. Saves were signed when that key was zero; keep a zero key for them. */
void sub_002BB5E5(void)
{
    uint32_t ctx = MEM32(esp + 4) + 8, digest = MEM32(esp + 8), out = MEM32(esp + 12);
    uint32_t ret_esp = esp, sv_ebx = ebx, sv_esi = esi, sv_edi = edi, sv_seh = g_seh_ebp;
    uint32_t key, base;
    esp -= 16;
    key = base = esp;
    MEM32(key) = 0; MEM32(key + 4) = 0; MEM32(key + 8) = 0; MEM32(key + 12) = 0;
    PUSH32(esp, ctx); PUSH32(esp, 0x10); PUSH32(esp, key); PUSH32(esp, 0);
    sub_002BB50C();
    esp = base;
    PUSH32(esp, 0x14); PUSH32(esp, digest); PUSH32(esp, ctx); PUSH32(esp, 0);
    sub_002FE380();
    esp = base;
    PUSH32(esp, out); PUSH32(esp, 0x10); PUSH32(esp, key); PUSH32(esp, ctx); PUSH32(esp, 0);
    sub_002BB573();
    ebx = sv_ebx; esi = sv_esi; edi = sv_edi; g_seh_ebp = sv_seh;
    eax = 1;
    esp = ret_esp + 16;                     /* ret 12 */
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

/* mwPlyStartFname (0x0031F380): the host presenter shows the movie with its ADX track
 * while the guest player runs alongside. The guest's audio is muted with
 * mwSfdSetOutVol (0x003118A0, -96 dB) so the soundtrack does not echo; not
 * mwPlySetAudioSw(0), which makes the guest player end the movie early. */
void sub_0031F380(void)
{
    extern void sub_0031F380_gen(void);
    extern void doa2u_movie_select(const char *guest_path);
    extern int doa2u_movies_enabled(void);
    uint32_t fname = MEM32(esp + 8);
    uint32_t handle = MEM32(esp + 4);
    if (handle) {
        uint32_t saved_esp = esp, sv_ebx = ebx, sv_esi = esi, sv_edi = edi, sv_seh = g_seh_ebp;
        PUSH32(esp, (uint32_t)-960);        /* vol: -96 dB (CRI minimum) */
        PUSH32(esp, handle);
        PUSH32(esp, 0);                     /* dummy return */
        sub_003118A0();
        esp = saved_esp; ebx = sv_ebx; esi = sv_esi; edi = sv_edi; g_seh_ebp = sv_seh;
    }
    if (fname) {
        char name[MAX_PATH];
        int i;
        for (i = 0; i < MAX_PATH - 1 && MEM8(fname + i); i++) name[i] = (char)MEM8(fname + i);
        name[i] = 0;
        fprintf(stderr, "[MOVIE] mwPlyStartFname(0x%08X, \"%s\")\n", MEM32(esp + 4), name);
        fflush(stderr);
        rt_sync();
        if (doa2u_movies_enabled()) {
            doa2u_movie_select(name);
        } else {
            /* FMV off: no presenter; the vblank pump's host-EOF trigger ends the
             * guest movie once it reaches PLAYING, the game's own end path. */
            extern int g_doa2u_host_movie_ended;
            g_doa2u_host_movie_ended = 1;
        }
    }
    sub_0031F380_gen();
}

/* Movie teardown (0x000FB8B0): stops and destroys the mwPly handle at 0xA9A678, on
 * both end of stream and START pressed. The host presenter runs on its own clock and
 * only stops at end of file, so on a skip it kept owning the screen (guest frames are
 * not presented while it is active) and played on. Hand the screen back here. */
void sub_000FB8B0(void)
{
    extern void sub_000FB8B0_gen(void);
    extern void doa2u_movie_stop(void);
    doa2u_movie_stop();
    sub_000FB8B0_gen();
}

/* Modelled vblank: the game may wait on vblank during movies without calling Swap,
 * so the presenter is ticked here too. */
void game_pump_vblank_servers(void)
{
    extern void doa2u_movie_tick(void);
    extern int doa2u_movie_active(void);
    extern volatile LONG g_doa2u_heartbeat;
    static LARGE_INTEGER s_last, s_freq;
    LARGE_INTEGER now;
    if (!doa2u_movie_active()) return;
    /* at most one presenter tick per 1/60 s from this path */
    if (!s_freq.QuadPart) QueryPerformanceFrequency(&s_freq);
    QueryPerformanceCounter(&now);
    if (s_last.QuadPart && (now.QuadPart - s_last.QuadPart) * 60 < s_freq.QuadPart) return;
    s_last = now;
    InterlockedIncrement(&g_doa2u_heartbeat);
    rt_sync();
    doa2u_movie_tick();
}

/* ── XAPI fibers -> host cooperative fibers ─────────────────────────── */
/* XAPI fibers backed by host coroutines (xbox_fiber.c), handles are
 * 0xF1BE0000|index, anything else means back to the dispatcher. */
extern int  xbox_fiber_create_dormant(uint32_t routine_va, uint32_t param, uint32_t stack_size);
extern void xbox_fiber_destroy(int idx);
extern void xbox_fiber_switch_direct(int idx);
#define XFIBER_TAG  0xF1BE0000u

void sub_002BEF18(void)   /* CreateFiber(stack_size, start_routine, param), stdcall ret 12 */
{
    uint32_t stack_sz = MEM32(esp + 4);
    uint32_t routine  = MEM32(esp + 8);
    uint32_t param    = MEM32(esp + 0xC);
    int idx = xbox_fiber_create_dormant(routine, param, stack_sz);
    eax = (idx > 0) ? (XFIBER_TAG | (uint32_t)idx) : 0;
    esp += 16;
}

void sub_002BEFA4(void)   /* DeleteFiber(handle), stdcall ret 4 */
{
    uint32_t h = MEM32(esp + 4);
    if ((h & 0xFFFF0000u) == XFIBER_TAG)
        xbox_fiber_destroy((int)(h & 0xFFFF));
    esp += 8;
}

void sub_002BEFB7(void)   /* SwitchToFiber(handle), stdcall ret 4 */
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

/* ── CRT memcpy (0x00339290) ────────────────────────────────────────── */
/* memcpy/memmove (0x339290): its jump-table tail can't be lifted; overlap-safe native copy. */
void sub_00339290(void)
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
static uint32_t g_pb_cb_arg[2];      /* 0x1D8C / 0x1D90: InsertCallback routine, context */
static uint32_t g_pb_cbq[64][2], g_pb_cbq_n;
static SRWLOCK  g_pb_cb_lock = SRWLOCK_INIT;
static LONG     s_gpu_irq;

/* Game thread: deliver a pending GPU interrupt as KeSetEvent on device+0x1DCC. */
void doa2u_gpu_irq_poll(void)
{
    if (s_gpu_irq && InterlockedExchange(&s_gpu_irq, 0)) {
        extern void xbox_fiber_wake(uint32_t event_va);
        uint32_t dev = MEM32(D3D_G_PDEVICE);
        if (dev) {
            MEM32(dev + 0x1DCC + 4) = 1;                 /* KEVENT SignalState */
            xbox_fiber_wake(dev + 0x1DCC);
        }
    }
}
static uint32_t g_zpass_acc;

/* Visibility tests: ZPASS count via a host occlusion query, GET_REPORT writes the
 * XDK report slot {time, count, done}; NOP 6/7 queues the inserted GPU callback. */
static void pb_side_method(uint32_t method, uint32_t param)
{
    extern void d3d8_OcclusionBegin(void);
    extern uint32_t d3d8_OcclusionEnd(void);
    switch (method) {
    case 0x17C8: if (param == 1) g_zpass_acc = 0; break;            /* CLEAR_REPORT_VALUE */
    case 0x17CC:                                                    /* ZPASS_PIXEL_COUNT_ENABLE */
        if (param) d3d8_OcclusionBegin(); else g_zpass_acc += d3d8_OcclusionEnd();
        break;
    case 0x17D0:                                                    /* GET_REPORT */
        {   /* Host heap pages sit above the 16 MB the 24-bit offset covers: match the
             * offset against the device's report pages (dev+0x7D4) instead. */
            uint32_t dev = MEM32(D3D_G_PDEVICE), va = 0, k;
            for (k = 0; dev && k < 64 && !va; k++) {
                uint32_t pg = MEM32(dev + 0x7D4 + k * 4);
                if (pg && !((pg ^ param) & 0x00FFF000u) && MEM32(pg + (param & 0xFF0u) + 0xC) == 0xFFFFFFFFu)
                    va = pg + (param & 0xFF0u);
            }
            if (va) {
                MEM32(va) = GetTickCount(); MEM32(va + 4) = 0;
                MEM32(va + 8) = g_zpass_acc;
                MEM32(va + 0xC) = 0;
            }
        }
        break;
    case 0x1D8C: g_pb_cb_arg[0] = param; break;
    case 0x1D90: g_pb_cb_arg[1] = param; break;
    case 0x0100:
        /* NOP 5: GPU interrupt for the push-buffer space wait (sub_0034DB88). */
        if (param == 5) InterlockedExchange(&s_gpu_irq, 1);
        AcquireSRWLockExclusive(&g_pb_cb_lock);
        if ((param == 6 || param == 7) && g_pb_cb_arg[0] && g_pb_cbq_n < 64) {
            g_pb_cbq[g_pb_cbq_n][0] = g_pb_cb_arg[0];
            g_pb_cbq[g_pb_cbq_n][1] = g_pb_cb_arg[1];
            g_pb_cbq_n++;
        }
        ReleaseSRWLockExclusive(&g_pb_cb_lock);
        break;
    }
}

/* Run the callbacks the translated commands reached, always on the game thread. */
static void pb_run_callbacks(void)
{
    uint32_t i, n, q[64][2];
    AcquireSRWLockExclusive(&g_pb_cb_lock);
    n = g_pb_cbq_n;
    memcpy(q, g_pb_cbq, n * sizeof q[0]);
    g_pb_cbq_n = 0;
    ReleaseSRWLockExclusive(&g_pb_cb_lock);
    for (i = 0; i < n; i++) {
        recomp_func_t fn = recomp_lookup_manual(q[i][0]);
        uint32_t sv[7] = { eax, ebx, ecx, edx, esi, edi, esp };
        if (!fn) fn = recomp_lookup(q[i][0]);
        if (!fn) continue;
        PUSH32(esp, q[i][1]);
        PUSH32(esp, 0);                       /* dummy return */
        fn();
        eax = sv[0]; ebx = sv[1]; ecx = sv[2]; edx = sv[3]; esi = sv[4]; edi = sv[5]; esp = sv[6];
    }
}

/* Drawing thread: KickOff queues the new commands and a second thread translates and presents
 * them, as the NV2A consumes the push buffer alongside the CPU. GET and fences follow its progress. */
typedef struct { uint32_t *w; uint32_t n, cap; uint32_t get, fence, done; int present; } RtItem;
#define RT_QN 16
static RtItem s_rtq[RT_QN];
static LONG s_rtq_head, s_rtq_tail, s_rt_busy;        /* head: producer, tail: consumer */
static SRWLOCK s_rt_lock = SRWLOCK_INIT;
static CONDITION_VARIABLE s_rt_cv_work = CONDITION_VARIABLE_INIT, s_rt_cv_done = CONDITION_VARIABLE_INIT;
static LONG s_rt_present_enq, s_rt_present_done;
static int s_rt_on = -1, s_rt_collecting;
static HANDLE s_rt_thread;

static void pb_exec_words(const uint32_t *w, uint32_t n);

static DWORD WINAPI rt_main(LPVOID unused)
{
    extern void pgraph_d3d11_flush(void);
    extern void doa2u_present_host(void);
    (void)unused;
    for (;;) {
        RtItem *it;
        AcquireSRWLockExclusive(&s_rt_lock);
        while (s_rtq_tail == s_rtq_head) SleepConditionVariableSRW(&s_rt_cv_work, &s_rt_lock, INFINITE, 0);
        it = &s_rtq[s_rtq_tail % RT_QN];
        s_rt_busy = 1;
        ReleaseSRWLockExclusive(&s_rt_lock);
        if (it->present) {
            extern void d3d8_frame_pace(void);
            pgraph_d3d11_flush();
            if (video_get_vsync()) d3d8_frame_pace();   /* VSync pacing, next to the present */
            doa2u_present_host();
            InterlockedIncrement(&s_rt_present_done);
        } else {
            pb_exec_words(it->w, it->n);
            MEM32(D3D_FAKE_CHANNEL + 0x44) = it->get;            /* DMA_GET: this batch consumed */
            if (it->done) {                                      /* its fences retired */
                MEM32(it->done) = it->fence - 2;
                nv2a_pgraph_set_reg(0xB10, (it->fence - 2) << 2);
            }
            /* The space wait patches its NOP-5 into already-copied commands: interrupt per batch. */
            InterlockedExchange(&s_gpu_irq, 1);
        }
        AcquireSRWLockExclusive(&s_rt_lock);
        s_rtq_tail++;
        s_rt_busy = 0;
        WakeAllConditionVariable(&s_rt_cv_done);
        ReleaseSRWLockExclusive(&s_rt_lock);
    }
}

static int rt_enabled(void)
{
    if (s_rt_on < 0) {
        s_rt_thread = CreateThread(NULL, 0, rt_main, NULL, 0, NULL);
        s_rt_on = s_rt_thread != NULL;
    }
    return s_rt_on;
}

/* Wait (pumping the window) until fewer than `items` slots are used and <= `presents` pending. */
static void rt_wait(LONG items, LONG presents)
{
    extern void doa2u_pump_messages(void);
    for (;;) {
        int ok;
        AcquireSRWLockExclusive(&s_rt_lock);
        ok = (s_rtq_head - s_rtq_tail) < items && (s_rt_present_enq - s_rt_present_done) <= presents;
        if (!ok) SleepConditionVariableSRW(&s_rt_cv_done, &s_rt_lock, 2, 0);
        ReleaseSRWLockExclusive(&s_rt_lock);
        if (ok) return;
        doa2u_pump_messages();
    }
}

/* Wait until everything queued is drawn (before game-thread use of the device). */
static void rt_sync(void)
{
    extern void doa2u_pump_messages(void);
    if (s_rt_on <= 0) return;
    for (;;) {
        int idle;
        AcquireSRWLockExclusive(&s_rt_lock);
        idle = s_rtq_head == s_rtq_tail && !s_rt_busy;
        if (!idle) SleepConditionVariableSRW(&s_rt_cv_done, &s_rt_lock, 2, 0);
        ReleaseSRWLockExclusive(&s_rt_lock);
        if (idle) return;
        doa2u_pump_messages();
    }
}

/* The slot KickOff fills; waits while the queue is full. */
static RtItem *rt_slot(void)
{
    RtItem *it;
    rt_wait(RT_QN, 0x7FFFFFFF);
    it = &s_rtq[s_rtq_head % RT_QN];
    it->n = 0; it->present = 0; it->done = 0;
    return it;
}

static void rt_append(RtItem *it, const uint32_t *w, uint32_t n)
{
    if (it->n + n > it->cap) {
        uint32_t cap = it->cap ? it->cap : 65536;
        while (cap < it->n + n) cap *= 2;
        it->w = (uint32_t *)realloc(it->w, (size_t)cap * 4);
        it->cap = cap;
    }
    memcpy(it->w + it->n, w, (size_t)n * 4);
    it->n += n;
}

static void rt_publish(void)
{
    AcquireSRWLockExclusive(&s_rt_lock);
    s_rtq_head++;
    WakeConditionVariable(&s_rt_cv_work);
    ReleaseSRWLockExclusive(&s_rt_lock);
}

static RtItem *s_rt_fill;   /* the batch KickOff is collecting into */

/* Translate [from, to). Stops at a JUMP/CALL/RETURN (wrap) and returns the
 * address it stopped at. */
static uint32_t pb_translate(uint32_t from, uint32_t to)
{
    extern int pgraph_d3d11_method(int subchannel, uint32_t method, uint32_t param);
    extern int pgraph_d3d11_method_bulk(uint32_t method, const uint32_t *params, uint32_t count);
    uint32_t pos = from;
    if (s_rt_collecting) {
        /* Same walk without executing: copy the complete packets for the drawing thread. */
        uint32_t good = from;
        while (pos + 4 <= to) {
            uint32_t word = MEM32(pos);
            if (word == 0) { pos += 4; good = pos; continue; }
            if ((word & 3) == 1 || (word & 0xE0000003u) == 0x20000000u || word == 0x00020000u ||
                (word & 3) == 2)
                break;                               /* jump / call / return: end of run */
            {
                uint32_t kind = word & 0xE0030003u;
                pos += 4;
                if (kind == 0 || kind == 0x40000000u) {
                    uint32_t count = (word >> 18) & 0x7FF;
                    if (pos + count * 4 > to) { pos = to; break; }
                    pos += count * 4;
                }
                good = pos;
            }
        }
        if (good > from) rt_append(s_rt_fill, (const uint32_t *)XBOX_PTR(from), (good - from) / 4);
        return pos;
    }
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
                /* Index and inline-vertex runs (no side effects in pb_side_method) in one call. */
                if ((kind == 0x40000000u || count == 1) &&
                    pgraph_d3d11_method_bulk(method, (const uint32_t *)XBOX_PTR(pos), count)) {
                    pos += count * 4;
                    continue;
                }
                for (i = 0; i < count; i++) {
                    uint32_t param = MEM32(pos), m = (kind == 0) ? method + i * 4 : method;
                    pos += 4;
                    pgraph_d3d11_method((int)subchan, m, param);
                    pb_side_method(m, param);
                }
            } else {
                pos += 4;
            }
        }
    }
    return pos;
}

/* Drawing thread: pb_translate over a copied batch (complete packets, no jumps). */
static void pb_exec_words(const uint32_t *w, uint32_t n)
{
    extern int pgraph_d3d11_method(int subchannel, uint32_t method, uint32_t param);
    extern int pgraph_d3d11_method_bulk(uint32_t method, const uint32_t *params, uint32_t count);
    uint32_t i = 0;
    while (i < n) {
        uint32_t word = w[i++], kind = word & 0xE0030003u;
        if (word == 0 || !(kind == 0 || kind == 0x40000000u)) continue;
        {
            uint32_t count = (word >> 18) & 0x7FF, method = word & 0x1FFC, subchan = (word >> 13) & 7, k;
            if (i + count > n) return;
            if ((kind == 0x40000000u || count == 1) && pgraph_d3d11_method_bulk(method, w + i, count)) {
                i += count;
                continue;
            }
            for (k = 0; k < count; k++) {
                uint32_t param = w[i++], m = (kind == 0) ? method + k * 4 : method;
                pgraph_d3d11_method((int)subchan, m, param);
                pb_side_method(m, param);
            }
        }
    }
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

void sub_0034D860(void)   /* CDevice_KickOff(this = ecx), ret */
{
    uint32_t dev = ecx;
    extern int doa2u_movie_active(void);
    if (dev && rt_enabled() && !doa2u_movie_active()) {
        uint32_t flags  = MEM32(dev + 8);
        uint32_t cursor = (flags & 4) ? MEM32(dev + 0x770) : MEM32(dev);
        RtItem *it = rt_slot();
        s_rt_fill = it;
        s_rt_collecting = 1;
        pb_translate_pending(dev, cursor);
        s_rt_collecting = 0;
        it->get = cursor & 0x0FFFFFFFu;
        it->fence = MEM32(dev + 0x2C);
        it->done = MEM32(dev + 0x30);
        MEM32(dev + 0x1C20) = D3D_FAKE_CHANNEL;
        MEM32(D3D_FAKE_CHANNEL + 0x40) = cursor & 0x0FFFFFFFu;   /* DMA_PUT */
        MEM32(dev + 0x1DE4) = MEM32(dev + 0x2478);
        rt_publish();
        pb_run_callbacks();
    } else if (dev) {
        uint32_t flags  = MEM32(dev + 8);
        uint32_t cursor = (flags & 4) ? MEM32(dev + 0x770) : MEM32(dev);
        rt_sync();
        perf_begin(PERF_TRANSLATE);
        pb_translate_pending(dev, cursor);
        perf_end(PERF_TRANSLATE);
        pb_run_callbacks();
        MEM32(dev + 0x1C20) = D3D_FAKE_CHANNEL;
        MEM32(D3D_FAKE_CHANNEL + 0x40) = cursor & 0x0FFFFFFFu;   /* DMA_PUT */
        MEM32(D3D_FAKE_CHANNEL + 0x44) = cursor & 0x0FFFFFFFu;   /* DMA_GET == PUT */
        {
            uint32_t done = MEM32(dev + 0x30);
            if (done) {                                          /* every inserted fence retired */
                MEM32(done) = MEM32(dev + 0x2C) - 2;
                nv2a_pgraph_set_reg(0xB10, (MEM32(dev + 0x2C) - 2) << 2);
            }
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

/* D3DDevice_Swap (0x0034E960): run the real Swap, present (or tick the movie),
 * then model the vblank (event + callback). */
void sub_0034E960(void)
{
    extern void sub_0034E960_gen(void);
    extern void pgraph_d3d11_flush(void);
    extern void doa2u_present_frame(void);
    extern void doa2u_movie_tick(void);
    extern int  doa2u_movie_active(void);
    uint32_t sv_esi = esi, sv_edi = edi, sv_ebx = ebx;
    uint32_t dev;
    sub_0034E960_gen();
    if (!video_get_vsync()) {   /* 60 Hz pacing: wait for the next 1/60 s boundary; resync if a frame or more behind. */
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
    } else if (!rt_enabled() || doa2u_movie_active()) {
        /* VSync: pace next to the present (d3d8_frame_pace); with the drawing thread presenting,
         * it paces there instead (rt_main). */
        extern void d3d8_frame_pace(void);
        rt_sync();
        d3d8_frame_pace();
    }
    {
        uint32_t ret_eax = eax, ret_esp = esp;
        dev = MEM32(D3D_G_PDEVICE);
        d3d_publish_vblank(dev);
        {   /* Host-EOF trigger: the guest Sofdec parks in PLAYING at a movie's end, so once
             * the presenter hits EOF set SFD state 6 / mwPly state 3 (PLAYEND). */
            extern int g_doa2u_host_movie_ended;
            uint32_t mp = MEM32(0xA9A678);                 /* mwPly handle */
            if (g_doa2u_host_movie_ended && mp >= 0x1000 && mp < 0x8000000u &&
                MEM32(mp + 8) == 2) {
                uint32_t sfd = MEM32(mp + 0x40);
                if (sfd >= 0x1000 && sfd < 0x8000000u && MEM32(sfd + 0x48) == 4) {
                    MEM32(sfd + 0x48) = 6;                 /* SFD handle: PLAYEND */
                    MEM32(mp + 8) = 3;                     /* movie object: finished */
                }
            }
        }
        if (doa2u_movie_active()) {
            extern volatile LONG g_doa2u_heartbeat;
            InterlockedIncrement(&g_doa2u_heartbeat);
            rt_sync();
            doa2u_movie_tick();
        } else if (rt_enabled()) {
            /* Hand the frame to the drawing thread and let the game run one frame ahead. */
            extern void doa2u_present_game_side(void);
            extern void doa2u_ui_build(void);
            RtItem *it;
            doa2u_present_game_side();
            doa2u_ui_build();
            if (g_perf_on) perf_frame();
            it = rt_slot();
            it->present = 1;
            InterlockedIncrement(&s_rt_present_enq);
            rt_publish();
            rt_wait(RT_QN + 1, 1);
            pb_run_callbacks();
        } else {
            pgraph_d3d11_flush();
            doa2u_present_frame();
        }
        {   extern void doa2u_rdtsc_frame(void); doa2u_rdtsc_frame(); }   /* one vblank of rdtsc time */
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
        {   /* Extras changed the profile: run the game's own save of the loaded
             * profile (sub_00023FC0, as after a settings change) on this thread. */
            extern int doa2u_extras_take_save_request(void);
            extern void sub_00023FC0(void);
            if (doa2u_extras_take_save_request()) {
                uint32_t saved = esp, sv_seh = g_seh_ebp;
                PUSH32(esp, 0);                     /* dummy return */
                sub_00023FC0();
                fprintf(stderr, "[EXTRAS] profile save -> %d\n", (int)eax);
                fflush(stderr);
                esp = saved; g_seh_ebp = sv_seh;
            }
        }
        eax = ret_eax; esp = ret_esp;
    }
    esi = sv_esi; edi = sv_edi; ebx = sv_ebx;
}

/* ── CRT _cinit (0x002C0C2C) ────────────────────────────────────────── */
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

void sub_002C0C2C(void)
{
    static const uint32_t tables[2][2] = {
        { 0x0049D638u, 0x0049D650u },   /* C initializers */
        { 0x0049D510u, 0x0049D634u },   /* C++ constructors */
    };
    uint32_t fp = MEM32(0x007CFA1Cu), p;
    int t;
    if (fp) cinit_call(fp, 0x007CFA1Cu);
    for (t = 0; t < 2; t++)
        for (p = tables[t][0]; p < tables[t][1]; p += 4) {
            uint32_t fn = MEM32(p);
            if (fn && fn != 0xFFFFFFFFu) cinit_call(fn, p);
        }
    fflush(stderr);
    esp += 4;   /* ret */
}

/* ADXF_GetPtStat (0x2FF2C0): the post-install mount spins on it
 * without yielding; pulse vblank and yield to the CRI workers until it's done. */
void sub_002FF2C0(void)
{
    extern void sub_002FF2C0_gen(void);
    extern uint32_t g_xbox_vblank_event_va;
    sub_002FF2C0_gen();
    if (eax != 3) {
        if (g_xbox_vblank_event_va) {
            MEM32(g_xbox_vblank_event_va + 4) = 1;  /* vblank KEVENT.SignalState */
            xbox_fiber_wake(g_xbox_vblank_event_va);
        }
        {   /* no presents happen during this spin -- service the window so it
             * doesn't go "Not Responding" under the user's clicks */
            extern void doa2u_pump_messages(void);
            static unsigned s_mp2 = 0;
            if ((++s_mp2 & 63) == 0) doa2u_pump_messages();
        }
        if (xbox_fiber_active())
            xbox_fiber_yield();
    }
}

/* ── XPP (Xbox Peripheral Port) input overrides — host-backed pads ─────────
 * There is no USB stack behind the XAPI pad calls, so the
 * gamepad ones are served from the host (src/input xbox_InputGetState: XInput
 * pads plus the Esc-menu keyboard mapping on port 0). Names from
 * tools/recomp/doa2u_cxbx_symbols.ini.
 *
 * The game's pad structs: base 0xA94838, stride 0x80. +0x00 caps blob
 * (XInputGetCapabilities), +0x19 XINPUT_STATE (XInputGetState), +0x2F
 * XINPUT_FEEDBACK (rumble motors at +0x71/+0x73), +0x78 XInputOpen handle.
 * Opened/polled by sub_000FC550 (boot) and sub_000FC640 (every frame).
 * Other device types (memory units, 0x3BBDC0) keep the generated bodies. */
#define XPP_TYPE_GAMEPAD  0x003BBE3Cu
#define XPP_HANDLE_BASE   0x0AD00001u   /* fake but consistent nonzero handles */

static uint32_t s_xpp_prev_mask;   /* XGetDeviceChanges baseline (real XAPI PreviousConnected) */

static int xpp_handle_port(uint32_t h)
{
    return (h >= XPP_HANDLE_BASE && h < XPP_HANDLE_BASE + 4) ? (int)(h - XPP_HANDLE_BASE) : -1;
}

void sub_003BD2F3_gen(void);
void sub_003BD2F3(void)   /* XGetDevices(type) -> connected mask, stdcall ret 4 */
{
    extern DWORD xbox_InputHostMask(void);
    if (MEM32(esp + 4) != XPP_TYPE_GAMEPAD) { sub_003BD2F3_gen(); return; }
    /* Real XAPI semantics (cxbx Xapi.cpp): reporting the connected set also
     * resets the change baseline, so XGetDeviceChanges does not re-report
     * these pads as insertions. */
    s_xpp_prev_mask = xbox_InputHostMask();
    eax = s_xpp_prev_mask;
    esp += 8;
}

void sub_003BD315_gen(void);
void sub_003BD315(void)   /* XGetDeviceChanges(type, &ins, &rem), stdcall ret 12 */
{
    extern DWORD xbox_InputHostMask(void);
    uint32_t p_ins, p_rem, cur, ins, rem;
    if (MEM32(esp + 4) != XPP_TYPE_GAMEPAD) { sub_003BD315_gen(); return; }
    /* Both outputs are written on every call -- zero when nothing changed. */
    p_ins = MEM32(esp + 8);
    p_rem = MEM32(esp + 12);
    cur = xbox_InputHostMask();
    ins = cur & ~s_xpp_prev_mask;
    rem = s_xpp_prev_mask & ~cur;
    s_xpp_prev_mask = cur;
    if (p_ins) MEM32(p_ins) = ins;
    if (p_rem) MEM32(p_rem) = rem;
    eax = (ins | rem) ? 1u : 0u;
    esp += 16;
}

void sub_003BD7F2_gen(void);
void sub_003BD7F2(void)   /* XInputOpen(type, port, slot, params) -> handle, stdcall ret 16 */
{
    uint32_t port = MEM32(esp + 8);
    if (MEM32(esp + 4) != XPP_TYPE_GAMEPAD) { sub_003BD7F2_gen(); return; }
    eax = port < 4 ? XPP_HANDLE_BASE + port : 0;
    esp += 20;
}

void sub_003BD848_gen(void);
void sub_003BD848(void)   /* XInputClose(handle), stdcall ret 4 */
{
    if (xpp_handle_port(MEM32(esp + 4)) < 0) { sub_003BD848_gen(); return; }
    eax = 0;
    esp += 8;
}

void sub_003BD854_gen(void);
void sub_003BD854(void)   /* XInputGetCapabilities(handle, caps), stdcall ret 8 */
{
    uint32_t caps = MEM32(esp + 8), i;
    if (xpp_handle_port(MEM32(esp + 4)) < 0) { sub_003BD854_gen(); return; }
    if (caps) {
        for (i = 0; i < 0x19; i++) MEM8(caps + i) = 0;
        MEM8(caps) = 1;   /* XINPUT_DEVSUBTYPE_GC_GAMEPAD */
    }
    eax = 0;
    esp += 12;
}

void sub_003BDA2C_gen(void);
void sub_003BDA2C(void)   /* XInputGetState(handle, state), stdcall ret 8 */
{
    extern DWORD xbox_InputGetState(DWORD, void *);
    static uint32_t s_packet = 0x1000;
    uint32_t st = MEM32(esp + 8);
    int port = xpp_handle_port(MEM32(esp + 4)), i;
    uint8_t raw[24] = {0};   /* XBOX_INPUT_STATE: packet, wButtons, 8 analog, 4 thumbs */
    if (port < 0) { sub_003BDA2C_gen(); return; }
    if (xbox_InputGetState((DWORD)port, raw) != 0) {
        eax = 0x48F;   /* ERROR_DEVICE_NOT_CONNECTED */
        esp += 12;
        return;
    }
    if (st) {
        MEM32(st) = ++s_packet;                       /* dwPacketNumber */
        for (i = 0; i < 18; i++) MEM8(st + 4 + i) = raw[4 + i];   /* XINPUT_GAMEPAD */
    }
    eax = 0;
    esp += 12;
}

void sub_003BDA9F_gen(void);
void sub_003BDA9F(void)   /* XInputSetState(handle, feedback), stdcall ret 8 */
{
    extern DWORD xbox_InputSetState(DWORD, const void *);
    uint32_t fb = MEM32(esp + 8);
    int port = xpp_handle_port(MEM32(esp + 4));
    if (port < 0) { sub_003BDA9F_gen(); return; }
    if (fb) {
        /* XINPUT_FEEDBACK: Status at +0, rumble motors after the 0x42-byte
         * header. The real call completes asynchronously (Status 0x3E5 until
         * then); this one completes at once. */
        uint16_t motors[2];
        motors[0] = MEM16(fb + 0x42);
        motors[1] = MEM16(fb + 0x44);
        xbox_InputSetState((DWORD)port, motors);
        MEM32(fb) = 0;
    }
    eax = 0;
    esp += 12;
}

/* ── Startup hook (main.c, before the entry point) ──────────────────── */
/* Legal screen (0xDB380) stubbed. On a first boot, wait here a game frame at a time
 * for the HDD cache copy (it pauses during movies), then go on to the Team Ninja FMV. */
void sub_000DB380(void)
{
    extern uint32_t g_xbox_cache_install_routine;
    extern int xbox_fiber_thread_alive(uint32_t ctx1);
    while (MEM32(0x8AFCA8) && g_xbox_cache_install_routine &&
           xbox_fiber_thread_alive(g_xbox_cache_install_routine)) {
        PUSH32(esp, 1);
        PUSH32(esp, 0);
        sub_000FC350();
        esp += 4;
    }
    esp += 4;   /* ret */
}

void doa2u_game_init(void)
{
    /* The device is the static 0x358EE0, so its vblank event is known before the first Swap. */
    extern uint32_t g_xbox_vblank_event_va;
    extern uint32_t g_xbox_cache_install_routine;
    extern volatile int g_fib_slice_due;
    g_xbox_vblank_event_va = 0x00358EE0u + DEV_VBLANK_EVENT_OFS;
    /* First-boot HDD cache copy worker, started by sub_000F9240. */
    g_xbox_cache_install_routine = 0x000F8F70u;
    g_fib_slice_due = 1;   /* first slice check starts the 4 ms slice timer */
}
