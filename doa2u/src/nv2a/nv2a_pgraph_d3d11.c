/*
 * NV2A PGRAPH → D3D11 Translator
 *
 * Translates NV2A push buffer methods into D3D8→D3D11 rendering calls.
 * Designed for Xbox static recompilation (xboxrecomp toolkit).
 *
 * Menu rendering profile (captured from xemu):
 *   - INLINE_ARRAY with 5-dword vertices (X, Y, U, V, Color)
 *   - TRIANGLE_STRIP topology
 *   - ~448 vertices per frame (~89 quads)
 *   - Textured 2D elements in 640×480 screen space
 */

#include "nv2a_pgraph_d3d11.h"
#include "nv2a_regs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

/* D3D8 device — we include the full header for COM vtable access */
#include "../d3d/d3d8_xbox.h"
#include "../d3d/d3d8_swizzle.h"
#include "nv2a_vertex_program.h"
#include "../d3d/d3d8_nv2aff.h"
extern IDirect3DDevice8 *xbox_GetD3DDevice(void);

/* Global.txd texture lookup */
typedef struct { char name[24]; IDirect3DTexture8 *texture; uint32_t width, height, format; } TXD_Entry;
typedef struct { TXD_Entry entries[512]; int count; } TXD_Dict;
extern TXD_Dict g_global_txd;
extern int g_textures_loaded;
extern IDirect3DTexture8 *txd_find(const TXD_Dict *dict, const char *name);

/* Font atlas DXT5 data captured from xemu */
#include "font_atlas_data.h"

/* Create a D3D8 texture from raw DXT5 data */
static IDirect3DTexture8 *create_dxt5_texture(IDirect3DDevice8 *dev,
    uint32_t width, uint32_t height, const void *dxt5_data, uint32_t data_size)
{
    IDirect3DTexture8 *tex = NULL;
    /* D3DFMT_DXT5 = 0x35545844 ('DXT5') on Xbox, mapped to DXGI_FORMAT_BC3 in our layer.
     * Our d3d8 layer uses format code 0x0F for DXT5. */
    HRESULT hr = dev->lpVtbl->CreateTexture(dev, width, height, 1,
        0 /*Usage*/, 0x0F /*DXT5*/, 0 /*D3DPOOL_DEFAULT*/, &tex);
    if (hr != 0 || !tex) {
        return NULL;
    }

    /* Lock and fill with DXT5 data */
    D3DLOCKED_RECT lr = {0};
    hr = tex->lpVtbl->LockRect(tex, 0, &lr, NULL, 0);
    if (hr == 0 && lr.pBits) {
        memcpy(lr.pBits, dxt5_data, data_size);
        tex->lpVtbl->UnlockRect(tex, 0);
    } else {
    }
    return tex;
}

/* ══════════════════════════════════════════════════════════════════════
 * NV2A method constants (from nv2a_regs.h, subset for translator)
 * ══════════════════════════════════════════════════════════════════════ */

#define NV097_SET_BEGIN_END             0x17FC
#define NV097_INLINE_ARRAY              0x1818
/* These four were wrong: 0x01D0..0x01DC are not NV2A methods at all, so the
 * clear command was never recognised and the backbuffer was never erased --
 * the swapchain just kept flipping whatever frames were left in it. Values
 * per nv2a_regs.h (NV097_SET_ZSTENCIL_CLEAR_VALUE 0x1D8C follows). */
#define NV097_CLEAR_SURFACE             0x1D94
#define NV097_SET_COLOR_CLEAR_VALUE     0x1D90
#define NV097_SET_CLEAR_RECT_HORIZONTAL 0x1D98
#define NV097_SET_CLEAR_RECT_VERTICAL   0x1D9C

#define NV097_SET_DEPTH_TEST_ENABLE     0x030C
#define NV097_SET_DEPTH_FUNC            0x0354
#define NV097_SET_DEPTH_MASK            0x035C
#define NV097_SET_BLEND_ENABLE          0x0304
#define NV097_SET_BLEND_FUNC_SFACTOR    0x0344
#define NV097_SET_BLEND_FUNC_DFACTOR    0x0348
#define NV097_SET_CULL_FACE_ENABLE      0x0308
#define NV097_SET_CULL_FACE             0x039C
#define NV097_SET_FRONT_FACE            0x03A0
#define NV097_SET_STENCIL_TEST_ENABLE   0x032C
#define NV097_SET_STENCIL_MASK          0x0360
#define NV097_SET_STENCIL_FUNC          0x0364
#define NV097_SET_STENCIL_FUNC_REF      0x0368
#define NV097_SET_STENCIL_FUNC_MASK     0x036C
#define NV097_SET_STENCIL_OP_FAIL       0x0370
#define NV097_SET_STENCIL_OP_ZFAIL      0x0374
#define NV097_SET_STENCIL_OP_ZPASS      0x0378
#define NV097_SET_ALPHA_TEST_ENABLE     0x0300
#define NV097_SET_ALPHA_FUNC            0x033C
#define NV097_SET_ALPHA_REF             0x0340
#define NV097_SET_COLOR_MASK            0x0358
#define NV097_SET_SHADE_MODE            0x037C

#define NV097_SET_VIEWPORT_OFFSET       0x0A20
#define NV097_SET_VIEWPORT_SCALE        0x0AF0
#define NV097_SET_SURFACE_CLIP_HORIZONTAL 0x0200
#define NV097_SET_SURFACE_CLIP_VERTICAL 0x0204

#define NV097_SET_TEXTURE_OFFSET        0x1B00  /* +0x40 per stage */
#define NV097_SET_TEXTURE_FORMAT        0x1B04  /* +0x40 per stage */
#define NV097_SET_TEXTURE_ADDRESS       0x1B08  /* +0x40 per stage */
#define NV097_SET_TEXTURE_CONTROL0      0x1B0C  /* +0x40 per stage */
#define NV097_SET_TEXTURE_CONTROL1      0x1B10  /* +0x40 per stage */
#define NV097_SET_TEXTURE_FILTER        0x1B14  /* +0x40 per stage */
#define NV097_SET_TEXTURE_PALETTE       0x1B20  /* +0x40 per stage */

/* NV2A draw modes → D3D primitive types */
static int nv2a_draw_mode_to_d3d(uint32_t mode) {
    switch (mode) {
        case 1:  return D3DPT_POINTLIST;
        case 2:  return D3DPT_LINELIST;
        case 3:  return D3DPT_LINESTRIP;  /* LINE_LOOP → LINE_STRIP */
        case 4:  return D3DPT_LINESTRIP;
        case 5:  return D3DPT_TRIANGLELIST;
        case 6:  return D3DPT_TRIANGLESTRIP;
        case 7:  return D3DPT_TRIANGLEFAN;
        case 8:  return D3DPT_TRIANGLELIST; /* QUADS → TRI_LIST (needs conversion) */
        default: return D3DPT_TRIANGLELIST;
    }
}

/* NV2A blend factors → D3D blend */
/* NV2A blend factor -> D3DBLEND. Returns 0 for a value that is not a blend
 * factor at all: the push-buffer parse desyncs often enough to drop floats
 * into these registers, and mapping those to ONE turns an ordinary surface
 * into an additive blowout. The caller keeps its last good pair instead. */
static uint32_t nv2a_blend_to_d3d(uint32_t nv) {
    switch (nv) {
        case 0x0000: return D3DBLEND_ZERO;
        case 0x0001: return D3DBLEND_ONE;
        case 0x0300: return D3DBLEND_SRCCOLOR;
        case 0x0301: return D3DBLEND_INVSRCCOLOR;
        case 0x0302: return D3DBLEND_SRCALPHA;
        case 0x0303: return D3DBLEND_INVSRCALPHA;
        case 0x0304: return D3DBLEND_DESTALPHA;
        case 0x0305: return D3DBLEND_INVDESTALPHA;
        case 0x0306: return D3DBLEND_DESTCOLOR;
        case 0x0307: return D3DBLEND_INVDESTCOLOR;
        case 0x0308: return D3DBLEND_SRCALPHASAT;
        /* CONSTANT_COLOR/ALPHA: the blend colour (NV097_SET_BLEND_COLOR) goes
         * to D3D11 as the blend factor. These used to be ONE/ZERO -- right
         * only for an opaque white constant; Omega's after-image accumulates
         * with CONSTANT_ALPHA/ONE_MINUS_CONSTANT_ALPHA and needs the real
         * value. */
        case 0x8001: case 0x8003: return D3DBLEND_BLENDFACTOR;
        case 0x8002: case 0x8004: return D3DBLEND_INVBLENDFACTOR;
        default:     return 0;   /* not a blend factor */
    }
}

/* ══════════════════════════════════════════════════════════════════════
 * Translator State
 * ══════════════════════════════════════════════════════════════════════ */

/* Inline vertex buffer - max 16K vertices per draw */
#define MAX_INLINE_VERTS 16384
/* Indexed / DRAW_ARRAYS batches. The snow stage's deformable ground is one
 * DrawIndexedVertices of far more than 16K indices; capping the index list
 * at the inline limit silently dropped the rest of the mesh (holes in the
 * snow). Kept separate from the inline cap, which sizes a 5-dword-per-vertex
 * accumulator. */
#define MAX_IDX 65536
#define INLINE_VERT_DWORDS 5  /* X, Y, U, V, Color */

/* RwIm2DVertex-compatible output vertex (28 bytes) */
typedef struct {
    float x, y, z, rhw;
    uint32_t color;
    float u, v;
} OutputVertex;

static struct {
    /* Draw state */
    int in_draw;           /* Between BEGIN and END */
    uint32_t draw_mode;    /* NV2A draw mode (0=end, 6=tristrip, etc.) */
    int d3d_prim_type;     /* Translated D3D prim type */

    /* Inline vertex accumulator */
    uint32_t inline_data[MAX_INLINE_VERTS * INLINE_VERT_DWORDS];
    uint32_t inline_count; /* Number of dwords accumulated */
    uint32_t vert_stride;  /* Dwords per vertex (auto-detected) */
    /* DOA2U: inline vertex LAYOUT supplied by the recompiled D3D draw wrapper
     * (sub_001B3760 in recomp_manual.c). The XDK never emits
     * SET_VERTEX_DATA_ARRAY_FORMAT on this path, so the pgraph can't derive
     * it from methods; the CPU-side FVF object holds the truth. Offsets are
     * DWORD indices within a vertex; -1 = attribute absent. */
    /* DOA2U: the vertex count the guest passed to DrawVerticesUP, plus the
     * dword count its shader object declares. The push buffer carries the
     * attributes the DEVICE is set up to copy, which for the D3DX sprite path
     * is neither the API stride nor what the shader object lists (position +
     * diffuse + up to four texcoord sets). inline_count / this count is the
     * only exact per-vertex stride available. 0 = no hint for this draw. */
    uint32_t hint_verts;
    uint32_t hint_declared_dw;
    int layout_pos_dw;     /* dwords of position (2=XY, 3=XYZ, 4=XYZRHW) */
    int layout_uv_off;     /* dword offset of texcoord0, or -1 */
    int layout_color_off;  /* dword offset of diffuse (D3DCOLOR), or -1 */

    /* Clear state */
    uint32_t clear_color;
    uint32_t clear_rect_h;  /* (width << 16) | x */
    uint32_t clear_rect_v;  /* (height << 16) | y */

    /* Render state cache */
    int depth_test;
    int depth_mask;        /* NV097_SET_DEPTH_MASK: depth writes enabled */
    uint32_t depth_func;   /* NV097_SET_DEPTH_FUNC, GL constant 0x200..0x207 */
    int blend_enable;
    uint32_t blend_sfactor;
    uint32_t blend_dfactor;
    int cull_enable;
    uint32_t cull_face;      /* 0x404 FRONT, 0x405 BACK, 0x408 BOTH */
    uint32_t front_face;     /* 0x900 CW, 0x901 CCW */
    int stencil_enable;
    uint32_t stencil_mask, stencil_func, stencil_ref, stencil_func_mask;
    uint32_t stencil_fail, stencil_zfail, stencil_zpass;
    int alpha_test;
    uint32_t alpha_func;   /* NV097_SET_ALPHA_FUNC, GL constant 0x200..0x207 */
    uint32_t alpha_ref;    /* NV097_SET_ALPHA_REF, 0..255 */
    uint32_t color_mask;
    uint32_t comb_factor0[8];
    /* from doa2u_pb_tss_marker: 0xA3<<24 | stage1-off<<17 | op<<12 | arg1<<6 | arg2 */
    uint32_t gtss;
    int      gtss_valid;
    uint32_t comb_control;  /* NV097_SET_COMBINER_CONTROL: bits 7:0 = stage count */
    /* Point sprites (the snow stage's falling snow). SET_POINT_PARAMS_ENABLE
     * 0x0318, SET_POINT_SMOOTH_ENABLE 0x031C (the sprite-coordinate switch:
     * the NV2A feeds a point's 0..1 coordinates to texture unit 3 only),
     * SET_POINT_SIZE 0x043C in 1/8 pixel units, SET_POINT_PARAMS 0x0A30. */
    uint32_t point_params_en, point_smooth, point_size;
    float    point_params[8];
    /* Stage-3 texture ops from the guest's TSS table (doa2u_pb_tss_marker
     * 0xA4 = colour, 0xA5 = alpha: op<<12 | arg1<<6 | arg2). */
    uint32_t tss3_color, tss3_alpha;
    int      tss3_valid;
    /* Stage-1 ops (markers 0xA6 colour / 0xA7 alpha, same packing) and the
     * guest's D3DRS_TEXTUREFACTOR (markers 0xA9 low 24 bits / 0xAA high 8).
     * The push buffer's SET_COMBINER_FACTOR0 is NOT this value: the XDK's
     * combiner compiler never completes in this port, so factor0 reads
     * FFFFFFFF on every draw while the game's factor is e.g. 0x23FFFFFF. */
    uint32_t tss1_color, tss1_alpha;
    uint32_t tss0_alpha;               /* marker 0xAB: guest stage-0 ALPHAOP/args */
    int      tss0_alpha_valid;
    int      tss1_valid;
    uint32_t tfactor_lo, tfactor_hi;

    /* Viewport */
    float vp_offset[4];
    float vp_scale[4];
    /* NV097_SET_WINDOW_CLIP_* (0x02B4/0x02C0/0x02E0): the hardware scissor.
     * The game programs it ~18.8k times per 2 s and it is what confines the
     * character-select portrait to its window. */
    uint32_t window_clip_type;
    uint32_t window_clip_h[8];
    uint32_t window_clip_v[8];
    uint32_t surface_clip_h;
    uint32_t surface_clip_v;
    /* DOA2U: depth range the fixed-function output is normalised with.
     * SET_CLIP_MIN/MAX (0x0394/0x0398) are what the hardware clips z
     * against; the zeta format (SET_SURFACE_FORMAT bits 7:4) gives the
     * z-buffer range: Z16 = 65535, Z24S8 = 16777215. */
    float    clip_min, clip_max;
    uint32_t surface_fmt;

    /* Texture state per stage (4 stages) */
    struct {
        uint32_t offset;     /* NV2A VRAM offset (method 0x1B00) */
        uint32_t format;     /* Format register (method 0x1B04) */
        uint32_t address;    /* Address modes: U bits 0-3, V bits 8-11 (0x1B08) */
        uint32_t control0;   /* Control0 register (method 0x1B0C) */
        uint32_t control1;   /* Control1: linear pitch in hi16 (method 0x1B10) */
        uint32_t filter;     /* MIN bits 16-23, MAG bits 24-27 (method 0x1B14) */
        uint32_t image_rect; /* Linear size: (width<<16)|height (method 0x1B1C) */
        /* Palette for the indexed formats (method 0x1B20): bit 0 selects the
         * context DMA, bits 3:2 the entry count (0=256, 1=128, 2=64, 3=32)
         * and bits 31:6 the 64-byte-aligned offset of an A8R8G8B8 table. */
        uint32_t palette;
        int enabled;         /* Decoded from control0 bit 30 */
    } tex[4];

    /* DOA2U: dynamic texture created from guest RAM (the movie frame surface
     * and other linear textures the game renders from memory). Re-uploaded
     * every draw; recreated when offset/dims/format change. */
    IDirect3DTexture8 *dyn_tex;   /* the binding the last draw resolved to */
    uint32_t dyn_src_off;   /* guest address of the last upload */
    int      dyn_src_valid; /* last upload was static (swizzled/DXT) */
    uint32_t dyn_w, dyn_h, dyn_fmt;
    uint32_t dyn_levels;          /* mip levels of the last binding */
    /* Guest-texture cache: one D3D texture per (address, size, format).
     *
     * 192 slots evicted round-robin was too small: a fight on the Beach binds
     * 198 distinct textures a frame and the attract window fall 223, so
     * textures were thrown out and recreated a few draws later -- 53-158
     * CreateTexture + uploads (1-2.6 MB) every frame, none of them because
     * the contents had changed. A whole stage visit touches at most 415
     * textures (~8 MB, measured), so 1024 slots under a byte budget keep
     * several stages resident, and the least recently used slot goes first.
     * Lookups go through a hash instead of scanning every slot. */
#define TEXCACHE_N      1024
#define TEXCACHE_HASH_N 4096                       /* power of two */
#define TEXCACHE_BUDGET (192u * 1024u * 1024u)     /* host bytes: GPU + staging */
    struct {
        IDirect3DTexture8 *tex;
        uint32_t off, w, h, fmt, levels;
        uint32_t pal;       /* palette register this upload was expanded with */
        int uploaded;       /* static source already uploaded */
        uint32_t sig;       /* sampled fingerprint of level 0 at that upload */
        uint32_t last_frame;/* g_pg.frame of the last draw that bound it */
        uint32_t bytes;     /* host bytes held: D3D11 texture + D3D8 staging copy */
    } texcache[TEXCACHE_N];
    int16_t  texhash[TEXCACHE_HASH_N];   /* slot index + 1, 0 = empty bucket */
    uint32_t texcache_bytes;             /* sum of .bytes over live slots */
    uint32_t frame;                      /* bumped once per pgraph_d3d11_flush */

    /* Cached texture pointers */
    void *menu_texture;           /* IDirect3DTexture8* from Global.txd */
    IDirect3DTexture8 *font_atlas; /* Created from captured DXT5 data */
    int texture_lookup_done;

    /* Stats */
    PgraphD3D11Stats stats;

    /* Chyron scroll */
    float chyron_scroll_offset;  /* Pixels to shift X for chyron text */

    /* Transform program state.
     *
     * The game draws its 3D screens with MODE_PROGRAM, so attribute 0 is an
     * object-space position that only becomes screen space after the uploaded
     * program runs. `attr_fmt` is the authoritative inline vertex layout from
     * SET_VERTEX_DATA_ARRAY_FORMAT, which this title does emit (the previous
     * title did not, hence the wrapper-supplied fallback layout above). */
    Nv2aVertexProgram vp;
    uint32_t xform_mode;        /* NV097_SET_TRANSFORM_EXECUTION_MODE */
    uint32_t attr_fmt[16];      /* SET_VERTEX_DATA_ARRAY_FORMAT per slot */
    int      attr_fmt_seen;

    /* Vertex-array (indexed / DRAW_ARRAYS) submission.
     *
     * The title screen does not use INLINE_ARRAY at all: it binds vertex
     * buffers and issues ~378 D3DDevice_DrawIndexedVertices per frame with
     * fixed-function T&L (confirmed against a cxbx trace of the real game).
     * Those arrive as SET_VERTEX_DATA_ARRAY_OFFSET + ARRAY_ELEMENT/DRAW_ARRAYS,
     * every one of which this translator previously ignored -- so the whole
     * screen was silently dropped. */
    uint32_t attr_off[16];      /* SET_VERTEX_DATA_ARRAY_OFFSET per slot */
    uint32_t idx[MAX_IDX];
    uint32_t idx_count;
    uint32_t idx_dropped;       /* indices past MAX_IDX in the current batch */
    float    composite[16];     /* NV097_SET_COMPOSITE_MATRIX */
    int      composite_seen;
    uint32_t lighting;          /* NV097_SET_LIGHTING_ENABLE 0x0314 */

    /* Fixed-function vertex lighting state (NV2A registers written by the
     * Xbox D3D runtime; light colours already carry the material factors). */
    struct {
        float amb[3], dif[3], spec[3];   /* 0x1000 / 0x100C / 0x1018 (+0x80*i) */
        float range;                     /* 0x1024 */
        float half[3], dir[3];           /* 0x1028 / 0x1034 (eye space) */
        float spot_fall[3], spot_dir[4]; /* 0x1040 / 0x104C */
        float pos[3], att[3];            /* 0x105C / 0x1068 (eye space) */
    } light[4];
    uint32_t light_mask;        /* 0x03BC: 2 bits per light, 0 off 1 inf 2 local 3 spot */
    uint32_t light_control;     /* 0x0294 */
    uint32_t color_material;    /* 0x0298 */
    uint32_t spec_enable;       /* 0x03B8 */
    uint32_t normalize_en;      /* 0x03A4 */
    float    scene_ambient[3];  /* 0x0A10 */
    float    emission[3];       /* 0x03A8 */
    float    material_alpha;    /* 0x03B4 */
    float    spec_params[6];    /* 0x09E0 */

    /* Init flag */
    int initialized;
} g_pg;

/* ══════════════════════════════════════════════════════════════════════
 * Float/uint32 conversion
 * ══════════════════════════════════════════════════════════════════════ */
static float u2f(uint32_t u) {
    union { float f; uint32_t i; } x;
    x.i = u;
    return x.f;
}

/* ══════════════════════════════════════════════════════════════════════
 * Initialization
 * ══════════════════════════════════════════════════════════════════════ */

void pgraph_d3d11_init(void)
{
    memset(&g_pg, 0, sizeof(g_pg));
    g_pg.vert_stride = INLINE_VERT_DWORDS;  /* Default: 5 dwords per vertex */
    g_pg.layout_pos_dw = 2;                 /* burnout default: X,Y,U,V,color */
    g_pg.layout_uv_off = 2;
    g_pg.layout_color_off = 4;
    g_pg.clear_color = 0xFF000000;
    g_pg.depth_test = 1;            /* hardware defaults: test and write on, */
    g_pg.depth_mask = 1;            /* comparing LESS, until the game says   */
    g_pg.depth_func = 0x201;        /* otherwise                             */
    g_pg.cull_face = 0x405;         /* BACK, CCW front: the GL defaults      */
    g_pg.front_face = 0x901;
    g_pg.stencil_func = 0x207;      /* ALWAYS                                */
    g_pg.stencil_mask = 0xFF;
    g_pg.stencil_func_mask = 0xFF;
    g_pg.stencil_fail = g_pg.stencil_zfail = g_pg.stencil_zpass = 0x1E00; /* KEEP */
    g_pg.color_mask = 0x01010101;
    g_pg.initialized = 1;

}

void pgraph_d3d11_shutdown(void)
{
    g_pg.initialized = 0;
}

/* ══════════════════════════════════════════════════════════════════════
 * Draw Submission
 * ══════════════════════════════════════════════════════════════════════ */

/* Build/refresh a D3D8 texture from guest RAM for the formats the game uses.
 *
 * This previously handled only the four LIN_* formats, so every swizzled or
 * DXT-compressed texture returned NULL and the draw fell through to
 * vertex-colour only -- with alpha blending forced on, that is invisible. The
 * the title screen binds swizzled and compressed textures, so none of it
 * appeared on screen.
 *
 * Two things the linear-only path got wrong for those formats:
 *   - size: only linear textures carry it in SET_TEXTURE_IMAGE_RECT. Swizzled
 *     and DXT textures encode log2(width)/log2(height) in the format register
 *     (BASE_SIZE_U/V), which is why they arrived as 0x0.
 *   - layout: swizzled textures are Z-order (Morton) and must be unswizzled to
 *     row-major before upload. DXT blocks are already linear.
 *
 * The Xbox D3DFORMAT codes are not all equal to the NV2A colour codes (NV A8 is
 * 0x19 but D3DFMT_A8 is 19 decimal; NV A1R5G5B5 is 0x02 but D3DFMT_A1R5G5B5 is
 * 3), so map them explicitly instead of passing the raw NV code through. */
extern ptrdiff_t g_xbox_mem_offset;

static int nv_texture_format(uint32_t nvfmt, D3DFORMAT *out_fmt,
                             uint32_t *out_bpp, int *out_swizzled,
                             int *out_compressed, int *out_palettised)
{
    D3DFORMAT f;
    uint32_t bpp;
    int comp = 0, pal = 0;
    switch (nvfmt) {
    case 0x00: f = D3DFMT_L8;           bpp = 1; break;  /* SZ_Y8       */
    case 0x01: f = D3DFMT_L8;           bpp = 1; break;  /* SZ_AY8      */
    case 0x02: f = D3DFMT_A1R5G5B5;     bpp = 2; break;  /* SZ_A1R5G5B5 */
    case 0x03: f = D3DFMT_A1R5G5B5;     bpp = 2; break;  /* SZ_X1R5G5B5 */
    case 0x04: f = D3DFMT_A4R4G4B4;     bpp = 2; break;
    case 0x05: f = D3DFMT_R5G6B5;       bpp = 2; break;
    case 0x06: f = D3DFMT_A8R8G8B8;     bpp = 4; break;
    case 0x07: f = D3DFMT_X8R8G8B8;     bpp = 4; break;
    /* Indexed (palettised) textures. The source is one byte per texel; the
     * palette named by SET_TEXTURE_PALETTE holds A8R8G8B8 entries, so the
     * upload expands to a 32-bit surface. bpp stays 1 here because every
     * source-side calculation (pitch, level sizes, bounds) is in source
     * bytes; the destination width is handled at upload time. Paletted
     * 8-bit textures use 0x0B, and with no case here the whole draw
     * was silently dropped. */
    case 0x0B: f = D3DFMT_A8R8G8B8;     bpp = 1; pal = 1; break;  /* SZ_I8_A8R8G8B8 */
    case 0x0C: f = D3DFMT_DXT1;         bpp = 0; comp = 1; break;
    case 0x0E: f = D3DFMT_DXT3;         bpp = 0; comp = 1; break;
    case 0x0F: f = D3DFMT_DXT5;         bpp = 0; comp = 1; break;
    case 0x19: f = D3DFMT_A8;           bpp = 1; break;  /* SZ_A8       */
    case 0x1A: f = D3DFMT_A8L8;         bpp = 2; break;  /* SZ_A8Y8     */
    case 0x10: f = D3DFMT_LIN_A1R5G5B5; bpp = 2; break;
    case 0x11: f = D3DFMT_LIN_R5G6B5;   bpp = 2; break;
    case 0x12: f = D3DFMT_LIN_A8R8G8B8; bpp = 4; break;
    case 0x13: f = D3DFMT_L8;           bpp = 1; break;  /* LIN_Y8      */
    case 0x1C: f = D3DFMT_LIN_A1R5G5B5; bpp = 2; break;
    case 0x1D: f = D3DFMT_LIN_A4R4G4B4; bpp = 2; break;
    case 0x1E: f = D3DFMT_LIN_X8R8G8B8; bpp = 4; break;
    case 0x1F: f = D3DFMT_A8;           bpp = 1; break;  /* LIN_A8      */
    default: return 0;
    }
    *out_fmt = f;
    *out_bpp = bpp;
    *out_compressed = comp;
    *out_palettised = pal;
    *out_swizzled = !comp && d3d8_format_is_swizzled(nvfmt);
    return 1;
}

