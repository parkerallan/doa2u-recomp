#include "pad_mapping.h"

#include <windows.h>
#include <xinput.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static PadMapping g_map;
static int        g_menu_open = 0;
static int        g_use_keys  = 1;   /* set per call by pad_mapping_apply_port */
static int        g_initialised = 0;

/* ── Row metadata ──────────────────────────────────────────────────────── */

static const struct { const char *key, *group; int axis; } k_ctl[PADCTL_COUNT] = {
    { "DPadUp",    "D-Pad",   0 }, { "DPadDown",  "D-Pad",   0 },
    { "DPadLeft",  "D-Pad",   0 }, { "DPadRight", "D-Pad",   0 },
    { "Start",     "System",  0 }, { "Back",      "System",  0 },
    { "LThumb",    "System",  0 }, { "RThumb",    "System",  0 },

    { "A",         "Buttons", 0 }, { "B",         "Buttons", 0 },
    { "X",         "Buttons", 0 }, { "Y",         "Buttons", 0 },
    { "Black",     "Buttons", 0 }, { "White",     "Buttons", 0 },
    { "LT",        "Buttons", 0 }, { "RT",        "Buttons", 0 },

    { "LX-",       "Sticks",  1 }, { "LX+",       "Sticks",  1 },
    { "LY-",       "Sticks",  1 }, { "LY+",       "Sticks",  1 },
    { "RX-",       "Sticks",  1 }, { "RX+",       "Sticks",  1 },
    { "RY-",       "Sticks",  1 }, { "RY+",       "Sticks",  1 },
};

const char *pad_ctl_key(int c)   { return (c >= 0 && c < PADCTL_COUNT) ? k_ctl[c].key   : "?"; }
const char *pad_ctl_group(int c) { return (c >= 0 && c < PADCTL_COUNT) ? k_ctl[c].group : "?"; }
int         pad_ctl_is_axis(int c){ return (c >= 0 && c < PADCTL_COUNT) ? k_ctl[c].axis  : 0; }

/* Xbox wButtons bit for the eight digital controls (same values as XInput's). */
static WORD ctl_xbox_bit(int c)
{
    switch (c) {
    case PADCTL_DPAD_UP:    return XBOX_GAMEPAD_DPAD_UP;
    case PADCTL_DPAD_DOWN:  return XBOX_GAMEPAD_DPAD_DOWN;
    case PADCTL_DPAD_LEFT:  return XBOX_GAMEPAD_DPAD_LEFT;
    case PADCTL_DPAD_RIGHT: return XBOX_GAMEPAD_DPAD_RIGHT;
    case PADCTL_START:      return XBOX_GAMEPAD_START;
    case PADCTL_BACK:       return XBOX_GAMEPAD_BACK;
    case PADCTL_LTHUMB:     return XBOX_GAMEPAD_LEFT_THUMB;
    case PADCTL_RTHUMB:     return XBOX_GAMEPAD_RIGHT_THUMB;
    default:                return 0;
    }
}

/* ── Defaults: the translation this layer did before it was remappable ──── */

