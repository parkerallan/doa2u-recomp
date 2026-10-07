/**
 * Xbox Memory Layout Implementation
 *
 * Maps the XBE data sections to their expected virtual addresses on Windows.
 * This is critical for the recompiled code which references globals by
 * absolute address (e.g., mov eax, [0x004D532C]).
 *
 * Implementation:
 * 1. VirtualAlloc a contiguous region at XBOX_BASE_ADDRESS
 * 2. Copy .rdata and initialized .data from the XBE
 * 3. Zero-fill the BSS region
 * 4. Set memory protection (read-only for .rdata)
 */

#include "xbox_memory_layout.h"
#include <stdio.h>
#include <string.h>

/* Sections are copied from the XBE's own section table at load time (see
 * xbox_MemoryLayoutInit), so nothing here is specific to one title. */

static void *g_memory_base = NULL;
static size_t g_memory_size = 0;
static ptrdiff_t g_memory_offset = 0;  /* actual_base - XBOX_BASE_ADDRESS */

/* File mapping handle for the Xbox memory region.
 * Using CreateFileMapping + MapViewOfFileEx allows mirror views to alias
 * the same physical pages as the base region, so writes to mirror addresses
 * (which wrap modulo 64 MB on real Xbox hardware) correctly modify the
 * underlying data. */
static HANDLE g_mapping_handle = NULL;

/* Mirror view pointers for cleanup */
static void *g_mirror_views[XBOX_NUM_MIRRORS] = {0};

/* Separate allocation for Xbox kernel address space (0x80010000+).
 * Some RenderWare code reads the kernel PE header to detect features. */
static void *g_kernel_memory = NULL;

/* Global offset accessible by recompiled code (via recomp_types.h) */
ptrdiff_t g_xbox_mem_offset = 0;

/* Global registers for recompiled code (via recomp_types.h) */
uint32_t g_eax = 0, g_ecx = 0, g_edx = 0, g_esp = 0;
uint32_t g_ebx = 0, g_esi = 0, g_edi = 0;

/* Last operand pair compared by a REP cmps/scas string op — the following jcc/setcc
 * reads these (the recompiler implements rep cmpsb/cmpsw/cmpsd/scasb as a loop that
 * leaves the final compared values here). No yield occurs between the op and its jcc,
 * so plain globals are safe under the cooperative fiber scheduler. */
uint32_t g_str_a = 0, g_str_b = 0;
/* GLOBAL x87 FPU stack (recomp bug #8) — real x87 state is process-global;
 * per-function locals broke every cross-function ST0 value transfer. */
double g_fp_stack[8];
int    g_fp_top;
uint16_t g_x87_cw = 0x027F;   /* x87 default: all exceptions masked, 53-bit, round-nearest */

/* GLOBAL SSE registers (see recomp_types.h); xbox_fiber.c swaps them per
 * fiber through the helpers below. */
typedef union { uint32_t u[4]; float f[4]; } xmm128_t;   /* same as recomp_types.h */
xmm128_t g_xmm[8];
void xbox_xmm_save(void *dst)       { memcpy(dst, g_xmm, sizeof(g_xmm)); }
void xbox_xmm_load(const void *src) { memcpy(g_xmm, src, sizeof(g_xmm)); }

/* SEH frame pointer bridge (see recomp_types.h for explanation) */
uint32_t g_seh_ebp = 0;

/* ICALL trace ring buffer */
volatile uint32_t g_icall_trace[16] = {0};
volatile uint32_t g_icall_trace_idx = 0;
volatile uint64_t g_icall_count = 0;

