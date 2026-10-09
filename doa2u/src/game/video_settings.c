/**
 * Video settings (see video_settings.h).
 */
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include "video_settings.h"

extern HWND d3d8_GetHWND(void);
extern ptrdiff_t g_xbox_mem_offset;

static int g_window_mode = VIDEO_BORDERLESS;
static int g_aspect      = VIDEO_ASPECT_16_9;
static int g_scale       = 3;

int video_get_window_mode(void) { return g_window_mode; }
int video_get_aspect(void)      { return g_aspect; }
int video_get_scale(void)       { return g_scale; }

const char *doa2u_settings_ini_path(void)
{
    static char path[MAX_PATH];
    char *slash;
    if (path[0]) return path;
    if (!GetModuleFileNameA(NULL, path, MAX_PATH)) {
        strcpy_s(path, sizeof(path), "doa2u_settings.ini");
        return path;
    }
    slash = strrchr(path, '\\');
    if (slash) slash[1] = 0; else path[0] = 0;
    strcat_s(path, sizeof(path), "doa2u_settings.ini");
    return path;
}

int video_settings_load(void)
{
    const char *p = doa2u_settings_ini_path();
    int wm = (int)GetPrivateProfileIntA("Video", "WindowMode", VIDEO_BORDERLESS, p);
    int ar = (int)GetPrivateProfileIntA("Video", "Widescreen", VIDEO_ASPECT_16_9, p);
    int sc = (int)GetPrivateProfileIntA("Video", "InternalResolution", 3, p);
    g_window_mode = (wm == VIDEO_WINDOWED) ? VIDEO_WINDOWED : VIDEO_BORDERLESS;
    g_aspect      = (ar == VIDEO_ASPECT_4_3) ? VIDEO_ASPECT_4_3 : VIDEO_ASPECT_16_9;
    g_scale       = (sc >= 1 && sc <= 3) ? sc : 3;
    return GetFileAttributesA(p) != INVALID_FILE_ATTRIBUTES;
}

int video_settings_save(void)
{
    const char *p = doa2u_settings_ini_path();
    /* WindowMode: 0 = windowed, 1 = borderless fullscreen.
     * Widescreen: 0 = 4:3, 1 = 16:9.
     * InternalResolution: 1 = 480 lines, 2 = 960, 3 = 1440. */
    return WritePrivateProfileStringA("Video", "WindowMode",
                                      g_window_mode ? "1" : "0", p) &&
           WritePrivateProfileStringA("Video", "Widescreen",
                                      g_aspect ? "1" : "0", p) &&
           WritePrivateProfileStringA("Video", "InternalResolution",
                                      g_scale == 3 ? "3" : g_scale == 2 ? "2" : "1", p);
}

/* 480 lines at 1x. The translator maps every guest vertex onto whatever size
 * this target is, so a larger target rasterises the scene at that resolution
 * rather than scaling up a 480-line picture. */
static void video_base_size(int aspect, unsigned *w, unsigned *h)
{
    *h = 480;
    *w = (aspect == VIDEO_ASPECT_16_9) ? 854 : 640;
}

void video_guest_target_size(int aspect, unsigned *w, unsigned *h)
{
    video_base_size(aspect, w, h);
    *w *= (unsigned)g_scale;
    *h *= (unsigned)g_scale;
}

void video_set_scale(int scale)
{
    /* Applied at the next frame boundary, like the aspect. */
    g_scale = (scale >= 1 && scale <= 3) ? scale : 3;
}

/* XC_VIDEO dword: XGetVideoFlags returns (value >> 16) & 0x5F, and
 * XC_VIDEO_FLAGS_WIDESCREEN is bit 0 of that. */
unsigned video_xc_video_value(void)
{
    return (g_aspect == VIDEO_ASPECT_16_9) ? 0x00010000u : 0u;
}

void video_set_aspect(int aspect)
{
    /* The d3d8 layer notices the change at the next frame boundary and
     * rebuilds the guest target (d3d8_device.c, present path). */
    g_aspect = (aspect == VIDEO_ASPECT_4_3) ? VIDEO_ASPECT_4_3 : VIDEO_ASPECT_16_9;
}

/* Mirror the aspect into the flags sub_00282570 caches from XGetVideoFlags: widescreen
 * 0xE65A98 bit 0, present flags 0xE65918 (0x10), raw 0xE6593C. No-op before that init. */
void video_sync_guest_widescreen(void)
{
    volatile uint8_t *m = (volatile uint8_t *)(uintptr_t)g_xbox_mem_offset;
    volatile uint32_t *pp_w  = (volatile uint32_t *)(m + 0xE658F0);
    volatile uint32_t *pp_fl = (volatile uint32_t *)(m + 0xE65918);
    volatile uint32_t *vflag = (volatile uint32_t *)(m + 0xE6593C);
    volatile uint32_t *ws    = (volatile uint32_t *)(m + 0xE65A98);
    int on = (g_aspect == VIDEO_ASPECT_16_9);
    if (!g_xbox_mem_offset || *pp_w != 0x2D0u) return;
    if (on) { *ws |= 1u;  *pp_fl |= 0x10u;  *vflag |= 1u; }
    else    { *ws &= ~1u; *pp_fl &= ~0x10u; *vflag &= ~1u; }
}

void video_apply_window_mode(HWND hwnd, int mode)
{
    MONITORINFO mi;
    HMONITOR mon;
    if (!hwnd) return;
    mon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY);
    memset(&mi, 0, sizeof(mi));
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoA(mon, &mi)) return;

    if (mode == VIDEO_BORDERLESS) {
        RECT r = mi.rcMonitor;
        SetWindowLongPtrA(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
        SetWindowPos(hwnd, HWND_TOP, r.left, r.top, r.right - r.left, r.bottom - r.top,
                     SWP_FRAMECHANGED | SWP_SHOWWINDOW);
    } else {
        unsigned cw, ch;
        RECT r, wa = mi.rcWork;
        video_base_size(g_aspect, &cw, &ch);
        r.left = 0; r.top = 0; r.right = (LONG)cw; r.bottom = (LONG)ch;
        AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, FALSE);
        SetWindowLongPtrA(hwnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
        SetWindowPos(hwnd, HWND_NOTOPMOST,
                     wa.left + ((wa.right - wa.left) - (r.right - r.left)) / 2,
                     wa.top + ((wa.bottom - wa.top) - (r.bottom - r.top)) / 2,
                     r.right - r.left, r.bottom - r.top,
                     SWP_FRAMECHANGED | SWP_SHOWWINDOW);
    }
}

void video_set_window_mode(int mode)
{
    g_window_mode = (mode == VIDEO_WINDOWED) ? VIDEO_WINDOWED : VIDEO_BORDERLESS;
    video_apply_window_mode(d3d8_GetHWND(), g_window_mode);
}
