/**
 * In-game overlay (Dear ImGui), opened with Escape.
 *
 * Modelled on XenFusion's editor panels (360engine/src/panels/MapperPanel.cpp):
 * a table of Xbox controls, click a row to listen, press the input you want.
 * Currently one section, Controls.
 *
 * The game keeps running underneath -- nothing here blocks the cooperative
 * fiber scheduler, because stalling it is what has previously killed the
 * intro movie's decode.
 *
 * C API so the C sources (main.c, d3d8_device.c) can call into the C++ TU.
 */

#ifndef DOA3_UI_H
#define DOA3_UI_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Bring the overlay up on the existing window and D3D11 device. Safe to call
 * more than once; later calls are ignored. Returns non-zero on success. */
int  doa3_ui_init(void);

void doa3_ui_shutdown(void);

/* Feed a window message to the overlay. Returns non-zero when the overlay
 * consumed it and the game should not see it. */
int  doa3_ui_wndproc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

/* Draw the overlay. Called at present time, after the game's own frame. */
void doa3_ui_render(void);

void doa3_ui_toggle(void);
int  doa3_ui_visible(void);

#ifdef __cplusplus
}
#endif

#endif /* DOA3_UI_H */