BOOL xbox_MemoryLayoutInit(const void *xbe_data, size_t xbe_size)
{
    DWORD old_protect;
    const uint8_t *xbe = (const uint8_t *)xbe_data;

    if (g_memory_base) {
        fprintf(stderr, "xbox_MemoryLayoutInit: already initialized\n");
        return FALSE;
    }

    /*
     * Calculate the full range we need to map.
     * From XBOX_MAP_START (0x0) to the end of the furthest section.
     * This includes low memory (KPCR at 0x0-0xFF) which game code reads
     * from, the XBE sections, and the simulated stack.
     */
    DWORD map_end = XBOX_HIGH_BASE + XBOX_HIGH_SIZE;  /* low 64 MB + high CPU-only heap */
    g_memory_size = map_end - XBOX_MAP_START;

    /*
     * Create a file mapping backed by the page file.
     *
     * Using file mapping instead of VirtualAlloc allows us to map the same
     * physical pages at multiple virtual addresses via MapViewOfFileEx.
     * This is critical for the Xbox RAM mirror: the Xbox memory controller
     * uses a 26-bit address bus, so ALL addresses wrap modulo 64 MB.
     * Code that writes to address 0x20000448 is really writing to 0x00000448.
     * With file mapping views, we create aliased mappings at 64 MB intervals
     * that all point to the same physical memory.
     */
    g_mapping_handle = CreateFileMappingA(
        INVALID_HANDLE_VALUE,   /* page file backed */
        NULL,                   /* default security */
        PAGE_READWRITE,         /* read-write access */
        0,                      /* high DWORD of size */
        (DWORD)g_memory_size,   /* low DWORD of size (64 MB) */
        NULL                    /* unnamed mapping */
    );
    if (!g_mapping_handle) {
        fprintf(stderr, "xbox_MemoryLayoutInit: CreateFileMapping failed (error %lu)\n",
                GetLastError());
        return FALSE;
    }

    /*
     * Map the base view at the desired virtual address.
     * Try the original Xbox base address first. If that fails (common on
     * Windows 11 where low addresses are often reserved), try page-aligned
     * addresses upward until we find a free region.
     */
    {
        static const uintptr_t try_bases[] = {
            XBOX_BASE_ADDRESS,      /* 0x00010000 - original Xbox address */
            0x00800000,             /* 8 MB - above typical PEB/TEB region */
            0x01000000,             /* 16 MB */
            0x02000000,             /* 32 MB */
            0x10000000,             /* 256 MB */
            0x20000000,             /* additional fallbacks: the 128MB view is
                                     * fragile to DLL/heap placement (adding a
                                     * user32 import shifted layout enough to
                                     * kill 0x10000000) */
            0x30000000,
            0x40000000,
            0x60000000,
            0x70000000,
            0,                      /* sentinel - let OS choose */
        };

        for (int i = 0; try_bases[i] != 0 || i == 0; i++) {
            LPVOID hint = try_bases[i] ? (LPVOID)try_bases[i] : NULL;
            g_memory_base = MapViewOfFileEx(
                g_mapping_handle,
                FILE_MAP_ALL_ACCESS,
                0, 0,           /* offset into mapping */
                g_memory_size,  /* size */
                hint            /* desired base address */
            );
            if (g_memory_base) {
                if (try_bases[i] != 0 && (uintptr_t)g_memory_base != try_bases[i]) {
                    /* OS gave us a different address, retry */
                    UnmapViewOfFile(g_memory_base);
                    g_memory_base = NULL;
                    continue;
                }
                break;
            }
        }
    }

    if (!g_memory_base) {
        fprintf(stderr, "xbox_MemoryLayoutInit: failed to map base view (%zu KB)\n",
                g_memory_size / 1024);
        CloseHandle(g_mapping_handle);
        g_mapping_handle = NULL;
        return FALSE;
    }

    g_memory_offset = (uintptr_t)g_memory_base - XBOX_MAP_START;

    if (g_memory_offset == 0) {
        fprintf(stderr, "xbox_MemoryLayoutInit: mapped %zu KB at 0x%08X (original Xbox address)\n",
                g_memory_size / 1024, XBOX_MAP_START);
    } else {
        fprintf(stderr, "xbox_MemoryLayoutInit: mapped %zu KB at 0x%p (offset %+td from Xbox base)\n",
                g_memory_size / 1024, g_memory_base, g_memory_offset);
    }

    /*
     * Reserve the NV2A MMIO aperture (Xbox VA 0xFD000000-0xFDFFFFFF).
     *
     * The GPU registers are emulated by faulting: the VEH in main.c catches an
     * access in this window and routes it to nv2a_hook_handle_mmio, which reads
     * and writes the NV2A register state machine. That only works while the
     * window is INACCESSIBLE, so the access raises the exception.
     *
     * Nothing used to hold the window, and every host allocation in the port
     * (xbox_HeapAlloc, the kernel Mm* bridges, the CRT) calls VirtualAlloc with
     * a NULL base, letting the OS pick. A multi-megabyte allocation landed on
     * 0x11C000000 -- Xbox VA 0xFC000000 -- and ran straight through the whole
     * aperture, leaving it committed PAGE_READWRITE. From then on GPU register
     * accesses no longer faulted: they read plain zeroed RAM, so every status
     * register answered 0.
     *
     * That is fatal to the D3D FIFO-idle wait (sub_001BB705). It spins until
     * NV_PFIFO_CACHE1_STATUS and NV_PFIFO_RUNOUT_STATUS both report LOW_MARK
     * (bit 4). pfifo_read answers both correctly, but with the aperture backed
     * by RAM it was never consulted, the bits read 0, and the loop never
     * exited -- the game hung with the last frame still on screen.
     *
     * Reserving without committing does both jobs: it keeps every later
     * VirtualAlloc(NULL, ...) out of the window, and a reserved page is
     * inaccessible, so accesses still fault into the emulator. Do it here,
     * before the heap and the kernel bridges allocate anything.
     */
    {
        void *mmio = (void *)((uintptr_t)XBOX_NV2A_MMIO_BASE + g_memory_offset);
        LPVOID r = VirtualAlloc(mmio, XBOX_NV2A_MMIO_SIZE,
                                MEM_RESERVE, PAGE_NOACCESS);
        if (r == mmio) {
            fprintf(stderr, "xbox_MemoryLayoutInit: NV2A MMIO aperture reserved "
                            "at %p (Xbox VA 0x%08X, %u MB)\n",
                    mmio, (unsigned)XBOX_NV2A_MMIO_BASE,
                    (unsigned)(XBOX_NV2A_MMIO_SIZE / (1024 * 1024)));
        } else {
            /* Loud: without it the GPU status registers silently read 0 and
             * the first FIFO-idle wait hangs the game. */
            fprintf(stderr, "xbox_MemoryLayoutInit: WARNING could not reserve the "
                            "NV2A MMIO aperture at %p (got %p, error %lu) -- GPU "
                            "register emulation will not trap\n",
                    mmio, r, GetLastError());
            if (r) VirtualFree(r, 0, MEM_RELEASE);
        }
    }

    /*
     * Reserve the MCPX APU MMIO aperture (Xbox VA 0xFE800000-0xFE87FFFF) for
     * the same reason. The recompiled DirectSound driver drives the audio
     * front end by storing methods into this window, and the VEH routes those
     * faults to apu_hook_handle_mmio. Nothing held the window, so a host
     * allocation could land on it: measured at the attract start, the page
     * at 0xFE820000 turned up committed PAGE_READWRITE (a 3 MB region), the
     * driver's SET_CURRENT_VOICE / CFG_FMT / VOICE_OFF stores for a buffer it
     * was stopping stopped faulting, the voice stayed active, and
     * CMcpxBuffer_Stop spun forever in its retire wait -- the intermittent
     * freeze ten seconds into the attract loop. Reserved, the stores trap
     * again and later VirtualAlloc(NULL, ...) calls stay out of the window.
     */
    {
        void *apu = (void *)((uintptr_t)0xFE800000u + g_memory_offset);
        LPVOID r = VirtualAlloc(apu, 0x00080000u, MEM_RESERVE, PAGE_NOACCESS);
        if (r == apu) {
            fprintf(stderr, "xbox_MemoryLayoutInit: APU MMIO aperture reserved at %p "
                            "(Xbox VA 0xFE800000, 512 KB)\n", apu);
        } else {
            fprintf(stderr, "xbox_MemoryLayoutInit: WARNING could not reserve the APU "
                            "MMIO aperture at %p (got %p, error %lu) -- audio register "
                            "writes may be lost\n", apu, r, GetLastError());
            if (r) VirtualFree(r, 0, MEM_RELEASE);
        }
    }

    /*
     * Helper macro: convert Xbox VA to actual mapped address.
     * When g_memory_offset == 0 (ideal case), this is identity.
     */
    #define XBOX_VA(va) ((void *)((uintptr_t)(va) + g_memory_offset))

    /*
     * Copy XBE header to base address.
     * The Xbox kernel maps the XBE image header at 0x00010000.
     * Game code reads kernel thunk table, certificate data, and
     * section info from this region.
     */
    {
        /* XBE header size is at file offset 0x0108 (SizeOfImageHeader) */
        DWORD header_size = 0;
        if (xbe_size >= 0x10C) {
            header_size = *(const DWORD *)(xbe + 0x0108);
        }
        if (header_size == 0 || header_size > 0x10000)
            header_size = 0x1000;  /* fallback: 4KB */
        if (header_size > xbe_size)
            header_size = (DWORD)xbe_size;
        memcpy(XBOX_VA(XBOX_BASE_ADDRESS), xbe, header_size);
        fprintf(stderr, "  XBE header: %u bytes at %p (Xbox VA 0x%08X)\n",
                header_size, XBOX_VA(XBOX_BASE_ADDRESS), XBOX_BASE_ADDRESS);
    }

    /*
     * Copy every XBE section to its original Xbox VA, straight from the
     * section headers (base address at +0x104, section count at +0x11C,
     * header array VA at +0x120; each header is 0x38 bytes: flags, VA,
     * virtual size, raw address, raw size, ...). Code sections are copied
     * too: the recompiled code never executes them, but guest code reads its
     * own image (jump tables, inline data, memory walkers). The virtual tail
     * past the raw size (BSS) stays zero from the fresh file mapping.
     */
    {
        const DWORD base  = *(const DWORD *)(xbe + 0x104);
        const DWORD count = *(const DWORD *)(xbe + 0x11C);
        const DWORD hdrs  = *(const DWORD *)(xbe + 0x120) - base;
        for (DWORD i = 0; i < count; i++) {
            const uint8_t *h = xbe + hdrs + i * 0x38;
            DWORD va = *(const DWORD *)(h + 4), vsize = *(const DWORD *)(h + 8);
            DWORD raw = *(const DWORD *)(h + 12), rsize = *(const DWORD *)(h + 16);
            DWORD name_va = *(const DWORD *)(h + 20);
            const char *name = (name_va >= base && name_va - base < xbe_size)
                ? (const char *)(xbe + (name_va - base)) : "?";
            DWORD n = rsize < vsize ? rsize : vsize;
            if ((size_t)raw + n > xbe_size || va + vsize > XBOX_IMAGE_END) {
                fprintf(stderr, "  WARNING: section %s out of bounds, skipped\n", name);
                continue;
            }
            memcpy(XBOX_VA(va), xbe + raw, n);
            fprintf(stderr, "  %-10s %8u bytes (+%u BSS) at Xbox VA 0x%08X\n",
                    name, n, vsize - n, va);
        }
    }

    /*
     * NOTE: .rdata is NOT set read-only.
     * VirtualProtect rounds to page boundaries, and the .rdata end (0x003B2454)
     * and .data start (0x003B2360) share the same 4KB page (0x003B2000-0x003B2FFF).
     * Making .rdata read-only also makes the first ~0xCA0 bytes of .data read-only,
     * which causes game initialization code to fault when writing to .data globals
     * in that overlap range.
     */
    (void)old_protect;

    #undef XBOX_VA

    /* Set the global offset for recompiled code MEM macros */
    g_xbox_mem_offset = g_memory_offset;

    /*
     * Initialize the Xbox stack for recompiled code.
     * The stack area lives at XBOX_STACK_BASE in Xbox address space.
     * g_esp is the global stack pointer shared by all translated functions.
     */
    g_esp = XBOX_STACK_TOP;
    fprintf(stderr, "  Stack: %u KB at Xbox VA 0x%08X (ESP = 0x%08X)\n",
            XBOX_STACK_SIZE / 1024, XBOX_STACK_BASE, g_esp);

    /*
     * Populate the fake Thread Information Block (TIB) at Xbox VA 0x0.
     *
     * The original Xbox code uses fs:[offset] to read per-thread data,
     * but the recompiler drops the fs: segment prefix and generates
     * MEM32(offset) instead. Since we mapped low memory (0x0-0xFFFF),
     * we populate the TIB fields that game code accesses:
     *
     *   fs:[0x00] = SEH exception list (-1 = end of chain)
     *   fs:[0x04] = stack base (top of stack)
     *   fs:[0x08] = stack limit (bottom of stack)
     *   fs:[0x18] = self pointer (TIB address)
     *   fs:[0x20] = KPCR Prcb pointer (→ fake structure)
     *   fs:[0x28] = TLS / RW engine context pointer
     *
     * We use free space in the BSS area for the fake structures.
     */
    {
        #define XBOX_VA(va) ((void *)((uintptr_t)(va) + g_memory_offset))
        #define MEM32_INIT(va, val) (*(uint32_t *)XBOX_VA(va) = (uint32_t)(val))

        /* Fake TIB at address 0x0 */
        MEM32_INIT(XBOX_FS_BASE + 0x00, 0xFFFFFFFF);       /* SEH: end of chain */
        MEM32_INIT(XBOX_FS_BASE + 0x04, XBOX_STACK_TOP);   /* Stack base (high address) */
        MEM32_INIT(XBOX_FS_BASE + 0x08, XBOX_STACK_BASE);  /* Stack limit (low address) */
        MEM32_INIT(XBOX_FS_BASE + 0x18, XBOX_FS_BASE);   /* NtTib.Self */
        MEM32_INIT(XBOX_FS_BASE + 0x1C, XBOX_FS_BASE);   /* KPCR.SelfPcr */

        /*
         * fs:[0x20] - On Xbox KPCR, this is the Prcb pointer.
         * Game code reads [fs:[0x20] + 0x250] which on the real Xbox
         * accesses a D3D cache structure. We set it to 0 so the read
         * at offset 0x250 returns 0, causing the cache init to be skipped.
         */
        /* DOA2U: a zeroed fake PRCB, not 0 -- the XDK's [Prcb+0x250] debug check otherwise read
         * guest 0x250 and called through it. */
        MEM32_INIT(XBOX_FS_BASE + 0x20, XBOX_FAKE_PRCB_VA);

        /*
         * fs:[0x28] - Thread local storage / RW engine context.
         * The RW engine reads [fs:[0x28] + 0x28] to get a pointer
         * to its data area. We allocate a fake structure at 0x00760000
         * (in the BSS area) and a data buffer at 0x00700000.
         */
        /* Placed in the gap between the image end (XBOX_IMAGE_END) and the
         * stack base (XBOX_STACK_BASE) so they don't collide with game BSS. */
        #define FAKE_TLS_VA     XBOX_FAKE_TLS_VA     /* Fake TLS structure */
        #define FAKE_RWDATA_VA  XBOX_FAKE_RWDATA_VA  /* Scratch context data area */

        MEM32_INIT(XBOX_FS_BASE + 0x28, FAKE_TLS_VA);
        /* TLS[0x28] = pointer to RW data area */
        MEM32_INIT(FAKE_TLS_VA + 0x28, FAKE_RWDATA_VA);

        fprintf(stderr, "  TIB: fake KPCR/TIB at VA 0x%08X (fs:), TLS at 0x%08X, RW data at 0x%08X\n",
                XBOX_FS_BASE, FAKE_TLS_VA, FAKE_RWDATA_VA);

        #undef FAKE_TLS_VA
        #undef FAKE_RWDATA_VA
        #undef MEM32_INIT
        #undef XBOX_VA
    }

    /* Initialize the dynamic heap. */
    fprintf(stderr, "  Heap: %u MB at Xbox VA 0x%08X-0x%08X\n",
            XBOX_HEAP_SIZE / (1024 * 1024), XBOX_HEAP_BASE,
            XBOX_HEAP_BASE + XBOX_HEAP_SIZE);

    /*
     * Map mirror views of the 64 MB region.
     *
     * On retail Xbox, physical RAM wraps at 64 MB due to the 26-bit
     * address bus. Address 0x04070000 reads the same data as 0x00070000.
     * The RenderWare engine's memory walker crosses 64 MB and accesses
     * mirrored data for an extended walk covering 256+ MB of virtual
     * addresses. Game init code also writes large data structures past
     * 64 MB that on real hardware wrap into physical RAM.
     *
     * We map additional views of the SAME file mapping section at 64 MB
     * intervals. All views alias the same physical pages, so reads and
     * writes at any mirror address correctly access the base data.
     */
    {
        int mirrors_ok = 0, mirrors_partial = 0;
        for (int m = 0; m < XBOX_NUM_MIRRORS; m++) {
            uintptr_t mirror_base = (uintptr_t)g_memory_base +
                                    (uintptr_t)(m + 1) * g_memory_size;
            g_mirror_views[m] = MapViewOfFileEx(
                g_mapping_handle,
                FILE_MAP_ALL_ACCESS,
                0, 0,
                g_memory_size,
                (LPVOID)mirror_base
            );
            if (g_mirror_views[m]) {
                mirrors_ok++;
            } else {
                /* A full-size view can fail simply because the address
                 * range is a little short, and losing the whole mirror
                 * leaves a 128 MB hole that guest code walks straight
                 * into -- every access there faults through the VEH and
                 * reads garbage. Mirror 11 at 0x78000000 is the case that
                 * bit us: the range is MEM_FREE but only 0x7FE0000 bytes
                 * of it, because KUSER_SHARED_DATA sits at 0x7FFE0000.
                 * Map as much as will fit rather than nothing at all --
                 * that covered every faulting address we had seen in the
                 * hole (guest 0x5FC00004, 0x5FD1BE90, 0x5FE4F910, all
                 * below the 0x5FFE0000 cut-off). */
                DWORD err = GetLastError();
                MEMORY_BASIC_INFORMATION mbi;
                SIZE_T avail = 0;
                if (VirtualQuery((LPCVOID)mirror_base, &mbi, sizeof mbi) &&
                    mbi.State == MEM_FREE) {
                    avail = mbi.RegionSize & ~(SIZE_T)0xFFFF;   /* 64K granularity */
                    if (avail > g_memory_size) avail = g_memory_size;
                }
                if (avail >= 0x10000) {
                    g_mirror_views[m] = MapViewOfFileEx(
                        g_mapping_handle, FILE_MAP_ALL_ACCESS, 0, 0,
                        avail, (LPVOID)mirror_base);
                }
                if (g_mirror_views[m]) {
                    mirrors_partial++;
                    fprintf(stderr, "  Mirror %d: partial at %p (%llu of %llu MB; "
                                    "full view gave error %lu)\n",
                            m + 1, (void *)mirror_base,
                            (unsigned long long)(avail / (1024 * 1024)),
                            (unsigned long long)(g_memory_size / (1024 * 1024)), err);
                } else {
                    fprintf(stderr, "  Mirror %d: FAILED at %p (error %lu, "
                                    "free run %llu bytes)\n",
                            m + 1, (void *)mirror_base, err,
                            (unsigned long long)mbi.RegionSize);
                }
            }
        }
        fprintf(stderr, "  RAM mirror: %d full + %d partial of %d views\n",
                mirrors_ok, mirrors_partial, XBOX_NUM_MIRRORS);
    }
    /* Fake kernel PE page goes in after the RAM mirrors: 0x80000000+ must be the real cached
     * RAM alias (if the mirror is there this allocation just fails). */
    /*
     * Allocate a page at Xbox kernel address space (0x80010000).
     *
     * RenderWare's Xbox driver code (xbcache.c) reads MEM32(0x8001003C)
     * to parse the Xbox kernel's PE header and find the INIT section for
     * CPU cache line sizing. On PC, we provide a minimal fake PE header
     * with 0 sections so the function gracefully skips the cache init.
     *
     * The actual native address is 0x80010000 + g_memory_offset.
     */
    {
        #define XBOX_KERNEL_BASE 0x80010000u
        #define KERNEL_PAGE_SIZE 4096
        uintptr_t kernel_native = XBOX_KERNEL_BASE + g_memory_offset;
        g_kernel_memory = VirtualAlloc(
            (LPVOID)kernel_native,
            KERNEL_PAGE_SIZE,
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE
        );
        if (g_kernel_memory) {
            /* Zero-fill then set e_lfanew = 0x80 (offset to PE header).
             * With the rest zeroed, NumberOfSections = 0 and the INIT
             * section search finds nothing, which is the safe path. */
            memset(g_kernel_memory, 0, KERNEL_PAGE_SIZE);
            *(uint32_t *)((uint8_t *)g_kernel_memory + 0x3C) = 0x80;  /* e_lfanew */
            fprintf(stderr, "  Kernel: fake PE header at Xbox VA 0x%08X (native %p)\n",
                    XBOX_KERNEL_BASE, g_kernel_memory);
        } else {
            fprintf(stderr, "  WARNING: could not map Xbox kernel VA 0x%08X\n",
                    XBOX_KERNEL_BASE);
        }
        #undef XBOX_KERNEL_BASE
        #undef KERNEL_PAGE_SIZE
    }


    fprintf(stderr, "xbox_MemoryLayoutInit: complete\n");
    return TRUE;
}

