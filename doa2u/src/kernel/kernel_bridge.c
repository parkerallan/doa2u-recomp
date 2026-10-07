/**
 * kernel_bridge.c - Bridge between translated game code and kernel functions
 *
 * Problem:
 *   Translated game code calls kernel functions via indirect calls through
 *   the kernel thunk table at VA 0x0036B7C0. In the XBE file, these entries
 *   contain unresolved ordinals (0x80000000 | ordinal). On real Xbox hardware,
 *   the kernel loader replaces these with actual function pointers before the
 *   game runs.
 *
 * Solution:
 *   1. After xbox_MemoryLayoutInit copies .rdata, call xbox_kernel_bridge_init()
 *   2. Replace each ordinal entry in Xbox memory with a synthetic VA
 *   3. When RECOMP_ICALL encounters a synthetic VA, route it to a per-ordinal
 *      bridge function that reads args from the simulated Xbox stack, translates
 *      pointer arguments from Xbox VA→native, and calls the kernel function.
 *
 * Synthetic VA scheme:
 *   Each thunk slot i gets VA 0xFE000000 + i*4
 *   The lookup function checks this range and dispatches appropriately.
 *
 * Why per-ordinal bridges instead of a generic trampoline:
 *   Kernel functions receive Xbox pointers (32-bit VAs) that must be translated
 *   to native pointers by adding g_xbox_mem_offset. Different functions have
 *   different parameter layouts (pointer vs value), so each needs its own bridge.
 */

#include "kernel.h"
#include "xbox_memory_layout.h"
#include "xbox_fiber.h"
#include "xbox_det.h"
#include <stdio.h>
#include <string.h>
#include <float.h>



/* Access to recompiled code globals */
extern uint32_t g_eax, g_ecx, g_edx, g_esp;
extern uint32_t g_ebx, g_esi, g_edi;
extern uint32_t g_seh_ebp;
extern ptrdiff_t g_xbox_mem_offset;

/* Dispatch table lookup (for function pointer args) */
typedef void (*recomp_func_t)(void);
recomp_func_t recomp_lookup(uint32_t xbox_va);
recomp_func_t recomp_lookup_manual(uint32_t xbox_va);

/* Memory access - same as recomp_types.h MEM32 but without the #define guard */
#define BRIDGE_MEM32(addr) (*(volatile uint32_t *)((uintptr_t)(addr) + g_xbox_mem_offset))

/* Translate Xbox VA to native pointer (NULL-safe: 0 → NULL) */
#define XBOX_TO_NATIVE(va) ((va) ? (void*)((uintptr_t)(va) + g_xbox_mem_offset) : NULL)

/* Title-specific guest addresses set by the game layer (0 = not present): D3D vblank
 * event/counter, first-boot cache copy routine, CRI ADX vsync server routine. */
uint32_t g_xbox_vblank_event_va = 0;
uint32_t g_xbox_vblank_counter_va = 0;
uint32_t g_xbox_cache_install_routine = 0;
/* Cache copy worker's exit status (PsTerminateSystemThread), read back by
 * GetExitCodeThread through ObReferenceObjectByHandle. */
uint32_t g_xbox_cache_install_exit = 0x103;
int g_xbox_cache_install_exited = 0;
uint32_t g_xbox_vsync_server_routine = 0;

/* ── Synthetic VA range (for function exports) ─────────── */

#define KERNEL_VA_BASE  0xFE000000u
#define KERNEL_VA_END   (KERNEL_VA_BASE + XBOX_KERNEL_THUNK_TABLE_SIZE * 4)

/* ── Kernel data exports ──────────────────────────────────
 *
 * Some kernel ordinals are DATA exports (structs/variables), not functions.
 * The game reads their thunk entries and dereferences the result to access
 * the data. These cannot use synthetic VAs — they must point to real,
 * dereferenceable addresses in the Xbox VA space.
 *
 * We allocate a "kernel data area" at XBOX_KERNEL_DATA_BASE and populate
 * it with the expected structures.
 */

#define BRIDGE_MEM16(addr) (*(volatile uint16_t *)((uintptr_t)(addr) + g_xbox_mem_offset))
#define BRIDGE_MEM8(addr)  (*(volatile uint8_t  *)((uintptr_t)(addr) + g_xbox_mem_offset))

static uint32_t kernel_data_va_for_ordinal(ULONG ordinal);   /* kernel_bridge_more.inc */


/**
 * Initialize kernel data export values at the kernel data area.
 * Called during bridge init, after Xbox memory is mapped.
 */
/* KeTickCount source: the guest reads the export page directly, so it has
 * to be advanced asynchronously. 1 ms period like the console's clock
 * interrupt; the value is milliseconds since boot. */
static DWORD WINAPI xbox_tick_count_thread(LPVOID arg)
{
    ULONGLONG t0 = GetTickCount64();
    (void)arg;
    for (;;) {
        /* Skipped while a netplay session drives the clock (xbox_det.c). */
        xbox_det_publish_host_tick((uint32_t)(GetTickCount64() - t0));
        Sleep(1);
    }
    return 0;
}

static void kernel_data_init(void)
{
    /* XboxHardwareInfo (ordinal 322) - XBOX_HARDWARE_INFO
     *   +0: ULONG Flags (0 = retail, 0x20 = devkit)
     *   +4: UCHAR GpuRevision
     *   +5: UCHAR McpRevision
     */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_HARDWARE_INFO + 0) = 0;   /* Retail */
    BRIDGE_MEM8(XBOX_KERNEL_DATA_BASE + KDATA_HARDWARE_INFO + 4) = 0xA1; /* NV2A A1 */
    BRIDGE_MEM8(XBOX_KERNEL_DATA_BASE + KDATA_HARDWARE_INFO + 5) = 0xB1; /* MCPX B1 */

    /* XboxKrnlVersion (ordinal 324) - XBOX_KRNL_VERSION
     *   +0: USHORT Major (1)
     *   +2: USHORT Minor (0)
     *   +4: USHORT Build (5849 = XDK version)
     *   +6: USHORT Qfe (0)
     */
    BRIDGE_MEM16(XBOX_KERNEL_DATA_BASE + KDATA_KRNL_VERSION + 0) = 1;
    BRIDGE_MEM16(XBOX_KERNEL_DATA_BASE + KDATA_KRNL_VERSION + 2) = 0;
    BRIDGE_MEM16(XBOX_KERNEL_DATA_BASE + KDATA_KRNL_VERSION + 4) = 5849;
    BRIDGE_MEM16(XBOX_KERNEL_DATA_BASE + KDATA_KRNL_VERSION + 6) = 0;

    /* KeTickCount (ordinal 156). The console's clock interrupt increments
     * this every millisecond from 0 at boot, and the game copies it into
     * its own frame clock every frame (sub_00164400 -> [0x85B9C8]) for the
     * sound and stage-event timing helpers. It used to be written once here
     * and never again, so the guest's millisecond clock stood still for the
     * whole run. Keep it ticking, boot-relative, from a 1 ms thread. */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_TICK_COUNT) = 0;
    {
        HANDLE th = CreateThread(NULL, 0, xbox_tick_count_thread, NULL, 0, NULL);
        if (th) CloseHandle(th);
    }

    /* LaunchDataPage (ordinal 164) - NULL (no launch data) */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_LAUNCH_DATA_PAGE) = 0;

    /* PsThreadObjectType (ordinal 259) - type object (stub: 0) */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_THREAD_OBJ_TYPE) = 0;

    /* ExEventObjectType (ordinal 17) - type object (stub: 0) */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_EVENT_OBJ_TYPE) = 0;

    /* IoCompletionObjectType (ordinal 65) - type object (stub: 0) */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_IO_COMPLETION_TYPE) = 0;

    /* IoDeviceObjectType (ordinal 71) - type object (stub: 0) */
    BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_IO_DEVICE_TYPE) = 0;

    {   /* HalDiskCachePartitionCount / HalDiskModelNumber / HalDiskSerialNumber
         * (STRING = Length, MaximumLength, Buffer) / HalBootSMCVideoMode */
        static const char model[] = "DOA2U-PC-HDD", serial[] = "0000000000";
        uint32_t m = XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_MODEL;
        uint32_t sn = XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_SERIAL;
        BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_HAL_DISK_PARTCOUNT) = 3;
        BRIDGE_MEM16(m) = sizeof(model) - 1; BRIDGE_MEM16(m + 2) = sizeof(model);
        BRIDGE_MEM32(m + 4) = m + 0x10;
        memcpy((void *)((uintptr_t)(m + 0x10) + g_xbox_mem_offset), model, sizeof(model));
        BRIDGE_MEM16(sn) = sizeof(serial) - 1; BRIDGE_MEM16(sn + 2) = sizeof(serial);
        BRIDGE_MEM32(sn + 4) = sn + 0x10;
        memcpy((void *)((uintptr_t)(sn + 0x10) + g_xbox_mem_offset), serial, sizeof(serial));
        BRIDGE_MEM32(XBOX_KERNEL_DATA_BASE + KDATA_SMC_VIDEO_MODE) = 1;   /* NTSC */
        memset((void *)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_IDEX_CHANNEL) + g_xbox_mem_offset), 0, 0x100);
    }
    /* XboxHDKey (ordinal 323) - 16 bytes of zeros (no key) */
    memset((void*)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_HD_KEY) + g_xbox_mem_offset), 0, 16);

    /* XboxSignatureKey (ordinal 325) - 16 bytes of zeros */
    memset((void*)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_SIGNATURE_KEY) + g_xbox_mem_offset), 0, 16);

    /* XboxLANKey (ordinals 326, 355) - 16 bytes of zeros */
    memset((void*)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_LAN_KEY) + g_xbox_mem_offset), 0, 16);

    /* XboxAlternateSignatureKeys (ordinals 327, 356) - 256 bytes of zeros */
    memset((void*)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_ALT_SIGNATURE_KEYS) + g_xbox_mem_offset), 0, 256);

    /* XePublicKeyData (ordinal 357) - 284 bytes of zeros */
    memset((void*)((uintptr_t)(XBOX_KERNEL_DATA_BASE + KDATA_XE_PUBLIC_KEY) + g_xbox_mem_offset), 0, 284);

}

/* ── Per-slot ordinal and bridge function ────────────────── */

/* Ordinal for each slot (read from Xbox memory during init) */
static ULONG g_slot_ordinals[XBOX_KERNEL_THUNK_TABLE_SIZE];

/* Log counter - limit output to avoid flooding */
/* 64-bit and unsigned: this counter gates every diagnostic below via
 * <= N tests, and as a signed int it wrapped negative during the CRI
 * resume spin (billions of calls). Once negative, every gate re-opened
 * and the bridge logged ~1M lines per run -- enough I/O to starve the
 * guest and make the movie teardown look like a hang. */
static unsigned long long g_kernel_call_count = 0;

/* Read Xbox stack arg as uint32_t.
 * After kernel_thunk_dispatch pops the dummy return address (g_esp += 4),
 * arg0 is at g_esp+0, arg1 at g_esp+4, etc. */
#define STACK_ARG(n) ((uint32_t)BRIDGE_MEM32(g_esp + (n) * 4))

/* ── Per-ordinal bridge functions ─────────────────────────
 *
 * Each bridge reads args from the Xbox stack, translates pointer
 * args from Xbox VA→native, calls the kernel function, and stores
 * the result in g_eax.
 *
 * Xbox cdecl: args pushed right-to-left, caller cleans stack.
 * Xbox stdcall: args pushed right-to-left, callee cleans stack.
 * In our case the caller (translated code) does "PUSH32" for each arg
 * before calling, and the kernel function's ret-N is handled by the
 * translated code's own stack adjustment.
 */

/* ── PsCreateSystemThreadEx (ordinal 255) ────────────────
 * NTSTATUS PsCreateSystemThreadEx(
 *   PHANDLE ThreadHandle,      // arg0: Xbox VA → pointer
 *   ULONG ThreadExtraSize,     // arg1: value
 *   ULONG KernelStackSize,     // arg2: value
 *   ULONG TlsDataSize,         // arg3: value
 *   PULONG ThreadId,           // arg4: Xbox VA → pointer (can be NULL)
 *   PVOID StartContext1,       // arg5: Xbox VA → opaque
 *   PVOID StartContext2,       // arg6: Xbox VA → opaque
 *   BOOLEAN CreateSuspended,   // arg7: value
 *   BOOLEAN DebugStack,        // arg8: value
 *   PXBOX_SYSTEM_ROUTINE StartRoutine  // arg9: Xbox function pointer
 * )
 *
 * For static recompilation, we don't create a real thread.
 * Instead we call the StartRoutine synchronously via RECOMP_ICALL.
 * This is correct because on Xbox, the entry point creates a system
 * thread and returns, and the thread runs the actual game.
 */
static int g_thread_call_count = 0;

static void bridge_PsCreateSystemThreadEx(void)
{
    uint32_t xbox_handle_ptr = STACK_ARG(0);
    uint32_t thread_id_ptr   = STACK_ARG(4);
    uint32_t start_context1  = STACK_ARG(5);
    uint32_t start_context2  = STACK_ARG(6);
    uint32_t create_suspended = STACK_ARG(7) & 0xFF;
    uint32_t start_routine   = STACK_ARG(9);
    int is_first_call = (g_thread_call_count == 0);
    uint32_t xhandle;
    g_thread_call_count++;
    /* SHARED fake handle for all threads. Unique handles (0xBEEF0000+n) were
     * tried to fix the Sofdec mwPly join spin, but they DEADLOCK THE BOOT:
     * the CRI ADX suspend/resume handshake between the master server and its
     * I/O workers only lines up when every thread handle compares equal (the
     * partition loads never issued a single read otherwise — bisected 2026-07).
     * The mwPly spin needs a different fix (its resume targets do reach the
     * right fibers; the decoder's wait chain is the issue). */
    xhandle = 0xBEEF0001u;


    if (xbox_handle_ptr) {
        BRIDGE_MEM32(xbox_handle_ptr) = xhandle;
    }
    if (thread_id_ptr) {
        BRIDGE_MEM32(thread_id_ptr) = xhandle;  /* id == handle in this port */
    }

    /* Call the start routine synchronously through the recomp dispatch.
     * Xbox thread start routines receive two parameters:
     *   void ThreadRoutine(PVOID StartContext1, PVOID StartContext2)
     * We push both onto the simulated stack (right-to-left).
     *
     * First call: the game's main thread entry point. Must run synchronously
     * and inherit the current register state (this IS the game starting).
     *
     * Subsequent calls: worker threads. Must save/restore ALL global registers
     * because on real Xbox each thread has its own register set. Without this,
     * the worker clobbers the caller's g_esi, g_ebx, etc. */
    fprintf(stderr, "[THREAD] create #%u routine=0x%08X ctx1=0x%08X ctx2=0x%08X%s\n",
            g_thread_call_count, start_routine, start_context1, start_context2,
            create_suspended ? " (suspended)" : "");
    if (start_routine) {
        recomp_func_t fn = recomp_lookup(start_routine);
        if (!fn) fn = recomp_lookup_manual(start_routine);
        if (!fn) fprintf(stderr, "[THREAD] no translated body for routine 0x%08X\n", start_routine);
        if (fn) {
            if (is_first_call) {
                /* Main game thread: run directly, inheriting register state */
                g_esp -= 4; BRIDGE_MEM32(g_esp) = start_context2;
                g_esp -= 4; BRIDGE_MEM32(g_esp) = start_context1;
                g_esp -= 4; BRIDGE_MEM32(g_esp) = 0;
                fn();
                g_esp += 12;
            } else {
                /* Worker thread: spawn a cooperative fiber. The game's CRI relies on
                 * its I/O worker threads actually running (they pump the file-load
                 * queue), so we give each one its own fiber + Xbox stack and let
                 * the cooperative scheduler (yield points: KeWaitForSingleObject and
                 * the game's busy-wait spins) run them. */
                if (xbox_fiber_active() &&
                    xbox_fiber_spawn(start_routine, start_context1, start_context2,
                                     xhandle, (int)create_suspended)) {
                    /* spawned; runs when next scheduled */
                } else {
                }
            }
        } else {
        }
    }

    g_eax = 0; /* STATUS_SUCCESS */
}

