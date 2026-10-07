/**
 * D3D8→D3D11 Compatibility Device Implementation
 *
 * Implements the Xbox D3D8 IDirect3DDevice8 interface using D3D11.
 * The game's translated RenderWare code calls D3D8 methods through
 * COM vtables; this layer translates those calls to D3D11 equivalents.
 *
 * Architecture:
 * - D3D11 device and swap chain created during initialization
 * - Render state tracking: D3D8 states mapped to D3D11 state objects
 * - Texture/buffer management: D3D8 resource handles wrap D3D11 resources
 * - Fixed-function pipeline: emulated via D3D11 shaders (the Xbox D3D8
 *   pipeline is configurable but not fully programmable)
 *
 * Build: Requires Windows SDK with d3d11.h and dxgi.h
 */

#include "d3d8_internal.h"
#include "d3d8_nv2aff.h"
static ID3D11Buffer *g_nv2aff_idx_ring;   /* NV2A FF index ring, see d3d8_DrawNv2aFF */
static UINT          g_nv2aff_idx_off;
#include "ui/doa3_ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ================================================================
 * Internal device state
 * ================================================================ */

/* Maximum tracked render states, texture stages, and transforms */
#define MAX_RENDER_STATES    256
#define MAX_TEXTURE_STAGES   4
#define MAX_TSS_STATES       32
#define MAX_TRANSFORMS       512
#define MAX_LIGHTS           8

typedef struct D3D8DeviceState {
    /* D3D11 objects */
    ID3D11Device            *d3d11_device;
    ID3D11DeviceContext     *d3d11_context;
    IDXGISwapChain          *swap_chain;

    /* Default render targets: the GUEST frame. This is an offscreen texture
     * of the aspect's guest size (640x480 or 854x480), not the swap chain;
     * the present path scales it into the window aspect-correct. */
    ID3D11Texture2D         *default_tex;
    ID3D11ShaderResourceView *default_srv;
    ID3D11RenderTargetView  *default_rtv;
    ID3D11DepthStencilView  *default_dsv;
    ID3D11Texture2D         *default_depth;

    /* Swap chain back buffer, sized to the window's client area. */
    ID3D11RenderTargetView  *swap_rtv;
    UINT                    swap_w, swap_h;

    /* Window */
    HWND                    hwnd;
    UINT                    width;      /* guest target size */
    UINT                    height;
    D3DFORMAT               backbuffer_format;

    /* State tracking */
    DWORD                   render_states[MAX_RENDER_STATES];
    DWORD                   tss[MAX_TEXTURE_STAGES][MAX_TSS_STATES];
    D3DMATRIX               transforms[MAX_TRANSFORMS];
    D3DVIEWPORT8            viewport;
    D3DMATERIAL8            material;
    D3DLIGHT8               lights[MAX_LIGHTS];
    BOOL                    light_enable[MAX_LIGHTS];

    /* Current shader/FVF */
    DWORD                   vertex_shader;
    DWORD                   pixel_shader;

    /* Scene state */
    BOOL                    in_scene;

    /* Reference count */
    LONG                    ref_count;
} D3D8DeviceState;

/* Global device instance (Xbox has a single D3D device) */
static D3D8DeviceState g_device_state;
static IDirect3DDevice8 g_device;
static BOOL g_device_initialized = FALSE;

/* Suppress Present when NV2A push buffer replay is active */
volatile int g_suppress_present = 0;

/* Current resource bindings */
static IDirect3DVertexBuffer8 *g_cur_vb = NULL;
static UINT                    g_cur_vb_stride = 0;
static IDirect3DIndexBuffer8  *g_cur_ib = NULL;
static UINT                    g_cur_ib_base_vertex = 0;
static IDirect3DBaseTexture8  *g_cur_textures[4] = { NULL };

/* Forward declarations */
static const IDirect3DDevice8Vtbl g_device_vtbl;
static HRESULT d3d8_compose_and_present(void);
static void up_ring_shutdown(void);

/* ================================================================
 * Public frame pump (called from recompiled game code)
 * ================================================================ */
/* DOA3 DIAG: report the render target and viewport a draw would land in.
 * The intro movie is presented by movie_present.c, which binds its own
 * RTV/viewport and never restores this layer's, so post-movie geometry
 * can be valid yet rasterise nowhere. */
void d3d8_DebugDumpTargetState(void)
{
    ID3D11RenderTargetView *rtv = NULL, *own = g_device_state.default_rtv;
    ID3D11DepthStencilView *dsv = NULL;
    D3D11_VIEWPORT vp[8];
    UINT nvp = 8;
    if (!g_device_state.d3d11_context) {
          return;
    }
    ID3D11DeviceContext_OMGetRenderTargets(g_device_state.d3d11_context, 1, &rtv, &dsv);
    ID3D11DeviceContext_RSGetViewports(g_device_state.d3d11_context, &nvp, vp);
    if (rtv) ID3D11RenderTargetView_Release(rtv);
    if (dsv) ID3D11DepthStencilView_Release(dsv);
}
/* Actual swap-chain flips, split by who caused them. During movie playback
 * only the host presenter may flip; a non-zero guest count there is the
 * flicker. */
DWORD g_flip_guest = 0, g_flip_host = 0, g_flip_blocked = 0;
void d3d8_PresentFrame(void)
{
    /* Pump Windows messages */
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) { extern void netplay_shutdown(void); netplay_shutdown(); ExitProcess(0); }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    /* Present the guest frame (scaled into the window) */
    if (g_device_state.swap_chain) {
        g_flip_host++;
        d3d8_compose_and_present();
    }
}

/* Dump the current backbuffer to a .bmp for headless visual verification
 * (the game window lives on a non-interactive desktop under the test
 * harness, so external capture can't see it). Called from the frame wrapper
 * at a few checkpoints. */
void d3d8_DumpBackbufferBMP(const char *path)
{
    if (!g_device_state.swap_chain || !g_device_state.d3d11_device ||
        !g_device_state.d3d11_context)
        return;
    /* The guest frame (not the window-sized swap chain). */
    ID3D11Texture2D *bb = g_device_state.default_tex;
    if (!bb) return;
    ID3D11Texture2D_AddRef(bb);
    D3D11_TEXTURE2D_DESC td;
    ID3D11Texture2D_GetDesc(bb, &td);
    td.Usage = D3D11_USAGE_STAGING;
    td.BindFlags = 0;
    td.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    td.MiscFlags = 0;
    ID3D11Texture2D *st = NULL;
    if (FAILED(ID3D11Device_CreateTexture2D(g_device_state.d3d11_device, &td, NULL, &st)) || !st) {
        ID3D11Texture2D_Release(bb);
        return;
    }
    ID3D11DeviceContext_CopyResource(g_device_state.d3d11_context,
                                     (ID3D11Resource *)st, (ID3D11Resource *)bb);
    D3D11_MAPPED_SUBRESOURCE map;
    if (SUCCEEDED(ID3D11DeviceContext_Map(g_device_state.d3d11_context,
                                          (ID3D11Resource *)st, 0,
                                          D3D11_MAP_READ, 0, &map))) {
        FILE *f = fopen(path, "wb");
        if (f) {
            uint32_t w = td.Width, h = td.Height;
            uint32_t img = w * h * 4;
            uint8_t hdr[54] = {0};
            hdr[0]='B'; hdr[1]='M';
            *(uint32_t *)(hdr+2)  = 54 + img;
            *(uint32_t *)(hdr+10) = 54;
            *(uint32_t *)(hdr+14) = 40;
            *(int32_t  *)(hdr+18) = (int32_t)w;
            *(int32_t  *)(hdr+22) = -(int32_t)h;   /* top-down */
            *(uint16_t *)(hdr+26) = 1;
            *(uint16_t *)(hdr+28) = 32;
            *(uint32_t *)(hdr+34) = img;
            fwrite(hdr, 1, 54, f);
            /* The swap chain is DXGI_FORMAT_R8G8B8A8_UNORM (memory order
             * R,G,B,A) but a 32-bit BMP stores B,G,R,A. Writing the rows
             * verbatim swapped red and blue, so every captured frame read
             * back in the wrong colour -- the FMV end card looked blue in
             * the dumps while the window itself showed it red. Swap the
             * two channels on the way out. */
            {
                uint8_t *row = (uint8_t *)malloc((size_t)w * 4);
                if (row) {
                    for (uint32_t y = 0; y < h; y++) {
                        const uint8_t *src = (const uint8_t *)map.pData + y * map.RowPitch;
                        for (uint32_t x = 0; x < w; x++) {
                            row[x * 4 + 0] = src[x * 4 + 2];   /* B <- R */
                            row[x * 4 + 1] = src[x * 4 + 1];   /* G */
                            row[x * 4 + 2] = src[x * 4 + 0];   /* R <- B */
                            row[x * 4 + 3] = src[x * 4 + 3];
                        }
                        fwrite(row, 1, (size_t)w * 4, f);
                    }
                    free(row);
                }
            }
            fclose(f);
        }
        ID3D11DeviceContext_Unmap(g_device_state.d3d11_context, (ID3D11Resource *)st, 0);
    }
    ID3D11Texture2D_Release(st);
    ID3D11Texture2D_Release(bb);
}

/* ================================================================
 * Internal accessors (used by d3d8_resources/shaders/states)
 * ================================================================ */

IDirect3DDevice8    *d3d8_GetDevice(void) { return &g_device; }
ID3D11Device        *d3d8_GetD3D11Device(void) { return g_device_state.d3d11_device; }
ID3D11DeviceContext *d3d8_GetD3D11Context(void) { return g_device_state.d3d11_context; }
IDXGISwapChain      *d3d8_GetSwapChain(void) { return g_device_state.swap_chain; }
ID3D11RenderTargetView *d3d8_GetDefaultRTV(void) { return g_device_state.default_rtv; }
ID3D11Texture2D     *d3d8_GetGuestTexture(void) { return g_device_state.default_tex; }
/* The window-sized swap chain target, for the overlay drawn after the blit. */
ID3D11RenderTargetView *d3d8_GetPresentRTV(void) { return g_device_state.swap_rtv; }
UINT                 d3d8_GetPresentWidth(void) { return g_device_state.swap_w; }
UINT                 d3d8_GetPresentHeight(void) { return g_device_state.swap_h; }
HWND                 d3d8_GetHWND(void) { return g_device_state.hwnd; }
UINT                 d3d8_GetBackbufferWidth(void) { return g_device_state.width; }
/* Host scissor, for the pgraph to hand NV097_SET_WINDOW_CLIP through.
 * The rasterizer state has ScissorEnable on, so the rect must always be
 * valid -- a zero or negative one is taken as "the whole target" rather
 * than clipping everything away. */
void d3d8_SetScissorRect(int x, int y, int w, int h)
{
    D3D11_RECT r;
    if (!g_device_state.d3d11_context) return;
    if (w <= 0 || h <= 0 || x < 0 || y < 0) {
        x = 0; y = 0; w = (int)g_device_state.width; h = (int)g_device_state.height;
    }
    r.left = x; r.top = y; r.right = x + w; r.bottom = y + h;
    ID3D11DeviceContext_RSSetScissorRects(g_device_state.d3d11_context, 1, &r);
}

void d3d8_ResetScissorRect(void)
{
    d3d8_SetScissorRect(0, 0, (int)g_device_state.width, (int)g_device_state.height);
}

UINT                 d3d8_GetBackbufferHeight(void) { return g_device_state.height; }
const DWORD         *d3d8_GetRenderStates(void) { return g_device_state.render_states; }
const DWORD         *d3d8_GetTSS(DWORD stage) { return (stage < MAX_TEXTURE_STAGES) ? g_device_state.tss[stage] : NULL; }
const D3DMATRIX     *d3d8_GetTransform(D3DTRANSFORMSTATETYPE type) {
    return ((DWORD)type < MAX_TRANSFORMS) ? &g_device_state.transforms[(DWORD)type] : NULL;
}