void xbox_MemoryLayoutShutdown(void)
{
    if (g_kernel_memory) {
        VirtualFree(g_kernel_memory, 0, MEM_RELEASE);
        g_kernel_memory = NULL;
    }
    /* Unmap mirror views first */
    for (int m = 0; m < XBOX_NUM_MIRRORS; m++) {
        if (g_mirror_views[m]) {
            UnmapViewOfFile(g_mirror_views[m]);
            g_mirror_views[m] = NULL;
        }
    }
    /* Unmap base view */
    if (g_memory_base) {
        UnmapViewOfFile(g_memory_base);
        g_memory_base = NULL;
        g_memory_size = 0;
    }
    /* Close file mapping handle */
    if (g_mapping_handle) {
        CloseHandle(g_mapping_handle);
        g_mapping_handle = NULL;
    }
    fprintf(stderr, "xbox_MemoryLayoutShutdown: released\n");
}

BOOL xbox_IsXboxAddress(uintptr_t address)
{
    return (address >= XBOX_BASE_ADDRESS &&
            address < XBOX_BASE_ADDRESS + g_memory_size);
}

void *xbox_GetMemoryBase(void)
{
    return g_memory_base;
}
size_t xbox_GetMemorySize(void)
{
    return g_memory_size;
}

ptrdiff_t xbox_GetMemoryOffset(void)
{
    return g_memory_offset;
}

