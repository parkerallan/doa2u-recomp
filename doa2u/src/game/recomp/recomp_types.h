/**
 * Dead or Alive 2 Ultimate - Recompiled Code Runtime Support
 *
 * Type definitions and helper macros used by mechanically
 * translated x86→C code. Each original x86 function is
 * translated to a C function that uses these types.
 *
 * Memory model:
 *   Xbox data sections are mapped to their original VAs via
 *   VirtualAlloc (see xbox_memory_layout.c). Recompiled code
 *   accesses globals via pointer casts, e.g.:
 *     *(uint32_t*)0x003B2360
 *
 * Register model:
 *   Volatile registers (eax, ecx, edx, esp) are global variables,
 *   matching real x86 behavior where these registers are shared
 *   across all code. This enables correct argument passing via the
 *   simulated stack and return value communication via eax.
 *
 *   Callee-saved registers (ebx, esi, edi, ebp) are local variables
 *   in each translated function, automatically preserving the caller's
 *   values through C's stack frame mechanism.
 *
 * Calling convention:
 *   All translated functions are void(void). Arguments are passed
 *   on the simulated Xbox stack (via push instructions before call).
 *   Return values are communicated through g_eax.
 *   The call instruction pushes a dummy return address; ret pops it.
 */

#ifndef RECOMP_TYPES_H
#define RECOMP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>    /* x87_frndint: floor/ceil/trunc/rint */

/* ── Memory offset ──────────────────────────────────────── */

/**
 * Memory offset from Xbox VA to actual mapped address.
 * When Xbox memory is mapped at the original address (0x00010000),
 * this is 0 and the MEM macros are simple identity casts.
 * When mapped elsewhere, this adjusts all memory accesses.
 *
 * Set once during xbox_MemoryLayoutInit, then read-only.
 */
extern ptrdiff_t g_xbox_mem_offset;

/* ── Global registers ──────────────────────────────────── */

/**
 * Volatile x86 registers (caller-saved):
 *   eax - return values, general accumulator
 *   ecx - 'this' pointer for thiscall, loop counter
 *   edx - high dword of multiply/divide, general
 *   esp - stack pointer (initialized to XBOX_STACK_TOP)
 *
 * Callee-saved x86 registers (also global):
 *   ebx, esi, edi - these are global because callers pass implicit
 *   parameters through them (e.g. 'this' via esi in thiscall).
 *   The callee-save contract is enforced by PUSH32/POP32 instructions
 *   in the generated code, not by C local variable scoping.
 *
 * NOT global: ebp - stays local in each function because 20K+ FPO
 * (Frame Pointer Omission) functions use it as scratch without
 * save/restore. For SEH functions, g_seh_ebp bridges the gap.
 */
extern uint32_t g_eax, g_ecx, g_edx, g_esp;
extern uint32_t g_ebx, g_esi, g_edi;
extern uint32_t g_str_a, g_str_b;   /* last REP cmps/scas operand pair (see xbox_memory_layout.c) */
extern double  g_fp_stack[8];       /* GLOBAL x87 FPU stack (recomp bug #8: was per-function
                                     * locals, breaking every cross-function ST0 transfer) */
extern int     g_fp_top;
extern uint16_t g_x87_cw;          /* x87 control word (fnstcw/fldcw); default 0x027F */

/* frndint honouring the control word's rounding mode (bits 10-11):
 * 0 nearest-even, 1 down, 2 up, 3 toward zero. */
static __inline double x87_frndint(double v)
{
    switch ((g_x87_cw >> 10) & 3) {
    case 1:  return floor(v);
    case 2:  return ceil(v);
    case 3:  return trunc(v);
    default: return rint(v);
    }
}

/**
 * SEH frame pointer bridge.
 *
 * __SEH_prolog (sub_00244784) sets up ebp for the caller, but since ebp is
 * a local variable in each function, the caller can't see the prolog's change.
 * The prolog writes g_seh_ebp, and the caller reads it after the call.
 * Similarly, __SEH_epilog reads g_seh_ebp at entry and writes it at exit.
 */
extern uint32_t g_seh_ebp;

/* ── ICALL trace ring buffer (for debugging) ────────── */
#define ICALL_TRACE_SIZE 16
extern volatile uint32_t g_icall_trace[ICALL_TRACE_SIZE];
extern volatile uint32_t g_icall_trace_idx;
extern volatile uint64_t g_icall_count;

/* ── ICALL failure diagnostic ────────────────────────────── */
void recomp_icall_fail_log(uint32_t va);

/* fs: base: the fake KPCR/NT_TIB (see xbox_memory_layout.h). */
#ifndef XBOX_FS_BASE
#define XBOX_FS_BASE 0x0107E000u
#endif

/* ── Memory access helpers ──────────────────────────────── */

/** Translate an Xbox VA to an actual pointer.
 *  Mask to 32-bit first: Xbox addresses are 32-bit and arithmetic
 *  in the recompiled code can overflow. Without the mask, a 64-bit
 *  uintptr_t cast preserves the overflow bits, landing us 4GB+ past
 *  our mapping and causing access violations.
 *
 *  Native pointer detection: RenderWare's internal allocator (and some
 *  kernel functions) may store native heap pointers in Xbox memory.
 *  When recompiled code reads these back and uses them as addresses,
 *  adding g_xbox_mem_offset would cause a double-offset fault. We detect
 *  this by checking if the address already falls within our mapped
 *  native region and skip the offset addition in that case.
 *
 *  This is safe because Xbox mirror views all alias the same physical
 *  memory, so a native pointer to any mirror correctly accesses the
 *  right underlying data. */