void pad_mapping_reset_defaults(void)
{
    static const struct { int ctl, kind, code; } d[] = {
        { PADCTL_DPAD_UP,    PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_DPAD_UP },
        { PADCTL_DPAD_DOWN,  PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_DPAD_DOWN },
        { PADCTL_DPAD_LEFT,  PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_DPAD_LEFT },
        { PADCTL_DPAD_RIGHT, PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_DPAD_RIGHT },
        { PADCTL_START,      PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_START },
        { PADCTL_BACK,       PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_BACK },
        { PADCTL_LTHUMB,     PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_LEFT_THUMB },
        { PADCTL_RTHUMB,     PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_RIGHT_THUMB },

        { PADCTL_A,          PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_A },
        { PADCTL_B,          PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_B },
        { PADCTL_X,          PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_X },
        { PADCTL_Y,          PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_Y },
        /* Xbox Black/White sit where XInput has the shoulder buttons. */
        { PADCTL_BLACK,      PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_LEFT_SHOULDER },
        { PADCTL_WHITE,      PADSRC_PAD_BUTTON,  XINPUT_GAMEPAD_RIGHT_SHOULDER },
        { PADCTL_LTRIGGER,   PADSRC_PAD_TRIGGER, 0 },
        { PADCTL_RTRIGGER,   PADSRC_PAD_TRIGGER, 1 },

        { PADCTL_LX_NEG,     PADSRC_PAD_AXIS,    PADAXIS_LX_NEG },
        { PADCTL_LX_POS,     PADSRC_PAD_AXIS,    PADAXIS_LX_POS },
        { PADCTL_LY_NEG,     PADSRC_PAD_AXIS,    PADAXIS_LY_NEG },
        { PADCTL_LY_POS,     PADSRC_PAD_AXIS,    PADAXIS_LY_POS },
        { PADCTL_RX_NEG,     PADSRC_PAD_AXIS,    PADAXIS_RX_NEG },
        { PADCTL_RX_POS,     PADSRC_PAD_AXIS,    PADAXIS_RX_POS },
        { PADCTL_RY_NEG,     PADSRC_PAD_AXIS,    PADAXIS_RY_NEG },
        { PADCTL_RY_POS,     PADSRC_PAD_AXIS,    PADAXIS_RY_POS },
    };
    size_t i;
    memset(&g_map, 0, sizeof(g_map));
    for (i = 0; i < sizeof(d) / sizeof(d[0]); i++) {
        g_map.b[d[i].ctl].kind = d[i].kind;
        g_map.b[d[i].ctl].code = d[i].code;
    }
    g_initialised = 1;
}

PadMapping *pad_mapping_get(void)
{
    if (!g_initialised) pad_mapping_reset_defaults();
    return &g_map;
}

void pad_mapping_set_menu_open(int open) { g_menu_open = open ? 1 : 0; }
int  pad_mapping_menu_open(void)         { return g_menu_open; }

int pad_mapping_has_key_binding(void)
{
    int i;
    PadMapping *m = pad_mapping_get();
    for (i = 0; i < PADCTL_COUNT; i++)
        if (m->b[i].kind == PADSRC_KEY) return 1;
    return 0;
}

/* ── Labels ────────────────────────────────────────────────────────────── */

static const char *pad_button_name(int bit)
{
    switch (bit) {
    case XINPUT_GAMEPAD_DPAD_UP:        return "Pad Up";
    case XINPUT_GAMEPAD_DPAD_DOWN:      return "Pad Down";
    case XINPUT_GAMEPAD_DPAD_LEFT:      return "Pad Left";
    case XINPUT_GAMEPAD_DPAD_RIGHT:     return "Pad Right";
    case XINPUT_GAMEPAD_START:          return "Start";
    case XINPUT_GAMEPAD_BACK:           return "Back";
    case XINPUT_GAMEPAD_LEFT_THUMB:     return "L3";
    case XINPUT_GAMEPAD_RIGHT_THUMB:    return "R3";
    case XINPUT_GAMEPAD_LEFT_SHOULDER:  return "LB";
    case XINPUT_GAMEPAD_RIGHT_SHOULDER: return "RB";
    case XINPUT_GAMEPAD_A:              return "A";
    case XINPUT_GAMEPAD_B:              return "B";
    case XINPUT_GAMEPAD_X:              return "X";
    case XINPUT_GAMEPAD_Y:              return "Y";
    default:                            return "Button?";
    }
}

static const char *pad_axis_name(int code)
{
    switch (code) {
    case PADAXIS_LX_NEG: return "LS Left";
    case PADAXIS_LX_POS: return "LS Right";
    case PADAXIS_LY_NEG: return "LS Down";
    case PADAXIS_LY_POS: return "LS Up";
    case PADAXIS_RX_NEG: return "RS Left";
    case PADAXIS_RX_POS: return "RS Right";
    case PADAXIS_RY_NEG: return "RS Down";
    case PADAXIS_RY_POS: return "RS Up";
    default:             return "Axis?";
    }
}