/* ── Dynamic heap allocator ────────────────────────────────
 *
 * Simple bump allocator for MmAllocateContiguousMemory and similar.
 * Returns Xbox VAs within the mapped region so MEM32() works correctly.
 * No free support (bump-only for now).
 */
static uint32_t g_heap_next = XBOX_HEAP_BASE;
/* Low-heap ceiling. Blocks reserved with xbox_HeapReserveTop() are carved
 * off the top and this drops to match, so the bump allocator below never
 * hands the same memory out. Reserving from the top rather than the front
 * leaves every game allocation at the address it had before. */
static uint32_t g_heap_limit = XBOX_HEAP_BASE + XBOX_HEAP_SIZE;

static int g_heap_alloc_count = 0;

/* Side-table allocation tracker so xbox_HeapFree can actually RECYCLE blocks
 * (the pure bump version leaked every MmFreeContiguousMemory /
 * NtFreeVirtualMemory — the game re-allocates its ~5MB partition/stream
 * buffers each boot phase and exhausted the 45MB low heap). Freed blocks go
 * on a free list and are reused first-fit (exact-or-larger, <=2x waste).
 * No headers: Xbox code receives raw aligned VAs. */
#define HEAP_TRACK_MAX 512
static struct { uint32_t va, size; int free; } g_heap_track[HEAP_TRACK_MAX];
static int g_heap_track_n = 0;

