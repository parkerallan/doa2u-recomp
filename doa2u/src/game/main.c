/**
 * Dead or Alive 2 Ultimate - Recompiled Game Host Entry Point
 *
 * Boots the statically-recompiled DOA2.xbe on Windows:
 *   load XBE -> map Xbox memory -> kernel init -> install fault-skip VEH ->
 *   host window + D3D8->D3D11 device + APU/DirectSound -> fibers ->
 *   call recompiled entry point (xbe_entry_point = mainCRTStartup @ 0x002BBB93).
 *
 * Ported from the DOA3 port's main.c (same runtime libraries). The XDK 5849
 * CRT startup (mainXapiStartup @ 0x002BBB1F) runs _rtinit/_cinit itself, so
 * unlike DOA3 the static initializer tables are not walked here.
 *
 * The VEH decoders (veh_skip_faulting_read / _write) come from the burnout3
 * reference via DOA3: they decode a faulting x86-64 instruction, return 0 for
 * reads (and skip stores), and advance RIP so wild guest pointers do not kill
 * the process.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "../kernel/kernel.h"
#include "../kernel/xbox_memory_layout.h"
#include "../kernel/xbox_fiber.h"
#include "../d3d/d3d8_xbox.h"
#include "../audio/dsound_xbox.h"
#include "recomp/gen/recomp_funcs.h"
#include "recomp/recomp_dispatch.h"
#include "video_settings.h"
#include "log_settings.h"

#define DOA2U_ENTRY_POINT  0x002BBB93
/* Game files live in assets next to the exe (the disc root); D: maps to assets. */
#define DOA2U_XBE_PATH     "assets/DOA2.xbe"

static HWND          g_hwnd;
static IDirect3D8   *g_d3d8;
static IDirect3DDevice8 *g_d3d_device;
static IDirectSound8 *g_dsound;

static LRESULT CALLBACK doa2u_wndproc(HWND h, UINT m, WPARAM w, LPARAM l)
{
    if (m == WM_CLOSE)   { DestroyWindow(h); return 0; }
    if (m == WM_DESTROY) { PostQuitMessage(0); return 0; }
    return DefWindowProcA(h, m, w, l);
}

static HWND doa2u_create_window(void)
{
    WNDCLASSEXA wc; RECT r = { 0, 0, 640, 480 };
    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.lpfnWndProc = doa2u_wndproc;
    wc.hInstance = GetModuleHandleA(NULL);
    wc.lpszClassName = "DOA2UWindow";
    wc.hCursor = LoadCursorA(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClassExA(&wc);
    AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);
    HWND h = CreateWindowExA(0, "DOA2UWindow", "Dead or Alive 2 Ultimate",
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             r.right - r.left, r.bottom - r.top, NULL, NULL,
                             wc.hInstance, NULL);
    if (h) { video_apply_window_mode(h, video_get_window_mode()); UpdateWindow(h); }
    return h;
}

/* Create the D3D8->D3D11 device the NV2A pgraph translator and the movie
 * presenter render through. */
static int doa2u_init_graphics(void)
{
    D3DPRESENT_PARAMETERS pp;
    HRESULT hr;
    unsigned gw, gh;

    video_settings_load();
    video_guest_target_size(video_get_aspect(), &gw, &gh);
    g_hwnd = doa2u_create_window();
    if (!g_hwnd) { fprintf(stderr, "WARNING: window creation failed\n"); }

    g_d3d8 = xbox_Direct3DCreate8(0);
    if (!g_d3d8) { fprintf(stderr, "WARNING: xbox_Direct3DCreate8 failed\n"); return 0; }

    memset(&pp, 0, sizeof(pp));
    pp.BackBufferWidth = gw;
    pp.BackBufferHeight = gh;
    pp.BackBufferFormat = D3DFMT_X8R8G8B8;
    pp.BackBufferCount = 1;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.hDeviceWindow = g_hwnd;
    pp.Windowed = TRUE;
    pp.EnableAutoDepthStencil = TRUE;
    pp.AutoDepthStencilFormat = D3DFMT_D24S8;

    hr = g_d3d8->lpVtbl->CreateDevice(g_d3d8, 0, 0, g_hwnd, 0, &pp, &g_d3d_device);
    if (FAILED(hr)) { fprintf(stderr, "WARNING: CreateDevice failed 0x%08lX\n", (unsigned long)hr); return 0; }

    { extern void pgraph_d3d11_init(void); pgraph_d3d11_init(); }
    fprintf(stderr, "  Graphics: D3D8->D3D11 device created (guest target %ux%u)\n", gw, gh);
    return 1;
}

/* Service the window's message queue without presenting (load spins). */
void doa3_pump_messages(void)
{
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            fprintf(stderr, "[EXIT] window closed by user\n");
            fflush(stderr);
            ExitProcess(0);
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}

/* ── Hang watchdog ────────────────────────────────────────────────────────
 * Non-faulting hangs leave nothing to catch, so sample the guest thread:
 * g_doa3_heartbeat is bumped once per present; if it stops moving, read the
 * guest thread's RIP and the recompiler registers. Resolve the RIP against
 * build/debug/DOA2U.map ("Rva+Base"). */
volatile LONG g_doa3_heartbeat = 0;
static HANDLE g_guest_thread;

