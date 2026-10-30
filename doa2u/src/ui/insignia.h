/* Insignia (the Xbox Live 1.0 revival) console setup, as its Setup Assistant does it. */
#ifndef DOA2U_INSIGNIA_H
#define DOA2U_INSIGNIA_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

enum { INSIGNIA_IDLE, INSIGNIA_BUSY, INSIGNIA_OK, INSIGNIA_FAILED };

/* Registers this console's serial, HDD key and online key (background thread). */
void insignia_register_start(void);
/* Current state, with Insignia's reply or the error in msg. */
int  insignia_register_state(char *msg, size_t msg_len);
/* Non-zero once this console identity has been registered (kept in doa2u_settings.ini). */
int  insignia_is_registered(void);
/* The console serial shown to the user. */
const char *insignia_serial(void);

/* Account wizard. The overlay queues a request; the game thread runs it through the
 * game's own XOnline code (doa2u_insignia_wizard_step) and reports back here. */
/* recover: 0 creates the account from a subscription code, 1 recovers it with the card number. */
void insignia_wizard_start(int recover, const char *gamertag, const char *code, const char *email);
int  insignia_wizard_state(char *msg, size_t msg_len);
/* Game thread: takes a queued request (non-zero when one was waiting). */
int  insignia_wizard_take(int *recover, char *gamertag, size_t gt_len, char *code, size_t code_len,
                          char *email, size_t email_len);
/* Game thread: progress or result (INSIGNIA_BUSY / _OK / _FAILED). */
void insignia_wizard_report(int state, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* DOA2U_INSIGNIA_H */
