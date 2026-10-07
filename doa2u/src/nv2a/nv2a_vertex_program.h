/*
 * NV2A vertex program (transform program) capture and execution.
 *
 * The pgraph translator was originally written against a title that only ever
 * used the fixed-function pipeline with pre-transformed, screen-space inline
 * vertices, so it read attribute 0 as literal pixel coordinates. DOA3 draws its
 * 3D screens in MODE_PROGRAM: attribute 0 is an object-space position that only
 * becomes screen space after the uploaded vertex program runs. Without this the
 * geometry is submitted with meaningless coordinates and nothing is visible.
 *
 * This implements the NV2A "VP1.1" transform program: capture through the
 * pushbuffer methods, and a CPU interpreter that produces the output registers
 * for one vertex. Running it on the CPU (rather than translating to HLSL) keeps
 * the existing D3D8 fixed-function draw path intact -- we simply hand it the
 * post-transform vertices it already knows how to draw.
 */
#ifndef NV2A_VERTEX_PROGRAM_H
#define NV2A_VERTEX_PROGRAM_H

#include <stdint.h>

#define NV2A_VP_MAX_INSTR   136   /* transform program slots */
#define NV2A_VP_NUM_CONST   192   /* c[0..191]; D3D c0 is uploaded at index 96 */
#define NV2A_VP_NUM_INPUT   16    /* v0..v15 */
#define NV2A_VP_NUM_OUTPUT  13    /* see the o[] map below */

/* Output register indices, matching the Xbox vertex shader o[] numbering.
 * (These are the same indices the FVF attribute slots use: 0 position,
 * 3 diffuse, 9 texcoord0 -- which is why the D3D wrapper keys on 3 and 9.) */
enum {
    NV2A_VP_OUT_POS  = 0,
    NV2A_VP_OUT_D0   = 3,   /* diffuse  */
    NV2A_VP_OUT_D1   = 4,   /* specular */
    NV2A_VP_OUT_FOG  = 5,
    NV2A_VP_OUT_PTS  = 6,
    NV2A_VP_OUT_B0   = 7,
    NV2A_VP_OUT_B1   = 8,
    NV2A_VP_OUT_T0   = 9,
    NV2A_VP_OUT_T1   = 10,
    NV2A_VP_OUT_T2   = 11,
    NV2A_VP_OUT_T3   = 12
};

typedef struct {
    uint32_t instr[NV2A_VP_MAX_INSTR][4];
    float    consts[NV2A_VP_NUM_CONST][4];

    uint32_t prog_ld_ptr;    /* NV097_SET_TRANSFORM_PROGRAM_LOAD  */
    uint32_t const_ld_ptr;   /* NV097_SET_TRANSFORM_CONSTANT_LOAD */
    uint32_t start;          /* NV097_SET_TRANSFORM_PROGRAM_START */
    uint32_t instr_count;    /* highest instruction slot written + 1 */
    int      have_program;   /* at least one instruction uploaded */
} Nv2aVertexProgram;

void nv2a_vp_reset(Nv2aVertexProgram *vp);

/* `slot` is (method - NV097_SET_TRANSFORM_PROGRAM) / 4 for program writes and
 * (method - NV097_SET_TRANSFORM_CONSTANT) / 4 for constant writes; the load
 * pointer advances every fourth dword, exactly as the hardware does. */
void nv2a_vp_write_program(Nv2aVertexProgram *vp, uint32_t slot, uint32_t param);
void nv2a_vp_write_constant(Nv2aVertexProgram *vp, uint32_t slot, uint32_t param);

/* Execute the program for one vertex.
 * `in` holds v0..v15, `out` receives the output registers.
 * Returns 0 when there is no usable program. */
int nv2a_vp_execute(const Nv2aVertexProgram *vp,
                    const float in[NV2A_VP_NUM_INPUT][4],
                    float out[NV2A_VP_NUM_OUTPUT][4]);

/* One-shot disassembly of the loaded program, for diagnostics. */
void nv2a_vp_dump(const Nv2aVertexProgram *vp);

#endif /* NV2A_VERTEX_PROGRAM_H */