/* ── NtWaitForSingleObject (ordinal 234) ──────────────────
 * NTSTATUS NtWaitForSingleObject(HANDLE Handle, BOOLEAN Alertable,
 *                                PLARGE_INTEGER Timeout)
 *
 * Was unbridged, i.e. every wait returned 0 = STATUS_WAIT_0 at once. The
 * one place the game joins a thread is the first-boot cache install: the boot
 * spawns the copy worker (routine 0x0009D440, sub_0009D6C0) and polls it
 * with WaitForSingleObject(hThread, 0) from sub_0009D713 before it loads
 * the partitions from z:\. "Signaled" on the first poll meant the boot
 * read z:\loadfile.afs while the copy was still on voice.afs; the open
 * failed, ADXF parked the partition in error and the boot spun on the
 * mount forever -- the black screen after a first-boot install.
 *
 * Thread pseudo-handles (0xBEEFxxxx) therefore report the worker's real
 * state: STATUS_TIMEOUT while its fiber is alive (a zero timeout is a poll),
 * or block by yielding to it until it exits. Everything else keeps the old
 * behaviour (satisfied immediately). */
static void bridge_NtWaitForSingleObject(void)
{
    uint32_t h = STACK_ARG(0);
    uint32_t timeout_va = STACK_ARG(2);
    if ((h & 0xFFFF0000u) == 0xBEEF0000u) {
        const uint32_t install_ctx = g_xbox_cache_install_routine;
        int zero_timeout = timeout_va &&
                           BRIDGE_MEM32(timeout_va) == 0 && BRIDGE_MEM32(timeout_va + 4) == 0;
        if (xbox_fiber_thread_alive(install_ctx)) {
            if (xbox_fiber_active()) {
                if (g_xbox_vblank_event_va) BRIDGE_MEM32(g_xbox_vblank_event_va + 4) = 1;   /* vblank pulse for the CRI workers */
                if (g_xbox_vblank_event_va) xbox_fiber_wake(g_xbox_vblank_event_va);
                xbox_fiber_yield();
            }
            if (zero_timeout) { g_eax = 0x00000102u; return; }   /* STATUS_TIMEOUT */
            while (xbox_fiber_thread_alive(install_ctx) && xbox_fiber_active()) {
                if (g_xbox_vblank_event_va) BRIDGE_MEM32(g_xbox_vblank_event_va + 4) = 1;
                if (g_xbox_vblank_event_va) xbox_fiber_wake(g_xbox_vblank_event_va);
                xbox_fiber_yield();
            }
        }
        g_eax = 0;   /* STATUS_WAIT_0 */
        return;
    }
    g_eax = 0;
}

/* ── KeInitializeInterrupt (ordinal 109) / KeInsertQueueDpc (119) ──
 * The DirectSound driver's interrupt path. KeInitializeInterrupt records
 * the KINTERRUPT's service routine + context; KeInsertQueueDpc queues the
 * DPC (routine/context live in the KDPC written by KeInitializeDpc). The
 * game thread drains both from doa2u_apu_deliver_irq once per frame. */
typedef struct { uint32_t obj, routine, ctx; } XboxIsr;
static XboxIsr  s_isr[4];
static int      s_isr_n;
typedef struct { uint32_t dpc, a1, a2; } XboxDpc;
static XboxDpc  s_dpcq[16];
static int      s_dpcq_n;

static void bridge_KeInitializeInterrupt(void)
{
    uint32_t obj = STACK_ARG(0), routine = STACK_ARG(1), ctx = STACK_ARG(2);
    if (s_isr_n < 4) { s_isr[s_isr_n].obj = obj; s_isr[s_isr_n].routine = routine; s_isr[s_isr_n].ctx = ctx; s_isr_n++; }
    g_eax = 0;
}

static void bridge_KeInsertQueueDpc(void)
{
    uint32_t dpc = STACK_ARG(0), a1 = STACK_ARG(1), a2 = STACK_ARG(2);
    int i;
    for (i = 0; i < s_dpcq_n; i++)
        if (s_dpcq[i].dpc == dpc) { g_eax = 0; return; }   /* already queued */
    if (s_dpcq_n < 16) { s_dpcq[s_dpcq_n].dpc = dpc; s_dpcq[s_dpcq_n].a1 = a1; s_dpcq[s_dpcq_n].a2 = a2; s_dpcq_n++; }
    g_eax = 1;
}

int xbox_kernel_get_isr(int i, uint32_t *obj, uint32_t *routine, uint32_t *ctx)
{
    if (i < 0 || i >= s_isr_n) return 0;
    *obj = s_isr[i].obj; *routine = s_isr[i].routine; *ctx = s_isr[i].ctx;
    return 1;
}

int xbox_kernel_pop_dpc(uint32_t *dpc, uint32_t *a1, uint32_t *a2)
{
    if (s_dpcq_n == 0) return 0;
    *dpc = s_dpcq[0].dpc; *a1 = s_dpcq[0].a1; *a2 = s_dpcq[0].a2;
    memmove(&s_dpcq[0], &s_dpcq[1], (size_t)(s_dpcq_n - 1) * sizeof(s_dpcq[0]));
    s_dpcq_n--;
    return 1;
}

/* ── NtClose (ordinal 187) ───────────────────────────────
 * NTSTATUS NtClose(HANDLE Handle)
 * Handle is a value (not a pointer), so safe for generic call.
 */
static void bridge_NtClose(void)
{
    uint32_t raw_handle = STACK_ARG(0);
    HANDLE h = (HANDLE)(uintptr_t)raw_handle;

    if (g_kernel_call_count <= 200) {
    }

    /* A published file handle retires its table slot; the id is never
     * reissued, so a later read with it fails instead of aliasing. */
    if (xbox_fh_release(raw_handle)) {
        g_eax = 0;
        return;
    }
    /* Close real handles but skip fake/synthetic ones */
    if (raw_handle && raw_handle != 0xDEAD0001u &&
        raw_handle != 0xBEEF0010u && h != INVALID_HANDLE_VALUE) {
        CloseHandle(h);
    }
    g_eax = 0; /* STATUS_SUCCESS */
}

/* ── MmAllocateContiguousMemory (ordinal 165) ─────────────
 * PVOID MmAllocateContiguousMemory(ULONG NumberOfBytes)
 */
static void bridge_MmAllocateContiguousMemory(void)
{
    uint32_t size = STACK_ARG(0);

    /* Allocate from Xbox heap so MEM32(result) works correctly */
    uint32_t xbox_va = xbox_HeapAlloc(size, 4096);

    if (g_kernel_call_count <= 100) {
    }

    g_eax = xbox_va;
}

/* ── MmAllocateContiguousMemoryEx (ordinal 166) ───────────
 * PVOID MmAllocateContiguousMemoryEx(SIZE_T size, ULONG_PTR low, ULONG_PTR high,
 *                                     ULONG alignment, ULONG protect)
 */
static void bridge_MmAllocateContiguousMemoryEx(void)
{
    uint32_t size = STACK_ARG(0);
    uint32_t low = STACK_ARG(1);
    uint32_t high = STACK_ARG(2);
    uint32_t align = STACK_ARG(3);
    uint32_t prot = STACK_ARG(4);

    /* Allocate from Xbox heap with requested alignment */
    if (align < 4096) align = 4096;
    uint32_t xbox_va = xbox_HeapAlloc(size, align);

    if (g_kernel_call_count <= 100) {
    }

    g_eax = xbox_va;
}

/* ── MmFreeContiguousMemory (ordinal 171) ─────────────────
 * VOID MmFreeContiguousMemory(PVOID BaseAddress)
 */
static void bridge_MmFreeContiguousMemory(void)
{
    uint32_t addr = STACK_ARG(0);
    xbox_HeapFree(addr);
    g_eax = 0;
}

/* ── NtAllocateVirtualMemory (ordinal 184) ────────────────
 * NTSTATUS NtAllocateVirtualMemory(PVOID *BaseAddress, ULONG ZeroBits,
 *     PULONG AllocationSize, ULONG AllocationType, ULONG Protect)
 */
static void bridge_NtAllocateVirtualMemory(void)
{
    uint32_t base_ptr = STACK_ARG(0);  /* PVOID* in Xbox VA */
    uint32_t zero_bits = STACK_ARG(1);
    uint32_t size_ptr = STACK_ARG(2);  /* PULONG in Xbox VA */
    uint32_t alloc_type = STACK_ARG(3);
    uint32_t protect = STACK_ARG(4);

    /* Read the requested size from Xbox memory */
    uint32_t size = size_ptr ? BRIDGE_MEM32(size_ptr) : 0;
    /* Read the base address hint (0 = let kernel choose) */
    uint32_t base_hint = base_ptr ? BRIDGE_MEM32(base_ptr) : 0;

    if (g_kernel_call_count <= 200) {
    }

    if (size == 0) {
        g_eax = 0xC0000045u; /* STATUS_INVALID_PAGE_PROTECTION */
        return;
    }

    /*
     * Xbox NtAllocateVirtualMemory supports two modes:
     * - MEM_RESERVE (0x2000): Reserve virtual address space
     * - MEM_COMMIT  (0x1000): Commit pages within a reserved region
     * - MEM_RESERVE|MEM_COMMIT (0x3000): Both in one call
     *
     * Our Xbox heap (bump allocator) always commits memory immediately,
     * so MEM_COMMIT on an already-reserved region is a no-op.
     * Only allocate new memory when MEM_RESERVE is requested.
     */
    if (base_hint != 0 && (alloc_type & 0x2000) == 0) {
        /* MEM_COMMIT only, on an already-reserved region.
         * The memory is already committed by our bump allocator.
         * Don't change the base address - just return success. */
        if (g_kernel_call_count <= 200) {
        }
        g_eax = 0; /* STATUS_SUCCESS */
        return;
    }

    /* Allocate from Xbox heap (MEM_RESERVE or MEM_RESERVE|MEM_COMMIT) */
    uint32_t xbox_va = xbox_HeapAlloc(size, 4096);
    if (!xbox_va) {
        g_eax = 0xC0000017u; /* STATUS_NO_MEMORY */
        return;
    }

    /* Write back the allocated address and actual size */
    if (base_ptr) BRIDGE_MEM32(base_ptr) = xbox_va;
    if (size_ptr) BRIDGE_MEM32(size_ptr) = size;

    g_eax = 0; /* STATUS_SUCCESS */
}

/* ── NtFreeVirtualMemory (ordinal 199) ────────────────────
 * NTSTATUS NtFreeVirtualMemory(PVOID *BaseAddress, PULONG FreeSize,
 *     ULONG FreeType)
 */
static void bridge_NtFreeVirtualMemory(void)
{
    uint32_t base_ptr = STACK_ARG(0);
    uint32_t size_ptr = STACK_ARG(1);
    uint32_t free_type = STACK_ARG(2);
    uint32_t base = base_ptr ? BRIDGE_MEM32(base_ptr) : 0;

    /* The region came from xbox_HeapAlloc (see bridge_NtAllocateVirtualMemory),
     * so it must go back to the guest heap. The old code passed the GUEST VA
     * to the host VirtualFree, which can never match a guest block, so every
     * MEM_RELEASE leaked. Only MEM_RELEASE (0x8000) returns the block; a
     * MEM_DECOMMIT of part of a region is left committed (the guest heap has
     * no page granularity), which the no-op MEM_COMMIT path already assumes. */
    if (base >= XBOX_HEAP_BASE && base < XBOX_LOW_END) {
        if (free_type & 0x8000u) {
            xbox_HeapFree(base);
            BRIDGE_MEM32(base_ptr) = 0;
        }
        g_eax = 0; /* STATUS_SUCCESS */
        return;
    }
    g_eax = (uint32_t)xbox_NtFreeVirtualMemory(
        XBOX_TO_NATIVE(base_ptr), XBOX_TO_NATIVE(size_ptr), free_type);
}

/* ── ExAllocatePool / ExAllocatePoolWithTag (ordinals 15, 16) ─
 * Must allocate from Xbox heap so the returned pointer is an Xbox VA
 * that can be accessed via MEM32(). Native HeapAlloc returns 64-bit
 * pointers that get truncated and produce garbage Xbox VAs.
 */
static void bridge_ExAllocatePool(void)
{
    uint32_t size = STACK_ARG(0);
    uint32_t xbox_va = xbox_HeapAlloc(size, 16);

    if (g_kernel_call_count <= 200) {
    }

    g_eax = xbox_va;
}

static void bridge_ExAllocatePoolWithTag(void)
{
    uint32_t size = STACK_ARG(0);
    uint32_t tag = STACK_ARG(1);
    uint32_t xbox_va = xbox_HeapAlloc(size, 16);

    if (g_kernel_call_count <= 200) {
    }

    g_eax = xbox_va;
}

/* ── KfRaiseIrql / KfLowerIrql (ordinals 160, 161) ────── */
static void bridge_KfRaiseIrql(void)
{
    uint32_t new_irql = g_ecx;   /* fastcall: the stack holds no argument */
    g_eax = (uint32_t)xbox_KfRaiseIrql((UCHAR)new_irql);
}

static void bridge_KfLowerIrql(void)
{
    uint32_t new_irql = g_ecx;   /* fastcall: the stack holds no argument */
    xbox_KfLowerIrql((UCHAR)new_irql);
    g_eax = 0;
}

/* ── KeRaiseIrqlToDpcLevel (ordinal 129) ─────────────────── */
static void bridge_KeRaiseIrqlToDpcLevel(void)
{
    g_eax = (uint32_t)xbox_KeRaiseIrqlToDpcLevel();
}

/* ── RtlInitializeCriticalSection / Enter / Leave (ordinals 291, 277, 294) ─ */
static void bridge_RtlInitializeCriticalSection(void)
{
    uint32_t cs_va = STACK_ARG(0);
    xbox_RtlInitializeCriticalSection(XBOX_TO_NATIVE(cs_va));
    g_eax = 0;
}

static void bridge_RtlEnterCriticalSection(void)
{
    uint32_t cs_va = STACK_ARG(0);
    xbox_RtlEnterCriticalSection(XBOX_TO_NATIVE(cs_va));
    g_eax = 0;
}

static void bridge_RtlLeaveCriticalSection(void)
{
    uint32_t cs_va = STACK_ARG(0);
    xbox_RtlLeaveCriticalSection(XBOX_TO_NATIVE(cs_va));
    g_eax = 0;
}

/* ── RtlInitAnsiString (ordinal 289) ──────────────────────
 * VOID RtlInitAnsiString(PANSI_STRING DestinationString, PCSZ SourceString)
 * Initializes an ANSI_STRING (Length=strlen, MaximumLength=Length+1, Buffer=SourceString).
 * The CRI ADXF middleware calls this to build the filename ANSI_STRING immediately before
 * NtOpenFile (ord 202); without it the ANSI_STRING is uninitialized stack garbage and the
 * loadfile.afs open fails with a malformed OBJECT_ATTRIBUTES. Store the Xbox VA in Buffer
 * (not a native pointer) so NtOpenFile's bridge_get_xbox_path resolves it correctly. */
static void bridge_RtlInitAnsiString(void)
{
    uint32_t dst_va = STACK_ARG(0);
    uint32_t src_va = STACK_ARG(1);
    uint16_t len = 0;
    if (src_va)
        len = (uint16_t)strlen((const char *)XBOX_TO_NATIVE(src_va));
    if (dst_va) {
        BRIDGE_MEM16(dst_va + 0) = len;                                /* Length */
        BRIDGE_MEM16(dst_va + 2) = src_va ? (uint16_t)(len + 1) : 0;   /* MaximumLength */
        BRIDGE_MEM32(dst_va + 4) = src_va;                             /* Buffer (Xbox VA) */
    }
    g_eax = 0;
}