/* Add a free-list entry, recycling a slot retired by heap_coalesce (size 0)
 * before growing the table so repeated quit/reload cycles cannot exhaust
 * HEAP_TRACK_MAX. Returns 0 when there is no room. */
static int heap_track_add_free(uint32_t va, uint32_t size)
{
    int k = -1;
    for (int i = 0; i < g_heap_track_n; i++)
        if (!g_heap_track[i].size) { k = i; break; }
    if (k < 0) {
        if (g_heap_track_n >= HEAP_TRACK_MAX) return 0;
        k = g_heap_track_n++;
    }
    g_heap_track[k].va = va; g_heap_track[k].size = size; g_heap_track[k].free = 1;
    return 1;
}

uint32_t xbox_HeapAlloc(uint32_t size, uint32_t alignment)
{
    uint32_t result;

    if (alignment < 4) alignment = 4;

    /* Enforce minimum allocation size.
     * The Xbox D3D8 code sometimes computes resource sizes from GPU
     * capabilities that return 0 (since we don't have real NV2A hardware),
     * resulting in zero-size allocations. With a bump allocator, these all
     * return the same address, causing overlapping structures. Enforce a
     * minimum of 4096 bytes so each allocation gets its own memory. */
    /* Zero-size requests must still get their own block: the Xbox D3D8 code
     * computes some resource sizes from GPU capabilities that read back 0
     * here, and with a bump allocator those would all share one address and
     * overlap. That is what the 4096 floor was for -- but applying it to
     * every small request wasted ~0.86 MB across 221 allocations, and the
     * heap runs out by the character-select reset (49.5 MB of 50.75 MB),
     * which is what starves the frame-buffer allocation. Keep the guard for
     * the zero case and use a small granularity otherwise; every allocation
     * still gets a distinct, non-overlapping block. */
    if (size == 0) size = 4096;
    else if (size < 64) size = 64;

    /* Reuse a freed block first: BEST FIT over every free block that is big
     * enough and naturally aligned, splitting the remainder back in.
     *
     * This used to refuse any block more than twice the request, so an
     * ordinary allocation could not swallow a huge one. Without splitting
     * that was the only protection available, but it also let the bump
     * pointer keep advancing while large freed blocks sat unused -- and the
     * bump never rewinds. By the character-select reset the heap stood at
     * 51.3 MB of 52.1 MB with ~20 MB free but unusable, so the frame-buffer
     * allocations failed and the surface descriptors were left empty. Best
     * fit plus splitting bounds the waste without stranding memory. */
    {
        /* A free block whose START is not aligned can still hold an aligned
         * sub-range; rejecting it outright stranded usable memory. Align up
         * inside the block and require the aligned range to fit. */
        int best = -1;
        uint32_t best_va = 0;
        for (int i = 0; i < g_heap_track_n; i++) {
            uint32_t va, end;
            if (!g_heap_track[i].free || !g_heap_track[i].size) continue;
            va  = (g_heap_track[i].va + alignment - 1) & ~(alignment - 1);
            end = g_heap_track[i].va + g_heap_track[i].size;
            if (va < g_heap_track[i].va || va + size > end) continue;
            if (best < 0 || g_heap_track[i].size < g_heap_track[best].size) {
                best = i; best_va = va;
            }
        }
        if (best >= 0) {
            uint32_t take;
            /* Split off any head skipped for alignment so it stays usable. */
            if (best_va != g_heap_track[best].va &&
                heap_track_add_free(g_heap_track[best].va, best_va - g_heap_track[best].va)) {
                g_heap_track[best].size -= (best_va - g_heap_track[best].va);
                g_heap_track[best].va    = best_va;
            }
            take = (size + 4095u) & ~4095u;
            if (g_heap_track[best].size >= take + 0x10000u &&
                heap_track_add_free(g_heap_track[best].va + take, g_heap_track[best].size - take)) {
                g_heap_track[best].size = take;
            }
            g_heap_track[best].free = 0;
            memset((void *)((uintptr_t)g_heap_track[best].va + g_memory_offset), 0,
                   g_heap_track[best].size);
            g_heap_alloc_count++;
            return g_heap_track[best].va;
        }
    }

    /* Align the next pointer */
    result = (g_heap_next + alignment - 1) & ~(alignment - 1);

    if (result + size > g_heap_limit) {
        /* The bump pointer is out of room. Before failing, take ANY free
         * block that is big enough and correctly aligned -- best fit, so
         * as little as possible is wasted.
         *
         * The tight-fit pass above deliberately refuses a block more than
         * twice the request, so an ordinary allocation does not eat a huge
         * one. That heuristic must not become an outright failure. Entering
         * character select the game tears down its frame buffers (freeing
         * 14 MB + 2.8 MB) and asks for a 5.9 MB multisampled one; the 14 MB
         * block was the only fit and was rejected, so
         * MmAllocateContiguousMemoryEx returned 0. sub_001B9260 then bails
         * before filling the implicit surface descriptors at device+0x2150
         * and +0x2168, leaving Format and Size zero -- and SetViewport
         * clamps every viewport against a surface it then computes as one
         * pixel wide. The 720x480 request became 1x1, the
         * projection-viewport matrix collapsed, and transformed vertices
         * came out with a negative w: the smeared geometry on that screen.
         *
         * This runs only where the allocator previously returned 0, so it
         * cannot alter any allocation that already succeeds. */
        int best = -1;
        for (int i = 0; i < g_heap_track_n; i++) {
            if (!g_heap_track[i].free) continue;
            if (g_heap_track[i].size < size) continue;
            if (g_heap_track[i].va & (alignment - 1)) continue;
            if (best < 0 || g_heap_track[i].size < g_heap_track[best].size)
                best = i;
        }
        if (best >= 0) {
            /* Split the remainder back into the free list, otherwise a single
             * oversized block satisfies one request and the rest is lost. The
             * character-select reset asks for the 5.9 MB multisampled frame
             * buffer TWICE; without splitting, the first took the whole 14 MB
             * block and the second still failed. */
            uint32_t take = (size + 4095u) & ~4095u;
            if (g_heap_track[best].size >= take + 0x10000u &&
                heap_track_add_free(g_heap_track[best].va + take, g_heap_track[best].size - take)) {
                g_heap_track[best].size = take;
            }
            g_heap_track[best].free = 0;
            memset((void *)((uintptr_t)g_heap_track[best].va + g_memory_offset), 0,
                   g_heap_track[best].size);
            g_heap_alloc_count++;
            return g_heap_track[best].va;
        }
        fprintf(stderr, "xbox_HeapAlloc: out of memory (requested %u, used %u/%u)\n",
                size, g_heap_next - XBOX_HEAP_BASE,
                g_heap_limit - XBOX_HEAP_BASE);
        return 0;
    }

    g_heap_next = result + size;

    /* Zero-fill the allocated block (Xbox memory is always zeroed) */
    memset((void *)((uintptr_t)result + g_memory_offset), 0, size);

    if (g_heap_track_n < HEAP_TRACK_MAX) {
        g_heap_track[g_heap_track_n].va = result;
        g_heap_track[g_heap_track_n].size = size;
        g_heap_track[g_heap_track_n].free = 0;
        g_heap_track_n++;
    }

    g_heap_alloc_count++;

    return result;
}

