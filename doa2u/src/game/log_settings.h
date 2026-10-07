/**
 * Log files on/off, persisted as Logging= in the [General] section of
 * doa2u_settings.ini. Off by default: stderr goes to NUL and xbox_kernel.log is
 * not written. On: stderr goes to doa2u_log.txt and the kernel layer writes
 * xbox_kernel.log, both next to the working directory as before.
 *
 * A stderr the launcher redirected (a shell `2> file`) is left alone either
 * way, so a redirected run still captures everything.
 */
#ifndef DOA2U_LOG_SETTINGS_H
#define DOA2U_LOG_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Read the setting and route stderr. Call once, before anything is logged. */
void doa2u_log_init(void);

int  doa2u_log_enabled(void);
/* Takes effect immediately; turning it on starts fresh log files. */
void doa2u_log_set_enabled(int on);
/* Returns non-zero on success. */
int  doa2u_log_save(void);

#ifdef __cplusplus
}
#endif

#endif /* DOA2U_LOG_SETTINGS_H */