/* ── KeQueryPerformanceCounter / Frequency (ordinals 126, 127) ─ */
static void bridge_KeQueryPerformanceCounter(void)
{
    /* Tight-poll detector: the game's DSOUND stream service loops on QPC waiting
     * for APU voice positions our emulation never advances (stalled the boot
     * after the warning screen for minutes). When polled in a hot loop,
     * fast-forward the returned time and yield to keep the CRI/render fibers
     * alive — the wait's deadline math then expires quickly.
     * item 100 (DETERMINISM): the old fast path gated on polls-per-OS-tick
     * (GetTickCount64) — host-speed dependent, so WHICH path tripped varied
     * run-to-run and machine-to-machine (one of item 99's timing dice). A hot
     * QPC loop makes (nearly) ONLY QPC kernel calls, so detect it by
     * CONSECUTIVE kernel-call numbers instead — same trigger point, no wall
     * clock. Yield PRIMARY-ONLY (worker yields here killed boot — bisected;
     * a worker hot loop still exits via the time boost alone). */
    static uint64_t s_boost = 0;
    static uint32_t s_consec = 0;
    static long long s_last_call = -2;   /* 64-bit: see g_kernel_call_count */
    static uint32_t s_run = 0;      /* every-Nth-poll fallback, never reset */
    static uint32_t s_epoch = 0;
    int hot = 0;
    if (s_epoch != xbox_det_epoch()) {
        /* A netplay session started or ended: both machines must begin the
         * session with the same poll history, so it cannot carry over. */
        s_epoch = xbox_det_epoch();
        s_consec = 0;
        s_run = 0;
        s_last_call = -2;
    }
    if (g_xbox_det_active) {
        /* Netplay session: the same hot-poll rules, kept per fiber. The CRI
         * audio workers poll QPC as often as their streaming work demands,
         * which depends on where the menu music was when the session began;
         * counted together with the game thread's polls (and adding to one
         * shared boost) that moved the game thread's time and yields. Each
         * fiber now sees frame time plus only its own boost. */
        static uint32_t d_consec[64], d_run[64];
        static long long d_last[64];
        static uint32_t d_epoch = 0;
        extern int xbox_fiber_is_primary(void);
        int fb = xbox_fiber_current();
        long long kc = (long long)xbox_det_fiber_kcalls();
        uint64_t dv;
        if (fb < 0 || fb >= 64) fb = 63;
        if (d_epoch != xbox_det_epoch()) {
            int i;
            d_epoch = xbox_det_epoch();
            memset(d_consec, 0, sizeof(d_consec));
            memset(d_run, 0, sizeof(d_run));
            for (i = 0; i < 64; i++) d_last[i] = -2;
        }
        if (kc <= d_last[fb] + 2) {
            if (++d_consec[fb] > 150) hot = 1;
        } else {
            d_consec[fb] = 0;
        }
        d_last[fb] = kc;
        if (hot || ++d_run[fb] >= 2048) {
            xbox_det_add_qpc_boost(733333);
            /* The game thread's poll loops wait on worker results (loads):
             * let the workers finish everything, so the number of polls --
             * and with it the boost, which reaches the game's frame delta
             * time (sub_000A06D0 -> 0x85B9C0) -- is the same everywhere. */
            if (xbox_fiber_active() && xbox_fiber_is_primary()) xbox_fiber_run_workers_idle(1024);
            d_run[fb] = 0;
        }
        dv = xbox_det_qpc();
        g_eax = (uint32_t)(dv & 0xFFFFFFFFu);
        g_edx = (uint32_t)(dv >> 32);
        return;
    }
    if ((long long)g_kernel_call_count <= s_last_call + 2) {   /* tolerate 1 interleaved call
                                                     * (e.g. QPC+QueryFrequency loops) */
        if (++s_consec > 150) hot = 1;   /* >150 near-back-to-back QPC calls = hot loop */
    } else {
        s_consec = 0;
    }
    s_last_call = (long long)g_kernel_call_count;
    if (hot) {
        s_boost += 733333;   /* +~10ms of 73.3MHz Xbox QPC ticks per poll */
        {
            extern int xbox_fiber_is_primary(void);
            if (xbox_fiber_active() && xbox_fiber_is_primary()) xbox_fiber_yield();
        }
        s_run = 0;
    } else if (++s_run >= 2048) {
        /* deterministic companion: even when the per-tick gate never trips
         * (slower iteration in interactive sessions), a sustained QPC poll
         * run still gets a scheduling point + time boost. PRIMARY ONLY —
         * yields from CRI worker fibers break the boot handshakes (bisected;
         * the unguarded version of this exact yield killed boot). */
        s_boost += 733333;
        {
            extern int xbox_fiber_is_primary(void);
            if (xbox_fiber_active() && xbox_fiber_is_primary()) xbox_fiber_yield();
        }
        s_run = 0;
    }
    LARGE_INTEGER li = xbox_KeQueryPerformanceCounter();
    uint64_t v = (uint64_t)li.QuadPart + s_boost + xbox_det_qpc_offset();
    g_eax = (uint32_t)(v & 0xFFFFFFFFu);
    g_edx = (uint32_t)(v >> 32);
}

static void bridge_KeQueryPerformanceFrequency(void)
{
    LARGE_INTEGER li = xbox_KeQueryPerformanceFrequency();
    g_eax = (uint32_t)li.LowPart;
    g_edx = (uint32_t)li.HighPart;
}

/* ── KeQuerySystemTime (ordinal 128) ─────────────────────── */
static void bridge_KeQuerySystemTime(void)
{
    uint32_t time_ptr = STACK_ARG(0);
    if (g_xbox_det_active && time_ptr) {
        uint64_t ft = xbox_det_filetime();   /* netplay session clock */
        BRIDGE_MEM32(time_ptr) = (uint32_t)ft;
        BRIDGE_MEM32(time_ptr + 4) = (uint32_t)(ft >> 32);
    } else {
        xbox_KeQuerySystemTime(XBOX_TO_NATIVE(time_ptr));
    }
    g_eax = 0;
}

/* ── MmQueryStatistics (ordinal 181) ─────────────────────── */
static void bridge_MmQueryStatistics(void)
{
    uint32_t stats_ptr = STACK_ARG(0);
    g_eax = (uint32_t)xbox_MmQueryStatistics(XBOX_TO_NATIVE(stats_ptr));
}

/* ── NtCreateEvent (ordinal 189) ─────────────────────────── */
static void bridge_NtCreateEvent(void)
{
    uint32_t handle_ptr = STACK_ARG(0);
    uint32_t obj_attr_ptr = STACK_ARG(1);
    uint32_t event_type = STACK_ARG(2);
    uint32_t initial_state = STACK_ARG(3);

    /* Use local HANDLE to avoid 8-byte write to 4-byte Xbox memory slot.
     * On x64, HANDLE is 8 bytes but Xbox expects 4-byte handles. */
    HANDLE local_handle = NULL;
    NTSTATUS status = xbox_NtCreateEvent(
        &local_handle,
        XBOX_TO_NATIVE(obj_attr_ptr),
        event_type, initial_state);

    if (handle_ptr) {
        BRIDGE_MEM32(handle_ptr) = (uint32_t)(uintptr_t)local_handle;
    }


    g_eax = (uint32_t)status;
}

/* ── KeSynchronizeExecution (ordinal 153) ─────────────────
 * BOOLEAN KeSynchronizeExecution(PKINTERRUPT, PKSYNCHRONIZE_ROUTINE, PVOID ctx):
 * runs the routine with the interrupt masked and returns its result. The
 * interrupt service routine here only ever runs from the game thread
 * (doa2u_apu_deliver_irq), so nothing can preempt the routine and a plain guest
 * call is the whole job. DirectSound's completion DPC (0x1C8D05) uses this to
 * collect the ISR's status bits (0x1C8478); with no bridge it got 0 and never
 * drained a finished buffer, so every one-shot sound effect kept its slot. */
static void bridge_KeSynchronizeExecution(void)
{
    uint32_t routine = STACK_ARG(1), context = STACK_ARG(2);
    recomp_func_t fn = recomp_lookup_manual(routine);
    if (!fn) fn = recomp_lookup(routine);
    if (!fn) {
        g_eax = 0;
        return;
    }
    {
        uint32_t saved_esp = g_esp;
        g_esp -= 4; BRIDGE_MEM32(g_esp) = context;
        g_esp -= 4; BRIDGE_MEM32(g_esp) = 0;          /* dummy return address */
        fn();
        g_esp = saved_esp;                           /* stdcall ret 4 */
    }
    g_eax &= 0xFF;                                   /* BOOLEAN */
}

/* ── KeSetEvent (ordinal 145) ──────────────────────────────
 * Set the KEVENT's signal-state and wake any fiber blocked on it (the CRI worker
 * that's parked in KeWaitForSingleObject). Returns the previous signal-state. */
static void bridge_KeSetEvent(void)
{
    uint32_t event_ptr = STACK_ARG(0);
    int32_t prev = event_ptr ? (int32_t)BRIDGE_MEM32(event_ptr + 4) : 0;
    if (event_ptr) BRIDGE_MEM32(event_ptr + 4) = 1;        /* signaled */
    if (xbox_fiber_active() && event_ptr) xbox_fiber_wake(event_ptr);
    g_eax = (uint32_t)prev;
}

/* ── KeWaitForSingleObject (ordinal 159) ───────────────────
 * Fiber-cooperative, event-accurate wait. cxbx shows the game's CRI worker thread
 * BLOCKS here on a KEVENT until the main thread signals it with KeSetEvent, then
 * wakes and opens loadfile.afs. We model that: block the current fiber on the event
 * VA until its DISPATCHER_HEADER signal-state (obj+4) goes positive (set by
 * KeSetEvent -> xbox_fiber_wake). SynchronizationEvent (Type byte at obj+0 == 1)
 * auto-resets on consumption. The big spin cap is a deadlock safety net only. */
static int g_kwait_log = 0;
static void bridge_KeWaitForSingleObject(void)
{
    uint32_t obj = STACK_ARG(0);
    uint32_t timeout_ptr = STACK_ARG(4);
    int infinite = (timeout_ptr == 0);
    if (g_kwait_log < 30) {
        uint32_t tlo = timeout_ptr ? BRIDGE_MEM32(timeout_ptr) : 0;
        uint32_t thi = timeout_ptr ? BRIDGE_MEM32(timeout_ptr + 4) : 0;
        g_kwait_log++;
    }
    if (xbox_fiber_active() && obj == g_xbox_vblank_event_va && obj) {
        /* D3D vblank event: on hardware the GPU vblank interrupt signals it
         * every 16.7ms, so an INFINITE wait always returns. We have no GPU
         * interrupt; only boot-time diagnostic wrappers pulsed it, and once
         * those went quiet the main thread parked here forever (frame counter
         * froze at 1801, the whole XAPI task system starved). Model "vblank
         * always fires": yield once so other fibers get their slice, then
         * report the wait satisfied. */
        /* Netplay session: the workers finish all queued work here, so a load
         * wait loop takes the same number of vblanks on every machine. */
        /* The ADX vsync server (sub_0016A570) takes exactly one vblank per
         * lockstep frame: spinning it here ticked the stream ~1000 times a
         * frame and the music stopped reading. The file server keeps
         * finishing all queued I/O inside the frame, so a load completes on
         * the same frame on both machines whatever music was in flight. */
        if (g_xbox_det_active && xbox_fiber_current_ctx1() == g_xbox_vsync_server_routine)
            xbox_fiber_block(XBOX_DET_VBLANK_KEY);
        else if (g_xbox_det_active && (xbox_fiber_is_primary() || xbox_fiber_is_coroutine())) xbox_fiber_run_workers_idle(1024);
        else xbox_fiber_yield();
        BRIDGE_MEM32(obj + 4) = 0;
        /* Run the CRI server pump on each vblank wait: on hardware the ADXM
         * user callbacks fire from the vsync interrupt, so game-side wait
         * loops ("wait vblank; poll movie status") make progress WITHOUT
         * presenting. Our pump used to live only in the Present path ->
         * those loops livelocked (item 79). Re-entrancy handled inside. */
        if (xbox_fiber_is_primary() || xbox_fiber_is_coroutine()) {
            extern void game_pump_vblank_servers(void);
            game_pump_vblank_servers();
        }
        {
            static uint64_t s_vbw = 0;
            if ((++s_vbw % 100000ull) == 0) {
                void *bt[14];
                USHORT nf = CaptureStackBackTrace(1, 14, bt, NULL);
            }
        }
        /* Also advance the D3D vblank COUNTER (device+0x820): the game's
         * frame-pacing loops (e.g. the movie blit throttle) wait the vblank
         * event N times and read the counter to see time pass; without the
         * bump they spin forever inside the frame (Present never runs, so
         * the SetFence-wrapper vblank emulation cannot advance it either). */
        if (g_xbox_vblank_counter_va) BRIDGE_MEM32(g_xbox_vblank_counter_va) = BRIDGE_MEM32(g_xbox_vblank_counter_va) + 1;
        g_eax = 0;
        return;
    }
    if (xbox_fiber_active() && obj) {
        long budget = 200000;   /* timed-wait yield budget before STATUS_TIMEOUT */
        for (;;) {
            int32_t sig = (int32_t)BRIDGE_MEM32(obj + 4);   /* SignalState */
            if (sig > 0) {
                /* Consume the signal for SynchronizationEvents (auto-reset)
                 * AND for the D3D vblank event (0x001C2CF0): it is a
                 * notification event that our port pulses but nothing ever
                 * resets, so the CRI ADX master server's per-tick wait
                 * succeeded instantly forever — a hot resume/suspend spin
                 * (600M+ kernel calls) that starved the render loop to 3 fps
                 * once the Sofdec movie player started. (A blanket consume
                 * broke real notification-event handshakes — the CRI I/O
                 * worker's work-pending event must STAY signaled.) */
                if ((BRIDGE_MEM8(obj) & 0xFF) == 1)  /* bisect: vblank consume off */
                    BRIDGE_MEM32(obj + 4) = 0;
                g_eax = 0;                                  /* STATUS_WAIT_0 */
                return;
            }
            if (infinite) {
                xbox_fiber_block(obj);                      /* block until KeSetEvent wakes us */
            } else {
                if (--budget <= 0) { g_eax = 0x00000102u; return; } /* STATUS_TIMEOUT */
                xbox_fiber_yield();                         /* stay runnable, re-check */
            }
        }
    }
    g_eax = 0;
}

/* ── NtYieldExecution (ordinal 238) ──────────────────────── */
static void bridge_NtYieldExecution(void)
{
    g_eax = (uint32_t)xbox_NtYieldExecution();
}

/* ── MmGetPhysicalAddress (ordinal 173) ──────────────────── */
static void bridge_MmGetPhysicalAddress(void)
{
    uint32_t addr = STACK_ARG(0);
    /* Xbox uses identity mapping (physical == virtual) for the lower 64MB.
     * Just return the Xbox VA as-is. Don't call xbox_MmGetPhysicalAddress
     * which would return a native pointer. */
    g_eax = addr;
}

/* ── MmSetAddressProtect (ordinal 182) ───────────────────── */
static void bridge_MmSetAddressProtect(void)
{
    uint32_t addr = STACK_ARG(0);
    uint32_t size = STACK_ARG(1);
    uint32_t prot = STACK_ARG(2);

    xbox_MmSetAddressProtect(XBOX_TO_NATIVE(addr), size, prot);
    g_eax = 0;
}

/* ── AvSetDisplayMode (ordinal 3) ────────────────────────── */
static void bridge_AvSetDisplayMode(void)
{
    uint32_t addr = STACK_ARG(0);
    uint32_t step = STACK_ARG(1);
    uint32_t mode = STACK_ARG(2);
    uint32_t format = STACK_ARG(3);
    uint32_t pitch = STACK_ARG(4);
    uint32_t fb = STACK_ARG(5);

    xbox_AvSetDisplayMode(XBOX_TO_NATIVE(addr), step, mode, format, pitch, fb);
    g_eax = 0;
}

/* ── PsTerminateSystemThread (ordinal 258) ───────────────
 * VOID PsTerminateSystemThread(NTSTATUS ExitStatus)
 *
 * On real Xbox, this terminates the calling thread (never returns).
 * In our recompiled version, threads run synchronously, so we just
 * return. The caller (sub_001D1818) handles this gracefully.
 */
static void bridge_PsTerminateSystemThread(void)
{
    uint32_t exit_status = STACK_ARG(0);


    g_eax = exit_status;
    if (g_xbox_cache_install_routine &&
        xbox_fiber_current_ctx1() == g_xbox_cache_install_routine) {
        g_xbox_cache_install_exit = exit_status;
        g_xbox_cache_install_exited = 1;
    }
    /* On real Xbox this never returns (the thread is destroyed). In the fiber
     * model, end the current worker fiber and switch away — otherwise control
     * returns to the caller (sub_00164B6F) which then hits its int3. No-op on the
     * primary fiber, where we fall through and return normally. */
    xbox_fiber_exit();
}