/* Merge every run of adjacent free blocks into one.
 *
 * The tracker is a flat list, so a block freed next to another stays a
 * separate entry and only the largest single entry can ever satisfy a big
 * request. Tearing down the frame buffers on the character-select reset frees
 * four blocks, two of which are contiguous (0x01278000 + 1474560 ==
 * 0x013E0000); without merging them the following 5.9 MB requests could not
 * all be met and the surface descriptors were left unfilled. */
static void heap_coalesce(void)
{
    int merged = 1;
    while (merged) {
        merged = 0;
        for (int i = 0; i < g_heap_track_n; i++) {
            if (!g_heap_track[i].free || !g_heap_track[i].size) continue;
            for (int j = 0; j < g_heap_track_n; j++) {
                if (i == j || !g_heap_track[j].free || !g_heap_track[j].size) continue;
                if (g_heap_track[i].va + g_heap_track[i].size != g_heap_track[j].va)
                    continue;
                g_heap_track[i].size += g_heap_track[j].size;
                g_heap_track[j].size = 0;      /* retired: size 0 never matches */
                g_heap_track[j].free = 0;
                merged = 1;
            }
        }
    }
}

void xbox_HeapFree(uint32_t xbox_va)
{
    if (!xbox_va) return;
    for (int i = 0; i < g_heap_track_n; i++) {
        /* Skip entries retired by heap_coalesce (size 0). They keep their
         * old VA, and once the merged region has been split and handed out
         * again a LIVE block sits at that same VA further down the list.
         * Matching the retired entry first logged "freed 0 bytes" and left
         * the real block allocated: quitting a fight from the pause menu
         * leaked its 14.7 MB + 1.4 MB buffers this way, and the next mode's
         * load then failed with out-of-memory on NOW LOADING. */
        if (!g_heap_track[i].size) continue;
        if (g_heap_track[i].va == xbox_va && !g_heap_track[i].free) {
            g_heap_track[i].free = 1;
            heap_coalesce();
            return;
        }
    }
    /* Unknown/duplicate free: ignore (matches previous no-op behavior). */
}