static __forceinline uintptr_t xbox_ptr_resolve(uint32_t addr)
{
    /* Fast path: most addresses are Xbox VAs below the mapping base.
     * The mapped native region spans [offset, offset + 29*64MB).
     * Any address in this range is already a native pointer and
     * should NOT have the offset added again. */
    uint32_t offset32 = (uint32_t)g_xbox_mem_offset;
    if (offset32 != 0) {
        uint32_t rel = addr - offset32;  /* wraps if addr < offset32 */
        if (rel < 0x74000000u) {  /* 29 * 64MB = total mapped region */
            return (uintptr_t)addr;
        }
    }
    return (uintptr_t)addr + g_xbox_mem_offset;
}
#define XBOX_PTR(addr) xbox_ptr_resolve((uint32_t)(addr))

/**
 * Check if a uint32_t value is a valid game pointer.
 * Accepts both Xbox VAs (0x10000..0x4000000) and native pointers
 * that fall within the mapped Xbox memory region.
 * Use this for vtable validation instead of rigid Xbox VA range checks.
 */
static __forceinline int is_valid_game_ptr(uint32_t val)
{
    /* Xbox VA range (covers .text, .data, .rdata, heap, stack) */
    if (val >= 0x10000 && val < 0x8000000) /* low heap to 80 MB + high heap to 128 MB */
        return 1;
    /* Native pointer in our mapped region */
    uint32_t offset32 = (uint32_t)g_xbox_mem_offset;
    if (offset32 != 0) {
        uint32_t rel = val - offset32;
        if (rel < 0x74000000u)
            return 1;
    }
    return 0;
}

/**
 * Convert a native pointer value to its Xbox VA equivalent.
 * Returns the Xbox VA (modulo 64MB mirror) if the value is a native
 * pointer in the mapped region. Returns the value unchanged if it's
 * already an Xbox VA.
 */
static __forceinline uint32_t native_to_xbox_va(uint32_t val)
{
    uint32_t offset32 = (uint32_t)g_xbox_mem_offset;
    if (offset32 != 0 && val >= offset32) {
        uint32_t rel = val - offset32;
        if (rel < 0x08000000u)
            return rel;              /* the 128 MB base view is not mirrored */
        if (rel < 0x74000000u)
            return rel % 0x04000000u;
    }
    return val;
}

/** Read N bytes from a flat memory address. */
#define MEM8(addr)   (*(volatile uint8_t  *)XBOX_PTR(addr))
#define MEM16(addr)  (*(volatile uint16_t *)XBOX_PTR(addr))
#define MEM32(addr)  (*(volatile uint32_t *)XBOX_PTR(addr))

/** Signed memory reads. */
#define SMEM8(addr)  (*(volatile int8_t   *)XBOX_PTR(addr))
#define SMEM16(addr) (*(volatile int16_t  *)XBOX_PTR(addr))
#define SMEM32(addr) (*(volatile int32_t  *)XBOX_PTR(addr))

/** Float memory access. */
#define MEMF(addr)   (*(volatile float    *)XBOX_PTR(addr))
#define MEMD(addr)   (*(volatile double   *)XBOX_PTR(addr))

/* ---- 128-bit SSE register -----------------------------------------------
 *
 * The lifter models an xmm register as a single `float`, which is correct
 * only for the scalar forms (movss, addss, ...). Every packed operation was
 * therefore wrong: the 16-byte moves (movaps) were emitted as single-float
 * MEMF moves and transferred 4 of 16 bytes, while the packed arithmetic
 * (mulps, addps, subps, shufps, cmpneqps, orps) was dropped entirely and
 * left as a bare comment doing nothing. The matrix routines in the XDK maths
 * library are built almost entirely out of those, so they moved partial data
 * around and performed none of the arithmetic.
 *
 * Lanes are kept as raw dwords so bitwise ops (xorps/orps/cmp*) and float
 * ops share one representation without type-punning through pointers. */
typedef union { uint32_t u[4]; float f[4]; } xmm128_t;

/* xmm0-7 are machine state, like g_eax: floats cross calls and split
 * fragments in xmm registers. Saved/restored per fiber in xbox_fiber.c. */
extern xmm128_t g_xmm[8];
#define xmm0 (g_xmm[0])
#define xmm1 (g_xmm[1])
#define xmm2 (g_xmm[2])
#define xmm3 (g_xmm[3])
#define xmm4 (g_xmm[4])
#define xmm5 (g_xmm[5])
#define xmm6 (g_xmm[6])
#define xmm7 (g_xmm[7])

static __forceinline xmm128_t xmm_load(uint32_t a) {
    xmm128_t r;
    r.u[0] = MEM32(a); r.u[1] = MEM32(a + 4);
    r.u[2] = MEM32(a + 8); r.u[3] = MEM32(a + 12);
    return r;
}
static __forceinline void xmm_store(uint32_t a, xmm128_t v) {
    MEM32(a) = v.u[0]; MEM32(a + 4) = v.u[1];
    MEM32(a + 8) = v.u[2]; MEM32(a + 12) = v.u[3];
}
static __forceinline xmm128_t xmm_zero(void) {
    xmm128_t r; r.u[0] = r.u[1] = r.u[2] = r.u[3] = 0; return r;
}
/* movss from memory zeroes the upper three lanes; movlps/movhps preserve
 * the half they do not write. */
