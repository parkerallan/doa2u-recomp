/**
 * Dead or Alive 3 - Recompiled code chunk 23
 * Functions: 547 (0x003B51E2 - 0x003C146C)
 */

#define RECOMP_GENERATED_CODE
#include "recomp_funcs.h"
#include <math.h>

/**
 * sub_003B51E2
 * Original: 0x003B51E2 - 0x003B51ED (11 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B51E2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B51E2: ;
    if (TEST_NZ(ecx, ecx)) { g_seh_ebp = ebp; sub_003B51ED(); return; } /* jne: not equal / not zero */

loc_003B51E6: ;
    eax = 0x80150005u;
    g_seh_ebp = ebp; sub_003B520B(); return; /* tail jmp 0x003B520B */

}

/**
 * sub_003B51ED
 * Original: 0x003B51ED - 0x003B520B (30 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B51ED(void)
{
    int _flags = 0; /* fallback flag var */

loc_003B51ED: ;
    eax = MEM32(esp + 4);
    if (CMP_NE(MEM32(eax + 0x10), 9)) goto loc_003B5208; /* jne: not equal / not zero */

loc_003B51F7: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = eax + 0x57C;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    POP32(esp, edi);
    POP32(esp, esi);

loc_003B5208: ;
    eax = MEM32(eax + 0x14);

    sub_003B520B(); return; /* restored dropped fall-through to sub_003B520B */
}

/**
 * sub_003B520B
 * Original: 0x003B520B - 0x003B5278 (109 bytes, 51 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B520B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B520B: ;
    esp += 12; return; /* ret 8 */

    PUSH32(esp, edi);
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B5227: ;
    /* cmp eax, ebx - flags set for next jcc */
    POP32(esp, ecx);
    POP32(esp, ecx);
    if (CMP_BE(eax, ebx)) goto loc_003B5231; /* jbe: below or equal (unsigned <=) */

loc_003B522D: ;
    eax = 0; /* xor self */
    goto loc_003B526E;

loc_003B5231: ;
    PUSH32(esp, ebp);
    goto loc_003B5256;

loc_003B5234: ;
    SET_LO16(ebx, MEM16(esi));
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00337F7F(); /* call 0x00337F7F */

loc_003B5242: ;
    PUSH32(esp, ebx);
    SET_LO16(ebp, LO16(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00337F7F(); /* call 0x00337F7F */

loc_003B524B: ;
    edi++;
    edi++;
    esi++;
    POP32(esp, ecx);
    esi++;
    /* cmp LO16(eax), LO16(ebp) - flags set for next jcc */
    POP32(esp, ecx);
    if (CMP_NE(LO16(eax), LO16(ebp))) goto loc_003B5274; /* jne: not equal / not zero */

loc_003B5256: ;
    if (CMP_NE(MEM16(edi), 0)) { RECOMP_SLICE_POINT(); goto loc_003B5234; } /* jne: not equal / not zero */

loc_003B525C: ;
    SET_LO16(esi, MEM16(esi));
    if (TEST_Z(LO16(esi), LO16(esi))) goto loc_003B526A; /* je: equal / zero */

loc_003B5264: ;
    if (CMP_NE(LO16(esi), 0x2E)) goto loc_003B5274; /* jne: not equal / not zero */

loc_003B526A: ;
    eax = 0; /* xor self */
    eax++;

loc_003B526D: ;
    POP32(esp, ebp);

loc_003B526E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003B5274: ;
    eax = 0; /* xor self */
    { RECOMP_SLICE_POINT(); goto loc_003B526D; }

}

/**
 * sub_003B520E
 * Original: 0x003B520E - 0x003B5278 (106 bytes, 50 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B520E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B520E: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B521F: ;
    PUSH32(esp, edi);
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B5227: ;
    /* cmp eax, ebx - flags set for next jcc */
    POP32(esp, ecx);
    POP32(esp, ecx);
    if (CMP_BE(eax, ebx)) goto loc_003B5231; /* jbe: below or equal (unsigned <=) */

loc_003B522D: ;
    eax = 0; /* xor self */
    goto loc_003B526E;

loc_003B5231: ;
    PUSH32(esp, ebp);
    goto loc_003B5256;

loc_003B5234: ;
    SET_LO16(ebx, MEM16(esi));
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00337F7F(); /* call 0x00337F7F */

loc_003B5242: ;
    PUSH32(esp, ebx);
    SET_LO16(ebp, LO16(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00337F7F(); /* call 0x00337F7F */

loc_003B524B: ;
    edi++;
    edi++;
    esi++;
    POP32(esp, ecx);
    esi++;
    /* cmp LO16(eax), LO16(ebp) - flags set for next jcc */
    POP32(esp, ecx);
    if (CMP_NE(LO16(eax), LO16(ebp))) goto loc_003B5274; /* jne: not equal / not zero */

loc_003B5256: ;
    if (CMP_NE(MEM16(edi), 0)) { RECOMP_SLICE_POINT(); goto loc_003B5234; } /* jne: not equal / not zero */

loc_003B525C: ;
    SET_LO16(esi, MEM16(esi));
    if (TEST_Z(LO16(esi), LO16(esi))) goto loc_003B526A; /* je: equal / zero */

loc_003B5264: ;
    if (CMP_NE(LO16(esi), 0x2E)) goto loc_003B5274; /* jne: not equal / not zero */

loc_003B526A: ;
    eax = 0; /* xor self */
    eax++;

loc_003B526D: ;
    POP32(esp, ebp);

loc_003B526E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003B5274: ;
    eax = 0; /* xor self */
    { RECOMP_SLICE_POINT(); goto loc_003B526D; }

}

/**
 * sub_003B5278
 * Original: 0x003B5278 - 0x003B52AA (50 bytes, 21 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5278(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5278: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, esi);
    eax = eax + 2;
    PUSH32(esp, 0x2F);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0033611C(); /* call 0x0033611C */

loc_003B5288: ;
    esi = eax;
    esi++;
    esi++;
    PUSH32(esp, 0x2F);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0033611C(); /* call 0x0033611C */

loc_003B5294: ;
    eax = eax - esi;
    eax = (uint32_t)((int32_t)eax >> 1);
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(esp + 0x24));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003361EA(); /* call 0x003361EA */

loc_003B52A3: ;
    esp = esp + 0x1C;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B52AA
 * Original: 0x003B52AA - 0x003B5740 (1174 bytes, 349 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B52AA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    xmm128_t xmm7;
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B52AA: ;
    PUSH32(esp, ebp);
    ebp = esp + -116;
    esp = esp - 0xA4;
    MEM32(ebp + 0x70) = MEM32(ebp + 0x70) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 0x7C);
    eax = MEM32(ebx + 0x10);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 9);
    POP32(esp, edi);
    /* cmp eax, edi - flags set for next jcc */
    esi = ecx;
    MEM32(ebp + 0x6C) = esi;
    if (CMP_A(eax, edi)) goto loc_003B570B; /* ja: above (unsigned >) */

loc_003B52D2: ;
    { uint32_t _jt = MEM32(eax * 4 + 0x3B5718); /* switch: 10 entries, 9 targets */
    if (_jt == 0x003B52D9u) goto loc_003B52D9;
    if (_jt == 0x003B531Cu) goto loc_003B531C;
    if (_jt == 0x003B550Fu) goto loc_003B550F;
    if (_jt == 0x003B557Fu) goto loc_003B557F;
    if (_jt == 0x003B55F3u) goto loc_003B55F3;
    if (_jt == 0x003B5685u) goto loc_003B5685;
    if (_jt == 0x003B56A9u) goto loc_003B56A9;
    if (_jt == 0x003B56D4u) goto loc_003B56D4;
    if (_jt == 0x003B5705u) goto loc_003B5705;
    g_seh_ebp = ebp; RECOMP_ITAIL(_jt); return; }

loc_003B52D9: ;
    PUSH32(esp, MEM32(ebx + 0x4F8));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0039C7AF(); /* call 0x0039C7AF */

loc_003B52E6: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B570B; /* je: equal / zero */

loc_003B52F1: ;
    if (CMP_GE(eax & eax, 0)) goto loc_003B5304; /* jge: greater or equal (signed >=) */

loc_003B52F5: ;
    MEM32(ebx + 0x14) = eax;
    MEM32(ebx + 0x10) = 8;
    goto loc_003B570B;

loc_003B5304: ;
    MEM32(ebx + 0x10) = 1;

loc_003B530B: ;
    PUSH32(esp, MEM32(ebx + 8));
    MEM32(ebp + 0x70) = MEM32(ebp + 0x70) & 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BB64F(); /* call 0x002BB64F */

loc_003B5317: ;
    goto loc_003B570B;

loc_003B531C: ;
    PUSH32(esp, 0x25);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    edi = ebp + -48;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = ebp + 0x64;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002B8FAE(); /* call 0x002B8FAE */

loc_003B532F: ;
    MEM32(ebp + 0x7C) = MEM32(ebp + 0x7C) & 0;
    PUSH32(esp, 0x3B520E);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A83F8(); /* call 0x003A83F8 */

loc_003B5345: ;
    eax = ebx + 0x590;
    edi = ebx + 0x4FC;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    MEM32(ebx + 0x61C) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003364CE(); /* call 0x003364CE */

loc_003B535E: ;
    POP32(esp, ecx);
    POP32(esp, ecx);
    eax = ebx + 0x614;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9BFD(); /* call 0x003A9BFD */

loc_003B5374: ;
    goto loc_003B53DB;

loc_003B5376: ;
    eax = ebp + 0x64;
    PUSH32(esp, eax);
    eax = ebx + 0x588;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002B8B0C(); /* call 0x002B8B0C */

loc_003B5386: ;
    if (CMP_LE(eax & eax, 0)) goto loc_003B5423; /* jle: less or equal (signed <=) */

loc_003B538E: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B5394: ;
    esi = eax;
    eax = ebp + -48;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B539F: ;
    /* cmp eax, esi - flags set for next jcc */
    POP32(esp, ecx);
    POP32(esp, ecx);
    if (CMP_AE(eax, esi)) goto loc_003B53AF; /* jae: above or equal (unsigned >=) */

loc_003B53A5: ;
    PUSH32(esp, 0x25);
    esi = edi;
    POP32(esp, ecx);
    edi = ebp + -48;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */

loc_003B53AF: ;
    esi = MEM32(ebp + 0x6C);

loc_003B53B2: ;
    eax = ebx + 0x590;
    PUSH32(esp, eax);
    edi = ebx + 0x4FC;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003364CE(); /* call 0x003364CE */

loc_003B53C5: ;
    POP32(esp, ecx);
    POP32(esp, ecx);
    eax = ebx + 0x614;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9C5F(); /* call 0x003A9C5F */

loc_003B53DB: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (TEST_S(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003B52F5; } /* jl: less (signed <) */

loc_003B53E6: ;
    if (CMP_NE(MEM32(ebx + 0x614), 0)) { RECOMP_SLICE_POINT(); goto loc_003B5376; } /* jne: not equal / not zero */

loc_003B53EF: ;
    eax = ebp + -48;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336227(); /* call 0x00336227 */

loc_003B53F8: ;
    /* test eax, eax - flags set for next jcc */
    POP32(esp, ecx);
    if (CMP_BE(eax & eax, 0)) goto loc_003B542C; /* jbe: below or equal (unsigned <=) */

loc_003B53FD: ;
    PUSH32(esp, MEM32(ebx + 8));
    MEM32(ebp + 0x70) = MEM32(ebp + 0x70) & 0;
    MEM32(ebx + 0x10) = 6;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BB64F(); /* call 0x002BB64F */

loc_003B5410: ;
    PUSH32(esp, 0x25);
    edi = ebx + 0x57C;
    POP32(esp, ecx);
    esi = ebp + 0x50;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    esi = MEM32(ebp + 0x6C);
    goto loc_003B5461;

loc_003B5423: ;
    MEM32(ebp + 0x7C) = 1;
    { RECOMP_SLICE_POINT(); goto loc_003B53B2; }

loc_003B542C: ;
    PUSH32(esp, 0x50);
    PUSH32(esp, 0x150);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB73F(); /* call 0x003AB73F */

loc_003B543A: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebx + 0xC) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003B544E; /* jne: not equal / not zero */

loc_003B5441: ;
    eax = 0x8007000Eu;
    MEM32(ebx + 0x14) = eax;
    goto loc_003B5708;

loc_003B544E: ;
    PUSH32(esp, MEM32(ebx + 8));
    MEM32(ebp + 0x70) = MEM32(ebp + 0x70) & 0;
    MEM32(ebx + 0x10) = 2;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BB64F(); /* call 0x002BB64F */

loc_003B5461: ;
    if (CMP_EQ(MEM32(ebp + 0x7C), 0)) goto loc_003B570B; /* je: equal / zero */

loc_003B546B: ;
    PUSH32(esp, 0x25);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    PUSH32(esp, 0x3B520E);
    PUSH32(esp, MEM32(ebx + 0x610));
    edi = ebp + -48;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A83F8(); /* call 0x003A83F8 */

loc_003B5487: ;
    eax = ebp + -48;
    MEM32(ebx + 0x61C) = eax;
    eax = ebx + 0x590;
    PUSH32(esp, eax);
    eax = ebp + -48;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003364CE(); /* call 0x003364CE */

loc_003B54A0: ;
    POP32(esp, ecx);
    POP32(esp, ecx);
    edi = ebx + 0x614;
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9BFD(); /* call 0x003A9BFD */

loc_003B54B6: ;
    goto loc_003B5503;

loc_003B54B8: ;
    if (CMP_EQ(MEM32(edi), 0)) goto loc_003B570B; /* je: equal / zero */

loc_003B54C1: ;
    eax = ebp + 0x64;
    PUSH32(esp, eax);
    eax = ebx + 0x588;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002B8B0C(); /* call 0x002B8B0C */

loc_003B54D1: ;
    if (CMP_GE(eax & eax, 0)) goto loc_003B54E3; /* jge: greater or equal (signed >=) */

loc_003B54D5: ;
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9CB2(); /* call 0x003A9CB2 */

loc_003B54E3: ;
    eax = ebx + 0x590;
    PUSH32(esp, eax);
    eax = ebp + -48;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003364CE(); /* call 0x003364CE */

loc_003B54F3: ;
    POP32(esp, ecx);
    POP32(esp, ecx);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebx + 0x610));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9C5F(); /* call 0x003A9C5F */

loc_003B5503: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (CMP_GE(eax & eax, 0)) { RECOMP_SLICE_POINT(); goto loc_003B54B8; } /* jge: greater or equal (signed >=) */

loc_003B550A: ;
    goto loc_003B570B;

loc_003B550F: ;
    eax = ebx + 0x590;
    PUSH32(esp, eax);
    eax = ebx + 0x22;
    PUSH32(esp, eax);
    edi = ebx + 0x20;
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A43BE(); /* call 0x003A43BE */

loc_003B5525: ;
    ecx = ZX16(MEM16(edi));
    eax = 0; /* xor self */
    PUSH32(esp, eax);
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebx + 0xC));
    ecx++;
    PUSH32(esp, MEM32(ebx + 8));
    ecx++;
    PUSH32(esp, 0xEA60);
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(0x1069884));
    ecx = ebx + 0xDF;
    PUSH32(esp, MEM32(0x1069880));
    PUSH32(esp, 0x416);
    PUSH32(esp, ecx);
    PUSH32(esp, 0x10698B8);
    PUSH32(esp, eax);
    PUSH32(esp, 0xE);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A412A(); /* call 0x003A412A */

loc_003B5562: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (CMP_GE(eax & eax, 0)) goto loc_003B5573; /* jge: greater or equal (signed >=) */

loc_003B5569: ;
    MEM32(ebx + 0x14) = eax;
    MEM32(ebx + 0x10) = 8;

loc_003B5573: ;
    MEM32(ebx + 0x10) = 3;
    goto loc_003B570B;

loc_003B557F: ;
    PUSH32(esp, MEM32(ebx + 0xC));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0039C7AF(); /* call 0x0039C7AF */

loc_003B5589: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B570B; /* je: equal / zero */

loc_003B5594: ;
    if (CMP_EQ(eax, 0x1500F0)) goto loc_003B55AA; /* je: equal / zero */

loc_003B559B: ;
    MEM32(ebx + 0x10) = 8;
    MEM32(ebx + 0x14) = eax;
    goto loc_003B570B;

loc_003B55AA: ;
    eax = 0; /* xor self */
    PUSH32(esp, 0x25);
    POP32(esp, ecx);
    edi = ebx + 0x4FC;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    /* cmp MEM32(ebx + 0x610), 0 - flags set for next jcc */
    eax = MEM32(ebx + 0xEB);
    esi = ebx + 0xDF;
    edi = ebx + 0x57C;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(ebx + 0x588) = eax;
    eax = MEM32(ebx + 0xEF);
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(ebx + 0x58C) = eax;
    if (CMP_EQ(MEM32(ebx + 0x610), 0)) goto loc_003B5665; /* je: equal / zero */

loc_003B55E7: ;
    MEM32(ebx + 0x10) = 4;
    { RECOMP_SLICE_POINT(); goto loc_003B530B; }

loc_003B55F3: ;
    PUSH32(esp, 0x3F);
    eax = ebx + 0x4FC;
    PUSH32(esp, eax);
    eax = ZX16(MEM16(ebx + 0xF3));
    PUSH32(esp, eax);
    eax = ebx + 0xF5;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0xFDE9);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BAFD0(); /* call 0x002BAFD0 */

loc_003B5617: ;
    if (TEST_NZ(eax, eax)) goto loc_003B5633; /* jne: not equal / not zero */

loc_003B561B: ;
    if (CMP_EQ(MEM16(ebx + 0xF3), LO16(eax))) goto loc_003B5633; /* je: equal / zero */

loc_003B5624: ;
    MEM32(ebx + 0x14) = 0x1500F1;
    MEM32(ebx + 0x10) = edi;
    goto loc_003B570B;

loc_003B5633: ;
    PUSH32(esp, 0);
    edi = ebx + 0x610;
    PUSH32(esp, MEM32(edi));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A83F8(); /* call 0x003A83F8 */

loc_003B5644: ;
    PUSH32(esp, 1);
    PUSH32(esp, 0);
    eax = ebx + 0x4FC;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebx + 0x4F8));
    ecx = esi;
    PUSH32(esp, MEM32(edi));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AA867(); /* call 0x003AA867 */

loc_003B565E: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (CMP_GE(eax & eax, 0)) goto loc_003B5679; /* jge: greater or equal (signed >=) */

loc_003B5665: ;
    eax = 0x1500F1;
    MEM32(ebx + 0x14) = eax;
    MEM32(ebx + 0x10) = 9;
    goto loc_003B5708;

loc_003B5679: ;
    MEM32(ebx + 0x10) = 5;
    goto loc_003B570B;

loc_003B5685: ;
    PUSH32(esp, MEM32(ebx + 0x4F8));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0039C7AF(); /* call 0x0039C7AF */

loc_003B5692: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B570B; /* je: equal / zero */

loc_003B5699: ;
    if (TEST_S(eax, eax)) goto loc_003B56C0; /* jl: less (signed <) */

loc_003B569D: ;
    MEM32(ebx + 0x10) = 6;
    { RECOMP_SLICE_POINT(); goto loc_003B530B; }

loc_003B56A9: ;
    PUSH32(esp, MEM32(ebx + 0x4F8));
    ecx = esi;
    PUSH32(esp, MEM32(ebx + 0x610));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003A9D08(); /* call 0x003A9D08 */

loc_003B56BC: ;
    if (CMP_GE(eax & eax, 0)) goto loc_003B56CD; /* jge: greater or equal (signed >=) */

loc_003B56C0: ;
    eax = 0x1500F1;
    MEM32(ebx + 0x14) = eax;
    MEM32(ebx + 0x10) = edi;
    goto loc_003B5708;

loc_003B56CD: ;
    MEM32(ebx + 0x10) = 7;

loc_003B56D4: ;
    PUSH32(esp, MEM32(ebx + 0x4F8));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0039C7AF(); /* call 0x0039C7AF */

loc_003B56E1: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x70) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B570B; /* je: equal / zero */

loc_003B56E8: ;
    /* cmp MEM32(ebp + 0x70), 0 - flags set for next jcc */
    eax = 0x1500F1;
    MEM32(ebx + 0x10) = edi;
    MEM32(ebx + 0x14) = eax;
    MEM32(ebp + 0x70) = eax;
    if (CMP_L(MEM32(ebp + 0x70), 0)) goto loc_003B570B; /* jl: less (signed <) */

loc_003B56FC: ;
    MEM32(ebx + 0x610) = MEM32(ebx + 0x610) & 0;
    goto loc_003B570B;

loc_003B5705: ;
    eax = MEM32(ebx + 0x14);

loc_003B5708: ;
    MEM32(ebp + 0x70) = eax;

loc_003B570B: ;
    eax = MEM32(ebp + 0x70);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    ebp = ebp + 0x74;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
}

/**
 * sub_003B5740
 * Original: 0x003B5740 - 0x003B578B (75 bytes, 33 insns)
 * Category: game_network
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5740(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B5740: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    eax = ebp + 8;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF);
    PUSH32(esp, MEM32(ebp + 8));
    esi = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003810F2(); /* call 0x003810F2 */

loc_003B5755: ;
    edi = eax;
    if (TEST_NZ(edi, edi)) goto loc_003B5783; /* jne: not equal / not zero */

loc_003B575B: ;
    eax = ebp + 8;
    eax = MEM32(eax);
    esi = esi + 0x1B9C;
    if (CMP_EQ(eax, MEM32(esi))) goto loc_003B577B; /* je: equal / zero */

loc_003B576A: ;
    eax = MEM32(esi);
    if (TEST_Z(eax, eax)) goto loc_003B5776; /* je: equal / zero */

loc_003B5770: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00381120(); /* call 0x00381120 */

loc_003B5776: ;
    eax = MEM32(ebp + 8);
    MEM32(esi) = eax;

loc_003B577B: ;
    eax = MEM32(ebp + 0xC);
    ecx = MEM32(ebp + 8);
    MEM32(eax) = ecx;

loc_003B5783: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B578B
 * Original: 0x003B578B - 0x003B57A3 (24 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B578B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B578B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    ebx = ecx;
    /* test ebx, ebx - flags set for next jcc */
    MEM32(ebp + -4) = ebx;
    if (TEST_NZ(ebx, ebx)) { g_seh_ebp = ebp; sub_003B57A3(); return; } /* jne: not equal / not zero */

loc_003B5799: ;
    eax = 0x80150005u;
    g_seh_ebp = ebp; sub_003B5897(); return; /* tail jmp 0x003B5897 */

}

/**
 * sub_003B57A3
 * Original: 0x003B57A3 - 0x003B5897 (244 bytes, 76 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B57A3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B57A3: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 0x10);
    /* test edi, edi - flags set for next jcc */
    PUSH32(esp, 0x50);
    ecx = ebx;
    PUSH32(esp, 0x628);
    if (TEST_Z(edi, edi)) goto loc_003B57BC; /* je: equal / zero */

loc_003B57B5: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB73F(); /* call 0x003AB73F */

loc_003B57BA: ;
    goto loc_003B57C1;

loc_003B57BC: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB6E6(); /* call 0x003AB6E6 */

loc_003B57C1: ;
    esi = eax;
    if (TEST_NZ(esi, esi)) goto loc_003B57D3; /* jne: not equal / not zero */

loc_003B57C7: ;
    MEM32(ebp + 8) = 0x8007000Eu;
    goto loc_003B5892;

loc_003B57D3: ;
    eax = esi + 0x590;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 8));
    MEM32(esi + 0x1C) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5278(); /* call 0x003B5278 */

loc_003B57E5: ;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0039C79E(); /* call 0x0039C79E */

loc_003B57ED: ;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    eax = MEM32(ebp + 0x14);
    MEM32(esi + 0x14) = 0x80004005u;
    MEM32(esi) = 0x3B52AA;
    MEM32(esi + 4) = 0x3B5161;
    MEM32(esi + 8) = eax;
    if (CMP_NE(MEM32(ebp + 0xC), 0)) goto loc_003B5849; /* jne: not equal / not zero */

loc_003B580D: ;
    ecx = MEM32(ebp + -4);
    MEM32(esi + 0x10) = MEM32(esi + 0x10) & 0;
    edi = esi + 0x4F8;
    PUSH32(esp, edi);
    ebx = esi + 0x610;
    PUSH32(esp, ebx);
    PUSH32(esp, MEM32(ebp + 0x10));
    MEM32(esi + 0x18) = 1;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0xA);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AA76A(); /* call 0x003AA76A */

loc_003B5836: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 8) = eax;
    if (CMP_GE(eax & eax, 0)) goto loc_003B588D; /* jge: greater or equal (signed >=) */

loc_003B583D: ;
    MEM32(ebx) = MEM32(ebx) & 0;
    MEM32(edi) = MEM32(edi) & 0;
    ebx = MEM32(ebp + -4);
    edi = MEM32(ebp + 0x10);

loc_003B5849: ;
    /* test edi, edi - flags set for next jcc */
    PUSH32(esp, 0x50);
    MEM32(esi + 0x18) = edi;
    ecx = ebx;
    PUSH32(esp, 0x150);
    if (TEST_Z(edi, edi)) goto loc_003B5860; /* je: equal / zero */

loc_003B5859: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB73F(); /* call 0x003AB73F */

loc_003B585E: ;
    goto loc_003B5865;

loc_003B5860: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB6E6(); /* call 0x003AB6E6 */

loc_003B5865: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003B5882; /* jne: not equal / not zero */

loc_003B586C: ;
    /* cmp MEM32(esi + 0x1C), eax - flags set for next jcc */
    MEM32(ebp + 8) = 0x8007000Eu;
    if (CMP_EQ(MEM32(esi + 0x1C), eax)) goto loc_003B5892; /* je: equal / zero */

loc_003B5878: ;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003AB753(); /* call 0x003AB753 */

loc_003B5880: ;
    goto loc_003B5892;

loc_003B5882: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    MEM32(esi + 0x10) = 2;

loc_003B588D: ;
    eax = MEM32(ebp + 0x18);
    MEM32(eax) = esi;

loc_003B5892: ;
    eax = MEM32(ebp + 8);
    POP32(esp, edi);
    POP32(esp, esi);

    g_seh_ebp = ebp; sub_003B5897(); return; /* restored dropped fall-through to sub_003B5897 */
}

/**
 * sub_003B5897
 * Original: 0x003B5897 - 0x003B589C (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5897(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5897: ;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

}

/**
 * sub_003B58A0
 * Original: 0x003B58A0 - 0x003B5CC4 (1060 bytes, 376 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B58A0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B58A0: ;
    esp = esp - 0x10;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0x1C);
    eax = MEM32(ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x20);
    PUSH32(esp, edi);
    edi = esi + 0x1308;
    PUSH32(esp, edi);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, ebx);
    MEM32(esp + 0x20) = edi;
    { uint32_t _icall_t = MEM32(eax + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B58C7: ;
    edx = MEM32(edi);
    eax = edx;
    eax = eax & 0xFFFFFFFCu;
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    edx = edx - eax;
    edx = edx << 3;
    esp = esp + 0x10;
    eax++;
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    eax++;
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    eax++;
    edi = ecx;
    eax++;
    ebp = ZX8(MEM8(eax + 1));
    ecx = edx;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    ecx = ecx << 8;
    ecx = ecx | ebp;
    eax++;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    ecx = MEM32(esi + 0x1310);
    edx = edx + ecx;
    eax++;
    if (CMP_L(edx, 0x20)) goto loc_003B595E; /* jl: less (signed <) */

loc_003B592F: ;
    edx = edx - 0x20;
    edi = ebp;
    ebp = ZX8(MEM8(eax + 1));
    ecx = edx;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    eax++;
    goto loc_003B5966;

loc_003B595E: ;
    edi = edi << LO8(ecx);
    goto loc_003B5966;

loc_003B5962: ;
    ebx = MEM32(esp + 0x28);

loc_003B5966: ;
    ecx = edi;
    ecx = ecx >> 9;
    /* cmp edx, 9 - flags set for next jcc */
    MEM32(esp + 0x24) = ecx;
    if (CMP_LE(edx, 9)) goto loc_003B5989; /* jle: less or equal (signed <=) */

loc_003B5974: ;
    ecx = 0x29;
    ecx = ecx - edx;
    ebx = ebp;
    ebx = ebx >> LO8(ecx);
    ecx = MEM32(esp + 0x24);
    ecx = ecx | ebx;
    ebx = MEM32(esp + 0x28);

loc_003B5989: ;
    if (TEST_Z(ecx, ecx)) goto loc_003B5C7B; /* je: equal / zero */

loc_003B5991: ;
    ecx = MEM32(esi + 0x334);
    MEM32(esp + 0x14) = ecx;
    goto loc_003B59A0;

    /* nop */

loc_003B59A0: ;
    ecx = edi;
    ecx = ecx >> 0x14;
    /* cmp edx, 0x14 - flags set for next jcc */
    MEM32(esp + 0x24) = ecx;
    if (CMP_LE(edx, 0x14)) goto loc_003B59BF; /* jle: less or equal (signed <=) */

loc_003B59AE: ;
    ecx = 0x34;
    ecx = ecx - edx;
    ebx = ebp;
    ebx = ebx >> LO8(ecx);
    ecx = MEM32(esp + 0x24);
    ecx = ecx | ebx;

loc_003B59BF: ;
    if (TEST_NZ(ecx, 0xFFFFFF00u)) goto loc_003B59CF; /* jne: not equal / not zero */

loc_003B59C7: ;
    ebx = MEM32(0xF65DDC);
    goto loc_003B59D8;

loc_003B59CF: ;
    ebx = MEM32(0xF65DBC);
    ecx = ecx >> 6;

loc_003B59D8: ;
    ebx = (uint32_t)(int32_t)SMEM16(ebx + ecx * 2);
    ecx = ebx;
    ecx = ecx & 0xF;
    edx = edx + ecx;
    if (CMP_L(edx, 0x20)) goto loc_003B5A17; /* jl: less (signed <) */

loc_003B59E8: ;
    edx = edx - 0x20;
    edi = ebp;
    ebp = ZX8(MEM8(eax + 1));
    ecx = edx;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    eax++;
    goto loc_003B5A19;

loc_003B5A17: ;
    edi = edi << LO8(ecx);

loc_003B5A19: ;
    ecx = ebx;
    ecx = ecx >> 2;
    ecx = ZX8(LO8(ecx));
    ecx = ecx >> 2;
    if (CMP_EQ(ecx, 0x22)) { RECOMP_SLICE_POINT(); goto loc_003B59A0; } /* je: equal / zero */

loc_003B5A2D: ;
    if (CMP_NE(ecx, 0x23)) goto loc_003B5A3E; /* jne: not equal / not zero */

loc_003B5A32: ;
    MEM32(esi + 0x334) = MEM32(esi + 0x334) + 0x21;
    { RECOMP_SLICE_POINT(); goto loc_003B59A0; }

loc_003B5A3E: ;
    if (CMP_EQ(ecx, 0x24)) goto loc_003B5C77; /* je: equal / zero */

loc_003B5A47: ;
    MEM32(esi + 0x334) = MEM32(esi + 0x334) + ecx;
    ecx = MEM32(esi + 0x334);
    ebx = ebx >> 0xA;
    MEM32(esi + 0x344) = ebx;
    if (CMP_G(ecx, MEM32(esi + 0x340))) goto loc_003B5C77; /* jg: greater (signed >) */

loc_003B5A68: ;
    ecx = ecx - MEM32(esp + 0x14);
    ebx = MEM32(esi + 0x33C);
    ebx = ebx + ecx;
    MEM32(esp + 0x24) = ecx;
    ecx = MEM32(esi + 0x1D8);
    /* cmp ebx, ecx - flags set for next jcc */
    MEM32(esi + 0x33C) = ebx;
    if (CMP_L(ebx, ecx)) goto loc_003B5AAA; /* jl: less (signed <) */

loc_003B5A88: ;
    goto loc_003B5A90;

    /* nop */

loc_003B5A90: ;
    MEM32(esi + 0x33C) = MEM32(esi + 0x33C) - ecx;
    MEM32(esi + 0x338) = MEM32(esi + 0x338) + 1;
    ebx = MEM32(esi + 0x33C);
    if (CMP_GE(ebx, MEM32(esi + 0x1D8))) { RECOMP_SLICE_POINT(); goto loc_003B5A90; } /* jge: greater or equal (signed >=) */

loc_003B5AAA: ;
    if (CMP_EQ(MEM32(esp + 0x24), 0xFFFFFFFEu)) goto loc_003B5C77; /* je: equal / zero */

loc_003B5AB5: ;
    if (TEST_Z(MEM8(esi + 0x344), 0x10)) goto loc_003B5B1B; /* je: equal / zero */

loc_003B5ABE: ;
    if (CMP_L(edx, 0x1B)) goto loc_003B5B0A; /* jl: less (signed <) */

loc_003B5AC3: ;
    edx = edx - 0x1B;
    if ((edx == 0)) goto loc_003B5ADE; /* je: equal / zero */

loc_003B5AC8: ;
    ecx = 5;
    ecx = ecx - edx;
    ebx = ebp;
    ebx = ebx >> LO8(ecx);
    ecx = edx;
    ebx = ebx | edi;
    ebx = ebx >> 0x1B;
    ebp = ebp << LO8(ecx);
    goto loc_003B5AE3;

loc_003B5ADE: ;
    ebx = edi;
    ebx = ebx >> 0x1B;

loc_003B5AE3: ;
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    eax++;
    ecx = ecx << 8;
    edi = ebp;
    ebp = ZX8(MEM8(eax));
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    eax++;
    goto loc_003B5B15;

loc_003B5B0A: ;
    ebx = edi;
    edx = edx + 5;
    ebx = ebx >> 0x1B;
    edi = edi << 5;

loc_003B5B15: ;
    MEM32(esi + 0x2E8) = ebx;

loc_003B5B1B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi) = edi;
    MEM32(esi + 4) = ebp;
    MEM32(esi + 8) = edx;
    MEM32(esi + 0xC) = eax;
    { uint32_t _icall_t = MEM32(esi + 0x2C8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5B2D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x2D0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5B34: ;
    ecx = MEM32(esi + 0x1324);
    esp = esp + 8;
    ecx--;
    eax = ecx;
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x1324) = ecx;
    if (CMP_G(eax & eax, 0)) goto loc_003B5B66; /* jg: greater (signed >) */

loc_003B5B4A: ;
    eax = MEM32(esi + 0x1B4);
    edx = MEM32(esi + 0x1AC);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    MEM32(esi + 0x1324) = edx;
    { uint32_t _icall_t = MEM32(esi + 0x1B0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5B63: ;
    esp = esp + 4;

loc_003B5B66: ;
    edx = MEM32(esi + 8);
    eax = MEM32(esi + 0xC);
    edi = MEM32(esi);
    ebp = MEM32(esi + 4);
    ecx = edx;
    ecx = ecx & 7;
    ebx = edx;
    ebx = ebx - ecx;
    ebx = ebx + 7;
    ebx = (uint32_t)((int32_t)ebx >> 3);
    MEM32(esp + 0x24) = ecx;
    ecx = MEM32(esp + 0x10);
    ebx = ebx - MEM32(ecx);
    ecx = ebx + eax + -8;
    ebx = MEM32(esi + 0x130C);
    ebx = ebx - ecx;
    if (CMP_G(ebx, 0x800)) { RECOMP_SLICE_POINT(); goto loc_003B5962; } /* jg: greater (signed >) */

loc_003B5BA2: ;
    edi = MEM32(esp + 0x10);
    edx = esp + 0x18;
    PUSH32(esp, edx);
    PUSH32(esp, edi);
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B5BB3: ;
    ebx = MEM32(esp + 0x38);
    eax = MEM32(ebx);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0);
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(eax + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5BC0: ;
    ecx = MEM32(ebx);
    edx = esp + 0x34;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    PUSH32(esp, 1);
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(ecx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5BCD: ;
    eax = MEM32(ebx);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(eax + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5BDB: ;
    edx = MEM32(edi);
    eax = edx;
    eax = eax & 0xFFFFFFFCu;
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    edx = edx - eax;
    edx = edx << 3;
    esp = esp + 0x38;
    eax++;
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    eax++;
    edi = ZX8(MEM8(eax + 1));
    ecx = ecx << 8;
    ecx = ecx | edi;
    eax++;
    edi = ecx;
    eax++;
    ebp = ZX8(MEM8(eax + 1));
    ecx = edx;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    ecx = ecx << 8;
    ecx = ecx | ebp;
    eax++;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    ecx = MEM32(esp + 0x24);
    edx = edx + ecx;
    eax++;
    if (CMP_L(edx, 0x20)) { RECOMP_SLICE_POINT(); goto loc_003B595E; } /* jl: less (signed <) */

loc_003B5C45: ;
    edx = edx - 0x20;
    edi = ebp;
    ebp = ZX8(MEM8(eax + 1));
    ecx = edx;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(eax);
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(eax + 1));
    eax++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    eax++;
    { RECOMP_SLICE_POINT(); goto loc_003B5966; }

loc_003B5C77: ;
    ebx = MEM32(esp + 0x28);

loc_003B5C7B: ;
    esi = MEM32(esp + 0x10);
    edi = MEM32(esi);
    edx = edx + 7;
    edx = (uint32_t)((int32_t)edx >> 3);
    ecx = esp + 0x18;
    PUSH32(esp, ecx);
    edx = edx - edi;
    PUSH32(esp, esi);
    edx = edx + eax + -8;
    PUSH32(esp, edx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B5C9A: ;
    eax = MEM32(ebx);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0);
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(eax + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5CA3: ;
    ecx = MEM32(ebx);
    edx = esp + 0x34;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    PUSH32(esp, 1);
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(ecx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5CB0: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0031F700(); /* call 0x0031F700 */

loc_003B5CB6: ;
    esp = esp + 0x2C;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0x10;
    esp += 4; return; /* ret */

}

/**
 * sub_003B5CE0
 * Original: 0x003B5CE0 - 0x003B5CF3 (19 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5CE0(void)
{

loc_003B5CE0: ;
    eax = MEM32(esp + 4);
    ecx = 0; /* xor self */
    MEM32(eax + 0x10) = ecx;
    MEM32(eax + 0x14) = ecx;
    MEM32(eax + 0x18) = ecx;
    MEM32(eax + 0x1C) = ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003B5D00
 * Original: 0x003B5D00 - 0x003B5D1C (28 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5D00(void)
{

loc_003B5D00: ;
    eax = MEM32(esp + 4);
    ecx = 0x400;
    MEM32(eax + 0x34C) = ecx;
    MEM32(eax + 0x354) = ecx;
    MEM32(eax + 0x350) = ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003B5D20
 * Original: 0x003B5D20 - 0x003B5D69 (73 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5D20(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5D20: ;
    esp = esp - 8;
    eax = MEM32(esp + 0xC);
    edx = MEM32(eax + 0xC);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebp = MEM32(eax + 4);
    PUSH32(esp, esi);
    esi = MEM32(eax + 8);
    PUSH32(esp, edi);
    edi = MEM32(eax);
    ebx = edi;
    ebx = ebx >> 0x15;
    /* cmp esi, 0x15 - flags set for next jcc */
    MEM32(esp + 0x14) = 0;
    if (CMP_LE(esi, 0x15)) goto loc_003B5D59; /* jle: less or equal (signed <=) */

loc_003B5D48: ;
    ecx = 0x35;
    ecx = ecx - esi;
    eax = ebp;
    eax = eax >> LO8(ecx);
    ebx = ebx | eax;
    eax = MEM32(esp + 0x1C);

loc_003B5D59: ;
    if (TEST_NZ(ebx, 0xFFFFFF80u)) { g_seh_ebp = ebp; sub_003B5D69(); return; } /* jne: not equal / not zero */

loc_003B5D61: ;
    ecx = MEM32(0xF65DE0);
    g_seh_ebp = ebp; sub_003B5D72(); return; /* tail jmp 0x003B5D72 */

}

/**
 * sub_003B5D69
 * Original: 0x003B5D69 - 0x003B5D72 (9 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5D69(void)
{

loc_003B5D69: ;
    ecx = MEM32(0xF65DA8);
    ebx = ebx >> 6;

    sub_003B5D72(); return; /* restored dropped fall-through to sub_003B5D72 */
}

/**
 * sub_003B5D72
 * Original: 0x003B5D72 - 0x003B5EE0 (366 bytes, 145 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5D72(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5D72: ;
    ecx = (uint32_t)(int32_t)SMEM16(ecx + ebx * 2);
    ebx = SX8(LO8(ecx));
    /* cmp ebx, 0x7F - flags set for next jcc */
    MEM32(esp + 0x1C) = ebx;
    if (CMP_NE(ebx, 0x7F)) goto loc_003B5D8F; /* jne: not equal / not zero */

loc_003B5D82: ;
    MEM32(esp + 0x14) = 0xFFFFFFFFu;
    goto loc_003B5EBC;

loc_003B5D8F: ;
    ecx = ecx >> 8;
    ecx = ZX8(LO8(ecx));
    esi = esi + ecx;
    if (CMP_L(esi, 0x20)) goto loc_003B5DCB; /* jl: less (signed <) */

loc_003B5D9C: ;
    esi = esi - 0x20;
    edi = ebp;
    ebp = ZX8(MEM8(edx + 1));
    ecx = esi;
    edi = edi << LO8(ecx);
    ecx = (uint32_t)(int32_t)SMEM8(edx);
    edx++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(edx + 1));
    edx++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(edx + 1));
    edx++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    edx++;
    goto loc_003B5DCD;

loc_003B5DCB: ;
    edi = edi << LO8(ecx);

loc_003B5DCD: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003B5DE2; /* jne: not equal / not zero */

loc_003B5DD1: ;
    ecx = MEM32(esp + 0x28);
    ebx = MEM32(ecx);
    ecx = MEM32(esp + 0x24);
    MEM32(ecx) = ebx;
    goto loc_003B5EB1;

loc_003B5DE2: ;
    ecx = MEM32(esp + 0x20);
    ebx = MEM32(ecx + 4);
    if (TEST_Z(ebx, ebx)) goto loc_003B5E85; /* je: equal / zero */

loc_003B5DF1: ;
    ecx = 0x20;
    ecx = ecx - ebx;
    /* cmp esi, ecx - flags set for next jcc */
    MEM32(esp + 0x10) = ecx;
    if (CMP_L(esi, ecx)) goto loc_003B5E49; /* jl: less (signed <) */

loc_003B5E00: ;
    esi = esi + ebx + -32;
    if (TEST_Z(esi, esi)) goto loc_003B5E1E; /* je: equal / zero */

loc_003B5E08: ;
    ecx = ebx;
    ecx = ecx - esi;
    ebx = ebp;
    ebx = ebx >> LO8(ecx);
    ecx = MEM32(esp + 0x10);
    ebx = ebx | edi;
    ebx = ebx >> LO8(ecx);
    ecx = esi;
    ebp = ebp << LO8(ecx);
    goto loc_003B5E22;

loc_003B5E1E: ;
    ebx = edi;
    ebx = ebx >> LO8(ecx);

loc_003B5E22: ;
    ecx = (uint32_t)(int32_t)SMEM8(edx);
    edx++;
    ecx = ecx << 8;
    edi = ebp;
    ebp = ZX8(MEM8(edx));
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(edx + 1));
    edx++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ZX8(MEM8(edx + 1));
    edx++;
    ecx = ecx << 8;
    ecx = ecx | ebp;
    ebp = ecx;
    edx++;
    goto loc_003B5E58;

loc_003B5E49: ;
    esi = esi + ebx;
    ebx = edi;
    ebx = ebx >> LO8(ecx);
    ecx = MEM32(esp + 0x20);
    ecx = MEM32(ecx + 4);
    edi = edi << LO8(ecx);

loc_003B5E58: ;
    ecx = MEM32(esp + 0x20);
    ecx = MEM32(ecx + 0xC);
    ecx = ecx - ebx;
    ebx = MEM32(esp + 0x1C);
    ecx--;
    MEM32(esp + 0x10) = ecx;
    ecx = MEM32(esp + 0x20);
    ecx = MEM32(ecx + 4);
    ebx = ebx << LO8(ecx);
    ecx = MEM32(esp + 0x10);
    if (CMP_LE(ebx & ebx, 0)) goto loc_003B5E7F; /* jle: less or equal (signed <=) */

loc_003B5E7B: ;
    ebx = ebx - ecx;
    goto loc_003B5E81;

loc_003B5E7F: ;
    ebx = ebx + ecx;

loc_003B5E81: ;
    MEM32(esp + 0x1C) = ebx;

loc_003B5E85: ;
    ecx = MEM32(esp + 0x28);
    ebx = MEM32(ecx);
    ebx = ebx + MEM32(esp + 0x1C);
    ecx = MEM32(esp + 0x20);
    ecx = MEM32(ecx + 8);
    ebx = ebx << LO8(ecx);
    ecx = MEM32(esp + 0x20);
    ecx = MEM32(ecx + 8);
    ebx = (uint32_t)((int32_t)ebx >> LO8(ecx));
    ecx = MEM32(esp + 0x24);
    MEM32(ecx) = ebx;
    ecx = MEM32(esp + 0x28);
    MEM32(ecx) = ebx;
    ecx = MEM32(esp + 0x24);

loc_003B5EB1: ;
    ebx = MEM32(esp + 0x20);
    if (CMP_EQ(MEM32(ebx), 0)) goto loc_003B5EBC; /* je: equal / zero */

loc_003B5EBA: ;
    MEM32(ecx) = MEM32(ecx) << 1;

loc_003B5EBC: ;
    MEM32(eax) = edi;
    POP32(esp, edi);
    MEM32(eax + 8) = esi;
    POP32(esp, esi);
    MEM32(eax + 4) = ebp;
    POP32(esp, ebp);
    MEM32(eax + 0xC) = edx;
    eax = MEM32(esp + 8);
    POP32(esp, ebx);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B5EE0
 * Original: 0x003B5EE0 - 0x003B5FAF (207 bytes, 80 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5EE0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5EE0: ;
    esp = esp - 0x18;
    eax = MEM32(esp + 0x20);
    ecx = MEM32(eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x2C);
    esi = edi + 0x1308;
    PUSH32(esp, esi);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    MEM32(esp + 0x28) = 1;
    MEM32(esp + 0x24) = esi;
    { uint32_t _icall_t = MEM32(ecx + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B5F0F: ;
    ebp = MEM32(esi);
    esi = ebp;
    esi = esi & 0xFFFFFFFCu;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    ebp = ebp - esi;
    ebp = ebp << 3;
    esp = esp + 0x10;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi + 1);
    esi++;
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    ecx = MEM32(edi + 0x1310);
    ebp = ebp + ecx;
    edx = eax;
    esi++;
    /* cmp ebp, 0x20 - flags set for next jcc */
    MEM32(esp + 0x2C) = edx;
    if (CMP_L(ebp, 0x20)) { g_seh_ebp = ebp; sub_003B5FAF(); return; } /* jl: less (signed <) */

loc_003B5F7C: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ebp = ebp - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    edx = eax;
    g_seh_ebp = ebp; sub_003B5FB1(); return; /* tail jmp 0x003B5FB1 */

}

/**
 * sub_003B5FAF
 * Original: 0x003B5FAF - 0x003B5FB1 (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5FAF(void)
{

loc_003B5FAF: ;
    ebx = ebx << LO8(ecx);

    sub_003B5FB1(); return; /* restored dropped fall-through to sub_003B5FB1 */
}

/**
 * sub_003B5FB1
 * Original: 0x003B5FB1 - 0x003B65A4 (1523 bytes, 505 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B5FB1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B5FB1: ;
    eax = ebx;
    eax = eax >> 9;
    /* cmp ebp, 9 - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(ebp, 9)) goto loc_003B5FD2; /* jle: less or equal (signed <=) */

loc_003B5FBF: ;
    ecx = 0x29;
    ecx = ecx - ebp;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B5FD2: ;
    if (TEST_Z(eax, eax)) goto loc_003B6558; /* je: equal / zero */

loc_003B5FDA: ;
    eax = MEM32(edi + 0x334);
    MEM32(esp + 0x1C) = eax;

loc_003B5FE4: ;
    eax = ebx;
    eax = eax >> 0x15;
    if (CMP_LE(ebp, 0x15)) goto loc_003B5FFD; /* jle: less or equal (signed <=) */

loc_003B5FEE: ;
    ecx = 0x35;
    ecx = ecx - ebp;
    edx = edx >> LO8(ecx);
    eax = eax | edx;
    edx = MEM32(esp + 0x2C);

loc_003B5FFD: ;
    if (TEST_NZ(eax, 0xFFFFFF80u)) goto loc_003B6014; /* jne: not equal / not zero */

loc_003B6004: ;
    ecx = MEM32(0xF65DB4);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    MEM32(esp + 0x10) = eax;
    goto loc_003B6025;

loc_003B6014: ;
    ecx = MEM32(0xF65DB0);
    eax = eax >> 6;
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    MEM32(esp + 0x10) = eax;

loc_003B6025: ;
    ecx = eax;
    ecx = ecx & 0xF;
    ebp = ebp + ecx;
    if (CMP_L(ebp, 0x20)) goto loc_003B6068; /* jl: less (signed <) */

loc_003B6031: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ebp = ebp - 0x20;
    ebx = edx;
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    MEM32(esp + 0x2C) = eax;
    edx = eax;
    eax = MEM32(esp + 0x10);
    esi++;
    goto loc_003B606A;

loc_003B6068: ;
    ebx = ebx << LO8(ecx);

loc_003B606A: ;
    ecx = eax;
    ecx = ecx >> 2;
    ecx = ZX8(LO8(ecx));
    ecx = ecx >> 2;
    if (CMP_EQ(ecx, 0x22)) { RECOMP_SLICE_POINT(); goto loc_003B5FE4; } /* je: equal / zero */

loc_003B607E: ;
    if (CMP_NE(ecx, 0x23)) goto loc_003B608F; /* jne: not equal / not zero */

loc_003B6083: ;
    MEM32(edi + 0x334) = MEM32(edi + 0x334) + 0x21;
    { RECOMP_SLICE_POINT(); goto loc_003B5FE4; }

loc_003B608F: ;
    if (CMP_EQ(ecx, 0x24)) goto loc_003B6558; /* je: equal / zero */

loc_003B6098: ;
    MEM32(edi + 0x334) = MEM32(edi + 0x334) + ecx;
    ecx = MEM32(edi + 0x334);
    eax = eax >> 0xA;
    MEM32(edi + 0x344) = eax;
    if (CMP_G(ecx, MEM32(edi + 0x340))) goto loc_003B6558; /* jg: greater (signed >) */

loc_003B60B9: ;
    ecx = ecx - MEM32(esp + 0x1C);
    eax = MEM32(edi + 0x33C);
    eax = eax + ecx;
    MEM32(esp + 0x10) = ecx;
    ecx = eax;
    MEM32(edi + 0x33C) = eax;
    eax = MEM32(edi + 0x1D8);
    if (CMP_L(ecx, eax)) goto loc_003B60FA; /* jl: less (signed <) */

loc_003B60DB: ;
    goto loc_003B60E0;

    /* nop */

loc_003B60E0: ;
    MEM32(edi + 0x33C) = MEM32(edi + 0x33C) - eax;
    MEM32(edi + 0x338) = MEM32(edi + 0x338) + 1;
    ecx = MEM32(edi + 0x33C);
    if (CMP_GE(ecx, MEM32(edi + 0x1D8))) { RECOMP_SLICE_POINT(); goto loc_003B60E0; } /* jge: greater or equal (signed >=) */

loc_003B60FA: ;
    eax = MEM32(esp + 0x10);
    if (CMP_EQ(eax, 0xFFFFFFFEu)) goto loc_003B6558; /* je: equal / zero */

loc_003B6107: ;
    ecx = MEM32(esp + 0x18);
    if (TEST_NZ(ecx, ecx)) goto loc_003B6129; /* jne: not equal / not zero */

loc_003B610F: ;
    if (CMP_BE(eax, 1)) goto loc_003B6129; /* jbe: below or equal (unsigned <=) */

loc_003B6114: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(edi + 0x2C4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B611C: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D00(); /* call 0x003B5D00 */

loc_003B6122: ;
    edx = MEM32(esp + 0x38);
    esp = esp + 0xC;

loc_003B6129: ;
    if (TEST_NZ(MEM8(edi + 0x344), 0x20)) goto loc_003B61A7; /* jne: not equal / not zero */

loc_003B6132: ;
    eax = ebx;
    eax = eax >> 0x1A;
    /* cmp ebp, 0x1A - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(ebp, 0x1A)) goto loc_003B6153; /* jle: less or equal (signed <=) */

loc_003B6140: ;
    ecx = 0x3A;
    ecx = ecx - ebp;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B6153: ;
    ecx = MEM32(0xF65DC8);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    ecx = eax;
    ecx = ecx >> 8;
    MEM32(edi + 0x344) = ecx;
    ecx = ZX8(LO8(eax));
    ebp = ebp + ecx;
    if (CMP_L(ebp, 0x20)) goto loc_003B61A5; /* jl: less (signed <) */

loc_003B6172: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ebp = ebp - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    edx = eax;
    goto loc_003B61A7;

loc_003B61A5: ;
    ebx = ebx << LO8(ecx);

loc_003B61A7: ;
    if (TEST_Z(MEM8(edi + 0x344), 0x10)) goto loc_003B6211; /* je: equal / zero */

loc_003B61B0: ;
    if (CMP_L(ebp, 0x1B)) goto loc_003B6200; /* jl: less (signed <) */

loc_003B61B5: ;
    ebp = ebp - 0x1B;
    if ((ebp == 0)) goto loc_003B61D0; /* je: equal / zero */

loc_003B61BA: ;
    ecx = 5;
    ecx = ecx - ebp;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = ebp;
    eax = eax | ebx;
    eax = eax >> 0x1B;
    edx = edx << LO8(ecx);
    goto loc_003B61D5;

loc_003B61D0: ;
    eax = ebx;
    eax = eax >> 0x1B;

loc_003B61D5: ;
    ecx = (uint32_t)(int32_t)SMEM8(esi);
    esi++;
    ecx = ecx << 8;
    ebx = edx;
    edx = ZX8(MEM8(esi));
    ecx = ecx | edx;
    edx = ZX8(MEM8(esi + 1));
    esi++;
    ecx = ecx << 8;
    ecx = ecx | edx;
    edx = ZX8(MEM8(esi + 1));
    esi++;
    ecx = ecx << 8;
    ecx = ecx | edx;
    MEM32(esp + 0x2C) = ecx;
    esi++;
    edx = ecx;
    goto loc_003B620B;

loc_003B6200: ;
    eax = ebx;
    ebp = ebp + 5;
    eax = eax >> 0x1B;
    ebx = ebx << 5;

loc_003B620B: ;
    MEM32(edi + 0x2E8) = eax;

loc_003B6211: ;
    if (TEST_Z(MEM8(edi + 0x344), 8)) goto loc_003B627B; /* je: equal / zero */

loc_003B621A: ;
    eax = edi + 0x2FC;
    PUSH32(esp, eax);
    ecx = edi + 0x304;
    MEM32(edi + 0xC) = esi;
    PUSH32(esp, ecx);
    esi = edi + 0x2EC;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    MEM32(edi) = ebx;
    MEM32(edi + 4) = edx;
    MEM32(edi + 8) = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B6240: ;
    edx = edi + 0x300;
    PUSH32(esp, edx);
    MEM32(esp + 0x30) = eax;
    eax = edi + 0x308;
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B6259: ;
    ecx = MEM32(edi + 4);
    ebx = MEM32(edi);
    ebp = MEM32(edi + 8);
    esi = MEM32(edi + 0xC);
    MEM32(esp + 0x4C) = ecx;
    ecx = MEM32(esp + 0x3C);
    esp = esp + 0x20;
    eax = eax | ecx;
    if ((eax != 0)) goto loc_003B6558; /* jne: not equal / not zero */

loc_003B6277: ;
    edx = MEM32(esp + 0x2C);

loc_003B627B: ;
    if (TEST_Z(MEM8(edi + 0x344), 4)) goto loc_003B62E5; /* je: equal / zero */

loc_003B6284: ;
    MEM32(edi + 4) = edx;
    edx = edi + 0x320;
    PUSH32(esp, edx);
    eax = edi + 0x328;
    MEM32(edi + 0xC) = esi;
    PUSH32(esp, eax);
    esi = edi + 0x310;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    MEM32(edi) = ebx;
    MEM32(edi + 8) = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B62AA: ;
    ecx = edi + 0x324;
    PUSH32(esp, ecx);
    edx = edi + 0x32C;
    PUSH32(esp, edx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    MEM32(esp + 0x3C) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B62C3: ;
    ecx = MEM32(edi + 4);
    ebx = MEM32(edi);
    ebp = MEM32(edi + 8);
    esi = MEM32(edi + 0xC);
    MEM32(esp + 0x4C) = ecx;
    ecx = MEM32(esp + 0x3C);
    esp = esp + 0x20;
    eax = eax | ecx;
    if ((eax != 0)) goto loc_003B6558; /* jne: not equal / not zero */

loc_003B62E1: ;
    edx = MEM32(esp + 0x2C);

loc_003B62E5: ;
    eax = MEM32(edi + 0x344);
    /* test LO8(eax), 2 - flags set for next jcc */
    MEM32(esp + 0x18) = eax;
    if (TEST_Z(LO8(eax), 2)) goto loc_003B6379; /* je: equal / zero */

loc_003B62F7: ;
    eax = ebx;
    eax = eax >> 0x17;
    /* cmp ebp, 0x17 - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(ebp, 0x17)) goto loc_003B6318; /* jle: less or equal (signed <=) */

loc_003B6305: ;
    ecx = 0x37;
    ecx = ecx - ebp;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B6318: ;
    ecx = MEM32(0xF65DD4);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    ecx = eax;
    ecx = ecx & 0xFFFFFFF0u;
    ecx = ecx << 0x10;
    MEM32(edi + 0x348) = ecx;
    ecx = ZX8(LO8(eax));
    ebp = ebp + ecx;
    if (CMP_L(ebp, 0x20)) goto loc_003B6371; /* jl: less (signed <) */

loc_003B633A: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ebp = ebp - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    eax = eax << 8;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    edx = eax;
    eax = MEM32(esp + 0x18);
    esi++;
    goto loc_003B6383;

loc_003B6371: ;
    eax = MEM32(esp + 0x18);
    ebx = ebx << LO8(ecx);
    goto loc_003B6383;

loc_003B6379: ;
    MEM32(edi + 0x348) = 0;

loc_003B6383: ;
    /* test LO8(eax), 1 - flags set for next jcc */
    MEM32(edi) = ebx;
    MEM32(edi + 4) = edx;
    MEM32(edi + 8) = ebp;
    MEM32(edi + 0xC) = esi;
    if (TEST_Z(LO8(eax), 1)) goto loc_003B63BD; /* je: equal / zero */

loc_003B6392: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(edi + 0x2C8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6399: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(edi + 0x2D0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B63A0: ;
    eax = edi + 0x2EC;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5CE0(); /* call 0x003B5CE0 */

loc_003B63AC: ;
    ecx = edi + 0x310;
    PUSH32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5CE0(); /* call 0x003B5CE0 */

loc_003B63B8: ;
    esp = esp + 0x10;
    goto loc_003B63F4;

loc_003B63BD: ;
    eax = (uint32_t)((int32_t)eax >> 2);
    eax = eax & 3;
    edx = MEM32(edi + eax * 4 + 0x2D4);
    eax = MEM32(edi + 0x348);
    /* test eax, eax - flags set for next jcc */
    MEM32(edi + 0x2D4) = edx;
    if (TEST_Z(eax, eax)) goto loc_003B63E4; /* je: equal / zero */

loc_003B63DA: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(edi + 0x2CC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B63E1: ;
    esp = esp + 4;

loc_003B63E4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(edi + 0x2D4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B63EB: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D00(); /* call 0x003B5D00 */

loc_003B63F1: ;
    esp = esp + 8;

loc_003B63F4: ;
    ecx = MEM32(edi + 0x1324);
    ecx--;
    eax = ecx;
    /* test eax, eax - flags set for next jcc */
    MEM32(edi + 0x1324) = ecx;
    if (CMP_G(eax & eax, 0)) goto loc_003B6423; /* jg: greater (signed >) */

loc_003B6407: ;
    ecx = MEM32(edi + 0x1B4);
    eax = MEM32(edi + 0x1AC);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    MEM32(edi + 0x1324) = eax;
    { uint32_t _icall_t = MEM32(edi + 0x1B0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6420: ;
    esp = esp + 4;

loc_003B6423: ;
    ebp = MEM32(edi + 8);
    edx = MEM32(edi + 4);
    esi = MEM32(edi + 0xC);
    ebx = MEM32(edi);
    eax = ebp;
    eax = eax & 7;
    ecx = ebp;
    ecx = ecx - eax;
    ecx = ecx + 7;
    MEM32(esp + 0x2C) = edx;
    MEM32(esp + 0x1C) = eax;
    eax = MEM32(esp + 0x14);
    edx = MEM32(eax);
    ecx = (uint32_t)((int32_t)ecx >> 3);
    ecx = ecx - edx;
    edx = MEM32(edi + 0x130C);
    ecx = ecx + esi + -8;
    edx = edx - ecx;
    if (CMP_G(edx, 0x800)) goto loc_003B6547; /* jg: greater (signed >) */

loc_003B6465: ;
    edx = esp + 0x20;
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B6472: ;
    ebx = MEM32(esp + 0x24);
    esi = MEM32(esp + 0x40);
    eax = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6483: ;
    ecx = MEM32(esi);
    edx = esp + 0x3C;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(ecx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6490: ;
    eax = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B649E: ;
    ebp = MEM32(ebx);
    esi = ebp;
    esi = esi & 0xFFFFFFFCu;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    ebp = ebp - esi;
    ebp = ebp << 3;
    esp = esp + 0x38;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi + 1);
    esi++;
    edx = ZX8(MEM8(esi + 1));
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    ecx = MEM32(esp + 0x1C);
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    ebp = ebp + ecx;
    esi++;
    /* cmp ebp, 0x20 - flags set for next jcc */
    MEM32(esp + 0x2C) = eax;
    if (CMP_L(ebp, 0x20)) goto loc_003B6545; /* jl: less (signed <) */

loc_003B6507: ;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ebp = ebp - 0x20;
    ecx = ebp;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    MEM32(esp + 0x18) = 0;
    edx = eax;
    { RECOMP_SLICE_POINT(); goto loc_003B5FB1; }

loc_003B6545: ;
    ebx = ebx << LO8(ecx);

loc_003B6547: ;
    edx = MEM32(esp + 0x2C);
    MEM32(esp + 0x18) = 0;
    { RECOMP_SLICE_POINT(); goto loc_003B5FB1; }

loc_003B6558: ;
    edi = MEM32(esp + 0x14);
    edx = esp + 0x20;
    PUSH32(esp, edx);
    edx = MEM32(edi);
    ebp = ebp + 7;
    ebp = (uint32_t)((int32_t)ebp >> 3);
    ebp = ebp - edx;
    PUSH32(esp, edi);
    eax = esi + ebp + -8;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B6577: ;
    esi = MEM32(esp + 0x40);
    ecx = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(ecx + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6584: ;
    edx = MEM32(esi);
    eax = esp + 0x3C;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(edx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6591: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0031F700(); /* call 0x0031F700 */

loc_003B6597: ;
    esp = esp + 0x2C;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0x18;
    esp += 4; return; /* ret */

}

/**
 * sub_003B65C0
 * Original: 0x003B65C0 - 0x003B6C00 (1600 bytes, 546 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B65C0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B65C0: ;
    esp = esp - 0x18;
    eax = MEM32(esp + 0x20);
    ecx = MEM32(eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebp = MEM32(esp + 0x24);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ebp + 0x1308;
    PUSH32(esp, esi);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    MEM32(esp + 0x28) = 1;
    MEM32(esp + 0x24) = esi;
    { uint32_t _icall_t = MEM32(ecx + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B65EF: ;
    edi = MEM32(esi);
    esi = edi;
    esi = esi & 0xFFFFFFFCu;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    edi = edi - esi;
    edi = edi << 3;
    esp = esp + 0x10;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi + 1);
    esi++;
    ecx = edi;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    ecx = MEM32(ebp + 0x1310);
    edi = edi + ecx;
    edx = eax;
    esi++;
    /* cmp edi, 0x20 - flags set for next jcc */
    MEM32(esp + 0x2C) = edx;
    if (CMP_L(edi, 0x20)) goto loc_003B668F; /* jl: less (signed <) */

loc_003B665C: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edi = edi - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = edi;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    edx = eax;
    goto loc_003B6691;

loc_003B668F: ;
    ebx = ebx << LO8(ecx);

loc_003B6691: ;
    eax = ebx;
    eax = eax >> 9;
    /* cmp edi, 9 - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(edi, 9)) goto loc_003B66B2; /* jle: less or equal (signed <=) */

loc_003B669F: ;
    ecx = 0x29;
    ecx = ecx - edi;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B66B2: ;
    if (TEST_Z(eax, eax)) goto loc_003B6BB5; /* je: equal / zero */

loc_003B66BA: ;
    eax = MEM32(ebp + 0x334);
    MEM32(esp + 0x1C) = eax;

loc_003B66C4: ;
    eax = ebx;
    eax = eax >> 0x15;
    if (CMP_LE(edi, 0x15)) goto loc_003B66DD; /* jle: less or equal (signed <=) */

loc_003B66CE: ;
    ecx = 0x35;
    ecx = ecx - edi;
    edx = edx >> LO8(ecx);
    eax = eax | edx;
    edx = MEM32(esp + 0x2C);

loc_003B66DD: ;
    if (TEST_NZ(eax, 0xFFFFFF80u)) goto loc_003B66F4; /* jne: not equal / not zero */

loc_003B66E4: ;
    ecx = MEM32(0xF65DC4);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    MEM32(esp + 0x10) = eax;
    goto loc_003B6705;

loc_003B66F4: ;
    ecx = MEM32(0xF65DC0);
    eax = eax >> 6;
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    MEM32(esp + 0x10) = eax;

loc_003B6705: ;
    ecx = eax;
    ecx = ecx & 0xF;
    edi = edi + ecx;
    if (CMP_L(edi, 0x20)) goto loc_003B6748; /* jl: less (signed <) */

loc_003B6711: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edi = edi - 0x20;
    ebx = edx;
    ecx = edi;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    MEM32(esp + 0x2C) = eax;
    edx = eax;
    eax = MEM32(esp + 0x10);
    esi++;
    goto loc_003B674A;

loc_003B6748: ;
    ebx = ebx << LO8(ecx);

loc_003B674A: ;
    ecx = eax;
    ecx = ecx >> 2;
    ecx = ZX8(LO8(ecx));
    ecx = ecx >> 2;
    if (CMP_EQ(ecx, 0x22)) { RECOMP_SLICE_POINT(); goto loc_003B66C4; } /* je: equal / zero */

loc_003B675E: ;
    if (CMP_NE(ecx, 0x23)) goto loc_003B676F; /* jne: not equal / not zero */

loc_003B6763: ;
    MEM32(ebp + 0x334) = MEM32(ebp + 0x334) + 0x21;
    { RECOMP_SLICE_POINT(); goto loc_003B66C4; }

loc_003B676F: ;
    if (CMP_EQ(ecx, 0x24)) goto loc_003B6BB5; /* je: equal / zero */

loc_003B6778: ;
    MEM32(ebp + 0x334) = MEM32(ebp + 0x334) + ecx;
    ecx = MEM32(ebp + 0x334);
    eax = eax >> 0xA;
    MEM32(ebp + 0x344) = eax;
    if (CMP_G(ecx, MEM32(ebp + 0x340))) goto loc_003B6BB5; /* jg: greater (signed >) */

loc_003B6799: ;
    ecx = ecx - MEM32(esp + 0x1C);
    eax = MEM32(ebp + 0x33C);
    eax = eax + ecx;
    MEM32(esp + 0x10) = ecx;
    ecx = eax;
    MEM32(ebp + 0x33C) = eax;
    eax = MEM32(ebp + 0x1D8);
    if (CMP_L(ecx, eax)) goto loc_003B67DA; /* jl: less (signed <) */

loc_003B67BB: ;
    goto loc_003B67C0;

    /* nop */

loc_003B67C0: ;
    MEM32(ebp + 0x33C) = MEM32(ebp + 0x33C) - eax;
    MEM32(ebp + 0x338) = MEM32(ebp + 0x338) + 1;
    ecx = MEM32(ebp + 0x33C);
    if (CMP_GE(ecx, MEM32(ebp + 0x1D8))) { RECOMP_SLICE_POINT(); goto loc_003B67C0; } /* jge: greater or equal (signed >=) */

loc_003B67DA: ;
    eax = MEM32(esp + 0x10);
    if (CMP_EQ(eax, 0xFFFFFFFEu)) goto loc_003B6BB5; /* je: equal / zero */

loc_003B67E7: ;
    ecx = MEM32(esp + 0x18);
    if (TEST_NZ(ecx, ecx)) goto loc_003B6815; /* jne: not equal / not zero */

loc_003B67EF: ;
    if (CMP_BE(eax, 1)) goto loc_003B6815; /* jbe: below or equal (unsigned <=) */

loc_003B67F4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, ebp);
    { uint32_t _icall_t = MEM32(ebp + 0x2C4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B67FC: ;
    edx = ebp + 0x2EC;
    PUSH32(esp, edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5CE0(); /* call 0x003B5CE0 */

loc_003B6808: ;
    PUSH32(esp, ebp);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D00(); /* call 0x003B5D00 */

loc_003B680E: ;
    edx = MEM32(esp + 0x3C);
    esp = esp + 0x10;

loc_003B6815: ;
    if (TEST_NZ(MEM8(ebp + 0x344), 0x20)) goto loc_003B6893; /* jne: not equal / not zero */

loc_003B681E: ;
    eax = ebx;
    eax = eax >> 0x1B;
    /* cmp edi, 0x1B - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(edi, 0x1B)) goto loc_003B683F; /* jle: less or equal (signed <=) */

loc_003B682C: ;
    ecx = 0x3B;
    ecx = ecx - edi;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B683F: ;
    ecx = MEM32(0xF65DAC);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    ecx = eax;
    ecx = ecx >> 8;
    MEM32(ebp + 0x344) = ecx;
    ecx = ZX8(LO8(eax));
    edi = edi + ecx;
    if (CMP_L(edi, 0x20)) goto loc_003B6891; /* jl: less (signed <) */

loc_003B685E: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edi = edi - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = edi;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    edx = eax;
    goto loc_003B6893;

loc_003B6891: ;
    ebx = ebx << LO8(ecx);

loc_003B6893: ;
    if (TEST_Z(MEM8(ebp + 0x344), 0x10)) goto loc_003B68FD; /* je: equal / zero */

loc_003B689C: ;
    if (CMP_L(edi, 0x1B)) goto loc_003B68EC; /* jl: less (signed <) */

loc_003B68A1: ;
    edi = edi - 0x1B;
    if ((edi == 0)) goto loc_003B68BC; /* je: equal / zero */

loc_003B68A6: ;
    ecx = 5;
    ecx = ecx - edi;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = edi;
    eax = eax | ebx;
    eax = eax >> 0x1B;
    edx = edx << LO8(ecx);
    goto loc_003B68C1;

loc_003B68BC: ;
    eax = ebx;
    eax = eax >> 0x1B;

loc_003B68C1: ;
    ecx = (uint32_t)(int32_t)SMEM8(esi);
    esi++;
    ecx = ecx << 8;
    ebx = edx;
    edx = ZX8(MEM8(esi));
    ecx = ecx | edx;
    edx = ZX8(MEM8(esi + 1));
    esi++;
    ecx = ecx << 8;
    ecx = ecx | edx;
    edx = ZX8(MEM8(esi + 1));
    esi++;
    ecx = ecx << 8;
    ecx = ecx | edx;
    MEM32(esp + 0x2C) = ecx;
    esi++;
    edx = ecx;
    goto loc_003B68F7;

loc_003B68EC: ;
    eax = ebx;
    edi = edi + 5;
    eax = eax >> 0x1B;
    ebx = ebx << 5;

loc_003B68F7: ;
    MEM32(ebp + 0x2E8) = eax;

loc_003B68FD: ;
    if (TEST_Z(MEM8(ebp + 0x344), 8)) goto loc_003B696B; /* je: equal / zero */

loc_003B6906: ;
    eax = ebp + 0x2FC;
    PUSH32(esp, eax);
    ecx = ebp + 0x304;
    MEM32(ebp + 0xC) = esi;
    PUSH32(esp, ecx);
    esi = ebp + 0x2EC;
    PUSH32(esp, esi);
    PUSH32(esp, ebp);
    MEM32(ebp) = ebx;
    MEM32(ebp + 4) = edx;
    MEM32(ebp + 8) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B692D: ;
    edx = ebp + 0x300;
    PUSH32(esp, edx);
    MEM32(esp + 0x30) = eax;
    eax = ebp + 0x308;
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    PUSH32(esp, ebp);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D20(); /* call 0x003B5D20 */

loc_003B6946: ;
    ecx = MEM32(ebp + 4);
    ebx = MEM32(ebp);
    edi = MEM32(ebp + 8);
    esi = MEM32(ebp + 0xC);
    MEM32(esp + 0x4C) = ecx;
    ecx = MEM32(esp + 0x3C);
    esp = esp + 0x20;
    eax = eax | ecx;
    if ((eax != 0)) goto loc_003B6BB5; /* jne: not equal / not zero */

loc_003B6965: ;
    edx = MEM32(esp + 0x2C);
    goto loc_003B697A;

loc_003B696B: ;
    eax = ebp + 0x2EC;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5CE0(); /* call 0x003B5CE0 */

loc_003B6977: ;
    esp = esp + 4;

loc_003B697A: ;
    if (TEST_Z(MEM8(ebp + 0x344), 2)) goto loc_003B69FD; /* je: equal / zero */

loc_003B6983: ;
    eax = ebx;
    eax = eax >> 0x17;
    /* cmp edi, 0x17 - flags set for next jcc */
    MEM32(esp + 0x10) = eax;
    if (CMP_LE(edi, 0x17)) goto loc_003B69A4; /* jle: less or equal (signed <=) */

loc_003B6991: ;
    ecx = 0x37;
    ecx = ecx - edi;
    eax = edx;
    eax = eax >> LO8(ecx);
    ecx = eax;
    eax = MEM32(esp + 0x10);
    eax = eax | ecx;

loc_003B69A4: ;
    ecx = MEM32(0xF65DD4);
    eax = (uint32_t)(int32_t)SMEM16(ecx + eax * 2);
    ecx = eax;
    ecx = ecx & 0xFFFFFFF0u;
    ecx = ecx << 0x10;
    MEM32(ebp + 0x348) = ecx;
    ecx = ZX8(LO8(eax));
    edi = edi + ecx;
    if (CMP_L(edi, 0x20)) goto loc_003B69F9; /* jl: less (signed <) */

loc_003B69C6: ;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edi = edi - 0x20;
    ebx = edx;
    edx = ZX8(MEM8(esi + 1));
    ecx = edi;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    edx = eax;
    goto loc_003B6A07;

loc_003B69F9: ;
    ebx = ebx << LO8(ecx);
    goto loc_003B6A07;

loc_003B69FD: ;
    MEM32(ebp + 0x348) = 0;

loc_003B6A07: ;
    /* test MEM8(ebp + 0x344), 1 - flags set for next jcc */
    MEM32(ebp) = ebx;
    MEM32(ebp + 4) = edx;
    MEM32(ebp + 8) = edi;
    MEM32(ebp + 0xC) = esi;
    if (TEST_Z(MEM8(ebp + 0x344), 1)) goto loc_003B6A2C; /* je: equal / zero */

loc_003B6A1C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    { uint32_t _icall_t = MEM32(ebp + 0x2C8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6A23: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    { uint32_t _icall_t = MEM32(ebp + 0x2D0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6A2A: ;
    goto loc_003B6A4D;

loc_003B6A2C: ;
    eax = MEM32(ebp + 0x348);
    if (TEST_Z(eax, eax)) goto loc_003B6A40; /* je: equal / zero */

loc_003B6A36: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    { uint32_t _icall_t = MEM32(ebp + 0x2CC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6A3D: ;
    esp = esp + 4;

loc_003B6A40: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    { uint32_t _icall_t = MEM32(ebp + 0x2DC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6A47: ;
    PUSH32(esp, ebp);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B5D00(); /* call 0x003B5D00 */

loc_003B6A4D: ;
    ecx = MEM32(ebp + 0x1324);
    esp = esp + 8;
    ecx--;
    eax = ecx;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + 0x1324) = ecx;
    if (CMP_G(eax & eax, 0)) goto loc_003B6A7F; /* jg: greater (signed >) */

loc_003B6A63: ;
    ecx = MEM32(ebp + 0x1B4);
    eax = MEM32(ebp + 0x1AC);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    MEM32(ebp + 0x1324) = eax;
    { uint32_t _icall_t = MEM32(ebp + 0x1B0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6A7C: ;
    esp = esp + 4;

loc_003B6A7F: ;
    edi = MEM32(ebp + 8);
    edx = MEM32(ebp + 4);
    esi = MEM32(ebp + 0xC);
    ebx = MEM32(ebp);
    eax = edi;
    eax = eax & 7;
    ecx = edi;
    ecx = ecx - eax;
    ecx = ecx + 7;
    MEM32(esp + 0x2C) = edx;
    MEM32(esp + 0x1C) = eax;
    eax = MEM32(esp + 0x14);
    edx = MEM32(eax);
    ecx = (uint32_t)((int32_t)ecx >> 3);
    ecx = ecx - edx;
    edx = MEM32(ebp + 0x130C);
    ecx = ecx + esi + -8;
    edx = edx - ecx;
    if (CMP_G(edx, 0x800)) goto loc_003B6BA4; /* jg: greater (signed >) */

loc_003B6AC2: ;
    edx = esp + 0x20;
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B6ACF: ;
    edi = MEM32(esp + 0x24);
    esi = MEM32(esp + 0x40);
    eax = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6AE0: ;
    ecx = MEM32(esi);
    edx = esp + 0x3C;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(ecx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6AED: ;
    eax = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0x7FFFFFFF);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0x18); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6AFB: ;
    edi = MEM32(edi);
    esi = edi;
    esi = esi & 0xFFFFFFFCu;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    edi = edi - esi;
    edi = edi << 3;
    esp = esp + 0x38;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi + 1);
    esi++;
    edx = ZX8(MEM8(esi + 1));
    ecx = edi;
    ebx = ebx << LO8(ecx);
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    ecx = MEM32(esp + 0x1C);
    esi++;
    eax = eax << 8;
    eax = eax | edx;
    edi = edi + ecx;
    esi++;
    /* cmp edi, 0x20 - flags set for next jcc */
    MEM32(esp + 0x2C) = eax;
    if (CMP_L(edi, 0x20)) goto loc_003B6BA2; /* jl: less (signed <) */

loc_003B6B64: ;
    ebx = eax;
    eax = (uint32_t)(int32_t)SMEM8(esi);
    edi = edi - 0x20;
    ecx = edi;
    ebx = ebx << LO8(ecx);
    ecx = ZX8(MEM8(esi + 1));
    esi++;
    edx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | ecx;
    esi++;
    ecx = ZX8(MEM8(esi + 1));
    eax = eax << 8;
    eax = eax | edx;
    esi++;
    eax = eax << 8;
    eax = eax | ecx;
    MEM32(esp + 0x2C) = eax;
    esi++;
    MEM32(esp + 0x18) = 0;
    edx = eax;
    { RECOMP_SLICE_POINT(); goto loc_003B6691; }

loc_003B6BA2: ;
    ebx = ebx << LO8(ecx);

loc_003B6BA4: ;
    edx = MEM32(esp + 0x2C);
    MEM32(esp + 0x18) = 0;
    { RECOMP_SLICE_POINT(); goto loc_003B6691; }

loc_003B6BB5: ;
    ebx = MEM32(esp + 0x14);
    ebp = MEM32(ebx);
    edi = edi + 7;
    edx = esp + 0x20;
    PUSH32(esp, edx);
    edi = (uint32_t)((int32_t)edi >> 3);
    edi = edi - ebp;
    PUSH32(esp, ebx);
    eax = edi + esi + -8;
    PUSH32(esp, eax);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00307070(); /* call 0x00307070 */

loc_003B6BD4: ;
    esi = MEM32(esp + 0x40);
    ecx = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(ecx + 0x20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6BE1: ;
    edx = MEM32(esi);
    eax = esp + 0x3C;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(edx + 0x1C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B6BEE: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_0031F700(); /* call 0x0031F700 */

loc_003B6BF4: ;
    esp = esp + 0x2C;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0x18;
    esp += 4; return; /* ret */

}

/**
 * sub_003B6C00
 * Original: 0x003B6C00 - 0x003B6C13 (19 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6C00(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B6C00: ;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, edi);
    edx = edx + 4;
    MEM32(esp + 0x10) = 6;
    g_seh_ebp = ebp; sub_003B6C17(); return; /* tail jmp 0x003B6C17 */

}

/**
 * sub_003B6C13
 * Original: 0x003B6C13 - 0x003B6C17 (4 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6C13(void)
{

loc_003B6C13: ;
    edx = MEM32(esp + 0x14);

    sub_003B6C17(); return; /* restored dropped fall-through to sub_003B6C17 */
}

/**
 * sub_003B6C17
 * Original: 0x003B6C17 - 0x003B6EB0 (665 bytes, 202 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6C17(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B6C17: ;
    eax = MEM32(edx);
    edi = MEM32(edx + 4);
    edx = edx + 4;
    edx = edx + 4;
    /* test LO8(eax), 0x1F - flags set for next jcc */
    MEM32(esp + 0x14) = edx;
    if (TEST_NZ(LO8(eax), 0x1F)) goto loc_003B6CB1; /* jne: not equal / not zero */

loc_003B6C2E: ;
    ebp = 8;

loc_003B6C33: ;
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 4);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 2);
    SET_LO8(edx, MEM8(edx + esi));
    /* prefetcht0 byte ptr [eax] */
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 6);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 1) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 2) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 3) = LO8(edx);
    MEM8(eax) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xC);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0xA);
    SET_LO8(edx, MEM8(edx + esi));
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xE);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 8);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 5) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 6) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 4) = LO8(ebx);
    MEM8(eax + 7) = LO8(edx);
    ecx = ecx + 0x10;
    eax = eax + edi;
    ebp--;
    if ((ebp != 0)) { RECOMP_SLICE_POINT(); goto loc_003B6C33; } /* jne: not equal / not zero */

loc_003B6CAC: ;
    goto loc_003B6E98;

loc_003B6CB1: ;
    ebp = 2;
    goto loc_003B6CC0;

    /* nop */
    /* nop */

loc_003B6CC0: ;
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 4);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 2);
    SET_LO8(edx, MEM8(edx + esi));
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 6);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 1) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 2) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 3) = LO8(edx);
    MEM8(eax) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xC);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0xA);
    SET_LO8(edx, MEM8(edx + esi));
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xE);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 8);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 5) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 6) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 7) = LO8(edx);
    MEM8(eax + 4) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0x14);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0x12);
    SET_LO8(edx, MEM8(edx + esi));
    ecx = ecx + 0x10;
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 6);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + edi + 1) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + edi + 2) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + edi + 3) = LO8(edx);
    MEM8(eax + edi) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xC);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0xA);
    SET_LO8(edx, MEM8(edx + esi));
    eax = eax + edi;
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xE);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 8);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 5) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 6) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 7) = LO8(edx);
    MEM8(eax + 4) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0x14);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0x12);
    SET_LO8(edx, MEM8(edx + esi));
    ecx = ecx + 0x10;
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 6);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx);
    SET_LO8(ebx, MEM8(ebx + esi));
    eax = eax + edi;
    MEM8(eax + 1) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax) = LO8(ebx);
    MEM8(eax + 2) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 3) = LO8(edx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xC);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0xA);
    SET_LO8(edx, MEM8(edx + esi));
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xE);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 8);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 5) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 6) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 7) = LO8(edx);
    MEM8(eax + 4) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0x14);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0x12);
    SET_LO8(edx, MEM8(edx + esi));
    ecx = ecx + 0x10;
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 6);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + edi + 1) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    eax = eax + edi;
    MEM8(eax + 2) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 3) = LO8(edx);
    MEM8(eax) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xC);
    SET_LO8(ebx, MEM8(ebx + esi));
    edx = (uint32_t)(int32_t)SMEM16(ecx + 0xA);
    SET_LO8(edx, MEM8(edx + esi));
    MEM8(esp + 0xE) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 0xE);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(esp + 0xF) = LO8(ebx);
    ebx = (uint32_t)(int32_t)SMEM16(ecx + 8);
    SET_LO8(ebx, MEM8(ebx + esi));
    MEM8(eax + 5) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xE));
    MEM8(eax + 6) = LO8(edx);
    SET_LO8(edx, MEM8(esp + 0xF));
    MEM8(eax + 4) = LO8(ebx);
    MEM8(eax + 7) = LO8(edx);
    ecx = ecx + 0x10;
    eax = eax + edi;
    ebp--;
    if ((ebp != 0)) { RECOMP_SLICE_POINT(); goto loc_003B6CC0; } /* jne: not equal / not zero */

loc_003B6E98: ;
    MEM32(esp + 0x10) = MEM32(esp + 0x10) - 1;
    if ((MEM32(esp + 0x10) != 0)) { g_seh_ebp = ebp; sub_003B6C13(); return; } /* jne: not equal / not zero */

loc_003B6EA2: ;
    POP32(esp, edi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0xC;
    esp += 4; return; /* ret */

}

/**
 * sub_003B6EB0
 * Original: 0x003B6EB0 - 0x003B6F29 (121 bytes, 44 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6EB0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B6EB0: ;
    esp = esp - 0xC;
    ecx = MEM32(eax + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = MEM32(eax + 4);
    PUSH32(esp, edi);
    edi = MEM32(eax);
    edx = edx + 4;
    MEM32(esp + 0x14) = 6;
    /* nop */
    eax = MEM32(edx);
    ebp = MEM32(edx + 4);
    ebx = MEM32(esp + 0x20);
    edx = edx + 4;
    edx = edx + 4;
    /* test ebx, ebx - flags set for next jcc */
    MEM32(esp + 0x18) = edx;
    if (TEST_S(ebx, ebx)) { g_seh_ebp = ebp; sub_003B6F29(); return; } /* jl: less (signed <) */

loc_003B6EE7: ;
    fp_push(MEMD(ecx)); /* fld double */
    esi = esi + 0x80;
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 8)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x10)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x18)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x20)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x28)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x30)); /* fld double */
    ecx = ecx + 0x40;
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    fp_push(MEMD(ecx + -8)); /* fld double */
    MEMD(eax + ebp) = fp_top(); fp_popp(); /* fstp */
    g_seh_ebp = ebp; sub_003B7165(); return; /* tail jmp 0x003B7165 */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
}

/**
 * sub_003B6ED0
 * Original: 0x003B6ED0 - 0x003B6F29 (89 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6ED0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B6ED0: ;
    eax = MEM32(edx);
    ebp = MEM32(edx + 4);
    ebx = MEM32(esp + 0x20);
    edx = edx + 4;
    edx = edx + 4;
    /* test ebx, ebx - flags set for next jcc */
    MEM32(esp + 0x18) = edx;
    if (TEST_S(ebx, ebx)) { g_seh_ebp = ebp; sub_003B6F29(); return; } /* jl: less (signed <) */

loc_003B6EE7: ;
    fp_push(MEMD(ecx)); /* fld double */
    esi = esi + 0x80;
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 8)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x10)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x18)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x20)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x28)); /* fld double */
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    eax = eax + ebp;
    fp_push(MEMD(ecx + 0x30)); /* fld double */
    ecx = ecx + 0x40;
    MEMD(eax) = fp_top(); fp_popp(); /* fstp */
    fp_push(MEMD(ecx + -8)); /* fld double */
    MEMD(eax + ebp) = fp_top(); fp_popp(); /* fstp */
    g_seh_ebp = ebp; sub_003B7165(); return; /* tail jmp 0x003B7165 */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
}

/**
 * sub_003B6F29
 * Original: 0x003B6F29 - 0x003B7165 (572 bytes, 178 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B6F29(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B6F29: ;
    MEM32(esp + 0x10) = 2;

loc_003B6F31: ;
    edx = ZX8(MEM8(ecx));
    ebx = (uint32_t)(int32_t)SMEM16(esi);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax) = LO8(edx);
    edx = ZX8(MEM8(ecx + 1));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 2);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 1) = LO8(edx);
    edx = ZX8(MEM8(ecx + 2));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 4);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 2) = LO8(edx);
    edx = ZX8(MEM8(ecx + 3));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 6);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 3) = LO8(edx);
    edx = ZX8(MEM8(ecx + 4));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 8);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(ecx + 5));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xA);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 5) = LO8(edx);
    edx = ZX8(MEM8(ecx + 6));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xC);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(ecx + 7));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 7) = LO8(edx);
    edx = ZX8(MEM8(ecx + 8));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x10);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp) = LO8(edx);
    edx = ZX8(MEM8(ecx + 9));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x12);
    ecx = ecx + 8;
    esi = esi + 0x10;
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp + 1) = LO8(edx);
    edx = ZX8(MEM8(ecx + 2));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 4);
    eax = eax + ebp;
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 2) = LO8(edx);
    edx = ZX8(MEM8(ecx + 3));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 6);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 3) = LO8(edx);
    edx = ZX8(MEM8(ecx + 4));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 8);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(ecx + 5));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xA);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 5) = LO8(edx);
    edx = ZX8(MEM8(ecx + 6));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xC);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(ecx + 7));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 7) = LO8(edx);
    edx = ZX8(MEM8(ecx + 8));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x10);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp) = LO8(edx);
    edx = ZX8(MEM8(ecx + 9));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x12);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp + 1) = LO8(edx);
    edx = ZX8(MEM8(ecx + 0xA));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x14);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp + 2) = LO8(edx);
    edx = ZX8(MEM8(ecx + 0xB));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x16);
    ecx = ecx + 8;
    esi = esi + 0x10;
    eax = eax + ebp;
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 3) = LO8(edx);
    edx = ZX8(MEM8(ecx + 4));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 8);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(ecx + 5));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xA);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 5) = LO8(edx);
    edx = ZX8(MEM8(ecx + 6));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xC);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(ecx + 7));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 7) = LO8(edx);
    edx = ZX8(MEM8(ecx + 8));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x10);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp) = LO8(edx);
    edx = ZX8(MEM8(ecx + 9));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0x12);
    ecx = ecx + 8;
    esi = esi + 0x10;
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + ebp + 1) = LO8(edx);
    edx = ZX8(MEM8(ecx + 2));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 4);
    eax = eax + ebp;
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 2) = LO8(edx);
    edx = ZX8(MEM8(ecx + 3));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 6);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 3) = LO8(edx);
    edx = ZX8(MEM8(ecx + 4));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 8);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(ecx + 5));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xA);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 5) = LO8(edx);
    edx = ZX8(MEM8(ecx + 6));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xC);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(ecx + 7));
    ebx = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    edx = edx + edi;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 7) = LO8(edx);
    edx = MEM32(esp + 0x10);
    ecx = ecx + 8;
    esi = esi + 0x10;
    eax = eax + ebp;
    edx--;
    MEM32(esp + 0x10) = edx;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003B6F31; } /* jne: not equal / not zero */

loc_003B7161: ;
    edx = MEM32(esp + 0x18);

    g_seh_ebp = ebp; sub_003B7165(); return; /* restored dropped fall-through to sub_003B7165 */
}

/**
 * sub_003B7165
 * Original: 0x003B7165 - 0x003B7190 (43 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7165(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7165: ;
    ebx = MEM32(esp + 0x20);
    eax = MEM32(esp + 0x14);
    ebx = ebx << 1;
    eax--;
    MEM32(esp + 0x20) = ebx;
    MEM32(esp + 0x14) = eax;
    if ((eax != 0)) { g_seh_ebp = ebp; sub_003B6ED0(); return; } /* jne: not equal / not zero */

loc_003B717E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0xC;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7190
 * Original: 0x003B7190 - 0x003B7438 (680 bytes, 202 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7190(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7190: ;
    esp = esp - 0x10;
    ecx = MEM32(eax + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebp = MEM32(eax);
    PUSH32(esp, esi);
    esi = MEM32(eax + 0xC);
    PUSH32(esp, edi);
    edi = MEM32(eax + 4);
    edx = edx + 4;
    MEM32(esp + 0x1C) = 6;
    /* nop */
    eax = MEM32(edx);
    ebx = MEM32(edx + 4);
    edx = edx + 4;
    edx = edx + 4;
    MEM32(esp + 0x18) = edx;
    edx = MEM32(esp + 0x24);
    /* test edx, edx - flags set for next jcc */
    MEM32(esp + 0x10) = ebx;
    if (TEST_S(edx, edx)) { g_seh_ebp = ebp; sub_003B7438(); return; } /* jl: less (signed <) */

loc_003B71CF: ;
    edi = edi + 0x80;
    MEM32(esp + 0x14) = 2;
    /* nop */

loc_003B71E0: ;
    ebx = ZX8(MEM8(ecx));
    edx = ZX8(MEM8(esi));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 1));
    edx = ZX8(MEM8(esi + 1));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    ecx = ecx + 8;
    esi = esi + 8;
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(esi + 7));
    ebx = ZX8(MEM8(ecx + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 0xA));
    edx = ZX8(MEM8(esi + 0xA));
    edx = edx + ebx + 1;
    ecx = ecx + 8;
    esi = esi + 8;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    ecx = ecx + 8;
    esi = esi + 8;
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(esi + 5));
    ebx = ZX8(MEM8(ecx + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    ebx = MEM32(esp + 0x10);
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    edx = MEM32(esp + 0x14);
    ecx = ecx + 8;
    esi = esi + 8;
    eax = eax + ebx;
    edx--;
    MEM32(esp + 0x14) = edx;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003B71E0; } /* jne: not equal / not zero */

loc_003B7433: ;
    g_seh_ebp = ebp; sub_003B752A(); return; /* tail jmp 0x003B752A */

}

/**
 * sub_003B71B0
 * Original: 0x003B71B0 - 0x003B7438 (648 bytes, 190 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B71B0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B71B0: ;
    eax = MEM32(edx);
    ebx = MEM32(edx + 4);
    edx = edx + 4;
    edx = edx + 4;
    MEM32(esp + 0x18) = edx;
    edx = MEM32(esp + 0x24);
    /* test edx, edx - flags set for next jcc */
    MEM32(esp + 0x10) = ebx;
    if (TEST_S(edx, edx)) { g_seh_ebp = ebp; sub_003B7438(); return; } /* jl: less (signed <) */

loc_003B71CF: ;
    edi = edi + 0x80;
    MEM32(esp + 0x14) = 2;
    /* nop */

loc_003B71E0: ;
    ebx = ZX8(MEM8(ecx));
    edx = ZX8(MEM8(esi));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 1));
    edx = ZX8(MEM8(esi + 1));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    ecx = ecx + 8;
    esi = esi + 8;
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    edx = ZX8(MEM8(esi + 7));
    ebx = ZX8(MEM8(ecx + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 0xA));
    edx = ZX8(MEM8(esi + 0xA));
    edx = edx + ebx + 1;
    ecx = ecx + 8;
    esi = esi + 8;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 8));
    eax = eax + MEM32(esp + 0x10);
    edx = ZX8(MEM8(esi + 8));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 9));
    edx = ZX8(MEM8(esi + 9));
    ecx = ecx + 8;
    esi = esi + 8;
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 4) = LO8(edx);
    edx = ZX8(MEM8(esi + 5));
    ebx = ZX8(MEM8(ecx + 5));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    ebx = MEM32(esp + 0x10);
    edx = (uint32_t)((int32_t)edx >> 1);
    MEM8(eax + 7) = LO8(edx);
    edx = MEM32(esp + 0x14);
    ecx = ecx + 8;
    esi = esi + 8;
    eax = eax + ebx;
    edx--;
    MEM32(esp + 0x14) = edx;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003B71E0; } /* jne: not equal / not zero */

loc_003B7433: ;
    g_seh_ebp = ebp; sub_003B752A(); return; /* tail jmp 0x003B752A */

}

/**
 * sub_003B7438
 * Original: 0x003B7438 - 0x003B752A (242 bytes, 74 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7438(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7438: ;
    MEM32(esp + 0x14) = 8;

loc_003B7440: ;
    ebx = ZX8(MEM8(ecx));
    edx = ZX8(MEM8(esi));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 1));
    edx = ZX8(MEM8(esi + 1));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 2);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 1) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 2));
    edx = ZX8(MEM8(esi + 2));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 4);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 2) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 3));
    edx = ZX8(MEM8(esi + 3));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 6);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(esi + 4));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 8);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 4) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 5));
    edx = ZX8(MEM8(esi + 5));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 0xA);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 5) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 6));
    edx = ZX8(MEM8(esi + 6));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 0xC);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    MEM8(eax + 6) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 7));
    edx = ZX8(MEM8(esi + 7));
    edx = edx + ebx + 1;
    ebx = (uint32_t)(int32_t)SMEM16(edi + 0xE);
    edx = (uint32_t)((int32_t)edx >> 1);
    edx = edx + ebp;
    SET_LO8(edx, MEM8(ebx + edx));
    ebx = MEM32(esp + 0x10);
    MEM8(eax + 7) = LO8(edx);
    edx = MEM32(esp + 0x14);
    ecx = ecx + 8;
    esi = esi + 8;
    edi = edi + 0x10;
    eax = eax + ebx;
    edx--;
    MEM32(esp + 0x14) = edx;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003B7440; } /* jne: not equal / not zero */

    g_seh_ebp = ebp; sub_003B752A(); return; /* restored dropped fall-through to sub_003B752A */
}

/**
 * sub_003B752A
 * Original: 0x003B752A - 0x003B7550 (38 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B752A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B752A: ;
    ebx = MEM32(esp + 0x24);
    eax = MEM32(esp + 0x1C);
    edx = MEM32(esp + 0x18);
    ebx = ebx << 1;
    eax--;
    MEM32(esp + 0x24) = ebx;
    MEM32(esp + 0x1C) = eax;
    if ((eax != 0)) { g_seh_ebp = ebp; sub_003B71B0(); return; } /* jne: not equal / not zero */

loc_003B7547: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0x10;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7550
 * Original: 0x003B7550 - 0x003B7651 (257 bytes, 94 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7550(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7550: ;
    ecx = MEM32(esp + 4);
    PUSH32(esp, ebp);
    ebp = MEM32(esp + 0xC);
    eax = (uint32_t)(int32_t)SMEM16(ebp + 0xC);
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    edx = edx & 7;
    eax = eax + edx;
    edx = MEM32(ecx);
    PUSH32(esp, esi);
    eax = (uint32_t)((int32_t)eax >> 3);
    PUSH32(esp, edi);
    edi = eax + eax;
    edi = edi << 3;
    if (TEST_NZ(LO8(edx), 0x1F)) { g_seh_ebp = ebp; sub_003B7651(); return; } /* jne: not equal / not zero */

loc_003B7579: ;
    esi = MEM32(ebx);
    fp_push(MEMD(esi + edx)); /* fld double */
    ecx = MEM32(ebp);
    /* prefetcht0 byte ptr [ecx + edx] */
    ecx = ecx + edx;
    /* prefetcht0 byte ptr [ecx + eax*8] */
    esi = esi + edx;
    fp_push(MEMD(esi + eax * 8)); /* fld double */
    esi = esi + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(esi)); /* fld double */
    ecx = ecx + edi;
    /* prefetcht0 byte ptr [ecx + eax*8] */
    fp_push(MEMD(esi + eax * 8)); /* fld double */
    esi = esi + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(esi)); /* fld double */
    ecx = ecx + edi;
    /* prefetcht0 byte ptr [ecx + eax*8] */
    fp_push(MEMD(esi + eax * 8)); /* fld double */
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    esi = esi + edi;
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(esi + eax * 8)); /* fld double */
    ecx = ecx + edi;
    /* prefetcht0 byte ptr [ecx + eax*8] */
    fp_push(MEMD(esi)); /* fld double */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    edx = ecx + eax * 8;
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    ecx = MEM32(ebp + 4);
    edx = MEM32(esp + 0x10);
    esi = MEM32(edx);
    edx = MEM32(ebx + 4);
    fp_push(MEMD(edx + esi)); /* fld double */
    /* prefetcht0 byte ptr [ecx + esi] */
    edx = edx + esi;
    fp_push(MEMD(edx + eax * 8)); /* fld double */
    ecx = ecx + esi;
    /* prefetcht0 byte ptr [ecx + eax*8] */
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    edx = edx + edi;
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + edi;
    fp_push(MEMD(edx + eax * 8)); /* fld double */
    /* prefetcht0 byte ptr [ecx + eax*8] */
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    edx = edx + edi;
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + edi;
    fp_push(MEMD(edx + eax * 8)); /* fld double */
    /* prefetcht0 byte ptr [ecx + eax*8] */
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    edx = edx + edi;
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + edi] */
    fp_push(MEMD(edx + eax * 8)); /* fld double */
    ecx = ecx + edi;
    fp_push(MEMD(edx)); /* fld double */
    /* prefetcht0 byte ptr [ecx + eax*8] */
    esi = ecx + eax * 8;
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(esi) = fp_top(); fp_popp(); /* fstp */
    g_seh_ebp = ebp; sub_003B76E0(); return; /* tail jmp 0x003B76E0 */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
}

/**
 * sub_003B7651
 * Original: 0x003B7651 - 0x003B76E0 (143 bytes, 60 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7651(void)
{
    uint32_t ebp;
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7651: ;
    ecx = MEM32(ebx);
    fp_push(MEMD(ecx + edx)); /* fld double */
    esi = MEM32(ebp);
    ecx = ecx + edx;
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    esi = esi + edx;
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(esi) = fp_top(); fp_popp(); /* fstp */
    MEMD(esi + eax * 8) = fp_top(); fp_popp(); /* fstp */
    esi = esi + edi;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(esi) = fp_top(); fp_popp(); /* fstp */
    MEMD(esi + eax * 8) = fp_top(); fp_popp(); /* fstp */
    esi = esi + edi;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(esi) = fp_top(); fp_popp(); /* fstp */
    MEMD(esi + eax * 8) = fp_top(); fp_popp(); /* fstp */
    esi = esi + edi;
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    fp_push(MEMD(ecx)); /* fld double */
    ecx = MEM32(esp + 0x10);
    MEMD(esi) = fp_top(); fp_popp(); /* fstp */
    MEMD(esi + eax * 8) = fp_top(); fp_popp(); /* fstp */
    esi = MEM32(ecx);
    ecx = MEM32(ebx + 4);
    fp_push(MEMD(ecx + esi)); /* fld double */
    edx = MEM32(ebp + 4);
    ecx = ecx + esi;
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    edx = edx + esi;
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + edi;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + edi;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    ecx = ecx + edi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + eax * 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + edi;
    fp_push(MEMD(ecx + eax * 8)); /* fld double */
    fp_push(MEMD(ecx)); /* fld double */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + eax * 8) = fp_top(); fp_popp(); /* fstp */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
    g_seh_ebp = ebp; sub_003B76E0(); return; /* restored dropped fall-through to sub_003B76E0 */
}

/**
 * sub_003B76E0
 * Original: 0x003B76E0 - 0x003B7960 (640 bytes, 269 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B76E0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    #define fp_push(v) (g_fp_stack[--g_fp_top & 7] = (v))
    #define fp_pop() (g_fp_top++)
    #define fp_popp() (fp_pop())
    #define fp_top() g_fp_stack[g_fp_top & 7]
    #define fp_st1() g_fp_stack[(g_fp_top + 1) & 7]
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B76E0: ;
    eax = (uint32_t)(int32_t)SMEM16(ebp + 0xE);
    ecx = MEM32(esp + 0x10);
    esi = MEM32(ecx + 4);
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    edx = edx & 7;
    eax = eax + edx;
    SET_LO8(edx, MEM8(ecx + 4));
    eax = (uint32_t)((int32_t)eax >> 3);
    eax = eax << 3;
    if (TEST_NZ(LO8(edx), 0x1F)) goto loc_003B784E; /* jne: not equal / not zero */

loc_003B7703: ;
    edx = MEM32(ebx + 8);
    fp_push(MEMD(edx + esi)); /* fld double */
    ecx = MEM32(ebp + 8);
    fp_push(MEMD(edx + esi + 8)); /* fld double */
    /* prefetcht0 byte ptr [ecx + esi] */
    edx = edx + esi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx + esi) = fp_top(); fp_popp(); /* fstp */
    ecx = ecx + esi;
    edx = edx + eax;
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    POP32(esp, edi);
    POP32(esp, esi);
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    POP32(esp, ebp);
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx + 8)); /* fld double */
    edx = edx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    /* prefetcht0 byte ptr [ecx + eax] */
    fp_push(MEMD(edx + 8)); /* fld double */
    ecx = ecx + eax;
    fp_push(MEMD(edx)); /* fld double */
    MEMD(ecx) = fp_top(); fp_popp(); /* fstp */
    MEMD(ecx + 8) = fp_top(); fp_popp(); /* fstp */
    esp += 4; return; /* ret */

loc_003B784E: ;
    ecx = MEM32(ebx + 8);
    fp_push(MEMD(ecx + esi)); /* fld double */
    edx = MEM32(ebp + 8);
    fp_push(MEMD(ecx + esi + 8)); /* fld double */
    ecx = ecx + esi;
    edx = edx + esi;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    ecx = ecx + eax;
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    POP32(esp, edi);
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    POP32(esp, esi);
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    POP32(esp, ebp);
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx)); /* fld double */
    fp_push(MEMD(ecx + 8)); /* fld double */
    ecx = ecx + eax;
    { double _t = fp_top(); fp_top() = g_fp_stack[(g_fp_top + 1) & 7]; g_fp_stack[(g_fp_top + 1) & 7] = _t; } /* fxch st(1) */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    edx = edx + eax;
    fp_push(MEMD(ecx + 8)); /* fld double */
    fp_push(MEMD(ecx)); /* fld double */
    MEMD(edx) = fp_top(); fp_popp(); /* fstp */
    MEMD(edx + 8) = fp_top(); fp_popp(); /* fstp */
    esp += 4; return; /* ret */

    #undef fp_push
    #undef fp_pop
    #undef fp_popp
    #undef fp_top
    #undef fp_st1
}

/**
 * sub_003B7960
 * Original: 0x003B7960 - 0x003B7993 (51 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7960(void)
{

loc_003B7960: ;
    PUSH32(esp, esi);
    esi = eax;
    eax = MEM32(ecx + 0x338);
    ecx = MEM32(ecx + 0x33C);
    PUSH32(esp, edi);
    edi = (uint32_t)(int32_t)SMEM16(esi + 0xC);
    eax = eax << 3;
    edi = (uint32_t)((int32_t)edi * (int32_t)eax);
    ecx = ecx << 3;
    edi = edi + ecx;
    MEM32(edx) = edi;
    esi = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    eax = eax + eax;
    esi = (uint32_t)((int32_t)esi * (int32_t)eax);
    ecx = esi + ecx * 2;
    POP32(esp, edi);
    MEM32(edx + 4) = ecx;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003B79A0
 * Original: 0x003B79A0 - 0x003B79F5 (85 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B79A0(void)
{
    int _flags = 0; /* fallback flag var */

loc_003B79A0: ;
    PUSH32(esp, esi);
    esi = MEM32(eax + 0x334);
    edx = 1;
    edx = edx - ecx;
    esi = esi + edx;
    edx = 1;
    edx = edx - ecx;
    ecx = MEM32(eax + 0x33C);
    ecx = ecx + edx;
    MEM32(eax + 0x334) = esi;
    MEM32(eax + 0x33C) = ecx;
    if (((int32_t)ecx >= 0)) goto loc_003B79F3; /* jns: not sign (positive) */

loc_003B79CD: ;
    ecx = MEM32(eax + 0x1D8);
    edx = MEM32(eax + 0x33C);
    esi = MEM32(eax + 0x338);
    /* nop */

loc_003B79E0: ;
    edx = edx + ecx;
    esi--;
    if (TEST_S(edx, edx)) { RECOMP_SLICE_POINT(); goto loc_003B79E0; } /* jl: less (signed <) */

loc_003B79E7: ;
    MEM32(eax + 0x338) = esi;
    MEM32(eax + 0x33C) = edx;

loc_003B79F3: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003B7A00
 * Original: 0x003B7A00 - 0x003B7A3C (60 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7A00(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    int _flags = 0; /* fallback flag var */

loc_003B7A00: ;
    ecx = MEM32(eax + 0x33C);
    edx = MEM32(eax + 0x1D8);
    ecx++;
    MEM32(eax + 0x33C) = ecx;
    /* cmp ecx, edx - flags set for next jcc */
    _rccf = (CMP_L(ecx, edx));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    ecx = MEM32(eax + 0x334);
    if (_rccf) goto loc_003B7A34; /* jl: less (signed <) */

loc_003B7A1D: ;
    edx = MEM32(eax + 0x338);
    edx++;
    MEM32(eax + 0x33C) = 0;
    MEM32(eax + 0x338) = edx;

loc_003B7A34: ;
    ecx++;
    MEM32(eax + 0x334) = ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7A40
 * Original: 0x003B7A40 - 0x003B7AB2 (114 bytes, 39 insns)
 * Category: game_video
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7A40(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7A40: ;
    esp = esp - 8;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0x10);
    PUSH32(esp, esi);
    esi = ebx + 0x294;
    PUSH32(esp, edi);
    edx = esp + 0xC;
    eax = esi;
    ecx = ebx;
    edi = ebx + 0x120;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7960(); /* call 0x003B7960 */

loc_003B7A63: ;
    edx = MEM32(esi);
    ecx = (uint32_t)(int32_t)SMEM16(esi + 0xE);
    eax = MEM32(esp + 0xC);
    edx = edx + eax;
    MEM32(edi + 4) = edx;
    edx = MEM32(esi + 4);
    edx = edx + eax;
    MEM32(edi + 0xC) = edx;
    eax = MEM32(esi + 8);
    edx = MEM32(esp + 0x10);
    eax = eax + edx;
    MEM32(edi + 0x14) = eax;
    eax = eax + 8;
    MEM32(edi + 0x1C) = eax;
    eax = MEM32(edi + 0x14);
    eax = eax + ecx * 8;
    MEM32(edi + 0x24) = eax;
    eax = eax + 8;
    MEM32(edi + 0x2C) = eax;
    esi = MEM32(ebx + 0x40);
    ecx = ebx + 0x380;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B6C00(); /* call 0x003B6C00 */

loc_003B7AAB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7AC0
 * Original: 0x003B7AC0 - 0x003B7C6A (426 bytes, 145 insns)
 * Category: game_video
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7AC0(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7AC0: ;
    esp = esp - 0x14;
    ecx = MEM32(esp + 0x18);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebx = eax;
    eax = MEM32(esp + 0x2C);
    edx = (uint32_t)(int32_t)SMEM16(eax + 0xC);
    PUSH32(esp, esi);
    esi = MEM32(ecx + 0x19C);
    PUSH32(esp, edi);
    edi = (uint32_t)(int32_t)SMEM16(eax + 0xE);
    MEM32(esp + 0x10) = edx;
    edx = MEM32(esp + 0x30);
    MEM32(esp + 0x1C) = esi;
    MEM32(esp + 0x14) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7960(); /* call 0x003B7960 */

loc_003B7AF4: ;
    eax = MEM32(ebx + 0x18);
    ebx = MEM32(ebx + 0x1C);
    ebp = ebx;
    ecx = eax;
    ebp = (uint32_t)((int32_t)ebp >> 1);
    ebp = (uint32_t)((int32_t)ebp * (int32_t)edi);
    edi = MEM32(edx + 4);
    ecx = (uint32_t)((int32_t)ecx >> 1);
    ebp = ebp + ecx;
    edx = ebx;
    edx = edx & 1;
    ecx = esi + esi;
    edx = edx + ecx;
    ebp = ebp + edi;
    edi = eax;
    edi = edi & 1;
    ecx = edi + edx * 2;
    edx = MEM32(ecx * 4 + 0xF45858);
    MEM32(esp + 0x20) = edx;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    eax = eax - edx;
    ecx = eax;
    eax = ebx;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    eax = eax - edx;
    eax = (uint32_t)((int32_t)eax >> 1);
    ebx = eax;
    ebx = (uint32_t)((int32_t)ebx >> 1);
    ebx = (uint32_t)((int32_t)ebx * (int32_t)MEM32(esp + 0x10));
    ecx = (uint32_t)((int32_t)ecx >> 1);
    edx = ecx;
    edx = (uint32_t)((int32_t)edx >> 1);
    ebx = ebx + edx;
    edx = MEM32(esp + 0x30);
    ebx = ebx + MEM32(edx);
    eax = eax & 1;
    edx = esi + esi;
    eax = eax + edx;
    ecx = ecx & 1;
    eax = ecx + eax * 2;
    edx = MEM32(eax * 4 + 0xF45858);
    eax = MEM32(esp + 0x2C);
    ecx = ecx & esi;
    esi = MEM32(esp + 0x28);
    esi = esi + 0xCC;
    MEM32(esi + 0x18) = eax;
    eax = MEM32(esp + 0x34);
    MEM32(esp + 0x30) = edx;
    edx = MEM32(esp + 0x10);
    MEM32(esi + 0x20) = edx;
    eax = MEM32(eax);
    eax = eax + ebx;
    MEM32(esi + 0x24) = eax;
    eax = eax + ecx;
    eax = eax + edx;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esp + 0x1C) = ecx;
    MEM32(esi + 0x28) = eax;
    { uint32_t _icall_t = MEM32(esp + 0x34); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7B9A: ;
    ecx = MEM32(esp + 0x30);
    edx = MEM32(esp + 0x38);
    ecx = ecx + 0x40;
    MEM32(esi + 0x18) = ecx;
    eax = MEM32(edx + 4);
    eax = eax + ebx;
    MEM32(esi + 0x24) = eax;
    ecx = MEM32(esp + 0x1C);
    eax = eax + ecx;
    eax = eax + MEM32(esp + 0x14);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi + 0x28) = eax;
    { uint32_t _icall_t = MEM32(esp + 0x38); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7BC2: ;
    ecx = MEM32(esp + 0x1C);
    ebx = MEM32(esp + 0x34);
    eax = MEM32(esp + 0x3C);
    edx = ebx + 0x80;
    MEM32(esi + 0x20) = ecx;
    MEM32(esi + 0x18) = edx;
    eax = MEM32(eax + 8);
    eax = eax + ebp;
    edi = edi & MEM32(esp + 0x24);
    edi = edi + eax;
    edi = edi + ecx;
    MEM32(esi + 0x28) = edi;
    edi = MEM32(esp + 0x28);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi + 0x24) = eax;
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7BF4: ;
    eax = MEM32(esi + 0x24);
    edx = MEM32(esi + 0x28);
    ebp = 8;
    ecx = ebx + 0xC0;
    eax = eax + ebp;
    edx = edx + ebp;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x24) = eax;
    MEM32(esi + 0x28) = edx;
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7C15: ;
    eax = MEM32(esp + 0x24);
    edx = ebx + 0x100;
    MEM32(esi + 0x18) = edx;
    edx = MEM32(esi + 0x24);
    ecx = eax * 8 + -8;
    edx = edx + ecx;
    MEM32(esi + 0x24) = edx;
    edx = eax * 8 + -8;
    eax = MEM32(esi + 0x28);
    eax = eax + edx;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi + 0x28) = eax;
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7C43: ;
    edx = MEM32(esi + 0x28);
    ebx = ebx + 0x140;
    MEM32(esi + 0x18) = ebx;
    ebx = MEM32(esi + 0x24);
    edx = edx + ebp;
    ebx = ebx + ebp;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    MEM32(esi + 0x24) = ebx;
    MEM32(esi + 0x28) = edx;
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7C5F: ;
    esp = esp + 0x18;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp = esp + 0x14;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7C70
 * Original: 0x003B7C70 - 0x003B7CD2 (98 bytes, 36 insns)
 * Category: game_video
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7C70(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B7C70: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp & 0xFFFFFFF8u;
    esp = esp - 0xC;
    ecx = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x334);
    eax = esi;
    ebx = esi + 0x264;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B79A0(); /* call 0x003B79A0 */

loc_003B7C95: ;
    if (CMP_GE(MEM32(esi + 0x334), edi)) goto loc_003B7CCB; /* jge: greater or equal (signed >=) */

loc_003B7C9D: ;
    /* nop */

loc_003B7CA0: ;
    edx = esp + 0x10;
    eax = ebx;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7960(); /* call 0x003B7960 */

loc_003B7CAD: ;
    eax = ebx + 0x10;
    PUSH32(esp, eax);
    eax = edx;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7550(); /* call 0x003B7550 */

loc_003B7CB9: ;
    esp = esp + 8;
    eax = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7A00(); /* call 0x003B7A00 */

loc_003B7CC3: ;
    if (CMP_L(MEM32(esi + 0x334), edi)) { RECOMP_SLICE_POINT(); goto loc_003B7CA0; } /* jl: less (signed <) */

loc_003B7CCB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp);
    esp += 4; return; /* ret */

}

/**
 * sub_003B7CE0
 * Original: 0x003B7CE0 - 0x003B7D29 (73 bytes, 23 insns)
 * Category: game_video
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7CE0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7CE0: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ebx = MEM32(esi + 0x2D4);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x334);
    eax = esi;
    MEM32(esi + 0x348) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B79A0(); /* call 0x003B79A0 */

loc_003B7D08: ;
    if (CMP_GE(MEM32(esi + 0x334), edi)) goto loc_003B7D25; /* jge: greater or equal (signed >=) */

loc_003B7D10: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7D13: ;
    esp = esp + 4;
    eax = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7A00(); /* call 0x003B7A00 */

loc_003B7D1D: ;
    if (CMP_L(MEM32(esi + 0x334), edi)) { RECOMP_SLICE_POINT(); goto loc_003B7D10; } /* jl: less (signed <) */

loc_003B7D25: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003B7D30
 * Original: 0x003B7D30 - 0x003B7DC0 (144 bytes, 43 insns)
 * Category: game_video
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7D30(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7D30: ;
    esp = esp - 8;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    PUSH32(esp, edi);
    ecx = esi + 0x264;
    PUSH32(esp, ecx);
    ecx = MEM32(esi + 0x118);
    edx = esp + 0xC;
    edi = esi + 0x110;
    PUSH32(esp, edx);
    PUSH32(esp, ecx);
    eax = esi + 0x2EC;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7AC0(); /* call 0x003B7AC0 */

loc_003B7D5E: ;
    ecx = MEM32(esi + 0x294);
    eax = MEM32(esp + 0x18);
    ecx = ecx + eax;
    edx = esi + 0x120;
    MEM32(edx + 4) = ecx;
    ecx = MEM32(esi + 0x298);
    ecx = ecx + eax;
    MEM32(edx + 0xC) = ecx;
    eax = MEM32(esi + 0x29C);
    ecx = MEM32(esp + 0x1C);
    eax = eax + ecx;
    MEM32(edx + 0x14) = eax;
    ecx = MEM32(edx + 0x14);
    eax = eax + 8;
    MEM32(edx + 0x1C) = eax;
    eax = (uint32_t)(int32_t)SMEM16(esi + 0x2A2);
    eax = ecx + eax * 8;
    MEM32(edx + 0x24) = eax;
    eax = eax + 8;
    MEM32(edx + 0x2C) = eax;
    eax = MEM32(esi + 0x348);
    PUSH32(esp, eax);
    eax = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B6EB0(); /* call 0x003B6EB0 */

loc_003B7DB7: ;
    esp = esp + 0x14;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7DC0
 * Original: 0x003B7DC0 - 0x003B7E50 (144 bytes, 43 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7DC0(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7DC0: ;
    esp = esp - 8;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    PUSH32(esp, edi);
    ecx = esi + 0x274;
    PUSH32(esp, ecx);
    ecx = MEM32(esi + 0x118);
    edx = esp + 0xC;
    edi = esi + 0x110;
    PUSH32(esp, edx);
    PUSH32(esp, ecx);
    eax = esi + 0x310;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7AC0(); /* call 0x003B7AC0 */

loc_003B7DEE: ;
    ecx = MEM32(esi + 0x294);
    eax = MEM32(esp + 0x18);
    ecx = ecx + eax;
    edx = esi + 0x120;
    MEM32(edx + 4) = ecx;
    ecx = MEM32(esi + 0x298);
    ecx = ecx + eax;
    MEM32(edx + 0xC) = ecx;
    eax = MEM32(esi + 0x29C);
    ecx = MEM32(esp + 0x1C);
    eax = eax + ecx;
    MEM32(edx + 0x14) = eax;
    ecx = MEM32(edx + 0x14);
    eax = eax + 8;
    MEM32(edx + 0x1C) = eax;
    eax = (uint32_t)(int32_t)SMEM16(esi + 0x2A2);
    eax = ecx + eax * 8;
    MEM32(edx + 0x24) = eax;
    eax = eax + 8;
    MEM32(edx + 0x2C) = eax;
    eax = MEM32(esi + 0x348);
    PUSH32(esp, eax);
    eax = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B6EB0(); /* call 0x003B6EB0 */

loc_003B7E47: ;
    esp = esp + 0x14;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7E50
 * Original: 0x003B7E50 - 0x003B7F00 (176 bytes, 59 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7E50(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7E50: ;
    esp = esp - 8;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x14);
    edx = MEM32(esi + 0x118);
    PUSH32(esp, edi);
    ebx = esi + 0x264;
    PUSH32(esp, ebx);
    ecx = esp + 0x10;
    edi = esi + 0x110;
    PUSH32(esp, ecx);
    PUSH32(esp, edx);
    eax = esi + 0x2EC;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7AC0(); /* call 0x003B7AC0 */

loc_003B7E7F: ;
    edx = MEM32(edi + 0xC);
    ebx = ebx + 0x10;
    PUSH32(esp, ebx);
    ecx = esp + 0x20;
    PUSH32(esp, ecx);
    PUSH32(esp, edx);
    eax = esi + 0x310;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7AC0(); /* call 0x003B7AC0 */

loc_003B7E98: ;
    ecx = MEM32(esi + 0x294);
    eax = MEM32(esp + 0x2C);
    ecx = ecx + eax;
    edx = esi + 0x120;
    MEM32(edx + 4) = ecx;
    ecx = MEM32(esi + 0x298);
    ecx = ecx + eax;
    MEM32(edx + 0xC) = ecx;
    eax = MEM32(esi + 0x29C);
    ecx = MEM32(esp + 0x30);
    eax = eax + ecx;
    MEM32(edx + 0x14) = eax;
    ecx = MEM32(edx + 0x14);
    eax = eax + 8;
    MEM32(edx + 0x1C) = eax;
    eax = (uint32_t)(int32_t)SMEM16(esi + 0x2A2);
    eax = ecx + eax * 8;
    MEM32(edx + 0x24) = eax;
    eax = eax + 8;
    MEM32(edx + 0x2C) = eax;
    eax = MEM32(esi + 0x348);
    PUSH32(esp, eax);
    eax = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B7190(); /* call 0x003B7190 */

loc_003B7EF1: ;
    esp = esp + 0x24;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B7F00
 * Original: 0x003B7F00 - 0x003B7FE4 (228 bytes, 69 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7F00(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7F00: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    edx = esi + 0x680;
    eax = 0; /* xor self */
    edi = edx;
    ecx = 0x180;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(esi + 0x2E8);
    edi = esi + 0x44;
    ecx = esi + 0xC80;
    MEM32(edi + 0x20) = ecx;
    MEM32(edi + 0x24) = eax;
    MEM32(edi + 0x30) = 0;
    eax = MEM32(esi + 0x1328);
    ecx = esi + 0x34C;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    ebx = esi + 0x78;
    MEM32(edi + 0x2C) = eax;
    MEM32(edi + 0x28) = ecx;
    MEM32(edi + 0x1C) = edx;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7F54: ;
    edx = esi + 0x780;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(ebx) = LO8(eax);
    PUSH32(esp, esi);
    MEM32(edi + 0x1C) = edx;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7F67: ;
    MEM8(ebx + 1) = LO8(eax);
    eax = esi + 0x880;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    MEM32(edi + 0x1C) = eax;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7F7B: ;
    ecx = esi + 0x980;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(ebx + 2) = LO8(eax);
    PUSH32(esp, esi);
    MEM32(edi + 0x1C) = ecx;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7F8F: ;
    MEM8(ebx + 3) = LO8(eax);
    edx = MEM32(esi + 0x132C);
    eax = esi + 0x350;
    ecx = esi + 0xA80;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    MEM32(edi + 0x2C) = edx;
    MEM32(edi + 0x28) = eax;
    MEM32(edi + 0x1C) = ecx;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7FB5: ;
    MEM8(ebx + 4) = LO8(eax);
    edx = esi + 0x354;
    eax = esi + 0xB80;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    MEM32(edi + 0x28) = edx;
    MEM32(edi + 0x1C) = eax;
    { uint32_t _icall_t = MEM32(esi + 0x1318); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B7FD2: ;
    PUSH32(esp, ebx);
    MEM8(ebx + 5) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00328D20(); /* call 0x00328D20 */

loc_003B7FDB: ;
    esp = esp + 0x34;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = 0; /* xor self */
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003B7FF0
 * Original: 0x003B7FF0 - 0x003B807C (140 bytes, 48 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B7FF0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B7FF0: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x14);
    ecx = MEM32(esi + 0x2E8);
    PUSH32(esp, edi);
    edi = esi + 0x44;
    edx = esi + 0xCC0;
    MEM32(edi + 0x24) = ecx;
    MEM32(edi + 0x20) = edx;
    MEM32(edi + 0x30) = 1;
    ebx = MEM32(esi + 0x348);
    eax = esi + 0x78;
    ebx = ebx << 2;
    MEM32(esp + 0x10) = eax;
    MEM32(eax + 0x28) = ebx;
    eax = esi + 0x680;
    ebp = 0; /* xor self */
    MEM32(esp + 0x18) = eax;

loc_003B8034: ;
    if (CMP_GE(ebx & ebx, 0)) goto loc_003B8051; /* jge: greater or equal (signed >=) */

loc_003B8038: ;
    ecx = MEM32(esp + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    MEM32(edi + 0x1C) = ecx;
    { uint32_t _icall_t = MEM32(esi + 0x131C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8047: ;
    edx = MEM32(esp + 0x18);
    esp = esp + 8;
    MEM8(edx + ebp) = LO8(eax);

loc_003B8051: ;
    ecx = MEM32(esp + 0x18);
    ebx = ebx << 1;
    ebp++;
    ecx = ecx + 0x100;
    /* cmp ebp, 6 - flags set for next jcc */
    MEM32(esp + 0x18) = ecx;
    if (CMP_L(ebp, 6)) { RECOMP_SLICE_POINT(); goto loc_003B8034; } /* jl: less (signed <) */

loc_003B8067: ;
    eax = MEM32(esp + 0x10);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00328D30(); /* call 0x00328D30 */

loc_003B8071: ;
    esp = esp + 4;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = 0; /* xor self */
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003B8080
 * Original: 0x003B8080 - 0x003B81A0 (288 bytes, 93 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8080(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B8080: ;
    edx = MEM32(esp + 4);
    eax = MEM32(edx + 0x24);
    ecx = MEM32(edx + 0x28);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = MEM32(edx + 0x18);
    PUSH32(esp, edi);
    edi = MEM32(edx + 0x20);
    ebp = 8;
    /* nop */

loc_003B80A0: ;
    ebx = ZX8(MEM8(eax));
    edx = ZX8(MEM8(ecx));
    edx = edx + ebx;
    ebx = ZX8(MEM8(eax + 1));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 1));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi) = LO8(edx);
    ebx = ZX8(MEM8(eax + 1));
    edx = ZX8(MEM8(eax + 2));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 1));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 2));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 1) = LO8(edx);
    ebx = ZX8(MEM8(eax + 3));
    edx = ZX8(MEM8(eax + 2));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 2));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 3));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 2) = LO8(edx);
    ebx = ZX8(MEM8(eax + 3));
    edx = ZX8(MEM8(ecx + 4));
    edx = edx + ebx;
    ebx = ZX8(MEM8(eax + 4));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 3));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 3) = LO8(edx);
    ebx = ZX8(MEM8(ecx + 4));
    edx = ZX8(MEM8(eax + 5));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 5));
    edx = edx + ebx;
    ebx = ZX8(MEM8(eax + 4));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 4) = LO8(edx);
    ebx = ZX8(MEM8(eax + 6));
    edx = ZX8(MEM8(eax + 5));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 5));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 6));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 5) = LO8(edx);
    ebx = ZX8(MEM8(eax + 7));
    edx = ZX8(MEM8(eax + 6));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 6));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 7));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 6) = LO8(edx);
    ebx = ZX8(MEM8(eax + 8));
    edx = ZX8(MEM8(ecx + 8));
    edx = edx + ebx;
    ebx = ZX8(MEM8(eax + 7));
    edx = edx + ebx;
    ebx = ZX8(MEM8(ecx + 7));
    edx = edx + ebx + 2;
    edx = (uint32_t)((int32_t)edx >> 2);
    MEM8(esi + 7) = LO8(edx);
    eax = eax + edi;
    ecx = ecx + edi;
    esi = esi + 8;
    ebp--;
    if ((ebp != 0)) { RECOMP_SLICE_POINT(); goto loc_003B80A0; } /* jne: not equal / not zero */

loc_003B819B: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003B81A0
 * Original: 0x003B81A0 - 0x003B8250 (176 bytes, 67 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B81A0(void)
{
    uint64_t mm0;

loc_003B81A0: ;
    esp = esp - 0xC;
    eax = MEM32(esp + 0x10);
    ecx = MEM32(eax + 0x20);
    edx = MEM32(eax + 0x24);
    MEM32(esp + 0x10) = ecx;
    ecx = MEM32(eax + 0x28);
    MEM32(esp + 8) = edx;
    edx = MEM32(eax + 0x18);
    PUSH32(esp, ebx);
    MEM32(esp + 8) = ecx;
    MEM32(esp + 4) = edx;
    eax = MEM32(esp + 0xC);
    ebx = MEM32(esp + 8);
    ecx = MEM32(esp + 4);
    edx = MEM32(esp + 0x14);
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 8, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x10, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x18, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x20, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x28, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x30, mm0); /* movq */
    eax = eax + edx;
    ebx = ebx + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(ebx)); /* pavgb */
    MMQ_STORE(ecx + 0x38, mm0); /* movq */
    /* emms */
    POP32(esp, ebx);
    esp = esp + 0xC;
    esp += 4; return; /* ret */

}

/**
 * sub_003B8250
 * Original: 0x003B8250 - 0x003B82E1 (145 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8250(void)
{
    uint64_t mm0;

loc_003B8250: ;
    esp = esp - 8;
    eax = MEM32(esp + 0xC);
    ecx = MEM32(eax + 0x20);
    edx = MEM32(eax + 0x24);
    eax = MEM32(eax + 0x18);
    MEM32(esp + 0xC) = ecx;
    MEM32(esp + 4) = edx;
    MEM32(esp) = eax;
    eax = MEM32(esp + 4);
    ecx = MEM32(esp);
    edx = MEM32(esp + 0xC);
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 8, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x10, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x18, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x20, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x28, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x30, mm0); /* movq */
    eax = eax + edx;
    mm0 = MMQ_LOAD(eax); /* movq */
    mm0 = mmx_pavgb(mm0, MMQ_LOAD(eax + 1)); /* pavgb */
    MMQ_STORE(ecx + 0x38, mm0); /* movq */
    /* emms */
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B82F0
 * Original: 0x003B82F0 - 0x003B8367 (119 bytes, 41 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B82F0(void)
{
    uint64_t mm0, mm1, mm2, mm3, mm4, mm5, mm6, mm7;

loc_003B82F0: ;
    esp = esp - 8;
    eax = MEM32(esp + 0xC);
    ecx = MEM32(eax + 0x24);
    edx = MEM32(eax + 0x18);
    eax = MEM32(eax + 0x20);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    MEM32(esp + 0xC) = ecx;
    MEM32(esp + 0x14) = edx;
    MEM32(esp + 8) = eax;
    esi = MEM32(esp + 0xC);
    eax = MEM32(esp + 8);
    edi = MEM32(esp + 0x14);
    mm0 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi, mm0); /* movq */
    esi = esi + eax;
    mm1 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 8, mm1); /* movq */
    esi = esi + eax;
    mm2 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x10, mm2); /* movq */
    esi = esi + eax;
    mm3 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x18, mm3); /* movq */
    esi = esi + eax;
    mm4 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x20, mm4); /* movq */
    esi = esi + eax;
    mm5 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x28, mm5); /* movq */
    esi = esi + eax;
    mm6 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x30, mm6); /* movq */
    esi = esi + eax;
    mm7 = MMQ_LOAD(esi); /* movq */
    MMQ_STORE(edi + 0x38, mm7); /* movq */
    /* emms */
    POP32(esp, edi);
    POP32(esp, esi);
    esp = esp + 8;
    esp += 4; return; /* ret */

}

/**
 * sub_003B8604
 * Original: 0x003B8604 - 0x003B8710 (268 bytes, 95 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8604(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8604: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    eax = 0; /* xor self */
    ecx = 0xC04;
    edi = 0xF273C8;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = 0xF273CC;
    PUSH32(esp, 0x5F5F554D);
    PUSH32(esp, 0x60);
    MEM32(0xF273D0) = eax;
    MEM32(0xF273CC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBC2C(); /* call 0x003BBC2C */

loc_003B8636: ;
    edi = eax;
    PUSH32(esp, 0x18);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    MEM32(0xF2A3D4) = edi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = MEM32(ebp + 8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88E0(); /* call 0x003B88E0 */

loc_003B864D: ;
    if (TEST_NZ(eax, eax)) goto loc_003B8666; /* jne: not equal / not zero */

loc_003B8651: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, 0x3B83E0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88A9(); /* call 0x003B88A9 */

loc_003B865E: ;
    ebx = eax;
    ebx++;
    if (CMP_BE(ebx, 8)) goto loc_003B8669; /* jbe: below or equal (unsigned <=) */

loc_003B8666: ;
    PUSH32(esp, 8);
    POP32(esp, ebx);

loc_003B8669: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3C146C);
    eax = ebp + -12;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C14E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8678: ;
    esi = 0; /* xor self */
    if (CMP_BE(ebx & ebx, 0)) goto loc_003B86EB; /* jbe: below or equal (unsigned <=) */

loc_003B867E: ;
    /* cmp esi, 9 - flags set for next jcc */
    eax = esi + 0x41;
    if (CMP_A(esi, 9)) goto loc_003B8689; /* ja: above (unsigned >) */

loc_003B8686: ;
    eax = esi + 0x30;

loc_003B8689: ;
    ecx = MEM32(ebp + -8);
    MEM8(ecx + 0xB) = LO8(eax);
    eax = ebp + -4;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0x3A);
    eax = ebp + -12;
    PUSH32(esp, eax);
    PUSH32(esp, 0x170);
    PUSH32(esp, 0x3B8418);
    { uint32_t _icall_t = MEM32(0x3C15EC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B86AB: ;
    if (TEST_S(eax, eax)) goto loc_003B86EB; /* jl: less (signed <) */

loc_003B86AF: ;
    eax = MEM32(ebp + -4);
    edx = MEM32(eax + 0x18);
    PUSH32(esp, 0x5C);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebp + -4);
    MEM32(edx) = eax;
    MEM32(edx + 4) = esi;
    PUSH32(esp, 4);
    POP32(esp, ecx);
    MEM32(edx + 0xC) = ecx;
    eax = MEM32(ebp + -4);
    MEM8(eax + 0x1E) = 1;
    eax = MEM32(ebp + -4);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) | ecx;
    eax = MEM32(ebp + -4);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0xFFFFFFEFu;
    PUSH32(esp, edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B99BD(); /* call 0x003B99BD */

loc_003B86E6: ;
    esi++;
    if (CMP_B(esi, ebx)) { RECOMP_SLICE_POINT(); goto loc_003B867E; } /* jb: below (unsigned <) */

loc_003B86EB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    MEM8(0x3B8409) = LO8(ebx);
    /* cmp ebx, 1 - flags set for next jcc */
    _rccf = (CMP_BE(ebx, 1));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    POP32(esp, ebx);
    if (_rccf) goto loc_003B86FF; /* jbe: below or equal (unsigned <=) */

loc_003B86F9: ;
    MEM8(0x3B840F) = MEM8(0x3B840F) << 1;

loc_003B86FF: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, 0x3B8408);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B870C: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B8710
 * Original: 0x003B8710 - 0x003B875B (75 bytes, 29 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8710(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8710: ;
    PUSH32(esp, ebp);
    ebp = esp;
    SET_LO8(eax, MEM8(ebp + 8));
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    edi = ZX8(LO8(eax));
    MEM8(esi + 0x7A) = LO8(eax);
    ebx = 0; /* xor self */
    eax = edi;
    PUSH32(esp, 0x44425355);
    eax = eax << 5;
    PUSH32(esp, eax);
    MEM8(esi) = LO8(ebx);
    MEM8(esi + 0x79) = LO8(ebx);
    MEM32(esi + 0x7C) = ebx;
    MEM32(esi + 0x80) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBC2C(); /* call 0x003BBC2C */

loc_003B8741: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(ebp + 8) = eax;
    if (CMP_EQ(eax, ebx)) { g_seh_ebp = ebp; sub_003B875B(); return; } /* je: equal / zero */

loc_003B8748: ;
    PUSH32(esp, 0x3BA154);
    PUSH32(esp, edi);
    PUSH32(esp, 0x20);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_000238D0(); /* call 0x000238D0 */

loc_003B8756: ;
    eax = MEM32(ebp + 8);
    g_seh_ebp = ebp; sub_003B875D(); return; /* tail jmp 0x003B875D */

}

/**
 * sub_003B875B
 * Original: 0x003B875B - 0x003B875D (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B875B(void)
{

loc_003B875B: ;
    eax = 0; /* xor self */

    sub_003B875D(); return; /* restored dropped fall-through to sub_003B875D */
}

/**
 * sub_003B875D
 * Original: 0x003B875D - 0x003B87B3 (86 bytes, 32 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B875D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B875D: ;
    ecx = ZX8(MEM8(esi + 0x7A));
    MEM32(esi + 0xE0) = eax;
    SET_LO8(eax, MEM8(ebp + 0xC));
    MEM8(esi + 0x7B) = LO8(eax);
    SET_LO8(eax, 0); /* xor self */
    ecx--;
    if (CMP_LE(ecx & ecx, 0)) goto loc_003B8791; /* jle: less or equal (signed <=) */

loc_003B8774: ;
    ecx = 0; /* xor self */

loc_003B8776: ;
    edx = MEM32(esi + 0xE0);
    SET_LO8(eax, LO8(eax) + 1);
    ecx = ecx << 5;
    MEM8(ecx + edx + 1) = LO8(eax);
    edx = ZX8(MEM8(esi + 0x7A));
    ecx = SX8(LO8(eax));
    edx--;
    if (CMP_L(ecx, edx)) { RECOMP_SLICE_POINT(); goto loc_003B8776; } /* jl: less (signed <) */

loc_003B8791: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0x3BAF59);
    eax = esi + 0x34;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B87A1: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    esi = esi + 0x50;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B87AC: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B87B3
 * Original: 0x003B87B3 - 0x003B882C (121 bytes, 41 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B87B3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B87B3: ;
    PUSH32(esp, ebp);
    ebp = esp + -112;
    esp = esp - 0xB4;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebp + 0x7C));
    ecx = ebp + -68;
    PUSH32(esp, MEM32(ebp + 0x78));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BAFAD(); /* call 0x003BAFAD */

loc_003B87CE: ;
    eax = 0x3B8394;
    esi = 0x3B83AC;
    /* cmp eax, esi - flags set for next jcc */
    edi = eax;
    if (CMP_AE(eax, esi)) goto loc_003B87F2; /* jae: above or equal (unsigned >=) */

loc_003B87DE: ;
    eax = MEM32(edi);
    if (TEST_Z(eax, eax)) goto loc_003B87EB; /* je: equal / zero */

loc_003B87E4: ;
    ecx = ebp + -68;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    { uint32_t _icall_t = MEM32(eax + 4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B87EB: ;
    edi = edi + 4;
    if (CMP_B(edi, esi)) { RECOMP_SLICE_POINT(); goto loc_003B87DE; } /* jb: below (unsigned <) */

loc_003B87F2: ;
    ecx = ebp + -68;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8AEE(); /* call 0x003B8AEE */

loc_003B87FA: ;
    eax = ebp + 0x60;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8F5E(); /* call 0x003B8F5E */

loc_003B8803: ;
    eax = ZX8(MEM8(ebp + 0x5D));
    PUSH32(esp, eax);
    eax = ZX8(MEM8(ebp + 0x5C));
    PUSH32(esp, eax);
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8710(); /* call 0x003B8710 */

loc_003B8817: ;
    MEM8(0xF2A4C4) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8F6A(); /* call 0x003B8F6A */

loc_003B8823: ;
    POP32(esp, edi);
    POP32(esp, esi);
    ebp = ebp + 0x70;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B882C
 * Original: 0x003B882C - 0x003B88A9 (125 bytes, 45 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B882C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B882C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    PUSH32(esp, 0x44425355);
    edi = edi + 0x18;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBC2C(); /* call 0x003BBC2C */

loc_003B8840: ;
    esi = eax;
    if (TEST_Z(esi, esi)) goto loc_003B88A4; /* je: equal / zero */

loc_003B8846: ;
    ecx = edi;
    edx = ecx;
    ecx = ecx >> 2;
    eax = 0; /* xor self */
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    MEM8(0xF2A4C4) = MEM8(0xF2A4C4) + 1;
    eax = ZX8(MEM8(0xF2A4C4));
    ecx = 0xF2A3D8;
    MEM32(esi) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA166(); /* call 0x003BA166 */

loc_003B8873: ;
    PUSH32(esp, MEM32(esp + 0xC));
    ecx = esi + 4;
    MEM32(ecx) = eax;
    MEM8(eax) = 0;
    eax = MEM32(ecx);
    MEM8(eax + 2) = 0x80;
    eax = MEM32(ecx);
    MEM8(eax + 1) = 0x80;
    eax = MEM32(ecx);
    MEM8(eax + 3) = 0x80;
    eax = MEM32(ecx);
    MEM32(eax + 0xC) = esi;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi));
    esi = esi + 0x18;
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8FAC(); /* call 0x003B8FAC */

loc_003B88A4: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B88A9
 * Original: 0x003B88A9 - 0x003B88DA (49 bytes, 21 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B88A9(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003B88A9: ;
    edx = MEM32(ecx + 0x9C);
    eax = 0; /* xor self */
    if (TEST_Z(edx, edx)) goto loc_003B88D7; /* je: equal / zero */

loc_003B88B5: ;
    ecx = MEM32(ecx + 0x98);
    /* test ecx, ecx - flags set for next jcc */
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    if (CMP_BE(ecx & ecx, 0)) goto loc_003B88D3; /* jbe: below or equal (unsigned <=) */

loc_003B88C1: ;
    esi = edx;

loc_003B88C3: ;
    edi = MEM32(esi);
    if (CMP_EQ(edi, MEM32(esp + 0xC))) { g_seh_ebp = ebp; sub_003B88DA(); return; } /* je: equal / zero */

loc_003B88CB: ;
    eax++;
    esi = esi + 8;
    if (CMP_B(eax, ecx)) { RECOMP_SLICE_POINT(); goto loc_003B88C3; } /* jb: below (unsigned <) */

loc_003B88D3: ;
    eax = 0; /* xor self */
    POP32(esp, edi);
    POP32(esp, esi);

loc_003B88D7: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B88D5
 * Original: 0x003B88D5 - 0x003B88DA (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B88D5(void)
{

loc_003B88D5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B88DA
 * Original: 0x003B88DA - 0x003B88E0 (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B88DA(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B88DA: ;
    eax = MEM32(edx + eax * 8 + 4);
    g_seh_ebp = ebp; sub_003B88D5(); return; /* tail jmp 0x003B88D5 */

}

/**
 * sub_003B88E0
 * Original: 0x003B88E0 - 0x003B88EC (12 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B88E0(void)
{
    int _flags = 0; /* fallback flag var */

loc_003B88E0: ;
    eax = 0; /* xor self */
    /* cmp MEM32(ecx + 0x9C), eax - flags set for next jcc */
    SET_LO8(eax, (CMP_EQ(MEM32(ecx + 0x9C), eax)) ? 1 : 0); /* sete */
    esp += 4; return; /* ret */

}

/**
 * sub_003B88EC
 * Original: 0x003B88EC - 0x003B8AEE (514 bytes, 198 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B88EC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B88EC: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    eax = ZX8(MEM8(esi + 1));
    MEM32(ebp + -8) = eax;
    eax = ZX8(MEM8(esi));
    eax = eax - 0;
    edx = ecx;
    PUSH32(esp, edi);
    MEM32(ebp + -12) = edx;
    if ((eax == 0)) goto loc_003B894C; /* je: equal / zero */

loc_003B890C: ;
    eax--;
    if ((eax == 0)) goto loc_003B8947; /* je: equal / zero */

loc_003B890F: ;
    eax--;
    if ((eax != 0)) goto loc_003B8950; /* jne: not equal / not zero */

loc_003B8912: ;
    SET_LO8(eax, MEM8(esi + 2));
    /* cmp LO8(eax), MEM8(edx + 0x34) - flags set for next jcc */
    ebx = edx + 0x64;
    if (CMP_BE(LO8(eax), MEM8(edx + 0x34))) goto loc_003B8920; /* jbe: below or equal (unsigned <=) */

loc_003B891D: ;
    MEM8(edx + 0x34) = LO8(eax);

loc_003B8920: ;
    SET_LO8(eax, MEM8(esi + 1));
    if (CMP_BE(LO8(eax), 4)) goto loc_003B8953; /* jbe: below or equal (unsigned <=) */

loc_003B8927: ;
    SET_LO8(eax, LO8(eax) - 4);
    PUSH32(esp, esi);
    ecx = edx;
    MEM8(esi + 1) = LO8(eax);
    MEM8(esi) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B8937: ;
    MEM8(esi + 1) = MEM8(esi + 1) + 4;
    MEM32(ebp + -8) = MEM32(ebp + -8) - 4;
    edx = MEM32(ebp + -12);
    MEM8(esi) = 2;
    goto loc_003B8953;

loc_003B8947: ;
    ebx = edx + 0x32;
    goto loc_003B8953;

loc_003B894C: ;
    ebx = edx;
    goto loc_003B8953;

loc_003B8950: ;
    ebx = MEM32(ebp + 8);

loc_003B8953: ;
    SET_LO8(eax, MEM8(esi + 2));
    if (CMP_BE(LO8(eax), MEM8(ebx + 2))) goto loc_003B895E; /* jbe: below or equal (unsigned <=) */

loc_003B895B: ;
    MEM8(ebx + 2) = LO8(eax);

loc_003B895E: ;
    eax = MEM32(ebp + -8);
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B89B5; /* je: equal / zero */

loc_003B896C: ;
    edi = ebx + 3;

loc_003B896F: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B89B5; /* jae: above or equal (unsigned >=) */

loc_003B8975: ;
    SET_LO8(eax, MEM8(edi));
    if (CMP_BE(LO8(eax), MEM8(esi + 3))) goto loc_003B8984; /* jbe: below or equal (unsigned <=) */

loc_003B897C: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    edi = edi + 0xA;
    goto loc_003B89AF;

loc_003B8984: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B89A1; /* jae: above or equal (unsigned >=) */

loc_003B898A: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    eax = eax - MEM32(ebp + 8);
    ecx = ebx + 0x2B;

loc_003B8993: ;
    SET_LO8(edx, MEM8(ecx + -10));
    MEM8(ecx) = LO8(edx);
    ecx = ecx - 0xA;
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003B8993; } /* jne: not equal / not zero */

loc_003B899E: ;
    edx = MEM32(ebp + -12);

loc_003B89A1: ;
    SET_LO8(eax, MEM8(esi + 3));
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    MEM8(edi) = LO8(eax);
    edi = edi + 0xA;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;

loc_003B89AF: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) { RECOMP_SLICE_POINT(); goto loc_003B896F; } /* jne: not equal / not zero */

loc_003B89B5: ;
    eax = MEM32(ebp + -8);
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B8A0C; /* je: equal / zero */

loc_003B89C3: ;
    edi = ebx + 4;

loc_003B89C6: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B8A0C; /* jae: above or equal (unsigned >=) */

loc_003B89CC: ;
    SET_LO8(eax, MEM8(edi));
    if (CMP_BE(LO8(eax), MEM8(esi + 4))) goto loc_003B89DB; /* jbe: below or equal (unsigned <=) */

loc_003B89D3: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    edi = edi + 0xA;
    goto loc_003B8A06;

loc_003B89DB: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B89F8; /* jae: above or equal (unsigned >=) */

loc_003B89E1: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    eax = eax - MEM32(ebp + 8);
    ecx = ebx + 0x2C;

loc_003B89EA: ;
    SET_LO8(edx, MEM8(ecx + -10));
    MEM8(ecx) = LO8(edx);
    ecx = ecx - 0xA;
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003B89EA; } /* jne: not equal / not zero */

loc_003B89F5: ;
    edx = MEM32(ebp + -12);

loc_003B89F8: ;
    SET_LO8(eax, MEM8(esi + 4));
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    MEM8(edi) = LO8(eax);
    edi = edi + 0xA;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;

loc_003B8A06: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) { RECOMP_SLICE_POINT(); goto loc_003B89C6; } /* jne: not equal / not zero */

loc_003B8A0C: ;
    eax = MEM32(ebp + -8);
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B8A63; /* je: equal / zero */

loc_003B8A1A: ;
    edi = ebx + 5;

loc_003B8A1D: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B8A63; /* jae: above or equal (unsigned >=) */

loc_003B8A23: ;
    SET_LO8(eax, MEM8(edi));
    if (CMP_BE(LO8(eax), MEM8(esi + 5))) goto loc_003B8A32; /* jbe: below or equal (unsigned <=) */

loc_003B8A2A: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    edi = edi + 0xA;
    goto loc_003B8A5D;

loc_003B8A32: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B8A4F; /* jae: above or equal (unsigned >=) */

loc_003B8A38: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    eax = eax - MEM32(ebp + 8);
    ecx = ebx + 0x2D;

loc_003B8A41: ;
    SET_LO8(edx, MEM8(ecx + -10));
    MEM8(ecx) = LO8(edx);
    ecx = ecx - 0xA;
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003B8A41; } /* jne: not equal / not zero */

loc_003B8A4C: ;
    edx = MEM32(ebp + -12);

loc_003B8A4F: ;
    SET_LO8(eax, MEM8(esi + 5));
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    MEM8(edi) = LO8(eax);
    edi = edi + 0xA;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;

loc_003B8A5D: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) { RECOMP_SLICE_POINT(); goto loc_003B8A1D; } /* jne: not equal / not zero */

loc_003B8A63: ;
    eax = MEM32(ebp + -8);
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (TEST_Z(eax, eax)) goto loc_003B8ABA; /* je: equal / zero */

loc_003B8A71: ;
    edi = ebx + 8;

loc_003B8A74: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B8ABA; /* jae: above or equal (unsigned >=) */

loc_003B8A7A: ;
    SET_LO8(eax, MEM8(edi));
    if (CMP_BE(LO8(eax), MEM8(esi + 8))) goto loc_003B8A89; /* jbe: below or equal (unsigned <=) */

loc_003B8A81: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    edi = edi + 0xA;
    goto loc_003B8AB4;

loc_003B8A89: ;
    if (CMP_AE(MEM32(ebp + 8), 4)) goto loc_003B8AA6; /* jae: above or equal (unsigned >=) */

loc_003B8A8F: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    eax = eax - MEM32(ebp + 8);
    ecx = ebx + 0x30;

loc_003B8A98: ;
    SET_LO8(edx, MEM8(ecx + -10));
    MEM8(ecx) = LO8(edx);
    ecx = ecx - 0xA;
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003B8A98; } /* jne: not equal / not zero */

loc_003B8AA3: ;
    edx = MEM32(ebp + -12);

loc_003B8AA6: ;
    SET_LO8(eax, MEM8(esi + 8));
    MEM32(ebp + 8) = MEM32(ebp + 8) + 1;
    MEM8(edi) = LO8(eax);
    edi = edi + 0xA;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;

loc_003B8AB4: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) { RECOMP_SLICE_POINT(); goto loc_003B8A74; } /* jne: not equal / not zero */

loc_003B8ABA: ;
    SET_LO8(eax, MEM8(esi + 6));
    ecx = edx + 0xB0;
    if (CMP_BE(LO8(eax), MEM8(ecx))) goto loc_003B8AC9; /* jbe: below or equal (unsigned <=) */

loc_003B8AC7: ;
    MEM8(ecx) = LO8(eax);

loc_003B8AC9: ;
    SET_LO8(eax, MEM8(esi + 7));
    ecx = edx + 0xB1;
    if (CMP_BE(LO8(eax), MEM8(ecx))) goto loc_003B8AD8; /* jbe: below or equal (unsigned <=) */

loc_003B8AD6: ;
    MEM8(ecx) = LO8(eax);

loc_003B8AD8: ;
    SET_LO8(eax, MEM8(esi + 9));
    POP32(esp, edi);
    ecx = edx + 0xB2;
    /* cmp LO8(eax), MEM8(ecx) - flags set for next jcc */
    POP32(esp, esi);
    POP32(esp, ebx);
    if (CMP_BE(LO8(eax), MEM8(ecx))) goto loc_003B8AEA; /* jbe: below or equal (unsigned <=) */

loc_003B8AE8: ;
    MEM8(ecx) = LO8(eax);

loc_003B8AEA: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B8AEE
 * Original: 0x003B8AEE - 0x003B8BF4 (262 bytes, 73 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8AEE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8AEE: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    eax = 0; /* xor self */
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    MEM8(ecx + 0xA0) = 0x10;
    /* cmp MEM8(0x3B83B0), LO8(eax) - flags set for next jcc */
    PUSH32(esp, edi);
    MEM32(ebp + -4) = eax;
    MEM32(ebp + -8) = eax;
    if (CMP_EQ(MEM8(0x3B83B0), LO8(eax))) goto loc_003B8B17; /* je: equal / zero */

loc_003B8B10: ;
    MEM8(ecx + 0xA0) = 0x30;

loc_003B8B17: ;
    SET_LO8(eax, MEM8(ecx + 2));
    SET_LO8(edx, MEM8(ecx + 0x34));
    SET_LO8(edx, LO8(edx) + LO8(eax));
    SET_LO8(edx, LO8(edx) + MEM8(ecx + 0x66));
    SET_LO8(edx, LO8(edx) << 2);
    SET_LO8(edx, LO8(edx) + 3);
    MEM8(ecx + 0xA0) = MEM8(ecx + 0xA0) + LO8(edx);
    if (CMP_BE(LO8(eax), MEM8(ecx + 0xA1))) goto loc_003B8B3C; /* jbe: below or equal (unsigned <=) */

loc_003B8B36: ;
    MEM8(ecx + 0xA1) = LO8(eax);

loc_003B8B3C: ;
    SET_LO8(eax, MEM8(ecx + 0x66));
    if (CMP_BE(LO8(eax), MEM8(ecx + 0xA1))) goto loc_003B8B4D; /* jbe: below or equal (unsigned <=) */

loc_003B8B47: ;
    MEM8(ecx + 0xA1) = LO8(eax);

loc_003B8B4D: ;
    SET_LO8(eax, MEM8(ecx + 0x34));
    if (CMP_BE(LO8(eax), MEM8(ecx + 0xA1))) goto loc_003B8B5E; /* jbe: below or equal (unsigned <=) */

loc_003B8B58: ;
    MEM8(ecx + 0xA1) = LO8(eax);

loc_003B8B5E: ;
    SET_LO8(eax, MEM8(ecx + 0xA1));
    MEM8(ecx + 0xA0) = MEM8(ecx + 0xA0) + LO8(eax);
    eax = ecx + 0x37;
    MEM32(ebp + -12) = 4;

loc_003B8B74: ;
    edi = ZX8(MEM8(eax + 0x32));
    edx = ZX8(MEM8(eax + -50));
    edx = edx + edi;
    edi = ZX8(MEM8(eax));
    edi = edi + esi;
    esi = edi + edx;
    edi = ZX8(MEM8(eax + 0x30));
    edx = ZX8(MEM8(eax + -52));
    edx = edx + edi;
    edi = ZX8(MEM8(eax + -2));
    edi = edi + MEM32(ebp + -4);
    eax = eax + 0xA;
    edi = edi + edx;
    edx = ZX8(MEM8(eax + -61));
    MEM32(ebp + -4) = edi;
    edi = ZX8(MEM8(eax + 0x27));
    edx = edx + edi;
    edi = ZX8(MEM8(eax + -11));
    edi = edi + MEM32(ebp + -8);
    edi = edi + edx;
    edx = ZX8(MEM8(eax + -57));
    MEM32(ecx + 0xA8) = MEM32(ecx + 0xA8) + edx;
    ebx = ZX8(MEM8(eax + 0x2B));
    edx = MEM32(ecx + 0xA8);
    edx = edx + ebx;
    MEM32(ecx + 0xA8) = edx;
    ebx = ZX8(MEM8(eax + -7));
    ebx = ebx + edx;
    MEM32(ebp + -12) = MEM32(ebp + -12) - 1;
    MEM32(ebp + -8) = edi;
    MEM32(ecx + 0xA8) = ebx;
    if ((MEM32(ebp + -12) != 0)) { RECOMP_SLICE_POINT(); goto loc_003B8B74; } /* jne: not equal / not zero */

loc_003B8BE2: ;
    if (CMP_EQ(MEM8(0x3B83B0), 0)) { g_seh_ebp = ebp; sub_003B8BF4(); return; } /* je: equal / zero */

loc_003B8BEB: ;
    esi = esi + 0xD;
    MEM32(ebp + -4) = MEM32(ebp + -4) + 0xD;
    g_seh_ebp = ebp; sub_003B8BFB(); return; /* tail jmp 0x003B8BFB */

}

/**
 * sub_003B8BF4
 * Original: 0x003B8BF4 - 0x003B8BFB (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8BF4(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B8BF4: ;
    esi = esi + 5;
    MEM32(ebp + -4) = MEM32(ebp + -4) + 5;

    g_seh_ebp = ebp; sub_003B8BFB(); return; /* restored dropped fall-through to sub_003B8BFB */
}

/**
 * sub_003B8BFB
 * Original: 0x003B8BFB - 0x003B8C37 (60 bytes, 21 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8BFB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B8BFB: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + 1;
    edx = ecx + 0xB0;
    if (CMP_AE(MEM8(edx), 0xD)) goto loc_003B8C0C; /* jae: above or equal (unsigned >=) */

loc_003B8C09: ;
    MEM8(edx) = 0xD;

loc_003B8C0C: ;
    eax = MEM32(ebp + -4);
    edx = ZX8(MEM8(edx));
    eax = eax + edi;
    edi = ZX8(MEM8(ecx + 0xB1));
    ebx = eax + esi * 2;
    ebx = ebx + esi;
    ebx = ebx + edi;
    edx = edx + ebx;
    POP32(esp, edi);
    eax = eax + esi;
    POP32(esp, esi);
    MEM32(ecx + 0xAC) = edx;
    MEM32(ecx + 0xA4) = eax;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003B8C37
 * Original: 0x003B8C37 - 0x003B8E42 (523 bytes, 165 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8C37(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8C37: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x60;
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    /* cmp MEM32(0x3B8548), esi - flags set for next jcc */
    MEM32(ebp + -8) = esi;
    MEM32(ebp + -4) = esi;
    MEM32(ebp + -12) = esi;
    if (CMP_NE(MEM32(0x3B8548), esi)) goto loc_003B8E3D; /* jne: not equal / not zero */

loc_003B8C55: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    MEM32(0x3B8548) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88E0(); /* call 0x003B88E0 */

loc_003B8C69: ;
    MEM32(ebp + -16) = eax;
    eax = 0x3B8384;
    ebx = 0x3B838C;
    /* cmp eax, ebx - flags set for next jcc */
    edi = eax;
    if (CMP_AE(eax, ebx)) goto loc_003B8CF0; /* jae: above or equal (unsigned >=) */

loc_003B8C7C: ;
    eax = MEM32(edi);
    if (TEST_Z(eax, eax)) goto loc_003B8CC9; /* je: equal / zero */

loc_003B8C82: ;
    eax = MEM32(eax + 4);
    MEM32(ebp + esi * 4 + -96) = eax;
    esi++;
    if (CMP_NE(MEM32(ebp + -16), 0)) goto loc_003B8C9E; /* jne: not equal / not zero */

loc_003B8C90: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88A9(); /* call 0x003B88A9 */

loc_003B8C99: ;
    ecx = MEM32(edi);
    MEM8(ecx + 1) = LO8(eax);

loc_003B8C9E: ;
    eax = MEM32(edi);
    eax = MEM32(eax + 0x14);
    if (TEST_Z(eax, eax)) goto loc_003B8CA9; /* je: equal / zero */

loc_003B8CA7: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = eax; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8CA9: ;
    eax = MEM32(edi);
    ecx = MEM32(eax + 0x28);
    /* test LO8(ecx), 4 - flags set for next jcc */
    eax = ZX8(MEM8(eax + 1));
    if (TEST_Z(LO8(ecx), 4)) goto loc_003B8CBC; /* je: equal / zero */

loc_003B8CB7: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + eax;
    goto loc_003B8CC9;

loc_003B8CBC: ;
    if (TEST_Z(LO8(ecx), 8)) goto loc_003B8CC6; /* je: equal / zero */

loc_003B8CC1: ;
    MEM32(ebp + -12) = MEM32(ebp + -12) + eax;
    goto loc_003B8CC9;

loc_003B8CC6: ;
    MEM32(ebp + -8) = MEM32(ebp + -8) + eax;

loc_003B8CC9: ;
    edi = edi + 4;
    if (CMP_B(edi, ebx)) { RECOMP_SLICE_POINT(); goto loc_003B8C7C; } /* jb: below (unsigned <) */

loc_003B8CD0: ;
    if (CMP_EQ(MEM32(ebp + -12), 0)) goto loc_003B8CE1; /* je: equal / zero */

loc_003B8CD6: ;
    MEM16(0xF2A4C8) = 0xC;
    goto loc_003B8CF9;

loc_003B8CE1: ;
    /* cmp MEM32(ebp + -4), 0 - flags set for next jcc */
    MEM16(0xF2A4C8) = 8;
    if (CMP_NE(MEM32(ebp + -4), 0)) goto loc_003B8CF9; /* jne: not equal / not zero */

loc_003B8CF0: ;
    MEM16(0xF2A4C8) = 4;

loc_003B8CF9: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    if (CMP_BE(MEM32(ebp + -8), eax)) goto loc_003B8D04; /* jbe: below or equal (unsigned <=) */

loc_003B8D01: ;
    MEM32(ebp + -8) = eax;

loc_003B8D04: ;
    if (CMP_BE(MEM32(ebp + -4), eax)) goto loc_003B8D0C; /* jbe: below or equal (unsigned <=) */

loc_003B8D09: ;
    MEM32(ebp + -4) = eax;

loc_003B8D0C: ;
    ecx = MEM32(ebp + -12);
    eax = MEM32(ebp + -4);
    eax = eax + ecx;
    PUSH32(esp, 8);
    POP32(esp, ecx);
    /* cmp eax, ecx - flags set for next jcc */
    MEM32(ebp + -16) = eax;
    if (CMP_BE(eax, ecx)) goto loc_003B8D21; /* jbe: below or equal (unsigned <=) */

loc_003B8D1E: ;
    MEM32(ebp + -16) = ecx;

loc_003B8D21: ;
    eax = MEM32(ebp + -16);
    eax = eax + MEM32(ebp + -8);
    ecx = ZX16(MEM16(0xF2A4C8));
    MEM32(ebp + -16) = eax;
    ecx = (uint32_t)((int32_t)ecx * (int32_t)0x16);
    eax = (uint32_t)((int32_t)eax * (int32_t)0xAB);
    ebx = esi;
    ebx = ebx << 2;
    ecx = ecx + ebx;
    eax = eax + ecx;
    PUSH32(esp, 0x5F444958);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBC2C(); /* call 0x003BBC2C */

loc_003B8D4E: ;
    ecx = ebx;
    edx = ecx;
    ecx = ecx >> 2;
    MEM32(0x3B851C) = esi;
    MEM32(0x3B8534) = esi;
    MEM32(0x3B8520) = eax;
    MEM32(0x3B8538) = eax;
    edi = eax;
    esi = ebp + -96;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = edx;
    edx = MEM32(ebp + -16);
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    edi = 0; /* xor self */
    ecx = 0; /* xor self */
    eax = eax + ebx;
    /* cmp edx, edi - flags set for next jcc */
    MEM32(0xF2A4D0) = ecx;
    if (CMP_BE(edx, edi)) goto loc_003B8DA2; /* jbe: below or equal (unsigned <=) */

loc_003B8D8C: ;
    MEM32(eax + 0xA7) = ecx;
    ecx = eax;
    eax = eax + 0xAB;
    edx--;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003B8D8C; } /* jne: not equal / not zero */

loc_003B8D9C: ;
    MEM32(0xF2A4D0) = ecx;

loc_003B8DA2: ;
    edx = 0; /* xor self */
    /* cmp MEM16(0xF2A4C8), LO16(edi) - flags set for next jcc */
    MEM32(0xF2A4CC) = eax;
    MEM16(0xF2A4CA) = LO16(edi);
    if (CMP_BE(MEM16(0xF2A4C8), LO16(edi))) goto loc_003B8DD6; /* jbe: below or equal (unsigned <=) */

loc_003B8DB9: ;
    ecx = 0; /* xor self */

loc_003B8DBB: ;
    eax = MEM32(0xF2A4CC);
    eax = ecx + eax + 4;
    MEM8(eax) = MEM8(eax) & 0xFE;
    eax = ZX16(MEM16(0xF2A4C8));
    edx++;
    ecx = ecx + 0x16;
    if (CMP_B(edx, eax)) { RECOMP_SLICE_POINT(); goto loc_003B8DBB; } /* jb: below (unsigned <) */

loc_003B8DD6: ;
    eax = MEM32(ebp + -8);
    /* cmp eax, edi - flags set for next jcc */
    esi = 0x3B853C;
    if (CMP_EQ(eax, edi)) goto loc_003B8DF7; /* je: equal / zero */

loc_003B8DE2: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    MEM8(0x3B853C) = 0;
    MEM8(0x3B853D) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B8DF7: ;
    eax = MEM32(ebp + -12);
    if (CMP_EQ(eax, edi)) goto loc_003B8E13; /* je: equal / zero */

loc_003B8DFE: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    MEM8(0x3B853C) = 2;
    MEM8(0x3B853D) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B8E13: ;
    eax = MEM32(ebp + -4);
    if (CMP_EQ(eax, edi)) goto loc_003B8E2F; /* je: equal / zero */

loc_003B8E1A: ;
    ecx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    MEM8(0x3B853C) = 1;
    MEM8(0x3B853D) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B8E2F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8E3B: ;
    POP32(esp, edi);
    POP32(esp, ebx);

loc_003B8E3D: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B8E42
 * Original: 0x003B8E42 - 0x003B8EAE (108 bytes, 29 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8E42(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B8E42: ;
    eax = 0; /* xor self */
    /* cmp MEM8(0x3B83B0), LO8(eax) - flags set for next jcc */
    PUSH32(esp, edi);
    SET_LO8(eax, (CMP_NE(MEM8(0x3B83B0), LO8(eax))) ? 1 : 0); /* setne */
    MEM16(0xF2A622) = MEM16(0xF2A622) & 0;
    PUSH32(esp, 0x48425355);
    eax = eax * 8 + 6;
    MEM16(0xF2A620) = LO16(eax);
    eax = ZX16(LO16(eax));
    eax = eax << 6;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBC2C(); /* call 0x003BBC2C */

loc_003B8E74: ;
    ecx = ZX16(MEM16(0xF2A620));
    ecx = ecx << 6;
    edx = ecx;
    edi = eax;
    ecx = ecx >> 2;
    MEM32(0xF2A624) = edi;
    eax = 0; /* xor self */
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    ecx = ecx & 3;
    PUSH32(esp, 0xF2A5D0);
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8EA3: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;
    POP32(esp, edi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B8EAE
 * Original: 0x003B8EAE - 0x003B8F5E (176 bytes, 61 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8EAE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8EAE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    ebx = MEM32(esi);
    PUSH32(esp, 0);
    eax = esi + 0x478;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8EC9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x3BE613);
    eax = esi + 0x4A0;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8EDC: ;
    MEM8(esi + 0x460) = 4;
    eax = MEM32(ebx + 0x50);
    MEM32(ebp + -8) = eax;
    MEM16(ebp + -8) = MEM16(ebp + -8) & 0;
    eax = MEM32(ebp + -8);
    ecx = 0; /* xor self */
    MEM32(ebx + 0x50) = eax;
    eax = 0; /* xor self */
    edx = 0; /* xor self */
    edi = ebp + -4;
    ecx++;
    /* cmp MEM8(esi + 0x460), LO8(edx) - flags set for next jcc */
    MEM32(edi) = eax; edi += 4; /* stosd */
    if (CMP_BE(MEM8(esi + 0x460), LO8(edx))) goto loc_003B8F38; /* jbe: below or equal (unsigned <=) */

loc_003B8F07: ;
    eax = ebx + 0x54;

loc_003B8F0A: ;
    edi = MEM32(eax);
    MEM32(ebp + -8) = edi;
    if (TEST_Z(MEM8(ebp + -8), 1)) goto loc_003B8F1D; /* je: equal / zero */

loc_003B8F15: ;
    MEM16(ebp + -2) = MEM16(ebp + -2) | LO16(ecx);
    MEM16(ebp + -4) = MEM16(ebp + -4) | LO16(ecx);

loc_003B8F1D: ;
    MEM16(ebp + -8) = MEM16(ebp + -8) & 0;
    edi = MEM32(ebp + -8);
    MEM32(eax) = edi;
    edi = ZX8(MEM8(esi + 0x460));
    edx++;
    eax = eax + 4;
    ecx = ecx << 1;
    if (CMP_B(edx, edi)) { RECOMP_SLICE_POINT(); goto loc_003B8F0A; } /* jb: below (unsigned <) */

loc_003B8F38: ;
    MEM32(ebx + 0x10) = 0x40;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8F45: ;
    edx = ebp + -4;
    ecx = esi;
    SET_LO8(ebx, LO8(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE51A(); /* call 0x003BE51A */

loc_003B8F51: ;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8F59: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003B8F5E
 * Original: 0x003B8F5E - 0x003B8F6A (12 bytes, 3 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8F5E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B8F5E: ;
    ecx = MEM32(esp + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9127(); /* call 0x003B9127 */

loc_003B8F67: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B8F6A
 * Original: 0x003B8F6A - 0x003B8FAC (66 bytes, 20 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8F6A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8F6A: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x28;
    eax = MEM32(0x3C1620);
    if (CMP_EQ(MEM8(eax + 5), 0xA1)) goto loc_003B8FAA; /* je: equal / zero */

loc_003B8F7B: ;
    eax = ebp + -4;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 1);
    MEM8(ebp + -24) = 3;
    MEM32(ebp + -16) = 0x1000;
    MEM32(ebp + -20) = 0xFED00000u;
    { uint32_t _icall_t = MEM32(0x3C1648); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B8F99: ;
    MEM32(ebp + -12) = eax;
    PUSH32(esp, 0x4E0);
    eax = ebp + -40;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B882C(); /* call 0x003B882C */

loc_003B8FAA: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003B8FAC
 * Original: 0x003B8FAC - 0x003B9127 (379 bytes, 114 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B8FAC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B8FAC: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    MEM8(ebp + 0xC) = MEM8(ebp + 0xC) - 1;
    eax = MEM32(ebp + 0x10);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    PUSH32(esp, edi);
    edi = ZX8(MEM8(ebp + 0xC));
    MEM32(esi + 0x45C) = edi;
    ecx = MEM32(eax + 0x18);
    MEM32(esi + 4) = ecx;
    eax = MEM32(eax + 0x14);
    PUSH32(esp, esi);
    MEM32(ebp + -4) = edi;
    MEM32(esi) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B934D(); /* call 0x003B934D */

loc_003B8FDA: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9358(); /* call 0x003B9358 */

loc_003B8FE0: ;
    ebx = MEM32(esi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x3BF84B);
    eax = esi + 0x440;
    MEM32(ebx + 0x48) = 0x1200;
    MEM32(ebx + 0x4C) = 0;
    MEM32(ebx + 0x50) = 0x80000000u;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B900A: ;
    eax = MEM32(edi * 4 + 0xF45F04);
    MEM32(esi + 8) = eax;
    eax = MEM32(ebx + 8);
    MEM32(ebp + 8) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9020: ;
    MEM8(ebp + 0xF) = LO8(eax);
    eax = MEM32(ebp + 8);
    eax = eax | 1;
    MEM32(ebx + 8) = eax;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xA);
    { uint32_t _icall_t = MEM32(0x3C1658); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9034: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B92EC(); /* call 0x003B92EC */

loc_003B903B: ;
    MEM32(ebx + 4) = 0xBE;
    eax = MEM32(ebx + 0x34);
    eax = eax & 0xA772EED8u;
    eax = eax | 0x27722ED8;
    ecx = eax;
    ecx = ~ecx;
    ecx = ecx ^ eax;
    ecx = ecx & 0x7FFFFFFF;
    eax = ~eax;
    ecx = ecx ^ eax;
    MEM32(ebx + 0x34) = ecx;
    eax = MEM32(0x3C1620);
    if (TEST_NZ(MEM8(eax), 1)) goto loc_003B90AF; /* jne: not equal / not zero */

loc_003B906C: ;
    MEM32(ebp + 8) = 2;

loc_003B9073: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE6FD(); /* call 0x003BE6FD */

loc_003B9078: ;
    edx = eax;
    eax = 0; /* xor self */
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = edx;
    eax = eax - MEM32(0xF45F00);
    ecx = esi;
    MEM32(edx + 0x14) = eax;
    eax = MEM32(edx);
    eax = eax & 0xF808FFFFu;
    eax = eax | 0x80000;
    MEM8(edx + 0x11) = 0;
    MEM32(edx) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BED08(); /* call 0x003BED08 */

loc_003B90A7: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) - 1;
    if ((MEM32(ebp + 8) != 0)) { RECOMP_SLICE_POINT(); goto loc_003B9073; } /* jne: not equal / not zero */

loc_003B90AC: ;
    edi = MEM32(ebp + -4);

loc_003B90AF: ;
    SET_LO8(ecx, MEM8(ebp + 0xF));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B90B8: ;
    edi = (uint32_t)((int32_t)edi * (int32_t)0x70);
    eax = MEM32(ebp + 0x10);
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(eax + 0x24));
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    edi = edi + 0xF45FA0;
    PUSH32(esp, ecx);
    PUSH32(esp, MEM32(eax + 0x1C));
    PUSH32(esp, esi);
    PUSH32(esp, 0x3BF177);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1654); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B90DE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1650); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B90E5: ;
    edx = 0; /* xor self */
    edx++;
    ecx = esi + 0x4C0;
    eax = esi + 0x4C8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    PUSH32(esp, ecx);
    MEM32(ecx) = 0x3BEA27;
    MEM32(esi + 0x4C4) = edx;
    MEM32(esi + 0x4CC) = eax;
    MEM32(eax) = eax;
    { uint32_t _icall_t = MEM32(0x3C1624); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9110: ;
    ecx = esi;
    MEM32(ebx + 0x10) = 0x80000033u;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B8EAE(); /* call 0x003B8EAE */

loc_003B911E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = 0; /* xor self */
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B9127
 * Original: 0x003B9127 - 0x003B92EC (453 bytes, 142 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9127(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9127: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    ebx = ecx;
    ecx = ZX8(MEM8(ebx + 0xE));
    eax = MEM32(ebx + 4);
    ecx = ecx << 6;
    ecx = ecx + 0x30;
    /* cmp MEM32(ebx), eax - flags set for next jcc */
    PUSH32(esp, esi);
    MEM32(ebp + -8) = ecx;
    if (CMP_AE(MEM32(ebx), eax)) goto loc_003B9147; /* jae: above or equal (unsigned >=) */

loc_003B9145: ;
    MEM32(ebx) = eax;

loc_003B9147: ;
    eax = (uint32_t)((int32_t)eax * (int32_t)ecx);
    ecx = MEM32(ebx + 8);
    ecx = ecx + 8;
    ecx = ecx << 5;
    eax = eax + ecx;
    ecx = MEM32(ebx);
    ecx = ecx + ecx * 2;
    ecx = ecx << 4;
    eax = eax + ecx;
    ecx = eax;
    eax = ecx + 0xFFF;
    eax = eax >> 0xC;
    edx = eax;
    edx = edx << 4;
    edx = edx + ecx;
    ecx = eax;
    ecx = ecx << 0xC;
    if (CMP_AE(ecx, edx)) goto loc_003B917B; /* jae: above or equal (unsigned >=) */

loc_003B917A: ;
    eax++;

loc_003B917B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    eax = eax << 0xC;
    edi = eax;
    PUSH32(esp, edi);
    MEM32(ebp + -4) = edi;
    { uint32_t _icall_t = MEM32(0x3C155C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B918B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    esi = eax;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C1680); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9197: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C167C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B919E: ;
    ecx = esi;
    ecx = ecx - eax;
    MEM32(0xF45F00) = ecx;
    ecx = edi;
    edx = ecx;
    ecx = ecx >> 2;
    eax = 0; /* xor self */
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    eax = edx;
    edx = 0; /* xor self */
    MEM32(0xF45F04) = esi;
    MEM32(0xF45F08) = edx;
    edi = ZX8(MEM8(ebx + 0xE));
    ecx = esi + eax;
    esi = esi + 0x100;
    eax = 0; /* xor self */
    MEM32(0xF45F2C) = edi;
    MEM32(0xF45F28) = edx;
    /* cmp MEM32(ebx + 4), edx - flags set for next jcc */
    MEM32(ebp + -12) = ecx;
    if (CMP_BE(MEM32(ebx + 4), edx)) goto loc_003B922D; /* jbe: below or equal (unsigned <=) */

loc_003B91EF: ;
    edi = MEM32(0xF45F28);
    MEM32(esi) = edi;
    edi = MEM32(0xF45F08);
    MEM32(0xF45F28) = esi;
    esi = esi + MEM32(ebp + -8);
    MEM32(esi + 0x18) = edi;
    MEM32(0xF45F08) = esi;
    esi = esi + 0x30;
    eax++;
    if (CMP_B(eax, MEM32(ebx + 4))) { RECOMP_SLICE_POINT(); goto loc_003B91EF; } /* jb: below (unsigned <) */

loc_003B9218: ;
    goto loc_003B922D;

loc_003B921A: ;
    edi = MEM32(0xF45F08);
    MEM32(esi + 0x18) = edi;
    MEM32(0xF45F08) = esi;
    esi = esi + 0x30;
    eax++;

loc_003B922D: ;
    if (CMP_B(eax, MEM32(ebx))) { RECOMP_SLICE_POINT(); goto loc_003B921A; } /* jb: below (unsigned <) */

loc_003B9231: ;
    edi = esi + 0x20;
    /* cmp edi, ecx - flags set for next jcc */
    MEM32(ebp + -4) = edx;
    MEM32(0xF45F0C) = edx;
    MEM32(0xF45F10) = esi;
    if (CMP_A(edi, ecx)) goto loc_003B926B; /* ja: above (unsigned >) */

loc_003B9247: ;
    eax = esi;
    eax = eax - MEM32(0xF45F00);
    PUSH32(esp, esi);
    MEM32(ebp + -8) = esi;
    MEM32(edi + -16) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BECEB(); /* call 0x003BECEB */

loc_003B925B: ;
    esi = esi + 0x20;
    edi = edi + 0x20;
    MEM32(ebp + -4) = MEM32(ebp + -4) + 1;
    if (CMP_BE(edi, MEM32(ebp + -12))) { RECOMP_SLICE_POINT(); goto loc_003B9247; } /* jbe: below or equal (unsigned <=) */

loc_003B9269: ;
    edx = 0; /* xor self */

loc_003B926B: ;
    eax = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    MEM32(0xF45F14) = eax;
    MEM32(0xF45F18) = edx;
    MEM32(0xF45F1C) = 0x3E8;
    SET_LO16(eax, ZX8(MEM8(ebx + 0xC)));
    MEM16(0xF45F20) = LO16(eax);
    SET_LO16(eax, ZX8(MEM8(ebx + 0xD)));
    MEM16(0xF45F24) = LO16(eax);
    /* cmp ecx, MEM32(ebx + 8) - flags set for next jcc */
    POP32(esp, edi);
    if (CMP_BE(ecx, MEM32(ebx + 8))) goto loc_003B92D4; /* jbe: below or equal (unsigned <=) */

loc_003B92A2: ;
    SET_LO8(ecx, LO8(ecx) - MEM8(ebx + 8));
    if (CMP_EQ(LO16(eax), LO16(edx))) goto loc_003B92BD; /* je: equal / zero */

loc_003B92AA: ;
    SET_LO8(edx, LO8(ecx));
    SET_LO8(edx, LO8(edx) >> 1);
    SET_LO16(esi, ZX8(LO8(edx)));
    SET_LO16(eax, LO16(eax) + LO16(esi));
    MEM16(0xF45F24) = LO16(eax);
    SET_LO8(ecx, LO8(ecx) - LO8(edx));

loc_003B92BD: ;
    SET_LO16(eax, ZX8(LO8(ecx)));
    MEM16(0xF45F20) = MEM16(0xF45F20) + LO16(eax);
    eax = MEM32(ebp + -4);
    MEM32(ebx + 8) = eax;
    SET_LO16(eax, MEM16(0xF45F24));

loc_003B92D4: ;
    SET_LO16(ecx, MEM16(0xF45F20));
    POP32(esp, esi);
    MEM16(0xF45F22) = LO16(ecx);
    MEM16(0xF45F26) = LO16(eax);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003B92EC
 * Original: 0x003B92EC - 0x003B934D (97 bytes, 32 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B92EC(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B92EC: ;
    PUSH32(esp, esi);
    esi = ecx;
    eax = MEM32(esi + 8);
    eax = eax - MEM32(0xF45F00);
    ecx = MEM32(esi);
    MEM32(ecx + 0x18) = eax;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    MEM32(ecx + 0x1C) = eax;
    ecx = MEM32(esi);
    MEM32(ecx + 0x20) = eax;
    ecx = MEM32(esi);
    MEM32(ecx + 0x24) = eax;
    ecx = MEM32(esi);
    MEM32(ecx + 0x28) = eax;
    ecx = MEM32(esi);
    MEM32(ecx + 0x2C) = eax;
    ecx = MEM32(esi);
    MEM32(ecx + 0x30) = eax;
    PUSH32(esp, 1);
    MEM16(esi + 0x416) = 0x2772;
    eax = MEM32(esi);
    PUSH32(esp, 3);
    MEM32(eax + 0x40) = 0x2A29;
    PUSH32(esp, 8);
    MEM16(esi + 0x414) = 0x236F;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB01B(); /* call 0x003BB01B */

loc_003B9343: ;
    ecx = MEM32(esi);
    eax = ZX16(LO16(eax));
    MEM32(ecx + 0x44) = eax;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003B934D
 * Original: 0x003B934D - 0x003B9358 (11 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B934D(void)
{

loc_003B934D: ;
    eax = MEM32(esp + 4);
    eax = MEM32(eax);
    eax = MEM32(eax);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B9358
 * Original: 0x003B9358 - 0x003B9381 (41 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9358(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9358: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    edx = MEM32(ebp + 8);
    eax = MEM32(edx);
    ecx = MEM32(eax + 4);
    PUSH32(esp, esi);
    esi = 0x100;
    if (TEST_Z(esi, ecx)) { g_seh_ebp = ebp; sub_003B9381(); return; } /* je: equal / zero */

loc_003B936F: ;
    ecx = MEM32(eax + 8);
    ecx = ecx | 8;
    MEM32(eax + 8) = ecx;
    edx = MEM32(edx);

loc_003B937A: ;
    /* hw busy-wait forced through (was: if (TEST_NZ(MEM32(edx + 4), esi)) goto loc_003B937A) */

loc_003B937F: ;
    g_seh_ebp = ebp; sub_003B93B5(); return; /* tail jmp 0x003B93B5 */

}

/**
 * sub_003B9381
 * Original: 0x003B9381 - 0x003B93B5 (52 bytes, 16 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9381(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9381: ;
    edx = ecx;
    edx = edx >> 6;
    edx = edx & 3;
    if ((edx == 0)) { g_seh_ebp = ebp; sub_003B93B5(); return; } /* je: equal / zero */

loc_003B938B: ;
    if (CMP_EQ(edx, 2)) { g_seh_ebp = ebp; sub_003B93B5(); return; } /* je: equal / zero */

loc_003B9390: ;
    ecx = ecx & 0xFFFFFF7Fu;
    ecx = ecx | 0x40;
    MEM32(eax + 4) = ecx;
    MEM32(ebp + -4) = MEM32(ebp + -4) | 0xFFFFFFFFu;
    eax = ebp + -8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    MEM32(ebp + -8) = 0xFFFCF2C0u;
    { uint32_t _icall_t = MEM32(0x3C15D4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003B93B5(); return; /* restored dropped fall-through to sub_003B93B5 */
}

/**
 * sub_003B93B5
 * Original: 0x003B93B5 - 0x003B93BA (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B93B5(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B93B5: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B93BA
 * Original: 0x003B93BA - 0x003B9421 (103 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B93BA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B93BA: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 0xC);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    esi = edi + ebx;
    if (TEST_Z(esi, esi)) goto loc_003B93E4; /* je: equal / zero */

loc_003B93CD: ;
    eax = esi;
    eax = (uint32_t)((int32_t)eax * (int32_t)0x380);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x6B776168);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C163C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B93E1: ;
    MEM32(ebp + 8) = eax;

loc_003B93E4: ;
    eax = 0; /* xor self */
    /* test esi, esi - flags set for next jcc */
    MEM32(0x3B8570) = eax;
    if (CMP_BE(esi & esi, 0)) goto loc_003B9404; /* jbe: below or equal (unsigned <=) */

loc_003B93EF: ;
    ecx = MEM32(ebp + 8);

loc_003B93F2: ;
    MEM32(ecx) = eax;
    eax = ecx;
    ecx = ecx + 0x380;
    esi--;
    if ((esi != 0)) { RECOMP_SLICE_POINT(); goto loc_003B93F2; } /* jne: not equal / not zero */

loc_003B93FF: ;
    MEM32(0x3B8570) = eax;

loc_003B9404: ;
    MEM16(0x3B856C) = LO16(edi);
    eax = 0; /* xor self */
    edi = 0xF2A66C;
    MEM32(edi) = eax; edi += 4; /* stosd */
    POP32(esp, edi);
    POP32(esp, esi);
    MEM16(0x3B8568) = LO16(ebx);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9421
 * Original: 0x003B9421 - 0x003B94C4 (163 bytes, 56 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9421(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9421: ;
    PUSH32(esp, ebp);
    ebp = esp;
    if (CMP_NE(MEM32(0x3B8600), 0)) goto loc_003B94C0; /* jne: not equal / not zero */

loc_003B9431: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    PUSH32(esp, edi);
    ecx = esi;
    MEM32(0x3B8600) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88E0(); /* call 0x003B88E0 */

loc_003B9448: ;
    if (TEST_Z(eax, eax)) goto loc_003B9453; /* je: equal / zero */

loc_003B944C: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    ebx = eax;
    goto loc_003B948E;

loc_003B9453: ;
    PUSH32(esp, 0x3B85AC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88A9(); /* call 0x003B88A9 */

loc_003B945F: ;
    PUSH32(esp, 0x3B8594);
    ecx = esi;
    edi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88A9(); /* call 0x003B88A9 */

loc_003B946D: ;
    PUSH32(esp, 0x3B85A0);
    ecx = esi;
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88A9(); /* call 0x003B88A9 */

loc_003B947B: ;
    PUSH32(esp, 4);
    MEM32(ebp + 8) = eax;
    ebx = ebx + edi;
    POP32(esp, eax);
    if (CMP_BE(ebx, eax)) goto loc_003B9489; /* jbe: below or equal (unsigned <=) */

loc_003B9487: ;
    ebx = eax;

loc_003B9489: ;
    if (CMP_BE(MEM32(ebp + 8), eax)) goto loc_003B9491; /* jbe: below or equal (unsigned <=) */

loc_003B948E: ;
    MEM32(ebp + 8) = eax;

loc_003B9491: ;
    edi = 0x3B85F4;
    PUSH32(esp, edi);
    ecx = esi;
    MEM8(0x3B85F5) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B94A4: ;
    SET_LO8(eax, MEM8(ebp + 8));
    PUSH32(esp, edi);
    ecx = esi;
    MEM8(0x3B85F5) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B88EC(); /* call 0x003B88EC */

loc_003B94B4: ;
    PUSH32(esp, MEM32(ebp + 8));
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B93BA(); /* call 0x003B93BA */

loc_003B94BD: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);

loc_003B94C0: ;
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B94C4
 * Original: 0x003B94C4 - 0x003B951B (87 bytes, 32 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B94C4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B94C4: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xA4;
    eax = MEM32(ebp + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003B94D7; /* je: equal / zero */

loc_003B94D4: ;
    MEM8(eax) = 0;

loc_003B94D7: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = 0x3B83B8;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1598); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B94E6: ;
    SET_LO8(ebx, MEM8(ebp + 8));
    SET_LO8(ebx, LO8(ebx) + 0x23);
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) + MEM8(ebp + 0xC));
    eax = 0; /* xor self */
    esi = SX8(LO8(ebx));
    eax++;
    ecx = esi + -70;
    eax = eax << LO8(ecx);
    /* test MEM32(0xF273C0), eax - flags set for next jcc */
    MEM32(ebp + -16) = eax;
    if (TEST_Z(MEM32(0xF273C0), eax)) { g_seh_ebp = ebp; sub_003B951B(); return; } /* je: equal / zero */

loc_003B9507: ;
    eax = MEM32(ebp + 0x10);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(eax) = LO8(ebx);
    { uint32_t _icall_t = MEM32(0x3C1594); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9513: ;
    PUSH32(esp, 0x55);
    POP32(esp, eax);
    g_seh_ebp = ebp; sub_003B95EF(); return; /* tail jmp 0x003B95EF */

}

/**
 * sub_003B951B
 * Original: 0x003B951B - 0x003B95EF (212 bytes, 66 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B951B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B951B: ;
    MEM16(ebp + -8) = MEM16(ebp + -8) & 0;
    eax = ebp + -164;
    MEM32(ebp + -4) = eax;
    eax = ebp + -8;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0xC));
    MEM16(ebp + -6) = 0x3F;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9C26(); /* call 0x003B9C26 */

loc_003B953E: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (TEST_S(eax, eax)) goto loc_003B95DF; /* jl: less (signed <) */

loc_003B9549: ;
    PUSH32(esp, esi);
    eax = ebp + -100;
    PUSH32(esp, 0x46BAE0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336977(); /* call 0x00336977 */

loc_003B9558: ;
    esp = esp + 0xC;
    eax = ebp + -100;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    eax = ebp + -24;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C14E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9569: ;
    eax = MEM32(0x10118);
    PUSH32(esp, MEM32(eax + 8));
    eax = ebp + -36;
    PUSH32(esp, 0x46BAD8);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336977(); /* call 0x00336977 */

loc_003B957F: ;
    eax = ZX16(MEM16(ebp + -8));
    ecx = MEM32(ebp + -4);
    esp = esp + 0xC;
    MEM8(eax + ecx) = 0x5C;
    MEM16(ebp + -8) = MEM16(ebp + -8) + 1;
    eax = MEM32(0x10118);
    PUSH32(esp, 0);
    eax = eax + 0xC;
    PUSH32(esp, eax);
    PUSH32(esp, 1);
    eax = ebp + -36;
    PUSH32(esp, eax);
    eax = ebp + -8;
    PUSH32(esp, eax);
    eax = ebp + -24;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BBE40(); /* call 0x002BBE40 */

loc_003B95AF: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (TEST_S(eax, eax)) goto loc_003B95CA; /* jl: less (signed <) */

loc_003B95B6: ;
    eax = MEM32(ebp + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003B95BF; /* je: equal / zero */

loc_003B95BD: ;
    MEM8(eax) = LO8(ebx);

loc_003B95BF: ;
    eax = MEM32(ebp + -16);
    MEM32(0xF273C0) = MEM32(0xF273C0) | eax;
    goto loc_003B95DF;

loc_003B95CA: ;
    eax = ebp + -8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15D8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B95D4: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9BB9(); /* call 0x003B9BB9 */

loc_003B95DF: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1594); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B95E6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -12));
    { uint32_t _icall_t = MEM32(0x3C1504); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003B95EF(); return; /* restored dropped fall-through to sub_003B95EF */
}

/**
 * sub_003B95EF
 * Original: 0x003B95EF - 0x003B95F6 (7 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B95EF(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B95EF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B95F6
 * Original: 0x003B95F6 - 0x003B963B (69 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B95F6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B95F6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x60;
    PUSH32(esp, ebx);
    SET_LO8(ebx, MEM8(ebp + 8));
    PUSH32(esp, esi);
    SET_LO8(ebx, LO8(ebx) + 0x23);
    PUSH32(esp, edi);
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) + MEM8(ebp + 0xC));
    PUSH32(esp, 0x3B83B8);
    { uint32_t _icall_t = MEM32(0x3C1598); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9615: ;
    edi = SX8(LO8(ebx));
    esi = 0; /* xor self */
    esi++;
    ecx = edi + -70;
    esi = esi << LO8(ecx);
    if (TEST_NZ(MEM32(0xF273C0), esi)) { g_seh_ebp = ebp; sub_003B963B(); return; } /* jne: not equal / not zero */

loc_003B9628: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3B83B8);
    { uint32_t _icall_t = MEM32(0x3C1594); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9633: ;
    PUSH32(esp, 0xF);
    POP32(esp, eax);
    g_seh_ebp = ebp; sub_003B96FD(); return; /* tail jmp 0x003B96FD */

}

/**
 * sub_003B963B
 * Original: 0x003B963B - 0x003B96FD (194 bytes, 66 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B963B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B963B: ;
    if (CMP_NE(MEM8(0xF273BC), LO8(ebx))) goto loc_003B964A; /* jne: not equal / not zero */

loc_003B9643: ;
    PUSH32(esp, 0x58);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002B86E6(); /* call 0x002B86E6 */

loc_003B964A: ;
    PUSH32(esp, edi);
    eax = ebp + -96;
    PUSH32(esp, 0x46BAE0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336977(); /* call 0x00336977 */

loc_003B9659: ;
    esp = esp + 0xC;
    eax = ebp + -96;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    eax = ebp + -12;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C14E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B966A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x20);
    PUSH32(esp, 1);
    edi = 0; /* xor self */
    PUSH32(esp, edi);
    PUSH32(esp, 0x80);
    eax = ebp + -12;
    MEM32(ebp + -28) = eax;
    PUSH32(esp, edi);
    eax = ebp + -20;
    PUSH32(esp, eax);
    eax = ebp + -32;
    PUSH32(esp, eax);
    PUSH32(esp, 0x100000);
    eax = ebp + -4;
    PUSH32(esp, eax);
    MEM32(ebp + -32) = edi;
    MEM32(ebp + -24) = 0x40;
    { uint32_t _icall_t = MEM32(0x3C1540); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B969E: ;
    ebx = eax;
    if (CMP_L(ebx, edi)) goto loc_003B96EB; /* jl: less (signed <) */

loc_003B96A4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, 0x90020);
    eax = ebp + -20;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebp + -4));
    { uint32_t _icall_t = MEM32(0x3C1508); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B96BD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -4));
    ebx = eax;
    { uint32_t _icall_t = MEM32(0x3C14D8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B96C8: ;
    if (CMP_L(ebx, edi)) goto loc_003B96EB; /* jl: less (signed <) */

loc_003B96CC: ;
    eax = ebp + -12;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1500); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B96D6: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    ebx = eax;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9BB9(); /* call 0x003B9BB9 */

loc_003B96E3: ;
    esi = ~esi;
    MEM32(0xF273C0) = MEM32(0xF273C0) & esi;

loc_003B96EB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3B83B8);
    { uint32_t _icall_t = MEM32(0x3C1594); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B96F6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C1504); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003B96FD(); return; /* restored dropped fall-through to sub_003B96FD */
}

/**
 * sub_003B96FD
 * Original: 0x003B96FD - 0x003B9704 (7 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B96FD(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B96FD: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9704
 * Original: 0x003B9704 - 0x003B9764 (96 bytes, 32 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9704(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9704: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x94;
    PUSH32(esp, ebx);
    SET_LO8(ebx, MEM8(ebp + 8));
    SET_LO8(ebx, LO8(ebx) + 0x23);
    PUSH32(esp, edi);
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) + MEM8(ebp + 0xC));
    PUSH32(esp, 0x3B83B8);
    { uint32_t _icall_t = MEM32(0x3C1598); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9725: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, LO8(ebx));
    eax = 0; /* xor self */
    eax++;
    ebx = 0; /* xor self */
    ecx = ecx - 0x46;
    eax = eax << LO8(ecx);
    /* test MEM32(0xF273C0), eax - flags set for next jcc */
    MEM32(ebp + -20) = eax;
    if (TEST_NZ(MEM32(0xF273C0), eax)) { g_seh_ebp = ebp; sub_003B9764(); return; } /* jne: not equal / not zero */

loc_003B973E: ;
    eax = ebp + -148;
    MEM32(ebp + -12) = eax;
    eax = ebp + -16;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0xC));
    MEM16(ebp + -16) = LO16(ebx);
    PUSH32(esp, MEM32(ebp + 8));
    MEM16(ebp + -14) = 0x3E;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9C26(); /* call 0x003B9C26 */

loc_003B9760: ;
    edi = eax;
    g_seh_ebp = ebp; sub_003B9766(); return; /* tail jmp 0x003B9766 */

}

/**
 * sub_003B9764
 * Original: 0x003B9764 - 0x003B9766 (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9764(void)
{

loc_003B9764: ;
    edi = 0; /* xor self */

    sub_003B9766(); return; /* restored dropped fall-through to sub_003B9766 */
}

/**
 * sub_003B9766
 * Original: 0x003B9766 - 0x003B986F (265 bytes, 95 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9766(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9766: ;
    if (CMP_L(edi, ebx)) goto loc_003B9857; /* jl: less (signed <) */

loc_003B976E: ;
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9A7B(); /* call 0x003B9A7B */

loc_003B977A: ;
    esi = MEM32(0x3C15E0);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, 0x18);
    ecx = ebp + -84;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, eax);
    PUSH32(esp, 0x70000);
    MEM32(ebp + -4) = eax;
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9795: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003B9840; /* jl: less (signed <) */

loc_003B979F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, 0x20);
    eax = ebp + -60;
    PUSH32(esp, eax);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, MEM32(ebp + -4));
    PUSH32(esp, 0x74004);
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B97B3: ;
    /* cmp MEM32(ebp + -48), ebx - flags set for next jcc */
    edi = eax;
    esi = 0x1000;
    if (CMP_G(MEM32(ebp + -48), ebx)) goto loc_003B97CB; /* jg: greater (signed >) */

loc_003B97BF: ;
    if (CMP_L(MEM32(ebp + -48), ebx)) goto loc_003B97C6; /* jl: less (signed <) */

loc_003B97C1: ;
    if (CMP_AE(MEM32(ebp + -52), esi)) goto loc_003B97CB; /* jae: above or equal (unsigned >=) */

loc_003B97C6: ;
    edi = 0xC000014Fu;

loc_003B97CB: ;
    if (CMP_L(edi, ebx)) goto loc_003B9840; /* jl: less (signed <) */

loc_003B97CF: ;
    PUSH32(esp, 0x24830000);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BBC27(); /* call 0x002BBC27 */

loc_003B97DA: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(ebp + -8) = eax;
    if (CMP_EQ(eax, ebx)) goto loc_003B983B; /* je: equal / zero */

loc_003B97E1: ;
    ecx = ebp + -28;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + -4));
    MEM32(ebp + -28) = ebx;
    PUSH32(esp, 2);
    MEM32(ebp + -24) = ebx;
    { uint32_t _icall_t = MEM32(0x3C15DC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B97F8: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003B982C; /* jl: less (signed <) */

loc_003B97FE: ;
    eax = MEM32(ebp + -8);
    if (CMP_NE(MEM32(eax), 0x58544146)) goto loc_003B9827; /* jne: not equal / not zero */

loc_003B9809: ;
    edx = MEM32(ebp + 0x14);
    ecx = MEM32(ebp + 0x18);
    edi = MEM32(ebp + 0x10);
    esi = eax + edx;
    eax = ecx;
    ecx = ecx >> 2;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    edi = 0; /* xor self */
    goto loc_003B982C;

loc_003B9827: ;
    edi = 0xC000014Fu;

loc_003B982C: ;
    PUSH32(esp, 0x24830000);
    PUSH32(esp, MEM32(ebp + -8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BBCC7(); /* call 0x002BBCC7 */

loc_003B9839: ;
    goto loc_003B9840;

loc_003B983B: ;
    edi = 0xC000009Au;

loc_003B9840: ;
    eax = MEM32(ebp + -20);
    /* test MEM32(0xF273C0), eax - flags set for next jcc */
    POP32(esp, esi);
    if (TEST_NZ(MEM32(0xF273C0), eax)) goto loc_003B9857; /* jne: not equal / not zero */

loc_003B984C: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9BB9(); /* call 0x003B9BB9 */

loc_003B9857: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3B83B8);
    { uint32_t _icall_t = MEM32(0x3C1594); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9862: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1504); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9869: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

}

/**
 * sub_003B986F
 * Original: 0x003B986F - 0x003B9888 (25 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B986F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B986F: ;
    SET_LO8(eax, MEM8(esp + 4));
    if (CMP_L(LO8(eax), 0x46)) { g_seh_ebp = ebp; sub_003B9888(); return; } /* jl: less (signed <) */

loc_003B9877: ;
    if (CMP_G(LO8(eax), 0x4D)) { g_seh_ebp = ebp; sub_003B9888(); return; } /* jg: greater (signed >) */

loc_003B987B: ;
    eax = SX8(LO8(eax));
    eax = eax - 0x46;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    eax = eax - edx;
    eax = (uint32_t)((int32_t)eax >> 1);
    g_seh_ebp = ebp; sub_003B988B(); return; /* tail jmp 0x003B988B */

}

/**
 * sub_003B9888
 * Original: 0x003B9888 - 0x003B988B (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9888(void)
{

loc_003B9888: ;
    eax = eax | 0xFFFFFFFFu;

    sub_003B988B(); return; /* restored dropped fall-through to sub_003B988B */
}

/**
 * sub_003B988B
 * Original: 0x003B988B - 0x003B988E (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B988B(void)
{

loc_003B988B: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B988E
 * Original: 0x003B988E - 0x003B98AA (28 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B988E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B988E: ;
    SET_LO8(eax, MEM8(esp + 4));
    if (CMP_L(LO8(eax), 0x46)) { g_seh_ebp = ebp; sub_003B98AA(); return; } /* jl: less (signed <) */

loc_003B9896: ;
    if (CMP_G(LO8(eax), 0x4D)) { g_seh_ebp = ebp; sub_003B98AA(); return; } /* jg: greater (signed >) */

loc_003B989A: ;
    eax = SX8(LO8(eax));
    eax = eax - 0x46;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    PUSH32(esp, 2);
    POP32(esp, ecx);
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = edx;
    g_seh_ebp = ebp; sub_003B98AD(); return; /* tail jmp 0x003B98AD */

}

/**
 * sub_003B98AA
 * Original: 0x003B98AA - 0x003B98AD (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98AA(void)
{

loc_003B98AA: ;
    eax = eax | 0xFFFFFFFFu;

    sub_003B98AD(); return; /* restored dropped fall-through to sub_003B98AD */
}

/**
 * sub_003B98AD
 * Original: 0x003B98AD - 0x003B98B0 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98AD(void)
{

loc_003B98AD: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B98B0
 * Original: 0x003B98B0 - 0x003B98CB (27 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98B0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B98B0: ;
    ecx = MEM32(esp + 8);
    eax = 0; /* xor self */
    eax++;
    eax = eax << LO8(ecx);
    ecx = MEM32(esp + 4);
    MEM32(ecx + 4) = MEM32(ecx + 4) | eax;
    if (CMP_EQ(MEM8(esp + 0xC), 0)) { g_seh_ebp = ebp; sub_003B98CB(); return; } /* je: equal / zero */

loc_003B98C7: ;
    MEM32(ecx) = MEM32(ecx) | eax;
    g_seh_ebp = ebp; sub_003B98CF(); return; /* tail jmp 0x003B98CF */

}

/**
 * sub_003B98CB
 * Original: 0x003B98CB - 0x003B98CF (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98CB(void)
{

loc_003B98CB: ;
    eax = ~eax;
    MEM32(ecx) = MEM32(ecx) & eax;

    sub_003B98CF(); return; /* restored dropped fall-through to sub_003B98CF */
}

/**
 * sub_003B98CF
 * Original: 0x003B98CF - 0x003B98D2 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98CF(void)
{

loc_003B98CF: ;
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B98D2
 * Original: 0x003B98D2 - 0x003B990E (60 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B98D2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B98D2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B98DA: ;
    edi = MEM32(esp + 0x10);
    /* test edi, edi - flags set for next jcc */
    edx = MEM32(esp + 0xC);
    esi = MEM32(edx);
    if (TEST_Z(edi, edi)) goto loc_003B98ED; /* je: equal / zero */

loc_003B98E8: ;
    ecx = MEM32(edx + 8);
    MEM32(edi) = ecx;

loc_003B98ED: ;
    edi = MEM32(esp + 0x14);
    if (TEST_Z(edi, edi)) goto loc_003B98FF; /* je: equal / zero */

loc_003B98F5: ;
    ecx = MEM32(edx + 8);
    ecx = ecx & MEM32(edx + 4);
    ecx = ecx & MEM32(edx);
    MEM32(edi) = ecx;

loc_003B98FF: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9907: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B990E
 * Original: 0x003B990E - 0x003B9913 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B990E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B990E: ;
    g_seh_ebp = ebp; sub_003B87B3(); return; /* tail jmp 0x003B87B3 */

}

/**
 * sub_003B9913
 * Original: 0x003B9913 - 0x003B9935 (34 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9913(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9913: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B991A: ;
    edx = MEM32(esp + 8);
    esi = MEM32(edx);
    MEM32(edx + 4) = MEM32(edx + 4) & 0;
    SET_LO8(ecx, LO8(eax));
    MEM32(edx + 8) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B992F: ;
    eax = esi;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B9935
 * Original: 0x003B9935 - 0x003B994F (26 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9935(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9935: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    eax = 0; /* xor self */
    if (CMP_NE(MEM32(esi + 4), eax)) { g_seh_ebp = ebp; sub_003B994F(); return; } /* jne: not equal / not zero */

loc_003B9943: ;
    ecx = MEM32(ebp + 0xC);
    MEM32(ecx) = eax;
    ecx = MEM32(ebp + 0x10);
    MEM32(ecx) = eax;
    g_seh_ebp = ebp; sub_003B999D(); return; /* tail jmp 0x003B999D */

}

/**
 * sub_003B994F
 * Original: 0x003B994F - 0x003B999D (78 bytes, 32 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B994F(void)
{
    uint32_t ebp;
    int _cf = 0; /* carry flag */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B994F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9957: ;
    ecx = MEM32(esi + 8);
    ebx = MEM32(ebp + 0xC);
    ecx = ~ecx;
    ecx = ecx & MEM32(esi);
    MEM32(ebx) = ecx;
    edx = MEM32(esi);
    ecx = MEM32(ebp + 0x10);
    edx = ~edx;
    edx = edx & MEM32(esi + 8);
    MEM32(ecx) = edx;
    edi = MEM32(esi + 4);
    edi = edi & MEM32(esi + 8);
    edi = edi & MEM32(esi);
    edx = edx | edi;
    MEM32(ecx) = edx;
    MEM32(ebx) = MEM32(ebx) | edi;
    ecx = MEM32(esi);
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    MEM32(esi + 8) = ecx;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B998E: ;
    eax = MEM32(ebx);
    ecx = MEM32(ebp + 0x10);
    eax = eax | MEM32(ecx);
    POP32(esp, edi);
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = (uint32_t)(-(int32_t)eax);
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003B999D(); return; /* restored dropped fall-through to sub_003B999D */
}

/**
 * sub_003B999D
 * Original: 0x003B999D - 0x003B99A2 (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B999D(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B999D: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B99A2
 * Original: 0x003B99A2 - 0x003B99BD (27 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B99A2(void)
{
    int _flags = 0; /* fallback flag var */

loc_003B99A2: ;
    eax = MEM32(0xF273C8);
    if (TEST_Z(eax, eax)) goto loc_003B99BC; /* je: equal / zero */

loc_003B99AB: ;
    ecx = MEM32(eax + 8);
    MEM32(0xF273C8) = ecx;
    MEM32(eax + 0xC) = MEM32(eax + 0xC) & 0;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;

loc_003B99BC: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003B99BD
 * Original: 0x003B99BD - 0x003B99E5 (40 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B99BD(void)
{

loc_003B99BD: ;
    edx = MEM32(esp + 4);
    PUSH32(esp, edi);
    PUSH32(esp, 0x58);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    edi = edx + 0x10;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM32(edx + 0xC) = 4;
    eax = MEM32(0xF273C8);
    MEM32(edx + 8) = eax;
    MEM32(0xF273C8) = edx;
    POP32(esp, edi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B99E5
 * Original: 0x003B99E5 - 0x003B9A7B (150 bytes, 58 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B99E5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B99E5: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE2D(); /* call 0x003BBE2D */

loc_003B99F3: ;
    ebx = 0; /* xor self */
    ecx = 0; /* xor self */
    if (CMP_B(eax, 0x10)) goto loc_003B9A00; /* jb: below (unsigned <) */

loc_003B99FC: ;
    eax = eax - 0x10;
    ecx++;

loc_003B9A00: ;
    eax = ecx + eax * 2;
    ecx = MEM32(0xF2A3D4);
    PUSH32(esp, ebx);
    eax = eax + eax * 2;
    PUSH32(esp, 1);
    esi = ecx + eax * 4;
    PUSH32(esp, 2);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003B9A1B: ;
    if (CMP_EQ(eax, ebx)) goto loc_003B9A69; /* je: equal / zero */

loc_003B9A1F: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 5) = LO8(ecx);
    /* cmp MEM16(eax + 4), 0x40 - flags set for next jcc */
    ecx = edi;
    if (CMP_NE(MEM16(eax + 4), 0x40)) goto loc_003B9A6B; /* jne: not equal / not zero */

loc_003B9A2E: ;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, 2);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003B9A37: ;
    if (CMP_EQ(eax, ebx)) goto loc_003B9A69; /* je: equal / zero */

loc_003B9A3B: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 6) = LO8(ecx);
    /* cmp MEM16(eax + 4), 0x40 - flags set for next jcc */
    ecx = edi;
    if (CMP_NE(MEM16(eax + 4), 0x40)) goto loc_003B9A6B; /* jne: not equal / not zero */

loc_003B9A4A: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003B9A50: ;
    ecx = edi;
    MEM32(esi) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCC9(); /* call 0x003BBCC9 */

loc_003B9A59: ;
    PUSH32(esp, ebx);
    ecx = edi;
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003B9A64: ;
    PUSH32(esp, ebx);
    ecx = edi;
    goto loc_003B9A70;

loc_003B9A69: ;
    ecx = edi;

loc_003B9A6B: ;
    PUSH32(esp, 0x80000400u);

loc_003B9A70: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003B9A75: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B9A7B
 * Original: 0x003B9A7B - 0x003B9A98 (29 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9A7B(void)
{

loc_003B9A7B: ;
    ecx = MEM32(esp + 4);
    eax = MEM32(esp + 8);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF2A3D4);
    eax = eax + eax * 2;
    eax = MEM32(ecx + eax * 4 + 8);
    eax = MEM32(eax);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9A98
 * Original: 0x003B9A98 - 0x003B9AC6 (46 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9A98(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9A98: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0xC);
    /* test eax, 0x40000 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = MEM32(esi + 8);
    if (TEST_Z(eax, 0x40000)) { g_seh_ebp = ebp; sub_003B9AC6(); return; } /* je: equal / zero */

loc_003B9AAB: ;
    edx = MEM32(esi + 0x24);
    MEM32(esi + 0x24) = MEM32(esi + 0x24) & 0;
    MEM8(esi + 0x111) = 0x43;
    MEM32(esi + 0x120) = edx;
    eax = eax & 0xFFFBFFFFu;
    g_seh_ebp = ebp; sub_003B9AFB(); return; /* tail jmp 0x003B9AFB */

}

/**
 * sub_003B9AC6
 * Original: 0x003B9AC6 - 0x003B9AFB (53 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9AC6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9AC6: ;
    if (TEST_Z(eax, 0x20000)) goto loc_003B9AE8; /* je: equal / zero */

loc_003B9ACD: ;
    edx = MEM32(esi + 0x20);
    MEM32(esi + 0x20) = MEM32(esi + 0x20) & 0;
    MEM8(esi + 0x111) = 0x43;
    MEM32(esi + 0x120) = edx;
    eax = eax & 0xFFFDFFFFu;
    g_seh_ebp = ebp; sub_003B9AFB(); return; /* tail jmp 0x003B9AFB */

loc_003B9AE8: ;
    if (TEST_Z(eax, 0x10000)) { g_seh_ebp = ebp; sub_003B9B21(); return; } /* je: equal / zero */

loc_003B9AEF: ;
    MEM8(esi + 0x111) = 0xC3;
    eax = eax & 0xFFFEFFFFu;

    g_seh_ebp = ebp; sub_003B9AFB(); return; /* restored dropped fall-through to sub_003B9AFB */
}

/**
 * sub_003B9AFB
 * Original: 0x003B9AFB - 0x003B9B6A (111 bytes, 36 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9AFB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9AFB: ;
    ecx = esi + 0x110;
    MEM8(ecx) = 0x1C;
    MEM32(esi + 0x118) = 0x3B9A98;
    MEM32(esi + 0x11C) = esi;
    MEM32(esi + 0xC) = eax;
    PUSH32(esp, ecx);
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9B1F: ;
    goto loc_003B9B65;

    eax = eax & 0xFFF7FFFFu;
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* test LO8(eax), 1 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    MEM32(esi + 8) = ebx;
    if (TEST_Z(LO8(eax), 1)) goto loc_003B9B49; /* je: equal / zero */

loc_003B9B33: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = esi + 0x12C;
    PUSH32(esp, eax);
    MEM32(edi + 8) = ebx;
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9B45: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) & 0xFFFFFFFEu;

loc_003B9B49: ;
    if (TEST_Z(MEM8(esi + 0xC), 2)) goto loc_003B9B64; /* je: equal / zero */

loc_003B9B4F: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003B9B56: ;
    MEM32(edi) = ebx;
    eax = MEM32(esi + 0xC);
    eax = eax & 0xFFFFFFFDu;
    eax = eax | 4;
    MEM32(esi + 0xC) = eax;

loc_003B9B64: ;
    POP32(esp, ebx);

loc_003B9B65: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9B21
 * Original: 0x003B9B21 - 0x003B9B6A (73 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9B21(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9B21: ;
    eax = eax & 0xFFF7FFFFu;
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* test LO8(eax), 1 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    MEM32(esi + 8) = ebx;
    if (TEST_Z(LO8(eax), 1)) goto loc_003B9B49; /* je: equal / zero */

loc_003B9B33: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = esi + 0x12C;
    PUSH32(esp, eax);
    MEM32(edi + 8) = ebx;
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9B45: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) & 0xFFFFFFFEu;

loc_003B9B49: ;
    if (TEST_Z(MEM8(esi + 0xC), 2)) goto loc_003B9B64; /* je: equal / zero */

loc_003B9B4F: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003B9B56: ;
    MEM32(edi) = ebx;
    eax = MEM32(esi + 0xC);
    eax = eax & 0xFFFFFFFDu;
    eax = eax | 4;
    MEM32(esi + 0xC) = eax;

loc_003B9B64: ;
    POP32(esp, ebx);
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9B6A
 * Original: 0x003B9B6A - 0x003B9B84 (26 bytes, 10 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9B6A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9B6A: ;
    eax = MEM32(ecx + 0xC);
    edx = 0x80000;
    if (TEST_NZ(edx, eax)) goto loc_003B9B83; /* jne: not equal / not zero */

loc_003B9B76: ;
    PUSH32(esp, ecx);
    eax = eax | edx;
    PUSH32(esp, 0);
    MEM32(ecx + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9A98(); /* call 0x003B9A98 */

loc_003B9B83: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003B9B84
 * Original: 0x003B9B84 - 0x003B9BB9 (53 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9B84(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9B84: ;
    ecx = MEM32(esp + 4);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003B9B8E: ;
    esi = eax;
    ecx = MEM32(esi + 8);
    if (TEST_Z(ecx, ecx)) goto loc_003B9BAB; /* je: equal / zero */

loc_003B9B97: ;
    eax = MEM32(ecx + 0xC);
    if (TEST_NZ(LO8(eax), 4)) goto loc_003B9BAB; /* jne: not equal / not zero */

loc_003B9B9E: ;
    eax = eax | 2;
    MEM32(ecx + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9B6A(); /* call 0x003B9B6A */

loc_003B9BA9: ;
    goto loc_003B9BB5;

loc_003B9BAB: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003B9BB2: ;
    MEM32(esi) = MEM32(esi) & 0;

loc_003B9BB5: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B9BB9
 * Original: 0x003B9BB9 - 0x003B9C10 (87 bytes, 31 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9BB9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9BB9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(ebp + 8);
    eax = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF2A3D4);
    PUSH32(esp, esi);
    eax = eax + eax * 2;
    PUSH32(esp, edi);
    edi = ecx + eax * 4;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9BDA: ;
    esi = MEM32(edi + 8);
    ebx = 0; /* xor self */
    /* cmp MEM32(esi + 8), ebx - flags set for next jcc */
    SET_LO8(ecx, LO8(eax));
    MEM8(ebp + 0xF) = LO8(ecx);
    if (CMP_EQ(MEM32(esi + 8), ebx)) { g_seh_ebp = ebp; sub_003B9C10(); return; } /* je: equal / zero */

loc_003B9BE9: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) | 1;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9B6A(); /* call 0x003B9B6A */

loc_003B9BF4: ;
    SET_LO8(ecx, MEM8(ebp + 0xF));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9BFD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = esi + 0x12C;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9C0E: ;
    g_seh_ebp = ebp; sub_003B9C19(); return; /* tail jmp 0x003B9C19 */

}

/**
 * sub_003B9C10
 * Original: 0x003B9C10 - 0x003B9C19 (9 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C10(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9C10: ;
    MEM32(edi + 8) = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003B9C19(); return; /* restored dropped fall-through to sub_003B9C19 */
}

/**
 * sub_003B9C19
 * Original: 0x003B9C19 - 0x003B9C26 (13 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C19(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9C19: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B99BD(); /* call 0x003B99BD */

loc_003B9C1F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003B9C26
 * Original: 0x003B9C26 - 0x003B9C63 (61 bytes, 23 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C26(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9C26: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    eax = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF2A3D4);
    PUSH32(esp, esi);
    eax = eax + eax * 2;
    PUSH32(esp, edi);
    ebx = 0; /* xor self */
    MEM32(ebp + -8) = ebx;
    edi = ecx + eax * 4;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9C4E: ;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B99A2(); /* call 0x003B99A2 */

loc_003B9C56: ;
    esi = eax;
    if (CMP_NE(esi, ebx)) { g_seh_ebp = ebp; sub_003B9C63(); return; } /* jne: not equal / not zero */

loc_003B9C5C: ;
    esi = 0xC0000017u;
    g_seh_ebp = ebp; sub_003B9C72(); return; /* tail jmp 0x003B9C72 */

}

/**
 * sub_003B9C63
 * Original: 0x003B9C63 - 0x003B9C72 (15 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C63(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9C63: ;
    /* cmp MEM32(edi), ebx - flags set for next jcc */
    PUSH32(esp, esi);
    if (CMP_NE(MEM32(edi), ebx)) { g_seh_ebp = ebp; sub_003B9C82(); return; } /* jne: not equal / not zero */

loc_003B9C68: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B99BD(); /* call 0x003B99BD */

loc_003B9C6D: ;
    esi = 0xC000009Du;

    g_seh_ebp = ebp; sub_003B9C72(); return; /* restored dropped fall-through to sub_003B9C72 */
}

/**
 * sub_003B9C72
 * Original: 0x003B9C72 - 0x003B9E12 (416 bytes, 102 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C72(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9C72: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9C7B: ;
    eax = esi;
    goto loc_003B9DD3;

    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BC1E4);
    eax = esi + 0x98;
    MEM32(edi + 8) = esi;
    PUSH32(esp, eax);
    MEM32(esi + 8) = edi;
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9C9A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9CA5: ;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM32(esi + 0x130) = ebx;
    eax = esi + 0x134;
    ebx = esi + 0xB8;
    MEM8(esi + 0x12C) = 0;
    MEM8(esi + 0x12E) = 4;
    MEM32(esi + 0x138) = eax;
    MEM32(eax) = eax;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 0x82;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9CE6: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9CEE: ;
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 1;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 2;
    SET_LO8(eax, MEM8(edi + 5));
    MEM8(esi + 0xCD) = LO8(eax);
    MEM8(esi + 0xCE) = 2;
    MEM8(esi + 0xCF) = 0;
    MEM16(esi + 0xD4) = 0x40;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9D2B: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9D2F: ;
    eax = MEM32(esi + 0xC8);
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 2;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM32(esi + 0x20) = eax;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 2;
    SET_LO8(eax, MEM8(edi + 6));
    MEM8(esi + 0xCD) = LO8(eax);
    MEM8(esi + 0xCE) = 2;
    MEM8(esi + 0xCF) = 0;
    MEM16(esi + 0xD4) = 0x40;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9D75: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9D79: ;
    eax = MEM32(esi + 0xC8);
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 4;
    MEM32(esi + 0x24) = eax;
    goto loc_003B9D91;

loc_003B9D88: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003B9D8E: ;
    MEM32(ebp + -8) = eax;

loc_003B9D91: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9D9A: ;
    ecx = MEM32(ebp + -8);
    eax = 0xC0000000u;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003B9DB5; /* jne: not equal / not zero */

loc_003B9DA8: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9BB9(); /* call 0x003B9BB9 */

loc_003B9DB3: ;
    goto loc_003B9DD0;

loc_003B9DB5: ;
    eax = MEM32(ebp + 0x10);
    MEM16(eax) = 0xC;
    PUSH32(esp, MEM32(esi + 4));
    PUSH32(esp, 0x3C147C);
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336977(); /* call 0x00336977 */

loc_003B9DCD: ;
    esp = esp + 0xC;

loc_003B9DD0: ;
    eax = MEM32(ebp + -8);

loc_003B9DD3: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B9C82
 * Original: 0x003B9C82 - 0x003B9E12 (400 bytes, 98 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9C82(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9C82: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BC1E4);
    eax = esi + 0x98;
    MEM32(edi + 8) = esi;
    PUSH32(esp, eax);
    MEM32(esi + 8) = edi;
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9C9A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9CA5: ;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM32(esi + 0x130) = ebx;
    eax = esi + 0x134;
    ebx = esi + 0xB8;
    MEM8(esi + 0x12C) = 0;
    MEM8(esi + 0x12E) = 4;
    MEM32(esi + 0x138) = eax;
    MEM32(eax) = eax;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 0x82;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9CE6: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9CEE: ;
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 1;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 2;
    SET_LO8(eax, MEM8(edi + 5));
    MEM8(esi + 0xCD) = LO8(eax);
    MEM8(esi + 0xCE) = 2;
    MEM8(esi + 0xCF) = 0;
    MEM16(esi + 0xD4) = 0x40;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9D2B: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9D2F: ;
    eax = MEM32(esi + 0xC8);
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 2;
    MEM32(esi + 0xC0) = MEM32(esi + 0xC0) & 0;
    MEM32(esi + 0x20) = eax;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0xB9) = 2;
    SET_LO8(eax, MEM8(edi + 6));
    MEM8(esi + 0xCD) = LO8(eax);
    MEM8(esi + 0xCE) = 2;
    MEM8(esi + 0xCF) = 0;
    MEM16(esi + 0xD4) = 0x40;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9D75: ;
    if (TEST_S(eax, eax)) goto loc_003B9D88; /* jl: less (signed <) */

loc_003B9D79: ;
    eax = MEM32(esi + 0xC8);
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 4;
    MEM32(esi + 0x24) = eax;
    goto loc_003B9D91;

loc_003B9D88: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003B9D8E: ;
    MEM32(ebp + -8) = eax;

loc_003B9D91: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9D9A: ;
    ecx = MEM32(ebp + -8);
    eax = 0xC0000000u;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003B9DB5; /* jne: not equal / not zero */

loc_003B9DA8: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B9BB9(); /* call 0x003B9BB9 */

loc_003B9DB3: ;
    goto loc_003B9DD0;

loc_003B9DB5: ;
    eax = MEM32(ebp + 0x10);
    MEM16(eax) = 0xC;
    PUSH32(esp, MEM32(esi + 4));
    PUSH32(esp, 0x3C147C);
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336977(); /* call 0x00336977 */

loc_003B9DCD: ;
    esp = esp + 0xC;

loc_003B9DD0: ;
    eax = MEM32(ebp + -8);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003B9DDA
 * Original: 0x003B9DDA - 0x003B9E12 (56 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9DDA(void)
{

loc_003B9DDA: ;
    eax = MEM32(0x3C1600);
    MEM32(0x3B8424) = eax;
    MEM32(0x3B8428) = eax;
    MEM32(0x3B8434) = eax;
    MEM32(0x3B8438) = eax;
    MEM32(0x3B843C) = eax;
    MEM32(0x3B8440) = eax;
    MEM32(0x3B8444) = eax;
    MEM32(0x3B8448) = eax;
    MEM32(0x3B8454) = eax;
    MEM32(0x3B8458) = eax;
    esp += 4; return; /* ret */

}

/**
 * sub_003B9E12
 * Original: 0x003B9E12 - 0x003B9E31 (31 bytes, 12 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9E12(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9E12: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA129(); /* call 0x003BA129 */

loc_003B9E22: ;
    if (TEST_NZ(eax, eax)) { g_seh_ebp = ebp; sub_003B9E31(); return; } /* jne: not equal / not zero */

loc_003B9E26: ;
    PUSH32(esp, 0x57);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BAAF3(); /* call 0x002BAAF3 */

loc_003B9E2D: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003B9E64(); return; /* tail jmp 0x003B9E64 */

}

/**
 * sub_003B9E31
 * Original: 0x003B9E31 - 0x003B9E64 (51 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9E31(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9E31: ;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x14);
    if (TEST_NZ(esi, esi)) goto loc_003B9E3C; /* jne: not equal / not zero */

loc_003B9E39: ;
    esi = MEM32(eax + 0x10);

loc_003B9E3C: ;
    /* cmp MEM32(ebp + 0x10), 1 - flags set for next jcc */
    edx = MEM32(ebp + 0xC);
    if (CMP_NE(MEM32(ebp + 0x10), 1)) goto loc_003B9E48; /* jne: not equal / not zero */

loc_003B9E45: ;
    edx = edx + 0x10;

loc_003B9E48: ;
    PUSH32(esp, esi);
    ecx = ebp + -4;
    PUSH32(esp, ecx);
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD493(); /* call 0x003BD493 */

loc_003B9E54: ;
    /* cmp MEM32(ebp + -4), 0 - flags set for next jcc */
    POP32(esp, esi);
    if (CMP_NE(MEM32(ebp + -4), 0)) goto loc_003B9E61; /* jne: not equal / not zero */

loc_003B9E5B: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_002BAAF3(); /* call 0x002BAAF3 */

loc_003B9E61: ;
    eax = MEM32(ebp + -4);

    g_seh_ebp = ebp; sub_003B9E64(); return; /* restored dropped fall-through to sub_003B9E64 */
}

/**
 * sub_003B9E64
 * Original: 0x003B9E64 - 0x003B9E68 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9E64(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9E64: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003B9E68
 * Original: 0x003B9E68 - 0x003B9E74 (12 bytes, 3 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9E68(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003B9E68: ;
    ecx = MEM32(esp + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD0FF(); /* call 0x003BD0FF */

loc_003B9E71: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003B9E74
 * Original: 0x003B9E74 - 0x003BA04C (472 bytes, 145 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003B9E74(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003B9E74: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x48;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(0x3C15E8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9E89: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    esi = MEM32(eax);
    if (TEST_Z(esi, esi)) goto loc_003BA02A; /* je: equal / zero */

loc_003B9E99: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BA02A; /* jne: not equal / not zero */

loc_003B9EA3: ;
    edx = MEM32(ebp + 0xC);
    eax = 0; /* xor self */
    PUSH32(esp, 6);
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM8(edi) = LO8(eax); edi++; /* stosb */
    SET_LO8(eax, MEM8(esi + 0xB));
    MEM8(edx) = LO8(eax);
    eax = MEM32(esi + 0xE);
    if (TEST_Z(MEM8(eax + 0x28), 1)) goto loc_003B9ECA; /* je: equal / zero */

loc_003B9EBE: ;
    MEM32(ebp + -8) = 5;
    goto loc_003BA031;

loc_003B9ECA: ;
    eax = MEM32(eax + 0xC);
    eax = ZX8(MEM8(eax));
    MEM32(ebp + -20) = MEM32(ebp + -20) & 0;
    MEM32(ebp + -56) = MEM32(ebp + -56) & 0;
    ecx = ebp + -16;
    MEM32(ebp + -12) = ecx;
    MEM32(ebp + -16) = ecx;
    ecx = ebp + -24;
    MEM32(ebp + -60) = ecx;
    ecx = eax + 2;
    edx = edx + 0x13;
    MEM8(ebp + -24) = 0;
    MEM8(ebp + -22) = 4;
    MEM8(ebp + -72) = 0x30;
    MEM8(ebp + -71) = 0x40;
    edi = 0x3BBC94;
    MEM32(ebp + -64) = edi;
    MEM32(ebp + -48) = edx;
    MEM32(ebp + -52) = ecx;
    MEM8(ebp + -44) = 2;
    MEM8(ebp + -43) = 1;
    MEM8(ebp + -42) = 0;
    MEM8(ebp + -32) = 0xC1;
    MEM8(ebp + -31) = 1;
    MEM16(ebp + -30) = 0x200;
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    eax = eax + 2;
    MEM16(ebp + -26) = LO16(eax);
    eax = ebp + -72;
    MEM16(ebp + -28) = LO16(ecx);
    ecx = MEM32(esi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9F40: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9F49: ;
    ecx = MEM32(esi);
    eax = ebp + -24;
    PUSH32(esp, eax);
    edx = ebp + -72;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD98(); /* call 0x003BCD98 */

loc_003B9F57: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9F59: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    ecx = 0; /* xor self */
    if (CMP_EQ(MEM32(eax), ecx)) goto loc_003BA02A; /* je: equal / zero */

loc_003B9F69: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BA02A; /* jne: not equal / not zero */

loc_003B9F73: ;
    if (CMP_L(MEM32(ebp + -68), ecx)) goto loc_003BA01D; /* jl: less (signed <) */

loc_003B9F7C: ;
    eax = MEM32(esi + 0xE);
    eax = MEM32(eax + 8);
    eax = ZX8(MEM8(eax));
    edx = ebp + -24;
    MEM32(ebp + -60) = edx;
    edx = MEM32(ebp + 0xC);
    edx++;
    MEM32(ebp + -48) = edx;
    edx = eax + 2;
    eax = eax + 2;
    MEM8(ebp + -72) = 0x30;
    MEM8(ebp + -71) = 0x40;
    MEM32(ebp + -64) = edi;
    MEM32(ebp + -56) = ecx;
    MEM32(ebp + -52) = edx;
    MEM8(ebp + -44) = 2;
    MEM8(ebp + -43) = 1;
    MEM8(ebp + -42) = LO8(ecx);
    MEM8(ebp + -32) = 0xC1;
    MEM8(ebp + -31) = 1;
    MEM16(ebp + -30) = 0x100;
    SET_LO16(edx, ZX8(MEM8(esi + 5)));
    MEM16(ebp + -26) = LO16(eax);
    eax = ebp + -16;
    MEM32(ebp + -12) = eax;
    MEM32(ebp + -16) = eax;
    eax = ebp + -72;
    MEM16(ebp + -28) = LO16(edx);
    MEM8(ebp + -24) = LO8(ecx);
    MEM8(ebp + -22) = 4;
    MEM32(ebp + -20) = ecx;
    ecx = MEM32(esi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003B9FED: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003B9FF6: ;
    ecx = MEM32(esi);
    eax = ebp + -24;
    PUSH32(esp, eax);
    edx = ebp + -72;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD98(); /* call 0x003BCD98 */

loc_003BA004: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA006: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003BA02A; /* je: equal / zero */

loc_003BA011: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BA02A; /* jne: not equal / not zero */

loc_003BA017: ;
    if (CMP_GE(MEM32(ebp + -68), 0)) goto loc_003BA031; /* jge: greater or equal (signed >=) */

loc_003BA01D: ;
    PUSH32(esp, MEM32(ebp + -68));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003BA025: ;
    MEM32(ebp + -8) = eax;
    goto loc_003BA031;

loc_003BA02A: ;
    MEM32(ebp + -8) = 0x48F;

loc_003BA031: ;
    eax = MEM32(ebp + 0xC);
    SET_LO8(ecx, MEM8(ebp + -1));
    MEM16(eax + 1) = MEM16(eax + 1) & 0;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA042: ;
    eax = MEM32(ebp + -8);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA04C
 * Original: 0x003BA04C - 0x003BA06B (31 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA04C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA04C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA056: ;
    edx = MEM32(esp + 0xC);
    ecx = MEM32(edx + 0xA3);
    if (TEST_Z(MEM8(ecx + 0x28), 0x10)) { g_seh_ebp = ebp; sub_003BA06B(); return; } /* je: equal / zero */

loc_003BA066: ;
    PUSH32(esp, 0x57);
    POP32(esp, esi);
    g_seh_ebp = ebp; sub_003BA0B0(); return; /* tail jmp 0x003BA0B0 */

}

/**
 * sub_003BA06B
 * Original: 0x003BA06B - 0x003BA0B0 (69 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA06B(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BA06B: ;
    ecx = MEM32(edx);
    if (TEST_Z(ecx, ecx)) goto loc_003BA077; /* je: equal / zero */

loc_003BA071: ;
    if (TEST_Z(MEM8(ecx + 4), 2)) goto loc_003BA07C; /* je: equal / zero */

loc_003BA077: ;
    ebx = 0x48F;

loc_003BA07C: ;
    ecx = MEM32(edx + 8);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    MEM32(edi) = ecx;
    MEM8(edx + 0xA2) = MEM8(edx + 0xA2) & 0xEF;
    ecx = MEM32(edx + 0xA3);
    ecx = MEM32(ecx + 8);
    ecx = ZX8(MEM8(ecx));
    esi = edx + 0x14;
    edx = ecx;
    edi = edi + 4;
    ecx = ecx >> 2;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = edx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    esi = ebx;
    POP32(esp, edi);

    sub_003BA0B0(); return; /* restored dropped fall-through to sub_003BA0B0 */
}

/**
 * sub_003BA0B0
 * Original: 0x003BA0B0 - 0x003BA0BF (15 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA0B0(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA0B0: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA0B8: ;
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA0BF
 * Original: 0x003BA0BF - 0x003BA0D6 (23 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA0BF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA0BF: ;
    ecx = MEM32(esp + 4);
    eax = ecx + 0xA3;
    edx = MEM32(eax);
    if (TEST_Z(MEM8(edx + 0x28), 0x20)) { g_seh_ebp = ebp; sub_003BA0D6(); return; } /* je: equal / zero */

loc_003BA0D1: ;
    PUSH32(esp, 0x57);
    POP32(esp, eax);
    g_seh_ebp = ebp; sub_003BA0EF(); return; /* tail jmp 0x003BA0EF */

}

/**
 * sub_003BA0D6
 * Original: 0x003BA0D6 - 0x003BA0EF (25 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA0D6(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA0D6: ;
    edx = MEM32(esp + 8);
    MEM8(edx + 0x40) = 0;
    eax = MEM32(eax);
    eax = MEM32(eax + 0xC);
    SET_LO8(eax, MEM8(eax));
    SET_LO8(eax, LO8(eax) + 2);
    MEM8(edx + 0x41) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD193(); /* call 0x003BD193 */

    g_seh_ebp = ebp; sub_003BA0EF(); return; /* restored dropped fall-through to sub_003BA0EF */
}

/**
 * sub_003BA0EF
 * Original: 0x003BA0EF - 0x003BA0F2 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA0EF(void)
{

loc_003BA0EF: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA0F2
 * Original: 0x003BA0F2 - 0x003BA123 (49 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA0F2(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BA0F2: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    eax = 0x3B8384;
    PUSH32(esp, edi);
    edi = eax;
    esi = 0x3B838C;
    SET_LO8(ebx, 0); /* xor self */
    /* cmp edi, esi - flags set for next jcc */
    MEM8(edx) = 0;
    if (CMP_AE(edi, esi)) goto loc_003BA11D; /* jae: above or equal (unsigned >=) */

loc_003BA10A: ;
    edi = MEM32(eax);
    if (TEST_Z(edi, edi)) goto loc_003BA116; /* je: equal / zero */

loc_003BA110: ;
    if (CMP_EQ(MEM8(edi), LO8(ecx))) { g_seh_ebp = ebp; sub_003BA123(); return; } /* je: equal / zero */

loc_003BA114: ;
    SET_LO8(ebx, LO8(ebx) + 1);

loc_003BA116: ;
    eax = eax + 4;
    if (CMP_B(eax, esi)) { RECOMP_SLICE_POINT(); goto loc_003BA10A; } /* jb: below (unsigned <) */

loc_003BA11D: ;
    eax = 0; /* xor self */
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA11F
 * Original: 0x003BA11F - 0x003BA123 (4 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA11F(void)
{

loc_003BA11F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA123
 * Original: 0x003BA123 - 0x003BA129 (6 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA123(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA123: ;
    MEM8(edx) = LO8(ebx);
    eax = MEM32(eax);
    g_seh_ebp = ebp; sub_003BA11F(); return; /* tail jmp 0x003BA11F */

}

/**
 * sub_003BA129
 * Original: 0x003BA129 - 0x003BA150 (39 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA129(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BA129: ;
    eax = 0x3B8384;
    PUSH32(esp, esi);
    edx = eax;
    esi = 0x3B838C;
    if (CMP_AE(edx, esi)) goto loc_003BA14C; /* jae: above or equal (unsigned >=) */

loc_003BA13A: ;
    edx = MEM32(eax);
    if (TEST_Z(edx, edx)) goto loc_003BA145; /* je: equal / zero */

loc_003BA140: ;
    if (CMP_EQ(MEM32(edx + 4), ecx)) { g_seh_ebp = ebp; sub_003BA150(); return; } /* je: equal / zero */

loc_003BA145: ;
    eax = eax + 4;
    if (CMP_B(eax, esi)) { RECOMP_SLICE_POINT(); goto loc_003BA13A; } /* jb: below (unsigned <) */

loc_003BA14C: ;
    eax = 0; /* xor self */
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA150
 * Original: 0x003BA150 - 0x003BA166 (22 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA150(void)
{

loc_003BA150: ;
    eax = MEM32(eax);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA154
 * Original: 0x003BA154 - 0x003BA166 (18 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA154(void)
{

loc_003BA154: ;
    eax = ecx;
    MEM8(eax) = 0xFF;
    MEM8(eax + 1) = 0x80;
    MEM8(eax + 2) = 0x80;
    MEM8(eax + 3) = 0x80;
    esp += 4; return; /* ret */

}

/**
 * sub_003BA166
 * Original: 0x003BA166 - 0x003BA1B6 (80 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA166(void)
{

loc_003BA166: ;
    edx = ZX8(MEM8(ecx + 0x79));
    eax = MEM32(ecx + 0xE0);
    edx = edx << 5;
    PUSH32(esp, esi);
    esi = eax + edx + 1;
    SET_LO8(eax, MEM8(esi));
    MEM8(ecx + 0x79) = LO8(eax);
    MEM8(esi) = 0x80;
    eax = MEM32(ecx + 0xE0);
    MEM8(eax + edx + 2) = 0x80;
    eax = MEM32(ecx + 0xE0);
    MEM8(eax + edx + 3) = 0x80;
    eax = MEM32(ecx + 0xE0);
    MEM32(eax + edx + 0x1C) = MEM32(eax + edx + 0x1C) & 0;
    eax = MEM32(ecx + 0xE0);
    MEM8(eax + edx + 7) = 0xFF;
    eax = MEM32(ecx + 0xE0);
    eax = eax + edx;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA1B6
 * Original: 0x003BA1B6 - 0x003BA1E8 (50 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA1B6(void)
{

loc_003BA1B6: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    ecx = MEM32(esi + 0xE0);
    eax = eax - ecx;
    eax = (uint32_t)((int32_t)eax >> 5);
    edx = ZX8(LO8(eax));
    edx = edx << 5;
    MEM8(edx + ecx) = 0xFF;
    SET_LO8(ebx, MEM8(esi + 0x79));
    ecx = MEM32(esi + 0xE0);
    MEM8(edx + ecx + 1) = LO8(ebx);
    MEM8(esi + 0x79) = LO8(eax);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BA1E8
 * Original: 0x003BA1E8 - 0x003BA1FC (20 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA1E8(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BA1E8: ;
    SET_LO8(eax, MEM8(ecx + 1));
    if (CMP_EQ(LO8(eax), 0x80)) { g_seh_ebp = ebp; sub_003BA1FC(); return; } /* je: equal / zero */

loc_003BA1EF: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF2A4B8);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA1FC
 * Original: 0x003BA1FC - 0x003BA1FF (3 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA1FC(void)
{

loc_003BA1FC: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BA1FF
 * Original: 0x003BA1FF - 0x003BA213 (20 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA1FF(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BA1FF: ;
    SET_LO8(eax, MEM8(ecx + 2));
    if (CMP_EQ(LO8(eax), 0x80)) { g_seh_ebp = ebp; sub_003BA213(); return; } /* je: equal / zero */

loc_003BA206: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF2A4B8);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA213
 * Original: 0x003BA213 - 0x003BA216 (3 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA213(void)
{

loc_003BA213: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BA216
 * Original: 0x003BA216 - 0x003BA22A (20 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA216(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BA216: ;
    SET_LO8(eax, MEM8(ecx + 3));
    if (CMP_EQ(LO8(eax), 0x80)) { g_seh_ebp = ebp; sub_003BA22A(); return; } /* je: equal / zero */

loc_003BA21D: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF2A4B8);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA22A
 * Original: 0x003BA22A - 0x003BA22D (3 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA22A(void)
{

loc_003BA22A: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BA22D
 * Original: 0x003BA22D - 0x003BA2F1 (196 bytes, 58 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA22D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA22D: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ecx;
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA166(); /* call 0x003BA166 */

loc_003BA23C: ;
    esi = eax;
    ebx = 0; /* xor self */
    if (CMP_EQ(esi, ebx)) goto loc_003BA2EB; /* je: equal / zero */

loc_003BA248: ;
    SET_LO8(eax, MEM8(esp + 0x10));
    MEM8(esi) = 0xFE;
    MEM8(esi + 4) = LO8(eax);
    MEM32(esi + 0x10) = ebx;
    eax = MEM32(edi + 0xC);
    PUSH32(esp, esi);
    ecx = edi;
    MEM32(esi + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF54(); /* call 0x003BBF54 */

loc_003BA263: ;
    /* cmp MEM8(0xF2A3D8), LO8(ebx) - flags set for next jcc */
    SET_LO8(eax, MEM8(esp + 0x14));
    if (CMP_EQ(MEM8(0xF2A3D8), LO8(ebx))) goto loc_003BA2A6; /* je: equal / zero */

loc_003BA26F: ;
    edi = esi + 0x18;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(esi + 5) = LO8(eax);
    { uint32_t _icall_t = MEM32(0x3C1510); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA27C: ;
    MEM32(edi) = MEM32(edi) + 0xF4240;
    MEM32(esi + 0x10) = ebx;
    _cf = ((uint32_t)(MEM32(edi)) < (uint32_t)(0xF4240)); /* CF from add */
    MEM32(edi + 4) = MEM32(edi + 4) + ebx + _cf; /* adc */
    eax = MEM32(0xF2A454);
    if (CMP_NE(eax, ebx)) goto loc_003BA29C; /* jne: not equal / not zero */

loc_003BA291: ;
    MEM32(0xF2A454) = esi;
    goto loc_003BA2EB;

loc_003BA299: ;
    eax = MEM32(eax + 0x10);

loc_003BA29C: ;
    if (CMP_NE(MEM32(eax + 0x10), ebx)) { RECOMP_SLICE_POINT(); goto loc_003BA299; } /* jne: not equal / not zero */

loc_003BA2A1: ;
    MEM32(eax + 0x10) = esi;
    goto loc_003BA2EB;

loc_003BA2A6: ;
    MEM8(esi) = 0xFD;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A40C);
    MEM8(0xF2A3DA) = LO8(eax);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFF0BDC0u;
    PUSH32(esp, eax);
    MEM8(0xF2A3D8) = 1;
    MEM8(0xF2A3D9) = LO8(ebx);
    MEM32(0xF2A458) = esi;
    MEM8(0xF2A3DB) = 0x80;
    MEM8(esi + 5) = LO8(ebx);
    PUSH32(esp, 0xF2A428);
    MEM8(0xF2A450) = LO8(ebx);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA2EB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA2F1
 * Original: 0x003BA2F1 - 0x003BA313 (34 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA2F1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA2F1: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A40C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFD050F80u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF2A428);
    MEM8(0xF2A450) = 1;
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA312: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BA313
 * Original: 0x003BA313 - 0x003BA38F (124 bytes, 30 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA313(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA313: ;
    /* cmp MEM32(esp + 4), 0 - flags set for next jcc */
    MEM8(0xF2A3DB) = 0x81;
    if (CMP_GE(MEM32(esp + 4), 0)) goto loc_003BA32E; /* jge: greater or equal (signed >=) */

loc_003BA321: ;
    PUSH32(esp, MEM32(esp + 8));
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA7A1(); /* call 0x003BA7A1 */

loc_003BA32C: ;
    goto loc_003BA361;

loc_003BA32E: ;
    if (CMP_NE(MEM32(esp + 4), 0x1000000)) goto loc_003BA340; /* jne: not equal / not zero */

loc_003BA338: ;
    eax = MEM32(esp + 8);
    MEM8(eax + 4) = MEM8(eax + 4) | 0x80;

loc_003BA340: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A40C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFFE7960u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF2A428);
    MEM8(0xF2A450) = 2;
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA361: ;
    esp += 12; return; /* ret 8 */

    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA364
 * Original: 0x003BA364 - 0x003BA38F (43 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA364(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA364: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A40C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFFFB1E0u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF2A428);
    MEM8(0xF2A3DB) = 0x84;
    MEM8(0xF2A450) = 3;
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA38C: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA38F
 * Original: 0x003BA38F - 0x003BA3B2 (35 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA38F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA38F: ;
    PUSH32(esp, ebx);
    edx = 0; /* xor self */
    SET_LO8(ebx, 0); /* xor self */
    edx++;
    PUSH32(esp, esi);
    SET_LO8(eax, LO8(edx));

loc_003BA398: ;
    esi = ZX8(LO8(ebx));
    if (TEST_Z(MEM32(ecx + esi * 4 + 8), edx)) { g_seh_ebp = ebp; sub_003BA3B2(); return; } /* je: equal / zero */

loc_003BA3A1: ;
    edx = edx << 1;
    if ((edx != 0)) goto loc_003BA3AA; /* jne: not equal / not zero */

loc_003BA3A5: ;
    edx = 0; /* xor self */
    SET_LO8(ebx, LO8(ebx) + 1);
    edx++;

loc_003BA3AA: ;
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_B(LO8(eax), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003BA398; } /* jb: below (unsigned <) */

loc_003BA3B0: ;
    g_seh_ebp = ebp; sub_003BA3BB(); return; /* tail jmp 0x003BA3BB */

}

/**
 * sub_003BA3B2
 * Original: 0x003BA3B2 - 0x003BA3BB (9 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA3B2(void)
{

loc_003BA3B2: ;
    esi = ZX8(LO8(ebx));
    ecx = ecx + esi * 4 + 8;
    MEM32(ecx) = MEM32(ecx) | edx;

    sub_003BA3BB(); return; /* restored dropped fall-through to sub_003BA3BB */
}

/**
 * sub_003BA3BB
 * Original: 0x003BA3BB - 0x003BA3C0 (5 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA3BB(void)
{

loc_003BA3BB: ;
    POP32(esp, esi);
    SET_LO8(eax, LO8(eax) & 0x7F);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA3C0
 * Original: 0x003BA3C0 - 0x003BA3F4 (52 bytes, 26 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA3C0(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BA3C0: ;
    PUSH32(esp, ebx);
    SET_LO8(ebx, 0); /* xor self */
    SET_LO8(edx, LO8(edx) - 1);
    /* cmp LO8(edx), 0x1F - flags set for next jcc */
    PUSH32(esp, esi);
    if (CMP_BE(LO8(edx), 0x1F)) goto loc_003BA3DF; /* jbe: below or equal (unsigned <=) */

loc_003BA3CB: ;
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) - 0x20);
    SET_LO8(eax, LO8(eax) >> 5);
    SET_LO8(eax, LO8(eax) + 1);
    eax = ZX8(LO8(eax));
    SET_LO8(ebx, LO8(eax));

loc_003BA3D9: ;
    SET_LO8(edx, LO8(edx) + 0xE0);
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003BA3D9; } /* jne: not equal / not zero */

loc_003BA3DF: ;
    eax = ZX8(LO8(ebx));
    esi = 0; /* xor self */
    eax = ecx + eax * 4 + 8;
    esi++;
    SET_LO8(ecx, LO8(edx));
    esi = esi << LO8(ecx);
    esi = ~esi;
    MEM32(eax) = MEM32(eax) & esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA3F4
 * Original: 0x003BA3F4 - 0x003BA3FB (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA3F4(void)
{

loc_003BA3F4: ;
    MEM32(0xF2A4BC) = MEM32(0xF2A4BC) + 1;
    esp += 4; return; /* ret */

}

/**
 * sub_003BA3FB
 * Original: 0x003BA3FB - 0x003BA402 (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA3FB(void)
{

loc_003BA3FB: ;
    MEM32(0xF2A4BC) = MEM32(0xF2A4BC) - 1;
    esp += 4; return; /* ret */

}

/**
 * sub_003BA402
 * Original: 0x003BA402 - 0x003BA42B (41 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA402(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA402: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA40B: ;
    if (CMP_NE(MEM32(0xF2A4BC), esi)) goto loc_003BA41C; /* jne: not equal / not zero */

loc_003BA413: ;
    if (CMP_EQ(MEM8(0xF2A3D8), 0)) goto loc_003BA41F; /* je: equal / zero */

loc_003BA41C: ;
    esi = 0; /* xor self */
    esi++;

loc_003BA41F: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA427: ;
    eax = esi;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA42B
 * Original: 0x003BA42B - 0x003BA440 (21 bytes, 6 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA42B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA42B: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(eax + -20);
    PUSH32(esp, 5);
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA22D(); /* call 0x003BA22D */

loc_003BA43D: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA440
 * Original: 0x003BA440 - 0x003BA462 (34 bytes, 13 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA440(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA440: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(0xF2A458);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0xC);
    ebx = 0; /* xor self */
    edi = edi + 0x18;
    if (CMP_EQ(MEM8(0xF2A3D9), LO8(ebx))) { g_seh_ebp = ebp; sub_003BA462(); return; } /* je: equal / zero */

loc_003BA459: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA7A1(); /* call 0x003BA7A1 */

loc_003BA460: ;
    g_seh_ebp = ebp; sub_003BA49E(); return; /* tail jmp 0x003BA49E */

}

/**
 * sub_003BA462
 * Original: 0x003BA462 - 0x003BA49E (60 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA462(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA462: ;
    ecx = esi;
    MEM8(0xF2A3DB) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA46F: ;
    if (CMP_NE(MEM8(eax), LO8(ebx))) goto loc_003BA48A; /* jne: not equal / not zero */

loc_003BA473: ;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 4));
    PUSH32(esp, esi);
    PUSH32(esp, 0x3BA313);
    eax = eax & 0x7F;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE5A9(); /* call 0x003BE5A9 */

loc_003BA488: ;
    g_seh_ebp = ebp; sub_003BA49E(); return; /* tail jmp 0x003BA49E */

loc_003BA48A: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 4));
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ecx = ecx & 0xFFFFFF7Fu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDB9F(); /* call 0x003BDB9F */

    g_seh_ebp = ebp; sub_003BA49E(); return; /* restored dropped fall-through to sub_003BA49E */
}

/**
 * sub_003BA49E
 * Original: 0x003BA49E - 0x003BA4A2 (4 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA49E(void)
{

loc_003BA49E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA4A2
 * Original: 0x003BA4A2 - 0x003BA4A7 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA4A2(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA4A2: ;
    g_seh_ebp = ebp; sub_003BA313(); return; /* tail jmp 0x003BA313 */

}

/**
 * sub_003BA4A7
 * Original: 0x003BA4A7 - 0x003BA51D (118 bytes, 47 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA4A7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA4A7: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    SET_LO8(eax, MEM8(esi + 7));
    /* cmp LO8(eax), 0xFF - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_EQ(LO8(eax), 0xFF)) goto loc_003BA4CE; /* je: equal / zero */

loc_003BA4B3: ;
    ecx = MEM32(esi + 0x10);
    ecx = MEM32(ecx + 0x14);
    eax = ZX8(LO8(eax));
    eax = MEM32(ecx + eax * 4);
    if (TEST_Z(eax, eax)) goto loc_003BA4CE; /* je: equal / zero */

loc_003BA4C3: ;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(esi + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B98B0(); /* call 0x003B98B0 */

loc_003BA4CE: ;
    /* cmp MEM8(esi), 5 - flags set for next jcc */
    ebx = 0xF2A3D8;
    if (CMP_NE(MEM8(esi), 5)) goto loc_003BA502; /* jne: not equal / not zero */

loc_003BA4D8: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA4DF: ;
    edi = eax;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF9C(); /* call 0x003BBF9C */

loc_003BA4E9: ;
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003BA511; /* jne: not equal / not zero */

loc_003BA4ED: ;
    SET_LO8(edx, MEM8(edi + 5));
    ecx = MEM32(edi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA3C0(); /* call 0x003BA3C0 */

loc_003BA4F8: ;
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1B6(); /* call 0x003BA1B6 */

loc_003BA500: ;
    goto loc_003BA511;

loc_003BA502: ;
    SET_LO8(edx, MEM8(esi + 5));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BA511; /* je: equal / zero */

loc_003BA509: ;
    ecx = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA3C0(); /* call 0x003BA3C0 */

loc_003BA511: ;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1B6(); /* call 0x003BA1B6 */

loc_003BA519: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BA51D
 * Original: 0x003BA51D - 0x003BA56F (82 bytes, 34 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA51D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA51D: ;
    ecx = MEM32(esp + 4);
    /* cmp MEM8(ecx), 4 - flags set for next jcc */
    PUSH32(esp, esi);
    if (CMP_NE(MEM8(ecx), 4)) goto loc_003BA559; /* jne: not equal / not zero */

loc_003BA527: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BA52C: ;
    esi = eax;
    if (TEST_Z(esi, esi)) goto loc_003BA56B; /* je: equal / zero */

loc_003BA532: ;
    PUSH32(esp, edi);

loc_003BA533: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BA53A: ;
    edi = eax;
    eax = MEM32(esi + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BA549; /* je: equal / zero */

loc_003BA543: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0xC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA547: ;
    goto loc_003BA550;

loc_003BA549: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BA550: ;
    /* test edi, edi - flags set for next jcc */
    esi = edi;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003BA533; } /* jne: not equal / not zero */

loc_003BA556: ;
    POP32(esp, edi);
    goto loc_003BA56B;

loc_003BA559: ;
    eax = MEM32(ecx + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BA566; /* je: equal / zero */

loc_003BA560: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    { uint32_t _icall_t = MEM32(eax + 0xC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA564: ;
    goto loc_003BA56B;

loc_003BA566: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BA56B: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BA56F
 * Original: 0x003BA56F - 0x003BA5A4 (53 bytes, 17 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA56F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BA56F: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    if (CMP_EQ(MEM8(0xF2A3D9), LO8(ebx))) goto loc_003BA587; /* je: equal / zero */

loc_003BA57F: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA51D(); /* call 0x003BA51D */

loc_003BA587: ;
    eax = MEM32(0xF2A454);
    /* cmp eax, ebx - flags set for next jcc */
    MEM8(0xF2A3D9) = LO8(ebx);
    if (CMP_NE(eax, ebx)) { g_seh_ebp = ebp; sub_003BA5A4(); return; } /* jne: not equal / not zero */

loc_003BA596: ;
    MEM32(0xF2A458) = ebx;
    MEM8(0xF2A3D8) = LO8(ebx);
    g_seh_ebp = ebp; sub_003BA619(); return; /* tail jmp 0x003BA619 */

}

/**
 * sub_003BA5A4
 * Original: 0x003BA5A4 - 0x003BA619 (117 bytes, 30 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA5A4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA5A4: ;
    MEM32(0xF2A458) = eax;
    ecx = MEM32(eax + 0x10);
    MEM32(0xF2A454) = ecx;
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(0xF2A3DA) = LO8(ecx);
    MEM8(0xF2A3DB) = 0x80;
    MEM8(eax) = 0xFD;
    eax = MEM32(0xF2A458);
    MEM32(eax + 0x10) = ebx;
    eax = MEM32(0xF2A458);
    MEM8(eax + 5) = LO8(ebx);
    eax = ebp + -8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1510); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA5DF: ;
    eax = MEM32(0xF2A458);
    ecx = MEM32(ebp + -4);
    if (CMP_L(ecx, MEM32(eax + 0x1C))) goto loc_003BA5FD; /* jl: less (signed <) */

loc_003BA5EC: ;
    if (CMP_G(ecx, MEM32(eax + 0x1C))) goto loc_003BA5F6; /* jg: greater (signed >) */

loc_003BA5EE: ;
    ecx = MEM32(ebp + -8);
    if (CMP_BE(ecx, MEM32(eax + 0x18))) goto loc_003BA5FD; /* jbe: below or equal (unsigned <=) */

loc_003BA5F6: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA440(); /* call 0x003BA440 */

loc_003BA5FB: ;
    g_seh_ebp = ebp; sub_003BA619(); return; /* tail jmp 0x003BA619 */

loc_003BA5FD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A40C);
    MEM8(0xF2A450) = LO8(ebx);
    PUSH32(esp, MEM32(eax + 0x1C));
    PUSH32(esp, MEM32(eax + 0x18));
    PUSH32(esp, 0xF2A428);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003BA619(); return; /* restored dropped fall-through to sub_003BA619 */
}

/**
 * sub_003BA619
 * Original: 0x003BA619 - 0x003BA61E (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA619(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA619: ;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA61E
 * Original: 0x003BA61E - 0x003BA695 (119 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA61E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA61E: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(esp + 0xC));
    edi = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF23(); /* call 0x003BBF23 */

loc_003BA62B: ;
    esi = eax;
    if (TEST_Z(esi, esi)) goto loc_003BA690; /* je: equal / zero */

loc_003BA631: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF9C(); /* call 0x003BBF9C */

loc_003BA639: ;
    if (CMP_NE(MEM8(esi), 0xFE)) goto loc_003BA670; /* jne: not equal / not zero */

loc_003BA63E: ;
    eax = MEM32(0xF2A454);
    if (CMP_NE(eax, esi)) goto loc_003BA654; /* jne: not equal / not zero */

loc_003BA647: ;
    eax = MEM32(esi + 0x10);
    MEM32(0xF2A454) = eax;
    goto loc_003BA65F;

loc_003BA651: ;
    eax = MEM32(eax + 0x10);

loc_003BA654: ;
    if (CMP_NE(esi, MEM32(eax + 0x10))) { RECOMP_SLICE_POINT(); goto loc_003BA651; } /* jne: not equal / not zero */

loc_003BA659: ;
    ecx = MEM32(esi + 0x10);
    MEM32(eax + 0x10) = ecx;

loc_003BA65F: ;
    MEM32(esi + 0x10) = MEM32(esi + 0x10) & 0;
    PUSH32(esp, esi);
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1B6(); /* call 0x003BA1B6 */

loc_003BA66E: ;
    goto loc_003BA690;

loc_003BA670: ;
    if (CMP_EQ(MEM8(0xF2A3D8), 0)) goto loc_003BA68A; /* je: equal / zero */

loc_003BA679: ;
    if (CMP_NE(MEM32(0xF2A458), esi)) goto loc_003BA68A; /* jne: not equal / not zero */

loc_003BA681: ;
    MEM8(0xF2A3D9) = 1;
    goto loc_003BA690;

loc_003BA68A: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA51D(); /* call 0x003BA51D */

loc_003BA690: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BA695
 * Original: 0x003BA695 - 0x003BA6A9 (20 bytes, 10 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA695(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BA695: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    /* cmp MEM8(ecx), 5 - flags set for next jcc */
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    if (CMP_NE(MEM8(ecx), 5)) { g_seh_ebp = ebp; sub_003BA6A9(); return; } /* jne: not equal / not zero */

loc_003BA6A0: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA6A5: ;
    esi = eax;
    g_seh_ebp = ebp; sub_003BA6AB(); return; /* tail jmp 0x003BA6AB */

}

/**
 * sub_003BA6A9
 * Original: 0x003BA6A9 - 0x003BA6AB (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA6A9(void)
{

loc_003BA6A9: ;
    esi = ecx;

    sub_003BA6AB(); return; /* restored dropped fall-through to sub_003BA6AB */
}

/**
 * sub_003BA6AB
 * Original: 0x003BA6AB - 0x003BA6DA (47 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA6AB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA6AB: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA6B2: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003BA6D6; /* je: equal / zero */

loc_003BA6B8: ;
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0x7F);
    MEM8(ebp + -4) = LO8(eax);
    PUSH32(esp, MEM32(ebp + -4));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA61E(); /* call 0x003BA61E */

loc_003BA6CA: ;
    PUSH32(esp, 5);
    PUSH32(esp, MEM32(ebp + -4));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA22D(); /* call 0x003BA22D */

loc_003BA6D6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BA6DA
 * Original: 0x003BA6DA - 0x003BA75B (129 bytes, 49 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA6DA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BA6DA: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    SET_LO8(ebx, 0); /* xor self */
    edi = 0; /* xor self */
    /* cmp MEM8(0xF2A3D9), 0 - flags set for next jcc */
    esi = ecx;
    MEM8(ebp + -4) = LO8(ebx);
    MEM8(0xF2A3DB) = 0xA;
    if (CMP_NE(MEM8(0xF2A3D9), 0)) goto loc_003BA71C; /* jne: not equal / not zero */

loc_003BA6FA: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA6FF: ;
    edi = eax;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF9C(); /* call 0x003BBF9C */

loc_003BA709: ;
    SET_LO8(eax, MEM8(0xF2A3DA));
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BA71C; /* je: equal / zero */

loc_003BA712: ;
    SET_LO8(ebx, LO8(eax));
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0x7F);
    MEM8(ebp + -4) = LO8(eax);

loc_003BA71C: ;
    SET_LO8(edx, MEM8(esi + 5));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BA72B; /* je: equal / zero */

loc_003BA723: ;
    ecx = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA3C0(); /* call 0x003BA3C0 */

loc_003BA72B: ;
    PUSH32(esp, esi);
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1B6(); /* call 0x003BA1B6 */

loc_003BA736: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003BA747; /* je: equal / zero */

loc_003BA73A: ;
    SET_LO8(ebx, LO8(ebx) - 1);
    ecx = edi;
    PUSH32(esp, ebx);
    PUSH32(esp, MEM32(ebp + -4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA22D(); /* call 0x003BA22D */

loc_003BA747: ;
    PUSH32(esp, esi);
    PUSH32(esp, 0);
    MEM8(0xF2A3D9) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA56F(); /* call 0x003BA56F */

loc_003BA756: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BA75B
 * Original: 0x003BA75B - 0x003BA76E (19 bytes, 5 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA75B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA75B: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, MEM32(esp + 8));
    ecx = MEM32(eax + -20);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA61E(); /* call 0x003BA61E */

loc_003BA76B: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA76E
 * Original: 0x003BA76E - 0x003BA7A1 (51 bytes, 13 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA76E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA76E: ;
    ecx = MEM32(esp + 8);
    eax = 0; /* xor self */
    /* cmp MEM32(esp + 4), eax - flags set for next jcc */
    MEM8(0xF2A3DB) = 9;
    if (CMP_GE(MEM32(esp + 4), eax)) goto loc_003BA78C; /* jge: greater or equal (signed >=) */

loc_003BA781: ;
    if (CMP_NE(MEM8(0xF2A3D9), LO8(eax))) goto loc_003BA794; /* jne: not equal / not zero */

loc_003BA789: ;
    MEM8(ecx + 5) = LO8(eax);

loc_003BA78C: ;
    if (CMP_EQ(MEM8(0xF2A3D9), LO8(eax))) goto loc_003BA799; /* je: equal / zero */

loc_003BA794: ;
    MEM8(0xF2A3DA) = LO8(eax);

loc_003BA799: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA6DA(); /* call 0x003BA6DA */

loc_003BA79E: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA7A1
 * Original: 0x003BA7A1 - 0x003BA7FA (89 bytes, 31 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA7A1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA7A1: ;
    /* cmp MEM8(0xF2A3D9), 0 - flags set for next jcc */
    PUSH32(esp, esi);
    MEM8(0xF2A3DB) = 8;
    if (CMP_NE(MEM8(0xF2A3D9), 0)) { g_seh_ebp = ebp; sub_003BA7FA(); return; } /* jne: not equal / not zero */

loc_003BA7B2: ;
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA7BD: ;
    if (CMP_NE(MEM8(eax), 0)) goto loc_003BA7E3; /* jne: not equal / not zero */

loc_003BA7C2: ;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 4));
    eax = eax & 0x7F;
    PUSH32(esp, eax);
    eax = MEM32(esi + 0xC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE5F6(); /* call 0x003BE5F6 */

loc_003BA7D7: ;
    PUSH32(esp, esi);
    PUSH32(esp, 0);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA76E(); /* call 0x003BA76E */

loc_003BA7E1: ;
    g_seh_ebp = ebp; sub_003BA80A(); return; /* tail jmp 0x003BA80A */

loc_003BA7E3: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 4));
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    ecx = ecx & 0xFFFFFF7Fu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDB9F(); /* call 0x003BDB9F */

loc_003BA7F8: ;
    g_seh_ebp = ebp; sub_003BA80A(); return; /* tail jmp 0x003BA80A */

}

/**
 * sub_003BA7FA
 * Original: 0x003BA7FA - 0x003BA80A (16 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA7FA(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA7FA: ;
    ecx = MEM32(esp + 0xC);
    MEM8(0xF2A3DA) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA6DA(); /* call 0x003BA6DA */

    g_seh_ebp = ebp; sub_003BA80A(); return; /* restored dropped fall-through to sub_003BA80A */
}

/**
 * sub_003BA80A
 * Original: 0x003BA80A - 0x003BA80E (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA80A(void)
{

loc_003BA80A: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA80E
 * Original: 0x003BA80E - 0x003BA873 (101 bytes, 22 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA80E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA80E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A428);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BA819: ;
    eax = MEM32(esp + 4);
    MEM8(0xF2A3DB) = 3;
    if (CMP_L(MEM32(eax + 4), 0)) goto loc_003BA83D; /* jl: less (signed <) */

loc_003BA82A: ;
    /* cmp MEM8(0xF2A3D9), 0 - flags set for next jcc */
    MEM32(0xF2A3E4) = 0x3BA364;
    if (CMP_EQ(MEM8(0xF2A3D9), 0)) goto loc_003BA847; /* je: equal / zero */

loc_003BA83D: ;
    MEM32(0xF2A3E4) = 0x3BA7A1;

loc_003BA847: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    MEM8(0xF2A3DC) = 0x1C;
    MEM8(0xF2A3DD) = 0x43;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BA86B: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BA873
 * Original: 0x003BA873 - 0x003BA8A3 (48 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA873(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BA873: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    ecx = 0; /* xor self */
    ecx++;
    ebx = 0; /* xor self */
    /* cmp MEM32(ebp + 8), ebx - flags set for next jcc */
    PUSH32(esp, edi);
    MEM32(ebp + -4) = ecx;
    MEM8(0xF2A3DB) = 7;
    if (CMP_GE(MEM32(ebp + 8), ebx)) { g_seh_ebp = ebp; sub_003BA8A3(); return; } /* jge: greater or equal (signed >=) */

loc_003BA892: ;
    if (CMP_NE(MEM32(ebp + 8), 0x80000400u)) goto loc_003BA89E; /* jne: not equal / not zero */

loc_003BA89B: ;
    MEM32(ebp + -4) = ebx;

loc_003BA89E: ;
    MEM32(esi + 0x10) = ebx;
    g_seh_ebp = ebp; sub_003BA8C4(); return; /* tail jmp 0x003BA8C4 */

}

/**
 * sub_003BA8A3
 * Original: 0x003BA8A3 - 0x003BA8C4 (33 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA8A3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA8A3: ;
    SET_LO8(eax, MEM8(esi + 7));
    if (CMP_EQ(LO8(eax), 0xFF)) { g_seh_ebp = ebp; sub_003BA8C4(); return; } /* je: equal / zero */

loc_003BA8AA: ;
    edx = MEM32(esi + 0x10);
    edx = MEM32(edx + 0x14);
    eax = ZX8(LO8(eax));
    eax = MEM32(edx + eax * 4);
    if (CMP_EQ(eax, ebx)) { g_seh_ebp = ebp; sub_003BA8C4(); return; } /* je: equal / zero */

loc_003BA8BA: ;
    PUSH32(esp, ecx);
    PUSH32(esp, MEM32(esi + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003B98B0(); /* call 0x003B98B0 */

    g_seh_ebp = ebp; sub_003BA8C4(); return; /* restored dropped fall-through to sub_003BA8C4 */
}

/**
 * sub_003BA8C4
 * Original: 0x003BA8C4 - 0x003BA9FF (315 bytes, 94 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA8C4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA8C4: ;
    SET_LO8(eax, MEM8(esi));
    if (CMP_EQ(LO8(eax), 2)) goto loc_003BA9D9; /* je: equal / zero */

loc_003BA8CE: ;
    if (CMP_EQ(LO8(eax), 1)) goto loc_003BA9D9; /* je: equal / zero */

loc_003BA8D6: ;
    /* cmp LO8(eax), 5 - flags set for next jcc */
    ecx = MEM32(esi + 8);
    edi = esi;
    MEM32(ebp + -12) = ecx;
    MEM32(esi + 8) = ebx;
    MEM32(ebp + -8) = 0x3BA56F;
    if (CMP_NE(LO8(eax), 5)) goto loc_003BA98A; /* jne: not equal / not zero */

loc_003BA8F0: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BA8F7: ;
    ecx = esi;
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BA900: ;
    /* cmp MEM8(0xF2A3D9), 0 - flags set for next jcc */
    edi = eax;
    if (CMP_NE(MEM8(0xF2A3D9), 0)) goto loc_003BA9A2; /* jne: not equal / not zero */

loc_003BA90F: ;
    if (CMP_NE(MEM32(esi + 0x10), 0)) goto loc_003BA944; /* jne: not equal / not zero */

loc_003BA915: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF9C(); /* call 0x003BBF9C */

loc_003BA91D: ;
    PUSH32(esp, esi);
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1B6(); /* call 0x003BA1B6 */

loc_003BA928: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BA92F: ;
    if (TEST_NZ(eax, eax)) goto loc_003BA944; /* jne: not equal / not zero */

loc_003BA933: ;
    PUSH32(esp, edi);
    MEM8(0xF2A3DA) = LO8(eax);
    PUSH32(esp, eax);

loc_003BA93A: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA7A1(); /* call 0x003BA7A1 */

loc_003BA93F: ;
    goto loc_003BA9F8;

loc_003BA944: ;
    if (TEST_Z(ebx, ebx)) goto loc_003BA9A2; /* je: equal / zero */

loc_003BA948: ;
    eax = MEM32(0xF2A4B4);

loc_003BA94D: ;
    ecx = ZX8(MEM8(eax));
    eax = eax + ecx;
    if (CMP_NE(MEM8(eax + 1), 4)) { RECOMP_SLICE_POINT(); goto loc_003BA94D; } /* jne: not equal / not zero */

loc_003BA958: ;
    MEM32(0xF2A4B4) = eax;
    SET_LO8(eax, MEM8(eax + 2));
    MEM8(ebx + 2) = LO8(eax);
    eax = MEM32(0xF2A4B4);
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(ebp + 9) = LO8(ecx);
    SET_LO8(ecx, MEM8(eax + 6));
    SET_LO8(eax, MEM8(eax + 7));
    MEM8(ebp + 0xA) = LO8(ecx);
    MEM8(ebp + 0xB) = LO8(eax);
    MEM8(ebp + 8) = 0x82;
    PUSH32(esp, MEM32(ebp + 8));
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA9FF(); /* call 0x003BA9FF */

loc_003BA988: ;
    goto loc_003BA9F8;

loc_003BA98A: ;
    if (CMP_GE(MEM32(ebp + 8), ebx)) goto loc_003BA9A2; /* jge: greater or equal (signed >=) */

loc_003BA98F: ;
    if (CMP_NE(MEM32(ebp + -4), ebx)) goto loc_003BA99B; /* jne: not equal / not zero */

loc_003BA994: ;
    MEM8(0xF2A3DA) = 0;

loc_003BA99B: ;
    MEM32(ebp + -8) = 0x3BA7A1;

loc_003BA9A2: ;
    eax = MEM32(ebp + -8);
    MEM32(0xF2A3E4) = eax;
    eax = MEM32(ebp + -12);
    MEM32(0xF2A3EC) = eax;
    MEM8(0xF2A3DC) = 0x1C;
    MEM8(0xF2A3DD) = 0x43;
    MEM32(0xF2A3E8) = edi;
    eax = MEM32(edi + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BA9D7: ;
    goto loc_003BA9F8;

loc_003BA9D9: ;
    if (CMP_GE(MEM32(ebp + 8), ebx)) goto loc_003BA9F1; /* jge: greater or equal (signed >=) */

loc_003BA9DE: ;
    if (CMP_NE(MEM32(ebp + -4), ebx)) goto loc_003BA9EA; /* jne: not equal / not zero */

loc_003BA9E3: ;
    MEM8(0xF2A3DA) = 0;

loc_003BA9EA: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    { RECOMP_SLICE_POINT(); goto loc_003BA93A; }

loc_003BA9F1: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA56F(); /* call 0x003BA56F */

loc_003BA9F8: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BA9FF
 * Original: 0x003BA9FF - 0x003BAA23 (36 bytes, 13 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BA9FF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BA9FF: ;
    PUSH32(esp, esi);
    esi = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC199(); /* call 0x003BC199 */

loc_003BAA07: ;
    if (CMP_EQ(MEM32(esi + 0x14), 0x20)) { g_seh_ebp = ebp; sub_003BAA23(); return; } /* je: equal / zero */

loc_003BAA0D: ;
    PUSH32(esp, MEM32(esp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB064(); /* call 0x003BB064 */

loc_003BAA16: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x10) = eax;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BAA23(); return; } /* je: equal / zero */

loc_003BAA1D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BAA21: ;
    g_seh_ebp = ebp; sub_003BAA2F(); return; /* tail jmp 0x003BAA2F */

}

/**
 * sub_003BAA23
 * Original: 0x003BAA23 - 0x003BAA2F (12 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAA23(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAA23: ;
    ecx = esi;
    PUSH32(esp, 0x80000400u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

    g_seh_ebp = ebp; sub_003BAA2F(); return; /* restored dropped fall-through to sub_003BAA2F */
}

/**
 * sub_003BAA2F
 * Original: 0x003BAA2F - 0x003BAB0E (223 bytes, 53 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAA2F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAA2F: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

    edx = MEM32(esp + 8);
    ebx = 0; /* xor self */
    MEM8(0xF2A3DB) = 2;
    if (CMP_L(MEM32(edx + 4), ebx)) goto loc_003BAB00; /* jl: less (signed <) */

loc_003BAA55: ;
    if (CMP_NE(MEM8(0xF2A3D9), LO8(ebx))) goto loc_003BAB00; /* jne: not equal / not zero */

loc_003BAA61: ;
    if (CMP_B(MEM32(edx + 0x14), 8)) goto loc_003BAAF9; /* jb: below (unsigned <) */

loc_003BAA6B: ;
    SET_LO8(eax, MEM8(0xF2A463));
    if (CMP_A(LO8(eax), 0x40)) goto loc_003BAAF9; /* ja: above (unsigned >) */

loc_003BAA78: ;
    if (CMP_NE(MEM8(0xF2A45D), 1)) goto loc_003BAAF9; /* jne: not equal / not zero */

loc_003BAA81: ;
    SET_LO8(ecx, MEM8(0xF2A45C));
    if (CMP_EQ(LO8(ecx), 8)) goto loc_003BAA91; /* je: equal / zero */

loc_003BAA8C: ;
    if (CMP_NE(LO8(ecx), 0x12)) goto loc_003BAAF9; /* jne: not equal / not zero */

loc_003BAA91: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = MEM32(esi + 0xC);
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA38F(); /* call 0x003BA38F */

loc_003BAAA1: ;
    MEM8(esi + 5) = LO8(eax);
    MEM32(0xF2A3E4) = 0x3BA80E;
    MEM32(0xF2A3F4) = ebx;
    MEM32(0xF2A3F0) = ebx;
    MEM8(0xF2A404) = LO8(ebx);
    MEM8(0xF2A405) = 5;
    SET_LO16(eax, ZX8(MEM8(esi + 5)));
    MEM16(0xF2A406) = LO16(eax);
    MEM16(0xF2A408) = LO16(ebx);
    MEM16(0xF2A40A) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA2F1(); /* call 0x003BA2F1 */

loc_003BAAE5: ;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAAF6: ;
    POP32(esp, esi);
    goto loc_003BAB0A;

loc_003BAAF9: ;
    MEM32(edx + 4) = 0x80000600u;

loc_003BAB00: ;
    PUSH32(esp, MEM32(esp + 0xC));
    PUSH32(esp, edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA80E(); /* call 0x003BA80E */

loc_003BAB0A: ;
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BAA33
 * Original: 0x003BAA33 - 0x003BAB0E (219 bytes, 51 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAA33(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAA33: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0xF2A428);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BAA3F: ;
    edx = MEM32(esp + 8);
    ebx = 0; /* xor self */
    MEM8(0xF2A3DB) = 2;
    if (CMP_L(MEM32(edx + 4), ebx)) goto loc_003BAB00; /* jl: less (signed <) */

loc_003BAA55: ;
    if (CMP_NE(MEM8(0xF2A3D9), LO8(ebx))) goto loc_003BAB00; /* jne: not equal / not zero */

loc_003BAA61: ;
    if (CMP_B(MEM32(edx + 0x14), 8)) goto loc_003BAAF9; /* jb: below (unsigned <) */

loc_003BAA6B: ;
    SET_LO8(eax, MEM8(0xF2A463));
    if (CMP_A(LO8(eax), 0x40)) goto loc_003BAAF9; /* ja: above (unsigned >) */

loc_003BAA78: ;
    if (CMP_NE(MEM8(0xF2A45D), 1)) goto loc_003BAAF9; /* jne: not equal / not zero */

loc_003BAA81: ;
    SET_LO8(ecx, MEM8(0xF2A45C));
    if (CMP_EQ(LO8(ecx), 8)) goto loc_003BAA91; /* je: equal / zero */

loc_003BAA8C: ;
    if (CMP_NE(LO8(ecx), 0x12)) goto loc_003BAAF9; /* jne: not equal / not zero */

loc_003BAA91: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = MEM32(esi + 0xC);
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA38F(); /* call 0x003BA38F */

loc_003BAAA1: ;
    MEM8(esi + 5) = LO8(eax);
    MEM32(0xF2A3E4) = 0x3BA80E;
    MEM32(0xF2A3F4) = ebx;
    MEM32(0xF2A3F0) = ebx;
    MEM8(0xF2A404) = LO8(ebx);
    MEM8(0xF2A405) = 5;
    SET_LO16(eax, ZX8(MEM8(esi + 5)));
    MEM16(0xF2A406) = LO16(eax);
    MEM16(0xF2A408) = LO16(ebx);
    MEM16(0xF2A40A) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA2F1(); /* call 0x003BA2F1 */

loc_003BAAE5: ;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAAF6: ;
    POP32(esp, esi);
    goto loc_003BAB0A;

loc_003BAAF9: ;
    MEM32(edx + 4) = 0x80000600u;

loc_003BAB00: ;
    PUSH32(esp, MEM32(esp + 0xC));
    PUSH32(esp, edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA80E(); /* call 0x003BA80E */

loc_003BAB0A: ;
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BAB0E
 * Original: 0x003BAB0E - 0x003BAC46 (312 bytes, 89 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAB0E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BAB0E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, 0xF2A428);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BAB1E: ;
    ecx = MEM32(ebp + 8);
    ebx = 0; /* xor self */
    MEM8(0xF2A3DB) = 6;
    if (CMP_L(MEM32(ecx + 4), ebx)) { g_seh_ebp = ebp; sub_003BAC46(); return; } /* jl: less (signed <) */

loc_003BAB33: ;
    if (CMP_NE(MEM8(0xF2A3D9), LO8(ebx))) { g_seh_ebp = ebp; sub_003BAC46(); return; } /* jne: not equal / not zero */

loc_003BAB3F: ;
    esi = MEM32(ebp + 0xC);
    MEM32(esi + 0x18) = ebx;
    eax = 0xF2A464;

loc_003BAB4A: ;
    edx = ZX8(MEM8(eax));
    eax = eax + edx;
    if (CMP_AE(eax, 0xF2A4B4)) goto loc_003BAC35; /* jae: above or equal (unsigned >=) */

loc_003BAB5A: ;
    if (CMP_EQ(MEM8(eax), 0)) goto loc_003BAC35; /* je: equal / zero */

loc_003BAB63: ;
    if (CMP_NE(MEM8(eax + 1), 4)) { RECOMP_SLICE_POINT(); goto loc_003BAB4A; } /* jne: not equal / not zero */

loc_003BAB69: ;
    /* cmp MEM8(0xF2A468), 1 - flags set for next jcc */
    MEM32(0xF2A4B4) = eax;
    if (CMP_EQ(MEM8(0xF2A468), 1)) goto loc_003BAC00; /* je: equal / zero */

loc_003BAB7B: ;
    if (CMP_EQ(MEM8(0xF2A453), 0)) goto loc_003BAC00; /* je: equal / zero */

loc_003BAB84: ;
    MEM8(esi) = 4;
    MEM8(esi + 2) = 0x80;
    if (CMP_BE(MEM8(0xF2A468), 0)) goto loc_003BABF1; /* jbe: below or equal (unsigned <=) */

loc_003BAB94: ;
    eax = ZX8(MEM8(0xF2A453));
    if (CMP_BE(eax, ebx)) goto loc_003BABF1; /* jbe: below or equal (unsigned <=) */

loc_003BAB9F: ;
    ecx = 0xF2A3D8;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA166(); /* call 0x003BA166 */

loc_003BABA9: ;
    if (TEST_Z(eax, eax)) goto loc_003BABF1; /* je: equal / zero */

loc_003BABAD: ;
    MEM8(eax) = 5;
    SET_LO8(ecx, MEM8(esi + 4));
    SET_LO8(ecx, LO8(ecx) & 0x80);
    SET_LO8(edx, LO8(ebx));
    SET_LO8(edx, LO8(edx) + 1);
    SET_LO8(ecx, LO8(ecx) | LO8(edx));
    MEM8(eax + 4) = LO8(ecx);
    SET_LO8(ecx, MEM8(esi + 5));
    MEM8(eax + 5) = LO8(ecx);
    ecx = MEM32(esi + 8);
    MEM32(eax + 8) = ecx;
    ecx = MEM32(esi + 0xC);
    MEM32(eax + 0xC) = ecx;
    SET_LO8(ecx, MEM8(esi + 6));
    MEM8(eax + 6) = LO8(ecx);
    ecx = MEM32(esi + 0x18);
    MEM32(eax + 0x18) = ecx;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBF54(); /* call 0x003BBF54 */

loc_003BABE5: ;
    eax = ZX8(MEM8(0xF2A468));
    ebx++;
    if (CMP_B(ebx, eax)) { RECOMP_SLICE_POINT(); goto loc_003BAB94; } /* jb: below (unsigned <) */

loc_003BABF1: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BABFC: ;
    esi = eax;
    goto loc_003BAC03;

loc_003BAC00: ;
    MEM8(esi) = 3;

loc_003BAC03: ;
    eax = MEM32(0xF2A4B4);
    SET_LO8(eax, MEM8(eax + 2));
    MEM8(esi + 2) = LO8(eax);
    eax = MEM32(0xF2A4B4);
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(ebp + 0xD) = LO8(ecx);
    SET_LO8(ecx, MEM8(eax + 6));
    SET_LO8(eax, MEM8(eax + 7));
    MEM8(ebp + 0xE) = LO8(ecx);
    MEM8(ebp + 0xF) = LO8(eax);
    MEM8(ebp + 0xC) = 0x82;
    PUSH32(esp, MEM32(ebp + 0xC));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA9FF(); /* call 0x003BA9FF */

loc_003BAC33: ;
    g_seh_ebp = ebp; sub_003BAC4F(); return; /* tail jmp 0x003BAC4F */

loc_003BAC35: ;
    MEM8(0xF2A3DA) = 0;
    MEM32(ecx + 4) = 0x80000400u;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; sub_003BAC49(); return; /* tail jmp 0x003BAC49 */

}

/**
 * sub_003BAC46
 * Original: 0x003BAC46 - 0x003BAC49 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAC46(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAC46: ;
    PUSH32(esp, MEM32(ebp + 0xC));

    g_seh_ebp = ebp; sub_003BAC49(); return; /* restored dropped fall-through to sub_003BAC49 */
}

/**
 * sub_003BAC49
 * Original: 0x003BAC49 - 0x003BAC4F (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAC49(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAC49: ;
    PUSH32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA80E(); /* call 0x003BA80E */

    g_seh_ebp = ebp; sub_003BAC4F(); return; /* restored dropped fall-through to sub_003BAC4F */
}

/**
 * sub_003BAC4F
 * Original: 0x003BAC4F - 0x003BAC55 (6 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAC4F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAC4F: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BAC55
 * Original: 0x003BAC55 - 0x003BAC7D (40 bytes, 14 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAC55(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAC55: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    edi = MEM32(esi + 0xC);
    ebx = 0; /* xor self */
    edi = edi + 0x18;
    /* cmp MEM8(0xF2A3D9), LO8(ebx) - flags set for next jcc */
    MEM8(0xF2A3DB) = 1;
    if (CMP_EQ(MEM8(0xF2A3D9), LO8(ebx))) { g_seh_ebp = ebp; sub_003BAC7D(); return; } /* je: equal / zero */

loc_003BAC71: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA7A1(); /* call 0x003BA7A1 */

loc_003BAC78: ;
    g_seh_ebp = ebp; sub_003BAD51(); return; /* tail jmp 0x003BAD51 */

}

/**
 * sub_003BAC7D
 * Original: 0x003BAC7D - 0x003BAD51 (212 bytes, 42 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAC7D(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAC7D: ;
    MEM32(esi + 0x18) = ebx;
    PUSH32(esp, ebp);
    MEM8(0xF2A3DC) = 0x20;
    MEM8(0xF2A3DD) = 2;
    MEM32(0xF2A3E4) = ebx;
    MEM8(0xF2A3F1) = LO8(ebx);
    MEM8(0xF2A3F2) = LO8(ebx);
    MEM8(0xF2A3F3) = LO8(ebx);
    MEM16(0xF2A3F8) = 8;
    SET_LO8(eax, MEM8(esi + 4));
    ebp = 0xF2A3DC;
    PUSH32(esp, ebp);
    SET_LO8(eax, LO8(eax) >> 7);
    PUSH32(esp, edi);
    MEM8(0xF2A3FA) = LO8(eax);
    MEM8(0xF2A3F0) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BACCD: ;
    eax = MEM32(0xF2A3EC);
    MEM32(esi + 8) = eax;
    MEM8(0xF2A3DC) = 0x30;
    MEM8(0xF2A3DD) = 0x40;
    MEM32(0xF2A3E4) = 0x3BAA33;
    MEM32(0xF2A3E8) = esi;
    eax = MEM32(esi + 8);
    PUSH32(esp, 8);
    MEM32(0xF2A3EC) = eax;
    POP32(esp, eax);
    MEM32(0xF2A3F4) = 0xF2A45C;
    MEM32(0xF2A3F0) = eax;
    MEM8(0xF2A3F8) = 2;
    MEM8(0xF2A3F9) = LO8(ebx);
    MEM8(0xF2A3FA) = LO8(ebx);
    MEM8(0xF2A404) = 0x80;
    MEM8(0xF2A405) = 6;
    MEM16(0xF2A406) = 0x100;
    MEM16(0xF2A408) = LO16(ebx);
    MEM16(0xF2A40A) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA2F1(); /* call 0x003BA2F1 */

loc_003BAD49: ;
    PUSH32(esp, ebp);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAD50: ;
    POP32(esp, ebp);

    g_seh_ebp = ebp; sub_003BAD51(); return; /* restored dropped fall-through to sub_003BAD51 */
}

/**
 * sub_003BAD51
 * Original: 0x003BAD51 - 0x003BAD55 (4 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAD51(void)
{

loc_003BAD51: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BAD55
 * Original: 0x003BAD55 - 0x003BADA3 (78 bytes, 21 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAD55(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BAD55: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, 0xF2A428);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BAD63: ;
    eax = MEM32(ebp + 8);
    edx = 0; /* xor self */
    MEM8(0xF2A3DB) = 5;
    if (CMP_L(MEM32(eax + 4), edx)) goto loc_003BAD96; /* jl: less (signed <) */

loc_003BAD74: ;
    if (CMP_NE(MEM8(0xF2A3D9), LO8(edx))) goto loc_003BAD96; /* jne: not equal / not zero */

loc_003BAD7C: ;
    SET_LO16(ecx, MEM16(0xF2A466));
    if (CMP_BE(LO16(ecx), 0x50)) { g_seh_ebp = ebp; sub_003BADA3(); return; } /* jbe: below or equal (unsigned <=) */

loc_003BAD89: ;
    MEM8(0xF2A3DA) = LO8(edx);
    MEM32(eax + 4) = 0x80000400u;

loc_003BAD96: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA80E(); /* call 0x003BA80E */

loc_003BAD9F: ;
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BAD96
 * Original: 0x003BAD96 - 0x003BAD9F (9 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAD96(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAD96: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA80E(); /* call 0x003BA80E */

    g_seh_ebp = ebp; sub_003BAD9F(); return; /* restored dropped fall-through to sub_003BAD9F */
}

/**
 * sub_003BAD9F
 * Original: 0x003BAD9F - 0x003BADA3 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAD9F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAD9F: ;
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BADA3
 * Original: 0x003BADA3 - 0x003BAE0E (107 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BADA3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BADA3: ;
    ecx = ZX16(LO16(ecx));
    if (CMP_EQ(ecx, MEM32(eax + 0x14))) goto loc_003BADB4; /* je: equal / zero */

loc_003BADAB: ;
    MEM32(eax + 4) = 0x80000000u;
    g_seh_ebp = ebp; sub_003BAD96(); return; /* tail jmp 0x003BAD96 */

loc_003BADB4: ;
    SET_LO16(eax, ZX8(MEM8(0xF2A469)));
    MEM32(0xF2A3E4) = 0x3BAB0E;
    MEM32(0xF2A3F4) = edx;
    MEM32(0xF2A3F0) = edx;
    MEM8(0xF2A404) = LO8(edx);
    MEM8(0xF2A405) = 9;
    MEM16(0xF2A406) = LO16(eax);
    MEM16(0xF2A408) = LO16(edx);
    MEM16(0xF2A40A) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA2F1(); /* call 0x003BA2F1 */

loc_003BADF8: ;
    eax = MEM32(ebp + 0xC);
    eax = MEM32(eax + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAE0C: ;
    g_seh_ebp = ebp; sub_003BAD9F(); return; /* tail jmp 0x003BAD9F */

}

/**
 * sub_003BAE0E
 * Original: 0x003BAE0E - 0x003BAE33 (37 bytes, 14 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAE0E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BAE0E: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* cmp MEM8(0xF2A3D9), LO8(ebx) - flags set for next jcc */
    PUSH32(esp, esi);
    esi = edx;
    MEM8(0xF2A3DB) = 4;
    if (CMP_EQ(MEM8(0xF2A3D9), LO8(ebx))) { g_seh_ebp = ebp; sub_003BAE33(); return; } /* je: equal / zero */

loc_003BAE27: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA7A1(); /* call 0x003BA7A1 */

loc_003BAE2E: ;
    g_seh_ebp = ebp; sub_003BAF55(); return; /* tail jmp 0x003BAF55 */

}

/**
 * sub_003BAE33
 * Original: 0x003BAE33 - 0x003BAF55 (290 bytes, 65 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAE33(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAE33: ;
    SET_LO8(eax, MEM8(0xF2A460));
    if (CMP_EQ(LO8(eax), LO8(ebx))) goto loc_003BAE70; /* je: equal / zero */

loc_003BAE3C: ;
    /* cmp LO8(eax), 9 - flags set for next jcc */
    SET_LO8(eax, (CMP_NE(LO8(eax), 9)) ? 1 : 0); /* setne */
    SET_LO8(eax, LO8(eax) + 1);
    MEM8(esi) = LO8(eax);
    SET_LO8(eax, MEM8(0xF2A460));
    MEM8(ebp + -3) = LO8(eax);
    SET_LO8(eax, MEM8(0xF2A461));
    MEM8(ebp + -2) = LO8(eax);
    SET_LO8(eax, MEM8(0xF2A462));
    MEM8(ebp + -1) = LO8(eax);
    MEM8(ebp + -4) = 0x81;
    PUSH32(esp, MEM32(ebp + -4));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA9FF(); /* call 0x003BA9FF */

loc_003BAE6B: ;
    g_seh_ebp = ebp; sub_003BAF55(); return; /* tail jmp 0x003BAF55 */

loc_003BAE70: ;
    SET_LO16(eax, ZX8(MEM8(0xF2A463)));
    MEM16(0xF2A3F8) = LO16(eax);
    MEM8(0xF2A3DC) = 0x20;
    MEM8(0xF2A3DD) = 2;
    MEM32(0xF2A3E4) = ebx;
    MEM8(0xF2A3F1) = LO8(ebx);
    MEM8(0xF2A3F2) = LO8(ebx);
    MEM8(0xF2A3F3) = LO8(ebx);
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) >> 7);
    MEM8(0xF2A3FA) = LO8(eax);
    SET_LO8(eax, MEM8(esi + 5));
    PUSH32(esp, edi);
    MEM8(0xF2A3F0) = LO8(eax);
    eax = MEM32(esi + 0xC);
    edi = 0xF2A3DC;
    PUSH32(esp, edi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAECA: ;
    eax = MEM32(0xF2A3EC);
    MEM32(esi + 8) = eax;
    MEM8(0xF2A3DC) = 0x30;
    MEM8(0xF2A3DD) = 0x40;
    MEM32(0xF2A3E4) = 0x3BAD55;
    MEM32(0xF2A3E8) = esi;
    eax = MEM32(esi + 8);
    PUSH32(esp, 0x50);
    MEM32(0xF2A3EC) = eax;
    POP32(esp, eax);
    MEM32(0xF2A3F4) = 0xF2A464;
    MEM32(0xF2A3F0) = eax;
    MEM8(0xF2A3F8) = 2;
    MEM8(0xF2A3F9) = 1;
    MEM8(0xF2A3FA) = LO8(ebx);
    MEM8(0xF2A404) = 0x80;
    MEM8(0xF2A405) = 6;
    MEM16(0xF2A406) = 0x200;
    MEM16(0xF2A408) = LO16(ebx);
    MEM16(0xF2A40A) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA2F1(); /* call 0x003BA2F1 */

loc_003BAF47: ;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, edi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BAF54: ;
    POP32(esp, edi);

    g_seh_ebp = ebp; sub_003BAF55(); return; /* restored dropped fall-through to sub_003BAF55 */
}

/**
 * sub_003BAF55
 * Original: 0x003BAF55 - 0x003BAFAD (88 bytes, 29 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAF55(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAF55: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

    eax--;
    if ((eax == 0)) goto loc_003BAF8D; /* je: equal / zero */

loc_003BAF68: ;
    eax--;
    if ((eax == 0)) goto loc_003BAF80; /* je: equal / zero */

loc_003BAF6B: ;
    eax--;
    if ((eax != 0)) goto loc_003BAFAA; /* jne: not equal / not zero */

loc_003BAF6E: ;
    edx = MEM32(0xF2A458);
    ecx = 0xF2A3DC;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BAE0E(); /* call 0x003BAE0E */

loc_003BAF7E: ;
    goto loc_003BAFAA;

loc_003BAF80: ;
    ecx = MEM32(0xF2A458);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BAC55(); /* call 0x003BAC55 */

loc_003BAF8B: ;
    goto loc_003BAFAA;

loc_003BAF8D: ;
    eax = MEM32(0xF2A458);
    eax = MEM32(eax + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEA62(); /* call 0x003BEA62 */

loc_003BAFA3: ;
    goto loc_003BAFAA;

loc_003BAFA5: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA440(); /* call 0x003BA440 */

loc_003BAFAA: ;
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BAF59
 * Original: 0x003BAF59 - 0x003BAFAD (84 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAF59(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BAF59: ;
    eax = ZX8(MEM8(0xF2A450));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003BAFA5; /* je: equal / zero */

loc_003BAF65: ;
    eax--;
    if ((eax == 0)) goto loc_003BAF8D; /* je: equal / zero */

loc_003BAF68: ;
    eax--;
    if ((eax == 0)) goto loc_003BAF80; /* je: equal / zero */

loc_003BAF6B: ;
    eax--;
    if ((eax != 0)) goto loc_003BAFAA; /* jne: not equal / not zero */

loc_003BAF6E: ;
    edx = MEM32(0xF2A458);
    ecx = 0xF2A3DC;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BAE0E(); /* call 0x003BAE0E */

loc_003BAF7E: ;
    goto loc_003BAFAA;

loc_003BAF80: ;
    ecx = MEM32(0xF2A458);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BAC55(); /* call 0x003BAC55 */

loc_003BAF8B: ;
    goto loc_003BAFAA;

loc_003BAF8D: ;
    eax = MEM32(0xF2A458);
    eax = MEM32(eax + 0xC);
    PUSH32(esp, 0xF2A3DC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEA62(); /* call 0x003BEA62 */

loc_003BAFA3: ;
    goto loc_003BAFAA;

loc_003BAFA5: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA440(); /* call 0x003BA440 */

loc_003BAFAA: ;
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BAFAD
 * Original: 0x003BAFAD - 0x003BB007 (90 bytes, 35 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BAFAD(void)
{

loc_003BAFAD: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, edi);
    edx = ecx;
    MEM32(edx + 0x98) = eax;
    eax = MEM32(esp + 0xC);
    MEM32(edx + 0x9C) = eax;
    eax = 0; /* xor self */
    MEM8(edx + 0xA0) = 0;
    MEM8(edx + 0xA1) = 0;
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM16(edi) = LO16(eax); edi += 2; /* stosw */
    eax = 0; /* xor self */
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = edx + 0x32;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM16(edi) = LO16(eax); edi += 2; /* stosw */
    eax = 0; /* xor self */
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = edx + 0x64;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM16(edi) = LO16(eax); edi += 2; /* stosw */
    eax = 0; /* xor self */
    edi = edx + 0xA4;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    eax = edx;
    POP32(esp, edi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB007
 * Original: 0x003BB007 - 0x003BB01B (20 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB007(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB007: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(eax + 8);
    if (TEST_Z(ecx, ecx)) goto loc_003BB018; /* je: equal / zero */

loc_003BB012: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(eax + 0xC));
    PUSH32(esp, eax);
    { uint32_t _icall_t = ecx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB018: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB01B
 * Original: 0x003BB01B - 0x003BB064 (73 bytes, 26 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB01B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB01B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x10;
    eax = ZX8(MEM8(ebp + 0xC));
    MEM32(ebp + -16) = MEM32(ebp + -16) & 0;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    MEM32(ebp + -12) = 9;
    MEM32(ebp + -4) = 0xD;
    ecx = MEM32(ebp + eax * 4 + -16);
    eax = ZX16(MEM16(ebp + 8));
    eax = eax + ecx;
    eax = (uint32_t)((int32_t)eax * (int32_t)0x38);
    PUSH32(esp, esi);
    PUSH32(esp, 6);
    edx = 0; /* xor self */
    POP32(esp, esi);
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)esi);
      edx = (uint32_t)(_dividend % (uint32_t)esi); }
    /* test ecx, ecx - flags set for next jcc */
    POP32(esp, esi);
    if (TEST_NZ(ecx, ecx)) goto loc_003BB057; /* jne: not equal / not zero */

loc_003BB055: ;
    eax = 0; /* xor self */

loc_003BB057: ;
    if (CMP_EQ(MEM8(ebp + 0x10), 0)) goto loc_003BB060; /* je: equal / zero */

loc_003BB05D: ;
    eax = eax << 3;

loc_003BB060: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BB064
 * Original: 0x003BB064 - 0x003BB095 (49 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB064(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BB064: ;
    PUSH32(esp, esi);
    eax = 0x3B8394;
    esi = 0x3B83AC;
    /* cmp eax, esi - flags set for next jcc */
    ecx = eax;
    if (CMP_AE(eax, esi)) goto loc_003BB08F; /* jae: above or equal (unsigned >=) */

loc_003BB075: ;
    edx = MEM32(esp + 8);

loc_003BB079: ;
    eax = MEM32(ecx);
    if (TEST_Z(eax, eax)) goto loc_003BB088; /* je: equal / zero */

loc_003BB07F: ;
    if (CMP_NE(HI8(edx), MEM8(eax + 1))) goto loc_003BB088; /* jne: not equal / not zero */

loc_003BB084: ;
    if (CMP_EQ(LO8(edx), MEM8(eax))) { g_seh_ebp = ebp; sub_003BB095(); return; } /* je: equal / zero */

loc_003BB088: ;
    ecx = ecx + 4;
    if (CMP_B(ecx, esi)) { RECOMP_SLICE_POINT(); goto loc_003BB079; } /* jb: below (unsigned <) */

loc_003BB08F: ;
    eax = 0; /* xor self */
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB091
 * Original: 0x003BB091 - 0x003BB095 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB091(void)
{

loc_003BB091: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB095
 * Original: 0x003BB095 - 0x003BB099 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB095(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB095: ;
    eax = MEM32(ecx);
    g_seh_ebp = ebp; sub_003BB091(); return; /* tail jmp 0x003BB091 */

}

/**
 * sub_003BB099
 * Original: 0x003BB099 - 0x003BB0B9 (32 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB099(void)
{
    uint32_t ebp;

loc_003BB099: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    SET_LO8(eax, MEM8(ebp + 0xB));
    MEM8(ebp + -4) = LO8(eax);
    SET_LO8(eax, MEM8(ebp + 0xA));
    MEM8(ebp + -3) = LO8(eax);
    eax = MEM32(ebp + 8);
    MEM8(ebp + -2) = HI8(eax);
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + -4);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB0B9
 * Original: 0x003BB0B9 - 0x003BB0F0 (55 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB0B9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB0B9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    esi = MEM32(edi + 0x18);
    ebx = 0x103;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB0D0: ;
    /* test MEM8(esi + 0xC), 6 - flags set for next jcc */
    ecx = MEM32(ebp + 0xC);
    MEM8(ebp + 0xB) = LO8(eax);
    if (TEST_Z(MEM8(esi + 0xC), 6)) { g_seh_ebp = ebp; sub_003BB0F0(); return; } /* je: equal / zero */

loc_003BB0DC: ;
    eax = 0xC000009Du;
    SET_LO8(edx, 0); /* xor self */
    ebx = eax;
    MEM32(ecx + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB0EE: ;
    g_seh_ebp = ebp; sub_003BB101(); return; /* tail jmp 0x003BB101 */

}

/**
 * sub_003BB0F0
 * Original: 0x003BB0F0 - 0x003BB101 (17 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB0F0(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB0F0: ;
    eax = MEM32(ecx + 0x5C);
    MEM8(eax + 3) = MEM8(eax + 3) | 1;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C162C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003BB101(); return; /* restored dropped fall-through to sub_003BB101 */
}

/**
 * sub_003BB101
 * Original: 0x003BB101 - 0x003BB113 (18 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB101(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB101: ;
    SET_LO8(ecx, MEM8(ebp + 0xB));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB10A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB113
 * Original: 0x003BB113 - 0x003BB136 (35 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB113(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB113: ;
    eax = MEM32(esp + 8);
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    ecx = MEM32(esi + 0x10);
    MEM32(ecx + 0x10) = eax;
    ecx = 0xC0000000u;
    eax = eax & ecx;
    /* cmp eax, ecx - flags set for next jcc */
    _rccf = (CMP_NE(eax, ecx));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    eax = MEM32(esi + 0x10);
    if (_rccf) { g_seh_ebp = ebp; sub_003BB136(); return; } /* jne: not equal / not zero */

loc_003BB130: ;
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    g_seh_ebp = ebp; sub_003BB13C(); return; /* tail jmp 0x003BB13C */

}

/**
 * sub_003BB136
 * Original: 0x003BB136 - 0x003BB13C (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB136(void)
{

loc_003BB136: ;
    ecx = MEM32(esi + 0x2C);
    MEM32(eax + 0x14) = ecx;

    sub_003BB13C(); return; /* restored dropped fall-through to sub_003BB13C */
}

/**
 * sub_003BB13C
 * Original: 0x003BB13C - 0x003BB153 (23 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB13C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB13C: ;
    ecx = MEM32(esi + 0x10);
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB147: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB14F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB153
 * Original: 0x003BB153 - 0x003BB16F (28 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB153(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB153: ;
    eax = MEM32(0xF273CC);
    if (CMP_EQ(eax, 0xF273CC)) goto loc_003BB16E; /* je: equal / zero */

loc_003BB15F: ;
    eax = MEM32(eax + 8);
    eax = MEM32(eax + 0x14);
    eax = MEM32(eax + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(eax + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB16E: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BB16F
 * Original: 0x003BB16F - 0x003BB196 (39 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB16F(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BB16F: ;
    eax = ecx;
    edx = 0; /* xor self */
    if (CMP_BE(MEM32(eax + 4), edx)) goto loc_003BB195; /* jbe: below or equal (unsigned <=) */

loc_003BB178: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003BB17A: ;
    edi = MEM32(eax);
    edi = edi + edx;
    PUSH32(esp, 8);
    POP32(esp, ecx);
    esi = 0x3C148C;
    edx = edx + 0x1000;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    if (CMP_B(edx, MEM32(eax + 4))) { RECOMP_SLICE_POINT(); goto loc_003BB17A; } /* jb: below (unsigned <) */

loc_003BB193: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BB195: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BB196
 * Original: 0x003BB196 - 0x003BB1AB (21 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB196(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB196: ;
    eax = MEM32(esp + 4);
    if (CMP_BE(eax, 1)) { g_seh_ebp = ebp; sub_003BB1AB(); return; } /* jbe: below or equal (unsigned <=) */

loc_003BB19F: ;
    ecx = eax + -1;
    if (TEST_NZ(eax, ecx)) { g_seh_ebp = ebp; sub_003BB1AB(); return; } /* jne: not equal / not zero */

loc_003BB1A6: ;
    eax = 0; /* xor self */
    eax++;
    g_seh_ebp = ebp; sub_003BB1AD(); return; /* tail jmp 0x003BB1AD */

}

/**
 * sub_003BB1AB
 * Original: 0x003BB1AB - 0x003BB1AD (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB1AB(void)
{

loc_003BB1AB: ;
    eax = 0; /* xor self */

    sub_003BB1AD(); return; /* restored dropped fall-through to sub_003BB1AD */
}

/**
 * sub_003BB1AD
 * Original: 0x003BB1AD - 0x003BB1B0 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB1AD(void)
{

loc_003BB1AD: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB1B0
 * Original: 0x003BB1B0 - 0x003BB1C6 (22 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB1B0(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BB1B0: ;
    ecx = 0; /* xor self */
    SET_LO8(eax, 0); /* xor self */
    ecx++;

loc_003BB1B5: ;
    if (TEST_NZ(MEM32(esp + 4), ecx)) goto loc_003BB1C3; /* jne: not equal / not zero */

loc_003BB1BB: ;
    SET_LO8(eax, LO8(eax) + 1);
    ecx = ecx << 1;
    if (CMP_B(LO8(eax), 0x20)) { RECOMP_SLICE_POINT(); goto loc_003BB1B5; } /* jb: below (unsigned <) */

loc_003BB1C3: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BB1C6
 * Original: 0x003BB1C6 - 0x003BB203 (61 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB1C6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB1C6: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    edx = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    ecx = MEM32(ebx + 0x10);
    eax = MEM32(ecx + 0x5C);
    PUSH32(esp, esi);
    MEM32(ebp + -12) = eax;
    eax = 0xC0000000u;
    esi = edx;
    PUSH32(esp, edi);
    edi = MEM32(ebx + 0x28);
    esi = esi & eax;
    /* cmp esi, eax - flags set for next jcc */
    MEM32(ebp + -8) = edi;
    MEM32(ebp + -4) = ecx;
    if (CMP_NE(esi, eax)) { g_seh_ebp = ebp; sub_003BB203(); return; } /* jne: not equal / not zero */

loc_003BB1F4: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = edx;
    g_seh_ebp = ebp; sub_003BB378(); return; /* tail jmp 0x003BB378 */

}

/**
 * sub_003BB203
 * Original: 0x003BB203 - 0x003BB378 (373 bytes, 99 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB203(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB203: ;
    SET_LO16(eax, MEM16(edi + 6));
    PUSH32(esp, MEM32(edi));
    MEM8(ebp + 0xA) = HI8(eax);
    MEM8(ebp + 0xB) = LO8(eax);
    SET_LO16(eax, MEM16(edi + 4));
    ecx = ZX16(MEM16(ebp + 0xA));
    MEM8(ebp + 0xE) = HI8(eax);
    MEM8(ebp + 0xF) = LO8(eax);
    esi = ZX16(MEM16(ebp + 0xE));
    esi = (uint32_t)((int32_t)esi * (int32_t)ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB099(); /* call 0x003BB099 */

loc_003BB229: ;
    ecx = ZX16(MEM16(ebp + 0xA));
    eax++;
    MEM32(ebp + 0xC) = eax;
    { uint64_t _r = (uint64_t)eax * (uint64_t)ecx;
      eax = (uint32_t)_r; edx = (uint32_t)(_r >> 32); }
    /* test esi, esi - flags set for next jcc */
    MEM32(ebp + -20) = eax;
    MEM32(ebp + -16) = edx;
    if (TEST_NZ(esi, esi)) goto loc_003BB242; /* jne: not equal / not zero */

loc_003BB23D: ;
    esi = 0x2000;

loc_003BB242: ;
    PUSH32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB196(); /* call 0x003BB196 */

loc_003BB248: ;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* je: equal / zero */

loc_003BB250: ;
    edx = ZX16(MEM16(ebp + 0xA));
    if (CMP_A(edx, 0x1000)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* ja: above (unsigned >) */

loc_003BB260: ;
    if (CMP_A(esi, 0x4000)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* ja: above (unsigned >) */

loc_003BB26C: ;
    if (TEST_NZ(LO16(esi), 0xFFF)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* jne: not equal / not zero */

loc_003BB277: ;
    ecx = 0; /* xor self */
    if (CMP_EQ(MEM32(ebp + 0xC), ecx)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* je: equal / zero */

loc_003BB282: ;
    eax = MEM32(ebp + -16);
    if (CMP_B(eax, ecx)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* jb: below (unsigned <) */

loc_003BB28D: ;
    if (CMP_A(eax, ecx)) goto loc_003BB298; /* ja: above (unsigned >) */

loc_003BB28F: ;
    if (CMP_B(MEM32(ebp + -20), esi)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* jb: below (unsigned <) */

loc_003BB298: ;
    if (CMP_A(eax, 1)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* ja: above (unsigned >) */

loc_003BB2A1: ;
    if (CMP_B(eax, 1)) goto loc_003BB2AD; /* jb: below (unsigned <) */

loc_003BB2A3: ;
    if (CMP_A(MEM32(ebp + -20), 0)) { g_seh_ebp = ebp; sub_003BB399(); return; } /* ja: above (unsigned >) */

loc_003BB2AD: ;
    ecx = MEM32(ebp + -20);
    PUSH32(esp, edx);
    MEM32(ebx + 0x160) = ecx;
    MEM32(ebx + 0x164) = eax;
    MEM32(ebx + 0x168) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB1B0(); /* call 0x003BB1B0 */

loc_003BB2C8: ;
    eax = ZX8(LO8(eax));
    MEM32(ebx + 0x158) = eax;
    eax = 0; /* xor self */
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + -16));
    MEM32(ebx + 0x148) = 0xC;
    PUSH32(esp, MEM32(ebp + -20));
    edi = ebx + 0x140;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00337630(); /* call 0x00337630 */

loc_003BB2F0: ;
    MEM32(edi) = eax;
    eax = MEM32(ebp + -12);
    esi = esi >> 0xC;
    MEM32(edi + 4) = edx;
    MEM32(ebx + 0x14C) = 1;
    MEM32(ebx + 0x150) = esi;
    MEM32(ebx + 0x154) = 0x1000;
    eax = MEM32(eax + 0x10);
    if (CMP_EQ(eax, 0x70000)) goto loc_003BB357; /* je: equal / zero */

loc_003BB31F: ;
    if (CMP_NE(eax, 0x74004)) goto loc_003BB375; /* jne: not equal / not zero */

loc_003BB326: ;
    eax = MEM32(ebp + -4);
    edx = MEM32(eax + 0x30);
    eax = 0; /* xor self */
    PUSH32(esp, 8);
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebx + 0x160);
    MEM32(edx + 8) = eax;
    eax = MEM32(ebx + 0x164);
    MEM32(edx + 0xC) = eax;
    MEM8(edx + 0x1A) = 1;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x14) = 0x20;
    goto loc_003BB36E;

loc_003BB357: ;
    eax = MEM32(ebp + -4);
    PUSH32(esp, 6);
    esi = edi;
    edi = MEM32(eax + 0x30);
    POP32(esp, ecx);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x14) = 0x18;

loc_003BB36E: ;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = MEM32(eax + 0x10) & 0;

loc_003BB375: ;
    edi = MEM32(ebp + -8);

    g_seh_ebp = ebp; sub_003BB378(); return; /* restored dropped fall-through to sub_003BB378 */
}

/**
 * sub_003BB378
 * Original: 0x003BB378 - 0x003BB3AC (52 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB378(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB378: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1638); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB37F: ;
    ecx = MEM32(ebx + 0x10);
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB38A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebx));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB392: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB399
 * Original: 0x003BB399 - 0x003BB3AC (19 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB399(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB399: ;
    eax = MEM32(ebp + -4);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = 0xC000014Fu;
    g_seh_ebp = ebp; sub_003BB378(); return; /* tail jmp 0x003BB378 */

}

/**
 * sub_003BB3AC
 * Original: 0x003BB3AC - 0x003BB42D (129 bytes, 48 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB3AC(void)
{
    uint32_t ebp;

loc_003BB3AC: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    eax = MEM32(edx + 0x5C);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    PUSH32(esp, edi);
    edi = MEM32(eax + 8);
    MEM8(esi + 0x4F) = 0x2F;
    ecx = MEM32(esi + 0x158);
    eax = MEM32(edi);
    edx = MEM32(edi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003376A0(); /* call 0x003376A0 */

loc_003BB3CF: ;
    ecx = MEM32(esi + 0x158);
    ebx = MEM32(edi + 8);
    edx = eax;
    eax = 0; /* xor self */
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = eax;
    MEM32(esi + 0x30) = 0x3BB113;
    ebx = ebx >> LO8(ecx);
    SET_LO16(ecx, MEM16(edi + 0xA));
    SET_LO16(ecx, (uint32_t)((int32_t)LO16(ecx) * (int32_t)0x64));
    MEM16(esi + 0x34) = LO16(ecx);
    ecx = esi + 0x4F;
    MEM8(esi + 0x37) = LO8(eax);
    MEM8(esi + 0x36) = 2;
    edi = ecx;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    PUSH32(esp, edx);
    MEM8(ecx) = 0x2F;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB099(); /* call 0x003BB099 */

loc_003BB410: ;
    MEM32(esi + 0x51) = eax;
    MEM8(ebp + -4) = HI8(ebx);
    MEM8(ebp + -3) = LO8(ebx);
    SET_LO16(eax, MEM16(ebp + -4));
    ecx = esi;
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC906(); /* call 0x003BC906 */

loc_003BB428: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BB42D
 * Original: 0x003BB42D - 0x003BB4FB (206 bytes, 72 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB42D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB42D: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    eax = MEM32(ebp + 8);
    ecx = MEM32(eax + 0x2C);
    PUSH32(esp, edi);
    edi = MEM32(eax + 0x28);
    ecx = ecx + edi;
    /* cmp edi, ecx - flags set for next jcc */
    MEM32(ebp + -8) = ecx;
    if (CMP_AE(edi, ecx)) goto loc_003BB4ED; /* jae: above or equal (unsigned >=) */

loc_003BB44A: ;
    edx = edi;
    edx = edx - 0x3C148C;
    PUSH32(esp, ebx);
    MEM32(ebp + -12) = edx;
    PUSH32(esp, esi);

loc_003BB457: ;
    eax = 0; /* xor self */
    if (CMP_NE(MEM32(edi), 0x46313539)) goto loc_003BB4D1; /* jne: not equal / not zero */

loc_003BB461: ;
    eax++;
    /* cmp eax, 8 - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (CMP_EQ(eax, 8)) goto loc_003BB47C; /* je: equal / zero */

loc_003BB46A: ;
    esi = MEM32(edx + eax * 4 + 0x3C148C);
    if (CMP_EQ(esi, MEM32(eax * 4 + 0x3C148C))) { RECOMP_SLICE_POINT(); goto loc_003BB461; } /* je: equal / zero */

loc_003BB47A: ;
    goto loc_003BB4D1;

loc_003BB47C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1580); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB483: ;
    esi = esi | 0xFFFFFFFFu;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    ebx = eax;
    if (CMP_L(MEM32(ebp + 0xC), 0)) goto loc_003BB495; /* jl: less (signed <) */

loc_003BB48E: ;
    MEM32(ebp + 0xC) = 0xC000003Eu;

loc_003BB495: ;
    eax = ebx;
    eax = eax & 6;
    if (CMP_NE(LO8(eax), 2)) goto loc_003BB4B0; /* jne: not equal / not zero */

loc_003BB49E: ;
    esi = ebx;
    esi = esi & 0xFFFFFFFDu;
    esi = esi | 4;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x20);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C157C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB4B0: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;
    eax = MEM32(ebp + -4);
    MEM32(edi + eax * 4) = 0x4C494146;
    if ((MEM32(ebp + -4) != 0)) { RECOMP_SLICE_POINT(); goto loc_003BB4B0; } /* jne: not equal / not zero */

loc_003BB4BF: ;
    if (CMP_EQ(esi, 0xFFFFFFFFu)) goto loc_003BB4CE; /* je: equal / zero */

loc_003BB4C4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0x20);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C157C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB4CE: ;
    ecx = MEM32(ebp + -8);

loc_003BB4D1: ;
    edx = MEM32(ebp + -12);
    eax = 0x1000;
    edi = edi + eax;
    edx = edx + eax;
    /* cmp edi, ecx - flags set for next jcc */
    MEM32(ebp + -12) = edx;
    if (CMP_B(edi, ecx)) { RECOMP_SLICE_POINT(); goto loc_003BB457; } /* jb: below (unsigned <) */

loc_003BB4E8: ;
    eax = MEM32(ebp + 8);
    POP32(esp, esi);
    POP32(esp, ebx);

loc_003BB4ED: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB113(); /* call 0x003BB113 */

loc_003BB4F6: ;
    POP32(esp, edi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB4FB
 * Original: 0x003BB4FB - 0x003BB6E1 (486 bytes, 133 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB4FB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB4FB: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    ebx = MEM32(esi + 0xC);
    ecx = MEM32(esi + 0x10);
    ebx = ebx & 0xF0000000u;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = MEM32(ecx + 0x5C);
    MEM32(ebp + 8) = ecx;
    if (CMP_L(MEM32(ebp + 0xC), 0)) goto loc_003BB5D1; /* jl: less (signed <) */

loc_003BB520: ;
    ebx = ebx + 0x10000000;
    if (CMP_NE(ebx, 0x20000000)) goto loc_003BB539; /* jne: not equal / not zero */

loc_003BB52E: ;
    if (TEST_NZ(MEM8(esi + 0xF), 2)) goto loc_003BB54C; /* jne: not equal / not zero */

loc_003BB534: ;
    ebx = 0x40000000;

loc_003BB539: ;
    if (CMP_NE(ebx, 0x40000000)) goto loc_003BB54C; /* jne: not equal / not zero */

loc_003BB541: ;
    if (TEST_NZ(MEM8(esi + 0xF), 4)) goto loc_003BB54C; /* jne: not equal / not zero */

loc_003BB547: ;
    ebx = 0x60000000;

loc_003BB54C: ;
    eax = MEM32(esi + 0xC);
    edx = 0xFFFFFFF;
    eax = eax & edx;
    eax = eax | ebx;
    /* cmp ebx, 0x20000000 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (CMP_EQ(ebx, 0x20000000)) goto loc_003BB68A; /* je: equal / zero */

loc_003BB567: ;
    if (CMP_EQ(ebx, 0x30000000)) goto loc_003BB65E; /* je: equal / zero */

loc_003BB573: ;
    if (CMP_EQ(ebx, 0x40000000)) goto loc_003BB63E; /* je: equal / zero */

loc_003BB57F: ;
    if (CMP_EQ(ebx, 0x50000000)) goto loc_003BB60C; /* je: equal / zero */

loc_003BB58B: ;
    if (CMP_NE(ebx, 0x60000000)) goto loc_003BB6DA; /* jne: not equal / not zero */

loc_003BB597: ;
    eax = eax & edx;
    MEM32(esi + 0xC) = eax;
    eax = MEM32(0xF273CC);
    edx = MEM32(eax);
    eax = MEM32(eax + 4);
    MEM32(eax) = edx;
    MEM32(edx + 4) = eax;
    eax = MEM32(edi + 4);
    MEM32(ecx + 0x14) = eax;
    eax = MEM32(ebp + 0xC);
    SET_LO8(edx, 0); /* xor self */
    MEM32(ecx + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB5BF: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB153(); /* call 0x003BB153 */

loc_003BB5C4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB5CC: ;
    goto loc_003BB6DA;

loc_003BB5D1: ;
    if (CMP_EQ(ebx, 0x20000000)) goto loc_003BB5E5; /* je: equal / zero */

loc_003BB5D9: ;
    if (CMP_NE(ebx, 0x40000000)) { RECOMP_SLICE_POINT(); goto loc_003BB547; } /* jne: not equal / not zero */

loc_003BB5E5: ;
    if (CMP_NE(MEM32(ebp + 0xC), 0xC000003Eu)) { RECOMP_SLICE_POINT(); goto loc_003BB547; } /* jne: not equal / not zero */

loc_003BB5F2: ;
    ecx = esi + 0x28;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB16F(); /* call 0x003BB16F */

loc_003BB5FA: ;
    MEM32(ebp + 0xC) = MEM32(ebp + 0xC) & 0;
    ecx = MEM32(ebp + 8);
    ebx = ebx + 0x10000000;
    { RECOMP_SLICE_POINT(); goto loc_003BB54C; }

loc_003BB60C: ;
    MEM32(esi + 0x38) = MEM32(esi + 0x38) & 0;
    MEM8(esi + 0x37) = 6;
    eax = MEM32(esi + 0x1C);
    MEM32(esi + 0x3C) = eax;
    MEM8(esi + 0x4F) = 0x2A;
    eax = MEM32(edi + 8);
    eax = eax - MEM32(esi + 0x1C);
    eax = eax + MEM32(edi + 4);
    MEM32(esi + 0x28) = eax;
    eax = MEM32(esi + 0x168);
    MEM32(esi + 0x2C) = eax;
    eax = MEM32(edi + 0xC);
    eax = eax - MEM32(esi + 0x1C);

loc_003BB639: ;
    eax = eax + MEM32(edi + 4);
    goto loc_003BB6AB;

loc_003BB63E: ;
    MEM32(esi + 0x28) = 0xF273D4;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x1C);
    MEM8(esi + 0x37) = 1;
    MEM32(esi + 0x2C) = eax;
    MEM8(esi + 0x4F) = 0x28;
    eax = MEM32(edi + 0xC);
    { RECOMP_SLICE_POINT(); goto loc_003BB639; }

loc_003BB65E: ;
    eax = MEM32(esi + 0x2C);
    MEM32(esi + 0x38) = eax;
    MEM8(esi + 0x37) = 6;
    eax = esi + 0x168;
    ecx = MEM32(eax);
    MEM32(esi + 0x3C) = ecx;
    ecx = MEM32(edi + 8);
    MEM32(esi + 0x28) = ecx;
    eax = MEM32(eax);
    MEM32(esi + 0x2C) = eax;
    MEM8(esi + 0x4F) = 0x2A;
    eax = MEM32(edi + 0xC);
    eax = eax - MEM32(esi + 0x38);
    goto loc_003BB6AB;

loc_003BB68A: ;
    MEM32(esi + 0x28) = 0xF273D4;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x18);
    MEM8(esi + 0x37) = 1;
    MEM32(esi + 0x2C) = eax;
    MEM8(esi + 0x4F) = 0x28;
    eax = MEM32(edi + 0xC);
    eax = eax - MEM32(esi + 0x2C);

loc_003BB6AB: ;
    edi = esi + 0x158;
    ecx = MEM32(edi);
    eax = eax >> LO8(ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB099(); /* call 0x003BB099 */

loc_003BB6BB: ;
    MEM32(esi + 0x51) = eax;
    ecx = MEM32(edi);
    eax = MEM32(esi + 0x2C);
    eax = eax >> LO8(ecx);
    ecx = esi;
    MEM8(ebp + 0xE) = HI8(eax);
    MEM8(ebp + 0xF) = LO8(eax);
    SET_LO16(eax, MEM16(ebp + 0xE));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC906(); /* call 0x003BC906 */

loc_003BB6DA: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB6E1
 * Original: 0x003BB6E1 - 0x003BB70A (41 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB6E1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB6E1: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    ebx = MEM32(esi + 0x10);
    edx = MEM32(ebx + 0x5C);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0xC);
    edi = edi & 0xF0000000u;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    MEM32(ebp + 8) = edx;
    if (CMP_L(MEM32(ebp + 0xC), 0)) { g_seh_ebp = ebp; sub_003BB70A(); return; } /* jl: less (signed <) */

loc_003BB702: ;
    edi = edi + 0x10000000;
    g_seh_ebp = ebp; sub_003BB73F(); return; /* tail jmp 0x003BB73F */

}

/**
 * sub_003BB70A
 * Original: 0x003BB70A - 0x003BB73F (53 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB70A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB70A: ;
    if (CMP_EQ(edi, 0x20000000)) goto loc_003BB71A; /* je: equal / zero */

loc_003BB712: ;
    if (CMP_NE(edi, 0x30000000)) goto loc_003BB73A; /* jne: not equal / not zero */

loc_003BB71A: ;
    if (CMP_NE(MEM32(ebp + 0xC), 0xC000003Eu)) goto loc_003BB73A; /* jne: not equal / not zero */

loc_003BB723: ;
    ecx = esi + 0x28;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB16F(); /* call 0x003BB16F */

loc_003BB72B: ;
    MEM32(ebp + 0xC) = MEM32(ebp + 0xC) & 0;
    edx = MEM32(ebp + 8);
    edi = edi + 0x10000000;
    g_seh_ebp = ebp; sub_003BB73F(); return; /* tail jmp 0x003BB73F */

loc_003BB73A: ;
    edi = 0x50000000;

    g_seh_ebp = ebp; sub_003BB73F(); return; /* restored dropped fall-through to sub_003BB73F */
}

/**
 * sub_003BB73F
 * Original: 0x003BB73F - 0x003BB85C (285 bytes, 82 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB73F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB73F: ;
    eax = MEM32(esi + 0xC);
    ecx = 0xFFFFFFF;
    eax = eax & ecx;
    eax = eax | edi;
    /* cmp edi, 0x20000000 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (CMP_EQ(edi, 0x20000000)) goto loc_003BB806; /* je: equal / zero */

loc_003BB75A: ;
    if (CMP_EQ(edi, 0x30000000)) goto loc_003BB7ED; /* je: equal / zero */

loc_003BB766: ;
    if (CMP_EQ(edi, 0x40000000)) goto loc_003BB7B6; /* je: equal / zero */

loc_003BB76E: ;
    if (CMP_NE(edi, 0x50000000)) goto loc_003BB855; /* jne: not equal / not zero */

loc_003BB77A: ;
    eax = eax & ecx;
    MEM32(esi + 0xC) = eax;
    eax = MEM32(0xF273CC);
    ecx = MEM32(eax);
    eax = MEM32(eax + 4);
    MEM32(eax) = ecx;
    MEM32(ecx + 4) = eax;
    eax = MEM32(edx + 4);
    MEM32(ebx + 0x14) = eax;
    eax = MEM32(ebp + 0xC);
    SET_LO8(edx, 0); /* xor self */
    ecx = ebx;
    MEM32(ebx + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB7A4: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB153(); /* call 0x003BB153 */

loc_003BB7A9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB7B1: ;
    goto loc_003BB855;

loc_003BB7B6: ;
    MEM8(esi + 0x4F) = 0x2A;
    MEM8(esi + 0x37) = 6;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x18);
    MEM32(esi + 0x38) = eax;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x1C);
    MEM32(esi + 0x3C) = eax;
    eax = MEM32(edx + 8);
    MEM32(esi + 0x28) = eax;
    eax = MEM32(esi + 0x168);
    MEM32(esi + 0x2C) = eax;
    eax = MEM32(edx + 0xC);
    eax = eax - MEM32(esi + 0x38);
    goto loc_003BB826;

loc_003BB7ED: ;
    eax = MEM32(esi + 0x2C);
    eax = eax + 0xF273D4;
    MEM32(esi + 0x28) = eax;
    eax = MEM32(esi + 0x1C);
    MEM32(esi + 0x2C) = eax;
    eax = MEM32(edx + 0xC);
    eax = eax + MEM32(edx + 4);
    goto loc_003BB826;

loc_003BB806: ;
    MEM8(esi + 0x37) = 1;
    MEM8(esi + 0x4F) = 0x28;
    MEM32(esi + 0x28) = 0xF273D4;
    ecx = MEM32(esi + 0x168);
    ecx = ecx - MEM32(esi + 0x18);
    MEM32(esi + 0x2C) = ecx;
    eax = MEM32(edx + 0xC);
    eax = eax - ecx;

loc_003BB826: ;
    edi = esi + 0x158;
    ecx = MEM32(edi);
    eax = eax >> LO8(ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB099(); /* call 0x003BB099 */

loc_003BB836: ;
    MEM32(esi + 0x51) = eax;
    ecx = MEM32(edi);
    eax = MEM32(esi + 0x2C);
    eax = eax >> LO8(ecx);
    ecx = esi;
    MEM8(ebp + 0xE) = HI8(eax);
    MEM8(ebp + 0xF) = LO8(eax);
    SET_LO16(eax, MEM16(ebp + 0xE));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC906(); /* call 0x003BC906 */

loc_003BB855: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB85C
 * Original: 0x003BB85C - 0x003BB881 (37 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB85C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB85C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0x5F5F554D);
    PUSH32(esp, 8);
    POP32(esp, edi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C163C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB86F: ;
    if (TEST_NZ(eax, eax)) { g_seh_ebp = ebp; sub_003BB881(); return; } /* jne: not equal / not zero */

loc_003BB873: ;
    eax = MEM32(esi + 0x10);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    eax = 0xC000009Au;
    g_seh_ebp = ebp; sub_003BB8B6(); return; /* tail jmp 0x003BB8B6 */

}

/**
 * sub_003BB881
 * Original: 0x003BB881 - 0x003BB8B6 (53 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB881(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB881: ;
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = edi;
    ecx = esi + 0x4F;
    MEM32(esi + 0x30) = 0x3BB1C6;
    MEM16(esi + 0x34) = 0xA;
    MEM8(esi + 0x36) = 2;
    MEM8(esi + 0x37) = 1;
    eax = 0; /* xor self */
    edi = ecx;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM8(ecx) = 0x25;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC906(); /* call 0x003BC906 */

loc_003BB8B1: ;
    eax = 0x103;

    g_seh_ebp = ebp; sub_003BB8B6(); return; /* restored dropped fall-through to sub_003BB8B6 */
}

/**
 * sub_003BB8B6
 * Original: 0x003BB8B6 - 0x003BB8B9 (3 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB8B6(void)
{

loc_003BB8B6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BB8B9
 * Original: 0x003BB8B9 - 0x003BB8F0 (55 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB8B9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB8B9: ;
    edx = MEM32(esp + 8);
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    MEM8(esi + 0xF) = MEM8(esi + 0xF) & 0xF;
    ecx = MEM32(esi + 0x10);
    PUSH32(esp, edi);
    eax = 0xC0000000u;
    edi = edx;
    edi = edi & eax;
    if (CMP_NE(edi, eax)) { g_seh_ebp = ebp; sub_003BB8F0(); return; } /* jne: not equal / not zero */

loc_003BB8D7: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    MEM32(ecx + 0x10) = edx;
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB8E6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB8EE: ;
    g_seh_ebp = ebp; sub_003BB956(); return; /* tail jmp 0x003BB956 */

}

/**
 * sub_003BB8F0
 * Original: 0x003BB8F0 - 0x003BB956 (102 bytes, 32 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB8F0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB8F0: ;
    eax = 0; /* xor self */
    edi = esi + 0x4F;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM16(esi + 0x34) = 8;
    MEM8(esi + 0x36) = 2;
    if (TEST_Z(MEM8(esi + 0xF), 8)) goto loc_003BB912; /* je: equal / zero */

loc_003BB909: ;
    MEM32(esi + 0x30) = 0x3BB6E1;
    goto loc_003BB919;

loc_003BB912: ;
    MEM32(esi + 0x30) = 0x3BB4FB;

loc_003BB919: ;
    MEM8(esi + 0xF) = MEM8(esi + 0xF) | 0x10;
    edi = MEM32(0xF273CC);
    edx = 0xF273CC;
    /* cmp edi, edx - flags set for next jcc */
    eax = ecx + 0x54;
    if (CMP_NE(edi, edx)) goto loc_003BB944; /* jne: not equal / not zero */

loc_003BB92F: ;
    MEM32(eax) = edi;
    MEM32(ecx + 0x58) = edx;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    MEM32(edi + 4) = eax;
    PUSH32(esp, esi);
    MEM32(0xF273CC) = eax;
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BB942: ;
    g_seh_ebp = ebp; sub_003BB956(); return; /* tail jmp 0x003BB956 */

loc_003BB944: ;
    esi = MEM32(0xF273D0);
    MEM32(eax) = edx;
    MEM32(ecx + 0x58) = esi;
    MEM32(esi) = eax;
    MEM32(0xF273D0) = eax;

    g_seh_ebp = ebp; sub_003BB956(); return; /* restored dropped fall-through to sub_003BB956 */
}

/**
 * sub_003BB956
 * Original: 0x003BB956 - 0x003BB95B (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB956(void)
{

loc_003BB956: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BB95B
 * Original: 0x003BB95B - 0x003BB9DE (131 bytes, 42 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB95B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BB95B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0xC);
    eax = MEM32(esi + 0x5C);
    eax = MEM32(eax + 0x10);
    eax = eax - 0x70000;
    PUSH32(esp, edi);
    if ((eax == 0)) { g_seh_ebp = ebp; sub_003BB9DE(); return; } /* je: equal / zero */

loc_003BB974: ;
    eax = eax - 0x14;
    if ((eax == 0)) goto loc_003BB9D2; /* je: equal / zero */

loc_003BB979: ;
    eax = eax - 0x3FF0;
    if ((eax == 0)) goto loc_003BB98E; /* je: equal / zero */

loc_003BB980: ;
    MEM32(esi + 0x14) = MEM32(esi + 0x14) & 0;
    eax = 0xC0000010u;
    g_seh_ebp = ebp; sub_003BBA0F(); return; /* tail jmp 0x003BBA0F */

loc_003BB98E: ;
    edx = MEM32(esi + 0x30);
    PUSH32(esp, 8);
    eax = 0; /* xor self */
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebx + 0x160);
    eax = eax | MEM32(ebx + 0x164);
    if ((eax != 0)) goto loc_003BB9B3; /* jne: not equal / not zero */

loc_003BB9A8: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB85C(); /* call 0x003BB85C */

loc_003BB9B1: ;
    g_seh_ebp = ebp; sub_003BBA08(); return; /* tail jmp 0x003BBA08 */

loc_003BB9B3: ;
    eax = MEM32(ebx + 0x160);
    MEM32(edx + 8) = eax;
    eax = MEM32(ebx + 0x164);
    MEM32(edx + 0xC) = eax;
    MEM8(edx + 0x1A) = 1;
    MEM32(esi + 0x14) = 0x20;
    g_seh_ebp = ebp; sub_003BBA06(); return; /* tail jmp 0x003BBA06 */

loc_003BB9D2: ;
    ecx = MEM32(ebp + 8);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB3AC(); /* call 0x003BB3AC */

loc_003BB9DC: ;
    g_seh_ebp = ebp; sub_003BBA24(); return; /* tail jmp 0x003BBA24 */

}

/**
 * sub_003BB9A8
 * Original: 0x003BB9A8 - 0x003BB9DE (54 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB9A8(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB9A8: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB85C(); /* call 0x003BB85C */

loc_003BB9B1: ;
    g_seh_ebp = ebp; sub_003BBA08(); return; /* tail jmp 0x003BBA08 */

    eax = MEM32(ebx + 0x160);
    MEM32(edx + 8) = eax;
    eax = MEM32(ebx + 0x164);
    MEM32(edx + 0xC) = eax;
    MEM8(edx + 0x1A) = 1;
    MEM32(esi + 0x14) = 0x20;
    g_seh_ebp = ebp; sub_003BBA06(); return; /* tail jmp 0x003BBA06 */

    ecx = MEM32(ebp + 8);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB3AC(); /* call 0x003BB3AC */

loc_003BB9DC: ;
    g_seh_ebp = ebp; sub_003BBA24(); return; /* tail jmp 0x003BBA24 */

}

/**
 * sub_003BB9DE
 * Original: 0x003BB9DE - 0x003BBA06 (40 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BB9DE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BB9DE: ;
    eax = MEM32(ebx + 0x160);
    eax = eax | MEM32(ebx + 0x164);
    edi = MEM32(esi + 0x30);
    if ((eax == 0)) { g_seh_ebp = ebp; sub_003BB9A8(); return; } /* je: equal / zero */

loc_003BB9EF: ;
    PUSH32(esp, 6);
    esi = ebx + 0x140;
    POP32(esp, ecx);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebp + 0xC);
    MEM32(ecx + 0x14) = 0x18;
    esi = ecx;

    g_seh_ebp = ebp; sub_003BBA06(); return; /* restored dropped fall-through to sub_003BBA06 */
}

/**
 * sub_003BBA06
 * Original: 0x003BBA06 - 0x003BBA08 (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBA06(void)
{

loc_003BBA06: ;
    eax = 0; /* xor self */

    sub_003BBA08(); return; /* restored dropped fall-through to sub_003BBA08 */
}

/**
 * sub_003BBA08
 * Original: 0x003BBA08 - 0x003BBA0F (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBA08(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BBA08: ;
    if (CMP_EQ(eax, 0x103)) { g_seh_ebp = ebp; sub_003BBA24(); return; } /* je: equal / zero */

    g_seh_ebp = ebp; sub_003BBA0F(); return; /* restored dropped fall-through to sub_003BBA0F */
}

/**
 * sub_003BBA0F
 * Original: 0x003BBA0F - 0x003BBA24 (21 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBA0F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBA0F: ;
    SET_LO8(edx, 0); /* xor self */
    ecx = esi;
    MEM32(esi + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBA1C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebx));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003BBA24(); return; /* restored dropped fall-through to sub_003BBA24 */
}

/**
 * sub_003BBA24
 * Original: 0x003BBA24 - 0x003BBA2B (7 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBA24(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBA24: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BBA2B
 * Original: 0x003BBA2B - 0x003BBACF (164 bytes, 57 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBA2B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003BBA2B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    PUSH32(esp, ebx);
    eax = edx;
    PUSH32(esp, esi);
    esi = ecx;
    ecx = MEM32(eax + 0x5C);
    edx = MEM32(ecx + 0xC);
    ebx = MEM32(ecx + 4);
    PUSH32(esp, edi);
    edi = 0xFFF;
    /* test edi, edx - flags set for next jcc */
    MEM32(ebp + -8) = eax;
    MEM32(ebp + -12) = edx;
    if (TEST_NZ(edi, edx)) goto loc_003BBAA7; /* jne: not equal / not zero */

loc_003BBA54: ;
    if (TEST_NZ(edi, ebx)) goto loc_003BBAA7; /* jne: not equal / not zero */

loc_003BBA58: ;
    eax = 0; /* xor self */
    edi = ebx;
    edi = edi + edx;
    _cf = ((uint32_t)(edi) < (uint32_t)(edx)); /* CF from add */
    eax = eax + MEM32(ecx + 0x10) + _cf; /* adc */
    if (CMP_G(eax, MEM32(esi + 0x164))) goto loc_003BBAA4; /* jg: greater (signed >) */

loc_003BBA69: ;
    if (CMP_L(eax, MEM32(esi + 0x164))) goto loc_003BBA73; /* jl: less (signed <) */

loc_003BBA6B: ;
    if (CMP_A(edi, MEM32(esi + 0x160))) goto loc_003BBAA4; /* ja: above (unsigned >) */

loc_003BBA73: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BBA7F; /* jne: not equal / not zero */

loc_003BBA77: ;
    eax = MEM32(ebp + -8);
    MEM32(eax + 0x10) = MEM32(eax + 0x10) & ebx;
    goto loc_003BBAB4;

loc_003BBA7F: ;
    if (TEST_Z(MEM8(ecx + 2), 0x80)) goto loc_003BBA90; /* je: equal / zero */

loc_003BBA85: ;
    eax = MEM32(ecx + 8);
    MEM32(ebp + -4) = eax;
    eax = MEM32(ebp + -8);
    goto loc_003BBA9C;

loc_003BBA90: ;
    eax = MEM32(ebp + -8);
    edi = MEM32(eax + 0x30);
    edi = edi + MEM32(ecx + 8);
    MEM32(ebp + -4) = edi;

loc_003BBA9C: ;
    edi = MEM32(ebp + -4);
    MEM32(ecx + 8) = edi;
    goto loc_003BBAAE;

loc_003BBAA4: ;
    eax = MEM32(ebp + -8);

loc_003BBAA7: ;
    MEM32(eax + 0x10) = 0xC000000Du;

loc_003BBAAE: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) { g_seh_ebp = ebp; sub_003BBACF(); return; } /* jne: not equal / not zero */

loc_003BBAB4: ;
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    SET_LO8(edx, 0); /* xor self */
    ecx = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBAC2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBACA: ;
    g_seh_ebp = ebp; sub_003BBBB6(); return; /* tail jmp 0x003BBBB6 */

}

/**
 * sub_003BBACF
 * Original: 0x003BBACF - 0x003BBBB6 (231 bytes, 76 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBACF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBACF: ;
    eax = 0; /* xor self */
    edi = esi + 0x4F;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    if (CMP_NE(MEM8(ecx), 3)) goto loc_003BBB68; /* jne: not equal / not zero */

loc_003BBAE1: ;
    edi = MEM32(esi + 0x168);
    eax = edx;
    edx = 0; /* xor self */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)edi);
      edx = (uint32_t)(_dividend % (uint32_t)edi); }
    MEM8(esi + 0xF) = MEM8(esi + 0xF) & 0xF1;
    ecx = MEM32(esi + 0xC);
    if (TEST_Z(edx, edx)) goto loc_003BBB24; /* je: equal / zero */

loc_003BBAF8: ;
    eax = edi;
    eax = eax - edx;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(esi + 0x18) = eax;
    if (CMP_BE(eax, ebx)) goto loc_003BBB13; /* jbe: below or equal (unsigned <=) */

loc_003BBB03: ;
    ecx = ecx | 0x8000000;
    eax = eax - ebx;
    MEM32(esi + 0xC) = ecx;
    MEM32(esi + 0x1C) = eax;
    goto loc_003BBB3B;

loc_003BBB13: ;
    MEM32(ebp + -12) = MEM32(ebp + -12) + eax;
    MEM32(ebp + -4) = MEM32(ebp + -4) + eax;
    ebx = ebx - eax;
    ecx = ecx | 0x2000000;
    MEM32(esi + 0xC) = ecx;

loc_003BBB24: ;
    edx = 0; /* xor self */
    eax = ebx;
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)edi);
      edx = (uint32_t)(_dividend % (uint32_t)edi); }
    if (TEST_Z(edx, edx)) goto loc_003BBB37; /* je: equal / zero */

loc_003BBB2E: ;
    ebx = ebx - edx;
    MEM8(esi + 0xF) = MEM8(esi + 0xF) | 4;
    MEM32(esi + 0x1C) = edx;

loc_003BBB37: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BBB45; /* jne: not equal / not zero */

loc_003BBB3B: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB8B9(); /* call 0x003BB8B9 */

loc_003BBB43: ;
    g_seh_ebp = ebp; sub_003BBBB6(); return; /* tail jmp 0x003BBBB6 */

loc_003BBB45: ;
    if (TEST_Z(MEM8(esi + 0xF), 0xE)) goto loc_003BBB54; /* je: equal / zero */

loc_003BBB4B: ;
    MEM32(esi + 0x30) = 0x3BB8B9;
    goto loc_003BBB5B;

loc_003BBB54: ;
    MEM32(esi + 0x30) = 0x3BB113;

loc_003BBB5B: ;
    edx = MEM32(ebp + -12);
    MEM8(esi + 0x37) = 2;
    MEM8(esi + 0x4F) = 0x2A;
    goto loc_003BBB77;

loc_003BBB68: ;
    MEM32(esi + 0x30) = 0x3BB42D;
    MEM8(esi + 0x37) = 1;
    MEM8(esi + 0x4F) = 0x28;

loc_003BBB77: ;
    edi = MEM32(esi + 0x158);
    eax = MEM32(ebp + -4);
    ecx = edi;
    edx = edx >> LO8(ecx);
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = ebx;
    MEM16(esi + 0x34) = 8;
    PUSH32(esp, edx);
    MEM8(esi + 0x36) = 2;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB099(); /* call 0x003BB099 */

loc_003BBB9A: ;
    ecx = edi;
    ebx = ebx >> LO8(ecx);
    MEM32(esi + 0x51) = eax;
    ecx = esi;
    MEM8(ebp + -2) = HI8(ebx);
    MEM8(ebp + -1) = LO8(ebx);
    SET_LO16(eax, MEM16(ebp + -2));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC906(); /* call 0x003BC906 */

    g_seh_ebp = ebp; sub_003BBBB6(); return; /* restored dropped fall-through to sub_003BBBB6 */
}

/**
 * sub_003BBBB6
 * Original: 0x003BBBB6 - 0x003BBBBB (5 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBBB6(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBBB6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BBBBB
 * Original: 0x003BBBBB - 0x003BBBF4 (57 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBBBB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BBBBB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    eax = MEM32(ebx + 0x18);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 0xC);
    esi = MEM32(edi + 0x5C);
    MEM32(ebp + 8) = eax;
    { uint32_t _icall_t = MEM32(0x3C1644); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBBD6: ;
    if (TEST_Z(LO8(eax), LO8(eax))) { g_seh_ebp = ebp; sub_003BBBF4(); return; } /* je: equal / zero */

loc_003BBBDA: ;
    SET_LO8(edx, 0); /* xor self */
    ecx = edi;
    MEM32(edi + 0x10) = 0xC0000240u;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C1630); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBBEB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C1634); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBBF2: ;
    g_seh_ebp = ebp; sub_003BBC25(); return; /* tail jmp 0x003BBC25 */

}

/**
 * sub_003BBBF4
 * Original: 0x003BBBF4 - 0x003BBC25 (49 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBBF4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBBF4: ;
    MEM32(esi + 0x14) = ebx;
    ebx = MEM32(ebp + 8);
    MEM32(ebx + 0x10) = edi;
    eax = ZX8(MEM8(esi));
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BBC1C; /* je: equal / zero */

loc_003BBC04: ;
    eax--;
    if ((eax == 0)) goto loc_003BBC15; /* je: equal / zero */

loc_003BBC07: ;
    eax = eax - 7;
    if ((eax != 0)) { g_seh_ebp = ebp; sub_003BBC25(); return; } /* jne: not equal / not zero */

loc_003BBC0C: ;
    PUSH32(esp, edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB95B(); /* call 0x003BB95B */

loc_003BBC13: ;
    g_seh_ebp = ebp; sub_003BBC25(); return; /* tail jmp 0x003BBC25 */

loc_003BBC15: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C1640); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBC1C: ;
    edx = edi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBA2B(); /* call 0x003BBA2B */

    g_seh_ebp = ebp; sub_003BBC25(); return; /* restored dropped fall-through to sub_003BBC25 */
}

/**
 * sub_003BBC25
 * Original: 0x003BBC25 - 0x003BBC2C (7 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBC25(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBC25: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BBC2C
 * Original: 0x003BBC2C - 0x003BBC79 (77 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBC2C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBC2C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = edi + 3;
    esi = esi & 0xFFFFFFFCu;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBC3F: ;
    /* cmp MEM32(0x3B8508), esi - flags set for next jcc */
    SET_LO8(ecx, LO8(eax));
    if (CMP_B(MEM32(0x3B8508), esi)) { g_seh_ebp = ebp; sub_003BBC79(); return; } /* jb: below (unsigned <) */

loc_003BBC49: ;
    ebx = 0x80001000u;
    ebx = ebx - MEM32(0x3B8508);
    MEM32(0x3B8508) = MEM32(0x3B8508) - esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBC60: ;
    ecx = esi;
    edx = ecx;
    ecx = ecx >> 2;
    eax = 0xCCCCCCCCu;
    edi = ebx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    g_seh_ebp = ebp; sub_003BBC8C(); return; /* tail jmp 0x003BBC8C */

}

/**
 * sub_003BBC79
 * Original: 0x003BBC79 - 0x003BBC8C (19 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBC79(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBC79: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBC7F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esp + 0x14));
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C163C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBC8A: ;
    ebx = eax;

    g_seh_ebp = ebp; sub_003BBC8C(); return; /* restored dropped fall-through to sub_003BBC8C */
}

/**
 * sub_003BBC8C
 * Original: 0x003BBC8C - 0x003BBCA5 (25 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBC8C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBC8C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BBC94
 * Original: 0x003BBC94 - 0x003BBCA5 (17 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBC94(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBC94: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(esp + 0x10));
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BBCA2: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BBCA5
 * Original: 0x003BBCA5 - 0x003BBCB8 (19 bytes, 6 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCA5(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBCA5: ;
    eax = MEM32(ecx + 0xC);
    PUSH32(esp, MEM32(esp + 4));
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEA62(); /* call 0x003BEA62 */

loc_003BBCB5: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBCB8
 * Original: 0x003BBCB8 - 0x003BBCBC (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCB8(void)
{

loc_003BBCB8: ;
    eax = MEM32(ecx + 0x1C);
    esp += 4; return; /* ret */

}

/**
 * sub_003BBCBC
 * Original: 0x003BBCBC - 0x003BBCC9 (13 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCBC(void)
{

loc_003BBCBC: ;
    edx = MEM32(esp + 4);
    eax = MEM32(ecx + 0x1C);
    MEM32(ecx + 0x1C) = edx;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBCC9
 * Original: 0x003BBCC9 - 0x003BBCCD (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCC9(void)
{

loc_003BBCC9: ;
    SET_LO8(eax, MEM8(ecx + 2));
    esp += 4; return; /* ret */

}

/**
 * sub_003BBCCD
 * Original: 0x003BBCCD - 0x003BBCD7 (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCCD(void)
{

loc_003BBCCD: ;
    SET_LO8(eax, MEM8(esp + 4));
    MEM8(ecx + 7) = LO8(eax);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBCD7
 * Original: 0x003BBCD7 - 0x003BBD41 (106 bytes, 34 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBCD7(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BBCD7: ;
    eax = MEM32(esp + 4);
    ecx = 0xC000000Fu;
    if (CMP_G(eax, ecx)) goto loc_003BBD24; /* jg: greater (signed >) */

loc_003BBCE4: ;
    if (CMP_EQ(eax, ecx)) goto loc_003BBD1D; /* je: equal / zero */

loc_003BBCE6: ;
    if (CMP_EQ(eax, 0x80000000u)) goto loc_003BBD09; /* je: equal / zero */

loc_003BBCED: ;
    if (CMP_EQ(eax, 0x80000100u)) goto loc_003BBD18; /* je: equal / zero */

loc_003BBCF4: ;
    if (CMP_EQ(eax, 0x80000800u)) goto loc_003BBD11; /* je: equal / zero */

loc_003BBCFB: ;
    if (CMP_LE(eax, 0xBFFFFFFFu)) goto loc_003BBD36; /* jle: less or equal (signed <=) */

loc_003BBD02: ;
    if (CMP_G(eax, 0xC000000Eu)) goto loc_003BBD36; /* jg: greater (signed >) */

loc_003BBD09: ;
    eax = 0x45D;

loc_003BBD0E: ;
    esp += 8; return; /* ret 4 */

loc_003BBD11: ;
    eax = 0x5AA;
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

loc_003BBD18: ;
    PUSH32(esp, 0xE);

loc_003BBD1A: ;
    POP32(esp, eax);
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

loc_003BBD1D: ;
    eax = 0x4C7;
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

loc_003BBD24: ;
    if (CMP_EQ(eax, 0xC0000010u)) { RECOMP_SLICE_POINT(); goto loc_003BBD09; } /* je: equal / zero */

loc_003BBD2B: ;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BBD41(); return; } /* je: equal / zero */

loc_003BBD2F: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BBD3A; /* je: equal / zero */

loc_003BBD36: ;
    PUSH32(esp, 0x1F);
    { RECOMP_SLICE_POINT(); goto loc_003BBD1A; }

loc_003BBD3A: ;
    eax = 0x3E5;
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

}

/**
 * sub_003BBD09
 * Original: 0x003BBD09 - 0x003BBD0E (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD09(void)
{

loc_003BBD09: ;
    eax = 0x45D;

    sub_003BBD0E(); return; /* restored dropped fall-through to sub_003BBD0E */
}

/**
 * sub_003BBD0E
 * Original: 0x003BBD0E - 0x003BBD41 (51 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD0E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BBD0E: ;
    esp += 8; return; /* ret 4 */

    PUSH32(esp, 0xE);

loc_003BBD1A: ;
    POP32(esp, eax);
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

    eax = 0x4C7;
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

    if (CMP_EQ(eax, 0xC0000010u)) { g_seh_ebp = ebp; sub_003BBD09(); return; } /* je: equal / zero */

loc_003BBD2B: ;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BBD41(); return; } /* je: equal / zero */

loc_003BBD2F: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BBD3A; /* je: equal / zero */

loc_003BBD36: ;
    PUSH32(esp, 0x1F);
    { RECOMP_SLICE_POINT(); goto loc_003BBD1A; }

loc_003BBD3A: ;
    eax = 0x3E5;
    { RECOMP_SLICE_POINT(); goto loc_003BBD0E; }

}

/**
 * sub_003BBD41
 * Original: 0x003BBD41 - 0x003BBD45 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD41(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBD41: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BBD0E(); return; /* tail jmp 0x003BBD0E */

}

/**
 * sub_003BBD45
 * Original: 0x003BBD45 - 0x003BBDAD (104 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD45(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BBD45: ;
    eax = MEM32(esp + 4);
    ecx = 0xC000000Fu;
    if (CMP_G(eax, ecx)) goto loc_003BBD8D; /* jg: greater (signed >) */

loc_003BBD52: ;
    if (CMP_EQ(eax, ecx)) goto loc_003BBD86; /* je: equal / zero */

loc_003BBD54: ;
    if (CMP_EQ(eax, 0x80000000u)) goto loc_003BBD77; /* je: equal / zero */

loc_003BBD5B: ;
    if (CMP_EQ(eax, 0x80000100u)) goto loc_003BBD7F; /* je: equal / zero */

loc_003BBD62: ;
    if (CMP_EQ(eax, 0x80000800u)) goto loc_003BBD7F; /* je: equal / zero */

loc_003BBD69: ;
    if (CMP_LE(eax, 0xBFFFFFFFu)) goto loc_003BBD9F; /* jle: less or equal (signed <=) */

loc_003BBD70: ;
    if (CMP_G(eax, 0xC000000Eu)) goto loc_003BBD9F; /* jg: greater (signed >) */

loc_003BBD77: ;
    eax = 0xC0000185u;

loc_003BBD7C: ;
    esp += 8; return; /* ret 4 */

loc_003BBD7F: ;
    eax = 0xC000009Au;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

loc_003BBD86: ;
    eax = 0xC0000120u;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

loc_003BBD8D: ;
    if (CMP_EQ(eax, 0xC0000010u)) { RECOMP_SLICE_POINT(); goto loc_003BBD77; } /* je: equal / zero */

loc_003BBD94: ;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BBDAD(); return; } /* je: equal / zero */

loc_003BBD98: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BBDA6; /* je: equal / zero */

loc_003BBD9F: ;
    eax = 0xC0000001u;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

loc_003BBDA6: ;
    eax = 0x103;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

}

/**
 * sub_003BBD77
 * Original: 0x003BBD77 - 0x003BBD7C (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD77(void)
{

loc_003BBD77: ;
    eax = 0xC0000185u;

    sub_003BBD7C(); return; /* restored dropped fall-through to sub_003BBD7C */
}

/**
 * sub_003BBD7C
 * Original: 0x003BBD7C - 0x003BBDAD (49 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBD7C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BBD7C: ;
    esp += 8; return; /* ret 4 */

    eax = 0xC0000120u;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

    if (CMP_EQ(eax, 0xC0000010u)) { g_seh_ebp = ebp; sub_003BBD77(); return; } /* je: equal / zero */

loc_003BBD94: ;
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BBDAD(); return; } /* je: equal / zero */

loc_003BBD98: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BBDA6; /* je: equal / zero */

loc_003BBD9F: ;
    eax = 0xC0000001u;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

loc_003BBDA6: ;
    eax = 0x103;
    { RECOMP_SLICE_POINT(); goto loc_003BBD7C; }

}

/**
 * sub_003BBDAD
 * Original: 0x003BBDAD - 0x003BBDB1 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBDAD(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBDAD: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BBD7C(); return; /* tail jmp 0x003BBD7C */

}

/**
 * sub_003BBDB1
 * Original: 0x003BBDB1 - 0x003BBDB7 (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBDB1(void)
{

loc_003BBDB1: ;
    eax = MEM32(0xF2A4B4);
    esp += 4; return; /* ret */

}

/**
 * sub_003BBDB7
 * Original: 0x003BBDB7 - 0x003BBE2D (118 bytes, 49 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBDB7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BBDB7: ;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(0xF2A4B4);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ZX16(MEM16(0xF2A466));
    PUSH32(esp, edi);
    esi = esi + 0xF2A464;
    edi = 0; /* xor self */

loc_003BBDD2: ;
    SET_LO8(edx, MEM8(ecx));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BBE24; /* je: equal / zero */

loc_003BBDD8: ;
    eax = ZX8(LO8(edx));
    ecx = ecx + eax;
    if (CMP_AE(ecx, esi)) goto loc_003BBE24; /* jae: above or equal (unsigned >=) */

loc_003BBDE1: ;
    SET_LO8(eax, MEM8(ecx + 1));
    if (CMP_NE(LO8(eax), 5)) goto loc_003BBE1C; /* jne: not equal / not zero */

loc_003BBDE8: ;
    SET_LO8(edx, MEM8(ecx + 3));
    SET_LO8(edx, LO8(edx) & 3);
    if (CMP_NE(LO8(edx), MEM8(ebp + 8))) goto loc_003BBE1C; /* jne: not equal / not zero */

loc_003BBDF3: ;
    if (CMP_EQ(MEM8(ebp + 8), 0)) goto loc_003BBE1C; /* je: equal / zero */

loc_003BBDF9: ;
    edx = 0; /* xor self */
    SET_LO8(edx, MEM8(ecx + 2));
    ebx = 0; /* xor self */
    edx = edx >> 7;
    edx = ~edx;
    edx = edx & 1;
    /* cmp MEM8(ebp + 0xC), LO8(ebx) - flags set for next jcc */
    SET_LO8(ebx, (CMP_EQ(MEM8(ebp + 0xC), LO8(ebx))) ? 1 : 0); /* sete */
    if (CMP_NE(edx, ebx)) goto loc_003BBE1C; /* jne: not equal / not zero */

loc_003BBE12: ;
    SET_LO8(edx, MEM8(ebp + 0x10));
    MEM8(ebp + 0x10) = MEM8(ebp + 0x10) - 1;
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BBE22; /* je: equal / zero */

loc_003BBE1C: ;
    if (CMP_NE(LO8(eax), 4)) { RECOMP_SLICE_POINT(); goto loc_003BBDD2; } /* jne: not equal / not zero */

loc_003BBE20: ;
    goto loc_003BBE24;

loc_003BBE22: ;
    edi = ecx;

loc_003BBE24: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BBE2D
 * Original: 0x003BBE2D - 0x003BBE31 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBE2D(void)
{

loc_003BBE2D: ;
    eax = MEM32(ecx + 0x14);
    esp += 4; return; /* ret */

}

/**
 * sub_003BBE31
 * Original: 0x003BBE31 - 0x003BBE5F (46 bytes, 18 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBE31(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBE31: ;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = ecx;
    ebx = 0; /* xor self */
    if (CMP_NE(MEM8(edi), 5)) { g_seh_ebp = ebp; sub_003BBE5F(); return; } /* jne: not equal / not zero */

loc_003BBE3C: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BBE41: ;
    ebx = eax;
    eax = MEM32(ebx + 8);
    if (TEST_Z(eax, eax)) { g_seh_ebp = ebp; sub_003BBE5F(); return; } /* je: equal / zero */

loc_003BBE4A: ;
    MEM32(edi + 8) = eax;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BBE5B: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BBEB2(); return; /* tail jmp 0x003BBEB2 */

}

/**
 * sub_003BBE5F
 * Original: 0x003BBE5F - 0x003BBEB2 (83 bytes, 28 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBE5F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBE5F: ;
    SET_LO8(eax, MEM8(edi + 5));
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    MEM8(esi + 0x14) = LO8(eax);
    MEM8(esi + 0x15) = 0;
    MEM8(esi + 0x16) = 0;
    SET_LO16(eax, ZX8(MEM8(edi + 6)));
    MEM16(esi + 0x1C) = LO16(eax);
    SET_LO8(eax, MEM8(edi + 4));
    MEM32(esi + 0x18) = MEM32(esi + 0x18) & 0;
    SET_LO8(eax, LO8(eax) >> 7);
    MEM8(esi + 0x1E) = LO8(eax);
    MEM8(esi + 1) = 2;
    eax = MEM32(edi + 0xC);
    PUSH32(esp, esi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BBE99: ;
    if (TEST_S(eax, eax)) goto loc_003BBEAD; /* jl: less (signed <) */

loc_003BBE9D: ;
    /* test ebx, ebx - flags set for next jcc */
    ecx = MEM32(esi + 0x10);
    MEM32(edi + 8) = ecx;
    if (TEST_Z(ebx, ebx)) goto loc_003BBEAD; /* je: equal / zero */

loc_003BBEA7: ;
    ecx = MEM32(esi + 0x10);
    MEM32(ebx + 8) = ecx;

loc_003BBEAD: ;
    MEM32(esi + 0x10) = MEM32(esi + 0x10) & 0;
    POP32(esp, esi);

    g_seh_ebp = ebp; sub_003BBEB2(); return; /* restored dropped fall-through to sub_003BBEB2 */
}

/**
 * sub_003BBEB2
 * Original: 0x003BBEB2 - 0x003BBEB7 (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBEB2(void)
{

loc_003BBEB2: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBEB7
 * Original: 0x003BBEB7 - 0x003BBF11 (90 bytes, 32 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBEB7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBEB7: ;
    PUSH32(esp, esi);
    esi = ecx;
    PUSH32(esp, edi);
    edi = MEM32(esi + 8);
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    if (CMP_NE(MEM8(esi), 5)) goto loc_003BBEF0; /* jne: not equal / not zero */

loc_003BBEC7: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BBECC: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BBED3: ;
    goto loc_003BBEE1;

loc_003BBED5: ;
    if (CMP_EQ(MEM32(eax + 8), edi)) { g_seh_ebp = ebp; sub_003BBF11(); return; } /* je: equal / zero */

loc_003BBEDA: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BBEE1: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BBED5; } /* jne: not equal / not zero */

loc_003BBEE5: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BBEEC: ;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;

loc_003BBEF0: ;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 0x18) = MEM32(eax + 0x18) & 0;
    PUSH32(esp, eax);
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 0x10) = edi;
    eax = MEM32(esi + 0xC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BBF0C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBF0C
 * Original: 0x003BBF0C - 0x003BBF11 (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBF0C(void)
{

loc_003BBF0C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBF11
 * Original: 0x003BBF11 - 0x003BBF23 (18 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBF11(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBF11: ;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BBF1F: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BBF0C(); return; /* tail jmp 0x003BBF0C */

}

/**
 * sub_003BBF23
 * Original: 0x003BBF23 - 0x003BBF54 (49 bytes, 19 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBF23(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBF23: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BBF28: ;
    if (TEST_Z(eax, eax)) goto loc_003BBF51; /* je: equal / zero */

loc_003BBF2C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ZX8(MEM8(esp + 0xC));
    esi = 0xFFFFFF7Fu;
    edi = edi & esi;

loc_003BBF3A: ;
    ecx = ZX8(MEM8(eax + 4));
    ecx = ecx & esi;
    if (CMP_EQ(ecx, edi)) goto loc_003BBF4F; /* je: equal / zero */

loc_003BBF44: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BBF4B: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BBF3A; } /* jne: not equal / not zero */

loc_003BBF4F: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BBF51: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBF54
 * Original: 0x003BBF54 - 0x003BBF9C (72 bytes, 25 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBF54(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBF54: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, ebx);
    ebx = eax;
    ebx = ebx - MEM32(0xF2A4B8);
    PUSH32(esp, esi);
    esi = ecx;
    MEM8(eax + 3) = 0x80;
    ecx = ecx - MEM32(0xF2A4B8);
    ebx = (uint32_t)((int32_t)ebx >> 5);
    ecx = (uint32_t)((int32_t)ecx >> 5);
    MEM8(eax + 1) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BBF7E: ;
    if (TEST_NZ(eax, eax)) goto loc_003BBF8E; /* jne: not equal / not zero */

loc_003BBF82: ;
    MEM8(esi + 2) = LO8(ebx);
    goto loc_003BBF97;

loc_003BBF87: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BBF8E: ;
    if (CMP_NE(MEM8(eax + 3), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003BBF87; } /* jne: not equal / not zero */

loc_003BBF94: ;
    MEM8(eax + 3) = LO8(ebx);

loc_003BBF97: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBF9C
 * Original: 0x003BBF9C - 0x003BBFF8 (92 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBF9C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBF9C: ;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    ebp = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1FF(); /* call 0x003BA1FF */

loc_003BBFA7: ;
    esi = MEM32(esp + 0x14);
    edi = eax;
    /* cmp edi, esi - flags set for next jcc */
    SET_LO8(ebx, 1);
    if (CMP_NE(edi, esi)) goto loc_003BBFC1; /* jne: not equal / not zero */

loc_003BBFB3: ;
    SET_LO8(eax, MEM8(esi + 3));
    /* cmp LO8(eax), 0x80 - flags set for next jcc */
    MEM8(ebp + 2) = LO8(eax);
    if (CMP_NE(LO8(eax), 0x80)) goto loc_003BBFE7; /* jne: not equal / not zero */

loc_003BBFBD: ;
    SET_LO8(ebx, 0); /* xor self */
    goto loc_003BBFE7;

loc_003BBFC1: ;
    if (TEST_Z(edi, edi)) goto loc_003BBFE7; /* je: equal / zero */

loc_003BBFC5: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BBFCC: ;
    if (CMP_EQ(eax, esi)) goto loc_003BBFDD; /* je: equal / zero */

loc_003BBFD0: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA216(); /* call 0x003BA216 */

loc_003BBFD7: ;
    edi = eax;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003BBFC5; } /* jne: not equal / not zero */

loc_003BBFDD: ;
    if (TEST_Z(edi, edi)) goto loc_003BBFE7; /* je: equal / zero */

loc_003BBFE1: ;
    SET_LO8(eax, MEM8(esi + 3));
    MEM8(edi + 3) = LO8(eax);

loc_003BBFE7: ;
    POP32(esp, edi);
    MEM8(esi + 3) = 0x80;
    MEM8(esi + 1) = 0x80;
    POP32(esp, esi);
    POP32(esp, ebp);
    SET_LO8(eax, LO8(ebx));
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BBFF8
 * Original: 0x003BBFF8 - 0x003BC018 (32 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BBFF8(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BBFF8: ;
    eax = MEM32(esp + 4);
    edx = MEM32(eax + 4);
    edx = ZX8(MEM8(edx + 4));
    edx = edx & 0x7F;
    edx--;
    /* cmp edx, 4 - flags set for next jcc */
    MEM32(ecx + 0x14) = edx;
    if (CMP_L(edx, 4)) { g_seh_ebp = ebp; sub_003BC018(); return; } /* jl: less (signed <) */

loc_003BC00F: ;
    MEM32(ecx + 0x14) = 0x20;
    g_seh_ebp = ebp; sub_003BC06A(); return; /* tail jmp 0x003BC06A */

}

/**
 * sub_003BC018
 * Original: 0x003BC018 - 0x003BC06A (82 bytes, 30 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC018(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BC018: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    edx = edx ^ 2;
    MEM32(ecx + 0x14) = edx;
    PUSH32(esp, edi);
    edi = MEM32(eax + esi * 4);
    if (CMP_NE(MEM8(edi), 1)) goto loc_003BC048; /* jne: not equal / not zero */

loc_003BC02C: ;
    if (CMP_EQ(esi, 1)) goto loc_003BC068; /* je: equal / zero */

loc_003BC031: ;
    if (CMP_EQ(MEM8(0x3B83B0), 0)) goto loc_003BC03F; /* je: equal / zero */

loc_003BC03A: ;
    if (CMP_EQ(esi, 2)) goto loc_003BC068; /* je: equal / zero */

loc_003BC03F: ;
    MEM32(ecx + 0x14) = 0x20;
    goto loc_003BC068;

loc_003BC048: ;
    if (CMP_BE(esi, 1)) goto loc_003BC068; /* jbe: below or equal (unsigned <=) */

loc_003BC04D: ;
    eax = MEM32(eax + 8);
    eax = ZX8(MEM8(eax + 4));
    eax = eax & 0x7F;
    eax--;
    if (CMP_A(eax, 3)) { RECOMP_SLICE_POINT(); goto loc_003BC03F; } /* ja: above (unsigned >) */

loc_003BC05D: ;
    if (CMP_NE(eax, 2)) goto loc_003BC068; /* jne: not equal / not zero */

loc_003BC062: ;
    edx = edx + 0x10;
    MEM32(ecx + 0x14) = edx;

loc_003BC068: ;
    POP32(esp, edi);
    POP32(esp, esi);

    sub_003BC06A(); return; /* restored dropped fall-through to sub_003BC06A */
}

/**
 * sub_003BC06A
 * Original: 0x003BC06A - 0x003BC06D (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC06A(void)
{

loc_003BC06A: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC06D
 * Original: 0x003BC06D - 0x003BC157 (234 bytes, 89 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC06D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BC06D: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    SET_LO8(eax, MEM8(esi + 1));
    ebx = 0; /* xor self */
    /* test LO8(eax), 0x40 - flags set for next jcc */
    MEM8(ebp + -1) = LO8(ebx);
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003BC0AD; /* je: equal / zero */

loc_003BC084: ;
    if (CMP_NE(MEM32(esi + 8), ebx)) goto loc_003BC0AD; /* jne: not equal / not zero */

loc_003BC089: ;
    edx = ebp + -12;
    MEM32(ebp + -8) = edx;
    MEM32(ebp + -12) = edx;
    edx = ebp + -20;
    MEM8(ebp + -1) = 1;
    MEM8(ebp + -20) = LO8(ebx);
    MEM8(ebp + -18) = 4;
    MEM32(ebp + -16) = ebx;
    MEM32(esi + 8) = 0x3BBC94;
    MEM32(esi + 0xC) = edx;

loc_003BC0AD: ;
    eax = ZX8(LO8(eax));
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BC103; /* je: equal / zero */

loc_003BC0B4: ;
    eax = eax - 7;
    if ((eax == 0)) goto loc_003BC0FB; /* je: equal / zero */

loc_003BC0B9: ;
    eax = eax - 0x37;
    if ((eax == 0)) goto loc_003BC0E5; /* je: equal / zero */

loc_003BC0BE: ;
    eax = eax - 3;
    if ((eax == 0)) goto loc_003BC0DD; /* je: equal / zero */

loc_003BC0C3: ;
    eax = eax - 0x3F;
    if ((eax == 0)) goto loc_003BC0D5; /* je: equal / zero */

loc_003BC0C8: ;
    eax = eax - 0x41;
    if ((eax != 0)) goto loc_003BC118; /* jne: not equal / not zero */

loc_003BC0CD: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBEB7(); /* call 0x003BBEB7 */

loc_003BC0D3: ;
    goto loc_003BC125;

loc_003BC0D5: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE31(); /* call 0x003BBE31 */

loc_003BC0DB: ;
    goto loc_003BC125;

loc_003BC0DD: ;
    eax = ecx + 0x18;
    MEM32(esi + 0x18) = eax;
    goto loc_003BC118;

loc_003BC0E5: ;
    if (CMP_NE(MEM32(esi + 0x10), ebx)) goto loc_003BC0F0; /* jne: not equal / not zero */

loc_003BC0EA: ;
    eax = MEM32(ecx + 8);
    MEM32(esi + 0x10) = eax;

loc_003BC0F0: ;
    if (CMP_NE(MEM8(esi + 0x29), 9)) goto loc_003BC118; /* jne: not equal / not zero */

loc_003BC0F6: ;
    MEM32(ecx + 0x18) = ebx;
    goto loc_003BC118;

loc_003BC0FB: ;
    SET_LO8(eax, MEM8(ecx + 5));
    MEM8(esi + 0x14) = LO8(eax);
    goto loc_003BC118;

loc_003BC103: ;
    SET_LO8(eax, MEM8(ecx + 5));
    MEM8(esi + 0x14) = LO8(eax);
    eax = ecx + 0x18;
    MEM32(esi + 0x18) = eax;
    SET_LO8(eax, MEM8(ecx + 4));
    SET_LO8(eax, LO8(eax) >> 7);
    MEM8(esi + 0x1E) = LO8(eax);

loc_003BC118: ;
    eax = MEM32(ecx + 0xC);
    PUSH32(esp, esi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEBD3(); /* call 0x003BEBD3 */

loc_003BC125: ;
    if (CMP_EQ(MEM8(ebp + -1), LO8(ebx))) goto loc_003BC151; /* je: equal / zero */

loc_003BC12A: ;
    ecx = eax;
    ecx = ecx & 0xC0000000u;
    if (CMP_NE(ecx, 0x40000000)) goto loc_003BC14B; /* jne: not equal / not zero */

loc_003BC13A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = ebp + -20;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC148: ;
    eax = MEM32(esi + 4);

loc_003BC14B: ;
    MEM32(esi + 8) = ebx;
    MEM32(esi + 0xC) = ebx;

loc_003BC151: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BC157
 * Original: 0x003BC157 - 0x003BC17A (35 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC157(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC157: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    eax = esi + 4;
    edx = MEM32(eax);
    if (CMP_NE(MEM8(edx), 1)) goto loc_003BC171; /* jne: not equal / not zero */

loc_003BC166: ;
    SET_LO8(edx, MEM8(edx + 4));
    SET_LO8(edx, LO8(edx) & 0x7F);
    if (CMP_EQ(LO8(edx), 1)) { g_seh_ebp = ebp; sub_003BC17A(); return; } /* je: equal / zero */

loc_003BC171: ;
    MEM32(ecx + 0x14) = 0x20;
    g_seh_ebp = ebp; sub_003BC195(); return; /* tail jmp 0x003BC195 */

}

/**
 * sub_003BC17A
 * Original: 0x003BC17A - 0x003BC195 (27 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC17A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC17A: ;
    edx = MEM32(esp + 0xC);
    if (CMP_NE(edx, 1)) goto loc_003BC189; /* jne: not equal / not zero */

loc_003BC183: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    g_seh_ebp = ebp; sub_003BC195(); return; /* tail jmp 0x003BC195 */

loc_003BC189: ;
    esi = MEM32(esi);
    edx--;
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBFF8(); /* call 0x003BBFF8 */

    g_seh_ebp = ebp; sub_003BC195(); return; /* restored dropped fall-through to sub_003BC195 */
}

/**
 * sub_003BC195
 * Original: 0x003BC195 - 0x003BC199 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC195(void)
{

loc_003BC195: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC199
 * Original: 0x003BC199 - 0x003BC1DB (66 bytes, 27 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC199(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BC199: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ecx;
    PUSH32(esp, 5);
    POP32(esp, esi);
    MEM32(ebp + -4) = edi;

loc_003BC1A9: ;
    ecx = MEM32(ebp + esi * 4 + -24);
    esi--;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA1E8(); /* call 0x003BA1E8 */

loc_003BC1B3: ;
    /* cmp MEM8(eax), 0 - flags set for next jcc */
    MEM32(ebp + esi * 4 + -24) = eax;
    if (CMP_NE(MEM8(eax), 0)) { RECOMP_SLICE_POINT(); goto loc_003BC1A9; } /* jne: not equal / not zero */

loc_003BC1BC: ;
    edx = MEM32(0x3C1620);
    PUSH32(esp, 5);
    POP32(esp, eax);
    eax = eax - esi;
    /* test MEM8(edx), 1 - flags set for next jcc */
    ecx = ebp + esi * 4 + -24;
    PUSH32(esp, eax);
    PUSH32(esp, ecx);
    ecx = edi;
    if (TEST_Z(MEM8(edx), 1)) { g_seh_ebp = ebp; sub_003BC1DB(); return; } /* je: equal / zero */

loc_003BC1D4: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC157(); /* call 0x003BC157 */

loc_003BC1D9: ;
    g_seh_ebp = ebp; sub_003BC1E0(); return; /* tail jmp 0x003BC1E0 */

}

/**
 * sub_003BC1DB
 * Original: 0x003BC1DB - 0x003BC1E0 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC1DB(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC1DB: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBFF8(); /* call 0x003BBFF8 */

    g_seh_ebp = ebp; sub_003BC1E0(); return; /* restored dropped fall-through to sub_003BC1E0 */
}

/**
 * sub_003BC1E0
 * Original: 0x003BC1E0 - 0x003BC21F (63 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC1E0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC1E0: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

    eax = esi + 0xB8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC204: ;
    if (TEST_Z(MEM8(esi + 0xD), 4)) goto loc_003BC21B; /* je: equal / zero */

loc_003BC20A: ;
    eax = esi + 0xE8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC21B: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BC1E4
 * Original: 0x003BC1E4 - 0x003BC21F (59 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC1E4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC1E4: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;
    if (TEST_Z(MEM8(esi + 0xD), 2)) goto loc_003BC204; /* je: equal / zero */

loc_003BC1F3: ;
    eax = esi + 0xB8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC204: ;
    if (TEST_Z(MEM8(esi + 0xD), 4)) goto loc_003BC21B; /* je: equal / zero */

loc_003BC20A: ;
    eax = esi + 0xE8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC21B: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BC21F
 * Original: 0x003BC21F - 0x003BC252 (51 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC21F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC21F: ;
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = ecx;
    /* test MEM8(esi + 0xD), 1 - flags set for next jcc */
    ebp = MEM32(esi + 8);
    PUSH32(esp, edi);
    edi = edx;
    if (TEST_Z(MEM8(esi + 0xD), 1)) goto loc_003BC23D; /* je: equal / zero */

loc_003BC22F: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC239: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BC23D: ;
    eax = MEM32(esi + 0xC);
    if (TEST_Z(LO8(eax), 6)) { g_seh_ebp = ebp; sub_003BC252(); return; } /* je: equal / zero */

loc_003BC244: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xC000009Du);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC24D: ;
    g_seh_ebp = ebp; sub_003BC321(); return; /* tail jmp 0x003BC321 */

}

/**
 * sub_003BC252
 * Original: 0x003BC252 - 0x003BC321 (207 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC252(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC252: ;
    eax = eax | 0x1000;
    PUSH32(esp, ebx);
    MEM32(esi + 0xC) = eax;
    eax = MEM32(esi + 0x20);
    MEM32(esi + 0x6C) = edi;
    edi = esi + 0xB8;
    ebx = 0; /* xor self */
    MEM8(edi) = 0x18;
    MEM8(esi + 0xB9) = 5;
    MEM32(esi + 0xC0) = ebx;
    MEM32(esi + 0xC8) = eax;
    MEM32(esi + 0xCC) = 4;
    ecx = MEM32(ebp);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC292: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 3;
    edx = esi + 0x98;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFF0BDC0u;
    PUSH32(esp, eax);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC2B1: ;
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3BC706;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xC8) = ebx;
    MEM32(esi + 0xD0) = ebx;
    MEM32(esi + 0xCC) = ebx;
    MEM8(esi + 0xD4) = LO8(ebx);
    MEM8(esi + 0xD5) = LO8(ebx);
    MEM8(esi + 0xD6) = LO8(ebx);
    MEM8(esi + 0xE0) = 2;
    MEM8(esi + 0xE1) = 1;
    MEM16(esi + 0xE2) = LO16(ebx);
    SET_LO16(eax, ZX8(MEM8(ebp + 5)));
    MEM16(esi + 0xE4) = LO16(eax);
    MEM16(esi + 0xE6) = LO16(ebx);
    ecx = MEM32(ebp);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC320: ;
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003BC321(); return; /* restored dropped fall-through to sub_003BC321 */
}

/**
 * sub_003BC321
 * Original: 0x003BC321 - 0x003BC3A9 (136 bytes, 52 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC321(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC321: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 4; return; /* ret */

    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC33D: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BC341: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    eax = MEM32(esp + 0xC);
    eax = MEM32(eax + 4);
    if (CMP_GE(eax & eax, 0)) goto loc_003BC358; /* jge: greater or equal (signed >=) */

loc_003BC350: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC356: ;
    edi = eax;

loc_003BC358: ;
    /* cmp MEM32(esi + 0x5F), 0x53425355 - flags set for next jcc */
    eax = 0xC0000001u;
    if (CMP_EQ(MEM32(esi + 0x5F), 0x53425355)) goto loc_003BC368; /* je: equal / zero */

loc_003BC366: ;
    edi = eax;

loc_003BC368: ;
    ecx = MEM32(esi + 0x63);
    if (CMP_EQ(ecx, MEM32(esi + 0x44))) goto loc_003BC372; /* je: equal / zero */

loc_003BC370: ;
    edi = eax;

loc_003BC372: ;
    SET_LO8(ecx, MEM8(esi + 0x6B));
    if (CMP_NE(LO8(ecx), 2)) goto loc_003BC37C; /* jne: not equal / not zero */

loc_003BC37A: ;
    edi = eax;

loc_003BC37C: ;
    if (CMP_NE(LO8(ecx), 1)) goto loc_003BC386; /* jne: not equal / not zero */

loc_003BC381: ;
    edi = 0xC000003Eu;

loc_003BC386: ;
    eax = 0xC0000000u;
    ecx = edi;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003BC39E; /* jne: not equal / not zero */

loc_003BC393: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC39C: ;
    goto loc_003BC3A4;

loc_003BC39E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC3A4: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC325
 * Original: 0x003BC325 - 0x003BC3A9 (132 bytes, 48 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC325(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC325: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    edi = 0; /* xor self */
    if (TEST_Z(MEM8(esi + 0xD), 1)) goto loc_003BC341; /* je: equal / zero */

loc_003BC333: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC33D: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BC341: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    eax = MEM32(esp + 0xC);
    eax = MEM32(eax + 4);
    if (CMP_GE(eax & eax, 0)) goto loc_003BC358; /* jge: greater or equal (signed >=) */

loc_003BC350: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC356: ;
    edi = eax;

loc_003BC358: ;
    /* cmp MEM32(esi + 0x5F), 0x53425355 - flags set for next jcc */
    eax = 0xC0000001u;
    if (CMP_EQ(MEM32(esi + 0x5F), 0x53425355)) goto loc_003BC368; /* je: equal / zero */

loc_003BC366: ;
    edi = eax;

loc_003BC368: ;
    ecx = MEM32(esi + 0x63);
    if (CMP_EQ(ecx, MEM32(esi + 0x44))) goto loc_003BC372; /* je: equal / zero */

loc_003BC370: ;
    edi = eax;

loc_003BC372: ;
    SET_LO8(ecx, MEM8(esi + 0x6B));
    if (CMP_NE(LO8(ecx), 2)) goto loc_003BC37C; /* jne: not equal / not zero */

loc_003BC37A: ;
    edi = eax;

loc_003BC37C: ;
    if (CMP_NE(LO8(ecx), 1)) goto loc_003BC386; /* jne: not equal / not zero */

loc_003BC381: ;
    edi = 0xC000003Eu;

loc_003BC386: ;
    eax = 0xC0000000u;
    ecx = edi;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003BC39E; /* jne: not equal / not zero */

loc_003BC393: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC39C: ;
    goto loc_003BC3A4;

loc_003BC39E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC3A4: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC3A9
 * Original: 0x003BC3A9 - 0x003BC432 (137 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC3A9(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC3A9: ;
    PUSH32(esp, esi);
    esi = ecx;
    eax = MEM32(esi + 0x20);
    MEM32(esi + 0xC8) = eax;
    PUSH32(esp, edi);
    eax = esi + 0x5F;
    MEM32(esi + 0xD0) = eax;
    eax = ZX16(MEM16(esi + 0x34));
    PUSH32(esp, 0xFFFFFFFFu);
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    PUSH32(esp, 0xFFFE7960u);
    PUSH32(esp, edx);
    edi = esi + 0xB8;
    PUSH32(esp, eax);
    MEM8(edi) = 0x28;
    MEM8(esi + 0xB9) = 0x41;
    MEM32(esi + 0xC0) = 0x3BC325;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xCC) = 0xD;
    MEM8(esi + 0xD4) = 2;
    MEM8(esi + 0xD5) = 0;
    MEM8(esi + 0xD6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00336DC0(); /* call 0x00336DC0 */

loc_003BC411: ;
    ecx = esi + 0x98;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC424: ;
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC42F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BC432
 * Original: 0x003BC432 - 0x003BC52F (253 bytes, 80 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC432(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC432: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0xC);
    edx = 0x800;
    if (TEST_Z(edx, eax)) goto loc_003BC481; /* je: equal / zero */

loc_003BC443: ;
    eax = eax & 0xFFFFF7FFu;
    ecx = esi + 0xB8;
    /* cmp MEM32(esp + 8), ecx - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (CMP_NE(MEM32(esp + 8), ecx)) goto loc_003BC45F; /* jne: not equal / not zero */

loc_003BC457: ;
    ecx = MEM32(esi + 0xEC);
    goto loc_003BC465;

loc_003BC45F: ;
    ecx = MEM32(esi + 0xBC);

loc_003BC465: ;
    eax = eax & 0xFFFFF9FFu;
    PUSH32(esp, ecx);
    MEM32(esi + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC473: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC47C: ;
    goto loc_003BC52B;

loc_003BC481: ;
    ecx = MEM32(esp + 8);
    /* cmp MEM32(ecx + 4), 0 - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_L(MEM32(ecx + 4), 0)) goto loc_003BC4D5; /* jl: less (signed <) */

loc_003BC48C: ;
    if (TEST_NZ(LO8(eax), 6)) goto loc_003BC4D5; /* jne: not equal / not zero */

loc_003BC490: ;
    edx = MEM32(esi + 0x6C);
    if (CMP_AE(edx, MEM32(esi + 0x2C))) goto loc_003BC4A4; /* jae: above or equal (unsigned >=) */

loc_003BC498: ;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC52F(); /* call 0x003BC52F */

loc_003BC49F: ;
    goto loc_003BC52A;

loc_003BC4A4: ;
    edi = esi + 0xB8;
    /* cmp ecx, edi - flags set for next jcc */
    edx = 0x200;
    if (CMP_NE(ecx, edi)) goto loc_003BC4BD; /* jne: not equal / not zero */

loc_003BC4B3: ;
    eax = eax & 0xFFFFFDFFu;
    /* test HI8(eax), 4 - flags set for next jcc */
    goto loc_003BC4C4;

loc_003BC4BD: ;
    eax = eax & 0xFFFFFBFFu;
    /* test edx, eax - flags set for next jcc */

loc_003BC4C4: ;
    MEM32(esi + 0xC) = eax;
    if (TEST_NZ(edx, eax)) goto loc_003BC52A; /* jne: not equal / not zero */

loc_003BC4C9: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) | edx;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC3A9(); /* call 0x003BC3A9 */

loc_003BC4D3: ;
    goto loc_003BC52A;

loc_003BC4D5: ;
    edi = esi + 0xB8;
    if (CMP_NE(ecx, edi)) goto loc_003BC504; /* jne: not equal / not zero */

loc_003BC4DF: ;
    eax = eax & 0xFFFFFDFFu;
    /* test HI8(eax), 4 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_Z(HI8(eax), 4)) goto loc_003BC519; /* je: equal / zero */

loc_003BC4EC: ;
    eax = eax | edx;
    MEM32(esi + 0xC) = eax;
    eax = esi + 0xE8;
    PUSH32(esp, eax);

loc_003BC4F8: ;
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC502: ;
    goto loc_003BC52A;

loc_003BC504: ;
    eax = eax & 0xFFFFFBFFu;
    /* test HI8(eax), 2 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_Z(HI8(eax), 2)) goto loc_003BC519; /* je: equal / zero */

loc_003BC511: ;
    eax = eax | edx;
    MEM32(esi + 0xC) = eax;
    PUSH32(esp, edi);
    { RECOMP_SLICE_POINT(); goto loc_003BC4F8; }

loc_003BC519: ;
    PUSH32(esp, MEM32(ecx + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC521: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC52A: ;
    POP32(esp, edi);

loc_003BC52B: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC52F
 * Original: 0x003BC52F - 0x003BC550 (33 bytes, 16 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC52F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BC52F: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    SET_LO8(eax, MEM8(edi + 0x37));
    esi = ecx;
    SET_LO8(ecx, LO8(eax));
    SET_LO8(ecx, LO8(ecx) & 3);
    if (CMP_NE(LO8(ecx), 1)) { g_seh_ebp = ebp; sub_003BC550(); return; } /* jne: not equal / not zero */

loc_003BC547: ;
    ebx = MEM32(edi + 0x20);
    MEM8(ebp + -1) = 2;
    g_seh_ebp = ebp; sub_003BC557(); return; /* tail jmp 0x003BC557 */

}

/**
 * sub_003BC550
 * Original: 0x003BC550 - 0x003BC557 (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC550(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC550: ;
    ebx = MEM32(edi + 0x24);
    MEM8(ebp + -1) = 1;

    g_seh_ebp = ebp; sub_003BC557(); return; /* restored dropped fall-through to sub_003BC557 */
}

/**
 * sub_003BC557
 * Original: 0x003BC557 - 0x003BC65D (262 bytes, 88 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC557(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC557: ;
    /* test LO8(eax), 4 - flags set for next jcc */
    edx = MEM32(edi + 0x6C);
    if (TEST_Z(LO8(eax), 4)) goto loc_003BC586; /* je: equal / zero */

loc_003BC55E: ;
    ecx = MEM32(edi + 0x38);
    if (CMP_AE(edx, ecx)) goto loc_003BC56D; /* jae: above or equal (unsigned >=) */

loc_003BC565: ;
    eax = edx + 0xF273D4;
    goto loc_003BC58B;

loc_003BC56D: ;
    eax = MEM32(edi + 0x3C);
    if (CMP_AE(edx, eax)) goto loc_003BC57B; /* jae: above or equal (unsigned >=) */

loc_003BC574: ;
    eax = MEM32(edi + 0x28);
    eax = eax - ecx;
    goto loc_003BC589;

loc_003BC57B: ;
    ecx = ecx - eax;
    eax = ecx + edx + 0xF273D4;
    goto loc_003BC58B;

loc_003BC586: ;
    eax = MEM32(edi + 0x28);

loc_003BC589: ;
    eax = eax + edx;

loc_003BC58B: ;
    ecx = MEM32(edi + 0x2C);
    ecx = ecx - edx;
    if (CMP_BE(ecx, 0x400)) goto loc_003BC59D; /* jbe: below or equal (unsigned <=) */

loc_003BC598: ;
    ecx = 0x400;

loc_003BC59D: ;
    edx = edx + ecx;
    MEM32(edi + 0x6C) = edx;
    MEM32(esi + 0x18) = eax;
    SET_LO8(eax, MEM8(ebp + -1));
    edx = edi + 0x98;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    MEM32(esi + 0x14) = ecx;
    MEM8(esi + 0x1C) = LO8(eax);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFE91CA0u;
    PUSH32(esp, eax);
    eax = edi + 0x70;
    PUSH32(esp, eax);
    MEM8(esi) = 0x28;
    MEM8(esi + 1) = 0x41;
    MEM32(esi + 8) = 0x3BC432;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = ebx;
    MEM8(esi + 0x1D) = 0;
    MEM8(esi + 0x1E) = 0;
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC5E5: ;
    eax = MEM32(edi + 8);
    ecx = MEM32(eax);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC5F0: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

    if (TEST_NZ(MEM8(esi + 0xC), 6)) goto loc_003BC644; /* jne: not equal / not zero */

loc_003BC60B: ;
    if (CMP_EQ(MEM32(esi + 0x28), ecx)) goto loc_003BC63B; /* je: equal / zero */

loc_003BC610: ;
    MEM32(esi + 0x6C) = ecx;
    ecx = esi + 0xB8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC52F(); /* call 0x003BC52F */

loc_003BC620: ;
    eax = MEM32(esi + 0x6C);
    if (CMP_AE(eax, MEM32(esi + 0x2C))) goto loc_003BC659; /* jae: above or equal (unsigned >=) */

loc_003BC628: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 4;
    ecx = esi + 0xE8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC52F(); /* call 0x003BC52F */

loc_003BC639: ;
    goto loc_003BC659;

loc_003BC63B: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC3A9(); /* call 0x003BC3A9 */

loc_003BC642: ;
    goto loc_003BC659;

loc_003BC644: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC650: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC659: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC5F5
 * Original: 0x003BC5F5 - 0x003BC65D (104 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC5F5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC5F5: ;
    eax = MEM32(esp + 4);
    ecx = 0; /* xor self */
    /* cmp MEM32(eax + 4), ecx - flags set for next jcc */
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    if (CMP_L(MEM32(eax + 4), ecx)) goto loc_003BC644; /* jl: less (signed <) */

loc_003BC605: ;
    if (TEST_NZ(MEM8(esi + 0xC), 6)) goto loc_003BC644; /* jne: not equal / not zero */

loc_003BC60B: ;
    if (CMP_EQ(MEM32(esi + 0x28), ecx)) goto loc_003BC63B; /* je: equal / zero */

loc_003BC610: ;
    MEM32(esi + 0x6C) = ecx;
    ecx = esi + 0xB8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC52F(); /* call 0x003BC52F */

loc_003BC620: ;
    eax = MEM32(esi + 0x6C);
    if (CMP_AE(eax, MEM32(esi + 0x2C))) goto loc_003BC659; /* jae: above or equal (unsigned >=) */

loc_003BC628: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 4;
    ecx = esi + 0xE8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC52F(); /* call 0x003BC52F */

loc_003BC639: ;
    goto loc_003BC659;

loc_003BC63B: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC3A9(); /* call 0x003BC3A9 */

loc_003BC642: ;
    goto loc_003BC659;

loc_003BC644: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBD45(); /* call 0x003BBD45 */

loc_003BC650: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC21F(); /* call 0x003BC21F */

loc_003BC659: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC65D
 * Original: 0x003BC65D - 0x003BC706 (169 bytes, 44 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC65D(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC65D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    esi = ecx;
    PUSH32(esp, edi);
    edi = esi + 0x40;
    MEM32(edi) = 0x43425355;
    eax = MEM32(esi + 0x10);
    MEM32(edi + 4) = eax;
    eax = MEM32(esi + 0x2C);
    MEM32(edi + 8) = eax;
    SET_LO8(eax, MEM8(esi + 0x37));
    SET_LO8(eax, LO8(eax) << 7);
    edx = esi + 0x98;
    PUSH32(esp, edx);
    MEM8(edi + 0xC) = LO8(eax);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFF3CB00u;
    PUSH32(esp, eax);
    eax = esi + 0x70;
    MEM8(edi + 0xD) = 0;
    MEM8(edi + 0xE) = 0xA;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 1;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC6A6: ;
    ecx = MEM32(esi + 0x24);
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 2;
    eax = esi + 0xB8;
    MEM8(eax) = 0x28;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    MEM8(esi + 0xB9) = 0x41;
    MEM32(esi + 0xC0) = 0x3BC5F5;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xC8) = ecx;
    MEM32(esi + 0xD0) = edi;
    MEM32(esi + 0xCC) = 0x1F;
    MEM8(esi + 0xD4) = 1;
    MEM8(esi + 0xD5) = 0;
    MEM8(esi + 0xD6) = 0;
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC703: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BC706
 * Original: 0x003BC706 - 0x003BC906 (512 bytes, 120 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC706(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC706: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    eax = MEM32(esi + 0xC);
    ebx = MEM32(esi + 8);
    PUSH32(esp, edi);
    edi = eax;
    eax = eax & 0xFFFFFDFFu;
    edi = edi & 0x7000;
    /* test HI8(eax), 1 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_Z(HI8(eax), 1)) goto loc_003BC736; /* je: equal / zero */

loc_003BC728: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC732: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BC736: ;
    eax = MEM32(esi + 0xC);
    if (TEST_Z(LO8(eax), 6)) goto loc_003BC744; /* je: equal / zero */

loc_003BC73D: ;
    PUSH32(esp, 0xC000009Du);
    goto loc_003BC7A5;

loc_003BC744: ;
    edx = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_GE(MEM32(edx + 4), ecx)) goto loc_003BC760; /* jge: greater or equal (signed >=) */

loc_003BC74F: ;
    eax = eax & 0xFFFF8FFFu;
    MEM32(esi + 0xC) = eax;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BC75E: ;
    { RECOMP_SLICE_POINT(); goto loc_003BC73D; }

loc_003BC760: ;
    if (CMP_EQ(edi, 0x1000)) goto loc_003BC82F; /* je: equal / zero */

loc_003BC76C: ;
    if (CMP_EQ(edi, 0x2000)) goto loc_003BC7AE; /* je: equal / zero */

loc_003BC774: ;
    if (CMP_NE(edi, 0x4000)) goto loc_003BC900; /* jne: not equal / not zero */

loc_003BC780: ;
    eax = eax & 0xFFFFBFFFu;
    MEM32(esi + 0xC) = eax;
    SET_LO8(eax, MEM8(esi + 0x36));
    SET_LO8(ecx, LO8(eax));
    SET_LO8(ecx, LO8(ecx) - 1);
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    MEM8(esi + 0x36) = LO8(ecx);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BC7A2; /* je: equal / zero */

loc_003BC796: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC65D(); /* call 0x003BC65D */

loc_003BC79D: ;
    goto loc_003BC900;

loc_003BC7A2: ;
    PUSH32(esp, MEM32(esi + 0x6C));

loc_003BC7A5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC7A9: ;
    goto loc_003BC900;

loc_003BC7AE: ;
    eax = eax & 0xFFFFDFFFu;
    eax = eax | 0x4000;
    edi = esi + 0xB8;
    MEM32(esi + 0xC) = eax;
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3BC706;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xC8) = ecx;
    MEM32(esi + 0xD0) = ecx;
    MEM32(esi + 0xCC) = ecx;
    MEM8(esi + 0xD4) = 1;
    MEM8(esi + 0xD5) = 0;
    MEM8(esi + 0xD6) = 0;
    MEM8(esi + 0xE0) = 0x21;
    MEM8(esi + 0xE1) = 0xFF;
    MEM16(esi + 0xE2) = LO16(ecx);
    SET_LO16(eax, ZX8(MEM8(ebx + 4)));
    MEM16(esi + 0xE4) = LO16(eax);
    MEM16(esi + 0xE6) = LO16(ecx);
    goto loc_003BC8D5;

loc_003BC82F: ;
    eax = eax & 0xFFFFEFFFu;
    eax = eax | 0x2000;
    MEM32(esi + 0xC) = eax;
    eax = MEM32(esi + 0x24);
    edi = esi + 0xB8;
    MEM8(edi) = 0x18;
    MEM8(esi + 0xB9) = 5;
    MEM32(esi + 0xC0) = ecx;
    MEM32(esi + 0xC8) = eax;
    MEM32(esi + 0xCC) = 4;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC86D: ;
    eax = 0; /* xor self */
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3BC706;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xC8) = eax;
    MEM32(esi + 0xD0) = eax;
    MEM32(esi + 0xCC) = eax;
    MEM8(esi + 0xD4) = LO8(eax);
    MEM8(esi + 0xD5) = LO8(eax);
    MEM8(esi + 0xD6) = LO8(eax);
    MEM8(esi + 0xE0) = 2;
    MEM8(esi + 0xE1) = 1;
    MEM16(esi + 0xE2) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(ebx + 6)));
    MEM16(esi + 0xE4) = LO16(ecx);
    MEM16(esi + 0xE6) = LO16(eax);

loc_003BC8D5: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 3;
    edx = esi + 0x98;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edx);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFF0BDC0u;
    PUSH32(esp, eax);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC8F4: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 2;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BC900: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BC906
 * Original: 0x003BC906 - 0x003BC923 (29 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC906(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC906: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC910: ;
    /* test MEM8(esi + 0xC), 6 - flags set for next jcc */
    SET_LO8(ebx, LO8(eax));
    if (TEST_Z(MEM8(esi + 0xC), 6)) { g_seh_ebp = ebp; sub_003BC923(); return; } /* je: equal / zero */

loc_003BC918: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xC000009Du);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC921: ;
    g_seh_ebp = ebp; sub_003BC92A(); return; /* tail jmp 0x003BC92A */

}

/**
 * sub_003BC923
 * Original: 0x003BC923 - 0x003BC92A (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC923(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC923: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC65D(); /* call 0x003BC65D */

    g_seh_ebp = ebp; sub_003BC92A(); return; /* restored dropped fall-through to sub_003BC92A */
}

/**
 * sub_003BC92A
 * Original: 0x003BC92A - 0x003BC934 (10 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC92A(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC92A: ;
    POP32(esp, esi);
    SET_LO8(ecx, LO8(ebx));
    POP32(esp, ebx);
    g_seh_ebp = ebp; RECOMP_ITAIL(MEM32(0x3C15E4)); return; /* indirect tail jmp */

}

/**
 * sub_003BC934
 * Original: 0x003BC934 - 0x003BC94F (27 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC934(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC934: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A548);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFD050F80u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BC94E: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BC94F
 * Original: 0x003BC94F - 0x003BC960 (17 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC94F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC94F: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, 0xF2A4E8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BC95D: ;
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BC960
 * Original: 0x003BC960 - 0x003BC983 (35 bytes, 12 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC960(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC960: ;
    PUSH32(esp, esi);
    esi = ecx;
    ecx = MEM32(esi);
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BC96C: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BC973: ;
    MEM32(esi) = MEM32(esi) & 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BC983
 * Original: 0x003BC983 - 0x003BC9ED (106 bytes, 42 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC983(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BC983: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebx = 0; /* xor self */
    ebp = 0; /* xor self */
    /* cmp MEM16(0xF2A4C8), LO16(ebx) - flags set for next jcc */
    PUSH32(esp, edi);
    MEM32(esp + 0xC) = edx;
    edi = ecx;
    if (CMP_BE(MEM16(0xF2A4C8), LO16(ebx))) goto loc_003BC9E6; /* jbe: below or equal (unsigned <=) */

loc_003BC99A: ;
    PUSH32(esp, esi);

loc_003BC99B: ;
    eax = MEM32(0xF2A4CC);
    esi = ZX8(LO8(ebx));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x16);
    eax = eax + esi;
    if (TEST_Z(MEM8(eax + 4), 1)) goto loc_003BC9D6; /* je: equal / zero */

loc_003BC9AE: ;
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE2D(); /* call 0x003BBE2D */

loc_003BC9B5: ;
    if (CMP_NE(eax, MEM32(esp + 0x10))) goto loc_003BC9D6; /* jne: not equal / not zero */

loc_003BC9BB: ;
    eax = MEM32(0xF2A4CC);
    eax = eax + esi;
    if (CMP_NE(MEM32(eax + 0xE), edi)) goto loc_003BC9D6; /* jne: not equal / not zero */

loc_003BC9C7: ;
    SET_LO8(ecx, MEM8(eax + 4));
    if (TEST_Z(LO8(ecx), 8)) goto loc_003BC9D6; /* je: equal / zero */

loc_003BC9CF: ;
    if (TEST_NZ(LO8(ecx), 2)) goto loc_003BC9D6; /* jne: not equal / not zero */

loc_003BC9D4: ;
    ebp = eax;

loc_003BC9D6: ;
    SET_LO8(ebx, LO8(ebx) + 1);
    SET_LO16(eax, ZX8(LO8(ebx)));
    if (CMP_B(LO16(eax), MEM16(0xF2A4C8))) { RECOMP_SLICE_POINT(); goto loc_003BC99B; } /* jb: below (unsigned <) */

loc_003BC9E5: ;
    POP32(esp, esi);

loc_003BC9E6: ;
    POP32(esp, edi);
    eax = ebp;
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BC9ED
 * Original: 0x003BC9ED - 0x003BCA98 (171 bytes, 62 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BC9ED(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BC9ED: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    MEM32(esi + 0x5A) = MEM32(esi + 0x5A) & 0;
    PUSH32(esp, edi);
    edi = MEM32(esi);
    ebx = esi + 0x52;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0x53) = 0x82;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    MEM32(ebp + -4) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCA11: ;
    if (TEST_S(eax, eax)) goto loc_003BCA93; /* jl: less (signed <) */

loc_003BCA15: ;
    MEM8(esi + 0xA2) = MEM8(esi + 0xA2) | 2;
    MEM32(esi + 0x5A) = MEM32(esi + 0x5A) & 0;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0x53) = 2;
    SET_LO8(eax, MEM8(edi + 8));
    MEM8(esi + 0x67) = LO8(eax);
    eax = MEM32(ebp + -4);
    MEM8(esi + 0x68) = 3;
    SET_LO8(eax, MEM8(eax + 1));
    MEM8(esi + 0x69) = LO8(eax);
    MEM16(esi + 0x6E) = 0x20;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCA48: ;
    if (TEST_S(eax, eax)) goto loc_003BCA93; /* jl: less (signed <) */

loc_003BCA4C: ;
    ecx = MEM32(esi + 0x62);
    MEM32(esi + 0xC) = ecx;
    ecx = MEM32(ebp + -4);
    if (TEST_Z(MEM8(ecx), 2)) goto loc_003BCA93; /* je: equal / zero */

loc_003BCA5A: ;
    if (CMP_EQ(MEM8(edi + 9), 0)) goto loc_003BCA93; /* je: equal / zero */

loc_003BCA60: ;
    MEM32(esi + 0x5A) = MEM32(esi + 0x5A) & 0;
    MEM8(ebx) = 0x20;
    MEM8(esi + 0x53) = 2;
    SET_LO8(eax, MEM8(edi + 9));
    MEM8(esi + 0x67) = LO8(eax);
    MEM8(esi + 0x68) = 3;
    SET_LO8(eax, MEM8(ecx + 2));
    MEM8(esi + 0x69) = LO8(eax);
    MEM16(esi + 0x6E) = 0x20;
    ecx = MEM32(edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCA89: ;
    if (TEST_S(eax, eax)) goto loc_003BCA93; /* jl: less (signed <) */

loc_003BCA8D: ;
    ecx = MEM32(esi + 0x62);
    MEM32(esi + 0x10) = ecx;

loc_003BCA93: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BCA98
 * Original: 0x003BCA98 - 0x003BCAC9 (49 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCA98(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCA98: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    /* test MEM8(esi + 0xA2), 2 - flags set for next jcc */
    eax = MEM32(esi);
    ecx = MEM32(eax);
    PUSH32(esp, edi);
    if (TEST_Z(MEM8(esi + 0xA2), 2)) { g_seh_ebp = ebp; sub_003BCAC9(); return; } /* je: equal / zero */

loc_003BCAAB: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0xC3;
    MEM32(eax + 8) = 0x3BCA98;
    MEM32(eax + 0xC) = esi;
    MEM8(esi + 0xA2) = MEM8(esi + 0xA2) & 0xFD;
    g_seh_ebp = ebp; sub_003BCB13(); return; /* tail jmp 0x003BCB13 */

}

/**
 * sub_003BCAC9
 * Original: 0x003BCAC9 - 0x003BCB13 (74 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCAC9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCAC9: ;
    edi = 0; /* xor self */
    if (CMP_EQ(MEM32(esi + 0xC), edi)) goto loc_003BCAF0; /* je: equal / zero */

loc_003BCAD0: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 8) = 0x3BCA98;
    MEM32(eax + 0xC) = esi;
    edx = MEM32(esi + 0xC);
    MEM32(eax + 0x10) = edx;
    MEM32(esi + 0xC) = edi;
    g_seh_ebp = ebp; sub_003BCB13(); return; /* tail jmp 0x003BCB13 */

loc_003BCAF0: ;
    if (CMP_EQ(MEM32(esi + 0x10), edi)) { g_seh_ebp = ebp; sub_003BCB1B(); return; } /* je: equal / zero */

loc_003BCAF5: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 8) = 0x3BCA98;
    MEM32(eax + 0xC) = esi;
    edx = MEM32(esi + 0x10);
    MEM32(eax + 0x10) = edx;
    MEM32(esi + 0x10) = edi;

    g_seh_ebp = ebp; sub_003BCB13(); return; /* restored dropped fall-through to sub_003BCB13 */
}

/**
 * sub_003BCB13
 * Original: 0x003BCB13 - 0x003BCD05 (498 bytes, 181 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCB13(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCB13: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCB19: ;
    goto loc_003BCB44;

    MEM32(eax + 0x12) = edi;
    MEM32(esi) = edi;
    if (TEST_Z(MEM8(eax + 4), 2)) goto loc_003BCB2D; /* je: equal / zero */

loc_003BCB26: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC960(); /* call 0x003BC960 */

loc_003BCB2D: ;
    if (TEST_Z(MEM8(esi + 0xA2), 1)) goto loc_003BCB44; /* je: equal / zero */

loc_003BCB36: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(esi + 0x9E));
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB44: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    SET_LO8(eax, MEM8(edi + 4));
    if (TEST_NZ(LO8(eax), 2)) goto loc_003BCBA1; /* jne: not equal / not zero */

loc_003BCB61: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ecx)) goto loc_003BCBA6; /* jl: less (signed <) */

loc_003BCB6D: ;
    SET_LO8(eax, LO8(eax) & 0xF);
    MEM8(edi + 4) = LO8(eax);
    eax = MEM32(edi + 0xE);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB7A: ;
    MEM8(ebx + 0xA2) = MEM8(ebx + 0xA2) | 0x10;
    MEM32(ebx + 8) = MEM32(ebx + 8) + 1;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    eax = ZX8(MEM8(edi + 0xC));
    MEM32(esi + 0x14) = eax;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003BCBA0; /* je: equal / zero */

loc_003BCB98: ;
    ecx = MEM32(edi);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCBA0: ;
    POP32(esp, esi);

loc_003BCBA1: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003BCBA6: ;
    MEM32(esi + 0x10) = ecx;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x14) = ecx;
    MEM16(esi + 0x2A) = LO16(ecx);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BCC05;
    MEM32(esi + 0xC) = ebx;
    MEM8(esi + 0x1C) = 0;
    MEM8(esi + 0x1D) = 0;
    MEM8(esi + 0x1E) = 0;
    MEM8(esi + 0x28) = 2;
    MEM8(esi + 0x29) = 1;
    SET_LO16(eax, ZX8(MEM8(edi + 8)));
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    SET_LO8(ecx, MEM8(edi + 4));
    SET_LO8(eax, LO8(ecx));
    SET_LO8(eax, LO8(eax) & 0xF0);
    SET_LO8(eax, LO8(eax) + 0x10);
    SET_LO8(ecx, LO8(ecx) & 0xF);
    SET_LO8(eax, LO8(eax) ^ LO8(ecx));
    MEM8(edi + 4) = LO8(eax);
    SET_LO8(eax, LO8(eax) & 0xF0);
    if (CMP_NE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003BCB98; } /* jne: not equal / not zero */

loc_003BCBFC: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC03: ;
    { RECOMP_SLICE_POINT(); goto loc_003BCBA0; }

    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ebx = MEM32(esi);
    if (TEST_NZ(MEM8(ebx + 4), 2)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC13: ;
    if (TEST_NZ(MEM8(esi + 0xA2), 1)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC1C: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    if (CMP_L(MEM32(edi + 4), 0)) goto loc_003BCC82; /* jl: less (signed <) */

loc_003BCC27: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0;
    MEM8(edi) = 0x18;
    MEM8(edi + 1) = 5;
    eax = MEM32(esi + 0xC);
    MEM32(edi + 0x10) = eax;
    MEM32(edi + 0x14) = 4;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC47: ;
    eax = MEM32(esi + 0xC);
    MEM32(esi + 0x62) = eax;
    eax = esi + 0x32;
    MEM8(esi + 0x52) = 0x28;
    MEM8(esi + 0x53) = 0x41;
    MEM32(esi + 0x5A) = 0x3BCB49;
    MEM32(esi + 0x5E) = esi;
    MEM32(esi + 0x6A) = eax;
    eax = ZX8(MEM8(ebx + 0xC));
    MEM32(esi + 0x66) = eax;
    MEM8(esi + 0x6E) = 2;
    MEM8(esi + 0x6F) = 1;
    MEM8(esi + 0x70) = 0;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC80: ;
    goto loc_003BCC89;

loc_003BCC82: ;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC89: ;
    POP32(esp, edi);

loc_003BCC8A: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    PUSH32(esp, esi);
    ecx = ecx + 0xFFFFFFFEu;
    PUSH32(esp, edi);
    esi = eax + 0x34;
    eax = ecx;
    ecx = ecx >> 2;
    edi = edx;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    PUSH32(esp, 8);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    POP32(esp, ecx);
    POP32(esp, edi);
    eax = edx + 2;
    POP32(esp, esi);

loc_003BCCBF: ;
    if (CMP_AE(MEM8(eax), 0x20)) goto loc_003BCCC9; /* jae: above or equal (unsigned >=) */

loc_003BCCC4: ;
    MEM8(eax) = 0;
    goto loc_003BCCCC;

loc_003BCCC9: ;
    ebx = 0; /* xor self */
    ebx++;

loc_003BCCCC: ;
    eax++;
    ecx--;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003BCCBF; } /* jne: not equal / not zero */

loc_003BCCD0: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BCCD9; /* jne: not equal / not zero */

loc_003BCCD4: ;
    if (TEST_Z(MEM8(edx), 0x3F)) goto loc_003BCCDF; /* je: equal / zero */

loc_003BCCD9: ;
    POP32(esp, ebx);
    g_seh_ebp = ebp; sub_002BFDA6(); return; /* tail jmp 0x002BFDA6 */

loc_003BCCDF: ;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BCB1B
 * Original: 0x003BCB1B - 0x003BCD05 (490 bytes, 178 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCB1B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCB1B: ;
    MEM32(eax + 0x12) = edi;
    MEM32(esi) = edi;
    if (TEST_Z(MEM8(eax + 4), 2)) goto loc_003BCB2D; /* je: equal / zero */

loc_003BCB26: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC960(); /* call 0x003BC960 */

loc_003BCB2D: ;
    if (TEST_Z(MEM8(esi + 0xA2), 1)) goto loc_003BCB44; /* je: equal / zero */

loc_003BCB36: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(esi + 0x9E));
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB44: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    SET_LO8(eax, MEM8(edi + 4));
    if (TEST_NZ(LO8(eax), 2)) goto loc_003BCBA1; /* jne: not equal / not zero */

loc_003BCB61: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ecx)) goto loc_003BCBA6; /* jl: less (signed <) */

loc_003BCB6D: ;
    SET_LO8(eax, LO8(eax) & 0xF);
    MEM8(edi + 4) = LO8(eax);
    eax = MEM32(edi + 0xE);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB7A: ;
    MEM8(ebx + 0xA2) = MEM8(ebx + 0xA2) | 0x10;
    MEM32(ebx + 8) = MEM32(ebx + 8) + 1;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    eax = ZX8(MEM8(edi + 0xC));
    MEM32(esi + 0x14) = eax;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003BCBA0; /* je: equal / zero */

loc_003BCB98: ;
    ecx = MEM32(edi);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCBA0: ;
    POP32(esp, esi);

loc_003BCBA1: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003BCBA6: ;
    MEM32(esi + 0x10) = ecx;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x14) = ecx;
    MEM16(esi + 0x2A) = LO16(ecx);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BCC05;
    MEM32(esi + 0xC) = ebx;
    MEM8(esi + 0x1C) = 0;
    MEM8(esi + 0x1D) = 0;
    MEM8(esi + 0x1E) = 0;
    MEM8(esi + 0x28) = 2;
    MEM8(esi + 0x29) = 1;
    SET_LO16(eax, ZX8(MEM8(edi + 8)));
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    SET_LO8(ecx, MEM8(edi + 4));
    SET_LO8(eax, LO8(ecx));
    SET_LO8(eax, LO8(eax) & 0xF0);
    SET_LO8(eax, LO8(eax) + 0x10);
    SET_LO8(ecx, LO8(ecx) & 0xF);
    SET_LO8(eax, LO8(eax) ^ LO8(ecx));
    MEM8(edi + 4) = LO8(eax);
    SET_LO8(eax, LO8(eax) & 0xF0);
    if (CMP_NE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003BCB98; } /* jne: not equal / not zero */

loc_003BCBFC: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC03: ;
    { RECOMP_SLICE_POINT(); goto loc_003BCBA0; }

    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ebx = MEM32(esi);
    if (TEST_NZ(MEM8(ebx + 4), 2)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC13: ;
    if (TEST_NZ(MEM8(esi + 0xA2), 1)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC1C: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    if (CMP_L(MEM32(edi + 4), 0)) goto loc_003BCC82; /* jl: less (signed <) */

loc_003BCC27: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0;
    MEM8(edi) = 0x18;
    MEM8(edi + 1) = 5;
    eax = MEM32(esi + 0xC);
    MEM32(edi + 0x10) = eax;
    MEM32(edi + 0x14) = 4;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC47: ;
    eax = MEM32(esi + 0xC);
    MEM32(esi + 0x62) = eax;
    eax = esi + 0x32;
    MEM8(esi + 0x52) = 0x28;
    MEM8(esi + 0x53) = 0x41;
    MEM32(esi + 0x5A) = 0x3BCB49;
    MEM32(esi + 0x5E) = esi;
    MEM32(esi + 0x6A) = eax;
    eax = ZX8(MEM8(ebx + 0xC));
    MEM32(esi + 0x66) = eax;
    MEM8(esi + 0x6E) = 2;
    MEM8(esi + 0x6F) = 1;
    MEM8(esi + 0x70) = 0;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC80: ;
    goto loc_003BCC89;

loc_003BCC82: ;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC89: ;
    POP32(esp, edi);

loc_003BCC8A: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    PUSH32(esp, esi);
    ecx = ecx + 0xFFFFFFFEu;
    PUSH32(esp, edi);
    esi = eax + 0x34;
    eax = ecx;
    ecx = ecx >> 2;
    edi = edx;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    PUSH32(esp, 8);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    POP32(esp, ecx);
    POP32(esp, edi);
    eax = edx + 2;
    POP32(esp, esi);

loc_003BCCBF: ;
    if (CMP_AE(MEM8(eax), 0x20)) goto loc_003BCCC9; /* jae: above or equal (unsigned >=) */

loc_003BCCC4: ;
    MEM8(eax) = 0;
    goto loc_003BCCCC;

loc_003BCCC9: ;
    ebx = 0; /* xor self */
    ebx++;

loc_003BCCCC: ;
    eax++;
    ecx--;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003BCCBF; } /* jne: not equal / not zero */

loc_003BCCD0: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BCCD9; /* jne: not equal / not zero */

loc_003BCCD4: ;
    if (TEST_Z(MEM8(edx), 0x3F)) goto loc_003BCCDF; /* je: equal / zero */

loc_003BCCD9: ;
    POP32(esp, ebx);
    g_seh_ebp = ebp; sub_002BFDA6(); return; /* tail jmp 0x002BFDA6 */

loc_003BCCDF: ;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BCB49
 * Original: 0x003BCB49 - 0x003BCD05 (444 bytes, 163 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCB49(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCB49: ;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0xC);
    /* test MEM8(ebx + 0xA2), 1 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = MEM32(ebx);
    if (TEST_NZ(MEM8(ebx + 0xA2), 1)) goto loc_003BCBA1; /* jne: not equal / not zero */

loc_003BCB5A: ;
    SET_LO8(eax, MEM8(edi + 4));
    if (TEST_NZ(LO8(eax), 2)) goto loc_003BCBA1; /* jne: not equal / not zero */

loc_003BCB61: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ecx)) goto loc_003BCBA6; /* jl: less (signed <) */

loc_003BCB6D: ;
    SET_LO8(eax, LO8(eax) & 0xF);
    MEM8(edi + 4) = LO8(eax);
    eax = MEM32(edi + 0xE);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB7A: ;
    MEM8(ebx + 0xA2) = MEM8(ebx + 0xA2) | 0x10;
    MEM32(ebx + 8) = MEM32(ebx + 8) + 1;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    eax = ZX8(MEM8(edi + 0xC));
    MEM32(esi + 0x14) = eax;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003BCBA0; /* je: equal / zero */

loc_003BCB98: ;
    ecx = MEM32(edi);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCBA0: ;
    POP32(esp, esi);

loc_003BCBA1: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003BCBA6: ;
    MEM32(esi + 0x10) = ecx;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x14) = ecx;
    MEM16(esi + 0x2A) = LO16(ecx);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BCC05;
    MEM32(esi + 0xC) = ebx;
    MEM8(esi + 0x1C) = 0;
    MEM8(esi + 0x1D) = 0;
    MEM8(esi + 0x1E) = 0;
    MEM8(esi + 0x28) = 2;
    MEM8(esi + 0x29) = 1;
    SET_LO16(eax, ZX8(MEM8(edi + 8)));
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    SET_LO8(ecx, MEM8(edi + 4));
    SET_LO8(eax, LO8(ecx));
    SET_LO8(eax, LO8(eax) & 0xF0);
    SET_LO8(eax, LO8(eax) + 0x10);
    SET_LO8(ecx, LO8(ecx) & 0xF);
    SET_LO8(eax, LO8(eax) ^ LO8(ecx));
    MEM8(edi + 4) = LO8(eax);
    SET_LO8(eax, LO8(eax) & 0xF0);
    if (CMP_NE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003BCB98; } /* jne: not equal / not zero */

loc_003BCBFC: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC03: ;
    { RECOMP_SLICE_POINT(); goto loc_003BCBA0; }

    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ebx = MEM32(esi);
    if (TEST_NZ(MEM8(ebx + 4), 2)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC13: ;
    if (TEST_NZ(MEM8(esi + 0xA2), 1)) goto loc_003BCC8A; /* jne: not equal / not zero */

loc_003BCC1C: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    if (CMP_L(MEM32(edi + 4), 0)) goto loc_003BCC82; /* jl: less (signed <) */

loc_003BCC27: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0;
    MEM8(edi) = 0x18;
    MEM8(edi + 1) = 5;
    eax = MEM32(esi + 0xC);
    MEM32(edi + 0x10) = eax;
    MEM32(edi + 0x14) = 4;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC47: ;
    eax = MEM32(esi + 0xC);
    MEM32(esi + 0x62) = eax;
    eax = esi + 0x32;
    MEM8(esi + 0x52) = 0x28;
    MEM8(esi + 0x53) = 0x41;
    MEM32(esi + 0x5A) = 0x3BCB49;
    MEM32(esi + 0x5E) = esi;
    MEM32(esi + 0x6A) = eax;
    eax = ZX8(MEM8(ebx + 0xC));
    MEM32(esi + 0x66) = eax;
    MEM8(esi + 0x6E) = 2;
    MEM8(esi + 0x6F) = 1;
    MEM8(esi + 0x70) = 0;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCC80: ;
    goto loc_003BCC89;

loc_003BCC82: ;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BCC89: ;
    POP32(esp, edi);

loc_003BCC8A: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    PUSH32(esp, esi);
    ecx = ecx + 0xFFFFFFFEu;
    PUSH32(esp, edi);
    esi = eax + 0x34;
    eax = ecx;
    ecx = ecx >> 2;
    edi = edx;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    PUSH32(esp, 8);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    POP32(esp, ecx);
    POP32(esp, edi);
    eax = edx + 2;
    POP32(esp, esi);

loc_003BCCBF: ;
    if (CMP_AE(MEM8(eax), 0x20)) goto loc_003BCCC9; /* jae: above or equal (unsigned >=) */

loc_003BCCC4: ;
    MEM8(eax) = 0;
    goto loc_003BCCCC;

loc_003BCCC9: ;
    ebx = 0; /* xor self */
    ebx++;

loc_003BCCCC: ;
    eax++;
    ecx--;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003BCCBF; } /* jne: not equal / not zero */

loc_003BCCD0: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BCCD9; /* jne: not equal / not zero */

loc_003BCCD4: ;
    if (TEST_Z(MEM8(edx), 0x3F)) goto loc_003BCCDF; /* je: equal / zero */

loc_003BCCD9: ;
    POP32(esp, ebx);
    g_seh_ebp = ebp; sub_002BFDA6(); return; /* tail jmp 0x002BFDA6 */

loc_003BCCDF: ;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BCC8F
 * Original: 0x003BCC8F - 0x003BCCE1 (82 bytes, 40 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCC8F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCC8F: ;
    eax = ecx;
    ecx = MEM32(eax + 0x66);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* cmp ecx, 2 - flags set for next jcc */
    edx = eax + 0x14;
    if (CMP_B(ecx, 2)) goto loc_003BCCDF; /* jb: below (unsigned <) */

loc_003BCC9F: ;
    PUSH32(esp, esi);
    ecx = ecx + 0xFFFFFFFEu;
    PUSH32(esp, edi);
    esi = eax + 0x34;
    eax = ecx;
    ecx = ecx >> 2;
    edi = edx;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    PUSH32(esp, 8);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    POP32(esp, ecx);
    POP32(esp, edi);
    eax = edx + 2;
    POP32(esp, esi);

loc_003BCCBF: ;
    if (CMP_AE(MEM8(eax), 0x20)) goto loc_003BCCC9; /* jae: above or equal (unsigned >=) */

loc_003BCCC4: ;
    MEM8(eax) = 0;
    goto loc_003BCCCC;

loc_003BCCC9: ;
    ebx = 0; /* xor self */
    ebx++;

loc_003BCCCC: ;
    eax++;
    ecx--;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003BCCBF; } /* jne: not equal / not zero */

loc_003BCCD0: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BCCD9; /* jne: not equal / not zero */

loc_003BCCD4: ;
    if (TEST_Z(MEM8(edx), 0x3F)) goto loc_003BCCDF; /* je: equal / zero */

loc_003BCCD9: ;
    POP32(esp, ebx);
    g_seh_ebp = ebp; sub_002BFDA6(); return; /* tail jmp 0x002BFDA6 */

loc_003BCCDF: ;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BCCE1
 * Original: 0x003BCCE1 - 0x003BCD05 (36 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCCE1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCCE1: ;
    eax = ecx;
    ecx = MEM32(eax + 0x66);
    ecx--;
    PUSH32(esp, esi);
    ecx--;
    PUSH32(esp, edi);
    esi = eax + 0x34;
    edi = eax + 0x14;
    eax = ecx;
    ecx = ecx >> 2;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = eax;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    POP32(esp, edi);
    POP32(esp, esi);
    g_seh_ebp = ebp; sub_002BFDA6(); return; /* tail jmp 0x002BFDA6 */

}

/**
 * sub_003BCD05
 * Original: 0x003BCD05 - 0x003BCD2F (42 bytes, 17 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD05(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCD05: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ecx + 4));
    esi = edx;
    edi = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003BCD14: ;
    /* test edi, edi - flags set for next jcc */
    MEM32(esi) = eax;
    if (TEST_Z(edi, edi)) { g_seh_ebp = ebp; sub_003BCD2F(); return; } /* je: equal / zero */

loc_003BCD1A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCD25: ;
    ecx = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    g_seh_ebp = ebp; RECOMP_ITAIL(MEM32(0x3C1538)); return; /* indirect tail jmp */

}

/**
 * sub_003BCD2F
 * Original: 0x003BCD2F - 0x003BCD98 (105 bytes, 34 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD2F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCD2F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

    if (TEST_NZ(MEM8(ecx + 4), 2)) goto loc_003BCD7F; /* jne: not equal / not zero */

loc_003BCD4C: ;
    esi = MEM32(esp + 0xC);
    if (CMP_L(MEM32(esi + 4), 0)) goto loc_003BCD76; /* jl: less (signed <) */

loc_003BCD56: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    MEM8(esi) = 0x18;
    MEM8(esi + 1) = 5;
    eax = MEM32(eax + 0x10);
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x14) = 4;
    ecx = MEM32(ecx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCD76: ;
    MEM32(esi + 4) = 0xC0000004u;
    goto loc_003BCD8A;

loc_003BCD7F: ;
    esi = MEM32(esp + 0xC);
    MEM32(esi + 4) = 0x80000700u;

loc_003BCD8A: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD05(); /* call 0x003BCD05 */

loc_003BCD93: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCD32
 * Original: 0x003BCD32 - 0x003BCD98 (102 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD32(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCD32: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    eax = MEM32(edi + 8);
    /* test MEM8(eax + 0xA2), 1 - flags set for next jcc */
    ecx = MEM32(eax);
    if (TEST_NZ(MEM8(eax + 0xA2), 1)) goto loc_003BCD7F; /* jne: not equal / not zero */

loc_003BCD46: ;
    if (TEST_NZ(MEM8(ecx + 4), 2)) goto loc_003BCD7F; /* jne: not equal / not zero */

loc_003BCD4C: ;
    esi = MEM32(esp + 0xC);
    if (CMP_L(MEM32(esi + 4), 0)) goto loc_003BCD76; /* jl: less (signed <) */

loc_003BCD56: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    MEM8(esi) = 0x18;
    MEM8(esi + 1) = 5;
    eax = MEM32(eax + 0x10);
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x14) = 4;
    ecx = MEM32(ecx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCD76: ;
    MEM32(esi + 4) = 0xC0000004u;
    goto loc_003BCD8A;

loc_003BCD7F: ;
    esi = MEM32(esp + 0xC);
    MEM32(esi + 4) = 0x80000700u;

loc_003BCD8A: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD05(); /* call 0x003BCD05 */

loc_003BCD93: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCD98
 * Original: 0x003BCD98 - 0x003BCDE5 (77 bytes, 35 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD98(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCD98: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    MEM32(ebp + -8) = MEM32(ebp + -8) | 0xFFFFFFFFu;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(0x3C15F4);
    PUSH32(esp, edi);
    eax = ebp + -12;
    PUSH32(esp, eax);
    edi = 0; /* xor self */
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebp + 8));
    ebx = edx;
    MEM32(ebp + -4) = ecx;
    MEM32(ebp + -12) = 0xFFF85EE0u;
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCDC5: ;
    if (CMP_NE(eax, 0x102)) goto loc_003BCDDE; /* jne: not equal / not zero */

loc_003BCDCC: ;
    ecx = MEM32(ebp + -4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BCDD5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebp + 8));
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCDDE: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BCDE5
 * Original: 0x003BCDE5 - 0x003BCE6F (138 bytes, 47 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCDE5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCDE5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCDF3: ;
    esi = MEM32(esp + 0x14);
    edi = esi + 0xA;
    edx = edi;
    SET_LO8(ecx, 2);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA0F2(); /* call 0x003BA0F2 */

loc_003BCE03: ;
    ebx = eax;
    if (TEST_Z(ebx, ebx)) goto loc_003BCE44; /* je: equal / zero */

loc_003BCE09: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE2D(); /* call 0x003BBE2D */

loc_003BCE10: ;
    edx = eax;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC983(); /* call 0x003BC983 */

loc_003BCE19: ;
    if (TEST_NZ(eax, eax)) goto loc_003BCE44; /* jne: not equal / not zero */

loc_003BCE1D: ;
    ecx = MEM32(esi);
    MEM8(esi + 0xB) = LO8(eax);
    SET_LO8(eax, MEM8(edi));
    MEM32(esi + 0xE) = ebx;
    MEM8(esi + 0xC) = 8;
    MEM8(esi + 0xD) = 1;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003BCE35: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BCE3E: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003BCE69;

loc_003BCE44: ;
    edi = MEM32(esi);
    MEM32(esi) = MEM32(esi) & 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    PUSH32(esp, 0);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BCE5D: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BCE69: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCE6F
 * Original: 0x003BCE6F - 0x003BCF0C (157 bytes, 58 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCE6F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCE6F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCE7E: ;
    esi = MEM32(esp + 0x18);
    ebp = esi + 0xA;
    edx = ebp;
    SET_LO8(ecx, 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA0F2(); /* call 0x003BA0F2 */

loc_003BCE8E: ;
    edi = eax;
    ebx = 0; /* xor self */
    if (CMP_EQ(edi, ebx)) goto loc_003BCEE2; /* je: equal / zero */

loc_003BCE96: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE2D(); /* call 0x003BBE2D */

loc_003BCE9D: ;
    edx = eax;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC983(); /* call 0x003BC983 */

loc_003BCEA6: ;
    if (TEST_NZ(eax, eax)) goto loc_003BCEE2; /* jne: not equal / not zero */

loc_003BCEAA: ;
    SET_LO8(ecx, MEM8(esi + 6));
    MEM32(esi + 0xE) = edi;
    MEM8(esi + 0xB) = LO8(ebx);
    eax = MEM32(edi + 8);
    SET_LO8(eax, MEM8(eax));
    if (CMP_AE(LO8(ecx), LO8(eax))) goto loc_003BCEC1; /* jae: above or equal (unsigned >=) */

loc_003BCEBC: ;
    MEM8(esi + 0xC) = LO8(ecx);
    goto loc_003BCEC4;

loc_003BCEC1: ;
    MEM8(esi + 0xC) = LO8(eax);

loc_003BCEC4: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebp));
    MEM8(esi + 0xD) = LO8(ebx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003BCED4: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BCEDC: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003BCF05;

loc_003BCEE2: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BCEF9: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BCF05: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCF0C
 * Original: 0x003BCF0C - 0x003BCF2A (30 bytes, 11 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCF0C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCF0C: ;
    edx = ecx + 0xA2;
    SET_LO8(eax, MEM8(edx));
    if (TEST_NZ(LO8(eax), 4)) goto loc_003BCF29; /* jne: not equal / not zero */

loc_003BCF18: ;
    PUSH32(esp, ecx);
    ecx = ecx + 0x82;
    SET_LO8(eax, LO8(eax) | 4);
    PUSH32(esp, ecx);
    MEM8(edx) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCA98(); /* call 0x003BCA98 */

loc_003BCF29: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BCF2A
 * Original: 0x003BCF2A - 0x003BCFAE (132 bytes, 38 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCF2A(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCF2A: ;
    edx = MEM32(esp + 8);
    ecx = MEM32(edx + 8);
    eax = MEM32(ecx);
    /* test MEM8(ecx + 0xA2), 1 - flags set for next jcc */
    _rccf = (TEST_NZ(MEM8(ecx + 0xA2), 1));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    ecx = MEM32(esp + 4);
    if (_rccf) goto loc_003BCF46; /* jne: not equal / not zero */

loc_003BCF40: ;
    if (TEST_Z(MEM8(eax + 4), 2)) goto loc_003BCF4D; /* je: equal / zero */

loc_003BCF46: ;
    MEM32(ecx + 4) = 0x80000700u;

loc_003BCF4D: ;
    if (CMP_NE(MEM32(ecx + 4), 0xC0000004u)) goto loc_003BCFA6; /* jne: not equal / not zero */

loc_003BCF56: ;
    if (CMP_NE(MEM8(ecx + 1), 0x41)) goto loc_003BCFA6; /* jne: not equal / not zero */

loc_003BCF5C: ;
    MEM32(ecx + 0xC) = edx;
    edx = 0; /* xor self */
    PUSH32(esp, esi);
    MEM8(ecx) = 0x30;
    MEM8(ecx + 1) = 0x40;
    MEM32(ecx + 8) = 0x3BCD32;
    MEM32(ecx + 0x10) = edx;
    MEM32(ecx + 0x18) = edx;
    MEM32(ecx + 0x14) = edx;
    MEM8(ecx + 0x1C) = LO8(edx);
    MEM8(ecx + 0x1D) = LO8(edx);
    MEM8(ecx + 0x1E) = LO8(edx);
    MEM8(ecx + 0x28) = 2;
    MEM8(ecx + 0x29) = 1;
    MEM16(ecx + 0x2A) = LO16(edx);
    SET_LO16(esi, ZX8(MEM8(eax + 9)));
    MEM16(ecx + 0x2C) = LO16(esi);
    MEM16(ecx + 0x2E) = LO16(edx);
    PUSH32(esp, ecx);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BCFA3: ;
    POP32(esp, esi);
    goto loc_003BCFAB;

loc_003BCFA6: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD05(); /* call 0x003BCD05 */

loc_003BCFAB: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCFAE
 * Original: 0x003BCFAE - 0x003BD039 (139 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCFAE(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCFAE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCFBA: ;
    esi = MEM32(esp + 0xC);
    eax = 0; /* xor self */
    MEM8(0xF2A4E8) = 0x30;
    MEM8(0xF2A4E9) = 0x40;
    MEM32(0xF2A4F0) = 0x3BCDE5;
    MEM32(0xF2A4F4) = esi;
    MEM32(0xF2A4F8) = eax;
    MEM32(0xF2A500) = eax;
    MEM32(0xF2A4FC) = eax;
    MEM8(0xF2A504) = LO8(eax);
    MEM8(0xF2A505) = 1;
    MEM8(0xF2A506) = LO8(eax);
    MEM8(0xF2A510) = 0x21;
    MEM8(0xF2A511) = 0xA;
    MEM16(0xF2A512) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF2A514) = LO16(ecx);
    MEM16(0xF2A516) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD029: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF2A4E8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD035: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD039
 * Original: 0x003BD039 - 0x003BD0C4 (139 bytes, 27 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD039(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD039: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD045: ;
    esi = MEM32(esp + 0xC);
    eax = 0; /* xor self */
    MEM8(0xF2A4E8) = 0x30;
    MEM8(0xF2A4E9) = 0x40;
    MEM32(0xF2A4F0) = 0x3BCE6F;
    MEM32(0xF2A4F4) = esi;
    MEM32(0xF2A4F8) = eax;
    MEM32(0xF2A500) = eax;
    MEM32(0xF2A4FC) = eax;
    MEM8(0xF2A504) = LO8(eax);
    MEM8(0xF2A505) = 1;
    MEM8(0xF2A506) = LO8(eax);
    MEM8(0xF2A510) = 0x21;
    MEM8(0xF2A511) = 0xA;
    MEM16(0xF2A512) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF2A514) = LO16(ecx);
    MEM16(0xF2A516) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD0B4: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF2A4E8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD0C0: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD0C4
 * Original: 0x003BD0C4 - 0x003BD0FF (59 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD0C4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD0C4: ;
    ecx = MEM32(esp + 4);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BD0CE: ;
    esi = eax;
    ecx = MEM32(esi + 0x12);
    MEM8(esi + 4) = MEM8(esi + 4) | 2;
    if (TEST_Z(ecx, ecx)) goto loc_003BD0F4; /* je: equal / zero */

loc_003BD0DB: ;
    eax = MEM32(ecx + 0xA3);
    eax = MEM32(eax + 0x20);
    if (TEST_Z(eax, eax)) goto loc_003BD0EA; /* je: equal / zero */

loc_003BD0E8: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = eax; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD0EA: ;
    ecx = MEM32(esi + 0x12);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCF0C(); /* call 0x003BCF0C */

loc_003BD0F2: ;
    goto loc_003BD0FB;

loc_003BD0F4: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC960(); /* call 0x003BC960 */

loc_003BD0FB: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD0FF
 * Original: 0x003BD0FF - 0x003BD16C (109 bytes, 38 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD0FF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD0FF: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD10F: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(esi + 0xA3);
    eax = MEM32(eax + 0x1C);
    ebx = 0; /* xor self */
    if (CMP_EQ(eax, ebx)) goto loc_003BD125; /* je: equal / zero */

loc_003BD121: ;
    ecx = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = eax; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD125: ;
    if (CMP_EQ(MEM32(esi), ebx)) { g_seh_ebp = ebp; sub_003BD16C(); return; } /* je: equal / zero */

loc_003BD129: ;
    MEM8(esi + 0xA2) = MEM8(esi + 0xA2) | 1;
    eax = ebp + -12;
    MEM32(ebp + -8) = eax;
    MEM32(ebp + -12) = eax;
    eax = ebp + -20;
    ecx = esi;
    MEM8(ebp + -20) = LO8(ebx);
    MEM8(ebp + -18) = 4;
    MEM32(ebp + -16) = ebx;
    MEM32(esi + 0x9E) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCF0C(); /* call 0x003BCF0C */

loc_003BD153: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD15C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = ebp + -20;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD16A: ;
    g_seh_ebp = ebp; sub_003BD175(); return; /* tail jmp 0x003BD175 */

}

/**
 * sub_003BD16C
 * Original: 0x003BD16C - 0x003BD175 (9 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD16C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD16C: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003BD175(); return; /* restored dropped fall-through to sub_003BD175 */
}

/**
 * sub_003BD175
 * Original: 0x003BD175 - 0x003BD193 (30 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD175(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD175: ;
    eax = MEM32(esi + 0xA3);
    MEM8(eax + 1) = MEM8(eax + 1) + 1;
    eax = MEM32(0xF2A4D0);
    MEM32(esi + 0xA7) = eax;
    MEM32(0xF2A4D0) = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BD193
 * Original: 0x003BD193 - 0x003BD2AB (280 bytes, 91 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD193(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD193: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ecx);
    esi = edx;
    MEM32(ebp + -8) = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD1A8: ;
    ebx = 0; /* xor self */
    /* cmp edi, ebx - flags set for next jcc */
    MEM8(ebp + -2) = LO8(eax);
    if (CMP_EQ(edi, ebx)) { g_seh_ebp = ebp; sub_003BD2AB(); return; } /* je: equal / zero */

loc_003BD1B5: ;
    if (TEST_NZ(MEM8(edi + 4), 2)) { g_seh_ebp = ebp; sub_003BD2AB(); return; } /* jne: not equal / not zero */

loc_003BD1BF: ;
    if (CMP_NE(MEM8(edi + 0xD), LO8(ebx))) goto loc_003BD1CF; /* jne: not equal / not zero */

loc_003BD1C4: ;
    MEM32(esi) = 0x32;
    g_seh_ebp = ebp; sub_003BD2B1(); return; /* tail jmp 0x003BD2B1 */

loc_003BD1CF: ;
    eax = MEM32(esi + 4);
    if (CMP_EQ(eax, ebx)) goto loc_003BD1EE; /* je: equal / zero */

loc_003BD1D6: ;
    ecx = esi + 0xC;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, MEM32(0x3C15C8));
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C153C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD1E7: ;
    if (CMP_GE(eax & eax, 0)) goto loc_003BD1F1; /* jge: greater or equal (signed >=) */

loc_003BD1EB: ;
    MEM32(esi + 4) = ebx;

loc_003BD1EE: ;
    MEM32(esi + 0xC) = ebx;

loc_003BD1F1: ;
    ecx = esi + 0x40;
    SET_LO8(eax, MEM8(ecx));
    /* cmp LO8(eax), LO8(ebx) - flags set for next jcc */
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_NE(LO8(eax), LO8(ebx))) goto loc_003BD208; /* jne: not equal / not zero */

loc_003BD1FD: ;
    SET_LO8(eax, MEM8(edi + 0xD));
    if (CMP_AE(LO8(eax), MEM8(esi + 0x41))) goto loc_003BD208; /* jae: above or equal (unsigned >=) */

loc_003BD205: ;
    MEM8(esi + 0x41) = LO8(eax);

loc_003BD208: ;
    eax = MEM32(edi + 0xE);
    if (TEST_Z(MEM8(eax + 0x28), 2)) goto loc_003BD214; /* je: equal / zero */

loc_003BD211: ;
    ecx = esi + 0x42;

loc_003BD214: ;
    edx = MEM32(ebp + -8);
    /* cmp MEM32(edx + 0x10), ebx - flags set for next jcc */
    eax = esi + 0x10;
    MEM32(esi + 0x1C) = esi;
    MEM32(esi + 0x18) = 0x3BCF2A;
    if (CMP_EQ(MEM32(edx + 0x10), ebx)) goto loc_003BD24C; /* je: equal / zero */

loc_003BD229: ;
    MEM8(eax) = 0x28;
    MEM8(esi + 0x11) = 0x41;
    edx = MEM32(edx + 0x10);
    MEM32(esi + 0x28) = ecx;
    ecx = ZX8(MEM8(esi + 0x41));
    MEM32(esi + 0x20) = edx;
    MEM32(esi + 0x24) = ecx;
    MEM8(esi + 0x2C) = 1;
    MEM8(esi + 0x2D) = LO8(ebx);
    MEM8(esi + 0x2E) = LO8(ebx);
    goto loc_003BD293;

loc_003BD24C: ;
    MEM32(esi + 0x28) = ecx;
    SET_LO8(ecx, MEM8(esi + 0x41));
    edx = ZX8(LO8(ecx));
    MEM32(esi + 0x24) = edx;
    SET_LO16(edx, ZX8(MEM8(ebp + -1)));
    SET_LO16(edx, LO16(edx) | 0x200);
    MEM8(eax) = 0x30;
    MEM8(esi + 0x11) = 0x40;
    MEM32(esi + 0x20) = ebx;
    MEM8(esi + 0x2C) = 1;
    MEM8(esi + 0x2D) = LO8(ebx);
    MEM8(esi + 0x2E) = LO8(ebx);
    MEM8(esi + 0x38) = 0x21;
    MEM8(esi + 0x39) = 9;
    MEM16(esi + 0x3A) = LO16(edx);
    SET_LO16(edx, ZX8(MEM8(edi + 5)));
    SET_LO16(ecx, ZX8(LO8(ecx)));
    MEM16(esi + 0x3C) = LO16(edx);
    MEM16(esi + 0x3E) = LO16(ecx);

loc_003BD293: ;
    ecx = MEM32(ebp + -8);
    MEM32(esi + 8) = ecx;
    ecx = MEM32(edi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD2A1: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003BD2A7: ;
    MEM32(esi) = eax;
    g_seh_ebp = ebp; sub_003BD2B1(); return; /* tail jmp 0x003BD2B1 */

}

/**
 * sub_003BD2AB
 * Original: 0x003BD2AB - 0x003BD2B1 (6 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2AB(void)
{

loc_003BD2AB: ;
    MEM32(esi) = 0x48F;

    sub_003BD2B1(); return; /* restored dropped fall-through to sub_003BD2B1 */
}

/**
 * sub_003BD2B1
 * Original: 0x003BD2B1 - 0x003BD2C1 (16 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2B1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD2B1: ;
    SET_LO8(ecx, MEM8(ebp + -2));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD2BA: ;
    eax = MEM32(esi);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BD2C1
 * Original: 0x003BD2C1 - 0x003BD374 (179 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2C1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD2C1: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB1(); /* call 0x003BBDB1 */

loc_003BD2CD: ;
    SET_LO8(ecx, MEM8(eax + 5));
    if (CMP_NE(LO8(ecx), 3)) { g_seh_ebp = ebp; sub_003BD374(); return; } /* jne: not equal / not zero */

loc_003BD2D9: ;
    if (CMP_NE(MEM8(eax + 7), 1)) goto loc_003BD358; /* jne: not equal / not zero */

loc_003BD2DF: ;
    eax = 0; /* xor self */
    MEM8(0xF2A4E8) = 0x30;
    MEM8(0xF2A4E9) = 0x40;
    MEM32(0xF2A4F0) = 0x3BCFAE;
    MEM32(0xF2A4F4) = esi;
    MEM32(0xF2A4F8) = eax;
    MEM32(0xF2A500) = eax;
    MEM32(0xF2A4FC) = eax;
    MEM8(0xF2A504) = LO8(eax);
    MEM8(0xF2A505) = 1;
    MEM8(0xF2A506) = LO8(eax);
    MEM8(0xF2A510) = 0x21;
    MEM8(0xF2A511) = 0xB;
    MEM16(0xF2A512) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF2A514) = LO16(ecx);
    MEM16(0xF2A516) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD34A: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF2A4E8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD356: ;
    g_seh_ebp = ebp; sub_003BD39B(); return; /* tail jmp 0x003BD39B */

loc_003BD358: ;
    if (CMP_NE(LO8(ecx), 3)) { g_seh_ebp = ebp; sub_003BD374(); return; } /* jne: not equal / not zero */

loc_003BD35D: ;
    if (CMP_NE(MEM8(eax + 7), 2)) { g_seh_ebp = ebp; sub_003BD374(); return; } /* jne: not equal / not zero */

loc_003BD363: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD368: ;
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD039(); /* call 0x003BD039 */

loc_003BD372: ;
    g_seh_ebp = ebp; sub_003BD39B(); return; /* tail jmp 0x003BD39B */

}

/**
 * sub_003BD374
 * Original: 0x003BD374 - 0x003BD39B (39 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD374(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD374: ;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    PUSH32(esp, edi);
    edi = MEM32(esi);
    eax = 0; /* xor self */
    MEM32(esi) = eax;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    PUSH32(esp, eax);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BD38E: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD39A: ;
    POP32(esp, edi);

    g_seh_ebp = ebp; sub_003BD39B(); return; /* restored dropped fall-through to sub_003BD39B */
}

/**
 * sub_003BD39B
 * Original: 0x003BD39B - 0x003BD493 (248 bytes, 74 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD39B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD39B: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(eax + 4), ebx)) goto loc_003BD483; /* jl: less (signed <) */

loc_003BD3BC: ;
    if (CMP_B(MEM32(eax + 0x14), 8)) goto loc_003BD483; /* jb: below (unsigned <) */

loc_003BD3C6: ;
    if (CMP_B(MEM8(0xF2A4D4), 8)) goto loc_003BD483; /* jb: below (unsigned <) */

loc_003BD3D3: ;
    if (CMP_NE(MEM8(0xF2A4D5), 0x42)) goto loc_003BD483; /* jne: not equal / not zero */

loc_003BD3E0: ;
    if (CMP_EQ(MEM16(0xF2A4D6), LO16(ebx))) goto loc_003BD483; /* je: equal / zero */

loc_003BD3ED: ;
    esi = MEM32(esp + 0x14);
    SET_LO8(ecx, MEM8(0xF2A4D8));
    edi = esi + 0xA;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA0F2(); /* call 0x003BA0F2 */

loc_003BD401: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(esi + 0xE) = eax;
    SET_LO8(ecx, MEM8(0xF2A4D9));
    MEM8(esi + 0xB) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF2A4DA));
    MEM8(esi + 0xC) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF2A4DB));
    MEM8(esi + 0xD) = LO8(ecx);
    if (CMP_EQ(eax, ebx)) goto loc_003BD45E; /* je: equal / zero */

loc_003BD423: ;
    SET_LO8(eax, MEM8(0xF2A4DA));
    if (CMP_B(LO8(eax), 2)) goto loc_003BD45E; /* jb: below (unsigned <) */

loc_003BD42C: ;
    if (CMP_A(LO8(eax), 0x20)) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD430: ;
    SET_LO8(eax, MEM8(esi + 0xC));
    if (CMP_A(LO8(eax), MEM8(esi + 6))) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD438: ;
    if (CMP_EQ(MEM8(esi + 9), LO8(ebx))) goto loc_003BD444; /* je: equal / zero */

loc_003BD43D: ;
    SET_LO8(eax, LO8(ecx));
    if (CMP_A(LO8(eax), MEM8(esi + 7))) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD444: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(edi));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003BD450: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD458: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003BD48D;

loc_003BD45E: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BD475: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD481: ;
    goto loc_003BD48D;

loc_003BD483: ;
    PUSH32(esp, MEM32(esp + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD2C1(); /* call 0x003BD2C1 */

loc_003BD48D: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD39F
 * Original: 0x003BD39F - 0x003BD493 (244 bytes, 72 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD39F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD39F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF2A520);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD3AD: ;
    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(eax + 4), ebx)) goto loc_003BD483; /* jl: less (signed <) */

loc_003BD3BC: ;
    if (CMP_B(MEM32(eax + 0x14), 8)) goto loc_003BD483; /* jb: below (unsigned <) */

loc_003BD3C6: ;
    if (CMP_B(MEM8(0xF2A4D4), 8)) goto loc_003BD483; /* jb: below (unsigned <) */

loc_003BD3D3: ;
    if (CMP_NE(MEM8(0xF2A4D5), 0x42)) goto loc_003BD483; /* jne: not equal / not zero */

loc_003BD3E0: ;
    if (CMP_EQ(MEM16(0xF2A4D6), LO16(ebx))) goto loc_003BD483; /* je: equal / zero */

loc_003BD3ED: ;
    esi = MEM32(esp + 0x14);
    SET_LO8(ecx, MEM8(0xF2A4D8));
    edi = esi + 0xA;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA0F2(); /* call 0x003BA0F2 */

loc_003BD401: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(esi + 0xE) = eax;
    SET_LO8(ecx, MEM8(0xF2A4D9));
    MEM8(esi + 0xB) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF2A4DA));
    MEM8(esi + 0xC) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF2A4DB));
    MEM8(esi + 0xD) = LO8(ecx);
    if (CMP_EQ(eax, ebx)) goto loc_003BD45E; /* je: equal / zero */

loc_003BD423: ;
    SET_LO8(eax, MEM8(0xF2A4DA));
    if (CMP_B(LO8(eax), 2)) goto loc_003BD45E; /* jb: below (unsigned <) */

loc_003BD42C: ;
    if (CMP_A(LO8(eax), 0x20)) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD430: ;
    SET_LO8(eax, MEM8(esi + 0xC));
    if (CMP_A(LO8(eax), MEM8(esi + 6))) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD438: ;
    if (CMP_EQ(MEM8(esi + 9), LO8(ebx))) goto loc_003BD444; /* je: equal / zero */

loc_003BD43D: ;
    SET_LO8(eax, LO8(ecx));
    if (CMP_A(LO8(eax), MEM8(esi + 7))) goto loc_003BD45E; /* ja: above (unsigned >) */

loc_003BD444: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(edi));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003BD450: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD458: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003BD48D;

loc_003BD45E: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BD475: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD481: ;
    goto loc_003BD48D;

loc_003BD483: ;
    PUSH32(esp, MEM32(esp + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD2C1(); /* call 0x003BD2C1 */

loc_003BD48D: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD493
 * Original: 0x003BD493 - 0x003BD4D7 (68 bytes, 25 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD493(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD493: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x28;
    eax = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = 0; /* xor self */
    esi = ecx;
    PUSH32(esp, edi);
    edi = edx;
    MEM32(ebp + -16) = esi;
    MEM32(ebp + -8) = ebx;
    MEM32(ebp + -12) = ebx;
    MEM32(eax) = ebx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD4B6: ;
    edx = edi;
    ecx = esi;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC983(); /* call 0x003BC983 */

loc_003BD4C2: ;
    edx = eax;
    /* cmp edx, ebx - flags set for next jcc */
    MEM32(ebp + -20) = edx;
    if (CMP_NE(edx, ebx)) { g_seh_ebp = ebp; sub_003BD4D7(); return; } /* jne: not equal / not zero */

loc_003BD4CB: ;
    MEM32(ebp + -8) = 0x48F;
    g_seh_ebp = ebp; sub_003BD6C2(); return; /* tail jmp 0x003BD6C2 */

}

/**
 * sub_003BD4CB
 * Original: 0x003BD4CB - 0x003BD4D7 (12 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD4CB(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD4CB: ;
    MEM32(ebp + -8) = 0x48F;
    g_seh_ebp = ebp; sub_003BD6C2(); return; /* tail jmp 0x003BD6C2 */

}

/**
 * sub_003BD4D7
 * Original: 0x003BD4D7 - 0x003BD6C2 (491 bytes, 145 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD4D7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD4D7: ;
    if (CMP_EQ(MEM32(edx + 0x12), ebx)) goto loc_003BD4E8; /* je: equal / zero */

loc_003BD4DC: ;
    MEM32(ebp + -8) = 0x20;
    g_seh_ebp = ebp; sub_003BD6C2(); return; /* tail jmp 0x003BD6C2 */

loc_003BD4E8: ;
    SET_LO8(eax, MEM8(esi + 1));
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003BD4FB; /* jne: not equal / not zero */

loc_003BD4EF: ;
    MEM32(ebp + -8) = 0xE;
    g_seh_ebp = ebp; sub_003BD6C2(); return; /* tail jmp 0x003BD6C2 */

loc_003BD4FB: ;
    SET_LO8(eax, LO8(eax) - 1);
    MEM8(esi + 1) = LO8(eax);
    ebx = MEM32(0xF2A4D0);
    eax = MEM32(ebx + 0xA7);
    MEM32(0xF2A4D0) = eax;
    eax = 0; /* xor self */
    PUSH32(esp, 0x2A);
    POP32(esp, ecx);
    edi = ebx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM16(edi) = LO16(eax); edi += 2; /* stosw */
    MEM8(edi) = LO8(eax); edi++; /* stosb */
    edi = MEM32(ebp + 0xC);
    SET_LO8(ecx, MEM8(ebx + 0xA2));
    MEM32(ebx) = edx;
    MEM32(ebx + 0xA3) = esi;
    SET_LO8(eax, MEM8(edi));
    SET_LO8(eax, LO8(eax) & 1);
    SET_LO8(ecx, LO8(ecx) & 0xE7);
    SET_LO8(eax, LO8(eax) << 3);
    SET_LO8(eax, LO8(eax) | LO8(ecx));
    MEM8(ebx + 0xA2) = LO8(eax);
    MEM32(edx + 0x12) = ebx;
    edx = edi;
    ecx = ebx;
    MEM32(ebp + -24) = ebx;
    MEM32(ebp + -12) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC9ED(); /* call 0x003BC9ED */

loc_003BD556: ;
    if (TEST_S(eax, eax)) goto loc_003BD6B9; /* jl: less (signed <) */

loc_003BD55E: ;
    edx = MEM32(esi + 0x18);
    if (TEST_Z(edx, edx)) goto loc_003BD577; /* je: equal / zero */

loc_003BD565: ;
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = edx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD569: ;
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = eax & 0x7FFFFF00;
    eax = eax + 0x80000100u;

loc_003BD577: ;
    if (TEST_S(eax, eax)) goto loc_003BD6B9; /* jl: less (signed <) */

loc_003BD57F: ;
    esi = MEM32(esi + 8);
    ecx = ZX8(MEM8(esi));
    esi = MEM32(esi + 1);
    edx = ecx;
    ecx = ecx >> 2;
    eax = ebx + 0x34;
    edi = eax;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = edx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    PUSH32(esp, 7);
    esi = eax;
    eax = MEM32(ebp + -16);
    edi = ebx + 0x14;
    POP32(esp, ecx);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    MEM16(edi) = MEM16(esi); esi += 2; edi += 2; /* movsw */
    /* test MEM8(eax + 0x28), 0x40 - flags set for next jcc */
    esi = MEM32(ebp + -20);
    if (TEST_NZ(MEM8(eax + 0x28), 0x40)) goto loc_003BD666; /* jne: not equal / not zero */

loc_003BD5B7: ;
    MEM32(ebp + -36) = MEM32(ebp + -36) & 0;
    eax = ebp + -32;
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -32) = eax;
    eax = ZX8(MEM8(esi + 0xC));
    MEM32(ebx + 0x62) = MEM32(ebx + 0x62) & 0;
    ecx = ebp + -40;
    MEM32(ebx + 0x5E) = ecx;
    ecx = ebx + 0x32;
    edi = ebx + 0x52;
    MEM8(edi) = 0x30;
    MEM8(ebx + 0x53) = 0x40;
    MEM32(ebx + 0x5A) = 0x3BBC94;
    MEM32(ebx + 0x6A) = ecx;
    MEM32(ebx + 0x66) = eax;
    MEM8(ebx + 0x6E) = 2;
    MEM8(ebx + 0x6F) = 1;
    MEM8(ebx + 0x70) = 0;
    MEM8(ebx + 0x7A) = 0xA1;
    MEM8(ebx + 0x7B) = 1;
    MEM16(ebx + 0x7C) = 0x100;
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(ebx + 0x7E) = LO16(ecx);
    MEM16(ebx + 0x80) = LO16(eax);
    ecx = MEM32(esi);
    PUSH32(esp, edi);
    MEM8(ebp + -40) = 1;
    MEM8(ebp + -38) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD626: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD62F: ;
    ecx = MEM32(esi);
    eax = ebp + -40;
    PUSH32(esp, eax);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BCD98(); /* call 0x003BCD98 */

loc_003BD63C: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD642: ;
    /* cmp MEM32(ebx), 0 - flags set for next jcc */
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_EQ(MEM32(ebx), 0)) { g_seh_ebp = ebp; sub_003BD4CB(); return; } /* je: equal / zero */

loc_003BD64E: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) { g_seh_ebp = ebp; sub_003BD4CB(); return; } /* jne: not equal / not zero */

loc_003BD658: ;
    if (CMP_L(MEM32(ebx + 0x56), 0)) goto loc_003BD666; /* jl: less (signed <) */

loc_003BD65E: ;
    eax = MEM32(ebp + -16);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD666: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(ebx + 0x62) = ecx;
    ecx = ebx + 0x32;
    eax = ebx + 0x52;
    MEM8(eax) = 0x28;
    MEM8(ebx + 0x53) = 0x41;
    MEM32(ebx + 0x5A) = 0x3BCB49;
    MEM32(ebx + 0x5E) = ebx;
    MEM32(ebx + 0x6A) = ecx;
    ecx = ZX8(MEM8(esi + 0xC));
    MEM32(ebx + 0x66) = ecx;
    MEM8(ebx + 0x6E) = 2;
    MEM8(ebx + 0x6F) = 1;
    MEM8(ebx + 0x70) = 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xF;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003BD6AE; /* je: equal / zero */

loc_003BD6A6: ;
    ecx = MEM32(esi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD6AE: ;
    eax = MEM32(ebp + 8);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM32(eax) = ebx;
    g_seh_ebp = ebp; sub_003BD6C2(); return; /* tail jmp 0x003BD6C2 */

loc_003BD6B9: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003BD6BF: ;
    MEM32(ebp + -8) = eax;

    g_seh_ebp = ebp; sub_003BD6C2(); return; /* restored dropped fall-through to sub_003BD6C2 */
}

/**
 * sub_003BD6C2
 * Original: 0x003BD6C2 - 0x003BD887 (453 bytes, 123 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD6C2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD6C2: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD6CB: ;
    /* cmp MEM32(ebp + -12), 0 - flags set for next jcc */
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    if (CMP_EQ(MEM32(ebp + -12), 0)) goto loc_003BD6DC; /* je: equal / zero */

loc_003BD6D4: ;
    ecx = MEM32(ebp + -24);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD0FF(); /* call 0x003BD0FF */

loc_003BD6DC: ;
    eax = MEM32(ebp + -8);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

    eax = MEM32(0xF2A4CC);
    if (TEST_Z(MEM8(eax + 4), 1)) goto loc_003BD715; /* je: equal / zero */

loc_003BD706: ;
    SET_LO8(ecx, LO8(ecx) + 1);
    edx = ZX8(LO8(ecx));
    edx = (uint32_t)((int32_t)edx * (int32_t)0x16);
    if (TEST_NZ(MEM8(edx + eax + 4), 1)) { RECOMP_SLICE_POINT(); goto loc_003BD706; } /* jne: not equal / not zero */

loc_003BD715: ;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) + 1;
    PUSH32(esp, esi);
    esi = ZX8(LO8(ecx));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x16);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = esi + eax;
    MEM8(0xF2A518) = LO8(ecx);
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BD738: ;
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0xF1);
    SET_LO8(eax, LO8(eax) | 1);
    ecx = edi;
    MEM32(esi) = edi;
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCC9(); /* call 0x003BBCC9 */

loc_003BD74B: ;
    PUSH32(esp, ebx);
    PUSH32(esp, 1);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 5) = LO8(eax);
    MEM32(esi + 0x12) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003BD75D: ;
    SET_LO8(ecx, MEM8(eax + 2));
    PUSH32(esp, ebx);
    MEM8(esi + 8) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    PUSH32(esp, ebx);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003BD774: ;
    if (CMP_EQ(eax, ebx)) goto loc_003BD786; /* je: equal / zero */

loc_003BD778: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 9) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    MEM8(esi + 7) = LO8(eax);
    goto loc_003BD78C;

loc_003BD786: ;
    MEM8(esi + 9) = LO8(ebx);
    MEM8(esi + 7) = LO8(ebx);

loc_003BD78C: ;
    PUSH32(esp, 0x10);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(0xF2A4E8) = 0x30;
    MEM8(0xF2A4E9) = 0x40;
    MEM32(0xF2A4F0) = 0x3BD39F;
    MEM32(0xF2A4F4) = esi;
    MEM32(0xF2A4F8) = ebx;
    MEM32(0xF2A500) = 0xF2A4D4;
    MEM32(0xF2A4FC) = eax;
    MEM8(0xF2A504) = 2;
    MEM8(0xF2A505) = 1;
    MEM8(0xF2A506) = LO8(ebx);
    MEM8(0xF2A510) = 0xC1;
    MEM8(0xF2A511) = 6;
    MEM16(0xF2A512) = 0x4200;
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    PUSH32(esp, 0x3BC94F);
    PUSH32(esp, 0xF2A548);
    MEM16(0xF2A514) = LO16(ecx);
    MEM16(0xF2A516) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD810: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD815: ;
    PUSH32(esp, 0xF2A4E8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD821: ;
    POP32(esp, edi);
    POP32(esp, esi);
    goto loc_003BD833;

loc_003BD825: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD833: ;
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD84D: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = MEM32(esp + 0x10);
    PUSH32(esp, MEM32(esi + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

loc_003BD85F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    PUSH32(esp, MEM32(0xF2A5C8));
    eax = MEM32(esp + 8);
    PUSH32(esp, MEM32(eax + 4));
    ecx = MEM32(esp + 0x10);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA76E(); /* call 0x003BA76E */

loc_003BD884: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD6E3
 * Original: 0x003BD6E3 - 0x003BD837 (340 bytes, 91 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD6E3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD6E3: ;
    SET_LO16(eax, MEM16(0xF2A4CA));
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    SET_LO8(ecx, 0); /* xor self */
    if (CMP_AE(LO16(eax), MEM16(0xF2A4C8))) goto loc_003BD825; /* jae: above or equal (unsigned >=) */

loc_003BD6FB: ;
    eax = MEM32(0xF2A4CC);
    if (TEST_Z(MEM8(eax + 4), 1)) goto loc_003BD715; /* je: equal / zero */

loc_003BD706: ;
    SET_LO8(ecx, LO8(ecx) + 1);
    edx = ZX8(LO8(ecx));
    edx = (uint32_t)((int32_t)edx * (int32_t)0x16);
    if (TEST_NZ(MEM8(edx + eax + 4), 1)) { RECOMP_SLICE_POINT(); goto loc_003BD706; } /* jne: not equal / not zero */

loc_003BD715: ;
    MEM16(0xF2A4CA) = MEM16(0xF2A4CA) + 1;
    PUSH32(esp, esi);
    esi = ZX8(LO8(ecx));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x16);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = esi + eax;
    MEM8(0xF2A518) = LO8(ecx);
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BD738: ;
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0xF1);
    SET_LO8(eax, LO8(eax) | 1);
    ecx = edi;
    MEM32(esi) = edi;
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCC9(); /* call 0x003BBCC9 */

loc_003BD74B: ;
    PUSH32(esp, ebx);
    PUSH32(esp, 1);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 5) = LO8(eax);
    MEM32(esi + 0x12) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003BD75D: ;
    SET_LO8(ecx, MEM8(eax + 2));
    PUSH32(esp, ebx);
    MEM8(esi + 8) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    PUSH32(esp, ebx);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003BD774: ;
    if (CMP_EQ(eax, ebx)) goto loc_003BD786; /* je: equal / zero */

loc_003BD778: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 9) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    MEM8(esi + 7) = LO8(eax);
    goto loc_003BD78C;

loc_003BD786: ;
    MEM8(esi + 9) = LO8(ebx);
    MEM8(esi + 7) = LO8(ebx);

loc_003BD78C: ;
    PUSH32(esp, 0x10);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(0xF2A4E8) = 0x30;
    MEM8(0xF2A4E9) = 0x40;
    MEM32(0xF2A4F0) = 0x3BD39F;
    MEM32(0xF2A4F4) = esi;
    MEM32(0xF2A4F8) = ebx;
    MEM32(0xF2A500) = 0xF2A4D4;
    MEM32(0xF2A4FC) = eax;
    MEM8(0xF2A504) = 2;
    MEM8(0xF2A505) = 1;
    MEM8(0xF2A506) = LO8(ebx);
    MEM8(0xF2A510) = 0xC1;
    MEM8(0xF2A511) = 6;
    MEM16(0xF2A512) = 0x4200;
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    PUSH32(esp, 0x3BC94F);
    PUSH32(esp, 0xF2A548);
    MEM16(0xF2A514) = LO16(ecx);
    MEM16(0xF2A516) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD810: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC934(); /* call 0x003BC934 */

loc_003BD815: ;
    PUSH32(esp, 0xF2A4E8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD821: ;
    POP32(esp, edi);
    POP32(esp, esi);
    goto loc_003BD833;

loc_003BD825: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BD833: ;
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD837
 * Original: 0x003BD837 - 0x003BD863 (44 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD837(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD837: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    if (CMP_GE(MEM32(esi + 4), 0)) goto loc_003BD85F; /* jge: greater or equal (signed >=) */

loc_003BD842: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD84D: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = MEM32(esp + 0x10);
    PUSH32(esp, MEM32(esi + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

loc_003BD85F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD863
 * Original: 0x003BD863 - 0x003BD887 (36 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD863(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD863: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD86E: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    eax = MEM32(esp + 8);
    PUSH32(esp, MEM32(eax + 4));
    ecx = MEM32(esp + 0x10);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA76E(); /* call 0x003BA76E */

loc_003BD884: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD887
 * Original: 0x003BD887 - 0x003BD8E4 (93 bytes, 29 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD887(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD887: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BD894: ;
    SET_LO16(edi, ZX8(MEM8(eax + 3)));
    edx = 0; /* xor self */
    ecx = eax + 8;
    MEM8(ecx) = 0x30;
    PUSH32(esp, ecx);
    ecx = esi;
    MEM8(eax + 9) = 0x40;
    MEM32(eax + 0x10) = 0x3BE16B;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x18) = edx;
    MEM32(eax + 0x20) = edx;
    MEM32(eax + 0x1C) = edx;
    MEM8(eax + 0x24) = LO8(edx);
    MEM8(eax + 0x25) = LO8(edx);
    MEM8(eax + 0x26) = LO8(edx);
    MEM8(eax + 0x30) = 0x23;
    MEM8(eax + 0x31) = 1;
    MEM16(eax + 0x32) = 1;
    MEM16(eax + 0x34) = LO16(edi);
    MEM16(eax + 0x36) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BD8DF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD8E4
 * Original: 0x003BD8E4 - 0x003BD903 (31 bytes, 11 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD8E4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD8E4: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    SET_LO8(eax, MEM8(esi));
    SET_LO8(eax, LO8(eax) >> 4);
    SET_LO8(eax, LO8(eax) & 1);
    if ((LO8(eax) == 0)) { g_seh_ebp = ebp; sub_003BD903(); return; } /* je: equal / zero */

loc_003BD8F2: ;
    if (CMP_NE(MEM32(esp + 0xC), 0)) { g_seh_ebp = ebp; sub_003BD903(); return; } /* jne: not equal / not zero */

loc_003BD8F9: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA3FB(); /* call 0x003BA3FB */

loc_003BD8FE: ;
    MEM8(esi) = MEM8(esi) & 0xEF;
    g_seh_ebp = ebp; sub_003BD916(); return; /* tail jmp 0x003BD916 */

}

/**
 * sub_003BD903
 * Original: 0x003BD903 - 0x003BD916 (19 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD903(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD903: ;
    if (TEST_NZ(LO8(eax), LO8(eax))) { g_seh_ebp = ebp; sub_003BD916(); return; } /* jne: not equal / not zero */

loc_003BD907: ;
    if (CMP_EQ(MEM32(esp + 0xC), 0)) { g_seh_ebp = ebp; sub_003BD916(); return; } /* je: equal / zero */

loc_003BD90E: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA3F4(); /* call 0x003BA3F4 */

loc_003BD913: ;
    MEM8(esi) = MEM8(esi) | 0x10;

    g_seh_ebp = ebp; sub_003BD916(); return; /* restored dropped fall-through to sub_003BD916 */
}

/**
 * sub_003BD916
 * Original: 0x003BD916 - 0x003BD98B (117 bytes, 39 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD916(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD916: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    ecx = MEM32(0xF2A614);
    ecx = ecx - 0;
    if ((ecx == 0)) goto loc_003BD97C; /* je: equal / zero */

loc_003BD931: ;
    ecx--;
    if ((ecx == 0)) goto loc_003BD968; /* je: equal / zero */

loc_003BD934: ;
    ecx--;
    if ((ecx == 0)) goto loc_003BD954; /* je: equal / zero */

loc_003BD937: ;
    ecx--;
    if ((ecx != 0)) goto loc_003BD987; /* jne: not equal / not zero */

loc_003BD93A: ;
    eax = MEM32(0xF2A618);
    if (TEST_Z(eax, eax)) goto loc_003BD987; /* je: equal / zero */

loc_003BD943: ;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BD94B: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;
    goto loc_003BD987;

loc_003BD954: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA76E(); /* call 0x003BA76E */

loc_003BD966: ;
    goto loc_003BD987;

loc_003BD968: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

loc_003BD97A: ;
    goto loc_003BD987;

loc_003BD97C: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BD987: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BD91A
 * Original: 0x003BD91A - 0x003BD98B (113 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD91A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD91A: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BD926: ;
    ecx = MEM32(0xF2A614);
    ecx = ecx - 0;
    if ((ecx == 0)) goto loc_003BD97C; /* je: equal / zero */

loc_003BD931: ;
    ecx--;
    if ((ecx == 0)) goto loc_003BD968; /* je: equal / zero */

loc_003BD934: ;
    ecx--;
    if ((ecx == 0)) goto loc_003BD954; /* je: equal / zero */

loc_003BD937: ;
    ecx--;
    if ((ecx != 0)) goto loc_003BD987; /* jne: not equal / not zero */

loc_003BD93A: ;
    eax = MEM32(0xF2A618);
    if (TEST_Z(eax, eax)) goto loc_003BD987; /* je: equal / zero */

loc_003BD943: ;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BD94B: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;
    goto loc_003BD987;

loc_003BD954: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA76E(); /* call 0x003BA76E */

loc_003BD966: ;
    goto loc_003BD987;

loc_003BD968: ;
    PUSH32(esp, MEM32(0xF2A5C8));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

loc_003BD97A: ;
    goto loc_003BD987;

loc_003BD97C: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCA5(); /* call 0x003BBCA5 */

loc_003BD987: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BD98B
 * Original: 0x003BD98B - 0x003BD9C4 (57 bytes, 15 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD98B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD98B: ;
    /* cmp MEM32(0xF2A618), 0 - flags set for next jcc */
    PUSH32(esp, esi);
    esi = 0xF2A5D0;
    if (CMP_EQ(MEM32(0xF2A618), 0)) goto loc_003BD9B5; /* je: equal / zero */

loc_003BD99A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD9A1: ;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(0xF2A618));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BD9AE: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;

loc_003BD9B5: ;
    edx = MEM32(esp + 8);
    if (TEST_NZ(edx, edx)) { g_seh_ebp = ebp; sub_003BD9C4(); return; } /* jne: not equal / not zero */

loc_003BD9BD: ;
    eax = 0xFA0A1F00u;
    g_seh_ebp = ebp; sub_003BD9D3(); return; /* tail jmp 0x003BD9D3 */

}

/**
 * sub_003BD9C4
 * Original: 0x003BD9C4 - 0x003BD9D3 (15 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD9C4(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003BD9C4: ;
    /* cmp edx, 3 - flags set for next jcc */
    eax = 0xFFF48E50u;
    if (CMP_EQ(edx, 3)) { g_seh_ebp = ebp; sub_003BD9D3(); return; } /* je: equal / zero */

loc_003BD9CE: ;
    eax = 0xFFB3B4C0u;

    g_seh_ebp = ebp; sub_003BD9D3(); return; /* restored dropped fall-through to sub_003BD9D3 */
}

/**
 * sub_003BD9D3
 * Original: 0x003BD9D3 - 0x003BD9EE (27 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD9D3(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD9D3: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5F8);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    MEM32(0xF2A614) = edx;
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD9EA: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD9EE
 * Original: 0x003BD9EE - 0x003BDA65 (119 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD9EE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD9EE: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BD9FE: ;
    esi = eax;
    SET_LO16(eax, MEM16(esi + 0x3A));
    ebx = 0; /* xor self */
    if (TEST_Z(LO8(eax), 0x10)) { g_seh_ebp = ebp; sub_003BDA65(); return; } /* je: equal / zero */

loc_003BDA0A: ;
    if (CMP_NE(MEM32(0xF2A614), 1)) goto loc_003BDA5D; /* jne: not equal / not zero */

loc_003BDA13: ;
    if (CMP_EQ(MEM32(0xF2A5C8), ebx)) goto loc_003BDA5D; /* je: equal / zero */

loc_003BDA1B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    edi = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDA28: ;
    SET_LO16(eax, MEM16(esi + 0x38));
    if (TEST_Z(LO8(eax), 2)) goto loc_003BDA40; /* je: equal / zero */

loc_003BDA30: ;
    if (TEST_NZ(LO8(eax), 0x10)) goto loc_003BDA40; /* jne: not equal / not zero */

loc_003BDA34: ;
    if (TEST_Z(HI8(eax), 2)) goto loc_003BDA45; /* je: equal / zero */

loc_003BDA39: ;
    edi = 0x1000000;
    goto loc_003BDA45;

loc_003BDA40: ;
    edi = 0x80000600u;

loc_003BDA45: ;
    eax = MEM32(0xF2A5C8);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    MEM32(0xF2A5C8) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

loc_003BDA5A: ;
    edi = MEM32(ebp + 8);

loc_003BDA5D: ;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xEF;
    PUSH32(esp, 0x14);
    g_seh_ebp = ebp; sub_003BDADC(); return; /* tail jmp 0x003BDADC */

}

/**
 * sub_003BDA65
 * Original: 0x003BDA65 - 0x003BDADC (119 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDA65(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDA65: ;
    if (TEST_Z(LO8(eax), 1)) goto loc_003BDAB6; /* je: equal / zero */

loc_003BDA69: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 3));
    MEM8(ebp + 8) = LO8(ecx);
    SET_LO8(eax, 1);
    ecx--;
    SET_LO8(eax, LO8(eax) << LO8(ecx));
    if (TEST_Z(MEM8(esi + 0x38), 1)) goto loc_003BDA96; /* je: equal / zero */

loc_003BDA7C: ;
    if (TEST_Z(MEM8(esi + 5), LO8(eax))) goto loc_003BDA8B; /* je: equal / zero */

loc_003BDA81: ;
    PUSH32(esp, MEM32(ebp + 8));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA61E(); /* call 0x003BA61E */

loc_003BDA8B: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD887(); /* call 0x003BD887 */

loc_003BDA91: ;
    g_seh_ebp = ebp; sub_003BDB35(); return; /* tail jmp 0x003BDB35 */

loc_003BDA96: ;
    SET_LO8(ecx, MEM8(esi + 5));
    if (TEST_Z(LO8(eax), LO8(ecx))) goto loc_003BDAAE; /* je: equal / zero */

loc_003BDA9D: ;
    PUSH32(esp, MEM32(ebp + 8));
    SET_LO8(eax, ~LO8(eax));
    SET_LO8(eax, LO8(eax) & LO8(ecx));
    ecx = edi;
    MEM8(esi + 5) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA61E(); /* call 0x003BA61E */

loc_003BDAAE: ;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xFE;
    PUSH32(esp, 0x10);
    g_seh_ebp = ebp; sub_003BDADC(); return; /* tail jmp 0x003BDADC */

loc_003BDAB6: ;
    if (TEST_Z(LO8(eax), 2)) goto loc_003BDAC2; /* je: equal / zero */

loc_003BDABA: ;
    SET_LO16(eax, LO16(eax) & 0xFFFD);
    PUSH32(esp, 0x11);
    goto loc_003BDAD8;

loc_003BDAC2: ;
    if (TEST_Z(LO8(eax), 4)) goto loc_003BDACE; /* je: equal / zero */

loc_003BDAC6: ;
    SET_LO16(eax, LO16(eax) & 0xFFFB);
    PUSH32(esp, 0x12);
    goto loc_003BDAD8;

loc_003BDACE: ;
    if (TEST_Z(LO8(eax), 8)) { g_seh_ebp = ebp; sub_003BDB26(); return; } /* je: equal / zero */

loc_003BDAD2: ;
    SET_LO16(eax, LO16(eax) & 0xFFF7);
    PUSH32(esp, 0x13);

loc_003BDAD8: ;
    MEM16(esi + 0x3A) = LO16(eax);

    g_seh_ebp = ebp; sub_003BDADC(); return; /* restored dropped fall-through to sub_003BDADC */
}

/**
 * sub_003BDADC
 * Original: 0x003BDADC - 0x003BDB9F (195 bytes, 62 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDADC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDADC: ;
    POP32(esp, ecx);
    MEM16(esi + 0x32) = LO16(ecx);
    SET_LO16(ecx, ZX8(MEM8(esi + 3)));
    eax = esi + 8;
    MEM16(esi + 0x34) = LO16(ecx);
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BE13B;
    MEM32(esi + 0x14) = edi;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = ebx;
    MEM32(esi + 0x1C) = ebx;
    MEM8(esi + 0x24) = LO8(ebx);
    MEM8(esi + 0x25) = LO8(ebx);
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 1;
    MEM16(esi + 0x36) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDB24: ;
    goto loc_003BDB35;

    MEM16(esi + 0x3A) = MEM16(esi + 0x3A) & 0;
    PUSH32(esp, edi);
    esi = esi + 8;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE13B(); /* call 0x003BE13B */

loc_003BDB35: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

    PUSH32(esp, 0);
    ecx = edi;
    esi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BDB54: ;
    MEM8(esi) = MEM8(esi) & 0xFE;
    MEM16(0xF2A622) = MEM16(0xF2A622) - 1;
    if (TEST_Z(MEM8(esi), 2)) goto loc_003BDB8E; /* je: equal / zero */

loc_003BDB63: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BDB6B: ;
    if (CMP_NE(esi, MEM32(0xF2A618))) goto loc_003BDB85; /* jne: not equal / not zero */

loc_003BDB73: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDB7E: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;

loc_003BDB85: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BDB8C: ;
    goto loc_003BDB9A;

loc_003BDB8E: ;
    PUSH32(esp, 0x80000100u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BDB9A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDB26
 * Original: 0x003BDB26 - 0x003BDB35 (15 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB26(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDB26: ;
    MEM16(esi + 0x3A) = MEM16(esi + 0x3A) & 0;
    PUSH32(esp, edi);
    esi = esi + 8;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE13B(); /* call 0x003BE13B */

    g_seh_ebp = ebp; sub_003BDB35(); return; /* restored dropped fall-through to sub_003BDB35 */
}

/**
 * sub_003BDB35
 * Original: 0x003BDB35 - 0x003BDB9F (106 bytes, 35 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB35(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDB35: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

    PUSH32(esp, 0);
    ecx = edi;
    esi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BDB54: ;
    MEM8(esi) = MEM8(esi) & 0xFE;
    MEM16(0xF2A622) = MEM16(0xF2A622) - 1;
    if (TEST_Z(MEM8(esi), 2)) goto loc_003BDB8E; /* je: equal / zero */

loc_003BDB63: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BDB6B: ;
    if (CMP_NE(esi, MEM32(0xF2A618))) goto loc_003BDB85; /* jne: not equal / not zero */

loc_003BDB73: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDB7E: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;

loc_003BDB85: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BDB8C: ;
    goto loc_003BDB9A;

loc_003BDB8E: ;
    PUSH32(esp, 0x80000100u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BDB9A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDB3C
 * Original: 0x003BDB3C - 0x003BDB9F (99 bytes, 30 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB3C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDB3C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDB49: ;
    PUSH32(esp, 0);
    ecx = edi;
    esi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BDB54: ;
    MEM8(esi) = MEM8(esi) & 0xFE;
    MEM16(0xF2A622) = MEM16(0xF2A622) - 1;
    if (TEST_Z(MEM8(esi), 2)) goto loc_003BDB8E; /* je: equal / zero */

loc_003BDB63: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BDB6B: ;
    if (CMP_NE(esi, MEM32(0xF2A618))) goto loc_003BDB85; /* jne: not equal / not zero */

loc_003BDB73: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDB7E: ;
    MEM32(0xF2A618) = MEM32(0xF2A618) & 0;

loc_003BDB85: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003BDB8C: ;
    goto loc_003BDB9A;

loc_003BDB8E: ;
    PUSH32(esp, 0x80000100u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BDB9A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDB9F
 * Original: 0x003BDB9F - 0x003BDC6F (208 bytes, 51 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB9F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BDB9F: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDBAE: ;
    ecx = 0; /* xor self */
    /* cmp eax, ecx - flags set for next jcc */
    PUSH32(esp, 4);
    SET_LO8(edx, 3);
    POP32(esp, esi);
    MEM32(ebp + -4) = 1;
    edi = 0x3BD837;
    if (CMP_EQ(eax, ecx)) { g_seh_ebp = ebp; sub_003BDC6F(); return; } /* je: equal / zero */

loc_003BDBC9: ;
    SET_LO8(ebx, MEM8(ebp + 0xC));
    if (CMP_B(MEM8(eax + 2), LO8(ebx))) { g_seh_ebp = ebp; sub_003BDC6F(); return; } /* jb: below (unsigned <) */

loc_003BDBD5: ;
    /* cmp MEM8(ebp + 0x14), LO8(ecx) - flags set for next jcc */
    eax = MEM32(ebp + 0x10);
    MEM32(0xF2A5C8) = eax;
    if (CMP_EQ(MEM8(ebp + 0x14), LO8(ecx))) goto loc_003BDBF3; /* je: equal / zero */

loc_003BDBE2: ;
    edx = 0; /* xor self */
    edx++;
    esi = edx;
    edi = 0x3BD863;
    MEM32(ebp + -4) = 2;

loc_003BDBF3: ;
    PUSH32(esp, MEM32(ebp + -4));
    SET_LO16(eax, ZX8(LO8(ebx)));
    MEM32(0xF2A5A0) = edi;
    edi = MEM32(ebp + 8);
    MEM8(0xF2A598) = 0x30;
    MEM8(0xF2A599) = 0x40;
    MEM32(0xF2A5A4) = edi;
    MEM32(0xF2A5A8) = ecx;
    MEM32(0xF2A5B0) = ecx;
    MEM32(0xF2A5AC) = ecx;
    MEM8(0xF2A5B4) = LO8(ecx);
    MEM8(0xF2A5B5) = LO8(ecx);
    MEM8(0xF2A5B6) = LO8(ecx);
    MEM8(0xF2A5C0) = 0x23;
    MEM8(0xF2A5C1) = LO8(edx);
    MEM16(0xF2A5C2) = LO16(esi);
    MEM16(0xF2A5C4) = LO16(eax);
    MEM16(0xF2A5C6) = LO16(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BDC61: ;
    PUSH32(esp, 0xF2A598);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDC6D: ;
    g_seh_ebp = ebp; sub_003BDC7F(); return; /* tail jmp 0x003BDC7F */

}

/**
 * sub_003BDC6F
 * Original: 0x003BDC6F - 0x003BDC7F (16 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDC6F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDC6F: ;
    PUSH32(esp, MEM32(ebp + 0x10));
    ecx = MEM32(ebp + 8);
    PUSH32(esp, 0x80000300u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A2(); /* call 0x003BA4A2 */

    g_seh_ebp = ebp; sub_003BDC7F(); return; /* restored dropped fall-through to sub_003BDC7F */
}

/**
 * sub_003BDC7F
 * Original: 0x003BDC7F - 0x003BDC86 (7 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDC7F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDC7F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BDC86
 * Original: 0x003BDC86 - 0x003BDCA8 (34 bytes, 9 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDC86(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDC86: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(esp + 8);
    PUSH32(esp, eax);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0xC3;
    MEM32(eax + 8) = 0x3BDB3C;
    MEM32(eax + 0xC) = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDCA5: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDCA8
 * Original: 0x003BDCA8 - 0x003BDCDA (50 bytes, 16 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDCA8(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDCA8: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDCB4: ;
    edx = MEM32(eax + 0x3C);
    ecx = eax + 8;
    MEM8(ecx) = 0x1C;
    PUSH32(esp, ecx);
    ecx = esi;
    MEM8(eax + 9) = 0x43;
    MEM32(eax + 0x10) = 0x3BDC86;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x18) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDCD6: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BDCDA
 * Original: 0x003BDCDA - 0x003BDD6B (145 bytes, 49 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDCDA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDCDA: ;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDCE7: ;
    edi = eax;
    SET_LO8(eax, MEM8(edi));
    if (TEST_Z(LO8(eax), 2)) goto loc_003BDCF7; /* je: equal / zero */

loc_003BDCEF: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDCF5: ;
    goto loc_003BDD66;

loc_003BDCF7: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    /* cmp MEM32(esi + 4), 0 - flags set for next jcc */
    ecx = ebx;
    if (CMP_GE(MEM32(esi + 4), 0)) goto loc_003BDD0F; /* jge: greater or equal (signed >=) */

loc_003BDD04: ;
    SET_LO8(eax, LO8(eax) | 8);
    MEM8(edi) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BDD0D: ;
    goto loc_003BDD65;

loc_003BDD0F: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    MEM8(esi) = 0x18;
    MEM8(esi + 1) = 5;
    eax = MEM32(edi + 0x3C);
    PUSH32(esp, esi);
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDD2D: ;
    MEM8(esi) = 0x28;
    MEM8(esi + 1) = 0x41;
    MEM32(esi + 8) = 0x3BDE71;
    MEM32(esi + 0xC) = ebx;
    eax = MEM32(edi + 0x3C);
    MEM32(esi + 0x10) = eax;
    eax = edi + 0x38;
    MEM32(esi + 0x18) = eax;
    eax = ZX8(MEM8(edi + 7));
    PUSH32(esp, esi);
    ecx = ebx;
    MEM32(esi + 0x14) = eax;
    MEM8(esi + 0x1C) = 2;
    MEM8(esi + 0x1D) = 1;
    MEM8(esi + 0x1E) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDD65: ;
    POP32(esp, esi);

loc_003BDD66: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDD6B
 * Original: 0x003BDD6B - 0x003BDDC6 (91 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDD6B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDD6B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDD77: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003BDD86; /* je: equal / zero */

loc_003BDD7E: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDD84: ;
    goto loc_003BDDC2;

loc_003BDD86: ;
    edx = MEM32(esp + 8);
    if (CMP_L(MEM32(edx + 4), 0)) goto loc_003BDD9C; /* jl: less (signed <) */

loc_003BDD90: ;
    PUSH32(esp, esi);
    MEM8(eax + 6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD9EE(); /* call 0x003BD9EE */

loc_003BDD9A: ;
    goto loc_003BDDC2;

loc_003BDD9C: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003BDDB3; /* jbe: below or equal (unsigned <=) */

loc_003BDDA5: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BDDB1: ;
    goto loc_003BDDC2;

loc_003BDDB3: ;
    PUSH32(esp, edx);
    ecx = esi;
    MEM32(edx + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDDC2: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDDC6
 * Original: 0x003BDDC6 - 0x003BDE21 (91 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDDC6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDDC6: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDDD2: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003BDDE1; /* je: equal / zero */

loc_003BDDD9: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDDDF: ;
    goto loc_003BDE1D;

loc_003BDDE1: ;
    edx = MEM32(esp + 8);
    if (CMP_GE(MEM32(edx + 4), 0)) goto loc_003BDE13; /* jge: greater or equal (signed >=) */

loc_003BDDEB: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003BDE02; /* jbe: below or equal (unsigned <=) */

loc_003BDDF4: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BDE00: ;
    goto loc_003BDE1D;

loc_003BDE02: ;
    PUSH32(esp, edx);
    ecx = esi;
    MEM32(edx + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDE11: ;
    goto loc_003BDE1D;

loc_003BDE13: ;
    PUSH32(esp, esi);
    MEM8(eax + 6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE068(); /* call 0x003BE068 */

loc_003BDE1D: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDE21
 * Original: 0x003BDE21 - 0x003BDE71 (80 bytes, 33 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE21(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BDE21: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDE2F: ;
    esi = eax;
    MEM8(esi) = MEM8(esi) | 2;
    ebx = 0; /* xor self */
    ebx++;
    MEM8(ebp + -4) = LO8(ebx);

loc_003BDE3A: ;
    if (TEST_Z(MEM8(esi + 5), LO8(ebx))) goto loc_003BDE51; /* je: equal / zero */

loc_003BDE3F: ;
    PUSH32(esp, MEM32(ebp + -4));
    ecx = MEM32(ebp + 8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA61E(); /* call 0x003BA61E */

loc_003BDE4A: ;
    SET_LO8(eax, LO8(ebx));
    SET_LO8(eax, ~LO8(eax));
    MEM8(esi + 5) = MEM8(esi + 5) & LO8(eax);

loc_003BDE51: ;
    ebx = ebx << 1;
    MEM8(ebp + -4) = MEM8(ebp + -4) + 1;
    SET_LO8(eax, MEM8(ebp + -4));
    if (CMP_BE(LO8(eax), MEM8(esi + 2))) { RECOMP_SLICE_POINT(); goto loc_003BDE3A; } /* jbe: below or equal (unsigned <=) */

loc_003BDE5E: ;
    /* test MEM8(esi), 8 - flags set for next jcc */
    _rccf = (TEST_Z(MEM8(esi), 8));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    POP32(esp, esi);
    POP32(esp, ebx);
    if (_rccf) goto loc_003BDE6D; /* je: equal / zero */

loc_003BDE65: ;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDE6D: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BDE71
 * Original: 0x003BDE71 - 0x003BDF3D (204 bytes, 68 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE71(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDE71: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDE7E: ;
    esi = eax;
    SET_LO8(ecx, MEM8(esi));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003BDE92; /* je: equal / zero */

loc_003BDE87: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDE8D: ;
    goto loc_003BDF38;

loc_003BDE92: ;
    eax = MEM32(esp + 0xC);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(eax + 4), ebx)) goto loc_003BDEDC; /* jl: less (signed <) */

loc_003BDE9E: ;
    if (CMP_NE(esi, MEM32(0xF2A618))) goto loc_003BDEB7; /* jne: not equal / not zero */

loc_003BDEA6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDEB1: ;
    MEM32(0xF2A618) = ebx;

loc_003BDEB7: ;
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BDEBF: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 2));
    SET_LO8(eax, 1);
    PUSH32(esp, edi);
    MEM8(esi + 6) = LO8(ebx);
    ecx++;
    SET_LO8(eax, LO8(eax) << LO8(ecx));
    SET_LO8(eax, LO8(eax) - 1);
    SET_LO8(eax, LO8(eax) & MEM8(esi + 0x38));
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE068(); /* call 0x003BE068 */

loc_003BDEDA: ;
    goto loc_003BDF37;

loc_003BDEDC: ;
    MEM8(esi + 6) = MEM8(esi + 6) + 1;
    if (CMP_BE(MEM8(esi + 6), 3)) goto loc_003BDEF3; /* jbe: below or equal (unsigned <=) */

loc_003BDEE5: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(esi) = LO8(ecx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BDEF1: ;
    goto loc_003BDF37;

loc_003BDEF3: ;
    MEM8(eax) = 0x30;
    MEM8(eax + 1) = 0x40;
    MEM32(eax + 8) = 0x3BDCDA;
    MEM32(eax + 0xC) = edi;
    MEM32(eax + 0x10) = ebx;
    MEM32(eax + 0x18) = ebx;
    MEM32(eax + 0x14) = ebx;
    MEM8(eax + 0x1C) = LO8(ebx);
    MEM8(eax + 0x1D) = LO8(ebx);
    MEM8(eax + 0x1E) = LO8(ebx);
    MEM8(eax + 0x28) = 2;
    MEM8(eax + 0x29) = 1;
    MEM16(eax + 0x2A) = LO16(ebx);
    SET_LO16(ecx, ZX8(MEM8(esi + 1)));
    MEM16(eax + 0x2C) = LO16(ecx);
    PUSH32(esp, eax);
    ecx = edi;
    MEM16(eax + 0x2E) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDF37: ;
    POP32(esp, ebx);

loc_003BDF38: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDF3D
 * Original: 0x003BDF3D - 0x003BDFFD (192 bytes, 64 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDF3D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDF3D: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0xC);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BDF49: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003BDF5B; /* je: equal / zero */

loc_003BDF50: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BDF56: ;
    goto loc_003BDFF9;

loc_003BDF5B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    edx = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), edx)) goto loc_003BDF8F; /* jge: greater or equal (signed >=) */

loc_003BDF67: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003BDF7E; /* jbe: below or equal (unsigned <=) */

loc_003BDF70: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA695(); /* call 0x003BA695 */

loc_003BDF7C: ;
    goto loc_003BDFF8;

loc_003BDF7E: ;
    MEM32(esi + 0x14) = 4;
    PUSH32(esp, esi);

loc_003BDF86: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BDF8D: ;
    goto loc_003BDFF8;

loc_003BDF8F: ;
    SET_LO16(ecx, MEM16(eax + 0x3A));
    /* test LO8(ecx), 1 - flags set for next jcc */
    MEM8(eax + 6) = LO8(edx);
    if (TEST_Z(LO8(ecx), 1)) goto loc_003BDFA4; /* je: equal / zero */

loc_003BDF9B: ;
    esi = 0; /* xor self */
    SET_LO16(ecx, LO16(ecx) & 0xFFFE);
    goto loc_003BDFB1;

loc_003BDFA4: ;
    if (TEST_Z(LO8(ecx), 2)) goto loc_003BDFF2; /* je: equal / zero */

loc_003BDFA9: ;
    esi = 0; /* xor self */
    esi++;
    SET_LO16(ecx, LO16(ecx) & 0xFFFD);

loc_003BDFB1: ;
    MEM16(eax + 0x3A) = LO16(ecx);
    ecx = eax + 8;
    MEM8(ecx) = 0x30;
    MEM8(eax + 9) = 0x40;
    MEM32(eax + 0x10) = 0x3BDDC6;
    MEM32(eax + 0x14) = edi;
    MEM32(eax + 0x18) = edx;
    MEM32(eax + 0x20) = edx;
    MEM32(eax + 0x1C) = edx;
    MEM8(eax + 0x24) = LO8(edx);
    MEM8(eax + 0x25) = LO8(edx);
    MEM8(eax + 0x26) = LO8(edx);
    MEM8(eax + 0x30) = 0x20;
    MEM8(eax + 0x31) = 1;
    MEM16(eax + 0x32) = LO16(esi);
    MEM16(eax + 0x34) = LO16(edx);
    MEM16(eax + 0x36) = LO16(edx);
    PUSH32(esp, ecx);
    { RECOMP_SLICE_POINT(); goto loc_003BDF86; }

loc_003BDFF2: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE068(); /* call 0x003BE068 */

loc_003BDFF8: ;
    POP32(esp, esi);

loc_003BDFF9: ;
    POP32(esp, edi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDFFD
 * Original: 0x003BDFFD - 0x003BE068 (107 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDFFD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDFFD: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE009: ;
    SET_LO8(ecx, MEM8(eax + 3));
    if (CMP_NE(LO8(ecx), MEM8(eax + 2))) goto loc_003BE048; /* jne: not equal / not zero */

loc_003BE011: ;
    ecx = MEM32(eax + 0x3C);
    MEM32(eax + 0x18) = ecx;
    ecx = eax + 0x38;
    MEM32(eax + 0x20) = ecx;
    ecx = ZX8(MEM8(eax + 7));
    MEM8(eax + 3) = 0;
    MEM8(eax + 8) = 0x28;
    MEM8(eax + 9) = 0x41;
    MEM32(eax + 0x10) = 0x3BDE71;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x1C) = ecx;
    MEM8(eax + 0x24) = 2;
    MEM8(eax + 0x25) = 1;
    MEM8(eax + 0x26) = 0;
    goto loc_003BE059;

loc_003BE048: ;
    edx = MEM32(esp + 8);
    SET_LO8(ecx, LO8(ecx) + 1);
    MEM8(eax + 3) = LO8(ecx);
    SET_LO16(ecx, ZX8(LO8(ecx)));
    MEM16(edx + 0x2C) = LO16(ecx);

loc_003BE059: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE064: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE068
 * Original: 0x003BE068 - 0x003BE099 (49 bytes, 21 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE068(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE068: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE078: ;
    SET_LO8(ebx, MEM8(eax + 4));
    ecx = 0; /* xor self */
    SET_LO8(edx, 1);
    MEM8(eax + 3) = LO8(ecx);
    MEM8(ebp + 0xB) = LO8(ebx);

loc_003BE085: ;
    if (TEST_NZ(MEM8(ebp + 0xB), LO8(edx))) { g_seh_ebp = ebp; sub_003BE099(); return; } /* jne: not equal / not zero */

loc_003BE08A: ;
    MEM8(eax + 3) = MEM8(eax + 3) + 1;
    SET_LO8(ebx, MEM8(eax + 3));
    SET_LO8(edx, LO8(edx) << 1);
    if (CMP_BE(LO8(ebx), MEM8(eax + 2))) { RECOMP_SLICE_POINT(); goto loc_003BE085; } /* jbe: below or equal (unsigned <=) */

loc_003BE097: ;
    g_seh_ebp = ebp; sub_003BE0A1(); return; /* tail jmp 0x003BE0A1 */

}

/**
 * sub_003BE099
 * Original: 0x003BE099 - 0x003BE0A1 (8 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE099(void)
{

loc_003BE099: ;
    SET_LO8(edx, ~LO8(edx));
    SET_LO8(edx, LO8(edx) & MEM8(eax + 4));
    MEM8(eax + 4) = LO8(edx);

    sub_003BE0A1(); return; /* restored dropped fall-through to sub_003BE0A1 */
}

/**
 * sub_003BE0A1
 * Original: 0x003BE0A1 - 0x003BE13B (154 bytes, 50 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE0A1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE0A1: ;
    SET_LO8(ebx, MEM8(eax + 3));
    /* cmp LO8(ebx), MEM8(eax + 2) - flags set for next jcc */
    MEM8(eax + 0x26) = LO8(ecx);
    MEM8(eax + 0x24) = 2;
    MEM32(eax + 0x14) = edi;
    esi = eax + 8;
    if (CMP_BE(LO8(ebx), MEM8(eax + 2))) goto loc_003BE0E4; /* jbe: below or equal (unsigned <=) */

loc_003BE0B6: ;
    edx = MEM32(eax + 0x3C);
    MEM32(eax + 0x18) = edx;
    edx = eax + 0x38;
    MEM32(eax + 0x20) = edx;
    edx = ZX8(MEM8(eax + 7));
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    MEM8(esi) = 0x28;
    MEM8(eax + 9) = 0x41;
    MEM32(eax + 0x10) = 0x3BDE71;
    MEM32(eax + 0x1C) = edx;
    MEM8(eax + 0x25) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BE0E2: ;
    goto loc_003BE12C;

loc_003BE0E4: ;
    /* cmp LO8(ebx), LO8(ecx) - flags set for next jcc */
    edx = eax + 0x38;
    PUSH32(esp, 4);
    MEM32(eax + 0x20) = edx;
    POP32(esp, edx);
    MEM16(eax + 0x32) = LO16(ecx);
    MEM8(eax + 0x31) = LO8(ecx);
    MEM8(eax + 0x25) = LO8(ecx);
    MEM32(eax + 0x18) = ecx;
    MEM8(eax + 9) = 0x40;
    MEM8(esi) = 0x30;
    MEM16(eax + 0x36) = LO16(edx);
    MEM32(eax + 0x1C) = edx;
    if (CMP_NE(LO8(ebx), LO8(ecx))) goto loc_003BE119; /* jne: not equal / not zero */

loc_003BE10C: ;
    MEM32(eax + 0x10) = 0x3BDF3D;
    MEM8(eax + 0x30) = 0xA0;
    goto loc_003BE128;

loc_003BE119: ;
    MEM32(eax + 0x10) = 0x3BDD6B;
    MEM8(eax + 0x30) = 0xA3;
    SET_LO16(ecx, ZX8(LO8(ebx)));

loc_003BE128: ;
    MEM16(eax + 0x34) = LO16(ecx);

loc_003BE12C: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE134: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE13B
 * Original: 0x003BE13B - 0x003BE154 (25 bytes, 9 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE13B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE13B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE147: ;
    /* test MEM8(eax), 2 - flags set for next jcc */
    PUSH32(esp, esi);
    if (TEST_Z(MEM8(eax), 2)) { g_seh_ebp = ebp; sub_003BE154(); return; } /* je: equal / zero */

loc_003BE14D: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BE152: ;
    g_seh_ebp = ebp; sub_003BE167(); return; /* tail jmp 0x003BE167 */

}

/**
 * sub_003BE154
 * Original: 0x003BE154 - 0x003BE167 (19 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE154(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE154: ;
    if (CMP_EQ(MEM16(eax + 0x3A), 0)) goto loc_003BE162; /* je: equal / zero */

loc_003BE15B: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD9EE(); /* call 0x003BD9EE */

loc_003BE160: ;
    g_seh_ebp = ebp; sub_003BE167(); return; /* tail jmp 0x003BE167 */

loc_003BE162: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE068(); /* call 0x003BE068 */

    g_seh_ebp = ebp; sub_003BE167(); return; /* restored dropped fall-through to sub_003BE167 */
}

/**
 * sub_003BE167
 * Original: 0x003BE167 - 0x003BE312 (427 bytes, 138 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE167(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE167: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    esi = eax;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xFE;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 3));
    ecx = 0; /* xor self */
    SET_LO8(ecx, LO8(eax));
    SET_LO8(ebx, 1);
    PUSH32(esp, 5);
    PUSH32(esp, eax);
    ecx--;
    SET_LO8(ebx, LO8(ebx) << LO8(ecx));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA22D(); /* call 0x003BA22D */

loc_003BE197: ;
    SET_LO16(edx, ZX8(MEM8(esi + 3)));
    MEM8(esi + 5) = MEM8(esi + 5) | LO8(ebx);
    ecx = 0; /* xor self */
    eax = esi + 8;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x20) = ecx;
    MEM32(esi + 0x1C) = ecx;
    MEM8(esi + 0x24) = LO8(ecx);
    MEM8(esi + 0x25) = LO8(ecx);
    MEM8(esi + 0x26) = LO8(ecx);
    MEM16(esi + 0x36) = LO16(ecx);
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BE13B;
    MEM32(esi + 0x14) = edi;
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 1;
    MEM16(esi + 0x32) = 0x10;
    MEM16(esi + 0x34) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE1E5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    esi = eax;
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE206: ;
    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_GE(MEM32(eax + 4), ebx)) goto loc_003BE219; /* jge: greater or equal (signed >=) */

loc_003BE211: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BE217: ;
    goto loc_003BE290;

loc_003BE219: ;
    SET_LO8(eax, MEM8(0xF2A56A));
    /* cmp LO8(eax), 7 - flags set for next jcc */
    MEM8(esi + 2) = LO8(eax);
    if (CMP_BE(LO8(eax), 7)) goto loc_003BE229; /* jbe: below or equal (unsigned <=) */

loc_003BE225: ;
    MEM8(esi + 2) = 7;

loc_003BE229: ;
    PUSH32(esp, 3);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE230: ;
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    MEM32(0xF2A618) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BE23E: ;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BE246: ;
    eax = esi + 8;
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(esi + 3) = 1;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BDFFD;
    MEM32(esi + 0x14) = edi;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = ebx;
    MEM32(esi + 0x1C) = ebx;
    MEM8(esi + 0x24) = LO8(ebx);
    MEM8(esi + 0x25) = LO8(ebx);
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 3;
    MEM16(esi + 0x32) = 8;
    MEM16(esi + 0x34) = 1;
    MEM16(esi + 0x36) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE290: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    esi = MEM32(esp + 8);
    eax = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), eax)) goto loc_003BE2B8; /* jge: greater or equal (signed >=) */

loc_003BE2AD: ;
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BE2B6: ;
    goto loc_003BE30E;

loc_003BE2B8: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    PUSH32(esp, 8);
    POP32(esp, ecx);
    PUSH32(esp, eax);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BE1EB;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x18) = 0xF2A568;
    MEM32(esi + 0x14) = ecx;
    MEM8(esi + 0x1C) = 2;
    MEM8(esi + 0x1D) = 1;
    MEM8(esi + 0x1E) = LO8(eax);
    MEM8(esi + 0x28) = 0xA0;
    MEM8(esi + 0x29) = 6;
    MEM16(esi + 0x2A) = 0x2900;
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE305: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE30D: ;
    POP32(esp, edi);

loc_003BE30E: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE16B
 * Original: 0x003BE16B - 0x003BE1EB (128 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE16B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE16B: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE179: ;
    esi = eax;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xFE;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 3));
    ecx = 0; /* xor self */
    SET_LO8(ecx, LO8(eax));
    SET_LO8(ebx, 1);
    PUSH32(esp, 5);
    PUSH32(esp, eax);
    ecx--;
    SET_LO8(ebx, LO8(ebx) << LO8(ecx));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA22D(); /* call 0x003BA22D */

loc_003BE197: ;
    SET_LO16(edx, ZX8(MEM8(esi + 3)));
    MEM8(esi + 5) = MEM8(esi + 5) | LO8(ebx);
    ecx = 0; /* xor self */
    eax = esi + 8;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x20) = ecx;
    MEM32(esi + 0x1C) = ecx;
    MEM8(esi + 0x24) = LO8(ecx);
    MEM8(esi + 0x25) = LO8(ecx);
    MEM8(esi + 0x26) = LO8(ecx);
    MEM16(esi + 0x36) = LO16(ecx);
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BE13B;
    MEM32(esi + 0x14) = edi;
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 1;
    MEM16(esi + 0x32) = 0x10;
    MEM16(esi + 0x34) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE1E5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE1EB
 * Original: 0x003BE1EB - 0x003BE296 (171 bytes, 54 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE1EB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE1EB: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE1F9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    esi = eax;
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE206: ;
    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_GE(MEM32(eax + 4), ebx)) goto loc_003BE219; /* jge: greater or equal (signed >=) */

loc_003BE211: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BE217: ;
    goto loc_003BE290;

loc_003BE219: ;
    SET_LO8(eax, MEM8(0xF2A56A));
    /* cmp LO8(eax), 7 - flags set for next jcc */
    MEM8(esi + 2) = LO8(eax);
    if (CMP_BE(LO8(eax), 7)) goto loc_003BE229; /* jbe: below or equal (unsigned <=) */

loc_003BE225: ;
    MEM8(esi + 2) = 7;

loc_003BE229: ;
    PUSH32(esp, 3);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE230: ;
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    MEM32(0xF2A618) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD8E4(); /* call 0x003BD8E4 */

loc_003BE23E: ;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BE246: ;
    eax = esi + 8;
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(esi + 3) = 1;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BDFFD;
    MEM32(esi + 0x14) = edi;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = ebx;
    MEM32(esi + 0x1C) = ebx;
    MEM8(esi + 0x24) = LO8(ebx);
    MEM8(esi + 0x25) = LO8(ebx);
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 3;
    MEM16(esi + 0x32) = 8;
    MEM16(esi + 0x34) = 1;
    MEM16(esi + 0x36) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE290: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE296
 * Original: 0x003BE296 - 0x003BE312 (124 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE296(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE296: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF2A5D0);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE2A2: ;
    esi = MEM32(esp + 8);
    eax = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), eax)) goto loc_003BE2B8; /* jge: greater or equal (signed >=) */

loc_003BE2AD: ;
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDCA8(); /* call 0x003BDCA8 */

loc_003BE2B6: ;
    goto loc_003BE30E;

loc_003BE2B8: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    PUSH32(esp, 8);
    POP32(esp, ecx);
    PUSH32(esp, eax);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BE1EB;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x18) = 0xF2A568;
    MEM32(esi + 0x14) = ecx;
    MEM8(esi + 0x1C) = 2;
    MEM8(esi + 0x1D) = 1;
    MEM8(esi + 0x1E) = LO8(eax);
    MEM8(esi + 0x28) = 0xA0;
    MEM8(esi + 0x29) = 6;
    MEM16(esi + 0x2A) = 0x2900;
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE305: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE30D: ;
    POP32(esp, edi);

loc_003BE30E: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE312
 * Original: 0x003BE312 - 0x003BE428 (278 bytes, 82 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE312(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE312: ;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003BE320: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF2A5D0);
    edi = eax;
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE32D: ;
    esi = MEM32(ebp + 8);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ebx)) { g_seh_ebp = ebp; sub_003BE428(); return; } /* jl: less (signed <) */

loc_003BE33B: ;
    SET_LO16(ecx, MEM16(0xF2A56A));
    edx = 0; /* xor self */
    /* cmp LO16(ecx), 0x30 - flags set for next jcc */
    eax = 0xF2A568;
    if (CMP_A(LO16(ecx), 0x30)) { g_seh_ebp = ebp; sub_003BE428(); return; } /* ja: above (unsigned >) */

loc_003BE353: ;
    ecx = ZX16(LO16(ecx));
    /* cmp MEM32(esi + 0x14), ecx - flags set for next jcc */
    MEM32(ebp + 8) = ecx;
    if (CMP_B(MEM32(esi + 0x14), ecx)) { g_seh_ebp = ebp; sub_003BE428(); return; } /* jb: below (unsigned <) */

loc_003BE362: ;
    SET_LO8(eax, MEM8(eax));
    ecx = ZX8(LO8(eax));
    edx = edx + ecx;
    if (CMP_EQ(LO8(eax), LO8(ebx))) { g_seh_ebp = ebp; sub_003BE428(); return; } /* je: equal / zero */

loc_003BE371: ;
    if (CMP_AE(edx, MEM32(ebp + 8))) { g_seh_ebp = ebp; sub_003BE428(); return; } /* jae: above or equal (unsigned >=) */

loc_003BE37A: ;
    eax = edx + 0xF2A568;
    if (CMP_NE(MEM8(eax + 1), 5)) { RECOMP_SLICE_POINT(); goto loc_003BE362; } /* jne: not equal / not zero */

loc_003BE386: ;
    if (CMP_A(MEM16(eax + 4), 4)) goto loc_003BE395; /* ja: above (unsigned >) */

loc_003BE38D: ;
    SET_LO8(ecx, MEM8(eax + 4));
    MEM8(edi + 7) = LO8(ecx);
    goto loc_003BE399;

loc_003BE395: ;
    MEM8(edi + 7) = 4;

loc_003BE399: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(edi + 1) = LO8(ecx);
    MEM8(esi) = 0x20;
    MEM8(esi + 1) = 2;
    MEM32(esi + 8) = ebx;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 0x15) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 3));
    ecx = MEM32(ebp + 0xC);
    SET_LO8(eax, LO8(eax) & 3);
    MEM8(esi + 0x16) = LO8(eax);
    MEM8(esi + 0x17) = 0x10;
    SET_LO16(eax, ZX8(MEM8(edi + 7)));
    PUSH32(esp, esi);
    MEM16(esi + 0x1C) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE3CD: ;
    if (TEST_S(eax, eax)) { g_seh_ebp = ebp; sub_003BE428(); return; } /* jl: less (signed <) */

loc_003BE3D1: ;
    eax = MEM32(esi + 0x10);
    MEM32(edi + 0x3C) = eax;
    edi = MEM32(ebp + 0xC);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3BE296;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = ebx;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x14) = ebx;
    MEM8(esi + 0x1C) = LO8(ebx);
    MEM8(esi + 0x1D) = LO8(ebx);
    MEM8(esi + 0x1E) = LO8(ebx);
    MEM8(esi + 0x28) = LO8(ebx);
    MEM8(esi + 0x29) = 9;
    SET_LO16(eax, ZX8(MEM8(0xF2A56D)));
    PUSH32(esp, ebx);
    MEM16(esi + 0x2A) = LO16(eax);
    MEM16(esi + 0x2C) = LO16(ebx);
    MEM16(esi + 0x2E) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE41E: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE426: ;
    g_seh_ebp = ebp; sub_003BE431(); return; /* tail jmp 0x003BE431 */

}

/**
 * sub_003BE428
 * Original: 0x003BE428 - 0x003BE431 (9 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE428(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE428: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BDC86(); /* call 0x003BDC86 */

    g_seh_ebp = ebp; sub_003BE431(); return; /* restored dropped fall-through to sub_003BE431 */
}

/**
 * sub_003BE431
 * Original: 0x003BE431 - 0x003BE51A (233 bytes, 77 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE431(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE431: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

    eax = MEM32(0xF2A624);
    if (TEST_Z(MEM8(eax), 1)) goto loc_003BE466; /* je: equal / zero */

loc_003BE45B: ;
    ecx = eax;

loc_003BE45D: ;
    ecx = ecx + 0x40;
    esi++;
    if (TEST_NZ(MEM8(ecx), 1)) { RECOMP_SLICE_POINT(); goto loc_003BE45D; } /* jne: not equal / not zero */

loc_003BE466: ;
    MEM16(0xF2A622) = MEM16(0xF2A622) + 1;
    PUSH32(esp, ebp);
    ebp = MEM32(esp + 0x10);
    esi = esi << 6;
    PUSH32(esp, edi);
    esi = esi + eax;
    PUSH32(esp, esi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BE480: ;
    SET_LO8(eax, MEM8(esi));
    SET_LO8(eax, LO8(eax) & 0xF5);
    edi = esi + 8;
    SET_LO8(eax, LO8(eax) | 1);
    PUSH32(esp, edi);
    ecx = ebp;
    MEM8(esi) = LO8(eax);
    MEM8(esi + 5) = LO8(ebx);
    MEM8(esi + 6) = LO8(ebx);
    MEM8(edi) = 0x20;
    MEM8(esi + 9) = 0x82;
    MEM32(esi + 0x10) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE4A3: ;
    PUSH32(esp, 0x30);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    PUSH32(esp, 0x3BD91A);
    PUSH32(esp, 0xF2A5F8);
    MEM8(edi) = LO8(eax);
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BE312;
    MEM32(esi + 0x14) = ebp;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = 0xF2A568;
    MEM32(esi + 0x1C) = eax;
    MEM8(esi + 0x24) = 2;
    MEM8(esi + 0x25) = 1;
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x80;
    MEM8(esi + 0x31) = 6;
    MEM16(esi + 0x32) = 0x200;
    MEM16(esi + 0x34) = LO16(ebx);
    MEM16(esi + 0x36) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE4F5: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE4FB: ;
    PUSH32(esp, edi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE503: ;
    POP32(esp, edi);
    POP32(esp, ebp);
    goto loc_003BE515;

loc_003BE507: ;
    ecx = MEM32(esp + 0xC);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BE515: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE438
 * Original: 0x003BE438 - 0x003BE51A (226 bytes, 72 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE438(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE438: ;
    SET_LO16(eax, MEM16(0xF2A622));
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = 0; /* xor self */
    esi = 0; /* xor self */
    if (CMP_AE(LO16(eax), MEM16(0xF2A620))) goto loc_003BE507; /* jae: above or equal (unsigned >=) */

loc_003BE451: ;
    eax = MEM32(0xF2A624);
    if (TEST_Z(MEM8(eax), 1)) goto loc_003BE466; /* je: equal / zero */

loc_003BE45B: ;
    ecx = eax;

loc_003BE45D: ;
    ecx = ecx + 0x40;
    esi++;
    if (TEST_NZ(MEM8(ecx), 1)) { RECOMP_SLICE_POINT(); goto loc_003BE45D; } /* jne: not equal / not zero */

loc_003BE466: ;
    MEM16(0xF2A622) = MEM16(0xF2A622) + 1;
    PUSH32(esp, ebp);
    ebp = MEM32(esp + 0x10);
    esi = esi << 6;
    PUSH32(esp, edi);
    esi = esi + eax;
    PUSH32(esp, esi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003BE480: ;
    SET_LO8(eax, MEM8(esi));
    SET_LO8(eax, LO8(eax) & 0xF5);
    edi = esi + 8;
    SET_LO8(eax, LO8(eax) | 1);
    PUSH32(esp, edi);
    ecx = ebp;
    MEM8(esi) = LO8(eax);
    MEM8(esi + 5) = LO8(ebx);
    MEM8(esi + 6) = LO8(ebx);
    MEM8(edi) = 0x20;
    MEM8(esi + 9) = 0x82;
    MEM32(esi + 0x10) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE4A3: ;
    PUSH32(esp, 0x30);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    PUSH32(esp, 0x3BD91A);
    PUSH32(esp, 0xF2A5F8);
    MEM8(edi) = LO8(eax);
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3BE312;
    MEM32(esi + 0x14) = ebp;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = 0xF2A568;
    MEM32(esi + 0x1C) = eax;
    MEM8(esi + 0x24) = 2;
    MEM8(esi + 0x25) = 1;
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x80;
    MEM8(esi + 0x31) = 6;
    MEM16(esi + 0x32) = 0x200;
    MEM16(esi + 0x34) = LO16(ebx);
    MEM16(esi + 0x36) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C15FC); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE4F5: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BD98B(); /* call 0x003BD98B */

loc_003BE4FB: ;
    PUSH32(esp, edi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003BE503: ;
    POP32(esp, edi);
    POP32(esp, ebp);
    goto loc_003BE515;

loc_003BE507: ;
    ecx = MEM32(esp + 0xC);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003BE515: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE51A
 * Original: 0x003BE51A - 0x003BE5A9 (143 bytes, 56 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE51A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE51A: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = ecx;
    /* cmp MEM8(esi + 0x460), 0 - flags set for next jcc */
    ebp = edx;
    SET_LO8(ebx, 1);
    if (CMP_BE(MEM8(esi + 0x460), 0)) goto loc_003BE5A4; /* jbe: below or equal (unsigned <=) */

loc_003BE52D: ;
    MEM8(esp + 0xC) = LO8(ebx);
    PUSH32(esp, edi);

loc_003BE532: ;
    SET_LO16(eax, ZX8(LO8(ebx)));
    if (TEST_Z(MEM16(ebp), LO16(eax))) goto loc_003BE58F; /* je: equal / zero */

loc_003BE53C: ;
    ecx = 0; /* xor self */
    SET_LO16(ecx, MEM16(ebp + 2));
    ecx = ecx & eax;
    if (TEST_Z(LO16(ecx), LO16(ecx))) goto loc_003BE571; /* je: equal / zero */

loc_003BE549: ;
    ecx = esi + 0x461;
    SET_LO8(eax, MEM8(ecx));
    if (TEST_Z(LO8(ebx), LO8(eax))) goto loc_003BE561; /* je: equal / zero */

loc_003BE555: ;
    PUSH32(esp, MEM32(esp + 0x10));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA75B(); /* call 0x003BA75B */

loc_003BE55F: ;
    goto loc_003BE565;

loc_003BE561: ;
    SET_LO8(eax, LO8(eax) | LO8(ebx));
    MEM8(ecx) = LO8(eax);

loc_003BE565: ;
    PUSH32(esp, MEM32(esp + 0x10));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA42B(); /* call 0x003BA42B */

loc_003BE56F: ;
    goto loc_003BE58F;

loc_003BE571: ;
    edi = esi + 0x461;
    SET_LO8(eax, MEM8(edi));
    if (TEST_Z(LO8(ebx), LO8(eax))) goto loc_003BE58F; /* je: equal / zero */

loc_003BE57D: ;
    PUSH32(esp, MEM32(esp + 0x10));
    SET_LO8(ecx, LO8(ebx));
    SET_LO8(ecx, ~LO8(ecx));
    SET_LO8(ecx, LO8(ecx) & LO8(eax));
    PUSH32(esp, esi);
    MEM8(edi) = LO8(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA75B(); /* call 0x003BA75B */

loc_003BE58F: ;
    MEM8(esp + 0x10) = MEM8(esp + 0x10) + 1;
    SET_LO8(eax, MEM8(esp + 0x10));
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(eax, LO8(eax) - 1);
    if (CMP_B(LO8(eax), MEM8(esi + 0x460))) { RECOMP_SLICE_POINT(); goto loc_003BE532; } /* jb: below (unsigned <) */

loc_003BE5A3: ;
    POP32(esp, edi);

loc_003BE5A4: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE5A9
 * Original: 0x003BE5A9 - 0x003BE5F6 (77 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE5A9(void)
{
    uint32_t ebp;

loc_003BE5A9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    eax = MEM32(ebp + 8);
    ecx = MEM32(ebp + 0x10);
    edx = MEM32(ebp + 0xC);
    MEM32(eax + 0x470) = ecx;
    ecx = MEM32(ebp + 0x14);
    PUSH32(esp, esi);
    MEM32(eax + 0x474) = ecx;
    ecx = MEM32(eax);
    MEM16(ebp + 8) = 0x10;
    esi = MEM32(ebp + 8);
    MEM32(ecx + edx * 4 + 0x50) = esi;
    esi = eax + 0x4A0;
    PUSH32(esp, esi);
    edx = edx | 0xFFFFFFFFu;
    PUSH32(esp, edx);
    ecx = 0xFFF0BDC0u;
    PUSH32(esp, ecx);
    eax = eax + 0x478;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1618); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE5F1: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BE5F6
 * Original: 0x003BE5F6 - 0x003BE613 (29 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE5F6(void)
{
    uint32_t ebp;

loc_003BE5F6: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    eax = MEM32(ebp + 8);
    eax = MEM32(eax);
    ecx = MEM32(ebp + 0xC);
    MEM16(ebp + -4) = 1;
    edx = MEM32(ebp + -4);
    MEM32(eax + ecx * 4 + 0x50) = edx;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE613
 * Original: 0x003BE613 - 0x003BE63E (43 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE613(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE613: ;
    ecx = MEM32(esp + 8);
    eax = ecx + 0x470;
    edx = MEM32(eax);
    ecx = ecx + 0x474;
    /* test edx, edx - flags set for next jcc */
    PUSH32(esp, esi);
    esi = MEM32(ecx);
    if (TEST_Z(edx, edx)) goto loc_003BE63A; /* je: equal / zero */

loc_003BE62C: ;
    MEM32(eax) = MEM32(eax) & 0;
    MEM32(ecx) = MEM32(ecx) & 0;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x80000600u);
    { uint32_t _icall_t = edx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE63A: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BE63E
 * Original: 0x003BE63E - 0x003BE6FD (191 bytes, 64 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE63E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE63E: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x1C;
    PUSH32(esp, esi);
    esi = ecx;
    eax = MEM32(esi);
    edx = ZX8(MEM8(esi + 0x460));
    ecx = eax + 0x54;
    eax = MEM32(ecx);
    PUSH32(esp, edi);
    eax = 0; /* xor self */
    /* test edx, edx - flags set for next jcc */
    edi = ebp + -8;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(ebp + -12) = 1;
    if (CMP_BE(edx & edx, 0)) goto loc_003BE6EF; /* jbe: below or equal (unsigned <=) */

loc_003BE66B: ;
    MEM32(ebp + -16) = ecx;
    MEM32(ebp + -20) = edx;
    PUSH32(esp, ebx);

loc_003BE672: ;
    edi = MEM32(ecx);
    MEM32(ebp + -4) = edi;
    if (TEST_Z(MEM8(ebp + -2), 0x10)) goto loc_003BE6BC; /* je: equal / zero */

loc_003BE67D: ;
    ecx = MEM32(esi + 0x474);
    ebx = esi + 0x470;
    eax = MEM32(ebx);
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -24) = ecx;
    if (TEST_Z(eax, eax)) goto loc_003BE6BC; /* je: equal / zero */

loc_003BE695: ;
    eax = esi + 0x478;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C161C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE6A2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -24));
    MEM32(ebx) = MEM32(ebx) & 0;
    MEM32(esi + 0x474) = MEM32(esi + 0x474) & 0;
    edi = edi & 0x200;
    edi = edi << 0xF;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(ebp + -28); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE6BC: ;
    if (TEST_Z(MEM8(ebp + -2), 1)) goto loc_003BE6D3; /* je: equal / zero */

loc_003BE6C2: ;
    eax = MEM32(ebp + -12);
    MEM16(ebp + -8) = MEM16(ebp + -8) | LO16(eax);
    if (TEST_Z(MEM8(ebp + -4), 1)) goto loc_003BE6D3; /* je: equal / zero */

loc_003BE6CF: ;
    MEM16(ebp + -6) = MEM16(ebp + -6) | LO16(eax);

loc_003BE6D3: ;
    MEM16(ebp + -4) = MEM16(ebp + -4) & 0;
    ecx = MEM32(ebp + -16);
    eax = MEM32(ebp + -4);
    MEM32(ebp + -12) = MEM32(ebp + -12) << 1;
    MEM32(ecx) = eax;
    ecx = ecx + 4;
    MEM32(ebp + -20) = MEM32(ebp + -20) - 1;
    MEM32(ebp + -16) = ecx;
    if ((MEM32(ebp + -20) != 0)) { RECOMP_SLICE_POINT(); goto loc_003BE672; } /* jne: not equal / not zero */

loc_003BE6EE: ;
    POP32(esp, ebx);

loc_003BE6EF: ;
    edx = ebp + -8;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE51A(); /* call 0x003BE51A */

loc_003BE6F9: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE6FD
 * Original: 0x003BE6FD - 0x003BE710 (19 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE6FD(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE6FD: ;
    eax = MEM32(0xF45F08);
    if (TEST_Z(eax, eax)) goto loc_003BE70F; /* je: equal / zero */

loc_003BE706: ;
    ecx = MEM32(eax + 0x18);
    MEM32(0xF45F08) = ecx;

loc_003BE70F: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BE710
 * Original: 0x003BE710 - 0x003BE741 (49 bytes, 16 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE710(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE710: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = edx;
    MEM32(ebp + -12) = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE727: ;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE6FD(); /* call 0x003BE6FD */

loc_003BE72F: ;
    esi = eax;
    if (TEST_NZ(esi, esi)) { g_seh_ebp = ebp; sub_003BE741(); return; } /* jne: not equal / not zero */

loc_003BE735: ;
    MEM32(ebp + -8) = 0x80000100u;
    g_seh_ebp = ebp; sub_003BE86F(); return; /* tail jmp 0x003BE86F */

}

/**
 * sub_003BE741
 * Original: 0x003BE741 - 0x003BE86F (302 bytes, 108 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE741(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE741: ;
    PUSH32(esp, edi);
    eax = 0; /* xor self */
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = esi;
    eax = eax - MEM32(0xF45F00);
    MEM32(esi + 0x14) = eax;
    SET_LO8(eax, MEM8(ebx + 0x16));
    MEM8(esi + 0x11) = LO8(eax);
    SET_LO8(eax, MEM8(ebx + 0x17));
    MEM8(esi + 0x13) = LO8(eax);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebx + 0x1E));
    PUSH32(esp, eax);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 0x11));
    PUSH32(esp, eax);
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(ebx + 0x1C));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB01B(); /* call 0x003BB01B */

loc_003BE77A: ;
    MEM16(esi + 0x22) = LO16(eax);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebx + 0x14));
    eax = eax ^ MEM32(esi);
    eax = eax & 0x7F;
    MEM32(esi) = MEM32(esi) ^ eax;
    eax = ZX8(MEM8(ebx + 0x15));
    ecx = MEM32(esi);
    eax = eax << 7;
    eax = eax ^ ecx;
    eax = eax & 0x780;
    eax = eax ^ ecx;
    /* cmp MEM8(esi + 0x11), 0 - flags set for next jcc */
    MEM32(esi) = eax;
    if (CMP_NE(MEM8(esi + 0x11), 0)) goto loc_003BE7AD; /* jne: not equal / not zero */

loc_003BE7A4: ;
    eax = eax & 0xFFFFE7FFu;
    MEM32(esi) = eax;
    goto loc_003BE7C7;

loc_003BE7AD: ;
    /* test MEM8(ebx + 0x15), 0x80 - flags set for next jcc */
    PUSH32(esp, 0);
    POP32(esp, ecx);
    SET_LO8(ecx, (TEST_NZ(MEM8(ebx + 0x15), 0x80)) ? 1 : 0); /* setne */
    ecx++;
    ecx = ecx << 0xB;
    ecx = ecx ^ eax;
    ecx = ecx & 0x1800;
    ecx = ecx ^ eax;
    MEM32(esi) = ecx;

loc_003BE7C7: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebx + 0x1E));
    ecx = ecx & 0xFFFF5FFFu;
    eax = eax & 1;
    eax = eax | 2;
    eax = eax << 0xD;
    eax = eax | ecx;
    MEM32(esi) = eax;
    ecx = ZX16(MEM16(ebx + 0x1C));
    ecx = ecx << 0x10;
    ecx = ecx ^ eax;
    ecx = ecx & 0x7FF0000;
    ecx = ecx ^ eax;
    eax = 0; /* xor self */
    MEM32(esi) = ecx;
    MEM32(esi + 0xC) = eax;
    MEM32(esi + 8) = eax;
    MEM32(esi + 4) = eax;
    edx = MEM32(ebx + 0x18);
    if (CMP_EQ(edx, eax)) goto loc_003BE82D; /* je: equal / zero */

loc_003BE806: ;
    eax = ecx;
    edi = 0; /* xor self */
    ecx = ecx >> 7;
    ecx = ecx & 0xF;
    edi++;
    eax = eax & 0x1800;
    edi = edi << LO8(ecx);
    if (CMP_NE(eax, 0x1000)) goto loc_003BE822; /* jne: not equal / not zero */

loc_003BE81F: ;
    edi = edi << 0x10;

loc_003BE822: ;
    if (TEST_Z(MEM32(edx), edi)) goto loc_003BE82D; /* je: equal / zero */

loc_003BE826: ;
    MEM32(esi + 8) = 2;

loc_003BE82D: ;
    SET_LO8(eax, MEM8(esi + 0x11));
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    POP32(esp, edi);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BE848; /* je: equal / zero */

loc_003BE835: ;
    if (CMP_EQ(LO8(eax), 2)) goto loc_003BE848; /* je: equal / zero */

loc_003BE839: ;
    ecx = MEM32(ebp + -12);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEE22(); /* call 0x003BEE22 */

loc_003BE843: ;
    MEM32(ebp + -8) = eax;
    goto loc_003BE852;

loc_003BE848: ;
    ecx = MEM32(ebp + -12);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BED08(); /* call 0x003BED08 */

loc_003BE852: ;
    if (CMP_L(MEM32(ebp + -8), 0)) goto loc_003BE85D; /* jl: less (signed <) */

loc_003BE858: ;
    MEM32(ebx + 0x10) = esi;
    g_seh_ebp = ebp; sub_003BE86F(); return; /* tail jmp 0x003BE86F */

loc_003BE85D: ;
    MEM32(ebx + 0x10) = MEM32(ebx + 0x10) & 0;
    eax = MEM32(0xF45F08);
    MEM32(esi + 0x18) = eax;
    MEM32(0xF45F08) = esi;

    g_seh_ebp = ebp; sub_003BE86F(); return; /* restored dropped fall-through to sub_003BE86F */
}

/**
 * sub_003BE86F
 * Original: 0x003BE86F - 0x003BE884 (21 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE86F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE86F: ;
    esi = MEM32(ebp + -8);
    SET_LO8(ecx, MEM8(ebp + -1));
    MEM32(ebx + 4) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE87E: ;
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE884
 * Original: 0x003BE884 - 0x003BE8A5 (33 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE884(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE884: ;
    ecx = MEM32(edx + 0x10);
    eax = MEM32(ecx + 8);
    eax = eax & 1;
    MEM32(edx + 0x14) = eax;
    if (CMP_NE(MEM8(ecx + 0x26), 0)) goto loc_003BE89C; /* jne: not equal / not zero */

loc_003BE896: ;
    if (CMP_EQ(MEM8(ecx + 0x27), 0)) goto loc_003BE8A2; /* je: equal / zero */

loc_003BE89C: ;
    eax = eax | 2;
    MEM32(edx + 0x14) = eax;

loc_003BE8A2: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE8A5
 * Original: 0x003BE8A5 - 0x003BE8D3 (46 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE8A5(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE8A5: ;
    eax = MEM32(edx + 0x10);
    edx = MEM32(edx + 0x14);
    if (TEST_Z(LO8(edx), 4)) goto loc_003BE8B4; /* je: equal / zero */

loc_003BE8B0: ;
    MEM32(eax + 8) = MEM32(eax + 8) & 0xFFFFFFFDu;

loc_003BE8B4: ;
    if (TEST_Z(LO8(edx), 8)) goto loc_003BE8BD; /* je: equal / zero */

loc_003BE8B9: ;
    MEM32(eax + 8) = MEM32(eax + 8) | 2;

loc_003BE8BD: ;
    if (TEST_NZ(LO8(edx), 1)) goto loc_003BE8D0; /* jne: not equal / not zero */

loc_003BE8C2: ;
    ecx = MEM32(eax + 8);
    if (TEST_Z(LO8(ecx), 1)) goto loc_003BE8D0; /* je: equal / zero */

loc_003BE8CA: ;
    ecx = ecx & 0xFFFFFFFEu;
    MEM32(eax + 8) = ecx;

loc_003BE8D0: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE8D3
 * Original: 0x003BE8D3 - 0x003BE8F8 (37 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE8D3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE8D3: ;
    eax = MEM32(ecx + 0x41C);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003BE8ED; /* je: equal / zero */

loc_003BE8E0: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003BE8E0; } /* jne: not equal / not zero */

loc_003BE8E9: ;
    if (TEST_NZ(esi, esi)) { g_seh_ebp = ebp; sub_003BE8F8(); return; } /* jne: not equal / not zero */

loc_003BE8ED: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x41C) = eax;
    g_seh_ebp = ebp; sub_003BE8FE(); return; /* tail jmp 0x003BE8FE */

}

/**
 * sub_003BE8F8
 * Original: 0x003BE8F8 - 0x003BE8FE (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE8F8(void)
{

loc_003BE8F8: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

    sub_003BE8FE(); return; /* restored dropped fall-through to sub_003BE8FE */
}

/**
 * sub_003BE8FE
 * Original: 0x003BE8FE - 0x003BE90C (14 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE8FE(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE8FE: ;
    eax = ecx + 0x420;
    if (CMP_NE(edx, MEM32(eax))) goto loc_003BE90A; /* jne: not equal / not zero */

loc_003BE908: ;
    MEM32(eax) = esi;

loc_003BE90A: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE90C
 * Original: 0x003BE90C - 0x003BE931 (37 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE90C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE90C: ;
    eax = MEM32(ecx + 0x424);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003BE926; /* je: equal / zero */

loc_003BE919: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003BE919; } /* jne: not equal / not zero */

loc_003BE922: ;
    if (TEST_NZ(esi, esi)) { g_seh_ebp = ebp; sub_003BE931(); return; } /* jne: not equal / not zero */

loc_003BE926: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x424) = eax;
    g_seh_ebp = ebp; sub_003BE937(); return; /* tail jmp 0x003BE937 */

}

/**
 * sub_003BE931
 * Original: 0x003BE931 - 0x003BE937 (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE931(void)
{

loc_003BE931: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

    sub_003BE937(); return; /* restored dropped fall-through to sub_003BE937 */
}

/**
 * sub_003BE937
 * Original: 0x003BE937 - 0x003BE945 (14 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE937(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE937: ;
    eax = ecx + 0x428;
    if (CMP_NE(edx, MEM32(eax))) goto loc_003BE943; /* jne: not equal / not zero */

loc_003BE941: ;
    MEM32(eax) = esi;

loc_003BE943: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE945
 * Original: 0x003BE945 - 0x003BE964 (31 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE945(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE945: ;
    eax = MEM32(ecx + 0x28);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003BE95C; /* je: equal / zero */

loc_003BE94F: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003BE94F; } /* jne: not equal / not zero */

loc_003BE958: ;
    if (TEST_NZ(esi, esi)) { g_seh_ebp = ebp; sub_003BE964(); return; } /* jne: not equal / not zero */

loc_003BE95C: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x28) = eax;
    g_seh_ebp = ebp; sub_003BE96A(); return; /* tail jmp 0x003BE96A */

}

/**
 * sub_003BE964
 * Original: 0x003BE964 - 0x003BE96A (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE964(void)
{

loc_003BE964: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

    sub_003BE96A(); return; /* restored dropped fall-through to sub_003BE96A */
}

/**
 * sub_003BE96A
 * Original: 0x003BE96A - 0x003BE974 (10 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE96A(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BE96A: ;
    if (CMP_NE(edx, MEM32(ecx + 0x2C))) goto loc_003BE972; /* jne: not equal / not zero */

loc_003BE96F: ;
    MEM32(ecx + 0x2C) = esi;

loc_003BE972: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE974
 * Original: 0x003BE974 - 0x003BE9EA (118 bytes, 46 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE974(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE974: ;
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    edi = edx;
    if (CMP_EQ(MEM8(edi + 0x26), 0)) goto loc_003BE9E7; /* je: equal / zero */

loc_003BE97E: ;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    if ((eax == 0)) goto loc_003BE9A6; /* je: equal / zero */

loc_003BE989: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BE998; /* je: equal / zero */

loc_003BE98D: ;
    eax--;
    if ((eax != 0)) goto loc_003BE9E5; /* jne: not equal / not zero */

loc_003BE990: ;
    ebx = edi + 0x28;
    ebp = edi + 0x2C;
    goto loc_003BE9B2;

loc_003BE998: ;
    ebx = ecx + 0x424;
    ebp = ecx + 0x428;
    goto loc_003BE9B2;

loc_003BE9A6: ;
    ebx = ecx + 0x41C;
    ebp = ecx + 0x420;

loc_003BE9B2: ;
    PUSH32(esp, esi);

loc_003BE9B3: ;
    esi = MEM32(ebx);
    if (CMP_NE(MEM32(esi + 0x10), edi)) goto loc_003BE9D1; /* jne: not equal / not zero */

loc_003BE9BA: ;
    eax = MEM32(esi + 0x24);
    MEM32(ebx) = eax;
    MEM32(esi + 4) = 0xC000000Fu;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BE9CF: ;
    goto loc_003BE9D8;

loc_003BE9D1: ;
    MEM32(esp + 0x10) = esi;
    ebx = esi + 0x24;

loc_003BE9D8: ;
    if (CMP_NE(MEM32(ebp), esi)) { RECOMP_SLICE_POINT(); goto loc_003BE9B3; } /* jne: not equal / not zero */

loc_003BE9DD: ;
    eax = MEM32(esp + 0x10);
    MEM32(ebp) = eax;
    POP32(esp, esi);

loc_003BE9E5: ;
    POP32(esp, ebp);
    POP32(esp, ebx);

loc_003BE9E7: ;
    POP32(esp, edi);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE9EA
 * Original: 0x003BE9EA - 0x003BEA27 (61 bytes, 24 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE9EA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE9EA: ;
    PUSH32(esp, esi);
    esi = edx;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) + 1;
    /* test MEM8(esi + 0x10), 0x20 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = ecx;
    if (TEST_NZ(MEM8(esi + 0x10), 0x20)) goto loc_003BEA24; /* jne: not equal / not zero */

loc_003BE9F9: ;
    MEM8(esi + 1) = MEM8(esi + 1) | 0x40;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BEA02: ;
    eax++;
    MEM32(esi + 0x1C) = eax;
    if (CMP_EQ(MEM32(edi + 0x438), 0)) goto loc_003BEA13; /* je: equal / zero */

loc_003BEA0F: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x40;

loc_003BEA13: ;
    ecx = MEM32(edi);
    PUSH32(esp, 4);
    POP32(esp, eax);
    MEM32(ecx + 0xC) = eax;
    ecx = MEM32(edi);
    MEM32(ecx + 0x10) = eax;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x20;

loc_003BEA24: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BEA27
 * Original: 0x003BEA27 - 0x003BEA62 (59 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA27(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEA27: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    eax = MEM32(esi + -100);
    esi = esi + 0xFFFFFB40u;
    eax = (uint32_t)((int32_t)eax * (int32_t)0x70);
    SET_LO8(ecx, MEM8(eax + 0xF45FAC));
    { uint32_t _icall_t = MEM32(0x3C164C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEA44: ;
    ecx = MEM32(esi);
    MEM32(ecx + 0x14) = 0x80000033u;
    ecx = MEM32(esi);
    MEM32(ecx + 4) = 2;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEA5E: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BEA62
 * Original: 0x003BEA62 - 0x003BEA77 (21 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA62(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEA62: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    if (TEST_Z(MEM8(esi + 0x22), 1)) { g_seh_ebp = ebp; sub_003BEA77(); return; } /* je: equal / zero */

loc_003BEA6D: ;
    eax = 0x40020000;
    g_seh_ebp = ebp; sub_003BEB15(); return; /* tail jmp 0x003BEB15 */

}

/**
 * sub_003BEA77
 * Original: 0x003BEA77 - 0x003BEB15 (158 bytes, 53 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA77(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEA77: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEA7F: ;
    edi = MEM32(esi + 0x10);
    /* test MEM8(edi + 0x10), 0x10 - flags set for next jcc */
    SET_LO8(ebx, LO8(eax));
    if (TEST_NZ(MEM8(edi + 0x10), 0x10)) goto loc_003BEB04; /* jne: not equal / not zero */

loc_003BEA8A: ;
    SET_LO16(eax, MEM16(esi + 0x22));
    if (TEST_Z(LO8(eax), 2)) goto loc_003BEAE4; /* je: equal / zero */

loc_003BEA92: ;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003BEAC1; /* je: equal / zero */

loc_003BEA9B: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BEAB4; /* je: equal / zero */

loc_003BEA9F: ;
    eax--;
    if ((eax == 0)) goto loc_003BEAA9; /* je: equal / zero */

loc_003BEAA2: ;
    esi = 0x80000600u;
    goto loc_003BEB09;

loc_003BEAA9: ;
    edx = esi;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE945(); /* call 0x003BE945 */

loc_003BEAB2: ;
    goto loc_003BEACC;

loc_003BEAB4: ;
    ecx = MEM32(esp + 0x10);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE90C(); /* call 0x003BE90C */

loc_003BEABF: ;
    goto loc_003BEACC;

loc_003BEAC1: ;
    ecx = MEM32(esp + 0x10);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE8D3(); /* call 0x003BE8D3 */

loc_003BEACC: ;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;
    MEM8(esi + 0x22) = MEM8(esi + 0x22) | 1;
    PUSH32(esp, esi);
    MEM32(esi + 4) = 0xC000000Fu;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BEAE0: ;
    esi = 0; /* xor self */
    goto loc_003BEB09;

loc_003BEAE4: ;
    ecx = MEM32(esp + 0x10);
    SET_LO16(eax, LO16(eax) | 1);
    MEM16(esi + 0x22) = LO16(eax);
    eax = ecx + 0x42C;
    edx = MEM32(eax);
    MEM32(esi + 0x24) = edx;
    edx = edi;
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE9EA(); /* call 0x003BE9EA */

loc_003BEB04: ;
    esi = 0x40020000;

loc_003BEB09: ;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB11: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003BEB15(); return; /* restored dropped fall-through to sub_003BEB15 */
}

/**
 * sub_003BEB15
 * Original: 0x003BEB15 - 0x003BEB19 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB15(void)
{

loc_003BEB15: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BEB19
 * Original: 0x003BEB19 - 0x003BEB4F (54 bytes, 22 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB19(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEB19: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    esi = MEM32(edi + 0x10);
    ebp = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB2A: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x10;
    edx = esi;
    ecx = ebp;
    SET_LO8(ebx, LO8(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE974(); /* call 0x003BE974 */

loc_003BEB39: ;
    SET_LO8(eax, MEM8(esi + 0x11));
    if (TEST_Z(LO8(eax), LO8(eax))) { g_seh_ebp = ebp; sub_003BEB4F(); return; } /* je: equal / zero */

loc_003BEB40: ;
    if (CMP_EQ(LO8(eax), 2)) { g_seh_ebp = ebp; sub_003BEB4F(); return; } /* je: equal / zero */

loc_003BEB44: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEFFE(); /* call 0x003BEFFE */

loc_003BEB4D: ;
    g_seh_ebp = ebp; sub_003BEB58(); return; /* tail jmp 0x003BEB58 */

}

/**
 * sub_003BEB4F
 * Original: 0x003BEB4F - 0x003BEB58 (9 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB4F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEB4F: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BED45(); /* call 0x003BED45 */

    g_seh_ebp = ebp; sub_003BEB58(); return; /* restored dropped fall-through to sub_003BEB58 */
}

/**
 * sub_003BEB58
 * Original: 0x003BEB58 - 0x003BEB80 (40 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB58(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEB58: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE9EA(); /* call 0x003BE9EA */

loc_003BEB61: ;
    eax = ebp + 0x434;
    ecx = MEM32(eax);
    MEM32(edi + 0x14) = ecx;
    SET_LO8(ecx, LO8(ebx));
    MEM32(eax) = edi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB76: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = 0x40000000;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BEB80
 * Original: 0x003BEB80 - 0x003BEBD3 (83 bytes, 33 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB80(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEB80: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = edx;
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x10);
    ebp = ecx;
    ebx = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB94: ;
    edx = edi;
    ecx = ebp;
    MEM8(esp + 0x13) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE974(); /* call 0x003BE974 */

loc_003BEBA1: ;
    if (CMP_EQ(MEM8(edi + 0x27), LO8(ebx))) goto loc_003BEBC1; /* je: equal / zero */

loc_003BEBA6: ;
    eax = ebp + 0x430;
    ecx = MEM32(eax);
    MEM32(esi + 0x14) = ecx;
    edx = edi;
    ecx = ebp;
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE9EA(); /* call 0x003BE9EA */

loc_003BEBBC: ;
    ebx = 0x40000000;

loc_003BEBC1: ;
    SET_LO8(ecx, MEM8(esp + 0x13));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEBCB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = ebx;
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BEBD3
 * Original: 0x003BEBD3 - 0x003BECC0 (237 bytes, 82 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEBD3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEBD3: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 0xC);
    eax = ZX8(MEM8(edi + 1));
    if (CMP_G(eax, 0xC)) goto loc_003BEC6B; /* jg: greater (signed >) */

loc_003BEBE8: ;
    if (CMP_EQ(eax, 0xC)) goto loc_003BEC5F; /* je: equal / zero */

loc_003BEBEA: ;
    PUSH32(esp, 2);
    POP32(esp, ecx);
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003BEC53; /* je: equal / zero */

loc_003BEBF1: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003BEC47; /* je: equal / zero */

loc_003BEBF5: ;
    eax--;
    if ((eax == 0)) goto loc_003BEC38; /* je: equal / zero */

loc_003BEBF8: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003BEC26; /* je: equal / zero */

loc_003BEBFC: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003BEC17; /* je: equal / zero */

loc_003BEC00: ;
    eax = eax - ecx;
    if ((eax != 0)) goto loc_003BECB9; /* jne: not equal / not zero */

loc_003BEC08: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFBED(); /* call 0x003BFBED */

loc_003BEC12: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC17: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF973(); /* call 0x003BF973 */

loc_003BEC21: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC26: ;
    ecx = MEM32(ebp + 8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BEC2E: ;
    MEM32(edi + 0x14) = eax;
    esi = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BECCC(); return; /* tail jmp 0x003BECCC */

loc_003BEC38: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE8A5(); /* call 0x003BE8A5 */

loc_003BEC42: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC47: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE884(); /* call 0x003BE884 */

loc_003BEC51: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC53: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE710(); /* call 0x003BE710 */

loc_003BEC5D: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC5F: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFD54(); /* call 0x003BFD54 */

loc_003BEC69: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC6B: ;
    if (CMP_EQ(eax, 0xD)) { g_seh_ebp = ebp; sub_003BECC0(); return; } /* je: equal / zero */

loc_003BEC70: ;
    if (CMP_LE(eax, 0x3F)) goto loc_003BECB9; /* jle: less or equal (signed <=) */

loc_003BEC75: ;
    if (CMP_LE(eax, 0x41)) goto loc_003BECAD; /* jle: less or equal (signed <=) */

loc_003BEC7A: ;
    if (CMP_EQ(eax, 0x43)) goto loc_003BECA1; /* je: equal / zero */

loc_003BEC7F: ;
    if (CMP_EQ(eax, 0x46)) goto loc_003BEC95; /* je: equal / zero */

loc_003BEC84: ;
    if (CMP_NE(eax, 0x4A)) goto loc_003BECB9; /* jne: not equal / not zero */

loc_003BEC89: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFB20(); /* call 0x003BFB20 */

loc_003BEC93: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BEC95: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEB80(); /* call 0x003BEB80 */

loc_003BEC9F: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BECA1: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEB19(); /* call 0x003BEB19 */

loc_003BECAB: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BECAD: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C051D(); /* call 0x003C051D */

loc_003BECB7: ;
    g_seh_ebp = ebp; sub_003BECCA(); return; /* tail jmp 0x003BECCA */

loc_003BECB9: ;
    esi = 0x80000200u;
    g_seh_ebp = ebp; sub_003BECCC(); return; /* tail jmp 0x003BECCC */

}

/**
 * sub_003BECC0
 * Original: 0x003BECC0 - 0x003BECCA (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BECC0(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BECC0: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFE73(); /* call 0x003BFE73 */

    g_seh_ebp = ebp; sub_003BECCA(); return; /* restored dropped fall-through to sub_003BECCA */
}

/**
 * sub_003BECCA
 * Original: 0x003BECCA - 0x003BECCC (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BECCA(void)
{

loc_003BECCA: ;
    esi = eax;

    sub_003BECCC(); return; /* restored dropped fall-through to sub_003BECCC */
}

/**
 * sub_003BECCC
 * Original: 0x003BECCC - 0x003BECEB (31 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BECCC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BECCC: ;
    eax = esi;
    eax = eax & 0xC0000000u;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BECE3; /* je: equal / zero */

loc_003BECDA: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BECE3: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BECEB
 * Original: 0x003BECEB - 0x003BED08 (29 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BECEB(void)
{

loc_003BECEB: ;
    eax = MEM32(esp + 4);
    MEM32(eax + 8) = MEM32(eax + 8) | 0xFFFFFFFFu;
    MEM8(eax + 0x1F) = 0xFF;
    ecx = MEM32(0xF45F0C);
    MEM32(eax + 0x14) = ecx;
    MEM32(0xF45F0C) = eax;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BED08
 * Original: 0x003BED08 - 0x003BED1C (20 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED08(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BED08: ;
    /* cmp MEM8(edx + 0x11), 0 - flags set for next jcc */
    eax = MEM32(ecx);
    PUSH32(esp, esi);
    if (CMP_NE(MEM8(edx + 0x11), 0)) { g_seh_ebp = ebp; sub_003BED1C(); return; } /* jne: not equal / not zero */

loc_003BED11: ;
    esi = ecx + 0x40C;
    eax = eax + 0x20;
    g_seh_ebp = ebp; sub_003BED25(); return; /* tail jmp 0x003BED25 */

}

/**
 * sub_003BED1C
 * Original: 0x003BED1C - 0x003BED25 (9 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED1C(void)
{

loc_003BED1C: ;
    esi = ecx + 0x410;
    eax = eax + 0x28;

    sub_003BED25(); return; /* restored dropped fall-through to sub_003BED25 */
}

/**
 * sub_003BED25
 * Original: 0x003BED25 - 0x003BED45 (32 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED25(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BED25: ;
    ecx = MEM32(esi);
    MEM32(edx + 0x18) = ecx;
    MEM32(esi) = edx;
    ecx = MEM32(edx + 0x18);
    /* test ecx, ecx - flags set for next jcc */
    POP32(esp, esi);
    if (TEST_NZ(ecx, ecx)) goto loc_003BED39; /* jne: not equal / not zero */

loc_003BED34: ;
    MEM32(edx + 0xC) = MEM32(edx + 0xC) & ecx;
    goto loc_003BED3F;

loc_003BED39: ;
    ecx = MEM32(ecx + 0x14);
    MEM32(edx + 0xC) = ecx;

loc_003BED3F: ;
    ecx = MEM32(edx + 0x14);
    MEM32(eax) = ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003BED45
 * Original: 0x003BED45 - 0x003BED5A (21 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED45(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BED45: ;
    /* cmp MEM8(edx + 0x11), 0 - flags set for next jcc */
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    if (CMP_NE(MEM8(edx + 0x11), 0)) { g_seh_ebp = ebp; sub_003BED5A(); return; } /* jne: not equal / not zero */

loc_003BED4D: ;
    esi = ecx + 0x40C;
    ecx = MEM32(ecx);
    ecx = ecx + 0x20;
    g_seh_ebp = ebp; sub_003BED65(); return; /* tail jmp 0x003BED65 */

}

/**
 * sub_003BED5A
 * Original: 0x003BED5A - 0x003BED65 (11 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED5A(void)
{

loc_003BED5A: ;
    esi = ecx + 0x410;
    ecx = MEM32(ecx);
    ecx = ecx + 0x28;

    sub_003BED65(); return; /* restored dropped fall-through to sub_003BED65 */
}

/**
 * sub_003BED65
 * Original: 0x003BED65 - 0x003BED95 (48 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED65(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BED65: ;
    eax = MEM32(esi);
    edi = 0; /* xor self */

loc_003BED69: ;
    if (CMP_EQ(edx, eax)) goto loc_003BED76; /* je: equal / zero */

loc_003BED6D: ;
    edi = eax;
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BED69; } /* jne: not equal / not zero */

loc_003BED76: ;
    if (TEST_Z(edi, edi)) goto loc_003BED88; /* je: equal / zero */

loc_003BED7A: ;
    ecx = MEM32(eax + 0x18);
    MEM32(edi + 0x18) = ecx;
    eax = MEM32(eax + 0xC);
    MEM32(edi + 0xC) = eax;
    goto loc_003BED92;

loc_003BED88: ;
    edx = MEM32(eax + 0x18);
    MEM32(esi) = edx;
    eax = MEM32(eax + 0xC);
    MEM32(ecx) = eax;

loc_003BED92: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BED95
 * Original: 0x003BED95 - 0x003BEDAB (22 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED95(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BED95: ;
    eax = 0; /* xor self */
    if (CMP_BE(ecx & ecx, 0)) goto loc_003BEDAA; /* jbe: below or equal (unsigned <=) */

loc_003BED9B: ;
    PUSH32(esp, esi);

loc_003BED9C: ;
    esi = edx;
    esi = esi & 1;
    edx = edx >> 1;
    ecx--;
    eax = esi + eax * 2;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003BED9C; } /* jne: not equal / not zero */

loc_003BEDA9: ;
    POP32(esp, esi);

loc_003BEDAA: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BEDAB
 * Original: 0x003BEDAB - 0x003BEDD3 (40 bytes, 18 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEDAB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEDAB: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = ecx;
    SET_LO8(ecx, MEM8(ebp + 8));
    /* cmp LO8(ecx), 0x20 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = edx;
    if (CMP_B(LO8(ecx), 0x20)) { g_seh_ebp = ebp; sub_003BEDD3(); return; } /* jb: below (unsigned <) */

loc_003BEDBD: ;
    edx = ZX8(LO8(ecx));
    PUSH32(esp, 5);
    edx = edx - 0x20;
    POP32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BED95(); /* call 0x003BED95 */

loc_003BEDCB: ;
    ecx = MEM32(esi + 8);
    MEM32(ecx + eax * 4) = edi;
    g_seh_ebp = ebp; sub_003BEE1C(); return; /* tail jmp 0x003BEE1C */

}

/**
 * sub_003BEDD3
 * Original: 0x003BEDD3 - 0x003BEE1C (73 bytes, 28 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEDD3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEDD3: ;
    SET_LO8(eax, LO8(ecx));
    SET_LO8(eax, LO8(eax) << 1);
    PUSH32(esp, ebx);
    SET_LO8(eax, LO8(eax) + 1);
    SET_LO8(ebx, LO8(ecx));
    MEM8(ebp + -4) = LO8(eax);
    MEM8(ebp + 0xB) = 0;
    SET_LO8(ebx, LO8(ebx) << 1);

loc_003BEDE5: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    eax = eax + esi + 0xC;
    if (CMP_NE(MEM32(eax + 8), 0)) goto loc_003BEE03; /* jne: not equal / not zero */

loc_003BEDF5: ;
    PUSH32(esp, MEM32(ebp + -4));
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEDAB(); /* call 0x003BEDAB */

loc_003BEE01: ;
    goto loc_003BEE09;

loc_003BEE03: ;
    eax = MEM32(eax + 0xC);
    MEM32(eax + 0xC) = edi;

loc_003BEE09: ;
    SET_LO8(eax, LO8(ebx));
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    MEM8(ebp + -4) = LO8(eax);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BEE1B; /* je: equal / zero */

loc_003BEE12: ;
    MEM8(ebp + 0xB) = MEM8(ebp + 0xB) + 1;
    if (CMP_B(MEM8(ebp + 0xB), 2)) { RECOMP_SLICE_POINT(); goto loc_003BEDE5; } /* jb: below (unsigned <) */

loc_003BEE1B: ;
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003BEE1C(); return; /* restored dropped fall-through to sub_003BEE1C */
}

/**
 * sub_003BEE1C
 * Original: 0x003BEE1C - 0x003BEE22 (6 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEE1C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEE1C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BEE22
 * Original: 0x003BEE22 - 0x003BEEB3 (145 bytes, 52 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEE22(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEE22: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x10;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM8(esi + 0x11), 3 - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_NE(MEM8(esi + 0x11), 3)) goto loc_003BEE86; /* jne: not equal / not zero */

loc_003BEE33: ;
    SET_LO8(eax, 0x20);
    if (CMP_AE(MEM8(esi + 0x13), LO8(eax))) goto loc_003BEE43; /* jae: above or equal (unsigned >=) */

loc_003BEE3A: ;
    SET_LO8(edx, MEM8(esi + 0x13));

loc_003BEE3D: ;
    SET_LO8(eax, LO8(eax) >> 1);
    if (CMP_A(LO8(eax), LO8(edx))) { RECOMP_SLICE_POINT(); goto loc_003BEE3D; } /* ja: above (unsigned >) */

loc_003BEE43: ;
    SET_LO8(ebx, LO8(eax));
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) - 1);
    /* cmp LO8(eax), LO8(ebx) - flags set for next jcc */
    edi = 0x2EE0;
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_A(LO8(eax), LO8(ebx))) goto loc_003BEE92; /* ja: above (unsigned >) */

loc_003BEE55: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    edx = eax + ecx + 0x10;

loc_003BEE5F: ;
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edx + -2));
    SET_LO16(eax, LO16(eax) + MEM16(edx + 2));
    SET_LO16(eax, LO16(eax) + MEM16(edx));
    if (CMP_AE(LO16(eax), LO16(edi))) goto loc_003BEE79; /* jae: above or equal (unsigned >=) */

loc_003BEE71: ;
    edi = eax;
    SET_LO8(eax, MEM8(ebp + -1));
    MEM8(ebp + -5) = LO8(eax);

loc_003BEE79: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) + 1;
    edx = edx + 0x10;
    if (CMP_BE(MEM8(ebp + -1), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003BEE5F; } /* jbe: below or equal (unsigned <=) */

loc_003BEE84: ;
    goto loc_003BEE92;

loc_003BEE86: ;
    SET_LO16(edi, MEM16(ecx + 0x10));
    SET_LO16(edi, LO16(edi) + MEM16(ecx + 0xE));
    MEM8(ebp + -5) = 0;

loc_003BEE92: ;
    SET_LO16(eax, MEM16(esi + 0x22));
    edi = ZX16(LO16(edi));
    edx = ZX16(LO16(eax));
    edx = edx + edi;
    edi = ZX16(MEM16(ecx + 0x414));
    if (CMP_LE(edx, edi)) { g_seh_ebp = ebp; sub_003BEEB3(); return; } /* jle: less or equal (signed <=) */

loc_003BEEA9: ;
    eax = 0x80000800u;
    g_seh_ebp = ebp; sub_003BEFF9(); return; /* tail jmp 0x003BEFF9 */

}

/**
 * sub_003BEEB3
 * Original: 0x003BEEB3 - 0x003BEFF9 (326 bytes, 115 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEEB3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEEB3: ;
    SET_LO8(edx, MEM8(ebp + -5));
    edi = ZX8(LO8(edx));
    edi = edi << 4;
    edi = edi + ecx + 0xC;
    MEM8(esi + 0x12) = LO8(edx);
    MEM16(edi + 2) = MEM16(edi + 2) + LO16(eax);
    if (TEST_NZ(LO8(edx), LO8(edx))) goto loc_003BEED2; /* jne: not equal / not zero */

loc_003BEECB: ;
    SET_LO8(eax, 1);
    MEM8(ebp + -1) = LO8(eax);
    goto loc_003BEEE3;

loc_003BEED2: ;
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) << 1);
    MEM8(ebp + -1) = LO8(eax);
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_A(LO8(eax), 0x40)) goto loc_003BEF23; /* ja: above (unsigned >) */

loc_003BEEE3: ;
    if (CMP_A(MEM8(ebp + -1), LO8(eax))) goto loc_003BEF15; /* ja: above (unsigned >) */

loc_003BEEE8: ;
    edx = ZX8(MEM8(ebp + -1));
    edx = edx << 4;
    edx = edx + ecx + 0x12;
    MEM32(ebp + -16) = edx;
    SET_LO8(edx, LO8(eax));
    SET_LO8(edx, LO8(edx) - MEM8(ebp + -1));
    SET_LO8(edx, LO8(edx) + 1);
    edx = ZX8(LO8(edx));
    MEM32(ebp + -12) = edx;
    edx = MEM32(ebp + -16);

loc_003BEF06: ;
    SET_LO16(ebx, MEM16(esi + 0x22));
    MEM16(edx) = MEM16(edx) + LO16(ebx);
    edx = edx + 0x10;
    MEM32(ebp + -12) = MEM32(ebp + -12) - 1;
    if ((MEM32(ebp + -12) != 0)) { RECOMP_SLICE_POINT(); goto loc_003BEF06; } /* jne: not equal / not zero */

loc_003BEF15: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) << 1;
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_BE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003BEEE3; } /* jbe: below or equal (unsigned <=) */

loc_003BEF20: ;
    SET_LO8(edx, MEM8(ebp + -5));

loc_003BEF23: ;
    /* cmp LO8(edx), 1 - flags set for next jcc */
    MEM8(ebp + -1) = LO8(edx);
    if (CMP_BE(LO8(edx), 1)) goto loc_003BEF8C; /* jbe: below or equal (unsigned <=) */

loc_003BEF2B: ;
    SET_LO8(eax, MEM8(ebp + -1));
    edx = ZX8(MEM8(ebp + -1));
    SET_LO8(eax, LO8(eax) ^ 1);
    eax = ZX8(LO8(eax));
    edx = edx << 4;
    edx = edx + ecx + 0xC;
    eax = eax << 4;
    ebx = 0; /* xor self */
    SET_LO16(ebx, MEM16(edx + 4));
    SET_LO16(edx, MEM16(edx + 2));
    eax = eax + ecx + 0xC;
    MEM16(ebp + -12) = LO16(edx);
    edx = ZX16(MEM16(eax + 4));
    eax = ZX16(MEM16(eax + 2));
    edx = edx + eax;
    eax = ZX16(MEM16(ebp + -12));
    MEM32(ebp + -16) = ebx;
    ebx = ZX16(LO16(ebx));
    eax = eax + ebx;
    if (CMP_LE(eax, edx)) goto loc_003BEF8C; /* jle: less or equal (signed <=) */

loc_003BEF6D: ;
    SET_LO8(eax, MEM8(ebp + -1));
    ebx = MEM32(ebp + -16);
    edx = MEM32(ebp + -12);
    SET_LO8(eax, LO8(eax) >> 1);
    edx = edx + ebx;
    ebx = ZX8(LO8(eax));
    ebx = ebx << 4;
    /* cmp LO8(eax), 1 - flags set for next jcc */
    MEM16(ebx + ecx + 0x10) = LO16(edx);
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_A(LO8(eax), 1)) { RECOMP_SLICE_POINT(); goto loc_003BEF2B; } /* ja: above (unsigned >) */

loc_003BEF8C: ;
    if (CMP_NE(MEM8(ebp + -1), 1)) goto loc_003BEF9E; /* jne: not equal / not zero */

loc_003BEF92: ;
    SET_LO16(eax, MEM16(ecx + 0x20));
    SET_LO16(eax, LO16(eax) + MEM16(ecx + 0x1E));
    MEM16(ecx + 0x10) = LO16(eax);

loc_003BEF9E: ;
    eax = MEM32(edi + 8);
    edx = 0; /* xor self */
    if (CMP_NE(eax, edx)) goto loc_003BEFDD; /* jne: not equal / not zero */

loc_003BEFA7: ;
    SET_LO8(eax, MEM8(ebp + -5));
    goto loc_003BEFB0;

loc_003BEFAC: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BEFBE; /* je: equal / zero */

loc_003BEFB0: ;
    SET_LO8(eax, LO8(eax) >> 1);
    ebx = ZX8(LO8(eax));
    ebx = ebx << 4;
    if (CMP_EQ(MEM32(ebx + ecx + 0x14), edx)) { RECOMP_SLICE_POINT(); goto loc_003BEFAC; } /* je: equal / zero */

loc_003BEFBE: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    eax = MEM32(eax + ecx + 0x14);
    if (CMP_EQ(eax, edx)) goto loc_003BEFD2; /* je: equal / zero */

loc_003BEFCC: ;
    eax = MEM32(eax + 0x14);
    MEM32(esi + 0xC) = eax;

loc_003BEFD2: ;
    MEM32(edi + 8) = esi;
    MEM32(edi + 0xC) = esi;
    MEM32(esi + 0x18) = edx;
    goto loc_003BEFEC;

loc_003BEFDD: ;
    MEM32(esi + 0x18) = eax;
    MEM32(edi + 8) = esi;
    eax = MEM32(esi + 0x18);
    eax = MEM32(eax + 0x14);
    MEM32(esi + 0xC) = eax;

loc_003BEFEC: ;
    PUSH32(esp, MEM32(ebp + -5));
    edx = MEM32(esi + 0x14);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEDAB(); /* call 0x003BEDAB */

loc_003BEFF7: ;
    eax = 0; /* xor self */

    g_seh_ebp = ebp; sub_003BEFF9(); return; /* restored dropped fall-through to sub_003BEFF9 */
}

/**
 * sub_003BEFF9
 * Original: 0x003BEFF9 - 0x003BEFFE (5 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEFF9(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEFF9: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BEFFE
 * Original: 0x003BEFFE - 0x003BF095 (151 bytes, 58 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEFFE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEFFE: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    SET_LO16(eax, MEM16(edx + 0x22));
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    PUSH32(esp, ebx);
    SET_LO8(ebx, MEM8(edx + 0x12));
    MEM16(ebp + -16) = LO16(eax);
    eax = ZX8(LO8(ebx));
    PUSH32(esp, esi);
    eax = eax << 4;
    esi = ecx;
    PUSH32(esp, edi);
    edi = eax + esi + 0xC;
    eax = MEM32(edi + 8);
    MEM32(ebp + -20) = edx;
    MEM8(ebp + -12) = LO8(ebx);

loc_003BF02B: ;
    if (CMP_EQ(eax, edx)) goto loc_003BF039; /* je: equal / zero */

loc_003BF02F: ;
    MEM32(ebp + -4) = eax;
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BF02B; } /* jne: not equal / not zero */

loc_003BF039: ;
    ecx = MEM32(eax + 0x18);
    if (TEST_NZ(ecx, ecx)) goto loc_003BF074; /* jne: not equal / not zero */

loc_003BF040: ;
    ecx = MEM32(ebp + -4);
    edx = 0; /* xor self */
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    MEM32(edi + 0xC) = ecx;
    MEM32(ebp + -8) = edx;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003BF07C; /* je: equal / zero */

loc_003BF04F: ;
    SET_LO8(edx, LO8(ebx));
    goto loc_003BF057;

loc_003BF053: ;
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BF066; /* je: equal / zero */

loc_003BF057: ;
    SET_LO8(edx, LO8(edx) >> 1);
    ecx = ZX8(LO8(edx));
    ecx = ecx << 4;
    if (CMP_EQ(MEM32(ecx + esi + 0x14), 0)) { RECOMP_SLICE_POINT(); goto loc_003BF053; } /* je: equal / zero */

loc_003BF066: ;
    ecx = ZX8(LO8(edx));
    ecx = ecx << 4;
    ecx = MEM32(ecx + esi + 0x14);
    if (TEST_Z(ecx, ecx)) goto loc_003BF079; /* je: equal / zero */

loc_003BF074: ;
    edx = MEM32(ecx + 0x14);
    goto loc_003BF07C;

loc_003BF079: ;
    edx = MEM32(ebp + -8);

loc_003BF07C: ;
    ecx = MEM32(ebp + -4);
    /* test ecx, ecx - flags set for next jcc */
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(ecx, ecx)) { g_seh_ebp = ebp; sub_003BF095(); return; } /* jne: not equal / not zero */

loc_003BF086: ;
    PUSH32(esp, MEM32(ebp + -12));
    ecx = esi;
    MEM32(edi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEDAB(); /* call 0x003BEDAB */

loc_003BF093: ;
    g_seh_ebp = ebp; sub_003BF09B(); return; /* tail jmp 0x003BF09B */

}

/**
 * sub_003BF095
 * Original: 0x003BF095 - 0x003BF09B (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF095(void)
{

loc_003BF095: ;
    MEM32(ecx + 0x18) = eax;
    MEM32(ecx + 0xC) = edx;

    sub_003BF09B(); return; /* restored dropped fall-through to sub_003BF09B */
}

/**
 * sub_003BF09B
 * Original: 0x003BF09B - 0x003BF20D (370 bytes, 129 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF09B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF09B: ;
    SET_LO16(eax, MEM16(ebp + -16));
    MEM16(edi + 2) = MEM16(edi + 2) - LO16(eax);
    if (TEST_NZ(LO8(ebx), LO8(ebx))) goto loc_003BF16E; /* jne: not equal / not zero */

loc_003BF0AB: ;
    SET_LO8(eax, 1);
    SET_LO8(ecx, LO8(eax));

loc_003BF0AF: ;
    if (CMP_A(LO8(ecx), LO8(eax))) goto loc_003BF0DB; /* ja: above (unsigned >) */

loc_003BF0B3: ;
    edx = ZX8(LO8(ecx));
    edx = edx << 4;
    edi = edx + esi + 0x12;
    SET_LO8(edx, LO8(eax));
    SET_LO8(edx, LO8(edx) - LO8(ecx));
    SET_LO8(edx, LO8(edx) + 1);
    edx = ZX8(LO8(edx));
    MEM32(ebp + -4) = edx;

loc_003BF0C9: ;
    edx = MEM32(ebp + -20);
    SET_LO16(edx, MEM16(edx + 0x22));
    MEM16(edi) = MEM16(edi) - LO16(edx);
    edi = edi + 0x10;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;
    if ((MEM32(ebp + -4) != 0)) { RECOMP_SLICE_POINT(); goto loc_003BF0C9; } /* jne: not equal / not zero */

loc_003BF0DB: ;
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(ecx, LO8(ecx) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_BE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003BF0AF; } /* jbe: below or equal (unsigned <=) */

loc_003BF0E5: ;
    if (CMP_BE(LO8(ebx), 1)) goto loc_003BF15B; /* jbe: below or equal (unsigned <=) */

loc_003BF0EA: ;
    SET_LO8(edx, LO8(ebx));
    SET_LO8(edx, LO8(edx) ^ 1);
    ecx = ZX8(LO8(edx));
    ecx = ecx << 4;
    ecx = ecx + esi + 0xC;
    edi = ZX16(MEM16(ecx + 4));
    ecx = ZX16(MEM16(ecx + 2));
    edi = edi + ecx;
    ecx = ZX8(LO8(ebx));
    ecx = ecx << 4;
    MEM32(ebp + -4) = edi;
    ecx = ecx + esi + 0xC;
    edi = ZX16(MEM16(ecx + 4));
    ecx = ZX16(MEM16(ecx + 2));
    SET_LO8(eax, LO8(ebx));
    edi = edi + ecx;
    SET_LO8(eax, LO8(eax) >> 1);
    if (CMP_G(edi, MEM32(ebp + -4))) goto loc_003BF135; /* jg: greater (signed >) */

loc_003BF123: ;
    ecx = ZX8(LO8(eax));
    ecx = ecx << 4;
    ecx = ZX16(MEM16(ecx + esi + 0x10));
    if (CMP_EQ(MEM32(ebp + -4), ecx)) goto loc_003BF158; /* je: equal / zero */

loc_003BF133: ;
    SET_LO8(ebx, LO8(edx));

loc_003BF135: ;
    ecx = ZX8(LO8(ebx));
    ecx = ecx << 4;
    ecx = ecx + esi + 0xC;
    SET_LO16(edx, MEM16(ecx + 4));
    SET_LO16(edx, LO16(edx) + MEM16(ecx + 2));
    ecx = ZX8(LO8(eax));
    ecx = ecx << 4;
    /* cmp LO8(eax), 1 - flags set for next jcc */
    MEM16(ecx + esi + 0x10) = LO16(edx);
    SET_LO8(ebx, LO8(eax));
    if (CMP_A(LO8(eax), 1)) { RECOMP_SLICE_POINT(); goto loc_003BF0EA; } /* ja: above (unsigned >) */

loc_003BF158: ;
    /* cmp LO8(ebx), 1 - flags set for next jcc */

loc_003BF15B: ;
    if (CMP_NE(LO8(ebx), 1)) goto loc_003BF169; /* jne: not equal / not zero */

loc_003BF15D: ;
    SET_LO16(eax, MEM16(esi + 0x20));
    SET_LO16(eax, LO16(eax) + MEM16(esi + 0x1E));
    MEM16(esi + 0x10) = LO16(eax);

loc_003BF169: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

loc_003BF16E: ;
    SET_LO8(ecx, LO8(ebx));
    SET_LO8(eax, LO8(ebx));
    { RECOMP_SLICE_POINT(); goto loc_003BF0DB; }

    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = MEM32(esi);
    MEM32(0xF2A62C) = MEM32(0xF2A62C) + 1;
    eax = MEM32(ecx + 0x10);
    edx = MEM32(ecx + 0xC);
    edx = edx & eax;
    PUSH32(esp, edi);
    if ((edx == 0)) goto loc_003BF206; /* je: equal / zero */

loc_003BF18F: ;
    edi = 0x80000000u;
    if (TEST_Z(edi, eax)) goto loc_003BF206; /* je: equal / zero */

loc_003BF198: ;
    eax = 0; /* xor self */
    eax++;
    /* test LO8(eax), LO8(edx) - flags set for next jcc */
    MEM32(ecx + 0x14) = edi;
    if (TEST_Z(LO8(eax), LO8(edx))) goto loc_003BF1A8; /* je: equal / zero */

loc_003BF1A2: ;
    MEM32(ecx + 0xC) = eax;
    edx = edx & 0xFFFFFFFEu;

loc_003BF1A8: ;
    if (TEST_Z(LO8(edx), 0x20)) goto loc_003BF1DC; /* je: equal / zero */

loc_003BF1AD: ;
    PUSH32(esp, ebx);
    ebx = MEM32(esi + 8);
    ebx = ZX16(MEM16(ebx + 0x80));
    edi = esi + 0x418;
    eax = MEM32(edi);
    ebx = ebx ^ eax;
    ebx = ebx & 0x8000;
    eax = eax - ebx;
    eax = eax + 0x10000;
    MEM32(edi) = eax;
    MEM32(ecx + 0xC) = 0x20;
    edx = edx & 0xFFFFFFDFu;
    POP32(esp, ebx);

loc_003BF1DC: ;
    if (TEST_Z(edx, edx)) goto loc_003BF1F9; /* je: equal / zero */

loc_003BF1E0: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    MEM32(esi + 0x438) = edx;
    PUSH32(esp, 0);
    esi = esi + 0x440;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C1684); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF1F7: ;
    goto loc_003BF202;

loc_003BF1F9: ;
    eax = MEM32(esi);
    MEM32(eax + 0x10) = 0x80000000u;

loc_003BF202: ;
    SET_LO8(eax, 1);
    goto loc_003BF208;

loc_003BF206: ;
    SET_LO8(eax, 0); /* xor self */

loc_003BF208: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF20D
 * Original: 0x003BF20D - 0x003BF231 (36 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF20D(void)
{

loc_003BF20D: ;
    eax = MEM32(ecx + 8);
    edx = MEM32(ecx + 0x418);
    ecx = ZX16(MEM16(eax + 0x80));
    eax = ecx;
    eax = eax ^ edx;
    ecx = ecx & 0x7FFF;
    eax = eax & 0x8000;
    ecx = ecx | edx;
    eax = eax + ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003BF231
 * Original: 0x003BF231 - 0x003BF344 (275 bytes, 97 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF231(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF231: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    edx = MEM32(ecx + 0x418);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    /* TODO: cli  */
    eax = MEM32(ecx + 8);
    eax = ZX16(MEM16(eax + 0x80));
    ebx = MEM32(-25157620);
    /* TODO: sti  */
    esi = eax;
    eax = eax & 0x7FFF;
    esi = esi ^ edx;
    eax = eax | edx;
    esi = esi & 0x8000;
    esi = esi + eax;
    eax = esi;
    eax = eax - MEM32(ecx + 0x4D8);
    /* cmp eax, 0x14 - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (CMP_B(eax, 0x14)) goto loc_003BF340; /* jb: below (unsigned <) */

loc_003BF276: ;
    edx = MEM32(ecx + 0x4D0);
    PUSH32(esp, edi);
    edi = esi + esi * 2;
    edi = edi << 4;
    edi = edi - ebx;
    if (TEST_NZ(edx, edx)) goto loc_003BF2A1; /* jne: not equal / not zero */

loc_003BF289: ;
    MEM32(ecx + 0x4D4) = MEM32(ecx + 0x4D4) & 0;
    MEM32(ecx + 0x4D0) = edi;
    MEM32(ecx + 0x4D8) = esi;
    goto loc_003BF33F;

loc_003BF2A1: ;
    eax = edi;
    eax = eax - edx;
    if (((int32_t)eax >= 0)) goto loc_003BF2AA; /* jns: not sign (positive) */

loc_003BF2A7: ;
    eax = eax + 0x2F;

loc_003BF2AA: ;
    PUSH32(esp, 0x30);
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    POP32(esp, ebx);
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ebx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ebx)); }
    ebx = MEM32(ecx + 0x4D4);
    edx = eax;
    edx = edx - ebx;
    if ((edx != 0)) goto loc_003BF2D1; /* jne: not equal / not zero */

loc_003BF2BC: ;
    if (TEST_Z(eax, eax)) goto loc_003BF33F; /* je: equal / zero */

loc_003BF2C0: ;
    if (CMP_BE(MEM32(ebp + -4), 0x61A8)) goto loc_003BF33F; /* jbe: below or equal (unsigned <=) */

loc_003BF2C9: ;
    MEM32(ecx + 0x4D8) = esi;
    goto loc_003BF2FB;

loc_003BF2D1: ;
    /* cmp edx, 3 - flags set for next jcc */
    MEM32(ecx + 0x4D4) = eax;
    MEM32(ecx + 0x4D8) = esi;
    if (CMP_G(edx, 3)) { RECOMP_SLICE_POINT(); goto loc_003BF289; } /* jg: greater (signed >) */

loc_003BF2E2: ;
    if (CMP_L(edx, 0xFFFFFFFDu)) { RECOMP_SLICE_POINT(); goto loc_003BF289; } /* jl: less (signed <) */

loc_003BF2E7: ;
    if (TEST_Z(eax, eax)) goto loc_003BF33F; /* je: equal / zero */

loc_003BF2EB: ;
    if (CMP_LE(edx & edx, 0)) goto loc_003BF2F5; /* jle: less or equal (signed <=) */

loc_003BF2EF: ;
    if (CMP_GE(ebx & ebx, 0)) goto loc_003BF2FB; /* jge: greater or equal (signed >=) */

loc_003BF2F3: ;
    /* test edx, edx - flags set for next jcc */

loc_003BF2F5: ;
    if (CMP_GE(edx & edx, 0)) goto loc_003BF33F; /* jge: greater or equal (signed >=) */

loc_003BF2F7: ;
    if (CMP_G(ebx & ebx, 0)) goto loc_003BF33F; /* jg: greater (signed >) */

loc_003BF2FB: ;
    ecx = MEM32(ecx);
    edx = MEM32(ecx + 0x34);
    /* test eax, eax - flags set for next jcc */
    esi = edx;
    eax = 0x3FFF;
    if (CMP_LE(eax & eax, 0)) goto loc_003BF31A; /* jle: less or equal (signed <=) */

loc_003BF30B: ;
    esi = esi & eax;
    if (CMP_AE(esi, 0x2EE1)) goto loc_003BF32D; /* jae: above or equal (unsigned >=) */

loc_003BF315: ;
    esi = edx + 1;
    goto loc_003BF327;

loc_003BF31A: ;
    esi = esi & eax;
    if (CMP_BE(esi, 0x2ED1)) goto loc_003BF32D; /* jbe: below or equal (unsigned <=) */

loc_003BF324: ;
    esi = edx + -1;

loc_003BF327: ;
    esi = esi ^ edx;
    esi = esi & eax;
    edx = edx ^ esi;

loc_003BF32D: ;
    eax = edx;
    eax = ~eax;
    eax = eax ^ edx;
    eax = eax & 0x7FFFFFFF;
    edx = ~edx;
    eax = eax ^ edx;
    MEM32(ecx + 0x34) = eax;

loc_003BF33F: ;
    POP32(esp, edi);

loc_003BF340: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF344
 * Original: 0x003BF344 - 0x003BF3C0 (124 bytes, 48 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF344(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF344: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = edx;
    MEM8(esi + 0x27) = MEM8(esi + 0x27) - 1;
    eax = MEM32(edi + 0x18);
    /* test eax, eax - flags set for next jcc */
    ebx = ecx;
    if (TEST_Z(eax, eax)) goto loc_003BF367; /* je: equal / zero */

loc_003BF359: ;
    ecx = ZX16(MEM16(edi + 0x20));
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1680); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF367: ;
    if (TEST_Z(MEM8(edi + 0x22), 1)) goto loc_003BF3B0; /* je: equal / zero */

loc_003BF36D: ;
    eax = MEM32(ebx + 0x42C);
    ecx = 0; /* xor self */
    if (TEST_Z(eax, eax)) goto loc_003BF3B0; /* je: equal / zero */

loc_003BF379: ;
    if (CMP_EQ(edi, eax)) goto loc_003BF386; /* je: equal / zero */

loc_003BF37D: ;
    ecx = eax;
    eax = MEM32(eax + 0x24);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BF379; } /* jne: not equal / not zero */

loc_003BF386: ;
    if (TEST_Z(eax, eax)) goto loc_003BF3B0; /* je: equal / zero */

loc_003BF38A: ;
    if (TEST_NZ(ecx, ecx)) goto loc_003BF399; /* jne: not equal / not zero */

loc_003BF38E: ;
    ecx = MEM32(eax + 0x24);
    MEM32(ebx + 0x42C) = ecx;
    goto loc_003BF39F;

loc_003BF399: ;
    edx = MEM32(eax + 0x24);
    MEM32(ecx + 0x24) = edx;

loc_003BF39F: ;
    MEM32(eax + 0x24) = MEM32(eax + 0x24) & 0;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003BF3B0; /* jne: not equal / not zero */

loc_003BF3A8: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003BF3B0: ;
    MEM8(edi + 0x22) = MEM8(edi + 0x22) | 8;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BF3BA: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF3C0
 * Original: 0x003BF3C0 - 0x003BF3F1 (49 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF3C0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF3C0: ;
    eax = ZX8(MEM8(edx + 0x11));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003BF3E5; /* je: equal / zero */

loc_003BF3C9: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BF3D9; /* je: equal / zero */

loc_003BF3CD: ;
    eax--;
    if ((eax != 0)) { g_seh_ebp = ebp; sub_003BF3F1(); return; } /* jne: not equal / not zero */

loc_003BF3D0: ;
    MEM16(edx + 0x24) = MEM16(edx + 0x24) - 1;
    g_seh_ebp = ebp; sub_003C0385(); return; /* tail jmp 0x003C0385 */

loc_003BF3D9: ;
    MEM16(0xF45F26) = MEM16(0xF45F26) + 1;
    g_seh_ebp = ebp; sub_003C03D8(); return; /* tail jmp 0x003C03D8 */

loc_003BF3E5: ;
    MEM16(0xF45F22) = MEM16(0xF45F22) + 1;
    g_seh_ebp = ebp; sub_003C0425(); return; /* tail jmp 0x003C0425 */

}

/**
 * sub_003BF3F1
 * Original: 0x003BF3F1 - 0x003BF3F2 (1 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF3F1(void)
{

loc_003BF3F1: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BF3F2
 * Original: 0x003BF3F2 - 0x003BF461 (111 bytes, 41 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF3F2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF3F2: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x10;
    eax = MEM32(edx);
    PUSH32(esp, ebx);
    ebx = MEM32(edx + 0x18);
    PUSH32(esp, esi);
    eax = eax >> 0x1C;
    /* cmp eax, 9 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = MEM32(edx + 0x14);
    MEM32(ebp + -8) = ecx;
    MEM32(ebp + -16) = ebx;
    MEM8(ebp + -1) = 1;
    if (CMP_NE(eax, 9)) { g_seh_ebp = ebp; sub_003BF461(); return; } /* jne: not equal / not zero */

loc_003BF415: ;
    if (CMP_EQ(MEM8(ebx + 0x1D), 0)) { g_seh_ebp = ebp; sub_003BF461(); return; } /* je: equal / zero */

loc_003BF41B: ;
    eax = MEM32(edx + 4);
    if (TEST_Z(eax, eax)) goto loc_003BF450; /* je: equal / zero */

loc_003BF422: ;
    ecx = MEM32(edx + 0xC);
    esi = 0xFFF;
    eax = eax & esi;
    ecx = ecx & esi;
    /* cmp ecx, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (CMP_L(ecx, eax)) goto loc_003BF440; /* jl: less (signed <) */

loc_003BF435: ;
    eax = ZX8(MEM8(edx + 0x1D));
    eax = eax - ecx;
    eax = eax + MEM32(ebp + -12);
    goto loc_003BF44D;

loc_003BF440: ;
    esi = ZX8(MEM8(edx + 0x1D));
    esi = esi - ecx;
    eax = esi + eax + -4096;

loc_003BF44D: ;
    eax--;
    goto loc_003BF454;

loc_003BF450: ;
    eax = ZX8(MEM8(edx + 0x1D));

loc_003BF454: ;
    MEM32(ebx + 0x14) = MEM32(ebx + 0x14) + eax;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    MEM8(ebp + -1) = 0;
    g_seh_ebp = ebp; sub_003BF47A(); return; /* tail jmp 0x003BF47A */

}

/**
 * sub_003BF461
 * Original: 0x003BF461 - 0x003BF47A (25 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF461(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BF461: ;
    if (CMP_NE(eax, 0xF)) goto loc_003BF46D; /* jne: not equal / not zero */

loc_003BF466: ;
    MEM32(ebx + 4) = 0xC000000Fu;

loc_003BF46D: ;
    eax = MEM32(edx);
    eax = eax >> 0x1C;
    eax = eax | 0xC0000000u;
    MEM32(ebx + 4) = eax;

    sub_003BF47A(); return; /* restored dropped fall-through to sub_003BF47A */
}

/**
 * sub_003BF47A
 * Original: 0x003BF47A - 0x003BF4E6 (108 bytes, 39 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF47A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF47A: ;
    esi = MEM32(edi + 8);
    esi = esi & 0xFFFFFFF0u;

loc_003BF480: ;
    SET_LO8(ebx, MEM8(edx + 0x1C));
    PUSH32(esp, edx);
    SET_LO8(ebx, LO8(ebx) & 2);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BECEB(); /* call 0x003BECEB */

loc_003BF48C: ;
    ecx = MEM32(ebp + -8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF3C0(); /* call 0x003BF3C0 */

loc_003BF496: ;
    eax = MEM32(0xF45F00);
    edx = eax + esi;
    /* cmp MEM8(edx + 0x1E), 2 - flags set for next jcc */
    esi = MEM32(edx + 8);
    if (CMP_NE(MEM8(edx + 0x1E), 2)) goto loc_003BF4AD; /* jne: not equal / not zero */

loc_003BF4A7: ;
    if (CMP_EQ(MEM8(ebp + -1), 0)) goto loc_003BF4B1; /* je: equal / zero */

loc_003BF4AD: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003BF480; } /* je: equal / zero */

loc_003BF4B1: ;
    eax = MEM32(edx + 0x10);
    eax = eax ^ MEM32(edi + 8);
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 0x10);
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    MEM32(edi + 8) = eax;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003BF4D1; /* je: equal / zero */

loc_003BF4C4: ;
    PUSH32(esp, MEM32(ebp + -16));
    ecx = MEM32(ebp + -8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF344(); /* call 0x003BF344 */

loc_003BF4D1: ;
    if (CMP_EQ(MEM8(edi + 0x11), 0)) goto loc_003BF4DD; /* je: equal / zero */

loc_003BF4D7: ;
    if (CMP_NE(MEM8(ebp + -1), 0)) goto loc_003BF4E1; /* jne: not equal / not zero */

loc_003BF4DD: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0xFFFFFFFEu;

loc_003BF4E1: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF4E6
 * Original: 0x003BF4E6 - 0x003BF52D (71 bytes, 25 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF4E6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF4E6: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM8(esi + 0x1E), 1 - flags set for next jcc */
    eax = MEM32(esi + 0x14);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x18);
    MEM32(ebp + -4) = ecx;
    MEM32(ebp + -8) = eax;
    if (CMP_NE(MEM8(esi + 0x1E), 1)) goto loc_003BF51B; /* jne: not equal / not zero */

loc_003BF501: ;
    eax = MEM32(esi + 0xC);
    ecx = MEM32(0xF45F00);
    eax = eax + ecx + -7;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BECEB(); /* call 0x003BECEB */

loc_003BF514: ;
    MEM16(0xF45F22) = MEM16(0xF45F22) + 1;

loc_003BF51B: ;
    if (TEST_Z(MEM8(esi + 3), 0xF0)) { g_seh_ebp = ebp; sub_003BF52D(); return; } /* je: equal / zero */

loc_003BF521: ;
    ecx = MEM32(ebp + -4);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF3F2(); /* call 0x003BF3F2 */

loc_003BF52B: ;
    g_seh_ebp = ebp; sub_003BF58E(); return; /* tail jmp 0x003BF58E */

}

/**
 * sub_003BF52D
 * Original: 0x003BF52D - 0x003BF58E (97 bytes, 35 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF52D(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF52D: ;
    eax = MEM32(esi + 4);
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, ebx);
    if (TEST_Z(eax, eax)) goto loc_003BF55B; /* je: equal / zero */

loc_003BF535: ;
    ecx = MEM32(esi + 0xC);
    edx = 0xFFF;
    eax = eax & edx;
    ebx = eax;
    eax = ZX8(MEM8(esi + 0x1D));
    ecx = ecx & edx;
    eax = eax - ecx;
    if (CMP_L(ecx, ebx)) goto loc_003BF551; /* jl: less (signed <) */

loc_003BF54D: ;
    eax = eax + ebx;
    goto loc_003BF558;

loc_003BF551: ;
    eax = eax + ebx + -4096;

loc_003BF558: ;
    eax--;
    goto loc_003BF55F;

loc_003BF55B: ;
    eax = ZX8(MEM8(esi + 0x1D));

loc_003BF55F: ;
    MEM32(edi + 0x14) = MEM32(edi + 0x14) + eax;
    SET_LO8(ebx, MEM8(esi + 0x1C));
    PUSH32(esp, esi);
    SET_LO8(ebx, LO8(ebx) & 2);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BECEB(); /* call 0x003BECEB */

loc_003BF56E: ;
    edx = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF3C0(); /* call 0x003BF3C0 */

loc_003BF579: ;
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    _rccf = (TEST_Z(LO8(ebx), LO8(ebx)));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    POP32(esp, ebx);
    if (_rccf) { g_seh_ebp = ebp; sub_003BF58E(); return; } /* je: equal / zero */

loc_003BF57E: ;
    edx = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    MEM32(edi + 4) = MEM32(edi + 4) & 0;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF344(); /* call 0x003BF344 */

    g_seh_ebp = ebp; sub_003BF58E(); return; /* restored dropped fall-through to sub_003BF58E */
}

/**
 * sub_003BF58E
 * Original: 0x003BF58E - 0x003BF592 (4 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF58E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF58E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF592
 * Original: 0x003BF592 - 0x003BF694 (258 bytes, 87 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF592(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF592: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = edx;
    ebx = ecx;
    edx = 0; /* xor self */
    /* cmp MEM32(ebx + 0x42C), edx - flags set for next jcc */
    MEM32(ebp + -20) = edi;
    MEM32(ebp + -8) = ebx;
    MEM32(ebp + -4) = edx;
    if (CMP_EQ(MEM32(ebx + 0x42C), edx)) goto loc_003BF683; /* je: equal / zero */

loc_003BF5B5: ;
    PUSH32(esp, esi);
    goto loc_003BF5BB;

loc_003BF5B8: ;
    edi = MEM32(ebp + -20);

loc_003BF5BB: ;
    ecx = MEM32(ebx + 0x42C);
    eax = MEM32(ecx + 0x24);
    MEM32(ebx + 0x42C) = eax;
    esi = MEM32(ecx + 0x10);
    if (CMP_AE(edi, MEM32(esi + 0x1C))) goto loc_003BF5DD; /* jae: above or equal (unsigned >=) */

loc_003BF5D2: ;
    MEM32(ecx + 0x24) = edx;
    MEM32(ebp + -4) = ecx;
    goto loc_003BF672;

loc_003BF5DD: ;
    SET_LO8(eax, MEM8(esi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003BF5EF; /* je: equal / zero */

loc_003BF5E4: ;
    edi++;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM32(esi + 0x1C) = edi;
    MEM8(esi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003BF5D2; }

loc_003BF5EF: ;
    eax = MEM32(esi + 8);
    edi = MEM32(0xF45F00);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM32(ebp + -24) = eax;
    eax = eax & 0xFFFFFFF0u;
    edx = edi + eax;
    /* cmp ecx, MEM32(edx + 0x18) - flags set for next jcc */
    MEM32(ebp + -16) = eax;
    if (CMP_EQ(ecx, MEM32(edx + 0x18))) goto loc_003BF625; /* je: equal / zero */

loc_003BF60D: ;
    ebx = MEM32(esi + 4);

loc_003BF610: ;
    if (CMP_EQ(eax, ebx)) goto loc_003BF622; /* je: equal / zero */

loc_003BF614: ;
    MEM32(ebp + -12) = eax;
    eax = MEM32(edx + 8);
    edx = edi + eax;
    if (CMP_NE(ecx, MEM32(edx + 0x18))) { RECOMP_SLICE_POINT(); goto loc_003BF610; } /* jne: not equal / not zero */

loc_003BF622: ;
    ebx = MEM32(ebp + -8);

loc_003BF625: ;
    eax = MEM32(edx + 8);
    eax = eax ^ MEM32(ebp + -24);
    ecx = ebx;
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 8);
    MEM32(esi + 8) = eax;
    MEM8(edx + 3) = MEM8(edx + 3) | 0xF0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF4E6(); /* call 0x003BF4E6 */

loc_003BF63F: ;
    eax = MEM32(ebp + -12);
    if (TEST_Z(eax, eax)) goto loc_003BF665; /* je: equal / zero */

loc_003BF646: ;
    ecx = MEM32(esi + 8);
    edx = MEM32(0xF45F00);
    ecx = ecx & 0xFFFFFFF0u;
    MEM32(edx + eax + 8) = ecx;
    eax = MEM32(esi + 8);
    eax = eax ^ MEM32(ebp + -16);
    eax = eax & 0xF;
    eax = eax ^ MEM32(ebp + -16);
    MEM32(esi + 8) = eax;

loc_003BF665: ;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003BF672; /* jne: not equal / not zero */

loc_003BF66A: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003BF672: ;
    /* cmp MEM32(ebx + 0x42C), 0 - flags set for next jcc */
    edx = MEM32(ebp + -4);
    if (CMP_NE(MEM32(ebx + 0x42C), 0)) { RECOMP_SLICE_POINT(); goto loc_003BF5B8; } /* jne: not equal / not zero */

loc_003BF682: ;
    POP32(esp, esi);

loc_003BF683: ;
    eax = 0; /* xor self */
    /* test edx, edx - flags set for next jcc */
    POP32(esp, edi);
    MEM32(ebx + 0x42C) = edx;
    SET_LO8(eax, (TEST_NZ(edx, edx)) ? 1 : 0); /* setne */
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF694
 * Original: 0x003BF694 - 0x003BF6EA (86 bytes, 35 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF694(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF694: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = edx;
    edi = ecx;
    SET_LO8(ebx, 0); /* xor self */

loc_003BF69D: ;
    eax = MEM32(esi + 8);
    ecx = eax;
    ecx = ecx & 0xFFFFFFF0u;
    if ((ecx == 0)) goto loc_003BF6E6; /* je: equal / zero */

loc_003BF6A7: ;
    edx = MEM32(0xF45F00);
    edx = edx + ecx;
    if (CMP_EQ(ecx, MEM32(esi + 4))) goto loc_003BF6D0; /* je: equal / zero */

loc_003BF6B4: ;
    eax = MEM32(edx + 8);
    MEM8(edx + 3) = MEM8(edx + 3) | 0xF0;
    eax = eax ^ MEM32(esi + 8);
    ecx = edi;
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 8);
    MEM32(esi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF4E6(); /* call 0x003BF4E6 */

loc_003BF6CE: ;
    goto loc_003BF6E2;

loc_003BF6D0: ;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    eax = eax & 0xF;
    PUSH32(esp, edx);
    MEM32(esi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BECEB(); /* call 0x003BECEB */

loc_003BF6E0: ;
    SET_LO8(ebx, 1);

loc_003BF6E2: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003BF69D; } /* je: equal / zero */

loc_003BF6E6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF6EA
 * Original: 0x003BF6EA - 0x003BF771 (135 bytes, 50 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF6EA(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF6EA: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebx = ecx;
    ebp = 0; /* xor self */
    /* cmp MEM32(ebx + 0x430), ebp - flags set for next jcc */
    MEM32(esp + 8) = edx;
    if (CMP_EQ(MEM32(ebx + 0x430), ebp)) goto loc_003BF760; /* je: equal / zero */

loc_003BF6FD: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003BF6FF: ;
    edi = MEM32(ebx + 0x430);
    eax = MEM32(edi + 0x24);
    MEM32(ebx + 0x430) = eax;
    esi = MEM32(edi + 0x10);
    if (CMP_AE(edx, MEM32(esi + 0x1C))) goto loc_003BF71D; /* jae: above or equal (unsigned >=) */

loc_003BF716: ;
    MEM32(edi + 0x14) = ebp;
    ebp = edi;
    goto loc_003BF755;

loc_003BF71D: ;
    SET_LO8(eax, MEM8(esi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003BF731; /* je: equal / zero */

loc_003BF724: ;
    ecx = edx + 1;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM32(esi + 0x1C) = ecx;
    MEM8(esi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003BF716; }

loc_003BF731: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF694(); /* call 0x003BF694 */

loc_003BF73A: ;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003BF747; /* jne: not equal / not zero */

loc_003BF73F: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003BF747: ;
    MEM32(edi + 4) = MEM32(edi + 4) & 0;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BF751: ;
    edx = MEM32(esp + 0x10);

loc_003BF755: ;
    if (CMP_NE(MEM32(ebx + 0x430), 0)) { RECOMP_SLICE_POINT(); goto loc_003BF6FF; } /* jne: not equal / not zero */

loc_003BF75E: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BF760: ;
    eax = 0; /* xor self */
    MEM32(ebx + 0x430) = ebp;
    /* test ebp, ebp - flags set for next jcc */
    _rccf = (TEST_NZ(ebp, ebp));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    POP32(esp, ebp);
    SET_LO8(eax, (_rccf) ? 1 : 0); /* setne */
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF771
 * Original: 0x003BF771 - 0x003BF84B (218 bytes, 75 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF771(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF771: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    ebx = ecx;
    ecx = 0; /* xor self */
    /* cmp MEM32(ebx + 0x434), ecx - flags set for next jcc */
    MEM32(ebp + -8) = edx;
    MEM32(ebp + -4) = ecx;
    if (CMP_EQ(MEM32(ebx + 0x434), ecx)) goto loc_003BF83B; /* je: equal / zero */

loc_003BF78E: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003BF790: ;
    esi = MEM32(ebx + 0x434);
    eax = MEM32(esi + 0x14);
    MEM32(ebx + 0x434) = eax;
    edi = MEM32(esi + 0x10);
    eax = MEM32(ebp + -8);
    if (CMP_AE(eax, MEM32(edi + 0x1C))) goto loc_003BF7B2; /* jae: above or equal (unsigned >=) */

loc_003BF7AA: ;
    MEM32(esi + 0x14) = ecx;
    MEM32(ebp + -4) = esi;
    goto loc_003BF829;

loc_003BF7B2: ;
    SET_LO8(eax, MEM8(edi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003BF7C0; /* je: equal / zero */

loc_003BF7B9: ;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM8(edi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003BF7AA; }

loc_003BF7C0: ;
    /* cmp MEM8(esi + 1), 0x4A - flags set for next jcc */
    ecx = ebx;
    if (CMP_NE(MEM8(esi + 1), 0x4A)) goto loc_003BF7D1; /* jne: not equal / not zero */

loc_003BF7C8: ;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFB64(); /* call 0x003BFB64 */

loc_003BF7CF: ;
    goto loc_003BF829;

loc_003BF7D1: ;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF694(); /* call 0x003BF694 */

loc_003BF7D8: ;
    edx = MEM32(esi + 0x18);
    if (TEST_Z(edx, edx)) goto loc_003BF811; /* je: equal / zero */

loc_003BF7DF: ;
    ecx = MEM32(edi);
    MEM32(ebp + -12) = ecx;
    ecx = ecx >> 7;
    eax = 0; /* xor self */
    ecx = ecx & 0xF;
    eax++;
    eax = eax << LO8(ecx);
    ecx = MEM32(ebp + -12);
    ecx = ecx & 0x1800;
    if (CMP_NE(ecx, 0x1000)) goto loc_003BF803; /* jne: not equal / not zero */

loc_003BF800: ;
    eax = eax << 0x10;

loc_003BF803: ;
    if (TEST_Z(MEM8(edi + 8), 2)) goto loc_003BF80D; /* je: equal / zero */

loc_003BF809: ;
    MEM32(edx) = MEM32(edx) | eax;
    goto loc_003BF811;

loc_003BF80D: ;
    eax = ~eax;
    MEM32(edx) = MEM32(edx) & eax;

loc_003BF811: ;
    eax = MEM32(0xF45F08);
    MEM32(edi + 0x18) = eax;
    MEM32(0xF45F08) = edi;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BF829: ;
    /* cmp MEM32(ebx + 0x434), 0 - flags set for next jcc */
    ecx = MEM32(ebp + -4);
    if (CMP_NE(MEM32(ebx + 0x434), 0)) { RECOMP_SLICE_POINT(); goto loc_003BF790; } /* jne: not equal / not zero */

loc_003BF839: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BF83B: ;
    eax = 0; /* xor self */
    /* test ecx, ecx - flags set for next jcc */
    MEM32(ebx + 0x434) = ecx;
    SET_LO8(eax, (TEST_NZ(ecx, ecx)) ? 1 : 0); /* setne */
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF84B
 * Original: 0x003BF84B - 0x003BF961 (278 bytes, 96 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF84B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF84B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0xC);
    ebx = MEM32(esi);
    eax = esi + 0x438;
    ecx = MEM32(eax);
    PUSH32(esp, edi);
    MEM32(ebp + -4) = ecx;
    edi = 0; /* xor self */
    ecx = esi;
    MEM8(ebp + 0xF) = 0;
    MEM32(eax) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF231(); /* call 0x003BF231 */

loc_003BF872: ;
    if (TEST_Z(MEM8(ebp + -4), 2)) goto loc_003BF8CF; /* je: equal / zero */

loc_003BF878: ;
    ecx = MEM32(esi + 8);
    ecx = ecx + 0x84;
    eax = MEM32(ecx);
    eax = eax & 0xFFFFFFF0u;
    MEM32(ecx) = edi;
    if ((eax == 0)) goto loc_003BF8BB; /* je: equal / zero */

loc_003BF88A: ;
    ecx = MEM32(0xF45F00);
    ecx = ecx + eax;
    eax = MEM32(ecx + 8);
    /* test eax, eax - flags set for next jcc */
    MEM32(ecx + 8) = edi;
    edi = ecx;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BF88A; } /* jne: not equal / not zero */

loc_003BF89E: ;
    edx = edi;
    /* test MEM8(edx + 2), 1 - flags set for next jcc */
    edi = MEM32(edi + 8);
    ecx = esi;
    if (TEST_Z(MEM8(edx + 2), 1)) goto loc_003BF8B2; /* je: equal / zero */

loc_003BF8AB: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFECD(); /* call 0x003BFECD */

loc_003BF8B0: ;
    goto loc_003BF8B7;

loc_003BF8B2: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF4E6(); /* call 0x003BF4E6 */

loc_003BF8B7: ;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003BF89E; } /* jne: not equal / not zero */

loc_003BF8BB: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFFDu;
    MEM32(ebx + 0xC) = 2;
    eax = MEM32(esi);
    MEM32(eax + 8) = 6;

loc_003BF8CF: ;
    /* test MEM8(ebp + -4), 4 - flags set for next jcc */
    PUSH32(esp, 4);
    POP32(esp, edi);
    if (TEST_Z(MEM8(ebp + -4), 4)) goto loc_003BF8E2; /* je: equal / zero */

loc_003BF8D8: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFFBu;
    MEM32(ebx + 0xC) = edi;
    MEM32(ebx + 0x14) = edi;

loc_003BF8E2: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BF8E9: ;
    edx = eax;
    ecx = esi;
    MEM32(ebp + -8) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF592(); /* call 0x003BF592 */

loc_003BF8F5: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BF8FD; /* je: equal / zero */

loc_003BF8F9: ;
    MEM8(ebp + 0xF) = 1;

loc_003BF8FD: ;
    edx = MEM32(ebp + -8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF6EA(); /* call 0x003BF6EA */

loc_003BF907: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BF90F; /* je: equal / zero */

loc_003BF90B: ;
    MEM8(ebp + 0xF) = 1;

loc_003BF90F: ;
    edx = MEM32(ebp + -8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF771(); /* call 0x003BF771 */

loc_003BF919: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BF921; /* je: equal / zero */

loc_003BF91D: ;
    MEM8(ebp + 0xF) = 1;

loc_003BF921: ;
    if (CMP_EQ(MEM8(ebp + 0xF), 0)) goto loc_003BF931; /* je: equal / zero */

loc_003BF927: ;
    eax = MEM32(esi);
    MEM32(eax + 0xC) = edi;
    eax = MEM32(esi);
    MEM32(eax + 0x10) = edi;

loc_003BF931: ;
    if (TEST_Z(MEM8(ebp + -4), 0x40)) goto loc_003BF949; /* je: equal / zero */

loc_003BF937: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE63E(); /* call 0x003BE63E */

loc_003BF93E: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFBFu;
    MEM32(ebx + 0xC) = 0x40;

loc_003BF949: ;
    eax = MEM32(ebp + -4);
    if (TEST_Z(eax, eax)) goto loc_003BF953; /* je: equal / zero */

loc_003BF950: ;
    MEM32(ebx + 0xC) = eax;

loc_003BF953: ;
    POP32(esp, edi);
    POP32(esp, esi);
    MEM32(ebx + 0x10) = 0x80000000u;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BF961
 * Original: 0x003BF961 - 0x003BF973 (18 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF961(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BF961: ;
    eax = MEM32(0xF45F28);
    if (TEST_Z(eax, eax)) goto loc_003BF972; /* je: equal / zero */

loc_003BF96A: ;
    ecx = MEM32(eax);
    MEM32(0xF45F28) = ecx;

loc_003BF972: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BF973
 * Original: 0x003BF973 - 0x003BF9A9 (54 bytes, 18 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF973(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF973: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    eax = MEM32(0xF45F2C);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    ebx = edx;
    MEM32(ebp + -20) = ecx;
    MEM32(ebp + -8) = eax;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF98E: ;
    MEM8(ebp + -2) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF961(); /* call 0x003BF961 */

loc_003BF996: ;
    edi = eax;
    /* test edi, edi - flags set for next jcc */
    MEM32(ebp + -12) = edi;
    if (TEST_NZ(edi, edi)) { g_seh_ebp = ebp; sub_003BF9A9(); return; } /* jne: not equal / not zero */

loc_003BF99F: ;
    edi = 0x80000100u;
    g_seh_ebp = ebp; sub_003BFB0E(); return; /* tail jmp 0x003BFB0E */

}

/**
 * sub_003BF9A9
 * Original: 0x003BF9A9 - 0x003BFB0E (357 bytes, 122 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF9A9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF9A9: ;
    PUSH32(esp, esi);
    esi = MEM32(ebp + -8);
    esi = esi << 6;
    eax = 0; /* xor self */
    ecx = esi + 0x30;
    edx = ecx;
    ecx = ecx >> 2;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    eax = MEM32(ebp + -12);
    esi = esi + eax;
    MEM32(esi + 0x2C) = eax;
    eax = esi;
    eax = eax - MEM32(0xF45F00);
    MEM8(esi + 0x11) = 1;
    MEM32(esi + 0x14) = eax;
    eax = 0; /* xor self */
    MEM8(esi + 0x13) = 1;
    SET_LO16(eax, MEM16(ebx + 0x16));
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB01B(); /* call 0x003BB01B */

loc_003BF9EE: ;
    edx = MEM32(ebp + -8);
    MEM16(esi + 0x22) = LO16(eax);
    MEM8(esi + 0x24) = LO8(edx);
    SET_LO8(eax, MEM8(ebx + 0x18));
    SET_LO8(eax, LO8(eax) & 1);
    MEM8(esi + 0x10) = LO8(eax);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebx + 0x14));
    PUSH32(esp, 0);
    eax = eax ^ MEM32(esi);
    eax = eax & 0x7F;
    MEM32(esi) = MEM32(esi) ^ eax;
    eax = ZX8(MEM8(ebx + 0x15));
    ecx = MEM32(esi);
    eax = eax << 7;
    eax = eax ^ ecx;
    eax = eax & 0x780;
    eax = eax ^ ecx;
    MEM32(esi) = eax;
    /* test MEM8(ebx + 0x15), 0x80 - flags set for next jcc */
    POP32(esp, ecx);
    SET_LO8(ecx, (TEST_NZ(MEM8(ebx + 0x15), 0x80)) ? 1 : 0); /* setne */
    eax = eax & 0xFFFFC7FFu;
    ecx++;
    ecx = ecx & 3;
    ecx = ecx | 0x18;
    ecx = ecx << 0xB;
    ecx = ecx | eax;
    MEM32(esi) = ecx;
    eax = ZX16(MEM16(ebx + 0x16));
    eax = eax << 0x10;
    eax = eax ^ ecx;
    eax = eax & 0x7FF0000;
    eax = eax ^ ecx;
    ecx = MEM32(esi + 8);
    MEM32(esi) = eax;
    eax = MEM32(esi + 0x2C);
    eax = eax - MEM32(0xF45F00);
    ecx = ecx ^ eax;
    ecx = ecx & 0xF;
    ecx = ecx ^ eax;
    MEM32(esi + 8) = ecx;
    SET_LO8(ecx, 0); /* xor self */
    /* test edx, edx - flags set for next jcc */
    MEM32(esi + 4) = eax;
    MEM8(ebp + -1) = LO8(ecx);
    if (CMP_BE(edx & edx, 0)) goto loc_003BFACE; /* jbe: below or equal (unsigned <=) */

loc_003BFA71: ;
    eax = 0; /* xor self */

loc_003BFA73: ;
    edx = MEM32(esi + 0x2C);
    eax = eax << 6;
    edi = eax + edx;
    MEM32(ebp + -16) = edi;
    edi = edi - MEM32(0xF45F00);
    edx = MEM32(ebp + -16);
    edi = edi + 0x40;
    SET_LO8(ecx, LO8(ecx) - 1);
    MEM8(edx + 0x2D) = LO8(ecx);
    edx = MEM32(esi + 0x2C);
    SET_LO8(ecx, MEM8(ebp + -1));
    MEM8(eax + edx + 0x2C) = LO8(ecx);
    edx = MEM32(esi + 0x2C);
    MEM32(eax + edx + 0x20) = esi;
    edx = MEM32(esi + 0x2C);
    MEM32(eax + edx + 0x28) = MEM32(eax + edx + 0x28) & 0;
    edx = MEM32(esi + 0x2C);
    MEM32(eax + edx + 0x24) = MEM32(eax + edx + 0x24) & 0;
    edx = MEM32(esi + 0x2C);
    edx = edx + eax;
    MEM8(edx + 2) = MEM8(edx + 2) | 1;
    edx = MEM32(esi + 0x2C);
    SET_LO8(ecx, LO8(ecx) + 1);
    MEM32(eax + edx + 8) = edi;
    eax = ZX8(LO8(ecx));
    /* cmp eax, MEM32(ebp + -8) - flags set for next jcc */
    MEM8(ebp + -1) = LO8(ecx);
    if (CMP_B(eax, MEM32(ebp + -8))) { RECOMP_SLICE_POINT(); goto loc_003BFA73; } /* jb: below (unsigned <) */

loc_003BFACE: ;
    edx = MEM32(esi + 0x2C);
    eax = ZX8(LO8(ecx));
    eax = eax << 6;
    MEM32(eax + edx + -56) = MEM32(eax + edx + -56) & 0;
    eax = MEM32(esi + 0x2C);
    SET_LO8(ecx, LO8(ecx) - 1);
    MEM8(eax + 0x2D) = LO8(ecx);
    ecx = MEM32(ebp + -20);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEE22(); /* call 0x003BEE22 */

loc_003BFAEE: ;
    edi = eax;
    if (TEST_S(edi, edi)) goto loc_003BFAF9; /* jl: less (signed <) */

loc_003BFAF4: ;
    MEM32(ebx + 0x10) = esi;
    goto loc_003BFB0D;

loc_003BFAF9: ;
    MEM32(ebx + 0x10) = MEM32(ebx + 0x10) & 0;
    ecx = MEM32(0xF45F28);
    eax = MEM32(ebp + -12);
    MEM32(eax) = ecx;
    MEM32(0xF45F28) = eax;

loc_003BFB0D: ;
    POP32(esp, esi);

    g_seh_ebp = ebp; sub_003BFB0E(); return; /* restored dropped fall-through to sub_003BFB0E */
}

/**
 * sub_003BFB0E
 * Original: 0x003BFB0E - 0x003BFB20 (18 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFB0E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFB0E: ;
    SET_LO8(ecx, MEM8(ebp + -2));
    MEM32(ebx + 4) = edi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFB1A: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFB20
 * Original: 0x003BFB20 - 0x003BFB64 (68 bytes, 27 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFB20(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFB20: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = edx;
    ebp = MEM32(esi + 0x10);
    PUSH32(esp, edi);
    edi = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFB31: ;
    edx = ebp;
    ecx = edi;
    SET_LO8(ebx, LO8(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BEFFE(); /* call 0x003BEFFE */

loc_003BFB3C: ;
    edx = ebp;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BE9EA(); /* call 0x003BE9EA */

loc_003BFB45: ;
    eax = edi + 0x434;
    ecx = MEM32(eax);
    MEM32(esi + 0x14) = ecx;
    SET_LO8(ecx, LO8(ebx));
    MEM32(eax) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFB5A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = 0x40000000;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BFB64
 * Original: 0x003BFB64 - 0x003BFBED (137 bytes, 52 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFB64(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFB64: ;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebp = edx;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x10);
    SET_LO8(eax, MEM8(esi + 0x25));
    ebx = ZX8(MEM8(esi + 0x26));
    ecx = ZX8(LO8(eax));
    ebx = ebx - ecx;
    ecx = ZX8(MEM8(esi + 0x24));
    ebx = ebx + ecx;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BFBC6; /* je: equal / zero */

loc_003BFB82: ;
    PUSH32(esp, edi);

loc_003BFB83: ;
    ecx = ZX8(MEM8(esi + 0x24));
    eax = ebx;
    edx = 0; /* xor self */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)ecx);
      edx = (uint32_t)(_dividend % (uint32_t)ecx); }
    MEM8(esi + 0x25) = MEM8(esi + 0x25) - 1;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    ebx = edx;
    edi = ebx;
    edi = edi << 6;
    edi = edi + MEM32(esi + 0x2C);
    ebx++;
    PUSH32(esp, MEM32(edi + 4));
    { uint32_t _icall_t = MEM32(0x3C1688); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFBA6: ;
    eax = MEM32(edi + 0xC);
    ecx = MEM32(edi + 4);
    ecx = ecx ^ eax;
    if (TEST_Z(ecx, 0xFFFFF000u)) goto loc_003BFBBF; /* je: equal / zero */

loc_003BFBB6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C1688); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFBBF: ;
    if (CMP_NE(MEM8(esi + 0x25), 0)) { RECOMP_SLICE_POINT(); goto loc_003BFB83; } /* jne: not equal / not zero */

loc_003BFBC5: ;
    POP32(esp, edi);

loc_003BFBC6: ;
    eax = ZX8(MEM8(esi + 0x24));
    MEM8(esi + 0x25) = MEM8(esi + 0x25) - 1;
    eax = eax << 6;
    esi = esi - eax;
    eax = MEM32(0xF45F28);
    MEM32(esi) = eax;
    MEM32(0xF45F28) = esi;
    MEM32(ebp + 4) = MEM32(ebp + 4) & 0;
    PUSH32(esp, ebp);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BFBE9: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BFBED
 * Original: 0x003BFBED - 0x003BFC24 (55 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFBED(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFBED: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x24;
    MEM32(ebp + -20) = MEM32(ebp + -20) & 0;
    PUSH32(esp, esi);
    esi = edx;
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x10);
    MEM32(ebp + -16) = esi;
    MEM32(ebp + -36) = ecx;
    MEM32(ebp + -32) = edi;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFC0D: ;
    SET_LO8(ecx, MEM8(edi + 0x24));
    /* cmp LO8(ecx), MEM8(edi + 0x25) - flags set for next jcc */
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_NE(LO8(ecx), MEM8(edi + 0x25))) { g_seh_ebp = ebp; sub_003BFC24(); return; } /* jne: not equal / not zero */

loc_003BFC18: ;
    MEM32(ebp + -20) = 0xC0000D00u;
    g_seh_ebp = ebp; sub_003BFD39(); return; /* tail jmp 0x003BFD39 */

}

/**
 * sub_003BFC24
 * Original: 0x003BFC24 - 0x003BFD39 (277 bytes, 101 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFC24(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFC24: ;
    eax = ZX8(MEM8(edi + 0x26));
    PUSH32(esp, ebx);
    ebx = eax;
    ebx = ebx << 6;
    ebx = ebx + MEM32(edi + 0x2C);
    eax++;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    ecx = ZX8(LO8(ecx));
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    esi = MEM32(esi + 0x18);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM32(ebp + -28) = esi;
    MEM8(edi + 0x26) = LO8(edx);
    eax = MEM32(esi + 0x18);
    MEM32(ebx + 0x24) = eax;
    eax = MEM32(esi + 0x1C);
    MEM32(ebx + 0x28) = eax;
    eax = MEM32(ebp + -16);
    MEM32(ebx + 0x20) = edi;
    eax = ZX8(MEM8(eax + 0x14));
    eax = eax << 0x15;
    eax = eax ^ MEM32(ebx);
    eax = eax & 0xE00000;
    MEM32(ebx) = MEM32(ebx) ^ eax;
    ecx = MEM32(esi);
    eax = MEM32(ebx);
    ecx--;
    ecx = ecx << 0x18;
    ecx = ecx ^ eax;
    ecx = ecx & 0x7000000;
    ecx = ecx ^ eax;
    MEM32(ebx) = ecx;
    eax = MEM32(esi + 4);
    eax = eax & 0xFFF;
    /* cmp MEM32(esi), 0 - flags set for next jcc */
    MEM32(ebp + -24) = eax;
    if (CMP_BE(MEM32(esi), 0)) goto loc_003BFCB6; /* jbe: below or equal (unsigned <=) */

loc_003BFC8B: ;
    ecx = esi + 8;
    MEM32(ebp + -8) = ecx;
    ecx = ebx + 0x10;

loc_003BFC94: ;
    edx = eax;
    SET_LO16(edx, LO16(edx) | 0xE000);
    MEM16(ecx) = LO16(edx);
    edx = MEM32(ebp + -8);
    edx = ZX16(MEM16(edx));
    MEM32(ebp + -8) = MEM32(ebp + -8) + 2;
    eax = eax + edx;
    MEM32(ebp + -12) = MEM32(ebp + -12) + 1;
    edx = MEM32(ebp + -12);
    ecx++;
    ecx++;
    if (CMP_B(edx, MEM32(esi))) { RECOMP_SLICE_POINT(); goto loc_003BFC94; } /* jb: below (unsigned <) */

loc_003BFCB6: ;
    eax = eax - MEM32(ebp + -24);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(esi + 4));
    MEM32(ebp + -24) = eax;
    { uint32_t _icall_t = MEM32(0x3C1680); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFCC8: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi + 4));
    { uint32_t _icall_t = MEM32(0x3C167C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFCD1: ;
    ecx = MEM32(ebp + -24);
    MEM32(ebx + 4) = eax;
    eax = MEM32(esi + 4);
    eax = eax + ecx + -1;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C167C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFCE5: ;
    MEM32(ebx + 0xC) = eax;
    if (TEST_Z(MEM8(edi + 0x10), 1)) goto loc_003BFCFE; /* je: equal / zero */

loc_003BFCEE: ;
    esi = ebx + 0x10;
    edi = ebx + 0x30;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    esi = MEM32(ebp + -28);
    edi = MEM32(ebp + -32);

loc_003BFCFE: ;
    if (TEST_Z(MEM8(edi + 0x10), 2)) goto loc_003BFD24; /* je: equal / zero */

loc_003BFD04: ;
    ecx = MEM32(ebp + -36);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BFD0C: ;
    ecx = MEM32(edi + 0x28);
    eax++;
    edx = ecx;
    edx = edx - eax;
    if (CMP_LE(edx & edx, 0)) goto loc_003BFD1A; /* jle: less or equal (signed <=) */

loc_003BFD18: ;
    eax = ecx;

loc_003BFD1A: ;
    MEM16(ebx) = LO16(eax);
    ecx = MEM32(esi);
    ecx = ecx + eax;
    MEM32(edi + 0x28) = ecx;

loc_003BFD24: ;
    MEM8(edi + 0x25) = MEM8(edi + 0x25) + 1;
    SET_LO8(eax, MEM8(edi + 0x25));
    /* cmp LO8(eax), MEM8(edi + 0x24) - flags set for next jcc */
    esi = MEM32(ebp + -16);
    if (CMP_EQ(LO8(eax), MEM8(edi + 0x24))) goto loc_003BFD38; /* je: equal / zero */

loc_003BFD32: ;
    eax = MEM32(ebx + 8);
    MEM32(edi + 4) = eax;

loc_003BFD38: ;
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003BFD39(); return; /* restored dropped fall-through to sub_003BFD39 */
}

/**
 * sub_003BFD39
 * Original: 0x003BFD39 - 0x003BFD54 (27 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFD39(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFD39: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFD42: ;
    edi = MEM32(ebp + -20);
    PUSH32(esp, esi);
    MEM32(esi + 4) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BFD4E: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFD54
 * Original: 0x003BFD54 - 0x003BFD87 (51 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFD54(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFD54: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    MEM32(ebp + -16) = MEM32(ebp + -16) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(0x3C15E8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    esi = MEM32(edi + 0x10);
    MEM32(ebp + -12) = edi;
    MEM32(ebp + -8) = ecx;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFD74: ;
    /* test MEM8(esi + 0x10), 2 - flags set for next jcc */
    MEM8(ebp + -1) = LO8(eax);
    if (TEST_Z(MEM8(esi + 0x10), 2)) { g_seh_ebp = ebp; sub_003BFD87(); return; } /* je: equal / zero */

loc_003BFD7D: ;
    esi = 0xC0000E00u;
    g_seh_ebp = ebp; sub_003BFE53(); return; /* tail jmp 0x003BFE53 */

}

/**
 * sub_003BFD87
 * Original: 0x003BFD87 - 0x003BFE53 (204 bytes, 67 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFD87(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFD87: ;
    ecx = MEM32(ebp + -8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BFD8F: ;
    SET_LO8(edx, MEM8(esi + 0x10));
    if (TEST_Z(LO8(edx), 4)) goto loc_003BFDD1; /* je: equal / zero */

loc_003BFD97: ;
    SET_LO8(edx, LO8(edx) & 0xFB);
    /* cmp MEM32(esi + 0x1C), eax - flags set for next jcc */
    MEM8(esi + 0x10) = LO8(edx);
    if (CMP_NE(MEM32(esi + 0x1C), eax)) goto loc_003BFDC9; /* jne: not equal / not zero */

loc_003BFDA2: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFDAB: ;
    MEM32(ebp + -20) = MEM32(ebp + -20) | 0xFFFFFFFFu;
    eax = ebp + -24;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    MEM32(ebp + -24) = 0xFFFFD8F0u;
    { uint32_t _icall_t = MEM32(0x3C15D4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFDC4: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFDC6: ;
    MEM8(ebp + -1) = LO8(eax);

loc_003BFDC9: ;
    ecx = MEM32(ebp + -8);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BFDD1: ;
    if (TEST_Z(MEM8(esi + 0x10), 1)) goto loc_003BFDE6; /* je: equal / zero */

loc_003BFDD7: ;
    SET_LO8(ecx, MEM8(esi + 0x24));
    if (CMP_EQ(LO8(ecx), MEM8(esi + 0x25))) goto loc_003BFDE6; /* je: equal / zero */

loc_003BFDDF: ;
    esi = 0xC0001000u;
    g_seh_ebp = ebp; sub_003BFE53(); return; /* tail jmp 0x003BFE53 */

loc_003BFDE6: ;
    /* test MEM8(edi + 0x18), 1 - flags set for next jcc */
    ecx = eax + 1;
    if (TEST_NZ(MEM8(edi + 0x18), 1)) goto loc_003BFE01; /* jne: not equal / not zero */

loc_003BFDEF: ;
    edx = MEM32(edi + 0x14);
    eax = edx;
    eax = eax - ecx;
    if (((int32_t)eax < 0)) { g_seh_ebp = ebp; sub_003BFE6C(); return; } /* js: sign (negative) */

loc_003BFDF8: ;
    if (CMP_G(eax, 0x400)) { g_seh_ebp = ebp; sub_003BFE6C(); return; } /* jg: greater (signed >) */

loc_003BFDFF: ;
    ecx = edx;

loc_003BFE01: ;
    SET_LO8(edx, MEM8(esi + 0x24));
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) - MEM8(esi + 0x25));
    edi = ZX8(LO8(edx));
    SET_LO8(eax, LO8(eax) + MEM8(esi + 0x26));
    eax = ZX8(LO8(eax));
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)edi));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)edi)); }
    edi = MEM32(esi + 0x2C);

loc_003BFE18: ;
    edx = ZX8(LO8(edx));
    eax = edx;
    eax = eax << 6;
    MEM16(edi + eax) = LO16(ecx);
    edi = MEM32(esi + 0x2C);
    eax = ZX8(MEM8(edi + eax + 3));
    ebx = ZX8(MEM8(esi + 0x24));
    eax = eax & 7;
    ecx = ecx + eax + 1;
    eax = edx + 1;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ebx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ebx)); }
    if (CMP_NE(LO8(edx), MEM8(esi + 0x26))) { RECOMP_SLICE_POINT(); goto loc_003BFE18; } /* jne: not equal / not zero */

loc_003BFE42: ;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 2;
    edi = MEM32(ebp + -12);
    MEM32(esi + 0x28) = ecx;
    esi = MEM32(ebp + -16);

    g_seh_ebp = ebp; sub_003BFE53(); return; /* restored dropped fall-through to sub_003BFE53 */
}

/**
 * sub_003BFE53
 * Original: 0x003BFE53 - 0x003BFE73 (32 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFE53(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFE53: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFE5C: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BFE65: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFE6C
 * Original: 0x003BFE6C - 0x003BFE73 (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFE6C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFE6C: ;
    esi = 0xC0000B00u;
    g_seh_ebp = ebp; sub_003BFE53(); return; /* tail jmp 0x003BFE53 */

}

/**
 * sub_003BFE73
 * Original: 0x003BFE73 - 0x003BFEAD (58 bytes, 24 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFE73(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFE73: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    esi = MEM32(edi + 0x10);
    ebx = ecx;
    ebp = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFE87: ;
    /* test MEM8(esi + 0x10), 2 - flags set for next jcc */
    MEM8(esp + 0x13) = LO8(eax);
    if (TEST_Z(MEM8(esi + 0x10), 2)) { g_seh_ebp = ebp; sub_003BFEAD(); return; } /* je: equal / zero */

loc_003BFE91: ;
    MEM8(esi + 1) = MEM8(esi + 1) | 0x40;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BFE9C: ;
    eax++;
    eax++;
    MEM32(esi + 0x1C) = eax;
    SET_LO8(eax, MEM8(esi + 0x10));
    SET_LO8(eax, LO8(eax) & 0xFD);
    SET_LO8(eax, LO8(eax) | 4);
    MEM8(esi + 0x10) = LO8(eax);
    g_seh_ebp = ebp; sub_003BFEB2(); return; /* tail jmp 0x003BFEB2 */

}

/**
 * sub_003BFEAD
 * Original: 0x003BFEAD - 0x003BFEB2 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFEAD(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFEAD: ;
    ebp = 0xC0000F00u;

    g_seh_ebp = ebp; sub_003BFEB2(); return; /* restored dropped fall-through to sub_003BFEB2 */
}

/**
 * sub_003BFEB2
 * Original: 0x003BFEB2 - 0x003BFECD (27 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFEB2(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFEB2: ;
    SET_LO8(ecx, MEM8(esp + 0x13));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFEBC: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BB007(); /* call 0x003BB007 */

loc_003BFEC5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebp;
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BFECD
 * Original: 0x003BFECD - 0x003BFF74 (167 bytes, 67 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFECD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFECD: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x2C;
    PUSH32(esp, ebx);
    ebx = edx;
    eax = MEM32(ebx);
    PUSH32(esp, esi);
    edx = MEM32(ebx + 0x20);
    MEM32(ebx + 8) = MEM32(ebx + 8) & 0;
    esi = eax;
    esi = esi >> 0x1C;
    MEM32(ebp + -44) = esi;
    eax = eax >> 0x18;
    eax = eax & 7;
    PUSH32(esp, edi);
    eax++;
    MEM32(ebp + -40) = eax;
    eax = MEM32(ebx + 0x28);
    esi = ebx + 0x10;
    MEM32(ebp + -8) = esi;
    edi = ebp + -36;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(ebp + -16) = eax;
    eax = MEM32(ebx + 0x24);
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    edi = MEM32(edx + 0x2C);
    MEM32(ebp + -20) = eax;
    eax = ZX8(MEM8(ebx + 0x2D));
    esi = ebx;
    esi = esi - MEM32(0xF45F00);
    eax = eax << 6;
    MEM32(eax + edi + 8) = esi;
    /* test MEM8(edx + 0x10), 1 - flags set for next jcc */
    MEM32(ebp + -4) = edx;
    MEM32(ebp + -12) = esi;
    if (TEST_Z(MEM8(edx + 0x10), 1)) { g_seh_ebp = ebp; sub_003BFF74(); return; } /* je: equal / zero */

loc_003BFF2E: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BF20D(); /* call 0x003BF20D */

loc_003BFF33: ;
    ecx = MEM32(ebp + -4);
    esi = eax;
    eax = MEM32(ecx + 0x28);
    esi++;
    edx = eax;
    edx = edx - esi;
    if (((int32_t)edx < 0)) goto loc_003BFF44; /* js: sign (negative) */

loc_003BFF42: ;
    esi = eax;

loc_003BFF44: ;
    edi = MEM32(ebp + -8);
    MEM16(ebx) = LO16(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebx + 3));
    eax = eax & 7;
    eax = eax + esi + 1;
    MEM32(ecx + 0x28) = eax;
    esi = ebx + 0x30;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    eax = ZX8(MEM8(ecx + 0x26));
    esi = ZX8(MEM8(ecx + 0x24));
    eax++;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)esi));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)esi)); }
    esi = MEM32(ebp + -12);
    MEM8(ecx + 0x26) = LO8(edx);
    g_seh_ebp = ebp; sub_003BFFAB(); return; /* tail jmp 0x003BFFAB */

}

/**
 * sub_003BFF74
 * Original: 0x003BFF74 - 0x003BFFAB (55 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFF74(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFF74: ;
    edi = MEM32(0x3C1688);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, MEM32(ebx + 4));
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFF81: ;
    eax = MEM32(ebx + 0xC);
    ecx = MEM32(ebx + 4);
    ecx = ecx ^ eax;
    if (TEST_Z(ecx, 0xFFFFF000u)) goto loc_003BFF96; /* je: equal / zero */

loc_003BFF91: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFF96: ;
    ecx = MEM32(ebp + -4);
    SET_LO8(eax, MEM8(ecx + 0x25));
    /* cmp LO8(eax), MEM8(ecx + 0x24) - flags set for next jcc */
    SET_LO8(edx, (CMP_EQ(LO8(eax), MEM8(ecx + 0x24))) ? 1 : 0); /* sete */
    SET_LO8(eax, LO8(eax) - 1);
    /* test LO8(edx), LO8(edx) - flags set for next jcc */
    MEM8(ecx + 0x25) = LO8(eax);
    if (TEST_Z(LO8(edx), LO8(edx))) { g_seh_ebp = ebp; sub_003BFFAE(); return; } /* je: equal / zero */

    g_seh_ebp = ebp; sub_003BFFAB(); return; /* restored dropped fall-through to sub_003BFFAB */
}

/**
 * sub_003BFFAB
 * Original: 0x003BFFAB - 0x003BFFBD (18 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFAB(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFFAB: ;
    MEM32(ecx + 4) = esi;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -16));
    eax = ebp + -44;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(ebp + -20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFFB8: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFFAE
 * Original: 0x003BFFAE - 0x003BFFBD (15 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFAE(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFFAE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -16));
    eax = ebp + -44;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(ebp + -20); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFFB8: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFFBD
 * Original: 0x003BFFBD - 0x003BFFDD (32 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFBD(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BFFBD: ;
    eax = MEM32(0xF45F0C);
    if (TEST_Z(eax, eax)) goto loc_003BFFCF; /* je: equal / zero */

loc_003BFFC6: ;
    ecx = MEM32(eax + 0x14);
    MEM32(0xF45F0C) = ecx;

loc_003BFFCF: ;
    SET_LO8(ecx, MEM8(esp + 4));
    MEM8(eax + 2) = MEM8(eax + 2) & 0xFE;
    MEM8(eax + 0x1F) = LO8(ecx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BFFDD
 * Original: 0x003BFFDD - 0x003BFFEF (18 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFDD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFFDD: ;
    SET_LO16(eax, MEM16(esp + 4));
    if (CMP_AE(MEM16(0xF45F22), LO16(eax))) { g_seh_ebp = ebp; sub_003BFFEF(); return; } /* jae: above or equal (unsigned >=) */

loc_003BFFEB: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003BFFF9(); return; /* tail jmp 0x003BFFF9 */

}

/**
 * sub_003BFFEF
 * Original: 0x003BFFEF - 0x003BFFF9 (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFEF(void)
{

loc_003BFFEF: ;
    MEM16(0xF45F22) = MEM16(0xF45F22) - LO16(eax);
    eax = 0; /* xor self */
    eax++;

    sub_003BFFF9(); return; /* restored dropped fall-through to sub_003BFFF9 */
}

/**
 * sub_003BFFF9
 * Original: 0x003BFFF9 - 0x003BFFFC (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFF9(void)
{

loc_003BFFF9: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BFFFC
 * Original: 0x003BFFFC - 0x003C000E (18 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFFC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFFFC: ;
    SET_LO16(eax, MEM16(esp + 4));
    if (CMP_AE(MEM16(0xF45F26), LO16(eax))) { g_seh_ebp = ebp; sub_003C000E(); return; } /* jae: above or equal (unsigned >=) */

loc_003C000A: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003C0018(); return; /* tail jmp 0x003C0018 */

}

/**
 * sub_003C000E
 * Original: 0x003C000E - 0x003C0018 (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C000E(void)
{

loc_003C000E: ;
    MEM16(0xF45F26) = MEM16(0xF45F26) - LO16(eax);
    eax = 0; /* xor self */
    eax++;

    sub_003C0018(); return; /* restored dropped fall-through to sub_003C0018 */
}

/**
 * sub_003C0018
 * Original: 0x003C0018 - 0x003C001B (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0018(void)
{

loc_003C0018: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C001B
 * Original: 0x003C001B - 0x003C004D (50 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C001B(void)
{
    int _rccf = 0; /* DOA3: deferred condition evaluated at the compare */
    int _flags = 0; /* fallback flag var */

loc_003C001B: ;
    PUSH32(esp, edi);
    edi = edx;
    edx = 0; /* xor self */
    SET_LO16(edx, MEM16(edi + 2));
    eax = 0; /* xor self */
    edx = edx & 0x7FF;
    if (CMP_EQ(MEM32(ecx + 0x14), eax)) goto loc_003C0042; /* je: equal / zero */

loc_003C0031: ;
    eax = MEM32(ecx + 0x14);
    PUSH32(esp, esi);
    esi = ZX16(LO16(edx));
    edx = 0; /* xor self */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)esi);
      edx = (uint32_t)(_dividend % (uint32_t)esi); }
    POP32(esp, esi);
    if (TEST_Z(edx, edx)) goto loc_003C0042; /* je: equal / zero */

loc_003C0041: ;
    eax++;

loc_003C0042: ;
    /* cmp MEM8(edi + 0x11), 0 - flags set for next jcc */
    _rccf = (CMP_NE(MEM8(edi + 0x11), 0));  /* DOA3: x86 latched these flags at the compare above and the branch below reads them, but an operand is overwritten in between -- evaluate the condition where the guest does. */
    POP32(esp, edi);
    if (_rccf) goto loc_003C004C; /* jne: not equal / not zero */

loc_003C0049: ;
    eax = eax + 3;

loc_003C004C: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C004D
 * Original: 0x003C004D - 0x003C0087 (58 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C004D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C004D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    PUSH32(esp, MEM32(esi));
    edi = edx;
    { uint32_t _icall_t = MEM32(0x3C167C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C005C: ;
    ecx = MEM32(esi);
    ecx = ecx & 0xFFF;
    edx = 0x1000;
    edx = edx - ecx;
    ecx = MEM32(esp + 0x10);
    MEM32(ecx) = edx;
    ebx = MEM32(edi);
    if (CMP_BE(edx, ebx)) goto loc_003C0079; /* jbe: below or equal (unsigned <=) */

loc_003C0077: ;
    MEM32(ecx) = ebx;

loc_003C0079: ;
    edx = MEM32(ecx);
    MEM32(edi) = MEM32(edi) - edx;
    ecx = MEM32(ecx);
    MEM32(esi) = MEM32(esi) + ecx;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C0087
 * Original: 0x003C0087 - 0x003C00ED (102 bytes, 35 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0087(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0087: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x28;
    eax = 0; /* xor self */
    PUSH32(esp, ebx);
    ebx = edx;
    SET_LO16(eax, MEM16(ebx + 2));
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    MEM32(ebp + -32) = ecx;
    SET_LO8(ecx, MEM8(ecx + 0x45C));
    MEM8(ebp + -24) = LO8(ecx);
    eax = eax & 0x7FF;
    MEM32(ebp + -40) = eax;
    eax = MEM32(edi + 0x14);
    MEM32(ebp + -16) = eax;
    eax = 0; /* xor self */
    MEM8(ebx + 0x26) = MEM8(ebx + 0x26) - 1;
    MEM8(ebx + 0x27) = MEM8(ebx + 0x27) + 1;
    SET_LO16(ecx, MEM16(edi + 0x22));
    SET_LO16(ecx, LO16(ecx) & 0xFFFD);
    SET_LO16(ecx, LO16(ecx) | 4);
    MEM16(edi + 0x22) = LO16(ecx);
    esi = MEM32(ebx + 4);
    /* cmp esi, eax - flags set for next jcc */
    MEM32(ebp + -20) = eax;
    MEM8(ebp + 0xB) = LO8(eax);
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -12) = eax;
    MEM32(ebp + -8) = eax;
    if (CMP_EQ(esi, eax)) { g_seh_ebp = ebp; sub_003C00ED(); return; } /* je: equal / zero */

loc_003C00E4: ;
    eax = MEM32(0xF45F00);
    esi = esi + eax;
    g_seh_ebp = ebp; sub_003C0106(); return; /* tail jmp 0x003C0106 */

}

/**
 * sub_003C00ED
 * Original: 0x003C00ED - 0x003C0106 (25 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C00ED(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C00ED: ;
    PUSH32(esp, MEM32(ebp + -24));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFBD(); /* call 0x003BFFBD */

loc_003C00F5: ;
    esi = eax;
    eax = MEM32(esi + 0x10);
    eax = eax ^ MEM32(ebx + 8);
    eax = eax & 0xF;
    eax = eax ^ MEM32(esi + 0x10);
    MEM32(ebx + 8) = eax;

    g_seh_ebp = ebp; sub_003C0106(); return; /* restored dropped fall-through to sub_003C0106 */
}

/**
 * sub_003C0106
 * Original: 0x003C0106 - 0x003C0385 (639 bytes, 204 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0106(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0106: ;
    /* cmp MEM8(ebx + 0x11), 0 - flags set for next jcc */
    MEM32(ebp + -4) = esi;
    if (CMP_NE(MEM8(ebx + 0x11), 0)) goto loc_003C0175; /* jne: not equal / not zero */

loc_003C010F: ;
    eax = 0; /* xor self */
    SET_LO8(eax, 0xFE);
    SET_LO8(eax, LO8(eax) - MEM8(ebp + -24));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFBD(); /* call 0x003BFFBD */

loc_003C011C: ;
    ecx = MEM32(edi + 0x28);
    PUSH32(esp, MEM32(ebp + -24));
    MEM32(eax) = ecx;
    ecx = MEM32(edi + 0x2C);
    MEM32(ebp + -36) = eax;
    MEM32(eax + 4) = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFBD(); /* call 0x003BFFBD */

loc_003C0132: ;
    esi = eax;
    eax = MEM32(ebp + -4);
    ecx = MEM32(eax);
    ecx = ecx & 0x3FFFF;
    ecx = ecx | 0xE2E00000u;
    MEM32(eax) = ecx;
    ecx = MEM32(ebp + -36);
    edx = MEM32(ecx + 0x10);
    MEM32(eax + 4) = edx;
    edx = MEM32(esi + 0x10);
    MEM32(eax + 8) = edx;
    ecx = MEM32(ecx + 0x10);
    ecx = ecx + 7;
    MEM8(ebp + 0xB) = 2;
    MEM32(eax + 0xC) = ecx;
    MEM32(eax + 0x14) = ebx;
    MEM8(eax + 0x1C) = 0;
    MEM8(eax + 0x1E) = 1;
    MEM8(eax + 0x1D) = 0;
    MEM32(eax + 0x18) = edi;

loc_003C0175: ;
    if (CMP_EQ(MEM32(ebp + -16), 0)) goto loc_003C0191; /* je: equal / zero */

loc_003C017B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(ebp + -16));
    PUSH32(esp, MEM32(edi + 0x18));
    { uint32_t _icall_t = MEM32(0x3C1680); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0189: ;
    eax = MEM32(edi + 0x18);
    MEM32(ebp + -36) = eax;
    goto loc_003C0195;

loc_003C0191: ;
    MEM8(edi + 0x1C) = 1;

loc_003C0195: ;
    if (CMP_EQ(MEM32(ebp + -16), 0)) goto loc_003C02B0; /* je: equal / zero */

loc_003C019F: ;
    eax = ebp + -20;
    PUSH32(esp, eax);
    edx = ebp + -16;
    ecx = ebp + -36;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C004D(); /* call 0x003C004D */

loc_003C01AE: ;
    MEM32(ebp + -4) = eax;

loc_003C01B1: ;
    edx = MEM32(ebp + -20);
    eax = MEM32(ebp + -12);
    ecx = MEM32(ebp + -40);
    eax = eax + edx;
    if (CMP_AE(eax, ecx)) goto loc_003C01D2; /* jae: above or equal (unsigned >=) */

loc_003C01C0: ;
    if (TEST_Z(edx, edx)) goto loc_003C028A; /* je: equal / zero */

loc_003C01C8: ;
    if (CMP_NE(MEM32(ebp + -16), 0)) goto loc_003C028A; /* jne: not equal / not zero */

loc_003C01D2: ;
    if (CMP_EQ(MEM32(ebp + -12), 0)) goto loc_003C01FA; /* je: equal / zero */

loc_003C01D8: ;
    ecx = ecx - MEM32(ebp + -12);
    eax = MEM32(ebp + -28);
    /* cmp edx, ecx - flags set for next jcc */
    MEM32(esi + 4) = eax;
    if (CMP_AE(edx, ecx)) goto loc_003C01E7; /* jae: above or equal (unsigned >=) */

loc_003C01E5: ;
    ecx = edx;

loc_003C01E7: ;
    SET_LO8(eax, MEM8(ebp + -12));
    MEM32(ebp + -4) = MEM32(ebp + -4) + ecx;
    SET_LO8(eax, LO8(eax) + LO8(ecx));
    edx = edx - ecx;
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM8(esi + 0x1D) = LO8(eax);
    goto loc_003C0218;

loc_003C01FA: ;
    /* cmp edx, ecx - flags set for next jcc */
    eax = MEM32(ebp + -4);
    MEM32(esi + 4) = eax;
    if (CMP_AE(edx, ecx)) goto loc_003C0210; /* jae: above or equal (unsigned >=) */

loc_003C0204: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + edx;
    MEM32(ebp + -20) = MEM32(ebp + -20) & 0;
    MEM8(esi + 0x1D) = LO8(edx);
    goto loc_003C021B;

loc_003C0210: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + ecx;
    MEM8(esi + 0x1D) = LO8(ecx);
    edx = edx - ecx;

loc_003C0218: ;
    MEM32(ebp + -20) = edx;

loc_003C021B: ;
    eax = MEM32(ebp + -4);
    ecx = MEM32(esi);
    MEM8(ebp + 0xB) = MEM8(ebp + 0xB) ^ 1;
    eax--;
    MEM32(esi + 0xC) = eax;
    eax = ZX8(MEM8(ebp + 0xB));
    PUSH32(esp, MEM32(ebp + -24));
    ecx = ecx & 0xFFBFFFF;
    ecx = ecx | 0xE0000000u;
    eax = eax << 0x18;
    eax = eax ^ ecx;
    eax = eax & 0x3000000;
    eax = eax ^ ecx;
    MEM32(esi) = ecx;
    eax = eax | 0xE00000;
    ecx = 0; /* xor self */
    MEM32(esi) = eax;
    MEM32(esi + 0x14) = ebx;
    MEM8(esi + 0x1C) = 0;
    MEM8(esi + 0x1E) = 0;
    SET_LO8(ecx, MEM8(edi + 0x1C));
    eax = eax & 0xF3E7FFFFu;
    MEM32(esi + 0x18) = edi;
    MEM32(ebp + -8) = esi;
    ecx = ecx & 3;
    ecx = ecx << 0x13;
    ecx = ecx | eax;
    MEM32(esi) = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFBD(); /* call 0x003BFFBD */

loc_003C027A: ;
    ecx = MEM32(ebp + -8);
    esi = eax;
    eax = MEM32(esi + 0x10);
    MEM32(ecx + 8) = eax;
    { RECOMP_SLICE_POINT(); goto loc_003C01B1; }

loc_003C028A: ;
    /* cmp MEM32(ebp + -16), 0 - flags set for next jcc */
    eax = MEM32(ebp + -4);
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -12) = edx;
    if (CMP_NE(MEM32(ebp + -16), 0)) { RECOMP_SLICE_POINT(); goto loc_003C019F; } /* jne: not equal / not zero */

loc_003C029D: ;
    if (CMP_EQ(MEM32(ebp + -8), 0)) goto loc_003C02B0; /* je: equal / zero */

loc_003C02A3: ;
    if (CMP_EQ(MEM8(edi + 0x1D), 0)) goto loc_003C02B0; /* je: equal / zero */

loc_003C02A9: ;
    eax = MEM32(ebp + -8);
    MEM8(eax + 2) = MEM8(eax + 2) | 4;

loc_003C02B0: ;
    if (CMP_NE(MEM8(ebx + 0x11), 0)) goto loc_003C0320; /* jne: not equal / not zero */

loc_003C02B6: ;
    MEM8(esi + 2) = MEM8(esi + 2) & 0xFB;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    /* cmp MEM8(edi + 0x1C), 2 - flags set for next jcc */
    PUSH32(esp, MEM32(ebp + -24));
    SET_LO8(eax, (CMP_NE(MEM8(edi + 0x1C), 2)) ? 1 : 0); /* setne */
    MEM32(ebp + -8) = esi;
    eax++;
    eax = eax << 0x13;
    eax = eax ^ ecx;
    eax = eax & 0x180000;
    eax = eax ^ ecx;
    ecx = 0; /* xor self */
    MEM32(esi) = eax;
    SET_LO8(ecx, MEM8(edi + 0x1E));
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) & 0;
    eax = eax & 0x1FFFFF;
    MEM32(esi + 0x14) = ebx;
    MEM8(esi + 0x1C) = 2;
    MEM8(esi + 0x1E) = 2;
    ecx = ecx & 7;
    ecx = ecx | 0xFFFFFF18u;
    ecx = ecx << 0x15;
    ecx = ecx | eax;
    MEM32(esi) = ecx;
    MEM32(esi + 0x18) = edi;
    MEM8(esi + 0x1D) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFBD(); /* call 0x003BFFBD */

loc_003C0313: ;
    ecx = MEM32(ebp + -8);
    esi = eax;
    eax = MEM32(esi + 0x10);
    MEM32(ecx + 8) = eax;
    goto loc_003C0338;

loc_003C0320: ;
    ecx = ZX8(MEM8(edi + 0x1E));
    eax = MEM32(ebp + -8);
    ecx = ecx << 0x15;
    ecx = ecx ^ MEM32(eax);
    MEM8(eax + 0x1C) = 2;
    ecx = ecx & 0xE00000;
    MEM32(eax) = MEM32(eax) ^ ecx;

loc_003C0338: ;
    MEM8(esi + 0x1E) = 3;
    SET_LO16(eax, MEM16(edi + 0x14));
    MEM32(edi + 0x14) = MEM32(edi + 0x14) & 0;
    MEM16(edi + 0x20) = LO16(eax);
    /* cmp MEM8(ebx + 0x20), 0 - flags set for next jcc */
    eax = MEM32(esi + 0x10);
    MEM32(ebx + 4) = eax;
    if (CMP_NE(MEM8(ebx + 0x20), 0)) goto loc_003C0358; /* jne: not equal / not zero */

loc_003C0354: ;
    MEM8(ebx + 1) = MEM8(ebx + 1) & 0xBF;

loc_003C0358: ;
    SET_LO8(ebx, MEM8(ebx + 0x11));
    if (TEST_NZ(LO8(ebx), LO8(ebx))) goto loc_003C036D; /* jne: not equal / not zero */

loc_003C035F: ;
    eax = MEM32(ebp + -32);
    eax = MEM32(eax);
    MEM32(eax + 8) = 2;
    goto loc_003C037E;

loc_003C036D: ;
    if (CMP_NE(LO8(ebx), 2)) goto loc_003C037E; /* jne: not equal / not zero */

loc_003C0372: ;
    eax = MEM32(ebp + -32);
    eax = MEM32(eax);
    MEM32(eax + 8) = 4;

loc_003C037E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C0385
 * Original: 0x003C0385 - 0x003C03D8 (83 bytes, 34 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0385(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0385: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM32(esi + 0x28), 0 - flags set for next jcc */
    MEM32(ebp + -4) = ecx;
    if (CMP_EQ(MEM32(esi + 0x28), 0)) goto loc_003C03D5; /* je: equal / zero */

loc_003C0395: ;
    PUSH32(esp, ebx);

loc_003C0396: ;
    eax = MEM32(esi + 0x28);
    SET_LO16(edx, MEM16(esi + 0x24));
    ebx = ZX16(MEM16(eax + 0x20));
    ecx = ZX16(LO16(edx));
    ecx = ecx + ebx;
    if (CMP_G(ecx, 3)) goto loc_003C03D4; /* jg: greater (signed >) */

loc_003C03AB: ;
    ecx = MEM32(eax + 0x24);
    /* test ecx, ecx - flags set for next jcc */
    MEM32(esi + 0x28) = ecx;
    if (TEST_NZ(ecx, ecx)) goto loc_003C03B8; /* jne: not equal / not zero */

loc_003C03B5: ;
    MEM32(esi + 0x2C) = MEM32(esi + 0x2C) & ecx;

loc_003C03B8: ;
    SET_LO16(ecx, MEM16(eax + 0x20));
    SET_LO16(ecx, LO16(ecx) + LO16(edx));
    MEM16(esi + 0x24) = LO16(ecx);
    ecx = MEM32(ebp + -4);
    PUSH32(esp, eax);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0087(); /* call 0x003C0087 */

loc_003C03CE: ;
    if (CMP_NE(MEM32(esi + 0x28), 0)) { RECOMP_SLICE_POINT(); goto loc_003C0396; } /* jne: not equal / not zero */

loc_003C03D4: ;
    POP32(esp, ebx);

loc_003C03D5: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C03D8
 * Original: 0x003C03D8 - 0x003C0425 (77 bytes, 26 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C03D8(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C03D8: ;
    PUSH32(esp, esi);
    esi = ecx;
    if (CMP_EQ(MEM32(esi + 0x424), 0)) goto loc_003C0423; /* je: equal / zero */

loc_003C03E4: ;
    PUSH32(esp, edi);

loc_003C03E5: ;
    edi = MEM32(esi + 0x424);
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi + 0x20));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFFC(); /* call 0x003BFFFC */

loc_003C03F7: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C0422; /* je: equal / zero */

loc_003C03FB: ;
    eax = MEM32(edi + 0x24);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x424) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003C040E; /* jne: not equal / not zero */

loc_003C0408: ;
    MEM32(esi + 0x428) = MEM32(esi + 0x428) & eax;

loc_003C040E: ;
    edx = MEM32(edi + 0x10);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0087(); /* call 0x003C0087 */

loc_003C0419: ;
    if (CMP_NE(MEM32(esi + 0x424), 0)) { RECOMP_SLICE_POINT(); goto loc_003C03E5; } /* jne: not equal / not zero */

loc_003C0422: ;
    POP32(esp, edi);

loc_003C0423: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C0425
 * Original: 0x003C0425 - 0x003C0472 (77 bytes, 26 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0425(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0425: ;
    PUSH32(esp, esi);
    esi = ecx;
    if (CMP_EQ(MEM32(esi + 0x41C), 0)) goto loc_003C0470; /* je: equal / zero */

loc_003C0431: ;
    PUSH32(esp, edi);

loc_003C0432: ;
    edi = MEM32(esi + 0x41C);
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi + 0x20));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BFFDD(); /* call 0x003BFFDD */

loc_003C0444: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C046F; /* je: equal / zero */

loc_003C0448: ;
    eax = MEM32(edi + 0x24);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x41C) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003C045B; /* jne: not equal / not zero */

loc_003C0455: ;
    MEM32(esi + 0x420) = MEM32(esi + 0x420) & eax;

loc_003C045B: ;
    edx = MEM32(edi + 0x10);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0087(); /* call 0x003C0087 */

loc_003C0466: ;
    if (CMP_NE(MEM32(esi + 0x41C), 0)) { RECOMP_SLICE_POINT(); goto loc_003C0432; } /* jne: not equal / not zero */

loc_003C046F: ;
    POP32(esp, edi);

loc_003C0470: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C0472
 * Original: 0x003C0472 - 0x003C0484 (18 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0472(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0472: ;
    eax = MEM32(esp + 4);
    if (CMP_BE(MEM16(eax + 0x20), 3)) { g_seh_ebp = ebp; sub_003C0484(); return; } /* jbe: below or equal (unsigned <=) */

loc_003C047D: ;
    eax = 0x80000500u;
    g_seh_ebp = ebp; sub_003C04A2(); return; /* tail jmp 0x003C04A2 */

}

/**
 * sub_003C0484
 * Original: 0x003C0484 - 0x003C04A2 (30 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0484(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0484: ;
    PUSH32(esp, esi);
    esi = MEM32(edx + 0x2C);
    if (TEST_Z(esi, esi)) goto loc_003C0491; /* je: equal / zero */

loc_003C048C: ;
    MEM32(esi + 0x24) = eax;
    goto loc_003C0494;

loc_003C0491: ;
    MEM32(edx + 0x28) = eax;

loc_003C0494: ;
    MEM32(edx + 0x2C) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0385(); /* call 0x003C0385 */

loc_003C049C: ;
    eax = 0x40000000;
    POP32(esp, esi);

    g_seh_ebp = ebp; sub_003C04A2(); return; /* restored dropped fall-through to sub_003C04A2 */
}

/**
 * sub_003C04A2
 * Original: 0x003C04A2 - 0x003C04A5 (3 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C04A2(void)
{

loc_003C04A2: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C04A5
 * Original: 0x003C04A5 - 0x003C04B8 (19 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C04A5(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003C04A5: ;
    SET_LO16(eax, MEM16(edx + 0x20));
    if (CMP_BE(LO16(eax), MEM16(0xF45F24))) { g_seh_ebp = ebp; sub_003C04B8(); return; } /* jbe: below or equal (unsigned <=) */

loc_003C04B2: ;
    eax = 0x80000500u;
    esp += 4; return; /* ret */

}

/**
 * sub_003C04B8
 * Original: 0x003C04B8 - 0x003C04E1 (41 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C04B8(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C04B8: ;
    eax = ecx + 0x424;
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003C04CE; /* je: equal / zero */

loc_003C04C3: ;
    eax = MEM32(ecx + 0x428);
    MEM32(eax + 0x24) = edx;
    goto loc_003C04D0;

loc_003C04CE: ;
    MEM32(eax) = edx;

loc_003C04D0: ;
    MEM32(ecx + 0x428) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C03D8(); /* call 0x003C03D8 */

loc_003C04DB: ;
    eax = 0x40000000;
    esp += 4; return; /* ret */

}

/**
 * sub_003C04E1
 * Original: 0x003C04E1 - 0x003C04F4 (19 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C04E1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003C04E1: ;
    SET_LO16(eax, MEM16(edx + 0x20));
    if (CMP_BE(LO16(eax), MEM16(0xF45F20))) { g_seh_ebp = ebp; sub_003C04F4(); return; } /* jbe: below or equal (unsigned <=) */

loc_003C04EE: ;
    eax = 0x80000500u;
    esp += 4; return; /* ret */

}

/**
 * sub_003C04F4
 * Original: 0x003C04F4 - 0x003C051D (41 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C04F4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C04F4: ;
    eax = ecx + 0x41C;
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003C050A; /* je: equal / zero */

loc_003C04FF: ;
    eax = MEM32(ecx + 0x420);
    MEM32(eax + 0x24) = edx;
    goto loc_003C050C;

loc_003C050A: ;
    MEM32(eax) = edx;

loc_003C050C: ;
    MEM32(ecx + 0x420) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0425(); /* call 0x003C0425 */

loc_003C0517: ;
    eax = 0x40000000;
    esp += 4; return; /* ret */

}

/**
 * sub_003C051D
 * Original: 0x003C051D - 0x003C057C (95 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C051D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C051D: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = edx;
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x10);
    ebx = ecx;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C001B(); /* call 0x003C001B */

loc_003C0534: ;
    MEM16(esi + 0x20) = LO16(eax);
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C053E: ;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) + 1;
    MEM32(esi + 0x24) = MEM32(esi + 0x24) & 0;
    MEM8(ebp + -1) = LO8(eax);
    MEM16(esi + 0x22) = 2;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    if ((eax == 0)) { g_seh_ebp = ebp; sub_003C057C(); return; } /* je: equal / zero */

loc_003C0557: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003C0571; /* je: equal / zero */

loc_003C055B: ;
    eax--;
    if ((eax == 0)) goto loc_003C0565; /* je: equal / zero */

loc_003C055E: ;
    ebx = 0x80000600u;
    g_seh_ebp = ebp; sub_003C058B(); return; /* tail jmp 0x003C058B */

loc_003C0565: ;
    PUSH32(esp, esi);
    edx = edi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0472(); /* call 0x003C0472 */

loc_003C056F: ;
    g_seh_ebp = ebp; sub_003C0585(); return; /* tail jmp 0x003C0585 */

loc_003C0571: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C04A5(); /* call 0x003C04A5 */

loc_003C057A: ;
    g_seh_ebp = ebp; sub_003C0585(); return; /* tail jmp 0x003C0585 */

}

/**
 * sub_003C057C
 * Original: 0x003C057C - 0x003C0585 (9 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C057C(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C057C: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C04E1(); /* call 0x003C04E1 */

    g_seh_ebp = ebp; sub_003C0585(); return; /* restored dropped fall-through to sub_003C0585 */
}

/**
 * sub_003C0585
 * Original: 0x003C0585 - 0x003C058B (6 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0585(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003C0585: ;
    ebx = eax;
    if (CMP_GE(ebx & ebx, 0)) { g_seh_ebp = ebp; sub_003C0593(); return; } /* jge: greater or equal (signed >=) */

    g_seh_ebp = ebp; sub_003C058B(); return; /* restored dropped fall-through to sub_003C058B */
}

/**
 * sub_003C058B
 * Original: 0x003C058B - 0x003C05A3 (24 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C058B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C058B: ;
    MEM16(esi + 0x22) = MEM16(esi + 0x22) & 0;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C059C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0593
 * Original: 0x003C0593 - 0x003C05A3 (16 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0593(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0593: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C059C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C05A3
 * Original: 0x003C05A3 - 0x003C068A (231 bytes, 84 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C05A3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003C05A3: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBE2D(); /* call 0x003BBE2D */

loc_003C05B3: ;
    esi = eax;
    /* cmp esi, 0x10 - flags set for next jcc */
    ecx = ebx;
    if (CMP_AE(esi, 0x10)) goto loc_003C0679; /* jae: above or equal (unsigned >=) */

loc_003C05C0: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB1(); /* call 0x003BBDB1 */

loc_003C05C5: ;
    SET_LO8(eax, MEM8(eax + 6));
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003C05D2; /* jne: not equal / not zero */

loc_003C05CC: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    goto loc_003C05E1;

loc_003C05D2: ;
    if (CMP_NE(LO8(eax), 1)) goto loc_003C0677; /* jne: not equal / not zero */

loc_003C05DA: ;
    MEM32(ebp + 8) = 1;

loc_003C05E1: ;
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    PUSH32(esp, 1);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003C05EE: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003C0611; /* je: equal / zero */

loc_003C05F4: ;
    SET_LO8(ecx, MEM8(ebp + 8));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF2A670;
    SET_LO8(eax, MEM8(esi + 0xB));
    SET_LO8(eax, LO8(eax) & 0x6F);
    SET_LO8(ecx, LO8(ecx) << 7);
    SET_LO8(eax, LO8(eax) | LO8(ecx));
    SET_LO8(eax, LO8(eax) | 0x10);
    MEM8(esi + 0xB) = LO8(eax);
    goto loc_003C0637;

loc_003C0611: ;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBDB7(); /* call 0x003BBDB7 */

loc_003C061E: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003C0677; /* je: equal / zero */

loc_003C0624: ;
    if (CMP_NE(MEM32(ebp + 8), 0)) goto loc_003C0677; /* jne: not equal / not zero */

loc_003C062A: ;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF2A6E0;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xEF;

loc_003C0637: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 1;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C0643: ;
    /* test MEM8(esi + 0xB), 0x10 - flags set for next jcc */
    MEM32(esi + 4) = ebx;
    SET_LO8(eax, MEM8(edi + 2));
    MEM8(esi + 0xA) = LO8(eax);
    SET_LO16(eax, MEM16(edi + 4));
    MEM16(esi + 8) = LO16(eax);
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C0666; /* je: equal / zero */

loc_003C065A: ;
    eax = MEM32(ebp + 8);
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = eax & 2;
    goto loc_003C0669;

loc_003C0666: ;
    eax = 0; /* xor self */
    eax++;

loc_003C0669: ;
    PUSH32(esp, eax);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCCD(); /* call 0x003BBCCD */

loc_003C0671: ;
    PUSH32(esp, 0);
    ecx = ebx;
    goto loc_003C067E;

loc_003C0677: ;
    ecx = ebx;

loc_003C0679: ;
    PUSH32(esp, 0x80000400u);

loc_003C067E: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA873(); /* call 0x003BA873 */

loc_003C0683: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C068A
 * Original: 0x003C068A - 0x003C06A6 (28 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C068A(void)
{
    uint32_t ebp;

loc_003C068A: ;
    PUSH32(esp, ebp);
    ebp = esp;
    eax = MEM32(ebp + 8);
    eax = eax + 0xC;
    MEM32(ebp + 8) = eax;
    eax = 1;
    ecx = MEM32(ebp + 8);
    { uint32_t _xa_old = MEM32(ecx); uint32_t _xa_sum = _xa_old + eax;
    eax = _xa_old;
    MEM32(ecx) = _xa_sum; } /* xadd */
    eax++;
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C06A6
 * Original: 0x003C06A6 - 0x003C06F1 (75 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06A6(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C06A6: ;
    ecx = MEM32(esp + 4);
    /* test MEM8(ecx + 0xB), 0x10 - flags set for next jcc */
    eax = MEM32(esp + 8);
    if (TEST_Z(MEM8(ecx + 0xB), 0x10)) goto loc_003C06CF; /* je: equal / zero */

loc_003C06B4: ;
    MEM32(eax) = 9;
    ecx = MEM32(ecx + 0x18);
    ecx = (uint32_t)(int32_t)SMEM8(ecx + 0x14);
    ecx = ecx + ecx * 4;
    ecx = ecx << 1;
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    MEM32(eax + 8) = ecx;
    goto loc_003C06E8;

loc_003C06CF: ;
    MEM32(eax) = 5;
    ecx = MEM32(ecx + 0x18);
    ecx = (uint32_t)(int32_t)SMEM8(ecx + 0x14);
    ecx = ecx + ecx * 4;
    ecx = ecx << 1;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;
    MEM32(eax + 4) = ecx;

loc_003C06E8: ;
    MEM32(eax + 0xC) = MEM32(eax + 0xC) & 0;
    eax = 0; /* xor self */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C06F1
 * Original: 0x003C06F1 - 0x003C06F9 (8 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06F1(void)
{

loc_003C06F1: ;
    eax = 0x80004001u;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C06F9
 * Original: 0x003C06F9 - 0x003C06FE (5 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06F9(void)
{

loc_003C06F9: ;
    eax = 0; /* xor self */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C06FE
 * Original: 0x003C06FE - 0x003C0741 (67 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06FE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C06FE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0705: ;
    edx = MEM32(esp + 8);
    SET_LO8(ebx, MEM8(edx + 0xB));
    if (TEST_Z(LO8(ebx), 0x20)) goto loc_003C072C; /* je: equal / zero */

loc_003C0711: ;
    ecx = MEM32(edx + 0x18);
    if (CMP_EQ(MEM32(ecx + 0xC), 0)) goto loc_003C072C; /* je: equal / zero */

loc_003C071A: ;
    edx = MEM32(esp + 0xC);
    PUSH32(esp, 0);
    /* test LO8(ebx), 0x10 - flags set for next jcc */
    POP32(esp, ecx);
    SET_LO8(ecx, (TEST_NZ(LO8(ebx), 0x10)) ? 1 : 0); /* setne */
    ecx++;
    MEM32(edx) = ecx;
    goto loc_003C0733;

loc_003C072C: ;
    ecx = MEM32(esp + 0xC);
    MEM32(ecx) = MEM32(ecx) & 0;

loc_003C0733: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C073B: ;
    eax = 0; /* xor self */
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0741
 * Original: 0x003C0741 - 0x003C075A (25 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0741(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0741: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x30;
    PUSH32(esp, esi);
    esi = ecx;
    if (TEST_NZ(MEM8(esi + 0xB), 1)) { g_seh_ebp = ebp; sub_003C075A(); return; } /* jne: not equal / not zero */

loc_003C0750: ;
    eax = 0x8007048Fu;
    g_seh_ebp = ebp; sub_003C084B(); return; /* tail jmp 0x003C084B */

}

/**
 * sub_003C075A
 * Original: 0x003C075A - 0x003C084B (241 bytes, 74 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C075A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C075A: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    eax = ebp + -48;
    ebx = 0; /* xor self */
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x20;
    MEM8(ebp + -47) = 0x82;
    MEM32(ebp + -40) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C0775: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003C0828; /* jl: less (signed <) */

loc_003C077F: ;
    SET_LO8(ecx, MEM8(ebp + 0xC));
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 4;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C078C: ;
    SET_LO16(eax, ZX8(MEM8(ebp + 8)));
    ecx = MEM32(esi + 4);
    SET_LO16(eax, LO16(eax) | 0x100);
    MEM16(ebp + -6) = LO16(eax);
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x30;
    MEM8(ebp + -47) = 0x40;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    MEM32(ebp + -32) = ebx;
    MEM32(ebp + -24) = ebx;
    MEM32(ebp + -28) = ebx;
    MEM8(ebp + -20) = LO8(ebx);
    MEM8(ebp + -19) = LO8(ebx);
    MEM8(ebp + -18) = LO8(ebx);
    MEM8(ebp + -8) = 0x41;
    MEM8(ebp + -7) = 3;
    MEM16(ebp + -4) = LO16(ebx);
    MEM16(ebp + -2) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C07D5: ;
    ecx = MEM32(esi + 4);
    edi = eax;
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x1C;
    MEM8(ebp + -47) = 0xC3;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C07F1: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C07F7: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF9;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C0820; /* je: equal / zero */

loc_003C0801: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C080A: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C0812: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = ebx;
    eax = 0x8007048Fu;
    goto loc_003C0849;

loc_003C0820: ;
    if (CMP_NE(MEM8(ebp + 8), 2)) goto loc_003C0828; /* jne: not equal / not zero */

loc_003C0826: ;
    edi = 0; /* xor self */

loc_003C0828: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C082E: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C083A; /* jg: greater (signed >) */

loc_003C0833: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0838: ;
    goto loc_003C0849;

loc_003C083A: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C083F: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;

loc_003C0849: ;
    POP32(esp, edi);
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003C084B(); return; /* restored dropped fall-through to sub_003C084B */
}

/**
 * sub_003C084B
 * Original: 0x003C084B - 0x003C0850 (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C084B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C084B: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0850
 * Original: 0x003C0850 - 0x003C0869 (25 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0850(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0850: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x30;
    PUSH32(esp, esi);
    esi = ecx;
    if (TEST_NZ(MEM8(esi + 0xB), 1)) { g_seh_ebp = ebp; sub_003C0869(); return; } /* jne: not equal / not zero */

loc_003C085F: ;
    eax = 0x8007048Fu;
    g_seh_ebp = ebp; sub_003C0950(); return; /* tail jmp 0x003C0950 */

}

/**
 * sub_003C0869
 * Original: 0x003C0869 - 0x003C0950 (231 bytes, 70 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0869(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0869: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    eax = ebp + -48;
    ebx = 0; /* xor self */
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x20;
    MEM8(ebp + -47) = 0x82;
    MEM32(ebp + -40) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C0884: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003C092D; /* jl: less (signed <) */

loc_003C088E: ;
    SET_LO8(ecx, MEM8(ebp + 0xC));
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 4;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C089B: ;
    SET_LO16(eax, ZX8(MEM8(ebp + 8)));
    ecx = MEM32(esi + 4);
    MEM16(ebp + -6) = LO16(eax);
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x30;
    MEM8(ebp + -47) = 0x40;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    MEM32(ebp + -32) = ebx;
    MEM32(ebp + -24) = ebx;
    MEM32(ebp + -28) = ebx;
    MEM8(ebp + -20) = LO8(ebx);
    MEM8(ebp + -19) = LO8(ebx);
    MEM8(ebp + -18) = LO8(ebx);
    MEM8(ebp + -8) = 0x41;
    MEM8(ebp + -7) = 3;
    MEM16(ebp + -4) = 1;
    MEM16(ebp + -2) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C08E2: ;
    ecx = MEM32(esi + 4);
    edi = eax;
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x1C;
    MEM8(ebp + -47) = 0xC3;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C08FE: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0904: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF9;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C092D; /* je: equal / zero */

loc_003C090E: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C0917: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C091F: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = ebx;
    eax = 0x8007048Fu;
    goto loc_003C094E;

loc_003C092D: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0933: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C093F; /* jg: greater (signed >) */

loc_003C0938: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C093D: ;
    goto loc_003C094E;

loc_003C093F: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0944: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;

loc_003C094E: ;
    POP32(esp, edi);
    POP32(esp, ebx);

    g_seh_ebp = ebp; sub_003C0950(); return; /* restored dropped fall-through to sub_003C0950 */
}

/**
 * sub_003C0950
 * Original: 0x003C0950 - 0x003C0955 (5 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0950(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0950: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0955
 * Original: 0x003C0955 - 0x003C0969 (20 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0955(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0955: ;
    eax = MEM32(esp + 4);
    MEM32(eax + 0x18) = MEM32(eax + 0x18) & 0;
    edx = MEM32(ecx + 4);
    if (TEST_Z(edx, edx)) { g_seh_ebp = ebp; sub_003C0969(); return; } /* je: equal / zero */

loc_003C0964: ;
    MEM32(edx + 0x18) = eax;
    g_seh_ebp = ebp; sub_003C096B(); return; /* tail jmp 0x003C096B */

}

/**
 * sub_003C0969
 * Original: 0x003C0969 - 0x003C096B (2 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0969(void)
{

loc_003C0969: ;
    MEM32(ecx) = eax;

    sub_003C096B(); return; /* restored dropped fall-through to sub_003C096B */
}

/**
 * sub_003C096B
 * Original: 0x003C096B - 0x003C0971 (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C096B(void)
{

loc_003C096B: ;
    MEM32(ecx + 4) = eax;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C0971
 * Original: 0x003C0971 - 0x003C0987 (22 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0971(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C0971: ;
    eax = MEM32(ecx);
    if (TEST_Z(eax, eax)) goto loc_003C0984; /* je: equal / zero */

loc_003C0977: ;
    edx = MEM32(eax + 0x18);
    /* test edx, edx - flags set for next jcc */
    MEM32(ecx) = edx;
    if (TEST_NZ(edx, edx)) goto loc_003C0986; /* jne: not equal / not zero */

loc_003C0980: ;
    MEM32(ecx + 4) = MEM32(ecx + 4) & edx;
    esp += 4; return; /* ret */

loc_003C0984: ;
    eax = 0; /* xor self */

loc_003C0986: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C0987
 * Original: 0x003C0987 - 0x003C09B6 (47 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0987(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0987: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x3C;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    PUSH32(esp, 0x6B776168);
    PUSH32(esp, esi);
    ebx = ecx;
    { uint32_t _icall_t = MEM32(0x3C163C); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C09A3: ;
    edx = eax;
    /* test edx, edx - flags set for next jcc */
    MEM32(ebp + -4) = edx;
    if (TEST_NZ(edx, edx)) { g_seh_ebp = ebp; sub_003C09B6(); return; } /* jne: not equal / not zero */

loc_003C09AC: ;
    eax = 0x8007000Eu;
    g_seh_ebp = ebp; sub_003C0AD3(); return; /* tail jmp 0x003C0AD3 */

}

/**
 * sub_003C09B6
 * Original: 0x003C09B6 - 0x003C0AD3 (285 bytes, 91 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C09B6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C09B6: ;
    PUSH32(esp, edi);
    eax = 0; /* xor self */
    ecx = esi;
    ecx = ecx >> 2;
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = esi;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    esi = MEM32(0x3B8570);
    eax = MEM32(esi);
    MEM32(0x3B8570) = eax;
    eax = 0; /* xor self */
    ecx = 0xE0;
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebp + 8);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi) = edx;
    if (CMP_BE(eax & eax, 0)) goto loc_003C0A00; /* jbe: below or equal (unsigned <=) */

loc_003C09EA: ;
    ecx = esi + 0xC;
    edi = edx;
    MEM32(ebp + 8) = eax;

loc_003C09F2: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0955(); /* call 0x003C0955 */

loc_003C09F8: ;
    edi = edi + 0x1C;
    MEM32(ebp + 8) = MEM32(ebp + 8) - 1;
    if ((MEM32(ebp + 8) != 0)) { RECOMP_SLICE_POINT(); goto loc_003C09F2; } /* jne: not equal / not zero */

loc_003C0A00: ;
    eax = MEM32(ebp + 0xC);
    eax = eax << 2;
    SET_LO8(ecx, MEM8(eax + 0x3B8576));
    MEM8(esi + 0x14) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 0x3B8577));
    MEM8(esi + 0x15) = LO8(eax);
    MEM8(esi + 0x17) = 3;
    MEM32(esi + 0x2C) = ebx;
    MEM32(esi + 0x18) = ebx;
    MEM8(esi + 0x2A) = 1;
    MEM8(esi + 0x3E) = 2;
    SET_LO8(ecx, MEM8(ebx + 0xA));
    eax = 0; /* xor self */
    MEM8(ebp + -11) = LO8(ecx);
    SET_LO16(ecx, MEM16(ebx + 8));
    MEM32(ebp + -24) = eax;
    MEM32(ebp + -20) = eax;
    MEM16(ebp + -8) = LO16(eax);
    eax = ebp + -32;
    MEM16(ebp + -10) = LO16(ecx);
    ecx = MEM32(ebx + 4);
    PUSH32(esp, eax);
    MEM8(ebp + -32) = 0x1C;
    MEM8(ebp + -31) = 9;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C0A58: ;
    edi = eax;
    ecx = 0; /* xor self */
    if (CMP_GE(edi, ecx)) goto loc_003C0A99; /* jge: greater or equal (signed >=) */

loc_003C0A60: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -4));
    { uint32_t _icall_t = MEM32(0x3C1638); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0A69: ;
    eax = MEM32(0x3B8570);
    MEM32(esi) = eax;
    PUSH32(esp, edi);
    MEM32(0x3B8570) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0A7C: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C0A88; /* jg: greater (signed >) */

loc_003C0A81: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0A86: ;
    goto loc_003C0AD2;

loc_003C0A88: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCD7(); /* call 0x003BBCD7 */

loc_003C0A8D: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;
    goto loc_003C0AD2;

loc_003C0A99: ;
    edx = MEM32(ebp + -16);
    eax = esi + 0x37C;
    MEM32(eax) = edx;
    MEM32(ebp + -52) = ecx;
    MEM32(ebp + -48) = ecx;
    MEM8(ebp + -60) = 0x1C;
    MEM8(ebp + -59) = 0xC;
    eax = MEM32(eax);
    MEM32(ebp + -44) = eax;
    eax = ebp + -60;
    MEM32(ebp + -40) = ecx;
    ecx = MEM32(ebx + 4);
    PUSH32(esp, eax);
    MEM32(ebp + -36) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C0ACD: ;
    MEM32(ebx + 0x18) = esi;
    eax = 0; /* xor self */

loc_003C0AD2: ;
    POP32(esp, edi);

    g_seh_ebp = ebp; sub_003C0AD3(); return; /* restored dropped fall-through to sub_003C0AD3 */
}

/**
 * sub_003C0AD3
 * Original: 0x003C0AD3 - 0x003C0AD9 (6 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0AD3(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0AD3: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0AD9
 * Original: 0x003C0AD9 - 0x003C0B0A (49 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0AD9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0AD9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x48;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = ecx;
    MEM32(ebp + -12) = edi;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0AEC: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(eax + 0x17));
    ebx = 0; /* xor self */
    if (TEST_Z(LO8(eax), 1)) { g_seh_ebp = ebp; sub_003C0B0A(); return; } /* je: equal / zero */

loc_003C0AFB: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFE;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x18;
    g_seh_ebp = ebp; sub_003C0B1B(); return; /* tail jmp 0x003C0B1B */

}

/**
 * sub_003C0B0A
 * Original: 0x003C0B0A - 0x003C0B1B (17 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0B0A(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003C0B0A: ;
    if (TEST_Z(LO8(eax), 2)) { g_seh_ebp = ebp; sub_003C0B1B(); return; } /* je: equal / zero */

loc_003C0B0E: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFD;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x2C;

    g_seh_ebp = ebp; sub_003C0B1B(); return; /* restored dropped fall-through to sub_003C0B1B */
}

/**
 * sub_003C0B1B
 * Original: 0x003C0B1B - 0x003C0D0B (496 bytes, 167 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0B1B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0B1B: ;
    /* test ebx, ebx - flags set for next jcc */
    MEM32(ebp + -48) = 0x3C0D0B;
    if (TEST_Z(ebx, ebx)) goto loc_003C0CFE; /* je: equal / zero */

loc_003C0B2A: ;
    PUSH32(esp, esi);

loc_003C0B2B: ;
    eax = MEM32(edi + 0x18);
    eax = MEM32(eax + 4);
    if (TEST_Z(eax, eax)) goto loc_003C0CF4; /* je: equal / zero */

loc_003C0B39: ;
    MEM32(ebx + 4) = eax;
    ecx = MEM32(eax);
    MEM32(ebx + 0xC) = MEM32(ebx + 0xC) & 0;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    MEM32(ebx + 8) = ecx;
    ecx = MEM32(edi + 0x18);
    SET_LO8(ecx, MEM8(ecx + 0x16));
    MEM8(ebx + 0x11) = LO8(ecx);
    MEM8(ebx + 0x10) = 0;
    MEM8(ebx + 0x13) = 0;

loc_003C0B5A: ;
    ecx = MEM32(edi + 0x18);
    esi = MEM32(ebp + -8);
    SET_LO16(edx, (uint32_t)(int32_t)SMEM8(ecx + 0x14));
    esi = ebp + esi * 2 + -64;
    MEM16(esi) = LO16(edx);
    if (CMP_EQ(MEM8(ecx + 0x15), 0)) goto loc_003C0B88; /* je: equal / zero */

loc_003C0B72: ;
    MEM8(ecx + 0x16) = MEM8(ecx + 0x16) + 1;
    ecx = MEM32(edi + 0x18);
    SET_LO8(edx, MEM8(ecx + 0x16));
    if (CMP_NE(LO8(edx), MEM8(ecx + 0x15))) goto loc_003C0B88; /* jne: not equal / not zero */

loc_003C0B80: ;
    MEM16(esi) = MEM16(esi) + 2;
    MEM8(ecx + 0x16) = 0;

loc_003C0B88: ;
    ecx = ZX16(MEM16(esi));
    edx = MEM32(ebx + 0xC);
    ecx = ecx + edx;
    MEM32(ebx + 0xC) = ecx;
    edx = MEM32(eax + 4);
    if (CMP_BE(ecx, edx)) goto loc_003C0BCB; /* jbe: below or equal (unsigned <=) */

loc_003C0B9A: ;
    ecx = ecx - edx;
    edx = MEM32(edi + 0x18);
    MEM32(edx + 0x48) = ecx;
    ecx = MEM32(eax + 4);
    MEM32(ebx + 0xC) = ecx;
    MEM8(ebx + 0x10) = 1;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C0BCB; /* jne: not equal / not zero */

loc_003C0BB2: ;
    edi = MEM32(edi + 0x18);
    esi = MEM32(eax);
    edx = ecx;
    edi = edi + 0x4C;
    ecx = ecx >> 2;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = edx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    edi = MEM32(ebp + -12);

loc_003C0BCB: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(ebp + -8) = MEM32(ebp + -8) + 1;
    if (CMP_EQ(ecx, MEM32(eax + 4))) goto loc_003C0BE2; /* je: equal / zero */

loc_003C0BD6: ;
    if (CMP_L(MEM32(ebp + -8), 8)) { RECOMP_SLICE_POINT(); goto loc_003C0B5A; } /* jl: less (signed <) */

loc_003C0BE0: ;
    goto loc_003C0BE6;

loc_003C0BE2: ;
    MEM8(ebx + 0x13) = 1;

loc_003C0BE6: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) - ecx;
    ecx = MEM32(ebp + -8);
    MEM32(ebp + -44) = ebx;
    MEM32(ebp + -72) = ecx;
    ecx = MEM32(eax);
    MEM32(ebp + -68) = ecx;
    ecx = MEM32(ebx + 0xC);
    MEM32(eax) = MEM32(eax) + ecx;
    if (CMP_EQ(MEM8(ebx + 0x13), 0)) goto loc_003C0C10; /* je: equal / zero */

loc_003C0C05: ;
    ecx = MEM32(edi + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0971(); /* call 0x003C0971 */

loc_003C0C10: ;
    if (CMP_EQ(MEM8(ebx + 0x10), 0)) goto loc_003C0C8A; /* je: equal / zero */

loc_003C0C16: ;
    edx = MEM32(edi + 0x18);
    eax = edx + 0x4C;
    MEM32(ebp + -68) = eax;
    eax = MEM32(edx + 4);
    if (TEST_Z(eax, eax)) goto loc_003C0C5F; /* je: equal / zero */

loc_003C0C26: ;
    MEM32(edx + 0x40) = eax;
    esi = MEM32(eax);
    MEM32(edx + 0x44) = esi;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C0C4F; /* jne: not equal / not zero */

loc_003C0C34: ;
    ecx = MEM32(edx + 0x48);
    edi = MEM32(ebx + 0xC);
    ebx = ecx;
    ecx = ecx >> 2;
    edi = edi + edx + 0x4C;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = ebx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    edi = MEM32(ebp + -12);

loc_003C0C4F: ;
    ecx = MEM32(edx + 0x48);
    ecx = ecx + MEM32(edx + 0x44);
    MEM32(eax) = ecx;
    ecx = MEM32(edx + 0x48);
    MEM32(eax + 4) = MEM32(eax + 4) - ecx;
    goto loc_003C0C8A;

loc_003C0C5F: ;
    MEM32(edx + 0x40) = MEM32(edx + 0x40) & 0;
    MEM32(edx + 0x44) = MEM32(edx + 0x44) & 0;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C0C8A; /* jne: not equal / not zero */

loc_003C0C6D: ;
    esi = MEM32(ebx + 0xC);
    ecx = MEM32(edx + 0x48);
    edi = esi + edx + 0x4C;
    edx = ecx;
    ecx = ecx >> 2;
    eax = 0; /* xor self */
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = edx;
    ecx = ecx & 3;
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    edi = MEM32(ebp + -12);

loc_003C0C8A: ;
    eax = MEM32(edi + 0x18);
    MEM32(ebp + -32) = MEM32(ebp + -32) & 0;
    MEM32(ebp + -28) = MEM32(ebp + -28) & 0;
    ecx = MEM32(edi + 4);
    MEM8(ebp + -40) = 0x1C;
    MEM8(ebp + -39) = 0xB;
    eax = MEM32(eax + 0x37C);
    MEM32(ebp + -24) = eax;
    eax = ebp + -72;
    MEM32(ebp + -16) = eax;
    eax = ebp + -40;
    PUSH32(esp, eax);
    MEM8(ebp + -20) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C0CBC: ;
    eax = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(eax + 0x17));
    if (TEST_Z(LO8(eax), 1)) goto loc_003C0CD5; /* je: equal / zero */

loc_003C0CC6: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFE;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x18;
    goto loc_003C0CEA;

loc_003C0CD5: ;
    if (TEST_Z(LO8(eax), 2)) goto loc_003C0CE8; /* je: equal / zero */

loc_003C0CD9: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFD;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x2C;
    goto loc_003C0CEA;

loc_003C0CE8: ;
    ebx = 0; /* xor self */

loc_003C0CEA: ;
    if (TEST_NZ(ebx, ebx)) { RECOMP_SLICE_POINT(); goto loc_003C0B2B; } /* jne: not equal / not zero */

loc_003C0CF2: ;
    goto loc_003C0CFD;

loc_003C0CF4: ;
    edi = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(ebx + 0x12));
    MEM8(edi + 0x17) = MEM8(edi + 0x17) | LO8(eax);

loc_003C0CFD: ;
    POP32(esp, esi);

loc_003C0CFE: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0D07: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0D0B
 * Original: 0x003C0D0B - 0x003C0EF1 (486 bytes, 177 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0D0B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003C0D0B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x30;
    eax = MEM32(ebp + 0xC);
    ecx = MEM32(eax + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(eax);
    edx = MEM32(esi + 0x18);
    MEM32(ebp + -20) = ecx;
    SET_LO8(ecx, MEM8(edx + 0x15));
    /* test LO8(ecx), LO8(ecx) - flags set for next jcc */
    PUSH32(esp, edi);
    MEM32(ebp + -24) = esi;
    MEM8(ebp + -1) = LO8(ecx);
    if (TEST_Z(LO8(ecx), LO8(ecx))) goto loc_003C0D32; /* je: equal / zero */

loc_003C0D2F: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) - 1;

loc_003C0D32: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C0E71; /* je: equal / zero */

loc_003C0D3C: ;
    /* cmp MEM8(eax + 0x10), 0 - flags set for next jcc */
    esi = edx + 0x4C;
    if (CMP_NE(MEM8(eax + 0x10), 0)) goto loc_003C0D48; /* jne: not equal / not zero */

loc_003C0D45: ;
    esi = MEM32(eax + 8);

loc_003C0D48: ;
    ecx = MEM32(ebp + 8);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    if (CMP_BE(MEM32(ecx + 4), 0)) goto loc_003C0E33; /* jbe: below or equal (unsigned <=) */

loc_003C0D59: ;
    ecx = ecx + 8;
    MEM32(ebp + -8) = ecx;

loc_003C0D5F: ;
    /* cmp MEM8(ebp + -1), 0 - flags set for next jcc */
    ecx = (uint32_t)(int32_t)SMEM8(edx + 0x14);
    MEM32(ebp + -16) = ecx;
    if (CMP_EQ(MEM8(ebp + -1), 0)) goto loc_003C0D80; /* je: equal / zero */

loc_003C0D6C: ;
    edi = (uint32_t)(int32_t)SMEM8(eax + 0x11);
    ebx = (uint32_t)(int32_t)SMEM8(ebp + -1);
    edi = edi + MEM32(ebp + -12);
    if (CMP_NE(edi, ebx)) goto loc_003C0D80; /* jne: not equal / not zero */

loc_003C0D7B: ;
    ecx++;
    ecx++;
    MEM32(ebp + -16) = ecx;

loc_003C0D80: ;
    edi = MEM32(ebp + -8);
    edi = ZX16(MEM16(edi));
    ebx = edi;
    SET_LO16(ebx, LO16(ebx) & 0xF000);
    if (CMP_NE(LO16(ebx), 0x9000)) goto loc_003C0DF7; /* jne: not equal / not zero */

loc_003C0D94: ;
    if (TEST_Z(LO16(edi), 0xFFF)) goto loc_003C0DE0; /* je: equal / zero */

loc_003C0D9B: ;
    edi = MEM32(ebp + -8);
    edi = ZX16(MEM16(edi));
    edi = edi & 0xFFF;
    ecx = ecx - edi;
    esi = esi + edi + -2;
    edi = 0; /* xor self */
    SET_LO16(edi, MEM16(esi));
    ecx = ecx >> 1;
    esi++;
    esi++;
    /* test ecx, ecx - flags set for next jcc */
    MEM32(ebp + -16) = ecx;
    if (TEST_Z(ecx, ecx)) goto loc_003C0DF9; /* je: equal / zero */

loc_003C0DBD: ;
    eax = edi;
    SET_LO16(ebx, LO16(eax));
    edi = esi;
    ebx = ebx << 0x10;
    SET_LO16(ebx, LO16(eax));
    ecx = ecx >> 1;
    eax = ebx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = ecx + ecx + _cf; /* adc */
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM16(edi + _i*2) = LO16(eax); }
    edi += ecx * 2; ecx = 0; /* rep stosw */
    eax = MEM32(ebp + -16);
    esi = esi + eax * 2;

loc_003C0DDB: ;
    eax = MEM32(ebp + 0xC);
    goto loc_003C0DF9;

loc_003C0DE0: ;
    ebx = ecx;
    ecx = ecx >> 2;
    eax = 0; /* xor self */
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    ecx = ebx;
    ecx = ecx & 3;
    esi = esi + MEM32(ebp + -16);
    memset((void*)XBOX_PTR(edi), (uint8_t)eax, ecx);
    edi += ecx; ecx = 0; /* rep stosb */
    { RECOMP_SLICE_POINT(); goto loc_003C0DDB; }

loc_003C0DF7: ;
    esi = esi + ecx;

loc_003C0DF9: ;
    if (CMP_EQ(MEM8(ebp + -1), 0)) goto loc_003C0E1D; /* je: equal / zero */

loc_003C0DFF: ;
    ecx = MEM32(ebp + -8);
    SET_LO16(ecx, MEM16(ecx));
    SET_LO16(ecx, LO16(ecx) & 0xF000);
    if (CMP_NE(LO16(ecx), 0x8000)) goto loc_003C0E1D; /* jne: not equal / not zero */

loc_003C0E11: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    SET_LO8(ecx, LO8(ecx) - MEM8(eax + 0x11));
    SET_LO8(ecx, LO8(ecx) - MEM8(ebp + -12));
    MEM8(edx + 0x16) = MEM8(edx + 0x16) + LO8(ecx);

loc_003C0E1D: ;
    MEM32(ebp + -12) = MEM32(ebp + -12) + 1;
    ecx = MEM32(ebp + 8);
    edi = MEM32(ebp + -12);
    MEM32(ebp + -8) = MEM32(ebp + -8) + 2;
    if (CMP_B(edi, MEM32(ecx + 4))) { RECOMP_SLICE_POINT(); goto loc_003C0D5F; } /* jb: below (unsigned <) */

loc_003C0E33: ;
    if (CMP_EQ(MEM8(eax + 0x10), 0)) goto loc_003C0E71; /* je: equal / zero */

loc_003C0E39: ;
    ecx = MEM32(eax + 0xC);
    edi = MEM32(eax + 8);
    ebx = ecx;
    ecx = ecx >> 2;
    esi = edx + 0x4C;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = ebx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */
    if (CMP_EQ(MEM32(edx + 0x40), 0)) goto loc_003C0E71; /* je: equal / zero */

loc_003C0E56: ;
    ecx = MEM32(edx + 0x48);
    esi = MEM32(eax + 0xC);
    edi = MEM32(edx + 0x44);
    ebx = ecx;
    ecx = ecx >> 2;
    esi = edx + esi + 0x4C;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = ebx;
    ecx = ecx & 3;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx);
    esi += ecx; edi += ecx; ecx = 0; /* rep movsb */

loc_003C0E71: ;
    esi = MEM32(ebp + -20);
    ebx = 0; /* xor self */
    if (CMP_EQ(MEM32(esi + 8), ebx)) goto loc_003C0E83; /* je: equal / zero */

loc_003C0E7B: ;
    ecx = MEM32(esi + 8);
    edi = MEM32(eax + 0xC);
    MEM32(ecx) = MEM32(ecx) + edi;

loc_003C0E83: ;
    if (CMP_EQ(MEM8(eax + 0x10), 0)) goto loc_003C0E9D; /* je: equal / zero */

loc_003C0E89: ;
    ecx = MEM32(edx + 0x40);
    if (CMP_EQ(ecx, ebx)) goto loc_003C0E9D; /* je: equal / zero */

loc_003C0E90: ;
    if (CMP_EQ(MEM32(ecx + 8), ebx)) goto loc_003C0E9D; /* je: equal / zero */

loc_003C0E95: ;
    ecx = MEM32(ecx + 8);
    edi = MEM32(edx + 0x48);
    MEM32(ecx) = MEM32(ecx) + edi;

loc_003C0E9D: ;
    ecx = ZX8(MEM8(eax + 0x13));
    SET_LO8(eax, MEM8(eax + 0x12));
    MEM8(edx + 0x17) = MEM8(edx + 0x17) | LO8(eax);
    if (CMP_EQ(ecx, ebx)) goto loc_003C0EDC; /* je: equal / zero */

loc_003C0EAB: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    edi = ebp + -48;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    eax = MEM32(ebp + -40);
    if (TEST_Z(eax, eax)) goto loc_003C0EBC; /* je: equal / zero */

loc_003C0EBA: ;
    ebx = MEM32(eax);

loc_003C0EBC: ;
    PUSH32(esp, MEM32(ebp + -20));
    ecx = edx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0955(); /* call 0x003C0955 */

loc_003C0EC7: ;
    eax = MEM32(ebp + -24);
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(eax + 0x14));
    PUSH32(esp, MEM32(eax + 0x10));
    eax = ebp + -48;
    PUSH32(esp, ebx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00367D60(); /* call 0x00367D60 */

loc_003C0EDC: ;
    ecx = MEM32(ebp + -24);
    /* test MEM8(ecx + 0xB), 0x20 - flags set for next jcc */
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    if (TEST_Z(MEM8(ecx + 0xB), 0x20)) goto loc_003C0EED; /* je: equal / zero */

loc_003C0EE8: ;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0AD9(); /* call 0x003C0AD9 */

loc_003C0EED: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0EF1
 * Original: 0x003C0EF1 - 0x003C0F72 (129 bytes, 53 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0EF1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0EF1: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, ebx);
    ebx = ecx;
    ecx = MEM32(ebx + 0x18);
    SET_LO8(edx, MEM8(ecx + 0x17));
    if (TEST_NZ(LO8(edx), 1)) goto loc_003C0F12; /* jne: not equal / not zero */

loc_003C0F05: ;
    if (CMP_EQ(MEM8(ecx + 0x2B), 0)) goto loc_003C0F12; /* je: equal / zero */

loc_003C0F0B: ;
    eax = MEM32(ecx + 0x1C);
    if (TEST_NZ(eax, eax)) goto loc_003C0F30; /* jne: not equal / not zero */

loc_003C0F12: ;
    if (TEST_NZ(LO8(edx), 2)) goto loc_003C0F24; /* jne: not equal / not zero */

loc_003C0F17: ;
    if (CMP_EQ(MEM8(ecx + 0x3F), 0)) goto loc_003C0F24; /* je: equal / zero */

loc_003C0F1D: ;
    eax = MEM32(ecx + 0x30);
    if (TEST_NZ(eax, eax)) goto loc_003C0F30; /* jne: not equal / not zero */

loc_003C0F24: ;
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0971(); /* call 0x003C0971 */

loc_003C0F2C: ;
    if (TEST_Z(eax, eax)) goto loc_003C0F6F; /* je: equal / zero */

loc_003C0F30: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003C0F32: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    esi = eax;
    edi = ebp + -24;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebx + 0x18);
    PUSH32(esp, eax);
    ecx = ecx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0955(); /* call 0x003C0955 */

loc_003C0F48: ;
    PUSH32(esp, 0x80004004u);
    PUSH32(esp, MEM32(ebx + 0x14));
    eax = ebp + -24;
    PUSH32(esp, MEM32(ebx + 0x10));
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00367D60(); /* call 0x00367D60 */

loc_003C0F5E: ;
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0971(); /* call 0x003C0971 */

loc_003C0F69: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C0F32; } /* jne: not equal / not zero */

loc_003C0F6D: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003C0F6F: ;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0F72
 * Original: 0x003C0F72 - 0x003C0FDA (104 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0F72(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0F72: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    /* test MEM8(ebx + 0xB), 0x10 - flags set for next jcc */
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x10);
    PUSH32(esp, edi);
    if (TEST_NZ(MEM8(ebx + 0xB), 0x10)) goto loc_003C0F8C; /* jne: not equal / not zero */

loc_003C0F89: ;
    esi = MEM32(ebp + 0xC);

loc_003C0F8C: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0F92: ;
    /* test MEM8(ebx + 0xB), 0x20 - flags set for next jcc */
    MEM8(ebp + 0xB) = LO8(eax);
    if (TEST_Z(MEM8(ebx + 0xB), 0x20)) { g_seh_ebp = ebp; sub_003C0FDA(); return; } /* je: equal / zero */

loc_003C0F9B: ;
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0971(); /* call 0x003C0971 */

loc_003C0FA6: ;
    edi = eax;
    /* test edi, edi - flags set for next jcc */
    MEM32(ebp + 0x10) = edi;
    if (TEST_Z(edi, edi)) goto loc_003C0FD1; /* je: equal / zero */

loc_003C0FAF: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00367D42(); /* call 0x00367D42 */

loc_003C0FB5: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    PUSH32(esp, MEM32(ebp + 0x10));
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0955(); /* call 0x003C0955 */

loc_003C0FC8: ;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0AD9(); /* call 0x003C0AD9 */

loc_003C0FCF: ;
    g_seh_ebp = ebp; sub_003C0FF4(); return; /* tail jmp 0x003C0FF4 */

loc_003C0FD1: ;
    MEM32(ebp + -4) = 0x800700AAu;
    g_seh_ebp = ebp; sub_003C0FE1(); return; /* tail jmp 0x003C0FE1 */

}

/**
 * sub_003C0FDA
 * Original: 0x003C0FDA - 0x003C0FE1 (7 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0FDA(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0FDA: ;
    MEM32(ebp + -4) = 0x8007048Fu;

    g_seh_ebp = ebp; sub_003C0FE1(); return; /* restored dropped fall-through to sub_003C0FE1 */
}

/**
 * sub_003C0FE1
 * Original: 0x003C0FE1 - 0x003C0FF4 (19 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0FE1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0FE1: ;
    PUSH32(esp, 0x80004005u);
    PUSH32(esp, MEM32(ebx + 0x14));
    PUSH32(esp, MEM32(ebx + 0x10));
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_00367D60(); /* call 0x00367D60 */

    g_seh_ebp = ebp; sub_003C0FF4(); return; /* restored dropped fall-through to sub_003C0FF4 */
}

/**
 * sub_003C0FF4
 * Original: 0x003C0FF4 - 0x003C1007 (19 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0FF4(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0FF4: ;
    SET_LO8(ecx, MEM8(ebp + 0xB));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0FFD: ;
    eax = MEM32(ebp + -4);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003C1007
 * Original: 0x003C1007 - 0x003C10DC (213 bytes, 71 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1007(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C1007: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = 0; /* xor self */
    MEM8(ebp + -4) = 2;
    SET_LO8(ebx, 0x1F);
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C101D: ;
    ecx = MEM32(ebp + 8);
    /* cmp ecx, 0x3B8594 - flags set for next jcc */
    edi = MEM32(ebp + 0xC);
    MEM8(ebp + -8) = LO8(eax);
    eax = 0x3B85AC;
    if (CMP_EQ(ecx, 0x3B8594)) goto loc_003C1055; /* je: equal / zero */

loc_003C1033: ;
    if (CMP_EQ(ecx, eax)) goto loc_003C1055; /* je: equal / zero */

loc_003C1037: ;
    if (CMP_NE(ecx, 0x3B85A0)) goto loc_003C1092; /* jne: not equal / not zero */

loc_003C103F: ;
    if (CMP_EQ(MEM16(0x3B8568), LO16(esi))) goto loc_003C105F; /* je: equal / zero */

loc_003C1048: ;
    esi = edi;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF2A6E0;
    goto loc_003C1092;

loc_003C1055: ;
    if (CMP_NE(MEM16(0x3B856C), 0)) goto loc_003C1069; /* jne: not equal / not zero */

loc_003C105F: ;
    esi = 0x8007000Eu;
    g_seh_ebp = ebp; sub_003C1119(); return; /* tail jmp 0x003C1119 */

loc_003C1069: ;
    esi = edi;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF2A670;
    if (CMP_NE(ecx, eax)) goto loc_003C108C; /* jne: not equal / not zero */

loc_003C1078: ;
    if (TEST_NZ(MEM8(esi + 0xB), 0x80)) goto loc_003C1088; /* jne: not equal / not zero */

loc_003C107E: ;
    esi = 0x8007048Fu;
    g_seh_ebp = ebp; sub_003C1119(); return; /* tail jmp 0x003C1119 */

loc_003C1088: ;
    SET_LO8(ebx, 0xB5);
    goto loc_003C1092;

loc_003C108C: ;
    if (TEST_NZ(MEM8(esi + 0xB), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003C107E; } /* jne: not equal / not zero */

loc_003C1092: ;
    eax = MEM32(ebp + 0x14);
    if (TEST_Z(eax, eax)) goto loc_003C10C9; /* je: equal / zero */

loc_003C1099: ;
    eax = MEM32(eax + 4);
    SET_LO8(ecx, 0); /* xor self */
    MEM8(ebp + -4) = LO8(ecx);

loc_003C10A1: ;
    edx = ZX8(LO8(ecx));
    edx = ZX16(MEM16(edx * 4 + 0x3B8574));
    if (CMP_EQ(eax, edx)) goto loc_003C10BC; /* je: equal / zero */

loc_003C10B0: ;
    SET_LO8(ecx, LO8(ecx) + 1);
    /* cmp LO8(ecx), 8 - flags set for next jcc */
    MEM8(ebp + -4) = LO8(ecx);
    if (CMP_B(LO8(ecx), 8)) { RECOMP_SLICE_POINT(); goto loc_003C10A1; } /* jb: below (unsigned <) */

loc_003C10BA: ;
    goto loc_003C10C9;

loc_003C10BC: ;
    eax = 0; /* xor self */
    eax++;
    eax = eax << LO8(ecx);
    if (TEST_NZ(LO8(ebx), LO8(eax))) goto loc_003C10C9; /* jne: not equal / not zero */

loc_003C10C5: ;
    MEM8(ebp + -4) = 8;

loc_003C10C9: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 2)) { g_seh_ebp = ebp; sub_003C10DC(); return; } /* je: equal / zero */

loc_003C10D0: ;
    esi = 0; /* xor self */
    ebx = 0x80070020u;
    g_seh_ebp = ebp; sub_003C11AB(); return; /* tail jmp 0x003C11AB */

}

/**
 * sub_003C10DC
 * Original: 0x003C10DC - 0x003C1119 (61 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C10DC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C10DC: ;
    if (TEST_Z(LO8(eax), 1)) { g_seh_ebp = ebp; sub_003C118A(); return; } /* je: equal / zero */

loc_003C10E4: ;
    if (((int8_t)(LO8(eax) & LO8(eax)) >= 0)) goto loc_003C10F7; /* jns: not sign (positive) */

loc_003C10E8: ;
    PUSH32(esp, MEM32(ebp + -8));
    ecx = esi;
    PUSH32(esp, MEM32(ebp + -4));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0741(); /* call 0x003C0741 */

loc_003C10F5: ;
    g_seh_ebp = ebp; sub_003C1158(); return; /* tail jmp 0x003C1158 */

loc_003C10F7: ;
    SET_LO8(eax, MEM8(edi + 0xF2A66C));
    if (TEST_Z(LO8(eax), LO8(eax))) { g_seh_ebp = ebp; sub_003C1129(); return; } /* je: equal / zero */

loc_003C1101: ;
    SET_LO8(eax, LO8(eax) + 1);
    MEM8(edi + 0xF2A66C) = LO8(eax);
    SET_LO8(eax, MEM8(edi + 0xF2A668));
    if (CMP_EQ(LO8(eax), MEM8(ebp + -4))) { g_seh_ebp = ebp; sub_003C115E(); return; } /* je: equal / zero */

loc_003C1114: ;
    esi = 0x80070057u;

    g_seh_ebp = ebp; sub_003C1119(); return; /* restored dropped fall-through to sub_003C1119 */
}

/**
 * sub_003C1119
 * Original: 0x003C1119 - 0x003C11AB (146 bytes, 44 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1119(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1119: ;
    SET_LO8(ecx, MEM8(ebp + -8));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1122: ;
    eax = esi;
    g_seh_ebp = ebp; sub_003C11BB(); return; /* tail jmp 0x003C11BB */

    PUSH32(esp, MEM32(ebp + -8));
    SET_LO8(eax, MEM8(ebp + -4));
    PUSH32(esp, MEM32(ebp + -4));
    ecx = esi;
    MEM8(edi + 0xF2A66C) = 1;
    MEM8(edi + 0xF2A668) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0741(); /* call 0x003C0741 */

loc_003C1146: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C1180; /* jl: less (signed <) */

loc_003C114C: ;
    PUSH32(esp, MEM32(ebp + -8));
    ecx = esi;
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0850(); /* call 0x003C0850 */

loc_003C1158: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C1180; /* jl: less (signed <) */

loc_003C115E: ;
    eax = ZX8(MEM8(ebp + -4));
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0x10));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0987(); /* call 0x003C0987 */

loc_003C116D: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C1180; /* jl: less (signed <) */

loc_003C1173: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 0x22;
    MEM32(esi + 0xC) = 1;
    goto loc_003C1191;

loc_003C1180: ;
    esi = 0; /* xor self */
    MEM8(edi + 0xF2A66C) = MEM8(edi + 0xF2A66C) - 1;
    goto loc_003C1191;

    esi = 0; /* xor self */
    ebx = 0x8007048Fu;

loc_003C1191: ;
    if (TEST_Z(esi, esi)) { g_seh_ebp = ebp; sub_003C11AB(); return; } /* je: equal / zero */

loc_003C1195: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C11A4; /* je: equal / zero */

loc_003C119B: ;
    MEM16(0x3B856C) = MEM16(0x3B856C) - 1;
    g_seh_ebp = ebp; sub_003C11AB(); return; /* tail jmp 0x003C11AB */

loc_003C11A4: ;
    MEM16(0x3B8568) = MEM16(0x3B8568) - 1;

    g_seh_ebp = ebp; sub_003C11AB(); return; /* restored dropped fall-through to sub_003C11AB */
}

/**
 * sub_003C1129
 * Original: 0x003C1129 - 0x003C1158 (47 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1129(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1129: ;
    PUSH32(esp, MEM32(ebp + -8));
    SET_LO8(eax, MEM8(ebp + -4));
    PUSH32(esp, MEM32(ebp + -4));
    ecx = esi;
    MEM8(edi + 0xF2A66C) = 1;
    MEM8(edi + 0xF2A668) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0741(); /* call 0x003C0741 */

loc_003C1146: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) { g_seh_ebp = ebp; sub_003C1180(); return; } /* jl: less (signed <) */

loc_003C114C: ;
    PUSH32(esp, MEM32(ebp + -8));
    ecx = esi;
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0850(); /* call 0x003C0850 */

    g_seh_ebp = ebp; sub_003C1158(); return; /* restored dropped fall-through to sub_003C1158 */
}

/**
 * sub_003C1158
 * Original: 0x003C1158 - 0x003C115E (6 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1158(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */
    int _flags = 0; /* fallback flag var */

loc_003C1158: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) { g_seh_ebp = ebp; sub_003C1180(); return; } /* jl: less (signed <) */

    g_seh_ebp = ebp; sub_003C115E(); return; /* restored dropped fall-through to sub_003C115E */
}

/**
 * sub_003C115E
 * Original: 0x003C115E - 0x003C118A (44 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C115E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C115E: ;
    eax = ZX8(MEM8(ebp + -4));
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0x10));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0987(); /* call 0x003C0987 */

loc_003C116D: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C1180; /* jl: less (signed <) */

loc_003C1173: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 0x22;
    MEM32(esi + 0xC) = 1;
    g_seh_ebp = ebp; sub_003C1191(); return; /* tail jmp 0x003C1191 */

loc_003C1180: ;
    esi = 0; /* xor self */
    MEM8(edi + 0xF2A66C) = MEM8(edi + 0xF2A66C) - 1;
    g_seh_ebp = ebp; sub_003C1191(); return; /* tail jmp 0x003C1191 */

}

/**
 * sub_003C1180
 * Original: 0x003C1180 - 0x003C118A (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1180(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1180: ;
    esi = 0; /* xor self */
    MEM8(edi + 0xF2A66C) = MEM8(edi + 0xF2A66C) - 1;
    g_seh_ebp = ebp; sub_003C1191(); return; /* tail jmp 0x003C1191 */

}

/**
 * sub_003C118A
 * Original: 0x003C118A - 0x003C11AB (33 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C118A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C118A: ;
    esi = 0; /* xor self */
    ebx = 0x8007048Fu;
    if (TEST_Z(esi, esi)) { g_seh_ebp = ebp; sub_003C11AB(); return; } /* je: equal / zero */

loc_003C1195: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C11A4; /* je: equal / zero */

loc_003C119B: ;
    MEM16(0x3B856C) = MEM16(0x3B856C) - 1;
    g_seh_ebp = ebp; sub_003C11AB(); return; /* tail jmp 0x003C11AB */

loc_003C11A4: ;
    MEM16(0x3B8568) = MEM16(0x3B8568) - 1;

    g_seh_ebp = ebp; sub_003C11AB(); return; /* restored dropped fall-through to sub_003C11AB */
}

/**
 * sub_003C1191
 * Original: 0x003C1191 - 0x003C11AB (26 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1191(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1191: ;
    if (TEST_Z(esi, esi)) { g_seh_ebp = ebp; sub_003C11AB(); return; } /* je: equal / zero */

loc_003C1195: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C11A4; /* je: equal / zero */

loc_003C119B: ;
    MEM16(0x3B856C) = MEM16(0x3B856C) - 1;
    g_seh_ebp = ebp; sub_003C11AB(); return; /* tail jmp 0x003C11AB */

loc_003C11A4: ;
    MEM16(0x3B8568) = MEM16(0x3B8568) - 1;

    g_seh_ebp = ebp; sub_003C11AB(); return; /* restored dropped fall-through to sub_003C11AB */
}

/**
 * sub_003C11AB
 * Original: 0x003C11AB - 0x003C123E (147 bytes, 53 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C11AB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C11AB: ;
    SET_LO8(ecx, MEM8(ebp + -8));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C11B4: ;
    eax = MEM32(ebp + 0x18);
    MEM32(eax) = esi;
    eax = ebx;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

    eax = eax - 0xF2A670;
    goto loc_003C11EA;

loc_003C11E5: ;
    eax = eax - 0xF2A6E0;

loc_003C11EA: ;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    ecx = esi;
    MEM8(eax + 0xF2A66C) = MEM8(eax + 0xF2A66C) - 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0EF1(); /* call 0x003C0EF1 */

loc_003C11FA: ;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C1218; /* je: equal / zero */

loc_003C1200: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C1209: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C1211: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = edi;

loc_003C1218: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 4)) goto loc_003C1235; /* je: equal / zero */

loc_003C121F: ;
    SET_LO8(eax, LO8(eax) & 0xF9);
    MEM8(esi + 0xB) = LO8(eax);
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1235: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xBF;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C11BB
 * Original: 0x003C11BB - 0x003C123E (131 bytes, 48 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C11BB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C11BB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

    eax = eax - 0xF2A670;
    goto loc_003C11EA;

loc_003C11E5: ;
    eax = eax - 0xF2A6E0;

loc_003C11EA: ;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    ecx = esi;
    MEM8(eax + 0xF2A66C) = MEM8(eax + 0xF2A66C) - 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0EF1(); /* call 0x003C0EF1 */

loc_003C11FA: ;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C1218; /* je: equal / zero */

loc_003C1200: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C1209: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C1211: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = edi;

loc_003C1218: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 4)) goto loc_003C1235; /* je: equal / zero */

loc_003C121F: ;
    SET_LO8(eax, LO8(eax) & 0xF9);
    MEM8(esi + 0xB) = LO8(eax);
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1235: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xBF;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C11C2
 * Original: 0x003C11C2 - 0x003C123E (124 bytes, 43 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C11C2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C11C2: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0x18);
    PUSH32(esp, edi);
    edi = 0; /* xor self */
    MEM32(eax + 0x37C) = edi;
    /* test MEM8(esi + 0xB), 0x10 - flags set for next jcc */
    PUSH32(esp, 0x1C);
    eax = esi;
    POP32(esp, ecx);
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C11E5; /* je: equal / zero */

loc_003C11DE: ;
    eax = eax - 0xF2A670;
    goto loc_003C11EA;

loc_003C11E5: ;
    eax = eax - 0xF2A6E0;

loc_003C11EA: ;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    ecx = esi;
    MEM8(eax + 0xF2A66C) = MEM8(eax + 0xF2A66C) - 1;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C0EF1(); /* call 0x003C0EF1 */

loc_003C11FA: ;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C1218; /* je: equal / zero */

loc_003C1200: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C1209: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C1211: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = edi;

loc_003C1218: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 4)) goto loc_003C1235; /* je: equal / zero */

loc_003C121F: ;
    SET_LO8(eax, LO8(eax) & 0xF9);
    MEM8(esi + 0xB) = LO8(eax);
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F0); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1235: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xBF;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C123E
 * Original: 0x003C123E - 0x003C126E (48 bytes, 20 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C123E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C123E: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x20);
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + 0x14));
    PUSH32(esp, MEM32(ebp + 0x10));
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C1007(); /* call 0x003C1007 */

loc_003C1257: ;
    if (TEST_S(eax, eax)) goto loc_003C1269; /* jl: less (signed <) */

loc_003C125B: ;
    ecx = MEM32(esi);
    edx = MEM32(ebp + 0x1C);
    MEM32(ecx + 0x14) = edx;
    edx = MEM32(ebp + 0x18);
    MEM32(ecx + 0x10) = edx;

loc_003C1269: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 32; return; /* ret 28 */

}

/**
 * sub_003C126E
 * Original: 0x003C126E - 0x003C12C9 (91 bytes, 23 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C126E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C126E: ;
    MEM8(ecx + 0xB) = MEM8(ecx + 0xB) & 0xDF;
    SET_LO8(eax, MEM8(ecx + 0xB));
    if (TEST_NZ(LO8(eax), 0x40)) goto loc_003C12C8; /* jne: not equal / not zero */

loc_003C1279: ;
    SET_LO8(eax, LO8(eax) | 0x40);
    MEM8(ecx + 0xB) = LO8(eax);
    eax = MEM32(ecx + 0x18);
    MEM8(eax + 0x360) = 0x1C;
    eax = MEM32(ecx + 0x18);
    MEM8(eax + 0x361) = 0x4A;
    eax = MEM32(ecx + 0x18);
    MEM32(eax + 0x368) = 0x3C11C2;
    eax = MEM32(ecx + 0x18);
    MEM32(eax + 0x36C) = ecx;
    eax = MEM32(ecx + 0x18);
    edx = MEM32(eax + 0x37C);
    MEM32(eax + 0x370) = edx;
    eax = MEM32(ecx + 0x18);
    ecx = MEM32(ecx + 4);
    eax = eax + 0x360;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BC06D(); /* call 0x003BC06D */

loc_003C12C8: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C12C9
 * Original: 0x003C12C9 - 0x003C1349 (128 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C12C9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C12C9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C15E8); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C12D4: ;
    SET_LO8(ebx, LO8(eax));
    eax = MEM32(esi + 0x18);
    edi = 0; /* xor self */
    if (CMP_EQ(MEM32(eax + 0x37C), edi)) { g_seh_ebp = ebp; sub_003C1349(); return; } /* je: equal / zero */

loc_003C12E3: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 4;
    MEM8(eax + 0x350) = 1;
    eax = MEM32(esi + 0x18);
    MEM8(eax + 0x352) = 4;
    eax = MEM32(esi + 0x18);
    MEM32(eax + 0x354) = edi;
    eax = MEM32(esi + 0x18);
    ecx = eax + 0x358;
    MEM32(eax + 0x35C) = ecx;
    eax = MEM32(esi + 0x18);
    ecx = MEM32(eax + 0x35C);
    MEM32(eax + 0x358) = ecx;
    if (TEST_NZ(MEM8(esi + 0xB), 8)) goto loc_003C132C; /* jne: not equal / not zero */

loc_003C1325: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C126E(); /* call 0x003C126E */

loc_003C132C: ;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1334: ;
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C15F4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1347: ;
    g_seh_ebp = ebp; sub_003C1355(); return; /* tail jmp 0x003C1355 */

}

/**
 * sub_003C1349
 * Original: 0x003C1349 - 0x003C1355 (12 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1349(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1349: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xFD;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C15E4); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

    g_seh_ebp = ebp; sub_003C1355(); return; /* restored dropped fall-through to sub_003C1355 */
}

/**
 * sub_003C1355
 * Original: 0x003C1355 - 0x003C13D7 (130 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1355(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1355: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C1364; /* je: equal / zero */

loc_003C135B: ;
    MEM16(0x3B856C) = MEM16(0x3B856C) + 1;
    goto loc_003C136B;

loc_003C1364: ;
    MEM16(0x3B8568) = MEM16(0x3B8568) + 1;

loc_003C136B: ;
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(eax));
    { uint32_t _icall_t = MEM32(0x3C1638); g_seh_ebp = ebp; PUSH32(esp, 0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1376: ;
    eax = MEM32(esi + 0x18);
    ecx = MEM32(0x3B8570);
    MEM32(eax) = ecx;
    eax = MEM32(esi + 0x18);
    MEM32(0x3B8570) = eax;
    MEM32(esi + 0x18) = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

    esi = eax;
    SET_LO8(eax, MEM8(esi + 0xB));
    SET_LO8(eax, LO8(eax) & 0xFE);
    SET_LO8(eax, LO8(eax) | 8);
    /* test LO8(eax), 0x20 - flags set for next jcc */
    MEM8(esi + 0xB) = LO8(eax);
    if (TEST_Z(LO8(eax), 0x20)) goto loc_003C13B6; /* je: equal / zero */

loc_003C13AD: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C126E(); /* call 0x003C126E */

loc_003C13B4: ;
    goto loc_003C13D2;

loc_003C13B6: ;
    if (TEST_NZ(LO8(eax), 4)) goto loc_003C13D2; /* jne: not equal / not zero */

loc_003C13BA: ;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    PUSH32(esp, 0);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C13C7: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C13CE: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;

loc_003C13D2: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C1390
 * Original: 0x003C1390 - 0x003C13D7 (71 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1390(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1390: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0xC);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCB8(); /* call 0x003BBCB8 */

loc_003C139D: ;
    esi = eax;
    SET_LO8(eax, MEM8(esi + 0xB));
    SET_LO8(eax, LO8(eax) & 0xFE);
    SET_LO8(eax, LO8(eax) | 8);
    /* test LO8(eax), 0x20 - flags set for next jcc */
    MEM8(esi + 0xB) = LO8(eax);
    if (TEST_Z(LO8(eax), 0x20)) goto loc_003C13B6; /* je: equal / zero */

loc_003C13AD: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C126E(); /* call 0x003C126E */

loc_003C13B4: ;
    goto loc_003C13D2;

loc_003C13B6: ;
    if (TEST_NZ(LO8(eax), 4)) goto loc_003C13D2; /* jne: not equal / not zero */

loc_003C13BA: ;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    PUSH32(esp, 0);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BBCBC(); /* call 0x003BBCBC */

loc_003C13C7: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003BA4A7(); /* call 0x003BA4A7 */

loc_003C13CE: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;

loc_003C13D2: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C13D7
 * Original: 0x003C13D7 - 0x003C13FA (35 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C13D7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C13D7: ;
    PUSH32(esp, ebp);
    ebp = esp;
    edx = MEM32(ebp + 8);
    eax = edx + 0xC;
    PUSH32(esp, esi);
    MEM32(ebp + 8) = eax;
    eax = 0xFFFFFFFFu;
    ecx = MEM32(ebp + 8);
    { uint32_t _xa_old = MEM32(ecx); uint32_t _xa_sum = _xa_old + eax;
    eax = _xa_old;
    MEM32(ecx) = _xa_sum; } /* xadd */
    eax--;
    esi = eax;
    if (CMP_GE(esi & esi, 0)) { g_seh_ebp = ebp; sub_003C13FA(); return; } /* jge: greater or equal (signed >=) */

loc_003C13F6: ;
    eax = 0; /* xor self */
    g_seh_ebp = ebp; sub_003C1405(); return; /* tail jmp 0x003C1405 */

}

/**
 * sub_003C13FA
 * Original: 0x003C13FA - 0x003C1405 (11 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C13FA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C13FA: ;
    if (TEST_NZ(esi, esi) /* jne: flags of `test esi, esi` before the split (entry-flags) */) goto loc_003C1403;

loc_003C13FC: ;
    ecx = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0); sub_003C12C9(); /* call 0x003C12C9 */

loc_003C1403: ;
    eax = esi;

    g_seh_ebp = ebp; sub_003C1405(); return; /* restored dropped fall-through to sub_003C1405 */
}

/**
 * sub_003C1405
 * Original: 0x003C1405 - 0x003C146C (103 bytes, 39 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1405(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1405: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

loc_003C1414: ;
    MEM32(eax + -8) = 0x46C30C;
    MEM32(eax + -4) = ecx;
    MEM16(eax) = LO16(ecx);
    MEM8(eax + 2) = LO8(ecx);
    MEM8(eax + 3) = LO8(ecx);
    MEM32(eax + 4) = ecx;
    MEM32(eax + 8) = ecx;
    MEM32(eax + 0xC) = ecx;
    MEM32(eax + 0x10) = ecx;
    eax = eax + 0x1C;
    edx--;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C1414; } /* jne: not equal / not zero */

loc_003C1439: ;
    esp += 4; return; /* ret */

loc_003C1444: ;
    MEM32(eax + -8) = 0x46C30C;
    MEM32(eax + -4) = ecx;
    MEM16(eax) = LO16(ecx);
    MEM8(eax + 2) = LO8(ecx);
    MEM8(eax + 3) = LO8(ecx);
    MEM32(eax + 4) = ecx;
    MEM32(eax + 8) = ecx;
    MEM32(eax + 0xC) = ecx;
    MEM32(eax + 0x10) = ecx;
    eax = eax + 0x1C;
    edx--;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C1444; } /* jne: not equal / not zero */

loc_003C1469: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C140A
 * Original: 0x003C140A - 0x003C143A (48 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C140A(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C140A: ;
    PUSH32(esp, 4);
    eax = 0xF2A678;
    POP32(esp, edx);
    ecx = 0; /* xor self */

loc_003C1414: ;
    MEM32(eax + -8) = 0x46C30C;
    MEM32(eax + -4) = ecx;
    MEM16(eax) = LO16(ecx);
    MEM8(eax + 2) = LO8(ecx);
    MEM8(eax + 3) = LO8(ecx);
    MEM32(eax + 4) = ecx;
    MEM32(eax + 8) = ecx;
    MEM32(eax + 0xC) = ecx;
    MEM32(eax + 0x10) = ecx;
    eax = eax + 0x1C;
    edx--;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C1414; } /* jne: not equal / not zero */

loc_003C1439: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C143A
 * Original: 0x003C143A - 0x003C146C (50 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C143A(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C143A: ;
    PUSH32(esp, 4);
    eax = 0xF2A6E8;
    POP32(esp, edx);
    ecx = 0; /* xor self */

loc_003C1444: ;
    MEM32(eax + -8) = 0x46C30C;
    MEM32(eax + -4) = ecx;
    MEM16(eax) = LO16(ecx);
    MEM8(eax + 2) = LO8(ecx);
    MEM8(eax + 3) = LO8(ecx);
    MEM32(eax + 4) = ecx;
    MEM32(eax + 8) = ecx;
    MEM32(eax + 0xC) = ecx;
    MEM32(eax + 0x10) = ecx;
    eax = eax + 0x1C;
    edx--;
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C1444; } /* jne: not equal / not zero */

loc_003C1469: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C146C
 * Original: 0x003C146C - 0x003C14AB (63 bytes, 36 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C146C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C146C: ;
    POP32(esp, esp);
    esp++;
    if (_flags /* jbe: below or equal (unsigned <=) */) { g_seh_ebp = ebp; sub_003C14DA(); return; }

loc_003C1471: ;
    /* TODO: arpl word ptr [ebp + 0x5c], sp */
    ebp--;
    PUSH32(esp, ebp);
    POP32(esp, edi);
    MEM8(eax) = MEM8(eax) ^ LO8(eax);
    MEM8(eax) = MEM8(eax) + LO8(eax);
    MEM8(esp + eax * 2 + 0x65) = MEM8(esp + eax * 2 + 0x65) + LO8(ebx);
    if (_flags /* jbe: below or equal (unsigned <=) */) { g_seh_ebp = ebp; sub_003C14EA(); return; }

loc_003C1481: ;
    /* TODO: arpl word ptr [ebp + 0x5c], sp */
    ebp--;
    PUSH32(esp, ebp);
    POP32(esp, edi);
    eax = eax & 0x78;
    /* cmp MEM32(0x45304631), esi - flags set for next jcc */
    esi++;
    esi = esi ^ MEM32(eax);
    esp++;
    ebx++;
    SET_LO8(eax, LO8(eax) ^ 0x36);
    /* cmp MEM32((XBOX_FS_BASE + edi + 0x43)), ebx - flags set for next jcc */
    edi--;
    PUSH32(esp, edx);
    PUSH32(esp, edx);
    PUSH32(esp, ebp);
    PUSH32(esp, eax);
    PUSH32(esp, esp);
    POP32(esp, edi);
    PUSH32(esp, ebx);
    ebp++;
    ebx++;
    PUSH32(esp, esp);
    edi--;
    PUSH32(esp, edx);

}