/* NV2A texture address mode -> D3DTEXTUREADDRESS. The two enums agree for
 * wrap/mirror/clamp/border; the OGL clamp variant has no D3D8 equivalent and
 * maps to clamp. An unprogrammed register means wrap, the hardware default --
 * not clamp, which smears the edge texel over every tiled surface. */
/* GL stencil op enum -> D3DSTENCILOP (KEEP 1 .. DECR 8). */
static DWORD nv_d3d_stencil_op(uint32_t op)
{
    switch (op) {
    case 0x1E00: return 1;   /* KEEP    */
    case 0x0000: return 2;   /* ZERO    */
    case 0x1E01: return 3;   /* REPLACE */
    case 0x1E02: return 4;   /* INCRSAT */
    case 0x1E03: return 5;   /* DECRSAT */
    case 0x150A: return 6;   /* INVERT  */
    case 0x8507: return 7;   /* INCR    */
    case 0x8508: return 8;   /* DECR    */
    default:     return 1;
    }
}

static DWORD nv_d3d_address(uint32_t nvmode)
{
    switch (nvmode & 0xF) {
    case 1:  return 1;   /* WRAP   */
    case 2:  return 2;   /* MIRROR */
    case 3:  return 3;   /* CLAMP_TO_EDGE */
    case 4:  return 4;   /* BORDER */
    case 5:  return 3;   /* CLAMP_TO_EDGE_OGL */
    default: return 1;
    }
}

/* NV2A minification filter -> D3DTEXF. 1 nearest, 2 linear, 3/4 with a
 * nearest mip, 5/6 with a linear mip; the odd values are the nearest
 * variants. */
static DWORD nv_d3d_minfilter(uint32_t m)
{
    switch (m & 0xFF) {
    case 1: case 3: case 5: return 1;   /* POINT  */
    case 2: case 4: case 6: return 2;   /* LINEAR */
    default: return 2;
    }
}

/* The mip term of the same enum: NEAREST/LINEAR have no mip filter, 3 and 4
 * select the nearest level, 5 and 6 interpolate between two. This used to be
 * pinned to NONE because only level 0 was ever uploaded; with the guest's own
 * mip chain uploaded it can follow the register, which is what stops distant
 * stage textures from aliasing into noise. */
static DWORD nv_d3d_mipfilter(uint32_t m)
{
    switch (m & 0xFF) {
    case 3: case 4: return 1;   /* POINT  */
    case 5: case 6: return 2;   /* LINEAR */
    default: return 0;          /* NONE   */
    }
}

static DWORD nv_d3d_magfilter(uint32_t m)
{
    return ((m & 0xF) == 1) ? 1u : 2u;  /* 1 nearest, else linear */
}

static void nv_apply_tex_address(IDirect3DDevice8 *dev, int stage)
{
    uint32_t a = g_pg.tex[stage].address;
    {   uint32_t f = g_pg.tex[stage].filter;
        DWORD mn = nv_d3d_minfilter(f >> 16), mg = nv_d3d_magfilter(f >> 24);
        {   /* DOA2U DIAG: what the game asks for, and what we were doing
             * before this (the stage states were never written at all, so the
             * shim's mapper fell through to MIN_MAG_MIP_POINT). */
            extern volatile int g_doa2u_post_movie;
            static DWORD s_next = 0; static uint32_t s_n[3][4];
            s_n[0][mn & 3]++; s_n[1][mg & 3]++; s_n[2][(f == 0) ? 0 : 1]++;
            if (g_doa2u_post_movie && GetTickCount() >= s_next) {
                s_next = GetTickCount() + 2000;
                 memset(s_n, 0, sizeof s_n);
            }
        }
        {   /* DOA2U DIAG: mip levels the source declares, and how many stages
             * the game actually enables -- the two texture features this
             * translator still does not implement. */
            extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_mip[16], s_stg[5];
            int k, n = 0;
            s_mip[(g_pg.tex[stage].format >> 16) & 0xF]++;
            for (k = 0; k < 4; k++) if (g_pg.tex[k].enabled) n++;
            s_stg[n & 4]++;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                memset(s_mip, 0, sizeof s_mip); memset(s_stg, 0, sizeof s_stg);
            }
        }
        {   /* Filter bits 12:0: mip LOD bias, signed 5.8; control0 bits 29:18:
             * min-LOD clamp, 5.8. */
            int bias = (int)(f & 0x1FFF); if (bias & 0x1000) bias -= 0x2000;
            float fb = (float)bias / 256.0f; DWORD bb; memcpy(&bb, &fb, sizeof bb);
            uint32_t minlod = (g_pg.tex[stage].control0 >> 18) & 0xFFF;
            dev->lpVtbl->SetTextureStageState(dev, stage, 19 /*MIPMAPLODBIAS*/, bb);
            dev->lpVtbl->SetTextureStageState(dev, stage, 20 /*MAXMIPLEVEL*/, minlod >> 8);
        }
        dev->lpVtbl->SetTextureStageState(dev, stage, 16 /*MAGFILTER*/, mg);
        dev->lpVtbl->SetTextureStageState(dev, stage, 17 /*MINFILTER*/, mn);
        dev->lpVtbl->SetTextureStageState(dev, stage, 18 /*MIPFILTER*/,
                                          g_pg.dyn_levels > 1 ? nv_d3d_mipfilter(f >> 16) : 0);
    }
    {   /* DOA2U DIAG: what the game actually asks for, per 2 s. */
        extern volatile int g_doa2u_post_movie;
        static DWORD s_next = 0; static uint32_t s_u[16], s_v[16];
        s_u[a & 0xF]++; s_v[(a >> 8) & 0xF]++;
        if (g_doa2u_post_movie && GetTickCount() >= s_next) {
            int i; s_next = GetTickCount() + 2000;
            memset(s_u, 0, sizeof s_u); memset(s_v, 0, sizeof s_v);
        }
    }
    dev->lpVtbl->SetTextureStageState(dev, stage, 13 /*ADDRESSU*/, nv_d3d_address(a));
    dev->lpVtbl->SetTextureStageState(dev, stage, 14 /*ADDRESSV*/, nv_d3d_address(a >> 8));
}

/* Sampled fingerprint of a texture's level-0 bytes: 64 dwords spread across
 * the image plus its size. Cheap enough to take on every cache hit. */
static uint32_t nv_tex_signature(const uint8_t *p, size_t n)
{
    uint32_t h = 2166136261u ^ (uint32_t)n;
    size_t i, step = (n / 64) & ~(size_t)3;
    if (step < 4) step = 4;
    for (i = 0; i + 4 <= n; i += step) {
        uint32_t v;
        memcpy(&v, p + i, 4);
        h = (h ^ v) * 16777619u;
    }
    return h;
}

/* ---- texture cache: hash lookup + least-recently-used eviction ---- */
static uint32_t texcache_hash(uint32_t off, uint32_t w, uint32_t h, uint32_t fmt, uint32_t pal)
{
    return (((off ^ (w << 20) ^ (h << 8) ^ (fmt * 0x9E3779B1u) ^ pal) * 2654435761u)
            >> 20) & (TEXCACHE_HASH_N - 1);
}

static int texcache_find(uint32_t off, uint32_t w, uint32_t h, uint32_t fmt, uint32_t pal)
{
    uint32_t b = texcache_hash(off, w, h, fmt, pal), n;
    for (n = 0; n < TEXCACHE_HASH_N; n++, b = (b + 1) & (TEXCACHE_HASH_N - 1)) {
        int s = g_pg.texhash[b] - 1;
        if (s < 0) return -1;
        if (g_pg.texcache[s].off == off && g_pg.texcache[s].w == w &&
            g_pg.texcache[s].h == h && g_pg.texcache[s].fmt == fmt &&
            g_pg.texcache[s].pal == pal)
            return s;
    }
    return -1;
}

static uint32_t texcache_home(int slot)
{
    return texcache_hash(g_pg.texcache[slot].off, g_pg.texcache[slot].w,
                         g_pg.texcache[slot].h, g_pg.texcache[slot].fmt,
                         g_pg.texcache[slot].pal);
}

static void texcache_hash_insert(int slot)
{
    uint32_t b = texcache_home(slot);
    while (g_pg.texhash[b]) b = (b + 1) & (TEXCACHE_HASH_N - 1);
    g_pg.texhash[b] = (int16_t)(slot + 1);
}

/* Drop a slot's bucket, then backward-shift the rest of its probe run so a
 * later lookup never stops at the hole before reaching a live entry. */
static void texcache_hash_remove(int slot)
{
    uint32_t b = texcache_home(slot), hole, j;
    while (g_pg.texhash[b] && g_pg.texhash[b] != slot + 1)
        b = (b + 1) & (TEXCACHE_HASH_N - 1);
    if (!g_pg.texhash[b]) return;
    hole = b;
    g_pg.texhash[hole] = 0;
    for (j = (hole + 1) & (TEXCACHE_HASH_N - 1); g_pg.texhash[j];
         j = (j + 1) & (TEXCACHE_HASH_N - 1)) {
        uint32_t home = texcache_home(g_pg.texhash[j] - 1);
        /* j may move into the hole unless its home lies cyclically in (hole, j]. */
        int stays = (hole <= j) ? (home > hole && home <= j)
                                : (home > hole || home <= j);
        if (!stays) {
            g_pg.texhash[hole] = g_pg.texhash[j];
            g_pg.texhash[j] = 0;
            hole = j;
        }
    }
}

static void texcache_evict(int slot)
{
    texcache_hash_remove(slot);
    g_pg.texcache[slot].tex->lpVtbl->Release(g_pg.texcache[slot].tex);
    g_pg.texcache[slot].tex = NULL;
    g_pg.texcache_bytes -= g_pg.texcache[slot].bytes;
    g_pg.texcache[slot].bytes = 0;
}

/* A free slot for a new texture of `bytes`: an empty slot while under the
 * budget, otherwise evict least-recently-used slots not bound this frame
 * until it fits. If everything was bound this frame (never measured), the
 * oldest goes anyway so a draw can always get a texture. Releasing a texture
 * that is still bound is safe: the D3D11 binding holds its own reference, and
 * eviction runs before the current draw binds anything. */
static int texcache_make_room(uint32_t bytes)
{
    for (;;) {
        int i, free_slot = -1, lru = -1, lru_any = -1;
        for (i = 0; i < TEXCACHE_N; i++) {
            if (!g_pg.texcache[i].tex) { if (free_slot < 0) free_slot = i; continue; }
            if (lru_any < 0 ||
                (int32_t)(g_pg.texcache[i].last_frame - g_pg.texcache[lru_any].last_frame) < 0)
                lru_any = i;
            if (g_pg.texcache[i].last_frame != g_pg.frame &&
                (lru < 0 ||
                 (int32_t)(g_pg.texcache[i].last_frame - g_pg.texcache[lru].last_frame) < 0))
                lru = i;
        }
        if (free_slot >= 0 && g_pg.texcache_bytes + bytes <= TEXCACHE_BUDGET)
            return free_slot;
        if (lru < 0) lru = lru_any;
        if (lru < 0) return free_slot >= 0 ? free_slot : 0;   /* nothing resident */
        texcache_evict(lru);
    }
}

static IDirect3DTexture8 *get_dynamic_texture(IDirect3DDevice8 *dev)
{
    uint32_t fmtreg = g_pg.tex[0].format;
    uint32_t off    = g_pg.tex[0].offset;
    uint32_t nvfmt  = (fmtreg >> 8) & 0xFF;
    uint32_t w, h, bpp, pitch, nlevels = 1;
    int swizzled, compressed, palettised;
    uint32_t palreg = g_pg.tex[0].palette;
    uint32_t sig;
    D3DFORMAT d3dfmt;

    if (!off || off >= 0x08000000u) return NULL; /* DOA2U: guest RAM to 128 MB */
    {   /* DOA2U DIAG: why textures do or do not materialise. */
        extern uint32_t g_texfmt[64], g_texnull[4];
        g_texfmt[nvfmt & 63]++;
        if (!off || off >= 0x08000000u) g_texnull[0]++;
    }
    if (!nv_texture_format(nvfmt, &d3dfmt, &bpp, &swizzled, &compressed,
                           &palettised)) {
        extern uint32_t g_texnull[4];
        g_texnull[1]++;
        return NULL;
    }

    /* Size: swizzled/compressed carry log2 dims in the format register;
     * linear ones use the image-rect method. */
    {
        uint32_t lu = (fmtreg & NV097_SET_TEXTURE_FORMAT_BASE_SIZE_U) >> 20;
        uint32_t lv = (fmtreg & NV097_SET_TEXTURE_FORMAT_BASE_SIZE_V) >> 24;
        if (swizzled || compressed) {
            if (lu > 12 || lv > 12) return NULL;
            w = 1u << lu;
            h = 1u << lv;
        } else {
            w = g_pg.tex[0].image_rect >> 16;
            h = g_pg.tex[0].image_rect & 0xFFFF;
            if (!w || !h) {
                if (lu > 12 || lv > 12) return NULL;
                w = 1u << lu;
                h = 1u << lv;
            }
        }
    }
    if (w == 0 || h == 0 || w > 2048 || h > 2048) {
        extern uint32_t g_texnull[4];
        g_texnull[2]++;
        return NULL;
    }

    /* Mip levels. SET_TEXTURE_FORMAT bits 19:16 hold the number of levels
     * present in the source; the Xbox packs level 1 onward immediately after
     * level 0 in the same blob. Measured on the title stage, the game declares
     * 3 to 9 levels on most of its draws and asks for a linear mip filter, so
     * uploading only level 0 left every minified surface aliasing. Linear
     * (non-swizzled, non-DXT) surfaces are render targets and movie frames:
     * one level only. */
    {
        uint32_t declared = (fmtreg >> 16) & 0xF;
        uint32_t mx = (w > h) ? w : h, cap = 1;
        while ((mx >> (cap - 1)) > 1) cap++;
        nlevels = (swizzled || compressed) ? declared : 1;
        if (nlevels < 1) nlevels = 1;
        if (nlevels > cap) nlevels = cap;
    }

    /* Source stride. control1 carries a linear pitch and is only meaningful
     * for linear formats; swizzled and DXT data are tightly packed. */
    if (compressed) {
        pitch = ((w + 3) / 4) * ((d3dfmt == D3DFMT_DXT1) ? 8u : 16u);
    } else if (swizzled) {
        pitch = w * bpp;
    } else {
        pitch = g_pg.tex[0].control1 >> 16;
        if (pitch < w * bpp || pitch > 0x4000) pitch = w * bpp;
    }

    /* Bounds-check the whole source -- every level -- against guest RAM
     * before reading it. */
    {
        unsigned long long need = 0;
        uint32_t l, lw = w, lh = h;
        for (l = 0; l < nlevels; l++) {
            uint32_t lp = compressed
                ? ((lw + 3) / 4) * ((d3dfmt == D3DFMT_DXT1) ? 8u : 16u)
                : (swizzled ? lw * bpp : pitch);
            need += compressed ? (unsigned long long)lp * ((lh + 3) / 4)
                               : (unsigned long long)lp * lh;
            lw = (lw > 1) ? lw / 2 : 1;
            lh = (lh > 1) ? lh / 2 : 1;
        }
        if ((unsigned long long)off + need > 0x08000000ull) {
            extern uint32_t g_texnull[4];
            g_texnull[3]++;
            return NULL;
        }
    }
    {   size_t l0 = compressed ? (size_t)pitch * ((h + 3) / 4) : (size_t)pitch * h;
        sig = nv_tex_signature((const uint8_t *)((uintptr_t)off + g_xbox_mem_offset), l0); }

    /* One texture per distinct binding, kept alive.
     *
     * There used to be a single slot here, so a screen that binds fifty
     * different textures in a frame destroyed and recreated a D3D texture on
     * nearly every draw -- ~500 CreateTexture + upload pairs a frame, which is
     * what held the post-movie screen at 0.4 fps. Cache by the guest address,
     * format and size instead; immutable (swizzled/DXT) sources then upload
     * exactly once and linear ones (movie frames, render targets) re-upload in
     * place. */
    {
        uint32_t keypal = palettised ? palreg : 0u;
        int slot = texcache_find(off, w, h, (uint32_t)d3dfmt, keypal);
        if (slot < 0) {
            /* Host bytes this texture will hold: every level in the host
             * format (DXT stays block-compressed, swizzled sources keep their
             * bpp, palettised ones are expanded to A8R8G8B8), twice -- the
             * D3D11 texture plus the D3D8 layer's staging copy of each level. */
            uint32_t bytes = 0, l, lw = w, lh = h;
            for (l = 0; l < nlevels; l++) {
                bytes += compressed
                    ? ((lw + 3) / 4) * ((lh + 3) / 4) * ((d3dfmt == D3DFMT_DXT1) ? 8u : 16u)
                    : lw * lh * (palettised ? 4u : bpp);
                lw = (lw > 1) ? lw / 2 : 1;
                lh = (lh > 1) ? lh / 2 : 1;
            }
            bytes *= 2;
            slot = texcache_make_room(bytes);
            if (dev->lpVtbl->CreateTexture(dev, w, h, nlevels, 0, d3dfmt, 0,
                                           &g_pg.texcache[slot].tex) != 0 ||
                !g_pg.texcache[slot].tex) {
                g_pg.texcache[slot].tex = NULL;
                return NULL;
            }
            g_pg.texcache[slot].bytes = bytes;
            g_pg.texcache_bytes += bytes;
            /* Everything uploaded below is row-major: swizzled sources are
             * unswizzled here (they have to be, so palettised ones can be
             * expanded), and linear ones are copied straight through. Say so,
             * or the D3D8 layer unswizzles the data a SECOND time in
             * tex_UnlockRect because the format still names the swizzled
             * Xbox layout -- which scrambled every swizzled texture in the
             * game, the corner logo included. */
            {   extern void d3d8_TextureSetLinearData(IDirect3DTexture8 *, BOOL);
                d3d8_TextureSetLinearData(g_pg.texcache[slot].tex, TRUE); }
            g_pg.texcache[slot].off = off;
            g_pg.texcache[slot].w = w;
            g_pg.texcache[slot].h = h;
            g_pg.texcache[slot].fmt = (uint32_t)d3dfmt;
            g_pg.texcache[slot].levels = nlevels;
            g_pg.texcache[slot].pal = palettised ? palreg : 0u;
            g_pg.texcache[slot].uploaded = 0;
            g_pg.texcache[slot].sig = 0;
            texcache_hash_insert(slot);
        }
        g_pg.texcache[slot].last_frame = g_pg.frame;
        g_pg.dyn_tex = g_pg.texcache[slot].tex;
        g_pg.dyn_w = w; g_pg.dyn_h = h; g_pg.dyn_fmt = (uint32_t)d3dfmt;
        g_pg.dyn_levels = g_pg.texcache[slot].levels;

        /* Swizzled and DXT textures come from the XPR0 bundles and never
         * change in place, so once uploaded they are not redone --
         * re-unswizzling them every draw costs far more than the whole rest
         * of the frame. Linear surfaces (the movie frame, render targets) do
         * change in place, so those are always re-uploaded.
         *
         * The guest address is NOT a permanent identity, though: the heap is
         * recycled between loads. On character select, Hitomi's 256x256 DXT1
         * face texture lands exactly where Kasumi's 256x256 DXT1 costume
         * texture had been, same size and format, so the key matched and the
         * cache kept serving Kasumi's blue costume as Hitomi's face. Compare
         * a sampled fingerprint of the source on every hit and re-upload when
         * the bytes behind the address have changed. */
        if ((swizzled || compressed) && g_pg.texcache[slot].uploaded &&
            g_pg.texcache[slot].sig == sig)
            return g_pg.dyn_tex;
        g_pg.texcache[slot].uploaded = (swizzled || compressed);
        g_pg.texcache[slot].sig = sig;
    }
    {
        const uint8_t *srcp = (const uint8_t *)((uintptr_t)off + g_xbox_mem_offset);
        uint32_t l, lw = w, lh = h;
        uint32_t pal[256];
        if (palettised) {
            /* SET_TEXTURE_PALETTE: 64-byte-aligned offset of an A8R8G8B8
             * table, with bits 3:2 giving 256/128/64/32 entries. Xbox palette
             * entries are already A8R8G8B8, so they drop straight into the
             * D3DFMT_A8R8G8B8 destination. Short tables are clamped rather
             * than left as zeros, which would punch transparent holes. */
            uint32_t paloff = palreg & 0xFFFFFFC0u;
            uint32_t pcount = 256u >> ((palreg >> 2) & 3u);
            uint32_t i;
            if (paloff &&
                (unsigned long long)paloff + 4ull * pcount <= 0x08000000ull) {
                const uint32_t *ps =
                    (const uint32_t *)((uintptr_t)paloff + g_xbox_mem_offset);
                for (i = 0; i < pcount; i++) pal[i] = ps[i];
                for (; i < 256; i++) pal[i] = pal[pcount - 1];
            } else {
                /* No usable palette: opaque greyscale, so a mis-set register
                 * shows as a readable image instead of an invisible draw. */
                for (i = 0; i < 256; i++)
                    pal[i] = 0xFF000000u | (i * 0x00010101u);
            }
        }
        for (l = 0; l < nlevels; l++) {
            D3DLOCKED_RECT lr;
            /* Source stride of this level. Swizzled and DXT levels are
             * tightly packed; a linear surface only ever has level 0. */
            uint32_t lp = compressed
                ? ((lw + 3) / 4) * ((d3dfmt == D3DFMT_DXT1) ? 8u : 16u)
                : (swizzled ? lw * bpp : pitch);
            size_t lsize = compressed ? (size_t)lp * ((lh + 3) / 4)
                                      : (size_t)lp * lh;
            if (g_pg.dyn_tex->lpVtbl->LockRect(g_pg.dyn_tex, l, &lr, NULL, 0) == 0 &&
                lr.pBits) {
                uint8_t *dstp = (uint8_t *)lr.pBits;
                if (compressed) {
                    uint32_t rows = (lh + 3) / 4, r;
                    for (r = 0; r < rows; r++)
                        memcpy(dstp + (size_t)r * lr.Pitch,
                               srcp + (size_t)r * lp, lp);
                } else if (swizzled) {
                    uint8_t *lin = (uint8_t *)malloc((size_t)lw * lh * bpp);
                    if (lin) {
                        uint32_t yy;
                        xbox_unswizzle_rect(lin, srcp, lw, lh, bpp);
                        if (palettised) {
                            for (yy = 0; yy < lh; yy++) {
                                uint32_t *drow =
                                    (uint32_t *)(dstp + (size_t)yy * lr.Pitch);
                                const uint8_t *srow = lin + (size_t)yy * lw;
                                uint32_t xx;
                                for (xx = 0; xx < lw; xx++)
                                    drow[xx] = pal[srow[xx]];
                            }
                        } else {
                            for (yy = 0; yy < lh; yy++)
                                memcpy(dstp + (size_t)yy * lr.Pitch,
                                       lin + (size_t)yy * lw * bpp,
                                       (size_t)lw * bpp);
                        }
                        free(lin);
                    }
                } else if (palettised) {
                    uint32_t yy;
                    for (yy = 0; yy < lh; yy++) {
                        uint32_t *drow = (uint32_t *)(dstp + (size_t)yy * lr.Pitch);
                        const uint8_t *srow = srcp + (size_t)yy * lp;
                        uint32_t xx;
                        for (xx = 0; xx < lw; xx++) drow[xx] = pal[srow[xx]];
                    }
                } else {
                    uint32_t row_bytes = lw * bpp, yy;
                    for (yy = 0; yy < lh; yy++)
                        memcpy(dstp + (size_t)yy * lr.Pitch,
                               srcp + (size_t)yy * lp, row_bytes);
                }
                g_pg.dyn_tex->lpVtbl->UnlockRect(g_pg.dyn_tex, l);
            }
            srcp += lsize;
            lw = (lw > 1) ? lw / 2 : 1;
            lh = (lh > 1) ? lh / 2 : 1;
        }
    }
    return g_pg.dyn_tex;
}

/* Called by the recompiled D3D draw wrapper before each inline draw. */
void pgraph_d3d11_set_inline_hint(uint32_t nverts, uint32_t declared_dw)
{
    g_pg.hint_verts = nverts;
    g_pg.hint_declared_dw = declared_dw;
}

void pgraph_d3d11_set_vertex_layout(uint32_t stride_dw, int pos_dw,
                                    int uv_off, int color_off)
{
    if (stride_dw >= 2 && stride_dw <= 16) {
        g_pg.vert_stride = stride_dw;
        g_pg.layout_pos_dw = pos_dw;
        g_pg.layout_uv_off = uv_off;
        g_pg.layout_color_off = color_off;
    }
}

/* DOA2U DIAG counters */
uint32_t g_mhist[0x800];
uint32_t g_xmode, g_xmode_n[4];
uint32_t g_dstat[16][3];
uint32_t g_census[12];

uint32_t g_texfmt[64], g_texnull[4];
/* Read one vertex attribute out of guest memory.
 *
 * Slot layout comes from SET_VERTEX_DATA_ARRAY_FORMAT: type in bits 0-3,
 * component count in bits 4-7, stride in bits 8-31. A count of 0 means the
 * slot is disabled. */