static __forceinline xmm128_t xmm_load_ss(uint32_t a) {
    xmm128_t r = xmm_zero(); r.u[0] = MEM32(a); return r;
}
static __forceinline void xmm_store_ss(uint32_t a, xmm128_t v) { MEM32(a) = v.u[0]; }
static __forceinline xmm128_t xmm_load_lo(xmm128_t d, uint32_t a) {
    d.u[0] = MEM32(a); d.u[1] = MEM32(a + 4); return d;
}
static __forceinline void xmm_store_lo(uint32_t a, xmm128_t v) {
    MEM32(a) = v.u[0]; MEM32(a + 4) = v.u[1];
}
static __forceinline xmm128_t xmm_load_hi(xmm128_t d, uint32_t a) {
    d.u[2] = MEM32(a); d.u[3] = MEM32(a + 4); return d;
}
static __forceinline void xmm_store_hi(uint32_t a, xmm128_t v) {
    MEM32(a) = v.u[2]; MEM32(a + 4) = v.u[3];
}
/* SHUFPS dst, src, imm: lanes 0-1 come from dst, lanes 2-3 from src. */
static __forceinline xmm128_t xmm_shufps(xmm128_t d, xmm128_t s, unsigned imm) {
    xmm128_t r;
    r.u[0] = d.u[(imm >> 0) & 3]; r.u[1] = d.u[(imm >> 2) & 3];
    r.u[2] = s.u[(imm >> 4) & 3]; r.u[3] = s.u[(imm >> 6) & 3];
    return r;
}
#define XMM_PACKED_OP(name, expr)                                   \
    static __forceinline xmm128_t name(xmm128_t a, xmm128_t b) {    \
        xmm128_t r; int _i;                                         \
        for (_i = 0; _i < 4; _i++) { expr; }                        \
        return r;                                                   \
    }
XMM_PACKED_OP(xmm_addps, r.f[_i] = a.f[_i] + b.f[_i])
XMM_PACKED_OP(xmm_subps, r.f[_i] = a.f[_i] - b.f[_i])
XMM_PACKED_OP(xmm_mulps, r.f[_i] = a.f[_i] * b.f[_i])
XMM_PACKED_OP(xmm_orps,  r.u[_i] = a.u[_i] | b.u[_i])
/* CMPNEQPS is true for unordered operands too, which is what !(x == y)
 * gives for NaN. */
XMM_PACKED_OP(xmm_cmpneqps, r.u[_i] = !(a.f[_i] == b.f[_i]) ? 0xFFFFFFFFu : 0u)
XMM_PACKED_OP(xmm_divps, r.f[_i] = a.f[_i] / b.f[_i])
XMM_PACKED_OP(xmm_minps, r.f[_i] = (a.f[_i] < b.f[_i]) ? a.f[_i] : b.f[_i])
XMM_PACKED_OP(xmm_maxps, r.f[_i] = (a.f[_i] > b.f[_i]) ? a.f[_i] : b.f[_i])
XMM_PACKED_OP(xmm_andps, r.u[_i] = a.u[_i] & b.u[_i])
XMM_PACKED_OP(xmm_andnps, r.u[_i] = ~a.u[_i] & b.u[_i])
XMM_PACKED_OP(xmm_xorps, r.u[_i] = a.u[_i] ^ b.u[_i])
XMM_PACKED_OP(xmm_cmpeqps, r.u[_i] = (a.f[_i] == b.f[_i]) ? 0xFFFFFFFFu : 0u)
XMM_PACKED_OP(xmm_cmpltps, r.u[_i] = (a.f[_i] < b.f[_i]) ? 0xFFFFFFFFu : 0u)
XMM_PACKED_OP(xmm_cmpleps, r.u[_i] = (a.f[_i] <= b.f[_i]) ? 0xFFFFFFFFu : 0u)
static __forceinline xmm128_t xmm_unpcklps(xmm128_t a, xmm128_t b) {
    xmm128_t r; r.u[0] = a.u[0]; r.u[1] = b.u[0]; r.u[2] = a.u[1]; r.u[3] = b.u[1]; return r;
}
static __forceinline xmm128_t xmm_unpckhps(xmm128_t a, xmm128_t b) {
    xmm128_t r; r.u[0] = a.u[2]; r.u[1] = b.u[2]; r.u[2] = a.u[3]; r.u[3] = b.u[3]; return r;
}
static __forceinline xmm128_t xmm_movlhps(xmm128_t a, xmm128_t b) {
    a.u[2] = b.u[0]; a.u[3] = b.u[1]; return a;
}
static __forceinline xmm128_t xmm_movhlps(xmm128_t a, xmm128_t b) {
    a.u[0] = b.u[2]; a.u[1] = b.u[3]; return a;
}
static __forceinline xmm128_t xmm_sqrtps(xmm128_t a) {
    int _i; for (_i = 0; _i < 4; _i++) a.f[_i] = sqrtf(a.f[_i]); return a;
}
static __forceinline xmm128_t xmm_rsqrtps(xmm128_t a) {
    int _i; for (_i = 0; _i < 4; _i++) a.f[_i] = 1.0f / sqrtf(a.f[_i]); return a;
}
static __forceinline xmm128_t xmm_rcpps(xmm128_t a) {
    int _i; for (_i = 0; _i < 4; _i++) a.f[_i] = 1.0f / a.f[_i]; return a;
}
static __forceinline uint32_t xmm_movmskps(xmm128_t a) {
    return (a.u[0] >> 31) | ((a.u[1] >> 31) << 1) | ((a.u[2] >> 31) << 2) | ((a.u[3] >> 31) << 3);
}


/* ── Flag computation helpers ───────────────────────────── */

/**
 * These macros compute x86 flags for conditional branches.
 * They are used by the lifter's pattern-matching output:
 *   cmp a, b; jcc target → if (COND(a, b)) goto target;
 */

/* Unsigned comparison conditions (from CMP a, b → a - b)
 *
 * Like the signed conditions below, these must be evaluated at the OPERAND
 * width. x86 sign-extends a byte immediate to the operand size and compares
 * there, so `cmp word ptr [m], -1` tests the 16-bit value against 0xFFFF --
 * but the lifter writes that immediate out already sign-extended to 32 bits
 * (`0xFFFFFFFFu`). Comparing a zero-extended uint16_t against it made the
 * equality permanently false, so `je` was never taken and `jne` always was.
 *
 * That is not academic either: it is why the character animation event loop
 * in sub_0008C420 (`cmp word ptr [esi*2+0x4BADEC], -1; jne loop`) never
 * terminated once the attract demo advanced to its second fight.
 *
 * RC_ZXB narrows the right operand to the left operand's width, exactly as
 * RC_SXB does for the signed conditions. 32-bit operands are unaffected, and
 * an immediate that already fits the operand width compares the same as
 * before. */
