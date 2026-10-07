/*
 * kernel_path.c - Xbox→Windows Path Translation
 *
 * Translates Xbox device-style paths to Windows filesystem paths:
 *   \Device\CdRom0\  → <game_dir>\assets\
 *   D:\               → <game_dir>\assets\
 *   T:\               → <save_dir>\TitleData\
 *   U:\               → <save_dir>\UserData\
 *   Z:\               → <save_dir>\Cache\
 */

#include "kernel.h"
#include <stdio.h>
#include <string.h>
#include <shlobj.h>

/* Base directories - set at init */
static WCHAR s_game_dir[MAX_PATH];    /* Path to game disc content */
static WCHAR s_save_dir[MAX_PATH];    /* Base for save/cache directories */
static BOOL  s_initialized = FALSE;
static volatile LONG s_title_redirect = 0;   /* see xbox_path_set_title_redirect */

static void copy_dir_files(const WCHAR *from, const WCHAR *to)
{
    WCHAR pat[MAX_PATH], src[MAX_PATH], dst[MAX_PATH];
    WIN32_FIND_DATAW fd;
    HANDLE h;
    CreateDirectoryW(to, NULL);
    swprintf_s(pat, MAX_PATH, L"%s\\*", from);
    h = FindFirstFileW(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (!wcscmp(fd.cFileName, L".") || !wcscmp(fd.cFileName, L"..")) continue;
        swprintf_s(src, MAX_PATH, L"%s\\%s", from, fd.cFileName);
        swprintf_s(dst, MAX_PATH, L"%s\\%s", to, fd.cFileName);
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) copy_dir_files(src, dst);
        else CopyFileW(src, dst, FALSE);
    } while (FindNextFileW(h, &fd));
    FindClose(h);
}

void xbox_path_set_title_redirect(int on)
{
    if (!s_initialized)
        xbox_path_init(NULL, NULL);
    if (on) {
        WCHAR real_dir[MAX_PATH], copy_dir[MAX_PATH];
        swprintf_s(real_dir, MAX_PATH, L"%s\\TitleData", s_save_dir);
        swprintf_s(copy_dir, MAX_PATH, L"%s\\TitleData_netplay", s_save_dir);
        CreateDirectoryW(s_save_dir, NULL);
        copy_dir_files(real_dir, copy_dir);
    }
    InterlockedExchange(&s_title_redirect, on ? 1 : 0);
    xbox_log(XBOX_LOG_INFO, XBOX_LOG_PATH, "TitleData redirect %s", on ? "ON" : "OFF");
}

void xbox_path_init(const char* game_dir, const char* save_dir)
{
    WCHAR save_base[MAX_PATH];

    if (game_dir) {
        MultiByteToWideChar(CP_UTF8, 0, game_dir, -1, s_game_dir, MAX_PATH);
    } else {
        /* Default: current directory (the exe's folder) + "assets" */
        GetCurrentDirectoryW(MAX_PATH, s_game_dir);
        wcscat_s(s_game_dir, MAX_PATH, L"\\assets");
    }

    if (save_dir) {
        MultiByteToWideChar(CP_UTF8, 0, save_dir, -1, s_save_dir, MAX_PATH);
    } else {
        /* Default: AppData\Local\DeadOrAlive2Ultimate */
        if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, save_base))) {
            swprintf_s(s_save_dir, MAX_PATH, L"%s\\DeadOrAlive2Ultimate", save_base);
        } else {
            GetCurrentDirectoryW(MAX_PATH, s_save_dir);
            wcscat_s(s_save_dir, MAX_PATH, L"\\SaveData");
        }
    }

    /* Ensure trailing backslashes are stripped for consistent concatenation */
    size_t len = wcslen(s_game_dir);
    if (len > 0 && s_game_dir[len - 1] == L'\\')
        s_game_dir[len - 1] = L'\0';

    len = wcslen(s_save_dir);
    if (len > 0 && s_save_dir[len - 1] == L'\\')
        s_save_dir[len - 1] = L'\0';

    s_initialized = TRUE;
    xbox_log(XBOX_LOG_INFO, XBOX_LOG_PATH, "Path init: game=%S, save=%S", s_game_dir, s_save_dir);
}