static DWORD WINAPI doa2u_watchdog(LPVOID unused)
{
    LONG last = -1; int stalled = 0, reports = 0;
    (void)unused;
    for (;;) {
        LONG now;
        Sleep(2000);
        now = g_doa3_heartbeat;
        if (now != last) { last = now; stalled = 0; continue; }
        if (++stalled < 3 || reports >= 10) continue;   /* ~6s of no progress */
        reports++;
        {
            CONTEXT ctx;
            int got = 0;
            memset(&ctx, 0, sizeof ctx);
            ctx.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
            /* Capture only while suspended; no stdio (the guest may hold the
             * CRT stream lock). */
            uintptr_t frames[16]; int nf = 0;
            if (SuspendThread(g_guest_thread) != (DWORD)-1) {
                got = GetThreadContext(g_guest_thread, &ctx);
                if (got) {
                    /* Return addresses into our image on the suspended stack (heuristic; reads only). */
                    uintptr_t lo = (uintptr_t)GetModuleHandleA(NULL);
                    uintptr_t *sp = (uintptr_t *)ctx.Rsp;
                    MEMORY_BASIC_INFORMATION mbi;
                    if (VirtualQuery(sp, &mbi, sizeof mbi)) {
                        uintptr_t *end = (uintptr_t *)((uintptr_t)mbi.BaseAddress + mbi.RegionSize);
                        for (; sp < end && nf < 16; sp++)
                            if (*sp > lo + 0x1000 && *sp < lo + 0x3000000)
                                frames[nf++] = *sp - lo;
                    }
                }
                ResumeThread(g_guest_thread);
            }
            if (got && nf) {
                int k;
                fprintf(stderr, "[WDOG] stack rvas:");
                for (k = 0; k < nf; k++) fprintf(stderr, " %llX", (unsigned long long)frames[k]);
                fprintf(stderr, "\n");
            }
            if (got)
                fprintf(stderr,
                        "[WDOG] STALLED %ds at heartbeat %ld: rip=0x%llX rsp=0x%llX | "
                        "guest eax=%08X ecx=%08X edx=%08X ebx=%08X esp=%08X esi=%08X edi=%08X sehebp=%08X\n",
                        stalled * 2, (long)now,
                        (unsigned long long)ctx.Rip, (unsigned long long)ctx.Rsp,
                        g_eax, g_ecx, g_edx, g_ebx, g_esp, g_esi, g_edi, g_seh_ebp);
            else
                fprintf(stderr, "[WDOG] STALLED but could not read guest context\n");
            if (reports <= 2) {
                extern void xbox_fiber_dump(void);
                xbox_fiber_dump();
            }
            { extern void xbox_kernel_dump_primary(void); xbox_kernel_dump_primary(); }
            fflush(stderr);
        }
    }
}

static void doa2u_watchdog_start(void)
{
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(),
                    GetCurrentProcess(), &g_guest_thread,
                    0, FALSE, DUPLICATE_SAME_ACCESS);
    if (g_guest_thread) {
        HANDLE h = CreateThread(NULL, 0, doa2u_watchdog, NULL, 0, NULL);
        if (h) CloseHandle(h);
    }
}

/* Present the host swap chain once per guest frame (called from the
 * D3DDevice_Swap override in recomp_manual.c) and pump the window. */
void doa3_present_frame(void)
{
    InterlockedIncrement(&g_doa3_heartbeat);
    { extern void doa3_apu_deliver_irq(void); doa3_apu_deliver_irq(); }
    doa3_pump_messages();
    {
        extern int doa3_movie_host_owns_screen(void);
        if (doa3_movie_host_owns_screen())
            return;   /* the movie presenter owns the swap chain */
    }
    if (g_d3d_device)
        g_d3d_device->lpVtbl->Present(g_d3d_device, NULL, NULL, NULL, NULL);
}

extern volatile uint32_t g_icall_trace[16];
extern volatile uint32_t g_icall_trace_idx;
extern volatile uint64_t g_icall_count;