#define RC_ZXB(a, b) (sizeof(a) == 1 ? (uint32_t)(uint8_t)(b) :                       sizeof(a) == 2 ? (uint32_t)(uint16_t)(b) : (uint32_t)(b))
#define CMP_EQ(a, b)  ((uint32_t)(a) == RC_ZXB(a, b))
#define CMP_NE(a, b)  ((uint32_t)(a) != RC_ZXB(a, b))
#define CMP_B(a, b)   ((uint32_t)(a) <  RC_ZXB(a, b))    /* below (CF=1) */
#define CMP_AE(a, b)  ((uint32_t)(a) >= RC_ZXB(a, b))    /* above or equal */
#define CMP_BE(a, b)  ((uint32_t)(a) <= RC_ZXB(a, b))    /* below or equal */
#define CMP_A(a, b)   ((uint32_t)(a) >  RC_ZXB(a, b))    /* above */

/* Signed comparison conditions */
/* Signed comparisons must be evaluated at the OPERAND width, not at 32 bits.
 *
 * The generated code passes LO8()/LO16() results for 8- and 16-bit operations,
 * and those are uint8_t/uint16_t -- so `sizeof` recovers the width the guest
 * instruction actually used. Evaluating them as int32_t made every negative
 * 8/16-bit value compare as a large positive number: `cmp ax, 0` with
 * ax = 0xFFFF took the >= 0 branch instead of the < 0 one.
 *
 * That is not academic. It is why sub_000E50B0 never terminated its 16-bit
 * index walk (the list is terminated by a negative entry) and scanned memory
 * until the fault cap aborted the process.
 *
 * The right-hand operand is narrowed to the left operand's width first, so an
 * immediate like 0xFF compares as -1 against an 8-bit register, exactly as
 * `cmp al, 0FFh` does. 32-bit operands are unaffected. */
#define RC_SXA(a)    (sizeof(a) == 1 ? (int32_t)(int8_t)(uint8_t)(a) : \
                      sizeof(a) == 2 ? (int32_t)(int16_t)(uint16_t)(a) : (int32_t)(a))
#define RC_SXB(a, b) (sizeof(a) == 1 ? (int32_t)(int8_t)(uint8_t)(b) : \
                      sizeof(a) == 2 ? (int32_t)(int16_t)(uint16_t)(b) : (int32_t)(b))
#define CMP_L(a, b)   (RC_SXA(a) <  RC_SXB(a, b))       /* less (SF!=OF) */
#define CMP_GE(a, b)  (RC_SXA(a) >= RC_SXB(a, b))       /* greater or equal */
#define CMP_LE(a, b)  (RC_SXA(a) <= RC_SXB(a, b))       /* less or equal */
#define CMP_G(a, b)   (RC_SXA(a) >  RC_SXB(a, b))       /* greater */

/* ── Flags carried across a fragment boundary ─────────────
 *
 * When the lifter split a basic block so that the cmp/test ended one generated
 * function and the jcc began the next, it emitted the branch as
 * `int _flags = 0; ... if (_flags ...)` -- a branch that can never be
 * taken. Re-evaluating the compare at the branch is not enough: several of
 * those branches are reached from paths that compared different things. The
 * compare therefore records its operands here and the branch evaluates the
 * x86 condition from them, which is exact for cmp and test. */
extern uint32_t g_flg_a, g_flg_b;
extern int g_flg_w, g_flg_test;
#define RC_SETF_CMP(a, b)  (g_flg_a = (uint32_t)(a), g_flg_b = (uint32_t)(b),                             g_flg_w = (int)sizeof(a), g_flg_test = 0)
#define RC_SETF_TEST(a, b) (g_flg_a = (uint32_t)(a), g_flg_b = (uint32_t)(b),                             g_flg_w = (int)sizeof(a), g_flg_test = 1)
int rc_flg_cc(int cc);
#define RC_F_JE()   rc_flg_cc(0)
#define RC_F_JNE()  rc_flg_cc(1)
#define RC_F_JB()   rc_flg_cc(2)
#define RC_F_JAE()  rc_flg_cc(3)
#define RC_F_JBE()  rc_flg_cc(4)
#define RC_F_JA()   rc_flg_cc(5)
#define RC_F_JL()   rc_flg_cc(6)
#define RC_F_JGE()  rc_flg_cc(7)
#define RC_F_JLE()  rc_flg_cc(8)
#define RC_F_JG()   rc_flg_cc(9)
#define RC_F_JS()   rc_flg_cc(10)
#define RC_F_JNS()  rc_flg_cc(11)
#define RC_F_JO()   rc_flg_cc(12)
#define RC_F_JNO()  rc_flg_cc(13)
#define RC_F_JP()   rc_flg_cc(14)
#define RC_F_JNP()  rc_flg_cc(15)

/* TEST-based conditions (AND without storing result) */
#define TEST_Z(a, b)  (((uint32_t)(a) & (uint32_t)(b)) == 0)  /* ZF=1 */
#define TEST_NZ(a, b) (((uint32_t)(a) & (uint32_t)(b)) != 0)  /* ZF=0 */
/* SF after TEST, at the operand width (see the note above). */
#define TEST_S(a, b)  (sizeof(a) == 1 ? (int8_t)((uint8_t)(a) & (uint8_t)(b)) < 0 : \
                       sizeof(a) == 2 ? (int16_t)((uint16_t)(a) & (uint16_t)(b)) < 0 : \
                       (int32_t)((uint32_t)(a) & (uint32_t)(b)) < 0)

/* ── Arithmetic with carry/overflow detection ───────────── */