static int nv_fetch_attr(int slot, uint32_t index, float out[4], uint32_t *out_color)
{
    extern ptrdiff_t g_xbox_mem_offset;
    uint32_t fmt = g_pg.attr_fmt[slot];
    uint32_t type = fmt & 0xF;
    uint32_t count = (fmt >> 4) & 0xF;
    uint32_t stride = fmt >> 8;
    uint32_t base = g_pg.attr_off[slot];
    uint32_t addr;
    const uint8_t *p;
    uint32_t c;

    if (count == 0 || base == 0 || base >= 0x08000000u)
        return 0;
    addr = base + index * stride;
    if (addr + 16u > 0x08000000u)
        return 0;
    p = (const uint8_t *)((uintptr_t)addr + g_xbox_mem_offset);

    out[0] = out[1] = out[2] = 0.0f;
    out[3] = 1.0f;

    switch (type) {
    case 2:   /* float32 */
        for (c = 0; c < count && c < 4; c++) {
            float f;
            memcpy(&f, p + c * 4, 4);
            out[c] = f;
        }
        return 1;
    case 0:   /* normalised ubyte, D3D (BGRA) order -- a colour */
        if (out_color) {
            memcpy(&c, p, 4);
            *out_color = c;
        }
        for (c = 0; c < count && c < 4; c++)
            out[c] = (float)p[c] * (1.0f / 255.0f);
        return 1;
    case 4:   /* normalised ubyte, OGL (RGBA) order */
        if (out_color)
            *out_color = ((uint32_t)p[3] << 24) | ((uint32_t)p[0] << 16) |
                         ((uint32_t)p[1] << 8)  |  (uint32_t)p[2];
        for (c = 0; c < count && c < 4; c++)
            out[c] = (float)p[c] * (1.0f / 255.0f);
        return 1;
    case 1: { /* normalised signed short */
        for (c = 0; c < count && c < 4; c++) {
            int16_t v;
            memcpy(&v, p + c * 2, 2);
            out[c] = (float)v * (1.0f / 32767.0f);
        }
        return 1;
    }
    case 5: { /* signed short, unscaled */
        for (c = 0; c < count && c < 4; c++) {
            int16_t v;
            memcpy(&v, p + c * 2, 2);
            out[c] = (float)v;
        }
        return 1;
    }
    default:
        return 0;
    }
}

/* Object space -> screen space for the fixed-function path.
 *
 * The game feeds these draws through fixed-function T&L, so the hardware
 * applies the composite matrix, then the perspective divide, then the
 * viewport. Reproduce that here and hand the result to the D3D8 layer as
 * pre-transformed XYZRHW, which is what the rest of this path expects. */
static void nv_transform_clip(const float in[4], OutputVertex *v,
                              int apply_composite);

static void nv_transform_position(const float in[4], OutputVertex *v)
{
    nv_transform_clip(in, v, g_pg.composite_seen);
}

/* Clip space -> screen space.
 *
 * `apply_composite` selects the fixed-function path (multiply by the composite
 * matrix first); the transform-program path passes 0 because the program has
 * already produced clip-space coordinates in o[0]. */
static void nv_transform_clip(const float in[4], OutputVertex *v,
                              int apply_composite)
{
    float c[4];
    float w, inv;
    float sx, sy, sz, ox, oy, oz;
    int i;

    if (apply_composite) {
        /* NV2A convention: SET_COMPOSITE_MATRIX row i holds the coefficients
         * of output component i (the D3D runtime uploads the row-vector
         * matrix transposed), so c[i] = dot(in, row i). The game's row 3 is the
         * camera forward axis plus distance -- w = view-space z -- which
         * only reads correctly this way round; dotting the columns instead
         * put the 2^24 z-scale into w and collapsed every draw to a point. */
        for (i = 0; i < 4; i++)
            c[i] = in[0] * g_pg.composite[i * 4 + 0] +
                   in[1] * g_pg.composite[i * 4 + 1] +
                   in[2] * g_pg.composite[i * 4 + 2] +
                   in[3] * g_pg.composite[i * 4 + 3];
    } else {
        c[0] = in[0]; c[1] = in[1]; c[2] = in[2]; c[3] = in[3];
    }

    {   /* DOA2U DIAG: DOA2U_FLIPW=1 negates the homogeneous position (same
         * screen point, opposite w) to test which side the composite's w
         * row puts the intended scene on. */
        static int s_flip = -1;
        if (s_flip < 0) { const char *e = getenv("DOA2U_FLIPW"); s_flip = (e && *e == '1'); }
        if (s_flip && apply_composite) { c[0] = -c[0]; c[1] = -c[1]; c[2] = -c[2]; c[3] = -c[3]; }
    }
    w = c[3];
    inv = (w != 0.0f) ? (1.0f / w) : 1.0f;

    if (apply_composite) {
        /* Fixed-function path. The Xbox D3D runtime folds the viewport
         * (w/2, -h/2, x0+w/2, y0+h/2 and the z-buffer range) into the
         * composite matrix itself -- the game's [MATMUL] shows proj x viewport
         * being multiplied before upload -- so c.xy/w is already the pixel
         * position and c.z/w is already in z-buffer units. Only z needs
         * normalising to D3D's [0,1], by the zeta format's range.
         *
         * SET_VIEWPORT_SCALE/OFFSET are deliberately NOT consulted here.
         * They are the transform constants c[58]/c[59], which the fixed
         * pipeline never reads, and the game overwrites them mid-scene (zeros,
         * then unit vectors). Dividing z by scale.z = 0 made every vertex
         * z = inf, and the "no viewport" fallback below rescaled pixel
         * coordinates as NDC (x ~ 340,000): that was the black screen after
         * the title showcase reload. */
        float zrange = (((g_pg.surface_fmt >> 4) & 0xF) == 1) ? 65535.0f : 16777215.0f;
        /* The composite carries the viewport's SCALE but not its ORIGIN: the
         * device's projection-viewport matrix (dev+0x5A0) has m03 = m13 = 0,
         * verified identical in cxbx. NV097_SET_VIEWPORT_OFFSET supplies the
         * origin, and ignoring it drew character select's portrait relative to
         * the surface instead of its window -- measured 96 surface units left
         * and 146 up, against a portrait viewport origin of (94,154) and an
         * offset register reading (95,155). Scale was already correct: the
         * face measures 0.380 of the window in both the port and cxbx.
         *
         * Guarded, because the game overwrites these registers mid-scene with
         * zeros and unit vectors -- only a plausible on-surface origin is
         * applied, and (0,0) costs nothing. */
        {   float ox = g_pg.vp_offset[0], oy = g_pg.vp_offset[1];
            unsigned sw = (g_pg.surface_clip_h >> 16) & 0xFFFF;
            unsigned sh = (g_pg.surface_clip_v >> 16) & 0xFFFF;
            if (!(ox >= 0.0f && oy >= 0.0f && sw && sh &&
                  ox < (float)sw && oy < (float)sh)) { ox = 0.0f; oy = 0.0f; }
            v->x   = c[0] * inv + ox;
            v->y   = c[1] * inv + oy;
        }
        v->z   = (c[2] * inv) / zrange;
        v->rhw = inv;
        return;
    }

    sx = g_pg.vp_scale[0]; sy = g_pg.vp_scale[1]; sz = g_pg.vp_scale[2];
    ox = g_pg.vp_offset[0]; oy = g_pg.vp_offset[1]; oz = g_pg.vp_offset[2];
    if (sx == 0.0f && sy == 0.0f) {
        /* No viewport programmed: treat the output as NDC over the full
         * surface, as before. */
        v->x   = c[0] * inv * 320.0f + 320.0f;
        v->y   = c[1] * inv * -240.0f + 240.0f;
        v->z   = c[2] * inv;
        v->rhw = inv;
        return;
    }

    /* The Xbox D3D runtime folds the viewport (w/2, -h/2, x0+w/2, y0+h/2,
     * and the 2^24-1 z range) into the composite matrix itself -- the game's
     * [MATMUL] shows proj x viewport being multiplied before upload -- so the
     * transform output divided by w is already the screen position. The
     * SET_VIEWPORT_SCALE/OFFSET registers describe that mapping for the
     * hardware's clipper; applying them again scaled everything by another
     * 360x. Only z still needs normalising from the viewport z range to
     * D3D's [0,1]. */
    (void)ox; (void)oy; (void)oz; (void)sx; (void)sy;
    v->x   = c[0] * inv;
    v->y   = c[1] * inv;
    v->z   = (sz != 0.0f) ? (c[2] * inv) / sz : c[2] * inv;
    v->rhw = inv;
}

/* Build one OutputVertex from the bound vertex arrays. */
/* DOA2U DIAG: did the transform-program path actually run for the last vertex,
 * and what did it produce? Reported on the [PG-ARRAY] line. */
int   g_vp_used, g_vpn;
float g_mv[16];
float g_vp_in0[4], g_vp_out0[4], g_fix_in0[4];
float g_vp_d0[4], g_vp_t0[4], g_vpbb[8];

/* Is the fixed-function composite matrix something we could actually transform
 * with? An unset or all-zero matrix maps every vertex onto the viewport
 * centre, which is never what the game meant. */
static int nv_composite_usable(void)
{
    int i;
    if (!g_pg.composite_seen)
        return 0;
    for (i = 0; i < 16; i++)
        if (g_pg.composite[i] != 0.0f)
            return 1;
    return 0;
}

static uint32_t nv_pack_color(const float c[4])
{
    int a = (int)(c[3] * 255.0f + 0.5f);
    int r = (int)(c[0] * 255.0f + 0.5f);
    int g = (int)(c[1] * 255.0f + 0.5f);
    int b = (int)(c[2] * 255.0f + 0.5f);
    if (a < 0) a = 0; if (a > 255) a = 255;
    if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255;
    if (b < 0) b = 0; if (b > 255) b = 255;
    return ((uint32_t)a << 24) | ((uint32_t)r << 16) |
           ((uint32_t)g << 8)  |  (uint32_t)b;
}

/* Fixed-function vertex lighting (NV2A / Xbox D3D8 fixed pipeline).
 *
 * The runtime uploads light directions/positions already in eye space and
 * folds the material colours into the per-light colours. Eye-space position
 * and normal come from the model-view matrix (wire row i = coefficients of
 * output i, the same convention as the composite). The game's world matrices are
 * rigid (|row| = 1 in every model-view matrix the game uploads), so the normal can use the same
 * rows as the position. Output: D0 = clamp(sceneAmbient + emission +
 * sum_i att_i * (amb_i + dif_i * max(0, N.L_i))), alpha = material alpha.
 * Specular (D1) is not produced yet. */
/* Per-batch fixed-function context.
 *
 * Every input below is GPU state, which cannot change between BEGIN and END,
 * so it is evaluated once per batch instead of once (or three times) per
 * vertex: nv_composite_usable() scans the matrix, and every lit vertex used to
 * re-normalise every directional light. Same operations in the same order on
 * the same inputs, so every output bit is what the per-vertex code produced. */
typedef struct {
    int      composite_ok;   /* nv_composite_usable() */
    int      run_program;    /* take the transform-program path */
    int      lit;            /* fixed-function lighting with at least one light */
    int      ambient_only;   /* lighting on, every light off: ambient + emission */
    uint32_t ltype[4];       /* 0 off, 1 directional, 2 local, 3 spot */
    float    dir_n[4][3];    /* directional lights, normalised */
    int      has_local;      /* any local/spot light: eye-space P is needed */
} NvBatchCtx;

static void nv_batch_ctx_init(NvBatchCtx *c)
{
    int i;
    c->composite_ok = nv_composite_usable();
    c->run_program  = g_pg.vp.have_program &&
                      ((g_pg.xform_mode & 3) == 2 || !c->composite_ok);
    c->lit          = g_pg.lighting && (g_pg.light_mask & 0xFF) && c->composite_ok;
    c->ambient_only = g_pg.lighting && !(g_pg.light_mask & 0xFF) &&
                      !g_pg.color_material && c->composite_ok;
    c->has_local = 0;
    for (i = 0; i < 4; i++) {
        c->ltype[i] = (g_pg.light_mask >> (2 * i)) & 3;
        if (c->ltype[i] == 1) {
            float L[3], len;
            L[0] = g_pg.light[i].dir[0]; L[1] = g_pg.light[i].dir[1]; L[2] = g_pg.light[i].dir[2];
            len = sqrtf(L[0] * L[0] + L[1] * L[1] + L[2] * L[2]);
            if (len > 1e-12f) { L[0] /= len; L[1] /= len; L[2] /= len; }
            c->dir_n[i][0] = L[0]; c->dir_n[i][1] = L[1]; c->dir_n[i][2] = L[2];
        } else if (c->ltype[i] >= 2) {
            c->has_local = 1;
        }
    }
}

static uint32_t nv_light_vertex(const float pos[4], const float nrm[3],
                                const NvBatchCtx *ctx)
{
    const float *mv = g_mv;
    float P[3], N[3], col[3], len;
    int i, k;
    /* The eye-space position only feeds local and spot lights. */
    if (ctx->has_local)
        for (i = 0; i < 3; i++)
            P[i] = pos[0] * mv[i * 4 + 0] + pos[1] * mv[i * 4 + 1] + pos[2] * mv[i * 4 + 2] + mv[i * 4 + 3];
    for (i = 0; i < 3; i++)
        N[i] = nrm[0] * mv[i * 4 + 0] + nrm[1] * mv[i * 4 + 1] + nrm[2] * mv[i * 4 + 2];
    len = sqrtf(N[0] * N[0] + N[1] * N[1] + N[2] * N[2]);
    if (len > 1e-12f) { N[0] /= len; N[1] /= len; N[2] /= len; }
    for (k = 0; k < 3; k++) col[k] = g_pg.scene_ambient[k] + g_pg.emission[k];
    for (i = 0; i < 4; i++) {
        uint32_t type = ctx->ltype[i];
        float L[3], att = 1.0f, ndotl;
        if (!type) continue;
        if (type == 1) {
            L[0] = ctx->dir_n[i][0]; L[1] = ctx->dir_n[i][1]; L[2] = ctx->dir_n[i][2];
        } else {
            float d;
            L[0] = g_pg.light[i].pos[0] - P[0]; L[1] = g_pg.light[i].pos[1] - P[1]; L[2] = g_pg.light[i].pos[2] - P[2];
            d = sqrtf(L[0] * L[0] + L[1] * L[1] + L[2] * L[2]);
            if (d <= 1e-12f) continue;
            L[0] /= d; L[1] /= d; L[2] /= d;
            {   float a0 = g_pg.light[i].att[0], a1 = g_pg.light[i].att[1], a2 = g_pg.light[i].att[2];
                float den = a0 + a1 * d + a2 * d * d;
                att = (den > 1e-12f) ? 1.0f / den : 1.0f; }
            if (g_pg.light[i].range > 0.0f && d > g_pg.light[i].range) att = 0.0f;
        }
        ndotl = N[0] * L[0] + N[1] * L[1] + N[2] * L[2];
        if (ndotl < 0.0f) ndotl = 0.0f;
        for (k = 0; k < 3; k++)
            col[k] += att * (g_pg.light[i].amb[k] + g_pg.light[i].dif[k] * ndotl);
    }
    {   float c4[4] = { col[0], col[1], col[2], g_pg.material_alpha };
        return nv_pack_color(c4);
    }
}

static void nv_build_array_vertex(uint32_t index, OutputVertex *v,
                                  const NvBatchCtx *ctx)
{
    float pos[4], tex[4], col[4], nrm[4];
    uint32_t colour = 0xFFFFFFFFu;

    memset(v, 0, sizeof(*v));
    v->color = 0xFFFFFFFFu;
    v->rhw = 1.0f;

    /* MODE_PROGRAM: attribute 0 is an object-space position that only becomes
     * clip space after the uploaded transform program runs. The game draws every
     * post-movie screen this way. Treating those positions as fixed-function
     * input multiplied them by a composite matrix the game never set, which
     * collapsed every batch onto the viewport centre -- ~500 draws a frame,
     * all degenerate, and a black window.
     *
     * The mode bit alone is not a reliable selector here: the pushbuffer
     * carries SET_TRANSFORM_EXECUTION_MODE = FIXED for many of these draws
     * while every piece of fixed-function transform state it also carries is
     * zero -- the composite matrix streams in as 16 zero dwords and the
     * viewport scale as (0, -0, 0, 0). A zero matrix cannot be a real
     * transform, so when the game has a program loaded and has given the
     * fixed pipeline nothing to work with, run the program. */
    if (ctx->run_program) {
        float in[NV2A_VP_NUM_INPUT][4];
        float out[NV2A_VP_NUM_OUTPUT][4];
        int s;
        for (s = 0; s < NV2A_VP_NUM_INPUT; s++) {
            /* Unwritten input registers read as (0,0,0,1) on hardware. */
            in[s][0] = in[s][1] = in[s][2] = 0.0f;
            in[s][3] = 1.0f;
            nv_fetch_attr(s, index, in[s], NULL);
        }
        if (nv2a_vp_execute(&g_pg.vp, in, out)) {
            {   /* Raw program output, accumulated over the batch: the only
                 * way to tell screen space from clip space is the range of
                 * o[0] across a whole draw. */
                extern int g_vp_used, g_vpn;
                extern float g_vp_in0[4], g_vp_out0[4], g_vp_d0[4], g_vp_t0[4];
                extern float g_vpbb[8];
                const float *o = out[NV2A_VP_OUT_POS];
                int k;
                g_vp_used = 1;
                if (g_vpn == 0) {
                    for (k = 0; k < 4; k++) { g_vpbb[k*2] = g_vpbb[k*2+1] = o[k]; }
                    memcpy(g_vp_in0, in[0], sizeof g_vp_in0);
                    memcpy(g_vp_out0, o, sizeof g_vp_out0);
                    memcpy(g_vp_d0, out[NV2A_VP_OUT_D0], sizeof g_vp_d0);
                    memcpy(g_vp_t0, out[NV2A_VP_OUT_T0], sizeof g_vp_t0);
                } else {
                    for (k = 0; k < 4; k++) {
                        if (o[k] < g_vpbb[k*2])   g_vpbb[k*2]   = o[k];
                        if (o[k] > g_vpbb[k*2+1]) g_vpbb[k*2+1] = o[k];
                    }
                }
                g_vpn++;
            }
            /* A transform program writes o[0] already in screen space with
             * 1/w in o[0].w -- the Xbox D3D8 runtime folds the viewport
             * transform into the program through c[-38]/c[-37], which is why
             * the hardware viewport registers arrive as (0, -0, 0, 0). That is
             * exactly D3D's XYZRHW, so hand it straight through instead of
             * running the fixed-function viewport transform over it. */
            v->x   = out[NV2A_VP_OUT_POS][0];
            v->y   = out[NV2A_VP_OUT_POS][1];
            /* Program output z is in the viewport's z range (the XDK epilogue
             * scales by c[-38].z = SET_VIEWPORT_SCALE.z = 2^24-1), exactly as
             * the fixed-function path's output; normalise it the same way. */
            v->z   = (g_pg.vp_scale[2] != 0.0f) ? out[NV2A_VP_OUT_POS][2] / g_pg.vp_scale[2] : out[NV2A_VP_OUT_POS][2];
            v->rhw = out[NV2A_VP_OUT_POS][3];
            v->color = nv_pack_color(out[NV2A_VP_OUT_D0]);
            v->u = out[NV2A_VP_OUT_T0][0];
            v->v = out[NV2A_VP_OUT_T0][1];
            return;
        }
    }
    { extern int g_vp_used; g_vp_used = 0; }

    if (nv_fetch_attr(0, index, pos, NULL)) {
        {   extern float g_fix_in0[4];
            memcpy(g_fix_in0, pos, sizeof g_fix_in0); }
        nv_transform_position(pos, v);
        /* Fixed-function lighting: only when the guest enabled it, has a
         * light on, and supplies normals; otherwise diffuse stays white as
         * before. */
        if (ctx->lit && nv_fetch_attr(2, index, nrm, NULL))
            v->color = nv_light_vertex(pos, nrm, ctx);
        /* Lighting on with every light off still lights: the NV2A outputs
         * scene ambient + emission with the material alpha. The beach's palm
         * shadow relies on it -- the fronds are drawn into the shadow surface
         * that way (ambient and emission 0) to get a black silhouette with
         * the texture's alpha. Left white, they rendered in the palm's own
         * green and the projected shadow showed green fronds. */
        else if (ctx->ambient_only) {
            float c4[4] = { g_pg.scene_ambient[0] + g_pg.emission[0],
                            g_pg.scene_ambient[1] + g_pg.emission[1],
                            g_pg.scene_ambient[2] + g_pg.emission[2],
                            g_pg.material_alpha };
            v->color = nv_pack_color(c4);
        }
    }
    if (nv_fetch_attr(3, index, col, &colour))
        v->color = colour;
    if (nv_fetch_attr(9, index, tex, NULL)) {
        v->u = tex[0];
        v->v = tex[1];
    }
}

/* Render state + texture binding shared by both submission paths.
 *
 * Factored out of submit_draw so the vertex-array path applies exactly the
 * same state; it previously existed only on the inline path. */
/* Does the draw in front of us have a texcoord attribute at all? An inline
 * vertex whose SET_VERTEX_DATA_ARRAY_FORMAT declares no texcoord slot cannot
 * be textured: the game's character-select panel borders, window backing quad and
 * background gradient are position+diffuse only (5 dwords), and binding the
 * stale dynamic texture for them sampled texel (0,0) and multiplied them away.
 * The array path leaves this set, so only the inline path can clear it. */
static int g_nv_draw_has_uv = 1;
/* DOA2U: 1 while submit_draw (the inline 2D path) is applying state. */
static int g_nv_draw_inline = 0;
/* Stage 1 from the guest's texture-stage table when it is CURRENT x TFACTOR
 * with no texture of its own (the beach's palm shadow is 0x99FFFFFF, the
 * Kowloon street's additive wet-road sheen 0x23FFFFFF: a pink gradient blended
 * SRC_ALPHA/ONE whose alpha the factor scales to 14%). Without this stage the
 * sheen drew at full strength and the road went milky white. Colour and alpha
 * are honoured separately; any other stage-1 configuration (env maps, texture
 * args) is left to the existing single-stage rules, and the stage is switched
 * off for every other draw so nothing leaks. */
static void nv_apply_stage1_factor(IDirect3DDevice8 *dev)
{
    uint32_t cop = (g_pg.tss1_color >> 12) & 0x1F, ca1 = (g_pg.tss1_color >> 6) & 0x3F, ca2 = g_pg.tss1_color & 0x3F;
    uint32_t aop = (g_pg.tss1_alpha >> 12) & 0x1F, aa1 = (g_pg.tss1_alpha >> 6) & 0x3F, aa2 = g_pg.tss1_alpha & 0x3F;
#define NV_FACTOR_MOD(op, x, y) ((op) == 4 && ((((x) & 0xF) == 3 && ((y) & 0xF) == 1) || (((x) & 0xF) == 1 && ((y) & 0xF) == 3)))
    int cf = NV_FACTOR_MOD(cop, ca1, ca2), af = NV_FACTOR_MOD(aop, aa1, aa2);
    int keep_alpha = (aop == 1) || ((aop == 2 || aop == 3) && ((aop == 2 ? aa1 : aa2) & 0xF) == 1);
#undef NV_FACTOR_MOD
    if (!g_pg.tss1_valid || g_nv_draw_inline || !cf || !(af || keep_alpha)) {
        dev->lpVtbl->SetTextureStageState(dev, 1, 1 /*COLOROP*/, 1 /*DISABLE*/);
        return;
    }
    dev->lpVtbl->SetRenderState(dev, D3DRS_TEXTUREFACTOR, (g_pg.tfactor_hi << 24) | g_pg.tfactor_lo);
    dev->lpVtbl->SetTexture(dev, 1, NULL);
    dev->lpVtbl->SetTextureStageState(dev, 1, 1 /*COLOROP*/,   4 /*MODULATE*/);
    dev->lpVtbl->SetTextureStageState(dev, 1, 2 /*COLORARG1*/, 1 /*CURRENT*/);
    dev->lpVtbl->SetTextureStageState(dev, 1, 3 /*COLORARG2*/, 3 /*TFACTOR*/);
    dev->lpVtbl->SetTextureStageState(dev, 1, 4 /*ALPHAOP*/,   af ? 4 /*MODULATE*/ : 1 /*DISABLE: keep current*/);
    dev->lpVtbl->SetTextureStageState(dev, 1, 5 /*ALPHAARG1*/, 1 /*CURRENT*/);
    dev->lpVtbl->SetTextureStageState(dev, 1, 6 /*ALPHAARG2*/, 3 /*TFACTOR*/);
}

static uint32_t g_pg_surf_coff;   /* defined with g_pg_surf_pitch below */
static uint32_t g_pg_blend_color = 0xFFFFFFFFu;   /* NV097_SET_BLEND_COLOR */
/* Colour surfaces that are the frame buffer (both flip buffers), recorded by
 * nv_sync_render_target. A draw sampling one of them reads the frame on
 * screen -- the previous presented frame. */
static uint32_t g_fb_offs[4];
static int      g_fb_offs_n;
static int nv_samples_framebuffer(uint32_t tex_off)
{
    int k;
    tex_off &= 0x07FFFFFFu;
    if (!tex_off) return 0;
    if (g_pg_surf_coff && tex_off == (g_pg_surf_coff & 0x07FFFFFFu)) return 1;
    for (k = 0; k < g_fb_offs_n; k++) if (g_fb_offs[k] == tex_off) return 1;
    return 0;
}
/* What the draw-state code needs to know about the batch's vertices, and
 * the vertex edits it asks for in return. The CPU path fills the summary
 * from its finished out[] and applies the post-ops to it; the GPU path
 * derives the summary from the batch's inputs and hands the post-ops to the
 * vertex shader as constants. */
typedef struct {
    int   all_zero;          /* every vertex colour is 0x00000000 */
    float max_u, max_v;      /* largest texcoord in the batch */
} NvDrawSummary;
typedef struct {
    int      fold;           /* multiply every colour by fold_factor, (c*f+127)/255 per channel */
    uint32_t fold_factor;
    float    uv_div_w, uv_div_h;   /* divide every texcoord by these (0 = none) */
} NvPostOps;

