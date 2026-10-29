/**
 * Dead or Alive 2 Ultimate - Recompiled code chunk 15
 * Functions: 254 (0x003BCB07 - 0x003C4E4C)
 */

#define RECOMP_GENERATED_CODE
#include "recomp_funcs.h"
#include <math.h>

/**
 * sub_003BCB07
 * Original: 0x003BCB07 - 0x003BCCCC (453 bytes, 142 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCB07(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCB07: ;
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
    _rcc0 = (CMP_AE(MEM32(ebx), eax)); /* latched */
    PUSH32(esp, esi);
    MEM32(ebp + -8) = ecx;
    if (_rcc0) goto loc_003BCB27; /* jae: above or equal (unsigned >=) */

loc_003BCB25: ;
    MEM32(ebx) = eax;

loc_003BCB27: ;
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
    if (CMP_AE(ecx, edx)) goto loc_003BCB5B; /* jae: above or equal (unsigned >=) */

loc_003BCB5A: ;
    eax++;

loc_003BCB5B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    eax = eax << 0xC;
    edi = eax;
    PUSH32(esp, edi);
    MEM32(ebp + -4) = edi;
    { uint32_t _icall_t = MEM32(0x3C4F3C); g_seh_ebp = ebp; PUSH32(esp, 0x3BCB6B); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB6B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    esi = eax;
    PUSH32(esp, edi);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C5060); g_seh_ebp = ebp; PUSH32(esp, 0x3BCB77); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB77: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C505C); g_seh_ebp = ebp; PUSH32(esp, 0x3BCB7E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCB7E: ;
    ecx = esi;
    ecx = ecx - eax;
    MEM32(0xF4C340) = ecx;
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
    MEM32(0xF4C344) = esi;
    MEM32(0xF4C348) = edx;
    edi = ZX8(MEM8(ebx + 0xE));
    ecx = esi + eax;
    esi = esi + 0x100;
    eax = 0; /* xor self */
    MEM32(0xF4C36C) = edi;
    MEM32(0xF4C368) = edx;
    /* cmp MEM32(ebx + 4), edx - flags set for next jcc */
    _rcc0 = (CMP_BE(MEM32(ebx + 4), edx)); /* latched */
    MEM32(ebp + -12) = ecx;
    if (_rcc0) goto loc_003BCC0D; /* jbe: below or equal (unsigned <=) */

loc_003BCBCF: ;
    edi = MEM32(0xF4C368);
    MEM32(esi) = edi;
    edi = MEM32(0xF4C348);
    MEM32(0xF4C368) = esi;
    esi = esi + MEM32(ebp + -8);
    MEM32(esi + 0x18) = edi;
    MEM32(0xF4C348) = esi;
    esi = esi + 0x30;
    eax++;
    if (CMP_B(eax, MEM32(ebx + 4))) { RECOMP_SLICE_POINT(); goto loc_003BCBCF; } /* jb: below (unsigned <) */

loc_003BCBF8: ;
    goto loc_003BCC0D;

loc_003BCBFA: ;
    edi = MEM32(0xF4C348);
    MEM32(esi + 0x18) = edi;
    MEM32(0xF4C348) = esi;
    esi = esi + 0x30;
    eax++;

loc_003BCC0D: ;
    if (CMP_B(eax, MEM32(ebx))) { RECOMP_SLICE_POINT(); goto loc_003BCBFA; } /* jb: below (unsigned <) */

loc_003BCC11: ;
    edi = esi + 0x20;
    /* cmp edi, ecx - flags set for next jcc */
    MEM32(ebp + -4) = edx;
    MEM32(0xF4C34C) = edx;
    MEM32(0xF4C350) = esi;
    if (CMP_A(edi, ecx)) goto loc_003BCC4B; /* ja: above (unsigned >) */

loc_003BCC27: ;
    eax = esi;
    eax = eax - MEM32(0xF4C340);
    PUSH32(esp, esi);
    MEM32(ebp + -8) = esi;
    MEM32(edi + -16) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCC3B); sub_003C26CB(); /* call 0x003C26CB */

loc_003BCC3B: ;
    esi = esi + 0x20;
    edi = edi + 0x20;
    MEM32(ebp + -4) = MEM32(ebp + -4) + 1;
    if (CMP_BE(edi, MEM32(ebp + -12))) { RECOMP_SLICE_POINT(); goto loc_003BCC27; } /* jbe: below or equal (unsigned <=) */

loc_003BCC49: ;
    edx = 0; /* xor self */

loc_003BCC4B: ;
    eax = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    MEM32(0xF4C354) = eax;
    MEM32(0xF4C358) = edx;
    MEM32(0xF4C35C) = 0x3E8;
    SET_LO16(eax, ZX8(MEM8(ebx + 0xC)));
    MEM16(0xF4C360) = LO16(eax);
    SET_LO16(eax, ZX8(MEM8(ebx + 0xD)));
    MEM16(0xF4C364) = LO16(eax);
    /* cmp ecx, MEM32(ebx + 8) - flags set for next jcc */
    POP32(esp, edi);
    if (CMP_BE(ecx, MEM32(ebx + 8))) goto loc_003BCCB4; /* jbe: below or equal (unsigned <=) */

loc_003BCC82: ;
    SET_LO8(ecx, LO8(ecx) - MEM8(ebx + 8));
    if (CMP_EQ(LO16(eax), LO16(edx))) goto loc_003BCC9D; /* je: equal / zero */

loc_003BCC8A: ;
    SET_LO8(edx, LO8(ecx));
    SET_LO8(edx, LO8(edx) >> 1);
    SET_LO16(esi, ZX8(LO8(edx)));
    SET_LO16(eax, LO16(eax) + LO16(esi));
    MEM16(0xF4C364) = LO16(eax);
    SET_LO8(ecx, LO8(ecx) - LO8(edx));

loc_003BCC9D: ;
    SET_LO16(eax, ZX8(LO8(ecx)));
    MEM16(0xF4C360) = MEM16(0xF4C360) + LO16(eax);
    eax = MEM32(ebp + -4);
    MEM32(ebx + 8) = eax;
    SET_LO16(eax, MEM16(0xF4C364));

loc_003BCCB4: ;
    SET_LO16(ecx, MEM16(0xF4C360));
    POP32(esp, esi);
    MEM16(0xF4C362) = LO16(ecx);
    MEM16(0xF4C366) = LO16(eax);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BCCCC
 * Original: 0x003BCCCC - 0x003BCD2D (97 bytes, 32 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCCCC(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BCCCC: ;
    PUSH32(esp, esi);
    esi = ecx;
    eax = MEM32(esi + 8);
    eax = eax - MEM32(0xF4C340);
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCD23); sub_003BE9FB(); /* call 0x003BE9FB */

loc_003BCD23: ;
    ecx = MEM32(esi);
    eax = ZX16(LO16(eax));
    MEM32(ecx + 0x44) = eax;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BCD2D
 * Original: 0x003BCD2D - 0x003BCD38 (11 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD2D(void)
{

loc_003BCD2D: ;
    eax = MEM32(esp + 4);
    eax = MEM32(eax);
    eax = MEM32(eax);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BCD38
 * Original: 0x003BCD38 - 0x003BCD9A (98 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD38(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCD38: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    edx = MEM32(ebp + 8);
    eax = MEM32(edx);
    ecx = MEM32(eax + 4);
    PUSH32(esp, esi);
    esi = 0x100;
    if (TEST_Z(esi, ecx)) goto loc_003BCD61; /* je: equal / zero */

loc_003BCD4F: ;
    ecx = MEM32(eax + 8);
    ecx = ecx | 8;
    MEM32(eax + 8) = ecx;
    edx = MEM32(edx);

loc_003BCD5A: ;
    /* hw busy-wait forced through (was: if (TEST_NZ(MEM32(edx + 4), esi)) goto loc_003BCD5A) */

loc_003BCD5F: ;
    goto loc_003BCD95;

loc_003BCD61: ;
    edx = ecx;
    edx = edx >> 6;
    edx = edx & 3;
    if ((edx == 0)) goto loc_003BCD95; /* je: equal / zero */

loc_003BCD6B: ;
    if (CMP_EQ(edx, 2)) goto loc_003BCD95; /* je: equal / zero */

loc_003BCD70: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FB4); g_seh_ebp = ebp; PUSH32(esp, 0x3BCD95); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCD95: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BCD9A
 * Original: 0x003BCD9A - 0x003BCE01 (103 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCD9A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCD9A: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 0xC);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    esi = edi + ebx;
    if (TEST_Z(esi, esi)) goto loc_003BCDC4; /* je: equal / zero */

loc_003BCDAD: ;
    eax = esi;
    eax = (uint32_t)((int32_t)eax * (int32_t)0x380);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x6B776168);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C501C); g_seh_ebp = ebp; PUSH32(esp, 0x3BCDC1); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCDC1: ;
    MEM32(ebp + 8) = eax;

loc_003BCDC4: ;
    eax = 0; /* xor self */
    /* test esi, esi - flags set for next jcc */
    MEM32(0x3BBF50) = eax;
    if (CMP_BE(esi & esi, 0)) goto loc_003BCDE4; /* jbe: below or equal (unsigned <=) */

loc_003BCDCF: ;
    ecx = MEM32(ebp + 8);

loc_003BCDD2: ;
    MEM32(ecx) = eax;
    eax = ecx;
    ecx = ecx + 0x380;
    esi--;
    if ((esi != 0)) { RECOMP_SLICE_POINT(); goto loc_003BCDD2; } /* jne: not equal / not zero */

loc_003BCDDF: ;
    MEM32(0x3BBF50) = eax;

loc_003BCDE4: ;
    MEM16(0x3BBF4C) = LO16(edi);
    eax = 0; /* xor self */
    edi = 0xF30AAC;
    MEM32(edi) = eax; edi += 4; /* stosd */
    POP32(esp, edi);
    POP32(esp, esi);
    MEM16(0x3BBF48) = LO16(ebx);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BCE01
 * Original: 0x003BCE01 - 0x003BCEA4 (163 bytes, 56 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCE01(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCE01: ;
    PUSH32(esp, ebp);
    ebp = esp;
    if (CMP_NE(MEM32(0x3BBFE0), 0)) goto loc_003BCEA0; /* jne: not equal / not zero */

loc_003BCE11: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    PUSH32(esp, edi);
    ecx = esi;
    MEM32(0x3BBFE0) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE28); sub_003BC2C0(); /* call 0x003BC2C0 */

loc_003BCE28: ;
    if (TEST_Z(eax, eax)) goto loc_003BCE33; /* je: equal / zero */

loc_003BCE2C: ;
    PUSH32(esp, 4);
    POP32(esp, eax);
    ebx = eax;
    goto loc_003BCE6E;

loc_003BCE33: ;
    PUSH32(esp, 0x3BBF8C);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE3F); sub_003BC289(); /* call 0x003BC289 */

loc_003BCE3F: ;
    PUSH32(esp, 0x3BBF74);
    ecx = esi;
    edi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE4D); sub_003BC289(); /* call 0x003BC289 */

loc_003BCE4D: ;
    PUSH32(esp, 0x3BBF80);
    ecx = esi;
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE5B); sub_003BC289(); /* call 0x003BC289 */

loc_003BCE5B: ;
    PUSH32(esp, 4);
    MEM32(ebp + 8) = eax;
    ebx = ebx + edi;
    POP32(esp, eax);
    if (CMP_BE(ebx, eax)) goto loc_003BCE69; /* jbe: below or equal (unsigned <=) */

loc_003BCE67: ;
    ebx = eax;

loc_003BCE69: ;
    if (CMP_BE(MEM32(ebp + 8), eax)) goto loc_003BCE71; /* jbe: below or equal (unsigned <=) */

loc_003BCE6E: ;
    MEM32(ebp + 8) = eax;

loc_003BCE71: ;
    edi = 0x3BBFD4;
    PUSH32(esp, edi);
    ecx = esi;
    MEM8(0x3BBFD5) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE84); sub_003BC2CC(); /* call 0x003BC2CC */

loc_003BCE84: ;
    SET_LO8(eax, MEM8(ebp + 8));
    PUSH32(esp, edi);
    ecx = esi;
    MEM8(0x3BBFD5) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE94); sub_003BC2CC(); /* call 0x003BC2CC */

loc_003BCE94: ;
    PUSH32(esp, MEM32(ebp + 8));
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCE9D); sub_003BCD9A(); /* call 0x003BCD9A */

loc_003BCE9D: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);

loc_003BCEA0: ;
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BCEA4
 * Original: 0x003BCEA4 - 0x003BCFD6 (306 bytes, 103 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCEA4(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCEA4: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xA4;
    eax = MEM32(ebp + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BCEB7; /* je: equal / zero */

loc_003BCEB4: ;
    MEM8(eax) = 0;

loc_003BCEB7: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = 0x3BBD98;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4F78); g_seh_ebp = ebp; PUSH32(esp, 0x3BCEC6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCEC6: ;
    SET_LO8(ebx, MEM8(ebp + 8));
    SET_LO8(ebx, LO8(ebx) + 0x23);
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) + MEM8(ebp + 0xC));
    eax = 0; /* xor self */
    esi = SX8(LO8(ebx));
    eax++;
    ecx = esi + -70;
    eax = eax << LO8(ecx);
    /* test MEM32(0xF2D800), eax - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM32(0xF2D800), eax)); /* latched */
    MEM32(ebp + -16) = eax;
    if (_rcc0) goto loc_003BCEFB; /* je: equal / zero */

loc_003BCEE7: ;
    eax = MEM32(ebp + 0x10);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(eax) = LO8(ebx);
    { uint32_t _icall_t = MEM32(0x3C4F74); g_seh_ebp = ebp; PUSH32(esp, 0x3BCEF3); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCEF3: ;
    PUSH32(esp, 0x55);
    POP32(esp, eax);
    goto loc_003BCFCF;

loc_003BCEFB: ;
    MEM16(ebp + -8) = MEM16(ebp + -8) & 0;
    eax = ebp + -164;
    MEM32(ebp + -4) = eax;
    eax = ebp + -8;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0xC));
    MEM16(ebp + -6) = 0x3F;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCF1E); sub_003BD606(); /* call 0x003BD606 */

loc_003BCF1E: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (TEST_S(eax, eax)) goto loc_003BCFBF; /* jl: less (signed <) */

loc_003BCF29: ;
    PUSH32(esp, esi);
    eax = ebp + -100;
    PUSH32(esp, 0x471880);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCF38); sub_0033A187(); /* call 0x0033A187 */

loc_003BCF38: ;
    esp = esp + 0xC;
    eax = ebp + -100;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    eax = ebp + -24;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4EC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BCF49); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCF49: ;
    eax = MEM32(0x10118);
    PUSH32(esp, MEM32(eax + 8));
    eax = ebp + -36;
    PUSH32(esp, 0x471878);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCF5F); sub_0033A187(); /* call 0x0033A187 */

loc_003BCF5F: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCF8F); sub_002BF620(); /* call 0x002BF620 */

loc_003BCF8F: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (TEST_S(eax, eax)) goto loc_003BCFAA; /* jl: less (signed <) */

loc_003BCF96: ;
    eax = MEM32(ebp + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BCF9F; /* je: equal / zero */

loc_003BCF9D: ;
    MEM8(eax) = LO8(ebx);

loc_003BCF9F: ;
    eax = MEM32(ebp + -16);
    MEM32(0xF2D800) = MEM32(0xF2D800) | eax;
    goto loc_003BCFBF;

loc_003BCFAA: ;
    eax = ebp + -8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FB8); g_seh_ebp = ebp; PUSH32(esp, 0x3BCFB4); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCFB4: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BCFBF); sub_003BD599(); /* call 0x003BD599 */

loc_003BCFBF: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4F74); g_seh_ebp = ebp; PUSH32(esp, 0x3BCFC6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCFC6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -12));
    { uint32_t _icall_t = MEM32(0x3C4EE4); g_seh_ebp = ebp; PUSH32(esp, 0x3BCFCF); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCFCF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BCFD6
 * Original: 0x003BCFD6 - 0x003BD0E4 (270 bytes, 95 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BCFD6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BCFD6: ;
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
    PUSH32(esp, 0x3BBD98);
    { uint32_t _icall_t = MEM32(0x3C4F78); g_seh_ebp = ebp; PUSH32(esp, 0x3BCFF5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BCFF5: ;
    edi = SX8(LO8(ebx));
    esi = 0; /* xor self */
    esi++;
    ecx = edi + -70;
    esi = esi << LO8(ecx);
    if (TEST_NZ(MEM32(0xF2D800), esi)) goto loc_003BD01B; /* jne: not equal / not zero */

loc_003BD008: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BBD98);
    { uint32_t _icall_t = MEM32(0x3C4F74); g_seh_ebp = ebp; PUSH32(esp, 0x3BD013); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD013: ;
    PUSH32(esp, 0xF);
    POP32(esp, eax);
    goto loc_003BD0DD;

loc_003BD01B: ;
    if (CMP_NE(MEM8(0xF2D7FC), LO8(ebx))) goto loc_003BD02A; /* jne: not equal / not zero */

loc_003BD023: ;
    PUSH32(esp, 0x58);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD02A); sub_002BBEC6(); /* call 0x002BBEC6 */

loc_003BD02A: ;
    PUSH32(esp, edi);
    eax = ebp + -96;
    PUSH32(esp, 0x471880);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD039); sub_0033A187(); /* call 0x0033A187 */

loc_003BD039: ;
    esp = esp + 0xC;
    eax = ebp + -96;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    eax = ebp + -12;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4EC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD04A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD04A: ;
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
    { uint32_t _icall_t = MEM32(0x3C4F20); g_seh_ebp = ebp; PUSH32(esp, 0x3BD07E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD07E: ;
    ebx = eax;
    if (CMP_L(ebx, edi)) goto loc_003BD0CB; /* jl: less (signed <) */

loc_003BD084: ;
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
    { uint32_t _icall_t = MEM32(0x3C4EE8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD09D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD09D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -4));
    ebx = eax;
    { uint32_t _icall_t = MEM32(0x3C4EB8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD0A8); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD0A8: ;
    if (CMP_L(ebx, edi)) goto loc_003BD0CB; /* jl: less (signed <) */

loc_003BD0AC: ;
    eax = ebp + -12;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4EE0); g_seh_ebp = ebp; PUSH32(esp, 0x3BD0B6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD0B6: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    ebx = eax;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD0C3); sub_003BD599(); /* call 0x003BD599 */

loc_003BD0C3: ;
    esi = ~esi;
    MEM32(0xF2D800) = MEM32(0xF2D800) & esi;

loc_003BD0CB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BBD98);
    { uint32_t _icall_t = MEM32(0x3C4F74); g_seh_ebp = ebp; PUSH32(esp, 0x3BD0D6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD0D6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C4EE4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD0DD); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD0DD: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD0E4
 * Original: 0x003BD0E4 - 0x003BD24F (363 bytes, 128 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD0E4(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD0E4: ;
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
    PUSH32(esp, 0x3BBD98);
    { uint32_t _icall_t = MEM32(0x3C4F78); g_seh_ebp = ebp; PUSH32(esp, 0x3BD105); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD105: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, LO8(ebx));
    eax = 0; /* xor self */
    eax++;
    ebx = 0; /* xor self */
    ecx = ecx - 0x46;
    eax = eax << LO8(ecx);
    /* test MEM32(0xF2D800), eax - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM32(0xF2D800), eax)); /* latched */
    MEM32(ebp + -20) = eax;
    if (_rcc0) goto loc_003BD144; /* jne: not equal / not zero */

loc_003BD11E: ;
    eax = ebp + -148;
    MEM32(ebp + -12) = eax;
    eax = ebp + -16;
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0xC));
    MEM16(ebp + -16) = LO16(ebx);
    PUSH32(esp, MEM32(ebp + 8));
    MEM16(ebp + -14) = 0x3E;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD140); sub_003BD606(); /* call 0x003BD606 */

loc_003BD140: ;
    edi = eax;
    goto loc_003BD146;

loc_003BD144: ;
    edi = 0; /* xor self */

loc_003BD146: ;
    if (CMP_L(edi, ebx)) goto loc_003BD237; /* jl: less (signed <) */

loc_003BD14E: ;
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD15A); sub_003BD45B(); /* call 0x003BD45B */

loc_003BD15A: ;
    esi = MEM32(0x3C4FC0);
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
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0x3BD175); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD175: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003BD220; /* jl: less (signed <) */

loc_003BD17F: ;
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
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0x3BD193); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD193: ;
    /* cmp MEM32(ebp + -48), ebx - flags set for next jcc */
    edi = eax;
    esi = 0x1000;
    if (CMP_G(MEM32(ebp + -48), ebx)) goto loc_003BD1AB; /* jg: greater (signed >) */

loc_003BD19F: ;
    if (CMP_L(MEM32(ebp + -48), ebx)) goto loc_003BD1A6; /* jl: less (signed <) */

loc_003BD1A1: ;
    if (CMP_AE(MEM32(ebp + -52), esi)) goto loc_003BD1AB; /* jae: above or equal (unsigned >=) */

loc_003BD1A6: ;
    edi = 0xC000014Fu;

loc_003BD1AB: ;
    if (CMP_L(edi, ebx)) goto loc_003BD220; /* jl: less (signed <) */

loc_003BD1AF: ;
    PUSH32(esp, 0x24830000);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD1BA); sub_002BF407(); /* call 0x002BF407 */

loc_003BD1BA: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(ebp + -8) = eax;
    if (CMP_EQ(eax, ebx)) goto loc_003BD21B; /* je: equal / zero */

loc_003BD1C1: ;
    ecx = ebp + -28;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + -4));
    MEM32(ebp + -28) = ebx;
    PUSH32(esp, 2);
    MEM32(ebp + -24) = ebx;
    { uint32_t _icall_t = MEM32(0x3C4FBC); g_seh_ebp = ebp; PUSH32(esp, 0x3BD1D8); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD1D8: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003BD20C; /* jl: less (signed <) */

loc_003BD1DE: ;
    eax = MEM32(ebp + -8);
    if (CMP_NE(MEM32(eax), 0x58544146)) goto loc_003BD207; /* jne: not equal / not zero */

loc_003BD1E9: ;
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
    goto loc_003BD20C;

loc_003BD207: ;
    edi = 0xC000014Fu;

loc_003BD20C: ;
    PUSH32(esp, 0x24830000);
    PUSH32(esp, MEM32(ebp + -8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD219); sub_002BF4A7(); /* call 0x002BF4A7 */

loc_003BD219: ;
    goto loc_003BD220;

loc_003BD21B: ;
    edi = 0xC000009Au;

loc_003BD220: ;
    eax = MEM32(ebp + -20);
    /* test MEM32(0xF2D800), eax - flags set for next jcc */
    POP32(esp, esi);
    if (TEST_NZ(MEM32(0xF2D800), eax)) goto loc_003BD237; /* jne: not equal / not zero */

loc_003BD22C: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD237); sub_003BD599(); /* call 0x003BD599 */

loc_003BD237: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BBD98);
    { uint32_t _icall_t = MEM32(0x3C4F74); g_seh_ebp = ebp; PUSH32(esp, 0x3BD242); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD242: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4EE4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD249); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD249: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

}

/**
 * sub_003BD24F
 * Original: 0x003BD24F - 0x003BD26E (31 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD24F(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BD24F: ;
    SET_LO8(eax, MEM8(esp + 4));
    if (CMP_L(LO8(eax), 0x46)) goto loc_003BD268; /* jl: less (signed <) */

loc_003BD257: ;
    if (CMP_G(LO8(eax), 0x4D)) goto loc_003BD268; /* jg: greater (signed >) */

loc_003BD25B: ;
    eax = SX8(LO8(eax));
    eax = eax - 0x46;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    eax = eax - edx;
    eax = (uint32_t)((int32_t)eax >> 1);
    goto loc_003BD26B;

loc_003BD268: ;
    eax = eax | 0xFFFFFFFFu;

loc_003BD26B: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD26E
 * Original: 0x003BD26E - 0x003BD290 (34 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD26E(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BD26E: ;
    SET_LO8(eax, MEM8(esp + 4));
    if (CMP_L(LO8(eax), 0x46)) goto loc_003BD28A; /* jl: less (signed <) */

loc_003BD276: ;
    if (CMP_G(LO8(eax), 0x4D)) goto loc_003BD28A; /* jg: greater (signed >) */

loc_003BD27A: ;
    eax = SX8(LO8(eax));
    eax = eax - 0x46;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    PUSH32(esp, 2);
    POP32(esp, ecx);
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    eax = edx;
    goto loc_003BD28D;

loc_003BD28A: ;
    eax = eax | 0xFFFFFFFFu;

loc_003BD28D: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD290
 * Original: 0x003BD290 - 0x003BD2B2 (34 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD290(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BD290: ;
    ecx = MEM32(esp + 8);
    eax = 0; /* xor self */
    eax++;
    eax = eax << LO8(ecx);
    ecx = MEM32(esp + 4);
    MEM32(ecx + 4) = MEM32(ecx + 4) | eax;
    if (CMP_EQ(MEM8(esp + 0xC), 0)) goto loc_003BD2AB; /* je: equal / zero */

loc_003BD2A7: ;
    MEM32(ecx) = MEM32(ecx) | eax;
    goto loc_003BD2AF;

loc_003BD2AB: ;
    eax = ~eax;
    MEM32(ecx) = MEM32(ecx) & eax;

loc_003BD2AF: ;
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BD2B2
 * Original: 0x003BD2B2 - 0x003BD2EE (60 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2B2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD2B2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD2BA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD2BA: ;
    edi = MEM32(esp + 0x10);
    /* test edi, edi - flags set for next jcc */
    edx = MEM32(esp + 0xC);
    esi = MEM32(edx);
    if (TEST_Z(edi, edi)) goto loc_003BD2CD; /* je: equal / zero */

loc_003BD2C8: ;
    ecx = MEM32(edx + 8);
    MEM32(edi) = ecx;

loc_003BD2CD: ;
    edi = MEM32(esp + 0x14);
    if (TEST_Z(edi, edi)) goto loc_003BD2DF; /* je: equal / zero */

loc_003BD2D5: ;
    ecx = MEM32(edx + 8);
    ecx = ecx & MEM32(edx + 4);
    ecx = ecx & MEM32(edx);
    MEM32(edi) = ecx;

loc_003BD2DF: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD2E7); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD2E7: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BD2EE
 * Original: 0x003BD2EE - 0x003BD2F3 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2EE(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD2EE: ;
    g_seh_ebp = ebp; sub_003BC193(); return; /* tail jmp 0x003BC193 */

}

/**
 * sub_003BD2F3
 * Original: 0x003BD2F3 - 0x003BD315 (34 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD2F3_gen(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD2F3: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD2FA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD2FA: ;
    edx = MEM32(esp + 8);
    esi = MEM32(edx);
    MEM32(edx + 4) = MEM32(edx + 4) & 0;
    SET_LO8(ecx, LO8(eax));
    MEM32(edx + 8) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD30F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD30F: ;
    eax = esi;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD315
 * Original: 0x003BD315 - 0x003BD382 (109 bytes, 47 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD315_gen(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003BD315: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    eax = 0; /* xor self */
    if (CMP_NE(MEM32(esi + 4), eax)) goto loc_003BD32F; /* jne: not equal / not zero */

loc_003BD323: ;
    ecx = MEM32(ebp + 0xC);
    MEM32(ecx) = eax;
    ecx = MEM32(ebp + 0x10);
    MEM32(ecx) = eax;
    goto loc_003BD37D;

loc_003BD32F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD337); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD337: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD36E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD36E: ;
    eax = MEM32(ebx);
    ecx = MEM32(ebp + 0x10);
    eax = eax | MEM32(ecx);
    POP32(esp, edi);
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = (uint32_t)(-(int32_t)eax);
    POP32(esp, ebx);

loc_003BD37D: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BD382
 * Original: 0x003BD382 - 0x003BD39D (27 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD382(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BD382: ;
    eax = MEM32(0xF2D808);
    if (TEST_Z(eax, eax)) goto loc_003BD39C; /* je: equal / zero */

loc_003BD38B: ;
    ecx = MEM32(eax + 8);
    MEM32(0xF2D808) = ecx;
    MEM32(eax + 0xC) = MEM32(eax + 0xC) & 0;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;

loc_003BD39C: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BD39D
 * Original: 0x003BD39D - 0x003BD3C5 (40 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD39D(void)
{

loc_003BD39D: ;
    edx = MEM32(esp + 4);
    PUSH32(esp, edi);
    PUSH32(esp, 0x58);
    POP32(esp, ecx);
    eax = 0; /* xor self */
    edi = edx + 0x10;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    MEM32(edx + 0xC) = 4;
    eax = MEM32(0xF2D808);
    MEM32(edx + 8) = eax;
    MEM32(0xF2D808) = edx;
    POP32(esp, edi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD3C5
 * Original: 0x003BD3C5 - 0x003BD45B (150 bytes, 58 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD3C5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD3C5: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD3D3); sub_003BF80D(); /* call 0x003BF80D */

loc_003BD3D3: ;
    ebx = 0; /* xor self */
    ecx = 0; /* xor self */
    if (CMP_B(eax, 0x10)) goto loc_003BD3E0; /* jb: below (unsigned <) */

loc_003BD3DC: ;
    eax = eax - 0x10;
    ecx++;

loc_003BD3E0: ;
    eax = ecx + eax * 2;
    ecx = MEM32(0xF30814);
    PUSH32(esp, ebx);
    eax = eax + eax * 2;
    PUSH32(esp, 1);
    esi = ecx + eax * 4;
    PUSH32(esp, 2);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD3FB); sub_003BF797(); /* call 0x003BF797 */

loc_003BD3FB: ;
    if (CMP_EQ(eax, ebx)) goto loc_003BD449; /* je: equal / zero */

loc_003BD3FF: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 5) = LO8(ecx);
    /* cmp MEM16(eax + 4), 0x40 - flags set for next jcc */
    ecx = edi;
    if (CMP_NE(MEM16(eax + 4), 0x40)) goto loc_003BD44B; /* jne: not equal / not zero */

loc_003BD40E: ;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, 2);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD417); sub_003BF797(); /* call 0x003BF797 */

loc_003BD417: ;
    if (CMP_EQ(eax, ebx)) goto loc_003BD449; /* je: equal / zero */

loc_003BD41B: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 6) = LO8(ecx);
    /* cmp MEM16(eax + 4), 0x40 - flags set for next jcc */
    ecx = edi;
    if (CMP_NE(MEM16(eax + 4), 0x40)) goto loc_003BD44B; /* jne: not equal / not zero */

loc_003BD42A: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD430); sub_003BF69C(); /* call 0x003BF69C */

loc_003BD430: ;
    ecx = edi;
    MEM32(esi) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD439); sub_003BF6A9(); /* call 0x003BF6A9 */

loc_003BD439: ;
    PUSH32(esp, ebx);
    ecx = edi;
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD444); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003BD444: ;
    PUSH32(esp, ebx);
    ecx = edi;
    goto loc_003BD450;

loc_003BD449: ;
    ecx = edi;

loc_003BD44B: ;
    PUSH32(esp, 0x80000400u);

loc_003BD450: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD455); sub_003BE253(); /* call 0x003BE253 */

loc_003BD455: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD45B
 * Original: 0x003BD45B - 0x003BD478 (29 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD45B(void)
{

loc_003BD45B: ;
    ecx = MEM32(esp + 4);
    eax = MEM32(esp + 8);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF30814);
    eax = eax + eax * 2;
    eax = MEM32(ecx + eax * 4 + 8);
    eax = MEM32(eax);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD478
 * Original: 0x003BD478 - 0x003BD54A (210 bytes, 61 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD478(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD478: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0xC);
    /* test eax, 0x40000 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = MEM32(esi + 8);
    if (TEST_Z(eax, 0x40000)) goto loc_003BD4A6; /* je: equal / zero */

loc_003BD48B: ;
    edx = MEM32(esi + 0x24);
    MEM32(esi + 0x24) = MEM32(esi + 0x24) & 0;
    MEM8(esi + 0x111) = 0x43;
    MEM32(esi + 0x120) = edx;
    eax = eax & 0xFFFBFFFFu;
    goto loc_003BD4DB;

loc_003BD4A6: ;
    if (TEST_Z(eax, 0x20000)) goto loc_003BD4C8; /* je: equal / zero */

loc_003BD4AD: ;
    edx = MEM32(esi + 0x20);
    MEM32(esi + 0x20) = MEM32(esi + 0x20) & 0;
    MEM8(esi + 0x111) = 0x43;
    MEM32(esi + 0x120) = edx;
    eax = eax & 0xFFFDFFFFu;
    goto loc_003BD4DB;

loc_003BD4C8: ;
    if (TEST_Z(eax, 0x10000)) goto loc_003BD501; /* je: equal / zero */

loc_003BD4CF: ;
    MEM8(esi + 0x111) = 0xC3;
    eax = eax & 0xFFFEFFFFu;

loc_003BD4DB: ;
    ecx = esi + 0x110;
    MEM8(ecx) = 0x1C;
    MEM32(esi + 0x118) = 0x3BD478;
    MEM32(esi + 0x11C) = esi;
    MEM32(esi + 0xC) = eax;
    PUSH32(esp, ecx);
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD4FF); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD4FF: ;
    goto loc_003BD545;

loc_003BD501: ;
    eax = eax & 0xFFF7FFFFu;
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* test LO8(eax), 1 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    MEM32(esi + 8) = ebx;
    if (TEST_Z(LO8(eax), 1)) goto loc_003BD529; /* je: equal / zero */

loc_003BD513: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = esi + 0x12C;
    PUSH32(esp, eax);
    MEM32(edi + 8) = ebx;
    { uint32_t _icall_t = MEM32(0x3C4FD0); g_seh_ebp = ebp; PUSH32(esp, 0x3BD525); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD525: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) & 0xFFFFFFFEu;

loc_003BD529: ;
    if (TEST_Z(MEM8(esi + 0xC), 2)) goto loc_003BD544; /* je: equal / zero */

loc_003BD52F: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD536); sub_003BDE87(); /* call 0x003BDE87 */

loc_003BD536: ;
    MEM32(edi) = ebx;
    eax = MEM32(esi + 0xC);
    eax = eax & 0xFFFFFFFDu;
    eax = eax | 4;
    MEM32(esi + 0xC) = eax;

loc_003BD544: ;
    POP32(esp, ebx);

loc_003BD545: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD54A
 * Original: 0x003BD54A - 0x003BD564 (26 bytes, 10 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD54A(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD54A: ;
    eax = MEM32(ecx + 0xC);
    edx = 0x80000;
    if (TEST_NZ(edx, eax)) goto loc_003BD563; /* jne: not equal / not zero */

loc_003BD556: ;
    PUSH32(esp, ecx);
    eax = eax | edx;
    PUSH32(esp, 0);
    MEM32(ecx + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD563); sub_003BD478(); /* call 0x003BD478 */

loc_003BD563: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BD564
 * Original: 0x003BD564 - 0x003BD599 (53 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD564(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD564: ;
    ecx = MEM32(esp + 4);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD56E); sub_003BF698(); /* call 0x003BF698 */

loc_003BD56E: ;
    esi = eax;
    ecx = MEM32(esi + 8);
    if (TEST_Z(ecx, ecx)) goto loc_003BD58B; /* je: equal / zero */

loc_003BD577: ;
    eax = MEM32(ecx + 0xC);
    if (TEST_NZ(LO8(eax), 4)) goto loc_003BD58B; /* jne: not equal / not zero */

loc_003BD57E: ;
    eax = eax | 2;
    MEM32(ecx + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD589); sub_003BD54A(); /* call 0x003BD54A */

loc_003BD589: ;
    goto loc_003BD595;

loc_003BD58B: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD592); sub_003BDE87(); /* call 0x003BDE87 */

loc_003BD592: ;
    MEM32(esi) = MEM32(esi) & 0;

loc_003BD595: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD599
 * Original: 0x003BD599 - 0x003BD606 (109 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD599(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD599: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(ebp + 8);
    eax = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF30814);
    PUSH32(esp, esi);
    eax = eax + eax * 2;
    PUSH32(esp, edi);
    edi = ecx + eax * 4;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD5BA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD5BA: ;
    esi = MEM32(edi + 8);
    ebx = 0; /* xor self */
    /* cmp MEM32(esi + 8), ebx - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(esi + 8), ebx)); /* latched */
    SET_LO8(ecx, LO8(eax));
    MEM8(ebp + 0xF) = LO8(ecx);
    if (_rcc0) goto loc_003BD5F0; /* je: equal / zero */

loc_003BD5C9: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) | 1;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD5D4); sub_003BD54A(); /* call 0x003BD54A */

loc_003BD5D4: ;
    SET_LO8(ecx, MEM8(ebp + 0xF));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD5DD); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD5DD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = esi + 0x12C;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD5EE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD5EE: ;
    goto loc_003BD5F9;

loc_003BD5F0: ;
    MEM32(edi + 8) = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD5F9); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD5F9: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD5FF); sub_003BD39D(); /* call 0x003BD39D */

loc_003BD5FF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BD606
 * Original: 0x003BD606 - 0x003BD7BA (436 bytes, 118 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD606(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD606: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    eax = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    eax = eax + ecx * 2;
    ecx = MEM32(0xF30814);
    PUSH32(esp, esi);
    eax = eax + eax * 2;
    PUSH32(esp, edi);
    ebx = 0; /* xor self */
    MEM32(ebp + -8) = ebx;
    edi = ecx + eax * 4;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD62E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD62E: ;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD636); sub_003BD382(); /* call 0x003BD382 */

loc_003BD636: ;
    esi = eax;
    if (CMP_NE(esi, ebx)) goto loc_003BD643; /* jne: not equal / not zero */

loc_003BD63C: ;
    esi = 0xC0000017u;
    goto loc_003BD652;

loc_003BD643: ;
    /* cmp MEM32(edi), ebx - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM32(edi), ebx)); /* latched */
    PUSH32(esp, esi);
    if (_rcc0) goto loc_003BD662; /* jne: not equal / not zero */

loc_003BD648: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD64D); sub_003BD39D(); /* call 0x003BD39D */

loc_003BD64D: ;
    esi = 0xC000009Du;

loc_003BD652: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD65B); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD65B: ;
    eax = esi;
    goto loc_003BD7B3;

loc_003BD662: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0x3BFBC4);
    eax = esi + 0x98;
    MEM32(edi + 8) = esi;
    PUSH32(esp, eax);
    MEM32(esi + 8) = edi;
    { uint32_t _icall_t = MEM32(0x3C4FDC); g_seh_ebp = ebp; PUSH32(esp, 0x3BD67A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD67A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD8); g_seh_ebp = ebp; PUSH32(esp, 0x3BD685); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD685: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD6C6); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD6C6: ;
    if (TEST_S(eax, eax)) goto loc_003BD768; /* jl: less (signed <) */

loc_003BD6CE: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD70B); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD70B: ;
    if (TEST_S(eax, eax)) goto loc_003BD768; /* jl: less (signed <) */

loc_003BD70F: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD755); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD755: ;
    if (TEST_S(eax, eax)) goto loc_003BD768; /* jl: less (signed <) */

loc_003BD759: ;
    eax = MEM32(esi + 0xC8);
    MEM8(esi + 0xE) = MEM8(esi + 0xE) | 4;
    MEM32(esi + 0x24) = eax;
    goto loc_003BD771;

loc_003BD768: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD76E); sub_003BF725(); /* call 0x003BF725 */

loc_003BD76E: ;
    MEM32(ebp + -8) = eax;

loc_003BD771: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD77A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD77A: ;
    ecx = MEM32(ebp + -8);
    eax = 0xC0000000u;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003BD795; /* jne: not equal / not zero */

loc_003BD788: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD793); sub_003BD599(); /* call 0x003BD599 */

loc_003BD793: ;
    goto loc_003BD7B0;

loc_003BD795: ;
    eax = MEM32(ebp + 0x10);
    MEM16(eax) = 0xC;
    PUSH32(esp, MEM32(esi + 4));
    PUSH32(esp, 0x3C4E5C);
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD7AD); sub_0033A187(); /* call 0x0033A187 */

loc_003BD7AD: ;
    esp = esp + 0xC;

loc_003BD7B0: ;
    eax = MEM32(ebp + -8);

loc_003BD7B3: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BD7BA
 * Original: 0x003BD7BA - 0x003BD7F2 (56 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD7BA(void)
{

loc_003BD7BA: ;
    eax = MEM32(0x3C4FE0);
    MEM32(0x3BBE04) = eax;
    MEM32(0x3BBE08) = eax;
    MEM32(0x3BBE14) = eax;
    MEM32(0x3BBE18) = eax;
    MEM32(0x3BBE1C) = eax;
    MEM32(0x3BBE20) = eax;
    MEM32(0x3BBE24) = eax;
    MEM32(0x3BBE28) = eax;
    MEM32(0x3BBE34) = eax;
    MEM32(0x3BBE38) = eax;
    esp += 4; return; /* ret */

}

/**
 * sub_003BD7F2
 * Original: 0x003BD7F2 - 0x003BD848 (86 bytes, 34 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD7F2_gen(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD7F2: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD802); sub_003BDB09(); /* call 0x003BDB09 */

loc_003BD802: ;
    if (TEST_NZ(eax, eax)) goto loc_003BD811; /* jne: not equal / not zero */

loc_003BD806: ;
    PUSH32(esp, 0x57);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD80D); sub_002BE2D3(); /* call 0x002BE2D3 */

loc_003BD80D: ;
    eax = 0; /* xor self */
    goto loc_003BD844;

loc_003BD811: ;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x14);
    if (TEST_NZ(esi, esi)) goto loc_003BD81C; /* jne: not equal / not zero */

loc_003BD819: ;
    esi = MEM32(eax + 0x10);

loc_003BD81C: ;
    /* cmp MEM32(ebp + 0x10), 1 - flags set for next jcc */
    edx = MEM32(ebp + 0xC);
    if (CMP_NE(MEM32(ebp + 0x10), 1)) goto loc_003BD828; /* jne: not equal / not zero */

loc_003BD825: ;
    edx = edx + 0x10;

loc_003BD828: ;
    PUSH32(esp, esi);
    ecx = ebp + -4;
    PUSH32(esp, ecx);
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD834); sub_003C0E73(); /* call 0x003C0E73 */

loc_003BD834: ;
    /* cmp MEM32(ebp + -4), 0 - flags set for next jcc */
    POP32(esp, esi);
    if (CMP_NE(MEM32(ebp + -4), 0)) goto loc_003BD841; /* jne: not equal / not zero */

loc_003BD83B: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD841); sub_002BE2D3(); /* call 0x002BE2D3 */

loc_003BD841: ;
    eax = MEM32(ebp + -4);

loc_003BD844: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BD848
 * Original: 0x003BD848 - 0x003BD854 (12 bytes, 3 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD848_gen(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BD848: ;
    ecx = MEM32(esp + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD851); sub_003C0ADF(); /* call 0x003C0ADF */

loc_003BD851: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BD854
 * Original: 0x003BD854 - 0x003BDA2C (472 bytes, 145 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BD854_gen(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BD854: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x48;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(0x3C4FC8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0x3BD869); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD869: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    esi = MEM32(eax);
    if (TEST_Z(esi, esi)) goto loc_003BDA0A; /* je: equal / zero */

loc_003BD879: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BDA0A; /* jne: not equal / not zero */

loc_003BD883: ;
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
    if (TEST_Z(MEM8(eax + 0x28), 1)) goto loc_003BD8AA; /* je: equal / zero */

loc_003BD89E: ;
    MEM32(ebp + -8) = 5;
    goto loc_003BDA11;

loc_003BD8AA: ;
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
    edi = 0x3BF674;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD920); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD920: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD929); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD929: ;
    ecx = MEM32(esi);
    eax = ebp + -24;
    PUSH32(esp, eax);
    edx = ebp + -72;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD937); sub_003C0778(); /* call 0x003C0778 */

loc_003BD937: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0x3BD939); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD939: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    ecx = 0; /* xor self */
    if (CMP_EQ(MEM32(eax), ecx)) goto loc_003BDA0A; /* je: equal / zero */

loc_003BD949: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BDA0A; /* jne: not equal / not zero */

loc_003BD953: ;
    if (CMP_L(MEM32(ebp + -68), ecx)) goto loc_003BD9FD; /* jl: less (signed <) */

loc_003BD95C: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD9CD); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BD9CD: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BD9D6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD9D6: ;
    ecx = MEM32(esi);
    eax = ebp + -24;
    PUSH32(esp, eax);
    edx = ebp + -72;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BD9E4); sub_003C0778(); /* call 0x003C0778 */

loc_003BD9E4: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0x3BD9E6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BD9E6: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(ebp + 8);
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003BDA0A; /* je: equal / zero */

loc_003BD9F1: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) goto loc_003BDA0A; /* jne: not equal / not zero */

loc_003BD9F7: ;
    if (CMP_GE(MEM32(ebp + -68), 0)) goto loc_003BDA11; /* jge: greater or equal (signed >=) */

loc_003BD9FD: ;
    PUSH32(esp, MEM32(ebp + -68));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDA05); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003BDA05: ;
    MEM32(ebp + -8) = eax;
    goto loc_003BDA11;

loc_003BDA0A: ;
    MEM32(ebp + -8) = 0x48F;

loc_003BDA11: ;
    eax = MEM32(ebp + 0xC);
    SET_LO8(ecx, MEM8(ebp + -1));
    MEM16(eax + 1) = MEM16(eax + 1) & 0;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BDA22); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDA22: ;
    eax = MEM32(ebp + -8);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDA2C
 * Original: 0x003BDA2C - 0x003BDA9F (115 bytes, 41 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDA2C_gen(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDA2C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDA36); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDA36: ;
    edx = MEM32(esp + 0xC);
    ecx = MEM32(edx + 0xA3);
    if (TEST_Z(MEM8(ecx + 0x28), 0x10)) goto loc_003BDA4B; /* je: equal / zero */

loc_003BDA46: ;
    PUSH32(esp, 0x57);
    POP32(esp, esi);
    goto loc_003BDA90;

loc_003BDA4B: ;
    ecx = MEM32(edx);
    if (TEST_Z(ecx, ecx)) goto loc_003BDA57; /* je: equal / zero */

loc_003BDA51: ;
    if (TEST_Z(MEM8(ecx + 4), 2)) goto loc_003BDA5C; /* je: equal / zero */

loc_003BDA57: ;
    ebx = 0x48F;

loc_003BDA5C: ;
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

loc_003BDA90: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BDA98); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDA98: ;
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDA9F
 * Original: 0x003BDA9F - 0x003BDAD2 (51 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDA9F_gen(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDA9F: ;
    ecx = MEM32(esp + 4);
    eax = ecx + 0xA3;
    edx = MEM32(eax);
    if (TEST_Z(MEM8(edx + 0x28), 0x20)) goto loc_003BDAB6; /* je: equal / zero */

loc_003BDAB1: ;
    PUSH32(esp, 0x57);
    POP32(esp, eax);
    goto loc_003BDACF;

loc_003BDAB6: ;
    edx = MEM32(esp + 8);
    MEM8(edx + 0x40) = 0;
    eax = MEM32(eax);
    eax = MEM32(eax + 0xC);
    SET_LO8(eax, MEM8(eax));
    SET_LO8(eax, LO8(eax) + 2);
    MEM8(edx + 0x41) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDACF); sub_003C0B73(); /* call 0x003C0B73 */

loc_003BDACF: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDAD2
 * Original: 0x003BDAD2 - 0x003BDB09 (55 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDAD2(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDAD2: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    eax = 0x3BBD64;
    PUSH32(esp, edi);
    edi = eax;
    esi = 0x3BBD6C;
    SET_LO8(ebx, 0); /* xor self */
    /* cmp edi, esi - flags set for next jcc */
    MEM8(edx) = 0;
    if (CMP_AE(edi, esi)) goto loc_003BDAFD; /* jae: above or equal (unsigned >=) */

loc_003BDAEA: ;
    edi = MEM32(eax);
    if (TEST_Z(edi, edi)) goto loc_003BDAF6; /* je: equal / zero */

loc_003BDAF0: ;
    if (CMP_EQ(MEM8(edi), LO8(ecx))) goto loc_003BDB03; /* je: equal / zero */

loc_003BDAF4: ;
    SET_LO8(ebx, LO8(ebx) + 1);

loc_003BDAF6: ;
    eax = eax + 4;
    if (CMP_B(eax, esi)) { RECOMP_SLICE_POINT(); goto loc_003BDAEA; } /* jb: below (unsigned <) */

loc_003BDAFD: ;
    eax = 0; /* xor self */

loc_003BDAFF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

loc_003BDB03: ;
    MEM8(edx) = LO8(ebx);
    eax = MEM32(eax);
    { RECOMP_SLICE_POINT(); goto loc_003BDAFF; }

}

/**
 * sub_003BDB09
 * Original: 0x003BDB09 - 0x003BDB34 (43 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB09(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDB09: ;
    eax = 0x3BBD64;
    PUSH32(esp, esi);
    edx = eax;
    esi = 0x3BBD6C;
    if (CMP_AE(edx, esi)) goto loc_003BDB2C; /* jae: above or equal (unsigned >=) */

loc_003BDB1A: ;
    edx = MEM32(eax);
    if (TEST_Z(edx, edx)) goto loc_003BDB25; /* je: equal / zero */

loc_003BDB20: ;
    if (CMP_EQ(MEM32(edx + 4), ecx)) goto loc_003BDB30; /* je: equal / zero */

loc_003BDB25: ;
    eax = eax + 4;
    if (CMP_B(eax, esi)) { RECOMP_SLICE_POINT(); goto loc_003BDB1A; } /* jb: below (unsigned <) */

loc_003BDB2C: ;
    eax = 0; /* xor self */
    POP32(esp, esi);
    esp += 4; return; /* ret */

loc_003BDB30: ;
    eax = MEM32(eax);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BDB34
 * Original: 0x003BDB34 - 0x003BDB46 (18 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB34(void)
{

loc_003BDB34: ;
    eax = ecx;
    MEM8(eax) = 0xFF;
    MEM8(eax + 1) = 0x80;
    MEM8(eax + 2) = 0x80;
    MEM8(eax + 3) = 0x80;
    esp += 4; return; /* ret */

}

/**
 * sub_003BDB46
 * Original: 0x003BDB46 - 0x003BDB96 (80 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB46(void)
{

loc_003BDB46: ;
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
 * sub_003BDB96
 * Original: 0x003BDB96 - 0x003BDBC8 (50 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDB96(void)
{

loc_003BDB96: ;
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
 * sub_003BDBC8
 * Original: 0x003BDBC8 - 0x003BDBDF (23 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDBC8(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDBC8: ;
    SET_LO8(eax, MEM8(ecx + 1));
    if (CMP_EQ(LO8(eax), 0x80)) goto loc_003BDBDC; /* je: equal / zero */

loc_003BDBCF: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF308F8);
    esp += 4; return; /* ret */

loc_003BDBDC: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BDBDF
 * Original: 0x003BDBDF - 0x003BDBF6 (23 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDBDF(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDBDF: ;
    SET_LO8(eax, MEM8(ecx + 2));
    if (CMP_EQ(LO8(eax), 0x80)) goto loc_003BDBF3; /* je: equal / zero */

loc_003BDBE6: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF308F8);
    esp += 4; return; /* ret */

loc_003BDBF3: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BDBF6
 * Original: 0x003BDBF6 - 0x003BDC0D (23 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDBF6(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDBF6: ;
    SET_LO8(eax, MEM8(ecx + 3));
    if (CMP_EQ(LO8(eax), 0x80)) goto loc_003BDC0A; /* je: equal / zero */

loc_003BDBFD: ;
    eax = ZX8(LO8(eax));
    eax = eax << 5;
    eax = eax + MEM32(0xF308F8);
    esp += 4; return; /* ret */

loc_003BDC0A: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003BDC0D
 * Original: 0x003BDC0D - 0x003BDCD1 (196 bytes, 58 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDC0D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDC0D: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ecx;
    ecx = 0xF30818;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDC1C); sub_003BDB46(); /* call 0x003BDB46 */

loc_003BDC1C: ;
    esi = eax;
    ebx = 0; /* xor self */
    if (CMP_EQ(esi, ebx)) goto loc_003BDCCB; /* je: equal / zero */

loc_003BDC28: ;
    SET_LO8(eax, MEM8(esp + 0x10));
    MEM8(esi) = 0xFE;
    MEM8(esi + 4) = LO8(eax);
    MEM32(esi + 0x10) = ebx;
    eax = MEM32(edi + 0xC);
    PUSH32(esp, esi);
    ecx = edi;
    MEM32(esi + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDC43); sub_003BF934(); /* call 0x003BF934 */

loc_003BDC43: ;
    /* cmp MEM8(0xF30818), LO8(ebx) - flags set for next jcc */
    SET_LO8(eax, MEM8(esp + 0x14));
    if (CMP_EQ(MEM8(0xF30818), LO8(ebx))) goto loc_003BDC86; /* je: equal / zero */

loc_003BDC4F: ;
    edi = esi + 0x18;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(esi + 5) = LO8(eax);
    { uint32_t _icall_t = MEM32(0x3C4EF0); g_seh_ebp = ebp; PUSH32(esp, 0x3BDC5C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDC5C: ;
    MEM32(edi) = MEM32(edi) + 0xF4240;
    _cf = ((uint32_t)(MEM32(edi)) < (uint32_t)(0xF4240)); /* CF from add */
    MEM32(esi + 0x10) = ebx;
    MEM32(edi + 4) = MEM32(edi + 4) + ebx + _cf; /* adc */
    eax = MEM32(0xF30894);
    if (CMP_NE(eax, ebx)) goto loc_003BDC7C; /* jne: not equal / not zero */

loc_003BDC71: ;
    MEM32(0xF30894) = esi;
    goto loc_003BDCCB;

loc_003BDC79: ;
    eax = MEM32(eax + 0x10);

loc_003BDC7C: ;
    if (CMP_NE(MEM32(eax + 0x10), ebx)) { RECOMP_SLICE_POINT(); goto loc_003BDC79; } /* jne: not equal / not zero */

loc_003BDC81: ;
    MEM32(eax + 0x10) = esi;
    goto loc_003BDCCB;

loc_003BDC86: ;
    MEM8(esi) = 0xFD;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF3084C);
    MEM8(0xF3081A) = LO8(eax);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFF0BDC0u;
    PUSH32(esp, eax);
    MEM8(0xF30818) = 1;
    MEM8(0xF30819) = LO8(ebx);
    MEM32(0xF30898) = esi;
    MEM8(0xF3081B) = 0x80;
    MEM8(esi + 5) = LO8(ebx);
    PUSH32(esp, 0xF30868);
    MEM8(0xF30890) = LO8(ebx);
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDCCB); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDCCB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDCD1
 * Original: 0x003BDCD1 - 0x003BDCF3 (34 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDCD1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDCD1: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF3084C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFD050F80u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF30868);
    MEM8(0xF30890) = 1;
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDCF2); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDCF2: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BDCF3
 * Original: 0x003BDCF3 - 0x003BDD44 (81 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDCF3(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDCF3: ;
    /* cmp MEM32(esp + 4), 0 - flags set for next jcc */
    _rcc0 = (CMP_GE(MEM32(esp + 4), 0)); /* latched */
    MEM8(0xF3081B) = 0x81;
    if (_rcc0) goto loc_003BDD0E; /* jge: greater or equal (signed >=) */

loc_003BDD01: ;
    PUSH32(esp, MEM32(esp + 8));
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDD0C); sub_003BE181(); /* call 0x003BE181 */

loc_003BDD0C: ;
    goto loc_003BDD41;

loc_003BDD0E: ;
    if (CMP_NE(MEM32(esp + 4), 0x1000000)) goto loc_003BDD20; /* jne: not equal / not zero */

loc_003BDD18: ;
    eax = MEM32(esp + 8);
    MEM8(eax + 4) = MEM8(eax + 4) | 0x80;

loc_003BDD20: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF3084C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFFE7960u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF30868);
    MEM8(0xF30890) = 2;
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDD41); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDD41: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDD44
 * Original: 0x003BDD44 - 0x003BDD6F (43 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDD44(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDD44: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF3084C);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFFFFB1E0u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF30868);
    MEM8(0xF3081B) = 0x84;
    MEM8(0xF30890) = 3;
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDD6C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDD6C: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDD6F
 * Original: 0x003BDD6F - 0x003BDDA0 (49 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDD6F(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDD6F: ;
    PUSH32(esp, ebx);
    edx = 0; /* xor self */
    SET_LO8(ebx, 0); /* xor self */
    edx++;
    PUSH32(esp, esi);
    SET_LO8(eax, LO8(edx));

loc_003BDD78: ;
    esi = ZX8(LO8(ebx));
    if (TEST_Z(MEM32(ecx + esi * 4 + 8), edx)) goto loc_003BDD92; /* je: equal / zero */

loc_003BDD81: ;
    edx = edx << 1;
    if ((edx != 0)) goto loc_003BDD8A; /* jne: not equal / not zero */

loc_003BDD85: ;
    edx = 0; /* xor self */
    SET_LO8(ebx, LO8(ebx) + 1);
    edx++;

loc_003BDD8A: ;
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_B(LO8(eax), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003BDD78; } /* jb: below (unsigned <) */

loc_003BDD90: ;
    goto loc_003BDD9B;

loc_003BDD92: ;
    esi = ZX8(LO8(ebx));
    ecx = ecx + esi * 4 + 8;
    MEM32(ecx) = MEM32(ecx) | edx;

loc_003BDD9B: ;
    POP32(esp, esi);
    SET_LO8(eax, LO8(eax) & 0x7F);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BDDA0
 * Original: 0x003BDDA0 - 0x003BDDD4 (52 bytes, 26 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDDA0(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BDDA0: ;
    PUSH32(esp, ebx);
    SET_LO8(ebx, 0); /* xor self */
    SET_LO8(edx, LO8(edx) - 1);
    /* cmp LO8(edx), 0x1F - flags set for next jcc */
    PUSH32(esp, esi);
    if (CMP_BE(LO8(edx), 0x1F)) goto loc_003BDDBF; /* jbe: below or equal (unsigned <=) */

loc_003BDDAB: ;
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) - 0x20);
    SET_LO8(eax, LO8(eax) >> 5);
    SET_LO8(eax, LO8(eax) + 1);
    eax = ZX8(LO8(eax));
    SET_LO8(ebx, LO8(eax));

loc_003BDDB9: ;
    SET_LO8(edx, LO8(edx) + 0xE0);
    eax--;
    if ((eax != 0)) { RECOMP_SLICE_POINT(); goto loc_003BDDB9; } /* jne: not equal / not zero */

loc_003BDDBF: ;
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
 * sub_003BDDD4
 * Original: 0x003BDDD4 - 0x003BDDDB (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDDD4(void)
{

loc_003BDDD4: ;
    MEM32(0xF308FC) = MEM32(0xF308FC) + 1;
    esp += 4; return; /* ret */

}

/**
 * sub_003BDDDB
 * Original: 0x003BDDDB - 0x003BDDE2 (7 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDDDB(void)
{

loc_003BDDDB: ;
    MEM32(0xF308FC) = MEM32(0xF308FC) - 1;
    esp += 4; return; /* ret */

}

/**
 * sub_003BDDE2
 * Original: 0x003BDDE2 - 0x003BDE0B (41 bytes, 14 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDDE2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDDE2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDDEB); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDDEB: ;
    if (CMP_NE(MEM32(0xF308FC), esi)) goto loc_003BDDFC; /* jne: not equal / not zero */

loc_003BDDF3: ;
    if (CMP_EQ(MEM8(0xF30818), 0)) goto loc_003BDDFF; /* je: equal / zero */

loc_003BDDFC: ;
    esi = 0; /* xor self */
    esi++;

loc_003BDDFF: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BDE07); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDE07: ;
    eax = esi;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BDE0B
 * Original: 0x003BDE0B - 0x003BDE20 (21 bytes, 6 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE0B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDE0B: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(eax + -20);
    PUSH32(esp, 5);
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDE1D); sub_003BDC0D(); /* call 0x003BDC0D */

loc_003BDE1D: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDE20
 * Original: 0x003BDE20 - 0x003BDE82 (98 bytes, 39 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE20(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDE20: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(0xF30898);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0xC);
    ebx = 0; /* xor self */
    edi = edi + 0x18;
    if (CMP_EQ(MEM8(0xF30819), LO8(ebx))) goto loc_003BDE42; /* je: equal / zero */

loc_003BDE39: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDE40); sub_003BE181(); /* call 0x003BE181 */

loc_003BDE40: ;
    goto loc_003BDE7E;

loc_003BDE42: ;
    ecx = esi;
    MEM8(0xF3081B) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDE4F); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BDE4F: ;
    if (CMP_NE(MEM8(eax), LO8(ebx))) goto loc_003BDE6A; /* jne: not equal / not zero */

loc_003BDE53: ;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 4));
    PUSH32(esp, esi);
    PUSH32(esp, 0x3BDCF3);
    eax = eax & 0x7F;
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDE68); sub_003C1F89(); /* call 0x003C1F89 */

loc_003BDE68: ;
    goto loc_003BDE7E;

loc_003BDE6A: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 4));
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ecx = ecx & 0xFFFFFF7Fu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDE7E); sub_003C157F(); /* call 0x003C157F */

loc_003BDE7E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BDE82
 * Original: 0x003BDE82 - 0x003BDE87 (5 bytes, 1 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE82(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDE82: ;
    g_seh_ebp = ebp; sub_003BDCF3(); return; /* tail jmp 0x003BDCF3 */

}

/**
 * sub_003BDE87
 * Original: 0x003BDE87 - 0x003BDEFD (118 bytes, 47 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDE87(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDE87: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    SET_LO8(eax, MEM8(esi + 7));
    /* cmp LO8(eax), 0xFF - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_EQ(LO8(eax), 0xFF)) goto loc_003BDEAE; /* je: equal / zero */

loc_003BDE93: ;
    ecx = MEM32(esi + 0x10);
    ecx = MEM32(ecx + 0x14);
    eax = ZX8(LO8(eax));
    eax = MEM32(ecx + eax * 4);
    if (TEST_Z(eax, eax)) goto loc_003BDEAE; /* je: equal / zero */

loc_003BDEA3: ;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(esi + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEAE); sub_003BD290(); /* call 0x003BD290 */

loc_003BDEAE: ;
    /* cmp MEM8(esi), 5 - flags set for next jcc */
    ebx = 0xF30818;
    if (CMP_NE(MEM8(esi), 5)) goto loc_003BDEE2; /* jne: not equal / not zero */

loc_003BDEB8: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEBF); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BDEBF: ;
    edi = eax;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEC9); sub_003BF97C(); /* call 0x003BF97C */

loc_003BDEC9: ;
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003BDEF1; /* jne: not equal / not zero */

loc_003BDECD: ;
    SET_LO8(edx, MEM8(edi + 5));
    ecx = MEM32(edi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDED8); sub_003BDDA0(); /* call 0x003BDDA0 */

loc_003BDED8: ;
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEE0); sub_003BDB96(); /* call 0x003BDB96 */

loc_003BDEE0: ;
    goto loc_003BDEF1;

loc_003BDEE2: ;
    SET_LO8(edx, MEM8(esi + 5));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BDEF1; /* je: equal / zero */

loc_003BDEE9: ;
    ecx = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEF1); sub_003BDDA0(); /* call 0x003BDDA0 */

loc_003BDEF1: ;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDEF9); sub_003BDB96(); /* call 0x003BDB96 */

loc_003BDEF9: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BDEFD
 * Original: 0x003BDEFD - 0x003BDF4F (82 bytes, 34 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDEFD(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDEFD: ;
    ecx = MEM32(esp + 4);
    /* cmp MEM8(ecx), 4 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(ecx), 4)); /* latched */
    PUSH32(esp, esi);
    if (_rcc0) goto loc_003BDF39; /* jne: not equal / not zero */

loc_003BDF07: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDF0C); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BDF0C: ;
    esi = eax;
    if (TEST_Z(esi, esi)) goto loc_003BDF4B; /* je: equal / zero */

loc_003BDF12: ;
    PUSH32(esp, edi);

loc_003BDF13: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDF1A); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BDF1A: ;
    edi = eax;
    eax = MEM32(esi + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BDF29; /* je: equal / zero */

loc_003BDF23: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 0xC); g_seh_ebp = ebp; PUSH32(esp, 0x3BDF27); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDF27: ;
    goto loc_003BDF30;

loc_003BDF29: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDF30); sub_003BDE87(); /* call 0x003BDE87 */

loc_003BDF30: ;
    /* test edi, edi - flags set for next jcc */
    esi = edi;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003BDF13; } /* jne: not equal / not zero */

loc_003BDF36: ;
    POP32(esp, edi);
    goto loc_003BDF4B;

loc_003BDF39: ;
    eax = MEM32(ecx + 0x10);
    if (TEST_Z(eax, eax)) goto loc_003BDF46; /* je: equal / zero */

loc_003BDF40: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    { uint32_t _icall_t = MEM32(eax + 0xC); g_seh_ebp = ebp; PUSH32(esp, 0x3BDF44); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDF44: ;
    goto loc_003BDF4B;

loc_003BDF46: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDF4B); sub_003BDE87(); /* call 0x003BDE87 */

loc_003BDF4B: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BDF4F
 * Original: 0x003BDF4F - 0x003BDFFE (175 bytes, 50 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDF4F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BDF4F: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    if (CMP_EQ(MEM8(0xF30819), LO8(ebx))) goto loc_003BDF67; /* je: equal / zero */

loc_003BDF5F: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDF67); sub_003BDEFD(); /* call 0x003BDEFD */

loc_003BDF67: ;
    eax = MEM32(0xF30894);
    /* cmp eax, ebx - flags set for next jcc */
    MEM8(0xF30819) = LO8(ebx);
    if (CMP_NE(eax, ebx)) goto loc_003BDF84; /* jne: not equal / not zero */

loc_003BDF76: ;
    MEM32(0xF30898) = ebx;
    MEM8(0xF30818) = LO8(ebx);
    goto loc_003BDFF9;

loc_003BDF84: ;
    MEM32(0xF30898) = eax;
    ecx = MEM32(eax + 0x10);
    MEM32(0xF30894) = ecx;
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(0xF3081A) = LO8(ecx);
    MEM8(0xF3081B) = 0x80;
    MEM8(eax) = 0xFD;
    eax = MEM32(0xF30898);
    MEM32(eax + 0x10) = ebx;
    eax = MEM32(0xF30898);
    MEM8(eax + 5) = LO8(ebx);
    eax = ebp + -8;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4EF0); g_seh_ebp = ebp; PUSH32(esp, 0x3BDFBF); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDFBF: ;
    eax = MEM32(0xF30898);
    ecx = MEM32(ebp + -4);
    if (CMP_L(ecx, MEM32(eax + 0x1C))) goto loc_003BDFDD; /* jl: less (signed <) */

loc_003BDFCC: ;
    if (CMP_G(ecx, MEM32(eax + 0x1C))) goto loc_003BDFD6; /* jg: greater (signed >) */

loc_003BDFCE: ;
    ecx = MEM32(ebp + -8);
    if (CMP_BE(ecx, MEM32(eax + 0x18))) goto loc_003BDFDD; /* jbe: below or equal (unsigned <=) */

loc_003BDFD6: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BDFDB); sub_003BDE20(); /* call 0x003BDE20 */

loc_003BDFDB: ;
    goto loc_003BDFF9;

loc_003BDFDD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF3084C);
    MEM8(0xF30890) = LO8(ebx);
    PUSH32(esp, MEM32(eax + 0x1C));
    PUSH32(esp, MEM32(eax + 0x18));
    PUSH32(esp, 0xF30868);
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BDFF9); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BDFF9: ;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BDFFE
 * Original: 0x003BDFFE - 0x003BE075 (119 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BDFFE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BDFFE: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(esp + 0xC));
    edi = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE00B); sub_003BF903(); /* call 0x003BF903 */

loc_003BE00B: ;
    esi = eax;
    if (TEST_Z(esi, esi)) goto loc_003BE070; /* je: equal / zero */

loc_003BE011: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE019); sub_003BF97C(); /* call 0x003BF97C */

loc_003BE019: ;
    if (CMP_NE(MEM8(esi), 0xFE)) goto loc_003BE050; /* jne: not equal / not zero */

loc_003BE01E: ;
    eax = MEM32(0xF30894);
    if (CMP_NE(eax, esi)) goto loc_003BE034; /* jne: not equal / not zero */

loc_003BE027: ;
    eax = MEM32(esi + 0x10);
    MEM32(0xF30894) = eax;
    goto loc_003BE03F;

loc_003BE031: ;
    eax = MEM32(eax + 0x10);

loc_003BE034: ;
    if (CMP_NE(esi, MEM32(eax + 0x10))) { RECOMP_SLICE_POINT(); goto loc_003BE031; } /* jne: not equal / not zero */

loc_003BE039: ;
    ecx = MEM32(esi + 0x10);
    MEM32(eax + 0x10) = ecx;

loc_003BE03F: ;
    MEM32(esi + 0x10) = MEM32(esi + 0x10) & 0;
    PUSH32(esp, esi);
    ecx = 0xF30818;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE04E); sub_003BDB96(); /* call 0x003BDB96 */

loc_003BE04E: ;
    goto loc_003BE070;

loc_003BE050: ;
    if (CMP_EQ(MEM8(0xF30818), 0)) goto loc_003BE06A; /* je: equal / zero */

loc_003BE059: ;
    if (CMP_NE(MEM32(0xF30898), esi)) goto loc_003BE06A; /* jne: not equal / not zero */

loc_003BE061: ;
    MEM8(0xF30819) = 1;
    goto loc_003BE070;

loc_003BE06A: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE070); sub_003BDEFD(); /* call 0x003BDEFD */

loc_003BE070: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE075
 * Original: 0x003BE075 - 0x003BE0BA (69 bytes, 30 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE075(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE075: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    /* cmp MEM8(ecx), 5 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(ecx), 5)); /* latched */
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003BE089; /* jne: not equal / not zero */

loc_003BE080: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE085); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BE085: ;
    esi = eax;
    goto loc_003BE08B;

loc_003BE089: ;
    esi = ecx;

loc_003BE08B: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE092); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BE092: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003BE0B6; /* je: equal / zero */

loc_003BE098: ;
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0x7F);
    MEM8(ebp + -4) = LO8(eax);
    PUSH32(esp, MEM32(ebp + -4));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE0AA); sub_003BDFFE(); /* call 0x003BDFFE */

loc_003BE0AA: ;
    PUSH32(esp, 5);
    PUSH32(esp, MEM32(ebp + -4));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE0B6); sub_003BDC0D(); /* call 0x003BDC0D */

loc_003BE0B6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE0BA
 * Original: 0x003BE0BA - 0x003BE13B (129 bytes, 49 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE0BA(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE0BA: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    SET_LO8(ebx, 0); /* xor self */
    edi = 0; /* xor self */
    /* cmp MEM8(0xF30819), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(0xF30819), 0)); /* latched */
    esi = ecx;
    MEM8(ebp + -4) = LO8(ebx);
    MEM8(0xF3081B) = 0xA;
    if (_rcc0) goto loc_003BE0FC; /* jne: not equal / not zero */

loc_003BE0DA: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE0DF); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BE0DF: ;
    edi = eax;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE0E9); sub_003BF97C(); /* call 0x003BF97C */

loc_003BE0E9: ;
    SET_LO8(eax, MEM8(0xF3081A));
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BE0FC; /* je: equal / zero */

loc_003BE0F2: ;
    SET_LO8(ebx, LO8(eax));
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0x7F);
    MEM8(ebp + -4) = LO8(eax);

loc_003BE0FC: ;
    SET_LO8(edx, MEM8(esi + 5));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BE10B; /* je: equal / zero */

loc_003BE103: ;
    ecx = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE10B); sub_003BDDA0(); /* call 0x003BDDA0 */

loc_003BE10B: ;
    PUSH32(esp, esi);
    ecx = 0xF30818;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE116); sub_003BDB96(); /* call 0x003BDB96 */

loc_003BE116: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003BE127; /* je: equal / zero */

loc_003BE11A: ;
    SET_LO8(ebx, LO8(ebx) - 1);
    ecx = edi;
    PUSH32(esp, ebx);
    PUSH32(esp, MEM32(ebp + -4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE127); sub_003BDC0D(); /* call 0x003BDC0D */

loc_003BE127: ;
    PUSH32(esp, esi);
    PUSH32(esp, 0);
    MEM8(0xF30819) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE136); sub_003BDF4F(); /* call 0x003BDF4F */

loc_003BE136: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE13B
 * Original: 0x003BE13B - 0x003BE14E (19 bytes, 5 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE13B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE13B: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, MEM32(esp + 8));
    ecx = MEM32(eax + -20);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE14B); sub_003BDFFE(); /* call 0x003BDFFE */

loc_003BE14B: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE14E
 * Original: 0x003BE14E - 0x003BE181 (51 bytes, 13 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE14E(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE14E: ;
    ecx = MEM32(esp + 8);
    eax = 0; /* xor self */
    /* cmp MEM32(esp + 4), eax - flags set for next jcc */
    _rcc0 = (CMP_GE(MEM32(esp + 4), eax)); /* latched */
    MEM8(0xF3081B) = 9;
    if (_rcc0) goto loc_003BE16C; /* jge: greater or equal (signed >=) */

loc_003BE161: ;
    if (CMP_NE(MEM8(0xF30819), LO8(eax))) goto loc_003BE174; /* jne: not equal / not zero */

loc_003BE169: ;
    MEM8(ecx + 5) = LO8(eax);

loc_003BE16C: ;
    if (CMP_EQ(MEM8(0xF30819), LO8(eax))) goto loc_003BE179; /* je: equal / zero */

loc_003BE174: ;
    MEM8(0xF3081A) = LO8(eax);

loc_003BE179: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE17E); sub_003BE0BA(); /* call 0x003BE0BA */

loc_003BE17E: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE181
 * Original: 0x003BE181 - 0x003BE1EE (109 bytes, 36 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE181(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE181: ;
    /* cmp MEM8(0xF30819), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(0xF30819), 0)); /* latched */
    PUSH32(esp, esi);
    MEM8(0xF3081B) = 8;
    if (_rcc0) goto loc_003BE1DA; /* jne: not equal / not zero */

loc_003BE192: ;
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE19D); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BE19D: ;
    if (CMP_NE(MEM8(eax), 0)) goto loc_003BE1C3; /* jne: not equal / not zero */

loc_003BE1A2: ;
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(esi + 4));
    eax = eax & 0x7F;
    PUSH32(esp, eax);
    eax = MEM32(esi + 0xC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE1B7); sub_003C1FD6(); /* call 0x003C1FD6 */

loc_003BE1B7: ;
    PUSH32(esp, esi);
    PUSH32(esp, 0);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE1C1); sub_003BE14E(); /* call 0x003BE14E */

loc_003BE1C1: ;
    goto loc_003BE1EA;

loc_003BE1C3: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 4));
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    ecx = ecx & 0xFFFFFF7Fu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE1D8); sub_003C157F(); /* call 0x003C157F */

loc_003BE1D8: ;
    goto loc_003BE1EA;

loc_003BE1DA: ;
    ecx = MEM32(esp + 0xC);
    MEM8(0xF3081A) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE1EA); sub_003BE0BA(); /* call 0x003BE0BA */

loc_003BE1EA: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE1EE
 * Original: 0x003BE1EE - 0x003BE253 (101 bytes, 22 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE1EE(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE1EE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30868);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BE1F9); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE1F9: ;
    eax = MEM32(esp + 4);
    MEM8(0xF3081B) = 3;
    if (CMP_L(MEM32(eax + 4), 0)) goto loc_003BE21D; /* jl: less (signed <) */

loc_003BE20A: ;
    /* cmp MEM8(0xF30819), 0 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(0xF30819), 0)); /* latched */
    MEM32(0xF30824) = 0x3BDD44;
    if (_rcc0) goto loc_003BE227; /* je: equal / zero */

loc_003BE21D: ;
    MEM32(0xF30824) = 0x3BE181;

loc_003BE227: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    MEM8(0xF3081C) = 0x1C;
    MEM8(0xF3081D) = 0x43;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, 0xF3081C);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE24B); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE24B: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE253
 * Original: 0x003BE253 - 0x003BE3DF (396 bytes, 126 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE253(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE253: ;
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
    _rcc0 = (CMP_GE(MEM32(ebp + 8), ebx)); /* latched */
    PUSH32(esp, edi);
    MEM32(ebp + -4) = ecx;
    MEM8(0xF3081B) = 7;
    if (_rcc0) goto loc_003BE283; /* jge: greater or equal (signed >=) */

loc_003BE272: ;
    if (CMP_NE(MEM32(ebp + 8), 0x80000400u)) goto loc_003BE27E; /* jne: not equal / not zero */

loc_003BE27B: ;
    MEM32(ebp + -4) = ebx;

loc_003BE27E: ;
    MEM32(esi + 0x10) = ebx;
    goto loc_003BE2A4;

loc_003BE283: ;
    SET_LO8(eax, MEM8(esi + 7));
    if (CMP_EQ(LO8(eax), 0xFF)) goto loc_003BE2A4; /* je: equal / zero */

loc_003BE28A: ;
    edx = MEM32(esi + 0x10);
    edx = MEM32(edx + 0x14);
    eax = ZX8(LO8(eax));
    eax = MEM32(edx + eax * 4);
    if (CMP_EQ(eax, ebx)) goto loc_003BE2A4; /* je: equal / zero */

loc_003BE29A: ;
    PUSH32(esp, ecx);
    PUSH32(esp, MEM32(esi + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE2A4); sub_003BD290(); /* call 0x003BD290 */

loc_003BE2A4: ;
    SET_LO8(eax, MEM8(esi));
    if (CMP_EQ(LO8(eax), 2)) goto loc_003BE3B9; /* je: equal / zero */

loc_003BE2AE: ;
    if (CMP_EQ(LO8(eax), 1)) goto loc_003BE3B9; /* je: equal / zero */

loc_003BE2B6: ;
    /* cmp LO8(eax), 5 - flags set for next jcc */
    ecx = MEM32(esi + 8);
    edi = esi;
    MEM32(ebp + -12) = ecx;
    MEM32(esi + 8) = ebx;
    MEM32(ebp + -8) = 0x3BDF4F;
    if (CMP_NE(LO8(eax), 5)) goto loc_003BE36A; /* jne: not equal / not zero */

loc_003BE2D0: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE2D7); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BE2D7: ;
    ecx = esi;
    ebx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE2E0); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BE2E0: ;
    /* cmp MEM8(0xF30819), 0 - flags set for next jcc */
    edi = eax;
    if (CMP_NE(MEM8(0xF30819), 0)) goto loc_003BE382; /* jne: not equal / not zero */

loc_003BE2EF: ;
    if (CMP_NE(MEM32(esi + 0x10), 0)) goto loc_003BE324; /* jne: not equal / not zero */

loc_003BE2F5: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE2FD); sub_003BF97C(); /* call 0x003BF97C */

loc_003BE2FD: ;
    PUSH32(esp, esi);
    ecx = 0xF30818;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE308); sub_003BDB96(); /* call 0x003BDB96 */

loc_003BE308: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE30F); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BE30F: ;
    if (TEST_NZ(eax, eax)) goto loc_003BE324; /* jne: not equal / not zero */

loc_003BE313: ;
    PUSH32(esp, edi);
    MEM8(0xF3081A) = LO8(eax);
    PUSH32(esp, eax);

loc_003BE31A: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE31F); sub_003BE181(); /* call 0x003BE181 */

loc_003BE31F: ;
    goto loc_003BE3D8;

loc_003BE324: ;
    if (TEST_Z(ebx, ebx)) goto loc_003BE382; /* je: equal / zero */

loc_003BE328: ;
    eax = MEM32(0xF308F4);

loc_003BE32D: ;
    ecx = ZX8(MEM8(eax));
    eax = eax + ecx;
    if (CMP_NE(MEM8(eax + 1), 4)) { RECOMP_SLICE_POINT(); goto loc_003BE32D; } /* jne: not equal / not zero */

loc_003BE338: ;
    MEM32(0xF308F4) = eax;
    SET_LO8(eax, MEM8(eax + 2));
    MEM8(ebx + 2) = LO8(eax);
    eax = MEM32(0xF308F4);
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(ebp + 9) = LO8(ecx);
    SET_LO8(ecx, MEM8(eax + 6));
    SET_LO8(eax, MEM8(eax + 7));
    MEM8(ebp + 0xA) = LO8(ecx);
    MEM8(ebp + 0xB) = LO8(eax);
    MEM8(ebp + 8) = 0x82;
    PUSH32(esp, MEM32(ebp + 8));
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE368); sub_003BE3DF(); /* call 0x003BE3DF */

loc_003BE368: ;
    goto loc_003BE3D8;

loc_003BE36A: ;
    if (CMP_GE(MEM32(ebp + 8), ebx)) goto loc_003BE382; /* jge: greater or equal (signed >=) */

loc_003BE36F: ;
    if (CMP_NE(MEM32(ebp + -4), ebx)) goto loc_003BE37B; /* jne: not equal / not zero */

loc_003BE374: ;
    MEM8(0xF3081A) = 0;

loc_003BE37B: ;
    MEM32(ebp + -8) = 0x3BE181;

loc_003BE382: ;
    eax = MEM32(ebp + -8);
    MEM32(0xF30824) = eax;
    eax = MEM32(ebp + -12);
    MEM32(0xF3082C) = eax;
    MEM8(0xF3081C) = 0x1C;
    MEM8(0xF3081D) = 0x43;
    MEM32(0xF30828) = edi;
    eax = MEM32(edi + 0xC);
    PUSH32(esp, 0xF3081C);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE3B7); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE3B7: ;
    goto loc_003BE3D8;

loc_003BE3B9: ;
    if (CMP_GE(MEM32(ebp + 8), ebx)) goto loc_003BE3D1; /* jge: greater or equal (signed >=) */

loc_003BE3BE: ;
    if (CMP_NE(MEM32(ebp + -4), ebx)) goto loc_003BE3CA; /* jne: not equal / not zero */

loc_003BE3C3: ;
    MEM8(0xF3081A) = 0;

loc_003BE3CA: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    { RECOMP_SLICE_POINT(); goto loc_003BE31A; }

loc_003BE3D1: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE3D8); sub_003BDF4F(); /* call 0x003BDF4F */

loc_003BE3D8: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE3DF
 * Original: 0x003BE3DF - 0x003BE413 (52 bytes, 18 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE3DF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE3DF: ;
    PUSH32(esp, esi);
    esi = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE3E7); sub_003BFB79(); /* call 0x003BFB79 */

loc_003BE3E7: ;
    if (CMP_EQ(MEM32(esi + 0x14), 0x20)) goto loc_003BE403; /* je: equal / zero */

loc_003BE3ED: ;
    PUSH32(esp, MEM32(esp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE3F6); sub_003BEA44(); /* call 0x003BEA44 */

loc_003BE3F6: ;
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x10) = eax;
    if (TEST_Z(eax, eax)) goto loc_003BE403; /* je: equal / zero */

loc_003BE3FD: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(eax + 8); g_seh_ebp = ebp; PUSH32(esp, 0x3BE401); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE401: ;
    goto loc_003BE40F;

loc_003BE403: ;
    ecx = esi;
    PUSH32(esp, 0x80000400u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE40F); sub_003BE253(); /* call 0x003BE253 */

loc_003BE40F: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE413
 * Original: 0x003BE413 - 0x003BE4EE (219 bytes, 51 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE413(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE413: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0xF30868);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BE41F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE41F: ;
    edx = MEM32(esp + 8);
    ebx = 0; /* xor self */
    MEM8(0xF3081B) = 2;
    if (CMP_L(MEM32(edx + 4), ebx)) goto loc_003BE4E0; /* jl: less (signed <) */

loc_003BE435: ;
    if (CMP_NE(MEM8(0xF30819), LO8(ebx))) goto loc_003BE4E0; /* jne: not equal / not zero */

loc_003BE441: ;
    if (CMP_B(MEM32(edx + 0x14), 8)) goto loc_003BE4D9; /* jb: below (unsigned <) */

loc_003BE44B: ;
    SET_LO8(eax, MEM8(0xF308A3));
    if (CMP_A(LO8(eax), 0x40)) goto loc_003BE4D9; /* ja: above (unsigned >) */

loc_003BE458: ;
    if (CMP_NE(MEM8(0xF3089D), 1)) goto loc_003BE4D9; /* jne: not equal / not zero */

loc_003BE461: ;
    SET_LO8(ecx, MEM8(0xF3089C));
    if (CMP_EQ(LO8(ecx), 8)) goto loc_003BE471; /* je: equal / zero */

loc_003BE46C: ;
    if (CMP_NE(LO8(ecx), 0x12)) goto loc_003BE4D9; /* jne: not equal / not zero */

loc_003BE471: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = MEM32(esi + 0xC);
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE481); sub_003BDD6F(); /* call 0x003BDD6F */

loc_003BE481: ;
    MEM8(esi + 5) = LO8(eax);
    MEM32(0xF30824) = 0x3BE1EE;
    MEM32(0xF30834) = ebx;
    MEM32(0xF30830) = ebx;
    MEM8(0xF30844) = LO8(ebx);
    MEM8(0xF30845) = 5;
    SET_LO16(eax, ZX8(MEM8(esi + 5)));
    MEM16(0xF30846) = LO16(eax);
    MEM16(0xF30848) = LO16(ebx);
    MEM16(0xF3084A) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE4C5); sub_003BDCD1(); /* call 0x003BDCD1 */

loc_003BE4C5: ;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, 0xF3081C);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE4D6); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE4D6: ;
    POP32(esp, esi);
    goto loc_003BE4EA;

loc_003BE4D9: ;
    MEM32(edx + 4) = 0x80000600u;

loc_003BE4E0: ;
    PUSH32(esp, MEM32(esp + 0xC));
    PUSH32(esp, edx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE4EA); sub_003BE1EE(); /* call 0x003BE1EE */

loc_003BE4EA: ;
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE4EE
 * Original: 0x003BE4EE - 0x003BE635 (327 bytes, 96 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE4EE(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE4EE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, 0xF30868);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BE4FE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE4FE: ;
    ecx = MEM32(ebp + 8);
    ebx = 0; /* xor self */
    MEM8(0xF3081B) = 6;
    if (CMP_L(MEM32(ecx + 4), ebx)) goto loc_003BE626; /* jl: less (signed <) */

loc_003BE513: ;
    if (CMP_NE(MEM8(0xF30819), LO8(ebx))) goto loc_003BE626; /* jne: not equal / not zero */

loc_003BE51F: ;
    esi = MEM32(ebp + 0xC);
    MEM32(esi + 0x18) = ebx;
    eax = 0xF308A4;

loc_003BE52A: ;
    edx = ZX8(MEM8(eax));
    eax = eax + edx;
    if (CMP_AE(eax, 0xF308F4)) goto loc_003BE615; /* jae: above or equal (unsigned >=) */

loc_003BE53A: ;
    if (CMP_EQ(MEM8(eax), 0)) goto loc_003BE615; /* je: equal / zero */

loc_003BE543: ;
    if (CMP_NE(MEM8(eax + 1), 4)) { RECOMP_SLICE_POINT(); goto loc_003BE52A; } /* jne: not equal / not zero */

loc_003BE549: ;
    /* cmp MEM8(0xF308A8), 1 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(0xF308A8), 1)); /* latched */
    MEM32(0xF308F4) = eax;
    if (_rcc0) goto loc_003BE5E0; /* je: equal / zero */

loc_003BE55B: ;
    if (CMP_EQ(MEM8(0xF30893), 0)) goto loc_003BE5E0; /* je: equal / zero */

loc_003BE564: ;
    MEM8(esi) = 4;
    MEM8(esi + 2) = 0x80;
    if (CMP_BE(MEM8(0xF308A8), 0)) goto loc_003BE5D1; /* jbe: below or equal (unsigned <=) */

loc_003BE574: ;
    eax = ZX8(MEM8(0xF30893));
    if (CMP_BE(eax, ebx)) goto loc_003BE5D1; /* jbe: below or equal (unsigned <=) */

loc_003BE57F: ;
    ecx = 0xF30818;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE589); sub_003BDB46(); /* call 0x003BDB46 */

loc_003BE589: ;
    if (TEST_Z(eax, eax)) goto loc_003BE5D1; /* je: equal / zero */

loc_003BE58D: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE5C5); sub_003BF934(); /* call 0x003BF934 */

loc_003BE5C5: ;
    eax = ZX8(MEM8(0xF308A8));
    ebx++;
    if (CMP_B(ebx, eax)) { RECOMP_SLICE_POINT(); goto loc_003BE574; } /* jb: below (unsigned <) */

loc_003BE5D1: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE5DC); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BE5DC: ;
    esi = eax;
    goto loc_003BE5E3;

loc_003BE5E0: ;
    MEM8(esi) = 3;

loc_003BE5E3: ;
    eax = MEM32(0xF308F4);
    SET_LO8(eax, MEM8(eax + 2));
    MEM8(esi + 2) = LO8(eax);
    eax = MEM32(0xF308F4);
    SET_LO8(ecx, MEM8(eax + 5));
    MEM8(ebp + 0xD) = LO8(ecx);
    SET_LO8(ecx, MEM8(eax + 6));
    SET_LO8(eax, MEM8(eax + 7));
    MEM8(ebp + 0xE) = LO8(ecx);
    MEM8(ebp + 0xF) = LO8(eax);
    MEM8(ebp + 0xC) = 0x82;
    PUSH32(esp, MEM32(ebp + 0xC));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE613); sub_003BE3DF(); /* call 0x003BE3DF */

loc_003BE613: ;
    goto loc_003BE62F;

loc_003BE615: ;
    MEM8(0xF3081A) = 0;
    MEM32(ecx + 4) = 0x80000400u;
    PUSH32(esp, esi);
    goto loc_003BE629;

loc_003BE626: ;
    PUSH32(esp, MEM32(ebp + 0xC));

loc_003BE629: ;
    PUSH32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE62F); sub_003BE1EE(); /* call 0x003BE1EE */

loc_003BE62F: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BE635
 * Original: 0x003BE635 - 0x003BE735 (256 bytes, 60 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE635(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE635: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    edi = MEM32(esi + 0xC);
    ebx = 0; /* xor self */
    edi = edi + 0x18;
    /* cmp MEM8(0xF30819), LO8(ebx) - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(0xF30819), LO8(ebx))); /* latched */
    MEM8(0xF3081B) = 1;
    if (_rcc0) goto loc_003BE65D; /* je: equal / zero */

loc_003BE651: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE658); sub_003BE181(); /* call 0x003BE181 */

loc_003BE658: ;
    goto loc_003BE731;

loc_003BE65D: ;
    MEM32(esi + 0x18) = ebx;
    PUSH32(esp, ebp);
    MEM8(0xF3081C) = 0x20;
    MEM8(0xF3081D) = 2;
    MEM32(0xF30824) = ebx;
    MEM8(0xF30831) = LO8(ebx);
    MEM8(0xF30832) = LO8(ebx);
    MEM8(0xF30833) = LO8(ebx);
    MEM16(0xF30838) = 8;
    SET_LO8(eax, MEM8(esi + 4));
    ebp = 0xF3081C;
    PUSH32(esp, ebp);
    SET_LO8(eax, LO8(eax) >> 7);
    PUSH32(esp, edi);
    MEM8(0xF3083A) = LO8(eax);
    MEM8(0xF30830) = LO8(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE6AD); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE6AD: ;
    eax = MEM32(0xF3082C);
    MEM32(esi + 8) = eax;
    MEM8(0xF3081C) = 0x30;
    MEM8(0xF3081D) = 0x40;
    MEM32(0xF30824) = 0x3BE413;
    MEM32(0xF30828) = esi;
    eax = MEM32(esi + 8);
    PUSH32(esp, 8);
    MEM32(0xF3082C) = eax;
    POP32(esp, eax);
    MEM32(0xF30834) = 0xF3089C;
    MEM32(0xF30830) = eax;
    MEM8(0xF30838) = 2;
    MEM8(0xF30839) = LO8(ebx);
    MEM8(0xF3083A) = LO8(ebx);
    MEM8(0xF30844) = 0x80;
    MEM8(0xF30845) = 6;
    MEM16(0xF30846) = 0x100;
    MEM16(0xF30848) = LO16(ebx);
    MEM16(0xF3084A) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE729); sub_003BDCD1(); /* call 0x003BDCD1 */

loc_003BE729: ;
    PUSH32(esp, ebp);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE730); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE730: ;
    POP32(esp, ebp);

loc_003BE731: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003BE735
 * Original: 0x003BE735 - 0x003BE7EE (185 bytes, 43 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE735(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE735: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, 0xF30868);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BE743); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE743: ;
    eax = MEM32(ebp + 8);
    edx = 0; /* xor self */
    MEM8(0xF3081B) = 5;
    if (CMP_L(MEM32(eax + 4), edx)) goto loc_003BE776; /* jl: less (signed <) */

loc_003BE754: ;
    if (CMP_NE(MEM8(0xF30819), LO8(edx))) goto loc_003BE776; /* jne: not equal / not zero */

loc_003BE75C: ;
    SET_LO16(ecx, MEM16(0xF308A6));
    if (CMP_BE(LO16(ecx), 0x50)) goto loc_003BE783; /* jbe: below or equal (unsigned <=) */

loc_003BE769: ;
    MEM8(0xF3081A) = LO8(edx);
    MEM32(eax + 4) = 0x80000400u;

loc_003BE776: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE77F); sub_003BE1EE(); /* call 0x003BE1EE */

loc_003BE77F: ;
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

loc_003BE783: ;
    ecx = ZX16(LO16(ecx));
    if (CMP_EQ(ecx, MEM32(eax + 0x14))) goto loc_003BE794; /* je: equal / zero */

loc_003BE78B: ;
    MEM32(eax + 4) = 0x80000000u;
    { RECOMP_SLICE_POINT(); goto loc_003BE776; }

loc_003BE794: ;
    SET_LO16(eax, ZX8(MEM8(0xF308A9)));
    MEM32(0xF30824) = 0x3BE4EE;
    MEM32(0xF30834) = edx;
    MEM32(0xF30830) = edx;
    MEM8(0xF30844) = LO8(edx);
    MEM8(0xF30845) = 9;
    MEM16(0xF30846) = LO16(eax);
    MEM16(0xF30848) = LO16(edx);
    MEM16(0xF3084A) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE7D8); sub_003BDCD1(); /* call 0x003BDCD1 */

loc_003BE7D8: ;
    eax = MEM32(ebp + 0xC);
    eax = MEM32(eax + 0xC);
    PUSH32(esp, 0xF3081C);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE7EC); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE7EC: ;
    { RECOMP_SLICE_POINT(); goto loc_003BE77F; }

}

/**
 * sub_003BE7EE
 * Original: 0x003BE7EE - 0x003BE939 (331 bytes, 83 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE7EE(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE7EE: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* cmp MEM8(0xF30819), LO8(ebx) - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(0xF30819), LO8(ebx))); /* latched */
    PUSH32(esp, esi);
    esi = edx;
    MEM8(0xF3081B) = 4;
    if (_rcc0) goto loc_003BE813; /* je: equal / zero */

loc_003BE807: ;
    PUSH32(esp, esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE80E); sub_003BE181(); /* call 0x003BE181 */

loc_003BE80E: ;
    goto loc_003BE935;

loc_003BE813: ;
    SET_LO8(eax, MEM8(0xF308A0));
    if (CMP_EQ(LO8(eax), LO8(ebx))) goto loc_003BE850; /* je: equal / zero */

loc_003BE81C: ;
    /* cmp LO8(eax), 9 - flags set for next jcc */
    SET_LO8(eax, (CMP_NE(LO8(eax), 9)) ? 1 : 0); /* setne */
    SET_LO8(eax, LO8(eax) + 1);
    MEM8(esi) = LO8(eax);
    SET_LO8(eax, MEM8(0xF308A0));
    MEM8(ebp + -3) = LO8(eax);
    SET_LO8(eax, MEM8(0xF308A1));
    MEM8(ebp + -2) = LO8(eax);
    SET_LO8(eax, MEM8(0xF308A2));
    MEM8(ebp + -1) = LO8(eax);
    MEM8(ebp + -4) = 0x81;
    PUSH32(esp, MEM32(ebp + -4));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE84B); sub_003BE3DF(); /* call 0x003BE3DF */

loc_003BE84B: ;
    goto loc_003BE935;

loc_003BE850: ;
    SET_LO16(eax, ZX8(MEM8(0xF308A3)));
    MEM16(0xF30838) = LO16(eax);
    MEM8(0xF3081C) = 0x20;
    MEM8(0xF3081D) = 2;
    MEM32(0xF30824) = ebx;
    MEM8(0xF30831) = LO8(ebx);
    MEM8(0xF30832) = LO8(ebx);
    MEM8(0xF30833) = LO8(ebx);
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) >> 7);
    MEM8(0xF3083A) = LO8(eax);
    SET_LO8(eax, MEM8(esi + 5));
    PUSH32(esp, edi);
    MEM8(0xF30830) = LO8(eax);
    eax = MEM32(esi + 0xC);
    edi = 0xF3081C;
    PUSH32(esp, edi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE8AA); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE8AA: ;
    eax = MEM32(0xF3082C);
    MEM32(esi + 8) = eax;
    MEM8(0xF3081C) = 0x30;
    MEM8(0xF3081D) = 0x40;
    MEM32(0xF30824) = 0x3BE735;
    MEM32(0xF30828) = esi;
    eax = MEM32(esi + 8);
    PUSH32(esp, 0x50);
    MEM32(0xF3082C) = eax;
    POP32(esp, eax);
    MEM32(0xF30834) = 0xF308A4;
    MEM32(0xF30830) = eax;
    MEM8(0xF30838) = 2;
    MEM8(0xF30839) = 1;
    MEM8(0xF3083A) = LO8(ebx);
    MEM8(0xF30844) = 0x80;
    MEM8(0xF30845) = 6;
    MEM16(0xF30846) = 0x200;
    MEM16(0xF30848) = LO16(ebx);
    MEM16(0xF3084A) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE927); sub_003BDCD1(); /* call 0x003BDCD1 */

loc_003BE927: ;
    eax = MEM32(esi + 0xC);
    PUSH32(esp, edi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE934); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BE934: ;
    POP32(esp, edi);

loc_003BE935: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BE939
 * Original: 0x003BE939 - 0x003BE98D (84 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE939(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE939: ;
    eax = ZX8(MEM8(0xF30890));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003BE985; /* je: equal / zero */

loc_003BE945: ;
    eax--;
    if ((eax == 0)) goto loc_003BE96D; /* je: equal / zero */

loc_003BE948: ;
    eax--;
    if ((eax == 0)) goto loc_003BE960; /* je: equal / zero */

loc_003BE94B: ;
    eax--;
    if ((eax != 0)) goto loc_003BE98A; /* jne: not equal / not zero */

loc_003BE94E: ;
    edx = MEM32(0xF30898);
    ecx = 0xF3081C;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE95E); sub_003BE7EE(); /* call 0x003BE7EE */

loc_003BE95E: ;
    goto loc_003BE98A;

loc_003BE960: ;
    ecx = MEM32(0xF30898);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE96B); sub_003BE635(); /* call 0x003BE635 */

loc_003BE96B: ;
    goto loc_003BE98A;

loc_003BE96D: ;
    eax = MEM32(0xF30898);
    eax = MEM32(eax + 0xC);
    PUSH32(esp, 0xF3081C);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE983); sub_003C2442(); /* call 0x003C2442 */

loc_003BE983: ;
    goto loc_003BE98A;

loc_003BE985: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BE98A); sub_003BDE20(); /* call 0x003BDE20 */

loc_003BE98A: ;
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BE98D
 * Original: 0x003BE98D - 0x003BE9E7 (90 bytes, 35 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE98D(void)
{

loc_003BE98D: ;
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
 * sub_003BE9E7
 * Original: 0x003BE9E7 - 0x003BE9FB (20 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE9E7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BE9E7: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(eax + 8);
    if (TEST_Z(ecx, ecx)) goto loc_003BE9F8; /* je: equal / zero */

loc_003BE9F2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(eax + 0xC));
    PUSH32(esp, eax);
    { uint32_t _icall_t = ecx; g_seh_ebp = ebp; PUSH32(esp, 0x3BE9F8); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BE9F8: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BE9FB
 * Original: 0x003BE9FB - 0x003BEA44 (73 bytes, 26 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BE9FB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BE9FB: ;
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
    if (TEST_NZ(ecx, ecx)) goto loc_003BEA37; /* jne: not equal / not zero */

loc_003BEA35: ;
    eax = 0; /* xor self */

loc_003BEA37: ;
    if (CMP_EQ(MEM8(ebp + 0x10), 0)) goto loc_003BEA40; /* je: equal / zero */

loc_003BEA3D: ;
    eax = eax << 3;

loc_003BEA40: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BEA44
 * Original: 0x003BEA44 - 0x003BEA79 (53 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA44(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BEA44: ;
    PUSH32(esp, esi);
    eax = 0x3BBD74;
    esi = 0x3BBD8C;
    /* cmp eax, esi - flags set for next jcc */
    ecx = eax;
    if (CMP_AE(eax, esi)) goto loc_003BEA6F; /* jae: above or equal (unsigned >=) */

loc_003BEA55: ;
    edx = MEM32(esp + 8);

loc_003BEA59: ;
    eax = MEM32(ecx);
    if (TEST_Z(eax, eax)) goto loc_003BEA68; /* je: equal / zero */

loc_003BEA5F: ;
    if (CMP_NE(HI8(edx), MEM8(eax + 1))) goto loc_003BEA68; /* jne: not equal / not zero */

loc_003BEA64: ;
    if (CMP_EQ(LO8(edx), MEM8(eax))) goto loc_003BEA75; /* je: equal / zero */

loc_003BEA68: ;
    ecx = ecx + 4;
    if (CMP_B(ecx, esi)) { RECOMP_SLICE_POINT(); goto loc_003BEA59; } /* jb: below (unsigned <) */

loc_003BEA6F: ;
    eax = 0; /* xor self */

loc_003BEA71: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

loc_003BEA75: ;
    eax = MEM32(ecx);
    { RECOMP_SLICE_POINT(); goto loc_003BEA71; }

}

/**
 * sub_003BEA79
 * Original: 0x003BEA79 - 0x003BEA99 (32 bytes, 13 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA79(void)
{
    uint32_t ebp;

loc_003BEA79: ;
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
 * sub_003BEA99
 * Original: 0x003BEA99 - 0x003BEAF3 (90 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEA99(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEA99: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    esi = MEM32(edi + 0x18);
    ebx = 0x103;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BEAB0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEAB0: ;
    /* test MEM8(esi + 0xC), 6 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0xC), 6)); /* latched */
    ecx = MEM32(ebp + 0xC);
    MEM8(ebp + 0xB) = LO8(eax);
    if (_rcc0) goto loc_003BEAD0; /* je: equal / zero */

loc_003BEABC: ;
    eax = 0xC000009Du;
    SET_LO8(edx, 0); /* xor self */
    ebx = eax;
    MEM32(ecx + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BEACE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEACE: ;
    goto loc_003BEAE1;

loc_003BEAD0: ;
    eax = MEM32(ecx + 0x5C);
    MEM8(eax + 3) = MEM8(eax + 3) | 1;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C500C); g_seh_ebp = ebp; PUSH32(esp, 0x3BEAE1); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEAE1: ;
    SET_LO8(ecx, MEM8(ebp + 0xB));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BEAEA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEAEA: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BEAF3
 * Original: 0x003BEAF3 - 0x003BEB33 (64 bytes, 21 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEAF3(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEAF3: ;
    eax = MEM32(esp + 8);
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    ecx = MEM32(esi + 0x10);
    MEM32(ecx + 0x10) = eax;
    ecx = 0xC0000000u;
    eax = eax & ecx;
    /* cmp eax, ecx - flags set for next jcc */
    _rcc0 = (CMP_NE(eax, ecx)); /* latched */
    eax = MEM32(esi + 0x10);
    if (_rcc0) goto loc_003BEB16; /* jne: not equal / not zero */

loc_003BEB10: ;
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    goto loc_003BEB1C;

loc_003BEB16: ;
    ecx = MEM32(esi + 0x2C);
    MEM32(eax + 0x14) = ecx;

loc_003BEB1C: ;
    ecx = MEM32(esi + 0x10);
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BEB27); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB27: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BEB2F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB2F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BEB33
 * Original: 0x003BEB33 - 0x003BEB4F (28 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB33(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BEB33: ;
    eax = MEM32(0xF2D80C);
    if (CMP_EQ(eax, 0xF2D80C)) goto loc_003BEB4E; /* je: equal / zero */

loc_003BEB3F: ;
    eax = MEM32(eax + 8);
    eax = MEM32(eax + 0x14);
    eax = MEM32(eax + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(eax + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3BEB4E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEB4E: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BEB4F
 * Original: 0x003BEB4F - 0x003BEB76 (39 bytes, 18 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB4F(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BEB4F: ;
    eax = ecx;
    edx = 0; /* xor self */
    if (CMP_BE(MEM32(eax + 4), edx)) goto loc_003BEB75; /* jbe: below or equal (unsigned <=) */

loc_003BEB58: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003BEB5A: ;
    edi = MEM32(eax);
    edi = edi + edx;
    PUSH32(esp, 8);
    POP32(esp, ecx);
    esi = 0x3C4E6C;
    edx = edx + 0x1000;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    if (CMP_B(edx, MEM32(eax + 4))) { RECOMP_SLICE_POINT(); goto loc_003BEB5A; } /* jb: below (unsigned <) */

loc_003BEB73: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BEB75: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003BEB76
 * Original: 0x003BEB76 - 0x003BEB90 (26 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB76(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BEB76: ;
    eax = MEM32(esp + 4);
    if (CMP_BE(eax, 1)) goto loc_003BEB8B; /* jbe: below or equal (unsigned <=) */

loc_003BEB7F: ;
    ecx = eax + -1;
    if (TEST_NZ(eax, ecx)) goto loc_003BEB8B; /* jne: not equal / not zero */

loc_003BEB86: ;
    eax = 0; /* xor self */
    eax++;
    goto loc_003BEB8D;

loc_003BEB8B: ;
    eax = 0; /* xor self */

loc_003BEB8D: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BEB90
 * Original: 0x003BEB90 - 0x003BEBA6 (22 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEB90(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BEB90: ;
    ecx = 0; /* xor self */
    SET_LO8(eax, 0); /* xor self */
    ecx++;

loc_003BEB95: ;
    if (TEST_NZ(MEM32(esp + 4), ecx)) goto loc_003BEBA3; /* jne: not equal / not zero */

loc_003BEB9B: ;
    SET_LO8(eax, LO8(eax) + 1);
    ecx = ecx << 1;
    if (CMP_B(LO8(eax), 0x20)) { RECOMP_SLICE_POINT(); goto loc_003BEB95; } /* jb: below (unsigned <) */

loc_003BEBA3: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BEBA6
 * Original: 0x003BEBA6 - 0x003BED8C (486 bytes, 139 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEBA6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEBA6: ;
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
    if (CMP_NE(esi, eax)) goto loc_003BEBE3; /* jne: not equal / not zero */

loc_003BEBD4: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = edx;
    goto loc_003BED58;

loc_003BEBE3: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEC09); sub_003BEA79(); /* call 0x003BEA79 */

loc_003BEC09: ;
    ecx = ZX16(MEM16(ebp + 0xA));
    eax++;
    MEM32(ebp + 0xC) = eax;
    { uint64_t _r = (uint64_t)eax * (uint64_t)ecx;
      eax = (uint32_t)_r; edx = (uint32_t)(_r >> 32); }
    /* test esi, esi - flags set for next jcc */
    MEM32(ebp + -20) = eax;
    MEM32(ebp + -16) = edx;
    if (TEST_NZ(esi, esi)) goto loc_003BEC22; /* jne: not equal / not zero */

loc_003BEC1D: ;
    esi = 0x2000;

loc_003BEC22: ;
    PUSH32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEC28); sub_003BEB76(); /* call 0x003BEB76 */

loc_003BEC28: ;
    if (TEST_Z(eax, eax)) goto loc_003BED79; /* je: equal / zero */

loc_003BEC30: ;
    edx = ZX16(MEM16(ebp + 0xA));
    if (CMP_A(edx, 0x1000)) goto loc_003BED79; /* ja: above (unsigned >) */

loc_003BEC40: ;
    if (CMP_A(esi, 0x4000)) goto loc_003BED79; /* ja: above (unsigned >) */

loc_003BEC4C: ;
    if (TEST_NZ(LO16(esi), 0xFFF)) goto loc_003BED79; /* jne: not equal / not zero */

loc_003BEC57: ;
    ecx = 0; /* xor self */
    if (CMP_EQ(MEM32(ebp + 0xC), ecx)) goto loc_003BED79; /* je: equal / zero */

loc_003BEC62: ;
    eax = MEM32(ebp + -16);
    if (CMP_B(eax, ecx)) goto loc_003BED79; /* jb: below (unsigned <) */

loc_003BEC6D: ;
    if (CMP_A(eax, ecx)) goto loc_003BEC78; /* ja: above (unsigned >) */

loc_003BEC6F: ;
    if (CMP_B(MEM32(ebp + -20), esi)) goto loc_003BED79; /* jb: below (unsigned <) */

loc_003BEC78: ;
    if (CMP_A(eax, 1)) goto loc_003BED79; /* ja: above (unsigned >) */

loc_003BEC81: ;
    if (CMP_B(eax, 1)) goto loc_003BEC8D; /* jb: below (unsigned <) */

loc_003BEC83: ;
    if (CMP_A(MEM32(ebp + -20), 0)) goto loc_003BED79; /* ja: above (unsigned >) */

loc_003BEC8D: ;
    ecx = MEM32(ebp + -20);
    PUSH32(esp, edx);
    MEM32(ebx + 0x160) = ecx;
    MEM32(ebx + 0x164) = eax;
    MEM32(ebx + 0x168) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BECA8); sub_003BEB90(); /* call 0x003BEB90 */

loc_003BECA8: ;
    eax = ZX8(LO8(eax));
    MEM32(ebx + 0x158) = eax;
    eax = 0; /* xor self */
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + -16));
    MEM32(ebx + 0x148) = 0xC;
    PUSH32(esp, MEM32(ebp + -20));
    edi = ebx + 0x140;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BECD0); sub_0033AE40(); /* call 0x0033AE40 */

loc_003BECD0: ;
    MEM32(edi) = eax;
    eax = MEM32(ebp + -12);
    esi = esi >> 0xC;
    MEM32(edi + 4) = edx;
    MEM32(ebx + 0x14C) = 1;
    MEM32(ebx + 0x150) = esi;
    MEM32(ebx + 0x154) = 0x1000;
    eax = MEM32(eax + 0x10);
    if (CMP_EQ(eax, 0x70000)) goto loc_003BED37; /* je: equal / zero */

loc_003BECFF: ;
    if (CMP_NE(eax, 0x74004)) goto loc_003BED55; /* jne: not equal / not zero */

loc_003BED06: ;
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
    goto loc_003BED4E;

loc_003BED37: ;
    eax = MEM32(ebp + -4);
    PUSH32(esp, 6);
    esi = edi;
    edi = MEM32(eax + 0x30);
    POP32(esp, ecx);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x14) = 0x18;

loc_003BED4E: ;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = MEM32(eax + 0x10) & 0;

loc_003BED55: ;
    edi = MEM32(ebp + -8);

loc_003BED58: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C5018); g_seh_ebp = ebp; PUSH32(esp, 0x3BED5F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BED5F: ;
    ecx = MEM32(ebx + 0x10);
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BED6A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BED6A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebx));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BED72); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BED72: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

loc_003BED79: ;
    eax = MEM32(ebp + -4);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    eax = MEM32(ebx + 0x10);
    MEM32(eax + 0x10) = 0xC000014Fu;
    { RECOMP_SLICE_POINT(); goto loc_003BED58; }

}

/**
 * sub_003BED8C
 * Original: 0x003BED8C - 0x003BEE0D (129 bytes, 48 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BED8C(void)
{
    uint32_t ebp;

loc_003BED8C: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEDAF); sub_0033AEB0(); /* call 0x0033AEB0 */

loc_003BEDAF: ;
    ecx = MEM32(esi + 0x158);
    ebx = MEM32(edi + 8);
    edx = eax;
    eax = 0; /* xor self */
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = eax;
    MEM32(esi + 0x30) = 0x3BEAF3;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEDF0); sub_003BEA79(); /* call 0x003BEA79 */

loc_003BEDF0: ;
    MEM32(esi + 0x51) = eax;
    MEM8(ebp + -4) = HI8(ebx);
    MEM8(ebp + -3) = LO8(ebx);
    SET_LO16(eax, MEM16(ebp + -4));
    ecx = esi;
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEE08); sub_003C02E6(); /* call 0x003C02E6 */

loc_003BEE08: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BEE0D
 * Original: 0x003BEE0D - 0x003BEEDB (206 bytes, 72 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEE0D(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEE0D: ;
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
    if (CMP_AE(edi, ecx)) goto loc_003BEECD; /* jae: above or equal (unsigned >=) */

loc_003BEE2A: ;
    edx = edi;
    edx = edx - 0x3C4E6C;
    PUSH32(esp, ebx);
    MEM32(ebp + -12) = edx;
    PUSH32(esp, esi);

loc_003BEE37: ;
    eax = 0; /* xor self */
    if (CMP_NE(MEM32(edi), 0x46313539)) goto loc_003BEEB1; /* jne: not equal / not zero */

loc_003BEE41: ;
    eax++;
    /* cmp eax, 8 - flags set for next jcc */
    MEM32(ebp + -4) = eax;
    if (CMP_EQ(eax, 8)) goto loc_003BEE5C; /* je: equal / zero */

loc_003BEE4A: ;
    esi = MEM32(edx + eax * 4 + 0x3C4E6C);
    if (CMP_EQ(esi, MEM32(eax * 4 + 0x3C4E6C))) { RECOMP_SLICE_POINT(); goto loc_003BEE41; } /* je: equal / zero */

loc_003BEE5A: ;
    goto loc_003BEEB1;

loc_003BEE5C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4F60); g_seh_ebp = ebp; PUSH32(esp, 0x3BEE63); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEE63: ;
    esi = esi | 0xFFFFFFFFu;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    ebx = eax;
    if (CMP_L(MEM32(ebp + 0xC), 0)) goto loc_003BEE75; /* jl: less (signed <) */

loc_003BEE6E: ;
    MEM32(ebp + 0xC) = 0xC000003Eu;

loc_003BEE75: ;
    eax = ebx;
    eax = eax & 6;
    if (CMP_NE(LO8(eax), 2)) goto loc_003BEE90; /* jne: not equal / not zero */

loc_003BEE7E: ;
    esi = ebx;
    esi = esi & 0xFFFFFFFDu;
    esi = esi | 4;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x20);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4F5C); g_seh_ebp = ebp; PUSH32(esp, 0x3BEE90); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEE90: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;
    _rcc0 = ((MEM32(ebp + -4) != 0)); /* latched */
    eax = MEM32(ebp + -4);
    MEM32(edi + eax * 4) = 0x4C494146;
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003BEE90; } /* jne: not equal / not zero */

loc_003BEE9F: ;
    if (CMP_EQ(esi, 0xFFFFFFFFu)) goto loc_003BEEAE; /* je: equal / zero */

loc_003BEEA4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, 0x20);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4F5C); g_seh_ebp = ebp; PUSH32(esp, 0x3BEEAE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEEAE: ;
    ecx = MEM32(ebp + -8);

loc_003BEEB1: ;
    edx = MEM32(ebp + -12);
    eax = 0x1000;
    edi = edi + eax;
    edx = edx + eax;
    /* cmp edi, ecx - flags set for next jcc */
    MEM32(ebp + -12) = edx;
    if (CMP_B(edi, ecx)) { RECOMP_SLICE_POINT(); goto loc_003BEE37; } /* jb: below (unsigned <) */

loc_003BEEC8: ;
    eax = MEM32(ebp + 8);
    POP32(esp, esi);
    POP32(esp, ebx);

loc_003BEECD: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEED6); sub_003BEAF3(); /* call 0x003BEAF3 */

loc_003BEED6: ;
    POP32(esp, edi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BEEDB
 * Original: 0x003BEEDB - 0x003BF0C1 (486 bytes, 133 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BEEDB(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BEEDB: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(ebp + 8);
    ebx = MEM32(esi + 0xC);
    ecx = MEM32(esi + 0x10);
    ebx = ebx & 0xF0000000u;
    /* cmp MEM32(ebp + 0xC), 0 - flags set for next jcc */
    _rcc0 = (CMP_L(MEM32(ebp + 0xC), 0)); /* latched */
    PUSH32(esp, edi);
    edi = MEM32(ecx + 0x5C);
    MEM32(ebp + 8) = ecx;
    if (_rcc0) goto loc_003BEFB1; /* jl: less (signed <) */

loc_003BEF00: ;
    ebx = ebx + 0x10000000;
    if (CMP_NE(ebx, 0x20000000)) goto loc_003BEF19; /* jne: not equal / not zero */

loc_003BEF0E: ;
    if (TEST_NZ(MEM8(esi + 0xF), 2)) goto loc_003BEF2C; /* jne: not equal / not zero */

loc_003BEF14: ;
    ebx = 0x40000000;

loc_003BEF19: ;
    if (CMP_NE(ebx, 0x40000000)) goto loc_003BEF2C; /* jne: not equal / not zero */

loc_003BEF21: ;
    if (TEST_NZ(MEM8(esi + 0xF), 4)) goto loc_003BEF2C; /* jne: not equal / not zero */

loc_003BEF27: ;
    ebx = 0x60000000;

loc_003BEF2C: ;
    eax = MEM32(esi + 0xC);
    edx = 0xFFFFFFF;
    eax = eax & edx;
    eax = eax | ebx;
    /* cmp ebx, 0x20000000 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (CMP_EQ(ebx, 0x20000000)) goto loc_003BF06A; /* je: equal / zero */

loc_003BEF47: ;
    if (CMP_EQ(ebx, 0x30000000)) goto loc_003BF03E; /* je: equal / zero */

loc_003BEF53: ;
    if (CMP_EQ(ebx, 0x40000000)) goto loc_003BF01E; /* je: equal / zero */

loc_003BEF5F: ;
    if (CMP_EQ(ebx, 0x50000000)) goto loc_003BEFEC; /* je: equal / zero */

loc_003BEF6B: ;
    if (CMP_NE(ebx, 0x60000000)) goto loc_003BF0BA; /* jne: not equal / not zero */

loc_003BEF77: ;
    eax = eax & edx;
    MEM32(esi + 0xC) = eax;
    eax = MEM32(0xF2D80C);
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
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BEF9F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEF9F: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEFA4); sub_003BEB33(); /* call 0x003BEB33 */

loc_003BEFA4: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BEFAC); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BEFAC: ;
    goto loc_003BF0BA;

loc_003BEFB1: ;
    if (CMP_EQ(ebx, 0x20000000)) goto loc_003BEFC5; /* je: equal / zero */

loc_003BEFB9: ;
    if (CMP_NE(ebx, 0x40000000)) { RECOMP_SLICE_POINT(); goto loc_003BEF27; } /* jne: not equal / not zero */

loc_003BEFC5: ;
    if (CMP_NE(MEM32(ebp + 0xC), 0xC000003Eu)) { RECOMP_SLICE_POINT(); goto loc_003BEF27; } /* jne: not equal / not zero */

loc_003BEFD2: ;
    ecx = esi + 0x28;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BEFDA); sub_003BEB4F(); /* call 0x003BEB4F */

loc_003BEFDA: ;
    MEM32(ebp + 0xC) = MEM32(ebp + 0xC) & 0;
    ecx = MEM32(ebp + 8);
    ebx = ebx + 0x10000000;
    { RECOMP_SLICE_POINT(); goto loc_003BEF2C; }

loc_003BEFEC: ;
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

loc_003BF019: ;
    eax = eax + MEM32(edi + 4);
    goto loc_003BF08B;

loc_003BF01E: ;
    MEM32(esi + 0x28) = 0xF2D814;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x1C);
    MEM8(esi + 0x37) = 1;
    MEM32(esi + 0x2C) = eax;
    MEM8(esi + 0x4F) = 0x28;
    eax = MEM32(edi + 0xC);
    { RECOMP_SLICE_POINT(); goto loc_003BF019; }

loc_003BF03E: ;
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
    goto loc_003BF08B;

loc_003BF06A: ;
    MEM32(esi + 0x28) = 0xF2D814;
    eax = MEM32(esi + 0x168);
    eax = eax - MEM32(esi + 0x18);
    MEM8(esi + 0x37) = 1;
    MEM32(esi + 0x2C) = eax;
    MEM8(esi + 0x4F) = 0x28;
    eax = MEM32(edi + 0xC);
    eax = eax - MEM32(esi + 0x2C);

loc_003BF08B: ;
    edi = esi + 0x158;
    ecx = MEM32(edi);
    eax = eax >> LO8(ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF09B); sub_003BEA79(); /* call 0x003BEA79 */

loc_003BF09B: ;
    MEM32(esi + 0x51) = eax;
    ecx = MEM32(edi);
    eax = MEM32(esi + 0x2C);
    eax = eax >> LO8(ecx);
    ecx = esi;
    MEM8(ebp + 0xE) = HI8(eax);
    MEM8(ebp + 0xF) = LO8(eax);
    SET_LO16(eax, MEM16(ebp + 0xE));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF0BA); sub_003C02E6(); /* call 0x003C02E6 */

loc_003BF0BA: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF0C1
 * Original: 0x003BF0C1 - 0x003BF23C (379 bytes, 110 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF0C1(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF0C1: ;
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
    _rcc0 = (CMP_L(MEM32(ebp + 0xC), 0)); /* latched */
    MEM32(ebp + 8) = edx;
    if (_rcc0) goto loc_003BF0EA; /* jl: less (signed <) */

loc_003BF0E2: ;
    edi = edi + 0x10000000;
    goto loc_003BF11F;

loc_003BF0EA: ;
    if (CMP_EQ(edi, 0x20000000)) goto loc_003BF0FA; /* je: equal / zero */

loc_003BF0F2: ;
    if (CMP_NE(edi, 0x30000000)) goto loc_003BF11A; /* jne: not equal / not zero */

loc_003BF0FA: ;
    if (CMP_NE(MEM32(ebp + 0xC), 0xC000003Eu)) goto loc_003BF11A; /* jne: not equal / not zero */

loc_003BF103: ;
    ecx = esi + 0x28;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF10B); sub_003BEB4F(); /* call 0x003BEB4F */

loc_003BF10B: ;
    MEM32(ebp + 0xC) = MEM32(ebp + 0xC) & 0;
    edx = MEM32(ebp + 8);
    edi = edi + 0x10000000;
    goto loc_003BF11F;

loc_003BF11A: ;
    edi = 0x50000000;

loc_003BF11F: ;
    eax = MEM32(esi + 0xC);
    ecx = 0xFFFFFFF;
    eax = eax & ecx;
    eax = eax | edi;
    /* cmp edi, 0x20000000 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (CMP_EQ(edi, 0x20000000)) goto loc_003BF1E6; /* je: equal / zero */

loc_003BF13A: ;
    if (CMP_EQ(edi, 0x30000000)) goto loc_003BF1CD; /* je: equal / zero */

loc_003BF146: ;
    if (CMP_EQ(edi, 0x40000000)) goto loc_003BF196; /* je: equal / zero */

loc_003BF14E: ;
    if (CMP_NE(edi, 0x50000000)) goto loc_003BF235; /* jne: not equal / not zero */

loc_003BF15A: ;
    eax = eax & ecx;
    MEM32(esi + 0xC) = eax;
    eax = MEM32(0xF2D80C);
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
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BF184); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF184: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF189); sub_003BEB33(); /* call 0x003BEB33 */

loc_003BF189: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BF191); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF191: ;
    goto loc_003BF235;

loc_003BF196: ;
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
    goto loc_003BF206;

loc_003BF1CD: ;
    eax = MEM32(esi + 0x2C);
    eax = eax + 0xF2D814;
    MEM32(esi + 0x28) = eax;
    eax = MEM32(esi + 0x1C);
    MEM32(esi + 0x2C) = eax;
    eax = MEM32(edx + 0xC);
    eax = eax + MEM32(edx + 4);
    goto loc_003BF206;

loc_003BF1E6: ;
    MEM8(esi + 0x37) = 1;
    MEM8(esi + 0x4F) = 0x28;
    MEM32(esi + 0x28) = 0xF2D814;
    ecx = MEM32(esi + 0x168);
    ecx = ecx - MEM32(esi + 0x18);
    MEM32(esi + 0x2C) = ecx;
    eax = MEM32(edx + 0xC);
    eax = eax - ecx;

loc_003BF206: ;
    edi = esi + 0x158;
    ecx = MEM32(edi);
    eax = eax >> LO8(ecx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF216); sub_003BEA79(); /* call 0x003BEA79 */

loc_003BF216: ;
    MEM32(esi + 0x51) = eax;
    ecx = MEM32(edi);
    eax = MEM32(esi + 0x2C);
    eax = eax >> LO8(ecx);
    ecx = esi;
    MEM8(ebp + 0xE) = HI8(eax);
    MEM8(ebp + 0xF) = LO8(eax);
    SET_LO16(eax, MEM16(ebp + 0xE));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF235); sub_003C02E6(); /* call 0x003C02E6 */

loc_003BF235: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF23C
 * Original: 0x003BF23C - 0x003BF299 (93 bytes, 34 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF23C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF23C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0x5F5F554D);
    PUSH32(esp, 8);
    POP32(esp, edi);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C501C); g_seh_ebp = ebp; PUSH32(esp, 0x3BF24F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF24F: ;
    if (TEST_NZ(eax, eax)) goto loc_003BF261; /* jne: not equal / not zero */

loc_003BF253: ;
    eax = MEM32(esi + 0x10);
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    eax = 0xC000009Au;
    goto loc_003BF296;

loc_003BF261: ;
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = edi;
    ecx = esi + 0x4F;
    MEM32(esi + 0x30) = 0x3BEBA6;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF291); sub_003C02E6(); /* call 0x003C02E6 */

loc_003BF291: ;
    eax = 0x103;

loc_003BF296: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF299
 * Original: 0x003BF299 - 0x003BF33B (162 bytes, 53 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF299(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF299: ;
    edx = MEM32(esp + 8);
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    MEM8(esi + 0xF) = MEM8(esi + 0xF) & 0xF;
    ecx = MEM32(esi + 0x10);
    PUSH32(esp, edi);
    eax = 0xC0000000u;
    edi = edx;
    edi = edi & eax;
    if (CMP_NE(edi, eax)) goto loc_003BF2D0; /* jne: not equal / not zero */

loc_003BF2B7: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    MEM32(ecx + 0x10) = edx;
    SET_LO8(edx, 0); /* xor self */
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BF2C6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF2C6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BF2CE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF2CE: ;
    goto loc_003BF336;

loc_003BF2D0: ;
    eax = 0; /* xor self */
    edi = esi + 0x4F;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM16(esi + 0x34) = 8;
    MEM8(esi + 0x36) = 2;
    if (TEST_Z(MEM8(esi + 0xF), 8)) goto loc_003BF2F2; /* je: equal / zero */

loc_003BF2E9: ;
    MEM32(esi + 0x30) = 0x3BF0C1;
    goto loc_003BF2F9;

loc_003BF2F2: ;
    MEM32(esi + 0x30) = 0x3BEEDB;

loc_003BF2F9: ;
    MEM8(esi + 0xF) = MEM8(esi + 0xF) | 0x10;
    edi = MEM32(0xF2D80C);
    edx = 0xF2D80C;
    /* cmp edi, edx - flags set for next jcc */
    eax = ecx + 0x54;
    if (CMP_NE(edi, edx)) goto loc_003BF324; /* jne: not equal / not zero */

loc_003BF30F: ;
    MEM32(eax) = edi;
    MEM32(ecx + 0x58) = edx;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    MEM32(edi + 4) = eax;
    PUSH32(esp, esi);
    MEM32(0xF2D80C) = eax;
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3BF322); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF322: ;
    goto loc_003BF336;

loc_003BF324: ;
    esi = MEM32(0xF2D810);
    MEM32(eax) = edx;
    MEM32(ecx + 0x58) = esi;
    MEM32(esi) = eax;
    MEM32(0xF2D810) = eax;

loc_003BF336: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF33B
 * Original: 0x003BF33B - 0x003BF40B (208 bytes, 67 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF33B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF33B: ;
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
    if ((eax == 0)) goto loc_003BF3BE; /* je: equal / zero */

loc_003BF354: ;
    eax = eax - 0x14;
    if ((eax == 0)) goto loc_003BF3B2; /* je: equal / zero */

loc_003BF359: ;
    eax = eax - 0x3FF0;
    if ((eax == 0)) goto loc_003BF36E; /* je: equal / zero */

loc_003BF360: ;
    MEM32(esi + 0x14) = MEM32(esi + 0x14) & 0;
    eax = 0xC0000010u;
    goto loc_003BF3EF;

loc_003BF36E: ;
    edx = MEM32(esi + 0x30);
    PUSH32(esp, 8);
    eax = 0; /* xor self */
    POP32(esp, ecx);
    edi = edx;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebx + 0x160);
    eax = eax | MEM32(ebx + 0x164);
    if ((eax != 0)) goto loc_003BF393; /* jne: not equal / not zero */

loc_003BF388: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF391); sub_003BF23C(); /* call 0x003BF23C */

loc_003BF391: ;
    goto loc_003BF3E8;

loc_003BF393: ;
    eax = MEM32(ebx + 0x160);
    MEM32(edx + 8) = eax;
    eax = MEM32(ebx + 0x164);
    MEM32(edx + 0xC) = eax;
    MEM8(edx + 0x1A) = 1;
    MEM32(esi + 0x14) = 0x20;
    goto loc_003BF3E6;

loc_003BF3B2: ;
    ecx = MEM32(ebp + 8);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF3BC); sub_003BED8C(); /* call 0x003BED8C */

loc_003BF3BC: ;
    goto loc_003BF404;

loc_003BF3BE: ;
    eax = MEM32(ebx + 0x160);
    eax = eax | MEM32(ebx + 0x164);
    edi = MEM32(esi + 0x30);
    if ((eax == 0)) { RECOMP_SLICE_POINT(); goto loc_003BF388; } /* je: equal / zero */

loc_003BF3CF: ;
    PUSH32(esp, 6);
    esi = ebx + 0x140;
    POP32(esp, ecx);
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebp + 0xC);
    MEM32(ecx + 0x14) = 0x18;
    esi = ecx;

loc_003BF3E6: ;
    eax = 0; /* xor self */

loc_003BF3E8: ;
    if (CMP_EQ(eax, 0x103)) goto loc_003BF404; /* je: equal / zero */

loc_003BF3EF: ;
    SET_LO8(edx, 0); /* xor self */
    ecx = esi;
    MEM32(esi + 0x10) = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BF3FC); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF3FC: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebx));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BF404); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF404: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF40B
 * Original: 0x003BF40B - 0x003BF59B (400 bytes, 138 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF40B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003BF40B: ;
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
    if (TEST_NZ(edi, edx)) goto loc_003BF487; /* jne: not equal / not zero */

loc_003BF434: ;
    if (TEST_NZ(edi, ebx)) goto loc_003BF487; /* jne: not equal / not zero */

loc_003BF438: ;
    eax = 0; /* xor self */
    edi = ebx;
    edi = edi + edx;
    _cf = ((uint32_t)(edi) < (uint32_t)(edx)); /* CF from add */
    eax = eax + MEM32(ecx + 0x10) + _cf; /* adc */
    if (CMP_G(eax, MEM32(esi + 0x164))) goto loc_003BF484; /* jg: greater (signed >) */

loc_003BF449: ;
    if (CMP_L(eax, MEM32(esi + 0x164))) goto loc_003BF453; /* jl: less (signed <) */

loc_003BF44B: ;
    if (CMP_A(edi, MEM32(esi + 0x160))) goto loc_003BF484; /* ja: above (unsigned >) */

loc_003BF453: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BF45F; /* jne: not equal / not zero */

loc_003BF457: ;
    eax = MEM32(ebp + -8);
    MEM32(eax + 0x10) = MEM32(eax + 0x10) & ebx;
    goto loc_003BF494;

loc_003BF45F: ;
    if (TEST_Z(MEM8(ecx + 2), 0x80)) goto loc_003BF470; /* je: equal / zero */

loc_003BF465: ;
    eax = MEM32(ecx + 8);
    MEM32(ebp + -4) = eax;
    eax = MEM32(ebp + -8);
    goto loc_003BF47C;

loc_003BF470: ;
    eax = MEM32(ebp + -8);
    edi = MEM32(eax + 0x30);
    edi = edi + MEM32(ecx + 8);
    MEM32(ebp + -4) = edi;

loc_003BF47C: ;
    edi = MEM32(ebp + -4);
    MEM32(ecx + 8) = edi;
    goto loc_003BF48E;

loc_003BF484: ;
    eax = MEM32(ebp + -8);

loc_003BF487: ;
    MEM32(eax + 0x10) = 0xC000000Du;

loc_003BF48E: ;
    if (CMP_NE(MEM32(ebp + -4), 0)) goto loc_003BF4AF; /* jne: not equal / not zero */

loc_003BF494: ;
    MEM32(eax + 0x14) = MEM32(eax + 0x14) & 0;
    SET_LO8(edx, 0); /* xor self */
    ecx = eax;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BF4A2); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF4A2: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi));
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BF4AA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF4AA: ;
    goto loc_003BF596;

loc_003BF4AF: ;
    eax = 0; /* xor self */
    edi = esi + 0x4F;
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    MEM32(edi) = eax; edi += 4; /* stosd */
    if (CMP_NE(MEM8(ecx), 3)) goto loc_003BF548; /* jne: not equal / not zero */

loc_003BF4C1: ;
    edi = MEM32(esi + 0x168);
    eax = edx;
    edx = 0; /* xor self */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)edi);
      edx = (uint32_t)(_dividend % (uint32_t)edi); }
    MEM8(esi + 0xF) = MEM8(esi + 0xF) & 0xF1;
    ecx = MEM32(esi + 0xC);
    if (TEST_Z(edx, edx)) goto loc_003BF504; /* je: equal / zero */

loc_003BF4D8: ;
    eax = edi;
    eax = eax - edx;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(esi + 0x18) = eax;
    if (CMP_BE(eax, ebx)) goto loc_003BF4F3; /* jbe: below or equal (unsigned <=) */

loc_003BF4E3: ;
    ecx = ecx | 0x8000000;
    eax = eax - ebx;
    MEM32(esi + 0xC) = ecx;
    MEM32(esi + 0x1C) = eax;
    goto loc_003BF51B;

loc_003BF4F3: ;
    MEM32(ebp + -12) = MEM32(ebp + -12) + eax;
    MEM32(ebp + -4) = MEM32(ebp + -4) + eax;
    ebx = ebx - eax;
    ecx = ecx | 0x2000000;
    MEM32(esi + 0xC) = ecx;

loc_003BF504: ;
    edx = 0; /* xor self */
    eax = ebx;
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)edi);
      edx = (uint32_t)(_dividend % (uint32_t)edi); }
    if (TEST_Z(edx, edx)) goto loc_003BF517; /* je: equal / zero */

loc_003BF50E: ;
    ebx = ebx - edx;
    MEM8(esi + 0xF) = MEM8(esi + 0xF) | 4;
    MEM32(esi + 0x1C) = edx;

loc_003BF517: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003BF525; /* jne: not equal / not zero */

loc_003BF51B: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF523); sub_003BF299(); /* call 0x003BF299 */

loc_003BF523: ;
    goto loc_003BF596;

loc_003BF525: ;
    if (TEST_Z(MEM8(esi + 0xF), 0xE)) goto loc_003BF534; /* je: equal / zero */

loc_003BF52B: ;
    MEM32(esi + 0x30) = 0x3BF299;
    goto loc_003BF53B;

loc_003BF534: ;
    MEM32(esi + 0x30) = 0x3BEAF3;

loc_003BF53B: ;
    edx = MEM32(ebp + -12);
    MEM8(esi + 0x37) = 2;
    MEM8(esi + 0x4F) = 0x2A;
    goto loc_003BF557;

loc_003BF548: ;
    MEM32(esi + 0x30) = 0x3BEE0D;
    MEM8(esi + 0x37) = 1;
    MEM8(esi + 0x4F) = 0x28;

loc_003BF557: ;
    edi = MEM32(esi + 0x158);
    eax = MEM32(ebp + -4);
    ecx = edi;
    edx = edx >> LO8(ecx);
    MEM32(esi + 0x28) = eax;
    MEM32(esi + 0x2C) = ebx;
    MEM16(esi + 0x34) = 8;
    PUSH32(esp, edx);
    MEM8(esi + 0x36) = 2;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF57A); sub_003BEA79(); /* call 0x003BEA79 */

loc_003BF57A: ;
    ecx = edi;
    ebx = ebx >> LO8(ecx);
    MEM32(esi + 0x51) = eax;
    ecx = esi;
    MEM8(ebp + -2) = HI8(ebx);
    MEM8(ebp + -1) = LO8(ebx);
    SET_LO16(eax, MEM16(ebp + -2));
    MEM16(esi + 0x56) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF596); sub_003C02E6(); /* call 0x003C02E6 */

loc_003BF596: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BF59B
 * Original: 0x003BF59B - 0x003BF60C (113 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF59B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF59B: ;
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
    { uint32_t _icall_t = MEM32(0x3C5024); g_seh_ebp = ebp; PUSH32(esp, 0x3BF5B6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF5B6: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003BF5D4; /* je: equal / zero */

loc_003BF5BA: ;
    SET_LO8(edx, 0); /* xor self */
    ecx = edi;
    MEM32(edi + 0x10) = 0xC0000240u;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C5010); g_seh_ebp = ebp; PUSH32(esp, 0x3BF5CB); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF5CB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C5014); g_seh_ebp = ebp; PUSH32(esp, 0x3BF5D2); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF5D2: ;
    goto loc_003BF605;

loc_003BF5D4: ;
    MEM32(esi + 0x14) = ebx;
    ebx = MEM32(ebp + 8);
    MEM32(ebx + 0x10) = edi;
    eax = ZX8(MEM8(esi));
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BF5FC; /* je: equal / zero */

loc_003BF5E4: ;
    eax--;
    if ((eax == 0)) goto loc_003BF5F5; /* je: equal / zero */

loc_003BF5E7: ;
    eax = eax - 7;
    if ((eax != 0)) goto loc_003BF605; /* jne: not equal / not zero */

loc_003BF5EC: ;
    PUSH32(esp, edi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF5F3); sub_003BF33B(); /* call 0x003BF33B */

loc_003BF5F3: ;
    goto loc_003BF605;

loc_003BF5F5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C5020); g_seh_ebp = ebp; PUSH32(esp, 0x3BF5FC); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF5FC: ;
    edx = edi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF605); sub_003BF40B(); /* call 0x003BF40B */

loc_003BF605: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF60C
 * Original: 0x003BF60C - 0x003BF674 (104 bytes, 34 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF60C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF60C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = edi + 3;
    esi = esi & 0xFFFFFFFCu;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3BF61F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF61F: ;
    /* cmp MEM32(0x3BBEE8), esi - flags set for next jcc */
    SET_LO8(ecx, LO8(eax));
    if (CMP_B(MEM32(0x3BBEE8), esi)) goto loc_003BF659; /* jb: below (unsigned <) */

loc_003BF629: ;
    ebx = 0x80001000u;
    ebx = ebx - MEM32(0x3BBEE8);
    MEM32(0x3BBEE8) = MEM32(0x3BBEE8) - esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BF640); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF640: ;
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
    goto loc_003BF66C;

loc_003BF659: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3BF65F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF65F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esp + 0x14));
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C501C); g_seh_ebp = ebp; PUSH32(esp, 0x3BF66A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF66A: ;
    ebx = eax;

loc_003BF66C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF674
 * Original: 0x003BF674 - 0x003BF685 (17 bytes, 5 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF674(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF674: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(esp + 0x10));
    { uint32_t _icall_t = MEM32(0x3C4FD0); g_seh_ebp = ebp; PUSH32(esp, 0x3BF682); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BF682: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BF685
 * Original: 0x003BF685 - 0x003BF698 (19 bytes, 6 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF685(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF685: ;
    eax = MEM32(ecx + 0xC);
    PUSH32(esp, MEM32(esp + 4));
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF695); sub_003C2442(); /* call 0x003C2442 */

loc_003BF695: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF698
 * Original: 0x003BF698 - 0x003BF69C (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF698(void)
{

loc_003BF698: ;
    eax = MEM32(ecx + 0x1C);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF69C
 * Original: 0x003BF69C - 0x003BF6A9 (13 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF69C(void)
{

loc_003BF69C: ;
    edx = MEM32(esp + 4);
    eax = MEM32(ecx + 0x1C);
    MEM32(ecx + 0x1C) = edx;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF6A9
 * Original: 0x003BF6A9 - 0x003BF6AD (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF6A9(void)
{

loc_003BF6A9: ;
    SET_LO8(eax, MEM8(ecx + 2));
    esp += 4; return; /* ret */

}

/**
 * sub_003BF6AD
 * Original: 0x003BF6AD - 0x003BF6B7 (10 bytes, 3 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF6AD(void)
{

loc_003BF6AD: ;
    SET_LO8(eax, MEM8(esp + 4));
    MEM8(ecx + 7) = LO8(eax);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF6B7
 * Original: 0x003BF6B7 - 0x003BF725 (110 bytes, 36 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF6B7(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BF6B7: ;
    eax = MEM32(esp + 4);
    ecx = 0xC000000Fu;
    if (CMP_G(eax, ecx)) goto loc_003BF704; /* jg: greater (signed >) */

loc_003BF6C4: ;
    if (CMP_EQ(eax, ecx)) goto loc_003BF6FD; /* je: equal / zero */

loc_003BF6C6: ;
    if (CMP_EQ(eax, 0x80000000u)) goto loc_003BF6E9; /* je: equal / zero */

loc_003BF6CD: ;
    if (CMP_EQ(eax, 0x80000100u)) goto loc_003BF6F8; /* je: equal / zero */

loc_003BF6D4: ;
    if (CMP_EQ(eax, 0x80000800u)) goto loc_003BF6F1; /* je: equal / zero */

loc_003BF6DB: ;
    if (CMP_LE(eax, 0xBFFFFFFFu)) goto loc_003BF716; /* jle: less or equal (signed <=) */

loc_003BF6E2: ;
    if (CMP_G(eax, 0xC000000Eu)) goto loc_003BF716; /* jg: greater (signed >) */

loc_003BF6E9: ;
    eax = 0x45D;

loc_003BF6EE: ;
    esp += 8; return; /* ret 4 */

loc_003BF6F1: ;
    eax = 0x5AA;
    { RECOMP_SLICE_POINT(); goto loc_003BF6EE; }

loc_003BF6F8: ;
    PUSH32(esp, 0xE);

loc_003BF6FA: ;
    POP32(esp, eax);
    { RECOMP_SLICE_POINT(); goto loc_003BF6EE; }

loc_003BF6FD: ;
    eax = 0x4C7;
    { RECOMP_SLICE_POINT(); goto loc_003BF6EE; }

loc_003BF704: ;
    if (CMP_EQ(eax, 0xC0000010u)) { RECOMP_SLICE_POINT(); goto loc_003BF6E9; } /* je: equal / zero */

loc_003BF70B: ;
    if (TEST_Z(eax, eax)) goto loc_003BF721; /* je: equal / zero */

loc_003BF70F: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BF71A; /* je: equal / zero */

loc_003BF716: ;
    PUSH32(esp, 0x1F);
    { RECOMP_SLICE_POINT(); goto loc_003BF6FA; }

loc_003BF71A: ;
    eax = 0x3E5;
    { RECOMP_SLICE_POINT(); goto loc_003BF6EE; }

loc_003BF721: ;
    eax = 0; /* xor self */
    { RECOMP_SLICE_POINT(); goto loc_003BF6EE; }

}

/**
 * sub_003BF725
 * Original: 0x003BF725 - 0x003BF791 (108 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF725(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BF725: ;
    eax = MEM32(esp + 4);
    ecx = 0xC000000Fu;
    if (CMP_G(eax, ecx)) goto loc_003BF76D; /* jg: greater (signed >) */

loc_003BF732: ;
    if (CMP_EQ(eax, ecx)) goto loc_003BF766; /* je: equal / zero */

loc_003BF734: ;
    if (CMP_EQ(eax, 0x80000000u)) goto loc_003BF757; /* je: equal / zero */

loc_003BF73B: ;
    if (CMP_EQ(eax, 0x80000100u)) goto loc_003BF75F; /* je: equal / zero */

loc_003BF742: ;
    if (CMP_EQ(eax, 0x80000800u)) goto loc_003BF75F; /* je: equal / zero */

loc_003BF749: ;
    if (CMP_LE(eax, 0xBFFFFFFFu)) goto loc_003BF77F; /* jle: less or equal (signed <=) */

loc_003BF750: ;
    if (CMP_G(eax, 0xC000000Eu)) goto loc_003BF77F; /* jg: greater (signed >) */

loc_003BF757: ;
    eax = 0xC0000185u;

loc_003BF75C: ;
    esp += 8; return; /* ret 4 */

loc_003BF75F: ;
    eax = 0xC000009Au;
    { RECOMP_SLICE_POINT(); goto loc_003BF75C; }

loc_003BF766: ;
    eax = 0xC0000120u;
    { RECOMP_SLICE_POINT(); goto loc_003BF75C; }

loc_003BF76D: ;
    if (CMP_EQ(eax, 0xC0000010u)) { RECOMP_SLICE_POINT(); goto loc_003BF757; } /* je: equal / zero */

loc_003BF774: ;
    if (TEST_Z(eax, eax)) goto loc_003BF78D; /* je: equal / zero */

loc_003BF778: ;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003BF786; /* je: equal / zero */

loc_003BF77F: ;
    eax = 0xC0000001u;
    { RECOMP_SLICE_POINT(); goto loc_003BF75C; }

loc_003BF786: ;
    eax = 0x103;
    { RECOMP_SLICE_POINT(); goto loc_003BF75C; }

loc_003BF78D: ;
    eax = 0; /* xor self */
    { RECOMP_SLICE_POINT(); goto loc_003BF75C; }

}

/**
 * sub_003BF791
 * Original: 0x003BF791 - 0x003BF797 (6 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF791(void)
{

loc_003BF791: ;
    eax = MEM32(0xF308F4);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF797
 * Original: 0x003BF797 - 0x003BF80D (118 bytes, 49 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF797(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BF797: ;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(0xF308F4);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ZX16(MEM16(0xF308A6));
    PUSH32(esp, edi);
    esi = esi + 0xF308A4;
    edi = 0; /* xor self */

loc_003BF7B2: ;
    SET_LO8(edx, MEM8(ecx));
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BF804; /* je: equal / zero */

loc_003BF7B8: ;
    eax = ZX8(LO8(edx));
    ecx = ecx + eax;
    if (CMP_AE(ecx, esi)) goto loc_003BF804; /* jae: above or equal (unsigned >=) */

loc_003BF7C1: ;
    SET_LO8(eax, MEM8(ecx + 1));
    if (CMP_NE(LO8(eax), 5)) goto loc_003BF7FC; /* jne: not equal / not zero */

loc_003BF7C8: ;
    SET_LO8(edx, MEM8(ecx + 3));
    SET_LO8(edx, LO8(edx) & 3);
    if (CMP_NE(LO8(edx), MEM8(ebp + 8))) goto loc_003BF7FC; /* jne: not equal / not zero */

loc_003BF7D3: ;
    if (CMP_EQ(MEM8(ebp + 8), 0)) goto loc_003BF7FC; /* je: equal / zero */

loc_003BF7D9: ;
    edx = 0; /* xor self */
    SET_LO8(edx, MEM8(ecx + 2));
    ebx = 0; /* xor self */
    edx = edx >> 7;
    edx = ~edx;
    edx = edx & 1;
    /* cmp MEM8(ebp + 0xC), LO8(ebx) - flags set for next jcc */
    SET_LO8(ebx, (CMP_EQ(MEM8(ebp + 0xC), LO8(ebx))) ? 1 : 0); /* sete */
    if (CMP_NE(edx, ebx)) goto loc_003BF7FC; /* jne: not equal / not zero */

loc_003BF7F2: ;
    SET_LO8(edx, MEM8(ebp + 0x10));
    MEM8(ebp + 0x10) = MEM8(ebp + 0x10) - 1;
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003BF802; /* je: equal / zero */

loc_003BF7FC: ;
    if (CMP_NE(LO8(eax), 4)) { RECOMP_SLICE_POINT(); goto loc_003BF7B2; } /* jne: not equal / not zero */

loc_003BF800: ;
    goto loc_003BF804;

loc_003BF802: ;
    edi = ecx;

loc_003BF804: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003BF80D
 * Original: 0x003BF80D - 0x003BF811 (4 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF80D(void)
{

loc_003BF80D: ;
    eax = MEM32(ecx + 0x14);
    esp += 4; return; /* ret */

}

/**
 * sub_003BF811
 * Original: 0x003BF811 - 0x003BF897 (134 bytes, 49 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF811(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF811: ;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = ecx;
    ebx = 0; /* xor self */
    if (CMP_NE(MEM8(edi), 5)) goto loc_003BF83F; /* jne: not equal / not zero */

loc_003BF81C: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF821); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BF821: ;
    ebx = eax;
    eax = MEM32(ebx + 8);
    if (TEST_Z(eax, eax)) goto loc_003BF83F; /* je: equal / zero */

loc_003BF82A: ;
    MEM32(edi + 8) = eax;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF83B); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003BF83B: ;
    eax = 0; /* xor self */
    goto loc_003BF892;

loc_003BF83F: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF879); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BF879: ;
    if (TEST_S(eax, eax)) goto loc_003BF88D; /* jl: less (signed <) */

loc_003BF87D: ;
    /* test ebx, ebx - flags set for next jcc */
    ecx = MEM32(esi + 0x10);
    MEM32(edi + 8) = ecx;
    if (TEST_Z(ebx, ebx)) goto loc_003BF88D; /* je: equal / zero */

loc_003BF887: ;
    ecx = MEM32(esi + 0x10);
    MEM32(ebx + 8) = ecx;

loc_003BF88D: ;
    MEM32(esi + 0x10) = MEM32(esi + 0x10) & 0;
    POP32(esp, esi);

loc_003BF892: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF897
 * Original: 0x003BF897 - 0x003BF903 (108 bytes, 38 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF897(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF897: ;
    PUSH32(esp, esi);
    esi = ecx;
    PUSH32(esp, edi);
    edi = MEM32(esi + 8);
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    if (CMP_NE(MEM8(esi), 5)) goto loc_003BF8D0; /* jne: not equal / not zero */

loc_003BF8A7: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8AC); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BF8AC: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8B3); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BF8B3: ;
    goto loc_003BF8C1;

loc_003BF8B5: ;
    if (CMP_EQ(MEM32(eax + 8), edi)) goto loc_003BF8F1; /* je: equal / zero */

loc_003BF8BA: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8C1); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BF8C1: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BF8B5; } /* jne: not equal / not zero */

loc_003BF8C5: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8CC); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BF8CC: ;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;

loc_003BF8D0: ;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 0x18) = MEM32(eax + 0x18) & 0;
    PUSH32(esp, eax);
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 0x10) = edi;
    eax = MEM32(esi + 0xC);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8EC); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BF8EC: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

loc_003BF8F1: ;
    eax = MEM32(esp + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF8FF); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003BF8FF: ;
    eax = 0; /* xor self */
    { RECOMP_SLICE_POINT(); goto loc_003BF8EC; }

}

/**
 * sub_003BF903
 * Original: 0x003BF903 - 0x003BF934 (49 bytes, 19 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF903(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF903: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF908); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BF908: ;
    if (TEST_Z(eax, eax)) goto loc_003BF931; /* je: equal / zero */

loc_003BF90C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ZX8(MEM8(esp + 0xC));
    esi = 0xFFFFFF7Fu;
    edi = edi & esi;

loc_003BF91A: ;
    ecx = ZX8(MEM8(eax + 4));
    ecx = ecx & esi;
    if (CMP_EQ(ecx, edi)) goto loc_003BF92F; /* je: equal / zero */

loc_003BF924: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF92B); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BF92B: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003BF91A; } /* jne: not equal / not zero */

loc_003BF92F: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BF931: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF934
 * Original: 0x003BF934 - 0x003BF97C (72 bytes, 25 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF934(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF934: ;
    eax = MEM32(esp + 4);
    PUSH32(esp, ebx);
    ebx = eax;
    ebx = ebx - MEM32(0xF308F8);
    PUSH32(esp, esi);
    esi = ecx;
    MEM8(eax + 3) = 0x80;
    ecx = ecx - MEM32(0xF308F8);
    ebx = (uint32_t)((int32_t)ebx >> 5);
    ecx = (uint32_t)((int32_t)ecx >> 5);
    MEM8(eax + 1) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF95E); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BF95E: ;
    if (TEST_NZ(eax, eax)) goto loc_003BF96E; /* jne: not equal / not zero */

loc_003BF962: ;
    MEM8(esi + 2) = LO8(ebx);
    goto loc_003BF977;

loc_003BF967: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF96E); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BF96E: ;
    if (CMP_NE(MEM8(eax + 3), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003BF967; } /* jne: not equal / not zero */

loc_003BF974: ;
    MEM8(eax + 3) = LO8(ebx);

loc_003BF977: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BF97C
 * Original: 0x003BF97C - 0x003BF9D8 (92 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF97C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BF97C: ;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    ebp = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF987); sub_003BDBDF(); /* call 0x003BDBDF */

loc_003BF987: ;
    esi = MEM32(esp + 0x14);
    edi = eax;
    /* cmp edi, esi - flags set for next jcc */
    SET_LO8(ebx, 1);
    if (CMP_NE(edi, esi)) goto loc_003BF9A1; /* jne: not equal / not zero */

loc_003BF993: ;
    SET_LO8(eax, MEM8(esi + 3));
    /* cmp LO8(eax), 0x80 - flags set for next jcc */
    MEM8(ebp + 2) = LO8(eax);
    if (CMP_NE(LO8(eax), 0x80)) goto loc_003BF9C7; /* jne: not equal / not zero */

loc_003BF99D: ;
    SET_LO8(ebx, 0); /* xor self */
    goto loc_003BF9C7;

loc_003BF9A1: ;
    if (TEST_Z(edi, edi)) goto loc_003BF9C7; /* je: equal / zero */

loc_003BF9A5: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF9AC); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BF9AC: ;
    if (CMP_EQ(eax, esi)) goto loc_003BF9BD; /* je: equal / zero */

loc_003BF9B0: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BF9B7); sub_003BDBF6(); /* call 0x003BDBF6 */

loc_003BF9B7: ;
    edi = eax;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003BF9A5; } /* jne: not equal / not zero */

loc_003BF9BD: ;
    if (TEST_Z(edi, edi)) goto loc_003BF9C7; /* je: equal / zero */

loc_003BF9C1: ;
    SET_LO8(eax, MEM8(esi + 3));
    MEM8(edi + 3) = LO8(eax);

loc_003BF9C7: ;
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
 * sub_003BF9D8
 * Original: 0x003BF9D8 - 0x003BFA4D (117 bytes, 41 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BF9D8(void)
{
    int _flags = 0; /* fallback flag var */

loc_003BF9D8: ;
    eax = MEM32(esp + 4);
    edx = MEM32(eax + 4);
    edx = ZX8(MEM8(edx + 4));
    edx = edx & 0x7F;
    edx--;
    /* cmp edx, 4 - flags set for next jcc */
    MEM32(ecx + 0x14) = edx;
    if (CMP_L(edx, 4)) goto loc_003BF9F8; /* jl: less (signed <) */

loc_003BF9EF: ;
    MEM32(ecx + 0x14) = 0x20;
    goto loc_003BFA4A;

loc_003BF9F8: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    edx = edx ^ 2;
    MEM32(ecx + 0x14) = edx;
    PUSH32(esp, edi);
    edi = MEM32(eax + esi * 4);
    if (CMP_NE(MEM8(edi), 1)) goto loc_003BFA28; /* jne: not equal / not zero */

loc_003BFA0C: ;
    if (CMP_EQ(esi, 1)) goto loc_003BFA48; /* je: equal / zero */

loc_003BFA11: ;
    if (CMP_EQ(MEM8(0x3BBD90), 0)) goto loc_003BFA1F; /* je: equal / zero */

loc_003BFA1A: ;
    if (CMP_EQ(esi, 2)) goto loc_003BFA48; /* je: equal / zero */

loc_003BFA1F: ;
    MEM32(ecx + 0x14) = 0x20;
    goto loc_003BFA48;

loc_003BFA28: ;
    if (CMP_BE(esi, 1)) goto loc_003BFA48; /* jbe: below or equal (unsigned <=) */

loc_003BFA2D: ;
    eax = MEM32(eax + 8);
    eax = ZX8(MEM8(eax + 4));
    eax = eax & 0x7F;
    eax--;
    if (CMP_A(eax, 3)) { RECOMP_SLICE_POINT(); goto loc_003BFA1F; } /* ja: above (unsigned >) */

loc_003BFA3D: ;
    if (CMP_NE(eax, 2)) goto loc_003BFA48; /* jne: not equal / not zero */

loc_003BFA42: ;
    edx = edx + 0x10;
    MEM32(ecx + 0x14) = edx;

loc_003BFA48: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003BFA4A: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BFA4D
 * Original: 0x003BFA4D - 0x003BFB37 (234 bytes, 89 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFA4D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFA4D: ;
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
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003BFA8D; /* je: equal / zero */

loc_003BFA64: ;
    if (CMP_NE(MEM32(esi + 8), ebx)) goto loc_003BFA8D; /* jne: not equal / not zero */

loc_003BFA69: ;
    edx = ebp + -12;
    MEM32(ebp + -8) = edx;
    MEM32(ebp + -12) = edx;
    edx = ebp + -20;
    MEM8(ebp + -1) = 1;
    MEM8(ebp + -20) = LO8(ebx);
    MEM8(ebp + -18) = 4;
    MEM32(ebp + -16) = ebx;
    MEM32(esi + 8) = 0x3BF674;
    MEM32(esi + 0xC) = edx;

loc_003BFA8D: ;
    eax = ZX8(LO8(eax));
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003BFAE3; /* je: equal / zero */

loc_003BFA94: ;
    eax = eax - 7;
    if ((eax == 0)) goto loc_003BFADB; /* je: equal / zero */

loc_003BFA99: ;
    eax = eax - 0x37;
    if ((eax == 0)) goto loc_003BFAC5; /* je: equal / zero */

loc_003BFA9E: ;
    eax = eax - 3;
    if ((eax == 0)) goto loc_003BFABD; /* je: equal / zero */

loc_003BFAA3: ;
    eax = eax - 0x3F;
    if ((eax == 0)) goto loc_003BFAB5; /* je: equal / zero */

loc_003BFAA8: ;
    eax = eax - 0x41;
    if ((eax != 0)) goto loc_003BFAF8; /* jne: not equal / not zero */

loc_003BFAAD: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFAB3); sub_003BF897(); /* call 0x003BF897 */

loc_003BFAB3: ;
    goto loc_003BFB05;

loc_003BFAB5: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFABB); sub_003BF811(); /* call 0x003BF811 */

loc_003BFABB: ;
    goto loc_003BFB05;

loc_003BFABD: ;
    eax = ecx + 0x18;
    MEM32(esi + 0x18) = eax;
    goto loc_003BFAF8;

loc_003BFAC5: ;
    if (CMP_NE(MEM32(esi + 0x10), ebx)) goto loc_003BFAD0; /* jne: not equal / not zero */

loc_003BFACA: ;
    eax = MEM32(ecx + 8);
    MEM32(esi + 0x10) = eax;

loc_003BFAD0: ;
    if (CMP_NE(MEM8(esi + 0x29), 9)) goto loc_003BFAF8; /* jne: not equal / not zero */

loc_003BFAD6: ;
    MEM32(ecx + 0x18) = ebx;
    goto loc_003BFAF8;

loc_003BFADB: ;
    SET_LO8(eax, MEM8(ecx + 5));
    MEM8(esi + 0x14) = LO8(eax);
    goto loc_003BFAF8;

loc_003BFAE3: ;
    SET_LO8(eax, MEM8(ecx + 5));
    MEM8(esi + 0x14) = LO8(eax);
    eax = ecx + 0x18;
    MEM32(esi + 0x18) = eax;
    SET_LO8(eax, MEM8(ecx + 4));
    SET_LO8(eax, LO8(eax) >> 7);
    MEM8(esi + 0x1E) = LO8(eax);

loc_003BFAF8: ;
    eax = MEM32(ecx + 0xC);
    PUSH32(esp, esi);
    eax = eax + 0x18;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFB05); sub_003C25B3(); /* call 0x003C25B3 */

loc_003BFB05: ;
    if (CMP_EQ(MEM8(ebp + -1), LO8(ebx))) goto loc_003BFB31; /* je: equal / zero */

loc_003BFB0A: ;
    ecx = eax;
    ecx = ecx & 0xC0000000u;
    if (CMP_NE(ecx, 0x40000000)) goto loc_003BFB2B; /* jne: not equal / not zero */

loc_003BFB1A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = ebp + -20;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD4); g_seh_ebp = ebp; PUSH32(esp, 0x3BFB28); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFB28: ;
    eax = MEM32(esi + 4);

loc_003BFB2B: ;
    MEM32(esi + 8) = ebx;
    MEM32(esi + 0xC) = ebx;

loc_003BFB31: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003BFB37
 * Original: 0x003BFB37 - 0x003BFB79 (66 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFB37(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFB37: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    eax = esi + 4;
    edx = MEM32(eax);
    if (CMP_NE(MEM8(edx), 1)) goto loc_003BFB51; /* jne: not equal / not zero */

loc_003BFB46: ;
    SET_LO8(edx, MEM8(edx + 4));
    SET_LO8(edx, LO8(edx) & 0x7F);
    if (CMP_EQ(LO8(edx), 1)) goto loc_003BFB5A; /* je: equal / zero */

loc_003BFB51: ;
    MEM32(ecx + 0x14) = 0x20;
    goto loc_003BFB75;

loc_003BFB5A: ;
    edx = MEM32(esp + 0xC);
    if (CMP_NE(edx, 1)) goto loc_003BFB69; /* jne: not equal / not zero */

loc_003BFB63: ;
    MEM32(ecx + 0x14) = MEM32(ecx + 0x14) & 0;
    goto loc_003BFB75;

loc_003BFB69: ;
    esi = MEM32(esi);
    edx--;
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFB75); sub_003BF9D8(); /* call 0x003BF9D8 */

loc_003BFB75: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BFB79
 * Original: 0x003BFB79 - 0x003BFBC4 (75 bytes, 32 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFB79(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFB79: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = ecx;
    PUSH32(esp, 5);
    POP32(esp, esi);
    MEM32(ebp + -4) = edi;

loc_003BFB89: ;
    ecx = MEM32(ebp + esi * 4 + -24);
    esi--;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFB93); sub_003BDBC8(); /* call 0x003BDBC8 */

loc_003BFB93: ;
    /* cmp MEM8(eax), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(eax), 0)); /* latched */
    MEM32(ebp + esi * 4 + -24) = eax;
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003BFB89; } /* jne: not equal / not zero */

loc_003BFB9C: ;
    edx = MEM32(0x3C5000);
    PUSH32(esp, 5);
    POP32(esp, eax);
    eax = eax - esi;
    /* test MEM8(edx), 1 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(edx), 1)); /* latched */
    ecx = ebp + esi * 4 + -24;
    PUSH32(esp, eax);
    PUSH32(esp, ecx);
    ecx = edi;
    if (_rcc0) goto loc_003BFBBB; /* je: equal / zero */

loc_003BFBB4: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFBB9); sub_003BFB37(); /* call 0x003BFB37 */

loc_003BFBB9: ;
    goto loc_003BFBC0;

loc_003BFBBB: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFBC0); sub_003BF9D8(); /* call 0x003BF9D8 */

loc_003BFBC0: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFBC4
 * Original: 0x003BFBC4 - 0x003BFBFF (59 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFBC4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFBC4: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;
    if (TEST_Z(MEM8(esi + 0xD), 2)) goto loc_003BFBE4; /* je: equal / zero */

loc_003BFBD3: ;
    eax = esi + 0xB8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFBE4); sub_003BF685(); /* call 0x003BF685 */

loc_003BFBE4: ;
    if (TEST_Z(MEM8(esi + 0xD), 4)) goto loc_003BFBFB; /* je: equal / zero */

loc_003BFBEA: ;
    eax = esi + 0xE8;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFBFB); sub_003BF685(); /* call 0x003BF685 */

loc_003BFBFB: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003BFBFF
 * Original: 0x003BFBFF - 0x003BFD05 (262 bytes, 68 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFBFF(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFBFF: ;
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = ecx;
    /* test MEM8(esi + 0xD), 1 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0xD), 1)); /* latched */
    ebp = MEM32(esi + 8);
    PUSH32(esp, edi);
    edi = edx;
    if (_rcc0) goto loc_003BFC1D; /* je: equal / zero */

loc_003BFC0F: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BFC19); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFC19: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BFC1D: ;
    eax = MEM32(esi + 0xC);
    if (TEST_Z(LO8(eax), 6)) goto loc_003BFC32; /* je: equal / zero */

loc_003BFC24: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xC000009Du);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3BFC2D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFC2D: ;
    goto loc_003BFD01;

loc_003BFC32: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFC72); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BFC72: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BFC91); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFC91: ;
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3C00E6;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFD00); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BFD00: ;
    POP32(esp, ebx);

loc_003BFD01: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 4; return; /* ret */

}

/**
 * sub_003BFD05
 * Original: 0x003BFD05 - 0x003BFD89 (132 bytes, 48 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFD05(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFD05: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    edi = 0; /* xor self */
    if (TEST_Z(MEM8(esi + 0xD), 1)) goto loc_003BFD21; /* je: equal / zero */

loc_003BFD13: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3BFD1D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFD1D: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003BFD21: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    eax = MEM32(esp + 0xC);
    eax = MEM32(eax + 4);
    if (CMP_GE(eax & eax, 0)) goto loc_003BFD38; /* jge: greater or equal (signed >=) */

loc_003BFD30: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFD36); sub_003BF725(); /* call 0x003BF725 */

loc_003BFD36: ;
    edi = eax;

loc_003BFD38: ;
    /* cmp MEM32(esi + 0x5F), 0x53425355 - flags set for next jcc */
    eax = 0xC0000001u;
    if (CMP_EQ(MEM32(esi + 0x5F), 0x53425355)) goto loc_003BFD48; /* je: equal / zero */

loc_003BFD46: ;
    edi = eax;

loc_003BFD48: ;
    ecx = MEM32(esi + 0x63);
    if (CMP_EQ(ecx, MEM32(esi + 0x44))) goto loc_003BFD52; /* je: equal / zero */

loc_003BFD50: ;
    edi = eax;

loc_003BFD52: ;
    SET_LO8(ecx, MEM8(esi + 0x6B));
    if (CMP_NE(LO8(ecx), 2)) goto loc_003BFD5C; /* jne: not equal / not zero */

loc_003BFD5A: ;
    edi = eax;

loc_003BFD5C: ;
    if (CMP_NE(LO8(ecx), 1)) goto loc_003BFD66; /* jne: not equal / not zero */

loc_003BFD61: ;
    edi = 0xC000003Eu;

loc_003BFD66: ;
    eax = 0xC0000000u;
    ecx = edi;
    ecx = ecx & eax;
    if (CMP_NE(ecx, eax)) goto loc_003BFD7E; /* jne: not equal / not zero */

loc_003BFD73: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFD7C); sub_003BFBFF(); /* call 0x003BFBFF */

loc_003BFD7C: ;
    goto loc_003BFD84;

loc_003BFD7E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3BFD84); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFD84: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BFD89
 * Original: 0x003BFD89 - 0x003BFE12 (137 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFD89(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFD89: ;
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
    MEM32(esi + 0xC0) = 0x3BFD05;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xCC) = 0xD;
    MEM8(esi + 0xD4) = 2;
    MEM8(esi + 0xD5) = 0;
    MEM8(esi + 0xD6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFDF1); sub_0033A5D0(); /* call 0x0033A5D0 */

loc_003BFDF1: ;
    ecx = esi + 0x98;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, edx);
    PUSH32(esp, eax);
    eax = esi + 0x70;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BFE04); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFE04: ;
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFE0F); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BFE0F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003BFE12
 * Original: 0x003BFE12 - 0x003BFF0F (253 bytes, 80 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFE12(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFE12: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0xC);
    edx = 0x800;
    if (TEST_Z(edx, eax)) goto loc_003BFE61; /* je: equal / zero */

loc_003BFE23: ;
    eax = eax & 0xFFFFF7FFu;
    ecx = esi + 0xB8;
    /* cmp MEM32(esp + 8), ecx - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM32(esp + 8), ecx)); /* latched */
    MEM32(esi + 0xC) = eax;
    if (_rcc0) goto loc_003BFE3F; /* jne: not equal / not zero */

loc_003BFE37: ;
    ecx = MEM32(esi + 0xEC);
    goto loc_003BFE45;

loc_003BFE3F: ;
    ecx = MEM32(esi + 0xBC);

loc_003BFE45: ;
    eax = eax & 0xFFFFF9FFu;
    PUSH32(esp, ecx);
    MEM32(esi + 0xC) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFE53); sub_003BF725(); /* call 0x003BF725 */

loc_003BFE53: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFE5C); sub_003BFBFF(); /* call 0x003BFBFF */

loc_003BFE5C: ;
    goto loc_003BFF0B;

loc_003BFE61: ;
    ecx = MEM32(esp + 8);
    /* cmp MEM32(ecx + 4), 0 - flags set for next jcc */
    _rcc0 = (CMP_L(MEM32(ecx + 4), 0)); /* latched */
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003BFEB5; /* jl: less (signed <) */

loc_003BFE6C: ;
    if (TEST_NZ(LO8(eax), 6)) goto loc_003BFEB5; /* jne: not equal / not zero */

loc_003BFE70: ;
    edx = MEM32(esi + 0x6C);
    if (CMP_AE(edx, MEM32(esi + 0x2C))) goto loc_003BFE84; /* jae: above or equal (unsigned >=) */

loc_003BFE78: ;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFE7F); sub_003BFF0F(); /* call 0x003BFF0F */

loc_003BFE7F: ;
    goto loc_003BFF0A;

loc_003BFE84: ;
    edi = esi + 0xB8;
    /* cmp ecx, edi - flags set for next jcc */
    edx = 0x200;
    if (CMP_NE(ecx, edi)) goto loc_003BFE9D; /* jne: not equal / not zero */

loc_003BFE93: ;
    eax = eax & 0xFFFFFDFFu;
    /* test HI8(eax), 4 - flags set for next jcc */
    goto loc_003BFEA4;

loc_003BFE9D: ;
    eax = eax & 0xFFFFFBFFu;
    /* test edx, eax - flags set for next jcc */

loc_003BFEA4: ;
    MEM32(esi + 0xC) = eax;
    if (TEST_NZ(edx, eax)) goto loc_003BFF0A; /* jne: not equal / not zero */

loc_003BFEA9: ;
    MEM32(esi + 0xC) = MEM32(esi + 0xC) | edx;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFEB3); sub_003BFD89(); /* call 0x003BFD89 */

loc_003BFEB3: ;
    goto loc_003BFF0A;

loc_003BFEB5: ;
    edi = esi + 0xB8;
    if (CMP_NE(ecx, edi)) goto loc_003BFEE4; /* jne: not equal / not zero */

loc_003BFEBF: ;
    eax = eax & 0xFFFFFDFFu;
    /* test HI8(eax), 4 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_Z(HI8(eax), 4)) goto loc_003BFEF9; /* je: equal / zero */

loc_003BFECC: ;
    eax = eax | edx;
    MEM32(esi + 0xC) = eax;
    eax = esi + 0xE8;
    PUSH32(esp, eax);

loc_003BFED8: ;
    eax = MEM32(esi + 8);
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFEE2); sub_003BF685(); /* call 0x003BF685 */

loc_003BFEE2: ;
    goto loc_003BFF0A;

loc_003BFEE4: ;
    eax = eax & 0xFFFFFBFFu;
    /* test HI8(eax), 2 - flags set for next jcc */
    MEM32(esi + 0xC) = eax;
    if (TEST_Z(HI8(eax), 2)) goto loc_003BFEF9; /* je: equal / zero */

loc_003BFEF1: ;
    eax = eax | edx;
    MEM32(esi + 0xC) = eax;
    PUSH32(esp, edi);
    { RECOMP_SLICE_POINT(); goto loc_003BFED8; }

loc_003BFEF9: ;
    PUSH32(esp, MEM32(ecx + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFF01); sub_003BF725(); /* call 0x003BF725 */

loc_003BFF01: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFF0A); sub_003BFBFF(); /* call 0x003BFBFF */

loc_003BFF0A: ;
    POP32(esp, edi);

loc_003BFF0B: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003BFF0F
 * Original: 0x003BFF0F - 0x003BFFD5 (198 bytes, 73 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFF0F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003BFF0F: ;
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
    if (CMP_NE(LO8(ecx), 1)) goto loc_003BFF30; /* jne: not equal / not zero */

loc_003BFF27: ;
    ebx = MEM32(edi + 0x20);
    MEM8(ebp + -1) = 2;
    goto loc_003BFF37;

loc_003BFF30: ;
    ebx = MEM32(edi + 0x24);
    MEM8(ebp + -1) = 1;

loc_003BFF37: ;
    /* test LO8(eax), 4 - flags set for next jcc */
    edx = MEM32(edi + 0x6C);
    if (TEST_Z(LO8(eax), 4)) goto loc_003BFF66; /* je: equal / zero */

loc_003BFF3E: ;
    ecx = MEM32(edi + 0x38);
    if (CMP_AE(edx, ecx)) goto loc_003BFF4D; /* jae: above or equal (unsigned >=) */

loc_003BFF45: ;
    eax = edx + 0xF2D814;
    goto loc_003BFF6B;

loc_003BFF4D: ;
    eax = MEM32(edi + 0x3C);
    if (CMP_AE(edx, eax)) goto loc_003BFF5B; /* jae: above or equal (unsigned >=) */

loc_003BFF54: ;
    eax = MEM32(edi + 0x28);
    eax = eax - ecx;
    goto loc_003BFF69;

loc_003BFF5B: ;
    ecx = ecx - eax;
    eax = ecx + edx + 0xF2D814;
    goto loc_003BFF6B;

loc_003BFF66: ;
    eax = MEM32(edi + 0x28);

loc_003BFF69: ;
    eax = eax + edx;

loc_003BFF6B: ;
    ecx = MEM32(edi + 0x2C);
    ecx = ecx - edx;
    if (CMP_BE(ecx, 0x400)) goto loc_003BFF7D; /* jbe: below or equal (unsigned <=) */

loc_003BFF78: ;
    ecx = 0x400;

loc_003BFF7D: ;
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
    MEM32(esi + 8) = 0x3BFE12;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = ebx;
    MEM8(esi + 0x1D) = 0;
    MEM8(esi + 0x1E) = 0;
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3BFFC5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003BFFC5: ;
    eax = MEM32(edi + 8);
    ecx = MEM32(eax);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3BFFD0); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003BFFD0: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003BFFD5
 * Original: 0x003BFFD5 - 0x003C003D (104 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003BFFD5(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003BFFD5: ;
    eax = MEM32(esp + 4);
    ecx = 0; /* xor self */
    /* cmp MEM32(eax + 4), ecx - flags set for next jcc */
    _rcc0 = (CMP_L(MEM32(eax + 4), ecx)); /* latched */
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    if (_rcc0) goto loc_003C0024; /* jl: less (signed <) */

loc_003BFFE5: ;
    if (TEST_NZ(MEM8(esi + 0xC), 6)) goto loc_003C0024; /* jne: not equal / not zero */

loc_003BFFEB: ;
    if (CMP_EQ(MEM32(esi + 0x28), ecx)) goto loc_003C001B; /* je: equal / zero */

loc_003BFFF0: ;
    MEM32(esi + 0x6C) = ecx;
    ecx = esi + 0xB8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0000); sub_003BFF0F(); /* call 0x003BFF0F */

loc_003C0000: ;
    eax = MEM32(esi + 0x6C);
    if (CMP_AE(eax, MEM32(esi + 0x2C))) goto loc_003C0039; /* jae: above or equal (unsigned >=) */

loc_003C0008: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 4;
    ecx = esi + 0xE8;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0019); sub_003BFF0F(); /* call 0x003BFF0F */

loc_003C0019: ;
    goto loc_003C0039;

loc_003C001B: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0022); sub_003BFD89(); /* call 0x003BFD89 */

loc_003C0022: ;
    goto loc_003C0039;

loc_003C0024: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFD;
    PUSH32(esp, MEM32(eax + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0030); sub_003BF725(); /* call 0x003BF725 */

loc_003C0030: ;
    edx = eax;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0039); sub_003BFBFF(); /* call 0x003BFBFF */

loc_003C0039: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C003D
 * Original: 0x003C003D - 0x003C00E6 (169 bytes, 44 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C003D(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C003D: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3C0086); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0086: ;
    ecx = MEM32(esi + 0x24);
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 2;
    eax = esi + 0xB8;
    MEM8(eax) = 0x28;
    PUSH32(esp, eax);
    eax = MEM32(esi + 8);
    MEM8(esi + 0xB9) = 0x41;
    MEM32(esi + 0xC0) = 0x3BFFD5;
    MEM32(esi + 0xC4) = esi;
    MEM32(esi + 0xC8) = ecx;
    MEM32(esi + 0xD0) = edi;
    MEM32(esi + 0xCC) = 0x1F;
    MEM8(esi + 0xD4) = 1;
    MEM8(esi + 0xD5) = 0;
    MEM8(esi + 0xD6) = 0;
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C00E3); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C00E3: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C00E6
 * Original: 0x003C00E6 - 0x003C02E6 (512 bytes, 120 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C00E6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C00E6: ;
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
    if (TEST_Z(HI8(eax), 1)) goto loc_003C0116; /* je: equal / zero */

loc_003C0108: ;
    eax = esi + 0x70;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C0112); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0112: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) & 0xFE;

loc_003C0116: ;
    eax = MEM32(esi + 0xC);
    if (TEST_Z(LO8(eax), 6)) goto loc_003C0124; /* je: equal / zero */

loc_003C011D: ;
    PUSH32(esp, 0xC000009Du);
    goto loc_003C0185;

loc_003C0124: ;
    edx = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_GE(MEM32(edx + 4), ecx)) goto loc_003C0140; /* jge: greater or equal (signed >=) */

loc_003C012F: ;
    eax = eax & 0xFFFF8FFFu;
    MEM32(esi + 0xC) = eax;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C013E); sub_003BE075(); /* call 0x003BE075 */

loc_003C013E: ;
    { RECOMP_SLICE_POINT(); goto loc_003C011D; }

loc_003C0140: ;
    if (CMP_EQ(edi, 0x1000)) goto loc_003C020F; /* je: equal / zero */

loc_003C014C: ;
    if (CMP_EQ(edi, 0x2000)) goto loc_003C018E; /* je: equal / zero */

loc_003C0154: ;
    if (CMP_NE(edi, 0x4000)) goto loc_003C02E0; /* jne: not equal / not zero */

loc_003C0160: ;
    eax = eax & 0xFFFFBFFFu;
    MEM32(esi + 0xC) = eax;
    SET_LO8(eax, MEM8(esi + 0x36));
    SET_LO8(ecx, LO8(eax));
    SET_LO8(ecx, LO8(ecx) - 1);
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    MEM8(esi + 0x36) = LO8(ecx);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C0182; /* je: equal / zero */

loc_003C0176: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C017D); sub_003C003D(); /* call 0x003C003D */

loc_003C017D: ;
    goto loc_003C02E0;

loc_003C0182: ;
    PUSH32(esp, MEM32(esi + 0x6C));

loc_003C0185: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3C0189); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0189: ;
    goto loc_003C02E0;

loc_003C018E: ;
    eax = eax & 0xFFFFDFFFu;
    eax = eax | 0x4000;
    edi = esi + 0xB8;
    MEM32(esi + 0xC) = eax;
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3C00E6;
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
    goto loc_003C02B5;

loc_003C020F: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C024D); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C024D: ;
    eax = 0; /* xor self */
    MEM8(edi) = 0x30;
    MEM8(esi + 0xB9) = 0x40;
    MEM32(esi + 0xC0) = 0x3C00E6;
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

loc_003C02B5: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3C02D4); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C02D4: ;
    MEM8(esi + 0xD) = MEM8(esi + 0xD) | 2;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C02E0); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C02E0: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C02E6
 * Original: 0x003C02E6 - 0x003C0314 (46 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C02E6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C02E6: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C02F0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C02F0: ;
    /* test MEM8(esi + 0xC), 6 - flags set for next jcc */
    SET_LO8(ebx, LO8(eax));
    if (TEST_Z(MEM8(esi + 0xC), 6)) goto loc_003C0303; /* je: equal / zero */

loc_003C02F8: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xC000009Du);
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(esi + 0x30); g_seh_ebp = ebp; PUSH32(esp, 0x3C0301); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0301: ;
    goto loc_003C030A;

loc_003C0303: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C030A); sub_003C003D(); /* call 0x003C003D */

loc_003C030A: ;
    POP32(esp, esi);
    SET_LO8(ecx, LO8(ebx));
    POP32(esp, ebx);
    g_seh_ebp = ebp; RECOMP_ITAIL(MEM32(0x3C4FC4)); return; /* indirect tail jmp */

}

/**
 * sub_003C0314
 * Original: 0x003C0314 - 0x003C032F (27 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0314(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0314: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30988);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    eax = 0xFD050F80u;
    PUSH32(esp, eax);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3C032E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C032E: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C032F
 * Original: 0x003C032F - 0x003C0340 (17 bytes, 4 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C032F(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C032F: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, 0xF30928);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C033D); sub_003BF685(); /* call 0x003BF685 */

loc_003C033D: ;
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C0340
 * Original: 0x003C0340 - 0x003C0363 (35 bytes, 12 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0340(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0340: ;
    PUSH32(esp, esi);
    esi = ecx;
    ecx = MEM32(esi);
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C034C); sub_003BF69C(); /* call 0x003BF69C */

loc_003C034C: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0353); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C0353: ;
    MEM32(esi) = MEM32(esi) & 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C0363
 * Original: 0x003C0363 - 0x003C03CD (106 bytes, 42 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0363(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0363: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebx = 0; /* xor self */
    ebp = 0; /* xor self */
    /* cmp MEM16(0xF30908), LO16(ebx) - flags set for next jcc */
    _rcc0 = (CMP_BE(MEM16(0xF30908), LO16(ebx))); /* latched */
    PUSH32(esp, edi);
    MEM32(esp + 0xC) = edx;
    edi = ecx;
    if (_rcc0) goto loc_003C03C6; /* jbe: below or equal (unsigned <=) */

loc_003C037A: ;
    PUSH32(esp, esi);

loc_003C037B: ;
    eax = MEM32(0xF3090C);
    esi = ZX8(LO8(ebx));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x16);
    eax = eax + esi;
    if (TEST_Z(MEM8(eax + 4), 1)) goto loc_003C03B6; /* je: equal / zero */

loc_003C038E: ;
    ecx = MEM32(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0395); sub_003BF80D(); /* call 0x003BF80D */

loc_003C0395: ;
    if (CMP_NE(eax, MEM32(esp + 0x10))) goto loc_003C03B6; /* jne: not equal / not zero */

loc_003C039B: ;
    eax = MEM32(0xF3090C);
    eax = eax + esi;
    if (CMP_NE(MEM32(eax + 0xE), edi)) goto loc_003C03B6; /* jne: not equal / not zero */

loc_003C03A7: ;
    SET_LO8(ecx, MEM8(eax + 4));
    if (TEST_Z(LO8(ecx), 8)) goto loc_003C03B6; /* je: equal / zero */

loc_003C03AF: ;
    if (TEST_NZ(LO8(ecx), 2)) goto loc_003C03B6; /* jne: not equal / not zero */

loc_003C03B4: ;
    ebp = eax;

loc_003C03B6: ;
    SET_LO8(ebx, LO8(ebx) + 1);
    SET_LO16(eax, ZX8(LO8(ebx)));
    if (CMP_B(LO16(eax), MEM16(0xF30908))) { RECOMP_SLICE_POINT(); goto loc_003C037B; } /* jb: below (unsigned <) */

loc_003C03C5: ;
    POP32(esp, esi);

loc_003C03C6: ;
    POP32(esp, edi);
    eax = ebp;
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C03CD
 * Original: 0x003C03CD - 0x003C0478 (171 bytes, 62 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C03CD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C03CD: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C03F1); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C03F1: ;
    if (TEST_S(eax, eax)) goto loc_003C0473; /* jl: less (signed <) */

loc_003C03F5: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0428); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0428: ;
    if (TEST_S(eax, eax)) goto loc_003C0473; /* jl: less (signed <) */

loc_003C042C: ;
    ecx = MEM32(esi + 0x62);
    MEM32(esi + 0xC) = ecx;
    ecx = MEM32(ebp + -4);
    if (TEST_Z(MEM8(ecx), 2)) goto loc_003C0473; /* je: equal / zero */

loc_003C043A: ;
    if (CMP_EQ(MEM8(edi + 9), 0)) goto loc_003C0473; /* je: equal / zero */

loc_003C0440: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0469); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0469: ;
    if (TEST_S(eax, eax)) goto loc_003C0473; /* jl: less (signed <) */

loc_003C046D: ;
    ecx = MEM32(esi + 0x62);
    MEM32(esi + 0x10) = ecx;

loc_003C0473: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0478
 * Original: 0x003C0478 - 0x003C0529 (177 bytes, 54 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0478(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0478: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    /* test MEM8(esi + 0xA2), 2 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0xA2), 2)); /* latched */
    eax = MEM32(esi);
    ecx = MEM32(eax);
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003C04A9; /* je: equal / zero */

loc_003C048B: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0xC3;
    MEM32(eax + 8) = 0x3C0478;
    MEM32(eax + 0xC) = esi;
    MEM8(esi + 0xA2) = MEM8(esi + 0xA2) & 0xFD;
    goto loc_003C04F3;

loc_003C04A9: ;
    edi = 0; /* xor self */
    if (CMP_EQ(MEM32(esi + 0xC), edi)) goto loc_003C04D0; /* je: equal / zero */

loc_003C04B0: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 8) = 0x3C0478;
    MEM32(eax + 0xC) = esi;
    edx = MEM32(esi + 0xC);
    MEM32(eax + 0x10) = edx;
    MEM32(esi + 0xC) = edi;
    goto loc_003C04F3;

loc_003C04D0: ;
    if (CMP_EQ(MEM32(esi + 0x10), edi)) goto loc_003C04FB; /* je: equal / zero */

loc_003C04D5: ;
    eax = MEM32(esp + 0xC);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0x43;
    MEM32(eax + 8) = 0x3C0478;
    MEM32(eax + 0xC) = esi;
    edx = MEM32(esi + 0x10);
    MEM32(eax + 0x10) = edx;
    MEM32(esi + 0x10) = edi;

loc_003C04F3: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C04F9); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C04F9: ;
    goto loc_003C0524;

loc_003C04FB: ;
    MEM32(eax + 0x12) = edi;
    MEM32(esi) = edi;
    if (TEST_Z(MEM8(eax + 4), 2)) goto loc_003C050D; /* je: equal / zero */

loc_003C0506: ;
    ecx = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C050D); sub_003C0340(); /* call 0x003C0340 */

loc_003C050D: ;
    if (TEST_Z(MEM8(esi + 0xA2), 1)) goto loc_003C0524; /* je: equal / zero */

loc_003C0516: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(esi + 0x9E));
    { uint32_t _icall_t = MEM32(0x3C4FD0); g_seh_ebp = ebp; PUSH32(esp, 0x3C0524); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0524: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0529
 * Original: 0x003C0529 - 0x003C066F (326 bytes, 106 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0529(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0529: ;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0xC);
    /* test MEM8(ebx + 0xA2), 1 - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM8(ebx + 0xA2), 1)); /* latched */
    PUSH32(esp, edi);
    edi = MEM32(ebx);
    if (_rcc0) goto loc_003C0581; /* jne: not equal / not zero */

loc_003C053A: ;
    SET_LO8(eax, MEM8(edi + 4));
    if (TEST_NZ(LO8(eax), 2)) goto loc_003C0581; /* jne: not equal / not zero */

loc_003C0541: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ecx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ecx)) goto loc_003C0586; /* jl: less (signed <) */

loc_003C054D: ;
    SET_LO8(eax, LO8(eax) & 0xF);
    MEM8(edi + 4) = LO8(eax);
    eax = MEM32(edi + 0xE);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0x3C055A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C055A: ;
    MEM8(ebx + 0xA2) = MEM8(ebx + 0xA2) | 0x10;
    MEM32(ebx + 8) = MEM32(ebx + 8) + 1;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    eax = ZX8(MEM8(edi + 0xC));
    MEM32(esi + 0x14) = eax;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003C0580; /* je: equal / zero */

loc_003C0578: ;
    ecx = MEM32(edi);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0580); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0580: ;
    POP32(esp, esi);

loc_003C0581: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

loc_003C0586: ;
    MEM32(esi + 0x10) = ecx;
    MEM32(esi + 0x18) = ecx;
    MEM32(esi + 0x14) = ecx;
    MEM16(esi + 0x2A) = LO16(ecx);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3C05E5;
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
    if (CMP_NE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003C0578; } /* jne: not equal / not zero */

loc_003C05DC: ;
    ecx = MEM32(edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C05E3); sub_003BE075(); /* call 0x003BE075 */

loc_003C05E3: ;
    { RECOMP_SLICE_POINT(); goto loc_003C0580; }

    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    ebx = MEM32(esi);
    if (TEST_NZ(MEM8(ebx + 4), 2)) goto loc_003C066A; /* jne: not equal / not zero */

loc_003C05F3: ;
    if (TEST_NZ(MEM8(esi + 0xA2), 1)) goto loc_003C066A; /* jne: not equal / not zero */

loc_003C05FC: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    if (CMP_L(MEM32(edi + 4), 0)) goto loc_003C0662; /* jl: less (signed <) */

loc_003C0607: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0;
    MEM8(edi) = 0x18;
    MEM8(edi + 1) = 5;
    eax = MEM32(esi + 0xC);
    MEM32(edi + 0x10) = eax;
    MEM32(edi + 0x14) = 4;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0627); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0627: ;
    eax = MEM32(esi + 0xC);
    MEM32(esi + 0x62) = eax;
    eax = esi + 0x32;
    MEM8(esi + 0x52) = 0x28;
    MEM8(esi + 0x53) = 0x41;
    MEM32(esi + 0x5A) = 0x3C0529;
    MEM32(esi + 0x5E) = esi;
    MEM32(esi + 0x6A) = eax;
    eax = ZX8(MEM8(ebx + 0xC));
    MEM32(esi + 0x66) = eax;
    MEM8(esi + 0x6E) = 2;
    MEM8(esi + 0x6F) = 1;
    MEM8(esi + 0x70) = 0;
    ecx = MEM32(ebx);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0660); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0660: ;
    goto loc_003C0669;

loc_003C0662: ;
    ecx = MEM32(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0669); sub_003BE075(); /* call 0x003BE075 */

loc_003C0669: ;
    POP32(esp, edi);

loc_003C066A: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C066F
 * Original: 0x003C066F - 0x003C06C1 (82 bytes, 40 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C066F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C066F: ;
    eax = ecx;
    ecx = MEM32(eax + 0x66);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    /* cmp ecx, 2 - flags set for next jcc */
    edx = eax + 0x14;
    if (CMP_B(ecx, 2)) goto loc_003C06BF; /* jb: below (unsigned <) */

loc_003C067F: ;
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

loc_003C069F: ;
    if (CMP_AE(MEM8(eax), 0x20)) goto loc_003C06A9; /* jae: above or equal (unsigned >=) */

loc_003C06A4: ;
    MEM8(eax) = 0;
    goto loc_003C06AC;

loc_003C06A9: ;
    ebx = 0; /* xor self */
    ebx++;

loc_003C06AC: ;
    eax++;
    ecx--;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C069F; } /* jne: not equal / not zero */

loc_003C06B0: ;
    if (TEST_NZ(ebx, ebx)) goto loc_003C06B9; /* jne: not equal / not zero */

loc_003C06B4: ;
    if (TEST_Z(MEM8(edx), 0x3F)) goto loc_003C06BF; /* je: equal / zero */

loc_003C06B9: ;
    POP32(esp, ebx);
    g_seh_ebp = ebp; sub_002C3586(); return; /* tail jmp 0x002C3586 */

loc_003C06BF: ;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C06C1
 * Original: 0x003C06C1 - 0x003C06E5 (36 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06C1(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C06C1: ;
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
    g_seh_ebp = ebp; sub_002C3586(); return; /* tail jmp 0x002C3586 */

}

/**
 * sub_003C06E5
 * Original: 0x003C06E5 - 0x003C0712 (45 bytes, 20 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C06E5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C06E5: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ecx + 4));
    esi = edx;
    edi = MEM32(esi + 0xC);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C06F4); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C06F4: ;
    /* test edi, edi - flags set for next jcc */
    MEM32(esi) = eax;
    if (TEST_Z(edi, edi)) goto loc_003C070F; /* je: equal / zero */

loc_003C06FA: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4FD0); g_seh_ebp = ebp; PUSH32(esp, 0x3C0705); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0705: ;
    ecx = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    g_seh_ebp = ebp; RECOMP_ITAIL(MEM32(0x3C4F18)); return; /* indirect tail jmp */

loc_003C070F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C0712
 * Original: 0x003C0712 - 0x003C0778 (102 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0712(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0712: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    eax = MEM32(edi + 8);
    /* test MEM8(eax + 0xA2), 1 - flags set for next jcc */
    ecx = MEM32(eax);
    if (TEST_NZ(MEM8(eax + 0xA2), 1)) goto loc_003C075F; /* jne: not equal / not zero */

loc_003C0726: ;
    if (TEST_NZ(MEM8(ecx + 4), 2)) goto loc_003C075F; /* jne: not equal / not zero */

loc_003C072C: ;
    esi = MEM32(esp + 0xC);
    if (CMP_L(MEM32(esi + 4), 0)) goto loc_003C0756; /* jl: less (signed <) */

loc_003C0736: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    MEM8(esi) = 0x18;
    MEM8(esi + 1) = 5;
    eax = MEM32(eax + 0x10);
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x14) = 4;
    ecx = MEM32(ecx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0756); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0756: ;
    MEM32(esi + 4) = 0xC0000004u;
    goto loc_003C076A;

loc_003C075F: ;
    esi = MEM32(esp + 0xC);
    MEM32(esi + 4) = 0x80000700u;

loc_003C076A: ;
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0773); sub_003C06E5(); /* call 0x003C06E5 */

loc_003C0773: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0778
 * Original: 0x003C0778 - 0x003C07C5 (77 bytes, 35 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0778(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0778: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    MEM32(ebp + -8) = MEM32(ebp + -8) | 0xFFFFFFFFu;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = MEM32(0x3C4FD4);
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
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0x3C07A5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C07A5: ;
    if (CMP_NE(eax, 0x102)) goto loc_003C07BE; /* jne: not equal / not zero */

loc_003C07AC: ;
    ecx = MEM32(ebp + -4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C07B5); sub_003BF685(); /* call 0x003BF685 */

loc_003C07B5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, MEM32(ebp + 8));
    { uint32_t _icall_t = esi; g_seh_ebp = ebp; PUSH32(esp, 0x3C07BE); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C07BE: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C07C5
 * Original: 0x003C07C5 - 0x003C08EC (295 bytes, 105 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C07C5(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C07C5: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C07D3); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C07D3: ;
    esi = MEM32(esp + 0x14);
    edi = esi + 0xA;
    edx = edi;
    SET_LO8(ecx, 2);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C07E3); sub_003BDAD2(); /* call 0x003BDAD2 */

loc_003C07E3: ;
    ebx = eax;
    if (TEST_Z(ebx, ebx)) goto loc_003C0824; /* je: equal / zero */

loc_003C07E9: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C07F0); sub_003BF80D(); /* call 0x003BF80D */

loc_003C07F0: ;
    edx = eax;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C07F9); sub_003C0363(); /* call 0x003C0363 */

loc_003C07F9: ;
    if (TEST_NZ(eax, eax)) goto loc_003C0824; /* jne: not equal / not zero */

loc_003C07FD: ;
    ecx = MEM32(esi);
    MEM8(esi + 0xB) = LO8(eax);
    SET_LO8(eax, MEM8(edi));
    MEM32(esi + 0xE) = ebx;
    MEM8(esi + 0xC) = 8;
    MEM8(esi + 0xD) = 1;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0815); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003C0815: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C081E); sub_003BE253(); /* call 0x003BE253 */

loc_003C081E: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003C0849;

loc_003C0824: ;
    edi = MEM32(esi);
    MEM32(esi) = MEM32(esi) & 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    PUSH32(esp, 0);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C083D); sub_003BF69C(); /* call 0x003BF69C */

loc_003C083D: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0849); sub_003BE253(); /* call 0x003BE253 */

loc_003C0849: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

    esi = MEM32(esp + 0x18);
    ebp = esi + 0xA;
    edx = ebp;
    SET_LO8(ecx, 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C086E); sub_003BDAD2(); /* call 0x003BDAD2 */

loc_003C086E: ;
    edi = eax;
    ebx = 0; /* xor self */
    if (CMP_EQ(edi, ebx)) goto loc_003C08C2; /* je: equal / zero */

loc_003C0876: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C087D); sub_003BF80D(); /* call 0x003BF80D */

loc_003C087D: ;
    edx = eax;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0886); sub_003C0363(); /* call 0x003C0363 */

loc_003C0886: ;
    if (TEST_NZ(eax, eax)) goto loc_003C08C2; /* jne: not equal / not zero */

loc_003C088A: ;
    SET_LO8(ecx, MEM8(esi + 6));
    MEM32(esi + 0xE) = edi;
    MEM8(esi + 0xB) = LO8(ebx);
    eax = MEM32(edi + 8);
    SET_LO8(eax, MEM8(eax));
    if (CMP_AE(LO8(ecx), LO8(eax))) goto loc_003C08A1; /* jae: above or equal (unsigned >=) */

loc_003C089C: ;
    MEM8(esi + 0xC) = LO8(ecx);
    goto loc_003C08A4;

loc_003C08A1: ;
    MEM8(esi + 0xC) = LO8(eax);

loc_003C08A4: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebp));
    MEM8(esi + 0xD) = LO8(ebx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08B4); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003C08B4: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08BC); sub_003BE253(); /* call 0x003BE253 */

loc_003C08BC: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003C08E5;

loc_003C08C2: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08D9); sub_003BF69C(); /* call 0x003BF69C */

loc_003C08D9: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08E5); sub_003BE253(); /* call 0x003BE253 */

loc_003C08E5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C084F
 * Original: 0x003C084F - 0x003C08EC (157 bytes, 58 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C084F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C084F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C085E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C085E: ;
    esi = MEM32(esp + 0x18);
    ebp = esi + 0xA;
    edx = ebp;
    SET_LO8(ecx, 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C086E); sub_003BDAD2(); /* call 0x003BDAD2 */

loc_003C086E: ;
    edi = eax;
    ebx = 0; /* xor self */
    if (CMP_EQ(edi, ebx)) goto loc_003C08C2; /* je: equal / zero */

loc_003C0876: ;
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C087D); sub_003BF80D(); /* call 0x003BF80D */

loc_003C087D: ;
    edx = eax;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0886); sub_003C0363(); /* call 0x003C0363 */

loc_003C0886: ;
    if (TEST_NZ(eax, eax)) goto loc_003C08C2; /* jne: not equal / not zero */

loc_003C088A: ;
    SET_LO8(ecx, MEM8(esi + 6));
    MEM32(esi + 0xE) = edi;
    MEM8(esi + 0xB) = LO8(ebx);
    eax = MEM32(edi + 8);
    SET_LO8(eax, MEM8(eax));
    if (CMP_AE(LO8(ecx), LO8(eax))) goto loc_003C08A1; /* jae: above or equal (unsigned >=) */

loc_003C089C: ;
    MEM8(esi + 0xC) = LO8(ecx);
    goto loc_003C08A4;

loc_003C08A1: ;
    MEM8(esi + 0xC) = LO8(eax);

loc_003C08A4: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(ebp));
    MEM8(esi + 0xD) = LO8(ebx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08B4); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003C08B4: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08BC); sub_003BE253(); /* call 0x003BE253 */

loc_003C08BC: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003C08E5;

loc_003C08C2: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08D9); sub_003BF69C(); /* call 0x003BF69C */

loc_003C08D9: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C08E5); sub_003BE253(); /* call 0x003BE253 */

loc_003C08E5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C08EC
 * Original: 0x003C08EC - 0x003C090A (30 bytes, 11 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C08EC(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C08EC: ;
    edx = ecx + 0xA2;
    SET_LO8(eax, MEM8(edx));
    if (TEST_NZ(LO8(eax), 4)) goto loc_003C0909; /* jne: not equal / not zero */

loc_003C08F8: ;
    PUSH32(esp, ecx);
    ecx = ecx + 0x82;
    SET_LO8(eax, LO8(eax) | 4);
    PUSH32(esp, ecx);
    MEM8(edx) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0909); sub_003C0478(); /* call 0x003C0478 */

loc_003C0909: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C090A
 * Original: 0x003C090A - 0x003C098E (132 bytes, 38 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C090A(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C090A: ;
    edx = MEM32(esp + 8);
    ecx = MEM32(edx + 8);
    eax = MEM32(ecx);
    /* test MEM8(ecx + 0xA2), 1 - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM8(ecx + 0xA2), 1)); /* latched */
    ecx = MEM32(esp + 4);
    if (_rcc0) goto loc_003C0926; /* jne: not equal / not zero */

loc_003C0920: ;
    if (TEST_Z(MEM8(eax + 4), 2)) goto loc_003C092D; /* je: equal / zero */

loc_003C0926: ;
    MEM32(ecx + 4) = 0x80000700u;

loc_003C092D: ;
    if (CMP_NE(MEM32(ecx + 4), 0xC0000004u)) goto loc_003C0986; /* jne: not equal / not zero */

loc_003C0936: ;
    if (CMP_NE(MEM8(ecx + 1), 0x41)) goto loc_003C0986; /* jne: not equal / not zero */

loc_003C093C: ;
    MEM32(ecx + 0xC) = edx;
    edx = 0; /* xor self */
    PUSH32(esp, esi);
    MEM8(ecx) = 0x30;
    MEM8(ecx + 1) = 0x40;
    MEM32(ecx + 8) = 0x3C0712;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0983); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0983: ;
    POP32(esp, esi);
    goto loc_003C098B;

loc_003C0986: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C098B); sub_003C06E5(); /* call 0x003C06E5 */

loc_003C098B: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C098E
 * Original: 0x003C098E - 0x003C0A19 (139 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C098E(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C098E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C099A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C099A: ;
    esi = MEM32(esp + 0xC);
    eax = 0; /* xor self */
    MEM8(0xF30928) = 0x30;
    MEM8(0xF30929) = 0x40;
    MEM32(0xF30930) = 0x3C07C5;
    MEM32(0xF30934) = esi;
    MEM32(0xF30938) = eax;
    MEM32(0xF30940) = eax;
    MEM32(0xF3093C) = eax;
    MEM8(0xF30944) = LO8(eax);
    MEM8(0xF30945) = 1;
    MEM8(0xF30946) = LO8(eax);
    MEM8(0xF30950) = 0x21;
    MEM8(0xF30951) = 0xA;
    MEM16(0xF30952) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF30954) = LO16(ecx);
    MEM16(0xF30956) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0A09); sub_003C0314(); /* call 0x003C0314 */

loc_003C0A09: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF30928);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0A15); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0A15: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0A19
 * Original: 0x003C0A19 - 0x003C0AA4 (139 bytes, 27 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0A19(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0A19: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C0A25); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0A25: ;
    esi = MEM32(esp + 0xC);
    eax = 0; /* xor self */
    MEM8(0xF30928) = 0x30;
    MEM8(0xF30929) = 0x40;
    MEM32(0xF30930) = 0x3C084F;
    MEM32(0xF30934) = esi;
    MEM32(0xF30938) = eax;
    MEM32(0xF30940) = eax;
    MEM32(0xF3093C) = eax;
    MEM8(0xF30944) = LO8(eax);
    MEM8(0xF30945) = 1;
    MEM8(0xF30946) = LO8(eax);
    MEM8(0xF30950) = 0x21;
    MEM8(0xF30951) = 0xA;
    MEM16(0xF30952) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF30954) = LO16(ecx);
    MEM16(0xF30956) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0A94); sub_003C0314(); /* call 0x003C0314 */

loc_003C0A94: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF30928);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0AA0); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0AA0: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0AA4
 * Original: 0x003C0AA4 - 0x003C0ADF (59 bytes, 20 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0AA4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0AA4: ;
    ecx = MEM32(esp + 4);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0AAE); sub_003BF698(); /* call 0x003BF698 */

loc_003C0AAE: ;
    esi = eax;
    ecx = MEM32(esi + 0x12);
    MEM8(esi + 4) = MEM8(esi + 4) | 2;
    if (TEST_Z(ecx, ecx)) goto loc_003C0AD4; /* je: equal / zero */

loc_003C0ABB: ;
    eax = MEM32(ecx + 0xA3);
    eax = MEM32(eax + 0x20);
    if (TEST_Z(eax, eax)) goto loc_003C0ACA; /* je: equal / zero */

loc_003C0AC8: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = eax; g_seh_ebp = ebp; PUSH32(esp, 0x3C0ACA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0ACA: ;
    ecx = MEM32(esi + 0x12);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0AD2); sub_003C08EC(); /* call 0x003C08EC */

loc_003C0AD2: ;
    goto loc_003C0ADB;

loc_003C0AD4: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0ADB); sub_003C0340(); /* call 0x003C0340 */

loc_003C0ADB: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C0ADF
 * Original: 0x003C0ADF - 0x003C0B73 (148 bytes, 49 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0ADF(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0ADF: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C0AEF); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0AEF: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(esi + 0xA3);
    eax = MEM32(eax + 0x1C);
    ebx = 0; /* xor self */
    if (CMP_EQ(eax, ebx)) goto loc_003C0B05; /* je: equal / zero */

loc_003C0B01: ;
    ecx = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = eax; g_seh_ebp = ebp; PUSH32(esp, 0x3C0B05); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0B05: ;
    if (CMP_EQ(MEM32(esi), ebx)) goto loc_003C0B4C; /* je: equal / zero */

loc_003C0B09: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0B33); sub_003C08EC(); /* call 0x003C08EC */

loc_003C0B33: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C0B3C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0B3C: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebx);
    eax = ebp + -20;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD4); g_seh_ebp = ebp; PUSH32(esp, 0x3C0B4A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0B4A: ;
    goto loc_003C0B55;

loc_003C0B4C: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C0B55); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0B55: ;
    eax = MEM32(esi + 0xA3);
    MEM8(eax + 1) = MEM8(eax + 1) + 1;
    eax = MEM32(0xF30910);
    MEM32(esi + 0xA7) = eax;
    MEM32(0xF30910) = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0B73
 * Original: 0x003C0B73 - 0x003C0CA1 (302 bytes, 100 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0B73(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C0B73: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C0B88); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0B88: ;
    ebx = 0; /* xor self */
    /* cmp edi, ebx - flags set for next jcc */
    MEM8(ebp + -2) = LO8(eax);
    if (CMP_EQ(edi, ebx)) goto loc_003C0C8B; /* je: equal / zero */

loc_003C0B95: ;
    if (TEST_NZ(MEM8(edi + 4), 2)) goto loc_003C0C8B; /* jne: not equal / not zero */

loc_003C0B9F: ;
    if (CMP_NE(MEM8(edi + 0xD), LO8(ebx))) goto loc_003C0BAF; /* jne: not equal / not zero */

loc_003C0BA4: ;
    MEM32(esi) = 0x32;
    goto loc_003C0C91;

loc_003C0BAF: ;
    eax = MEM32(esi + 4);
    if (CMP_EQ(eax, ebx)) goto loc_003C0BCE; /* je: equal / zero */

loc_003C0BB6: ;
    ecx = esi + 0xC;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ecx);
    PUSH32(esp, MEM32(0x3C4FA8));
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4F1C); g_seh_ebp = ebp; PUSH32(esp, 0x3C0BC7); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0BC7: ;
    if (CMP_GE(eax & eax, 0)) goto loc_003C0BD1; /* jge: greater or equal (signed >=) */

loc_003C0BCB: ;
    MEM32(esi + 4) = ebx;

loc_003C0BCE: ;
    MEM32(esi + 0xC) = ebx;

loc_003C0BD1: ;
    ecx = esi + 0x40;
    SET_LO8(eax, MEM8(ecx));
    /* cmp LO8(eax), LO8(ebx) - flags set for next jcc */
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_NE(LO8(eax), LO8(ebx))) goto loc_003C0BE8; /* jne: not equal / not zero */

loc_003C0BDD: ;
    SET_LO8(eax, MEM8(edi + 0xD));
    if (CMP_AE(LO8(eax), MEM8(esi + 0x41))) goto loc_003C0BE8; /* jae: above or equal (unsigned >=) */

loc_003C0BE5: ;
    MEM8(esi + 0x41) = LO8(eax);

loc_003C0BE8: ;
    eax = MEM32(edi + 0xE);
    if (TEST_Z(MEM8(eax + 0x28), 2)) goto loc_003C0BF4; /* je: equal / zero */

loc_003C0BF1: ;
    ecx = esi + 0x42;

loc_003C0BF4: ;
    edx = MEM32(ebp + -8);
    /* cmp MEM32(edx + 0x10), ebx - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(edx + 0x10), ebx)); /* latched */
    eax = esi + 0x10;
    MEM32(esi + 0x1C) = esi;
    MEM32(esi + 0x18) = 0x3C090A;
    if (_rcc0) goto loc_003C0C2C; /* je: equal / zero */

loc_003C0C09: ;
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
    goto loc_003C0C73;

loc_003C0C2C: ;
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

loc_003C0C73: ;
    ecx = MEM32(ebp + -8);
    MEM32(esi + 8) = ecx;
    ecx = MEM32(edi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0C81); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0C81: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0C87); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C0C87: ;
    MEM32(esi) = eax;
    goto loc_003C0C91;

loc_003C0C8B: ;
    MEM32(esi) = 0x48F;

loc_003C0C91: ;
    SET_LO8(ecx, MEM8(ebp + -2));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C0C9A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0C9A: ;
    eax = MEM32(esi);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C0CA1
 * Original: 0x003C0CA1 - 0x003C0D7F (222 bytes, 55 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0CA1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0CA1: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = MEM32(esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0CAD); sub_003BF791(); /* call 0x003BF791 */

loc_003C0CAD: ;
    SET_LO8(ecx, MEM8(eax + 5));
    if (CMP_NE(LO8(ecx), 3)) goto loc_003C0D54; /* jne: not equal / not zero */

loc_003C0CB9: ;
    if (CMP_NE(MEM8(eax + 7), 1)) goto loc_003C0D38; /* jne: not equal / not zero */

loc_003C0CBF: ;
    eax = 0; /* xor self */
    MEM8(0xF30928) = 0x30;
    MEM8(0xF30929) = 0x40;
    MEM32(0xF30930) = 0x3C098E;
    MEM32(0xF30934) = esi;
    MEM32(0xF30938) = eax;
    MEM32(0xF30940) = eax;
    MEM32(0xF3093C) = eax;
    MEM8(0xF30944) = LO8(eax);
    MEM8(0xF30945) = 1;
    MEM8(0xF30946) = LO8(eax);
    MEM8(0xF30950) = 0x21;
    MEM8(0xF30951) = 0xB;
    MEM16(0xF30952) = LO16(eax);
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    MEM16(0xF30954) = LO16(ecx);
    MEM16(0xF30956) = LO16(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D2A); sub_003C0314(); /* call 0x003C0314 */

loc_003C0D2A: ;
    ecx = MEM32(esi);
    PUSH32(esp, 0xF30928);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D36); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C0D36: ;
    goto loc_003C0D7B;

loc_003C0D38: ;
    if (CMP_NE(LO8(ecx), 3)) goto loc_003C0D54; /* jne: not equal / not zero */

loc_003C0D3D: ;
    if (CMP_NE(MEM8(eax + 7), 2)) goto loc_003C0D54; /* jne: not equal / not zero */

loc_003C0D43: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D48); sub_003C0314(); /* call 0x003C0314 */

loc_003C0D48: ;
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D52); sub_003C0A19(); /* call 0x003C0A19 */

loc_003C0D52: ;
    goto loc_003C0D7B;

loc_003C0D54: ;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    PUSH32(esp, edi);
    edi = MEM32(esi);
    eax = 0; /* xor self */
    MEM32(esi) = eax;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    PUSH32(esp, eax);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D6E); sub_003BF69C(); /* call 0x003BF69C */

loc_003C0D6E: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0D7A); sub_003BE253(); /* call 0x003BE253 */

loc_003C0D7A: ;
    POP32(esp, edi);

loc_003C0D7B: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0D7F
 * Original: 0x003C0D7F - 0x003C0E73 (244 bytes, 72 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0D7F(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C0D7F: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    PUSH32(esp, 0xF30960);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C0D8D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0D8D: ;
    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(eax + 4), ebx)) goto loc_003C0E63; /* jl: less (signed <) */

loc_003C0D9C: ;
    if (CMP_B(MEM32(eax + 0x14), 8)) goto loc_003C0E63; /* jb: below (unsigned <) */

loc_003C0DA6: ;
    if (CMP_B(MEM8(0xF30914), 8)) goto loc_003C0E63; /* jb: below (unsigned <) */

loc_003C0DB3: ;
    if (CMP_NE(MEM8(0xF30915), 0x42)) goto loc_003C0E63; /* jne: not equal / not zero */

loc_003C0DC0: ;
    if (CMP_EQ(MEM16(0xF30916), LO16(ebx))) goto loc_003C0E63; /* je: equal / zero */

loc_003C0DCD: ;
    esi = MEM32(esp + 0x14);
    SET_LO8(ecx, MEM8(0xF30918));
    edi = esi + 0xA;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0DE1); sub_003BDAD2(); /* call 0x003BDAD2 */

loc_003C0DE1: ;
    /* cmp eax, ebx - flags set for next jcc */
    MEM32(esi + 0xE) = eax;
    SET_LO8(ecx, MEM8(0xF30919));
    MEM8(esi + 0xB) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF3091A));
    MEM8(esi + 0xC) = LO8(ecx);
    SET_LO8(ecx, MEM8(0xF3091B));
    MEM8(esi + 0xD) = LO8(ecx);
    if (CMP_EQ(eax, ebx)) goto loc_003C0E3E; /* je: equal / zero */

loc_003C0E03: ;
    SET_LO8(eax, MEM8(0xF3091A));
    if (CMP_B(LO8(eax), 2)) goto loc_003C0E3E; /* jb: below (unsigned <) */

loc_003C0E0C: ;
    if (CMP_A(LO8(eax), 0x20)) goto loc_003C0E3E; /* ja: above (unsigned >) */

loc_003C0E10: ;
    SET_LO8(eax, MEM8(esi + 0xC));
    if (CMP_A(LO8(eax), MEM8(esi + 6))) goto loc_003C0E3E; /* ja: above (unsigned >) */

loc_003C0E18: ;
    if (CMP_EQ(MEM8(esi + 9), LO8(ebx))) goto loc_003C0E24; /* je: equal / zero */

loc_003C0E1D: ;
    SET_LO8(eax, LO8(ecx));
    if (CMP_A(LO8(eax), MEM8(esi + 7))) goto loc_003C0E3E; /* ja: above (unsigned >) */

loc_003C0E24: ;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    SET_LO8(eax, MEM8(edi));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0E30); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003C0E30: ;
    ecx = MEM32(esi);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0E38); sub_003BE253(); /* call 0x003BE253 */

loc_003C0E38: ;
    MEM8(esi + 4) = MEM8(esi + 4) | 8;
    goto loc_003C0E6D;

loc_003C0E3E: ;
    edi = MEM32(esi);
    MEM8(esi + 4) = MEM8(esi + 4) & 0xFE;
    MEM32(esi) = ebx;
    MEM16(0xF3090A) = MEM16(0xF3090A) - 1;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0E55); sub_003BF69C(); /* call 0x003BF69C */

loc_003C0E55: ;
    PUSH32(esp, 0x80000400u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0E61); sub_003BE253(); /* call 0x003BE253 */

loc_003C0E61: ;
    goto loc_003C0E6D;

loc_003C0E63: ;
    PUSH32(esp, MEM32(esp + 0x14));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0E6D); sub_003C0CA1(); /* call 0x003C0CA1 */

loc_003C0E6D: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C0E73
 * Original: 0x003C0E73 - 0x003C10C3 (592 bytes, 182 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C0E73(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003C0E73: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C0E96); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0E96: ;
    edx = edi;
    ecx = esi;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0EA2); sub_003C0363(); /* call 0x003C0363 */

loc_003C0EA2: ;
    edx = eax;
    /* cmp edx, ebx - flags set for next jcc */
    MEM32(ebp + -20) = edx;
    if (CMP_NE(edx, ebx)) goto loc_003C0EB7; /* jne: not equal / not zero */

loc_003C0EAB: ;
    MEM32(ebp + -8) = 0x48F;
    goto loc_003C10A2;

loc_003C0EB7: ;
    if (CMP_EQ(MEM32(edx + 0x12), ebx)) goto loc_003C0EC8; /* je: equal / zero */

loc_003C0EBC: ;
    MEM32(ebp + -8) = 0x20;
    goto loc_003C10A2;

loc_003C0EC8: ;
    SET_LO8(eax, MEM8(esi + 1));
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003C0EDB; /* jne: not equal / not zero */

loc_003C0ECF: ;
    MEM32(ebp + -8) = 0xE;
    goto loc_003C10A2;

loc_003C0EDB: ;
    SET_LO8(eax, LO8(eax) - 1);
    MEM8(esi + 1) = LO8(eax);
    ebx = MEM32(0xF30910);
    eax = MEM32(ebx + 0xA7);
    MEM32(0xF30910) = eax;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C0F36); sub_003C03CD(); /* call 0x003C03CD */

loc_003C0F36: ;
    if (TEST_S(eax, eax)) goto loc_003C1099; /* jl: less (signed <) */

loc_003C0F3E: ;
    edx = MEM32(esi + 0x18);
    if (TEST_Z(edx, edx)) goto loc_003C0F57; /* je: equal / zero */

loc_003C0F45: ;
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = edx; g_seh_ebp = ebp; PUSH32(esp, 0x3C0F49); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C0F49: ;
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = eax & 0x7FFFFF00;
    eax = eax + 0x80000100u;

loc_003C0F57: ;
    if (TEST_S(eax, eax)) goto loc_003C1099; /* jl: less (signed <) */

loc_003C0F5F: ;
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
    if (TEST_NZ(MEM8(eax + 0x28), 0x40)) goto loc_003C1046; /* jne: not equal / not zero */

loc_003C0F97: ;
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
    MEM32(ebx + 0x5A) = 0x3BF674;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1006); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1006: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C100F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C100F: ;
    ecx = MEM32(esi);
    eax = ebp + -40;
    PUSH32(esp, eax);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C101C); sub_003C0778(); /* call 0x003C0778 */

loc_003C101C: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C1022); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1022: ;
    /* cmp MEM32(ebx), 0 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(ebx), 0)); /* latched */
    MEM8(ebp + -1) = LO8(eax);
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003C0EAB; } /* je: equal / zero */

loc_003C102E: ;
    if (TEST_NZ(MEM8(esi + 4), 2)) { RECOMP_SLICE_POINT(); goto loc_003C0EAB; } /* jne: not equal / not zero */

loc_003C1038: ;
    if (CMP_L(MEM32(ebx + 0x56), 0)) goto loc_003C1046; /* jl: less (signed <) */

loc_003C103E: ;
    eax = MEM32(ebp + -16);
    ecx = ebx;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(eax + 0x24); g_seh_ebp = ebp; PUSH32(esp, 0x3C1046); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1046: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(ebx + 0x62) = ecx;
    ecx = ebx + 0x32;
    eax = ebx + 0x52;
    MEM8(eax) = 0x28;
    MEM8(ebx + 0x53) = 0x41;
    MEM32(ebx + 0x5A) = 0x3C0529;
    MEM32(ebx + 0x5E) = ebx;
    MEM32(ebx + 0x6A) = ecx;
    ecx = ZX8(MEM8(esi + 0xC));
    MEM32(ebx + 0x66) = ecx;
    MEM8(ebx + 0x6E) = 2;
    MEM8(ebx + 0x6F) = 1;
    MEM8(ebx + 0x70) = 0;
    MEM8(esi + 4) = MEM8(esi + 4) & 0xF;
    if (TEST_Z(MEM8(ebx + 0xA2), 8)) goto loc_003C108E; /* je: equal / zero */

loc_003C1086: ;
    ecx = MEM32(esi);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C108E); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C108E: ;
    eax = MEM32(ebp + 8);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM32(eax) = ebx;
    goto loc_003C10A2;

loc_003C1099: ;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C109F); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C109F: ;
    MEM32(ebp + -8) = eax;

loc_003C10A2: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C10AB); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C10AB: ;
    /* cmp MEM32(ebp + -12), 0 - flags set for next jcc */
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    if (CMP_EQ(MEM32(ebp + -12), 0)) goto loc_003C10BC; /* je: equal / zero */

loc_003C10B4: ;
    ecx = MEM32(ebp + -24);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C10BC); sub_003C0ADF(); /* call 0x003C0ADF */

loc_003C10BC: ;
    eax = MEM32(ebp + -8);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C10C3
 * Original: 0x003C10C3 - 0x003C1243 (384 bytes, 103 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C10C3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C10C3: ;
    SET_LO16(eax, MEM16(0xF3090A));
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    SET_LO8(ecx, 0); /* xor self */
    if (CMP_AE(LO16(eax), MEM16(0xF30908))) goto loc_003C1205; /* jae: above or equal (unsigned >=) */

loc_003C10DB: ;
    eax = MEM32(0xF3090C);
    if (TEST_Z(MEM8(eax + 4), 1)) goto loc_003C10F5; /* je: equal / zero */

loc_003C10E6: ;
    SET_LO8(ecx, LO8(ecx) + 1);
    edx = ZX8(LO8(ecx));
    edx = (uint32_t)((int32_t)edx * (int32_t)0x16);
    if (TEST_NZ(MEM8(edx + eax + 4), 1)) { RECOMP_SLICE_POINT(); goto loc_003C10E6; } /* jne: not equal / not zero */

loc_003C10F5: ;
    MEM16(0xF3090A) = MEM16(0xF3090A) + 1;
    PUSH32(esp, esi);
    esi = ZX8(LO8(ecx));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x16);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = esi + eax;
    MEM8(0xF30958) = LO8(ecx);
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1118); sub_003BF69C(); /* call 0x003BF69C */

loc_003C1118: ;
    SET_LO8(eax, MEM8(esi + 4));
    SET_LO8(eax, LO8(eax) & 0xF1);
    SET_LO8(eax, LO8(eax) | 1);
    ecx = edi;
    MEM32(esi) = edi;
    MEM8(esi + 4) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C112B); sub_003BF6A9(); /* call 0x003BF6A9 */

loc_003C112B: ;
    PUSH32(esp, ebx);
    PUSH32(esp, 1);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 5) = LO8(eax);
    MEM32(esi + 0x12) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C113D); sub_003BF797(); /* call 0x003BF797 */

loc_003C113D: ;
    SET_LO8(ecx, MEM8(eax + 2));
    PUSH32(esp, ebx);
    MEM8(esi + 8) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    PUSH32(esp, ebx);
    PUSH32(esp, 3);
    ecx = edi;
    MEM8(esi + 6) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1154); sub_003BF797(); /* call 0x003BF797 */

loc_003C1154: ;
    if (CMP_EQ(eax, ebx)) goto loc_003C1166; /* je: equal / zero */

loc_003C1158: ;
    SET_LO8(ecx, MEM8(eax + 2));
    MEM8(esi + 9) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 4));
    MEM8(esi + 7) = LO8(eax);
    goto loc_003C116C;

loc_003C1166: ;
    MEM8(esi + 9) = LO8(ebx);
    MEM8(esi + 7) = LO8(ebx);

loc_003C116C: ;
    PUSH32(esp, 0x10);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    MEM8(0xF30928) = 0x30;
    MEM8(0xF30929) = 0x40;
    MEM32(0xF30930) = 0x3C0D7F;
    MEM32(0xF30934) = esi;
    MEM32(0xF30938) = ebx;
    MEM32(0xF30940) = 0xF30914;
    MEM32(0xF3093C) = eax;
    MEM8(0xF30944) = 2;
    MEM8(0xF30945) = 1;
    MEM8(0xF30946) = LO8(ebx);
    MEM8(0xF30950) = 0xC1;
    MEM8(0xF30951) = 6;
    MEM16(0xF30952) = 0x4200;
    SET_LO16(ecx, ZX8(MEM8(esi + 5)));
    PUSH32(esp, 0x3C032F);
    PUSH32(esp, 0xF30988);
    MEM16(0xF30954) = LO16(ecx);
    MEM16(0xF30956) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C4FDC); g_seh_ebp = ebp; PUSH32(esp, 0x3C11F0); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C11F0: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C11F5); sub_003C0314(); /* call 0x003C0314 */

loc_003C11F5: ;
    PUSH32(esp, 0xF30928);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1201); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1201: ;
    POP32(esp, edi);
    POP32(esp, esi);
    goto loc_003C1213;

loc_003C1205: ;
    ecx = MEM32(esp + 8);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1213); sub_003BE253(); /* call 0x003BE253 */

loc_003C1213: ;
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C122D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C122D: ;
    PUSH32(esp, MEM32(0xF30A08));
    ecx = MEM32(esp + 0x10);
    PUSH32(esp, MEM32(esi + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C123F); sub_003BDE82(); /* call 0x003BDE82 */

loc_003C123F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1217
 * Original: 0x003C1217 - 0x003C1243 (44 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1217(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1217: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    if (CMP_GE(MEM32(esi + 4), 0)) goto loc_003C123F; /* jge: greater or equal (signed >=) */

loc_003C1222: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C122D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C122D: ;
    PUSH32(esp, MEM32(0xF30A08));
    ecx = MEM32(esp + 0x10);
    PUSH32(esp, MEM32(esi + 4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C123F); sub_003BDE82(); /* call 0x003BDE82 */

loc_003C123F: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1243
 * Original: 0x003C1243 - 0x003C1267 (36 bytes, 8 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1243(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1243: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C124E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C124E: ;
    PUSH32(esp, MEM32(0xF30A08));
    eax = MEM32(esp + 8);
    PUSH32(esp, MEM32(eax + 4));
    ecx = MEM32(esp + 0x10);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1264); sub_003BE14E(); /* call 0x003BE14E */

loc_003C1264: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1267
 * Original: 0x003C1267 - 0x003C12C4 (93 bytes, 29 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1267(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1267: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1274); sub_003BF698(); /* call 0x003BF698 */

loc_003C1274: ;
    SET_LO16(edi, ZX8(MEM8(eax + 3)));
    edx = 0; /* xor self */
    ecx = eax + 8;
    MEM8(ecx) = 0x30;
    PUSH32(esp, ecx);
    ecx = esi;
    MEM8(eax + 9) = 0x40;
    MEM32(eax + 0x10) = 0x3C1B4B;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C12BF); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C12BF: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C12C4
 * Original: 0x003C12C4 - 0x003C12FA (54 bytes, 19 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C12C4(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C12C4: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    SET_LO8(eax, MEM8(esi));
    SET_LO8(eax, LO8(eax) >> 4);
    SET_LO8(eax, LO8(eax) & 1);
    if ((LO8(eax) == 0)) goto loc_003C12E3; /* je: equal / zero */

loc_003C12D2: ;
    if (CMP_NE(MEM32(esp + 0xC), 0)) goto loc_003C12E3; /* jne: not equal / not zero */

loc_003C12D9: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C12DE); sub_003BDDDB(); /* call 0x003BDDDB */

loc_003C12DE: ;
    MEM8(esi) = MEM8(esi) & 0xEF;
    goto loc_003C12F6;

loc_003C12E3: ;
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003C12F6; /* jne: not equal / not zero */

loc_003C12E7: ;
    if (CMP_EQ(MEM32(esp + 0xC), 0)) goto loc_003C12F6; /* je: equal / zero */

loc_003C12EE: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C12F3); sub_003BDDD4(); /* call 0x003BDDD4 */

loc_003C12F3: ;
    MEM8(esi) = MEM8(esi) | 0x10;

loc_003C12F6: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C12FA
 * Original: 0x003C12FA - 0x003C136B (113 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C12FA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C12FA: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1306); sub_003BF698(); /* call 0x003BF698 */

loc_003C1306: ;
    ecx = MEM32(0xF30A54);
    ecx = ecx - 0;
    if ((ecx == 0)) goto loc_003C135C; /* je: equal / zero */

loc_003C1311: ;
    ecx--;
    if ((ecx == 0)) goto loc_003C1348; /* je: equal / zero */

loc_003C1314: ;
    ecx--;
    if ((ecx == 0)) goto loc_003C1334; /* je: equal / zero */

loc_003C1317: ;
    ecx--;
    if ((ecx != 0)) goto loc_003C1367; /* jne: not equal / not zero */

loc_003C131A: ;
    eax = MEM32(0xF30A58);
    if (TEST_Z(eax, eax)) goto loc_003C1367; /* je: equal / zero */

loc_003C1323: ;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C132B); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C132B: ;
    MEM32(0xF30A58) = MEM32(0xF30A58) & 0;
    goto loc_003C1367;

loc_003C1334: ;
    PUSH32(esp, MEM32(0xF30A08));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1346); sub_003BE14E(); /* call 0x003BE14E */

loc_003C1346: ;
    goto loc_003C1367;

loc_003C1348: ;
    PUSH32(esp, MEM32(0xF30A08));
    ecx = esi;
    PUSH32(esp, 0x80000600u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C135A); sub_003BDE82(); /* call 0x003BDE82 */

loc_003C135A: ;
    goto loc_003C1367;

loc_003C135C: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1367); sub_003BF685(); /* call 0x003BF685 */

loc_003C1367: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C136B
 * Original: 0x003C136B - 0x003C13CE (99 bytes, 28 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C136B(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C136B: ;
    /* cmp MEM32(0xF30A58), 0 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(0xF30A58), 0)); /* latched */
    PUSH32(esp, esi);
    esi = 0xF30A10;
    if (_rcc0) goto loc_003C1395; /* je: equal / zero */

loc_003C137A: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1381); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1381: ;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(0xF30A58));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C138E); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C138E: ;
    MEM32(0xF30A58) = MEM32(0xF30A58) & 0;

loc_003C1395: ;
    edx = MEM32(esp + 8);
    if (TEST_NZ(edx, edx)) goto loc_003C13A4; /* jne: not equal / not zero */

loc_003C139D: ;
    eax = 0xFA0A1F00u;
    goto loc_003C13B3;

loc_003C13A4: ;
    /* cmp edx, 3 - flags set for next jcc */
    eax = 0xFFF48E50u;
    if (CMP_EQ(edx, 3)) goto loc_003C13B3; /* je: equal / zero */

loc_003C13AE: ;
    eax = 0xFFB3B4C0u;

loc_003C13B3: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A38);
    ecx = ecx | 0xFFFFFFFFu;
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    PUSH32(esp, esi);
    MEM32(0xF30A54) = edx;
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3C13CA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C13CA: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C13CE
 * Original: 0x003C13CE - 0x003C151C (334 bytes, 117 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C13CE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C13CE: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C13DE); sub_003BF698(); /* call 0x003BF698 */

loc_003C13DE: ;
    esi = eax;
    SET_LO16(eax, MEM16(esi + 0x3A));
    ebx = 0; /* xor self */
    if (TEST_Z(LO8(eax), 0x10)) goto loc_003C1445; /* je: equal / zero */

loc_003C13EA: ;
    if (CMP_NE(MEM32(0xF30A54), 1)) goto loc_003C143D; /* jne: not equal / not zero */

loc_003C13F3: ;
    if (CMP_EQ(MEM32(0xF30A08), ebx)) goto loc_003C143D; /* je: equal / zero */

loc_003C13FB: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    edi = 0; /* xor self */
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1408); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1408: ;
    SET_LO16(eax, MEM16(esi + 0x38));
    if (TEST_Z(LO8(eax), 2)) goto loc_003C1420; /* je: equal / zero */

loc_003C1410: ;
    if (TEST_NZ(LO8(eax), 0x10)) goto loc_003C1420; /* jne: not equal / not zero */

loc_003C1414: ;
    if (TEST_Z(HI8(eax), 2)) goto loc_003C1425; /* je: equal / zero */

loc_003C1419: ;
    edi = 0x1000000;
    goto loc_003C1425;

loc_003C1420: ;
    edi = 0x80000600u;

loc_003C1425: ;
    eax = MEM32(0xF30A08);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, eax);
    PUSH32(esp, edi);
    MEM32(0xF30A08) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C143A); sub_003BDE82(); /* call 0x003BDE82 */

loc_003C143A: ;
    edi = MEM32(ebp + 8);

loc_003C143D: ;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xEF;
    PUSH32(esp, 0x14);
    goto loc_003C14BC;

loc_003C1445: ;
    if (TEST_Z(LO8(eax), 1)) goto loc_003C1496; /* je: equal / zero */

loc_003C1449: ;
    ecx = 0; /* xor self */
    SET_LO8(ecx, MEM8(esi + 3));
    MEM8(ebp + 8) = LO8(ecx);
    SET_LO8(eax, 1);
    ecx--;
    SET_LO8(eax, LO8(eax) << LO8(ecx));
    if (TEST_Z(MEM8(esi + 0x38), 1)) goto loc_003C1476; /* je: equal / zero */

loc_003C145C: ;
    if (TEST_Z(MEM8(esi + 5), LO8(eax))) goto loc_003C146B; /* je: equal / zero */

loc_003C1461: ;
    PUSH32(esp, MEM32(ebp + 8));
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C146B); sub_003BDFFE(); /* call 0x003BDFFE */

loc_003C146B: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1471); sub_003C1267(); /* call 0x003C1267 */

loc_003C1471: ;
    goto loc_003C1515;

loc_003C1476: ;
    SET_LO8(ecx, MEM8(esi + 5));
    if (TEST_Z(LO8(eax), LO8(ecx))) goto loc_003C148E; /* je: equal / zero */

loc_003C147D: ;
    PUSH32(esp, MEM32(ebp + 8));
    SET_LO8(eax, ~LO8(eax));
    SET_LO8(eax, LO8(eax) & LO8(ecx));
    ecx = edi;
    MEM8(esi + 5) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C148E); sub_003BDFFE(); /* call 0x003BDFFE */

loc_003C148E: ;
    MEM8(esi + 0x3A) = MEM8(esi + 0x3A) & 0xFE;
    PUSH32(esp, 0x10);
    goto loc_003C14BC;

loc_003C1496: ;
    if (TEST_Z(LO8(eax), 2)) goto loc_003C14A2; /* je: equal / zero */

loc_003C149A: ;
    SET_LO16(eax, LO16(eax) & 0xFFFD);
    PUSH32(esp, 0x11);
    goto loc_003C14B8;

loc_003C14A2: ;
    if (TEST_Z(LO8(eax), 4)) goto loc_003C14AE; /* je: equal / zero */

loc_003C14A6: ;
    SET_LO16(eax, LO16(eax) & 0xFFFB);
    PUSH32(esp, 0x12);
    goto loc_003C14B8;

loc_003C14AE: ;
    if (TEST_Z(LO8(eax), 8)) goto loc_003C1506; /* je: equal / zero */

loc_003C14B2: ;
    SET_LO16(eax, LO16(eax) & 0xFFF7);
    PUSH32(esp, 0x13);

loc_003C14B8: ;
    MEM16(esi + 0x3A) = LO16(eax);

loc_003C14BC: ;
    POP32(esp, ecx);
    MEM16(esi + 0x32) = LO16(ecx);
    SET_LO16(ecx, ZX8(MEM8(esi + 3)));
    eax = esi + 8;
    MEM16(esi + 0x34) = LO16(ecx);
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3C1B1B;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1504); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1504: ;
    goto loc_003C1515;

loc_003C1506: ;
    MEM16(esi + 0x3A) = MEM16(esi + 0x3A) & 0;
    PUSH32(esp, edi);
    esi = esi + 8;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1515); sub_003C1B1B(); /* call 0x003C1B1B */

loc_003C1515: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C151C
 * Original: 0x003C151C - 0x003C157F (99 bytes, 30 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C151C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C151C: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1529); sub_003BF698(); /* call 0x003BF698 */

loc_003C1529: ;
    PUSH32(esp, 0);
    ecx = edi;
    esi = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1534); sub_003BF69C(); /* call 0x003BF69C */

loc_003C1534: ;
    MEM8(esi) = MEM8(esi) & 0xFE;
    MEM16(0xF30A62) = MEM16(0xF30A62) - 1;
    if (TEST_Z(MEM8(esi), 2)) goto loc_003C156E; /* je: equal / zero */

loc_003C1543: ;
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C154B); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C154B: ;
    if (CMP_NE(esi, MEM32(0xF30A58))) goto loc_003C1565; /* jne: not equal / not zero */

loc_003C1553: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C155E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C155E: ;
    MEM32(0xF30A58) = MEM32(0xF30A58) & 0;

loc_003C1565: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C156C); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C156C: ;
    goto loc_003C157A;

loc_003C156E: ;
    PUSH32(esp, 0x80000100u);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C157A); sub_003BE253(); /* call 0x003BE253 */

loc_003C157A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C157F
 * Original: 0x003C157F - 0x003C1666 (231 bytes, 60 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C157F(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C157F: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C158E); sub_003BF698(); /* call 0x003BF698 */

loc_003C158E: ;
    ecx = 0; /* xor self */
    /* cmp eax, ecx - flags set for next jcc */
    PUSH32(esp, 4);
    SET_LO8(edx, 3);
    POP32(esp, esi);
    MEM32(ebp + -4) = 1;
    edi = 0x3C1217;
    if (CMP_EQ(eax, ecx)) goto loc_003C164F; /* je: equal / zero */

loc_003C15A9: ;
    SET_LO8(ebx, MEM8(ebp + 0xC));
    if (CMP_B(MEM8(eax + 2), LO8(ebx))) goto loc_003C164F; /* jb: below (unsigned <) */

loc_003C15B5: ;
    /* cmp MEM8(ebp + 0x14), LO8(ecx) - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(ebp + 0x14), LO8(ecx))); /* latched */
    eax = MEM32(ebp + 0x10);
    MEM32(0xF30A08) = eax;
    if (_rcc0) goto loc_003C15D3; /* je: equal / zero */

loc_003C15C2: ;
    edx = 0; /* xor self */
    edx++;
    esi = edx;
    edi = 0x3C1243;
    MEM32(ebp + -4) = 2;

loc_003C15D3: ;
    PUSH32(esp, MEM32(ebp + -4));
    SET_LO16(eax, ZX8(LO8(ebx)));
    MEM32(0xF309E0) = edi;
    edi = MEM32(ebp + 8);
    MEM8(0xF309D8) = 0x30;
    MEM8(0xF309D9) = 0x40;
    MEM32(0xF309E4) = edi;
    MEM32(0xF309E8) = ecx;
    MEM32(0xF309F0) = ecx;
    MEM32(0xF309EC) = ecx;
    MEM8(0xF309F4) = LO8(ecx);
    MEM8(0xF309F5) = LO8(ecx);
    MEM8(0xF309F6) = LO8(ecx);
    MEM8(0xF30A00) = 0x23;
    MEM8(0xF30A01) = LO8(edx);
    MEM16(0xF30A02) = LO16(esi);
    MEM16(0xF30A04) = LO16(eax);
    MEM16(0xF30A06) = LO16(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1641); sub_003C136B(); /* call 0x003C136B */

loc_003C1641: ;
    PUSH32(esp, 0xF309D8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C164D); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C164D: ;
    goto loc_003C165F;

loc_003C164F: ;
    PUSH32(esp, MEM32(ebp + 0x10));
    ecx = MEM32(ebp + 8);
    PUSH32(esp, 0x80000300u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C165F); sub_003BDE82(); /* call 0x003BDE82 */

loc_003C165F: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C1666
 * Original: 0x003C1666 - 0x003C1688 (34 bytes, 9 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1666(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1666: ;
    eax = MEM32(esp + 4);
    ecx = MEM32(esp + 8);
    PUSH32(esp, eax);
    MEM8(eax) = 0x1C;
    MEM8(eax + 1) = 0xC3;
    MEM32(eax + 8) = 0x3C151C;
    MEM32(eax + 0xC) = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1685); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1685: ;
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1688
 * Original: 0x003C1688 - 0x003C16BA (50 bytes, 16 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1688(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1688: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1694); sub_003BF698(); /* call 0x003BF698 */

loc_003C1694: ;
    edx = MEM32(eax + 0x3C);
    ecx = eax + 8;
    MEM8(ecx) = 0x1C;
    PUSH32(esp, ecx);
    ecx = esi;
    MEM8(eax + 9) = 0x43;
    MEM32(eax + 0x10) = 0x3C1666;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x18) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C16B6); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C16B6: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C16BA
 * Original: 0x003C16BA - 0x003C174B (145 bytes, 49 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C16BA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C16BA: ;
    PUSH32(esp, ebx);
    ebx = MEM32(esp + 0xC);
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C16C7); sub_003BF698(); /* call 0x003BF698 */

loc_003C16C7: ;
    edi = eax;
    SET_LO8(eax, MEM8(edi));
    if (TEST_Z(LO8(eax), 2)) goto loc_003C16D7; /* je: equal / zero */

loc_003C16CF: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C16D5); sub_003C1688(); /* call 0x003C1688 */

loc_003C16D5: ;
    goto loc_003C1746;

loc_003C16D7: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0x10);
    /* cmp MEM32(esi + 4), 0 - flags set for next jcc */
    ecx = ebx;
    if (CMP_GE(MEM32(esi + 4), 0)) goto loc_003C16EF; /* jge: greater or equal (signed >=) */

loc_003C16E4: ;
    SET_LO8(eax, LO8(eax) | 8);
    MEM8(edi) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C16ED); sub_003BE075(); /* call 0x003BE075 */

loc_003C16ED: ;
    goto loc_003C1745;

loc_003C16EF: ;
    MEM32(esi + 8) = MEM32(esi + 8) & 0;
    MEM8(esi) = 0x18;
    MEM8(esi + 1) = 5;
    eax = MEM32(edi + 0x3C);
    PUSH32(esp, esi);
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C170D); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C170D: ;
    MEM8(esi) = 0x28;
    MEM8(esi + 1) = 0x41;
    MEM32(esi + 8) = 0x3C1851;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1745); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1745: ;
    POP32(esp, esi);

loc_003C1746: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C174B
 * Original: 0x003C174B - 0x003C1801 (182 bytes, 62 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C174B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C174B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1757); sub_003BF698(); /* call 0x003BF698 */

loc_003C1757: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C1766; /* je: equal / zero */

loc_003C175E: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1764); sub_003C1688(); /* call 0x003C1688 */

loc_003C1764: ;
    goto loc_003C17A2;

loc_003C1766: ;
    edx = MEM32(esp + 8);
    if (CMP_L(MEM32(edx + 4), 0)) goto loc_003C177C; /* jl: less (signed <) */

loc_003C1770: ;
    PUSH32(esp, esi);
    MEM8(eax + 6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C177A); sub_003C13CE(); /* call 0x003C13CE */

loc_003C177A: ;
    goto loc_003C17A2;

loc_003C177C: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003C1793; /* jbe: below or equal (unsigned <=) */

loc_003C1785: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1791); sub_003BE075(); /* call 0x003BE075 */

loc_003C1791: ;
    goto loc_003C17A2;

loc_003C1793: ;
    PUSH32(esp, edx);
    ecx = esi;
    MEM32(edx + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17A2); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C17A2: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C17C1; /* je: equal / zero */

loc_003C17B9: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17BF); sub_003C1688(); /* call 0x003C1688 */

loc_003C17BF: ;
    goto loc_003C17FD;

loc_003C17C1: ;
    edx = MEM32(esp + 8);
    if (CMP_GE(MEM32(edx + 4), 0)) goto loc_003C17F3; /* jge: greater or equal (signed >=) */

loc_003C17CB: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003C17E2; /* jbe: below or equal (unsigned <=) */

loc_003C17D4: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17E0); sub_003BE075(); /* call 0x003BE075 */

loc_003C17E0: ;
    goto loc_003C17FD;

loc_003C17E2: ;
    PUSH32(esp, edx);
    ecx = esi;
    MEM32(edx + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17F1); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C17F1: ;
    goto loc_003C17FD;

loc_003C17F3: ;
    PUSH32(esp, esi);
    MEM8(eax + 6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17FD); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C17FD: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C17A6
 * Original: 0x003C17A6 - 0x003C1801 (91 bytes, 31 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C17A6(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C17A6: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17B2); sub_003BF698(); /* call 0x003BF698 */

loc_003C17B2: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C17C1; /* je: equal / zero */

loc_003C17B9: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17BF); sub_003C1688(); /* call 0x003C1688 */

loc_003C17BF: ;
    goto loc_003C17FD;

loc_003C17C1: ;
    edx = MEM32(esp + 8);
    if (CMP_GE(MEM32(edx + 4), 0)) goto loc_003C17F3; /* jge: greater or equal (signed >=) */

loc_003C17CB: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003C17E2; /* jbe: below or equal (unsigned <=) */

loc_003C17D4: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17E0); sub_003BE075(); /* call 0x003BE075 */

loc_003C17E0: ;
    goto loc_003C17FD;

loc_003C17E2: ;
    PUSH32(esp, edx);
    ecx = esi;
    MEM32(edx + 0x14) = 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17F1); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C17F1: ;
    goto loc_003C17FD;

loc_003C17F3: ;
    PUSH32(esp, esi);
    MEM8(eax + 6) = 0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C17FD); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C17FD: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1801
 * Original: 0x003C1801 - 0x003C1851 (80 bytes, 33 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1801(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C1801: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    ecx = MEM32(ebp + 8);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C180F); sub_003BF698(); /* call 0x003BF698 */

loc_003C180F: ;
    esi = eax;
    MEM8(esi) = MEM8(esi) | 2;
    ebx = 0; /* xor self */
    ebx++;
    MEM8(ebp + -4) = LO8(ebx);

loc_003C181A: ;
    if (TEST_Z(MEM8(esi + 5), LO8(ebx))) goto loc_003C1831; /* je: equal / zero */

loc_003C181F: ;
    PUSH32(esp, MEM32(ebp + -4));
    ecx = MEM32(ebp + 8);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C182A); sub_003BDFFE(); /* call 0x003BDFFE */

loc_003C182A: ;
    SET_LO8(eax, LO8(ebx));
    SET_LO8(eax, ~LO8(eax));
    MEM8(esi + 5) = MEM8(esi + 5) & LO8(eax);

loc_003C1831: ;
    ebx = ebx << 1;
    MEM8(ebp + -4) = MEM8(ebp + -4) + 1;
    SET_LO8(eax, MEM8(ebp + -4));
    if (CMP_BE(LO8(eax), MEM8(esi + 2))) { RECOMP_SLICE_POINT(); goto loc_003C181A; } /* jbe: below or equal (unsigned <=) */

loc_003C183E: ;
    /* test MEM8(esi), 8 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi), 8)); /* latched */
    POP32(esp, esi);
    POP32(esp, ebx);
    if (_rcc0) goto loc_003C184D; /* je: equal / zero */

loc_003C1845: ;
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C184D); sub_003C1688(); /* call 0x003C1688 */

loc_003C184D: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C1851
 * Original: 0x003C1851 - 0x003C1A48 (503 bytes, 165 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1851(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1851: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C185E); sub_003BF698(); /* call 0x003BF698 */

loc_003C185E: ;
    esi = eax;
    SET_LO8(ecx, MEM8(esi));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C1872; /* je: equal / zero */

loc_003C1867: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C186D); sub_003C1688(); /* call 0x003C1688 */

loc_003C186D: ;
    goto loc_003C1918;

loc_003C1872: ;
    eax = MEM32(esp + 0xC);
    PUSH32(esp, ebx);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(eax + 4), ebx)) goto loc_003C18BC; /* jl: less (signed <) */

loc_003C187E: ;
    if (CMP_NE(esi, MEM32(0xF30A58))) goto loc_003C1897; /* jne: not equal / not zero */

loc_003C1886: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1891); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1891: ;
    MEM32(0xF30A58) = ebx;

loc_003C1897: ;
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C189F); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C189F: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C18BA); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C18BA: ;
    goto loc_003C1917;

loc_003C18BC: ;
    MEM8(esi + 6) = MEM8(esi + 6) + 1;
    if (CMP_BE(MEM8(esi + 6), 3)) goto loc_003C18D3; /* jbe: below or equal (unsigned <=) */

loc_003C18C5: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(esi) = LO8(ecx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C18D1); sub_003BE075(); /* call 0x003BE075 */

loc_003C18D1: ;
    goto loc_003C1917;

loc_003C18D3: ;
    MEM8(eax) = 0x30;
    MEM8(eax + 1) = 0x40;
    MEM32(eax + 8) = 0x3C16BA;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1917); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1917: ;
    POP32(esp, ebx);

loc_003C1918: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C193B; /* je: equal / zero */

loc_003C1930: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1936); sub_003C1688(); /* call 0x003C1688 */

loc_003C1936: ;
    goto loc_003C19D9;

loc_003C193B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    edx = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), edx)) goto loc_003C196F; /* jge: greater or equal (signed >=) */

loc_003C1947: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003C195E; /* jbe: below or equal (unsigned <=) */

loc_003C1950: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C195C); sub_003BE075(); /* call 0x003BE075 */

loc_003C195C: ;
    goto loc_003C19D8;

loc_003C195E: ;
    MEM32(esi + 0x14) = 4;
    PUSH32(esp, esi);

loc_003C1966: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C196D); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C196D: ;
    goto loc_003C19D8;

loc_003C196F: ;
    SET_LO16(ecx, MEM16(eax + 0x3A));
    /* test LO8(ecx), 1 - flags set for next jcc */
    MEM8(eax + 6) = LO8(edx);
    if (TEST_Z(LO8(ecx), 1)) goto loc_003C1984; /* je: equal / zero */

loc_003C197B: ;
    esi = 0; /* xor self */
    SET_LO16(ecx, LO16(ecx) & 0xFFFE);
    goto loc_003C1991;

loc_003C1984: ;
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C19D2; /* je: equal / zero */

loc_003C1989: ;
    esi = 0; /* xor self */
    esi++;
    SET_LO16(ecx, LO16(ecx) & 0xFFFD);

loc_003C1991: ;
    MEM16(eax + 0x3A) = LO16(ecx);
    ecx = eax + 8;
    MEM8(ecx) = 0x30;
    MEM8(eax + 9) = 0x40;
    MEM32(eax + 0x10) = 0x3C17A6;
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
    { RECOMP_SLICE_POINT(); goto loc_003C1966; }

loc_003C19D2: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C19D8); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C19D8: ;
    POP32(esp, esi);

loc_003C19D9: ;
    POP32(esp, edi);
    esp += 12; return; /* ret 8 */

    SET_LO8(ecx, MEM8(eax + 3));
    if (CMP_NE(LO8(ecx), MEM8(eax + 2))) goto loc_003C1A28; /* jne: not equal / not zero */

loc_003C19F1: ;
    ecx = MEM32(eax + 0x3C);
    MEM32(eax + 0x18) = ecx;
    ecx = eax + 0x38;
    MEM32(eax + 0x20) = ecx;
    ecx = ZX8(MEM8(eax + 7));
    MEM8(eax + 3) = 0;
    MEM8(eax + 8) = 0x28;
    MEM8(eax + 9) = 0x41;
    MEM32(eax + 0x10) = 0x3C1851;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x1C) = ecx;
    MEM8(eax + 0x24) = 2;
    MEM8(eax + 0x25) = 1;
    MEM8(eax + 0x26) = 0;
    goto loc_003C1A39;

loc_003C1A28: ;
    edx = MEM32(esp + 8);
    SET_LO8(ecx, LO8(ecx) + 1);
    MEM8(eax + 3) = LO8(ecx);
    SET_LO16(ecx, ZX8(LO8(ecx)));
    MEM16(edx + 0x2C) = LO16(ecx);

loc_003C1A39: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1A44); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1A44: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C191D
 * Original: 0x003C191D - 0x003C19DD (192 bytes, 64 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C191D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C191D: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0xC);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1929); sub_003BF698(); /* call 0x003BF698 */

loc_003C1929: ;
    SET_LO8(ecx, MEM8(eax));
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C193B; /* je: equal / zero */

loc_003C1930: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1936); sub_003C1688(); /* call 0x003C1688 */

loc_003C1936: ;
    goto loc_003C19D9;

loc_003C193B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    edx = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), edx)) goto loc_003C196F; /* jge: greater or equal (signed >=) */

loc_003C1947: ;
    MEM8(eax + 6) = MEM8(eax + 6) + 1;
    if (CMP_BE(MEM8(eax + 6), 3)) goto loc_003C195E; /* jbe: below or equal (unsigned <=) */

loc_003C1950: ;
    SET_LO8(ecx, LO8(ecx) | 8);
    MEM8(eax) = LO8(ecx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C195C); sub_003BE075(); /* call 0x003BE075 */

loc_003C195C: ;
    goto loc_003C19D8;

loc_003C195E: ;
    MEM32(esi + 0x14) = 4;
    PUSH32(esp, esi);

loc_003C1966: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C196D); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C196D: ;
    goto loc_003C19D8;

loc_003C196F: ;
    SET_LO16(ecx, MEM16(eax + 0x3A));
    /* test LO8(ecx), 1 - flags set for next jcc */
    MEM8(eax + 6) = LO8(edx);
    if (TEST_Z(LO8(ecx), 1)) goto loc_003C1984; /* je: equal / zero */

loc_003C197B: ;
    esi = 0; /* xor self */
    SET_LO16(ecx, LO16(ecx) & 0xFFFE);
    goto loc_003C1991;

loc_003C1984: ;
    if (TEST_Z(LO8(ecx), 2)) goto loc_003C19D2; /* je: equal / zero */

loc_003C1989: ;
    esi = 0; /* xor self */
    esi++;
    SET_LO16(ecx, LO16(ecx) & 0xFFFD);

loc_003C1991: ;
    MEM16(eax + 0x3A) = LO16(ecx);
    ecx = eax + 8;
    MEM8(ecx) = 0x30;
    MEM8(eax + 9) = 0x40;
    MEM32(eax + 0x10) = 0x3C17A6;
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
    { RECOMP_SLICE_POINT(); goto loc_003C1966; }

loc_003C19D2: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C19D8); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C19D8: ;
    POP32(esp, esi);

loc_003C19D9: ;
    POP32(esp, edi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C19DD
 * Original: 0x003C19DD - 0x003C1A48 (107 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C19DD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C19DD: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C19E9); sub_003BF698(); /* call 0x003BF698 */

loc_003C19E9: ;
    SET_LO8(ecx, MEM8(eax + 3));
    if (CMP_NE(LO8(ecx), MEM8(eax + 2))) goto loc_003C1A28; /* jne: not equal / not zero */

loc_003C19F1: ;
    ecx = MEM32(eax + 0x3C);
    MEM32(eax + 0x18) = ecx;
    ecx = eax + 0x38;
    MEM32(eax + 0x20) = ecx;
    ecx = ZX8(MEM8(eax + 7));
    MEM8(eax + 3) = 0;
    MEM8(eax + 8) = 0x28;
    MEM8(eax + 9) = 0x41;
    MEM32(eax + 0x10) = 0x3C1851;
    MEM32(eax + 0x14) = esi;
    MEM32(eax + 0x1C) = ecx;
    MEM8(eax + 0x24) = 2;
    MEM8(eax + 0x25) = 1;
    MEM8(eax + 0x26) = 0;
    goto loc_003C1A39;

loc_003C1A28: ;
    edx = MEM32(esp + 8);
    SET_LO8(ecx, LO8(ecx) + 1);
    MEM8(eax + 3) = LO8(ecx);
    SET_LO16(ecx, ZX8(LO8(ecx)));
    MEM16(edx + 0x2C) = LO16(ecx);

loc_003C1A39: ;
    eax = eax + 8;
    PUSH32(esp, eax);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1A44); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1A44: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1A48
 * Original: 0x003C1A48 - 0x003C1B1B (211 bytes, 74 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1A48(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C1A48: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 8);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1A58); sub_003BF698(); /* call 0x003BF698 */

loc_003C1A58: ;
    SET_LO8(ebx, MEM8(eax + 4));
    ecx = 0; /* xor self */
    SET_LO8(edx, 1);
    MEM8(eax + 3) = LO8(ecx);
    MEM8(ebp + 0xB) = LO8(ebx);

loc_003C1A65: ;
    if (TEST_NZ(MEM8(ebp + 0xB), LO8(edx))) goto loc_003C1A79; /* jne: not equal / not zero */

loc_003C1A6A: ;
    MEM8(eax + 3) = MEM8(eax + 3) + 1;
    SET_LO8(ebx, MEM8(eax + 3));
    SET_LO8(edx, LO8(edx) << 1);
    if (CMP_BE(LO8(ebx), MEM8(eax + 2))) { RECOMP_SLICE_POINT(); goto loc_003C1A65; } /* jbe: below or equal (unsigned <=) */

loc_003C1A77: ;
    goto loc_003C1A81;

loc_003C1A79: ;
    SET_LO8(edx, ~LO8(edx));
    SET_LO8(edx, LO8(edx) & MEM8(eax + 4));
    MEM8(eax + 4) = LO8(edx);

loc_003C1A81: ;
    SET_LO8(ebx, MEM8(eax + 3));
    /* cmp LO8(ebx), MEM8(eax + 2) - flags set for next jcc */
    _rcc0 = (CMP_BE(LO8(ebx), MEM8(eax + 2))); /* latched */
    MEM8(eax + 0x26) = LO8(ecx);
    MEM8(eax + 0x24) = 2;
    MEM32(eax + 0x14) = edi;
    esi = eax + 8;
    if (_rcc0) goto loc_003C1AC4; /* jbe: below or equal (unsigned <=) */

loc_003C1A96: ;
    edx = MEM32(eax + 0x3C);
    MEM32(eax + 0x18) = edx;
    edx = eax + 0x38;
    MEM32(eax + 0x20) = edx;
    edx = ZX8(MEM8(eax + 7));
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    MEM8(esi) = 0x28;
    MEM8(eax + 9) = 0x41;
    MEM32(eax + 0x10) = 0x3C1851;
    MEM32(eax + 0x1C) = edx;
    MEM8(eax + 0x25) = 1;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1AC2); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C1AC2: ;
    goto loc_003C1B0C;

loc_003C1AC4: ;
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
    if (CMP_NE(LO8(ebx), LO8(ecx))) goto loc_003C1AF9; /* jne: not equal / not zero */

loc_003C1AEC: ;
    MEM32(eax + 0x10) = 0x3C191D;
    MEM8(eax + 0x30) = 0xA0;
    goto loc_003C1B08;

loc_003C1AF9: ;
    MEM32(eax + 0x10) = 0x3C174B;
    MEM8(eax + 0x30) = 0xA3;
    SET_LO16(ecx, ZX8(LO8(ebx)));

loc_003C1B08: ;
    MEM16(eax + 0x34) = LO16(ecx);

loc_003C1B0C: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B14); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1B14: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C1B1B
 * Original: 0x003C1B1B - 0x003C1B4B (48 bytes, 16 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1B1B(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1B1B: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B27); sub_003BF698(); /* call 0x003BF698 */

loc_003C1B27: ;
    /* test MEM8(eax), 2 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(eax), 2)); /* latched */
    PUSH32(esp, esi);
    if (_rcc0) goto loc_003C1B34; /* je: equal / zero */

loc_003C1B2D: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B32); sub_003C1688(); /* call 0x003C1688 */

loc_003C1B32: ;
    goto loc_003C1B47;

loc_003C1B34: ;
    if (CMP_EQ(MEM16(eax + 0x3A), 0)) goto loc_003C1B42; /* je: equal / zero */

loc_003C1B3B: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B40); sub_003C13CE(); /* call 0x003C13CE */

loc_003C1B40: ;
    goto loc_003C1B47;

loc_003C1B42: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B47); sub_003C1A48(); /* call 0x003C1A48 */

loc_003C1B47: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1B4B
 * Original: 0x003C1B4B - 0x003C1BCB (128 bytes, 45 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1B4B(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1B4B: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B59); sub_003BF698(); /* call 0x003BF698 */

loc_003C1B59: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1B77); sub_003BDC0D(); /* call 0x003BDC0D */

loc_003C1B77: ;
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
    MEM32(esi + 0x10) = 0x3C1B1B;
    MEM32(esi + 0x14) = edi;
    MEM8(esi + 0x30) = 0x23;
    MEM8(esi + 0x31) = 1;
    MEM16(esi + 0x32) = 0x10;
    MEM16(esi + 0x34) = LO16(edx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1BC5); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1BC5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1BCB
 * Original: 0x003C1BCB - 0x003C1C76 (171 bytes, 54 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1BCB(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1BCB: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x14);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1BD9); sub_003BF698(); /* call 0x003BF698 */

loc_003C1BD9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    esi = eax;
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1BE6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1BE6: ;
    eax = MEM32(esp + 0x10);
    ebx = 0; /* xor self */
    if (CMP_GE(MEM32(eax + 4), ebx)) goto loc_003C1BF9; /* jge: greater or equal (signed >=) */

loc_003C1BF1: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1BF7); sub_003C1688(); /* call 0x003C1688 */

loc_003C1BF7: ;
    goto loc_003C1C70;

loc_003C1BF9: ;
    SET_LO8(eax, MEM8(0xF309AA));
    /* cmp LO8(eax), 7 - flags set for next jcc */
    MEM8(esi + 2) = LO8(eax);
    if (CMP_BE(LO8(eax), 7)) goto loc_003C1C09; /* jbe: below or equal (unsigned <=) */

loc_003C1C05: ;
    MEM8(esi + 2) = 7;

loc_003C1C09: ;
    PUSH32(esp, 3);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1C10); sub_003C136B(); /* call 0x003C136B */

loc_003C1C10: ;
    PUSH32(esp, 1);
    PUSH32(esp, esi);
    MEM32(0xF30A58) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1C1E); sub_003C12C4(); /* call 0x003C12C4 */

loc_003C1C1E: ;
    PUSH32(esp, ebx);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1C26); sub_003BE253(); /* call 0x003BE253 */

loc_003C1C26: ;
    eax = esi + 8;
    PUSH32(esp, eax);
    ecx = edi;
    MEM8(esi + 3) = 1;
    MEM8(eax) = 0x30;
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3C19DD;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1C70); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1C70: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1C76
 * Original: 0x003C1C76 - 0x003C1CF2 (124 bytes, 37 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1C76(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1C76: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0xF30A10);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1C82); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1C82: ;
    esi = MEM32(esp + 8);
    eax = 0; /* xor self */
    if (CMP_GE(MEM32(esi + 4), eax)) goto loc_003C1C98; /* jge: greater or equal (signed >=) */

loc_003C1C8D: ;
    PUSH32(esp, MEM32(esp + 0xC));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1C96); sub_003C1688(); /* call 0x003C1688 */

loc_003C1C96: ;
    goto loc_003C1CEE;

loc_003C1C98: ;
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    PUSH32(esp, 8);
    POP32(esp, ecx);
    PUSH32(esp, eax);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3C1BCB;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = eax;
    MEM32(esi + 0x18) = 0xF309A8;
    MEM32(esi + 0x14) = ecx;
    MEM8(esi + 0x1C) = 2;
    MEM8(esi + 0x1D) = 1;
    MEM8(esi + 0x1E) = LO8(eax);
    MEM8(esi + 0x28) = 0xA0;
    MEM8(esi + 0x29) = 6;
    MEM16(esi + 0x2A) = 0x2900;
    MEM16(esi + 0x2C) = LO16(eax);
    MEM16(esi + 0x2E) = LO16(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1CE5); sub_003C136B(); /* call 0x003C136B */

loc_003C1CE5: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1CED); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1CED: ;
    POP32(esp, edi);

loc_003C1CEE: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1CF2
 * Original: 0x003C1CF2 - 0x003C1E18 (294 bytes, 90 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1CF2(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C1CF2: ;
    PUSH32(esp, ebp);
    ebp = esp;
    ecx = MEM32(ebp + 0xC);
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1D00); sub_003BF698(); /* call 0x003BF698 */

loc_003C1D00: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0xF30A10);
    edi = eax;
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1D0D); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1D0D: ;
    esi = MEM32(ebp + 8);
    ebx = 0; /* xor self */
    if (CMP_L(MEM32(esi + 4), ebx)) goto loc_003C1E08; /* jl: less (signed <) */

loc_003C1D1B: ;
    SET_LO16(ecx, MEM16(0xF309AA));
    edx = 0; /* xor self */
    /* cmp LO16(ecx), 0x30 - flags set for next jcc */
    eax = 0xF309A8;
    if (CMP_A(LO16(ecx), 0x30)) goto loc_003C1E08; /* ja: above (unsigned >) */

loc_003C1D33: ;
    ecx = ZX16(LO16(ecx));
    /* cmp MEM32(esi + 0x14), ecx - flags set for next jcc */
    _rcc0 = (CMP_B(MEM32(esi + 0x14), ecx)); /* latched */
    MEM32(ebp + 8) = ecx;
    if (_rcc0) goto loc_003C1E08; /* jb: below (unsigned <) */

loc_003C1D42: ;
    SET_LO8(eax, MEM8(eax));
    ecx = ZX8(LO8(eax));
    edx = edx + ecx;
    if (CMP_EQ(LO8(eax), LO8(ebx))) goto loc_003C1E08; /* je: equal / zero */

loc_003C1D51: ;
    if (CMP_AE(edx, MEM32(ebp + 8))) goto loc_003C1E08; /* jae: above or equal (unsigned >=) */

loc_003C1D5A: ;
    eax = edx + 0xF309A8;
    if (CMP_NE(MEM8(eax + 1), 5)) { RECOMP_SLICE_POINT(); goto loc_003C1D42; } /* jne: not equal / not zero */

loc_003C1D66: ;
    if (CMP_A(MEM16(eax + 4), 4)) goto loc_003C1D75; /* ja: above (unsigned >) */

loc_003C1D6D: ;
    SET_LO8(ecx, MEM8(eax + 4));
    MEM8(edi + 7) = LO8(ecx);
    goto loc_003C1D79;

loc_003C1D75: ;
    MEM8(edi + 7) = 4;

loc_003C1D79: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1DAD); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1DAD: ;
    if (TEST_S(eax, eax)) goto loc_003C1E08; /* jl: less (signed <) */

loc_003C1DB1: ;
    eax = MEM32(esi + 0x10);
    MEM32(edi + 0x3C) = eax;
    edi = MEM32(ebp + 0xC);
    MEM8(esi) = 0x30;
    MEM8(esi + 1) = 0x40;
    MEM32(esi + 8) = 0x3C1C76;
    MEM32(esi + 0xC) = edi;
    MEM32(esi + 0x10) = ebx;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x14) = ebx;
    MEM8(esi + 0x1C) = LO8(ebx);
    MEM8(esi + 0x1D) = LO8(ebx);
    MEM8(esi + 0x1E) = LO8(ebx);
    MEM8(esi + 0x28) = LO8(ebx);
    MEM8(esi + 0x29) = 9;
    SET_LO16(eax, ZX8(MEM8(0xF309AD)));
    PUSH32(esp, ebx);
    MEM16(esi + 0x2A) = LO16(eax);
    MEM16(esi + 0x2C) = LO16(ebx);
    MEM16(esi + 0x2E) = LO16(ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1DFE); sub_003C136B(); /* call 0x003C136B */

loc_003C1DFE: ;
    PUSH32(esp, esi);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1E06); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1E06: ;
    goto loc_003C1E11;

loc_003C1E08: ;
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1E11); sub_003C1666(); /* call 0x003C1666 */

loc_003C1E11: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C1E18
 * Original: 0x003C1E18 - 0x003C1EFA (226 bytes, 72 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1E18(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1E18: ;
    SET_LO16(eax, MEM16(0xF30A62));
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = 0; /* xor self */
    esi = 0; /* xor self */
    if (CMP_AE(LO16(eax), MEM16(0xF30A60))) goto loc_003C1EE7; /* jae: above or equal (unsigned >=) */

loc_003C1E31: ;
    eax = MEM32(0xF30A64);
    if (TEST_Z(MEM8(eax), 1)) goto loc_003C1E46; /* je: equal / zero */

loc_003C1E3B: ;
    ecx = eax;

loc_003C1E3D: ;
    ecx = ecx + 0x40;
    esi++;
    if (TEST_NZ(MEM8(ecx), 1)) { RECOMP_SLICE_POINT(); goto loc_003C1E3D; } /* jne: not equal / not zero */

loc_003C1E46: ;
    MEM16(0xF30A62) = MEM16(0xF30A62) + 1;
    PUSH32(esp, ebp);
    ebp = MEM32(esp + 0x10);
    esi = esi << 6;
    PUSH32(esp, edi);
    esi = esi + eax;
    PUSH32(esp, esi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1E60); sub_003BF69C(); /* call 0x003BF69C */

loc_003C1E60: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1E83); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1E83: ;
    PUSH32(esp, 0x30);
    POP32(esp, eax);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    PUSH32(esp, 0x3C12FA);
    PUSH32(esp, 0xF30A38);
    MEM8(edi) = LO8(eax);
    MEM8(esi + 9) = 0x40;
    MEM32(esi + 0x10) = 0x3C1CF2;
    MEM32(esi + 0x14) = ebp;
    MEM32(esi + 0x18) = ebx;
    MEM32(esi + 0x20) = 0xF309A8;
    MEM32(esi + 0x1C) = eax;
    MEM8(esi + 0x24) = 2;
    MEM8(esi + 0x25) = 1;
    MEM8(esi + 0x26) = LO8(ebx);
    MEM8(esi + 0x30) = 0x80;
    MEM8(esi + 0x31) = 6;
    MEM16(esi + 0x32) = 0x200;
    MEM16(esi + 0x34) = LO16(ebx);
    MEM16(esi + 0x36) = LO16(eax);
    { uint32_t _icall_t = MEM32(0x3C4FDC); g_seh_ebp = ebp; PUSH32(esp, 0x3C1ED5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1ED5: ;
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1EDB); sub_003C136B(); /* call 0x003C136B */

loc_003C1EDB: ;
    PUSH32(esp, edi);
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1EE3); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C1EE3: ;
    POP32(esp, edi);
    POP32(esp, ebp);
    goto loc_003C1EF5;

loc_003C1EE7: ;
    ecx = MEM32(esp + 0xC);
    PUSH32(esp, 0x80000100u);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1EF5); sub_003BE253(); /* call 0x003BE253 */

loc_003C1EF5: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C1EFA
 * Original: 0x003C1EFA - 0x003C1F89 (143 bytes, 56 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1EFA(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1EFA: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = ecx;
    /* cmp MEM8(esi + 0x460), 0 - flags set for next jcc */
    ebp = edx;
    SET_LO8(ebx, 1);
    if (CMP_BE(MEM8(esi + 0x460), 0)) goto loc_003C1F84; /* jbe: below or equal (unsigned <=) */

loc_003C1F0D: ;
    MEM8(esp + 0xC) = LO8(ebx);
    PUSH32(esp, edi);

loc_003C1F12: ;
    SET_LO16(eax, ZX8(LO8(ebx)));
    if (TEST_Z(MEM16(ebp), LO16(eax))) goto loc_003C1F6F; /* je: equal / zero */

loc_003C1F1C: ;
    ecx = 0; /* xor self */
    SET_LO16(ecx, MEM16(ebp + 2));
    ecx = ecx & eax;
    if (TEST_Z(LO16(ecx), LO16(ecx))) goto loc_003C1F51; /* je: equal / zero */

loc_003C1F29: ;
    ecx = esi + 0x461;
    SET_LO8(eax, MEM8(ecx));
    if (TEST_Z(LO8(ebx), LO8(eax))) goto loc_003C1F41; /* je: equal / zero */

loc_003C1F35: ;
    PUSH32(esp, MEM32(esp + 0x10));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1F3F); sub_003BE13B(); /* call 0x003BE13B */

loc_003C1F3F: ;
    goto loc_003C1F45;

loc_003C1F41: ;
    SET_LO8(eax, LO8(eax) | LO8(ebx));
    MEM8(ecx) = LO8(eax);

loc_003C1F45: ;
    PUSH32(esp, MEM32(esp + 0x10));
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1F4F); sub_003BDE0B(); /* call 0x003BDE0B */

loc_003C1F4F: ;
    goto loc_003C1F6F;

loc_003C1F51: ;
    edi = esi + 0x461;
    SET_LO8(eax, MEM8(edi));
    if (TEST_Z(LO8(ebx), LO8(eax))) goto loc_003C1F6F; /* je: equal / zero */

loc_003C1F5D: ;
    PUSH32(esp, MEM32(esp + 0x10));
    SET_LO8(ecx, LO8(ebx));
    SET_LO8(ecx, ~LO8(ecx));
    SET_LO8(ecx, LO8(ecx) & LO8(eax));
    PUSH32(esp, esi);
    MEM8(edi) = LO8(ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C1F6F); sub_003BE13B(); /* call 0x003BE13B */

loc_003C1F6F: ;
    MEM8(esp + 0x10) = MEM8(esp + 0x10) + 1;
    SET_LO8(eax, MEM8(esp + 0x10));
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(eax, LO8(eax) - 1);
    if (CMP_B(LO8(eax), MEM8(esi + 0x460))) { RECOMP_SLICE_POINT(); goto loc_003C1F12; } /* jb: below (unsigned <) */

loc_003C1F83: ;
    POP32(esp, edi);

loc_003C1F84: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C1F89
 * Original: 0x003C1F89 - 0x003C1FD6 (77 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1F89(void)
{
    uint32_t ebp;

loc_003C1F89: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FF8); g_seh_ebp = ebp; PUSH32(esp, 0x3C1FD1); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C1FD1: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C1FD6
 * Original: 0x003C1FD6 - 0x003C1FF3 (29 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1FD6(void)
{
    uint32_t ebp;

loc_003C1FD6: ;
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
 * sub_003C1FF3
 * Original: 0x003C1FF3 - 0x003C201E (43 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C1FF3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C1FF3: ;
    ecx = MEM32(esp + 8);
    eax = ecx + 0x470;
    edx = MEM32(eax);
    ecx = ecx + 0x474;
    /* test edx, edx - flags set for next jcc */
    PUSH32(esp, esi);
    esi = MEM32(ecx);
    if (TEST_Z(edx, edx)) goto loc_003C201A; /* je: equal / zero */

loc_003C200C: ;
    MEM32(eax) = MEM32(eax) & 0;
    MEM32(ecx) = MEM32(ecx) & 0;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    PUSH32(esp, 0x80000600u);
    { uint32_t _icall_t = edx; g_seh_ebp = ebp; PUSH32(esp, 0x3C201A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C201A: ;
    POP32(esp, esi);
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C201E
 * Original: 0x003C201E - 0x003C20DD (191 bytes, 64 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C201E(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C201E: ;
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
    if (CMP_BE(edx & edx, 0)) goto loc_003C20CF; /* jbe: below or equal (unsigned <=) */

loc_003C204B: ;
    MEM32(ebp + -16) = ecx;
    MEM32(ebp + -20) = edx;
    PUSH32(esp, ebx);

loc_003C2052: ;
    edi = MEM32(ecx);
    MEM32(ebp + -4) = edi;
    if (TEST_Z(MEM8(ebp + -2), 0x10)) goto loc_003C209C; /* je: equal / zero */

loc_003C205D: ;
    ecx = MEM32(esi + 0x474);
    ebx = esi + 0x470;
    eax = MEM32(ebx);
    /* test eax, eax - flags set for next jcc */
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -24) = ecx;
    if (TEST_Z(eax, eax)) goto loc_003C209C; /* je: equal / zero */

loc_003C2075: ;
    eax = esi + 0x478;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FFC); g_seh_ebp = ebp; PUSH32(esp, 0x3C2082); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2082: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -24));
    MEM32(ebx) = MEM32(ebx) & 0;
    MEM32(esi + 0x474) = MEM32(esi + 0x474) & 0;
    edi = edi & 0x200;
    edi = edi << 0xF;
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(ebp + -28); g_seh_ebp = ebp; PUSH32(esp, 0x3C209C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C209C: ;
    if (TEST_Z(MEM8(ebp + -2), 1)) goto loc_003C20B3; /* je: equal / zero */

loc_003C20A2: ;
    eax = MEM32(ebp + -12);
    MEM16(ebp + -8) = MEM16(ebp + -8) | LO16(eax);
    if (TEST_Z(MEM8(ebp + -4), 1)) goto loc_003C20B3; /* je: equal / zero */

loc_003C20AF: ;
    MEM16(ebp + -6) = MEM16(ebp + -6) | LO16(eax);

loc_003C20B3: ;
    MEM16(ebp + -4) = MEM16(ebp + -4) & 0;
    ecx = MEM32(ebp + -16);
    eax = MEM32(ebp + -4);
    MEM32(ebp + -12) = MEM32(ebp + -12) << 1;
    MEM32(ecx) = eax;
    ecx = ecx + 4;
    MEM32(ebp + -20) = MEM32(ebp + -20) - 1;
    _rcc0 = ((MEM32(ebp + -20) != 0)); /* latched */
    MEM32(ebp + -16) = ecx;
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003C2052; } /* jne: not equal / not zero */

loc_003C20CE: ;
    POP32(esp, ebx);

loc_003C20CF: ;
    edx = ebp + -8;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C20D9); sub_003C1EFA(); /* call 0x003C1EFA */

loc_003C20D9: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C20DD
 * Original: 0x003C20DD - 0x003C20F0 (19 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C20DD(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C20DD: ;
    eax = MEM32(0xF4C348);
    if (TEST_Z(eax, eax)) goto loc_003C20EF; /* je: equal / zero */

loc_003C20E6: ;
    ecx = MEM32(eax + 0x18);
    MEM32(0xF4C348) = ecx;

loc_003C20EF: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C20F0
 * Original: 0x003C20F0 - 0x003C2264 (372 bytes, 133 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C20F0(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C20F0: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    MEM32(ebp + -8) = MEM32(ebp + -8) & 0;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    ebx = edx;
    MEM32(ebp + -12) = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C2107); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2107: ;
    MEM8(ebp + -1) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C210F); sub_003C20DD(); /* call 0x003C20DD */

loc_003C210F: ;
    esi = eax;
    if (TEST_NZ(esi, esi)) goto loc_003C2121; /* jne: not equal / not zero */

loc_003C2115: ;
    MEM32(ebp + -8) = 0x80000100u;
    goto loc_003C224F;

loc_003C2121: ;
    PUSH32(esp, edi);
    eax = 0; /* xor self */
    PUSH32(esp, 0xC);
    POP32(esp, ecx);
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = esi;
    eax = eax - MEM32(0xF4C340);
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C215A); sub_003BE9FB(); /* call 0x003BE9FB */

loc_003C215A: ;
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
    _rcc0 = (CMP_NE(MEM8(esi + 0x11), 0)); /* latched */
    MEM32(esi) = eax;
    if (_rcc0) goto loc_003C218D; /* jne: not equal / not zero */

loc_003C2184: ;
    eax = eax & 0xFFFFE7FFu;
    MEM32(esi) = eax;
    goto loc_003C21A7;

loc_003C218D: ;
    /* test MEM8(ebx + 0x15), 0x80 - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM8(ebx + 0x15), 0x80)); /* latched */
    PUSH32(esp, 0);
    POP32(esp, ecx);
    SET_LO8(ecx, (_rcc0) ? 1 : 0); /* setne */
    ecx++;
    ecx = ecx << 0xB;
    ecx = ecx ^ eax;
    ecx = ecx & 0x1800;
    ecx = ecx ^ eax;
    MEM32(esi) = ecx;

loc_003C21A7: ;
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
    if (CMP_EQ(edx, eax)) goto loc_003C220D; /* je: equal / zero */

loc_003C21E6: ;
    eax = ecx;
    edi = 0; /* xor self */
    ecx = ecx >> 7;
    ecx = ecx & 0xF;
    edi++;
    eax = eax & 0x1800;
    edi = edi << LO8(ecx);
    if (CMP_NE(eax, 0x1000)) goto loc_003C2202; /* jne: not equal / not zero */

loc_003C21FF: ;
    edi = edi << 0x10;

loc_003C2202: ;
    if (TEST_Z(MEM32(edx), edi)) goto loc_003C220D; /* je: equal / zero */

loc_003C2206: ;
    MEM32(esi + 8) = 2;

loc_003C220D: ;
    SET_LO8(eax, MEM8(esi + 0x11));
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    POP32(esp, edi);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C2228; /* je: equal / zero */

loc_003C2215: ;
    if (CMP_EQ(LO8(eax), 2)) goto loc_003C2228; /* je: equal / zero */

loc_003C2219: ;
    ecx = MEM32(ebp + -12);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2223); sub_003C2802(); /* call 0x003C2802 */

loc_003C2223: ;
    MEM32(ebp + -8) = eax;
    goto loc_003C2232;

loc_003C2228: ;
    ecx = MEM32(ebp + -12);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2232); sub_003C26E8(); /* call 0x003C26E8 */

loc_003C2232: ;
    if (CMP_L(MEM32(ebp + -8), 0)) goto loc_003C223D; /* jl: less (signed <) */

loc_003C2238: ;
    MEM32(ebx + 0x10) = esi;
    goto loc_003C224F;

loc_003C223D: ;
    MEM32(ebx + 0x10) = MEM32(ebx + 0x10) & 0;
    eax = MEM32(0xF4C348);
    MEM32(esi + 0x18) = eax;
    MEM32(0xF4C348) = esi;

loc_003C224F: ;
    esi = MEM32(ebp + -8);
    SET_LO8(ecx, MEM8(ebp + -1));
    MEM32(ebx + 4) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C225E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C225E: ;
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C2264
 * Original: 0x003C2264 - 0x003C2285 (33 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2264(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C2264: ;
    ecx = MEM32(edx + 0x10);
    eax = MEM32(ecx + 8);
    eax = eax & 1;
    MEM32(edx + 0x14) = eax;
    if (CMP_NE(MEM8(ecx + 0x26), 0)) goto loc_003C227C; /* jne: not equal / not zero */

loc_003C2276: ;
    if (CMP_EQ(MEM8(ecx + 0x27), 0)) goto loc_003C2282; /* je: equal / zero */

loc_003C227C: ;
    eax = eax | 2;
    MEM32(edx + 0x14) = eax;

loc_003C2282: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003C2285
 * Original: 0x003C2285 - 0x003C22B3 (46 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2285(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C2285: ;
    eax = MEM32(edx + 0x10);
    edx = MEM32(edx + 0x14);
    if (TEST_Z(LO8(edx), 4)) goto loc_003C2294; /* je: equal / zero */

loc_003C2290: ;
    MEM32(eax + 8) = MEM32(eax + 8) & 0xFFFFFFFDu;

loc_003C2294: ;
    if (TEST_Z(LO8(edx), 8)) goto loc_003C229D; /* je: equal / zero */

loc_003C2299: ;
    MEM32(eax + 8) = MEM32(eax + 8) | 2;

loc_003C229D: ;
    if (TEST_NZ(LO8(edx), 1)) goto loc_003C22B0; /* jne: not equal / not zero */

loc_003C22A2: ;
    ecx = MEM32(eax + 8);
    if (TEST_Z(LO8(ecx), 1)) goto loc_003C22B0; /* je: equal / zero */

loc_003C22AA: ;
    ecx = ecx & 0xFFFFFFFEu;
    MEM32(eax + 8) = ecx;

loc_003C22B0: ;
    eax = 0; /* xor self */
    esp += 4; return; /* ret */

}

/**
 * sub_003C22B3
 * Original: 0x003C22B3 - 0x003C22EC (57 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C22B3(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C22B3: ;
    eax = MEM32(ecx + 0x41C);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003C22CD; /* je: equal / zero */

loc_003C22C0: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003C22C0; } /* jne: not equal / not zero */

loc_003C22C9: ;
    if (TEST_NZ(esi, esi)) goto loc_003C22D8; /* jne: not equal / not zero */

loc_003C22CD: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x41C) = eax;
    goto loc_003C22DE;

loc_003C22D8: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

loc_003C22DE: ;
    eax = ecx + 0x420;
    if (CMP_NE(edx, MEM32(eax))) goto loc_003C22EA; /* jne: not equal / not zero */

loc_003C22E8: ;
    MEM32(eax) = esi;

loc_003C22EA: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C22EC
 * Original: 0x003C22EC - 0x003C2325 (57 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C22EC(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C22EC: ;
    eax = MEM32(ecx + 0x424);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003C2306; /* je: equal / zero */

loc_003C22F9: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003C22F9; } /* jne: not equal / not zero */

loc_003C2302: ;
    if (TEST_NZ(esi, esi)) goto loc_003C2311; /* jne: not equal / not zero */

loc_003C2306: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x424) = eax;
    goto loc_003C2317;

loc_003C2311: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

loc_003C2317: ;
    eax = ecx + 0x428;
    if (CMP_NE(edx, MEM32(eax))) goto loc_003C2323; /* jne: not equal / not zero */

loc_003C2321: ;
    MEM32(eax) = esi;

loc_003C2323: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C2325
 * Original: 0x003C2325 - 0x003C2354 (47 bytes, 21 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2325(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C2325: ;
    eax = MEM32(ecx + 0x28);
    PUSH32(esp, esi);
    esi = 0; /* xor self */
    if (CMP_EQ(eax, edx)) goto loc_003C233C; /* je: equal / zero */

loc_003C232F: ;
    esi = eax;
    eax = MEM32(eax + 0x24);
    if (CMP_NE(eax, edx)) { RECOMP_SLICE_POINT(); goto loc_003C232F; } /* jne: not equal / not zero */

loc_003C2338: ;
    if (TEST_NZ(esi, esi)) goto loc_003C2344; /* jne: not equal / not zero */

loc_003C233C: ;
    eax = MEM32(eax + 0x24);
    MEM32(ecx + 0x28) = eax;
    goto loc_003C234A;

loc_003C2344: ;
    eax = MEM32(eax + 0x24);
    MEM32(esi + 0x24) = eax;

loc_003C234A: ;
    if (CMP_NE(edx, MEM32(ecx + 0x2C))) goto loc_003C2352; /* jne: not equal / not zero */

loc_003C234F: ;
    MEM32(ecx + 0x2C) = esi;

loc_003C2352: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C2354
 * Original: 0x003C2354 - 0x003C23CA (118 bytes, 46 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2354(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2354: ;
    PUSH32(esp, ecx);
    PUSH32(esp, edi);
    edi = edx;
    if (CMP_EQ(MEM8(edi + 0x26), 0)) goto loc_003C23C7; /* je: equal / zero */

loc_003C235E: ;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    if ((eax == 0)) goto loc_003C2386; /* je: equal / zero */

loc_003C2369: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003C2378; /* je: equal / zero */

loc_003C236D: ;
    eax--;
    if ((eax != 0)) goto loc_003C23C5; /* jne: not equal / not zero */

loc_003C2370: ;
    ebx = edi + 0x28;
    ebp = edi + 0x2C;
    goto loc_003C2392;

loc_003C2378: ;
    ebx = ecx + 0x424;
    ebp = ecx + 0x428;
    goto loc_003C2392;

loc_003C2386: ;
    ebx = ecx + 0x41C;
    ebp = ecx + 0x420;

loc_003C2392: ;
    PUSH32(esp, esi);

loc_003C2393: ;
    esi = MEM32(ebx);
    if (CMP_NE(MEM32(esi + 0x10), edi)) goto loc_003C23B1; /* jne: not equal / not zero */

loc_003C239A: ;
    eax = MEM32(esi + 0x24);
    MEM32(ebx) = eax;
    MEM32(esi + 4) = 0xC000000Fu;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C23AF); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C23AF: ;
    goto loc_003C23B8;

loc_003C23B1: ;
    MEM32(esp + 0x10) = esi;
    ebx = esi + 0x24;

loc_003C23B8: ;
    if (CMP_NE(MEM32(ebp), esi)) { RECOMP_SLICE_POINT(); goto loc_003C2393; } /* jne: not equal / not zero */

loc_003C23BD: ;
    eax = MEM32(esp + 0x10);
    MEM32(ebp) = eax;
    POP32(esp, esi);

loc_003C23C5: ;
    POP32(esp, ebp);
    POP32(esp, ebx);

loc_003C23C7: ;
    POP32(esp, edi);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C23CA
 * Original: 0x003C23CA - 0x003C2407 (61 bytes, 24 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C23CA(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C23CA: ;
    PUSH32(esp, esi);
    esi = edx;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) + 1;
    /* test MEM8(esi + 0x10), 0x20 - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM8(esi + 0x10), 0x20)); /* latched */
    PUSH32(esp, edi);
    edi = ecx;
    if (_rcc0) goto loc_003C2404; /* jne: not equal / not zero */

loc_003C23D9: ;
    MEM8(esi + 1) = MEM8(esi + 1) | 0x40;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C23E2); sub_003C2BED(); /* call 0x003C2BED */

loc_003C23E2: ;
    eax++;
    MEM32(esi + 0x1C) = eax;
    if (CMP_EQ(MEM32(edi + 0x438), 0)) goto loc_003C23F3; /* je: equal / zero */

loc_003C23EF: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x40;

loc_003C23F3: ;
    ecx = MEM32(edi);
    PUSH32(esp, 4);
    POP32(esp, eax);
    MEM32(ecx + 0xC) = eax;
    ecx = MEM32(edi);
    MEM32(ecx + 0x10) = eax;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x20;

loc_003C2404: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C2407
 * Original: 0x003C2407 - 0x003C2442 (59 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2407(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2407: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, esi);
    esi = MEM32(esp + 8);
    eax = MEM32(esi + -100);
    esi = esi + 0xFFFFFB40u;
    eax = (uint32_t)((int32_t)eax * (int32_t)0x70);
    SET_LO8(ecx, MEM8(eax + 0xF4C3EC));
    { uint32_t _icall_t = MEM32(0x3C502C); g_seh_ebp = ebp; PUSH32(esp, 0x3C2424); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2424: ;
    ecx = MEM32(esi);
    MEM32(ecx + 0x14) = 0x80000033u;
    ecx = MEM32(esi);
    MEM32(ecx + 4) = 2;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C243E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C243E: ;
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C2442
 * Original: 0x003C2442 - 0x003C24F9 (183 bytes, 61 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2442(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2442: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    if (TEST_Z(MEM8(esi + 0x22), 1)) goto loc_003C2457; /* je: equal / zero */

loc_003C244D: ;
    eax = 0x40020000;
    goto loc_003C24F5;

loc_003C2457: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C245F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C245F: ;
    edi = MEM32(esi + 0x10);
    /* test MEM8(edi + 0x10), 0x10 - flags set for next jcc */
    SET_LO8(ebx, LO8(eax));
    if (TEST_NZ(MEM8(edi + 0x10), 0x10)) goto loc_003C24E4; /* jne: not equal / not zero */

loc_003C246A: ;
    SET_LO16(eax, MEM16(esi + 0x22));
    if (TEST_Z(LO8(eax), 2)) goto loc_003C24C4; /* je: equal / zero */

loc_003C2472: ;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003C24A1; /* je: equal / zero */

loc_003C247B: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003C2494; /* je: equal / zero */

loc_003C247F: ;
    eax--;
    if ((eax == 0)) goto loc_003C2489; /* je: equal / zero */

loc_003C2482: ;
    esi = 0x80000600u;
    goto loc_003C24E9;

loc_003C2489: ;
    edx = esi;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2492); sub_003C2325(); /* call 0x003C2325 */

loc_003C2492: ;
    goto loc_003C24AC;

loc_003C2494: ;
    ecx = MEM32(esp + 0x10);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C249F); sub_003C22EC(); /* call 0x003C22EC */

loc_003C249F: ;
    goto loc_003C24AC;

loc_003C24A1: ;
    ecx = MEM32(esp + 0x10);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C24AC); sub_003C22B3(); /* call 0x003C22B3 */

loc_003C24AC: ;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;
    MEM8(esi + 0x22) = MEM8(esi + 0x22) | 1;
    PUSH32(esp, esi);
    MEM32(esi + 4) = 0xC000000Fu;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C24C0); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C24C0: ;
    esi = 0; /* xor self */
    goto loc_003C24E9;

loc_003C24C4: ;
    ecx = MEM32(esp + 0x10);
    SET_LO16(eax, LO16(eax) | 1);
    MEM16(esi + 0x22) = LO16(eax);
    eax = ecx + 0x42C;
    edx = MEM32(eax);
    MEM32(esi + 0x24) = edx;
    edx = edi;
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C24E4); sub_003C23CA(); /* call 0x003C23CA */

loc_003C24E4: ;
    esi = 0x40020000;

loc_003C24E9: ;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C24F1); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C24F1: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, ebx);

loc_003C24F5: ;
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C24F9
 * Original: 0x003C24F9 - 0x003C2560 (103 bytes, 40 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C24F9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C24F9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    esi = MEM32(edi + 0x10);
    ebp = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C250A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C250A: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 0x10;
    edx = esi;
    ecx = ebp;
    SET_LO8(ebx, LO8(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2519); sub_003C2354(); /* call 0x003C2354 */

loc_003C2519: ;
    SET_LO8(eax, MEM8(esi + 0x11));
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C252F; /* je: equal / zero */

loc_003C2520: ;
    if (CMP_EQ(LO8(eax), 2)) goto loc_003C252F; /* je: equal / zero */

loc_003C2524: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C252D); sub_003C29DE(); /* call 0x003C29DE */

loc_003C252D: ;
    goto loc_003C2538;

loc_003C252F: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2538); sub_003C2725(); /* call 0x003C2725 */

loc_003C2538: ;
    edx = esi;
    ecx = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2541); sub_003C23CA(); /* call 0x003C23CA */

loc_003C2541: ;
    eax = ebp + 0x434;
    ecx = MEM32(eax);
    MEM32(edi + 0x14) = ecx;
    SET_LO8(ecx, LO8(ebx));
    MEM32(eax) = edi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C2556); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2556: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = 0x40000000;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C2560
 * Original: 0x003C2560 - 0x003C25B3 (83 bytes, 33 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2560(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2560: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C2574); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2574: ;
    edx = edi;
    ecx = ebp;
    MEM8(esp + 0x13) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2581); sub_003C2354(); /* call 0x003C2354 */

loc_003C2581: ;
    if (CMP_EQ(MEM8(edi + 0x27), LO8(ebx))) goto loc_003C25A1; /* je: equal / zero */

loc_003C2586: ;
    eax = ebp + 0x430;
    ecx = MEM32(eax);
    MEM32(esi + 0x14) = ecx;
    edx = edi;
    ecx = ebp;
    MEM32(eax) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C259C); sub_003C23CA(); /* call 0x003C23CA */

loc_003C259C: ;
    ebx = 0x40000000;

loc_003C25A1: ;
    SET_LO8(ecx, MEM8(esp + 0x13));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C25AB); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C25AB: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = ebx;
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C25B3
 * Original: 0x003C25B3 - 0x003C26CB (280 bytes, 98 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C25B3(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C25B3: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(ebp + 0xC);
    eax = ZX8(MEM8(edi + 1));
    if (CMP_G(eax, 0xC)) goto loc_003C264B; /* jg: greater (signed >) */

loc_003C25C8: ;
    if (CMP_EQ(eax, 0xC)) goto loc_003C263F; /* je: equal / zero */

loc_003C25CA: ;
    PUSH32(esp, 2);
    POP32(esp, ecx);
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003C2633; /* je: equal / zero */

loc_003C25D1: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003C2627; /* je: equal / zero */

loc_003C25D5: ;
    eax--;
    if ((eax == 0)) goto loc_003C2618; /* je: equal / zero */

loc_003C25D8: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003C2606; /* je: equal / zero */

loc_003C25DC: ;
    eax = eax - ecx;
    if ((eax == 0)) goto loc_003C25F7; /* je: equal / zero */

loc_003C25E0: ;
    eax = eax - ecx;
    if ((eax != 0)) goto loc_003C2699; /* jne: not equal / not zero */

loc_003C25E8: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C25F2); sub_003C35CD(); /* call 0x003C35CD */

loc_003C25F2: ;
    goto loc_003C26AA;

loc_003C25F7: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2601); sub_003C3353(); /* call 0x003C3353 */

loc_003C2601: ;
    goto loc_003C26AA;

loc_003C2606: ;
    ecx = MEM32(ebp + 8);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C260E); sub_003C2BED(); /* call 0x003C2BED */

loc_003C260E: ;
    MEM32(edi + 0x14) = eax;
    esi = 0; /* xor self */
    goto loc_003C26AC;

loc_003C2618: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2622); sub_003C2285(); /* call 0x003C2285 */

loc_003C2622: ;
    goto loc_003C26AA;

loc_003C2627: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2631); sub_003C2264(); /* call 0x003C2264 */

loc_003C2631: ;
    goto loc_003C26AA;

loc_003C2633: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C263D); sub_003C20F0(); /* call 0x003C20F0 */

loc_003C263D: ;
    goto loc_003C26AA;

loc_003C263F: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2649); sub_003C3734(); /* call 0x003C3734 */

loc_003C2649: ;
    goto loc_003C26AA;

loc_003C264B: ;
    if (CMP_EQ(eax, 0xD)) goto loc_003C26A0; /* je: equal / zero */

loc_003C2650: ;
    if (CMP_LE(eax, 0x3F)) goto loc_003C2699; /* jle: less or equal (signed <=) */

loc_003C2655: ;
    if (CMP_LE(eax, 0x41)) goto loc_003C268D; /* jle: less or equal (signed <=) */

loc_003C265A: ;
    if (CMP_EQ(eax, 0x43)) goto loc_003C2681; /* je: equal / zero */

loc_003C265F: ;
    if (CMP_EQ(eax, 0x46)) goto loc_003C2675; /* je: equal / zero */

loc_003C2664: ;
    if (CMP_NE(eax, 0x4A)) goto loc_003C2699; /* jne: not equal / not zero */

loc_003C2669: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2673); sub_003C3500(); /* call 0x003C3500 */

loc_003C2673: ;
    goto loc_003C26AA;

loc_003C2675: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C267F); sub_003C2560(); /* call 0x003C2560 */

loc_003C267F: ;
    goto loc_003C26AA;

loc_003C2681: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C268B); sub_003C24F9(); /* call 0x003C24F9 */

loc_003C268B: ;
    goto loc_003C26AA;

loc_003C268D: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2697); sub_003C3EFD(); /* call 0x003C3EFD */

loc_003C2697: ;
    goto loc_003C26AA;

loc_003C2699: ;
    esi = 0x80000200u;
    goto loc_003C26AC;

loc_003C26A0: ;
    ecx = MEM32(ebp + 8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C26AA); sub_003C3853(); /* call 0x003C3853 */

loc_003C26AA: ;
    esi = eax;

loc_003C26AC: ;
    eax = esi;
    eax = eax & 0xC0000000u;
    if (CMP_EQ(eax, 0x40000000)) goto loc_003C26C3; /* je: equal / zero */

loc_003C26BA: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C26C3); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C26C3: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C26CB
 * Original: 0x003C26CB - 0x003C26E8 (29 bytes, 7 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C26CB(void)
{

loc_003C26CB: ;
    eax = MEM32(esp + 4);
    MEM32(eax + 8) = MEM32(eax + 8) | 0xFFFFFFFFu;
    MEM8(eax + 0x1F) = 0xFF;
    ecx = MEM32(0xF4C34C);
    MEM32(eax + 0x14) = ecx;
    MEM32(0xF4C34C) = eax;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C26E8
 * Original: 0x003C26E8 - 0x003C2725 (61 bytes, 23 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C26E8(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    int _flags = 0; /* fallback flag var */

loc_003C26E8: ;
    /* cmp MEM8(edx + 0x11), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(edx + 0x11), 0)); /* latched */
    eax = MEM32(ecx);
    PUSH32(esp, esi);
    if (_rcc0) goto loc_003C26FC; /* jne: not equal / not zero */

loc_003C26F1: ;
    esi = ecx + 0x40C;
    eax = eax + 0x20;
    goto loc_003C2705;

loc_003C26FC: ;
    esi = ecx + 0x410;
    eax = eax + 0x28;

loc_003C2705: ;
    ecx = MEM32(esi);
    MEM32(edx + 0x18) = ecx;
    MEM32(esi) = edx;
    ecx = MEM32(edx + 0x18);
    /* test ecx, ecx - flags set for next jcc */
    POP32(esp, esi);
    if (TEST_NZ(ecx, ecx)) goto loc_003C2719; /* jne: not equal / not zero */

loc_003C2714: ;
    MEM32(edx + 0xC) = MEM32(edx + 0xC) & ecx;
    goto loc_003C271F;

loc_003C2719: ;
    ecx = MEM32(ecx + 0x14);
    MEM32(edx + 0xC) = ecx;

loc_003C271F: ;
    ecx = MEM32(edx + 0x14);
    MEM32(eax) = ecx;
    esp += 4; return; /* ret */

}

/**
 * sub_003C2725
 * Original: 0x003C2725 - 0x003C2775 (80 bytes, 33 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2725(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    int _flags = 0; /* fallback flag var */

loc_003C2725: ;
    /* cmp MEM8(edx + 0x11), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(edx + 0x11), 0)); /* latched */
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003C273A; /* jne: not equal / not zero */

loc_003C272D: ;
    esi = ecx + 0x40C;
    ecx = MEM32(ecx);
    ecx = ecx + 0x20;
    goto loc_003C2745;

loc_003C273A: ;
    esi = ecx + 0x410;
    ecx = MEM32(ecx);
    ecx = ecx + 0x28;

loc_003C2745: ;
    eax = MEM32(esi);
    edi = 0; /* xor self */

loc_003C2749: ;
    if (CMP_EQ(edx, eax)) goto loc_003C2756; /* je: equal / zero */

loc_003C274D: ;
    edi = eax;
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C2749; } /* jne: not equal / not zero */

loc_003C2756: ;
    if (TEST_Z(edi, edi)) goto loc_003C2768; /* je: equal / zero */

loc_003C275A: ;
    ecx = MEM32(eax + 0x18);
    MEM32(edi + 0x18) = ecx;
    eax = MEM32(eax + 0xC);
    MEM32(edi + 0xC) = eax;
    goto loc_003C2772;

loc_003C2768: ;
    edx = MEM32(eax + 0x18);
    MEM32(esi) = edx;
    eax = MEM32(eax + 0xC);
    MEM32(ecx) = eax;

loc_003C2772: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C2775
 * Original: 0x003C2775 - 0x003C278B (22 bytes, 12 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2775(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C2775: ;
    eax = 0; /* xor self */
    if (CMP_BE(ecx & ecx, 0)) goto loc_003C278A; /* jbe: below or equal (unsigned <=) */

loc_003C277B: ;
    PUSH32(esp, esi);

loc_003C277C: ;
    esi = edx;
    esi = esi & 1;
    edx = edx >> 1;
    ecx--;
    eax = esi + eax * 2;
    if ((ecx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C277C; } /* jne: not equal / not zero */

loc_003C2789: ;
    POP32(esp, esi);

loc_003C278A: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C278B
 * Original: 0x003C278B - 0x003C2802 (119 bytes, 50 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C278B(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C278B: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = ecx;
    SET_LO8(ecx, MEM8(ebp + 8));
    /* cmp LO8(ecx), 0x20 - flags set for next jcc */
    PUSH32(esp, edi);
    edi = edx;
    if (CMP_B(LO8(ecx), 0x20)) goto loc_003C27B3; /* jb: below (unsigned <) */

loc_003C279D: ;
    edx = ZX8(LO8(ecx));
    PUSH32(esp, 5);
    edx = edx - 0x20;
    POP32(esp, ecx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C27AB); sub_003C2775(); /* call 0x003C2775 */

loc_003C27AB: ;
    ecx = MEM32(esi + 8);
    MEM32(ecx + eax * 4) = edi;
    goto loc_003C27FC;

loc_003C27B3: ;
    SET_LO8(eax, LO8(ecx));
    SET_LO8(eax, LO8(eax) << 1);
    PUSH32(esp, ebx);
    SET_LO8(eax, LO8(eax) + 1);
    SET_LO8(ebx, LO8(ecx));
    MEM8(ebp + -4) = LO8(eax);
    MEM8(ebp + 0xB) = 0;
    SET_LO8(ebx, LO8(ebx) << 1);

loc_003C27C5: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    eax = eax + esi + 0xC;
    if (CMP_NE(MEM32(eax + 8), 0)) goto loc_003C27E3; /* jne: not equal / not zero */

loc_003C27D5: ;
    PUSH32(esp, MEM32(ebp + -4));
    edx = edi;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C27E1); sub_003C278B(); /* call 0x003C278B */

loc_003C27E1: ;
    goto loc_003C27E9;

loc_003C27E3: ;
    eax = MEM32(eax + 0xC);
    MEM32(eax + 0xC) = edi;

loc_003C27E9: ;
    SET_LO8(eax, LO8(ebx));
    /* test LO8(eax), LO8(eax) - flags set for next jcc */
    MEM8(ebp + -4) = LO8(eax);
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C27FB; /* je: equal / zero */

loc_003C27F2: ;
    MEM8(ebp + 0xB) = MEM8(ebp + 0xB) + 1;
    if (CMP_B(MEM8(ebp + 0xB), 2)) { RECOMP_SLICE_POINT(); goto loc_003C27C5; } /* jb: below (unsigned <) */

loc_003C27FB: ;
    POP32(esp, ebx);

loc_003C27FC: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C2802
 * Original: 0x003C2802 - 0x003C29DE (476 bytes, 172 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2802(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C2802: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x10;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM8(esi + 0x11), 3 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(esi + 0x11), 3)); /* latched */
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003C2866; /* jne: not equal / not zero */

loc_003C2813: ;
    SET_LO8(eax, 0x20);
    if (CMP_AE(MEM8(esi + 0x13), LO8(eax))) goto loc_003C2823; /* jae: above or equal (unsigned >=) */

loc_003C281A: ;
    SET_LO8(edx, MEM8(esi + 0x13));

loc_003C281D: ;
    SET_LO8(eax, LO8(eax) >> 1);
    if (CMP_A(LO8(eax), LO8(edx))) { RECOMP_SLICE_POINT(); goto loc_003C281D; } /* ja: above (unsigned >) */

loc_003C2823: ;
    SET_LO8(ebx, LO8(eax));
    SET_LO8(ebx, LO8(ebx) << 1);
    SET_LO8(ebx, LO8(ebx) - 1);
    /* cmp LO8(eax), LO8(ebx) - flags set for next jcc */
    edi = 0x2EE0;
    MEM8(ebp + -1) = LO8(eax);
    if (CMP_A(LO8(eax), LO8(ebx))) goto loc_003C2872; /* ja: above (unsigned >) */

loc_003C2835: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    edx = eax + ecx + 0x10;

loc_003C283F: ;
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edx + -2));
    SET_LO16(eax, LO16(eax) + MEM16(edx + 2));
    SET_LO16(eax, LO16(eax) + MEM16(edx));
    if (CMP_AE(LO16(eax), LO16(edi))) goto loc_003C2859; /* jae: above or equal (unsigned >=) */

loc_003C2851: ;
    edi = eax;
    SET_LO8(eax, MEM8(ebp + -1));
    MEM8(ebp + -5) = LO8(eax);

loc_003C2859: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) + 1;
    edx = edx + 0x10;
    if (CMP_BE(MEM8(ebp + -1), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003C283F; } /* jbe: below or equal (unsigned <=) */

loc_003C2864: ;
    goto loc_003C2872;

loc_003C2866: ;
    SET_LO16(edi, MEM16(ecx + 0x10));
    SET_LO16(edi, LO16(edi) + MEM16(ecx + 0xE));
    MEM8(ebp + -5) = 0;

loc_003C2872: ;
    SET_LO16(eax, MEM16(esi + 0x22));
    edi = ZX16(LO16(edi));
    edx = ZX16(LO16(eax));
    edx = edx + edi;
    edi = ZX16(MEM16(ecx + 0x414));
    if (CMP_LE(edx, edi)) goto loc_003C2893; /* jle: less or equal (signed <=) */

loc_003C2889: ;
    eax = 0x80000800u;
    goto loc_003C29D9;

loc_003C2893: ;
    SET_LO8(edx, MEM8(ebp + -5));
    edi = ZX8(LO8(edx));
    edi = edi << 4;
    edi = edi + ecx + 0xC;
    MEM8(esi + 0x12) = LO8(edx);
    MEM16(edi + 2) = MEM16(edi + 2) + LO16(eax);
    if (TEST_NZ(LO8(edx), LO8(edx))) goto loc_003C28B2; /* jne: not equal / not zero */

loc_003C28AB: ;
    SET_LO8(eax, 1);
    MEM8(ebp + -1) = LO8(eax);
    goto loc_003C28C3;

loc_003C28B2: ;
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) << 1);
    MEM8(ebp + -1) = LO8(eax);
    SET_LO8(eax, LO8(edx));
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_A(LO8(eax), 0x40)) goto loc_003C2903; /* ja: above (unsigned >) */

loc_003C28C3: ;
    if (CMP_A(MEM8(ebp + -1), LO8(eax))) goto loc_003C28F5; /* ja: above (unsigned >) */

loc_003C28C8: ;
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

loc_003C28E6: ;
    SET_LO16(ebx, MEM16(esi + 0x22));
    MEM16(edx) = MEM16(edx) + LO16(ebx);
    edx = edx + 0x10;
    MEM32(ebp + -12) = MEM32(ebp + -12) - 1;
    if ((MEM32(ebp + -12) != 0)) { RECOMP_SLICE_POINT(); goto loc_003C28E6; } /* jne: not equal / not zero */

loc_003C28F5: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) << 1;
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_BE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003C28C3; } /* jbe: below or equal (unsigned <=) */

loc_003C2900: ;
    SET_LO8(edx, MEM8(ebp + -5));

loc_003C2903: ;
    /* cmp LO8(edx), 1 - flags set for next jcc */
    MEM8(ebp + -1) = LO8(edx);
    if (CMP_BE(LO8(edx), 1)) goto loc_003C296C; /* jbe: below or equal (unsigned <=) */

loc_003C290B: ;
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
    if (CMP_LE(eax, edx)) goto loc_003C296C; /* jle: less or equal (signed <=) */

loc_003C294D: ;
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
    if (CMP_A(LO8(eax), 1)) { RECOMP_SLICE_POINT(); goto loc_003C290B; } /* ja: above (unsigned >) */

loc_003C296C: ;
    if (CMP_NE(MEM8(ebp + -1), 1)) goto loc_003C297E; /* jne: not equal / not zero */

loc_003C2972: ;
    SET_LO16(eax, MEM16(ecx + 0x20));
    SET_LO16(eax, LO16(eax) + MEM16(ecx + 0x1E));
    MEM16(ecx + 0x10) = LO16(eax);

loc_003C297E: ;
    eax = MEM32(edi + 8);
    edx = 0; /* xor self */
    if (CMP_NE(eax, edx)) goto loc_003C29BD; /* jne: not equal / not zero */

loc_003C2987: ;
    SET_LO8(eax, MEM8(ebp + -5));
    goto loc_003C2990;

loc_003C298C: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C299E; /* je: equal / zero */

loc_003C2990: ;
    SET_LO8(eax, LO8(eax) >> 1);
    ebx = ZX8(LO8(eax));
    ebx = ebx << 4;
    if (CMP_EQ(MEM32(ebx + ecx + 0x14), edx)) { RECOMP_SLICE_POINT(); goto loc_003C298C; } /* je: equal / zero */

loc_003C299E: ;
    eax = ZX8(LO8(eax));
    eax = eax << 4;
    eax = MEM32(eax + ecx + 0x14);
    if (CMP_EQ(eax, edx)) goto loc_003C29B2; /* je: equal / zero */

loc_003C29AC: ;
    eax = MEM32(eax + 0x14);
    MEM32(esi + 0xC) = eax;

loc_003C29B2: ;
    MEM32(edi + 8) = esi;
    MEM32(edi + 0xC) = esi;
    MEM32(esi + 0x18) = edx;
    goto loc_003C29CC;

loc_003C29BD: ;
    MEM32(esi + 0x18) = eax;
    MEM32(edi + 8) = esi;
    eax = MEM32(esi + 0x18);
    eax = MEM32(eax + 0x14);
    MEM32(esi + 0xC) = eax;

loc_003C29CC: ;
    PUSH32(esp, MEM32(ebp + -5));
    edx = MEM32(esi + 0x14);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C29D7); sub_003C278B(); /* call 0x003C278B */

loc_003C29D7: ;
    eax = 0; /* xor self */

loc_003C29D9: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C29DE
 * Original: 0x003C29DE - 0x003C2B57 (377 bytes, 138 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C29DE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C29DE: ;
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

loc_003C2A0B: ;
    if (CMP_EQ(eax, edx)) goto loc_003C2A19; /* je: equal / zero */

loc_003C2A0F: ;
    MEM32(ebp + -4) = eax;
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C2A0B; } /* jne: not equal / not zero */

loc_003C2A19: ;
    ecx = MEM32(eax + 0x18);
    if (TEST_NZ(ecx, ecx)) goto loc_003C2A54; /* jne: not equal / not zero */

loc_003C2A20: ;
    ecx = MEM32(ebp + -4);
    edx = 0; /* xor self */
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    MEM32(edi + 0xC) = ecx;
    MEM32(ebp + -8) = edx;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003C2A5C; /* je: equal / zero */

loc_003C2A2F: ;
    SET_LO8(edx, LO8(ebx));
    goto loc_003C2A37;

loc_003C2A33: ;
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003C2A46; /* je: equal / zero */

loc_003C2A37: ;
    SET_LO8(edx, LO8(edx) >> 1);
    ecx = ZX8(LO8(edx));
    ecx = ecx << 4;
    if (CMP_EQ(MEM32(ecx + esi + 0x14), 0)) { RECOMP_SLICE_POINT(); goto loc_003C2A33; } /* je: equal / zero */

loc_003C2A46: ;
    ecx = ZX8(LO8(edx));
    ecx = ecx << 4;
    ecx = MEM32(ecx + esi + 0x14);
    if (TEST_Z(ecx, ecx)) goto loc_003C2A59; /* je: equal / zero */

loc_003C2A54: ;
    edx = MEM32(ecx + 0x14);
    goto loc_003C2A5C;

loc_003C2A59: ;
    edx = MEM32(ebp + -8);

loc_003C2A5C: ;
    ecx = MEM32(ebp + -4);
    /* test ecx, ecx - flags set for next jcc */
    eax = MEM32(eax + 0x18);
    if (TEST_NZ(ecx, ecx)) goto loc_003C2A75; /* jne: not equal / not zero */

loc_003C2A66: ;
    PUSH32(esp, MEM32(ebp + -12));
    ecx = esi;
    MEM32(edi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2A73); sub_003C278B(); /* call 0x003C278B */

loc_003C2A73: ;
    goto loc_003C2A7B;

loc_003C2A75: ;
    MEM32(ecx + 0x18) = eax;
    MEM32(ecx + 0xC) = edx;

loc_003C2A7B: ;
    SET_LO16(eax, MEM16(ebp + -16));
    MEM16(edi + 2) = MEM16(edi + 2) - LO16(eax);
    if (TEST_NZ(LO8(ebx), LO8(ebx))) goto loc_003C2B4E; /* jne: not equal / not zero */

loc_003C2A8B: ;
    SET_LO8(eax, 1);
    SET_LO8(ecx, LO8(eax));

loc_003C2A8F: ;
    if (CMP_A(LO8(ecx), LO8(eax))) goto loc_003C2ABB; /* ja: above (unsigned >) */

loc_003C2A93: ;
    edx = ZX8(LO8(ecx));
    edx = edx << 4;
    edi = edx + esi + 0x12;
    SET_LO8(edx, LO8(eax));
    SET_LO8(edx, LO8(edx) - LO8(ecx));
    SET_LO8(edx, LO8(edx) + 1);
    edx = ZX8(LO8(edx));
    MEM32(ebp + -4) = edx;

loc_003C2AA9: ;
    edx = MEM32(ebp + -20);
    SET_LO16(edx, MEM16(edx + 0x22));
    MEM16(edi) = MEM16(edi) - LO16(edx);
    edi = edi + 0x10;
    MEM32(ebp + -4) = MEM32(ebp + -4) - 1;
    if ((MEM32(ebp + -4) != 0)) { RECOMP_SLICE_POINT(); goto loc_003C2AA9; } /* jne: not equal / not zero */

loc_003C2ABB: ;
    SET_LO8(eax, LO8(eax) << 1);
    SET_LO8(ecx, LO8(ecx) << 1);
    SET_LO8(eax, LO8(eax) + 1);
    if (CMP_BE(LO8(eax), 0x40)) { RECOMP_SLICE_POINT(); goto loc_003C2A8F; } /* jbe: below or equal (unsigned <=) */

loc_003C2AC5: ;
    if (CMP_BE(LO8(ebx), 1)) goto loc_003C2B3B; /* jbe: below or equal (unsigned <=) */

loc_003C2ACA: ;
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
    if (CMP_G(edi, MEM32(ebp + -4))) goto loc_003C2B15; /* jg: greater (signed >) */

loc_003C2B03: ;
    ecx = ZX8(LO8(eax));
    ecx = ecx << 4;
    ecx = ZX16(MEM16(ecx + esi + 0x10));
    if (CMP_EQ(MEM32(ebp + -4), ecx)) goto loc_003C2B38; /* je: equal / zero */

loc_003C2B13: ;
    SET_LO8(ebx, LO8(edx));

loc_003C2B15: ;
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
    if (CMP_A(LO8(eax), 1)) { RECOMP_SLICE_POINT(); goto loc_003C2ACA; } /* ja: above (unsigned >) */

loc_003C2B38: ;
    /* cmp LO8(ebx), 1 - flags set for next jcc */

loc_003C2B3B: ;
    if (CMP_NE(LO8(ebx), 1)) goto loc_003C2B49; /* jne: not equal / not zero */

loc_003C2B3D: ;
    SET_LO16(eax, MEM16(esi + 0x20));
    SET_LO16(eax, LO16(eax) + MEM16(esi + 0x1E));
    MEM16(esi + 0x10) = LO16(eax);

loc_003C2B49: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

loc_003C2B4E: ;
    SET_LO8(ecx, LO8(ebx));
    SET_LO8(eax, LO8(ebx));
    { RECOMP_SLICE_POINT(); goto loc_003C2ABB; }

}

/**
 * sub_003C2BED
 * Original: 0x003C2BED - 0x003C2C11 (36 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2BED(void)
{

loc_003C2BED: ;
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
 * sub_003C2C11
 * Original: 0x003C2C11 - 0x003C2D24 (275 bytes, 97 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2C11(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C2C11: ;
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
    if (CMP_B(eax, 0x14)) goto loc_003C2D20; /* jb: below (unsigned <) */

loc_003C2C56: ;
    edx = MEM32(ecx + 0x4D0);
    PUSH32(esp, edi);
    edi = esi + esi * 2;
    edi = edi << 4;
    edi = edi - ebx;
    if (TEST_NZ(edx, edx)) goto loc_003C2C81; /* jne: not equal / not zero */

loc_003C2C69: ;
    MEM32(ecx + 0x4D4) = MEM32(ecx + 0x4D4) & 0;
    MEM32(ecx + 0x4D0) = edi;
    MEM32(ecx + 0x4D8) = esi;
    goto loc_003C2D1F;

loc_003C2C81: ;
    eax = edi;
    eax = eax - edx;
    if (((int32_t)eax >= 0)) goto loc_003C2C8A; /* jns: not sign (positive) */

loc_003C2C87: ;
    eax = eax + 0x2F;

loc_003C2C8A: ;
    PUSH32(esp, 0x30);
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    POP32(esp, ebx);
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ebx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ebx)); }
    ebx = MEM32(ecx + 0x4D4);
    edx = eax;
    edx = edx - ebx;
    if ((edx != 0)) goto loc_003C2CB1; /* jne: not equal / not zero */

loc_003C2C9C: ;
    if (TEST_Z(eax, eax)) goto loc_003C2D1F; /* je: equal / zero */

loc_003C2CA0: ;
    if (CMP_BE(MEM32(ebp + -4), 0x61A8)) goto loc_003C2D1F; /* jbe: below or equal (unsigned <=) */

loc_003C2CA9: ;
    MEM32(ecx + 0x4D8) = esi;
    goto loc_003C2CDB;

loc_003C2CB1: ;
    /* cmp edx, 3 - flags set for next jcc */
    MEM32(ecx + 0x4D4) = eax;
    MEM32(ecx + 0x4D8) = esi;
    if (CMP_G(edx, 3)) { RECOMP_SLICE_POINT(); goto loc_003C2C69; } /* jg: greater (signed >) */

loc_003C2CC2: ;
    if (CMP_L(edx, 0xFFFFFFFDu)) { RECOMP_SLICE_POINT(); goto loc_003C2C69; } /* jl: less (signed <) */

loc_003C2CC7: ;
    if (TEST_Z(eax, eax)) goto loc_003C2D1F; /* je: equal / zero */

loc_003C2CCB: ;
    if (CMP_LE(edx & edx, 0)) goto loc_003C2CD5; /* jle: less or equal (signed <=) */

loc_003C2CCF: ;
    if (CMP_GE(ebx & ebx, 0)) goto loc_003C2CDB; /* jge: greater or equal (signed >=) */

loc_003C2CD3: ;
    /* test edx, edx - flags set for next jcc */

loc_003C2CD5: ;
    if (CMP_GE(edx & edx, 0)) goto loc_003C2D1F; /* jge: greater or equal (signed >=) */

loc_003C2CD7: ;
    if (CMP_G(ebx & ebx, 0)) goto loc_003C2D1F; /* jg: greater (signed >) */

loc_003C2CDB: ;
    ecx = MEM32(ecx);
    edx = MEM32(ecx + 0x34);
    /* test eax, eax - flags set for next jcc */
    _rcc0 = (CMP_LE(eax & eax, 0)); /* latched */
    esi = edx;
    eax = 0x3FFF;
    if (_rcc0) goto loc_003C2CFA; /* jle: less or equal (signed <=) */

loc_003C2CEB: ;
    esi = esi & eax;
    if (CMP_AE(esi, 0x2EE1)) goto loc_003C2D0D; /* jae: above or equal (unsigned >=) */

loc_003C2CF5: ;
    esi = edx + 1;
    goto loc_003C2D07;

loc_003C2CFA: ;
    esi = esi & eax;
    if (CMP_BE(esi, 0x2ED1)) goto loc_003C2D0D; /* jbe: below or equal (unsigned <=) */

loc_003C2D04: ;
    esi = edx + -1;

loc_003C2D07: ;
    esi = esi ^ edx;
    esi = esi & eax;
    edx = edx ^ esi;

loc_003C2D0D: ;
    eax = edx;
    eax = ~eax;
    eax = eax ^ edx;
    eax = eax & 0x7FFFFFFF;
    edx = ~edx;
    eax = eax ^ edx;
    MEM32(ecx + 0x34) = eax;

loc_003C2D1F: ;
    POP32(esp, edi);

loc_003C2D20: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C2D24
 * Original: 0x003C2D24 - 0x003C2DA0 (124 bytes, 48 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2D24(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2D24: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0x10);
    esi = edx;
    MEM8(esi + 0x27) = MEM8(esi + 0x27) - 1;
    eax = MEM32(edi + 0x18);
    /* test eax, eax - flags set for next jcc */
    ebx = ecx;
    if (TEST_Z(eax, eax)) goto loc_003C2D47; /* je: equal / zero */

loc_003C2D39: ;
    ecx = ZX16(MEM16(edi + 0x20));
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, ecx);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C5060); g_seh_ebp = ebp; PUSH32(esp, 0x3C2D47); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C2D47: ;
    if (TEST_Z(MEM8(edi + 0x22), 1)) goto loc_003C2D90; /* je: equal / zero */

loc_003C2D4D: ;
    eax = MEM32(ebx + 0x42C);
    ecx = 0; /* xor self */
    if (TEST_Z(eax, eax)) goto loc_003C2D90; /* je: equal / zero */

loc_003C2D59: ;
    if (CMP_EQ(edi, eax)) goto loc_003C2D66; /* je: equal / zero */

loc_003C2D5D: ;
    ecx = eax;
    eax = MEM32(eax + 0x24);
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C2D59; } /* jne: not equal / not zero */

loc_003C2D66: ;
    if (TEST_Z(eax, eax)) goto loc_003C2D90; /* je: equal / zero */

loc_003C2D6A: ;
    if (TEST_NZ(ecx, ecx)) goto loc_003C2D79; /* jne: not equal / not zero */

loc_003C2D6E: ;
    ecx = MEM32(eax + 0x24);
    MEM32(ebx + 0x42C) = ecx;
    goto loc_003C2D7F;

loc_003C2D79: ;
    edx = MEM32(eax + 0x24);
    MEM32(ecx + 0x24) = edx;

loc_003C2D7F: ;
    MEM32(eax + 0x24) = MEM32(eax + 0x24) & 0;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003C2D90; /* jne: not equal / not zero */

loc_003C2D88: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003C2D90: ;
    MEM8(edi + 0x22) = MEM8(edi + 0x22) | 8;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2D9A); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C2D9A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C2DA0
 * Original: 0x003C2DA0 - 0x003C2DD2 (50 bytes, 15 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2DA0(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C2DA0: ;
    eax = ZX8(MEM8(edx + 0x11));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003C2DC5; /* je: equal / zero */

loc_003C2DA9: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003C2DB9; /* je: equal / zero */

loc_003C2DAD: ;
    eax--;
    if ((eax != 0)) goto loc_003C2DD1; /* jne: not equal / not zero */

loc_003C2DB0: ;
    MEM16(edx + 0x24) = MEM16(edx + 0x24) - 1;
    g_seh_ebp = ebp; sub_003C3D65(); return; /* tail jmp 0x003C3D65 */

loc_003C2DB9: ;
    MEM16(0xF4C366) = MEM16(0xF4C366) + 1;
    g_seh_ebp = ebp; sub_003C3DB8(); return; /* tail jmp 0x003C3DB8 */

loc_003C2DC5: ;
    MEM16(0xF4C362) = MEM16(0xF4C362) + 1;
    g_seh_ebp = ebp; sub_003C3E05(); return; /* tail jmp 0x003C3E05 */

loc_003C2DD1: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C2DD2
 * Original: 0x003C2DD2 - 0x003C2EC6 (244 bytes, 87 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2DD2(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C2DD2: ;
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
    if (CMP_NE(eax, 9)) goto loc_003C2E41; /* jne: not equal / not zero */

loc_003C2DF5: ;
    if (CMP_EQ(MEM8(ebx + 0x1D), 0)) goto loc_003C2E41; /* je: equal / zero */

loc_003C2DFB: ;
    eax = MEM32(edx + 4);
    if (TEST_Z(eax, eax)) goto loc_003C2E30; /* je: equal / zero */

loc_003C2E02: ;
    ecx = MEM32(edx + 0xC);
    esi = 0xFFF;
    eax = eax & esi;
    ecx = ecx & esi;
    /* cmp ecx, eax - flags set for next jcc */
    MEM32(ebp + -12) = eax;
    if (CMP_L(ecx, eax)) goto loc_003C2E20; /* jl: less (signed <) */

loc_003C2E15: ;
    eax = ZX8(MEM8(edx + 0x1D));
    eax = eax - ecx;
    eax = eax + MEM32(ebp + -12);
    goto loc_003C2E2D;

loc_003C2E20: ;
    esi = ZX8(MEM8(edx + 0x1D));
    esi = esi - ecx;
    eax = esi + eax + -4096;

loc_003C2E2D: ;
    eax--;
    goto loc_003C2E34;

loc_003C2E30: ;
    eax = ZX8(MEM8(edx + 0x1D));

loc_003C2E34: ;
    MEM32(ebx + 0x14) = MEM32(ebx + 0x14) + eax;
    MEM32(ebx + 4) = MEM32(ebx + 4) & 0;
    MEM8(ebp + -1) = 0;
    goto loc_003C2E5A;

loc_003C2E41: ;
    if (CMP_NE(eax, 0xF)) goto loc_003C2E4D; /* jne: not equal / not zero */

loc_003C2E46: ;
    MEM32(ebx + 4) = 0xC000000Fu;

loc_003C2E4D: ;
    eax = MEM32(edx);
    eax = eax >> 0x1C;
    eax = eax | 0xC0000000u;
    MEM32(ebx + 4) = eax;

loc_003C2E5A: ;
    esi = MEM32(edi + 8);
    esi = esi & 0xFFFFFFF0u;

loc_003C2E60: ;
    SET_LO8(ebx, MEM8(edx + 0x1C));
    PUSH32(esp, edx);
    SET_LO8(ebx, LO8(ebx) & 2);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2E6C); sub_003C26CB(); /* call 0x003C26CB */

loc_003C2E6C: ;
    ecx = MEM32(ebp + -8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2E76); sub_003C2DA0(); /* call 0x003C2DA0 */

loc_003C2E76: ;
    eax = MEM32(0xF4C340);
    edx = eax + esi;
    /* cmp MEM8(edx + 0x1E), 2 - flags set for next jcc */
    esi = MEM32(edx + 8);
    if (CMP_NE(MEM8(edx + 0x1E), 2)) goto loc_003C2E8D; /* jne: not equal / not zero */

loc_003C2E87: ;
    if (CMP_EQ(MEM8(ebp + -1), 0)) goto loc_003C2E91; /* je: equal / zero */

loc_003C2E8D: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003C2E60; } /* je: equal / zero */

loc_003C2E91: ;
    eax = MEM32(edx + 0x10);
    eax = eax ^ MEM32(edi + 8);
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 0x10);
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    MEM32(edi + 8) = eax;
    if (TEST_Z(LO8(ebx), LO8(ebx))) goto loc_003C2EB1; /* je: equal / zero */

loc_003C2EA4: ;
    PUSH32(esp, MEM32(ebp + -16));
    ecx = MEM32(ebp + -8);
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2EB1); sub_003C2D24(); /* call 0x003C2D24 */

loc_003C2EB1: ;
    if (CMP_EQ(MEM8(edi + 0x11), 0)) goto loc_003C2EBD; /* je: equal / zero */

loc_003C2EB7: ;
    if (CMP_NE(MEM8(ebp + -1), 0)) goto loc_003C2EC1; /* jne: not equal / not zero */

loc_003C2EBD: ;
    MEM32(edi + 8) = MEM32(edi + 8) & 0xFFFFFFFEu;

loc_003C2EC1: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C2EC6
 * Original: 0x003C2EC6 - 0x003C2F72 (172 bytes, 64 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2EC6(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C2EC6: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM8(esi + 0x1E), 1 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(esi + 0x1E), 1)); /* latched */
    eax = MEM32(esi + 0x14);
    PUSH32(esp, edi);
    edi = MEM32(esi + 0x18);
    MEM32(ebp + -4) = ecx;
    MEM32(ebp + -8) = eax;
    if (_rcc0) goto loc_003C2EFB; /* jne: not equal / not zero */

loc_003C2EE1: ;
    eax = MEM32(esi + 0xC);
    ecx = MEM32(0xF4C340);
    eax = eax + ecx + -7;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2EF4); sub_003C26CB(); /* call 0x003C26CB */

loc_003C2EF4: ;
    MEM16(0xF4C362) = MEM16(0xF4C362) + 1;

loc_003C2EFB: ;
    if (TEST_Z(MEM8(esi + 3), 0xF0)) goto loc_003C2F0D; /* je: equal / zero */

loc_003C2F01: ;
    ecx = MEM32(ebp + -4);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2F0B); sub_003C2DD2(); /* call 0x003C2DD2 */

loc_003C2F0B: ;
    goto loc_003C2F6E;

loc_003C2F0D: ;
    eax = MEM32(esi + 4);
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, ebx);
    if (TEST_Z(eax, eax)) goto loc_003C2F3B; /* je: equal / zero */

loc_003C2F15: ;
    ecx = MEM32(esi + 0xC);
    edx = 0xFFF;
    eax = eax & edx;
    ebx = eax;
    eax = ZX8(MEM8(esi + 0x1D));
    ecx = ecx & edx;
    eax = eax - ecx;
    if (CMP_L(ecx, ebx)) goto loc_003C2F31; /* jl: less (signed <) */

loc_003C2F2D: ;
    eax = eax + ebx;
    goto loc_003C2F38;

loc_003C2F31: ;
    eax = eax + ebx + -4096;

loc_003C2F38: ;
    eax--;
    goto loc_003C2F3F;

loc_003C2F3B: ;
    eax = ZX8(MEM8(esi + 0x1D));

loc_003C2F3F: ;
    MEM32(edi + 0x14) = MEM32(edi + 0x14) + eax;
    SET_LO8(ebx, MEM8(esi + 0x1C));
    PUSH32(esp, esi);
    SET_LO8(ebx, LO8(ebx) & 2);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2F4E); sub_003C26CB(); /* call 0x003C26CB */

loc_003C2F4E: ;
    edx = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2F59); sub_003C2DA0(); /* call 0x003C2DA0 */

loc_003C2F59: ;
    /* test LO8(ebx), LO8(ebx) - flags set for next jcc */
    _rcc0 = (TEST_Z(LO8(ebx), LO8(ebx))); /* latched */
    POP32(esp, ebx);
    if (_rcc0) goto loc_003C2F6E; /* je: equal / zero */

loc_003C2F5E: ;
    edx = MEM32(ebp + -8);
    ecx = MEM32(ebp + -4);
    MEM32(edi + 4) = MEM32(edi + 4) & 0;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C2F6E); sub_003C2D24(); /* call 0x003C2D24 */

loc_003C2F6E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C2F72
 * Original: 0x003C2F72 - 0x003C3074 (258 bytes, 87 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C2F72(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C2F72: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = edx;
    ebx = ecx;
    edx = 0; /* xor self */
    /* cmp MEM32(ebx + 0x42C), edx - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(ebx + 0x42C), edx)); /* latched */
    MEM32(ebp + -20) = edi;
    MEM32(ebp + -8) = ebx;
    MEM32(ebp + -4) = edx;
    if (_rcc0) goto loc_003C3063; /* je: equal / zero */

loc_003C2F95: ;
    PUSH32(esp, esi);
    goto loc_003C2F9B;

loc_003C2F98: ;
    edi = MEM32(ebp + -20);

loc_003C2F9B: ;
    ecx = MEM32(ebx + 0x42C);
    eax = MEM32(ecx + 0x24);
    MEM32(ebx + 0x42C) = eax;
    esi = MEM32(ecx + 0x10);
    if (CMP_AE(edi, MEM32(esi + 0x1C))) goto loc_003C2FBD; /* jae: above or equal (unsigned >=) */

loc_003C2FB2: ;
    MEM32(ecx + 0x24) = edx;
    MEM32(ebp + -4) = ecx;
    goto loc_003C3052;

loc_003C2FBD: ;
    SET_LO8(eax, MEM8(esi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003C2FCF; /* je: equal / zero */

loc_003C2FC4: ;
    edi++;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM32(esi + 0x1C) = edi;
    MEM8(esi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003C2FB2; }

loc_003C2FCF: ;
    eax = MEM32(esi + 8);
    edi = MEM32(0xF4C340);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM32(ebp + -24) = eax;
    eax = eax & 0xFFFFFFF0u;
    edx = edi + eax;
    /* cmp ecx, MEM32(edx + 0x18) - flags set for next jcc */
    _rcc0 = (CMP_EQ(ecx, MEM32(edx + 0x18))); /* latched */
    MEM32(ebp + -16) = eax;
    if (_rcc0) goto loc_003C3005; /* je: equal / zero */

loc_003C2FED: ;
    ebx = MEM32(esi + 4);

loc_003C2FF0: ;
    if (CMP_EQ(eax, ebx)) goto loc_003C3002; /* je: equal / zero */

loc_003C2FF4: ;
    MEM32(ebp + -12) = eax;
    eax = MEM32(edx + 8);
    edx = edi + eax;
    if (CMP_NE(ecx, MEM32(edx + 0x18))) { RECOMP_SLICE_POINT(); goto loc_003C2FF0; } /* jne: not equal / not zero */

loc_003C3002: ;
    ebx = MEM32(ebp + -8);

loc_003C3005: ;
    eax = MEM32(edx + 8);
    eax = eax ^ MEM32(ebp + -24);
    ecx = ebx;
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 8);
    MEM32(esi + 8) = eax;
    MEM8(edx + 3) = MEM8(edx + 3) | 0xF0;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C301F); sub_003C2EC6(); /* call 0x003C2EC6 */

loc_003C301F: ;
    eax = MEM32(ebp + -12);
    if (TEST_Z(eax, eax)) goto loc_003C3045; /* je: equal / zero */

loc_003C3026: ;
    ecx = MEM32(esi + 8);
    edx = MEM32(0xF4C340);
    ecx = ecx & 0xFFFFFFF0u;
    MEM32(edx + eax + 8) = ecx;
    eax = MEM32(esi + 8);
    eax = eax ^ MEM32(ebp + -16);
    eax = eax & 0xF;
    eax = eax ^ MEM32(ebp + -16);
    MEM32(esi + 8) = eax;

loc_003C3045: ;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003C3052; /* jne: not equal / not zero */

loc_003C304A: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003C3052: ;
    /* cmp MEM32(ebx + 0x42C), 0 - flags set for next jcc */
    edx = MEM32(ebp + -4);
    if (CMP_NE(MEM32(ebx + 0x42C), 0)) { RECOMP_SLICE_POINT(); goto loc_003C2F98; } /* jne: not equal / not zero */

loc_003C3062: ;
    POP32(esp, esi);

loc_003C3063: ;
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
 * sub_003C3074
 * Original: 0x003C3074 - 0x003C30CA (86 bytes, 35 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3074(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3074: ;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = edx;
    edi = ecx;
    SET_LO8(ebx, 0); /* xor self */

loc_003C307D: ;
    eax = MEM32(esi + 8);
    ecx = eax;
    ecx = ecx & 0xFFFFFFF0u;
    if ((ecx == 0)) goto loc_003C30C6; /* je: equal / zero */

loc_003C3087: ;
    edx = MEM32(0xF4C340);
    edx = edx + ecx;
    if (CMP_EQ(ecx, MEM32(esi + 4))) goto loc_003C30B0; /* je: equal / zero */

loc_003C3094: ;
    eax = MEM32(edx + 8);
    MEM8(edx + 3) = MEM8(edx + 3) | 0xF0;
    eax = eax ^ MEM32(esi + 8);
    ecx = edi;
    eax = eax & 0xF;
    eax = eax ^ MEM32(edx + 8);
    MEM32(esi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C30AE); sub_003C2EC6(); /* call 0x003C2EC6 */

loc_003C30AE: ;
    goto loc_003C30C2;

loc_003C30B0: ;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    eax = eax & 0xF;
    PUSH32(esp, edx);
    MEM32(esi + 8) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C30C0); sub_003C26CB(); /* call 0x003C26CB */

loc_003C30C0: ;
    SET_LO8(ebx, 1);

loc_003C30C2: ;
    if (TEST_Z(LO8(ebx), LO8(ebx))) { RECOMP_SLICE_POINT(); goto loc_003C307D; } /* je: equal / zero */

loc_003C30C6: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C30CA
 * Original: 0x003C30CA - 0x003C3151 (135 bytes, 50 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C30CA(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C30CA: ;
    PUSH32(esp, ecx);
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    ebx = ecx;
    ebp = 0; /* xor self */
    /* cmp MEM32(ebx + 0x430), ebp - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(ebx + 0x430), ebp)); /* latched */
    MEM32(esp + 8) = edx;
    if (_rcc0) goto loc_003C3140; /* je: equal / zero */

loc_003C30DD: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003C30DF: ;
    edi = MEM32(ebx + 0x430);
    eax = MEM32(edi + 0x24);
    MEM32(ebx + 0x430) = eax;
    esi = MEM32(edi + 0x10);
    if (CMP_AE(edx, MEM32(esi + 0x1C))) goto loc_003C30FD; /* jae: above or equal (unsigned >=) */

loc_003C30F6: ;
    MEM32(edi + 0x14) = ebp;
    ebp = edi;
    goto loc_003C3135;

loc_003C30FD: ;
    SET_LO8(eax, MEM8(esi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003C3111; /* je: equal / zero */

loc_003C3104: ;
    ecx = edx + 1;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM32(esi + 0x1C) = ecx;
    MEM8(esi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003C30F6; }

loc_003C3111: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C311A); sub_003C3074(); /* call 0x003C3074 */

loc_003C311A: ;
    MEM8(esi + 0x20) = MEM8(esi + 0x20) - 1;
    if ((MEM8(esi + 0x20) != 0)) goto loc_003C3127; /* jne: not equal / not zero */

loc_003C311F: ;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) & 0xDF;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;

loc_003C3127: ;
    MEM32(edi + 4) = MEM32(edi + 4) & 0;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3131); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C3131: ;
    edx = MEM32(esp + 0x10);

loc_003C3135: ;
    if (CMP_NE(MEM32(ebx + 0x430), 0)) { RECOMP_SLICE_POINT(); goto loc_003C30DF; } /* jne: not equal / not zero */

loc_003C313E: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003C3140: ;
    eax = 0; /* xor self */
    MEM32(ebx + 0x430) = ebp;
    /* test ebp, ebp - flags set for next jcc */
    _rcc0 = (TEST_NZ(ebp, ebp)); /* latched */
    POP32(esp, ebp);
    SET_LO8(eax, (_rcc0) ? 1 : 0); /* setne */
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C3151
 * Original: 0x003C3151 - 0x003C322B (218 bytes, 75 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3151(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3151: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0xC;
    PUSH32(esp, ebx);
    ebx = ecx;
    ecx = 0; /* xor self */
    /* cmp MEM32(ebx + 0x434), ecx - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(ebx + 0x434), ecx)); /* latched */
    MEM32(ebp + -8) = edx;
    MEM32(ebp + -4) = ecx;
    if (_rcc0) goto loc_003C321B; /* je: equal / zero */

loc_003C316E: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003C3170: ;
    esi = MEM32(ebx + 0x434);
    eax = MEM32(esi + 0x14);
    MEM32(ebx + 0x434) = eax;
    edi = MEM32(esi + 0x10);
    eax = MEM32(ebp + -8);
    if (CMP_AE(eax, MEM32(edi + 0x1C))) goto loc_003C3192; /* jae: above or equal (unsigned >=) */

loc_003C318A: ;
    MEM32(esi + 0x14) = ecx;
    MEM32(ebp + -4) = esi;
    goto loc_003C3209;

loc_003C3192: ;
    SET_LO8(eax, MEM8(edi + 0x10));
    if (TEST_Z(LO8(eax), 0x40)) goto loc_003C31A0; /* je: equal / zero */

loc_003C3199: ;
    SET_LO8(eax, LO8(eax) & 0xBF);
    MEM8(edi + 0x10) = LO8(eax);
    { RECOMP_SLICE_POINT(); goto loc_003C318A; }

loc_003C31A0: ;
    /* cmp MEM8(esi + 1), 0x4A - flags set for next jcc */
    ecx = ebx;
    if (CMP_NE(MEM8(esi + 1), 0x4A)) goto loc_003C31B1; /* jne: not equal / not zero */

loc_003C31A8: ;
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C31AF); sub_003C3544(); /* call 0x003C3544 */

loc_003C31AF: ;
    goto loc_003C3209;

loc_003C31B1: ;
    edx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C31B8); sub_003C3074(); /* call 0x003C3074 */

loc_003C31B8: ;
    edx = MEM32(esi + 0x18);
    if (TEST_Z(edx, edx)) goto loc_003C31F1; /* je: equal / zero */

loc_003C31BF: ;
    ecx = MEM32(edi);
    MEM32(ebp + -12) = ecx;
    ecx = ecx >> 7;
    eax = 0; /* xor self */
    ecx = ecx & 0xF;
    eax++;
    eax = eax << LO8(ecx);
    ecx = MEM32(ebp + -12);
    ecx = ecx & 0x1800;
    if (CMP_NE(ecx, 0x1000)) goto loc_003C31E3; /* jne: not equal / not zero */

loc_003C31E0: ;
    eax = eax << 0x10;

loc_003C31E3: ;
    if (TEST_Z(MEM8(edi + 8), 2)) goto loc_003C31ED; /* je: equal / zero */

loc_003C31E9: ;
    MEM32(edx) = MEM32(edx) | eax;
    goto loc_003C31F1;

loc_003C31ED: ;
    eax = ~eax;
    MEM32(edx) = MEM32(edx) & eax;

loc_003C31F1: ;
    eax = MEM32(0xF4C348);
    MEM32(edi + 0x18) = eax;
    MEM32(0xF4C348) = edi;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3209); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C3209: ;
    /* cmp MEM32(ebx + 0x434), 0 - flags set for next jcc */
    ecx = MEM32(ebp + -4);
    if (CMP_NE(MEM32(ebx + 0x434), 0)) { RECOMP_SLICE_POINT(); goto loc_003C3170; } /* jne: not equal / not zero */

loc_003C3219: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003C321B: ;
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
 * sub_003C322B
 * Original: 0x003C322B - 0x003C3341 (278 bytes, 96 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C322B(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C322B: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3252); sub_003C2C11(); /* call 0x003C2C11 */

loc_003C3252: ;
    if (TEST_Z(MEM8(ebp + -4), 2)) goto loc_003C32AF; /* je: equal / zero */

loc_003C3258: ;
    ecx = MEM32(esi + 8);
    ecx = ecx + 0x84;
    eax = MEM32(ecx);
    eax = eax & 0xFFFFFFF0u;
    MEM32(ecx) = edi;
    if ((eax == 0)) goto loc_003C329B; /* je: equal / zero */

loc_003C326A: ;
    ecx = MEM32(0xF4C340);
    ecx = ecx + eax;
    eax = MEM32(ecx + 8);
    /* test eax, eax - flags set for next jcc */
    MEM32(ecx + 8) = edi;
    edi = ecx;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C326A; } /* jne: not equal / not zero */

loc_003C327E: ;
    edx = edi;
    /* test MEM8(edx + 2), 1 - flags set for next jcc */
    edi = MEM32(edi + 8);
    ecx = esi;
    if (TEST_Z(MEM8(edx + 2), 1)) goto loc_003C3292; /* je: equal / zero */

loc_003C328B: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3290); sub_003C38AD(); /* call 0x003C38AD */

loc_003C3290: ;
    goto loc_003C3297;

loc_003C3292: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3297); sub_003C2EC6(); /* call 0x003C2EC6 */

loc_003C3297: ;
    if (TEST_NZ(edi, edi)) { RECOMP_SLICE_POINT(); goto loc_003C327E; } /* jne: not equal / not zero */

loc_003C329B: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFFDu;
    MEM32(ebx + 0xC) = 2;
    eax = MEM32(esi);
    MEM32(eax + 8) = 6;

loc_003C32AF: ;
    /* test MEM8(ebp + -4), 4 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(ebp + -4), 4)); /* latched */
    PUSH32(esp, 4);
    POP32(esp, edi);
    if (_rcc0) goto loc_003C32C2; /* je: equal / zero */

loc_003C32B8: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFFBu;
    MEM32(ebx + 0xC) = edi;
    MEM32(ebx + 0x14) = edi;

loc_003C32C2: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C32C9); sub_003C2BED(); /* call 0x003C2BED */

loc_003C32C9: ;
    edx = eax;
    ecx = esi;
    MEM32(ebp + -8) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C32D5); sub_003C2F72(); /* call 0x003C2F72 */

loc_003C32D5: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C32DD; /* je: equal / zero */

loc_003C32D9: ;
    MEM8(ebp + 0xF) = 1;

loc_003C32DD: ;
    edx = MEM32(ebp + -8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C32E7); sub_003C30CA(); /* call 0x003C30CA */

loc_003C32E7: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C32EF; /* je: equal / zero */

loc_003C32EB: ;
    MEM8(ebp + 0xF) = 1;

loc_003C32EF: ;
    edx = MEM32(ebp + -8);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C32F9); sub_003C3151(); /* call 0x003C3151 */

loc_003C32F9: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C3301; /* je: equal / zero */

loc_003C32FD: ;
    MEM8(ebp + 0xF) = 1;

loc_003C3301: ;
    if (CMP_EQ(MEM8(ebp + 0xF), 0)) goto loc_003C3311; /* je: equal / zero */

loc_003C3307: ;
    eax = MEM32(esi);
    MEM32(eax + 0xC) = edi;
    eax = MEM32(esi);
    MEM32(eax + 0x10) = edi;

loc_003C3311: ;
    if (TEST_Z(MEM8(ebp + -4), 0x40)) goto loc_003C3329; /* je: equal / zero */

loc_003C3317: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C331E); sub_003C201E(); /* call 0x003C201E */

loc_003C331E: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0xFFFFFFBFu;
    MEM32(ebx + 0xC) = 0x40;

loc_003C3329: ;
    eax = MEM32(ebp + -4);
    if (TEST_Z(eax, eax)) goto loc_003C3333; /* je: equal / zero */

loc_003C3330: ;
    MEM32(ebx + 0xC) = eax;

loc_003C3333: ;
    POP32(esp, edi);
    POP32(esp, esi);
    MEM32(ebx + 0x10) = 0x80000000u;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 20; return; /* ret 16 */

}

/**
 * sub_003C3341
 * Original: 0x003C3341 - 0x003C3353 (18 bytes, 6 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3341(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C3341: ;
    eax = MEM32(0xF4C368);
    if (TEST_Z(eax, eax)) goto loc_003C3352; /* je: equal / zero */

loc_003C334A: ;
    ecx = MEM32(eax);
    MEM32(0xF4C368) = ecx;

loc_003C3352: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C3353
 * Original: 0x003C3353 - 0x003C3500 (429 bytes, 148 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3353(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3353: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x14;
    eax = MEM32(0xF4C36C);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    ebx = edx;
    MEM32(ebp + -20) = ecx;
    MEM32(ebp + -8) = eax;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C336E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C336E: ;
    MEM8(ebp + -2) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3376); sub_003C3341(); /* call 0x003C3341 */

loc_003C3376: ;
    edi = eax;
    /* test edi, edi - flags set for next jcc */
    MEM32(ebp + -12) = edi;
    if (TEST_NZ(edi, edi)) goto loc_003C3389; /* jne: not equal / not zero */

loc_003C337F: ;
    edi = 0x80000100u;
    goto loc_003C34EE;

loc_003C3389: ;
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
    eax = eax - MEM32(0xF4C340);
    MEM8(esi + 0x11) = 1;
    MEM32(esi + 0x14) = eax;
    eax = 0; /* xor self */
    MEM8(esi + 0x13) = 1;
    SET_LO16(eax, MEM16(ebx + 0x16));
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C33CE); sub_003BE9FB(); /* call 0x003BE9FB */

loc_003C33CE: ;
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
    eax = eax - MEM32(0xF4C340);
    ecx = ecx ^ eax;
    ecx = ecx & 0xF;
    ecx = ecx ^ eax;
    MEM32(esi + 8) = ecx;
    SET_LO8(ecx, 0); /* xor self */
    /* test edx, edx - flags set for next jcc */
    MEM32(esi + 4) = eax;
    MEM8(ebp + -1) = LO8(ecx);
    if (CMP_BE(edx & edx, 0)) goto loc_003C34AE; /* jbe: below or equal (unsigned <=) */

loc_003C3451: ;
    eax = 0; /* xor self */

loc_003C3453: ;
    edx = MEM32(esi + 0x2C);
    eax = eax << 6;
    edi = eax + edx;
    MEM32(ebp + -16) = edi;
    edi = edi - MEM32(0xF4C340);
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
    _rcc0 = (CMP_B(eax, MEM32(ebp + -8))); /* latched */
    MEM8(ebp + -1) = LO8(ecx);
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003C3453; } /* jb: below (unsigned <) */

loc_003C34AE: ;
    edx = MEM32(esi + 0x2C);
    eax = ZX8(LO8(ecx));
    eax = eax << 6;
    MEM32(eax + edx + -56) = MEM32(eax + edx + -56) & 0;
    eax = MEM32(esi + 0x2C);
    SET_LO8(ecx, LO8(ecx) - 1);
    MEM8(eax + 0x2D) = LO8(ecx);
    ecx = MEM32(ebp + -20);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C34CE); sub_003C2802(); /* call 0x003C2802 */

loc_003C34CE: ;
    edi = eax;
    if (TEST_S(edi, edi)) goto loc_003C34D9; /* jl: less (signed <) */

loc_003C34D4: ;
    MEM32(ebx + 0x10) = esi;
    goto loc_003C34ED;

loc_003C34D9: ;
    MEM32(ebx + 0x10) = MEM32(ebx + 0x10) & 0;
    ecx = MEM32(0xF4C368);
    eax = MEM32(ebp + -12);
    MEM32(eax) = ecx;
    MEM32(0xF4C368) = eax;

loc_003C34ED: ;
    POP32(esp, esi);

loc_003C34EE: ;
    SET_LO8(ecx, MEM8(ebp + -2));
    MEM32(ebx + 4) = edi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C34FA); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C34FA: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C3500
 * Original: 0x003C3500 - 0x003C3544 (68 bytes, 27 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3500(void)
{
    uint32_t ebp;
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3500: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, ebp);
    PUSH32(esp, esi);
    esi = edx;
    ebp = MEM32(esi + 0x10);
    PUSH32(esp, edi);
    edi = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C3511); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3511: ;
    edx = ebp;
    ecx = edi;
    SET_LO8(ebx, LO8(eax));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C351C); sub_003C29DE(); /* call 0x003C29DE */

loc_003C351C: ;
    edx = ebp;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3525); sub_003C23CA(); /* call 0x003C23CA */

loc_003C3525: ;
    eax = edi + 0x434;
    ecx = MEM32(eax);
    MEM32(esi + 0x14) = ecx;
    SET_LO8(ecx, LO8(ebx));
    MEM32(eax) = esi;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C353A); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C353A: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebp);
    eax = 0x40000000;
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C3544
 * Original: 0x003C3544 - 0x003C35CD (137 bytes, 52 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3544(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3544: ;
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
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C35A6; /* je: equal / zero */

loc_003C3562: ;
    PUSH32(esp, edi);

loc_003C3563: ;
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
    { uint32_t _icall_t = MEM32(0x3C5068); g_seh_ebp = ebp; PUSH32(esp, 0x3C3586); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3586: ;
    eax = MEM32(edi + 0xC);
    ecx = MEM32(edi + 4);
    ecx = ecx ^ eax;
    if (TEST_Z(ecx, 0xFFFFF000u)) goto loc_003C359F; /* je: equal / zero */

loc_003C3596: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C5068); g_seh_ebp = ebp; PUSH32(esp, 0x3C359F); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C359F: ;
    if (CMP_NE(MEM8(esi + 0x25), 0)) { RECOMP_SLICE_POINT(); goto loc_003C3563; } /* jne: not equal / not zero */

loc_003C35A5: ;
    POP32(esp, edi);

loc_003C35A6: ;
    eax = ZX8(MEM8(esi + 0x24));
    MEM8(esi + 0x25) = MEM8(esi + 0x25) - 1;
    eax = eax << 6;
    esi = esi - eax;
    eax = MEM32(0xF4C368);
    MEM32(esi) = eax;
    MEM32(0xF4C368) = esi;
    MEM32(ebp + 4) = MEM32(ebp + 4) & 0;
    PUSH32(esp, ebp);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C35C9); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C35C9: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C35CD
 * Original: 0x003C35CD - 0x003C3734 (359 bytes, 130 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C35CD(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C35CD: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C35ED); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C35ED: ;
    SET_LO8(ecx, MEM8(edi + 0x24));
    /* cmp LO8(ecx), MEM8(edi + 0x25) - flags set for next jcc */
    _rcc0 = (CMP_NE(LO8(ecx), MEM8(edi + 0x25))); /* latched */
    MEM8(ebp + -1) = LO8(eax);
    if (_rcc0) goto loc_003C3604; /* jne: not equal / not zero */

loc_003C35F8: ;
    MEM32(ebp + -20) = 0xC0000D00u;
    goto loc_003C3719;

loc_003C3604: ;
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
    _rcc0 = (CMP_BE(MEM32(esi), 0)); /* latched */
    MEM32(ebp + -24) = eax;
    if (_rcc0) goto loc_003C3696; /* jbe: below or equal (unsigned <=) */

loc_003C366B: ;
    ecx = esi + 8;
    MEM32(ebp + -8) = ecx;
    ecx = ebx + 0x10;

loc_003C3674: ;
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
    if (CMP_B(edx, MEM32(esi))) { RECOMP_SLICE_POINT(); goto loc_003C3674; } /* jb: below (unsigned <) */

loc_003C3696: ;
    eax = eax - MEM32(ebp + -24);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(esi + 4));
    MEM32(ebp + -24) = eax;
    { uint32_t _icall_t = MEM32(0x3C5060); g_seh_ebp = ebp; PUSH32(esp, 0x3C36A8); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C36A8: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(esi + 4));
    { uint32_t _icall_t = MEM32(0x3C505C); g_seh_ebp = ebp; PUSH32(esp, 0x3C36B1); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C36B1: ;
    ecx = MEM32(ebp + -24);
    MEM32(ebx + 4) = eax;
    eax = MEM32(esi + 4);
    eax = eax + ecx + -1;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C505C); g_seh_ebp = ebp; PUSH32(esp, 0x3C36C5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C36C5: ;
    MEM32(ebx + 0xC) = eax;
    if (TEST_Z(MEM8(edi + 0x10), 1)) goto loc_003C36DE; /* je: equal / zero */

loc_003C36CE: ;
    esi = ebx + 0x10;
    edi = ebx + 0x30;
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    MEM32(edi) = MEM32(esi); esi += 4; edi += 4; /* movsd */
    esi = MEM32(ebp + -28);
    edi = MEM32(ebp + -32);

loc_003C36DE: ;
    if (TEST_Z(MEM8(edi + 0x10), 2)) goto loc_003C3704; /* je: equal / zero */

loc_003C36E4: ;
    ecx = MEM32(ebp + -36);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C36EC); sub_003C2BED(); /* call 0x003C2BED */

loc_003C36EC: ;
    ecx = MEM32(edi + 0x28);
    eax++;
    edx = ecx;
    edx = edx - eax;
    if (CMP_LE(edx & edx, 0)) goto loc_003C36FA; /* jle: less or equal (signed <=) */

loc_003C36F8: ;
    eax = ecx;

loc_003C36FA: ;
    MEM16(ebx) = LO16(eax);
    ecx = MEM32(esi);
    ecx = ecx + eax;
    MEM32(edi + 0x28) = ecx;

loc_003C3704: ;
    MEM8(edi + 0x25) = MEM8(edi + 0x25) + 1;
    SET_LO8(eax, MEM8(edi + 0x25));
    /* cmp LO8(eax), MEM8(edi + 0x24) - flags set for next jcc */
    esi = MEM32(ebp + -16);
    if (CMP_EQ(LO8(eax), MEM8(edi + 0x24))) goto loc_003C3718; /* je: equal / zero */

loc_003C3712: ;
    eax = MEM32(ebx + 8);
    MEM32(edi + 4) = eax;

loc_003C3718: ;
    POP32(esp, ebx);

loc_003C3719: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C3722); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3722: ;
    edi = MEM32(ebp + -20);
    PUSH32(esp, esi);
    MEM32(esi + 4) = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C372E); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C372E: ;
    eax = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C3734
 * Original: 0x003C3734 - 0x003C3853 (287 bytes, 98 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3734(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3734: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    MEM32(ebp + -16) = MEM32(ebp + -16) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(0x3C4FC8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = edx;
    esi = MEM32(edi + 0x10);
    MEM32(ebp + -12) = edi;
    MEM32(ebp + -8) = ecx;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0x3C3754); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3754: ;
    /* test MEM8(esi + 0x10), 2 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0x10), 2)); /* latched */
    MEM8(ebp + -1) = LO8(eax);
    if (_rcc0) goto loc_003C3767; /* je: equal / zero */

loc_003C375D: ;
    esi = 0xC0000E00u;
    goto loc_003C3833;

loc_003C3767: ;
    ecx = MEM32(ebp + -8);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C376F); sub_003C2BED(); /* call 0x003C2BED */

loc_003C376F: ;
    SET_LO8(edx, MEM8(esi + 0x10));
    if (TEST_Z(LO8(edx), 4)) goto loc_003C37B1; /* je: equal / zero */

loc_003C3777: ;
    SET_LO8(edx, LO8(edx) & 0xFB);
    /* cmp MEM32(esi + 0x1C), eax - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM32(esi + 0x1C), eax)); /* latched */
    MEM8(esi + 0x10) = LO8(edx);
    if (_rcc0) goto loc_003C37A9; /* jne: not equal / not zero */

loc_003C3782: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C378B); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C378B: ;
    MEM32(ebp + -20) = MEM32(ebp + -20) | 0xFFFFFFFFu;
    eax = ebp + -24;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, eax);
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    MEM32(ebp + -24) = 0xFFFFD8F0u;
    { uint32_t _icall_t = MEM32(0x3C4FB4); g_seh_ebp = ebp; PUSH32(esp, 0x3C37A4); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C37A4: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = ebx; g_seh_ebp = ebp; PUSH32(esp, 0x3C37A6); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C37A6: ;
    MEM8(ebp + -1) = LO8(eax);

loc_003C37A9: ;
    ecx = MEM32(ebp + -8);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C37B1); sub_003C2BED(); /* call 0x003C2BED */

loc_003C37B1: ;
    if (TEST_Z(MEM8(esi + 0x10), 1)) goto loc_003C37C6; /* je: equal / zero */

loc_003C37B7: ;
    SET_LO8(ecx, MEM8(esi + 0x24));
    if (CMP_EQ(LO8(ecx), MEM8(esi + 0x25))) goto loc_003C37C6; /* je: equal / zero */

loc_003C37BF: ;
    esi = 0xC0001000u;
    goto loc_003C3833;

loc_003C37C6: ;
    /* test MEM8(edi + 0x18), 1 - flags set for next jcc */
    ecx = eax + 1;
    if (TEST_NZ(MEM8(edi + 0x18), 1)) goto loc_003C37E1; /* jne: not equal / not zero */

loc_003C37CF: ;
    edx = MEM32(edi + 0x14);
    eax = edx;
    eax = eax - ecx;
    if (((int32_t)eax < 0)) goto loc_003C384C; /* js: sign (negative) */

loc_003C37D8: ;
    if (CMP_G(eax, 0x400)) goto loc_003C384C; /* jg: greater (signed >) */

loc_003C37DF: ;
    ecx = edx;

loc_003C37E1: ;
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

loc_003C37F8: ;
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
    if (CMP_NE(LO8(edx), MEM8(esi + 0x26))) { RECOMP_SLICE_POINT(); goto loc_003C37F8; } /* jne: not equal / not zero */

loc_003C3822: ;
    MEM8(esi + 1) = MEM8(esi + 1) & 0xBF;
    MEM8(esi + 0x10) = MEM8(esi + 0x10) | 2;
    edi = MEM32(ebp + -12);
    MEM32(esi + 0x28) = ecx;
    esi = MEM32(ebp + -16);

loc_003C3833: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C383C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C383C: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3845); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C3845: ;
    POP32(esp, edi);
    eax = esi;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

loc_003C384C: ;
    esi = 0xC0000B00u;
    { RECOMP_SLICE_POINT(); goto loc_003C3833; }

}

/**
 * sub_003C3853
 * Original: 0x003C3853 - 0x003C38AD (90 bytes, 37 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3853(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3853: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C3867); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3867: ;
    /* test MEM8(esi + 0x10), 2 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0x10), 2)); /* latched */
    MEM8(esp + 0x13) = LO8(eax);
    if (_rcc0) goto loc_003C388D; /* je: equal / zero */

loc_003C3871: ;
    MEM8(esi + 1) = MEM8(esi + 1) | 0x40;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C387C); sub_003C2BED(); /* call 0x003C2BED */

loc_003C387C: ;
    eax++;
    eax++;
    MEM32(esi + 0x1C) = eax;
    SET_LO8(eax, MEM8(esi + 0x10));
    SET_LO8(eax, LO8(eax) & 0xFD);
    SET_LO8(eax, LO8(eax) | 4);
    MEM8(esi + 0x10) = LO8(eax);
    goto loc_003C3892;

loc_003C388D: ;
    ebp = 0xC0000F00u;

loc_003C3892: ;
    SET_LO8(ecx, MEM8(esp + 0x13));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C389C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C389C: ;
    PUSH32(esp, edi);
    MEM32(edi + 4) = ebp;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C38A5); sub_003BE9E7(); /* call 0x003BE9E7 */

loc_003C38A5: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebp;
    POP32(esp, ebp);
    POP32(esp, ebx);
    POP32(esp, ecx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C38AD
 * Original: 0x003C38AD - 0x003C399D (240 bytes, 97 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C38AD(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C38AD: ;
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
    esi = esi - MEM32(0xF4C340);
    eax = eax << 6;
    MEM32(eax + edi + 8) = esi;
    /* test MEM8(edx + 0x10), 1 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(edx + 0x10), 1)); /* latched */
    MEM32(ebp + -4) = edx;
    MEM32(ebp + -12) = esi;
    if (_rcc0) goto loc_003C3954; /* je: equal / zero */

loc_003C390E: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3913); sub_003C2BED(); /* call 0x003C2BED */

loc_003C3913: ;
    ecx = MEM32(ebp + -4);
    esi = eax;
    eax = MEM32(ecx + 0x28);
    esi++;
    edx = eax;
    edx = edx - esi;
    if (((int32_t)edx < 0)) goto loc_003C3924; /* js: sign (negative) */

loc_003C3922: ;
    esi = eax;

loc_003C3924: ;
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
    goto loc_003C398B;

loc_003C3954: ;
    edi = MEM32(0x3C5068);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, MEM32(ebx + 4));
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0x3C3961); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3961: ;
    eax = MEM32(ebx + 0xC);
    ecx = MEM32(ebx + 4);
    ecx = ecx ^ eax;
    if (TEST_Z(ecx, 0xFFFFF000u)) goto loc_003C3976; /* je: equal / zero */

loc_003C3971: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 1);
    PUSH32(esp, eax);
    { uint32_t _icall_t = edi; g_seh_ebp = ebp; PUSH32(esp, 0x3C3976); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3976: ;
    ecx = MEM32(ebp + -4);
    SET_LO8(eax, MEM8(ecx + 0x25));
    /* cmp LO8(eax), MEM8(ecx + 0x24) - flags set for next jcc */
    SET_LO8(edx, (CMP_EQ(LO8(eax), MEM8(ecx + 0x24))) ? 1 : 0); /* sete */
    SET_LO8(eax, LO8(eax) - 1);
    /* test LO8(edx), LO8(edx) - flags set for next jcc */
    MEM8(ecx + 0x25) = LO8(eax);
    if (TEST_Z(LO8(edx), LO8(edx))) goto loc_003C398E; /* je: equal / zero */

loc_003C398B: ;
    MEM32(ecx + 4) = esi;

loc_003C398E: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -16));
    eax = ebp + -44;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(ebp + -20); g_seh_ebp = ebp; PUSH32(esp, 0x3C3998); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3998: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C399D
 * Original: 0x003C399D - 0x003C39BD (32 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C399D(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C399D: ;
    eax = MEM32(0xF4C34C);
    if (TEST_Z(eax, eax)) goto loc_003C39AF; /* je: equal / zero */

loc_003C39A6: ;
    ecx = MEM32(eax + 0x14);
    MEM32(0xF4C34C) = ecx;

loc_003C39AF: ;
    SET_LO8(ecx, MEM8(esp + 4));
    MEM8(eax + 2) = MEM8(eax + 2) & 0xFE;
    MEM8(eax + 0x1F) = LO8(ecx);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C39BD
 * Original: 0x003C39BD - 0x003C39DC (31 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C39BD(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C39BD: ;
    SET_LO16(eax, MEM16(esp + 4));
    if (CMP_AE(MEM16(0xF4C362), LO16(eax))) goto loc_003C39CF; /* jae: above or equal (unsigned >=) */

loc_003C39CB: ;
    eax = 0; /* xor self */
    goto loc_003C39D9;

loc_003C39CF: ;
    MEM16(0xF4C362) = MEM16(0xF4C362) - LO16(eax);
    eax = 0; /* xor self */
    eax++;

loc_003C39D9: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C39DC
 * Original: 0x003C39DC - 0x003C39FB (31 bytes, 9 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C39DC(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C39DC: ;
    SET_LO16(eax, MEM16(esp + 4));
    if (CMP_AE(MEM16(0xF4C366), LO16(eax))) goto loc_003C39EE; /* jae: above or equal (unsigned >=) */

loc_003C39EA: ;
    eax = 0; /* xor self */
    goto loc_003C39F8;

loc_003C39EE: ;
    MEM16(0xF4C366) = MEM16(0xF4C366) - LO16(eax);
    eax = 0; /* xor self */
    eax++;

loc_003C39F8: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C39FB
 * Original: 0x003C39FB - 0x003C3A2D (50 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C39FB(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    int _flags = 0; /* fallback flag var */

loc_003C39FB: ;
    PUSH32(esp, edi);
    edi = edx;
    edx = 0; /* xor self */
    SET_LO16(edx, MEM16(edi + 2));
    eax = 0; /* xor self */
    edx = edx & 0x7FF;
    if (CMP_EQ(MEM32(ecx + 0x14), eax)) goto loc_003C3A22; /* je: equal / zero */

loc_003C3A11: ;
    eax = MEM32(ecx + 0x14);
    PUSH32(esp, esi);
    esi = ZX16(LO16(edx));
    edx = 0; /* xor self */
    { uint64_t _dividend = ((uint64_t)edx << 32) | eax;
      eax = (uint32_t)(_dividend / (uint32_t)esi);
      edx = (uint32_t)(_dividend % (uint32_t)esi); }
    POP32(esp, esi);
    if (TEST_Z(edx, edx)) goto loc_003C3A22; /* je: equal / zero */

loc_003C3A21: ;
    eax++;

loc_003C3A22: ;
    /* cmp MEM8(edi + 0x11), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(edi + 0x11), 0)); /* latched */
    POP32(esp, edi);
    if (_rcc0) goto loc_003C3A2C; /* jne: not equal / not zero */

loc_003C3A29: ;
    eax = eax + 3;

loc_003C3A2C: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C3A2D
 * Original: 0x003C3A2D - 0x003C3A67 (58 bytes, 25 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3A2D(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3A2D: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    PUSH32(esp, MEM32(esi));
    edi = edx;
    { uint32_t _icall_t = MEM32(0x3C505C); g_seh_ebp = ebp; PUSH32(esp, 0x3C3A3C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3A3C: ;
    ecx = MEM32(esi);
    ecx = ecx & 0xFFF;
    edx = 0x1000;
    edx = edx - ecx;
    ecx = MEM32(esp + 0x10);
    MEM32(ecx) = edx;
    ebx = MEM32(edi);
    if (CMP_BE(edx, ebx)) goto loc_003C3A59; /* jbe: below or equal (unsigned <=) */

loc_003C3A57: ;
    MEM32(ecx) = ebx;

loc_003C3A59: ;
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
 * sub_003C3A67
 * Original: 0x003C3A67 - 0x003C3D65 (766 bytes, 247 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3A67(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3A67: ;
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
    if (CMP_EQ(esi, eax)) goto loc_003C3ACD; /* je: equal / zero */

loc_003C3AC4: ;
    eax = MEM32(0xF4C340);
    esi = esi + eax;
    goto loc_003C3AE6;

loc_003C3ACD: ;
    PUSH32(esp, MEM32(ebp + -24));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3AD5); sub_003C399D(); /* call 0x003C399D */

loc_003C3AD5: ;
    esi = eax;
    eax = MEM32(esi + 0x10);
    eax = eax ^ MEM32(ebx + 8);
    eax = eax & 0xF;
    eax = eax ^ MEM32(esi + 0x10);
    MEM32(ebx + 8) = eax;

loc_003C3AE6: ;
    /* cmp MEM8(ebx + 0x11), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(ebx + 0x11), 0)); /* latched */
    MEM32(ebp + -4) = esi;
    if (_rcc0) goto loc_003C3B55; /* jne: not equal / not zero */

loc_003C3AEF: ;
    eax = 0; /* xor self */
    SET_LO8(eax, 0xFE);
    SET_LO8(eax, LO8(eax) - MEM8(ebp + -24));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3AFC); sub_003C399D(); /* call 0x003C399D */

loc_003C3AFC: ;
    ecx = MEM32(edi + 0x28);
    PUSH32(esp, MEM32(ebp + -24));
    MEM32(eax) = ecx;
    ecx = MEM32(edi + 0x2C);
    MEM32(ebp + -36) = eax;
    MEM32(eax + 4) = ecx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3B12); sub_003C399D(); /* call 0x003C399D */

loc_003C3B12: ;
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

loc_003C3B55: ;
    if (CMP_EQ(MEM32(ebp + -16), 0)) goto loc_003C3B71; /* je: equal / zero */

loc_003C3B5B: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(ebp + -16));
    PUSH32(esp, MEM32(edi + 0x18));
    { uint32_t _icall_t = MEM32(0x3C5060); g_seh_ebp = ebp; PUSH32(esp, 0x3C3B69); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3B69: ;
    eax = MEM32(edi + 0x18);
    MEM32(ebp + -36) = eax;
    goto loc_003C3B75;

loc_003C3B71: ;
    MEM8(edi + 0x1C) = 1;

loc_003C3B75: ;
    if (CMP_EQ(MEM32(ebp + -16), 0)) goto loc_003C3C90; /* je: equal / zero */

loc_003C3B7F: ;
    eax = ebp + -20;
    PUSH32(esp, eax);
    edx = ebp + -16;
    ecx = ebp + -36;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3B8E); sub_003C3A2D(); /* call 0x003C3A2D */

loc_003C3B8E: ;
    MEM32(ebp + -4) = eax;

loc_003C3B91: ;
    edx = MEM32(ebp + -20);
    eax = MEM32(ebp + -12);
    ecx = MEM32(ebp + -40);
    eax = eax + edx;
    if (CMP_AE(eax, ecx)) goto loc_003C3BB2; /* jae: above or equal (unsigned >=) */

loc_003C3BA0: ;
    if (TEST_Z(edx, edx)) goto loc_003C3C6A; /* je: equal / zero */

loc_003C3BA8: ;
    if (CMP_NE(MEM32(ebp + -16), 0)) goto loc_003C3C6A; /* jne: not equal / not zero */

loc_003C3BB2: ;
    if (CMP_EQ(MEM32(ebp + -12), 0)) goto loc_003C3BDA; /* je: equal / zero */

loc_003C3BB8: ;
    ecx = ecx - MEM32(ebp + -12);
    eax = MEM32(ebp + -28);
    /* cmp edx, ecx - flags set for next jcc */
    MEM32(esi + 4) = eax;
    if (CMP_AE(edx, ecx)) goto loc_003C3BC7; /* jae: above or equal (unsigned >=) */

loc_003C3BC5: ;
    ecx = edx;

loc_003C3BC7: ;
    SET_LO8(eax, MEM8(ebp + -12));
    MEM32(ebp + -4) = MEM32(ebp + -4) + ecx;
    SET_LO8(eax, LO8(eax) + LO8(ecx));
    edx = edx - ecx;
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    MEM8(esi + 0x1D) = LO8(eax);
    goto loc_003C3BF8;

loc_003C3BDA: ;
    /* cmp edx, ecx - flags set for next jcc */
    eax = MEM32(ebp + -4);
    MEM32(esi + 4) = eax;
    if (CMP_AE(edx, ecx)) goto loc_003C3BF0; /* jae: above or equal (unsigned >=) */

loc_003C3BE4: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + edx;
    MEM32(ebp + -20) = MEM32(ebp + -20) & 0;
    MEM8(esi + 0x1D) = LO8(edx);
    goto loc_003C3BFB;

loc_003C3BF0: ;
    MEM32(ebp + -4) = MEM32(ebp + -4) + ecx;
    MEM8(esi + 0x1D) = LO8(ecx);
    edx = edx - ecx;

loc_003C3BF8: ;
    MEM32(ebp + -20) = edx;

loc_003C3BFB: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3C5A); sub_003C399D(); /* call 0x003C399D */

loc_003C3C5A: ;
    ecx = MEM32(ebp + -8);
    esi = eax;
    eax = MEM32(esi + 0x10);
    MEM32(ecx + 8) = eax;
    { RECOMP_SLICE_POINT(); goto loc_003C3B91; }

loc_003C3C6A: ;
    /* cmp MEM32(ebp + -16), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM32(ebp + -16), 0)); /* latched */
    eax = MEM32(ebp + -4);
    MEM32(ebp + -28) = eax;
    MEM32(ebp + -12) = edx;
    if (_rcc0) { RECOMP_SLICE_POINT(); goto loc_003C3B7F; } /* jne: not equal / not zero */

loc_003C3C7D: ;
    if (CMP_EQ(MEM32(ebp + -8), 0)) goto loc_003C3C90; /* je: equal / zero */

loc_003C3C83: ;
    if (CMP_EQ(MEM8(edi + 0x1D), 0)) goto loc_003C3C90; /* je: equal / zero */

loc_003C3C89: ;
    eax = MEM32(ebp + -8);
    MEM8(eax + 2) = MEM8(eax + 2) | 4;

loc_003C3C90: ;
    if (CMP_NE(MEM8(ebx + 0x11), 0)) goto loc_003C3D00; /* jne: not equal / not zero */

loc_003C3C96: ;
    MEM8(esi + 2) = MEM8(esi + 2) & 0xFB;
    ecx = MEM32(esi);
    eax = 0; /* xor self */
    /* cmp MEM8(edi + 0x1C), 2 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(edi + 0x1C), 2)); /* latched */
    PUSH32(esp, MEM32(ebp + -24));
    SET_LO8(eax, (_rcc0) ? 1 : 0); /* setne */
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3CF3); sub_003C399D(); /* call 0x003C399D */

loc_003C3CF3: ;
    ecx = MEM32(ebp + -8);
    esi = eax;
    eax = MEM32(esi + 0x10);
    MEM32(ecx + 8) = eax;
    goto loc_003C3D18;

loc_003C3D00: ;
    ecx = ZX8(MEM8(edi + 0x1E));
    eax = MEM32(ebp + -8);
    ecx = ecx << 0x15;
    ecx = ecx ^ MEM32(eax);
    MEM8(eax + 0x1C) = 2;
    ecx = ecx & 0xE00000;
    MEM32(eax) = MEM32(eax) ^ ecx;

loc_003C3D18: ;
    MEM8(esi + 0x1E) = 3;
    SET_LO16(eax, MEM16(edi + 0x14));
    MEM32(edi + 0x14) = MEM32(edi + 0x14) & 0;
    MEM16(edi + 0x20) = LO16(eax);
    /* cmp MEM8(ebx + 0x20), 0 - flags set for next jcc */
    _rcc0 = (CMP_NE(MEM8(ebx + 0x20), 0)); /* latched */
    eax = MEM32(esi + 0x10);
    MEM32(ebx + 4) = eax;
    if (_rcc0) goto loc_003C3D38; /* jne: not equal / not zero */

loc_003C3D34: ;
    MEM8(ebx + 1) = MEM8(ebx + 1) & 0xBF;

loc_003C3D38: ;
    SET_LO8(ebx, MEM8(ebx + 0x11));
    if (TEST_NZ(LO8(ebx), LO8(ebx))) goto loc_003C3D4D; /* jne: not equal / not zero */

loc_003C3D3F: ;
    eax = MEM32(ebp + -32);
    eax = MEM32(eax);
    MEM32(eax + 8) = 2;
    goto loc_003C3D5E;

loc_003C3D4D: ;
    if (CMP_NE(LO8(ebx), 2)) goto loc_003C3D5E; /* jne: not equal / not zero */

loc_003C3D52: ;
    eax = MEM32(ebp + -32);
    eax = MEM32(eax);
    MEM32(eax + 8) = 4;

loc_003C3D5E: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C3D65
 * Original: 0x003C3D65 - 0x003C3DB8 (83 bytes, 34 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3D65(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3D65: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    PUSH32(esp, esi);
    esi = edx;
    /* cmp MEM32(esi + 0x28), 0 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM32(esi + 0x28), 0)); /* latched */
    MEM32(ebp + -4) = ecx;
    if (_rcc0) goto loc_003C3DB5; /* je: equal / zero */

loc_003C3D75: ;
    PUSH32(esp, ebx);

loc_003C3D76: ;
    eax = MEM32(esi + 0x28);
    SET_LO16(edx, MEM16(esi + 0x24));
    ebx = ZX16(MEM16(eax + 0x20));
    ecx = ZX16(LO16(edx));
    ecx = ecx + ebx;
    if (CMP_G(ecx, 3)) goto loc_003C3DB4; /* jg: greater (signed >) */

loc_003C3D8B: ;
    ecx = MEM32(eax + 0x24);
    /* test ecx, ecx - flags set for next jcc */
    MEM32(esi + 0x28) = ecx;
    if (TEST_NZ(ecx, ecx)) goto loc_003C3D98; /* jne: not equal / not zero */

loc_003C3D95: ;
    MEM32(esi + 0x2C) = MEM32(esi + 0x2C) & ecx;

loc_003C3D98: ;
    SET_LO16(ecx, MEM16(eax + 0x20));
    SET_LO16(ecx, LO16(ecx) + LO16(edx));
    MEM16(esi + 0x24) = LO16(ecx);
    ecx = MEM32(ebp + -4);
    PUSH32(esp, eax);
    edx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3DAE); sub_003C3A67(); /* call 0x003C3A67 */

loc_003C3DAE: ;
    if (CMP_NE(MEM32(esi + 0x28), 0)) { RECOMP_SLICE_POINT(); goto loc_003C3D76; } /* jne: not equal / not zero */

loc_003C3DB4: ;
    POP32(esp, ebx);

loc_003C3DB5: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C3DB8
 * Original: 0x003C3DB8 - 0x003C3E05 (77 bytes, 26 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3DB8(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3DB8: ;
    PUSH32(esp, esi);
    esi = ecx;
    if (CMP_EQ(MEM32(esi + 0x424), 0)) goto loc_003C3E03; /* je: equal / zero */

loc_003C3DC4: ;
    PUSH32(esp, edi);

loc_003C3DC5: ;
    edi = MEM32(esi + 0x424);
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi + 0x20));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3DD7); sub_003C39DC(); /* call 0x003C39DC */

loc_003C3DD7: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C3E02; /* je: equal / zero */

loc_003C3DDB: ;
    eax = MEM32(edi + 0x24);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x424) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003C3DEE; /* jne: not equal / not zero */

loc_003C3DE8: ;
    MEM32(esi + 0x428) = MEM32(esi + 0x428) & eax;

loc_003C3DEE: ;
    edx = MEM32(edi + 0x10);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3DF9); sub_003C3A67(); /* call 0x003C3A67 */

loc_003C3DF9: ;
    if (CMP_NE(MEM32(esi + 0x424), 0)) { RECOMP_SLICE_POINT(); goto loc_003C3DC5; } /* jne: not equal / not zero */

loc_003C3E02: ;
    POP32(esp, edi);

loc_003C3E03: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C3E05
 * Original: 0x003C3E05 - 0x003C3E52 (77 bytes, 26 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3E05(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3E05: ;
    PUSH32(esp, esi);
    esi = ecx;
    if (CMP_EQ(MEM32(esi + 0x41C), 0)) goto loc_003C3E50; /* je: equal / zero */

loc_003C3E11: ;
    PUSH32(esp, edi);

loc_003C3E12: ;
    edi = MEM32(esi + 0x41C);
    eax = 0; /* xor self */
    SET_LO16(eax, MEM16(edi + 0x20));
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3E24); sub_003C39BD(); /* call 0x003C39BD */

loc_003C3E24: ;
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C3E4F; /* je: equal / zero */

loc_003C3E28: ;
    eax = MEM32(edi + 0x24);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi + 0x41C) = eax;
    if (TEST_NZ(eax, eax)) goto loc_003C3E3B; /* jne: not equal / not zero */

loc_003C3E35: ;
    MEM32(esi + 0x420) = MEM32(esi + 0x420) & eax;

loc_003C3E3B: ;
    edx = MEM32(edi + 0x10);
    PUSH32(esp, edi);
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3E46); sub_003C3A67(); /* call 0x003C3A67 */

loc_003C3E46: ;
    if (CMP_NE(MEM32(esi + 0x41C), 0)) { RECOMP_SLICE_POINT(); goto loc_003C3E12; } /* jne: not equal / not zero */

loc_003C3E4F: ;
    POP32(esp, edi);

loc_003C3E50: ;
    POP32(esp, esi);
    esp += 4; return; /* ret */

}

/**
 * sub_003C3E52
 * Original: 0x003C3E52 - 0x003C3E85 (51 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3E52(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3E52: ;
    eax = MEM32(esp + 4);
    if (CMP_BE(MEM16(eax + 0x20), 3)) goto loc_003C3E64; /* jbe: below or equal (unsigned <=) */

loc_003C3E5D: ;
    eax = 0x80000500u;
    goto loc_003C3E82;

loc_003C3E64: ;
    PUSH32(esp, esi);
    esi = MEM32(edx + 0x2C);
    if (TEST_Z(esi, esi)) goto loc_003C3E71; /* je: equal / zero */

loc_003C3E6C: ;
    MEM32(esi + 0x24) = eax;
    goto loc_003C3E74;

loc_003C3E71: ;
    MEM32(edx + 0x28) = eax;

loc_003C3E74: ;
    MEM32(edx + 0x2C) = eax;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3E7C); sub_003C3D65(); /* call 0x003C3D65 */

loc_003C3E7C: ;
    eax = 0x40000000;
    POP32(esp, esi);

loc_003C3E82: ;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C3E85
 * Original: 0x003C3E85 - 0x003C3EC1 (60 bytes, 16 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3E85(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3E85: ;
    SET_LO16(eax, MEM16(edx + 0x20));
    if (CMP_BE(LO16(eax), MEM16(0xF4C364))) goto loc_003C3E98; /* jbe: below or equal (unsigned <=) */

loc_003C3E92: ;
    eax = 0x80000500u;
    esp += 4; return; /* ret */

loc_003C3E98: ;
    eax = ecx + 0x424;
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003C3EAE; /* je: equal / zero */

loc_003C3EA3: ;
    eax = MEM32(ecx + 0x428);
    MEM32(eax + 0x24) = edx;
    goto loc_003C3EB0;

loc_003C3EAE: ;
    MEM32(eax) = edx;

loc_003C3EB0: ;
    MEM32(ecx + 0x428) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3EBB); sub_003C3DB8(); /* call 0x003C3DB8 */

loc_003C3EBB: ;
    eax = 0x40000000;
    esp += 4; return; /* ret */

}

/**
 * sub_003C3EC1
 * Original: 0x003C3EC1 - 0x003C3EFD (60 bytes, 16 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3EC1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C3EC1: ;
    SET_LO16(eax, MEM16(edx + 0x20));
    if (CMP_BE(LO16(eax), MEM16(0xF4C360))) goto loc_003C3ED4; /* jbe: below or equal (unsigned <=) */

loc_003C3ECE: ;
    eax = 0x80000500u;
    esp += 4; return; /* ret */

loc_003C3ED4: ;
    eax = ecx + 0x41C;
    if (CMP_EQ(MEM32(eax), 0)) goto loc_003C3EEA; /* je: equal / zero */

loc_003C3EDF: ;
    eax = MEM32(ecx + 0x420);
    MEM32(eax + 0x24) = edx;
    goto loc_003C3EEC;

loc_003C3EEA: ;
    MEM32(eax) = edx;

loc_003C3EEC: ;
    MEM32(ecx + 0x420) = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3EF7); sub_003C3E05(); /* call 0x003C3E05 */

loc_003C3EF7: ;
    eax = 0x40000000;
    esp += 4; return; /* ret */

}

/**
 * sub_003C3EFD
 * Original: 0x003C3EFD - 0x003C3F83 (134 bytes, 53 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3EFD(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C3EFD: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3F14); sub_003C39FB(); /* call 0x003C39FB */

loc_003C3F14: ;
    MEM16(esi + 0x20) = LO16(eax);
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C3F1E); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3F1E: ;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) + 1;
    MEM32(esi + 0x24) = MEM32(esi + 0x24) & 0;
    MEM8(ebp + -1) = LO8(eax);
    MEM16(esi + 0x22) = 2;
    eax = ZX8(MEM8(edi + 0x11));
    eax = eax - 0;
    if ((eax == 0)) goto loc_003C3F5C; /* je: equal / zero */

loc_003C3F37: ;
    eax--;
    eax--;
    if ((eax == 0)) goto loc_003C3F51; /* je: equal / zero */

loc_003C3F3B: ;
    eax--;
    if ((eax == 0)) goto loc_003C3F45; /* je: equal / zero */

loc_003C3F3E: ;
    ebx = 0x80000600u;
    goto loc_003C3F6B;

loc_003C3F45: ;
    PUSH32(esp, esi);
    edx = edi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3F4F); sub_003C3E52(); /* call 0x003C3E52 */

loc_003C3F4F: ;
    goto loc_003C3F65;

loc_003C3F51: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3F5A); sub_003C3E85(); /* call 0x003C3E85 */

loc_003C3F5A: ;
    goto loc_003C3F65;

loc_003C3F5C: ;
    edx = esi;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3F65); sub_003C3EC1(); /* call 0x003C3EC1 */

loc_003C3F65: ;
    ebx = eax;
    if (CMP_GE(ebx & ebx, 0)) goto loc_003C3F73; /* jge: greater or equal (signed >=) */

loc_003C3F6B: ;
    MEM16(esi + 0x22) = MEM16(esi + 0x22) & 0;
    MEM8(edi + 0x26) = MEM8(edi + 0x26) - 1;

loc_003C3F73: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C3F7C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C3F7C: ;
    POP32(esp, edi);
    POP32(esp, esi);
    eax = ebx;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C3F83
 * Original: 0x003C3F83 - 0x003C406A (231 bytes, 84 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C3F83(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003C3F83: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3F93); sub_003BF80D(); /* call 0x003BF80D */

loc_003C3F93: ;
    esi = eax;
    /* cmp esi, 0x10 - flags set for next jcc */
    ecx = ebx;
    if (CMP_AE(esi, 0x10)) goto loc_003C4059; /* jae: above or equal (unsigned >=) */

loc_003C3FA0: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3FA5); sub_003BF791(); /* call 0x003BF791 */

loc_003C3FA5: ;
    SET_LO8(eax, MEM8(eax + 6));
    if (TEST_NZ(LO8(eax), LO8(eax))) goto loc_003C3FB2; /* jne: not equal / not zero */

loc_003C3FAC: ;
    MEM32(ebp + 8) = MEM32(ebp + 8) & 0;
    goto loc_003C3FC1;

loc_003C3FB2: ;
    if (CMP_NE(LO8(eax), 1)) goto loc_003C4057; /* jne: not equal / not zero */

loc_003C3FBA: ;
    MEM32(ebp + 8) = 1;

loc_003C3FC1: ;
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    PUSH32(esp, 1);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3FCE); sub_003BF797(); /* call 0x003BF797 */

loc_003C3FCE: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003C3FF1; /* je: equal / zero */

loc_003C3FD4: ;
    SET_LO8(ecx, MEM8(ebp + 8));
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF30AB0;
    SET_LO8(eax, MEM8(esi + 0xB));
    SET_LO8(eax, LO8(eax) & 0x6F);
    SET_LO8(ecx, LO8(ecx) << 7);
    SET_LO8(eax, LO8(eax) | LO8(ecx));
    SET_LO8(eax, LO8(eax) | 0x10);
    MEM8(esi + 0xB) = LO8(eax);
    goto loc_003C4017;

loc_003C3FF1: ;
    PUSH32(esp, 0);
    PUSH32(esp, 0);
    PUSH32(esp, 1);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C3FFE); sub_003BF797(); /* call 0x003BF797 */

loc_003C3FFE: ;
    edi = eax;
    if (TEST_Z(edi, edi)) goto loc_003C4057; /* je: equal / zero */

loc_003C4004: ;
    if (CMP_NE(MEM32(ebp + 8), 0)) goto loc_003C4057; /* jne: not equal / not zero */

loc_003C400A: ;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF30B20;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xEF;

loc_003C4017: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 1;
    PUSH32(esp, esi);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4023); sub_003BF69C(); /* call 0x003BF69C */

loc_003C4023: ;
    /* test MEM8(esi + 0xB), 0x10 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0xB), 0x10)); /* latched */
    MEM32(esi + 4) = ebx;
    SET_LO8(eax, MEM8(edi + 2));
    MEM8(esi + 0xA) = LO8(eax);
    SET_LO16(eax, MEM16(edi + 4));
    MEM16(esi + 8) = LO16(eax);
    if (_rcc0) goto loc_003C4046; /* je: equal / zero */

loc_003C403A: ;
    eax = MEM32(ebp + 8);
    eax = (uint32_t)(-(int32_t)eax);
    _cf = ((eax) != 0); /* CF from neg */
    eax = _cf ? 0xFFFFFFFF : 0; /* sbb self (CF extend) */
    eax = eax & 2;
    goto loc_003C4049;

loc_003C4046: ;
    eax = 0; /* xor self */
    eax++;

loc_003C4049: ;
    PUSH32(esp, eax);
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4051); sub_003BF6AD(); /* call 0x003BF6AD */

loc_003C4051: ;
    PUSH32(esp, 0);
    ecx = ebx;
    goto loc_003C405E;

loc_003C4057: ;
    ecx = ebx;

loc_003C4059: ;
    PUSH32(esp, 0x80000400u);

loc_003C405E: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4063); sub_003BE253(); /* call 0x003BE253 */

loc_003C4063: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C406A
 * Original: 0x003C406A - 0x003C4086 (28 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C406A(void)
{
    uint32_t ebp;

loc_003C406A: ;
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
 * sub_003C4086
 * Original: 0x003C4086 - 0x003C40D1 (75 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4086(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C4086: ;
    ecx = MEM32(esp + 4);
    /* test MEM8(ecx + 0xB), 0x10 - flags set for next jcc */
    eax = MEM32(esp + 8);
    if (TEST_Z(MEM8(ecx + 0xB), 0x10)) goto loc_003C40AF; /* je: equal / zero */

loc_003C4094: ;
    MEM32(eax) = 9;
    ecx = MEM32(ecx + 0x18);
    ecx = (uint32_t)(int32_t)SMEM8(ecx + 0x14);
    ecx = ecx + ecx * 4;
    ecx = ecx << 1;
    MEM32(eax + 4) = MEM32(eax + 4) & 0;
    MEM32(eax + 8) = ecx;
    goto loc_003C40C8;

loc_003C40AF: ;
    MEM32(eax) = 5;
    ecx = MEM32(ecx + 0x18);
    ecx = (uint32_t)(int32_t)SMEM8(ecx + 0x14);
    ecx = ecx + ecx * 4;
    ecx = ecx << 1;
    MEM32(eax + 8) = MEM32(eax + 8) & 0;
    MEM32(eax + 4) = ecx;

loc_003C40C8: ;
    MEM32(eax + 0xC) = MEM32(eax + 0xC) & 0;
    eax = 0; /* xor self */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C40D1
 * Original: 0x003C40D1 - 0x003C40D9 (8 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C40D1(void)
{

loc_003C40D1: ;
    eax = 0x80004001u;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C40D9
 * Original: 0x003C40D9 - 0x003C40DE (5 bytes, 2 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C40D9(void)
{

loc_003C40D9: ;
    eax = 0; /* xor self */
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C40DE
 * Original: 0x003C40DE - 0x003C4121 (67 bytes, 24 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C40DE(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C40DE: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C40E5); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C40E5: ;
    edx = MEM32(esp + 8);
    SET_LO8(ebx, MEM8(edx + 0xB));
    if (TEST_Z(LO8(ebx), 0x20)) goto loc_003C410C; /* je: equal / zero */

loc_003C40F1: ;
    ecx = MEM32(edx + 0x18);
    if (CMP_EQ(MEM32(ecx + 0xC), 0)) goto loc_003C410C; /* je: equal / zero */

loc_003C40FA: ;
    edx = MEM32(esp + 0xC);
    PUSH32(esp, 0);
    /* test LO8(ebx), 0x10 - flags set for next jcc */
    POP32(esp, ecx);
    SET_LO8(ecx, (TEST_NZ(LO8(ebx), 0x10)) ? 1 : 0); /* setne */
    ecx++;
    MEM32(edx) = ecx;
    goto loc_003C4113;

loc_003C410C: ;
    ecx = MEM32(esp + 0xC);
    MEM32(ecx) = MEM32(ecx) & 0;

loc_003C4113: ;
    SET_LO8(ecx, LO8(eax));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C411B); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C411B: ;
    eax = 0; /* xor self */
    POP32(esp, ebx);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C4121
 * Original: 0x003C4121 - 0x003C4230 (271 bytes, 86 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4121(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4121: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x30;
    PUSH32(esp, esi);
    esi = ecx;
    if (TEST_NZ(MEM8(esi + 0xB), 1)) goto loc_003C413A; /* jne: not equal / not zero */

loc_003C4130: ;
    eax = 0x8007048Fu;
    goto loc_003C422B;

loc_003C413A: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    eax = ebp + -48;
    ebx = 0; /* xor self */
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x20;
    MEM8(ebp + -47) = 0x82;
    MEM32(ebp + -40) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4155); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C4155: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003C4208; /* jl: less (signed <) */

loc_003C415F: ;
    SET_LO8(ecx, MEM8(ebp + 0xC));
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 4;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C416C); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C416C: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C41B5); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C41B5: ;
    ecx = MEM32(esi + 4);
    edi = eax;
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x1C;
    MEM8(ebp + -47) = 0xC3;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C41D1); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C41D1: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C41D7); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C41D7: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF9;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C4200; /* je: equal / zero */

loc_003C41E1: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C41EA); sub_003BF69C(); /* call 0x003BF69C */

loc_003C41EA: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C41F2); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C41F2: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = ebx;
    eax = 0x8007048Fu;
    goto loc_003C4229;

loc_003C4200: ;
    if (CMP_NE(MEM8(ebp + 8), 2)) goto loc_003C4208; /* jne: not equal / not zero */

loc_003C4206: ;
    edi = 0; /* xor self */

loc_003C4208: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C420E); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C420E: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C421A; /* jg: greater (signed >) */

loc_003C4213: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4218); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C4218: ;
    goto loc_003C4229;

loc_003C421A: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C421F); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C421F: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;

loc_003C4229: ;
    POP32(esp, edi);
    POP32(esp, ebx);

loc_003C422B: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C4230
 * Original: 0x003C4230 - 0x003C4335 (261 bytes, 82 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4230(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4230: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x30;
    PUSH32(esp, esi);
    esi = ecx;
    if (TEST_NZ(MEM8(esi + 0xB), 1)) goto loc_003C4249; /* jne: not equal / not zero */

loc_003C423F: ;
    eax = 0x8007048Fu;
    goto loc_003C4330;

loc_003C4249: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    eax = ebp + -48;
    ebx = 0; /* xor self */
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x20;
    MEM8(ebp + -47) = 0x82;
    MEM32(ebp + -40) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4264); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C4264: ;
    edi = eax;
    if (CMP_L(edi, ebx)) goto loc_003C430D; /* jl: less (signed <) */

loc_003C426E: ;
    SET_LO8(ecx, MEM8(ebp + 0xC));
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 4;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C427B); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C427B: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C42C2); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C42C2: ;
    ecx = MEM32(esi + 4);
    edi = eax;
    eax = ebp + -48;
    PUSH32(esp, eax);
    MEM8(ebp + -48) = 0x1C;
    MEM8(ebp + -47) = 0xC3;
    MEM32(ebp + -40) = ebx;
    MEM32(ebp + -36) = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C42DE); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C42DE: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C42E4); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C42E4: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF9;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C430D; /* je: equal / zero */

loc_003C42EE: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, ebx);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C42F7); sub_003BF69C(); /* call 0x003BF69C */

loc_003C42F7: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C42FF); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C42FF: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = ebx;
    eax = 0x8007048Fu;
    goto loc_003C432E;

loc_003C430D: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4313); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C4313: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C431F; /* jg: greater (signed >) */

loc_003C4318: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C431D); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C431D: ;
    goto loc_003C432E;

loc_003C431F: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4324); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C4324: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;

loc_003C432E: ;
    POP32(esp, edi);
    POP32(esp, ebx);

loc_003C4330: ;
    POP32(esp, esi);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C4335
 * Original: 0x003C4335 - 0x003C4351 (28 bytes, 10 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4335(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C4335: ;
    eax = MEM32(esp + 4);
    MEM32(eax + 0x18) = MEM32(eax + 0x18) & 0;
    edx = MEM32(ecx + 4);
    if (TEST_Z(edx, edx)) goto loc_003C4349; /* je: equal / zero */

loc_003C4344: ;
    MEM32(edx + 0x18) = eax;
    goto loc_003C434B;

loc_003C4349: ;
    MEM32(ecx) = eax;

loc_003C434B: ;
    MEM32(ecx + 4) = eax;
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C4351
 * Original: 0x003C4351 - 0x003C4367 (22 bytes, 11 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4351(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C4351: ;
    eax = MEM32(ecx);
    if (TEST_Z(eax, eax)) goto loc_003C4364; /* je: equal / zero */

loc_003C4357: ;
    edx = MEM32(eax + 0x18);
    /* test edx, edx - flags set for next jcc */
    MEM32(ecx) = edx;
    if (TEST_NZ(edx, edx)) goto loc_003C4366; /* jne: not equal / not zero */

loc_003C4360: ;
    MEM32(ecx + 4) = MEM32(ecx + 4) & edx;
    esp += 4; return; /* ret */

loc_003C4364: ;
    eax = 0; /* xor self */

loc_003C4366: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C4367
 * Original: 0x003C4367 - 0x003C44B9 (338 bytes, 112 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4367(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4367: ;
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
    { uint32_t _icall_t = MEM32(0x3C501C); g_seh_ebp = ebp; PUSH32(esp, 0x3C4383); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4383: ;
    edx = eax;
    /* test edx, edx - flags set for next jcc */
    MEM32(ebp + -4) = edx;
    if (TEST_NZ(edx, edx)) goto loc_003C4396; /* jne: not equal / not zero */

loc_003C438C: ;
    eax = 0x8007000Eu;
    goto loc_003C44B3;

loc_003C4396: ;
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
    esi = MEM32(0x3BBF50);
    eax = MEM32(esi);
    MEM32(0x3BBF50) = eax;
    eax = 0; /* xor self */
    ecx = 0xE0;
    edi = esi;
    { uint32_t _i; for (_i = 0; _i < ecx; _i++) MEM32(edi + _i*4) = eax; }
    edi += ecx * 4; ecx = 0; /* rep stosd */
    eax = MEM32(ebp + 8);
    /* test eax, eax - flags set for next jcc */
    MEM32(esi) = edx;
    if (CMP_BE(eax & eax, 0)) goto loc_003C43E0; /* jbe: below or equal (unsigned <=) */

loc_003C43CA: ;
    ecx = esi + 0xC;
    edi = edx;
    MEM32(ebp + 8) = eax;

loc_003C43D2: ;
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C43D8); sub_003C4335(); /* call 0x003C4335 */

loc_003C43D8: ;
    edi = edi + 0x1C;
    MEM32(ebp + 8) = MEM32(ebp + 8) - 1;
    if ((MEM32(ebp + 8) != 0)) { RECOMP_SLICE_POINT(); goto loc_003C43D2; } /* jne: not equal / not zero */

loc_003C43E0: ;
    eax = MEM32(ebp + 0xC);
    eax = eax << 2;
    SET_LO8(ecx, MEM8(eax + 0x3BBF56));
    MEM8(esi + 0x14) = LO8(ecx);
    SET_LO8(eax, MEM8(eax + 0x3BBF57));
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4438); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C4438: ;
    edi = eax;
    ecx = 0; /* xor self */
    if (CMP_GE(edi, ecx)) goto loc_003C4479; /* jge: greater or equal (signed >=) */

loc_003C4440: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(ebp + -4));
    { uint32_t _icall_t = MEM32(0x3C5018); g_seh_ebp = ebp; PUSH32(esp, 0x3C4449); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4449: ;
    eax = MEM32(0x3BBF50);
    MEM32(esi) = eax;
    PUSH32(esp, edi);
    MEM32(0x3BBF50) = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C445C); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C445C: ;
    /* test eax, eax - flags set for next jcc */
    PUSH32(esp, edi);
    if (CMP_G(eax & eax, 0)) goto loc_003C4468; /* jg: greater (signed >) */

loc_003C4461: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4466); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C4466: ;
    goto loc_003C44B2;

loc_003C4468: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C446D); sub_003BF6B7(); /* call 0x003BF6B7 */

loc_003C446D: ;
    eax = eax & 0xFFFF;
    eax = eax | 0x80070000u;
    goto loc_003C44B2;

loc_003C4479: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C44AD); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C44AD: ;
    MEM32(ebx + 0x18) = esi;
    eax = 0; /* xor self */

loc_003C44B2: ;
    POP32(esp, edi);

loc_003C44B3: ;
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C44B9
 * Original: 0x003C44B9 - 0x003C46EB (562 bytes, 192 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C44B9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C44B9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x48;
    PUSH32(esp, ebx);
    PUSH32(esp, edi);
    edi = ecx;
    MEM32(ebp + -12) = edi;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C44CC); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C44CC: ;
    MEM8(ebp + -1) = LO8(eax);
    eax = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(eax + 0x17));
    ebx = 0; /* xor self */
    if (TEST_Z(LO8(eax), 1)) goto loc_003C44EA; /* je: equal / zero */

loc_003C44DB: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFE;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x18;
    goto loc_003C44FB;

loc_003C44EA: ;
    if (TEST_Z(LO8(eax), 2)) goto loc_003C44FB; /* je: equal / zero */

loc_003C44EE: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFD;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x2C;

loc_003C44FB: ;
    /* test ebx, ebx - flags set for next jcc */
    MEM32(ebp + -48) = 0x3C46EB;
    if (TEST_Z(ebx, ebx)) goto loc_003C46DE; /* je: equal / zero */

loc_003C450A: ;
    PUSH32(esp, esi);

loc_003C450B: ;
    eax = MEM32(edi + 0x18);
    eax = MEM32(eax + 4);
    if (TEST_Z(eax, eax)) goto loc_003C46D4; /* je: equal / zero */

loc_003C4519: ;
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

loc_003C453A: ;
    ecx = MEM32(edi + 0x18);
    esi = MEM32(ebp + -8);
    SET_LO16(edx, (uint32_t)(int32_t)SMEM8(ecx + 0x14));
    esi = ebp + esi * 2 + -64;
    MEM16(esi) = LO16(edx);
    if (CMP_EQ(MEM8(ecx + 0x15), 0)) goto loc_003C4568; /* je: equal / zero */

loc_003C4552: ;
    MEM8(ecx + 0x16) = MEM8(ecx + 0x16) + 1;
    ecx = MEM32(edi + 0x18);
    SET_LO8(edx, MEM8(ecx + 0x16));
    if (CMP_NE(LO8(edx), MEM8(ecx + 0x15))) goto loc_003C4568; /* jne: not equal / not zero */

loc_003C4560: ;
    MEM16(esi) = MEM16(esi) + 2;
    MEM8(ecx + 0x16) = 0;

loc_003C4568: ;
    ecx = ZX16(MEM16(esi));
    edx = MEM32(ebx + 0xC);
    ecx = ecx + edx;
    MEM32(ebx + 0xC) = ecx;
    edx = MEM32(eax + 4);
    if (CMP_BE(ecx, edx)) goto loc_003C45AB; /* jbe: below or equal (unsigned <=) */

loc_003C457A: ;
    ecx = ecx - edx;
    edx = MEM32(edi + 0x18);
    MEM32(edx + 0x48) = ecx;
    ecx = MEM32(eax + 4);
    MEM32(ebx + 0xC) = ecx;
    MEM8(ebx + 0x10) = 1;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C45AB; /* jne: not equal / not zero */

loc_003C4592: ;
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

loc_003C45AB: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(ebp + -8) = MEM32(ebp + -8) + 1;
    if (CMP_EQ(ecx, MEM32(eax + 4))) goto loc_003C45C2; /* je: equal / zero */

loc_003C45B6: ;
    if (CMP_L(MEM32(ebp + -8), 8)) { RECOMP_SLICE_POINT(); goto loc_003C453A; } /* jl: less (signed <) */

loc_003C45C0: ;
    goto loc_003C45C6;

loc_003C45C2: ;
    MEM8(ebx + 0x13) = 1;

loc_003C45C6: ;
    ecx = MEM32(ebx + 0xC);
    MEM32(eax + 4) = MEM32(eax + 4) - ecx;
    ecx = MEM32(ebp + -8);
    MEM32(ebp + -44) = ebx;
    MEM32(ebp + -72) = ecx;
    ecx = MEM32(eax);
    MEM32(ebp + -68) = ecx;
    ecx = MEM32(ebx + 0xC);
    MEM32(eax) = MEM32(eax) + ecx;
    if (CMP_EQ(MEM8(ebx + 0x13), 0)) goto loc_003C45F0; /* je: equal / zero */

loc_003C45E5: ;
    ecx = MEM32(edi + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C45F0); sub_003C4351(); /* call 0x003C4351 */

loc_003C45F0: ;
    if (CMP_EQ(MEM8(ebx + 0x10), 0)) goto loc_003C466A; /* je: equal / zero */

loc_003C45F6: ;
    edx = MEM32(edi + 0x18);
    eax = edx + 0x4C;
    MEM32(ebp + -68) = eax;
    eax = MEM32(edx + 4);
    if (TEST_Z(eax, eax)) goto loc_003C463F; /* je: equal / zero */

loc_003C4606: ;
    MEM32(edx + 0x40) = eax;
    esi = MEM32(eax);
    MEM32(edx + 0x44) = esi;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C462F; /* jne: not equal / not zero */

loc_003C4614: ;
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

loc_003C462F: ;
    ecx = MEM32(edx + 0x48);
    ecx = ecx + MEM32(edx + 0x44);
    MEM32(eax) = ecx;
    ecx = MEM32(edx + 0x48);
    MEM32(eax + 4) = MEM32(eax + 4) - ecx;
    goto loc_003C466A;

loc_003C463F: ;
    MEM32(edx + 0x40) = MEM32(edx + 0x40) & 0;
    MEM32(edx + 0x44) = MEM32(edx + 0x44) & 0;
    if (TEST_NZ(MEM8(edi + 0xB), 0x10)) goto loc_003C466A; /* jne: not equal / not zero */

loc_003C464D: ;
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

loc_003C466A: ;
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
    g_seh_ebp = ebp; PUSH32(esp, 0x3C469C); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C469C: ;
    eax = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(eax + 0x17));
    if (TEST_Z(LO8(eax), 1)) goto loc_003C46B5; /* je: equal / zero */

loc_003C46A6: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFE;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x18;
    goto loc_003C46CA;

loc_003C46B5: ;
    if (TEST_Z(LO8(eax), 2)) goto loc_003C46C8; /* je: equal / zero */

loc_003C46B9: ;
    eax = MEM32(edi + 0x18);
    MEM8(eax + 0x17) = MEM8(eax + 0x17) & 0xFD;
    ebx = MEM32(edi + 0x18);
    ebx = ebx + 0x2C;
    goto loc_003C46CA;

loc_003C46C8: ;
    ebx = 0; /* xor self */

loc_003C46CA: ;
    if (TEST_NZ(ebx, ebx)) { RECOMP_SLICE_POINT(); goto loc_003C450B; } /* jne: not equal / not zero */

loc_003C46D2: ;
    goto loc_003C46DD;

loc_003C46D4: ;
    edi = MEM32(edi + 0x18);
    SET_LO8(eax, MEM8(ebx + 0x12));
    MEM8(edi + 0x17) = MEM8(edi + 0x17) | LO8(eax);

loc_003C46DD: ;
    POP32(esp, esi);

loc_003C46DE: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C46E7); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C46E7: ;
    POP32(esp, edi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C46EB
 * Original: 0x003C46EB - 0x003C48D1 (486 bytes, 177 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C46EB(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    int _cf = 0; /* carry flag */

loc_003C46EB: ;
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
    if (TEST_Z(LO8(ecx), LO8(ecx))) goto loc_003C4712; /* je: equal / zero */

loc_003C470F: ;
    MEM8(ebp + -1) = MEM8(ebp + -1) - 1;

loc_003C4712: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C4851; /* je: equal / zero */

loc_003C471C: ;
    /* cmp MEM8(eax + 0x10), 0 - flags set for next jcc */
    esi = edx + 0x4C;
    if (CMP_NE(MEM8(eax + 0x10), 0)) goto loc_003C4728; /* jne: not equal / not zero */

loc_003C4725: ;
    esi = MEM32(eax + 8);

loc_003C4728: ;
    ecx = MEM32(ebp + 8);
    MEM32(ebp + -12) = MEM32(ebp + -12) & 0;
    if (CMP_BE(MEM32(ecx + 4), 0)) goto loc_003C4813; /* jbe: below or equal (unsigned <=) */

loc_003C4739: ;
    ecx = ecx + 8;
    MEM32(ebp + -8) = ecx;

loc_003C473F: ;
    /* cmp MEM8(ebp + -1), 0 - flags set for next jcc */
    _rcc0 = (CMP_EQ(MEM8(ebp + -1), 0)); /* latched */
    ecx = (uint32_t)(int32_t)SMEM8(edx + 0x14);
    MEM32(ebp + -16) = ecx;
    if (_rcc0) goto loc_003C4760; /* je: equal / zero */

loc_003C474C: ;
    edi = (uint32_t)(int32_t)SMEM8(eax + 0x11);
    ebx = (uint32_t)(int32_t)SMEM8(ebp + -1);
    edi = edi + MEM32(ebp + -12);
    if (CMP_NE(edi, ebx)) goto loc_003C4760; /* jne: not equal / not zero */

loc_003C475B: ;
    ecx++;
    ecx++;
    MEM32(ebp + -16) = ecx;

loc_003C4760: ;
    edi = MEM32(ebp + -8);
    edi = ZX16(MEM16(edi));
    ebx = edi;
    SET_LO16(ebx, LO16(ebx) & 0xF000);
    if (CMP_NE(LO16(ebx), 0x9000)) goto loc_003C47D7; /* jne: not equal / not zero */

loc_003C4774: ;
    if (TEST_Z(LO16(edi), 0xFFF)) goto loc_003C47C0; /* je: equal / zero */

loc_003C477B: ;
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
    if (TEST_Z(ecx, ecx)) goto loc_003C47D9; /* je: equal / zero */

loc_003C479D: ;
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

loc_003C47BB: ;
    eax = MEM32(ebp + 0xC);
    goto loc_003C47D9;

loc_003C47C0: ;
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
    { RECOMP_SLICE_POINT(); goto loc_003C47BB; }

loc_003C47D7: ;
    esi = esi + ecx;

loc_003C47D9: ;
    if (CMP_EQ(MEM8(ebp + -1), 0)) goto loc_003C47FD; /* je: equal / zero */

loc_003C47DF: ;
    ecx = MEM32(ebp + -8);
    SET_LO16(ecx, MEM16(ecx));
    SET_LO16(ecx, LO16(ecx) & 0xF000);
    if (CMP_NE(LO16(ecx), 0x8000)) goto loc_003C47FD; /* jne: not equal / not zero */

loc_003C47F1: ;
    SET_LO8(ecx, MEM8(ebp + -1));
    SET_LO8(ecx, LO8(ecx) - MEM8(eax + 0x11));
    SET_LO8(ecx, LO8(ecx) - MEM8(ebp + -12));
    MEM8(edx + 0x16) = MEM8(edx + 0x16) + LO8(ecx);

loc_003C47FD: ;
    MEM32(ebp + -12) = MEM32(ebp + -12) + 1;
    ecx = MEM32(ebp + 8);
    edi = MEM32(ebp + -12);
    MEM32(ebp + -8) = MEM32(ebp + -8) + 2;
    if (CMP_B(edi, MEM32(ecx + 4))) { RECOMP_SLICE_POINT(); goto loc_003C473F; } /* jb: below (unsigned <) */

loc_003C4813: ;
    if (CMP_EQ(MEM8(eax + 0x10), 0)) goto loc_003C4851; /* je: equal / zero */

loc_003C4819: ;
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
    if (CMP_EQ(MEM32(edx + 0x40), 0)) goto loc_003C4851; /* je: equal / zero */

loc_003C4836: ;
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

loc_003C4851: ;
    esi = MEM32(ebp + -20);
    ebx = 0; /* xor self */
    if (CMP_EQ(MEM32(esi + 8), ebx)) goto loc_003C4863; /* je: equal / zero */

loc_003C485B: ;
    ecx = MEM32(esi + 8);
    edi = MEM32(eax + 0xC);
    MEM32(ecx) = MEM32(ecx) + edi;

loc_003C4863: ;
    if (CMP_EQ(MEM8(eax + 0x10), 0)) goto loc_003C487D; /* je: equal / zero */

loc_003C4869: ;
    ecx = MEM32(edx + 0x40);
    if (CMP_EQ(ecx, ebx)) goto loc_003C487D; /* je: equal / zero */

loc_003C4870: ;
    if (CMP_EQ(MEM32(ecx + 8), ebx)) goto loc_003C487D; /* je: equal / zero */

loc_003C4875: ;
    ecx = MEM32(ecx + 8);
    edi = MEM32(edx + 0x48);
    MEM32(ecx) = MEM32(ecx) + edi;

loc_003C487D: ;
    ecx = ZX8(MEM8(eax + 0x13));
    SET_LO8(eax, MEM8(eax + 0x12));
    MEM8(edx + 0x17) = MEM8(edx + 0x17) | LO8(eax);
    if (CMP_EQ(ecx, ebx)) goto loc_003C48BC; /* je: equal / zero */

loc_003C488B: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    edi = ebp + -48;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    eax = MEM32(ebp + -40);
    if (TEST_Z(eax, eax)) goto loc_003C489C; /* je: equal / zero */

loc_003C489A: ;
    ebx = MEM32(eax);

loc_003C489C: ;
    PUSH32(esp, MEM32(ebp + -20));
    ecx = edx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C48A7); sub_003C4335(); /* call 0x003C4335 */

loc_003C48A7: ;
    eax = MEM32(ebp + -24);
    PUSH32(esp, 0);
    PUSH32(esp, MEM32(eax + 0x14));
    PUSH32(esp, MEM32(eax + 0x10));
    eax = ebp + -48;
    PUSH32(esp, ebx);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C48BC); sub_0036B740(); /* call 0x0036B740 */

loc_003C48BC: ;
    ecx = MEM32(ebp + -24);
    /* test MEM8(ecx + 0xB), 0x20 - flags set for next jcc */
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    if (TEST_Z(MEM8(ecx + 0xB), 0x20)) goto loc_003C48CD; /* je: equal / zero */

loc_003C48C8: ;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C48CD); sub_003C44B9(); /* call 0x003C44B9 */

loc_003C48CD: ;
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C48D1
 * Original: 0x003C48D1 - 0x003C4952 (129 bytes, 53 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C48D1(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C48D1: ;
    PUSH32(esp, ebp);
    ebp = esp;
    esp = esp - 0x18;
    PUSH32(esp, ebx);
    ebx = ecx;
    ecx = MEM32(ebx + 0x18);
    SET_LO8(edx, MEM8(ecx + 0x17));
    if (TEST_NZ(LO8(edx), 1)) goto loc_003C48F2; /* jne: not equal / not zero */

loc_003C48E5: ;
    if (CMP_EQ(MEM8(ecx + 0x2B), 0)) goto loc_003C48F2; /* je: equal / zero */

loc_003C48EB: ;
    eax = MEM32(ecx + 0x1C);
    if (TEST_NZ(eax, eax)) goto loc_003C4910; /* jne: not equal / not zero */

loc_003C48F2: ;
    if (TEST_NZ(LO8(edx), 2)) goto loc_003C4904; /* jne: not equal / not zero */

loc_003C48F7: ;
    if (CMP_EQ(MEM8(ecx + 0x3F), 0)) goto loc_003C4904; /* je: equal / zero */

loc_003C48FD: ;
    eax = MEM32(ecx + 0x30);
    if (TEST_NZ(eax, eax)) goto loc_003C4910; /* jne: not equal / not zero */

loc_003C4904: ;
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C490C); sub_003C4351(); /* call 0x003C4351 */

loc_003C490C: ;
    if (TEST_Z(eax, eax)) goto loc_003C494F; /* je: equal / zero */

loc_003C4910: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);

loc_003C4912: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    esi = eax;
    edi = ebp + -24;
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebx + 0x18);
    PUSH32(esp, eax);
    ecx = ecx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4928); sub_003C4335(); /* call 0x003C4335 */

loc_003C4928: ;
    PUSH32(esp, 0x80004004u);
    PUSH32(esp, MEM32(ebx + 0x14));
    eax = ebp + -24;
    PUSH32(esp, MEM32(ebx + 0x10));
    PUSH32(esp, 0);
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C493E); sub_0036B740(); /* call 0x0036B740 */

loc_003C493E: ;
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4949); sub_003C4351(); /* call 0x003C4351 */

loc_003C4949: ;
    if (TEST_NZ(eax, eax)) { RECOMP_SLICE_POINT(); goto loc_003C4912; } /* jne: not equal / not zero */

loc_003C494D: ;
    POP32(esp, edi);
    POP32(esp, esi);

loc_003C494F: ;
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 4; return; /* ret */

}

/**
 * sub_003C4952
 * Original: 0x003C4952 - 0x003C49E7 (149 bytes, 52 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4952(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4952: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, ecx);
    MEM32(ebp + -4) = MEM32(ebp + -4) & 0;
    PUSH32(esp, ebx);
    ebx = MEM32(ebp + 8);
    /* test MEM8(ebx + 0xB), 0x10 - flags set for next jcc */
    _rcc0 = (TEST_NZ(MEM8(ebx + 0xB), 0x10)); /* latched */
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x10);
    PUSH32(esp, edi);
    if (_rcc0) goto loc_003C496C; /* jne: not equal / not zero */

loc_003C4969: ;
    esi = MEM32(ebp + 0xC);

loc_003C496C: ;
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C4972); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4972: ;
    /* test MEM8(ebx + 0xB), 0x20 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(ebx + 0xB), 0x20)); /* latched */
    MEM8(ebp + 0xB) = LO8(eax);
    if (_rcc0) goto loc_003C49BA; /* je: equal / zero */

loc_003C497B: ;
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 0xC;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4986); sub_003C4351(); /* call 0x003C4351 */

loc_003C4986: ;
    edi = eax;
    /* test edi, edi - flags set for next jcc */
    MEM32(ebp + 0x10) = edi;
    if (TEST_Z(edi, edi)) goto loc_003C49B1; /* je: equal / zero */

loc_003C498F: ;
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4995); sub_0036B722(); /* call 0x0036B722 */

loc_003C4995: ;
    PUSH32(esp, 6);
    POP32(esp, ecx);
    PUSH32(esp, MEM32(ebp + 0x10));
    memcpy((void*)XBOX_PTR(edi), (void*)XBOX_PTR(esi), ecx * 4);
    esi += ecx * 4; edi += ecx * 4; ecx = 0; /* rep movsd */
    ecx = MEM32(ebx + 0x18);
    ecx = ecx + 4;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C49A8); sub_003C4335(); /* call 0x003C4335 */

loc_003C49A8: ;
    ecx = ebx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C49AF); sub_003C44B9(); /* call 0x003C44B9 */

loc_003C49AF: ;
    goto loc_003C49D4;

loc_003C49B1: ;
    MEM32(ebp + -4) = 0x800700AAu;
    goto loc_003C49C1;

loc_003C49BA: ;
    MEM32(ebp + -4) = 0x8007048Fu;

loc_003C49C1: ;
    PUSH32(esp, 0x80004005u);
    PUSH32(esp, MEM32(ebx + 0x14));
    PUSH32(esp, MEM32(ebx + 0x10));
    PUSH32(esp, 0);
    PUSH32(esp, esi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C49D4); sub_0036B740(); /* call 0x0036B740 */

loc_003C49D4: ;
    SET_LO8(ecx, MEM8(ebp + 0xB));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C49DD); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C49DD: ;
    eax = MEM32(ebp + -4);
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 16; return; /* ret 12 */

}

/**
 * sub_003C49E7
 * Original: 0x003C49E7 - 0x003C4BA2 (443 bytes, 143 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C49E7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C49E7: ;
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
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C49FD); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C49FD: ;
    ecx = MEM32(ebp + 8);
    /* cmp ecx, 0x3BBF74 - flags set for next jcc */
    edi = MEM32(ebp + 0xC);
    MEM8(ebp + -8) = LO8(eax);
    eax = 0x3BBF8C;
    if (CMP_EQ(ecx, 0x3BBF74)) goto loc_003C4A35; /* je: equal / zero */

loc_003C4A13: ;
    if (CMP_EQ(ecx, eax)) goto loc_003C4A35; /* je: equal / zero */

loc_003C4A17: ;
    if (CMP_NE(ecx, 0x3BBF80)) goto loc_003C4A72; /* jne: not equal / not zero */

loc_003C4A1F: ;
    if (CMP_EQ(MEM16(0x3BBF48), LO16(esi))) goto loc_003C4A3F; /* je: equal / zero */

loc_003C4A28: ;
    esi = edi;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF30B20;
    goto loc_003C4A72;

loc_003C4A35: ;
    if (CMP_NE(MEM16(0x3BBF4C), 0)) goto loc_003C4A49; /* jne: not equal / not zero */

loc_003C4A3F: ;
    esi = 0x8007000Eu;
    goto loc_003C4AF9;

loc_003C4A49: ;
    esi = edi;
    esi = (uint32_t)((int32_t)esi * (int32_t)0x1C);
    esi = esi + 0xF30AB0;
    if (CMP_NE(ecx, eax)) goto loc_003C4A6C; /* jne: not equal / not zero */

loc_003C4A58: ;
    if (TEST_NZ(MEM8(esi + 0xB), 0x80)) goto loc_003C4A68; /* jne: not equal / not zero */

loc_003C4A5E: ;
    esi = 0x8007048Fu;
    goto loc_003C4AF9;

loc_003C4A68: ;
    SET_LO8(ebx, 0xB5);
    goto loc_003C4A72;

loc_003C4A6C: ;
    if (TEST_NZ(MEM8(esi + 0xB), 0x80)) { RECOMP_SLICE_POINT(); goto loc_003C4A5E; } /* jne: not equal / not zero */

loc_003C4A72: ;
    eax = MEM32(ebp + 0x14);
    if (TEST_Z(eax, eax)) goto loc_003C4AA9; /* je: equal / zero */

loc_003C4A79: ;
    eax = MEM32(eax + 4);
    SET_LO8(ecx, 0); /* xor self */
    MEM8(ebp + -4) = LO8(ecx);

loc_003C4A81: ;
    edx = ZX8(LO8(ecx));
    edx = ZX16(MEM16(edx * 4 + 0x3BBF54));
    if (CMP_EQ(eax, edx)) goto loc_003C4A9C; /* je: equal / zero */

loc_003C4A90: ;
    SET_LO8(ecx, LO8(ecx) + 1);
    /* cmp LO8(ecx), 8 - flags set for next jcc */
    MEM8(ebp + -4) = LO8(ecx);
    if (CMP_B(LO8(ecx), 8)) { RECOMP_SLICE_POINT(); goto loc_003C4A81; } /* jb: below (unsigned <) */

loc_003C4A9A: ;
    goto loc_003C4AA9;

loc_003C4A9C: ;
    eax = 0; /* xor self */
    eax++;
    eax = eax << LO8(ecx);
    if (TEST_NZ(LO8(ebx), LO8(eax))) goto loc_003C4AA9; /* jne: not equal / not zero */

loc_003C4AA5: ;
    MEM8(ebp + -4) = 8;

loc_003C4AA9: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 2)) goto loc_003C4ABC; /* je: equal / zero */

loc_003C4AB0: ;
    esi = 0; /* xor self */
    ebx = 0x80070020u;
    goto loc_003C4B8B;

loc_003C4ABC: ;
    if (TEST_Z(LO8(eax), 1)) goto loc_003C4B6A; /* je: equal / zero */

loc_003C4AC4: ;
    if (((int8_t)(LO8(eax) & LO8(eax)) >= 0)) goto loc_003C4AD7; /* jns: not sign (positive) */

loc_003C4AC8: ;
    PUSH32(esp, MEM32(ebp + -8));
    ecx = esi;
    PUSH32(esp, MEM32(ebp + -4));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4AD5); sub_003C4121(); /* call 0x003C4121 */

loc_003C4AD5: ;
    goto loc_003C4B38;

loc_003C4AD7: ;
    SET_LO8(eax, MEM8(edi + 0xF30AAC));
    if (TEST_Z(LO8(eax), LO8(eax))) goto loc_003C4B09; /* je: equal / zero */

loc_003C4AE1: ;
    SET_LO8(eax, LO8(eax) + 1);
    MEM8(edi + 0xF30AAC) = LO8(eax);
    SET_LO8(eax, MEM8(edi + 0xF30AA8));
    if (CMP_EQ(LO8(eax), MEM8(ebp + -4))) goto loc_003C4B3E; /* je: equal / zero */

loc_003C4AF4: ;
    esi = 0x80070057u;

loc_003C4AF9: ;
    SET_LO8(ecx, MEM8(ebp + -8));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C4B02); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4B02: ;
    eax = esi;
    goto loc_003C4B9B;

loc_003C4B09: ;
    PUSH32(esp, MEM32(ebp + -8));
    SET_LO8(eax, MEM8(ebp + -4));
    PUSH32(esp, MEM32(ebp + -4));
    ecx = esi;
    MEM8(edi + 0xF30AAC) = 1;
    MEM8(edi + 0xF30AA8) = LO8(eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4B26); sub_003C4121(); /* call 0x003C4121 */

loc_003C4B26: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C4B60; /* jl: less (signed <) */

loc_003C4B2C: ;
    PUSH32(esp, MEM32(ebp + -8));
    ecx = esi;
    PUSH32(esp, 0);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4B38); sub_003C4230(); /* call 0x003C4230 */

loc_003C4B38: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C4B60; /* jl: less (signed <) */

loc_003C4B3E: ;
    eax = ZX8(MEM8(ebp + -4));
    PUSH32(esp, eax);
    PUSH32(esp, MEM32(ebp + 0x10));
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4B4D); sub_003C4367(); /* call 0x003C4367 */

loc_003C4B4D: ;
    ebx = eax;
    if (TEST_S(ebx, ebx)) goto loc_003C4B60; /* jl: less (signed <) */

loc_003C4B53: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) | 0x22;
    MEM32(esi + 0xC) = 1;
    goto loc_003C4B71;

loc_003C4B60: ;
    esi = 0; /* xor self */
    MEM8(edi + 0xF30AAC) = MEM8(edi + 0xF30AAC) - 1;
    goto loc_003C4B71;

loc_003C4B6A: ;
    esi = 0; /* xor self */
    ebx = 0x8007048Fu;

loc_003C4B71: ;
    if (TEST_Z(esi, esi)) goto loc_003C4B8B; /* je: equal / zero */

loc_003C4B75: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C4B84; /* je: equal / zero */

loc_003C4B7B: ;
    MEM16(0x3BBF4C) = MEM16(0x3BBF4C) - 1;
    goto loc_003C4B8B;

loc_003C4B84: ;
    MEM16(0x3BBF48) = MEM16(0x3BBF48) - 1;

loc_003C4B8B: ;
    SET_LO8(ecx, MEM8(ebp + -8));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C4B94); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4B94: ;
    eax = MEM32(ebp + 0x18);
    MEM32(eax) = esi;
    eax = ebx;

loc_003C4B9B: ;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp = ebp;
    POP32(esp, ebp); /* leave */
    esp += 24; return; /* ret 20 */

}

/**
 * sub_003C4BA2
 * Original: 0x003C4BA2 - 0x003C4C1E (124 bytes, 43 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4BA2(void)
{
    int _rcc0 = 0; /* flag reads latched at their setter */
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C4BA2: ;
    PUSH32(esp, esi);
    esi = MEM32(esp + 0xC);
    eax = MEM32(esi + 0x18);
    PUSH32(esp, edi);
    edi = 0; /* xor self */
    MEM32(eax + 0x37C) = edi;
    /* test MEM8(esi + 0xB), 0x10 - flags set for next jcc */
    _rcc0 = (TEST_Z(MEM8(esi + 0xB), 0x10)); /* latched */
    PUSH32(esp, 0x1C);
    eax = esi;
    POP32(esp, ecx);
    if (_rcc0) goto loc_003C4BC5; /* je: equal / zero */

loc_003C4BBE: ;
    eax = eax - 0xF30AB0;
    goto loc_003C4BCA;

loc_003C4BC5: ;
    eax = eax - 0xF30B20;

loc_003C4BCA: ;
    edx = ((int32_t)eax < 0) ? 0xFFFFFFFF : 0; /* cdq */
    { int64_t _dividend = ((int64_t)(int32_t)edx << 32) | eax;
      eax = (uint32_t)((int32_t)(_dividend / (int32_t)ecx));
      edx = (uint32_t)((int32_t)(_dividend % (int32_t)ecx)); }
    ecx = esi;
    MEM8(eax + 0xF30AAC) = MEM8(eax + 0xF30AAC) - 1;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4BDA); sub_003C48D1(); /* call 0x003C48D1 */

loc_003C4BDA: ;
    if (TEST_Z(MEM8(esi + 0xB), 8)) goto loc_003C4BF8; /* je: equal / zero */

loc_003C4BE0: ;
    ecx = MEM32(esi + 4);
    PUSH32(esp, edi);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4BE9); sub_003BF69C(); /* call 0x003BF69C */

loc_003C4BE9: ;
    ecx = MEM32(esi + 4);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4BF1); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C4BF1: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;
    MEM32(esi + 4) = edi;

loc_003C4BF8: ;
    SET_LO8(eax, MEM8(esi + 0xB));
    if (TEST_Z(LO8(eax), 4)) goto loc_003C4C15; /* je: equal / zero */

loc_003C4BFF: ;
    SET_LO8(eax, LO8(eax) & 0xF9);
    MEM8(esi + 0xB) = LO8(eax);
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD0); g_seh_ebp = ebp; PUSH32(esp, 0x3C4C15); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4C15: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xBF;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 12; return; /* ret 8 */

}

/**
 * sub_003C4C1E
 * Original: 0x003C4C1E - 0x003C4C4E (48 bytes, 20 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4C1E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4C1E: ;
    PUSH32(esp, ebp);
    ebp = esp;
    PUSH32(esp, esi);
    esi = MEM32(ebp + 0x20);
    PUSH32(esp, esi);
    PUSH32(esp, MEM32(ebp + 0x14));
    PUSH32(esp, MEM32(ebp + 0x10));
    PUSH32(esp, MEM32(ebp + 0xC));
    PUSH32(esp, MEM32(ebp + 8));
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4C37); sub_003C49E7(); /* call 0x003C49E7 */

loc_003C4C37: ;
    if (TEST_S(eax, eax)) goto loc_003C4C49; /* jl: less (signed <) */

loc_003C4C3B: ;
    ecx = MEM32(esi);
    edx = MEM32(ebp + 0x1C);
    MEM32(ecx + 0x14) = edx;
    edx = MEM32(ebp + 0x18);
    MEM32(ecx + 0x10) = edx;

loc_003C4C49: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 32; return; /* ret 28 */

}

/**
 * sub_003C4C4E
 * Original: 0x003C4C4E - 0x003C4CA9 (91 bytes, 23 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4C4E(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C4C4E: ;
    MEM8(ecx + 0xB) = MEM8(ecx + 0xB) & 0xDF;
    SET_LO8(eax, MEM8(ecx + 0xB));
    if (TEST_NZ(LO8(eax), 0x40)) goto loc_003C4CA8; /* jne: not equal / not zero */

loc_003C4C59: ;
    SET_LO8(eax, LO8(eax) | 0x40);
    MEM8(ecx + 0xB) = LO8(eax);
    eax = MEM32(ecx + 0x18);
    MEM8(eax + 0x360) = 0x1C;
    eax = MEM32(ecx + 0x18);
    MEM8(eax + 0x361) = 0x4A;
    eax = MEM32(ecx + 0x18);
    MEM32(eax + 0x368) = 0x3C4BA2;
    eax = MEM32(ecx + 0x18);
    MEM32(eax + 0x36C) = ecx;
    eax = MEM32(ecx + 0x18);
    edx = MEM32(eax + 0x37C);
    MEM32(eax + 0x370) = edx;
    eax = MEM32(ecx + 0x18);
    ecx = MEM32(ecx + 4);
    eax = eax + 0x360;
    PUSH32(esp, eax);
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4CA8); sub_003BFA4D(); /* call 0x003BFA4D */

loc_003C4CA8: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C4CA9
 * Original: 0x003C4CA9 - 0x003C4D70 (199 bytes, 58 insns)
 * Category: game_input
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4CA9(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C4CA9: ;
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, ebx);
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    esi = ecx;
    { uint32_t _icall_t = MEM32(0x3C4FC8); g_seh_ebp = ebp; PUSH32(esp, 0x3C4CB4); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4CB4: ;
    SET_LO8(ebx, LO8(eax));
    eax = MEM32(esi + 0x18);
    edi = 0; /* xor self */
    if (CMP_EQ(MEM32(eax + 0x37C), edi)) goto loc_003C4D29; /* je: equal / zero */

loc_003C4CC3: ;
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
    if (TEST_NZ(MEM8(esi + 0xB), 8)) goto loc_003C4D0C; /* jne: not equal / not zero */

loc_003C4D05: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4D0C); sub_003C4C4E(); /* call 0x003C4C4E */

loc_003C4D0C: ;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C4D14); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4D14: ;
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    PUSH32(esp, edi);
    eax = eax + 0x350;
    PUSH32(esp, eax);
    { uint32_t _icall_t = MEM32(0x3C4FD4); g_seh_ebp = ebp; PUSH32(esp, 0x3C4D27); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4D27: ;
    goto loc_003C4D35;

loc_003C4D29: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xFD;
    SET_LO8(ecx, LO8(ebx));
    { uint32_t _icall_esp = g_esp;
    { uint32_t _icall_t = MEM32(0x3C4FC4); g_seh_ebp = ebp; PUSH32(esp, 0x3C4D35); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4D35: ;
    if (TEST_Z(MEM8(esi + 0xB), 0x10)) goto loc_003C4D44; /* je: equal / zero */

loc_003C4D3B: ;
    MEM16(0x3BBF4C) = MEM16(0x3BBF4C) + 1;
    goto loc_003C4D4B;

loc_003C4D44: ;
    MEM16(0x3BBF48) = MEM16(0x3BBF48) + 1;

loc_003C4D4B: ;
    eax = MEM32(esi + 0x18);
    { uint32_t _icall_esp = g_esp;
    PUSH32(esp, MEM32(eax));
    { uint32_t _icall_t = MEM32(0x3C5018); g_seh_ebp = ebp; PUSH32(esp, 0x3C4D56); RECOMP_ICALL_SAFE(_icall_t, _icall_esp); } /* indirect call */
    }

loc_003C4D56: ;
    eax = MEM32(esi + 0x18);
    ecx = MEM32(0x3BBF50);
    MEM32(eax) = ecx;
    eax = MEM32(esi + 0x18);
    MEM32(0x3BBF50) = eax;
    MEM32(esi + 0x18) = edi;
    POP32(esp, edi);
    POP32(esp, esi);
    POP32(esp, ebx);
    esp += 4; return; /* ret */

}

/**
 * sub_003C4D70
 * Original: 0x003C4D70 - 0x003C4DB7 (71 bytes, 27 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4D70(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C4D70: ;
    PUSH32(esp, esi);
    PUSH32(esp, edi);
    edi = MEM32(esp + 0xC);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4D7D); sub_003BF698(); /* call 0x003BF698 */

loc_003C4D7D: ;
    esi = eax;
    SET_LO8(eax, MEM8(esi + 0xB));
    SET_LO8(eax, LO8(eax) & 0xFE);
    SET_LO8(eax, LO8(eax) | 8);
    /* test LO8(eax), 0x20 - flags set for next jcc */
    MEM8(esi + 0xB) = LO8(eax);
    if (TEST_Z(LO8(eax), 0x20)) goto loc_003C4D96; /* je: equal / zero */

loc_003C4D8D: ;
    ecx = esi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4D94); sub_003C4C4E(); /* call 0x003C4C4E */

loc_003C4D94: ;
    goto loc_003C4DB2;

loc_003C4D96: ;
    if (TEST_NZ(LO8(eax), 4)) goto loc_003C4DB2; /* jne: not equal / not zero */

loc_003C4D9A: ;
    MEM32(esi + 4) = MEM32(esi + 4) & 0;
    PUSH32(esp, 0);
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4DA7); sub_003BF69C(); /* call 0x003BF69C */

loc_003C4DA7: ;
    ecx = edi;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4DAE); sub_003BDE87(); /* call 0x003BDE87 */

loc_003C4DAE: ;
    MEM8(esi + 0xB) = MEM8(esi + 0xB) & 0xF7;

loc_003C4DB2: ;
    POP32(esp, edi);
    POP32(esp, esi);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C4DB7
 * Original: 0x003C4DB7 - 0x003C4DEA (51 bytes, 22 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4DB7(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */

loc_003C4DB7: ;
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
    if (CMP_GE(esi & esi, 0)) goto loc_003C4DDA; /* jge: greater or equal (signed >=) */

loc_003C4DD6: ;
    eax = 0; /* xor self */
    goto loc_003C4DE5;

loc_003C4DDA: ;
    if (TEST_NZ(esi, esi)) goto loc_003C4DE3; /* jne: not equal / not zero */

loc_003C4DDC: ;
    ecx = edx;
    g_seh_ebp = ebp; PUSH32(esp, 0x3C4DE3); sub_003C4CA9(); /* call 0x003C4CA9 */

loc_003C4DE3: ;
    eax = esi;

loc_003C4DE5: ;
    POP32(esp, esi);
    POP32(esp, ebp);
    esp += 8; return; /* ret 4 */

}

/**
 * sub_003C4DEA
 * Original: 0x003C4DEA - 0x003C4E1A (48 bytes, 17 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4DEA(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C4DEA: ;
    PUSH32(esp, 4);
    eax = 0xF30AB8;
    POP32(esp, edx);
    ecx = 0; /* xor self */

loc_003C4DF4: ;
    MEM32(eax + -8) = 0x4720AC;
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
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C4DF4; } /* jne: not equal / not zero */

loc_003C4E19: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C4E1A
 * Original: 0x003C4E1A - 0x003C4E4C (50 bytes, 19 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4E1A(void)
{
    int _flags = 0; /* fallback flag var */

loc_003C4E1A: ;
    PUSH32(esp, 4);
    eax = 0xF30B28;
    POP32(esp, edx);
    ecx = 0; /* xor self */

loc_003C4E24: ;
    MEM32(eax + -8) = 0x4720AC;
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
    if ((edx != 0)) { RECOMP_SLICE_POINT(); goto loc_003C4E24; } /* jne: not equal / not zero */

loc_003C4E49: ;
    esp += 4; return; /* ret */

}

/**
 * sub_003C4E4C
 * Original: 0x003C4E4C - 0x003C4E8B (63 bytes, 36 insns)
 * CC: cdecl, 0 params, returns int_or_void
 * Frame: fpo_leaf
 */
void sub_003C4E4C(void)
{
    uint32_t ebp;
    int _flags = 0; /* fallback flag var */
    ebp = g_seh_ebp; /* fpo_leaf: inherit caller's frame */

loc_003C4E4C: ;
    POP32(esp, esp);
    esp++;
    if (_flags /* jbe: below or equal (unsigned <=) */) { g_seh_ebp = ebp; sub_003C4EBA(); return; }

loc_003C4E51: ;
    /* TODO: arpl word ptr [ebp + 0x5c], sp */
    ebp--;
    PUSH32(esp, ebp);
    POP32(esp, edi);
    MEM8(eax) = MEM8(eax) ^ LO8(eax);
    MEM8(eax) = MEM8(eax) + LO8(eax);
    MEM8(esp + eax * 2 + 0x65) = MEM8(esp + eax * 2 + 0x65) + LO8(ebx);
    if (_flags /* jbe: below or equal (unsigned <=) */) { g_seh_ebp = ebp; sub_003C4ECA(); return; }

loc_003C4E61: ;
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
