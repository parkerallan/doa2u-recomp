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
#include <bcrypt.h>
#pragma comment(lib, "bcrypt.lib")

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

/* The title update's game program, where a console keeps it: E:\TDATA\54430006\$U
 * (T:\$U on this title), so <save>\TitleData\$U\doa2.xbe here. */
void xbox_path_title_update_xbe(WCHAR* out, size_t count)
{
    if (!s_initialized) xbox_path_init(NULL, NULL);
    swprintf_s(out, count, L"%s\\TitleData\\$U\\doa2.xbe", s_save_dir);
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

/* Config area file, created zeroed on first use so blank sectors read back as zeros. */
#define HDD_CONFIG_SECTORS 32

static void hdd_config_path(WCHAR* buf, DWORD size)
{
    HANDLE h;
    LARGE_INTEGER sz;

    CreateDirectoryW(s_save_dir, NULL);
    swprintf_s(buf, size, L"%s\\HDDConfig.bin", s_save_dir);
    h = CreateFileW(buf, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                    NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (h == INVALID_HANDLE_VALUE)
        return;
    if (GetFileSizeEx(h, &sz) && sz.QuadPart < HDD_CONFIG_SECTORS * 512) {
        sz.QuadPart = HDD_CONFIG_SECTORS * 512;
        SetFilePointerEx(h, sz, NULL, FILE_BEGIN);
        SetEndOfFile(h);
    }
    CloseHandle(h);
}

/* XNet config sector N lives at disk sector N+8; layout and checksum from the
 * game's reader (0x393D7A): sig, version, 1, 0x1EC data, ~sum, end sig. */
static void hdd_config_write_sector(HANDLE h, int index, const void* data, size_t len)
{
    uint32_t s[128] = {0};
    uint64_t sum = 0;
    uint32_t lo, folded;
    LARGE_INTEGER off;
    DWORD written;
    int i;

    s[0] = 0x79132568;
    s[1] = 1;
    s[2] = 1;
    memcpy(&s[3], data, len);
    s[127] = 0xAA550000;
    for (i = 0; i < 128; i++)
        sum += s[i];
    lo = (uint32_t)sum;
    folded = lo + (uint32_t)(sum >> 32);
    if (folded < lo)
        folded++;
    s[126] = ~folded;

    off.QuadPart = (LONGLONG)(index + 8) * 512;
    SetFilePointerEx(h, off, NULL, FILE_BEGIN);
    WriteFile(h, s, sizeof(s), &written, NULL);
}

const xbox_console_identity* xbox_console_identity_get(void)
{
    static xbox_console_identity id;
    static BOOL loaded = FALSE;
    WCHAR path[MAX_PATH];
    uint8_t buf[4 + sizeof(id)];
    HANDLE h;
    DWORD n = 0;
    int i, nonzero = 0;

    if (loaded)
        return &id;
    if (!s_initialized)
        xbox_path_init(NULL, NULL);
    CreateDirectoryW(s_save_dir, NULL);
    swprintf_s(path, MAX_PATH, L"%s\\ConsoleIdentity.bin", s_save_dir);

    h = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        if (!ReadFile(h, buf, sizeof(buf), &n, NULL))
            n = 0;
        CloseHandle(h);
    }
    if (n == sizeof(buf) && !memcmp(buf, "DXID", 4)) {
        memcpy(&id, buf + 4, sizeof(id));
        for (i = 0; i < 16; i++)
            nonzero |= id.hdd_key[i];
    }
    if (!nonzero) {
        /* First run: a new console. Serial is 12 digits, keys are random. */
        BCryptGenRandom(NULL, (PUCHAR)&id, sizeof(id), BCRYPT_USE_SYSTEM_PREFERRED_RNG);
        for (i = 0; i < 12; i++)
            id.serial[i] = (char)('0' + (uint8_t)id.serial[i] % 10);
        id.hdd_key[0] |= 1;
        memcpy(buf, "DXID", 4);
        memcpy(buf + 4, &id, sizeof(id));
        h = CreateFileW(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (h != INVALID_HANDLE_VALUE) {
            WriteFile(h, buf, sizeof(buf), &n, NULL);
            CloseHandle(h);
        }
        xbox_log(XBOX_LOG_INFO, XBOX_LOG_PATH, "Console identity created: serial %.12s", id.serial);
    }
    loaded = TRUE;
    return &id;
}

/* Encrypts the record's key@0x50 as XONLINE 0x3A0218 does: 3DES-CBC, IV = table entry,
 * key = HMACs of XboxHDKey keyed by the game's constants at 0x106E7E8 / 0x106E7D4. */
static BOOL hdd_encrypt_user_key(uint8_t* rec, const uint8_t* iv_in)
{
    extern ptrdiff_t g_xbox_mem_offset;
    const UCHAR* k1 = (const UCHAR*)((uintptr_t)0x0106E7E8 + g_xbox_mem_offset);
    const UCHAR* k2 = (const UCHAR*)((uintptr_t)0x0106E7D4 + g_xbox_mem_offset);
    const UCHAR* hd_key = xbox_console_identity_get()->hdd_key;
    MEMORY_BASIC_INFORMATION mbi;
    UCHAR d1[20], d2[20], des_key[24], iv[8];
    uint64_t table[48];

    if (!VirtualQuery(k2, &mbi, sizeof(mbi)) || mbi.State != MEM_COMMIT) {
        xbox_log(XBOX_LOG_WARN, XBOX_LOG_PATH, "Xbox Live account: game not loaded, not written");
        return FALSE;
    }
    xbox_XcHMAC(k1, 16, hd_key, 16, NULL, 0, d1);
    xbox_XcHMAC(k2, 16, hd_key, 16, NULL, 0, d2);
    memcpy(des_key, d1, 4);
    memcpy(des_key + 4, d2, 20);
    xbox_XcDESKeyParity(des_key, sizeof(des_key));
    xbox_XcKeyTable(1, table, des_key);
    memcpy(iv, iv_in, 8);
    xbox_XcBlockCryptCBC(1, 16, rec + 0x50, rec + 0x50, table, 1, iv);
    return TRUE;
}

/* Accounts live one per config sector 4..11; sector 3's table lists only sector 4, the
 * account the game signs in with. Records are self-contained, so selecting just moves them. */
#define HDD_ACCOUNT_SLOTS 8

static HANDLE hdd_config_open(void)
{
    WCHAR path[MAX_PATH];
    if (!s_initialized)
        xbox_path_init(NULL, NULL);
    hdd_config_path(path, MAX_PATH);
    return CreateFileW(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                       NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

static BOOL hdd_read_record(HANDLE h, int slot, uint8_t rec[0x6C])
{
    uint32_t sec[128];
    LARGE_INTEGER off;
    DWORD got = 0;
    off.QuadPart = (LONGLONG)(slot + 12) * 512;
    SetFilePointerEx(h, off, NULL, FILE_BEGIN);
    if (!ReadFile(h, sec, sizeof(sec), &got, NULL) || got != sizeof(sec) || sec[0] != 0x79132568)
        return FALSE;
    memcpy(rec, &sec[3], 0x6C);
    return (rec[0] | rec[1] | rec[2] | rec[3] | rec[4] | rec[5] | rec[6] | rec[7]) && rec[0x0C] != 0;
}

static void hdd_write_table(HANDLE h, const uint8_t* rec0)
{
    uint8_t table[0x60] = {0};
    if (rec0) {
        table[0] = 1;
        memcpy(table + 4, rec0, 8);
    }
    hdd_config_write_sector(h, 3, table, sizeof(table));
}

int xbox_hdd_account_list(char names[][16], int max)
{
    uint8_t rec[0x6C];
    HANDLE h = hdd_config_open();
    int i, n = 0;
    for (i = 0; i < max && i < HDD_ACCOUNT_SLOTS; i++) {
        names[i][0] = 0;
        if (h != INVALID_HANDLE_VALUE && hdd_read_record(h, i, rec)) {
            memcpy(names[i], rec + 0x0C, 15);
            names[i][15] = 0;
            n++;
        }
    }
    if (h != INVALID_HANDLE_VALUE) CloseHandle(h);
    return n;
}

BOOL xbox_hdd_account_select(int slot)
{
    uint8_t a[0x6C], b[0x6C];
    HANDLE h = hdd_config_open();
    BOOL has_b;
    if (h == INVALID_HANDLE_VALUE || slot < 0 || slot >= HDD_ACCOUNT_SLOTS || !hdd_read_record(h, slot, a)) {
        if (h != INVALID_HANDLE_VALUE) CloseHandle(h);
        return FALSE;
    }
    if (slot != 0) {
        has_b = hdd_read_record(h, 0, b);
        hdd_config_write_sector(h, 4, a, 0x6C);
        if (!has_b) memset(b, 0, sizeof(b));
        hdd_config_write_sector(h, 4 + slot, b, 0x6C);
    }
    hdd_write_table(h, a);
    CloseHandle(h);
    xbox_log(XBOX_LOG_INFO, XBOX_LOG_PATH, "Xbox Live account: %.15s", a + 0x0C);
    return TRUE;
}

BOOL xbox_hdd_account_remove(int slot)
{
    uint8_t rec[0x6C] = {0};
    HANDLE h = hdd_config_open();
    int i;
    if (h == INVALID_HANDLE_VALUE || slot < 0 || slot >= HDD_ACCOUNT_SLOTS) {
        if (h != INVALID_HANDLE_VALUE) CloseHandle(h);
        return FALSE;
    }
    hdd_config_write_sector(h, 4 + slot, rec, sizeof(rec));
    if (slot == 0) {
        hdd_write_table(h, NULL);
        for (i = 1; i < HDD_ACCOUNT_SLOTS; i++)
            if (hdd_read_record(h, i, rec)) {
                hdd_config_write_sector(h, 4, rec, sizeof(rec));
                hdd_write_table(h, rec);
                memset(rec, 0, sizeof(rec));
                hdd_config_write_sector(h, 4 + i, rec, sizeof(rec));
                break;
            }
    }
    CloseHandle(h);
    return TRUE;
}

/* Adds the account Insignia returned and makes it the one the game signs in with. Record as
 * the dashboard's 0x121F40: XUID@0, gamertag@0xC, domain@0x24, realm@0x38, key@0x50 (3DES),
 * half-seconds since 2001@0x60, HMAC(XboxHDKey, rec[0..0x64])@0x64. */
BOOL xbox_hdd_set_online_account(const uint8_t* xuid, const char* gamertag, const uint8_t* key,
                                 const char* domain, const char* realm)
{
    const UCHAR* hd_key = xbox_console_identity_get()->hdd_key;
    uint8_t rec[0x6C] = {0}, old[0x6C], cur[0x6C];
    UCHAR digest[20];
    FILETIME ft; ULARGE_INTEGER t;
    HANDLE h;
    int i, free_slot = -1, same = -1;

    memcpy(rec, xuid, 8);
    strncpy_s((char*)rec + 0x0C, 16, gamertag, _TRUNCATE);
    strncpy_s((char*)rec + 0x24, 20, domain, _TRUNCATE);
    strncpy_s((char*)rec + 0x38, 24, realm, _TRUNCATE);
    memcpy(rec + 0x50, key, 16);
    GetSystemTimeAsFileTime(&ft);
    t.LowPart = ft.dwLowDateTime; t.HighPart = ft.dwHighDateTime;
    *(uint32_t*)(rec + 0x60) = (uint32_t)((t.QuadPart - 126227808000000000ull) / 20000000ull);
    xbox_XcHMAC(hd_key, 16, rec, 0x64, NULL, 0, digest);
    memcpy(rec + 0x64, digest, 8);
    if (!hdd_encrypt_user_key(rec, xuid))
        return FALSE;

    h = hdd_config_open();
    if (h == INVALID_HANDLE_VALUE)
        return FALSE;
    for (i = 0; i < HDD_ACCOUNT_SLOTS; i++) {
        if (hdd_read_record(h, i, cur)) { if (!memcmp(cur, xuid, 8)) same = i; }
        else if (free_slot < 0) free_slot = i;
    }
    if (same > 0) {
        memset(cur, 0, sizeof(cur));
        hdd_config_write_sector(h, 4 + same, cur, sizeof(cur));
        if (free_slot < 0 || free_slot > same) free_slot = same;
    }
    if (same != 0 && hdd_read_record(h, 0, old)) {
        if (free_slot < 0) { CloseHandle(h); return FALSE; }
        hdd_config_write_sector(h, 4 + free_slot, old, sizeof(old));
    }
    hdd_config_write_sector(h, 4, rec, sizeof(rec));
    hdd_write_table(h, rec);
    CloseHandle(h);
    xbox_log(XBOX_LOG_INFO, XBOX_LOG_PATH, "Xbox Live account: %s@%s", gamertag, domain);
    return TRUE;
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

    /* \??\X:\ for any other drive (XDeleteSaveGame opens \??\U:\<save>\):
     * drop the object-manager prefix and translate the DOS path. */
    if (match_prefix(xbox_path, "\\??\\") && xbox_path[4] && xbox_path[5] == ':' &&
        xbox_path[6] == '\\')
        return xbox_translate_path(xbox_path + 4, win_path_buf, buf_size);

    /* Raw config area: XAPI, XNET and XONLINE read/write sectors by offset */
    if (!_stricmp(xbox_path, "\\Device\\Harddisk0\\partition0")) {
        hdd_config_path(win_path_buf, buf_size);
        return TRUE;
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