/** Add with carry flag. Returns result, sets *cf. */
static inline uint32_t ADD32_CF(uint32_t a, uint32_t b, int *cf) {
    uint32_t r = a + b;
    *cf = (r < a);
    return r;
}

/** Sub with carry (borrow) flag. Returns result, sets *cf. */
static inline uint32_t SUB32_CF(uint32_t a, uint32_t b, int *cf) {
    *cf = (a < b);
    return a - b;
}

/* ── Rotation / shift helpers ───────────────────────────── */

static inline uint32_t ROL32(uint32_t val, int n) {
    n &= 31;
    return (val << n) | (val >> (32 - n));
}

static inline uint32_t ROR32(uint32_t val, int n) {
    n &= 31;
    return (val >> n) | (val << (32 - n));
}

/* ── Sign/zero extension ───────────────────────────────── */

#define ZX8(v)   ((uint32_t)(uint8_t)(v))
#define ZX16(v)  ((uint32_t)(uint16_t)(v))
#define SX8(v)   ((uint32_t)(int32_t)(int8_t)(v))
#define SX16(v)  ((uint32_t)(int32_t)(int16_t)(v))

/* ── Byte/word register access ──────────────────────────── */

/** Extract low byte (al, bl, cl, dl). */
#define LO8(r)  ((uint8_t)((r) & 0xFF))
/** Extract high byte of low word (ah, bh, ch, dh). */
#define HI8(r)  ((uint8_t)(((r) >> 8) & 0xFF))
/** Extract low word (ax, bx, cx, dx). */
#define LO16(r) ((uint16_t)((r) & 0xFFFF))

/** Set low byte. */
#define SET_LO8(r, v)  ((r) = ((r) & 0xFFFFFF00u) | ((uint32_t)(uint8_t)(v)))
/** Set high byte of low word. */
#define SET_HI8(r, v)  ((r) = ((r) & 0xFFFF00FFu) | (((uint32_t)(uint8_t)(v)) << 8))

/* x86 parity flag of a byte: PF=1 when the low 8 bits have an EVEN number of
 * set bits (recomp bug #9: jp/jnp used to be hardcoded). Nibble-parity trick:
 * (0x6996 >> nibble) & 1 gives ODD parity of a nibble. */
#define X86_PF8(x) (!((0x6996 >> ((((uint32_t)(x) >> 4) ^ (uint32_t)(x)) & 0xF)) & 1))
/** Set low word. */
#define SET_LO16(r, v) ((r) = ((r) & 0xFFFF0000u) | ((uint32_t)(uint16_t)(v)))

/* ── Stack simulation (for push/pop heavy prologues) ────── */

/** Push a 32-bit value onto a simulated stack.
 *  Evaluates val BEFORE decrementing sp, matching x86 semantics
 *  where push [esp+N] reads the operand before adjusting ESP. */
#define PUSH32(sp, val) do { uint32_t _pv = (uint32_t)(val); (sp) -= 4; MEM32(sp) = _pv; } while(0)

/** Pop a 32-bit value from a simulated stack. */
#define POP32(sp, dst)  do { (dst) = MEM32(sp); (sp) += 4; } while(0)

/* ── Byte swap (for endian conversion if needed) ────────── */

static inline uint32_t BSWAP32(uint32_t v) {
    return ((v >> 24) & 0xFF) | ((v >> 8) & 0xFF00) |
           ((v << 8) & 0xFF0000) | ((v << 24) & 0xFF000000u);
}

static inline uint16_t BSWAP16(uint16_t v) {
    return (v >> 8) | (v << 8);
}

/* Bit scan (bsf/bsr): index of the lowest / highest set bit. Callers
 * guarantee a non-zero argument (the lifter tests it first). */
static inline uint32_t BSF32(uint32_t v) {
    uint32_t i = 0; while (!(v & 1u)) { v >>= 1; i++; } return i;
}
static inline uint32_t BSR32(uint32_t v) {
    uint32_t i = 0; while (v >>= 1) i++; return i;
}

/* ── Indirect call dispatch ──────────────────────────────── */

/**
 * Generic function pointer type for dispatch table lookups.
 */
#ifndef RECOMP_DISPATCH_H  /* avoid conflict with recomp_dispatch.h */
typedef void (*recomp_func_t)(void);
recomp_func_t recomp_lookup(uint32_t xbox_va);
recomp_func_t recomp_lookup_kernel(uint32_t xbox_va);
recomp_func_t recomp_lookup_manual(uint32_t xbox_va);
#endif

/**
 * Indirect call through the dispatch table.
 * Looks up the Xbox VA and calls the translated function.
 * Falls back to kernel bridge for kernel thunk synthetic VAs.
 * The caller must PUSH32 a dummy return address before this macro.
 * If not found, pop the dummy return address to keep the stack balanced.
 */
#define RECOMP_ICALL(xbox_va) do { \
    uint32_t _va = (uint32_t)(xbox_va); \
    g_icall_trace[g_icall_trace_idx & (ICALL_TRACE_SIZE-1)] = _va; \
    g_icall_trace_idx++; \
    g_icall_count++; \
    /* Try native pointer → Xbox VA conversion for addresses in mapped region. \
     * RW engine stores native heap pointers in Xbox memory; when code reads \
     * them back and uses as function addresses, they're native addresses \
     * pointing into our memory mirrors. Convert back to Xbox VA. */ \
    if (_va >= 0x00400000 && _va < 0xFE000000) { \
        uint32_t _off32 = (uint32_t)g_xbox_mem_offset; \
        int _resolved = 0; \
        /* Function pointers converted back must lie in the FIRST 64MB \
         * window (where XBOX_PTR-produced pointers live). The old \
         * modulo-any-mirror mapping let arbitrary garbage dwords (e.g. \
         * ASCII string bytes read via a wrong struct offset) alias onto \
         * real function starts and get CALLED with junk registers. */ \
        if (_off32 != 0 && _va >= _off32 && (_va - _off32) < 0x04000000u) { \
            uint32_t _xva = _va - _off32; \
            if (_xva >= 0x00011000 && _xva < 0x0106DAE0) { \
                _va = _xva; _resolved = 1; \
            } \
        } \
        if (!_resolved) { g_esp += 4; eax = 0; break; } \
    } \
    recomp_func_t _fn = recomp_lookup_manual(_va); \
    if (!_fn) _fn = recomp_lookup(_va); \
    if (!_fn) _fn = recomp_lookup_kernel(_va); \
    if (_fn) _fn(); \
    else { extern void recomp_icall_fail_log(uint32_t va); \
           recomp_icall_fail_log(_va); g_esp += 4; eax = 0; } \
} while(0)