/*
 * Helper: check if an ANSI string starts with a prefix (case-insensitive).
 * Returns the number of chars consumed from the prefix, or 0 if no match.
 */
static int match_prefix(const char* path, const char* prefix)
{
    int i = 0;
    while (prefix[i]) {
        if (tolower((unsigned char)path[i]) != tolower((unsigned char)prefix[i]))
            return 0;
        i++;
    }
    return i;
}

BOOL xbox_translate_path(const char* xbox_path, WCHAR* win_path_buf, DWORD buf_size)
{
    const char* remainder = NULL;
    const WCHAR* base_dir = NULL;
    const WCHAR* sub_dir = NULL;
    int skip;

    if (!xbox_path || !win_path_buf || buf_size == 0)
        return FALSE;

    if (!s_initialized)
        xbox_path_init(NULL, NULL);

    /* \Device\CdRom0\ → game disc */
    skip = match_prefix(xbox_path, "\\Device\\CdRom0\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_game_dir;
        sub_dir = NULL;
        goto translate;
    }

    /* \Device\Harddisk0\Partition1\ → game disc (alternative) */
    skip = match_prefix(xbox_path, "\\Device\\Harddisk0\\Partition1\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_game_dir;
        sub_dir = NULL;
        goto translate;
    }

    /* D:\ → game disc */
    skip = match_prefix(xbox_path, "D:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_game_dir;
        sub_dir = NULL;
        goto translate;
    }

    /* d:\ (lowercase variant) */
    skip = match_prefix(xbox_path, "d:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_game_dir;
        sub_dir = NULL;
        goto translate;
    }

    /* T:\ → TitleData (save games) */
    skip = match_prefix(xbox_path, "T:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_save_dir;
        sub_dir = s_title_redirect ? L"\\TitleData_netplay" : L"\\TitleData";
        goto translate;
    }

    /* U:\ → UserData */
    skip = match_prefix(xbox_path, "U:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_save_dir;
        sub_dir = L"\\UserData";
        goto translate;
    }

    /* Z:\ → Cache */
    skip = match_prefix(xbox_path, "Z:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_save_dir;
        sub_dir = L"\\Cache";
        goto translate;
    }

    /* \??\D:\ variant (NT object manager prefix) */
    skip = match_prefix(xbox_path, "\\??\\D:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_game_dir;
        sub_dir = NULL;
        goto translate;
    }

    skip = match_prefix(xbox_path, "\\??\\T:\\");
    if (skip) {
        remainder = xbox_path + skip;
        base_dir = s_save_dir;
        sub_dir = s_title_redirect ? L"\\TitleData_netplay" : L"\\TitleData";
        goto translate;
    }

    /* Unrecognized path - try to use as-is by converting to wide */
    xbox_log(XBOX_LOG_WARN, XBOX_LOG_PATH, "Unrecognized Xbox path: %s", xbox_path);
    MultiByteToWideChar(CP_ACP, 0, xbox_path, -1, win_path_buf, buf_size);
    return TRUE;

translate:
    {
        WCHAR remainder_wide[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, remainder, -1, remainder_wide, MAX_PATH);

        /* Convert forward slashes to backslashes in remainder */
        for (WCHAR* p = remainder_wide; *p; p++) {
            if (*p == L'/') *p = L'\\';
        }

        if (sub_dir) {
            swprintf_s(win_path_buf, buf_size, L"%s%s\\%s", base_dir, sub_dir, remainder_wide);
        } else {
            swprintf_s(win_path_buf, buf_size, L"%s\\%s", base_dir, remainder_wide);
        }

        /* Ensure save directories exist */
        if (sub_dir) {
            WCHAR dir_path[MAX_PATH];
            swprintf_s(dir_path, MAX_PATH, L"%s%s", base_dir, sub_dir);
            CreateDirectoryW(s_save_dir, NULL);
            CreateDirectoryW(dir_path, NULL);
        }

        XBOX_TRACE(XBOX_LOG_PATH, "%s -> %S", xbox_path, win_path_buf);
        return TRUE;
    }
}