/* ── NtSuspendThread (ordinal 231) ─────────────────────────
 * NTSTATUS NtSuspendThread(HANDLE Thread, PULONG PreviousSuspendCount)
 * The game's CRI worker self-suspends (NtSuspendThread on its own handle) at the end
 * of each loop iteration to wait for the next I/O request; the main thread later
 * NtResumeThread's it. The real call blocks; modeled here by parking this fiber on
 * its thread handle until xbox_fiber_wake(handle) (NtResumeThread). */
static void bridge_NtSuspendThread(void)
{
    uint32_t handle = STACK_ARG(0);
    uint32_t prev_va = STACK_ARG(1);
    if (prev_va) BRIDGE_MEM32(prev_va) = 0;
    /* Only a CRI worker thread self-suspends to wait for work. The main thread and
     * the XAPI game-task coroutines suspend OTHER threads (e.g. pausing background
     * streaming) — blocking the CALLER there parks the game forever (all fake
     * thread handles are identical, so treat any non-worker caller as suspending
     * someone else and no-op). */
    {
        extern int xbox_fiber_is_coroutine(void);
        if (xbox_fiber_active() && !xbox_fiber_is_primary() && !xbox_fiber_is_coroutine())
            xbox_fiber_block(handle ? handle : 0xFFFFFFFFu);
    }
    g_eax = 0;
}

/* ── NtResumeThread (ordinal 224) ──────────────────────────
 * NTSTATUS NtResumeThread(HANDLE Thread, PULONG PreviousSuspendCount)
 * Wake the fiber parked on this thread handle (the suspended CRI worker). */
static void bridge_NtResumeThread(void)
{
    uint32_t handle = STACK_ARG(0);
    uint32_t prev_va = STACK_ARG(1);
    static unsigned s_rn = 0;
    if (prev_va) BRIDGE_MEM32(prev_va) = 0;
    if (++s_rn <= 8 || (s_rn % 200000) == 0) {
    }
    if (xbox_fiber_active()) {
        extern int xbox_fiber_is_coroutine(void);
        extern int xbox_fiber_is_primary(void);
        extern int xbox_fiber_run_thread(uint32_t xhandle);
        /* item 100: do NOT add "resume credits" for resumes that wake nobody —
         * tried twice (unconditional, then wake_count==0-gated) and BOTH
         * collapsed playback: the ADXM protocol retries resumes against an
         * already-running server hundreds of times/frame, so any credit
         * scheme keeps the sfdec servers from ever parking (one worker then
         * monopolizes the scheduler). Lost resumes are healed by the
         * protocol's own retries; the one place the retries STOP (main stuck
         * in the sub_00169150 mount poll) is covered by the gated
         * [MOUNTNUDGE] in that wrapper. */
        xbox_fiber_wake(handle ? handle : 0xFFFFFFFFu);
        /* Scheduling: the resumed thread must actually RUN, or resume-poll
         * loops spin forever.
         *  - game-task coroutines: general yield (proven since item 42).
         *  - the PRIMARY fiber: a DIRECTED handoff to the resumed thread's
         *    fiber only (xbox_fiber_run_thread) — the ADXM lock acquire in
         *    the per-frame server pump resumes the parked CRI server thread
         *    and retries; without running that fiber the retry loop spun
         *    2+ billion kernel calls in interactive launches (evidence:
         *    user's doa2u_log.txt). A GENERAL yield here regressed playback
         *    (other fibers re-entered CRI code mid-pump) — do not widen.
         *  - CRI worker fibers: no scheduling point — a yield here deadlocks
         *    the boot-time master<->worker handshake (bisected). */
        if (xbox_fiber_is_coroutine())
            xbox_fiber_yield();
        else if (xbox_fiber_is_primary())
            xbox_fiber_run_thread(handle);
    }
    g_eax = 0;
}

/* ── HalReadSMCTrayState (ordinal 47) ─────────────────────
 * VOID HalReadSMCTrayState(PDWORD TrayState, PDWORD TrayStateChangeCount)
 *
 * Returns DVD tray state. 0x10 = no disc, 0x14 = tray closed with disc.
 */
static void bridge_HalReadSMCTrayState(void)
{
    uint32_t state_ptr = STACK_ARG(0);
    uint32_t count_ptr = STACK_ARG(1);

    if (state_ptr) BRIDGE_MEM32(state_ptr) = 0x10;  /* No disc */
    if (count_ptr) BRIDGE_MEM32(count_ptr) = 0;
    g_eax = 0;
}

/* ── KeInitializeDpc (ordinal 107) ────────────────────────
 * VOID KeInitializeDpc(PKDPC Dpc, PKDEFERRED_ROUTINE DeferredRoutine,
 *                       PVOID DeferredContext)
 *
 * Initializes a DPC object. The Xbox KDPC structure is 32 bytes.
 * We zero it and set the routine and context pointers.
 */
static void bridge_KeInitializeDpc(void)
{
    uint32_t dpc_va = STACK_ARG(0);
    uint32_t routine = STACK_ARG(1);
    uint32_t context = STACK_ARG(2);

    /* Zero the structure (32 bytes) */
    memset(XBOX_TO_NATIVE(dpc_va), 0, 32);

    /* Set Type (0x13 = DpcObject) and fields */
    BRIDGE_MEM16(dpc_va + 0) = 0x13;   /* Type */
    BRIDGE_MEM32(dpc_va + 12) = routine; /* DeferredRoutine */
    BRIDGE_MEM32(dpc_va + 16) = context; /* DeferredContext */
    g_eax = 0;
}

/* ── KeInitializeTimerEx (ordinal 113) ────────────────────
 * VOID KeInitializeTimerEx(PKTIMER Timer, TIMER_TYPE Type)
 *
 * Initializes a timer object. Xbox KTIMER is 40 bytes.
 */
static void bridge_KeInitializeTimerEx(void)
{
    uint32_t timer_va = STACK_ARG(0);
    uint32_t type = STACK_ARG(1);

    /* Zero the structure (40 bytes) */
    memset(XBOX_TO_NATIVE(timer_va), 0, 40);

    /* Set Type (0x08 = TimerNotificationObject, 0x09 = TimerSynchronizationObject) */
    BRIDGE_MEM16(timer_va + 0) = (uint16_t)(0x08 + (type & 1));
    g_eax = 0;
}

/* ── KeSetTimer / KeSetTimerEx (ordinal 149/150) ──────────
 * BOOLEAN KeSetTimer(PKTIMER Timer, LARGE_INTEGER DueTime, PKDPC Dpc)
 *
 * Sets a timer. We don't actually start timers - just record the state.
 * Returns FALSE (timer was not already set).
 */
static void bridge_KeSetTimer(void)
{
    /* Timer functionality is not needed for basic execution.
     * Return FALSE = timer was not previously set. */
    g_eax = 0;
}

/* ── Ordinal 24 ───────────────────────────────────────────
 * Named ExQueryPoolBlockSize in this table, but every game caller pushes the
 * five arguments of ExQueryNonVolatileSetting(ValueIndex, &Type, &Value,
 * ValueLength, &ResultLength) -- sub_00163C84/CB1/CDA/D05/D49 are XAPI's
 * XGetLanguage / XGetAVPack / XGetVideoFlags / XGetAudioFlags / parental
 * getters. The stub writes nothing, so each getter reads back whatever its
 * `push ecx` left in the value slot.
 *
 * Only XC_VIDEO (index 8) is answered, from the video settings: bit 16 is
 * XC_VIDEO_FLAGS_WIDESCREEN, which switches the game to its own widescreen
 * projection. The other indices keep the old behaviour.
 */
extern unsigned video_xc_video_value(void);
static void bridge_ExQueryPoolBlockSize(void)
{
    uint32_t index = STACK_ARG(0);
    if (index == 8 && STACK_ARG(2)) {
        BRIDGE_MEM32(STACK_ARG(2)) = video_xc_video_value();
        if (STACK_ARG(1)) BRIDGE_MEM32(STACK_ARG(1)) = 4;   /* REG_DWORD */
        if (STACK_ARG(4)) BRIDGE_MEM32(STACK_ARG(4)) = 4;
    }
    g_eax = 0;
}

/* ── RtlNtStatusToDosError (ordinal 301) ─────────────────
 * ULONG RtlNtStatusToDosError(NTSTATUS Status)
 *
 * Converts an NTSTATUS to a Win32 error code.
 */
static void bridge_RtlNtStatusToDosError(void)
{
    uint32_t status = STACK_ARG(0);

    /* Simple mapping of common status codes */
    switch (status) {
    case 0x00000000: g_eax = 0; break;          /* STATUS_SUCCESS → ERROR_SUCCESS */
    case 0xC0000034: g_eax = 2; break;          /* STATUS_OBJECT_NAME_NOT_FOUND → ERROR_FILE_NOT_FOUND */
    case 0xC000003A: g_eax = 3; break;          /* STATUS_OBJECT_PATH_NOT_FOUND → ERROR_PATH_NOT_FOUND */
    case 0xC0000022: g_eax = 5; break;          /* STATUS_ACCESS_DENIED → ERROR_ACCESS_DENIED */
    case 0xC0000008: g_eax = 6; break;          /* STATUS_INVALID_HANDLE → ERROR_INVALID_HANDLE */
    case 0xC0000017: g_eax = 8; break;          /* STATUS_NO_MEMORY → ERROR_NOT_ENOUGH_MEMORY */
    case 0xC000000D: g_eax = 87; break;         /* STATUS_INVALID_PARAMETER → ERROR_INVALID_PARAMETER */
    default:         g_eax = 317; break;         /* ERROR_MR_MID_NOT_FOUND (generic) */
    }
}

/* ── File I/O bridge helpers ─────────────────────────────── */

/*
 * Xbox structures use 32-bit pointers. On Win64, the C structs
 * (XBOX_OBJECT_ATTRIBUTES, etc.) have 64-bit pointers, so we can't
 * cast Xbox memory to them directly. Instead, parse the 32-bit
 * Xbox layout manually:
 *
 * XBOX_OBJECT_ATTRIBUTES (12 bytes):
 *   offset 0: RootDirectory  (uint32_t)
 *   offset 4: ObjectName     (uint32_t, Xbox VA to ANSI_STRING)
 *   offset 8: Attributes     (uint32_t)
 *
 * XBOX_ANSI_STRING (8 bytes):
 *   offset 0: Length          (uint16_t)
 *   offset 2: MaximumLength   (uint16_t)
 *   offset 4: Buffer          (uint32_t, Xbox VA to char[])
 *
 * XBOX_IO_STATUS_BLOCK (8 bytes):
 *   offset 0: Status          (uint32_t)
 *   offset 4: Information     (uint32_t)
 */

/* Extract the ANSI path string from an Xbox OBJECT_ATTRIBUTES.
 * Layout: +0 RootDirectory (HANDLE), +4 ObjectName (PANSI_STRING), +8 Attributes.
 * ANSI_STRING is a COUNTED string: Length (u16) bytes at Buffer, not necessarily
 * NUL-terminated. XAPI routinely passes a Length shorter than the buffer content
 * (e.g. FindFirstFileA opens the directory part "d:\" of "d:\loadfile.afs" with
 * Length=3), so the Length must be honored — returning the raw buffer opened the
 * wrong object. Copies into a static buffer valid until the next call. */
static const char* bridge_get_xbox_path(uint32_t obj_attrs_va)
{
    static char s_path[MAX_PATH];
    uint32_t ansi_str_va, buf_va;
    uint16_t len;
    if (!obj_attrs_va) return NULL;
    ansi_str_va = BRIDGE_MEM32(obj_attrs_va + 4);
    if (!ansi_str_va) {
        return NULL;
    }
    buf_va = BRIDGE_MEM32(ansi_str_va + 4);
    if (!buf_va) {
        return NULL;
    }
    len = BRIDGE_MEM16(ansi_str_va);
    if (len >= MAX_PATH) len = MAX_PATH - 1;
    memcpy(s_path, (const char*)XBOX_TO_NATIVE(buf_va), len);
    s_path[len] = '\0';
    return s_path;
}

/* Write NTSTATUS + Information into Xbox IO_STATUS_BLOCK */
static void bridge_write_iostatus(uint32_t ios_va, NTSTATUS status, uint32_t info)
{
    if (ios_va) {
        BRIDGE_MEM32(ios_va + 0) = (uint32_t)status;
        BRIDGE_MEM32(ios_va + 4) = info;
    }
}

/* Write a Win32 HANDLE into a 32-bit Xbox memory slot.
 * Win32 handles fit in 32 bits even on Win64. */
/* Guest file handles are opaque and never reused.
 *
 * Handing the guest raw Win32 HANDLE values lets Windows recycle a value the
 * guest still holds: a double-clicked boot issued 0x7F4 for d:\\voice.afs,
 * closed it, and Windows then gave the same 0x7F4 to the z:\\ directory
 * handle. The guest kept reading with its cached 0x7F4 and got
 * ERROR_INVALID_HANDLE from a directory forever -- 482,000 failed reads and a
 * boot that never finished. Which values get recycled depends on open/close
 * ordering, which is why it reproduced on a double-click but not on a
 * shell launch with redirected output.
 *
 * Publish a tagged, monotonically increasing id instead and keep the real
 * HANDLE in a table. A stale guest handle then resolves to a dead slot and
 * fails cleanly rather than aliasing a different live object. Values outside
 * the tagged range pass through untouched, so event/thread/synthetic handles
 * are unaffected. */
#define XFH_TAG   0x66000000u
#define XFH_MAX   4096
static HANDLE s_fh[XFH_MAX];
static WCHAR  s_fh_path[XFH_MAX][MAX_PATH];
static unsigned char s_fh_write[XFH_MAX];   /* opened with write access */
static unsigned s_fh_next;

/* Is any live guest handle writing this host path? (the wxCi cache
 * installer holds its z:\ target open for write while it copies) */
static int xbox_fh_has_writer(const WCHAR *win_path)
{
    unsigned i;
    for (i = 0; i < s_fh_next && i < XFH_MAX; i++)
        if (s_fh[i] && s_fh_write[i] && _wcsicmp(s_fh_path[i], win_path) == 0)
            return 1;
    return 0;
}

static uint32_t xbox_fh_publish(HANDLE h, const WCHAR *win_path)
{
    if (s_fh_next >= XFH_MAX) {
        static int told = 0;
        if (!told) { told = 1;
             }
        return (uint32_t)(uintptr_t)h;
    }
    s_fh[s_fh_next] = h;
    s_fh_write[s_fh_next] = 0;
    s_fh_path[s_fh_next][0] = 0;
    if (win_path)
        wcsncpy_s(s_fh_path[s_fh_next], MAX_PATH, win_path, MAX_PATH - 1);
    return XFH_TAG | (uint32_t)(s_fh_next++ * 4u);
}