/**
 * Stack-safe indirect call.
 * Restores g_esp to saved_esp (pre-arg value) on lookup failure,
 * preventing stdcall argument leaks on failed vtable calls.
 */
extern volatile int g_fib_slice_due;
void xbox_fiber_timeslice(void);
/* Loop back-edge slice point (tools/recomp/fix_slicepoints.py). */
#define RECOMP_SLICE_POINT() do { if (g_fib_slice_due) xbox_fiber_timeslice(); } while (0)
#define RECOMP_ICALL_SAFE(xbox_va, saved_esp) do { \
    uint32_t _va = (uint32_t)(xbox_va); \
    /* worker-thread scheduling point (xbox_fiber_timeslice): the game thread
     * can spend seconds without a kernel call while it loads a scene. */ \
    if (g_fib_slice_due) xbox_fiber_timeslice(); \
    g_icall_trace[g_icall_trace_idx & (ICALL_TRACE_SIZE-1)] = _va; \
    g_icall_trace_idx++; \
    g_icall_count++; \
    /* Reject IEEE 754 floats misread as function pointers. \
     * Common garbage: 0x3F800000 (1.0), 0x3C23D70A (0.01), 0x40000000 (2.0). \
     * Native Xbox VAs are 0x10011000-0x14000000 (exp ~32-40 after offset). \
     * Use exponent >= 50 to avoid false positives on native mirror addresses. \
     * Covers float range ~1e-22 to ~1e38 = all typical game data floats. */ \
    { uint32_t _exp = (_va >> 23) & 0xFF; \
      if (_exp >= 50 && _exp <= 200) { \
        g_esp += 4; eax = 0; break; \
      } \
    } \
    if (_va >= 0x00400000 && _va < 0xFE000000) { \
        uint32_t _off32 = (uint32_t)g_xbox_mem_offset; \
        int _resolved = 0; \
        /* Function pointers converted back must lie in the FIRST 64MB \
         * window (where XBOX_PTR-produced pointers live). The old \
         * modulo-any-mirror mapping let arbitrary garbage dwords (e.g. \
         * ASCII string bytes read via a wrong struct offset) alias onto \
         * real function starts and get CALLED with junk registers. */ \
        if (_off32 != 0 && _va >= _off32 && (_va - _off32) < 0x04000000u) { \
            uint32_t _xva = _va - _off32; \
            if (_xva >= 0x00011000 && _xva < 0x0106DAE0) { \
                _va = _xva; _resolved = 1; \
            } \
        } \
        if (!_resolved) { g_esp += 4; eax = 0; break; } \
    } \
    recomp_func_t _fn = recomp_lookup_manual(_va); \
    if (!_fn) _fn = recomp_lookup(_va); \
    if (!_fn) _fn = recomp_lookup_kernel(_va); \
    if (_fn) _fn(); \
    else { extern void recomp_icall_fail_log(uint32_t va); \
           recomp_icall_fail_log(_va); g_esp += 4; eax = 0; } \
} while(0)

/**
 * Indirect tail call (jmp through function pointer).
 * No return address is pushed - reuses the current frame's return addr.
 */
#define RECOMP_ITAIL(xbox_va) do { \
    g_icall_trace[g_icall_trace_idx & (ICALL_TRACE_SIZE-1)] = 0xEE000000u | ((uint32_t)(xbox_va) & 0x00FFFFFFu); \
    g_icall_trace_idx++; \
    recomp_func_t _fn = recomp_lookup_manual((uint32_t)(xbox_va)); \
    if (!_fn) _fn = recomp_lookup((uint32_t)(xbox_va)); \
    if (!_fn) _fn = recomp_lookup_kernel((uint32_t)(xbox_va)); \
    if (_fn) _fn(); \
    else { \
        /* Unresolved tail-jump: the emitted pattern is "RECOMP_ITAIL(x); \
         * return;" and the missing target would have consumed the fake \
         * return slot with its own "esp += 4; ret". Without this the \
         * caller leaks -4 esp per failed tail-jump (same class as the \
         * RECOMP_ICALL_SAFE cdecl-cleanup bug, NOTES.md "Runtime Architecture"). */ \
        extern void recomp_itail_fail_log(uint32_t va); \
        recomp_itail_fail_log((uint32_t)(xbox_va)); \
        g_esp += 4; \
    } \
} while(0)

/* ── Register name aliases for generated code ──────────── */

/**
 * Map x86 volatile register names to global variables.
 * These #defines allow the generated code to use natural register
 * names (eax, ecx, edx, esp) which the preprocessor maps to the
 * corresponding globals (g_eax, g_ecx, g_edx, g_esp).
 *
 * Only active when RECOMP_GENERATED_CODE is defined (in generated
 * .c files) to avoid polluting hand-written code.
 */
#ifdef RECOMP_GENERATED_CODE
#define eax g_eax
#define ecx g_ecx
#define edx g_edx
#define esp g_esp
#define ebx g_ebx
#define esi g_esi
#define edi g_edi
/* ebp is NOT global - it's local in each function.
 * For __SEH_prolog/epilog, use g_seh_ebp to bridge. */
#endif


