/* [Profile] in doa2u_settings.ini. SystemLanguage is XC_LANGUAGE (NV index 7); the game
 * rebuilds its menu language from it on every profile load (sub_000227D0). */
#ifndef DOA2U_PROFILE_SETTINGS_H
#define DOA2U_PROFILE_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* XC_LANGUAGE values the game tells apart (anything but Japanese reads as English). */
#define PROFILE_LANG_ENGLISH  1
#define PROFILE_LANG_JAPANESE 2

/* Loads doa2u_settings.ini on first use (default English). */
int  profile_get_language(void);
void profile_set_language(int lang);
/* Non-zero on success. */
int  profile_settings_save(void);

#ifdef __cplusplus
}
#endif

#endif /* DOA2U_PROFILE_SETTINGS_H */