static HANDLE xbox_fh_resolve(uint32_t gh)
{
    if ((gh & 0xFF000000u) == XFH_TAG) {
        unsigned i = (gh & 0x00FFFFFFu) / 4u;
        if (i < XFH_MAX && s_fh[i])
            return s_fh[i];
        /* Retired id. The CRI partition setup closes its d: handles and
         * opens the z: cache equivalents, but one partition keeps reading
         * through its old d: handle -- a use-after-close in the guest that
         * raw Win32 handles used to hide, because Windows had recycled the
         * value to some other live file and the read returned that file's
         * bytes instead. Re-open the file this id actually named, so the
         * read gets the right data and boot proceeds. */
        if (i < XFH_MAX && s_fh_path[i][0]) {
            HANDLE r = CreateFileW(s_fh_path[i], GENERIC_READ,
                                   FILE_SHARE_READ | FILE_SHARE_WRITE,
                                   NULL, OPEN_EXISTING,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
            if (r != INVALID_HANDLE_VALUE) {
                static int told = 0;
                s_fh[i] = r;
                if (told < 8) { told++;
                     }
                return r;
            }
        }
        return INVALID_HANDLE_VALUE;
    }
    return (HANDLE)(uintptr_t)gh;               /* not ours: unchanged */
}

static const WCHAR *xbox_fh_path(uint32_t gh)
{
    if ((gh & 0xFF000000u) == XFH_TAG) {
        unsigned i = (gh & 0x00FFFFFFu) / 4u;
        if (i < XFH_MAX) return s_fh_path[i];
    }
    return NULL;
}

static int xbox_fh_release(uint32_t gh)
{
    if ((gh & 0xFF000000u) == XFH_TAG) {
        unsigned i = (gh & 0x00FFFFFFu) / 4u;
        if (i < XFH_MAX && s_fh[i]) {
            { static int nrel = 0;
              if (nrel < 64) { nrel++;
                   } }
            CloseHandle(s_fh[i]);
            s_fh[i] = NULL;   /* id never reissued; path kept for reopen */
        }
        return 1;
    }
    return 0;
}


static void bridge_write_handle(uint32_t handle_va, HANDLE h)
{
    if (handle_va)
        BRIDGE_MEM32(handle_va) = (uint32_t)(uintptr_t)h;
}

/* Read a Win32 HANDLE from a 32-bit Xbox memory slot */
static HANDLE bridge_read_handle(uint32_t va)
{
    return (HANDLE)(uintptr_t)BRIDGE_MEM32(va);
}

/* Translate Xbox path and open file via Win32 CreateFileW */
/* z:\ cache copies of the game archives: cache MISS -> the d:\ original.
 *
 * The game's wxCi installer copies loadfile/bgm/voice.afs to Z: in the background
 * and the boot keeps going meanwhile. On the console a copy that is not there
 * yet is a plain cache miss and the CRI reads the disc instead. Here that
 * miss was fatal: with an empty cache the installer was still on voice.afs
 * when the boot's partition load asked for z:\loadfile.afs, the open failed
 * ("can not open 'z:\loadfile.afs'" from wxCiOpen), ADXF parked the
 * partition in error (-3) and the boot spun on the mount forever. A re-install
 * has the same window: the target is truncated first and grows while the
 * game already reads from it (an interrupted install left a 53 MB
 * loadfile.afs in the user's cache and the post-movie loads read past its
 * end).
 *
 * So a READ open (or path stat) of one of the three archives under z:\ uses
 * the d:\ original while the cache copy is missing or an installer has it
 * open for writing. A complete, stamped copy is used exactly as before, and
 * an interrupted copy fails validation on the next boot and is redone. Write
 * opens are never redirected. */
static int bridge_cache_archive_fallback(const char *xbox_path, WCHAR *win_path,
                                         DWORD win_access, const char *why)
{
    static const char *k_afs[] = { "loadfile.afs", "bgm.afs", "voice.afs" };
    const char *name;
    int i;
    if (!xbox_path || !((xbox_path[0] == 'z' || xbox_path[0] == 'Z') && xbox_path[1] == ':'))
        return 0;
    if (win_access & (GENERIC_WRITE | GENERIC_ALL | FILE_WRITE_DATA | FILE_APPEND_DATA |
                      FILE_WRITE_ATTRIBUTES | DELETE))
        return 0;
    name = xbox_path + 2;
    while (*name == '\\' || *name == '/') name++;
    for (i = 0; i < 3; i++) {
        if (_stricmp(name, k_afs[i]) == 0) {
            int missing = 0;   /* a missing copy must stay visible: the validator decides to install */
            int installing = xbox_fh_has_writer(win_path);
            char dpath[64];
            WCHAR alt[MAX_PATH];
            if (!installing) return 0;
            snprintf(dpath, sizeof dpath, "D:\\%s", k_afs[i]);
            if (xbox_translate_path(dpath, alt, MAX_PATH) &&
                GetFileAttributesW(alt) != INVALID_FILE_ATTRIBUTES) {
                wcscpy_s(win_path, MAX_PATH, alt);
                return 1;
            }
        }
    }
    return 0;
}

static NTSTATUS bridge_create_file_impl(
    uint32_t handle_va, ACCESS_MASK access, uint32_t obj_attrs_va,
    uint32_t iostatus_va, ULONG file_attrs, ULONG share,
    ULONG disposition, ULONG options)
{
    WCHAR win_path[MAX_PATH];
    HANDLE h;
    DWORD win_access = 0, win_share = 0, win_disp, flags_and_attrs = FILE_ATTRIBUTE_NORMAL;
    const char* xbox_path;
    DWORD err;

    xbox_path = bridge_get_xbox_path(obj_attrs_va);
    if (!xbox_path) {
        bridge_write_iostatus(iostatus_va, STATUS_OBJECT_PATH_NOT_FOUND, 0);
        return STATUS_OBJECT_PATH_NOT_FOUND;
    }
    {   /* Let the game layer see every guest file open (the movie presenter
         * starts on the .sfd the guest opens). */
        extern void game_on_file_open(const char *xbox_path);
        game_on_file_open(xbox_path);
    }

    if (!xbox_translate_path(xbox_path, win_path, MAX_PATH)) {
        bridge_write_iostatus(iostatus_va, STATUS_OBJECT_PATH_NOT_FOUND, 0);
        return STATUS_OBJECT_PATH_NOT_FOUND;
    }

    /* Directory-enumeration open: the CRI ADXF middleware opens a path with a trailing
     * wildcard (e.g. "d:\*") to obtain a directory handle for NtQueryDirectoryFile.
     * CreateFileW rejects wildcards, so strip the wildcard component and open the parent
     * directory itself (the wildcard becomes the NtQueryDirectoryFile search pattern). */
    if (wcschr(win_path, L'*') || wcschr(win_path, L'?')) {
        WCHAR *sep = wcsrchr(win_path, L'\\');
        if (sep) *sep = L'\0';
        options |= 0x00000001;  /* FILE_DIRECTORY_FILE */
        disposition = 1;        /* FILE_OPEN */
    }

    /* Access mask translation. NT generic rights match Win32 bit-for-bit:
     * 0x80000000 = GENERIC_READ (NOT GENERIC_ALL — mapping it to GENERIC_ALL
     * requested write+delete on read-only opens and drew ERROR_ACCESS_DENIED). */
    if (access & 0x80000000) win_access |= GENERIC_READ;
    if (access & 0x40000000) win_access |= GENERIC_WRITE;
    if (access & 0x20000000) win_access |= GENERIC_EXECUTE;
    if (access & 0x10000000) win_access |= GENERIC_ALL;
    if (access & 0x00000001) win_access |= FILE_READ_DATA;
    if (access & 0x00000002) win_access |= FILE_WRITE_DATA;
    if (access & 0x00000004) win_access |= FILE_APPEND_DATA;
    if (access & 0x00000080) win_access |= FILE_READ_ATTRIBUTES;
    if (access & 0x00000100) win_access |= FILE_WRITE_ATTRIBUTES;
    if (access & 0x00100000) win_access |= SYNCHRONIZE;
    if (win_access == 0 || win_access == SYNCHRONIZE)
        win_access |= GENERIC_READ;

    bridge_cache_archive_fallback(xbox_path, win_path, win_access, "open");

    /* Share mode: always grant full sharing. The Xbox kernel's FATX driver
     * was permissive within a title; the game's wxCi cache installer holds a
     * WRITE handle to z:\voice.afs while its streamer re-opens the same file
     * for READ — with host share semantics that read open died with
     * ERROR_SHARING_VIOLATION and the whole ADXSTM voice stream failed. */
    (void)share;
    win_share = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;

    /* Disposition */
    switch (disposition) {
    case 0: win_disp = CREATE_ALWAYS; break;     /* FILE_SUPERSEDE */
    case 1: win_disp = OPEN_EXISTING; break;     /* FILE_OPEN */
    case 2: win_disp = CREATE_NEW; break;        /* FILE_CREATE */
    case 3: win_disp = OPEN_ALWAYS; break;       /* FILE_OPEN_IF */
    case 4: win_disp = TRUNCATE_EXISTING; break; /* FILE_OVERWRITE */
    case 5: win_disp = CREATE_ALWAYS; break;     /* FILE_OVERWRITE_IF */
    default: win_disp = OPEN_EXISTING; break;
    }

    /* Handle directory requests */
    {
        /* Xbox FATX also lets a title open a DIRECTORY without
         * FILE_DIRECTORY_FILE (the game's wxCi cache scanner opens 'z:\.' to
         * enumerate the cache). Host CreateFileW needs BACKUP_SEMANTICS for
         * that or it fails with ACCESS_DENIED — which made the cache scan
         * fail, the cache table stay empty, and the game re-copy its AFS
         * files to z: forever. Detect existing-directory targets and treat
         * them as directory opens. */
        DWORD tattrs = GetFileAttributesW(win_path);
        if (!(options & 0x00000001) &&
            tattrs != INVALID_FILE_ATTRIBUTES && (tattrs & FILE_ATTRIBUTE_DIRECTORY))
            options |= 0x00000001;
    }
    if (options & 0x00000001) { /* FILE_DIRECTORY_FILE */
        if (disposition == 2 || disposition == 3)
            CreateDirectoryW(win_path, NULL);
        h = CreateFileW(win_path, win_access, win_share, NULL,
                        OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
    } else {
        /* FILE_NO_INTERMEDIATE_BUFFERING (options & 8): do NOT map to
         * FILE_FLAG_NO_BUFFERING — host no-buffering demands sector-aligned
         * buffers/offsets/lengths that Xbox virtual addresses don't satisfy,
         * making every ReadFile fail. Buffered host I/O is semantically fine. */
        if (file_attrs & 0x00000001) /* FILE_ATTRIBUTE_READONLY */
            flags_and_attrs |= FILE_ATTRIBUTE_READONLY;
        h = CreateFileW(win_path, win_access, win_share, NULL,
                        win_disp, flags_and_attrs, NULL);
    }

    /* NT semantics: a FILE_DIRECTORY_FILE open of an EXISTING regular file must fail
     * with STATUS_NOT_A_DIRECTORY (not NAME_NOT_FOUND). The CRI's cache probe
     * (sub_00167A6D) distinguishes exactly these two: NOT_A_DIRECTORY = "it's a plain
     * file", NOT_FOUND = "no such cache entry, use the disc". Do NOT consult the D:
     * disc here — on real hardware the Z: cache is simply empty and the CRI itself
     * falls back to D: on the miss. */
    if (h == INVALID_HANDLE_VALUE && (options & 0x00000001)) {
        DWORD attrs = GetFileAttributesW(win_path);
        if (attrs != INVALID_FILE_ATTRIBUTES && !(attrs & FILE_ATTRIBUTE_DIRECTORY)) {
            bridge_write_iostatus(iostatus_va, 0xC0000103u, 0); /* STATUS_NOT_A_DIRECTORY */
            return 0xC0000103u;
        }
    }

    if (h == INVALID_HANDLE_VALUE) {
        err = GetLastError();
        bridge_write_iostatus(iostatus_va, STATUS_OBJECT_NAME_NOT_FOUND, 0);
        switch (err) {
        case ERROR_FILE_NOT_FOUND: return STATUS_OBJECT_NAME_NOT_FOUND;
        case ERROR_PATH_NOT_FOUND: return STATUS_OBJECT_PATH_NOT_FOUND;
        case ERROR_ACCESS_DENIED:  return 0xC0000022u; /* STATUS_ACCESS_DENIED */
        case ERROR_ALREADY_EXISTS: return 0xC0000035u; /* STATUS_OBJECT_NAME_COLLISION */
        default:                   return 0xC0000001u; /* STATUS_UNSUCCESSFUL */
        }
    }

    {
        uint32_t gh = xbox_fh_publish(h, win_path);
        if ((gh & 0xFF000000u) == XFH_TAG &&
            (win_access & (GENERIC_WRITE | GENERIC_ALL | FILE_WRITE_DATA | FILE_APPEND_DATA)))
            s_fh_write[(gh & 0x00FFFFFFu) / 4u] = 1;
        if (handle_va) BRIDGE_MEM32(handle_va) = gh;
        bridge_write_iostatus(iostatus_va, STATUS_SUCCESS,
                              (disposition == 2) ? 2 /* FILE_CREATED */ : 1 /* FILE_OPENED */);
    }
    return STATUS_SUCCESS;
}

/* ── NtCreateFile (ordinal 190, 9 args = 36 bytes) ─────── */
static void bridge_NtCreateFile(void)
{
    xbox_det_note_io();
    uint32_t handle_va   = STACK_ARG(0);  /* PHANDLE */
    uint32_t access      = STACK_ARG(1);  /* ACCESS_MASK */
    uint32_t obj_attrs   = STACK_ARG(2);  /* POBJECT_ATTRIBUTES */
    uint32_t iostatus    = STACK_ARG(3);  /* PIO_STATUS_BLOCK */
    /* arg4: AllocationSize - ignored */
    uint32_t file_attrs  = STACK_ARG(5);  /* FileAttributes */
    uint32_t share       = STACK_ARG(6);  /* ShareAccess */
    uint32_t disposition = STACK_ARG(7);  /* CreateDisposition */
    uint32_t options     = STACK_ARG(8);  /* CreateOptions */

    g_eax = (uint32_t)bridge_create_file_impl(
        handle_va, access, obj_attrs, iostatus,
        file_attrs, share, disposition, options);
}

/* ── NtOpenFile (ordinal 202, 6 args = 24 bytes) ──────── */
static void bridge_NtOpenFile(void)
{
    xbox_det_note_io();
    uint32_t handle_va = STACK_ARG(0);  /* PHANDLE */
    uint32_t access    = STACK_ARG(1);  /* ACCESS_MASK */
    uint32_t obj_attrs = STACK_ARG(2);  /* POBJECT_ATTRIBUTES */
    uint32_t iostatus  = STACK_ARG(3);  /* PIO_STATUS_BLOCK */
    uint32_t share     = STACK_ARG(4);  /* ShareAccess */
    uint32_t options   = STACK_ARG(5);  /* OpenOptions */

    /* NtOpenFile = NtCreateFile with FILE_OPEN disposition */
    g_eax = (uint32_t)bridge_create_file_impl(
        handle_va, access, obj_attrs, iostatus,
        0, share, 1 /* FILE_OPEN */, options);
}

/* ── NtReadFile (ordinal 219, 8 args = 32 bytes) ──────── */
/* ── Pending user-APC queue (I/O completions from ReadFileEx/WriteFileEx).
 * Real NT delivers these during an alertable wait; the CRI's completion
 * handshake depends on that ordering. Delivered by KeDelayExecutionThread. */
#define APC_QUEUE_MAX 16
static struct { uint32_t ctx, iosb, bytes; } s_apc_queue[APC_QUEUE_MAX];
static int s_apc_count = 0;

static void bridge_apc_queue(uint32_t ctx, uint32_t iosb, uint32_t bytes)
{
    if (s_apc_count < APC_QUEUE_MAX) {
        s_apc_queue[s_apc_count].ctx = ctx;
        s_apc_queue[s_apc_count].iosb = iosb;
        s_apc_queue[s_apc_count].bytes = bytes;
        s_apc_count++;
    }
}

/* Deliver all pending APCs (calls the recompiled completion routines).
 * Returns nonzero if any were delivered. */
static int bridge_apc_deliver(void)
{
    int n = s_apc_count, i;
    if (!n) return 0;
    s_apc_count = 0;
    for (i = 0; i < n; i++) {
        recomp_func_t fn = recomp_lookup_manual(s_apc_queue[i].ctx);
        if (!fn) fn = recomp_lookup(s_apc_queue[i].ctx);
        if (fn) {
            uint32_t saved_esp = g_esp;
            g_esp -= 4; BRIDGE_MEM32(g_esp) = s_apc_queue[i].iosb;  /* lpOverlapped */
            g_esp -= 4; BRIDGE_MEM32(g_esp) = s_apc_queue[i].bytes; /* dwBytesTransferred */
            g_esp -= 4; BRIDGE_MEM32(g_esp) = 0;                    /* dwErrorCode */
            g_esp -= 4; BRIDGE_MEM32(g_esp) = 0;                    /* dummy return address */
            fn();
            g_esp = saved_esp;  /* stdcall callee-clean; force-restore */
        } else {
        }
    }
    return n;
}

/* ── KeDelayExecutionThread (ordinal 99, 3 args = 12 bytes) ──
 * (WaitMode, Alertable, Interval). The CRI uses SleepEx(alertable) to receive
 * its I/O-completion APCs; return STATUS_USER_APC (0xC0) when any delivered. */
static void bridge_KeDelayExecutionThread(void)
{
    uint32_t alertable = STACK_ARG(1);
    if (alertable && bridge_apc_deliver()) {
        g_eax = 0x000000C0u; /* STATUS_USER_APC */
        return;
    }
    if (xbox_fiber_active()) {
        if (g_xbox_det_active && (xbox_fiber_is_primary() || xbox_fiber_is_coroutine())) xbox_fiber_run_workers_idle(1024);
        else xbox_fiber_yield();  /* let other fibers run during the sleep */
    }
    g_eax = 0; /* STATUS_SUCCESS (timeout elapsed) */
}

int g_kernel_trace_reads = 0;
extern void (*g_kernel_ptinfo_hook)(const char *where);
static void bridge_NtReadFile(void)
{
    xbox_det_note_io();   /* netplay barrier: waits for file activity to stop */
    HANDLE   handle     = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    /* arg1: Event handle - ignored for sync I/O */
    uint32_t apc_va     = STACK_ARG(2);  /* ApcRoutine (kernel NtUserIoApcDispatcher thunk) */
    uint32_t apc_ctx    = STACK_ARG(3);  /* ApcContext = XAPI user completion routine VA */
    uint32_t iostatus   = STACK_ARG(4);  /* PIO_STATUS_BLOCK (= the OVERLAPPED for ReadFileEx) */
    uint32_t buffer_va  = STACK_ARG(5);  /* PVOID Buffer */
    uint32_t length     = STACK_ARG(6);  /* ULONG Length */
    uint32_t offset_va  = STACK_ARG(7);  /* PLARGE_INTEGER ByteOffset */
    void*    buffer     = XBOX_TO_NATIVE(buffer_va);
    DWORD    bytes_read = 0;
    BOOL     result;
    OVERLAPPED ov;

    if (!iostatus || !buffer) {
        g_eax = 0xC000000Du; /* STATUS_INVALID_PARAMETER */
        return;
    }

    if (offset_va) {
        uint32_t lo = BRIDGE_MEM32(offset_va);
        uint32_t hi = BRIDGE_MEM32(offset_va + 4);
        if ((int32_t)hi >= 0) { /* positive offset = explicit seek */
            memset(&ov, 0, sizeof(ov));
            ov.Offset = lo;
            ov.OffsetHigh = hi;
            result = ReadFile(handle, buffer, length, &bytes_read, &ov);
        } else {
            result = ReadFile(handle, buffer, length, &bytes_read, NULL);
        }
    } else {
        result = ReadFile(handle, buffer, length, &bytes_read, NULL);
    }

    if (g_kernel_ptinfo_hook) g_kernel_ptinfo_hook("ntread");
    {
        /* DOA2U DIAG: the first 16 reads cover boot; g_kernel_trace_reads is
         * raised by the game once the intro movie is over so the post-movie
         * resource loads (few, and the ones that arrive empty) are visible. */
        static int s_read_log = 0;
        if (s_read_log < 16 || g_kernel_trace_reads) {
            s_read_log++;
        }
    }

    if (result || GetLastError() == ERROR_HANDLE_EOF) {
        bridge_write_iostatus(iostatus, STATUS_SUCCESS, bytes_read);
        if (bytes_read == 0 && length > 0) {
            bridge_write_iostatus(iostatus, 0xC0000011u, 0); /* STATUS_END_OF_FILE */
            g_eax = 0xC0000011u;
            return;
        }
        /* Async form (XAPI ReadFileEx): the kernel queues ApcRoutine
         * (NtUserIoApcDispatcher) which, on delivery during an ALERTABLE WAIT,
         * calls the user completion (ApcContext) as completion(dosError, bytes,
         * lpOverlapped) with lpOverlapped == IoStatusBlock. The CRI relies on
         * that ordering (it sets an in-flight flag, enters SleepEx-alertable,
         * and expects the APC to clear the flag DURING the wait), so queue the
         * APC here and deliver it in bridge_KeDelayExecutionThread. */
        if (apc_va && apc_ctx) {
            bridge_apc_queue(apc_ctx, iostatus, bytes_read);
            g_eax = 0x00000103u; /* STATUS_PENDING */
            return;
        }
        g_eax = STATUS_SUCCESS;
        return;
    }

    /* Mapping every ReadFile failure to STATUS_UNSUCCESSFUL loses the only
     * information that says why, and the CRI loader retries such a read
     * forever -- a boot that fails here just spins. Report the Win32 error
     * and the request once per distinct error, and translate the ones the
     * guest knows how to handle. */
    {
        DWORD err = GetLastError();
        static DWORD seen[8]; static int nseen = 0;
        int known = 0, i;
        for (i = 0; i < nseen; i++) if (seen[i] == err) { known = 1; break; }
        if (!known && nseen < 8) {
            seen[nseen++] = err;
        }
        if (err == ERROR_HANDLE_EOF) {
            bridge_write_iostatus(iostatus, 0xC0000011u, 0); /* END_OF_FILE */
            g_eax = 0xC0000011u;
            return;
        }
    }
    bridge_write_iostatus(iostatus, 0xC0000001u, 0); /* STATUS_UNSUCCESSFUL */
    g_eax = 0xC0000001u;
}

/* ── NtWriteFile (ordinal 236, 8 args = 32 bytes) ─────── */
static void bridge_NtWriteFile(void)
{
    HANDLE   handle     = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    uint32_t iostatus   = STACK_ARG(4);
    uint32_t buffer_va  = STACK_ARG(5);
    uint32_t length     = STACK_ARG(6);
    uint32_t offset_va  = STACK_ARG(7);
    void*    buffer     = XBOX_TO_NATIVE(buffer_va);
    DWORD    bytes_written = 0;
    BOOL     result;
    OVERLAPPED ov;

    if (!iostatus || !buffer) {
        g_eax = 0xC000000Du;
        return;
    }

    if (offset_va) {
        uint32_t lo = BRIDGE_MEM32(offset_va);
        uint32_t hi = BRIDGE_MEM32(offset_va + 4);
        if ((int32_t)hi >= 0) {
            memset(&ov, 0, sizeof(ov));
            ov.Offset = lo;
            ov.OffsetHigh = hi;
            result = WriteFile(handle, buffer, length, &bytes_written, &ov);
        } else {
            result = WriteFile(handle, buffer, length, &bytes_written, NULL);
        }
    } else {
        result = WriteFile(handle, buffer, length, &bytes_written, NULL);
    }

    if (result) {
        bridge_write_iostatus(iostatus, STATUS_SUCCESS, bytes_written);
        g_eax = STATUS_SUCCESS;
    } else {
        bridge_write_iostatus(iostatus, 0xC0000001u, 0);
        g_eax = 0xC0000001u;
    }
}

/* ── NtQueryInformationFile (ordinal 211, 5 args = 20 bytes) */
/* File times handed to the guest are ALL the host LastWriteTime.
 *
 * The game's CRI cache validator compares the
 * times of d:\<file> against its z:\ cache copy with a 60 s tolerance and
 * re-installs the cache on a mismatch. Reporting the host CreationTime and
 * LastAccessTime made that decision depend on the launch: NTFS last-access
 * updates are "system managed" and drift between runs, so one boot passed the
 * check and the next started a multi-hundred-MB background copy whose reads
 * then collided with the post-movie loads (black screen after the movie).
 * Only LastWriteTime is stable for identical copies, so it stands in for
 * every time field. */
static void bridge_NtQueryInformationFile(void)
{
    HANDLE   handle  = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    uint32_t ios_va  = STACK_ARG(1);
    uint32_t info_va = STACK_ARG(2);
    uint32_t length  = STACK_ARG(3);
    uint32_t infoclass = STACK_ARG(4);
    BY_HANDLE_FILE_INFORMATION fi;
    void* info = XBOX_TO_NATIVE(info_va);

    if (!ios_va || !info) { g_eax = 0xC000000Du; return; }

    switch (infoclass) {
    case 4: { /* FileBasicInformation (36 bytes) */
        if (!GetFileInformationByHandle(handle, &fi)) { g_eax = 0xC0000001u; return; }
        BRIDGE_MEM32(info_va +  0) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va +  4) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va +  8) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va + 12) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 16) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va + 20) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 24) = fi.ftLastWriteTime.dwLowDateTime; /* ChangeTime */
        BRIDGE_MEM32(info_va + 28) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 32) = fi.dwFileAttributes;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 36);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 5: { /* FileStandardInformation (24 bytes) */
        LONGLONG size;
        if (!GetFileInformationByHandle(handle, &fi)) { g_eax = 0xC0000001u; return; }
        size = ((LONGLONG)fi.nFileSizeHigh << 32) | fi.nFileSizeLow;
        BRIDGE_MEM32(info_va +  0) = (uint32_t)((size + 4095) & ~4095LL);       /* AllocationSize.Lo */
        BRIDGE_MEM32(info_va +  4) = (uint32_t)(((size + 4095) & ~4095LL) >> 32);
        BRIDGE_MEM32(info_va +  8) = fi.nFileSizeLow;                            /* EndOfFile.Lo */
        BRIDGE_MEM32(info_va + 12) = fi.nFileSizeHigh;                           /* EndOfFile.Hi */
        BRIDGE_MEM32(info_va + 16) = fi.nNumberOfLinks;                          /* NumberOfLinks */
        BRIDGE_MEM32(info_va + 20) = (fi.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? 0x00010000 : 0;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 24);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 6: { /* FileInternalInformation (8 bytes: IndexNumber) */
        /* CRI cache validator (sub_00162F85) records the file ID alongside the
         * times; host file indices are stable per-file which is what it needs. */
        if (!GetFileInformationByHandle(handle, &fi)) { g_eax = 0xC0000001u; return; }
        BRIDGE_MEM32(info_va + 0) = fi.nFileIndexLow;
        BRIDGE_MEM32(info_va + 4) = fi.nFileIndexHigh;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 8);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 14: { /* FilePositionInformation (8 bytes) */
        LARGE_INTEGER pos, zero;
        zero.QuadPart = 0;
        if (!SetFilePointerEx(handle, zero, &pos, FILE_CURRENT)) { g_eax = 0xC0000001u; return; }
        BRIDGE_MEM32(info_va + 0) = pos.LowPart;
        BRIDGE_MEM32(info_va + 4) = pos.HighPart;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 8);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 34: { /* FileNetworkOpenInformation (56 bytes) */
        LONGLONG size;
        if (!GetFileInformationByHandle(handle, &fi)) { g_eax = 0xC0000001u; return; }
        size = ((LONGLONG)fi.nFileSizeHigh << 32) | fi.nFileSizeLow;
        BRIDGE_MEM32(info_va +  0) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va +  4) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va +  8) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va + 12) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 16) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va + 20) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 24) = fi.ftLastWriteTime.dwLowDateTime;
        BRIDGE_MEM32(info_va + 28) = fi.ftLastWriteTime.dwHighDateTime;
        BRIDGE_MEM32(info_va + 32) = fi.nFileSizeLow;
        BRIDGE_MEM32(info_va + 36) = fi.nFileSizeHigh;
        BRIDGE_MEM32(info_va + 40) = (uint32_t)((size + 4095) & ~4095LL);
        BRIDGE_MEM32(info_va + 44) = (uint32_t)(((size + 4095) & ~4095LL) >> 32);
        BRIDGE_MEM32(info_va + 48) = fi.dwFileAttributes;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 56);
        g_eax = STATUS_SUCCESS;
        break;
    }
    default:
        g_eax = 0xC00000BBu; /* STATUS_NOT_SUPPORTED */
        break;
    }
}

