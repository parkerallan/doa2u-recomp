/**
 * Remappable pad bindings (Xbox control <- PC source).
 *
 * Every guest pad read goes through xbox_InputGetState, which used to hold a
 * fixed XInput->Xbox translation. That translation now lives here as the
 * DEFAULT mapping, and the Esc menu can rebind any row.
 *
 * Model mirrors XenFusion's editor mapper (360engine/src/input/ControllerMapping.h):
 * a fixed list of destination controls, one source binding each, serialized as
 * `ControlKey = kind:code`. The difference is the source: XenFusion binds
 * keyboard/mouse only, here a source may also be a real controller input.
 */

#ifndef DOA3_PAD_MAPPING_H
#define DOA3_PAD_MAPPING_H

#include "xinput_xbox.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Destination controls, in display and serialization order. The first two
 * groups line up with XBOX_GAMEPAD's wButtons bits and bAnalogButtons[]
 * indices; the last group is the four stick axes split into two directions
 * each, because a key is on/off and needs one binding per side. */
typedef enum {
    PADCTL_DPAD_UP = 0, PADCTL_DPAD_DOWN, PADCTL_DPAD_LEFT, PADCTL_DPAD_RIGHT,
    PADCTL_START, PADCTL_BACK, PADCTL_LTHUMB, PADCTL_RTHUMB,

    PADCTL_A, PADCTL_B, PADCTL_X, PADCTL_Y,
    PADCTL_BLACK, PADCTL_WHITE, PADCTL_LTRIGGER, PADCTL_RTRIGGER,

    PADCTL_LX_NEG, PADCTL_LX_POS, PADCTL_LY_NEG, PADCTL_LY_POS,
    PADCTL_RX_NEG, PADCTL_RX_POS, PADCTL_RY_NEG, PADCTL_RY_POS,

    PADCTL_COUNT
} PadControl;

/* Where a control's value comes from. */
typedef enum {
    PADSRC_NONE = 0,
    PADSRC_PAD_BUTTON,   /* code = an XINPUT_GAMEPAD_* bit */
    PADSRC_PAD_TRIGGER,  /* code = 0 left, 1 right (analog 0..255) */
    PADSRC_PAD_AXIS,     /* code = PADAXIS_* below (one stick direction) */
    PADSRC_KEY           /* code = a Windows virtual-key code */
} PadSourceKind;

/* PADSRC_PAD_AXIS codes: one half of one stick axis. */
enum {
    PADAXIS_LX_NEG = 0, PADAXIS_LX_POS, PADAXIS_LY_NEG, PADAXIS_LY_POS,
    PADAXIS_RX_NEG,     PADAXIS_RX_POS, PADAXIS_RY_NEG, PADAXIS_RY_POS
};

typedef struct { int kind; int code; } PadBinding;
typedef struct { PadBinding b[PADCTL_COUNT]; } PadMapping;

/* Stable key used for display and in the .ini ("A", "LX-", "DPadUp"). */
const char *pad_ctl_key(int ctl);
/* Group heading a row belongs under ("D-Pad", "Buttons", "Sticks"). */
const char *pad_ctl_group(int ctl);
/* Non-zero when the control drives a stick axis rather than a button. */
int         pad_ctl_is_axis(int ctl);

/* The live mapping (one process-wide table; read on the guest thread, written
 * by the menu on that same thread). */
PadMapping *pad_mapping_get(void);

/* Restore the built-in defaults: exactly the translation this layer performed
 * before it was made remappable. */
void pad_mapping_reset_defaults(void);

/* `doa3_input.ini` next to the executable. Load is best-effort: a missing or
 * malformed file leaves the defaults in place. */
int  pad_mapping_load(const char *path);
int  pad_mapping_save(const char *path);
/* Default path (static buffer): <exe dir>\doa3_input.ini */
const char *pad_mapping_default_path(void);

/* Human-readable source label ("A", "Left Trigger", "LS Left", "Key W", "-"). */
void pad_binding_label(PadBinding b, char *out, size_t n);

/* While the menu is open, keyboard sources are suppressed so typing in the UI
 * does not also drive the game. Controller sources stay live so a rebind can
 * be tested immediately. */
void pad_mapping_set_menu_open(int open);
int  pad_mapping_menu_open(void);

/* Non-zero if any control is bound to a key -- the keyboard can then stand in
 * for a controller, and port 0 reports present even with no pad attached. */
int  pad_mapping_has_key_binding(void);


/* Build an Xbox gamepad state from a polled XInput state (may be NULL when no
 * controller is attached) plus the current keyboard, per the mapping. */
void pad_mapping_apply(const void *xinput_state, XBOX_GAMEPAD *out);
/* Same, but keyboard sources only contribute when use_keyboard is non-zero:
 * the keyboard belongs to port 0, it must not drive players 2-4 as well. */
void pad_mapping_apply_port(const void *xinput_state, XBOX_GAMEPAD *out, int use_keyboard);

#ifdef __cplusplus
}
#endif

#endif /* DOA3_PAD_MAPPING_H */