const D3DLIGHT8     *d3d8_GetLight(DWORD index) {
    return (index < MAX_LIGHTS) ? &g_device_state.lights[index] : NULL;
}

BOOL                 d3d8_GetLightEnable(DWORD index) {
    return (index < MAX_LIGHTS) ? g_device_state.light_enable[index] : FALSE;
}

const D3DMATERIAL8  *d3d8_GetMaterial(void) {
    return &g_device_state.material;
}

UINT                 d3d8_GetNumLights(void) {
    return MAX_LIGHTS;
}

/* ================================================================
 * D3D11 initialization helpers
 * ================================================================ */

static HRESULT d3d11_create_device_and_swap_chain(
    D3D8DeviceState *state,
    D3DPRESENT_PARAMETERS *pp)
{
    DXGI_SWAP_CHAIN_DESC scd;
    D3D_FEATURE_LEVEL feature_level;
    UINT create_flags = 0;
    HRESULT hr;

#ifdef _DEBUG
    create_flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    /* The swap chain takes the window's client size; the guest renders into
     * its own target of pp's size (d3d11_create_render_targets) and the
     * present path scales that into the window, pillarboxed or letterboxed. */
    UINT sw = 0, sh = 0;
    {
        RECT rc;
        if (pp->hDeviceWindow && GetClientRect(pp->hDeviceWindow, &rc)) {
            sw = (UINT)(rc.right - rc.left);
            sh = (UINT)(rc.bottom - rc.top);
        }
    }
    memset(&scd, 0, sizeof(scd));
    scd.BufferCount = pp->BackBufferCount ? pp->BackBufferCount : 1;
    scd.BufferDesc.Width = sw ? sw : (pp->BackBufferWidth ? pp->BackBufferWidth : 640);
    scd.BufferDesc.Height = sh ? sh : (pp->BackBufferHeight ? pp->BackBufferHeight : 480);
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow = pp->hDeviceWindow;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.Windowed = pp->Windowed;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    hr = D3D11CreateDeviceAndSwapChain(
        NULL,
        D3D_DRIVER_TYPE_HARDWARE,
        NULL,
        create_flags,
        NULL, 0,
        D3D11_SDK_VERSION,
        &scd,
        &state->swap_chain,
        &state->d3d11_device,
        &feature_level,
        &state->d3d11_context
    );

    if (FAILED(hr)) {
        return hr;
    }

    state->hwnd = pp->hDeviceWindow;
    state->swap_w = scd.BufferDesc.Width;
    state->swap_h = scd.BufferDesc.Height;
    state->width = pp->BackBufferWidth ? pp->BackBufferWidth : 640;
    state->height = pp->BackBufferHeight ? pp->BackBufferHeight : 480;

    return S_OK;
}

static HRESULT d3d11_create_swap_rtv(D3D8DeviceState *state)
{
    ID3D11Texture2D *back_buffer = NULL;
    HRESULT hr = IDXGISwapChain_GetBuffer(state->swap_chain, 0,
                                          &IID_ID3D11Texture2D,
                                          (void **)&back_buffer);
    if (FAILED(hr)) return hr;
    hr = ID3D11Device_CreateRenderTargetView(state->d3d11_device,
                                             (ID3D11Resource *)back_buffer,
                                             NULL, &state->swap_rtv);
    ID3D11Texture2D_Release(back_buffer);
    return hr;
}

static void d3d11_release_guest_target(D3D8DeviceState *state)
{
    if (state->default_dsv)   { ID3D11DepthStencilView_Release(state->default_dsv);    state->default_dsv = NULL; }
    if (state->default_depth) { ID3D11Texture2D_Release(state->default_depth);         state->default_depth = NULL; }
    if (state->default_srv)   { ID3D11ShaderResourceView_Release(state->default_srv);  state->default_srv = NULL; }
    if (state->default_rtv)   { ID3D11RenderTargetView_Release(state->default_rtv);    state->default_rtv = NULL; }
    if (state->default_tex)   { ID3D11Texture2D_Release(state->default_tex);           state->default_tex = NULL; }
}

/* The guest's frame buffer: colour (sampled by the present blit) + depth, at
 * state->width x state->height. Same format the swap chain had, so the
 * capture tools keep reading RGBA. */
static HRESULT d3d11_create_guest_target(D3D8DeviceState *state)
{
    D3D11_TEXTURE2D_DESC td;
    HRESULT hr;

    memset(&td, 0, sizeof(td));
    td.Width = state->width;
    td.Height = state->height;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DEFAULT;
    td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    hr = ID3D11Device_CreateTexture2D(state->d3d11_device, &td, NULL, &state->default_tex);
    if (FAILED(hr)) return hr;
    hr = ID3D11Device_CreateRenderTargetView(state->d3d11_device,
                                             (ID3D11Resource *)state->default_tex,
                                             NULL, &state->default_rtv);
    if (FAILED(hr)) return hr;
    hr = ID3D11Device_CreateShaderResourceView(state->d3d11_device,
                                               (ID3D11Resource *)state->default_tex,
                                               NULL, &state->default_srv);
    if (FAILED(hr)) return hr;

    td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    hr = ID3D11Device_CreateTexture2D(state->d3d11_device, &td, NULL, &state->default_depth);
    if (FAILED(hr)) return hr;
    hr = ID3D11Device_CreateDepthStencilView(state->d3d11_device,
                                             (ID3D11Resource *)state->default_depth,
                                             NULL, &state->default_dsv);
    if (FAILED(hr)) return hr;

    {   /* start black, like a fresh swap chain */
        const FLOAT black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        ID3D11DeviceContext_ClearRenderTargetView(state->d3d11_context, state->default_rtv, black);
    }
    return S_OK;
}

static HRESULT d3d11_create_render_targets(D3D8DeviceState *state)
{
    HRESULT hr = d3d11_create_swap_rtv(state);
    if (FAILED(hr)) return hr;
    hr = d3d11_create_guest_target(state);
    if (FAILED(hr)) return hr;

    /* Bind default render targets */
    ID3D11DeviceContext_OMSetRenderTargets(state->d3d11_context, 1,
                                            &state->default_rtv,
                                            state->default_dsv);

    return S_OK;
}

static void d3d8_init_default_states(D3D8DeviceState *state)
{
    /* Set Xbox D3D8 default render states */
    memset(state->render_states, 0, sizeof(state->render_states));
    state->render_states[D3DRS_ZENABLE]           = 1;
    state->render_states[D3DRS_FILLMODE]          = D3DFILL_SOLID;
    state->render_states[D3DRS_SHADEMODE]         = 2; /* D3DSHADE_GOURAUD */
    state->render_states[D3DRS_ZWRITEENABLE]      = TRUE;
    state->render_states[D3DRS_ALPHATESTENABLE]    = FALSE;
    state->render_states[D3DRS_SRCBLEND]          = D3DBLEND_ONE;
    state->render_states[D3DRS_DESTBLEND]         = D3DBLEND_ZERO;
    state->render_states[D3DRS_CULLMODE]          = D3DCULL_CCW;
    state->render_states[D3DRS_ZFUNC]             = D3DCMP_LESSEQUAL;
    state->render_states[D3DRS_ALPHAREF]          = 0;
    state->render_states[D3DRS_ALPHAFUNC]         = D3DCMP_ALWAYS;
    state->render_states[D3DRS_ALPHABLENDENABLE]   = FALSE;
    state->render_states[D3DRS_FOGENABLE]         = FALSE;
    state->render_states[D3DRS_STENCILENABLE]     = FALSE;
    state->render_states[D3DRS_COLORWRITEENABLE]  = 0x0F;

    /* Texture-stage defaults.
     *
     * These have to be seeded rather than left at zero. D3DTA_DIFFUSE is 0,
     * so code that treats a zero argument as "never set" cannot tell it
     * apart from a deliberate DIFFUSE and substitutes D3DTA_TEXTURE. That
     * is what turned the untextured 2D overlay quad black: it asks for
     * COLOROP=SELECTARG1 with COLORARG1=DIFFUSE, and the shader was handed
     * TEXTURE instead, sampling an unbound stage. */
    {
        DWORD s;
        memset(state->tss, 0, sizeof(state->tss));
        for (s = 0; s < MAX_TEXTURE_STAGES; s++) {
            state->tss[s][D3DTSS_COLOROP]   = (s == 0) ? D3DTOP_MODULATE
                                                       : D3DTOP_DISABLE;
            state->tss[s][D3DTSS_COLORARG1] = D3DTA_TEXTURE;
            state->tss[s][D3DTSS_COLORARG2] = D3DTA_CURRENT;
            state->tss[s][D3DTSS_ALPHAOP]   = (s == 0) ? D3DTOP_SELECTARG1
                                                       : D3DTOP_DISABLE;
            state->tss[s][D3DTSS_ALPHAARG1] = D3DTA_TEXTURE;
            state->tss[s][D3DTSS_ALPHAARG2] = D3DTA_CURRENT;
        }
    }

    /* Default viewport */
    state->viewport.X = 0;
    state->viewport.Y = 0;
    state->viewport.Width = state->width;
    state->viewport.Height = state->height;
    state->viewport.MinZ = 0.0f;
    state->viewport.MaxZ = 1.0f;

    /* Identity matrices */
    for (int i = 0; i < MAX_TRANSFORMS; i++) {
        memset(&state->transforms[i], 0, sizeof(D3DMATRIX));
        state->transforms[i]._11 = 1.0f;
        state->transforms[i]._22 = 1.0f;
        state->transforms[i]._33 = 1.0f;
        state->transforms[i]._44 = 1.0f;
    }

    state->vertex_shader = 0;
    state->pixel_shader = 0;
    state->in_scene = FALSE;
}

/* ================================================================
 * IDirect3DDevice8 method implementations
 * ================================================================ */

static HRESULT __stdcall dev_QueryInterface(IDirect3DDevice8 *self, const IID *riid, void **ppv)
{
    (void)self; (void)riid; (void)ppv;
    return E_NOINTERFACE;
}

static ULONG __stdcall dev_AddRef(IDirect3DDevice8 *self)
{
    (void)self;
    return InterlockedIncrement(&g_device_state.ref_count);
}

static ULONG __stdcall dev_Release(IDirect3DDevice8 *self)
{
    (void)self;
    LONG ref = InterlockedDecrement(&g_device_state.ref_count);
    if (ref <= 0) {
        /* Cleanup subsystems first */
        up_ring_shutdown();
        if (g_nv2aff_idx_ring) { ID3D11Buffer_Release(g_nv2aff_idx_ring); g_nv2aff_idx_ring = NULL; g_nv2aff_idx_off = 0; }
        d3d8_Nv2aFF_Shutdown();
        d3d8_vsh_shutdown();
        d3d8_combiners_shutdown();
        d3d8_states_shutdown();
        d3d8_shaders_shutdown();

        /* Cleanup D3D11 resources */
        D3D8DeviceState *s = &g_device_state;
        d3d11_release_guest_target(s);
        if (s->swap_rtv) { ID3D11RenderTargetView_Release(s->swap_rtv); s->swap_rtv = NULL; }
        if (s->swap_chain) { IDXGISwapChain_Release(s->swap_chain); s->swap_chain = NULL; }
        if (s->d3d11_context) { ID3D11DeviceContext_Release(s->d3d11_context); s->d3d11_context = NULL; }
        if (s->d3d11_device) { ID3D11Device_Release(s->d3d11_device); s->d3d11_device = NULL; }
        g_device_initialized = FALSE;
    }
    return (ULONG)ref;
}