/* ── NtSetInformationFile (ordinal 226, 5 args = 20 bytes) ─ */
static void bridge_NtSetInformationFile(void)
{
    HANDLE   handle    = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    uint32_t ios_va    = STACK_ARG(1);
    uint32_t info_va   = STACK_ARG(2);
    /* uint32_t length = STACK_ARG(3); */
    uint32_t infoclass = STACK_ARG(4);

    switch (infoclass) {
    case 14: { /* FilePositionInformation */
        LARGE_INTEGER pos;
        pos.LowPart  = BRIDGE_MEM32(info_va);
        pos.HighPart = BRIDGE_MEM32(info_va + 4);
        SetFilePointerEx(handle, pos, NULL, FILE_BEGIN);
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 0);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 20: { /* FileEndOfFileInformation */
        LARGE_INTEGER eof;
        eof.LowPart  = BRIDGE_MEM32(info_va);
        eof.HighPart = BRIDGE_MEM32(info_va + 4);
        SetFilePointerEx(handle, eof, NULL, FILE_BEGIN);
        SetEndOfFile(handle);
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 0);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 13: { /* FileDispositionInformation */
        FILE_DISPOSITION_INFO fdi;
        fdi.DeleteFile = BRIDGE_MEM32(info_va) ? TRUE : FALSE;
        SetFileInformationByHandle(handle, FileDispositionInfo, &fdi, sizeof(fdi));
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 0);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 4: { /* FileBasicInformation: CreationTime, LastAccessTime,
               * LastWriteTime, ChangeTime (8 bytes each, 0 = leave alone),
               * FileAttributes. The CRI wxCi cache installer stamps each
               * finished z:\ copy with the d:\ source's times; without this
               * the copies never validated on the next boot. */
        FILETIME ct, at, wt;
        FILETIME *pct = NULL, *pat = NULL, *pwt = NULL;
        BOOL ok;
        ct.dwLowDateTime = BRIDGE_MEM32(info_va +  0); ct.dwHighDateTime = BRIDGE_MEM32(info_va +  4);
        at.dwLowDateTime = BRIDGE_MEM32(info_va +  8); at.dwHighDateTime = BRIDGE_MEM32(info_va + 12);
        wt.dwLowDateTime = BRIDGE_MEM32(info_va + 16); wt.dwHighDateTime = BRIDGE_MEM32(info_va + 20);
        if (ct.dwLowDateTime | ct.dwHighDateTime) pct = &ct;
        if (at.dwLowDateTime | at.dwHighDateTime) pat = &at;
        if (wt.dwLowDateTime | wt.dwHighDateTime) pwt = &wt;
        ok = SetFileTime(handle, pct, pat, pwt);
        if (!ok) {
            /* The guest handle may lack FILE_WRITE_ATTRIBUTES on the host
             * side; retry through a fresh attributes-only handle by path. */
            const WCHAR *path = xbox_fh_path(STACK_ARG(0));
            if (path && path[0]) {
                HANDLE h2 = CreateFileW(path, FILE_WRITE_ATTRIBUTES,
                                        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                                        NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
                if (h2 != INVALID_HANDLE_VALUE) {
                    ok = SetFileTime(h2, pct, pat, pwt);
                    CloseHandle(h2);
                }
            }
        }
        bridge_write_iostatus(ios_va, ok ? STATUS_SUCCESS : 0xC0000022u, 0); /* ACCESS_DENIED */
        g_eax = ok ? STATUS_SUCCESS : 0xC0000022u;
        break;
    }
    default:
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 0);
        g_eax = STATUS_SUCCESS;
        break;
    }
}

/* ── NtQueryVolumeInformationFile (ordinal 218, 5 args = 20 bytes) */
static void bridge_NtQueryVolumeInformationFile(void)
{
    /* handle (STACK_ARG(0)) unused: class-1 volume info is synthesized below */
    uint32_t ios_va    = STACK_ARG(1);
    uint32_t info_va   = STACK_ARG(2);
    /* uint32_t length = STACK_ARG(3); */
    uint32_t infoclass = STACK_ARG(4);

    switch (infoclass) {
    case 3: { /* FileFsSizeInformation (24 bytes) */
        /* Report plenty of free space. (The earlier "drive full" hack — meant
         * to skip the then-broken cache copy — backfired: the boot showed the
         * "not enough free space" prompt (sub_00021F70's first hold checks
         * free blocks >= 0x10000) and waited for input. The copy machinery
         * has since been unblocked by the stack-leak/FPU/share/dir fixes.) */
        BRIDGE_MEM32(info_va +  0) = 1048576;  /* TotalAllocationUnits.Lo */
        BRIDGE_MEM32(info_va +  4) = 0;
        BRIDGE_MEM32(info_va +  8) = 524288;   /* AvailableAllocationUnits */
        BRIDGE_MEM32(info_va + 12) = 0;
        BRIDGE_MEM32(info_va + 16) = 8;        /* SectorsPerAllocationUnit */
        BRIDGE_MEM32(info_va + 20) = 512;      /* BytesPerSector */
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 24);
        g_eax = STATUS_SUCCESS;
        break;
    }
    case 1: { /* FileFsVolumeInformation (0x18 + label) */
        /* The CRI cache validator (sub_00162F85 -> sub_0009D9B8) queries the
         * VOLUME creation time + serial of both d: and z: handles and treats a
         * mismatch vs its recorded values as "cache stale" (a reformatted Xbox
         * cache partition gets a new volume time/serial). Synthesize CONSTANT
         * values so the comparison is stable across boots and across volumes. */
        BRIDGE_MEM32(info_va +  0) = 0x00000000u;  /* VolumeCreationTime.Lo */
        BRIDGE_MEM32(info_va +  4) = 0x01C00000u;  /* VolumeCreationTime.Hi (fixed) */
        BRIDGE_MEM32(info_va +  8) = 0xD0A3D0A3u;  /* VolumeSerialNumber (fixed) */
        BRIDGE_MEM32(info_va + 12) = 0;            /* VolumeLabelLength */
        BRIDGE_MEM32(info_va + 16) = 0;            /* SupportsObjects + pad */
        BRIDGE_MEM32(info_va + 20) = 0;
        bridge_write_iostatus(ios_va, STATUS_SUCCESS, 24);
        g_eax = STATUS_SUCCESS;
        break;
    }
    default:
        g_eax = 0xC00000BBu;
        break;
    }
}

