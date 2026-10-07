/*
 * NV2A vertex program (VP1.1) capture + CPU interpreter.
 *
 * Instruction encoding: 4 dwords per instruction. Each instruction may issue
 * one MAC (multiply/accumulate) op and one ILU (inverse logic unit) op, each
 * with its own write mask, plus at most one write to an output register. The
 * three source operands A, B and C each carry a register index, a source
 * select (temp / input / constant), a 4x2-bit swizzle and a negate bit.
 *
 * Field positions below follow the hardware layout; dword 0 carries no fields
 * we need. The operand-to-op mapping is not uniform and is easy to get wrong:
 * MUL reads A and B, ADD reads A and C, MAD reads A, B and C, and every ILU op
 * reads C.
 */

#include "nv2a_vertex_program.h"

#include <string.h>
#include <math.h>
#include <stdio.h>

/* ── MAC opcodes ── */
enum {
    MAC_NOP = 0, MAC_MOV, MAC_MUL, MAC_ADD, MAC_MAD, MAC_DP3, MAC_DPH,
    MAC_DP4, MAC_DST, MAC_MIN, MAC_MAX, MAC_SLT, MAC_SGE, MAC_ARL
};

/* ── ILU opcodes ── */
enum {
    ILU_NOP = 0, ILU_MOV, ILU_RCP, ILU_RCC, ILU_RSQ, ILU_EXP, ILU_LOG, ILU_LIT
};

/* ── operand source select ── */
enum { PARAM_UNKNOWN = 0, PARAM_R, PARAM_V, PARAM_C };

/* ── output destination select ── */
enum { OUTPUT_C = 0, OUTPUT_O };
enum { OMUX_MAC = 0, OMUX_ILU };

static uint32_t fld(const uint32_t t[4], int w, int b, int n)
{
    return (t[w] >> b) & ((n >= 32) ? 0xFFFFFFFFu : ((1u << n) - 1u));
}

