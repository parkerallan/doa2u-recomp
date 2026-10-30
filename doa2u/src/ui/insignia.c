/* Insignia console registration (see insignia.h). Same request as the Setup Assistant's
 * "Register Xbox" (2025-01-19): POST https://insignia.live/api/v1/xbox, 200/422/429. */
#include <windows.h>
#include <winhttp.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "insignia.h"
#include "video_settings.h"
#include "kernel.h"

#pragma comment(lib, "winhttp.lib")

static volatile LONG s_state = INSIGNIA_IDLE;
static char s_msg[256];
static char s_serial[13];

const char *insignia_serial(void)
{
    memcpy(s_serial, xbox_console_identity_get()->serial, 12);
    s_serial[12] = 0;
    return s_serial;
}

int insignia_is_registered(void)
{
    char reg[16];
    GetPrivateProfileStringA("Insignia", "RegisteredSerial", "", reg, sizeof reg,
                             doa2u_settings_ini_path());
    return reg[0] && !strcmp(reg, insignia_serial());
}

int insignia_register_state(char *msg, size_t msg_len)
{
    if (msg && msg_len)
        strncpy_s(msg, msg_len, s_msg, _TRUNCATE);
    return (int)s_state;
}

static void hex(char *out, const uint8_t *b, int n)
{
    int i;
    for (i = 0; i < n; i++)
        sprintf_s(out + i * 2, 3, "%02X", b[i]);
}