void pad_binding_label(PadBinding b, char *out, size_t n)
{
    if (!out || n == 0) return;
    switch (b.kind) {
    case PADSRC_PAD_BUTTON:  _snprintf_s(out, n, _TRUNCATE, "%s", pad_button_name(b.code)); return;
    case PADSRC_PAD_TRIGGER: _snprintf_s(out, n, _TRUNCATE, "%s", b.code ? "Right Trigger" : "Left Trigger"); return;
    case PADSRC_PAD_AXIS:    _snprintf_s(out, n, _TRUNCATE, "%s", pad_axis_name(b.code)); return;
    case PADSRC_KEY: {
        /* GetKeyNameText wants the scan code in bits 16..23. */
        UINT sc = MapVirtualKeyA((UINT)b.code, MAPVK_VK_TO_VSC);
        char name[64] = { 0 };
        if (sc && GetKeyNameTextA((LONG)(sc << 16), name, (int)sizeof(name)) > 0)
            _snprintf_s(out, n, _TRUNCATE, "Key %s", name);
        else
            _snprintf_s(out, n, _TRUNCATE, "Key 0x%02X", b.code);
        return;
    }
    default: _snprintf_s(out, n, _TRUNCATE, "%s", "-"); return;
    }
}

/* ── Persistence ───────────────────────────────────────────────────────── */

const char *pad_mapping_default_path(void)
{
    static char path[MAX_PATH];
    char *slash;
    if (path[0]) return path;
    if (!GetModuleFileNameA(NULL, path, MAX_PATH)) {
        strcpy_s(path, sizeof(path), "doa3_input.ini");
        return path;
    }
    slash = strrchr(path, '\\');
    if (slash) slash[1] = 0; else path[0] = 0;
    strcat_s(path, sizeof(path), "doa3_input.ini");
    return path;
}

int pad_mapping_save(const char *path)
{
    FILE *f = NULL;
    int i;
    PadMapping *m = pad_mapping_get();
    if (!path) path = pad_mapping_default_path();
    if (fopen_s(&f, path, "wb") != 0 || !f) return 0;
    fprintf(f, "# DOA3 pad mapping. Control = kind:code\n");
    fprintf(f, "# kind 0=unbound 1=pad button 2=pad trigger 3=pad axis 4=key(VK)\n");
    for (i = 0; i < PADCTL_COUNT; i++)
        fprintf(f, "%s=%d:%d\n", pad_ctl_key(i), m->b[i].kind, m->b[i].code);
    fclose(f);
    return 1;
}

int pad_mapping_load(const char *path)
{
    FILE *f = NULL;
    char line[256];
    PadMapping *m;
    if (!path) path = pad_mapping_default_path();
    if (fopen_s(&f, path, "rb") != 0 || !f) return 0;

    /* Start from defaults so a partial file still leaves every other row
     * working rather than silently unbound. */
    pad_mapping_reset_defaults();
    m = pad_mapping_get();

    while (fgets(line, sizeof(line), f)) {
        char *eq, *colon;
        int i, kind, code;
        if (line[0] == '#' || line[0] == ';') continue;
        eq = strchr(line, '=');
        if (!eq) continue;
        *eq = 0;
        colon = strchr(eq + 1, ':');
        if (!colon) continue;
        *colon = 0;
        kind = atoi(eq + 1);
        code = atoi(colon + 1);
        if (kind < PADSRC_NONE || kind > PADSRC_KEY) continue;
        for (i = 0; i < PADCTL_COUNT; i++) {
            if (strcmp(line, pad_ctl_key(i)) == 0) {
                m->b[i].kind = kind;
                m->b[i].code = code;
                break;
            }
        }
    }
    fclose(f);
    return 1;
}

/* ── Apply ─────────────────────────────────────────────────────────────── */

/* Is this source currently active, and how strongly (0..255)? */
static int source_value(PadBinding b, const XINPUT_STATE *xi)
{
    switch (b.kind) {
    case PADSRC_PAD_BUTTON:
        return (xi && (xi->Gamepad.wButtons & (WORD)b.code)) ? 255 : 0;
    case PADSRC_PAD_TRIGGER:
        if (!xi) return 0;
        return b.code ? xi->Gamepad.bRightTrigger : xi->Gamepad.bLeftTrigger;
    case PADSRC_PAD_AXIS: {
        int v;
        if (!xi) return 0;
        switch (b.code) {
        case PADAXIS_LX_NEG: v = -(int)xi->Gamepad.sThumbLX; break;
        case PADAXIS_LX_POS: v =  (int)xi->Gamepad.sThumbLX; break;
        case PADAXIS_LY_NEG: v = -(int)xi->Gamepad.sThumbLY; break;
        case PADAXIS_LY_POS: v =  (int)xi->Gamepad.sThumbLY; break;
        case PADAXIS_RX_NEG: v = -(int)xi->Gamepad.sThumbRX; break;
        case PADAXIS_RX_POS: v =  (int)xi->Gamepad.sThumbRX; break;
        case PADAXIS_RY_NEG: v = -(int)xi->Gamepad.sThumbRY; break;
        case PADAXIS_RY_POS: v =  (int)xi->Gamepad.sThumbRY; break;
        default: return 0;
        }
        if (v <= 0) return 0;
        return (v * 255) / 32767;
    }
    case PADSRC_KEY:
        /* Suppressed while the menu has the keyboard, so typing in the UI does
         * not also drive the game. Controller sources stay live. */
        if (g_menu_open || !g_use_keys) return 0;
        return (GetAsyncKeyState(b.code) & 0x8000) ? 255 : 0;
    default:
        return 0;
    }
}