static float u2fv(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

void nv2a_vp_reset(Nv2aVertexProgram *vp)
{
    memset(vp, 0, sizeof(*vp));
}

void nv2a_vp_write_program(Nv2aVertexProgram *vp, uint32_t slot, uint32_t param)
{
    uint32_t idx = vp->prog_ld_ptr;
    if (idx < NV2A_VP_MAX_INSTR) {
        vp->instr[idx][slot % 4] = param;
        if (idx + 1 > vp->instr_count)
            vp->instr_count = idx + 1;
        vp->have_program = 1;
    }
    if ((slot % 4) == 3)
        vp->prog_ld_ptr = idx + 1;
}

void nv2a_vp_write_constant(Nv2aVertexProgram *vp, uint32_t slot, uint32_t param)
{
    uint32_t idx = vp->const_ld_ptr;
    if (idx < NV2A_VP_NUM_CONST)
        vp->consts[idx][slot % 4] = u2fv(param);
    if ((slot % 4) == 3)
        vp->const_ld_ptr = idx + 1;
}

/* Fetch one swizzled/negated source operand. */
static void fetch(float dst[4], int mux, int r_idx, int v_idx, int c_idx,
                  const float R[16][4],
                  const float in[NV2A_VP_NUM_INPUT][4],
                  const float consts[NV2A_VP_NUM_CONST][4],
                  int sx, int sy, int sz, int sw, int neg)
{
    static const float zero[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    const float *src = zero;

    switch (mux) {
    case PARAM_R: src = R[r_idx & 15]; break;
    case PARAM_V: src = in[v_idx & 15]; break;
    case PARAM_C:
        if (c_idx >= 0 && c_idx < NV2A_VP_NUM_CONST) src = consts[c_idx];
        break;
    default: break;
    }

    dst[0] = src[sx]; dst[1] = src[sy]; dst[2] = src[sz]; dst[3] = src[sw];
    if (neg) { dst[0] = -dst[0]; dst[1] = -dst[1]; dst[2] = -dst[2]; dst[3] = -dst[3]; }
}

static void write_masked(float dst[4], const float src[4], int mask)
{
    /* Mask bits are x,y,z,w from the high bit down. */
    if (mask & 8) dst[0] = src[0];
    if (mask & 4) dst[1] = src[1];
    if (mask & 2) dst[2] = src[2];
    if (mask & 1) dst[3] = src[3];
}

static void splat(float dst[4], float v)
{
    dst[0] = dst[1] = dst[2] = dst[3] = v;
}

static float safe_rcp(float v)
{
    if (v == 0.0f) return 1.0e30f;
    return 1.0f / v;
}

int nv2a_vp_execute(const Nv2aVertexProgram *vp,
                    const float in[NV2A_VP_NUM_INPUT][4],
                    float out[NV2A_VP_NUM_OUTPUT][4])
{
    float R[16][4];
    int a0 = 0;
    uint32_t pc;
    int steps;

    if (!vp->have_program || vp->instr_count == 0)
        return 0;

    memset(R, 0, sizeof(R));
    memset(out, 0, sizeof(float) * NV2A_VP_NUM_OUTPUT * 4);
    /* Colours default to opaque white so a program that only writes position
     * still produces visible geometry rather than fully transparent black. */
    out[NV2A_VP_OUT_D0][0] = out[NV2A_VP_OUT_D0][1] =
    out[NV2A_VP_OUT_D0][2] = out[NV2A_VP_OUT_D0][3] = 1.0f;
    out[NV2A_VP_OUT_POS][3] = 1.0f;

    pc = vp->start;
    for (steps = 0; steps < NV2A_VP_MAX_INSTR * 2; steps++) {
        const uint32_t *t;
        int ilu, mac, c_base, v_idx, c_idx;
        int a_neg, a_sx, a_sy, a_sz, a_sw, a_r, a_mux;
        int b_neg, b_sx, b_sy, b_sz, b_sw, b_r, b_mux;
        int c_neg, c_sx, c_sy, c_sz, c_sw, c_r, c_mux;
        int mac_mask, out_r, ilu_mask, o_mask, orb, oaddr, omux, a0x, final;
        float A[4], B[4], C[4], res[4];

        if (pc >= vp->instr_count || pc >= NV2A_VP_MAX_INSTR)
            break;
        t = vp->instr[pc];

        ilu    = (int)fld(t, 1, 25, 3);
        mac    = (int)fld(t, 1, 21, 4);
        c_base = (int)fld(t, 1, 13, 8);
        v_idx  = (int)fld(t, 1,  9, 4);

        a_neg = (int)fld(t, 1, 8, 1);
        a_sx  = (int)fld(t, 1, 6, 2); a_sy = (int)fld(t, 1, 4, 2);
        a_sz  = (int)fld(t, 1, 2, 2); a_sw = (int)fld(t, 1, 0, 2);
        a_r   = (int)fld(t, 2, 28, 4); a_mux = (int)fld(t, 2, 26, 2);

        b_neg = (int)fld(t, 2, 25, 1);
        b_sx  = (int)fld(t, 2, 23, 2); b_sy = (int)fld(t, 2, 21, 2);
        b_sz  = (int)fld(t, 2, 19, 2); b_sw = (int)fld(t, 2, 17, 2);
        b_r   = (int)fld(t, 2, 13, 4); b_mux = (int)fld(t, 2, 11, 2);

        c_neg = (int)fld(t, 2, 10, 1);
        c_sx  = (int)fld(t, 2, 8, 2); c_sy = (int)fld(t, 2, 6, 2);
        c_sz  = (int)fld(t, 2, 4, 2); c_sw = (int)fld(t, 2, 2, 2);
        c_r   = (int)((fld(t, 2, 0, 2) << 2) | fld(t, 3, 30, 2));
        c_mux = (int)fld(t, 3, 28, 2);

        mac_mask = (int)fld(t, 3, 24, 4);
        out_r    = (int)fld(t, 3, 20, 4);
        ilu_mask = (int)fld(t, 3, 16, 4);
        o_mask   = (int)fld(t, 3, 12, 4);
        orb      = (int)fld(t, 3, 11, 1);
        oaddr    = (int)fld(t, 3,  3, 8);
        omux     = (int)fld(t, 3,  2, 1);
        a0x      = (int)fld(t, 3,  1, 1);
        final    = (int)fld(t, 3,  0, 1);

        c_idx = c_base + (a0x ? a0 : 0);

        fetch(A, a_mux, a_r, v_idx, c_idx, R, in, vp->consts,
              a_sx, a_sy, a_sz, a_sw, a_neg);
        fetch(B, b_mux, b_r, v_idx, c_idx, R, in, vp->consts,
              b_sx, b_sy, b_sz, b_sw, b_neg);
        fetch(C, c_mux, c_r, v_idx, c_idx, R, in, vp->consts,
              c_sx, c_sy, c_sz, c_sw, c_neg);

        if (mac != MAC_NOP) {
            switch (mac) {
            case MAC_MOV:
                res[0] = A[0]; res[1] = A[1]; res[2] = A[2]; res[3] = A[3];
                break;
            case MAC_MUL:
                res[0] = A[0]*B[0]; res[1] = A[1]*B[1];
                res[2] = A[2]*B[2]; res[3] = A[3]*B[3];
                break;
            case MAC_ADD:   /* A + C, not A + B */
                res[0] = A[0]+C[0]; res[1] = A[1]+C[1];
                res[2] = A[2]+C[2]; res[3] = A[3]+C[3];
                break;
            case MAC_MAD:
                res[0] = A[0]*B[0]+C[0]; res[1] = A[1]*B[1]+C[1];
                res[2] = A[2]*B[2]+C[2]; res[3] = A[3]*B[3]+C[3];
                break;
            case MAC_DP3:
                splat(res, A[0]*B[0] + A[1]*B[1] + A[2]*B[2]);
                break;
            case MAC_DPH:
                splat(res, A[0]*B[0] + A[1]*B[1] + A[2]*B[2] + B[3]);
                break;
            case MAC_DP4:
                splat(res, A[0]*B[0] + A[1]*B[1] + A[2]*B[2] + A[3]*B[3]);
                break;
            case MAC_DST:
                res[0] = 1.0f; res[1] = A[1]*B[1]; res[2] = A[2]; res[3] = B[3];
                break;
            case MAC_MIN:
                res[0] = A[0]<B[0]?A[0]:B[0]; res[1] = A[1]<B[1]?A[1]:B[1];
                res[2] = A[2]<B[2]?A[2]:B[2]; res[3] = A[3]<B[3]?A[3]:B[3];
                break;
            case MAC_MAX:
                res[0] = A[0]>B[0]?A[0]:B[0]; res[1] = A[1]>B[1]?A[1]:B[1];
                res[2] = A[2]>B[2]?A[2]:B[2]; res[3] = A[3]>B[3]?A[3]:B[3];
                break;
            case MAC_SLT:
                res[0] = A[0]<B[0]?1.0f:0.0f; res[1] = A[1]<B[1]?1.0f:0.0f;
                res[2] = A[2]<B[2]?1.0f:0.0f; res[3] = A[3]<B[3]?1.0f:0.0f;
                break;
            case MAC_SGE:
                res[0] = A[0]>=B[0]?1.0f:0.0f; res[1] = A[1]>=B[1]?1.0f:0.0f;
                res[2] = A[2]>=B[2]?1.0f:0.0f; res[3] = A[3]>=B[3]?1.0f:0.0f;
                break;
            case MAC_ARL:
                a0 = (int)floorf(A[0]);
                res[0] = res[1] = res[2] = res[3] = 0.0f;
                break;
            default:
                res[0] = res[1] = res[2] = res[3] = 0.0f;
                break;
            }

            if (mac != MAC_ARL) {
                if (omux == OMUX_MAC && o_mask && orb == OUTPUT_O &&
                    oaddr < NV2A_VP_NUM_OUTPUT)
                    write_masked(out[oaddr], res, o_mask);
                if (mac_mask)
                    write_masked(R[out_r & 15], res, mac_mask);
            }
        }

        if (ilu != ILU_NOP) {
            float s = C[0];
            switch (ilu) {
            case ILU_MOV:
                res[0] = C[0]; res[1] = C[1]; res[2] = C[2]; res[3] = C[3];
                break;
            case ILU_RCP: splat(res, safe_rcp(s)); break;
            case ILU_RCC: {
                float r = safe_rcp(s);
                /* Clamped reciprocal: keep the magnitude inside the hardware's
                 * representable window, preserving sign. */
                if (r >= 0.0f) { if (r < 5.42101086e-20f) r = 5.42101086e-20f;
                                 if (r > 1.884467e+19f)   r = 1.884467e+19f; }
                else           { if (r > -5.42101086e-20f) r = -5.42101086e-20f;
                                 if (r < -1.884467e+19f)   r = -1.884467e+19f; }
                splat(res, r);
                break;
            }
            case ILU_RSQ: {
                float a = fabsf(s);
                splat(res, a == 0.0f ? 1.0e30f : 1.0f / sqrtf(a));
                break;
            }
            case ILU_EXP: splat(res, powf(2.0f, s)); break;
            case ILU_LOG: splat(res, s == 0.0f ? -1.0e30f : log2f(fabsf(s))); break;
            case ILU_LIT: {
                /* C = (diffuse, specular, -, power) */
                float d = C[0], sp = C[1], p = C[3];
                if (p < -127.9961f) p = -127.9961f;
                if (p >  127.9961f) p =  127.9961f;
                res[0] = 1.0f;
                res[1] = d > 0.0f ? d : 0.0f;
                res[2] = (d > 0.0f && sp > 0.0f) ? powf(sp, p) : 0.0f;
                res[3] = 1.0f;
                break;
            }
            default:
                res[0] = res[1] = res[2] = res[3] = 0.0f;
                break;
            }

            if (omux == OMUX_ILU && o_mask && orb == OUTPUT_O &&
                oaddr < NV2A_VP_NUM_OUTPUT)
                write_masked(out[oaddr], res, o_mask);
            if (ilu_mask) {
                /* When the instruction also issues a MAC op, the MAC owns the
                 * named temp and the ILU result is forced to R1. */
                int dst = (mac != MAC_NOP) ? 1 : (out_r & 15);
                write_masked(R[dst], res, ilu_mask);
            }
        }

        /* R12 is a mirror of oPos (xemu: "#define R12 oPos"). The XDK's
         * viewport epilogue reads the clip position back through R12 after the
         * game's own code wrote o[0]; without the mirror it saw zeros and the
         * pond's water surface collapsed onto one point. */
        {   int wrote_o0 = (o_mask && orb == OUTPUT_O && oaddr == 0);
            int wrote_r12 = (mac != MAC_NOP && mac != MAC_ARL && mac_mask && (out_r & 15) == 12) ||
                            (ilu != ILU_NOP && ilu_mask && ((mac != MAC_NOP) ? 1 : (out_r & 15)) == 12);
            if (wrote_o0) memcpy(R[12], out[NV2A_VP_OUT_POS], sizeof(float) * 4);
            else if (wrote_r12) memcpy(out[NV2A_VP_OUT_POS], R[12], sizeof(float) * 4);
        }

        if (final)
            break;
        pc++;
    }

    return 1;
}

void nv2a_vp_dump(const Nv2aVertexProgram *vp)
{
    static const char *mac_name[] = {
        "nop","mov","mul","add","mad","dp3","dph","dp4",
        "dst","min","max","slt","sge","arl","?","?"
    };
    static const char *ilu_name[] = {
        "nop","mov","rcp","rcc","rsq","exp","log","lit"
    };
    uint32_t i;

    fprintf(stderr, "[VP] start=%u count=%u\n", vp->start, vp->instr_count);
    for (i = vp->start; i < vp->instr_count && i < NV2A_VP_MAX_INSTR; i++) {
        const uint32_t *t = vp->instr[i];
        int mac = (int)fld(t, 1, 21, 4);
        int ilu = (int)fld(t, 1, 25, 3);
        fprintf(stderr, "  [%3u] %-3s %-3s  cst=%-3u v=%-2u out=%s%u omask=%X "
                        "macmask=%X R%u %s\n",
                i, mac_name[mac & 15], ilu_name[ilu & 7],
                (unsigned)fld(t, 1, 13, 8), (unsigned)fld(t, 1, 9, 4),
                fld(t, 3, 11, 1) ? "o" : "c", (unsigned)fld(t, 3, 3, 8),
                (unsigned)fld(t, 3, 12, 4), (unsigned)fld(t, 3, 24, 4),
                (unsigned)fld(t, 3, 20, 4),
                fld(t, 3, 0, 1) ? "FINAL" : "");
    }
    fflush(stderr);
}