static void nv_apply_draw_state(IDirect3DDevice8 *dev, const NvDrawSummary *sum,
                                NvPostOps *post)
{
    if (g_nv_draw_inline && !g_pg.depth_test && !d3d8_OffscreenTargetActive()) {
        /* first 2D screen-space draw of the frame: capture the 3D scene for
         * Omega's after-image before the HUD and text land on it (no-op
         * unless the effect is running) */
        extern void d3d8_SnapshotSceneForAfterImage(void);
        d3d8_SnapshotSceneForAfterImage();
    }
    nv_apply_stage1_factor(dev);
    /* The fade-to-black quad carries an OPAQUE BLACK diffuse (0xFF000000) with
     * the stage disabled; all_zero compares the whole 32-bit colour, so that
     * read as a valid diffuse and the fade took its alpha from whatever
     * texture was still bound -- the character's hair. */
    int diffuse_all_zero = sum->all_zero;

    /* Alpha blending stays on for the 2D menu path. Depth follows the
     * guest: the game's 3D screens draw with SET_DEPTH_TEST_ENABLE and rely on
     * the z-buffer for ordering -- with the test forced off, whatever the
     * camera-facing stage wall drawn last covered the characters and the
     * frame went black seconds after the title appeared. The XYZRHW z is the
     * transformed z/w in [0,1], so the compat layer's depth buffer works. */
    dev->lpVtbl->SetRenderState(dev, D3DRS_ZENABLE, g_pg.depth_test ? TRUE : FALSE);
    dev->lpVtbl->SetRenderState(dev, D3DRS_ZWRITEENABLE, g_pg.depth_mask ? TRUE : FALSE);
    {
        DWORD zf = (g_pg.depth_func >= 0x200 && g_pg.depth_func <= 0x207)
                 ? (g_pg.depth_func - 0x200) + 1 : 4 /*LESSEQUAL*/;
        dev->lpVtbl->SetRenderState(dev, D3DRS_ZFUNC, zf);
        {   extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_t, s_nt, s_m, s_nm;
            if (g_pg.depth_test) s_t++; else s_nt++;
            if (g_pg.depth_mask) s_m++; else s_nm++;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                 s_t = s_nt = s_m = s_nm = 0;
            }
        }
    }
    dev->lpVtbl->SetRenderState(dev, D3DRS_LIGHTING, FALSE);
    /* Face culling. D3DCULL names the screen winding to discard, so the
     * mapping depends on which winding the game calls front-facing. Culling
     * both faces has no D3D equivalent, so that degenerates to no culling
     * rather than to guessing. */
    {
        DWORD cm = 1 /*NONE*/;
        if (g_pg.cull_enable && g_pg.cull_face != 0x408 && g_pg.draw_mode != 1 /* points never cull */) {
            int front_cw = (g_pg.front_face == 0x900);
            int cull_front = (g_pg.cull_face == 0x404);
            /* front CW: front faces are CW, so culling front discards CW */
            cm = (front_cw == cull_front) ? 2 /*CW*/ : 3 /*CCW*/;
        }
        dev->lpVtbl->SetRenderState(dev, D3DRS_CULLMODE, cm);
        {   extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_on, s_off;
            if (cm != 1) s_on++; else s_off++;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                 s_on = s_off = 0;
            }
        }
    }

    /* Stencil. */
    {
        DWORD sf = (g_pg.stencil_func >= 0x200 && g_pg.stencil_func <= 0x207)
                 ? (g_pg.stencil_func - 0x200) + 1 : 8 /*ALWAYS*/;
        {   /* Stencil shadows build their volume with colour writes off
             * (half the shadow draws); unapplied, the volume rasterised. */
            uint32_t cm = g_pg.color_mask;
            DWORD cwe = 0;
            if (cm & NV097_SET_COLOR_MASK_RED_WRITE_ENABLE)   cwe |= 1;
            if (cm & NV097_SET_COLOR_MASK_GREEN_WRITE_ENABLE) cwe |= 2;
            if (cm & NV097_SET_COLOR_MASK_BLUE_WRITE_ENABLE)  cwe |= 4;
            if (cm & NV097_SET_COLOR_MASK_ALPHA_WRITE_ENABLE) cwe |= 8;
            dev->lpVtbl->SetRenderState(dev, D3DRS_COLORWRITEENABLE, cwe);
        }
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILENABLE, g_pg.stencil_enable ? TRUE : FALSE);
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILFUNC, sf);
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILREF, g_pg.stencil_ref & 0xFF);
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILMASK, g_pg.stencil_func_mask & 0xFF);
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILWRITEMASK, g_pg.stencil_mask & 0xFF);
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILFAIL, nv_d3d_stencil_op(g_pg.stencil_fail));
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILZFAIL, nv_d3d_stencil_op(g_pg.stencil_zfail));
        dev->lpVtbl->SetRenderState(dev, D3DRS_STENCILPASS, nv_d3d_stencil_op(g_pg.stencil_zpass));
        {   extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_on, s_off;
            if (g_pg.stencil_enable) s_on++; else s_off++;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                 s_on = s_off = 0;
            }
        }
    }
    /* Blending. This used to be forced on with SRCALPHA/INVSRCALPHA for every
     * draw while SET_BLEND_ENABLE/SFACTOR/DFACTOR were tracked and never read.
     * Measured on the title stage: the guest asks for blending OFF on ~65% of
     * its batches and uses two functions when it is on (SRCALPHA/INVSRCALPHA
     * and the additive SRCALPHA/ONE). Forcing it on made every opaque surface
     * depend on an alpha channel it was not written for, and rendered the
     * additive pass as an ordinary blend. */
    {
        static DWORD s_sf = D3DBLEND_SRCALPHA, s_df = D3DBLEND_INVSRCALPHA;
        DWORD sf = nv2a_blend_to_d3d(g_pg.blend_sfactor);
        DWORD df = nv2a_blend_to_d3d(g_pg.blend_dfactor);
        if (sf) s_sf = sf;          /* a non-factor is parse garbage: keep the */
        if (df) s_df = df;          /* last value the guest really programmed  */
        dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHABLENDENABLE,
                                    g_pg.blend_enable ? TRUE : FALSE);
        dev->lpVtbl->SetRenderState(dev, D3DRS_SRCBLEND, s_sf);
        dev->lpVtbl->SetRenderState(dev, D3DRS_DESTBLEND, s_df);
        if (s_sf >= D3DBLEND_BLENDFACTOR || s_df >= D3DBLEND_BLENDFACTOR) {
            /* CONSTANT_ALPHA factors use the blend colour's alpha for every
             * channel, CONSTANT_COLOR its rgba. */
            extern void d3d8_SetBlendFactor(float r, float g, float b, float a);
            uint32_t c = g_pg_blend_color;
            float a = (float)((c >> 24) & 0xFF) / 255.0f;
            int alpha_only = g_pg.blend_sfactor == 0x8003 || g_pg.blend_sfactor == 0x8004 ||
                             g_pg.blend_dfactor == 0x8003 || g_pg.blend_dfactor == 0x8004;
            if (alpha_only) d3d8_SetBlendFactor(a, a, a, a);
            else d3d8_SetBlendFactor((float)((c >> 16) & 0xFF) / 255.0f,
                                     (float)((c >> 8) & 0xFF) / 255.0f,
                                     (float)(c & 0xFF) / 255.0f, a);
        }
    }

    /* Alpha test. The game drives it hard -- SET_ALPHA_FUNC arrives ~785,000
     * times in a couple of minutes -- and without it the punch-through
     * texels of a DXT1 decal or foliage quad are drawn as opaque black
     * instead of being discarded. */
    {
        DWORD func = (g_pg.alpha_func >= 0x200 && g_pg.alpha_func <= 0x207)
                   ? (g_pg.alpha_func - 0x200) + 1 : 8 /*ALWAYS*/;
        dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHATESTENABLE, g_pg.alpha_test ? TRUE : FALSE);
        dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHAFUNC, func);
        dev->lpVtbl->SetRenderState(dev, D3DRS_ALPHAREF, g_pg.alpha_ref & 0xFF);
        {   extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_on, s_off;
            if (g_pg.alpha_test) s_on++; else s_off++;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                 s_on = s_off = 0;
            }
        }
    }

    /* Set FVF for pre-transformed 2D with texture */
    dev->lpVtbl->SetVertexShader(dev, D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

    /* Bind texture from Global.txd based on NV2A VRAM offset.
     * We match the push buffer's SET_TEXTURE_OFFSET value to known
     * Global.txd entries identified via xemu dimension/format matching. */
    if (g_textures_loaded) {
        /* Build lookup table on first use */
        if (!g_pg.texture_lookup_done) {
            g_pg.texture_lookup_done = 1;
            /* Dump all texture names+sizes for reference */
            for (int ti = 0; ti < g_global_txd.count; ti++) {
            }
        }

        /* Match NV2A VRAM offset → Global.txd name (from xemu analysis).
         * Offsets identified by capturing PGRAPH texture registers from xemu
         * and matching by texture dimension + format code. */
        IDirect3DTexture8 *tex = NULL;
        uint32_t vram_off = g_pg.tex[0].offset;
        switch (vram_off) {
            case 0x03C1ED00: tex = txd_find(&g_global_txd, "B3Logo"); break;      /* 256x64 A1R5G5B5 */
            case 0x03C24700: tex = txd_find(&g_global_txd, "bg"); break;           /* 64x32 DXT1 */
            case 0x03C24B80: tex = txd_find(&g_global_txd, "big_curve"); break;    /* 128x128 DXT5 */
            case 0x03C7BE00: tex = txd_find(&g_global_txd, "Buttons"); break;      /* 128x64 DXT5 */
            case 0x03C95700: tex = txd_find(&g_global_txd, "dpad"); break;          /* 32x16 DXT5 */
            case 0x03C95980: tex = txd_find(&g_global_txd, "FE"); break;            /* 32x32 DXT5 */
            case 0x03CA1A80: tex = txd_find(&g_global_txd, "small_curve"); break;   /* 32x32 DXT5 */
            case 0x03D57000: tex = txd_find(&g_global_txd, "box_curve"); break;     /* 32x32 DXT5 */
            case 0x03CB9200: tex = txd_find(&g_global_txd, "grid"); break;          /* 16x16 DXT1 */
            case 0x02EC0400:
                /* Render target / framebuffer texture — skip this draw entirely.
                 * In xemu this shows the looping background video; in our recomp
                 * the background is rendered separately. Drawing this as vertex-color
                 * produces a solid white quad that washes out everything. */
                dev->lpVtbl->EndScene(dev);
                g_pg.inline_count = 0;
                return;  /* Skip draw */
            case 0x021C4100:
                /* Font atlas — create from captured DXT5 data on first use */
                if (!g_pg.font_atlas) {
                    g_pg.font_atlas = create_dxt5_texture(dev,
                        FONT_ATLAS_WIDTH, FONT_ATLAS_HEIGHT,
                        font_atlas_dxt5, FONT_ATLAS_SIZE);
                }
                tex = g_pg.font_atlas;
                break;
            case 0: tex = NULL; break;  /* No texture set — vertex color only */
            default: tex = NULL; break; /* Unknown — render with vertex color only */
        }

        if (tex) {
            dev->lpVtbl->SetTexture(dev, 0, (IDirect3DBaseTexture8 *)tex);
            dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, 4 /*MODULATE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 2 /*TEXTURE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 3 /*COLORARG2*/, 0 /*DIFFUSE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 4 /*MODULATE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 2 /*TEXTURE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 6 /*ALPHAARG2*/, 0 /*DIFFUSE*/);
            nv_apply_tex_address(dev, 0);
        } else {
            /* No texture — use vertex color only */
            dev->lpVtbl->SetTexture(dev, 0, NULL);
            dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, 2 /*SELECTARG1*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 0 /*DIFFUSE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 2 /*SELECTARG1*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 0 /*DIFFUSE*/);
        }
    } else {
        /* No Global.txd: bind a dynamic texture built from the guest
         * memory the game pointed SET_TEXTURE_OFFSET at (the movie frame
         * surface, loading screens, etc.). Vertex-color-only when absent. */
        IDirect3DTexture8 *dtex;
        {   /* sub_0004E9A0 draws the shadows as SELECTARG1(D3DTA_TFACTOR),
             * no texture, factor = opacity << 24. Otherwise the stage keeps
             * the last draw's texture. Pure-alpha only: the fade quad also
             * disables the stage but colours from the diffuse. */
            uint32_t tf = g_pg.comb_factor0[0];
            if (!g_pg.tex[0].enabled && (tf & 0x00FFFFFFu) == 0 &&
                tf != 0xFFFFFFFFu) {
                dev->lpVtbl->SetTexture(dev, 0, NULL);
                dev->lpVtbl->SetRenderState(dev, D3DRS_TEXTUREFACTOR, tf);
                dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/,   2 /*SELECTARG1*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 3 /*D3DTA_TFACTOR*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/,   2 /*SELECTARG1*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 3 /*D3DTA_TFACTOR*/);
                return;
            }
        }
        {   /* A draw that samples a surface the game itself rendered into
             * reads the HOST target that owns that guest offset -- the floor's
             * reflection pass, the attract sequence's captured frames -- since
             * the guest memory behind it is never written. Matching on the key
             * matters: these surfaces used to share one host texture selected
             * by whichever was most recent, which handed a fullscreen quad the
             * reflection pass and drew the stage over the whole screen. */
            extern int d3d8_BindOffscreenTexture(uint32_t key, UINT stage);
            extern int d3d8_HasOffscreenTexture(uint32_t key);
            extern int d3d8_BindPrevFrame(UINT stage);
            /* Sampling a frame buffer (the Omega boss fight's after-image
             * effect reads the other flip buffer): the last presented host
             * frame, not the never-written guest memory behind it. */
            int samples_fb = nv_samples_framebuffer(g_pg.tex[0].offset);
            if (g_pg.tex[0].offset &&
                (samples_fb || (!d3d8_OffscreenTargetActive() &&
                                d3d8_HasOffscreenTexture(g_pg.tex[0].offset)))) {
                int use_diffuse = !diffuse_all_zero;
                if (samples_fb) {
                    /* The frame buffer is a linear (rect) surface, sampled
                     * with texel coordinates -- Omega's after-image pass
                     * reads it with u 0..720, v 0..480 into its 512x512
                     * buffer. The host copy is sampled 0..1. */
                    float tw, th;
                    if (sum->max_u > 1.5f || sum->max_v > 1.5f) {
                        tw = (float)(g_pg.tex[0].image_rect >> 16);
                        th = (float)(g_pg.tex[0].image_rect & 0xFFFF);
                        if (tw < 16.0f) tw = 720.0f;
                        if (th < 16.0f) th = 480.0f;
                        post->uv_div_w = tw;
                        post->uv_div_h = th;
                    }
                }
                /* A second combiner stage with no texture of its own scales
                 * the result by the combiner factor. The beach's palm shadow
                 * is drawn that way -- stage 1 = CURRENT x TFACTOR with
                 * TFACTOR 0x99FFFFFF, i.e. 60% opacity -- and without it every
                 * shadow landed on the sand as solid black. The texture stage
                 * below modulates by the diffuse, so folding the factor into
                 * the vertex colour gives the same product. */
                if (use_diffuse && (g_pg.comb_control & 0xFF) >= 2 && !g_pg.tex[1].enabled) {
                    post->fold = 1;
                    post->fold_factor = g_pg.comb_factor0[0];
                }
                dev->lpVtbl->SetTexture(dev, 0, NULL);
                if (samples_fb ? d3d8_BindPrevFrame(0)
                               : d3d8_BindOffscreenTexture(g_pg.tex[0].offset, 0)) {
                    dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, use_diffuse ? 4 : 2);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 2 /*TEXTURE*/);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 3 /*COLORARG2*/, 0 /*DIFFUSE*/);
                    /* Alpha is texture x diffuse (the game's ALPHAOP is
                     * MODULATE). Taking the diffuse alone drew the beach's
                     * palm-shadow surface -- cleared to transparent black --
                     * as an opaque black block on the sand. */
                    dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, use_diffuse ? 4 : 2);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 2 /*TEXTURE*/);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 6 /*ALPHAARG2*/, 0 /*DIFFUSE*/);
                    nv_apply_tex_address(dev, 0);
                    return;
                }
            }
        }
        dtex = get_dynamic_texture(dev);
        /* DOA2U: a 2D draw whose texture stage is DISABLED is flat colour,
         * whatever its vertex layout carries. The fight UI submits its
         * health-bar fills, the pause menu's highlight bar and title box
         * and the button backings as 13-dword vertices (a texcoord slot
         * present) with the stage off; binding the previous draw's
         * texture here modulated every one of them away. Only rgb-black
         * quads survived, which is why the dark rows showed and the
         * coloured ones did not. The array (3D) path keeps its rule. */
        /* Stage 0 disabled by the guest: flat vertex colour on every path.
         * The 3D path used to keep the previously bound texture and
         * modulate the geometry by it; the console samples nothing there.
         * (The 2D path had this rule already, see the health bars above.) */
        if (!g_pg.tex[0].enabled) dtex = NULL;
        if (dtex) {
            /* The game configures the pixel pipeline through the register
             * combiners, which this translator does not implement; it
             * substitutes the fixed-function equivalent. Modulating by the
             * diffuse register is only valid when the game actually supplies
             * one. The game leaves vertex attribute 3 at zero for these draws and
             * sources colour from the combiners instead, so modulating turned
             * every textured pixel into transparent black -- the whole screen.
             * When the diffuse register is degenerate, take the texture
             * directly rather than multiplying the image away. */
            int use_diffuse = !diffuse_all_zero;
            /* Does the bound image carry an alpha channel worth sampling? */
            int tex_has_alpha =
                (g_pg.dyn_fmt == (uint32_t)D3DFMT_LIN_A8R8G8B8 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_LIN_A1R5G5B5 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_LIN_A4R4G4B4 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_A8R8G8B8 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_A1R5G5B5 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_A4R4G4B4 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_A8 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_A8L8 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_DXT1 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_DXT3 ||
                 g_pg.dyn_fmt == (uint32_t)D3DFMT_DXT5);
            /* An alpha-only image carries no colour: A8 samples as
             * (0,0,0,A). The glyph atlas the in-scene dialogue is drawn from
             * is one of these -- 128x128 A8, one quad per character, diffuse
             * 0xFFFFFF with the fade in the alpha byte -- so modulating the
             * texture's RGB into it painted every letter black with the
             * right shape. The colour has to come from the diffuse, and only
             * the alpha from the image. */
            int tex_alpha_only = (g_pg.dyn_fmt == (uint32_t)D3DFMT_A8);
            int mask_stage = 0;
            dev->lpVtbl->SetTexture(dev, 0, (IDirect3DBaseTexture8 *)dtex);
            dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/,
                                              (tex_alpha_only || !use_diffuse)
                                                  ? 2 /*SELECTARG1*/ : 4 /*MODULATE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/,
                                              tex_alpha_only ? 0 /*DIFFUSE*/ : 2 /*TEXTURE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 3 /*COLORARG2*/, 0 /*DIFFUSE*/);
            /* SELECTARG1(TEXTURE) with stage 1 disabled: colour from the texture
             * alone (beach clouds). Characters pair it with a stage-1 env map
             * and keep texture x diffuse. */
            if (!g_nv_draw_inline && g_pg.gtss_valid && !tex_alpha_only && (g_pg.gtss & (1u << 17)) &&
                ((g_pg.gtss >> 12) & 0x1F) == 2 && ((g_pg.gtss >> 6) & 0x3F) == 2) {
                dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, 2 /*SELECTARG1*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 2 /*TEXTURE*/);
            }
            /* Stage 0 MODULATEALPHA_ADDCOLOR(TEXTURE, DIFFUSE): the castle's
             * stone walls (DXT5, alpha blend on). The image's alpha is a
             * lighting mask -- colour = texture + texture.a * lit diffuse --
             * not opacity. Treating the stage as texture x diffuse made the
             * walls near-black, and feeding the same alpha into
             * SRC_ALPHA/INV_SRC_ALPHA made them see-through: the sky showed
             * where the tower walls should be. The blend alpha comes from the
             * guest's own stage-0 alpha op (marker 0xAB) below. */
            if (!g_nv_draw_inline && g_pg.gtss_valid && !tex_alpha_only &&
                ((g_pg.gtss >> 12) & 0x1F) == 18 && ((g_pg.gtss >> 6) & 0x3F) == 2 && (g_pg.gtss & 0x3F) == 0) {
                dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, 18 /*MODULATEALPHA_ADDCOLOR*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 2 /*TEXTURE*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 3 /*COLORARG2*/, 0 /*DIFFUSE*/);
                mask_stage = 1;
            }
            if (mask_stage && g_pg.tss0_alpha_valid) {
                uint32_t aop = (g_pg.tss0_alpha >> 12) & 0x1F;
                uint32_t aa1 = (g_pg.tss0_alpha >> 6) & 0x3F, aa2 = g_pg.tss0_alpha & 0x3F;
                uint32_t sel = (aop == 2) ? aa1 : (aop == 3) ? aa2 : 0;
                if (aop == 4) {                                   /* MODULATE(TEXTURE, DIFFUSE) */
                    dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 4 /*MODULATE*/);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 2 /*TEXTURE*/);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 6 /*ALPHAARG2*/, 0 /*DIFFUSE*/);
                } else {                                          /* DISABLE / SELECTARGn: one source */
                    dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 2 /*SELECTARG1*/);
                    dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, ((sel & 0xF) == 2) ? 2 /*TEXTURE*/ : 0 /*DIFFUSE*/);
                }
            } else
            if (use_diffuse && tex_has_alpha && (g_pg.blend_enable || g_pg.alpha_test)) {
                /* A draw whose image has its own alpha wants texture *
                 * diffuse, the Xbox default. Selecting the diffuse alpha
                 * alone made the 2D overlay's transparent surround opaque,
                 * so the corner logo drew as a black box with the lettering
                 * inside it -- and it did the same to every alpha-tested
                 * DXT1 surface: the alpha test is the other consumer of the
                 * texture's alpha, not just blending. */
                dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 4 /*MODULATE*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 2 /*TEXTURE*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 6 /*ALPHAARG2*/, 0 /*DIFFUSE*/);
            } else {
                dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 2 /*SELECTARG1*/);
                dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/,
                                                  use_diffuse ? 0 /*DIFFUSE*/ : 2 /*TEXTURE*/);
            }
            nv_apply_tex_address(dev, 0);
        } else {
            dev->lpVtbl->SetTexture(dev, 0, NULL);
            dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/, 2 /*SELECTARG1*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, 0 /*DIFFUSE*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/, 2 /*SELECTARG1*/);
            dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, 0 /*DIFFUSE*/);
        }
    }

}

/* CPU path: summarise the finished vertices, apply the state, then apply the
 * vertex edits the state code asked for. Same values in the same order as
 * when the edits lived inside nv_apply_draw_state. */
static void nv_apply_draw_state_cpu(IDirect3DDevice8 *dev, OutputVertex *out,
                                    uint32_t out_vert_count)
{
    NvDrawSummary sum;
    NvPostOps post;
    uint32_t i;
    sum.all_zero = 1;
    sum.max_u = 0.0f; sum.max_v = 0.0f;
    for (i = 0; i < out_vert_count; i++) {
        if (out[i].color != 0) sum.all_zero = 0;
        if (out[i].u > sum.max_u) sum.max_u = out[i].u;
        if (out[i].v > sum.max_v) sum.max_v = out[i].v;
    }
    memset(&post, 0, sizeof post);
    nv_apply_draw_state(dev, &sum, &post);
    if (post.uv_div_w != 0.0f) {
        for (i = 0; i < out_vert_count; i++) {
            out[i].u /= post.uv_div_w;
            out[i].v /= post.uv_div_h;
        }
    }
    if (post.fold) {
        uint32_t f = post.fold_factor;
        for (i = 0; i < out_vert_count; i++) {
            uint32_t c = out[i].color, r = 0, sh;
            for (sh = 0; sh < 32; sh += 8)
                r |= ((((c >> sh) & 0xFFu) * ((f >> sh) & 0xFFu) + 127u) / 255u) << sh;
            out[i].color = r;
        }
    }
}

/* Near-plane clipping for the fixed-function array path.
 *
 * The NV2A clips in clip space before the divide; the D3D8 layer only takes
 * pre-transformed XYZRHW, which cannot represent a vertex behind the eye
 * (w <= 0): its screen position is mirrored and a triangle straddling the
 * near plane sweeps across the frame. The game's title/attract camera sits inside
 * the stage, so most batches straddle. Rebuild each triangle in clip space
 * from the XYZRHW output (W = 1/rhw, X = x*W, ...), clip it against the D3D
 * near plane Zc >= 0 (Sutherland-Hodgman, attributes interpolated in clip
 * space where they are linear), and re-project the pieces. Batches that lie
 * entirely in front are drawn untouched. */
typedef struct { float X, Y, Z, W; float r, g, b, a; float u, v; } ClipVert;

static void nv_clip_from_out(const OutputVertex *o, ClipVert *c)
{
    float W = (o->rhw != 0.0f) ? 1.0f / o->rhw : 1.0f;
    c->X = o->x * W; c->Y = o->y * W; c->Z = o->z * W; c->W = W;
    c->a = (float)((o->color >> 24) & 255); c->r = (float)((o->color >> 16) & 255);
    c->g = (float)((o->color >> 8) & 255);  c->b = (float)(o->color & 255);
    c->u = o->u; c->v = o->v;
}

