/**
 * Xbox Input -> XInput Compatibility Layer
 *
 * Translates Xbox controller API calls to Windows XInput.
 *
 * Host XInput user slots 0..3 are packed onto guest ports 0..n-1 in order, so
 * one controller is always player 1 whatever index it enumerates at (a
 * wireless receiver or a virtual pad can leave slot 0 empty). Port 0 can also
 * be driven from the keyboard through the mapping (pad_mapping.c): it reports
 * present with no controller attached once any key is bound, and the keyboard
 * overlays the controller on port 0 when both exist.
 */

#include "xinput_xbox.h"
#include "pad_mapping.h"
#include <xinput.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "xinput.lib")

/* Host slots. connected is refreshed by every XInputGetState; an EMPTY slot
 * is re-probed only once a second, because XInputGetState on a disconnected
 * index is slow enough that polling four empty slots per frame stalls. */
static struct { BOOL connected; DWORD last_probe; } s_slot[XBOX_MAX_CONTROLLERS];
/* Guest port -> host slot, -1 = no controller. */
static int   s_port_slot[XBOX_MAX_CONTROLLERS] = { -1, -1, -1, -1 };
static DWORD s_kb_packet;

static void probe_slots(void)
{
    DWORD now = GetTickCount();
    DWORD i;
    for (i = 0; i < XBOX_MAX_CONTROLLERS; i++) {
        XINPUT_STATE st;
        if (!s_slot[i].connected && (now - s_slot[i].last_probe) < 1000)
            continue;
        s_slot[i].last_probe = now;
        s_slot[i].connected = (XInputGetState(i, &st) == ERROR_SUCCESS);
    }
}

static void rebuild_map(void)
{
    int p = 0, i;
    for (i = 0; i < XBOX_MAX_CONTROLLERS; i++) s_port_slot[i] = -1;
    for (i = 0; i < XBOX_MAX_CONTROLLERS; i++)
        if (s_slot[i].connected) s_port_slot[p++] = i;
}

static int port_has_keyboard(DWORD dwPort)
{
    return dwPort == 0 && pad_mapping_has_key_binding();
}

void xbox_InputInit(void)
{
    probe_slots();
    rebuild_map();
}

DWORD xbox_InputHostMask(void)
{
    DWORD mask = 0, i;
    probe_slots();
    rebuild_map();
    for (i = 0; i < XBOX_MAX_CONTROLLERS; i++)
        if (s_port_slot[i] >= 0 || port_has_keyboard(i)) mask |= (1u << i);
    return mask;
}

DWORD xbox_InputGetState(DWORD dwPort, XBOX_INPUT_STATE *pState)
{
    XINPUT_STATE xi_state;
    int slot;

    if (dwPort >= XBOX_MAX_CONTROLLERS || !pState) {
        return ERROR_DEVICE_NOT_CONNECTED;
    }

    slot = s_port_slot[dwPort];
    if (slot >= 0 && XInputGetState((DWORD)slot, &xi_state) == ERROR_SUCCESS) {
        memset(pState, 0, sizeof(XBOX_INPUT_STATE));
        pState->dwPacketNumber = xi_state.dwPacketNumber;
        pad_mapping_apply_port(&xi_state, &pState->Gamepad, dwPort == 0);
        return ERROR_SUCCESS;
    }
    if (slot >= 0) {
        /* Unplugged since the last poll: drop it now, XGetDeviceChanges
         * reports the removal on its next call. */
        s_slot[slot].connected = FALSE;
        s_slot[slot].last_probe = GetTickCount();
        rebuild_map();
    }

    /* No controller on this port. Port 0 can still be the keyboard, but ONLY
     * once the user has bound a key: with nothing bound we report the slot
     * empty rather than a pad that is not there. */
    if (!port_has_keyboard(dwPort))
        return ERROR_DEVICE_NOT_CONNECTED;

    memset(pState, 0, sizeof(XBOX_INPUT_STATE));
    pState->dwPacketNumber = ++s_kb_packet;
    pad_mapping_apply_port(NULL, &pState->Gamepad, 1);
    return ERROR_SUCCESS;
}

DWORD xbox_InputSetState(DWORD dwPort, const XBOX_VIBRATION *pVibration)
{
    XINPUT_VIBRATION xi_vib;
    int slot;

    if (dwPort >= XBOX_MAX_CONTROLLERS || !pVibration) {
        return ERROR_DEVICE_NOT_CONNECTED;
    }
    slot = s_port_slot[dwPort];
    if (slot < 0)
        return port_has_keyboard(dwPort) ? ERROR_SUCCESS : ERROR_DEVICE_NOT_CONNECTED;

    xi_vib.wLeftMotorSpeed = pVibration->wLeftMotorSpeed;
    xi_vib.wRightMotorSpeed = pVibration->wRightMotorSpeed;

    return XInputSetState((DWORD)slot, &xi_vib);
}

BOOL xbox_InputIsConnected(DWORD dwPort)
{
    if (dwPort >= XBOX_MAX_CONTROLLERS) return FALSE;
    return s_port_slot[dwPort] >= 0 || port_has_keyboard(dwPort);
}

DWORD xbox_InputGetCapabilities(DWORD dwPort, DWORD dwFlags, XBOX_INPUT_CAPABILITIES *pCaps)
{
    XINPUT_CAPABILITIES xi_caps;
    DWORD result;
    int slot;

    if (dwPort >= XBOX_MAX_CONTROLLERS || !pCaps) {
        return ERROR_DEVICE_NOT_CONNECTED;
    }
    slot = s_port_slot[dwPort];
    memset(pCaps, 0, sizeof(XBOX_INPUT_CAPABILITIES));
    if (slot < 0) {
        if (!port_has_keyboard(dwPort)) return ERROR_DEVICE_NOT_CONNECTED;
        pCaps->SubType = XINPUT_DEVSUBTYPE_GAMEPAD;
        return ERROR_SUCCESS;
    }

    result = XInputGetCapabilities((DWORD)slot, dwFlags, &xi_caps);
    if (result != ERROR_SUCCESS) return result;

    pCaps->Type = xi_caps.Type;
    pCaps->SubType = xi_caps.SubType;
    pCaps->Flags = xi_caps.Flags;

    return ERROR_SUCCESS;
}