/* Body, byte for byte as the Setup Assistant builds it (keys as %02X). */
static DWORD WINAPI register_thread(LPVOID p)
{
    const xbox_console_identity *id = xbox_console_identity_get();
    static const WCHAR hdrs[] = L"Content-Type: application/json\r\nAccept: application/json\r\n";
    char body[256], hdd[33], onl[33], reply[512] = "";
    HINTERNET ses, con = NULL, req = NULL;
    DWORD status = 0, len = sizeof(status), got, n = 0;
    int ok = 0;
    (void)p;

    hex(hdd, id->hdd_key, 16);
    hex(onl, id->online_key, 16);
    sprintf_s(body, sizeof body, "{\"serial_number\": \"%s\",\"hdd_key\": \"%s\",\"online_key\": \"%s\"}",
              insignia_serial(), hdd, onl);

    ses = WinHttpOpen(L"DOA2U-PC", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, NULL, NULL, 0);
    if (ses) con = WinHttpConnect(ses, L"insignia.live", INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (con) req = WinHttpOpenRequest(con, L"POST", L"/api/v1/xbox", NULL, NULL, NULL, WINHTTP_FLAG_SECURE);
    if (req && WinHttpSendRequest(req, hdrs, (DWORD)-1L, body, (DWORD)strlen(body), (DWORD)strlen(body), 0) &&
        WinHttpReceiveResponse(req, NULL) &&
        WinHttpQueryHeaders(req, WINHTTP_QUERY_STATUS_CODE | WINHTTP_QUERY_FLAG_NUMBER,
                            WINHTTP_HEADER_NAME_BY_INDEX, &status, &len, WINHTTP_NO_HEADER_INDEX)) {
        while (n + 1 < sizeof reply && WinHttpReadData(req, reply + n, (DWORD)(sizeof reply - 1 - n), &got) && got)
            n += got;
        reply[n] = 0;
        if (status == 200) {
            ok = 1;
            WritePrivateProfileStringA("Insignia", "RegisteredSerial", insignia_serial(),
                                       doa2u_settings_ini_path());
            sprintf_s(s_msg, sizeof s_msg, "Registered with Insignia.");
        } else if (status == 429) {
            sprintf_s(s_msg, sizeof s_msg, "Insignia is rate-limiting requests; try again later.");
        } else {
            sprintf_s(s_msg, sizeof s_msg, "Insignia refused (HTTP %lu): %.180s", status, reply);
        }
        xbox_log(XBOX_LOG_INFO, "INSIGNIA", "register: HTTP %lu %s", status, reply);
    } else {
        sprintf_s(s_msg, sizeof s_msg, "Could not reach insignia.live (error %lu).", GetLastError());
    }
    if (req) WinHttpCloseHandle(req);
    if (con) WinHttpCloseHandle(con);
    if (ses) WinHttpCloseHandle(ses);
    InterlockedExchange(&s_state, ok ? INSIGNIA_OK : INSIGNIA_FAILED);
    return 0;
}

/* Account wizard request/status, shared between the overlay and the game thread. */
static SRWLOCK s_wiz_lock = SRWLOCK_INIT;
static int  s_wiz_state = INSIGNIA_IDLE, s_wiz_pending, s_wiz_recover;
static char s_wiz_gamertag[16], s_wiz_code[32], s_wiz_email[128], s_wiz_msg[256];

void insignia_wizard_start(int recover, const char *gamertag, const char *code, const char *email)
{
    AcquireSRWLockExclusive(&s_wiz_lock);
    if (s_wiz_state != INSIGNIA_BUSY) {
        strncpy_s(s_wiz_gamertag, sizeof s_wiz_gamertag, gamertag, _TRUNCATE);
        strncpy_s(s_wiz_code, sizeof s_wiz_code, code, _TRUNCATE);
        strncpy_s(s_wiz_email, sizeof s_wiz_email, email ? email : "", _TRUNCATE);
        s_wiz_recover = recover;
        s_wiz_pending = 1;
        s_wiz_state = INSIGNIA_BUSY;
        strcpy_s(s_wiz_msg, sizeof s_wiz_msg, "Waiting for the game...");
    }
    ReleaseSRWLockExclusive(&s_wiz_lock);
}

int insignia_wizard_state(char *msg, size_t msg_len)
{
    int st;
    AcquireSRWLockShared(&s_wiz_lock);
    st = s_wiz_state;
    if (msg && msg_len)
        strncpy_s(msg, msg_len, s_wiz_msg, _TRUNCATE);
    ReleaseSRWLockShared(&s_wiz_lock);
    return st;
}

int insignia_wizard_take(int *recover, char *gamertag, size_t gt_len, char *code, size_t code_len,
                         char *email, size_t email_len)
{
    int got;
    AcquireSRWLockExclusive(&s_wiz_lock);
    got = s_wiz_pending;
    if (got) {
        strncpy_s(gamertag, gt_len, s_wiz_gamertag, _TRUNCATE);
        strncpy_s(code, code_len, s_wiz_code, _TRUNCATE);
        strncpy_s(email, email_len, s_wiz_email, _TRUNCATE);
        *recover = s_wiz_recover;
        s_wiz_pending = 0;
    }
    ReleaseSRWLockExclusive(&s_wiz_lock);
    return got;
}

void insignia_wizard_report(int state, const char *fmt, ...)
{
    va_list ap;
    AcquireSRWLockExclusive(&s_wiz_lock);
    s_wiz_state = state;
    va_start(ap, fmt);
    vsprintf_s(s_wiz_msg, sizeof s_wiz_msg, fmt, ap);
    va_end(ap);
    ReleaseSRWLockExclusive(&s_wiz_lock);
    xbox_log(XBOX_LOG_INFO, "INSIGNIA", "wizard: %s", s_wiz_msg);
}

void insignia_register_start(void)
{
    HANDLE h;
    if (InterlockedCompareExchange(&s_state, INSIGNIA_BUSY, INSIGNIA_IDLE) != INSIGNIA_IDLE &&
        InterlockedCompareExchange(&s_state, INSIGNIA_BUSY, INSIGNIA_FAILED) != INSIGNIA_FAILED)
        return;
    s_msg[0] = 0;
    h = CreateThread(NULL, 0, register_thread, NULL, 0, NULL);
    if (h) CloseHandle(h);
    else InterlockedExchange(&s_state, INSIGNIA_FAILED);
}