static void nv_clip_to_out(const ClipVert *c, OutputVertex *o)
{
    float inv = (c->W != 0.0f) ? 1.0f / c->W : 1.0f;
    int a = (int)(c->a + 0.5f), r = (int)(c->r + 0.5f), g = (int)(c->g + 0.5f), b = (int)(c->b + 0.5f);
    o->x = c->X * inv; o->y = c->Y * inv; o->z = c->Z * inv; o->rhw = inv;
    if (a < 0) a = 0; if (a > 255) a = 255; if (r < 0) r = 0; if (r > 255) r = 255;
    if (g < 0) g = 0; if (g > 255) g = 255; if (b < 0) b = 0; if (b > 255) b = 255;
    o->color = ((uint32_t)a << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    o->u = c->u; o->v = c->v;
}

static void nv_clip_lerp(const ClipVert *a, const ClipVert *b, float t, ClipVert *o)
{
    const float *fa = (const float *)a, *fb = (const float *)b; float *fo = (float *)o;
    int i;
    for (i = 0; i < (int)(sizeof(ClipVert) / sizeof(float)); i++)
        fo[i] = fa[i] + (fb[i] - fa[i]) * t;
}

/* Clip one convex polygon against one half-space. `sel` picks the clip
 * coordinate (0 = W, 1 = Z); the kept side is coord >= eps. */
static int nv_clip_plane(const ClipVert *in, int n_in, int sel, float eps,
                         ClipVert *out)
{
    int n = 0, i;
    for (i = 0; i < n_in; i++) {
        const ClipVert *a = &in[i], *b = &in[(i + 1) % n_in];
        float da = (sel ? a->Z : a->W) - eps;
        float db = (sel ? b->Z : b->W) - eps;
        int ina = (da >= 0.0f), inb = (db >= 0.0f);
        if (ina) out[n++] = *a;
        if (ina != inb) {
            float t = da / (da - db);
            nv_clip_lerp(a, b, t, &out[n++]);
        }
    }
    return n;
}

/* Clip one triangle against Wc > 0 and Zc >= 0; writes up to 3 triangles.
 *
 * Clipping on Zc alone was not enough. Zc here is the pre-divide depth
 * (o->z * W), so for a vertex behind the eye -- W < 0 -- a positive
 * view-space depth term comes back out as a POSITIVE Zc and the vertex was
 * kept, with its screen position mirrored through the origin. Those are the
 * triangles that sweep across the frame. Wc > 0 is the plane that actually
 * separates in front of the eye from behind it, and XYZRHW cannot represent
 * the far side of it at all. */
#define NV_CLIP_MAXTRI 3
static int nv_clip_triangle(const ClipVert in[3], OutputVertex *dst)
{
    ClipVert a[8], b[8];
    int n;
    /* Clip against W > NEAR_EPS, not W > 0.
     *
     * nv_clip_to_out divides by W, so a vertex interpolated exactly onto a
     * W>1e-6 plane comes out at x/1e-6 -- millions of pixels -- and the
     * rasteriser stretches it across the frame. That is the smeared geometry
     * on the character-select screen: [CLIP] showed inputs with w = -0.0006
     * producing clipped outputs at x = 3.7e6.
     *
     * W here is view-space z (the composite's row 3 is the camera forward axis
     * plus distance), and the game's projection carries a near plane of ~0.3, so
     * anything nearer than this epsilon is already behind the near plane and
     * must not survive the divide. Kept well under the real near distance so
     * only genuinely degenerate vertices are removed. */
    n = nv_clip_plane(in, 3, 0, 1e-2f, a);         /* W > near epsilon */
    if (n < 3) return 0;
    n = nv_clip_plane(a, n, 1, 0.0f, b);           /* Z >= 0 */
    if (n < 3) return 0;
    {   int i, t = 0;
        for (i = 2; i < n; i++) {                  /* fan the result */
            nv_clip_to_out(&b[0], &dst[t * 3 + 0]);
            nv_clip_to_out(&b[i - 1], &dst[t * 3 + 1]);
            nv_clip_to_out(&b[i], &dst[t * 3 + 2]);
            t++;
        }
        return t;
    }
}

static int nv_clip_triangle_old(const ClipVert in[3], OutputVertex *dst)
{
    ClipVert poly[4]; int n = 0, i;
    for (i = 0; i < 3; i++) {
        const ClipVert *a = &in[i], *b = &in[(i + 1) % 3];
        int ina = (a->Z >= 0.0f), inb = (b->Z >= 0.0f);
        if (ina) poly[n++] = *a;
        if (ina != inb) {
            float t = a->Z / (a->Z - b->Z);
            nv_clip_lerp(a, b, t, &poly[n++]);
        }
    }
    if (n < 3) return 0;
    nv_clip_to_out(&poly[0], &dst[0]); nv_clip_to_out(&poly[1], &dst[1]); nv_clip_to_out(&poly[2], &dst[2]);
    if (n == 3) return 1;
    dst[3] = dst[0]; dst[4] = dst[2]; nv_clip_to_out(&poly[3], &dst[5]);
    return 2;
}

/* Does any vertex of the batch lie behind the near plane / eye? */
static int nv_batch_needs_clip(const OutputVertex *out, uint32_t n)
{
    uint32_t i;
    for (i = 0; i < n; i++)
        if (out[i].rhw <= 0.0f || out[i].z < 0.0f) return 1;
    return 0;
}

/* Expand strip/fan/list into clipped triangle-list vertices. Returns the
 * vertex count written to dst (capacity 6 per source triangle). */
static uint32_t nv_clip_batch(const OutputVertex *out, uint32_t n, int prim, OutputVertex *dst)
{
    uint32_t tri, ntri, o = 0;
    switch (prim) {
    case D3DPT_TRIANGLELIST:  ntri = n / 3; break;
    case D3DPT_TRIANGLESTRIP:
    case D3DPT_TRIANGLEFAN:   ntri = (n >= 3) ? n - 2 : 0; break;
    default: return 0;
    }
    for (tri = 0; tri < ntri; tri++) {
        uint32_t i0, i1, i2; ClipVert cv[3];
        if (prim == D3DPT_TRIANGLELIST)      { i0 = tri * 3; i1 = i0 + 1; i2 = i0 + 2; }
        else if (prim == D3DPT_TRIANGLEFAN)  { i0 = 0; i1 = tri + 1; i2 = tri + 2; }
        else { /* strip: keep winding consistent */
            if (tri & 1) { i0 = tri + 1; i1 = tri; i2 = tri + 2; }
            else         { i0 = tri; i1 = tri + 1; i2 = tri + 2; }
        }
        nv_clip_from_out(&out[i0], &cv[0]); nv_clip_from_out(&out[i1], &cv[1]); nv_clip_from_out(&out[i2], &cv[2]);
        o += 3 * (uint32_t)nv_clip_triangle(cv, &dst[o]);
    }
    return o;
}
/* DOA2U: follow the guest's colour surface. The Xbox D3D renders a 256x256
 * reflection/shadow pass into a texture every frame, then switches back to
 * one of its two frame buffers for the scene. The surface pitch
 * (NV097_SET_SURFACE_PITCH, always programmed before the colour offset)
 * identifies the target regardless of method order: the frame buffers are
 * the widest surfaces the guest has ever drawn to (pitch 0xC00), the
 * reflection texture is narrower (0x400). Anything narrower than the frame
 * buffer gets an offscreen D3D11 target of its own size; the frame buffer
 * width restores the swap chain. Keying this on the clip rectangle or on
 * learning offsets both misclassified one of the two frame buffers at some
 * point, which routed the scene offscreen and froze the picture. */
static uint32_t g_pg_surf_coff, g_pg_surf_pitch;
extern int  d3d8_OffscreenTargetActive(void);
/* Map guest screen coordinates onto the host backbuffer.
 *
 * Everything this module emits is in the guest's framebuffer space, which
 * the game sets to 720x480 through SET_SURFACE_CLIP. The D3D8 layer's
 * pre-transformed path divides by the HOST backbuffer size, so with a 640-wide
 * window every guest x was scaled by 720/640 and the right 11% of the picture
 * fell off the screen -- which is why the "3" of the corner logo was missing.
 * Scale here, where the guest surface size is known, rather than changing what
 * XYZRHW means to the D3D8 layer. */
/* Per-vertex dword count for an INLINE_ARRAY, summed from the attribute
 * slots the guest enabled through SET_VERTEX_DATA_ARRAY_FORMAT. This is
 * what the hardware itself unpacks the array with, so it is layout truth
 * for the draw in front of us rather than whatever a previous draw left
 * in vert_stride. Slot format: type bits 0-3, component count bits 4-7
 * (0 = slot disabled). Returns 0 if no slot is enabled. */
static uint32_t nv_inline_layout_from_attrs(int *pos_dw, int *uv_off, int *color_off)
{
    uint32_t off = 0; int slot;
    if (pos_dw)    *pos_dw = 2;
    if (uv_off)    *uv_off = -1;
    if (color_off) *color_off = -1;
    for (slot = 0; slot < 16; slot++) {
        uint32_t fmt = g_pg.attr_fmt[slot];
        uint32_t type = fmt & 0xFu, count = (fmt >> 4) & 0xFu, dw;
        if (count == 0) continue;
        switch (type) {
        case 2:  dw = count;            break;   /* float per component */
        case 0:                                 /* UB_D3D  (4 bytes)   */
        case 4:  dw = 1;                break;   /* UB_OGL  (4 bytes)   */
        case 1:                                 /* S1  short normalised */
        case 5:  dw = (count + 1) / 2;  break;   /* S32K short          */
        case 6:  dw = 1;                break;   /* CMP packed          */
        default: dw = count;            break;
        }
        /* Slot 0 is position, 3 diffuse, 9 texcoord0 -- the same slot
         * semantics the recompiled DrawVerticesUP wrapper walks. */
        if      (slot == 0) { if (pos_dw)    *pos_dw    = (int)dw;  }
        else if (slot == 3) { if (color_off) *color_off = (int)off; }
        else if (slot == 9) { if (uv_off)    *uv_off    = (int)off; }
        off += dw;
    }
    return off;
}

/* Hand NV097_SET_WINDOW_CLIP to the host as a scissor rectangle.
 *
 * This is the NV2A's hardware scissor and the game leans on it: character select
 * programs 94,154-701,625 for the portrait pass and 0,0-1439,959 for the 2D
 * layer. The rect is in SURFACE pixels -- 1440x960 while the 2x2 supersampled
 * frame buffer is bound -- so it maps onto the back buffer exactly the way
 * nv_fit_to_backbuffer maps the vertices. Ignoring it let the portrait spill
 * across the whole screen instead of sitting inside its window.
 *
 * XMAX/YMAX are inclusive. Type 1 is an exclusion rectangle, which nothing
 * here needs; leave the scissor wide open rather than guess at it.
 * Returns 1 if a rect narrower than the whole target was set. */
static int nv_apply_window_clip(void)
{
    extern void d3d8_SetScissorRect(int x, int y, int w, int h);
    unsigned gw = (g_pg.surface_clip_h >> 16) & 0xFFFF;
    unsigned gh = (g_pg.surface_clip_v >> 16) & 0xFFFF;
    unsigned bw = d3d8_GetBackbufferWidth(), bh = d3d8_GetBackbufferHeight();
    uint32_t hz = g_pg.window_clip_h[0], vt = g_pg.window_clip_v[0];
    unsigned x0, y0, x1, y1;
    int sx0, sy0, sx1, sy1;

    if (g_pg.window_clip_type != 0) return 0;
    if (!gw || !gh || !bw || !bh) return 0;
    x0 =  hz        & 0xFFFu; x1 = (hz >> 16) & 0xFFFu;
    y0 =  vt        & 0xFFFu; y1 = (vt >> 16) & 0xFFFu;
    if (x1 <= x0 || y1 <= y0) return 0;                 /* never programmed */
    if (x0 == 0 && y0 == 0 && x1 + 1 >= gw && y1 + 1 >= gh) return 0;  /* whole surface */

    sx0 = (int)((float)x0 * (float)bw / (float)gw);
    sy0 = (int)((float)y0 * (float)bh / (float)gh);
    sx1 = (int)(((float)x1 + 1.0f) * (float)bw / (float)gw);
    sy1 = (int)(((float)y1 + 1.0f) * (float)bh / (float)gh);
    if (sx1 <= sx0 || sy1 <= sy0) return 0;
    d3d8_SetScissorRect(sx0, sy0, sx1 - sx0, sy1 - sy0);
    return 1;
}

/* `screen_space` marks the inline 2D layer, whose vertices the game submits
 * pre-transformed in DISPLAY pixels. Those are not the pixels of the surface
 * that happens to be bound: on character select the game turns on 2x2
 * supersampling and the frame buffer becomes 1440x960, so dividing the
 * overlay by SET_SURFACE_CLIP put the whole UI at half scale in the top-left
 * quadrant. Array-path vertices go through the composite matrix, which
 * already carries the (supersampled) NV2A viewport, so they keep mapping
 * from the clip. */
static void nv_fit_to_backbuffer(OutputVertex *out, uint32_t n, int screen_space)
{
    unsigned gw = (g_pg.surface_clip_h >> 16) & 0xFFFF;
    unsigned gh = (g_pg.surface_clip_v >> 16) & 0xFFFF;
    unsigned bw = d3d8_GetBackbufferWidth();
    unsigned bh = d3d8_GetBackbufferHeight();
    float sx, sy;
    uint32_t i;

    /* Only for the swap chain: an offscreen target really is the size of the
     * clip that made it, so its draws must keep using the clip. */
    if (screen_space && !d3d8_OffscreenTargetActive()) {
        extern int doa2u_guest_display_size(unsigned *w, unsigned *h);
        unsigned dw, dh;
        if (doa2u_guest_display_size(&dw, &dh)) { gw = dw; gh = dh; }
    }

    if (!gw || !gh || !bw || !bh) return;
    if (gw == bw && gh == bh) return;
    sx = (float)bw / (float)gw;
    sy = (float)bh / (float)gh;
    for (i = 0; i < n; i++) {
        out[i].x *= sx;
        out[i].y *= sy;
    }
}

static void nv_sync_render_target(void)
{
    extern int  d3d8_SetOffscreenTarget(uint32_t key, unsigned w, unsigned h);
    extern void d3d8_RestoreDefaultTarget(void);
    /* Frame buffers are 720 px wide (pitch 0xC00); the reflection texture is
     * 256. A learned "widest seen" bound was poisoned once by a wider
     * surface and then classed the frame buffer itself as offscreen. */
    unsigned pw = (g_pg_surf_pitch & 0xFFFF) / 4;
    unsigned h  = (g_pg.surface_clip_v >> 16) & 0xFFFF;
    extern uint32_t g_doa2u_offrt_offs[8]; extern int g_doa2u_offrt_n;
    if (pw < 16 || pw > 2048) return;             /* pitch not programmed yet */
    if (g_doa2u_offrt_n) {
        /* Colour-offset routing: the SetRenderTarget wrapper records every
         * texture surface the game renders into (the reflection target in
         * stage 0x3F is 720x480 with the frame buffer's pitch, which the
         * pitch rule below misrouted onto the swap chain). Everything else --
         * including both flip buffers, which rotate at Swap without a
         * SetRenderTarget call -- is the swap chain. */
        int k, is_fb = 1;
        for (k = 0; k < g_doa2u_offrt_n; k++) if (g_doa2u_offrt_offs[k] == g_pg_surf_coff) is_fb = 0;
        if (is_fb) {
            /* remember the flip buffers (see nv_samples_framebuffer) */
            int seen = 0;
            for (k = 0; k < g_fb_offs_n; k++) if (g_fb_offs[k] == (g_pg_surf_coff & 0x07FFFFFFu)) seen = 1;
            if (!seen && g_fb_offs_n < 4) g_fb_offs[g_fb_offs_n++] = g_pg_surf_coff & 0x07FFFFFFu;
            if (d3d8_OffscreenTargetActive()) d3d8_RestoreDefaultTarget();
        } else {
            /* Full-size targets take the host back-buffer size so the
             * viewport (which stays the host's) covers the whole texture. */
            unsigned w = (g_pg.surface_clip_h >> 16) & 0xFFFF;
            if (w < 16 || w > 2048) w = pw;
            if (h < 16 || h > 2048) h = w;
            if (w >= 512) { w = d3d8_GetBackbufferWidth(); h = d3d8_GetBackbufferHeight(); }
            d3d8_SetOffscreenTarget(g_pg_surf_coff, w, h);
        }
        return;
    }
    if (pw >= 512) {
        if (d3d8_OffscreenTargetActive()) d3d8_RestoreDefaultTarget();
    } else {
        if (h < 16 || h > 2048) h = pw;
        d3d8_SetOffscreenTarget(g_pg_surf_coff, pw, h);
    }
}

/* Growable heap scratch for the array path's vertex batches. A 65K-vertex
 * batch is 1.8 MB and its clip output up to three times that: far too much
 * for _alloca on a fiber stack. Slot 0 = transformed batch, 1 = clipped. */
static OutputVertex *nv_scratch_verts(int slot, uint32_t count)
{
    static OutputVertex *buf[2]; static uint32_t cap[2];
    if (cap[slot] < count) {
        OutputVertex *nb = (OutputVertex *)realloc(buf[slot], (size_t)count * sizeof(OutputVertex));
        if (!nb) return NULL;
        buf[slot] = nb; cap[slot] = count;
    }
    return buf[slot];
}

/* Xbox D3DTOP -> the compat layer's D3DTOP. Identical through
 * BLENDDIFFUSEALPHA (12); above that the Xbox orders the blend ops
 * differently (BLENDCURRENTALPHA 13, BLENDTEXTUREALPHA 14, BLENDFACTORALPHA
 * 15, DOTPRODUCT3 22), and the shader implements ops 2..15 and 24. Anything
 * it lacks falls back to MODULATE, as the shader itself does. */
static uint32_t nv_xbox_texop(uint32_t x)
{
    static const uint8_t map[] = {
        4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,   /* 0..12 as-is */
        15,   /* 13 BLENDCURRENTALPHA */
        13,   /* 14 BLENDTEXTUREALPHA */
        14,   /* 15 BLENDFACTORALPHA */
        13,   /* 16 BLENDTEXTUREALPHAPM: nearest supported */
        4, 4, 4, 4, 4,   /* 17..21 PREMODULATE / MODULATE*_ADD*: unsupported */
        24,   /* 22 DOTPRODUCT3 */
        4, 4, 4, 4 };    /* 23..26 MULTIPLYADD / LERP / bump: unsupported */
    return (x < sizeof map) ? map[x] : 4u;
}

/* Draw from the bound vertex arrays (the title-screen path). */
/* One point -> one screen-space sprite quad (two triangles), sized by the
 * NV2A point rule (xemu vsh-ff.c):
 *   d = |eye-space position|
 *   t = 1/sqrt(P0 + P1 d + P2 d^2) + P6
 *   s = clamp(t P3 + P7, min(P7, 63.875), min(P3 + P7, 63.875))
 * or SET_POINT_SIZE / 8 when the params are off. Sizes are in guest
 * render-target pixels; nv_fit_to_backbuffer scales the corners with
 * everything else. The hardware feeds the sprite's 0..1 coordinates to
 * texture unit 3 only, which is why the game binds the flake / ember there.
 * A point behind the eye (w <= 0) or outside the depth range has no XYZRHW
 * form and is dropped (returns 0). `pos` is the object-space position for
 * the distance term, or NULL when the draw has none to offer. */
static int nv_point_quad(const OutputVertex *v, const float *pos, OutputVertex *out)
{
    const float *pp = g_pg.point_params, *mv = g_mv;
    float s, h;
    if (!(v->rhw > 1e-6f) || !(v->x == v->x) || !(v->y == v->y) || !(v->z >= 0.0f) || v->z > 1.0f) return 0;
    if (g_pg.point_params_en && pos) {
        float e, d2 = 0.0f, d, q, t, lo, hi; int r;
        for (r = 0; r < 3; r++) {
            e = mv[r * 4 + 0] * pos[0] + mv[r * 4 + 1] * pos[1] + mv[r * 4 + 2] * pos[2] + mv[r * 4 + 3];
            d2 += e * e;
        }
        d = sqrtf(d2);
        q = pp[0] + pp[1] * d + pp[2] * d2;
        t = (q > 0.0f) ? 1.0f / sqrtf(q) + pp[6] : 1e9f;
        lo = (pp[7] < 63.875f) ? pp[7] : 63.875f;
        hi = (pp[3] + pp[7] < 63.875f) ? pp[3] + pp[7] : 63.875f;
        s = t * pp[3] + pp[7];
        if (!(s >= lo)) s = lo;
        if (s > hi) s = hi;
    } else {
        s = (float)(g_pg.point_size & 0x1FF) / 8.0f;
        if (s < 1.0f) s = 1.0f;
    }
    h = s * 0.5f;
    out[0] = *v; out[0].x = v->x - h; out[0].y = v->y - h; out[0].u = 0.0f; out[0].v = 0.0f;
    out[1] = *v; out[1].x = v->x + h; out[1].y = v->y - h; out[1].u = 1.0f; out[1].v = 0.0f;
    out[2] = *v; out[2].x = v->x - h; out[2].y = v->y + h; out[2].u = 0.0f; out[2].v = 1.0f;
    out[3] = out[2];
    out[4] = out[1];
    out[5] = *v; out[5].x = v->x + h; out[5].y = v->y + h; out[5].u = 1.0f; out[5].v = 1.0f;
    return 1;
}

/* Render state for a point-sprite batch. Sprite texture: texture unit 3,
 * combined by the guest's stage-3 ops. Bound on host stage 0 the way cxbx
 * does it. The unit's control0 enable bit is not consulted: the game never sets
 * it for any unit but 0 (measured), cxbx's HLE never reads it, and the
 * sprite is textured on the real console. */
static void nv_apply_point_state(IDirect3DDevice8 *dev, const OutputVertex *out, uint32_t out_n)
{
    unsigned char saved[sizeof g_pg.tex[0]];
    uint32_t cop, ca1, ca2, aop, aa1, aa2;
    if (!(g_pg.point_smooth && g_pg.tex[3].offset)) {
        nv_apply_draw_state_cpu(dev, out, out_n);
        return;
    }
    memcpy(saved, &g_pg.tex[0], sizeof saved);
    memcpy(&g_pg.tex[0], &g_pg.tex[3], sizeof saved);
    g_pg.tex[0].enabled = 1;
    nv_apply_draw_state_cpu(dev, out, out_n);
    memcpy(&g_pg.tex[0], saved, sizeof saved);
    if (g_pg.tss3_valid) {
        cop = nv_xbox_texop((g_pg.tss3_color >> 12) & 0x1F); ca1 = (g_pg.tss3_color >> 6) & 0x3F; ca2 = g_pg.tss3_color & 0x3F;
        aop = nv_xbox_texop((g_pg.tss3_alpha >> 12) & 0x1F); aa1 = (g_pg.tss3_alpha >> 6) & 0x3F; aa2 = g_pg.tss3_alpha & 0x3F;
        if (cop == 1) { cop = 2; ca1 = 0; }   /* DISABLE: diffuse only */
        if (aop == 1) { aop = 2; aa1 = 0; }
    } else {
        cop = 2; ca1 = 2; ca2 = 0; aop = 2; aa1 = 2; aa2 = 0;
    }
    dev->lpVtbl->SetTextureStageState(dev, 0, 1 /*COLOROP*/,   cop);
    dev->lpVtbl->SetTextureStageState(dev, 0, 2 /*COLORARG1*/, ca1);
    dev->lpVtbl->SetTextureStageState(dev, 0, 3 /*COLORARG2*/, ca2);
    dev->lpVtbl->SetTextureStageState(dev, 0, 4 /*ALPHAOP*/,   aop);
    dev->lpVtbl->SetTextureStageState(dev, 0, 5 /*ALPHAARG1*/, aa1);
    dev->lpVtbl->SetTextureStageState(dev, 0, 6 /*ALPHAARG2*/, aa2);
}

/* Inline (DrawVerticesUP) POINTS through the fixed-function pipeline.
 *
 * The courtyard torch's embers are DrawVerticesUP(POINTLIST, ~45 points,
 * XYZ|DIFFUSE, 16-byte stride) with the 16x16 spark sprite on texture unit
 * 3 -- object-space positions the hardware transforms with the composite
 * matrix. The inline path only knew pre-transformed 2D vertices: it took
 * x = -10.9, y = -6.4 as pixel coordinates and issued a D3D11 point list
 * with count / 3 primitives, so nothing ever reached the screen. This
 * transforms each point exactly like the vertex-array path and expands it
 * into a sprite quad with the same size rule and stage-3 texture binding.
 * Returns 0 (caller falls through to the 2D path) when the draw is not a
 * fixed-function 3D one. */
static int submit_inline_points(IDirect3DDevice8 *dev, const uint32_t *src, uint32_t num_verts,
                                uint32_t stride, int lay_pos, int lay_col)
{
    OutputVertex *out;
    uint32_t i, o = 0;
    if (g_pg.draw_mode != 1 || lay_pos < 3 || (g_pg.xform_mode & 3) == 2 || !nv_composite_usable())
        return 0;
    out = nv_scratch_verts(0, num_verts * 6);
    if (!out) return 0;
    for (i = 0; i < num_verts; i++) {
        const uint32_t *p = src + i * stride;
        OutputVertex v; float pos[4];
        pos[0] = u2f(p[0]); pos[1] = u2f(p[1]); pos[2] = u2f(p[2]); pos[3] = 1.0f;
        memset(&v, 0, sizeof v);
        v.rhw = 1.0f;
        v.color = (lay_col >= 0) ? p[lay_col] : 0xFFFFFFFFu;
        nv_transform_position(pos, &v);
        if (nv_point_quad(&v, pos, out + o)) o += 6;
    }
    g_nv_draw_has_uv = 1;
    g_nv_draw_inline = 0;
    if (o == 0) { g_pg.gtss_valid = 0; g_pg.tss3_valid = 0; g_pg.tss1_valid = 0; g_pg.tss0_alpha_valid = 0; return 1; }
    nv_apply_point_state(dev, out, o);
    g_pg.gtss_valid = 0;
    g_pg.tss3_valid = 0;
    g_pg.tss1_valid = 0;
    g_pg.tss0_alpha_valid = 0;
    nv_fit_to_backbuffer(out, o, 0);
    {   DWORD prev_vs = 0;
        int clipped = nv_apply_window_clip();
        HRESULT got = dev->lpVtbl->GetVertexShader(dev, &prev_vs);
        dev->lpVtbl->SetVertexShader(dev, D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        dev->lpVtbl->BeginScene(dev);
        dev->lpVtbl->DrawPrimitiveUP(dev, D3DPT_TRIANGLELIST, o / 3, out, sizeof(OutputVertex));
        if (clipped) { extern void d3d8_ResetScissorRect(void); d3d8_ResetScissorRect(); }
        if (got == 0) dev->lpVtbl->SetVertexShader(dev, prev_vs);
    }
    g_pg.stats.draw_calls++;
    g_pg.stats.vertices_submitted += num_verts;
    return 1;
}

/* Vertex reuse within one batch.
 *
 * Indexed batches repeat most of their indices -- only 50-65% of the indices
 * in a frame are distinct -- and every repeat used to fetch, transform and
 * light the same vertex again. A vertex's output depends only on its index
 * and on GPU state, which is fixed for the batch, and nothing modifies out[]
 * until the whole batch is built (the colour fold, nv_fit_to_backbuffer and
 * the clipper all run afterwards), so a repeat copies the vertex built the
 * first time. The table is indexed by (index - lowest index of the batch):
 * the widest batch measured spans 21,646 indices, and a wider one simply
 * builds every vertex as before. */
#define NV_VREUSE_N 65536
static uint32_t s_vstamp[NV_VREUSE_N], s_vslot[NV_VREUSE_N], s_vgen;

static int nv_vreuse_begin(const uint32_t *idx, uint32_t n, uint32_t *lo_out)
{
    uint32_t i, lo = 0xFFFFFFFFu, hi = 0;
    for (i = 0; i < n; i++) {
        if (idx[i] < lo) lo = idx[i];
        if (idx[i] > hi) hi = idx[i];
    }
    if (n == 0 || hi - lo >= NV_VREUSE_N) return 0;
    if (++s_vgen == 0) { memset(s_vstamp, 0, sizeof s_vstamp); s_vgen = 1; }
    *lo_out = lo;
    return 1;
}

/* Build out[pos] for `index`, or copy it if this batch already built it. */
static void nv_vreuse_build(uint32_t index, uint32_t lo, OutputVertex *out,
                            uint32_t pos, const NvBatchCtx *ctx)
{
    uint32_t d = index - lo;
    if (s_vstamp[d] == s_vgen) {
        out[pos] = out[s_vslot[d]];
    } else {
        nv_build_array_vertex(index, &out[pos], ctx);
        s_vstamp[d] = s_vgen;
        s_vslot[d] = pos;
    }
}

/* ---- GPU fixed-function path --------------------------------------------
 *
 * Array draws that take the fixed-function path are handed to a vertex
 * shader (d3d8_nv2aff.h) as packed object-space vertices plus the per-draw
 * constants the CPU math used. The composite matrix, the viewport origin,
 * the window fit and the z range fold into one clip matrix:
 *   xs = (c.x/c.w + ox) * sx          (nv_transform_clip, nv_fit_to_backbuffer)
 *   clip.x = (2 xs / SW - 1) * c.w     (the XYZRHW vertex shader)
 *          = (2 sx / SW) (c.x + ox c.w) - c.w
 * and likewise for y (flipped) and z (c.z / zrange); the near-plane clipper's
 * two planes (W > 0.01, Z >= 0) become clip distances. Everything else --
 * lighting, colour quantisation, the combiner-factor fold -- is the CPU
 * code ported operation for operation.
 *
 * Draws the shader cannot reproduce stay on the CPU path: transform-program
 * draws, points and lines, the frame-buffer-sampling (Omega) draws, batches
 * whose vertex colour summary cannot be derived from the inputs, and
 * anything with a failed or non-finite fetch. */
static Nv2aFFVertex *s_gv;  static uint32_t s_gv_cap;
static uint16_t     *s_gi;  static uint32_t s_gi_cap;
static uint16_t     *s_gs;  static uint32_t s_gs_cap;   /* source index -> packed slot */
uint32_t g_gpuff_stat[4];   /* 0 = GPU draws, 1 = CPU fallbacks, 2 = GPU verts, 3 = dropped (non-finite) */

static int nv_attr_enabled(int slot)
{
    uint32_t fmt = g_pg.attr_fmt[slot], base = g_pg.attr_off[slot];
    return ((fmt >> 4) & 0xF) != 0 && base != 0 && base < 0x08000000u;
}

/* 1 = drawn (or legitimately dropped) on the GPU, 0 = use the CPU path. */
static int nv_gpu_ff_submit(IDirect3DDevice8 *dev, const NvBatchCtx *ctx, int prim, int is_quads)
{
    uint32_t n = g_pg.idx_count, i, lo = 0, nv = 0, ni = 0, need_idx;
    int has_color, has_uv, lit, all_zero = 1, k;
    Nv2aFFConstants cb;
    NvDrawSummary sum;
    NvPostOps post;
    static int s_flip = -1;
    if (s_flip < 0) { const char *e = getenv("DOA2U_FLIPW"); s_flip = (e && *e == '1'); }

    if (ctx->run_program || !g_pg.composite_seen || s_flip) return 0;
    if (prim != D3DPT_TRIANGLELIST && prim != D3DPT_TRIANGLESTRIP && prim != D3DPT_TRIANGLEFAN) return 0;
    if (g_pg.tex[0].offset && nv_samples_framebuffer(g_pg.tex[0].offset)) return 0;
    for (i = 0; i < 16; i++) if (!isfinite(g_pg.composite[i])) return 0;
    if (!nv_attr_enabled(0)) return 0;
    lit       = ctx->lit && nv_attr_enabled(2);
    has_color = nv_attr_enabled(3);
    has_uv    = nv_attr_enabled(9);
    if (!has_color && lit) {
        /* The colour summary (is every colour 0?) needs the lit colours'
         * alpha to be non-zero to be decidable without lighting on the CPU. */
        int a = (int)(g_pg.material_alpha * 255.0f + 0.5f);
        if (a <= 0) return 0;
    }
    if (!nv_vreuse_begin(g_pg.idx, n, &lo)) return 0;

    need_idx = is_quads ? (n / 4) * 6 : (prim == D3DPT_TRIANGLEFAN ? (n - 2) * 3 : n);
    if (s_gv_cap < n)        { void *b = realloc(s_gv, n * sizeof *s_gv); if (!b) return 0; s_gv = b; s_gv_cap = n; }
    if (s_gi_cap < need_idx) { void *b = realloc(s_gi, need_idx * sizeof *s_gi); if (!b) return 0; s_gi = b; s_gi_cap = need_idx; }
    if (s_gs_cap < n)        { void *b = realloc(s_gs, n * sizeof *s_gs); if (!b) return 0; s_gs = b; s_gs_cap = n; }

    /* Pack each unique vertex once; map every source index to its slot. */
    for (i = 0; i < n; i++) {
        uint32_t idx = g_pg.idx[i], d = idx - lo;
        if (s_vstamp[d] == s_vgen) { s_gs[i] = (uint16_t)s_vslot[d]; continue; }
        {
            Nv2aFFVertex *v = &s_gv[nv];
            float tmp[4];
            uint32_t colour = 0xFFFFFFFFu;
            if (nv >= 65535) return 0;
            if (!nv_fetch_attr(0, idx, v->pos, NULL)) return 0;
            if (!isfinite(v->pos[0]) || !isfinite(v->pos[1]) || !isfinite(v->pos[2]) || !isfinite(v->pos[3])) {
                g_gpuff_stat[3]++;              /* the CPU path drops such a batch too */
                return 1;
            }
            if (lit) { if (!nv_fetch_attr(2, idx, tmp, NULL)) return 0; v->nrm[0] = tmp[0]; v->nrm[1] = tmp[1]; v->nrm[2] = tmp[2]; }
            else     { v->nrm[0] = v->nrm[1] = v->nrm[2] = 0.0f; }
            if (has_color) { if (!nv_fetch_attr(3, idx, tmp, &colour)) return 0; if (colour) all_zero = 0; }
            v->color = colour;
            if (has_uv) { if (!nv_fetch_attr(9, idx, tmp, NULL)) return 0; v->uv[0] = tmp[0]; v->uv[1] = tmp[1]; }
            else        { v->uv[0] = v->uv[1] = 0.0f; }
            s_vstamp[d] = s_vgen; s_vslot[d] = nv;
            s_gs[i] = (uint16_t)nv;
            nv++;
        }
    }
    if (is_quads) {
        uint32_t q;
        for (q = 0; q + 3 < n; q += 4) {
            s_gi[ni++] = s_gs[q + 0]; s_gi[ni++] = s_gs[q + 1]; s_gi[ni++] = s_gs[q + 2];
            s_gi[ni++] = s_gs[q + 0]; s_gi[ni++] = s_gs[q + 2]; s_gi[ni++] = s_gs[q + 3];
        }
    } else if (prim == D3DPT_TRIANGLEFAN) {
        for (i = 2; i < n; i++) { s_gi[ni++] = s_gs[0]; s_gi[ni++] = s_gs[i - 1]; s_gi[ni++] = s_gs[i]; }
    } else {
        for (i = 0; i < n; i++) s_gi[ni++] = s_gs[i];
    }
    if (ni < 3) return 1;

    /* The vertex colour summary, from the inputs. */
    if (has_color)              sum.all_zero = all_zero;
    else if (lit)               sum.all_zero = 0;             /* alpha != 0, checked above */
    else if (ctx->ambient_only) {
        float c4[4] = { g_pg.scene_ambient[0] + g_pg.emission[0], g_pg.scene_ambient[1] + g_pg.emission[1],
                        g_pg.scene_ambient[2] + g_pg.emission[2], g_pg.material_alpha };
        sum.all_zero = (nv_pack_color(c4) == 0);
    } else                      sum.all_zero = 0;             /* white */
    sum.max_u = sum.max_v = 0.0f;                              /* no frame-buffer sampling here */

    g_nv_draw_has_uv = 1;
    g_nv_draw_inline = 0;
    memset(&post, 0, sizeof post);
    nv_apply_draw_state(dev, &sum, &post);
    g_pg.gtss_valid = 0;
    g_pg.tss3_valid = 0;
    g_pg.tss1_valid = 0;
    g_pg.tss0_alpha_valid = 0;

    /* Constants. */
    memset(&cb, 0, sizeof cb);
    {
        float zrange = (((g_pg.surface_fmt >> 4) & 0xF) == 1) ? 65535.0f : 16777215.0f;
        float ox = g_pg.vp_offset[0], oy = g_pg.vp_offset[1];
        unsigned sw = (g_pg.surface_clip_h >> 16) & 0xFFFF, sh = (g_pg.surface_clip_v >> 16) & 0xFFFF;
        unsigned bw = d3d8_GetBackbufferWidth(), bh = d3d8_GetBackbufferHeight();
        float sx = 1.0f, sy = 1.0f, kx, ky;
        if (!(ox >= 0.0f && oy >= 0.0f && sw && sh && ox < (float)sw && oy < (float)sh)) { ox = 0.0f; oy = 0.0f; }
        if (sw && sh && bw && bh && !(sw == bw && sh == bh)) { sx = (float)bw / (float)sw; sy = (float)bh / (float)sh; }
        kx = 2.0f * sx / (float)bw;
        ky = 2.0f * sy / (float)bh;
        for (k = 0; k < 4; k++) {
            float r0 = g_pg.composite[0 * 4 + k], r1 = g_pg.composite[1 * 4 + k];
            float r2 = g_pg.composite[2 * 4 + k], r3 = g_pg.composite[3 * 4 + k];
            cb.clip[0][k] =  kx * r0 + (kx * ox - 1.0f) * r3;
            cb.clip[1][k] = -ky * r1 + (1.0f - ky * oy) * r3;
            cb.clip[2][k] =  r2 / zrange;
            cb.clip[3][k] =  r3;
        }
    }
    for (k = 0; k < 3; k++) { int j; for (j = 0; j < 4; j++) cb.mv[k][j] = g_mv[k * 4 + j]; }
    for (k = 0; k < 4; k++) {
        uint32_t t = ctx->ltype[k];
        if (!t) continue;
        if (t == 1) { cb.light_dir[k][0] = ctx->dir_n[k][0]; cb.light_dir[k][1] = ctx->dir_n[k][1]; cb.light_dir[k][2] = ctx->dir_n[k][2]; cb.light_dir[k][3] = 1.0f; }
        else        { cb.light_dir[k][0] = g_pg.light[k].pos[0]; cb.light_dir[k][1] = g_pg.light[k].pos[1]; cb.light_dir[k][2] = g_pg.light[k].pos[2]; cb.light_dir[k][3] = 2.0f; }
        cb.light_amb[k][0] = g_pg.light[k].amb[0]; cb.light_amb[k][1] = g_pg.light[k].amb[1]; cb.light_amb[k][2] = g_pg.light[k].amb[2];
        cb.light_dif[k][0] = g_pg.light[k].dif[0]; cb.light_dif[k][1] = g_pg.light[k].dif[1]; cb.light_dif[k][2] = g_pg.light[k].dif[2];
        cb.light_att[k][0] = g_pg.light[k].att[0]; cb.light_att[k][1] = g_pg.light[k].att[1]; cb.light_att[k][2] = g_pg.light[k].att[2];
        cb.light_att[k][3] = g_pg.light[k].range;
    }
    for (k = 0; k < 3; k++) cb.ambemis[k] = g_pg.scene_ambient[k] + g_pg.emission[k];
    cb.ambemis[3] = g_pg.material_alpha;
    cb.flags = (lit ? NV2AFF_FLAG_LIT : 0) | (ctx->ambient_only ? NV2AFF_FLAG_AMBIENT_ONLY : 0) |
               (has_color ? NV2AFF_FLAG_HAS_COLOR : 0);
    if (post.fold) {
        uint32_t f = post.fold_factor;
        cb.flags |= NV2AFF_FLAG_FOLD;
        cb.fold[0] = (float)((f >> 16) & 0xFF); cb.fold[1] = (float)((f >> 8) & 0xFF);
        cb.fold[2] = (float)(f & 0xFF);         cb.fold[3] = (float)(f >> 24);
    }

    {
        int clipped = nv_apply_window_clip();
        dev->lpVtbl->BeginScene(dev);
        d3d8_DrawNv2aFF(s_gv, nv, s_gi, ni,
                        (prim == D3DPT_TRIANGLESTRIP) ? 5 /* D3D11 TRIANGLESTRIP */ : 4 /* TRIANGLELIST */,
                        &cb);
        if (clipped) { extern void d3d8_ResetScissorRect(void); d3d8_ResetScissorRect(); }
    }
    g_gpuff_stat[0]++;
    g_gpuff_stat[2] += nv;
    g_pg.stats.draw_calls++;
    g_pg.stats.vertices_submitted += ni;
    return 1;
}

static void submit_array_draw(void)
{
    nv_sync_render_target();
    IDirect3DDevice8 *dev;
    OutputVertex *out;
    uint32_t n = g_pg.idx_count, i, prim_count, out_n;
    int prim = g_pg.d3d_prim_type;
    int is_quads = (g_pg.draw_mode == 8);
    int is_points = (g_pg.draw_mode == 1);
    NvBatchCtx ctx;

    if (n < (uint32_t)(is_points ? 1 : 3)) { g_pg.idx_count = 0; return; }

    out_n = is_quads ? (n / 4) * 6 : n;
    if (is_quads) prim = D3DPT_TRIANGLELIST;

    switch (prim) {
    case D3DPT_TRIANGLELIST:  prim_count = out_n / 3; break;
    case D3DPT_TRIANGLESTRIP:
    case D3DPT_TRIANGLEFAN:   prim_count = out_n - 2; break;
    case D3DPT_LINELIST:      prim_count = out_n / 2; break;
    case D3DPT_LINESTRIP:     prim_count = out_n - 1; break;
    default:                  prim_count = out_n / 3; break;
    }
    if (prim_count == 0) { g_pg.idx_count = 0; return; }

    dev = xbox_GetD3DDevice();
    if (!dev) { g_pg.idx_count = 0; return; }

    nv_batch_ctx_init(&ctx);

    if (!is_points && nv_gpu_ff_submit(dev, &ctx, prim, is_quads)) {
        g_pg.idx_count = 0;
        g_pg.idx_dropped = 0;
        return;
    }
    if (!is_points) g_gpuff_stat[1]++;

    if (is_points) {
        /* Point sprites -> screen-space quads. D3D11 has no sized points, so
         * each point becomes two triangles centred on its transformed
         * position, sized by the NV2A point rule (xemu vsh-ff.c):
         *   d = |eye-space position|
         *   t = 1/sqrt(P0 + P1 d + P2 d^2) + P6
         *   s = clamp(t P3 + P7, min(P7, 63.875), min(P3 + P7, 63.875))
         * or SET_POINT_SIZE / 8 when the params are off. Sizes are in guest
         * render-target pixels; nv_fit_to_backbuffer scales the corners with
         * everything else. The hardware feeds the sprite's 0..1 coordinates
         * to texture unit 3 only, which is why the game binds the flake there
         * (cxbx remaps stage 3 onto its host stage 0 for the same reason).
         * A point behind the eye (w <= 0) or outside the depth range has no
         * XYZRHW form and is dropped, so the batch never needs the near-plane
         * clipper (whose scratch space would be several MB for 3,500 quads).
         * The quads live in a heap buffer: six vertices per point is too much
         * for the stack. */
        uint32_t o = 0;
        out = nv_scratch_verts(0, n * 6);
        if (!out) { g_pg.idx_count = 0; g_pg.idx_dropped = 0; g_pg.gtss_valid = 0; g_pg.tss3_valid = 0; return; }
        { extern int g_vpn; g_vpn = 0; }
        for (i = 0; i < n; i++) {
            OutputVertex v; float pos[4];
            nv_build_array_vertex(g_pg.idx[i], &v, &ctx);
            if (nv_point_quad(&v, nv_fetch_attr(0, g_pg.idx[i], pos, NULL) ? pos : NULL, out + o))
                o += 6;
        }
        if (o == 0) { g_pg.idx_count = 0; g_pg.gtss_valid = 0; g_pg.tss3_valid = 0; return; }
        out_n = o; prim = D3DPT_TRIANGLELIST; prim_count = o / 3;
    } else {
        out = nv_scratch_verts(0, out_n);
        if (!out) { g_pg.idx_count = 0; g_pg.idx_dropped = 0; g_pg.gtss_valid = 0; g_pg.tss3_valid = 0; return; }
        { extern int g_vpn; g_vpn = 0; }   /* reset the per-batch program-output range */
        uint32_t lo = 0;
        int reuse = nv_vreuse_begin(g_pg.idx, n, &lo);
        if (is_quads) {
            uint32_t q, o = 0;
            for (q = 0; q + 3 < n; q += 4) {
                if (reuse) {
                    nv_vreuse_build(g_pg.idx[q + 0], lo, out, o + 0, &ctx);
                    nv_vreuse_build(g_pg.idx[q + 1], lo, out, o + 1, &ctx);
                    nv_vreuse_build(g_pg.idx[q + 2], lo, out, o + 2, &ctx);
                } else {
                    nv_build_array_vertex(g_pg.idx[q + 0], &out[o + 0], &ctx);
                    nv_build_array_vertex(g_pg.idx[q + 1], &out[o + 1], &ctx);
                    nv_build_array_vertex(g_pg.idx[q + 2], &out[o + 2], &ctx);
                }
                out[o + 3] = out[o + 0];
                out[o + 4] = out[o + 2];
                if (reuse)
                    nv_vreuse_build(g_pg.idx[q + 3], lo, out, o + 5, &ctx);
                else
                    nv_build_array_vertex(g_pg.idx[q + 3], &out[o + 5], &ctx);
                o += 6;
            }
        } else if (reuse) {
            for (i = 0; i < n; i++)
                nv_vreuse_build(g_pg.idx[i], lo, out, i, &ctx);
        } else {
            for (i = 0; i < n; i++)
                nv_build_array_vertex(g_pg.idx[i], &out[i], &ctx);
        }

        {   /* Post-movie the title screen submits ~500 of these per frame and the
             * window stays black. pos0 alone cannot separate a degenerate batch
             * (every vertex on one point) from a shading problem, so report the
             * screen bounding box, the colour range and the bound texture. */
            extern volatile int g_doa2u_post_movie;
            static int s_n = 0, s_pm = 0;
            static DWORD s_next = 0;
            static int s_burst = 0;
            int want = (s_n < 8);
            /* Post-movie: a burst of draws every couple of seconds rather than the
             * first 20 in a row, so the sample spans different batches. */
            if (!want && g_doa2u_post_movie && s_pm < 80) {
                DWORD now = GetTickCount();
                if (now >= s_next) { s_next = now + 2000; s_burst = 0; }
                if (s_burst < 4) { s_burst++; s_pm++; want = 1; }
            }
            if (want) {
                float x0 = out[0].x, x1 = out[0].x, y0 = out[0].y, y1 = out[0].y;
                uint32_t cmin = out[0].color, cmax = out[0].color, k;
                for (k = 1; k < out_n; k++) {
                    if (out[k].x < x0) x0 = out[k].x;
                    if (out[k].x > x1) x1 = out[k].x;
                    if (out[k].y < y0) y0 = out[k].y;
                    if (out[k].y > y1) y1 = out[k].y;
                    if (out[k].color < cmin) cmin = out[k].color;
                    if (out[k].color > cmax) cmax = out[k].color;
                }
                if (s_n < 8) s_n++;
                { extern int g_vp_used, g_vpn;
                  extern float g_vp_in0[4], g_vp_out0[4], g_vp_d0[4], g_vp_t0[4], g_vpbb[8];
                { extern float g_fix_in0[4];
                   } }
                 }
        }
    }

    {   /* A non-finite transform output cannot be rasterised into anything
         * meaningful -- D3D's behaviour there is undefined and what comes out
         * is a random smear across the frame. Drop the batch. */
        uint32_t k;
        for (k = 0; k < out_n; k++) {
            float X = out[k].x, Y = out[k].y, W = out[k].rhw;
            if (!(X == X) || !(Y == Y) || !(W == W)) { g_pg.idx_count = 0; return; }
        }
    }

    g_nv_draw_has_uv = 1;            /* array path: unchanged */
    g_nv_draw_inline = 0;
    if (is_points)
        nv_apply_point_state(dev, out, out_n);
    else
        nv_apply_draw_state_cpu(dev, out, out_n);
    g_pg.gtss_valid = 0;
    g_pg.tss3_valid = 0;
    g_pg.tss1_valid = 0;
    g_pg.tss0_alpha_valid = 0;
    nv_fit_to_backbuffer(out, out_n, 0);

    if (!is_points &&
        (prim == D3DPT_TRIANGLELIST || prim == D3DPT_TRIANGLESTRIP || prim == D3DPT_TRIANGLEFAN) &&
        nv_batch_needs_clip(out, out_n)) {
        uint32_t ntri = (prim == D3DPT_TRIANGLELIST) ? out_n / 3 : out_n - 2;
        /* Two clip planes can turn one triangle into a 5-gon -> 3 triangles. */
        OutputVertex *cl = nv_scratch_verts(1, ntri * 9);
        if (!cl) { g_pg.idx_count = 0; g_pg.idx_dropped = 0; return; }
        uint32_t cn = nv_clip_batch(out, out_n, prim, cl);
        {   /* DOA2U DIAG: clip statistics, one line every ~2 s. */
            static DWORD s_next = 0; static uint32_t s_b = 0, s_ti = 0, s_to = 0, s_empty = 0;
            s_b++; s_ti += ntri; s_to += cn / 3; if (cn < 3) s_empty++;
            if (GetTickCount() >= s_next) {
                s_next = GetTickCount() + 2000;
                s_b = s_ti = s_to = s_empty = 0;
            }
        }
        if (!getenv("DOA2U_NOCLIP")) {
            if (cn < 3) { g_pg.idx_count = 0; return; }
            out = cl; out_n = cn; prim = D3DPT_TRIANGLELIST; prim_count = cn / 3;
        }
    }

    {   DWORD prev_vs = 0;
        int clipped = nv_apply_window_clip();
        HRESULT got = dev->lpVtbl->GetVertexShader(dev, &prev_vs);
        dev->lpVtbl->SetVertexShader(dev,
            D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        dev->lpVtbl->BeginScene(dev);
        dev->lpVtbl->DrawPrimitiveUP(dev, (D3DPRIMITIVETYPE)prim,
                                     prim_count, out, sizeof(OutputVertex));
        if (clipped) { extern void d3d8_ResetScissorRect(void); d3d8_ResetScissorRect(); }
        if (got == 0) dev->lpVtbl->SetVertexShader(dev, prev_vs);
    }
    g_pg.stats.draw_calls++;
    g_pg.stats.vertices_submitted += out_n;
    g_pg.idx_count = 0;
    g_pg.idx_dropped = 0;
}

uint32_t g_dbail[8];        /* 0=calls 1=no-inline 2=no-stride 3=too-few 4=drawn 5=movie-gate */
uint32_t g_dbail_lastic, g_dbail_lastst;

/* Screen-space z for the inline 2D layer, clamped just inside the clip range.
 *
 * These vertices are pre-transformed, so the shader emits them as
 * (z, w) = (z, 1) and D3D11 clips anything outside 0 <= z <= w. The game
 * submits its character-select backing quad and panel borders at exactly
 * z = 1.0 -- the far plane -- and every one of them was being discarded on
 * that boundary. The NV2A clamps here rather than clipping, so nudge the
 * far end inside the range instead of turning depth clipping off for the
 * whole device, which would change the 3D path as well. 0.9999 still sorts
 * behind the 3D scene (the portrait sits around z = 0.82). */
static float nv_clamp_screen_z(float z)
{
    if (!(z == z)) return 0.0f;            /* NaN */
    if (z < 0.0f)    return 0.0f;
    if (z > 0.9999f) return 0.9999f;
    return z;
}
static void submit_draw(void)
{
    nv_sync_render_target();
    /* Vertex-array draws take precedence: the game issues these with no
     * INLINE_ARRAY data at all, so the inline path below would see an
     * empty buffer and drop them. */
    if (g_pg.idx_count >= 3) {
        submit_array_draw();
        return;
    }
    g_pg.idx_count = 0;

    /* DOA2U DIAG: why are ~89k of 90k BEGIN/END blocks dropped? */
    g_dbail[0]++;
    if (g_pg.inline_count == 0) { g_dbail[1]++; return; }
    if (g_pg.vert_stride == 0)  { g_dbail[2]++; return; }

    /* While the intro movie is playing, movie_present.c owns the screen: it
     * uploads and presents each decoded frame itself, because Sofdec writes
     * frames straight into the Xbox front-buffer pair instead of calling
     * Present. Guest geometry submitted during that window is not part of the
     * movie and compositing it produces flashing shapes over the video, so
     * hold it back until the presenter hands the screen over. */
    {
        extern int doa2u_movie_host_owns_screen(void);
        /* The guest's own movie surface (green: its colour conversion is
         * wrong) is drawn once more after a START skip. Remember its textures
         * while the presenter owns the screen and keep dropping draws on them
         * until a guest frame passes without one. */
        static uint32_t s_mtex[4];
        static int s_mtex_n = 0, s_was_owned = 0;
        static LONG s_mtex_seen = 0;
        extern volatile LONG g_doa2u_heartbeat;
        int tex_on = (g_pg.tex[0].control0 >> 30) & 1;
        if (doa2u_movie_host_owns_screen()) {
            if (!s_was_owned) { s_was_owned = 1; s_mtex_n = 0; }
            if (tex_on && g_pg.tex[0].offset) {
                int k, have = 0;
                for (k = 0; k < s_mtex_n; k++) if (s_mtex[k] == g_pg.tex[0].offset) have = 1;
                if (!have && s_mtex_n < 4) s_mtex[s_mtex_n++] = g_pg.tex[0].offset;
            }
            g_dbail[5]++;
            g_pg.inline_count = 0;
            return;
        }
        if (s_was_owned) { s_was_owned = 0; s_mtex_seen = g_doa2u_heartbeat; }
        if (s_mtex_n) {
            if (g_doa2u_heartbeat - s_mtex_seen > 1) {
                s_mtex_n = 0;                       /* a frame without it: done */
            } else if (tex_on) {
                int k;
                for (k = 0; k < s_mtex_n; k++) {
                    if (s_mtex[k] == g_pg.tex[0].offset) {
                        s_mtex_seen = g_doa2u_heartbeat;
                        g_pg.inline_count = 0;
                        return;
                    }
                }
            }
        }
    }

    /* Per-draw vertex layout. NOTHING derived here is written back into
     * g_pg.*: those persist between draws, so a 5-dword untextured line
     * deriving its own layout would poison the next 13-dword textured panel.
     * That is what blanked the character portrait and then striped it.
     * Only the hint path below still updates the globals, exactly as it
     * always did, because the corner-logo quad depends on that. */
    uint32_t stride  = g_pg.vert_stride;
    int      lay_uv  = g_pg.layout_uv_off;
    int      lay_col = g_pg.layout_color_off;
    int      lay_pos = g_pg.layout_pos_dw;

    {   /* The guest's own vertex count, when it gave us one: an exact
         * division beats every other source. */
        uint32_t hv = g_pg.hint_verts;
        g_pg.hint_verts = 0;
        if (hv && g_pg.inline_count && (g_pg.inline_count % hv) == 0) {
            uint32_t hs = g_pg.inline_count / hv;
            if (hs >= 2 && hs <= 16 && hs != g_pg.vert_stride) {
                if (g_pg.layout_uv_off < 0 && g_pg.hint_declared_dw > 0 &&
                    hs > g_pg.hint_declared_dw)
                    g_pg.layout_uv_off = (int)g_pg.hint_declared_dw;
                g_pg.vert_stride = hs;
            }
            stride = g_pg.vert_stride; lay_uv = g_pg.layout_uv_off;
        }
        /* No hint, and the stride in force does not divide the payload, so it
         * provably is not this draw's -- it is whatever the last draw left.
         * SET_VERTEX_DATA_ARRAY_FORMAT is what the hardware itself unpacks an
         * INLINE_ARRAY with, and the game does emit it (all 16 slots).
         *
         * Measured against cxbx at character select: of 2180 DrawVerticesUP
         * calls, 1672 are 2-vertex LINELIST at a 20-byte (5-dword) stride --
         * position + diffuse, no texcoords. Those are the panel borders
         * (0x0006DB1D, colour 80C8C8C8) and the background gradient
         * (0x000C9A9A / 0x000C9B4A, FF0A0A0A..FF282828 across the full 720).
         * Against the 13-dword stride of the textured panel before them they
         * parsed as zero vertices and every one was dropped. */
        else if (g_pg.inline_count && stride &&
                 (g_pg.inline_count % stride) != 0) {
            int a_pos = 2, a_uv = -1, a_col = -1;
            uint32_t adw = nv_inline_layout_from_attrs(&a_pos, &a_uv, &a_col);
            if (adw >= 2 && adw <= 16 && (g_pg.inline_count % adw) == 0) {
                stride = adw;
                /* Take the derived offsets only when this draw's vertex is NOT
                 * the size the CPU side declared -- then the CPU layout cannot
                 * describe it. When they agree the CPU layout is the better
                 * one; overriding it there sampled the textured panels at the
                 * wrong texcoord and striped them over the portrait. */
                if (adw != g_pg.hint_declared_dw) { lay_uv = a_uv; lay_col = a_col; lay_pos = a_pos; }
            } else if (g_pg.hint_declared_dw >= 2 && g_pg.hint_declared_dw <= 16 &&
                       (g_pg.inline_count % g_pg.hint_declared_dw) == 0) {
                stride = g_pg.hint_declared_dw;
            }
        }
    }

    uint32_t num_verts = g_pg.inline_count / stride;
    {   /* How many vertices this primitive actually needs. A flat 3 dropped
         * every LINE draw in the game -- and cxbx says 77% of this screen's
         * draws are 2-vertex LINELIST. */
        uint32_t min_verts;
        switch (g_pg.draw_mode) {
        case 1:  min_verts = 1; break;              /* POINTS               */
        case 2:                                     /* LINES                */
        case 3:                                     /* LINE_LOOP            */
        case 4:  min_verts = 2; break;              /* LINE_STRIP           */
        case 8:                                     /* QUADS                */
        case 9:  min_verts = 4; break;              /* QUAD_STRIP           */
        default: min_verts = 3; break;              /* triangles / polygon  */
        }
        if (num_verts < min_verts) {
            g_dbail[3]++; g_dbail_lastic = g_pg.inline_count;
            g_dbail_lastst = stride;
            return;
        }
    }
    g_dbail[4]++;

    {   /* DOA2U DIAG: per-draw-mode tally (count, last vert count, stride). */
            int dm = g_pg.draw_mode & 15;
        g_dstat[dm][0]++; g_dstat[dm][1] = num_verts; g_dstat[dm][2] = stride;
    }

    const uint32_t *src = g_pg.inline_data;

    {   IDirect3DDevice8 *pdev = xbox_GetD3DDevice();
        if (pdev && submit_inline_points(pdev, src, num_verts, stride, lay_pos, lay_col))
            return;
    }


    {   /* DOA2U DIAG: census of post-FMV draws -- what is actually being
         * submitted, and why none of it reaches the screen. */
        extern uint32_t g_census[12];
        if (g_pg.stats.draw_calls > 150000) {
            uint32_t nv = num_verts;
            int all_zero_col = 1, any_alpha = 0;
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
            for (uint32_t i = 0; i < nv && i < 64; i++) {
                uint32_t b = i * stride;
                float x = u2f(src[b + 0]), y = u2f(src[b + 1]);
                if (x < mnx) mnx = x;
                if (x > mxx) mxx = x;
                if (y < mny) mny = y;
                if (y > mxy) mxy = y;
                if (lay_col >= 0) {
                    uint32_t c = src[b + lay_col];
                    if (c) all_zero_col = 0;
                    if (c >> 24) any_alpha = 1;
                }
            }
            g_census[0]++;
            if (all_zero_col) g_census[1]++;
            if (any_alpha) g_census[2]++;
            if (g_pg.tex[0].offset) g_census[3]++;
            if (mnx >= 0.0f && mxx <= 720.0f && mny >= 0.0f && mxy <= 512.0f)
                g_census[4]++;      /* plausibly on-screen */
            else
                g_census[5]++;      /* off-screen / not screen space */
            if (g_pg.blend_enable) g_census[6]++;
            if (g_pg.alpha_test) g_census[7]++;
            if ((g_pg.xform_mode & 3) == 2) g_census[8]++;
            if (mxx - mnx > 8.0f && mxy - mny > 8.0f) g_census[9]++;
        }
    }

    int actual_prim_type = g_pg.d3d_prim_type;
    uint32_t out_vert_count = num_verts;

    /* Handle QUADS (mode 8): convert to triangle list (6 verts per quad) */
    int is_quads = (g_pg.draw_mode == 8);
    uint32_t num_quads = is_quads ? (num_verts / 4) : 0;
    if (is_quads) {
        out_vert_count = num_quads * 6;  /* 2 triangles per quad */
        actual_prim_type = D3DPT_TRIANGLELIST;
    }

    /* Calculate primitive count */
    uint32_t prim_count = 0;
    switch (actual_prim_type) {
        case D3DPT_TRIANGLELIST:  prim_count = out_vert_count / 3; break;
        case D3DPT_TRIANGLESTRIP: prim_count = out_vert_count - 2; break;
        case D3DPT_TRIANGLEFAN:   prim_count = out_vert_count - 2; break;
        case D3DPT_LINELIST:      prim_count = out_vert_count / 2; break;
        case D3DPT_LINESTRIP:     prim_count = out_vert_count - 1; break;
        default: prim_count = out_vert_count / 3; break;
    }
    if (prim_count == 0) {
        return;
    }

    /* Convert inline vertices to OutputVertex (28 bytes) */
    OutputVertex *out = (OutputVertex *)_alloca(out_vert_count * sizeof(OutputVertex));

    /* Helper to convert one inline vertex */
    #define CONVERT_VERT(dst_idx, src_idx) do { \
        uint32_t _b = (src_idx) * stride; \
        out[dst_idx].x     = u2f(src[_b + 0]); \
        out[dst_idx].y     = u2f(src[_b + 1]); \
        /* The guest's own z. Hardcoding 0 put every 2D draw on the NEAR plane: \
         * character select submits its window backing quad at z = 1.0 with \
         * depth test and write on, so at z = 0 it stamped the near plane over \
         * the window and the character behind it (z ~ 0.82) failed LEQUAL and \
         * vanished. Only read it when the position actually carries one. */ \
        out[dst_idx].z     = nv_clamp_screen_z((lay_pos >= 3) ? u2f(src[_b + 2]) : 0.0f); \
        /* A 4-dword inline position is XYZRHW the game transformed on the \
         * CPU; its 4th float is 1/w. Forcing 1.0 interpolated the texture of \
         * every such triangle affinely (ground next to the camera stretched \
         * and slid as it turned). Honour it, guarded; 2D quads carry 1.0. */ \
        {   float _rw = (lay_pos >= 4) ? u2f(src[_b + 3]) : 1.0f; \
            out[dst_idx].rhw = (_rw > 0.0f && _rw < 1e6f) ? _rw : 1.0f; } \
        out[dst_idx].u     = (lay_uv >= 0) ? u2f(src[_b + lay_uv]) : 0.0f; \
        out[dst_idx].v     = (lay_uv >= 0) ? u2f(src[_b + lay_uv + 1]) : 0.0f; \
        out[dst_idx].color = (lay_col >= 0) ? src[_b + lay_col] : 0xFFFFFFFFu; \
    } while(0)

    if (is_quads) {
        /* Convert quads (v0,v1,v2,v3) → two triangles (v0,v1,v2), (v0,v2,v3) */
        uint32_t out_idx = 0;
        for (uint32_t q = 0; q < num_quads; q++) {
            uint32_t qi = q * 4;
            CONVERT_VERT(out_idx + 0, qi + 0);  /* tri 1: v0 */
            CONVERT_VERT(out_idx + 1, qi + 1);  /* tri 1: v1 */
            CONVERT_VERT(out_idx + 2, qi + 2);  /* tri 1: v2 */
            CONVERT_VERT(out_idx + 3, qi + 0);  /* tri 2: v0 */
            CONVERT_VERT(out_idx + 4, qi + 2);  /* tri 2: v2 */
            CONVERT_VERT(out_idx + 5, qi + 3);  /* tri 2: v3 */
            out_idx += 6;
        }
    } else {
        for (uint32_t i = 0; i < num_verts; i++) {
            CONVERT_VERT(i, i);
        }
    }
    #undef CONVERT_VERT

    /* A draw whose every vertex carries a zero diffuse cannot be intending to
     * modulate by it; see the texture-stage setup below. */
    int diffuse_all_zero = 1;
    for (uint32_t i = 0; i < out_vert_count; i++)
        if (out[i].color != 0) { diffuse_all_zero = 0; break; }

    /* DOA2U interim: the movie quad's UVs are never written by the game-side
     * builder (all zeros). When a draw has NO usable texcoords but positions
     * span an area, derive full-range UVs from the position bounding box so
     * the bound dynamic texture (movie frame) maps across the quad. */
    if (lay_uv >= 0 && out_vert_count >= 3) {
        int all_zero = 1;
        for (uint32_t i = 0; i < out_vert_count; i++)
            if (out[i].u != 0.0f || out[i].v != 0.0f) { all_zero = 0; break; }
        if (all_zero) {
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
            for (uint32_t i = 0; i < out_vert_count; i++) {
                if (out[i].x < mnx) mnx = out[i].x;
                if (out[i].x > mxx) mxx = out[i].x;
                if (out[i].y < mny) mny = out[i].y;
                if (out[i].y > mxy) mxy = out[i].y;
            }
            if (mxx > mnx && mxy > mny) {
                for (uint32_t i = 0; i < out_vert_count; i++) {
                    out[i].u = (out[i].x - mnx) / (mxx - mnx);
                    out[i].v = (out[i].y - mny) / (mxy - mny);
                }
            }
        }
    }

    /* Chyron scroll: shift X for vertices in the chyron Y band (366-382).
     * Simple continuous scroll — no per-vertex wrapping to avoid artifacts
     * from split triangle-strip quads spanning the screen. */
    if (g_pg.chyron_scroll_offset != 0.0f && out_vert_count >= 6) {
        /* Check if this draw is in the chyron band */
        int is_chyron = 1;
        for (uint32_t i = 0; i < (out_vert_count < 8 ? out_vert_count : 8); i++) {
            if (out[i].y < 360.0f || out[i].y > 390.0f) {
                is_chyron = 0;
                break;
            }
        }
        if (is_chyron) {
            /* Find the total text width */
            float min_x = 9999.0f, max_x = -9999.0f;
            for (uint32_t i = 0; i < out_vert_count; i++) {
                if (out[i].x < min_x) min_x = out[i].x;
                if (out[i].x > max_x) max_x = out[i].x;
            }
            float text_width = max_x - min_x;

            /* Scroll loops: text slides left, then resets to start position.
             * Total cycle = text scrolls fully off-left + re-enters from right. */
            float cycle = text_width + 640.0f;
            float scroll = fmodf(g_pg.chyron_scroll_offset, cycle);

            /* Apply uniform shift to ALL vertices (no per-vertex wrap) */
            for (uint32_t i = 0; i < out_vert_count; i++) {
                out[i].x -= scroll;
            }
        }
    }

    /* Log first few draws' vertex positions (once) */
    if (g_pg.stats.draw_calls < 3 && num_verts >= 3) {
        uint32_t show = num_verts < 8 ? num_verts : 8;
        for (uint32_t i = 0; i < show; i++) {
            uint32_t b = i * stride;
        }
    }

    /* Get D3D8 device */
    IDirect3DDevice8 *dev = xbox_GetD3DDevice();
    if (!dev) return;

    g_nv_draw_has_uv = (lay_uv >= 0);
    g_nv_draw_inline = 1;
    nv_apply_draw_state_cpu(dev, out, out_vert_count);
    g_pg.gtss_valid = 0;
    g_pg.tss1_valid = 0;
    g_nv_draw_inline = 0;
    nv_fit_to_backbuffer(out, out_vert_count, 1);
    /* Begin scene if needed */
    dev->lpVtbl->BeginScene(dev);

    {   /* DOA2U DIAG: the D3D11 state the draw actually lands in.
         * movie_present.c binds its own RTV and viewport for the intro
         * movie and never restores the D3D8 layer's, so a post-movie
         * draw can be perfectly valid and still rasterise nowhere. */
        extern volatile int g_doa2u_post_movie;
        extern void d3d8_DebugDumpTargetState(void);
        static int s_n = 0;
        (void)g_doa2u_post_movie;
        /* Sampled unconditionally: the same wiring question applies to the
         * draws issued while the movie is still playing. */
        if (s_n < 3 || (g_doa2u_post_movie && s_n < 6)) { s_n++; d3d8_DebugDumpTargetState(); }
    }
    /* Draw.
     *
     * OutputVertex is PRE-TRANSFORMED (XYZRHW screen space, diffuse, one
     * texcoord), so it must go through the fixed-function pipeline. If the
     * game currently has a programmable vertex shader bound -- and the game always
     * does on its 3D screens -- the D3D8 layer would otherwise bind that
     * shader plus its own input layout (d3d8_vsh_prepare_draw) and run our
     * screen-space quads through the game's object-space vertex program with
     * the game's matrices. The geometry then lands nowhere and nothing is
     * visible, whatever colour or texture the draw asked for.
     *
     * Select the matching FVF for the duration of the draw and restore the
     * game's shader afterwards, so the guest's own pipeline state is
     * unaffected. */
    {
        DWORD prev_vs = 0;
        HRESULT got = dev->lpVtbl->GetVertexShader(dev, &prev_vs);
        dev->lpVtbl->SetVertexShader(dev,
            D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

        int clipped = nv_apply_window_clip();
        dev->lpVtbl->DrawPrimitiveUP(dev, (D3DPRIMITIVETYPE)g_pg.d3d_prim_type,
                                      prim_count, out, sizeof(OutputVertex));
        if (clipped) { extern void d3d8_ResetScissorRect(void); d3d8_ResetScissorRect(); }

        if (got == 0)
            dev->lpVtbl->SetVertexShader(dev, prev_vs);
    }

    g_pg.stats.draw_calls++;
    g_pg.stats.vertices_submitted += num_verts;

    {   /* DOA2U DIAG: what the post-movie screen actually submits --
         * which texture, where on screen, and with what colour. */
        extern volatile int g_doa2u_post_movie;
        static int s_n = 0;
        if (g_doa2u_post_movie && s_n < 24) {
            float mnx = 1e9f, mxx = -1e9f, mny = 1e9f, mxy = -1e9f;
            uint32_t i;
            s_n++;
            for (i = 0; i < out_vert_count; i++) {
                if (out[i].x < mnx) mnx = out[i].x;
                if (out[i].x > mxx) mxx = out[i].x;
                if (out[i].y < mny) mny = out[i].y;
                if (out[i].y > mxy) mxy = out[i].y;
            }
            {   /* Is the source surface the fade samples actually non-black? */
                extern ptrdiff_t g_xbox_mem_offset;
                const uint32_t *src32 =
                    (const uint32_t *)((uintptr_t)g_pg.tex[0].offset + g_xbox_mem_offset);
                unsigned nz = 0, k;
                for (k = 0; k < 4096; k++)
                    if (src32[k * 64] & 0x00FFFFFFu) nz++;
            }
        }
    }
    if (g_pg.stats.draw_calls <= 5 || (g_pg.stats.draw_calls % 1000) == 0) {
    }
}

/* ══════════════════════════════════════════════════════════════════════
 * Method Handler
 * ══════════════════════════════════════════════════════════════════════ */

/* DOA2U DIAG: which program slots the game loads and runs after the movie. */
#define DIAG_VP_PTR(what, val) do { \
    extern volatile int g_doa2u_post_movie; \
    static int s_dn = 0; \
    if (g_doa2u_post_movie && s_dn < 40) { s_dn++; \
         \
         } \
} while (0)

/* Per-method dispatch table.
 *
 * Every method used to run ~40 independent range tests before reaching the
 * switch -- the record-only state handlers (transform-constant mirror,
 * combiner markers, point parameters, lighting registers, matrices, the
 * vertex-array format/offset runs) plus a 15-term "silently ignored" list in
 * the switch's default. With ~190k methods a frame in the heavy scenes that
 * chain was a third of the translator's time. Each test depends only on the
 * method number (the 0x0100 markers look at the parameter only once the
 * method matches), so the outcome of every test is precomputed here once,
 * into one flag word and one constant-slot index per method. The handler
 * bodies below are the original ones, run under their precomputed flag in
 * the original order; the switch and its cases are unchanged. */
enum {
    MF_CONST       = 1u << 0,    /* transform-constant mirror, slot in cslot */
    MF_COMBCTL     = 1u << 1,    /* 0x1E60 */
    MF_MARKER      = 1u << 2,    /* 0x0100: wrapper-carried markers in the top byte */
    MF_PT_EN       = 1u << 3,    /* 0x0318 */
    MF_PT_SMOOTH   = 1u << 4,    /* 0x031C */
    MF_PT_SIZE     = 1u << 5,    /* 0x043C */
    MF_PT_PARAM    = 1u << 6,    /* 0x0A30..0x0A4C */
    MF_COMB_FACTOR = 1u << 7,    /* 0x0A60..0x0A7C, returns */
    MF_XMODE       = 1u << 8,    /* 0x1E94 diag */
    MF_VP_PROG     = 1u << 9,    /* 0x0B00..0x0B7C, returns */
    MF_VP_CONST    = 1u << 10,   /* 0x0B80..0x0BFC, returns */
    MF_ATTR_FMT    = 1u << 11,   /* 0x1760..0x179C, returns */
    MF_ATTR_OFF    = 1u << 12,   /* 0x1720..0x175C, returns */
    MF_MV          = 1u << 13,   /* 0x0480..0x04BC, returns */
    MF_LIGHT_EN    = 1u << 14,   /* 0x0314 */
    MF_LIGHT_REG   = 1u << 15,   /* 0x1000..0x11FC */
    MF_LIGHT_MASK  = 1u << 16,   /* 0x03BC */
    MF_LIGHT_CTL   = 1u << 17,   /* 0x0294 */
    MF_COLOR_MAT   = 1u << 18,   /* 0x0298 */
    MF_SPEC_EN     = 1u << 19,   /* 0x03B8 */
    MF_NORM_EN     = 1u << 20,   /* 0x03A4 */
    MF_SCENE_AMB   = 1u << 21,   /* 0x0A10..0x0A18 */
    MF_EMISSION    = 1u << 22,   /* 0x03A8..0x03B0 */
    MF_MAT_ALPHA   = 1u << 23,   /* 0x03B4 */
    MF_SPEC_PARAM  = 1u << 24,   /* 0x09E0..0x09F4 */
    MF_COMPOSITE   = 1u << 25,   /* 0x0680..0x06BC, returns */
    MF_SILENT      = 1u << 26,   /* the switch default's "ignored but acknowledged" list */
    MF_PRE  = MF_CONST | MF_COMBCTL | MF_MARKER | MF_PT_EN | MF_PT_SMOOTH | MF_PT_SIZE |
              MF_PT_PARAM | MF_COMB_FACTOR,
    MF_POST = MF_XMODE | MF_VP_PROG | MF_VP_CONST | MF_ATTR_FMT | MF_ATTR_OFF | MF_MV |
              MF_LIGHT_EN | MF_LIGHT_REG | MF_LIGHT_MASK | MF_LIGHT_CTL | MF_COLOR_MAT |
              MF_SPEC_EN | MF_NORM_EN | MF_SCENE_AMB | MF_EMISSION | MF_MAT_ALPHA |
              MF_SPEC_PARAM | MF_COMPOSITE
};
typedef struct { uint32_t mask; int8_t cslot; } NvMethodEntry;
static NvMethodEntry s_mtab[0x800];
static int s_mtab_ready;

/* The switch default's "known range we can safely ignore" test, as written. */
static int nv_method_silent(uint32_t method)
{
    return (method >= 0x0B80 && method < 0x0C00) ||  /* Transform program */
           (method >= 0x0E00 && method < 0x1000) ||  /* Transform constants */
           (method >= 0x1680 && method < 0x1780) ||  /* Vertex array format/offset */
           (method >= 0x1B00 && method < 0x1C00) ||  /* Texture registers */
           (method >= 0x1D60 && method < 0x1EA0) ||  /* Combiners */
           method == 0x0100 ||                        /* NOP */
           method == 0x0180 ||                        /* SET_OBJECT */
           method == 0x0394 ||                        /* TRANSFORM_EXECUTION_MODE */
           method == 0x0398 ||                        /* TRANSFORM_PROGRAM_CXT_WRITE_EN */
           method == 0x039C ||                        /* TRANSFORM_PROGRAM_LOAD */
           method == 0x01E0 ||                        /* SHADER_STAGE_PROGRAM */
           method == 0x0108 || method == 0x010C ||    /* FLIP_READ/WRITE */
           method == 0x0110 || method == 0x0114 ||    /* FLIP_MODULO/INCREMENT */
           method == 0x0118;                          /* FLIP_STALL */
}

static void nv_mtab_init(void)
{
    uint32_t method;
    for (method = 0; method < 0x2000; method += 4) {
        NvMethodEntry *e = &s_mtab[method >> 2];
        uint32_t f = 0;
        int slot = -1;
        /* Fixed-function context -> transform constants c[0..95].
         *
         * On the NV2A the first 96 transform constants ARE the fixed-function
         * context: SET_COMPOSITE_MATRIX lands in c[0..3], SET_PROJECTION_MATRIX in
         * c[4..7], the model-view / inverse model-view matrices in c[8..39], the
         * texgen planes and texture matrices in c[64..95], the eye position in c[56], the fog
         * parameters in c[57], SET_VIEWPORT_SCALE in c[58] and SET_VIEWPORT_OFFSET
         * in c[59] (xemu's NV_IGRAPH_XF_XFCTX_* slots). The XDK's vertex-shader
         * epilogue reads the viewport back as c[-38]/c[-37] = c[58]/c[59]; no code
         * ever loads them through SET_TRANSFORM_CONSTANT, so a program that runs
         * without this mirror scales every position by zero (the pond's water). */
        if      (method >= 0x0680 && method <= 0x06BC) slot = 0x00 + (method - 0x0680) / 16;
        else if (method >= 0x0440 && method <= 0x047C) slot = 0x04 + (method - 0x0440) / 16;
        else if (method >= 0x0480 && method <= 0x057C) slot = 0x08 + ((method - 0x0480) / 64) * 8 + ((method - 0x0480) % 64) / 16;
        else if (method >= 0x0580 && method <= 0x067C) slot = 0x0C + ((method - 0x0580) / 64) * 8 + ((method - 0x0580) % 64) / 16;
        else if (method >= 0x06C0 && method <= 0x07BC) slot = 0x44 + ((method - 0x06C0) / 64) * 8 + ((method - 0x06C0) % 64) / 16;
        else if (method >= 0x0840 && method <= 0x093C) slot = 0x40 + ((method - 0x0840) / 64) * 8 + ((method - 0x0840) % 64) / 16;
        else if (method >= 0x0A50 && method <= 0x0A5C) slot = 0x38;
        else if (method >= 0x09C0 && method <= 0x09C8) slot = 0x39;
        else if (method >= 0x0AF0 && method <= 0x0AFC) slot = 0x3A;
        else if (method >= 0x0A20 && method <= 0x0A2C) slot = 0x3B;
        if (slot >= 0 && slot < NV2A_VP_NUM_CONST) f |= MF_CONST; else slot = -1;
        if (method == 0x1E60) f |= MF_COMBCTL;
        if (method == 0x0100) f |= MF_MARKER;
        if (method == 0x0318) f |= MF_PT_EN;
        if (method == 0x031C) f |= MF_PT_SMOOTH;
        if (method == 0x043C) f |= MF_PT_SIZE;
        if (method >= 0x0A30 && method <= 0x0A4C) f |= MF_PT_PARAM;
        if (method >= 0x0A60 && method <= 0x0A7C) f |= MF_COMB_FACTOR;
        if (method == 0x1E94) f |= MF_XMODE;
        if (method >= 0x0B00 && method <= 0x0B7C) f |= MF_VP_PROG;
        if (method >= 0x0B80 && method <= 0x0BFC) f |= MF_VP_CONST;
        if (method >= 0x1760 && method <= 0x179C) f |= MF_ATTR_FMT;
        if (method >= 0x1720 && method <= 0x175C) f |= MF_ATTR_OFF;
        if (method >= 0x0480 && method <= 0x04BC) f |= MF_MV;
        if (method == 0x0314) f |= MF_LIGHT_EN;
        if (method >= 0x1000 && method <= 0x11FC) f |= MF_LIGHT_REG;
        if (method == 0x03BC) f |= MF_LIGHT_MASK;
        if (method == 0x0294) f |= MF_LIGHT_CTL;
        if (method == 0x0298) f |= MF_COLOR_MAT;
        if (method == 0x03B8) f |= MF_SPEC_EN;
        if (method == 0x03A4) f |= MF_NORM_EN;
        if (method >= 0x0A10 && method <= 0x0A18) f |= MF_SCENE_AMB;
        if (method >= 0x03A8 && method <= 0x03B0) f |= MF_EMISSION;
        if (method == 0x03B4) f |= MF_MAT_ALPHA;
        if (method >= 0x09E0 && method <= 0x09F4) f |= MF_SPEC_PARAM;
        if (method >= 0x0680 && method <= 0x06BC) f |= MF_COMPOSITE;
        if (nv_method_silent(method)) f |= MF_SILENT;
        e->mask = f;
        e->cslot = (int8_t)slot;
    }
    s_mtab_ready = 1;
}

int pgraph_d3d11_method(int subchannel, uint32_t method, uint32_t param)
{
    const NvMethodEntry *me;
    uint32_t f;
    (void)subchannel;
    if (!s_mtab_ready) nv_mtab_init();

    if (method >= 0x2000 || (method & 3)) {
        /* Outside the table (the push-buffer walker masks methods to 0x1FFC,
         * so this never happens): no handler matched such a method before
         * either, so it went straight to the switch default. */
        if (!g_pg.initialized) return 0;
        g_pg.stats.methods_handled++;
        if (nv_method_silent(method)) return 1;
        g_pg.stats.methods_ignored++;
        return 0;
    }
    me = &s_mtab[method >> 2];
    f = me->mask;

    if (f & MF_PRE) {
        if (f & MF_CONST)
            g_pg.vp.consts[me->cslot][(method / 4) & 3] = u2f(param);
        if (f & MF_COMBCTL) g_pg.comb_control = param;
        if (f & MF_MARKER) {
            switch (param >> 24) {
            case 0xA3u: g_pg.gtss = param; g_pg.gtss_valid = 1; return 1;
            case 0xA4u: g_pg.tss3_color = param; g_pg.tss3_valid = 1; return 1;
            case 0xA5u: g_pg.tss3_alpha = param; return 1;
            case 0xA6u: g_pg.tss1_color = param; g_pg.tss1_valid = 1; return 1;
            case 0xA7u: g_pg.tss1_alpha = param; return 1;
            case 0xABu: g_pg.tss0_alpha = param; g_pg.tss0_alpha_valid = 1; return 1;
            case 0xA9u: g_pg.tfactor_lo = param & 0xFFFFFF; return 1;
            /* Inline vertex layout / counts for the next DrawVerticesUP, carried in
             * the stream by the recompiled wrapper (see recomp_manual.c): the
             * globals the direct calls set are only right for the last such draw
             * before a kick. Offsets are 6-bit two's complement (0x3F = none). */
            case 0xACu: {
                int uv = (int)((param >> 6) & 0x3Fu), col = (int)(param & 0x3Fu);
                pgraph_d3d11_set_vertex_layout((param >> 16) & 0x1Fu, (int)((param >> 12) & 0x7u),
                                               uv == 0x3F ? -1 : uv, col == 0x3F ? -1 : col);
                return 1;
            }
            case 0xADu: pgraph_d3d11_set_inline_hint((param >> 8) & 0xFFFFu, param & 0xFFu); return 1;
            case 0xAAu: g_pg.tfactor_hi = param & 0xFF; return 1;
            default: break;
            }
        }
        if (f & MF_PT_EN)     g_pg.point_params_en = param;
        if (f & MF_PT_SMOOTH) g_pg.point_smooth = param;
        if (f & MF_PT_SIZE)   g_pg.point_size = param;
        if (f & MF_PT_PARAM)  g_pg.point_params[(method - 0x0A30) >> 2] = u2f(param);
        /* Combiner factors: recorded, not executed. */
        if (f & MF_COMB_FACTOR) {
            g_pg.comb_factor0[(method - 0x0A60) >> 2] = param;
            return 1;
        }
    }
    if (!g_pg.initialized)
        return 0;

    g_pg.stats.methods_handled++;

    {   /* DOA2U DIAG: exact per-method histogram + transform mode. */
        extern uint32_t g_mhist[0x800];
        extern uint32_t g_xmode, g_xmode_n[4];
        g_mhist[method >> 2]++;
        if (f & MF_XMODE) { g_xmode = param; g_xmode_n[param & 3]++; }
    }

    if (f & MF_POST) {
        /* Range methods: the pushbuffer streams these as runs, so they cannot be
         * expressed as switch cases. */
        if (f & MF_VP_PROG) {                                /* TRANSFORM_PROGRAM  */
            nv2a_vp_write_program(&g_pg.vp, (method - 0x0B00) / 4, param);
            return 1;
        }
        if (f & MF_VP_CONST) {                               /* TRANSFORM_CONSTANT */
            /* 32 dwords (0x0B80..0x0BFC; 0x0C00 is the next register). The range
             * used to stop at 0x0B9C, so the third and fourth rows of every 4x4
             * matrix the XDK uploads in one burst were dropped: the pond's water
             * program got c2 = c3 = 0 and every vertex came out with w = 0. */
            nv2a_vp_write_constant(&g_pg.vp, (method - 0x0B80) / 4, param);
            return 1;
        }
        if (f & MF_ATTR_FMT) {                               /* VERTEX_DATA_ARRAY_FORMAT */
            g_pg.attr_fmt[(method - 0x1760) / 4] = param;
            g_pg.attr_fmt_seen = 1;
            return 1;
        }
        if (f & MF_ATTR_OFF) {                               /* VERTEX_DATA_ARRAY_OFFSET */
            g_pg.attr_off[(method - 0x1720) / 4] = param;
            return 1;
        }
        if (f & MF_MV) {                                     /* SET_MODEL_VIEW_MATRIX */
            extern float g_mv[16];
            g_mv[(method - 0x0480) / 4] = u2f(param);
            return 1;
        }
        /* Fixed-function lighting state (record only; the draw path consumes it
         * and the methods keep their previous handled/ignored classification). */
        if (f & MF_LIGHT_EN) g_pg.lighting = param;
        if (f & MF_LIGHT_REG) {
            int li = (method - 0x1000) / 0x80, o = (method - 0x1000) % 0x80;
            float fl = u2f(param);
            if      (o < 0x0C) g_pg.light[li].amb[o / 4] = fl;
            else if (o < 0x18) g_pg.light[li].dif[(o - 0x0C) / 4] = fl;
            else if (o < 0x24) g_pg.light[li].spec[(o - 0x18) / 4] = fl;
            else if (o < 0x28) g_pg.light[li].range = fl;
            else if (o < 0x34) g_pg.light[li].half[(o - 0x28) / 4] = fl;
            else if (o < 0x40) g_pg.light[li].dir[(o - 0x34) / 4] = fl;
            else if (o < 0x4C) g_pg.light[li].spot_fall[(o - 0x40) / 4] = fl;
            else if (o < 0x5C) g_pg.light[li].spot_dir[(o - 0x4C) / 4] = fl;
            else if (o < 0x68) g_pg.light[li].pos[(o - 0x5C) / 4] = fl;
            else if (o < 0x74) g_pg.light[li].att[(o - 0x68) / 4] = fl;
        }
        if (f & MF_LIGHT_MASK) g_pg.light_mask = param;
        if (f & MF_LIGHT_CTL)  g_pg.light_control = param;
        if (f & MF_COLOR_MAT)  g_pg.color_material = param;
        if (f & MF_SPEC_EN)    g_pg.spec_enable = param;
        if (f & MF_NORM_EN)    g_pg.normalize_en = param;
        if (f & MF_SCENE_AMB)  g_pg.scene_ambient[(method - 0x0A10) / 4] = u2f(param);
        if (f & MF_EMISSION)   g_pg.emission[(method - 0x03A8) / 4] = u2f(param);
        if (f & MF_MAT_ALPHA)  g_pg.material_alpha = u2f(param);
        if (f & MF_SPEC_PARAM) g_pg.spec_params[(method - 0x09E0) / 4] = u2f(param);
        if (f & MF_COMPOSITE) {                              /* SET_COMPOSITE_MATRIX */
            g_pg.composite[(method - 0x0680) / 4] = u2f(param);
            g_pg.composite_seen = 1;
            return 1;
        }
    }

    switch (method) {

    /* ── Draw Begin/End ── */
    case NV097_SET_BEGIN_END:
        if (param == 0) {
            /* END: submit accumulated vertices */
            if (g_pg.in_draw) {
                submit_draw();
                g_pg.in_draw = 0;
            }
        } else {
            /* BEGIN: start new draw */
            g_pg.in_draw = 1;
            g_pg.draw_mode = param;
            g_pg.d3d_prim_type = nv2a_draw_mode_to_d3d(param);
            g_pg.inline_count = 0;
            g_pg.idx_count = 0;
        }
        return 1;

    /* -- Vertex-array submission (indexed and range draws) --
     *
     * Both are reduced to a flat index list here; the vertices themselves
     * are assembled from the bound arrays at END. */
    case 0x1800:   /* ARRAY_ELEMENT16: two indices per dword */
        if (g_pg.in_draw) {
            if (g_pg.idx_count < MAX_IDX) g_pg.idx[g_pg.idx_count++] = param & 0xFFFFu; else g_pg.idx_dropped++;
            if (g_pg.idx_count < MAX_IDX) g_pg.idx[g_pg.idx_count++] = param >> 16; else g_pg.idx_dropped++;
        }
        return 1;

    case 0x1808:   /* ARRAY_ELEMENT32 */
        if (g_pg.in_draw) {
            if (g_pg.idx_count < MAX_IDX) g_pg.idx[g_pg.idx_count++] = param; else g_pg.idx_dropped++;
        }
        return 1;

    case 0x1810: { /* DRAW_ARRAYS: start in bits 0-23, count-1 in 24-31 */
        uint32_t start = param & 0x00FFFFFFu;
        uint32_t count = ((param >> 24) & 0xFF) + 1u;
        uint32_t k;
        if (g_pg.in_draw)
            for (k = 0; k < count; k++) {
                if (g_pg.idx_count < MAX_IDX) g_pg.idx[g_pg.idx_count++] = start + k; else g_pg.idx_dropped++;
            }
        return 1;
    }

    /* ── Inline Vertex Data ── */
    case NV097_INLINE_ARRAY:
        if (g_pg.in_draw && g_pg.inline_count < MAX_INLINE_VERTS * INLINE_VERT_DWORDS) {
            g_pg.inline_data[g_pg.inline_count++] = param;
        }
        return 1;

    /* ── Clear ── */
    case NV097_SET_COLOR_CLEAR_VALUE:
        g_pg.clear_color = param;
        return 1;

    case NV097_SET_CLEAR_RECT_HORIZONTAL:
        g_pg.clear_rect_h = param;
        return 1;

    case NV097_SET_CLEAR_RECT_VERTICAL:
        g_pg.clear_rect_v = param;
        return 1;

    case NV097_CLEAR_SURFACE:
    {
        IDirect3DDevice8 *dev = xbox_GetD3DDevice();
        nv_sync_render_target();
        if (dev) {
            uint32_t flags = 0;
            if (param & 0xF0) flags |= 1;  /* D3DCLEAR_TARGET */
            if (param & 0x01) flags |= 2;  /* D3DCLEAR_ZBUFFER */
            if (param & 0x02) flags |= 4;  /* D3DCLEAR_STENCIL */
            dev->lpVtbl->Clear(dev, 0, NULL, flags, g_pg.clear_color, 1.0f, 0);
            {   /* DOA2U DIAG: clear trace alongside [RTT] SETRT lines. */
                extern volatile int g_doa2u_post_movie; extern volatile LONG g_doa2u_heartbeat;
                static int s_t = 0; static uint32_t s_lp, s_lc, s_k;
                int changed = (s_lp != g_pg_surf_pitch || s_lc != g_pg_surf_coff);
                s_k++;
                if (g_doa2u_post_movie && s_t < 1500 && (changed || (s_k & 31) == 0)) { s_t++;
                    s_lp = g_pg_surf_pitch; s_lc = g_pg_surf_coff;
                      }
            }
        }
        g_pg.stats.clears++;
        return 1;
    }

    /* ── Render State ── */
    case NV097_SET_DEPTH_TEST_ENABLE:
        g_pg.depth_test = param ? 1 : 0;
        return 1;

    case NV097_SET_DEPTH_FUNC:
        g_pg.depth_func = param;
        return 1;

    case NV097_SET_DEPTH_MASK:
        g_pg.depth_mask = param ? 1 : 0;
        return 1;

    case NV097_SET_BLEND_ENABLE:
        g_pg.blend_enable = param ? 1 : 0;
        return 1;

    case NV097_SET_BLEND_FUNC_SFACTOR:
        g_pg.blend_sfactor = param;
        return 1;

    case NV097_SET_BLEND_FUNC_DFACTOR:
        g_pg.blend_dfactor = param;
        return 1;

    case 0x034C: /* NV097_SET_BLEND_COLOR (A8R8G8B8) */
        g_pg_blend_color = param;
        return 1;

    case NV097_SET_CULL_FACE_ENABLE:
        g_pg.cull_enable = param ? 1 : 0;
        return 1;

    case NV097_SET_CULL_FACE:
        g_pg.cull_face = param;
        return 1;

    case NV097_SET_FRONT_FACE:
        g_pg.front_face = param;
        return 1;

    case NV097_SET_STENCIL_TEST_ENABLE:
        g_pg.stencil_enable = param ? 1 : 0;
        return 1;

    case NV097_SET_STENCIL_MASK:
        g_pg.stencil_mask = param;
        return 1;

    case NV097_SET_STENCIL_FUNC:
        g_pg.stencil_func = param;
        return 1;

    case NV097_SET_STENCIL_FUNC_REF:
        g_pg.stencil_ref = param;
        return 1;

    case NV097_SET_STENCIL_FUNC_MASK:
        g_pg.stencil_func_mask = param;
        return 1;

    case NV097_SET_STENCIL_OP_FAIL:
        g_pg.stencil_fail = param;
        return 1;

    case NV097_SET_STENCIL_OP_ZFAIL:
        g_pg.stencil_zfail = param;
        return 1;

    case NV097_SET_STENCIL_OP_ZPASS:
        g_pg.stencil_zpass = param;
        return 1;

    case NV097_SET_ALPHA_TEST_ENABLE:
        g_pg.alpha_test = param ? 1 : 0;
        return 1;

    case NV097_SET_ALPHA_FUNC:
        g_pg.alpha_func = param;
        return 1;

    case NV097_SET_ALPHA_REF:
        g_pg.alpha_ref = param;
        return 1;

    case NV097_SET_COLOR_MASK:
        g_pg.color_mask = param;
        return 1;

    case NV097_SET_SHADE_MODE:
        /* 1=flat, 2=gouraud — we always use gouraud */
        return 1;

    /* ── Viewport ── */
    case NV097_SET_VIEWPORT_OFFSET:
    case NV097_SET_VIEWPORT_OFFSET + 4:
    case NV097_SET_VIEWPORT_OFFSET + 8:
    case NV097_SET_VIEWPORT_OFFSET + 12:
    {
        int idx = (method - NV097_SET_VIEWPORT_OFFSET) / 4;
        g_pg.vp_offset[idx] = u2f(param);
        {   extern volatile int g_doa2u_post_movie;
            static int s_n = 0;
            if (g_doa2u_post_movie && idx == 3 && s_n < 6) { s_n++;
                 } }
        return 1;
    }

    case NV097_SET_VIEWPORT_SCALE:
    case NV097_SET_VIEWPORT_SCALE + 4:
    case NV097_SET_VIEWPORT_SCALE + 8:
    case NV097_SET_VIEWPORT_SCALE + 12:
    {
        int idx = (method - NV097_SET_VIEWPORT_SCALE) / 4;
        g_pg.vp_scale[idx] = u2f(param);
        {   /* DOA2U DIAG: the game rewrites this register mid-scene; log each
             * change so the sequence can be read against the draws. */
            extern volatile int g_doa2u_post_movie; extern volatile LONG g_doa2u_heartbeat;
            static float s_last[4]; static int s_n = 0;
            if (g_doa2u_post_movie && idx == 3 && s_n < 60 &&
                memcmp(s_last, g_pg.vp_scale, sizeof s_last) != 0) { s_n++;
                memcpy(s_last, g_pg.vp_scale, sizeof s_last);
                 }
        }
        return 1;
    }

    /* -- Depth clip range (SET_CLIP_MIN / SET_CLIP_MAX) -- */
    case NV097_SET_CLIP_MIN:
    case NV097_SET_CLIP_MAX:
    {
        if (method == NV097_SET_CLIP_MIN) g_pg.clip_min = u2f(param);
        else                              g_pg.clip_max = u2f(param);
        {   extern volatile int g_doa2u_post_movie; extern volatile LONG g_doa2u_heartbeat;
            static float s_last[2]; static int s_n = 0;
            if (g_doa2u_post_movie && method == NV097_SET_CLIP_MAX && s_n < 40 &&
                (s_last[0] != g_pg.clip_min || s_last[1] != g_pg.clip_max)) { s_n++;
                s_last[0] = g_pg.clip_min; s_last[1] = g_pg.clip_max;
                 }
        }
        return 1;
    }

    /* -- Transform program -- */
    case 0x1E94:                       /* SET_TRANSFORM_EXECUTION_MODE */
        g_pg.xform_mode = param;
        return 1;

    /* The NV2A order is LOAD, START, CONSTANT_LOAD. START and CONSTANT_LOAD
     * were swapped here, so every SET_TRANSFORM_CONSTANT run landed at the
     * index the game had just selected as its program entry point (usually 0)
     * and the entry point itself came from the constant pointer. The programs
     * therefore ran with their matrices in the wrong constant slots and only
     * the screen-space bias survived -- the post-movie geometry came out as
     * the raw object-space position plus 0.53, which is nowhere near the
     * screen. */
    case 0x1E9C:                       /* SET_TRANSFORM_PROGRAM_LOAD */
        g_pg.vp.prog_ld_ptr = param;
        DIAG_VP_PTR("load", param);
        return 1;

    case 0x1EA0:                       /* SET_TRANSFORM_PROGRAM_START */
        g_pg.vp.start = param;
        DIAG_VP_PTR("start", param);
        return 1;

    case 0x1EA4:                       /* SET_TRANSFORM_CONSTANT_LOAD */
        g_pg.vp.const_ld_ptr = param;
        DIAG_VP_PTR("cload", param);
        return 1;

    case NV097_SET_WINDOW_CLIP_TYPE:
        g_pg.window_clip_type = param;
        return 1;

    case NV097_SET_WINDOW_CLIP_HORIZONTAL:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x04:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x08:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x0C:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x10:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x14:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x18:
    case NV097_SET_WINDOW_CLIP_HORIZONTAL + 0x1C:
        g_pg.window_clip_h[(method - NV097_SET_WINDOW_CLIP_HORIZONTAL) >> 2] = param;
        return 1;

    case NV097_SET_WINDOW_CLIP_VERTICAL:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x04:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x08:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x0C:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x10:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x14:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x18:
    case NV097_SET_WINDOW_CLIP_VERTICAL + 0x1C:
        g_pg.window_clip_v[(method - NV097_SET_WINDOW_CLIP_VERTICAL) >> 2] = param;
        return 1;

    case NV097_SET_SURFACE_CLIP_HORIZONTAL:
        g_pg.surface_clip_h = param;
        return 1;

    case NV097_SET_SURFACE_CLIP_VERTICAL:
        g_pg.surface_clip_v = param;
        return 1;

    /* DOA2U DIAG: colour surface offset/format/pitch (0x0210/0x0208/0x020C),
     * traced with the [RTT] lines to see the per-frame render-target switch. */
    case 0x0208: case 0x020C: case 0x0210:
    {
        extern volatile int g_doa2u_post_movie; extern volatile LONG g_doa2u_heartbeat;
        static uint32_t s_last[3]; static int s_t = 0;
        int k = (method - 0x0208) / 4;
        if (g_doa2u_post_movie && s_last[k] != param && s_t < 300) { s_t++;
             }
        s_last[k] = param;
        if (k == 0) g_pg.surface_fmt = param;
        if (k == 1) g_pg_surf_pitch = param;
        if (k == 2) g_pg_surf_coff = param;
        return 1;
    }

    /* ── Texture state tracking (4 stages, 0x40 stride) ── */
    case NV097_SET_TEXTURE_OFFSET:
    case NV097_SET_TEXTURE_OFFSET + 0x40:
    case NV097_SET_TEXTURE_OFFSET + 0x80:
    case NV097_SET_TEXTURE_OFFSET + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_OFFSET) / 0x40;
        g_pg.tex[stage].offset = param;
        return 1;
    }
    case NV097_SET_TEXTURE_FORMAT:
    case NV097_SET_TEXTURE_FORMAT + 0x40:
    case NV097_SET_TEXTURE_FORMAT + 0x80:
    case NV097_SET_TEXTURE_FORMAT + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_FORMAT) / 0x40;
        g_pg.tex[stage].format = param;
        return 1;
    }
    case NV097_SET_TEXTURE_ADDRESS:
    case NV097_SET_TEXTURE_ADDRESS + 0x40:
    case NV097_SET_TEXTURE_ADDRESS + 0x80:
    case NV097_SET_TEXTURE_ADDRESS + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_ADDRESS) / 0x40;
        g_pg.tex[stage].address = param;
        return 1;
    }

    case NV097_SET_TEXTURE_CONTROL0:
    case NV097_SET_TEXTURE_CONTROL0 + 0x40:
    case NV097_SET_TEXTURE_CONTROL0 + 0x80:
    case NV097_SET_TEXTURE_CONTROL0 + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_CONTROL0) / 0x40;
        g_pg.tex[stage].control0 = param;
        g_pg.tex[stage].enabled = (param >> 30) & 1;
        {   extern volatile int g_doa2u_post_movie;
            static DWORD s_nx = 0; static uint32_t s_w[4], s_en[4], s_last[4];
            s_w[stage & 3]++; if ((param >> 30) & 1) s_en[stage & 3]++;
            s_last[stage & 3] = param;
            if (g_doa2u_post_movie && GetTickCount() >= s_nx) {
                s_nx = GetTickCount() + 2000;
                 memset(s_w, 0, sizeof s_w); memset(s_en, 0, sizeof s_en);
            }
        }
        return 1;
    }

    case NV097_SET_TEXTURE_CONTROL1:
    case NV097_SET_TEXTURE_CONTROL1 + 0x40:
    case NV097_SET_TEXTURE_CONTROL1 + 0x80:
    case NV097_SET_TEXTURE_CONTROL1 + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_CONTROL1) / 0x40;
        g_pg.tex[stage].control1 = param;
        return 1;
    }

    case NV097_SET_TEXTURE_FILTER:
    case NV097_SET_TEXTURE_FILTER + 0x40:
    case NV097_SET_TEXTURE_FILTER + 0x80:
    case NV097_SET_TEXTURE_FILTER + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_FILTER) / 0x40;
        g_pg.tex[stage].filter = param;
        return 1;
    }
    case 0x1B1C: case 0x1B1C + 0x40: case 0x1B1C + 0x80: case 0x1B1C + 0xC0:
    {
        int stage = (method - 0x1B1C) / 0x40;
        g_pg.tex[stage].image_rect = param;
        return 1;
    }

    case NV097_SET_TEXTURE_PALETTE:
    case NV097_SET_TEXTURE_PALETTE + 0x40:
    case NV097_SET_TEXTURE_PALETTE + 0x80:
    case NV097_SET_TEXTURE_PALETTE + 0xC0:
    {
        int stage = (method - NV097_SET_TEXTURE_PALETTE) / 0x40;
        g_pg.tex[stage].palette = param;
        return 1;
    }

    default:
        if (f & MF_SILENT)
            return 1;  /* Silently handled (ignored but acknowledged) */
        g_pg.stats.methods_ignored++;
        return 0;  /* Truly unhandled */
    }
}

uint32_t g_mhist[0x800];
void pgraph_diag_dump_ignored(void)
{
    extern uint32_t g_dstat[16][3];
    {
        extern uint32_t g_census[12];
        {
        extern uint32_t g_texfmt[64], g_texnull[4];
    }
    }
    { extern uint32_t g_dbail[8], g_dbail_lastic, g_dbail_lastst;
       }
}

void pgraph_d3d11_flush(void)
{
    if (g_pg.in_draw) {
        submit_draw();
        g_pg.in_draw = 0;
    }
    g_pg.stats.frames++;
    g_pg.frame++;
}

void pgraph_d3d11_set_chyron_scroll(uint32_t pixels)
{
    g_pg.chyron_scroll_offset = (float)pixels;
}

void pgraph_d3d11_get_stats(PgraphD3D11Stats *out)
{
    if (out) *out = g_pg.stats;
}
