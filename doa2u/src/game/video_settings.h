/**
 * Video settings: window type and aspect ratio, persisted to the [Video]
 * section of doa2u_settings.ini next to the executable. doa2u_settings.ini is the
 * general settings file; controls stay in doa2u_input.ini, which
 * pad_mapping_save rewrites wholesale.
 *
 * 16:9: the game reads XGetVideoFlags (sub_002BB87E) live and caches it in its D3D init
 * (sub_00282570); the host renders that into a 16:9 guest target.
 */
#ifndef DOA2U_VIDEO_SETTINGS_H
#define DOA2U_VIDEO_SETTINGS_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define VIDEO_WINDOWED    0
#define VIDEO_BORDERLESS  1

#define VIDEO_ASPECT_4_3  0
#define VIDEO_ASPECT_16_9 1

/* Full path of doa2u_settings.ini next to the executable. */
const char *doa2u_settings_ini_path(void);

int  video_get_window_mode(void);
int  video_get_aspect(void);

/* Load doa2u_settings.ini (defaults when absent: borderless, 16:9, 3x).
 * Returns non-zero if the file exists. */
int  video_settings_load(void);
/* Returns non-zero on success. */
int  video_settings_save(void);

/* Change settings at runtime. Window mode restyles the window immediately;
 * aspect switches the guest target and the game's widescreen state at the
 * next frame boundary. */
void video_set_window_mode(int mode);
void video_set_aspect(int aspect);

/* Internal resolution: 1 = 480 lines, 2 = 960, 3 = 1440 (default). Applied at the next
 * frame boundary. */
int  video_get_scale(void);
void video_set_scale(int scale);

/* Host size of the guest render target for an aspect at the current internal
 * resolution: 480 lines at 1x, 960 at 2x, 1440 at 3x. */
void video_guest_target_size(int aspect, unsigned *w, unsigned *h);

/* XC_VIDEO (ExQueryNonVolatileSetting index 8) value for the current aspect. */
unsigned video_xc_video_value(void);

/* Restyle/resize the window for a window mode (also used at startup). */
void video_apply_window_mode(HWND hwnd, int mode);

/* Update the game's cached widescreen state to the current aspect. Called by
 * the d3d8 layer when it rebuilds the guest target. */
void video_sync_guest_widescreen(void);

#ifdef __cplusplus
}
#endif

#endif /* DOA2U_VIDEO_SETTINGS_H */