/* ── Fault-skip decoders (burnout3 via DOA3, verbatim) ── */
/* ── Fault-skip decoders (ported verbatim from burnout3/src/game/main.c) ── */
static BOOL veh_skip_faulting_read(PCONTEXT ctx)
{
    uint8_t *rip = (uint8_t *)ctx->Rip;
    int prefix_len = 0;
    int rex_w = 0, rex_r = 0, rex_x = 0, rex_b = 0;

    /* Map register index to CONTEXT field */
    DWORD64 *gpr[] = {
        &ctx->Rax, &ctx->Rcx, &ctx->Rdx, &ctx->Rbx,
        &ctx->Rsp, &ctx->Rbp, &ctx->Rsi, &ctx->Rdi,
        &ctx->R8,  &ctx->R9,  &ctx->R10, &ctx->R11,
        &ctx->R12, &ctx->R13, &ctx->R14, &ctx->R15
    };

    /* Parse legacy prefixes (segment, operand size, etc.) */
    while (prefix_len < 4) {
        uint8_t b = rip[prefix_len];
        if (b == 0x66 || b == 0x67 || b == 0xF2 || b == 0xF3 ||
            b == 0x2E || b == 0x3E || b == 0x26 || b == 0x36 ||
            b == 0x64 || b == 0x65) {
            prefix_len++;
        } else {
            break;
        }
    }

    /* Parse REX prefix (0x40-0x4F) */
    if ((rip[prefix_len] & 0xF0) == 0x40) {
        uint8_t rex = rip[prefix_len];
        rex_w = (rex >> 3) & 1;
        rex_r = (rex >> 2) & 1;
        rex_x = (rex >> 1) & 1;
        rex_b = rex & 1;
        prefix_len++;
    }

    uint8_t *op = rip + prefix_len;

    /* Calculate ModRM displacement length */
    /* Returns total bytes for modrm + optional SIB + displacement */
    #define MODRM_LEN(modrm_byte) do { \
        int _mod = ((modrm_byte) >> 6) & 3; \
        int _rm  = ((modrm_byte) & 7) | (rex_b << 3); \
        modrm_total = 1; /* modrm byte itself */ \
        if (_mod == 0 && (_rm & 7) == 4) modrm_total++; /* SIB */ \
        if (_mod == 0 && (_rm & 7) == 5) modrm_total += 4; /* RIP-rel disp32 */ \
        if (_mod == 1) { modrm_total++; if ((_rm & 7) == 4) modrm_total++; } \
        if (_mod == 2) { modrm_total += 4; if ((_rm & 7) == 4) modrm_total++; } \
        if (_mod == 3) modrm_total = 1; /* reg-reg, shouldn't fault */ \
    } while(0)

    int modrm_total = 0;
    int reg_idx;

    /* 8B /r : mov r32/r64, r/m32/r/m64 */
    if (op[0] == 0x8B) {
        reg_idx = ((op[1] >> 3) & 7) | (rex_r << 3);
        MODRM_LEN(op[1]);
        *gpr[reg_idx] = 0;
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* 8A /r : mov r8, r/m8 */
    if (op[0] == 0x8A) {
        reg_idx = ((op[1] >> 3) & 7) | (rex_r << 3);
        MODRM_LEN(op[1]);
        /* Zero just the low byte of the register */
        *gpr[reg_idx] &= ~(DWORD64)0xFF;
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* 0F B6 /r : movzx r32, r/m8 */
    /* 0F B7 /r : movzx r32, r/m16 */
    /* 0F BE /r : movsx r32, r/m8 */
    /* 0F BF /r : movsx r32, r/m16 */
    if (op[0] == 0x0F && (op[1] == 0xB6 || op[1] == 0xB7 ||
                           op[1] == 0xBE || op[1] == 0xBF)) {
        reg_idx = ((op[2] >> 3) & 7) | (rex_r << 3);
        MODRM_LEN(op[2]);
        *gpr[reg_idx] = 0;
        ctx->Rip += prefix_len + 2 + modrm_total;
        return TRUE;
    }

    /* 3B /r : cmp r32, r/m32 - set flags as if comparing with 0 */
    if (op[0] == 0x3B) {
        reg_idx = ((op[1] >> 3) & 7) | (rex_r << 3);
        MODRM_LEN(op[1]);
        /* Set ZF=0, CF based on comparison with 0 */
        DWORD64 val = *gpr[reg_idx];
        ctx->EFlags &= ~(0x8D5);  /* clear OF, SF, ZF, AF, PF, CF */
        if (val == 0) ctx->EFlags |= 0x40;  /* ZF */
        if (val & (rex_w ? 0x8000000000000000ULL : 0x80000000ULL))
            ctx->EFlags |= 0x80;  /* SF */
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* 39 /r : cmp r/m32, r32 - set flags as if mem=0 */
    if (op[0] == 0x39) {
        reg_idx = ((op[1] >> 3) & 7) | (rex_r << 3);
        MODRM_LEN(op[1]);
        DWORD64 val = *gpr[reg_idx];
        ctx->EFlags &= ~(0x8D5);
        if (val == 0) ctx->EFlags |= 0x40;  /* ZF: 0 == val */
        /* 0 - val: CF set if val != 0 */
        if (val != 0) ctx->EFlags |= 0x01;  /* CF */
        /* SF: sign of (0 - val) */
        DWORD64 result = (rex_w ? (DWORD64)(-(int64_t)val) : (DWORD64)(uint32_t)(-(int32_t)(uint32_t)val));
        if (result & (rex_w ? 0x8000000000000000ULL : 0x80000000ULL))
            ctx->EFlags |= 0x80;  /* SF */
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* SSE instructions with memory operands.
     * These use legacy prefixes (F3/F2/66/none) + 0F opcode + modrm.
     * For faulting memory reads, zero the destination XMM register
     * and advance RIP to let execution continue.
     */
    {
        int has_f3 = 0, has_f2 = 0, has_66 = 0;
        for (int i = 0; i < prefix_len; i++) {
            if (rip[i] == 0xF3) has_f3 = 1;
            if (rip[i] == 0xF2) has_f2 = 1;
            if (rip[i] == 0x66) has_66 = 1;
        }

        if (op[0] == 0x0F) {
            int is_sse_mem_read = 0;

            /* F3 0F xx: scalar single-precision */
            if (has_f3) {
                switch (op[1]) {
                case 0x10: /* movss xmm, m32 */
                case 0x58: /* addss xmm, m32 */
                case 0x59: /* mulss xmm, m32 */
                case 0x5C: /* subss xmm, m32 */
                case 0x5E: /* divss xmm, m32 */
                case 0x51: /* sqrtss xmm, m32 */
                case 0x5D: /* minss xmm, m32 */
                case 0x5F: /* maxss xmm, m32 */
                case 0x2A: /* cvtsi2ss xmm, r/m32 */
                case 0x2C: /* cvttss2si r32, xmm/m32 */
                case 0x2D: /* cvtss2si r32, xmm/m32 */
                    is_sse_mem_read = 1;
                    break;
                }
            }
            /* F2 0F xx: scalar double-precision */
            else if (has_f2) {
                switch (op[1]) {
                case 0x10: /* movsd xmm, m64 */
                case 0x58: /* addsd */
                case 0x59: /* mulsd */
                case 0x5C: /* subsd */
                case 0x5E: /* divsd */
                    is_sse_mem_read = 1;
                    break;
                }
            }
            /* 66 0F xx: packed double / integer */
            else if (has_66) {
                switch (op[1]) {
                case 0x28: /* movapd xmm, m128 */
                case 0x10: /* movupd xmm, m128 */
                case 0x6F: /* movdqa xmm, m128 */
                    is_sse_mem_read = 1;
                    break;
                }
            }
            /* No prefix: packed single-precision */
            else {
                switch (op[1]) {
                case 0x28: /* movaps xmm, m128 */
                case 0x10: /* movups xmm, m128 */
                case 0x58: /* addps xmm, m128 */
                case 0x59: /* mulps xmm, m128 */
                case 0x5C: /* subps xmm, m128 */
                case 0x5E: /* divps xmm, m128 */
                    is_sse_mem_read = 1;
                    break;
                }
            }

            if (is_sse_mem_read) {
                int xmm_idx = ((op[2] >> 3) & 7) | (rex_r << 3);
                MODRM_LEN(op[2]);

                /* For cvttss2si/cvtss2si, dest is GPR, not XMM */
                if ((has_f3 && (op[1] == 0x2C || op[1] == 0x2D))) {
                    *gpr[xmm_idx] = 0;
                } else if (xmm_idx < 16) {
                    M128A *xmm = &ctx->Xmm0 + xmm_idx;
                    xmm->Low = 0;
                    xmm->High = 0;
                }
                ctx->Rip += prefix_len + 2 + modrm_total;
                return TRUE;
            }
        }
    }

    #undef MODRM_LEN
    return FALSE;
}

/**
 * Skip a faulting write instruction by advancing RIP past it.
 * Unlike read skips, write skips don't need to set a register.
 * Handles common store instructions: mov r/m, r and mov r/m, imm.
 */
static BOOL veh_skip_faulting_write(PCONTEXT ctx)
{
    uint8_t *rip = (uint8_t *)ctx->Rip;
    int prefix_len = 0;
    int rex_w = 0, rex_r = 0, rex_b = 0;

    /* Parse legacy prefixes */
    while (prefix_len < 4) {
        uint8_t b = rip[prefix_len];
        if (b == 0x66 || b == 0x67 || b == 0xF2 || b == 0xF3 ||
            b == 0x2E || b == 0x3E || b == 0x26 || b == 0x36 ||
            b == 0x64 || b == 0x65) {
            prefix_len++;
        } else {
            break;
        }
    }

    /* Parse REX prefix */
    if ((rip[prefix_len] & 0xF0) == 0x40) {
        uint8_t rex = rip[prefix_len];
        rex_w = (rex >> 3) & 1;
        rex_r = (rex >> 2) & 1;
        rex_b = rex & 1;
        prefix_len++;
    }

    uint8_t *op = rip + prefix_len;
    int modrm_total = 0;

    #define MODRM_LEN(modrm_byte) do { \
        int _mod = ((modrm_byte) >> 6) & 3; \
        int _rm  = ((modrm_byte) & 7) | (rex_b << 3); \
        modrm_total = 1; \
        if (_mod == 0 && (_rm & 7) == 4) modrm_total++; \
        if (_mod == 0 && (_rm & 7) == 5) modrm_total += 4; \
        if (_mod == 1) { modrm_total++; if ((_rm & 7) == 4) modrm_total++; } \
        if (_mod == 2) { modrm_total += 4; if ((_rm & 7) == 4) modrm_total++; } \
        if (_mod == 3) modrm_total = 1; \
    } while(0)

    (void)rex_r; (void)rex_w;

    /* 89 /r : mov r/m32, r32 */
    if (op[0] == 0x89) {
        MODRM_LEN(op[1]);
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* 88 /r : mov r/m8, r8 */
    if (op[0] == 0x88) {
        MODRM_LEN(op[1]);
        ctx->Rip += prefix_len + 1 + modrm_total;
        return TRUE;
    }

    /* C7 /0 id : mov r/m32, imm32 */
    if (op[0] == 0xC7) {
        MODRM_LEN(op[1]);
        ctx->Rip += prefix_len + 1 + modrm_total + 4;
        return TRUE;
    }

    /* C6 /0 ib : mov r/m8, imm8 */
    if (op[0] == 0xC6) {
        MODRM_LEN(op[1]);
        ctx->Rip += prefix_len + 1 + modrm_total + 1;
        return TRUE;
    }

    /* 66 89 /r : mov r/m16, r16 (handled via 0x66 prefix + 89) */
    /* Already handled above since 0x66 is parsed as prefix */

    /* 0F 11 /r : movups xmm, m128 (SSE store) */
    if (op[0] == 0x0F && op[1] == 0x11) {
        MODRM_LEN(op[2]);
        ctx->Rip += prefix_len + 2 + modrm_total;
        return TRUE;
    }

    /* F3 0F 11 /r : movss m32, xmm (SSE scalar store) */
    {
        int has_f3 = 0;
        for (int i = 0; i < prefix_len; i++) {
            if (rip[i] == 0xF3) has_f3 = 1;
        }
        if (has_f3 && op[0] == 0x0F && op[1] == 0x11) {
            MODRM_LEN(op[2]);
            ctx->Rip += prefix_len + 2 + modrm_total;
            return TRUE;
        }

        /* F3 A4 : rep movsb (inline memcpy)
         * F3 A5 : rep movsd (inline memcpy, 4-byte)
         * F3 AA : rep stosb (inline memset)
         * F3 AB : rep stosd (inline memset, 4-byte)
         *
         * Cancel remaining iterations: set RCX=0, advance RSI/RDI past
         * the unmapped region. The rep prefix with RCX=0 is a no-op,
         * so the CPU will naturally advance RIP past the instruction.
         * Assumes DF=0 (CLD), which is standard for MSVC code.
         */
        if (has_f3 && (op[0] == 0xA4 || op[0] == 0xA5)) {
            /* rep movsb / rep movsd */
            uint64_t stride = (op[0] == 0xA5) ? 4 : 1;
            uint64_t remaining = ctx->Rcx * stride;
            ctx->Rcx = 0;
            ctx->Rsi += remaining;
            ctx->Rdi += remaining;
            return TRUE;
        }
        if (has_f3 && (op[0] == 0xAA || op[0] == 0xAB)) {
            /* rep stosb / rep stosd */
            uint64_t stride = (op[0] == 0xAB) ? 4 : 1;
            uint64_t remaining = ctx->Rcx * stride;
            ctx->Rcx = 0;
            ctx->Rdi += remaining;
            return TRUE;
        }
    }

    #undef MODRM_LEN
    return FALSE;
}

/* ── Crash / fault-skip VEH ─────────────────────────────────────── */

static uint64_t g_fault_skips = 0;
static uint64_t g_fault_logged = 0;

/* Write watch (diagnostic): DOA2U_WATCHVA=<hex guest VA> logs every write to that dword
 * (writer RVA + value) across all RAM views. */
static uint32_t g_watch_off = 0;        /* offset of the watched dword inside a RAM view */
static int g_watch_on = 0;
static volatile int g_watch_step = 0;   /* re-protect after the single step */
static uintptr_t g_watch_rip = 0, g_watch_addr = 0;
static int g_watch_hits = 0;

/* The page is protected in the base RAM view and in every mirror view, so a
 * write through an alias (0x80000000 cached window, 64 MB mirrors) is seen. */
static void watch_protect(DWORD prot)
{
    uintptr_t base = (uintptr_t)xbox_GetMemoryBase();
    size_t sz = xbox_GetMemorySize();
    DWORD old; int m;
    for (m = 0; m <= XBOX_NUM_MIRRORS; m++)
        VirtualProtect((LPVOID)(base + (uintptr_t)m * sz + (g_watch_off & ~0xFFFu)), 0x1000, prot, &old);
}

static void watch_init(void)
{
    const char *e = getenv("DOA2U_WATCHVA");
    if (!e) return;
    g_watch_off = (uint32_t)strtoul(e, NULL, 16) % (uint32_t)xbox_GetMemorySize();
    g_watch_on = 1;
    watch_protect(PAGE_READONLY);
    fprintf(stderr, "[WATCH] guest 0x%s armed (all views)\n", e);
}

static int watch_veh(PEXCEPTION_POINTERS info)
{
    DWORD code = info->ExceptionRecord->ExceptionCode;
    if (!g_watch_on) return 0;
    if (code == EXCEPTION_SINGLE_STEP && g_watch_step) {
        g_watch_step = 0;
        if (g_watch_rip && g_watch_hits < 200) {
            g_watch_hits++;
            fprintf(stderr, "[WATCH] rva 0x%llX stored %08X via host %llX (guest esp %08X)\n",
                    (unsigned long long)(g_watch_rip - (uintptr_t)GetModuleHandleA(NULL)),
                    *(volatile uint32_t *)g_watch_addr, (unsigned long long)g_watch_addr, g_esp);
        }
        g_watch_rip = 0;
        watch_protect(PAGE_READONLY);
        return 1;
    }
    if (code == EXCEPTION_ACCESS_VIOLATION && info->ExceptionRecord->ExceptionInformation[0]) {
        uintptr_t f = info->ExceptionRecord->ExceptionInformation[1];
        uintptr_t base = (uintptr_t)xbox_GetMemoryBase();
        size_t sz = xbox_GetMemorySize();
        if (f >= base && f < base + (uintptr_t)(XBOX_NUM_MIRRORS + 1) * sz) {
            uint32_t off = (uint32_t)((f - base) % sz);
            if ((off & ~0xFFFu) == (g_watch_off & ~0xFFFu)) {
                if (off + 4 > g_watch_off && off < g_watch_off + 4) {
                    g_watch_rip = (uintptr_t)info->ContextRecord->Rip;
                    g_watch_addr = f - off + g_watch_off;
                }
                watch_protect(PAGE_READWRITE);
                info->ContextRecord->EFlags |= 0x100;   /* single-step the store */
                g_watch_step = 1;
                return 1;
            }
        }
    }
    return 0;
}

static LONG WINAPI crash_veh(PEXCEPTION_POINTERS info)
{
    DWORD code = info->ExceptionRecord->ExceptionCode;
    if (watch_veh(info)) return EXCEPTION_CONTINUE_EXECUTION;
    if (code == STATUS_GUARD_PAGE_VIOLATION) {
        /* A wild pointer landed in a fiber stack's guard region; Windows has
         * already cleared PAGE_GUARD, so resuming retries the access. */
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    /* OutputDebugString with no debugger attached: decode and log it. */
    if (code == 0x40010006UL || code == 0x4001000AUL) {
        const void *sp = (const void *)info->ExceptionRecord->ExceptionInformation[1];
        if (sp) {
            if (code == 0x40010006UL)
                fprintf(stderr, "[DBGPRINT] %.*s\n",
                        (int)info->ExceptionRecord->ExceptionInformation[0], (const char *)sp);
            else
                fprintf(stderr, "[DBGPRINT] %.*ls\n",
                        (int)(info->ExceptionRecord->ExceptionInformation[0] / 2),
                        (const wchar_t *)sp);
            fflush(stderr);
        }
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    if (code != EXCEPTION_ACCESS_VIOLATION) {
        static int s_nonav_logged = 0;
        if (s_nonav_logged < 8) {
            s_nonav_logged++;
            fprintf(stderr, "[CRASH-NONAV] code=0x%08lX rip=0x%llX g_esp=0x%08X fault=0x%llX\n",
                    (unsigned long)code,
                    (unsigned long long)info->ContextRecord->Rip, g_esp,
                    (unsigned long long)info->ExceptionRecord->ExceptionInformation[1]);
            fflush(stderr);
        }
        return EXCEPTION_CONTINUE_SEARCH;
    }

    uintptr_t fault = info->ExceptionRecord->ExceptionInformation[1];
    int is_write = (int)info->ExceptionRecord->ExceptionInformation[0];
    uintptr_t base = (uintptr_t)g_xbox_mem_offset;
    /* The whole 4 GB above base (+64 KB for wild 0xFFFFFFFC+off) is ours. */
    int in_region = (fault >= base && fault < base + 0x100010000ull);

    g_fault_logged++;

    if (in_region) {
        uint32_t fault_xbox_va = (uint32_t)(fault - base);
        /* Cached RAM mirror (0x80000000-0x87FFFFFF): map the matching RAM window on demand. */
        if (fault_xbox_va >= 0x80000000u && fault_xbox_va < 0x88000000u) {
            extern HANDLE xbox_GetMappingHandle(void);
            HANDLE h = xbox_GetMappingHandle();
            if (h) {
                uintptr_t mbase = fault & ~(uintptr_t)(0x4000000u - 1);
                DWORD sect_off = (DWORD)((fault_xbox_va - 0x80000000u) & ~0x3FFFFFFu);
                LPVOID p = MapViewOfFileEx(h, FILE_MAP_ALL_ACCESS, 0, sect_off,
                                           0x4000000u, (LPVOID)mbase);
                if (p) {
                    if (g_fault_logged < 60) {
                        fprintf(stderr, "  [MIRROR] RAM mirror view for xbva 0x%08X\n",
                                fault_xbox_va & ~0x3FFFFFFu);
                        fflush(stderr);
                    }
                    return EXCEPTION_CONTINUE_EXECUTION;
                }
            }
        }
        if (fault_xbox_va >= 0xF0000000u) {
            /* NV2A registers -> register state machine. */
            if (fault_xbox_va >= 0xFD000000u && fault_xbox_va < 0xFE000000u) {
                extern bool nv2a_hook_handle_mmio(PCONTEXT ctx, uintptr_t fault_addr,
                                                  uint32_t fault_xbox_va, int is_write);
                if (nv2a_hook_handle_mmio(info->ContextRecord, fault, fault_xbox_va, is_write))
                    return EXCEPTION_CONTINUE_EXECUTION;
            }
            /* MCPX APU registers. */
            if (fault_xbox_va >= 0xFE800000u && fault_xbox_va < 0xFE880000u) {
                extern bool apu_hook_handle_mmio(PCONTEXT ctx, uintptr_t fault_addr,
                                                 uint32_t fault_xbox_va, int is_write);
                if (apu_hook_handle_mmio(info->ContextRecord, fault, fault_xbox_va, is_write))
                    return EXCEPTION_CONTINUE_EXECUTION;
            }
            /* Other GPU/MCPX memory: back with a zero page. */
            uintptr_t alloc_base = fault & ~(uintptr_t)0xFFFF;
            LPVOID p = VirtualAlloc((LPVOID)alloc_base, 0x10000,
                                    MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            if (!p) p = VirtualAlloc((LPVOID)alloc_base, 0x10000, MEM_COMMIT, PAGE_READWRITE);
            if (p) {
                memset(p, 0, 0x10000);
                /* MCPX AC97 controller: report both codecs ready (global
                 * status 0x130 bits 8/9) so CMcpxAPU::Initialize succeeds. */
                if ((fault_xbox_va & 0xFFFF0000u) == 0xFEC00000u)
                    *(volatile uint32_t *)((uintptr_t)p + 0x130) = 0x00000300u;
                if (g_fault_logged < 60) {
                    fprintf(stderr, "  [NV2A] GPU mem page 0x%08X (%s)\n",
                            fault_xbox_va & 0xFFFF0000u, is_write ? "W" : "R");
                    fflush(stderr);
                }
                return EXCEPTION_CONTINUE_EXECUTION;
            }
        }
    }

    if (in_region) {
        /* Fault inside a host DLL (CRT memcpy called with a wild guest
         * pointer): back the page with junk so the copy completes. */
        uintptr_t rip = (uintptr_t)info->ContextRecord->Rip;
        if (rip < 0x140000000ull || rip >= 0x142000000ull) {
            uintptr_t alloc_base = fault & ~(uintptr_t)0xFFFF;
            LPVOID p = VirtualAlloc((LPVOID)alloc_base, 0x10000,
                                    MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
            if (!p) p = VirtualAlloc((LPVOID)alloc_base, 0x10000, MEM_COMMIT, PAGE_READWRITE);
            if (p) {
                if (g_fault_logged < 60) {
                    fprintf(stderr, "  [JUNK] backed wild page 0x%08X for host-DLL access (%s, rip=0x%llX)\n",
                            (uint32_t)(fault - base) & 0xFFFF0000u, is_write ? "W" : "R",
                            (unsigned long long)rip);
                    fflush(stderr);
                }
                return EXCEPTION_CONTINUE_EXECUTION;
            }
        }
        BOOL handled = is_write
            ? veh_skip_faulting_write(info->ContextRecord)
            : veh_skip_faulting_read(info->ContextRecord);
        if (handled) {
            g_fault_skips++;
            if (g_fault_skips <= 40) {
                fprintf(stderr, "  [SKIP] %s xbva=0x%08X rip=0x%llX esp=%08X\n",
                        is_write ? "W" : "R", (uint32_t)(fault - base),
                        (unsigned long long)info->ContextRecord->Rip, g_esp);
                fflush(stderr);
            }
            if (g_fault_skips > 2000000ull) {
                fprintf(stderr, "[FAULT] skip cap reached (%llu) - aborting\n",
                        (unsigned long long)g_fault_skips);
                return EXCEPTION_CONTINUE_SEARCH;
            }
            return EXCEPTION_CONTINUE_EXECUTION;
        }
        if (g_fault_logged < 60) {
            fprintf(stderr, "[FAULT] could not decode faulting instr at rip=0x%llX\n",
                    (unsigned long long)info->ContextRecord->Rip);
            fflush(stderr);
        }
    } else {
        HMODULE mod = NULL; char modname[MAX_PATH] = "?";
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                               GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                               (LPCSTR)info->ContextRecord->Rip, &mod) && mod)
            GetModuleFileNameA(mod, modname, sizeof modname);
        fprintf(stderr, "[NATIVE-CRASH] %s 0x%llX rip=0x%llX in %s (+0x%llX)\n",
                is_write ? "write" : "read",
                (unsigned long long)fault,
                (unsigned long long)info->ContextRecord->Rip,
                modname,
                (unsigned long long)(info->ContextRecord->Rip - (uintptr_t)mod));
        fflush(stderr);
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

/* ── XBE loading ────────────────────────────────────────────────── */

static BOOL load_xbe(const char *path, void **out_data, size_t *out_size)
{
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "Cannot open XBE: %s\n", path); return FALSE; }
    fseek(f, 0, SEEK_END); long size = ftell(f); fseek(f, 0, SEEK_SET);
    if (size <= 0) { fclose(f); return FALSE; }
    void *data = malloc((size_t)size);
    if (!data) { fclose(f); return FALSE; }
    if (fread(data, 1, (size_t)size, f) != (size_t)size) { free(data); fclose(f); return FALSE; }
    fclose(f);
    *out_data = data; *out_size = (size_t)size;
    return TRUE;
}

static void doa2u_atexit(void)
{
    fprintf(stderr, "[EXIT] process exiting via exit()/CRT (g_esp=0x%08X)\n", g_esp);
    fflush(stderr);
}

static LONG WINAPI doa2u_unhandled(PEXCEPTION_POINTERS info)
{
    fprintf(stderr, "[EXIT] UNHANDLED exception 0x%08lX rip=0x%llX g_esp=0x%08X",
            (unsigned long)info->ExceptionRecord->ExceptionCode,
            (unsigned long long)info->ContextRecord->Rip, g_esp);
    if (info->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
        fprintf(stderr, " %s 0x%llX",
                info->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
                (unsigned long long)info->ExceptionRecord->ExceptionInformation[1]);
    fprintf(stderr, "\n[EXIT] our frames:");
    {
        uintptr_t *sp = (uintptr_t *)info->ContextRecord->Rsp;
        int shown = 0;
        for (int k = 0; k < 2000 && shown < 16; k++) {
            if (IsBadReadPtr(&sp[k], 8)) break;
            uintptr_t v = sp[k];
            if (v >= 0x140000000ull && v < 0x142000000ull) {
                fprintf(stderr, " 0x%llX", (unsigned long long)v);
                shown++;
            }
        }
    }
    fprintf(stderr, "\n");
    fflush(stderr);
    return EXCEPTION_CONTINUE_SEARCH;
}

int main(int argc, char **argv)
{
    void *xbe_data = NULL; size_t xbe_size = 0;
    (void)argc; (void)argv;
    doa2u_watchdog_start();
    {   /* Run from the exe's folder whatever the launcher's working directory. */
        WCHAR exedir[MAX_PATH];
        DWORD n = GetModuleFileNameW(NULL, exedir, MAX_PATH);
        if (n > 0 && n < MAX_PATH) {
            WCHAR *slash = wcsrchr(exedir, L'\\');
            if (slash) { *slash = 0; SetCurrentDirectoryW(exedir); }
        }
    }
    setvbuf(stdout, NULL, _IONBF, 0);
    doa3_log_init();   /* stderr -> doa2u_log.txt (Logging=1 in doa2u_settings.ini) */

    atexit(doa2u_atexit);
    SetUnhandledExceptionFilter(doa2u_unhandled);
    { extern int pad_mapping_load(const char *); pad_mapping_load(NULL); }

    fprintf(stderr, "=== Dead or Alive 2 Ultimate - Static Recompilation ===\n");
    AddVectoredExceptionHandler(1, crash_veh);

    if (!load_xbe(DOA2U_XBE_PATH, &xbe_data, &xbe_size)) {
        char cwd[MAX_PATH] = {0}, msg[512];
        GetCurrentDirectoryA(MAX_PATH, cwd);
        snprintf(msg, sizeof(msg),
                 "Could not load %s\n(working directory: %s)\n\n"
                 "Expected the disc contents (DOA2.xbe and the doa2 folder) in the "
                 "assets folder next to DOA2U.exe.", DOA2U_XBE_PATH, cwd);
        fprintf(stderr, "FATAL: %s\n", msg);
        MessageBoxA(NULL, msg, "DOA2U recomp - startup error", 0x10);
        return 1;
    }
    fprintf(stderr, "XBE loaded: %zu bytes\n", xbe_size);

    if (!xbox_MemoryLayoutInit(xbe_data, xbe_size)) {
        fprintf(stderr, "FATAL: xbox_MemoryLayoutInit failed\n"); return 1;
    }
    fprintf(stderr, "Xbox memory mapped. Offset: 0x%llX\n",
            (unsigned long long)(uintptr_t)xbox_GetMemoryOffset());

    watch_init();
    xbox_kernel_init();
    xbox_path_init(NULL, NULL);   /* D:\ -> <exe folder>\assets */
    xbox_kernel_bridge_init();

    {   /* NV2A register emulation (VEH routes 0xFD000000 MMIO to it). */
        extern void nv2a_hook_init(ptrdiff_t xbox_mem_offset);
        nv2a_hook_init(g_xbox_mem_offset);
    }

    doa2u_init_graphics();

    {   /* MCPX APU emulation + host DirectSound backend. */
        typedef struct MCPXAPUState MCPXAPUState;
        extern MCPXAPUState *mcpx_apu_init_standalone(uint8_t *ram_ptr);
        extern MCPXAPUState *g_apu_state;
        uint8_t *phys_ram = (uint8_t *)(uintptr_t)g_xbox_mem_offset;
        g_apu_state = mcpx_apu_init_standalone(phys_ram);
        fprintf(stderr, "  APU: %s\n", g_apu_state ? "MCPX APU emulation initialized"
                                                    : "APU init FAILED");
    }
    {
        extern HRESULT xbox_DirectSoundCreate(void *pGuid, IDirectSound8 **ppDS, void *pUnkOuter);
        HRESULT hr = xbox_DirectSoundCreate(NULL, &g_dsound, NULL);
        fprintf(stderr, "  DirectSound: %s (hr=0x%08lX)\n",
                SUCCEEDED(hr) ? "host DirectSound created" : "FAILED", (unsigned long)hr);
    }

    /* The main OS thread becomes the primary cooperative fiber; guest threads
     * (CreateThread -> PsCreateSystemThreadEx) run as fibers beside it. */
    xbox_fiber_init();

    {   extern void doa2u_game_init(void); doa2u_game_init(); }

    fprintf(stderr, "Init complete. Entry=0x%08X  ESP=0x%08X\n--- Calling xbe_entry_point() ---\n",
            DOA2U_ENTRY_POINT, g_esp);
    fflush(stderr);

    xbe_entry_point();

    fprintf(stderr, "\nxbe_entry_point returned (g_eax=0x%08X), fault-skips=%llu\n",
            g_eax, (unsigned long long)g_fault_skips);

    xbox_kernel_shutdown();
    xbox_MemoryLayoutShutdown();
    free(xbe_data);
    return 0;
}