static HRESULT __stdcall dev_GetDirect3D(IDirect3DDevice8 *self, IDirect3D8 **ppD3D8)
{
    (void)self; (void)ppD3D8;
    /* TODO: return the factory */
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_GetDeviceCaps(IDirect3DDevice8 *self, void *pCaps)
{
    (void)self; (void)pCaps;
    /* TODO: fill with Xbox NV2A capabilities */
    return S_OK;
}

static HRESULT __stdcall dev_GetDisplayMode(IDirect3DDevice8 *self, void *pMode)
{
    (void)self; (void)pMode;
    return S_OK;
}

static HRESULT __stdcall dev_GetCreationParameters(IDirect3DDevice8 *self, void *pParams)
{
    (void)self; (void)pParams;
    return S_OK;
}

static HRESULT __stdcall dev_Reset(IDirect3DDevice8 *self, D3DPRESENT_PARAMETERS *pPP)
{
    (void)self; (void)pPP;
    /* TODO: resize swap chain */
    return S_OK;
}

static DWORD g_d3d_begin_count = 0;
static DWORD g_d3d_end_count = 0;
static DWORD g_d3d_clear_count = 0;
static DWORD g_d3d_draw_count = 0;
static DWORD g_d3d_settransform_count = 0;
static DWORD g_d3d_setrs_count = 0;
static DWORD g_d3d_settexture_count = 0;
static DWORD g_d3d_draw_off = 0, g_d3d_clear_def = 0, g_d3d_clear_off = 0;   /* DOA3 DIAG: target split */
static int g_off_active;

/* ================================================================
 * Present: guest frame -> window
 *
 * The guest renders into default_tex at its own size (640x480 for 4:3,
 * 854x480 for 16:9 -- see video_settings.h). Here it is scaled into the
 * window-sized swap chain at that aspect, centred, with black bars on
 * whichever sides the window has to spare, then the Esc overlay is drawn at
 * window resolution and the chain is flipped. All pipeline state touched here
 * is saved and restored, since the pgraph translator does not re-send state
 * it believes is still bound.
 * ================================================================ */
#include "../game/video_settings.h"
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

static ID3D11VertexShader    *g_blit_vs;
static ID3D11PixelShader     *g_blit_ps;
static ID3D11SamplerState    *g_blit_smp;
static ID3D11RasterizerState *g_blit_rs;
static int                    g_blit_failed;

static const char g_blit_hlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct V { float4 p : SV_Position; float2 uv : TEXCOORD0; };\n"
    "V vsmain(uint id : SV_VertexID) {\n"
    "  V o; float2 uv = float2((id << 1) & 2, id & 2);\n"
    "  o.p = float4(uv * float2(2, -2) + float2(-1, 1), 0, 1); o.uv = uv; return o;\n"
    "}\n"
    "float4 psmain(V i) : SV_Target { return float4(t.Sample(s, i.uv).rgb, 1); }\n";

static int blit_init(void)
{
    ID3D11Device *dev = g_device_state.d3d11_device;
    ID3DBlob *vsb = NULL, *psb = NULL, *err = NULL;
    D3D11_SAMPLER_DESC sd;
    D3D11_RASTERIZER_DESC rd;
    if (g_blit_vs) return 1;
    if (g_blit_failed || !dev) return 0;
    g_blit_failed = 1;
    if (FAILED(D3DCompile(g_blit_hlsl, sizeof(g_blit_hlsl) - 1, "present_vs", NULL, NULL,
                          "vsmain", "vs_4_0", 0, 0, &vsb, &err)) ||
        FAILED(D3DCompile(g_blit_hlsl, sizeof(g_blit_hlsl) - 1, "present_ps", NULL, NULL,
                          "psmain", "ps_4_0", 0, 0, &psb, &err))) {
        return 0;
    }
    if (FAILED(ID3D11Device_CreateVertexShader(dev, ID3D10Blob_GetBufferPointer(vsb),
                                               ID3D10Blob_GetBufferSize(vsb), NULL, &g_blit_vs)) ||
        FAILED(ID3D11Device_CreatePixelShader(dev, ID3D10Blob_GetBufferPointer(psb),
                                              ID3D10Blob_GetBufferSize(psb), NULL, &g_blit_ps)))
        return 0;
    ID3D10Blob_Release(vsb);
    ID3D10Blob_Release(psb);

    memset(&sd, 0, sizeof(sd));
    sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = sd.AddressV = sd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    sd.MaxLOD = D3D11_FLOAT32_MAX;
    if (FAILED(ID3D11Device_CreateSamplerState(dev, &sd, &g_blit_smp))) return 0;

    memset(&rd, 0, sizeof(rd));
    rd.FillMode = D3D11_FILL_SOLID;
    rd.CullMode = D3D11_CULL_NONE;
    rd.DepthClipEnable = TRUE;
    if (FAILED(ID3D11Device_CreateRasterizerState(dev, &rd, &g_blit_rs))) return 0;

    g_blit_failed = 0;
    return 1;
}

/* Follow the window: a mode switch or a drag-resize changes the client area,
 * and the chain must match it or DXGI stretches the whole buffer again. */
static void swap_resize_if_needed(void)
{
    D3D8DeviceState *s = &g_device_state;
    RECT rc;
    UINT w, h;
    HRESULT hr;
    if (!s->hwnd || !GetClientRect(s->hwnd, &rc)) return;
    w = (UINT)(rc.right - rc.left);
    h = (UINT)(rc.bottom - rc.top);
    if (!w || !h) return;                       /* minimised */
    if (w == s->swap_w && h == s->swap_h && s->swap_rtv) return;
    if (s->swap_rtv) { ID3D11RenderTargetView_Release(s->swap_rtv); s->swap_rtv = NULL; }
    hr = IDXGISwapChain_ResizeBuffers(s->swap_chain, 0, w, h, DXGI_FORMAT_UNKNOWN, 0);
    if (FAILED(hr)) {
    } else {
        s->swap_w = w;
        s->swap_h = h;
    }
    d3d11_create_swap_rtv(s);
}

/* The aspect or internal-resolution setting changed: rebuild the guest target
 * at the new size and tell the game. Runs right after a flip, so nothing is
 * mid-frame. */
static void d3d8_apply_target_size_change(void)
{
    D3D8DeviceState *s = &g_device_state;
    unsigned w, h;
    D3D11_VIEWPORT vp;
    video_guest_target_size(video_get_aspect(), &w, &h);
    if (w == s->width && h == s->height) return;

    ID3D11DeviceContext_OMSetRenderTargets(s->d3d11_context, 0, NULL, NULL);
    d3d11_release_guest_target(s);
    s->width = w;
    s->height = h;
    if (FAILED(d3d11_create_guest_target(s))) {
        return;
    }
    g_off_active = 0;
    ID3D11DeviceContext_OMSetRenderTargets(s->d3d11_context, 1, &s->default_rtv, s->default_dsv);
    /* The translator draws in target pixels through a viewport that covers
     * the whole target (set once at CreateDevice), so it has to follow. */
    vp.TopLeftX = 0.0f; vp.TopLeftY = 0.0f;
    vp.Width = (FLOAT)w; vp.Height = (FLOAT)h;
    vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;
    ID3D11DeviceContext_RSSetViewports(s->d3d11_context, 1, &vp);
    s->viewport.X = 0; s->viewport.Y = 0;
    s->viewport.Width = w; s->viewport.Height = h;
    d3d8_ResetScissorRect();
    video_sync_guest_widescreen();
}

static void d3d8_keep_prev_frame(void);
static HRESULT d3d8_compose_and_present(void)
{
    D3D8DeviceState *s = &g_device_state;
    ID3D11DeviceContext *ctx = s->d3d11_context;
    HRESULT hr;
    if (!s->swap_chain || !ctx) return E_FAIL;
    d3d8_keep_prev_frame();

    swap_resize_if_needed();
    if (s->swap_rtv && s->default_srv && blit_init()) {
        /* save */
        ID3D11InputLayout *il = NULL; D3D11_PRIMITIVE_TOPOLOGY topo;
        ID3D11VertexShader *vs = NULL; ID3D11PixelShader *ps = NULL;
        ID3D11ShaderResourceView *srv = NULL; ID3D11SamplerState *smp = NULL;
        ID3D11RasterizerState *rs = NULL; ID3D11BlendState *bs = NULL;
        FLOAT bf[4]; UINT bmask; ID3D11DepthStencilState *dss = NULL; UINT sref;
        ID3D11RenderTargetView *rtv = NULL; ID3D11DepthStencilView *dsv = NULL;
        D3D11_VIEWPORT vps[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
        D3D11_RECT scs[D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE];
        UINT nvp = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
        UINT nsc = D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE;
        const FLOAT black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        D3D11_VIEWPORT vp;
        float dar = (video_get_aspect() == VIDEO_ASPECT_16_9) ? (16.0f / 9.0f) : (4.0f / 3.0f);
        float sw = (float)s->swap_w, sh = (float)s->swap_h;

        ID3D11DeviceContext_IAGetInputLayout(ctx, &il);
        ID3D11DeviceContext_IAGetPrimitiveTopology(ctx, &topo);
        ID3D11DeviceContext_VSGetShader(ctx, &vs, NULL, NULL);
        ID3D11DeviceContext_PSGetShader(ctx, &ps, NULL, NULL);
        ID3D11DeviceContext_PSGetShaderResources(ctx, 0, 1, &srv);
        ID3D11DeviceContext_PSGetSamplers(ctx, 0, 1, &smp);
        ID3D11DeviceContext_RSGetState(ctx, &rs);
        ID3D11DeviceContext_RSGetViewports(ctx, &nvp, vps);
        ID3D11DeviceContext_RSGetScissorRects(ctx, &nsc, scs);
        ID3D11DeviceContext_OMGetBlendState(ctx, &bs, bf, &bmask);
        ID3D11DeviceContext_OMGetDepthStencilState(ctx, &dss, &sref);
        ID3D11DeviceContext_OMGetRenderTargets(ctx, 1, &rtv, &dsv);

        /* guest frame, aspect-fitted and centred */
        if (sw / sh > dar) { vp.Height = sh; vp.Width = sh * dar; }
        else               { vp.Width = sw;  vp.Height = sw / dar; }
        vp.TopLeftX = (float)(int)((sw - vp.Width) * 0.5f);
        vp.TopLeftY = (float)(int)((sh - vp.Height) * 0.5f);
        vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;

        ID3D11DeviceContext_OMSetRenderTargets(ctx, 1, &s->swap_rtv, NULL);
        ID3D11DeviceContext_ClearRenderTargetView(ctx, s->swap_rtv, black);
        ID3D11DeviceContext_RSSetViewports(ctx, 1, &vp);
        ID3D11DeviceContext_RSSetState(ctx, g_blit_rs);
        ID3D11DeviceContext_OMSetBlendState(ctx, NULL, NULL, 0xFFFFFFFFu);
        ID3D11DeviceContext_OMSetDepthStencilState(ctx, NULL, 0);
        ID3D11DeviceContext_IASetInputLayout(ctx, NULL);
        ID3D11DeviceContext_IASetPrimitiveTopology(ctx, D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        ID3D11DeviceContext_VSSetShader(ctx, g_blit_vs, NULL, 0);
        ID3D11DeviceContext_PSSetShader(ctx, g_blit_ps, NULL, 0);
        ID3D11DeviceContext_PSSetShaderResources(ctx, 0, 1, &s->default_srv);
        ID3D11DeviceContext_PSSetSamplers(ctx, 0, 1, &g_blit_smp);
        ID3D11DeviceContext_Draw(ctx, 3, 0);
        {   /* unbind the guest texture before it is a render target again */
            ID3D11ShaderResourceView *none = NULL;
            ID3D11DeviceContext_PSSetShaderResources(ctx, 0, 1, &none);
        }

        /* Overlay last, at window resolution. It draws nothing at all unless
         * the user has opened it, so a normal frame costs one predicate. */
        doa3_ui_render();

        /* restore */
        ID3D11DeviceContext_IASetInputLayout(ctx, il);
        ID3D11DeviceContext_IASetPrimitiveTopology(ctx, topo);
        ID3D11DeviceContext_VSSetShader(ctx, vs, NULL, 0);
        ID3D11DeviceContext_PSSetShader(ctx, ps, NULL, 0);
        ID3D11DeviceContext_PSSetShaderResources(ctx, 0, 1, &srv);
        ID3D11DeviceContext_PSSetSamplers(ctx, 0, 1, &smp);
        ID3D11DeviceContext_RSSetState(ctx, rs);
        ID3D11DeviceContext_RSSetViewports(ctx, nvp, vps);
        ID3D11DeviceContext_RSSetScissorRects(ctx, nsc, scs);
        ID3D11DeviceContext_OMSetBlendState(ctx, bs, bf, bmask);
        ID3D11DeviceContext_OMSetDepthStencilState(ctx, dss, sref);
        ID3D11DeviceContext_OMSetRenderTargets(ctx, 1, &rtv, dsv);
        if (il)  ID3D11InputLayout_Release(il);
        if (vs)  ID3D11VertexShader_Release(vs);
        if (ps)  ID3D11PixelShader_Release(ps);
        if (srv) ID3D11ShaderResourceView_Release(srv);
        if (smp) ID3D11SamplerState_Release(smp);
        if (rs)  ID3D11RasterizerState_Release(rs);
        if (bs)  ID3D11BlendState_Release(bs);
        if (dss) ID3D11DepthStencilState_Release(dss);
        if (rtv) ID3D11RenderTargetView_Release(rtv);
        if (dsv) ID3D11DepthStencilView_Release(dsv);
    }

    hr = IDXGISwapChain_Present(s->swap_chain, 0, 0);
    d3d8_apply_target_size_change();
    return hr;
}

/* Online play: while the game thread waits for the other player's input it
 * redraws the last guest frame with the overlay on top, so the window and
 * the Esc menu stay live during the wait. */
HRESULT d3d8_PresentHold(void)
{
    return d3d8_compose_and_present();
}

static HRESULT __stdcall dev_Present(IDirect3DDevice8 *self, const RECT *src, const RECT *dst, HWND hWnd, void *pDirty)
{
    static DWORD frame_count = 0;
    static DWORD last_tick = 0;
    (void)self; (void)src; (void)dst; (void)hWnd; (void)pDirty;

    frame_count++;
    DWORD now = GetTickCount();
    if (last_tick == 0) last_tick = now;
    if (now - last_tick >= 2000) {
        g_d3d_draw_off = g_d3d_clear_def = g_d3d_clear_off = 0;
        g_flip_guest = g_flip_host = g_flip_blocked = 0;
        frame_count = 0;
        g_d3d_begin_count = g_d3d_end_count = 0;
        g_d3d_clear_count = g_d3d_draw_count = 0;
        g_d3d_settransform_count = g_d3d_setrs_count = 0;
        g_d3d_settexture_count = 0;
        last_tick = now;
    }

    /* DOA3 DIAG: dump what is actually presented once the intro movie hands
     * the screen back, on a wall clock -- the draw-count triggers in the
     * pgraph translator fire during the movie and never again, so the
     * post-FMV screen was never captured. Buffer 0 is read before Present,
     * so this is the frame the user sees. Opt in with DOA3_PMSHOTS=1. */
    {
        extern volatile int g_doa3_post_movie;
        void d3d8_DumpBackbufferBMP(const char *path);
        static int s_on = -1, s_n = 0;
        static DWORD s_next = 0;
        if (s_on < 0) s_on = getenv("DOA3_PMSHOTS") ? 1 : 0;
        if (s_on && g_doa3_post_movie && s_n < 40) {
            DWORD now = GetTickCount();
            if (!s_next) s_next = now;
            if (now >= s_next) {
                char p[64];
                sprintf(p, "pm%02d.bmp", s_n++);
                s_next = now + 5000;
                d3d8_DebugDumpTargetState();   /* is the backbuffer even bound? */
                {   /* method profile of the post-FMV screen: the [FRAME] dump
                     * that used to carry this only fires every 600 frames and
                     * the post-movie loop runs at under one. */
                    void pgraph_diag_dump_ignored(void);
                    pgraph_diag_dump_ignored();
                }
                d3d8_DumpBackbufferBMP(p);
            }
        }
    }

    /* Pump Windows messages: the game's internal main loop drives rendering,
     * so our external message pump never runs. Process messages here to keep
     * the window responsive and handle input. */
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            extern void netplay_shutdown(void);
            netplay_shutdown();
            ExitProcess(0);
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    /* While the intro movie is playing the host presenter owns the swap
     * chain (movie_present.c). The game runs its own frame loop underneath
     * and calls Present every frame; flipping its back buffer here shows a
     * frame the movie never wrote, which is the flicker. Count it and drop
     * it until the presenter hands the screen over. */
    {
        extern int doa3_movie_host_owns_screen(void);
        if (doa3_movie_host_owns_screen()) {
            g_flip_blocked++;
            return S_OK;
        }
    }
    g_flip_guest++;
    /* The overlay is drawn by the compose step, onto the window-sized frame. */
    return d3d8_compose_and_present();
}

static HRESULT __stdcall dev_GetBackBuffer(IDirect3DDevice8 *self, INT iBackBuffer, DWORD Type, IDirect3DSurface8 **ppSurface)
{
    (void)self; (void)iBackBuffer; (void)Type; (void)ppSurface;
    /* TODO: wrap back buffer as D3D8 surface */
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_BeginScene(IDirect3DDevice8 *self)
{
    (void)self;
    g_device_state.in_scene = TRUE;
    g_d3d_begin_count++;
    return S_OK;
}

static HRESULT __stdcall dev_EndScene(IDirect3DDevice8 *self)
{
    (void)self;
    g_device_state.in_scene = FALSE;
    g_d3d_end_count++;
    return S_OK;
}

/* DOA3: offscreen colour target for the guest's render-to-texture passes.
 *
 * The guest D3D switches its colour surface every frame (a 256x256 texture
 * for a reflection/shadow pass, then the back buffer); the pgraph translator
 * follows NV097_SET_SURFACE_COLOR_OFFSET and asks for an offscreen target
 * of the surface-clip size while a non-backbuffer surface is bound. Until
 * this existed every such pass -- including its clear -- landed on the swap
 * chain and wiped the scene drawn just before it. */
/* DOA3: one host colour target PER GUEST OFFSCREEN SURFACE.
 *
 * There used to be a single g_off_tex shared by every render-to-texture pass,
 * and nv_apply_draw_state bound it to any draw whose texture offset matched
 * whichever surface the game had rendered into MOST RECENTLY.
 * DOA3 uses four of these (0x01728980 is the floor's reflection; the attract
 * sequence adds 0x01847680, 0x019D8F80 and 0x03D25000), so a fullscreen quad
 * sampling its own captured frame at 0x03D25000 was handed the reflection
 * pass instead and rasterised the stage -- palm fronds and all -- across the
 * whole screen, randomly, for the rest of the attract loop.
 *
 * Key each target by the guest colour offset that owns it, so a pass renders
 * into its own texture and a later draw samples back exactly that one. */
#define OFFRT_N 8
typedef struct {
    uint32_t key;                       /* guest SET_SURFACE_COLOR_OFFSET */
    ID3D11Texture2D           *tex;
    ID3D11RenderTargetView    *rtv;
    ID3D11Texture2D           *depth;
    ID3D11DepthStencilView    *dsv;
    ID3D11ShaderResourceView  *srv;
    UINT w, h;
} OffRT;
static OffRT g_offrt[OFFRT_N];
static int   g_off_cur = -1;            /* slot currently bound for rendering */

static ID3D11RenderTargetView *cur_rtv(void)
{
    return (g_off_active && g_off_cur >= 0) ? g_offrt[g_off_cur].rtv
                                            : g_device_state.default_rtv;
}
static ID3D11DepthStencilView *cur_dsv(void)
{
    return (g_off_active && g_off_cur >= 0) ? g_offrt[g_off_cur].dsv
                                            : g_device_state.default_dsv;
}

static void offrt_free(OffRT *s)
{
    if (s->srv)   { ID3D11ShaderResourceView_Release(s->srv);   s->srv = NULL; }
    if (s->rtv)   { ID3D11RenderTargetView_Release(s->rtv);     s->rtv = NULL; }
    if (s->tex)   { ID3D11Texture2D_Release(s->tex);            s->tex = NULL; }
    if (s->dsv)   { ID3D11DepthStencilView_Release(s->dsv);     s->dsv = NULL; }
    if (s->depth) { ID3D11Texture2D_Release(s->depth);          s->depth = NULL; }
}

/* Slot for `key`, creating or resizing its textures as needed. */
static int offrt_slot(uint32_t key, UINT w, UINT h)
{
    ID3D11Device *dev = g_device_state.d3d11_device;
    int i, slot = -1;
    for (i = 0; i < OFFRT_N; i++)
        if (g_offrt[i].tex && g_offrt[i].key == key) { slot = i; break; }
    if (slot < 0)
        for (i = 0; i < OFFRT_N; i++)
            if (!g_offrt[i].tex) { slot = i; break; }
    if (slot < 0) {
        /* Full: reuse the last slot rather than grow without bound. */
        slot = OFFRT_N - 1;
        offrt_free(&g_offrt[slot]);
    }
    if (slot < 0) return -1;
    if (!g_offrt[slot].rtv || g_offrt[slot].w != w || g_offrt[slot].h != h) {
        D3D11_TEXTURE2D_DESC td; HRESULT hr;
        offrt_free(&g_offrt[slot]);
        memset(&td, 0, sizeof td);
        td.Width = w; td.Height = h; td.MipLevels = 1; td.ArraySize = 1;
        td.Format = DXGI_FORMAT_B8G8R8A8_UNORM; td.SampleDesc.Count = 1;
        td.Usage = D3D11_USAGE_DEFAULT;
        td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
        hr = ID3D11Device_CreateTexture2D(dev, &td, NULL, &g_offrt[slot].tex);
        if (FAILED(hr)) return -1;
        hr = ID3D11Device_CreateRenderTargetView(dev,
                (ID3D11Resource *)g_offrt[slot].tex, NULL, &g_offrt[slot].rtv);
        if (FAILED(hr)) { offrt_free(&g_offrt[slot]); return -1; }
        td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        hr = ID3D11Device_CreateTexture2D(dev, &td, NULL, &g_offrt[slot].depth);
        if (SUCCEEDED(hr))
            ID3D11Device_CreateDepthStencilView(dev,
                (ID3D11Resource *)g_offrt[slot].depth, NULL, &g_offrt[slot].dsv);
        g_offrt[slot].w = w; g_offrt[slot].h = h;
    }
    g_offrt[slot].key = key;
    return slot;
}

int d3d8_SetOffscreenTarget(uint32_t key, UINT w, UINT h)
{
    int slot;
    if (!g_device_state.d3d11_device || !w || !h) return 0;
    slot = offrt_slot(key, w, h);
    if (slot < 0) return 0;
    ID3D11DeviceContext_OMSetRenderTargets(g_device_state.d3d11_context, 1,
                                           &g_offrt[slot].rtv, g_offrt[slot].dsv);
    {   /* The translator maps the guest surface onto -1..1 NDC, so the
         * viewport has to be this target's own size. Left at the back
         * buffer's, a 256x512 target (the beach's palm-shadow surface) got
         * only a stretched corner of the silhouette, and the sand showed
         * that crop as random black shapes. */
        D3D11_VIEWPORT vp;
        vp.TopLeftX = 0.0f; vp.TopLeftY = 0.0f;
        vp.Width = (FLOAT)w; vp.Height = (FLOAT)h;
        vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;
        ID3D11DeviceContext_RSSetViewports(g_device_state.d3d11_context, 1, &vp);
    }
    g_off_cur = slot;
    g_off_active = 1;
    return 1;
}

void d3d8_RestoreDefaultTarget(void)
{
    if (!g_device_state.d3d11_context) return;
    ID3D11DeviceContext_OMSetRenderTargets(g_device_state.d3d11_context, 1,
                                            &g_device_state.default_rtv, g_device_state.default_dsv);
    {   /* back to the guest frame's viewport (see d3d8_SetOffscreenTarget) */
        D3D11_VIEWPORT vp;
        vp.TopLeftX = 0.0f; vp.TopLeftY = 0.0f;
        vp.Width = (FLOAT)g_device_state.width; vp.Height = (FLOAT)g_device_state.height;
        vp.MinDepth = 0.0f; vp.MaxDepth = 1.0f;
        ID3D11DeviceContext_RSSetViewports(g_device_state.d3d11_context, 1, &vp);
    }
    g_off_active = 0;
}

int d3d8_OffscreenTargetActive(void) { return g_off_active; }

/* DOA3: sample the offscreen target from a later draw (the reflective floor
 * binds the reflection surface as its texture). The texture is created with
 * BIND_SHADER_RESOURCE above; the view is made on first use and dropped when
 * the target is recreated. Refuses while the target is still bound for
 * rendering, which D3D11 would silently unbind. */
/* Is there a host target for this guest surface, ready to be sampled? */
int d3d8_HasOffscreenTexture(uint32_t key)
{
    int i;
    for (i = 0; i < OFFRT_N; i++)
        if (g_offrt[i].tex && g_offrt[i].key == key)
            return !(g_off_active && g_off_cur == i);
    return 0;
}

int d3d8_BindOffscreenTexture(uint32_t key, UINT stage)
{
    int i, slot = -1;
    if (!g_device_state.d3d11_device) return 0;
    for (i = 0; i < OFFRT_N; i++)
        if (g_offrt[i].tex && g_offrt[i].key == key) { slot = i; break; }
    if (slot < 0) return 0;
    /* Refuse while this very target is still bound for rendering: D3D11 would
     * silently unbind it and the draw would sample nothing. */
    if (g_off_active && g_off_cur == slot) return 0;
    if (!g_offrt[slot].srv) {
        if (FAILED(ID3D11Device_CreateShaderResourceView(g_device_state.d3d11_device,
                (ID3D11Resource *)g_offrt[slot].tex, NULL, &g_offrt[slot].srv)))
            { g_offrt[slot].srv = NULL; return 0; }
    }
    ID3D11DeviceContext_PSSetShaderResources(g_device_state.d3d11_context, stage, 1,
                                             &g_offrt[slot].srv);
    return 1;
}

/* A draw that samples the frame buffer it is rendering into. The Omega
 * boss fight runs a fullscreen effect whose stage-0 texture is the colour
 * surface itself (0xEE8000): on the console that memory holds the scene
 * just drawn, here the scene lives in default_tex and the guest memory is
 * never written, so the quad sampled blank memory and covered the whole
 * fight in black (only the one-pixel border it does not cover showed the
 * stage). Bind a copy of the host frame as it is at this draw -- a copy,
 * because D3D11 cannot sample the render target that is bound. */
typedef struct { ID3D11Texture2D *tex; ID3D11ShaderResourceView *srv; UINT w, h; } FbCopy;
static FbCopy g_fbcopy;      /* the current frame as of the sampling draw */
static FbCopy g_prevframe;   /* the last presented frame */
static int    g_prevframe_valid;
static volatile LONG g_prevframe_want;   /* presents left to keep copying */

static int fbcopy_ensure(FbCopy *c)
{
    D3D11_TEXTURE2D_DESC td;
    ID3D11Texture2D *src = g_device_state.default_tex;
    if (!g_device_state.d3d11_device || !src) return 0;
    ID3D11Texture2D_GetDesc(src, &td);
    if (c->tex && c->w == td.Width && c->h == td.Height) return 1;
    if (c->srv) { ID3D11ShaderResourceView_Release(c->srv); c->srv = NULL; }
    if (c->tex) { ID3D11Texture2D_Release(c->tex); c->tex = NULL; }
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    td.Usage = D3D11_USAGE_DEFAULT;
    td.CPUAccessFlags = 0;
    td.MiscFlags = 0;
    if (FAILED(ID3D11Device_CreateTexture2D(g_device_state.d3d11_device, &td, NULL, &c->tex)))
        { c->tex = NULL; return 0; }
    if (FAILED(ID3D11Device_CreateShaderResourceView(g_device_state.d3d11_device,
            (ID3D11Resource *)c->tex, NULL, &c->srv))) {
        ID3D11Texture2D_Release(c->tex); c->tex = NULL; c->srv = NULL;
        return 0;
    }
    c->w = td.Width; c->h = td.Height;
    if (c == &g_prevframe) g_prevframe_valid = 0;
    return 1;
}

int d3d8_BindFramebufferCopy(UINT stage)
{
    if (!fbcopy_ensure(&g_fbcopy)) return 0;   /* copying is fine with or without default_tex bound */
    ID3D11DeviceContext_CopyResource(g_device_state.d3d11_context,
                                     (ID3D11Resource *)g_fbcopy.tex,
                                     (ID3D11Resource *)g_device_state.default_tex);
    ID3D11DeviceContext_PSSetShaderResources(g_device_state.d3d11_context, stage, 1, &g_fbcopy.srv);
    return 1;
}

/* The flip buffer the game is NOT drawing into holds the frame on screen,
 * i.e. the last one presented. Omega's after-image effect blends exactly
 * that over the new frame (it samples the other flip buffer: 0xEE8000 while
 * rendering into 0x1050000, and vice versa), so keep a copy of each
 * presented frame while the effect is in use. Before the first copy exists
 * the current frame stands in for it. */
int d3d8_BindPrevFrame(UINT stage)
{
    InterlockedExchange(&g_prevframe_want, 120);
    /* also while an offscreen target is bound: the effect renders its after-image buffer from the frame on screen */
    if (!g_prevframe_valid) return d3d8_BindFramebufferCopy(stage);
    ID3D11DeviceContext_PSSetShaderResources(g_device_state.d3d11_context, stage, 1, &g_prevframe.srv);
    return 1;
}

/* The after-image must be built from the 3D scene only. Copying the finished
 * frame at present put the HUD and the KO / YOU LOSE text into the blur (the
 * text ghosted) and fed each frame's blur overlay back into the next one,
 * which compounded the smear until the fight looked like it was crawling.
 * The pgraph translator calls this right before the first 2D screen-space
 * draw of a frame (HUD, text, fades, the effect's own overlay pass); the
 * present-time copy below only runs for a frame that had no such draw. */
static int g_prevframe_snapped;

void d3d8_SnapshotSceneForAfterImage(void)
{
    if (g_prevframe_want <= 0 || g_prevframe_snapped || g_off_active) return;
    if (!fbcopy_ensure(&g_prevframe)) return;
    ID3D11DeviceContext_CopyResource(g_device_state.d3d11_context,
                                     (ID3D11Resource *)g_prevframe.tex,
                                     (ID3D11Resource *)g_device_state.default_tex);
    g_prevframe_valid = 1;
    g_prevframe_snapped = 1;
}

static void d3d8_keep_prev_frame(void)
{
    int snapped = g_prevframe_snapped;
    g_prevframe_snapped = 0;            /* next frame takes a fresh snapshot */
    if (g_prevframe_want <= 0) return;
    InterlockedDecrement(&g_prevframe_want);
    if (snapped || !fbcopy_ensure(&g_prevframe)) return;
    ID3D11DeviceContext_CopyResource(g_device_state.d3d11_context,
                                     (ID3D11Resource *)g_prevframe.tex,
                                     (ID3D11Resource *)g_device_state.default_tex);
    g_prevframe_valid = 1;
}

static HRESULT __stdcall dev_Clear(IDirect3DDevice8 *self, DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    (void)self; (void)Count; (void)pRects; (void)Stencil;
    g_d3d_clear_count++; if (g_off_active) g_d3d_clear_off++; else g_d3d_clear_def++;

    /* While the intro movie is playing, movie_present.c owns the screen.
     *
     * Sofdec writes movie frames straight into the Xbox front-buffer pair
     * rather than calling Present, so the host presenter is the only thing
     * putting the movie on our swap chain. The game still runs its own frame
     * loop underneath, and once D3DDevice_SetRenderTarget started working the
     * guest clear finally reached the swap chain and wiped the movie frame --
     * the background flickered away on every guest present while the overlay
     * the game draws on top survived. Hold the clear back until the presenter
     * hands the screen over, the same way the pgraph translator already holds
     * back guest geometry.
     *
     * The rationale above was written when the hold-back was added to the
     * pgraph translator; the clear itself was never actually gated, so once
     * SetRenderTarget started working the movie flickered on every guest
     * frame. Gate it on the same predicate the translator uses. */
    {
        extern int doa3_movie_host_owns_screen(void);
        if (doa3_movie_host_owns_screen())
            Flags &= ~(DWORD)D3DCLEAR_TARGET;
    }
    if (Flags & D3DCLEAR_TARGET) {
        float clear_color[4] = {
            ((Color >> 16) & 0xFF) / 255.0f,  /* R */
            ((Color >>  8) & 0xFF) / 255.0f,  /* G */
            ((Color >>  0) & 0xFF) / 255.0f,  /* B */
            ((Color >> 24) & 0xFF) / 255.0f,  /* A */
        };
        ID3D11DeviceContext_ClearRenderTargetView(g_device_state.d3d11_context,
                                                   cur_rtv(),
                                                   clear_color);
    }

    if (Flags & (D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL)) {
        UINT clear_flags = 0;
        if (Flags & D3DCLEAR_ZBUFFER) clear_flags |= D3D11_CLEAR_DEPTH;
        if (Flags & D3DCLEAR_STENCIL) clear_flags |= D3D11_CLEAR_STENCIL;

        if (cur_dsv())
            ID3D11DeviceContext_ClearDepthStencilView(g_device_state.d3d11_context,
                                                    cur_dsv(),
                                                    clear_flags, Z, (UINT8)Stencil);
    }

    return S_OK;
}

static HRESULT __stdcall dev_SetTransform(IDirect3DDevice8 *self, D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix)
{
    (void)self;
    g_d3d_settransform_count++;
    if ((DWORD)State < MAX_TRANSFORMS && pMatrix) {
        g_device_state.transforms[(DWORD)State] = *pMatrix;
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetTransform(IDirect3DDevice8 *self, D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
    (void)self;
    if ((DWORD)State < MAX_TRANSFORMS && pMatrix) {
        *pMatrix = g_device_state.transforms[(DWORD)State];
    }
    return S_OK;
}

static HRESULT __stdcall dev_SetRenderState(IDirect3DDevice8 *self, D3DRENDERSTATETYPE State, DWORD Value)
{
    (void)self;
    g_d3d_setrs_count++;
    if ((DWORD)State < MAX_RENDER_STATES) {
        g_device_state.render_states[(DWORD)State] = Value;
    }
    /* Mark combiner state dirty if any PS register combiner state changed */
    if ((DWORD)State >= D3DRS_PSALPHAINPUTS0 && (DWORD)State <= D3DRS_PSINPUTTEXTURE) {
        d3d8_combiners_mark_dirty();
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetRenderState(IDirect3DDevice8 *self, D3DRENDERSTATETYPE State, DWORD *pValue)
{
    (void)self;
    if ((DWORD)State < MAX_RENDER_STATES && pValue) {
        *pValue = g_device_state.render_states[(DWORD)State];
    }
    return S_OK;
}

static HRESULT __stdcall dev_SetTextureStageState(IDirect3DDevice8 *self, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    (void)self;
    if (Stage < MAX_TEXTURE_STAGES && (DWORD)Type < MAX_TSS_STATES) {
        g_device_state.tss[Stage][(DWORD)Type] = Value;
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetTextureStageState(IDirect3DDevice8 *self, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
    (void)self;
    if (Stage < MAX_TEXTURE_STAGES && (DWORD)Type < MAX_TSS_STATES && pValue) {
        *pValue = g_device_state.tss[Stage][(DWORD)Type];
    }
    return S_OK;
}


static HRESULT __stdcall dev_SetTexture(IDirect3DDevice8 *self, DWORD Stage, IDirect3DBaseTexture8 *pTexture)
{
    (void)self;
    g_d3d_settexture_count++;
    if (Stage >= 4) return E_INVALIDARG;
    g_cur_textures[Stage] = pTexture;

    /* Bind SRV to pixel shader */
    if (pTexture) {
        D3D8Texture *tex = (D3D8Texture *)pTexture;
        if (tex->srv) {
            ID3D11DeviceContext_PSSetShaderResources(g_device_state.d3d11_context,
                Stage, 1, &tex->srv);
        }
        /* Mark texture stage as active */
        if (g_device_state.tss[Stage][D3DTSS_COLOROP] == D3DTOP_DISABLE)
            g_device_state.tss[Stage][D3DTSS_COLOROP] = D3DTOP_MODULATE;
    } else {
        ID3D11ShaderResourceView *null_srv = NULL;
        ID3D11DeviceContext_PSSetShaderResources(g_device_state.d3d11_context,
            Stage, 1, &null_srv);
        g_device_state.tss[Stage][D3DTSS_COLOROP] = D3DTOP_DISABLE;
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetTexture(IDirect3DDevice8 *self, DWORD Stage, IDirect3DBaseTexture8 **ppTexture)
{
    (void)self; (void)Stage; (void)ppTexture;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_SetStreamSource(IDirect3DDevice8 *self, UINT StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT Stride)
{
    (void)self;
    if (StreamNumber != 0) return S_OK; /* Only stream 0 supported */
    g_cur_vb = pStreamData;
    g_cur_vb_stride = Stride;

    if (pStreamData) {
        D3D8VertexBuffer *vb = (D3D8VertexBuffer *)pStreamData;
        UINT offset = 0;
        ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context,
            0, 1, &vb->d3d11_buffer, &Stride, &offset);
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetStreamSource(IDirect3DDevice8 *self, UINT StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride)
{
    (void)self; (void)StreamNumber; (void)ppStreamData; (void)pStride;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_SetIndices(IDirect3DDevice8 *self, IDirect3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex)
{
    (void)self;
    g_cur_ib = pIndexData;
    g_cur_ib_base_vertex = BaseVertexIndex;

    if (pIndexData) {
        D3D8IndexBuffer *ib = (D3D8IndexBuffer *)pIndexData;
        DXGI_FORMAT fmt = (ib->format == D3DFMT_INDEX32)
            ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
        ID3D11DeviceContext_IASetIndexBuffer(g_device_state.d3d11_context,
            ib->d3d11_buffer, fmt, 0);
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetIndices(IDirect3DDevice8 *self, IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex)
{
    (void)self; (void)ppIndexData; (void)pBaseVertexIndex;
    return E_NOTIMPL;
}

static D3D11_PRIMITIVE_TOPOLOGY map_primitive_type(D3DPRIMITIVETYPE pt, UINT count, UINT *out_count)
{
    switch (pt) {
    case D3DPT_TRIANGLELIST:  *out_count = count * 3; return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
    case D3DPT_TRIANGLESTRIP: *out_count = count + 2; return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
    case D3DPT_TRIANGLEFAN:   *out_count = count * 3; return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
    case D3DPT_LINELIST:      *out_count = count * 2; return D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
    case D3DPT_LINESTRIP:     *out_count = count + 1; return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
    case D3DPT_POINTLIST:     *out_count = count;     return D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
    case D3DPT_QUADLIST:      *out_count = count * 6; return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
    default:                  *out_count = 0;          return D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED;
    }
}

/* ================================================================
 * Triangle fan / quad list → triangle list conversion
 *
 * D3D11 doesn't support triangle fans or quad lists.
 * Convert vertex data in-place to triangle list.
 * Returns malloc'd buffer (caller must free) or NULL if no conversion needed.
 * ================================================================ */

static void *convert_fan_or_quad(D3DPRIMITIVETYPE pt, const void *src,
                                  UINT prim_count, UINT stride,
                                  UINT *out_vertex_count)
{
    BYTE *dst;
    const BYTE *s = (const BYTE *)src;
    UINT i;

    if (pt == D3DPT_TRIANGLEFAN) {
        /* Fan: vertex 0 is the hub, each triangle is (0, i+1, i+2) */
        UINT tri_verts = prim_count * 3;
        dst = (BYTE *)malloc(tri_verts * stride);
        if (!dst) return NULL;

        for (i = 0; i < prim_count; i++) {
            memcpy(dst + (i * 3 + 0) * stride, s, stride);                      /* v0 (hub) */
            memcpy(dst + (i * 3 + 1) * stride, s + (i + 1) * stride, stride);   /* v[i+1] */
            memcpy(dst + (i * 3 + 2) * stride, s + (i + 2) * stride, stride);   /* v[i+2] */
        }
        *out_vertex_count = tri_verts;
        return dst;
    }

    if (pt == D3DPT_QUADLIST) {
        /* Quad list: each quad (v0,v1,v2,v3) → 2 triangles (v0,v1,v2), (v0,v2,v3) */
        UINT tri_verts = prim_count * 6;
        dst = (BYTE *)malloc(tri_verts * stride);
        if (!dst) return NULL;

        for (i = 0; i < prim_count; i++) {
            const BYTE *q = s + i * 4 * stride;
            memcpy(dst + (i * 6 + 0) * stride, q + 0 * stride, stride);  /* v0 */
            memcpy(dst + (i * 6 + 1) * stride, q + 1 * stride, stride);  /* v1 */
            memcpy(dst + (i * 6 + 2) * stride, q + 2 * stride, stride);  /* v2 */
            memcpy(dst + (i * 6 + 3) * stride, q + 0 * stride, stride);  /* v0 */
            memcpy(dst + (i * 6 + 4) * stride, q + 2 * stride, stride);  /* v2 */
            memcpy(dst + (i * 6 + 5) * stride, q + 3 * stride, stride);  /* v3 */
        }
        *out_vertex_count = tri_verts;
        return dst;
    }

    return NULL; /* no conversion needed */
}

/* ================================================================
 * DrawPrimitiveUP ring buffer
 *
 * Instead of creating and destroying a D3D11 buffer on every
 * DrawPrimitiveUP call, use a persistent ring buffer.
 * ================================================================ */

#define UP_RING_BUFFER_SIZE (16 * 1024 * 1024) /* 16MB: a 65K-index batch is 1.8 MB, clipped up to 3x */

static ID3D11Buffer *g_up_ring_buffer = NULL;
static UINT          g_up_ring_offset = 0;

static HRESULT up_ring_init(void)
{
    D3D11_BUFFER_DESC bd;
    memset(&bd, 0, sizeof(bd));
    bd.ByteWidth = UP_RING_BUFFER_SIZE;
    bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    return ID3D11Device_CreateBuffer(g_device_state.d3d11_device, &bd, NULL, &g_up_ring_buffer);
}

static void up_ring_shutdown(void)
{
    if (g_up_ring_buffer) {
        ID3D11Buffer_Release(g_up_ring_buffer);
        g_up_ring_buffer = NULL;
    }
    g_up_ring_offset = 0;
}

/* Upload vertex data to ring buffer, returns offset. Returns (UINT)-1 on failure. */
static UINT up_ring_upload(const void *data, UINT size)
{
    D3D11_MAPPED_SUBRESOURCE mapped;
    D3D11_MAP map_type;
    HRESULT hr;
    UINT offset;

    if (!g_up_ring_buffer) {
        if (FAILED(up_ring_init())) return (UINT)-1;
    }

    if (size > UP_RING_BUFFER_SIZE) return (UINT)-1;

    /* Wrap around if not enough space */
    if (g_up_ring_offset + size > UP_RING_BUFFER_SIZE) {
        g_up_ring_offset = 0;
        map_type = D3D11_MAP_WRITE_DISCARD;
    } else {
        map_type = D3D11_MAP_WRITE_NO_OVERWRITE;
    }

    hr = ID3D11DeviceContext_Map(g_device_state.d3d11_context,
        (ID3D11Resource *)g_up_ring_buffer, 0, map_type, 0, &mapped);
    if (FAILED(hr)) return (UINT)-1;

    offset = g_up_ring_offset;
    memcpy((BYTE *)mapped.pData + offset, data, size);

    ID3D11DeviceContext_Unmap(g_device_state.d3d11_context,
        (ID3D11Resource *)g_up_ring_buffer, 0);

    g_up_ring_offset = (offset + size + 15) & ~15;  /* 16-byte align */
    return offset;
}

static HRESULT __stdcall dev_DrawPrimitive(IDirect3DDevice8 *self, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    (void)self;
    g_d3d_draw_count++;
    D3D11_PRIMITIVE_TOPOLOGY topology;
    UINT vertex_count;

    topology = map_primitive_type(PrimitiveType, PrimitiveCount, &vertex_count);
    if (vertex_count == 0) return E_INVALIDARG;

    /* Prepare pipeline: shaders, input layout, constant buffers, render states */
    /* Vertex shader: try programmable VS first, fall back to FVF fixed-function */
    if (!d3d8_vsh_prepare_draw(g_device_state.vertex_shader))
        d3d8_shaders_prepare_draw(g_device_state.vertex_shader);
    d3d8_combiners_prepare_draw(); /* overrides PS if combiner shader is active */
    d3d8_states_apply();

    ID3D11DeviceContext_IASetPrimitiveTopology(g_device_state.d3d11_context, topology);
    ID3D11DeviceContext_Draw(g_device_state.d3d11_context, vertex_count, StartVertex);
    return S_OK;
}

static HRESULT __stdcall dev_DrawIndexedPrimitive(IDirect3DDevice8 *self, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
    (void)self; (void)MinVertexIndex; (void)NumVertices;
    g_d3d_draw_count++;
    D3D11_PRIMITIVE_TOPOLOGY topology;
    UINT index_count;

    topology = map_primitive_type(PrimitiveType, PrimitiveCount, &index_count);
    if (index_count == 0) return E_INVALIDARG;

    /* Vertex shader: try programmable VS first, fall back to FVF fixed-function */
    if (!d3d8_vsh_prepare_draw(g_device_state.vertex_shader))
        d3d8_shaders_prepare_draw(g_device_state.vertex_shader);
    d3d8_combiners_prepare_draw(); /* overrides PS if combiner shader is active */
    d3d8_states_apply();

    ID3D11DeviceContext_IASetPrimitiveTopology(g_device_state.d3d11_context, topology);
    ID3D11DeviceContext_DrawIndexed(g_device_state.d3d11_context, index_count, StartIndex, (INT)g_cur_ib_base_vertex);
    return S_OK;
}

static HRESULT __stdcall dev_DrawPrimitiveUP(IDirect3DDevice8 *self, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexData, UINT VertexStreamZeroStride)
{
    (void)self;
    g_d3d_draw_count++; if (g_off_active) g_d3d_draw_off++;
    D3D11_PRIMITIVE_TOPOLOGY topology;
    UINT vertex_count, vb_size, ring_offset;
    const void *draw_data = pVertexData;
    void *converted = NULL;

    if (!pVertexData || !VertexStreamZeroStride) return E_INVALIDARG;

    topology = map_primitive_type(PrimitiveType, PrimitiveCount, &vertex_count);
    if (vertex_count == 0) return E_INVALIDARG;

    /* Convert triangle fans and quad lists to triangle lists */
    if (PrimitiveType == D3DPT_TRIANGLEFAN || PrimitiveType == D3DPT_QUADLIST) {
        converted = convert_fan_or_quad(PrimitiveType, pVertexData,
                                         PrimitiveCount, VertexStreamZeroStride,
                                         &vertex_count);
        if (converted) draw_data = converted;
    }

    vb_size = vertex_count * VertexStreamZeroStride;

    /* Upload to ring buffer */
    ring_offset = up_ring_upload(draw_data, vb_size);
    if (converted) free(converted);

    if (ring_offset == (UINT)-1) return E_OUTOFMEMORY;

    /* Bind ring buffer at the right offset */
    ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context,
        0, 1, &g_up_ring_buffer, &VertexStreamZeroStride, &ring_offset);

    /* Vertex shader: try programmable VS first, fall back to FVF fixed-function */
    if (!d3d8_vsh_prepare_draw(g_device_state.vertex_shader))
        d3d8_shaders_prepare_draw(g_device_state.vertex_shader);
    d3d8_combiners_prepare_draw(); /* overrides PS if combiner shader is active */
    d3d8_states_apply();

    ID3D11DeviceContext_IASetPrimitiveTopology(g_device_state.d3d11_context, topology);
    ID3D11DeviceContext_Draw(g_device_state.d3d11_context, vertex_count, 0);

    /* Restore previous VB binding if any */
    if (g_cur_vb) {
        D3D8VertexBuffer *vb = (D3D8VertexBuffer *)g_cur_vb;
        UINT restore_offset = 0;
        ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context,
            0, 1, &vb->d3d11_buffer, &g_cur_vb_stride, &restore_offset);
    }
    return S_OK;
}

static HRESULT __stdcall dev_DrawIndexedPrimitiveUP(IDirect3DDevice8 *self, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, const void *pIndexData, D3DFORMAT IndexDataFormat, const void *pVertexData, UINT VertexStreamZeroStride)
{
    (void)self; (void)MinVertexIndex;
    g_d3d_draw_count++;
    D3D11_PRIMITIVE_TOPOLOGY topology;
    D3D11_BUFFER_DESC bd;
    D3D11_SUBRESOURCE_DATA sd;
    ID3D11Buffer *tmp_vb = NULL, *tmp_ib = NULL;
    UINT index_count, vb_size, ib_size, offset = 0;
    UINT idx_bytes;
    DXGI_FORMAT ib_fmt;
    HRESULT hr;

    if (!pVertexData || !pIndexData || !VertexStreamZeroStride) return E_INVALIDARG;

    topology = map_primitive_type(PrimitiveType, PrimitiveCount, &index_count);
    if (index_count == 0) return E_INVALIDARG;

    idx_bytes = (IndexDataFormat == D3DFMT_INDEX32) ? 4 : 2;
    ib_fmt = (IndexDataFormat == D3DFMT_INDEX32) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
    vb_size = NumVertices * VertexStreamZeroStride;
    ib_size = index_count * idx_bytes;

    /* Create temp vertex buffer */
    memset(&bd, 0, sizeof(bd));
    bd.ByteWidth = vb_size;
    bd.Usage = D3D11_USAGE_IMMUTABLE;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    memset(&sd, 0, sizeof(sd));
    sd.pSysMem = pVertexData;
    hr = ID3D11Device_CreateBuffer(g_device_state.d3d11_device, &bd, &sd, &tmp_vb);
    if (FAILED(hr)) return hr;

    /* Create temp index buffer */
    bd.ByteWidth = ib_size;
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    sd.pSysMem = pIndexData;
    hr = ID3D11Device_CreateBuffer(g_device_state.d3d11_device, &bd, &sd, &tmp_ib);
    if (FAILED(hr)) { ID3D11Buffer_Release(tmp_vb); return hr; }

    /* Bind, prepare, draw */
    ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context,
        0, 1, &tmp_vb, &VertexStreamZeroStride, &offset);
    ID3D11DeviceContext_IASetIndexBuffer(g_device_state.d3d11_context,
        tmp_ib, ib_fmt, 0);

    /* Vertex shader: try programmable VS first, fall back to FVF fixed-function */
    if (!d3d8_vsh_prepare_draw(g_device_state.vertex_shader))
        d3d8_shaders_prepare_draw(g_device_state.vertex_shader);
    d3d8_combiners_prepare_draw(); /* overrides PS if combiner shader is active */
    d3d8_states_apply();

    ID3D11DeviceContext_IASetPrimitiveTopology(g_device_state.d3d11_context, topology);
    ID3D11DeviceContext_DrawIndexed(g_device_state.d3d11_context, index_count, 0, 0);

    /* Cleanup temp buffers */
    ID3D11Buffer_Release(tmp_ib);
    ID3D11Buffer_Release(tmp_vb);

    /* Restore previous bindings */
    if (g_cur_vb) {
        D3D8VertexBuffer *vb = (D3D8VertexBuffer *)g_cur_vb;
        offset = 0;
        ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context,
            0, 1, &vb->d3d11_buffer, &g_cur_vb_stride, &offset);
    }
    if (g_cur_ib) {
        D3D8IndexBuffer *ib = (D3D8IndexBuffer *)g_cur_ib;
        DXGI_FORMAT fmt = (ib->format == D3DFMT_INDEX32) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT;
        ID3D11DeviceContext_IASetIndexBuffer(g_device_state.d3d11_context,
            ib->d3d11_buffer, fmt, 0);
    }
    return S_OK;
}

static HRESULT __stdcall dev_CreateTexture(IDirect3DDevice8 *self, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8 **ppTexture)
{
    (void)self; (void)Pool;
    return d3d8_CreateTextureImpl(Width, Height, Levels, Usage, Format, ppTexture);
}

static HRESULT __stdcall dev_CreateVertexBuffer(IDirect3DDevice8 *self, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8 **ppVertexBuffer)
{
    (void)self; (void)Pool;
    return d3d8_CreateVertexBufferImpl(Length, Usage, FVF, ppVertexBuffer);
}

static HRESULT __stdcall dev_CreateIndexBuffer(IDirect3DDevice8 *self, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8 **ppIndexBuffer)
{
    (void)self; (void)Pool;
    return d3d8_CreateIndexBufferImpl(Length, Usage, Format, ppIndexBuffer);
}

static HRESULT __stdcall dev_CreateRenderTarget(IDirect3DDevice8 *self, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, IDirect3DSurface8 **ppSurface)
{
    (void)self; (void)Width; (void)Height; (void)Format; (void)MultiSample; (void)Lockable; (void)ppSurface;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_CreateDepthStencilSurface(IDirect3DDevice8 *self, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8 **ppSurface)
{
    (void)self; (void)Width; (void)Height; (void)Format; (void)MultiSample; (void)ppSurface;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_SetRenderTarget(IDirect3DDevice8 *self, IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pZStencilSurface)
{
    (void)self; (void)pRenderTarget; (void)pZStencilSurface;
    /* TODO: resolve D3D8 surface to D3D11 RTV/DSV */
    return S_OK;
}

static HRESULT __stdcall dev_GetRenderTarget(IDirect3DDevice8 *self, IDirect3DSurface8 **ppRenderTarget)
{
    (void)self; (void)ppRenderTarget;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_GetDepthStencilSurface(IDirect3DDevice8 *self, IDirect3DSurface8 **ppZStencilSurface)
{
    (void)self; (void)ppZStencilSurface;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_SetViewport(IDirect3DDevice8 *self, const D3DVIEWPORT8 *pViewport)
{
    (void)self;
    if (pViewport) {
        g_device_state.viewport = *pViewport;

        D3D11_VIEWPORT d3d11_vp;
        d3d11_vp.TopLeftX = (FLOAT)pViewport->X;
        d3d11_vp.TopLeftY = (FLOAT)pViewport->Y;
        d3d11_vp.Width    = (FLOAT)pViewport->Width;
        d3d11_vp.Height   = (FLOAT)pViewport->Height;
        d3d11_vp.MinDepth = pViewport->MinZ;
        d3d11_vp.MaxDepth = pViewport->MaxZ;
        ID3D11DeviceContext_RSSetViewports(g_device_state.d3d11_context, 1, &d3d11_vp);
    }
    return S_OK;
}

static HRESULT __stdcall dev_GetViewport(IDirect3DDevice8 *self, D3DVIEWPORT8 *pViewport)
{
    (void)self;
    if (pViewport) *pViewport = g_device_state.viewport;
    return S_OK;
}

static HRESULT __stdcall dev_SetMaterial(IDirect3DDevice8 *self, const D3DMATERIAL8 *pMaterial)
{
    (void)self;
    if (pMaterial) g_device_state.material = *pMaterial;
    return S_OK;
}

static HRESULT __stdcall dev_GetMaterial(IDirect3DDevice8 *self, D3DMATERIAL8 *pMaterial)
{
    (void)self;
    if (pMaterial) *pMaterial = g_device_state.material;
    return S_OK;
}

static HRESULT __stdcall dev_SetLight(IDirect3DDevice8 *self, DWORD Index, const D3DLIGHT8 *pLight)
{
    (void)self;
    if (Index < MAX_LIGHTS && pLight) g_device_state.lights[Index] = *pLight;
    return S_OK;
}

static HRESULT __stdcall dev_GetLight(IDirect3DDevice8 *self, DWORD Index, D3DLIGHT8 *pLight)
{
    (void)self;
    if (Index < MAX_LIGHTS && pLight) *pLight = g_device_state.lights[Index];
    return S_OK;
}

static HRESULT __stdcall dev_LightEnable(IDirect3DDevice8 *self, DWORD Index, BOOL Enable)
{
    (void)self;
    if (Index < MAX_LIGHTS) g_device_state.light_enable[Index] = Enable;
    return S_OK;
}

static HRESULT __stdcall dev_CreateVertexShader(IDirect3DDevice8 *self, const DWORD *pDeclaration, const DWORD *pFunction, DWORD *pHandle, DWORD Usage)
{
    (void)self; (void)pDeclaration; (void)Usage;
    if (!pHandle) return E_INVALIDARG;
    if (!pFunction) return E_INVALIDARG;
    /* Count instructions: each is 4 DWORDs, last has bit 0 of word[3] set (END flag) */
    {
        int i, num_insns = 0;
        for (i = 0; i < 136; i++) {
            num_insns++;
            if (pFunction[i * 4 + 3] & 1) break;  /* END bit in last word */
        }
        return d3d8_vsh_create_shader(pFunction, num_insns, pHandle);
    }
}

static HRESULT __stdcall dev_SetVertexShader(IDirect3DDevice8 *self, DWORD Handle)
{
    (void)self;
    g_device_state.vertex_shader = Handle;
    return S_OK;
}

static HRESULT __stdcall dev_GetVertexShader(IDirect3DDevice8 *self, DWORD *pHandle)
{
    (void)self;
    if (pHandle) *pHandle = g_device_state.vertex_shader;
    return S_OK;
}

static HRESULT __stdcall dev_SetVertexShaderConstant(IDirect3DDevice8 *self, INT Register, const void *pConstantData, DWORD ConstantCount)
{
    (void)self;
    d3d8_vsh_set_constant(Register, pConstantData, ConstantCount);
    return S_OK;
}

static HRESULT __stdcall dev_SetPixelShader(IDirect3DDevice8 *self, DWORD Handle)
{
    (void)self;
    g_device_state.pixel_shader = Handle;
    d3d8_combiners_set_pixel_shader(Handle);
    return S_OK;
}

static HRESULT __stdcall dev_GetPixelShader(IDirect3DDevice8 *self, DWORD *pHandle)
{
    (void)self;
    if (pHandle) *pHandle = g_device_state.pixel_shader;
    return S_OK;
}

static HRESULT __stdcall dev_SetPixelShaderConstant(IDirect3DDevice8 *self, INT Register, const void *pConstantData, DWORD ConstantCount)
{
    (void)self; (void)Register; (void)pConstantData; (void)ConstantCount;
    return S_OK;
}

static void __stdcall dev_SetGammaRamp(IDirect3DDevice8 *self, DWORD Flags, const D3DGAMMARAMP *pRamp)
{
    (void)self; (void)Flags; (void)pRamp;
}

static void __stdcall dev_GetGammaRamp(IDirect3DDevice8 *self, D3DGAMMARAMP *pRamp)
{
    (void)self; (void)pRamp;
}

static HRESULT __stdcall dev_SetPalette(IDirect3DDevice8 *self, DWORD PaletteNumber, const void *pEntries)
{
    (void)self; (void)PaletteNumber; (void)pEntries;
    return S_OK;
}

static HRESULT __stdcall dev_BeginPush(IDirect3DDevice8 *self, DWORD Count, DWORD **ppPush)
{
    (void)self; (void)Count; (void)ppPush;
    /* TODO: Xbox push buffer emulation */
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_EndPush(IDirect3DDevice8 *self, DWORD *pPush)
{
    (void)self; (void)pPush;
    return E_NOTIMPL;
}

static HRESULT __stdcall dev_Swap(IDirect3DDevice8 *self, DWORD Flags)
{
    (void)self; (void)Flags;

    /* Pump Windows messages (same as dev_Present) */
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            extern void netplay_shutdown(void);
            netplay_shutdown();
            ExitProcess(0);
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return d3d8_compose_and_present();
}

/* ================================================================
 * Vtable
 * ================================================================ */

static const IDirect3DDevice8Vtbl g_device_vtbl = {
    dev_QueryInterface,
    dev_AddRef,
    dev_Release,
    dev_GetDirect3D,
    dev_GetDeviceCaps,
    dev_GetDisplayMode,
    dev_GetCreationParameters,
    dev_Reset,
    dev_Present,
    dev_GetBackBuffer,
    dev_BeginScene,
    dev_EndScene,
    dev_Clear,
    dev_SetTransform,
    dev_GetTransform,
    dev_SetRenderState,
    dev_GetRenderState,
    dev_SetTextureStageState,
    dev_GetTextureStageState,
    dev_SetTexture,
    dev_GetTexture,
    dev_SetStreamSource,
    dev_GetStreamSource,
    dev_SetIndices,
    dev_GetIndices,
    dev_DrawPrimitive,
    dev_DrawIndexedPrimitive,
    dev_DrawPrimitiveUP,
    dev_DrawIndexedPrimitiveUP,
    dev_CreateTexture,
    dev_CreateVertexBuffer,
    dev_CreateIndexBuffer,
    dev_CreateRenderTarget,
    dev_CreateDepthStencilSurface,
    dev_SetRenderTarget,
    dev_GetRenderTarget,
    dev_GetDepthStencilSurface,
    dev_SetViewport,
    dev_GetViewport,
    dev_SetMaterial,
    dev_GetMaterial,
    dev_SetLight,
    dev_GetLight,
    dev_LightEnable,
    dev_SetVertexShader,
    dev_GetVertexShader,
    dev_SetVertexShaderConstant,
    dev_SetPixelShader,
    dev_GetPixelShader,
    dev_SetPixelShaderConstant,
    dev_SetGammaRamp,
    dev_GetGammaRamp,
    dev_SetPalette,
    dev_BeginPush,
    dev_EndPush,
    dev_Swap,
};

/* ================================================================
 * Public API
 * ================================================================ */

IDirect3DDevice8 *xbox_GetD3DDevice(void)
{
    return g_device_initialized ? &g_device : NULL;
}

/* ================================================================
 * IDirect3D8 factory implementation
 * ================================================================ */

static IDirect3D8 g_d3d8;
static LONG g_d3d8_ref = 0;

static HRESULT __stdcall d3d8_QueryInterface(IDirect3D8 *self, const IID *riid, void **ppv)
{
    (void)self; (void)riid; (void)ppv;
    return E_NOINTERFACE;
}

static ULONG __stdcall d3d8_AddRef(IDirect3D8 *self)
{
    (void)self;
    return (ULONG)InterlockedIncrement(&g_d3d8_ref);
}

static ULONG __stdcall d3d8_Release(IDirect3D8 *self)
{
    (void)self;
    return (ULONG)InterlockedDecrement(&g_d3d8_ref);
}

static HRESULT __stdcall d3d8_CreateDevice(IDirect3D8 *self, UINT Adapter, DWORD DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS *pPP, IDirect3DDevice8 **ppDevice)
{
    (void)self; (void)Adapter; (void)DeviceType; (void)BehaviorFlags;
    HRESULT hr;

    if (!pPP || !ppDevice) return E_INVALIDARG;

    memset(&g_device_state, 0, sizeof(g_device_state));
    g_device_state.ref_count = 1;

    if (!pPP->hDeviceWindow) pPP->hDeviceWindow = hFocusWindow;

    hr = d3d11_create_device_and_swap_chain(&g_device_state, pPP);
    if (FAILED(hr)) return hr;

    hr = d3d11_create_render_targets(&g_device_state);
    if (FAILED(hr)) return hr;

    /* Show black until the game's first frame. Nothing presents during boot,
     * and the window otherwise shows unpainted white until the intro movie. */
    {
        const FLOAT black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        ID3D11DeviceContext_ClearRenderTargetView(g_device_state.d3d11_context,
                                                  g_device_state.swap_rtv, black);
        IDXGISwapChain_Present(g_device_state.swap_chain, 0, 0);
    }

    d3d8_init_default_states(&g_device_state);

    /* Set initial viewport (D3D11 requires explicit viewport) */
    {
        D3D11_VIEWPORT vp;
        vp.TopLeftX = 0.0f;
        vp.TopLeftY = 0.0f;
        vp.Width    = (FLOAT)g_device_state.width;
        vp.Height   = (FLOAT)g_device_state.height;
        vp.MinDepth = 0.0f;
        vp.MaxDepth = 1.0f;
        ID3D11DeviceContext_RSSetViewports(g_device_state.d3d11_context, 1, &vp);
    }

    /* Scissoring is enabled in the rasterizer state, so start it at the whole
     * target; without this the default empty rect would clip every draw. */
    d3d8_ResetScissorRect();

    /* Initialize shader and state subsystems */
    hr = d3d8_shaders_init();
    if (SUCCEEDED(hr)) hr = d3d8_Nv2aFF_Init();
    if (FAILED(hr)) {
        return hr;
    }

    hr = d3d8_states_init();
    if (FAILED(hr)) {
        return hr;
    }

    hr = d3d8_combiners_init();
    if (FAILED(hr)) {
        /* Non-fatal: fall back to fixed-function pixel shaders */
    }

    hr = d3d8_vsh_init();
    if (FAILED(hr)) {
        /* Non-fatal: fall back to FVF vertex shaders */
    }

    g_device.lpVtbl = &g_device_vtbl;
    g_device_initialized = TRUE;

    *ppDevice = &g_device;
    return S_OK;
}

static const IDirect3D8Vtbl g_d3d8_vtbl = {
    d3d8_QueryInterface,
    d3d8_AddRef,
    d3d8_Release,
    d3d8_CreateDevice,
};

IDirect3D8 *xbox_Direct3DCreate8(UINT SDKVersion)
{
    (void)SDKVersion;
    g_d3d8.lpVtbl = &g_d3d8_vtbl;
    g_d3d8_ref = 1;
    return &g_d3d8;
}

/* ================================================================
 * NV2A fixed-function GPU draw (see d3d8_nv2aff.h)
 * ================================================================ */

#define NV2AFF_IDX_RING_SIZE (4 * 1024 * 1024)   /* 2M 16-bit indices */

/* Same ring discipline as the vertex ring above. Returns the byte offset. */
static UINT nv2aff_idx_upload(const void *data, UINT size)
{
    D3D11_MAPPED_SUBRESOURCE mapped;
    D3D11_MAP map_type;
    UINT off;
    if (!g_nv2aff_idx_ring) {
        D3D11_BUFFER_DESC bd;
        memset(&bd, 0, sizeof bd);
        bd.ByteWidth = NV2AFF_IDX_RING_SIZE;
        bd.Usage = D3D11_USAGE_DYNAMIC;
        bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
        bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        if (FAILED(ID3D11Device_CreateBuffer(g_device_state.d3d11_device, &bd, NULL, &g_nv2aff_idx_ring)))
            return (UINT)-1;
    }
    if (size > NV2AFF_IDX_RING_SIZE) return (UINT)-1;
    if (g_nv2aff_idx_off + size > NV2AFF_IDX_RING_SIZE) {
        g_nv2aff_idx_off = 0;
        map_type = D3D11_MAP_WRITE_DISCARD;
    } else {
        map_type = D3D11_MAP_WRITE_NO_OVERWRITE;
    }
    if (FAILED(ID3D11DeviceContext_Map(g_device_state.d3d11_context,
            (ID3D11Resource *)g_nv2aff_idx_ring, 0, map_type, 0, &mapped)))
        return (UINT)-1;
    off = g_nv2aff_idx_off;
    memcpy((BYTE *)mapped.pData + off, data, size);
    ID3D11DeviceContext_Unmap(g_device_state.d3d11_context, (ID3D11Resource *)g_nv2aff_idx_ring, 0);
    g_nv2aff_idx_off = (off + size + 15) & ~15u;
    return off;
}

long d3d8_DrawNv2aFF(const Nv2aFFVertex *verts, unsigned nverts,
                     const uint16_t *idx, unsigned nidx, int topology,
                     const Nv2aFFConstants *cb)
{
    UINT stride = sizeof(Nv2aFFVertex), vb_off, ib_off;
    if (!verts || !idx || !nverts || !nidx) return E_INVALIDARG;
    g_d3d_draw_count++; if (g_off_active) g_d3d_draw_off++;

    vb_off = up_ring_upload(verts, nverts * stride);
    if (vb_off == (UINT)-1) return E_OUTOFMEMORY;
    ib_off = nv2aff_idx_upload(idx, nidx * 2);
    if (ib_off == (UINT)-1) return E_OUTOFMEMORY;

    /* PS side exactly as the XYZRHW path: PS constants, combiner override,
     * render + sampler state. The VS it binds is replaced just below. */
    d3d8_shaders_prepare_draw(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
    d3d8_combiners_prepare_draw();
    d3d8_states_apply();
    if (!d3d8_Nv2aFF_Bind(cb)) return E_FAIL;

    ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context, 0, 1, &g_up_ring_buffer, &stride, &vb_off);
    ID3D11DeviceContext_IASetIndexBuffer(g_device_state.d3d11_context, g_nv2aff_idx_ring, DXGI_FORMAT_R16_UINT, 0);
    ID3D11DeviceContext_IASetPrimitiveTopology(g_device_state.d3d11_context, (D3D11_PRIMITIVE_TOPOLOGY)topology);
    ID3D11DeviceContext_DrawIndexed(g_device_state.d3d11_context, nidx, ib_off / 2, 0);

    /* Restore the game's own bindings, as DrawPrimitiveUP does. */
    if (g_cur_vb) {
        D3D8VertexBuffer *vb = (D3D8VertexBuffer *)g_cur_vb;
        UINT restore_offset = 0;
        ID3D11DeviceContext_IASetVertexBuffers(g_device_state.d3d11_context, 0, 1, &vb->d3d11_buffer, &g_cur_vb_stride, &restore_offset);
    }
    if (g_cur_ib) {
        D3D8IndexBuffer *ib = (D3D8IndexBuffer *)g_cur_ib;
        ID3D11DeviceContext_IASetIndexBuffer(g_device_state.d3d11_context, ib->d3d11_buffer,
            (ib->format == D3DFMT_INDEX32) ? DXGI_FORMAT_R32_UINT : DXGI_FORMAT_R16_UINT, 0);
    }
    return S_OK;
}