/* ── NtQueryFullAttributesFile (ordinal 210, 2 args = 8 bytes) */
static void bridge_NtQueryFullAttributesFile(void)
{
    uint32_t obj_attrs = STACK_ARG(0);
    uint32_t info_va   = STACK_ARG(1);
    WCHAR win_path[MAX_PATH];
    WIN32_FILE_ATTRIBUTE_DATA fad;
    LONGLONG size;
    const char* xbox_path;

    xbox_path = bridge_get_xbox_path(obj_attrs);
    if (!xbox_path || !xbox_translate_path(xbox_path, win_path, MAX_PATH)) {
        g_eax = STATUS_OBJECT_PATH_NOT_FOUND;
        return;
    }

    bridge_cache_archive_fallback(xbox_path, win_path, 0, "stat");
    if (!GetFileAttributesExW(win_path, GetFileExInfoStandard, &fad)) {
        DWORD err = GetLastError();
        g_eax = (err == ERROR_FILE_NOT_FOUND || err == ERROR_PATH_NOT_FOUND)
                ? STATUS_OBJECT_NAME_NOT_FOUND : 0xC0000001u;
        return;
    }

    size = ((LONGLONG)fad.nFileSizeHigh << 32) | fad.nFileSizeLow;
    BRIDGE_MEM32(info_va +  0) = fad.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va +  4) = fad.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va +  8) = fad.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 12) = fad.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 16) = fad.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 20) = fad.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 24) = fad.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 28) = fad.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 32) = fad.nFileSizeLow;
    BRIDGE_MEM32(info_va + 36) = fad.nFileSizeHigh;
    BRIDGE_MEM32(info_va + 40) = (uint32_t)((size + 4095) & ~4095LL);
    BRIDGE_MEM32(info_va + 44) = (uint32_t)(((size + 4095) & ~4095LL) >> 32);
    BRIDGE_MEM32(info_va + 48) = fad.dwFileAttributes;
    g_eax = STATUS_SUCCESS;
}

/* ── NtFlushBuffersFile (ordinal 198, 2 args = 8 bytes) ─── */
static void bridge_NtFlushBuffersFile(void)
{
    HANDLE handle = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    uint32_t ios_va = STACK_ARG(1);
    FlushFileBuffers(handle);
    bridge_write_iostatus(ios_va, STATUS_SUCCESS, 0);
    g_eax = STATUS_SUCCESS;
}

/* ── NtDeleteFile (ordinal 195, 1 arg = 4 bytes) ─────── */
static void bridge_NtDeleteFile(void)
{
    uint32_t obj_attrs = STACK_ARG(0);
    WCHAR win_path[MAX_PATH];
    const char* xbox_path = bridge_get_xbox_path(obj_attrs);

    if (!xbox_path || !xbox_translate_path(xbox_path, win_path, MAX_PATH)) {
        g_eax = STATUS_OBJECT_PATH_NOT_FOUND;
        return;
    }

    if (DeleteFileW(win_path) || RemoveDirectoryW(win_path))
        g_eax = STATUS_SUCCESS;
    else
        g_eax = STATUS_OBJECT_NAME_NOT_FOUND;
}

/* ── NtQueryDirectoryFile (ordinal 207, 10 args = 40 bytes) ─
 * Xbox signature (per cxbx): (FileHandle, Event, ApcRoutine, ApcContext,
 * IoStatusBlock, FileInformation, Length, FileInformationClass, FileMask,
 * RestartScan). FileMask is a counted STRING; FileMask==NULL means "continue
 * the previous enumeration on this handle", so per-handle find state is kept. */
#define QDIR_MAX_ENUM 8
static struct { HANDLE dir; HANDLE find; } s_qdir_enum[QDIR_MAX_ENUM];

/* FATX has no "." or ".." entries, so the Xbox kernel never reports them.
 * Win32 FindFirstFile/FindNextFile do, and handing them to the guest broke
 * the game's wxCi cache scanner: it registered "." as the one and only file in
 * z:\ (the registry at 0xC057C0 showed n=1, f0='.'), so every later
 * wxCiOpen/wxCiGetFileSize of z:\loadfile.afs reported "not in cache" even
 * though the file opens fine by name. That failed the post-movie load in a
 * retry loop and the title screen never built. */
static int qdir_is_dot_entry(const WCHAR *n)
{
    return n[0] == L'.' && (n[1] == 0 || (n[1] == L'.' && n[2] == 0));
}

static void bridge_NtQueryDirectoryFile(void)
{
    HANDLE   handle      = xbox_fh_resolve(STACK_ARG(0)); /* opaque guest handle */
    /* arg1: Event, arg2: ApcRoutine, arg3: ApcContext - ignored */
    uint32_t ios_va      = STACK_ARG(4);
    uint32_t info_va     = STACK_ARG(5);
    uint32_t length      = STACK_ARG(6);
    /* arg7: FileInformationClass - always FileDirectoryInformation(1) on Xbox */
    uint32_t filename_va = STACK_ARG(8);  /* FileMask: counted STRING or NULL */
    uint32_t restart     = STACK_ARG(9);  /* BOOLEAN RestartScan */

    WCHAR dir_path[MAX_PATH];
    WCHAR search_path[MAX_PATH];
    DWORD path_len;
    WCHAR* clean_path;
    WIN32_FIND_DATAW fd;
    char filename_ansi[MAX_PATH];
    int name_len;
    int slot = -1, i;
    int have_entry = 0;

    if (!info_va || length < 64) {
        bridge_write_iostatus(ios_va, 0xC0000001u, 0);
        g_eax = 0xC0000001u;
        return;
    }

    /* Find existing enumeration state for this handle. */
    for (i = 0; i < QDIR_MAX_ENUM; i++)
        if (s_qdir_enum[i].dir == handle && s_qdir_enum[i].find) { slot = i; break; }


    {   static int s_call_log = 0;
        if (s_call_log < 24) { s_call_log++;
             } }

    if (filename_va || restart || slot < 0) {
        /* (Re)start the enumeration. */
        if (slot >= 0) { FindClose(s_qdir_enum[slot].find); s_qdir_enum[slot].find = NULL; }

        path_len = GetFinalPathNameByHandleW(handle, dir_path, MAX_PATH, FILE_NAME_NORMALIZED);
        if (path_len == 0 || path_len >= MAX_PATH) {
            bridge_write_iostatus(ios_va, 0xC0000001u, 0);
            g_eax = 0xC0000001u;
            return;
        }
        clean_path = dir_path;
        if (wcsncmp(clean_path, L"\\\\?\\", 4) == 0)
            clean_path += 4;

        {
            WCHAR pattern[MAX_PATH]; int have_pat = 0;
            if (filename_va) {
                uint16_t fn_len = BRIDGE_MEM16(filename_va);
                uint32_t fn_buf = BRIDGE_MEM32(filename_va + 4);
                if (fn_buf && fn_len > 0 && fn_len < MAX_PATH) {
                    const char* fn_str = (const char*)XBOX_TO_NATIVE(fn_buf);
                    int wl = MultiByteToWideChar(CP_ACP, 0, fn_str, fn_len, pattern, MAX_PATH - 1);
                    pattern[wl > 0 ? wl : 0] = L'\0';
                    have_pat = (wl > 0);
                }
            }
            swprintf_s(search_path, MAX_PATH, L"%s\\%s", clean_path,
                       have_pat ? pattern : L"*");
        }

        {
            HANDLE fh = FindFirstFileW(search_path, &fd);
            static int s_qdir_log = 0;
            if (s_qdir_log < 24) {
                s_qdir_log++;
                {   /* Name the guest scanner: it takes one entry per directory
                     * and stops, which is why the wxCi cache registry holds
                     * only '\bgm.afs'. */
                    void *bt[10]; USHORT nb = CaptureStackBackTrace(1, 10, bt, NULL); int bi;
                }
            }
            if (fh == INVALID_HANDLE_VALUE) {
                bridge_write_iostatus(ios_va, 0xC000000Fu, 0); /* STATUS_NO_SUCH_FILE */
                g_eax = 0xC000000Fu;
                return;
            }
            while (qdir_is_dot_entry(fd.cFileName)) {
                if (!FindNextFileW(fh, &fd)) {
                    FindClose(fh);
                    bridge_write_iostatus(ios_va, 0x80000006u, 0); /* NO_MORE_FILES */
                    g_eax = 0x80000006u;
                    return;
                }
            }
            /* store enumeration state */
            if (slot < 0)
                for (i = 0; i < QDIR_MAX_ENUM; i++)
                    if (!s_qdir_enum[i].find) { slot = i; break; }
            if (slot >= 0) { s_qdir_enum[slot].dir = handle; s_qdir_enum[slot].find = fh; }
            have_entry = 1;
        }
    } else {
        /* Continue the existing enumeration. */
        {   /* Keep the result of the LAST FindNextFileW: on failure fd still
             * holds the previous entry, and returning that again made the
             * enumeration never terminate. */
            BOOL more;
            do {
                more = FindNextFileW(s_qdir_enum[slot].find, &fd);
            } while (more && qdir_is_dot_entry(fd.cFileName));
            have_entry = more ? 1 : 0;
            {   static int s_cont_log = 0;
                if (s_cont_log < 24) { s_cont_log++;
                     } }
        }
        if (have_entry) {
            /* fall through with the entry */
        } else {
            FindClose(s_qdir_enum[slot].find);
            s_qdir_enum[slot].find = NULL;
            s_qdir_enum[slot].dir = NULL;
            bridge_write_iostatus(ios_va, 0x80000006u, 0); /* STATUS_NO_MORE_FILES */
            g_eax = 0x80000006u;
            return;
        }
    }

    if (!have_entry) {
        bridge_write_iostatus(ios_va, 0x80000006u, 0);
        g_eax = 0x80000006u;
        return;
    }

    /* Fill Xbox FILE_DIRECTORY_INFORMATION:
     * 0 NextEntryOffset, 4 FileIndex, 8 CreationTime, 16 LastAccessTime,
     * 24 LastWriteTime, 32 ChangeTime, 40 EndOfFile, 48 AllocationSize,
     * 56 FileAttributes, 60 FileNameLength, 64 FileName[] */
    memset(XBOX_TO_NATIVE(info_va), 0, length);
    name_len = WideCharToMultiByte(CP_ACP, 0, fd.cFileName, -1,
                                    filename_ansi, MAX_PATH, NULL, NULL);
    if (name_len > 0) name_len--;

    BRIDGE_MEM32(info_va +  0) = 0; /* NextEntryOffset */
    BRIDGE_MEM32(info_va +  4) = 0; /* FileIndex */
    BRIDGE_MEM32(info_va +  8) = fd.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 12) = fd.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 16) = fd.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 20) = fd.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 24) = fd.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 28) = fd.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 32) = fd.ftLastWriteTime.dwLowDateTime;
    BRIDGE_MEM32(info_va + 36) = fd.ftLastWriteTime.dwHighDateTime;
    BRIDGE_MEM32(info_va + 40) = fd.nFileSizeLow;
    BRIDGE_MEM32(info_va + 44) = fd.nFileSizeHigh;
    { LONGLONG sz = ((LONGLONG)fd.nFileSizeHigh << 32) | fd.nFileSizeLow;
      BRIDGE_MEM32(info_va + 48) = (uint32_t)((sz + 4095) & ~4095LL);
      BRIDGE_MEM32(info_va + 52) = (uint32_t)(((sz + 4095) & ~4095LL) >> 32); }
    BRIDGE_MEM32(info_va + 56) = fd.dwFileAttributes;
    BRIDGE_MEM32(info_va + 60) = name_len;
    if (name_len > 0 && (uint32_t)(64 + name_len) <= length)
        memcpy(XBOX_TO_NATIVE(info_va + 64), filename_ansi, name_len);

    bridge_write_iostatus(ios_va, STATUS_SUCCESS, 64 + name_len);
    g_eax = STATUS_SUCCESS;
}

/* ── NtOpenSymbolicLinkObject (ordinal 203, 2 args = 8 bytes) */
static void bridge_NtOpenSymbolicLinkObject(void)
{
    uint32_t handle_va = STACK_ARG(0);
    /* arg1: POBJECT_ATTRIBUTES - ignored, we return a dummy */
    bridge_write_handle(handle_va, (HANDLE)(uintptr_t)0xDEAD0001u);
    g_eax = STATUS_SUCCESS;
}

/* ── NtQuerySymbolicLinkObject (ordinal 215, 3 args = 12 bytes) */
static void bridge_NtQuerySymbolicLinkObject(void)
{
    /* uint32_t handle = STACK_ARG(0); */
    uint32_t target_va = STACK_ARG(1);
    uint32_t retlen_va = STACK_ARG(2);
    const char* target = "\\Device\\CdRom0";
    USHORT len = (USHORT)strlen(target);

    if (target_va) {
        uint16_t max_len = BRIDGE_MEM16(target_va + 2);
        uint32_t buf_va  = BRIDGE_MEM32(target_va + 4);
        if (buf_va && len < max_len) {
            memcpy(XBOX_TO_NATIVE(buf_va), target, len + 1);
            BRIDGE_MEM16(target_va) = len;
        }
    }
    if (retlen_va) BRIDGE_MEM32(retlen_va) = (uint32_t)len;
    g_eax = STATUS_SUCCESS;
}

/* ── IoCreateFile (ordinal 67, 10 args = 40 bytes) ────── */
static void bridge_IoCreateFile(void)
{
    /* Same as NtCreateFile with an extra Options arg at the end */
    uint32_t handle_va   = STACK_ARG(0);
    uint32_t access      = STACK_ARG(1);
    uint32_t obj_attrs   = STACK_ARG(2);
    uint32_t iostatus    = STACK_ARG(3);
    uint32_t file_attrs  = STACK_ARG(5);
    uint32_t share       = STACK_ARG(6);
    uint32_t disposition = STACK_ARG(7);
    uint32_t options     = STACK_ARG(8);

    g_eax = (uint32_t)bridge_create_file_impl(
        handle_va, access, obj_attrs, iostatus,
        file_attrs, share, disposition, options);
}

/* ── NtDeviceIoControlFile (ordinal 196, 10 args = 40 bytes) */
static void bridge_NtDeviceIoControlFile(void)
{
    uint32_t ioctl = STACK_ARG(5);
    uint32_t ios_va = STACK_ARG(4);
    bridge_write_iostatus(ios_va, 0xC00000BBu, 0);
    g_eax = 0xC00000BBu; /* STATUS_NOT_IMPLEMENTED */
}

/* ── NtFsControlFile (ordinal 200, 10 args = 40 bytes) ──── */
static void bridge_NtFsControlFile(void)
{
    uint32_t fsctl = STACK_ARG(5);
    uint32_t ios_va = STACK_ARG(4);
    bridge_write_iostatus(ios_va, 0xC00000BBu, 0);
    g_eax = 0xC00000BBu;
}

/* ── NtCreateDirectoryObject (ordinal 188) ──────────────── */
static void bridge_NtCreateDirectoryObject(void)
{
    /* Return STATUS_SUCCESS with a fake handle */
    uint32_t handle_ptr = STACK_ARG(0);
    if (handle_ptr) BRIDGE_MEM32(handle_ptr) = 0xBEEF0010;
    g_eax = 0;  /* STATUS_SUCCESS */
}