/* ── MMX (64-bit integer SIMD) helpers — recomp bug #11 ────
 * The Sofdec movie decoder's IDCT/color-convert kernels are MMX; the lifter
 * used to drop every MMX instruction as a comment, so decode produced
 * garbage (NaN storms + wild blit pointers). MM registers are per-function
 * uint64_t locals (declared by the translator); these helpers implement the
 * lane arithmetic. Lanes are little-endian: lane 0 = bits 0..15. */
#define MMQ_LOAD(a)     ((uint64_t)MEM32(a) | ((uint64_t)MEM32((a) + 4) << 32))
#define MMQ_STORE(a, v) do { uint64_t _q = (v); MEM32(a) = (uint32_t)_q; \
                             MEM32((a) + 4) = (uint32_t)(_q >> 32); } while (0)

static __inline uint64_t mmx_paddw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        uint16_t x = (uint16_t)(a >> (i*16)), y = (uint16_t)(b >> (i*16));
        r |= (uint64_t)(uint16_t)(x + y) << (i*16);
    } return r;
}
static __inline uint64_t mmx_psubw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        uint16_t x = (uint16_t)(a >> (i*16)), y = (uint16_t)(b >> (i*16));
        r |= (uint64_t)(uint16_t)(x - y) << (i*16);
    } return r;
}
static __inline uint64_t mmx_pavgb(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 8; i++) {
        uint16_t x = (uint8_t)(a >> (i*8)), y = (uint8_t)(b >> (i*8));
        r |= (uint64_t)(uint8_t)((x + y + 1) >> 1) << (i*8);
    } return r;
}
static __inline uint64_t mmx_pmullw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        int32_t p = (int32_t)(int16_t)(a >> (i*16)) * (int32_t)(int16_t)(b >> (i*16));
        r |= (uint64_t)(uint16_t)p << (i*16);
    } return r;
}
static __inline uint64_t mmx_pmulhw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        int32_t p = (int32_t)(int16_t)(a >> (i*16)) * (int32_t)(int16_t)(b >> (i*16));
        r |= (uint64_t)(uint16_t)(p >> 16) << (i*16);
    } return r;
}
static __inline uint64_t mmx_psraw(uint64_t a, uint32_t n) {
    uint64_t r = 0; int i; if (n > 15) n = 15;
    for (i = 0; i < 4; i++)
        r |= (uint64_t)(uint16_t)((int16_t)(uint16_t)(a >> (i*16)) >> n) << (i*16);
    return r;
}
static __inline uint64_t mmx_psllw(uint64_t a, uint32_t n) {
    uint64_t r = 0; int i; if (n > 15) return 0;
    for (i = 0; i < 4; i++)
        r |= (uint64_t)(uint16_t)((uint16_t)(a >> (i*16)) << n) << (i*16);
    return r;
}
static __inline uint64_t mmx_psrad(uint64_t a, uint32_t n) {
    if (n > 31) n = 31;
    return (uint64_t)(uint32_t)((int32_t)(uint32_t)a >> n)
         | ((uint64_t)(uint32_t)((int32_t)(uint32_t)(a >> 32) >> n) << 32);
}
static __inline uint64_t mmx_punpcklwd(uint64_t a, uint64_t b) {
    return  (uint64_t)(uint16_t)(a)
         | ((uint64_t)(uint16_t)(b)        << 16)
         | ((uint64_t)(uint16_t)(a >> 16)  << 32)
         | ((uint64_t)(uint16_t)(b >> 16)  << 48);
}
static __inline uint64_t mmx_punpckhwd(uint64_t a, uint64_t b) {
    return  (uint64_t)(uint16_t)(a >> 32)
         | ((uint64_t)(uint16_t)(b >> 32)  << 16)
         | ((uint64_t)(uint16_t)(a >> 48)  << 32)
         | ((uint64_t)(uint16_t)(b >> 48)  << 48);
}
static __inline uint64_t mmx_punpcklbw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        r |= (uint64_t)(uint8_t)(a >> (i*8)) << (i*16);
        r |= (uint64_t)(uint8_t)(b >> (i*8)) << (i*16 + 8);
    } return r;
}
static __inline uint64_t mmx_punpckhbw(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        r |= (uint64_t)(uint8_t)(a >> (32 + i*8)) << (i*16);
        r |= (uint64_t)(uint8_t)(b >> (32 + i*8)) << (i*16 + 8);
    } return r;
}
static __inline uint16_t mmx_sat_dw(int32_t v) {
    return (uint16_t)(v > 32767 ? 32767 : (v < -32768 ? -32768 : v));
}
static __inline uint64_t mmx_packssdw(uint64_t a, uint64_t b) {
    return  (uint64_t)mmx_sat_dw((int32_t)(uint32_t)a)
         | ((uint64_t)mmx_sat_dw((int32_t)(uint32_t)(a >> 32)) << 16)
         | ((uint64_t)mmx_sat_dw((int32_t)(uint32_t)b)         << 32)
         | ((uint64_t)mmx_sat_dw((int32_t)(uint32_t)(b >> 32)) << 48);
}
static __inline uint8_t mmx_sat_ub(int16_t v) {
    return (uint8_t)(v > 255 ? 255 : (v < 0 ? 0 : v));
}
static __inline uint64_t mmx_packuswb(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        r |= (uint64_t)mmx_sat_ub((int16_t)(uint16_t)(a >> (i*16))) << (i*8);
        r |= (uint64_t)mmx_sat_ub((int16_t)(uint16_t)(b >> (i*16))) << (32 + i*8);
    } return r;
}