/* High heap (above the console's 64 MB): CPU-only allocations — see the
 * header comment. Same bump model as xbox_HeapAlloc. */
/* Reserve a block at the top of the low heap.
 *
 * Needed for anything the *guest* converts from a virtual to a physical
 * address. Xbox RAM is 64 MB and VA == PA there, so the console D3D8
 * library performs that conversion with a bare 26-bit mask (& 0x03FFFFFF;
 * see recomp_0010.c). A buffer placed above 64 MB therefore aliases onto
 * low RAM as soon as the guest masks its address: the D3D8 push buffer at
 * 0x04000000-0x04400000 aliased onto 0x00000000-0x00400000, so its vertex
 * writes landed in .data and corrupted the 175-object array at 0x370C48
 * that sub_000E8BB0 dispatches through -- vtable pointers overwritten with
 * vertex data, then called. Keeping such buffers under 64 MB makes the
 * guest mask the identity it is on hardware. */
uint32_t xbox_HeapReserveTop(uint32_t size, uint32_t alignment)
{
    uint32_t base;

    if (alignment < 4) alignment = 4;
    if (size > g_heap_limit - g_heap_next) {
        fprintf(stderr, "xbox_HeapReserveTop: no room (requested %u, free %u)\n",
                size, g_heap_limit - g_heap_next);
        return 0;
    }
    base = (g_heap_limit - size) & ~(alignment - 1);
    g_heap_limit = base;
    memset((void *)((uintptr_t)base + g_memory_offset), 0, size);
    return base;
}

static uint32_t g_high_next = XBOX_HIGH_BASE;

uint32_t xbox_HeapAllocHigh(uint32_t size, uint32_t alignment)
{
    uint32_t result;

    if (alignment < 4) alignment = 4;
    result = (g_high_next + alignment - 1) & ~(alignment - 1);

    if (result + size > XBOX_HIGH_BASE + XBOX_HIGH_SIZE) {
        fprintf(stderr, "xbox_HeapAllocHigh: out of memory (requested %u, used %u/%u)\n",
                size, g_high_next - XBOX_HIGH_BASE, XBOX_HIGH_SIZE);
        return 0;
    }

    g_high_next = result + size;
    memset((void *)((uintptr_t)result + g_memory_offset), 0, size);
    return result;
}

HANDLE xbox_GetMappingHandle(void)
{
    return g_mapping_handle;
}