/* ── IoCreateSymbolicLink (ordinal 63) ───────────────────── */
static void bridge_IoCreateSymbolicLink(void)
{
    g_eax = 0;  /* STATUS_SUCCESS */
}

/* ── ObReferenceObjectByHandle (ordinal 246) ─────────────── */
static void bridge_ObReferenceObjectByHandle(void)
{
    /* Xbox: NTSTATUS ObReferenceObjectByHandle(HANDLE Handle, PVOID ObjectType, PVOID* Object)
     * 3 args (not 6 like Windows NT).
     * *Object = 0 is LOAD-BEARING: callers pass the object to KeWaitForSingle
     * Object / Ke*Thread — with 0 those become no-ops, which is what the CRI
     * boot handshake needs (returning the handle as the object made thread
     * waits real and deadlocked the partition loads — bisected 2026-07). */
    uint32_t handle = STACK_ARG(0), type = STACK_ARG(1), object_ptr = STACK_ARG(2);
    if (object_ptr) BRIDGE_MEM32(object_ptr) = 0;
    /* Thread lookup after the cache copy worker exited: return a signaled KTHREAD with its
     * exit status at +0x120 (XAPI GetExitCodeThread); otherwise the object stays 0. */
    if (object_ptr && (handle & 0xFFFF0000u) == 0xBEEF0000u &&
        type == XBOX_KERNEL_DATA_BASE + KDATA_THREAD_OBJ_TYPE &&
        g_xbox_cache_install_routine && g_xbox_cache_install_exited) {
        static uint32_t s_kthread;
        if (!s_kthread) s_kthread = xbox_HeapAlloc(0x200, 16);
        if (s_kthread) {
            BRIDGE_MEM8(s_kthread) = 6;                       /* Header.Type: thread */
            BRIDGE_MEM32(s_kthread + 4) = 1;                  /* Header.SignalState */
            BRIDGE_MEM32(s_kthread + 0x120) = g_xbox_cache_install_exit;
            BRIDGE_MEM32(object_ptr) = s_kthread;
        }
    }
    g_eax = 0;  /* STATUS_SUCCESS */
    /* A game-task coroutine polling a thread in a tight
     * ObReferenceObjectByHandle + wait loop (e.g. the mwPly frame-sync in
     * the movie blit) must yield or the polled worker never runs and the
     * main thread spins forever (same class as the NtResumeThread fix). */
    if (xbox_fiber_is_coroutine())
        xbox_fiber_yield();
}

/* ── ObfDereferenceObject (ordinal 250, fastcall: object in ecx) ──
 * Refcount bookkeeping only; objects here are fake handles. No-op. */
static void bridge_ObfDereferenceObject(void)
{
    g_eax = 0;
}

/* ── RtlRaiseException (ordinal 302) ─────────────────────
 * VOID RtlRaiseException(PEXCEPTION_RECORD ExceptionRecord)
 *
 * Called by CRT / SEH code to raise structured exceptions.
 * On Xbox this triggers the kernel exception dispatcher.
 * For recompilation, we log and continue (no real SEH dispatch yet).
 */
static void bridge_RtlRaiseException(void)
{
    uint32_t record_ptr = STACK_ARG(0);
    uint32_t code = record_ptr ? BRIDGE_MEM32(record_ptr) : 0;

    static int raise_count = 0;
    raise_count++;
    if (raise_count <= 10) {
    }

    /* Handle float exceptions by clearing the FPU status.
     *
     * On the real Xbox, RtlRaiseException dispatches through the SEH chain.
     * For float exceptions (0xC0000090-0xC0000096), the CRT exception handler
     * clears the x87/SSE status word and continues execution. Without clearing,
     * the caller re-checks the FPU status, sees the exception still pending,
     * and re-raises in an infinite loop.
     *
     * _clearfp() clears both x87 and SSE exception flags on Windows x64.
     */
    if (code >= 0xC0000090u && code <= 0xC0000096u) {
        _clearfp();
    }

    g_eax = 0;
}

/* ── MmMapIoSpace (ordinal 177) ──────────────────────────
 * PVOID MmMapIoSpace(ULONG_PTR PhysicalAddress, ULONG NumberOfBytes, ULONG Protect)
 *
 * Maps physical I/O memory (GPU registers, etc.) into virtual address space.
 * Allocate from Xbox heap so the returned pointer is a valid Xbox VA.
 */
static void bridge_MmMapIoSpace(void)
{
    uint32_t phys_addr = STACK_ARG(0);
    uint32_t num_bytes = STACK_ARG(1);
    uint32_t protect = STACK_ARG(2);
    uint32_t xbox_va = xbox_HeapAlloc(num_bytes, 4096);


    g_eax = xbox_va;
}

/* ── MmPersistContiguousMemory (ordinal 178) ─────────────
 * VOID MmPersistContiguousMemory(PVOID BaseAddress, ULONG NumberOfBytes, BOOLEAN Persist)
 *
 * Marks contiguous memory as persistent across reboots (for save data).
 * No-op for recompilation.
 */
static void bridge_MmPersistContiguousMemory(void)
{
    /* No-op stub */
    g_eax = 0;
}

/* ── Generic fallback for simple value-only functions ────── */
static void bridge_generic_stub(void)
{
    /* For functions we haven't specifically bridged yet, log and return 0 */
    g_eax = 0;
}

/* ── Dispatch table: ordinal → bridge function + stack arg bytes ── */

typedef void (*bridge_func_t)(void);

/**
 * stdcall arg byte count for each kernel ordinal.
 * On x86 stdcall, the callee cleans (ret N). Our bridges must do the same
 * via g_esp += N after execution so the simulated stack stays balanced.
 *
 * Special cases:
 *   - KfRaiseIrql/KfLowerIrql: fastcall (arg in ecx), 0 stack bytes
 *   - KeSetTimer: DueTime is LARGE_INTEGER (8 bytes on stack) + Timer + Dpc
 */


/* ── DbgPrint (ordinal 14) ───────────────────────────────
 * ULONG DbgPrint(PCHAR Format, ...)  — cdecl varargs.
 * Captures the game's own debug output (a valuable boot oracle). Does a
 * minimal printf over the simulated Xbox stack args. */
static void bridge_DbgPrint(void)
{
    uint32_t fmt_va = STACK_ARG(0);
    if (!fmt_va) { g_eax = 0; return; }
    const char *fmt = (const char *)XBOX_TO_NATIVE(fmt_va);
    char out[1024];
    int o = 0, argi = 1;
    for (const char *p = fmt; *p && o < 1000; p++) {
        if (*p != '%') { out[o++] = *p; continue; }
        char spec[24]; int s = 0; spec[s++] = '%';
        p++;
        while (*p && s < 20 &&
               !(*p=='d'||*p=='i'||*p=='u'||*p=='o'||*p=='x'||*p=='X'||
                 *p=='c'||*p=='s'||*p=='p'||*p=='f'||*p=='e'||*p=='g'||
                 *p=='E'||*p=='G'||*p=='%'))
            spec[s++] = *p++;
        if (!*p) break;
        char c = *p; spec[s++] = c; spec[s] = 0;
        if (c == '%') { out[o++] = '%'; continue; }
        uint32_t a = STACK_ARG(argi++);
        int n = (int)(sizeof(out) - o);
        if (c == 's') {
            const char *str = a ? (const char *)XBOX_TO_NATIVE(a) : "(null)";
            o += snprintf(out + o, n, "%s", str);
        } else if (c == 'c') {
            o += snprintf(out + o, n, "%c", (char)a);
        } else if (c=='f'||c=='e'||c=='g'||c=='E'||c=='G') {
            uint32_t hi = STACK_ARG(argi++);
            uint64_t bits = ((uint64_t)hi << 32) | a; double d;
            memcpy(&d, &bits, 8);
            o += snprintf(out + o, n, "%g", d);
        } else if (c == 'p') {
            o += snprintf(out + o, n, "0x%08X", a);
        } else {
            o += snprintf(out + o, n, spec, a);  /* d/i/u/o/x/X (32-bit) */
        }
        if (o > 1000) o = 1000;
    }
    out[o] = 0;
    g_eax = 0;
}

/* ── KeConnectInterrupt (ordinal 98) ────────────────
 * BOOLEAN KeConnectInterrupt(PKINTERRUPT InterruptObject)
 * NOTE: older XDK titles import KeConnectInterrupt at ordinal 98 (our kernel's
 * later-XDK table calls 98 "KeBugCheckEx" — wrong for this title). Confirmed by
 * the cxbx trace: ord-98 call takes one InterruptObject and returns 0x01.
 * We have no real interrupts (single-threaded, no GPU IRQ), so just report
 * success so the D3D miniport's GPU-interrupt connect doesn't fail-and-panic. */
static void bridge_KeConnectInterrupt_98(void)
{
    g_eax = 1; /* TRUE */
}

/* ── HalGetInterruptVector (ordinal 44) ─────────────
 * ULONG HalGetInterruptVector(ULONG BusInterruptLevel, OUT PKIRQL Irql, ...)
 * cxbx returns 33. Return a non-zero vector and write an IRQL out. */
static void bridge_HalGetInterruptVector_44(void)
{
    uint32_t irql_ptr = STACK_ARG(1);
    if (irql_ptr) BRIDGE_MEM32(irql_ptr) = 0x0B; /* a plausible DIRQL */
    g_eax = 33;
}

/* HalRegisterShutdownNotification (ordinal 47): nothing to do on the host. */
static void bridge_HalRegisterShutdownNotification(void)
{
    g_eax = 0;
}

#include "kernel_bridge_more.inc"


/* ── Per-slot bridge functions (resolved at init) ────────── */

/* Game thread's most recent kernel call (see xbox_kernel_dump_primary). */
static ULONG g_primary_last_ordinal;
static unsigned long long g_primary_last_count;
static uint32_t g_primary_last_esp;
static void *g_primary_last_bt[12];
static USHORT g_primary_last_frames;

void xbox_kernel_dump_primary(void)
{
    uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
    USHORT i;
    fprintf(stderr, "[KTRACE] game thread last kernel call #%llu ord %lu guest esp %08X (total %llu), rvas:",
            g_primary_last_count, (unsigned long)g_primary_last_ordinal, g_primary_last_esp,
            (unsigned long long)g_kernel_call_count);
    for (i = 0; i < g_primary_last_frames; i++)
        fprintf(stderr, " %llX", (unsigned long long)((uintptr_t)g_primary_last_bt[i] - base));
    fputc(10, stderr);
}

static bridge_func_t g_slot_bridges[XBOX_KERNEL_THUNK_TABLE_SIZE];
static int g_slot_arg_bytes[XBOX_KERNEL_THUNK_TABLE_SIZE];

/* Current dispatching slot */
static int g_kernel_dispatch_slot = -1;

static void kernel_thunk_dispatch(void)
{
    int slot = g_kernel_dispatch_slot;
    bridge_func_t bridge;
    ULONG ordinal;

    if (slot < 0 || slot >= XBOX_KERNEL_THUNK_TABLE_SIZE) {
        g_eax = 0;
        g_esp += 4;  /* pop dummy return address */
        return;
    }

    ordinal = g_slot_ordinals[slot];
    bridge = g_slot_bridges[slot];

    g_kernel_call_count++;
    xbox_det_on_kernel_call(ordinal);
    if (xbox_fiber_is_primary()) {   /* last kernel call of the game thread, for stall reports */
        g_primary_last_ordinal = ordinal;
        g_primary_last_count = g_kernel_call_count;
        g_primary_last_esp = g_esp;
        g_primary_last_frames = CaptureStackBackTrace(1, 12, g_primary_last_bt, NULL);
    }
    {   /* worker-thread scheduling point (see xbox_fiber_timeslice). Only
         * once the movie is over (its verified timing is left alone), and
         * never from inside the CRI server pump or with the CRI lock held. */
        if (g_fib_slice_due) xbox_fiber_timeslice();
    }

    {
        static DWORD last_summary_tick = 0;
        DWORD now = GetTickCount();
        if (last_summary_tick == 0) last_summary_tick = now;
        if (now - last_summary_tick >= 2000 && g_kernel_call_count > 200) {
            last_summary_tick = now;
        }
    }

    /* Pop the dummy return address that PUSH32(esp, 0) pushed before RECOMP_ICALL.
     * On real x86, "call [thunk]" pushes a real return address and "ret" pops it.
     * In our model, the bridge is called directly (not via the simulated stack),
     * so we must manually consume the dummy return address. */
    g_esp += 4;

    if (bridge) {
        bridge();
    } else {
        /* No specific bridge - log warning and return 0 */
        if (g_kernel_call_count <= 200) {
        }
        g_eax = 0;
    }

    /* Clean stdcall args from the simulated stack.
     * On real x86, stdcall callee does "ret N" to pop the return address
     * and N bytes of arguments. We already popped the dummy return address
     * above; now pop the args. */
    g_esp += g_slot_arg_bytes[slot];

    if (g_kernel_call_count <= 200) {
    }
}

/* ── Dispatch lookup ────────────────────────────────────── */

/**
 * Look up a kernel thunk by synthetic VA.
 * Called as a fallback when recomp_lookup() returns NULL.
 */
recomp_func_t recomp_lookup_kernel(uint32_t xbox_va)
{
    if (xbox_va >= KERNEL_VA_BASE && xbox_va < KERNEL_VA_END) {
        int slot = (xbox_va - KERNEL_VA_BASE) / 4;
        if (slot >= 0 && slot < XBOX_KERNEL_THUNK_TABLE_SIZE) {
            g_kernel_dispatch_slot = slot;
            return kernel_thunk_dispatch;
        }
    }
    return NULL;
}

/* ── Initialization ─────────────────────────────────────── */

/**
 * Resolve the kernel thunk table in Xbox memory.
 *
 * Must be called AFTER xbox_MemoryLayoutInit() so Xbox memory is mapped.
 *
 * Reads the actual ordinals from the XBE memory thunk table (0x80000000|ordinal),
 * resolves each to a per-ordinal bridge function, and replaces the entry
 * with a synthetic VA for dispatch.
 */
void xbox_kernel_bridge_init(void)
{
    int i;
    int resolved = 0;
    int bridged = 0;
    int unbridged = 0;
    DWORD old_protect;


    /* The thunk table lives in .rdata which is marked PAGE_READONLY.
     * Temporarily make it writable so we can patch the ordinals. */
    VirtualProtect(
        (LPVOID)((uintptr_t)XBOX_KERNEL_THUNK_TABLE_BASE + g_xbox_mem_offset),
        XBOX_KERNEL_THUNK_TABLE_SIZE * 4,
        PAGE_READWRITE,
        &old_protect
    );

    /* Initialize kernel data export values first */
    kernel_data_init();

    for (i = 0; i < XBOX_KERNEL_THUNK_TABLE_SIZE; i++) {
        uint32_t va = XBOX_KERNEL_THUNK_TABLE_BASE + i * 4;
        uint32_t current = BRIDGE_MEM32(va);

        if (current & 0x80000000) {
            /* Read the actual ordinal from Xbox memory */
            ULONG ordinal = current & 0x7FFFFFFF;
            g_slot_ordinals[i] = ordinal;

            /* Check if this is a data export */
            uint32_t data_va = kernel_data_va_for_ordinal(ordinal);
            if (data_va) {
                /* DATA export: point thunk to actual data in mapped memory.
                 * This allows the game to dereference the thunk entry. */
                BRIDGE_MEM32(va) = data_va;
                resolved++;
                bridged++;
                continue;
            }

            /* FUNCTION export: use synthetic VA for dispatch */
            g_slot_bridges[i] = bridge_for_ordinal(ordinal);
            g_slot_arg_bytes[i] = stdcall_args_for_ordinal(ordinal);
            if (g_slot_bridges[i]) {
                bridged++;
            } else {
                unbridged++;
            }

            /* Replace Xbox memory entry with synthetic VA */
            uint32_t synthetic = KERNEL_VA_BASE + i * 4;
            BRIDGE_MEM32(va) = synthetic;
            resolved++;
        }
    }

    /* Restore original protection */
    VirtualProtect(
        (LPVOID)((uintptr_t)XBOX_KERNEL_THUNK_TABLE_BASE + g_xbox_mem_offset),
        XBOX_KERNEL_THUNK_TABLE_SIZE * 4,
        old_protect,
        &old_protect
    );


}
