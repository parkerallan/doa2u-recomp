/* NV2A fixed-function vertex path on the GPU.
 *
 * The pgraph translator used to transform, light and near-clip every array
 * vertex on the CPU and hand the D3D8 layer screen-space XYZRHW. This path
 * takes the packed object-space vertices instead, with the per-draw constants
 * the CPU math used, and a dedicated vertex shader does the same arithmetic:
 *   clip = Clip * pos          (composite x viewport origin x window fit x z range,
 *                               folded into one matrix by the translator)
 *   colour = vertex colour | NV2A fixed-function lighting | ambient+emission | white
 *   clip distances = (w - 0.01, z)   -- the two planes the CPU clipper used
 */
#ifndef D3D8_NV2AFF_H
#define D3D8_NV2AFF_H

#include <stdint.h>

/* One packed vertex: 40 bytes. */
typedef struct {
    float    pos[4];
    float    nrm[3];
    uint32_t color;      /* D3DCOLOR (A8R8G8B8) */
    float    uv[2];
} Nv2aFFVertex;

#define NV2AFF_FLAG_LIT          0x01u
#define NV2AFF_FLAG_AMBIENT_ONLY 0x02u
#define NV2AFF_FLAG_HAS_COLOR    0x04u
#define NV2AFF_FLAG_FOLD         0x08u   /* multiply the colour by `fold` (combiner factor) */

/* Constant buffer, HLSL float4-packed. Keep in step with the shader. */
typedef struct {
    float    clip[4][4];      /* row i: coefficients of clip component i */
    float    mv[3][4];        /* model-view rows (xyz coefficients + translation) */
    float    light_dir[4][4]; /* xyz: normalised direction (type 1) or eye-space position; w: type 0/1/2 */
    float    light_amb[4][4];
    float    light_dif[4][4];
    float    light_att[4][4]; /* a0, a1, a2, range */
    float    ambemis[4];      /* scene ambient + emission; w = material alpha */
    float    fold[4];         /* combiner factor r,g,b,a in 0..255 */
    uint32_t flags;
    uint32_t pad[3];
} Nv2aFFConstants;

/* d3d8_device.c: upload, bind and draw. `topology` is a D3D11_PRIMITIVE_TOPOLOGY. */
long d3d8_DrawNv2aFF(const Nv2aFFVertex *verts, unsigned nverts,
                     const uint16_t *idx, unsigned nidx, int topology,
                     const Nv2aFFConstants *cb);

/* d3d8_shaders.c: compile once; bind VS + layout + constants for one draw. */
long d3d8_Nv2aFF_Init(void);
void d3d8_Nv2aFF_Shutdown(void);
int  d3d8_Nv2aFF_Bind(const Nv2aFFConstants *cb);

#endif