/* MMX ops used by the DOA2U Sofdec decoder (MWSFD 3.18) and DSP code. */
#define MMX_LANES16(expr) do { int i; for (i = 0; i < 4; i++) {     uint16_t x = (uint16_t)(a >> (i*16)), y = (uint16_t)(b >> (i*16)); (void)x; (void)y;     r |= (uint64_t)(uint16_t)(expr) << (i*16); } } while (0)
static __inline uint64_t mmx_paddd(uint64_t a, uint64_t b) {
    return (uint64_t)(uint32_t)((uint32_t)a + (uint32_t)b) |
           ((uint64_t)(uint32_t)((uint32_t)(a >> 32) + (uint32_t)(b >> 32)) << 32);
}
static __inline uint64_t mmx_psubd(uint64_t a, uint64_t b) {
    return (uint64_t)(uint32_t)((uint32_t)a - (uint32_t)b) |
           ((uint64_t)(uint32_t)((uint32_t)(a >> 32) - (uint32_t)(b >> 32)) << 32);
}
static __inline uint64_t mmx_paddusw(uint64_t a, uint64_t b) {
    uint64_t r = 0; MMX_LANES16((uint32_t)x + y > 0xFFFF ? 0xFFFF : x + y); return r;
}
static __inline uint64_t mmx_paddusb(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 8; i++) {
        unsigned v = (unsigned)(uint8_t)(a >> (i*8)) + (uint8_t)(b >> (i*8));
        r |= (uint64_t)(v > 255 ? 255 : v) << (i*8);
    } return r;
}
static __inline uint64_t mmx_pminsw(uint64_t a, uint64_t b) {
    uint64_t r = 0; MMX_LANES16((int16_t)x < (int16_t)y ? x : y); return r;
}
static __inline uint64_t mmx_pmaxsw(uint64_t a, uint64_t b) {
    uint64_t r = 0; MMX_LANES16((int16_t)x > (int16_t)y ? x : y); return r;
}
static __inline uint64_t mmx_pavgw(uint64_t a, uint64_t b) {
    uint64_t r = 0; MMX_LANES16(((uint32_t)x + y + 1) >> 1); return r;
}
static __inline uint64_t mmx_pcmpeqw(uint64_t a, uint64_t b) {
    uint64_t r = 0; MMX_LANES16(x == y ? 0xFFFF : 0); return r;
}
static __inline uint64_t mmx_pcmpeqd(uint64_t a, uint64_t b) {
    return (((uint32_t)a == (uint32_t)b) ? 0xFFFFFFFFull : 0) |
           (((uint32_t)(a >> 32) == (uint32_t)(b >> 32)) ? 0xFFFFFFFF00000000ull : 0);
}
static __inline uint64_t mmx_pmaddwd(uint64_t a, uint64_t b) {
    int32_t lo = (int32_t)(int16_t)a * (int16_t)b + (int32_t)(int16_t)(a >> 16) * (int16_t)(b >> 16);
    int32_t hi = (int32_t)(int16_t)(a >> 32) * (int16_t)(b >> 32) +
                 (int32_t)(int16_t)(a >> 48) * (int16_t)(b >> 48);
    return (uint64_t)(uint32_t)lo | ((uint64_t)(uint32_t)hi << 32);
}
static __inline uint64_t mmx_punpckldq(uint64_t a, uint64_t b) {
    return (uint64_t)(uint32_t)a | ((uint64_t)(uint32_t)b << 32);
}
static __inline uint64_t mmx_punpckhdq(uint64_t a, uint64_t b) {
    return (a >> 32) | (b & 0xFFFFFFFF00000000ull);
}
static __inline int8_t mmx_sat_sb(int16_t v) {
    return (int8_t)(v > 127 ? 127 : (v < -128 ? -128 : v));
}
static __inline uint64_t mmx_packsswb(uint64_t a, uint64_t b) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) {
        r |= (uint64_t)(uint8_t)mmx_sat_sb((int16_t)(uint16_t)(a >> (i*16))) << (i*8);
        r |= (uint64_t)(uint8_t)mmx_sat_sb((int16_t)(uint16_t)(b >> (i*16))) << (32 + i*8);
    } return r;
}
static __inline uint64_t mmx_psrlw(uint64_t a, uint32_t n) {
    uint64_t r = 0; int i; if (n > 15) return 0;
    for (i = 0; i < 4; i++) r |= (uint64_t)(uint16_t)((uint16_t)(a >> (i*16)) >> n) << (i*16);
    return r;
}
static __inline uint64_t mmx_psrld(uint64_t a, uint32_t n) {
    if (n > 31) return 0;
    return (uint64_t)((uint32_t)a >> n) | ((uint64_t)((uint32_t)(a >> 32) >> n) << 32);
}
static __inline uint64_t mmx_pslld(uint64_t a, uint32_t n) {
    if (n > 31) return 0;
    return (uint64_t)(uint32_t)((uint32_t)a << n) | ((uint64_t)(uint32_t)((uint32_t)(a >> 32) << n) << 32);
}
static __inline uint64_t mmx_psrlq(uint64_t a, uint32_t n) { return n > 63 ? 0 : a >> n; }
static __inline uint64_t mmx_psllq(uint64_t a, uint32_t n) { return n > 63 ? 0 : a << n; }
static __inline uint64_t mmx_pshufw(uint64_t a, uint32_t imm) {
    uint64_t r = 0; int i;
    for (i = 0; i < 4; i++) r |= ((a >> (((imm >> (i*2)) & 3) * 16)) & 0xFFFF) << (i*16);
    return r;
}
static __inline uint64_t mmx_pinsrw(uint64_t a, uint32_t v, uint32_t lane) {
    a &= ~(0xFFFFull << (lane*16)); return a | ((uint64_t)(uint16_t)v << (lane*16));
}
static __inline uint32_t mmx_pmovmskb(uint64_t a) {
    uint32_t r = 0; int i; for (i = 0; i < 8; i++) r |= ((uint32_t)(a >> (i*8 + 7)) & 1) << i;
    return r;
}

/* ── Forward declarations for translated functions ──────── */
/* These are generated by the recompiler and included per-file. */

#endif /* RECOMP_TYPES_H */