/* Axis contribution in stick units, preserving a stick source's full
 * resolution instead of quantising it through the 0..255 button scale. */
static int axis_magnitude(PadBinding b, const XINPUT_STATE *xi)
{
    if (b.kind == PADSRC_PAD_AXIS && xi) {
        int v;
        switch (b.code) {
        case PADAXIS_LX_NEG: v = -(int)xi->Gamepad.sThumbLX; break;
        case PADAXIS_LX_POS: v =  (int)xi->Gamepad.sThumbLX; break;
        case PADAXIS_LY_NEG: v = -(int)xi->Gamepad.sThumbLY; break;
        case PADAXIS_LY_POS: v =  (int)xi->Gamepad.sThumbLY; break;
        case PADAXIS_RX_NEG: v = -(int)xi->Gamepad.sThumbRX; break;
        case PADAXIS_RX_POS: v =  (int)xi->Gamepad.sThumbRX; break;
        case PADAXIS_RY_NEG: v = -(int)xi->Gamepad.sThumbRY; break;
        case PADAXIS_RY_POS: v =  (int)xi->Gamepad.sThumbRY; break;
        default: return 0;
        }
        return (v > 0) ? v : 0;
    }
    /* Any other source is on/off: full deflection when held. */
    return source_value(b, xi) ? 32767 : 0;
}

static SHORT clamp_axis(int v)
{
    if (v >  32767) return  32767;
    if (v < -32768) return (SHORT)-32768;
    return (SHORT)v;
}

void pad_mapping_apply(const void *xinput_state, XBOX_GAMEPAD *out)
{
    pad_mapping_apply_port(xinput_state, out, 1);
}

void pad_mapping_apply_port(const void *xinput_state, XBOX_GAMEPAD *out, int use_keyboard)
{
    const XINPUT_STATE *xi = (const XINPUT_STATE *)xinput_state;
    PadMapping *m = pad_mapping_get();
    int i;

    if (!out) return;
    memset(out, 0, sizeof(*out));
    g_use_keys = use_keyboard ? 1 : 0;

    /* Digital controls -> wButtons bits. */
    for (i = PADCTL_DPAD_UP; i <= PADCTL_RTHUMB; i++)
        if (source_value(m->b[i], xi) >= XBOX_ANALOG_BUTTON_THRESHOLD)
            out->wButtons |= ctl_xbox_bit(i);

    /* Analog buttons -> bAnalogButtons[0..7], same order as the enum. */
    for (i = PADCTL_A; i <= PADCTL_RTRIGGER; i++) {
        int v = source_value(m->b[i], xi);
        if (v > 255) v = 255;
        out->bAnalogButtons[i - PADCTL_A] = (BYTE)v;
    }

    /* Stick axes: each side contributes independently, then sum and clamp, so
     * two opposing keys cancel the way a real stick would. */
    out->sThumbLX = clamp_axis(axis_magnitude(m->b[PADCTL_LX_POS], xi) -
                               axis_magnitude(m->b[PADCTL_LX_NEG], xi));
    out->sThumbLY = clamp_axis(axis_magnitude(m->b[PADCTL_LY_POS], xi) -
                               axis_magnitude(m->b[PADCTL_LY_NEG], xi));
    out->sThumbRX = clamp_axis(axis_magnitude(m->b[PADCTL_RX_POS], xi) -
                               axis_magnitude(m->b[PADCTL_RX_NEG], xi));
    out->sThumbRY = clamp_axis(axis_magnitude(m->b[PADCTL_RY_POS], xi) -
                               axis_magnitude(m->b[PADCTL_RY_NEG], xi));
}
