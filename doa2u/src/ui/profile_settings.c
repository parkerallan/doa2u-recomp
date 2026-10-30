/* Profile settings (see profile_settings.h). */
#include <windows.h>
#include <string.h>

#include "profile_settings.h"
#include "video_settings.h"

static int g_language = PROFILE_LANG_ENGLISH;
static int g_loaded = 0;

static int clamp_language(int lang)
{
    return lang == PROFILE_LANG_JAPANESE ? PROFILE_LANG_JAPANESE : PROFILE_LANG_ENGLISH;
}

static void profile_load(void)
{
    if (g_loaded)
        return;
    g_language = clamp_language((int)GetPrivateProfileIntA(
        "Profile", "SystemLanguage", PROFILE_LANG_ENGLISH, doa2u_settings_ini_path()));
    g_loaded = 1;
}

int profile_get_language(void)
{
    profile_load();
    return g_language;
}

void profile_set_language(int lang)
{
    profile_load();
    g_language = clamp_language(lang);
}

int profile_settings_save(void)
{
    /* SystemLanguage: 1 = English, 2 = Japanese (Xbox XC_LANGUAGE values). */
    int ok = WritePrivateProfileStringA("Profile", "SystemLanguage",
                                        profile_get_language() == PROFILE_LANG_JAPANESE ? "2" : "1",
                                        doa2u_settings_ini_path());
    return ok;
}
