/*
 * Inert stand-ins for hooks the shared D3D8 layer (src/d3d, from the DOA3
 * port) calls into the DOA3 Esc overlay and online code. DOA2U has neither
 * yet.
 */
#include <windows.h>
#include "ui/doa3_ui.h"

int  doa3_ui_init(void) { return 0; }
void doa3_ui_shutdown(void) {}
int  doa3_ui_wndproc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    (void)hwnd; (void)msg; (void)wp; (void)lp;
    return 0;
}
void doa3_ui_render(void) {}
void doa3_ui_toggle(void) {}
int  doa3_ui_visible(void) { return 0; }

void netplay_shutdown(void) {}
