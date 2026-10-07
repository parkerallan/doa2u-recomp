/**
 * Log files on/off, persisted as Logging= in the [General] section of
 * doa3_settings.ini. Off by default: stderr goes to NUL and xbox_kernel.log is
 * not written. On: stderr goes to doa3_log.txt and the kernel layer writes
 * xbox_kernel.log, both next to the working directory as before.
 *
 * A stderr the launcher redirected (a shell `2> file`) is left alone either
 * way, so a redirected run still captures everything.
 */
#ifndef DOA3_LOG_SETTINGS_H
#define DOA3_LOG_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Read the setting and route stderr. Call once, before anything is logged. */
void doa3_log_init(void);

int  doa3_log_enabled(void);
/* Takes effect immediately; turning it on starts fresh log files. */
void doa3_log_set_enabled(int on);
/* Returns non-zero on success. */
int  doa3_log_save(void);

#ifdef __cplusplus
}
#endif

#endif /* DOA3_LOG_SETTINGS_H */
