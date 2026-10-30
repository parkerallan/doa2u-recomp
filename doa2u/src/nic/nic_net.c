/* Host side of the NIC: libslirp user-mode NAT on its own thread. Guest frames go in
 * unchanged; DHCP hands out this PC's LAN address with Insignia's DNS server, 46.101.64.175. */

#include <winsock2.h>
#include <ws2tcpip.h>
#include <winhttp.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "slirp/libslirp.h"
#include "kernel.h"
#include "nic.h"

#define INSIGNIA_DNS "46.101.64.175"
#define TXQ_MAX      64

/* insigniaDNS's zone list (insignia.live/dns_zones.json), for networks that intercept
 * port 53: these names are answered here, as the insigniaDNS tool would. */
#define ZONE_MAX 32
static struct { char name[128]; uint32_t ip; } s_zone[ZONE_MAX];
static int s_zone_n;
static uint32_t s_dns_ip;                 /* 46.101.64.175, network order */

static Slirp*   s_slirp;
static HANDLE   s_thread;
static volatile LONG s_started;
static SRWLOCK  s_txq_lock = SRWLOCK_INIT;
static struct { uint16_t len; uint8_t data[0x800]; } s_txq[TXQ_MAX];
static int      s_txq_head, s_txq_count;

/* slirp's only timer (IPv6 router adverts, unused with IPv6 off), kept for completeness */
static struct { int64_t expire_ms; SlirpTimerId id; void* cb_opaque; int armed; } s_timer;

static uint32_t s_guest_ip, s_gateway_ip;      /* host order */

/* The IPv4 address of the interface that carries the default route (no packet is sent). */
static uint32_t lan_address(void)
{
    SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in to, me; int len = sizeof me; uint32_t ip = 0;
    if (s == INVALID_SOCKET) return 0;
    memset(&to, 0, sizeof to); to.sin_family = AF_INET; to.sin_port = htons(53);
    inet_pton(AF_INET, "8.8.8.8", &to.sin_addr);
    if (!connect(s, (struct sockaddr *)&to, sizeof to) && !getsockname(s, (struct sockaddr *)&me, &len))
        ip = ntohl(me.sin_addr.s_addr);
    closesocket(s);
    return ip;
}

static int64_t now_ms(void) { return (int64_t)GetTickCount64(); }

/* TEMP: pcap of every guest frame, both directions. */
static void pcap_frame(const void *buf, uint32_t len)
{
    static FILE *f; static SRWLOCK lk = SRWLOCK_INIT;
    FILETIME ft; uint64_t t; uint32_t rec[4];
    AcquireSRWLockExclusive(&lk);
    if (!f && (f = fopen("doa2u_net.pcap", "wb"))) {
        uint32_t hdr[6] = { 0xa1b2c3d4u, 0x00040002u, 0, 0, 65535, 1 };
        fwrite(hdr, 1, sizeof hdr, f);
    }
    if (f) {
        GetSystemTimeAsFileTime(&ft);
        t = ((uint64_t)ft.dwHighDateTime << 32 | ft.dwLowDateTime) / 10 - 11644473600000000ull;
        rec[0] = (uint32_t)(t / 1000000); rec[1] = (uint32_t)(t % 1000000); rec[2] = rec[3] = len;
        fwrite(rec, 1, sizeof rec, f); fwrite(buf, 1, len, f); fflush(f);
    }
    ReleaseSRWLockExclusive(&lk);
}

static slirp_ssize_t cb_send(const void* buf, size_t len, void* opaque)
{
    (void)opaque;
    pcap_frame(buf, (uint32_t)len);
    nic_rx_enqueue((const uint8_t*)buf, (uint32_t)len);
    return (slirp_ssize_t)len;
}
static void cb_guest_error(const char* msg, void* opaque)
{
    (void)opaque;
    xbox_log(XBOX_LOG_WARN, "NIC", "slirp: %s", msg);
}
static int64_t cb_clock_ns(void* opaque)
{
    LARGE_INTEGER c, f;
    (void)opaque;
    QueryPerformanceCounter(&c);
    QueryPerformanceFrequency(&f);
    return (int64_t)((double)c.QuadPart * 1e9 / (double)f.QuadPart);
}
static void* cb_timer_new(SlirpTimerId id, void* cb_opaque, void* opaque)
{
    (void)opaque;
    s_timer.id = id;
    s_timer.cb_opaque = cb_opaque;
    s_timer.armed = 0;
    return &s_timer;
}
static void cb_timer_free(void* t, void* opaque) { (void)t; (void)opaque; s_timer.armed = 0; }
static void cb_timer_mod(void* t, int64_t expire_ms, void* opaque)
{
    (void)t; (void)opaque;
    s_timer.expire_ms = expire_ms;
    s_timer.armed = 1;
}
static void cb_poll_socket(slirp_os_socket s, void* opaque) { (void)s; (void)opaque; }
static void cb_notify(void* opaque) { (void)opaque; }

/* WSAPoll has no POLLPRI: urgent data maps to POLLRDBAND. */
static WSAPOLLFD s_pfd[256];
static int       s_npfd;
static int cb_add_poll(slirp_os_socket fd, int events, void* opaque)
{
    short e = 0;
    (void)opaque;
    if (s_npfd >= 256)
        return -1;
    if (events & SLIRP_POLL_IN) e |= POLLRDNORM;
    if (events & SLIRP_POLL_OUT) e |= POLLWRNORM;
    if (events & SLIRP_POLL_PRI) e |= POLLRDBAND;
    s_pfd[s_npfd].fd = fd;
    s_pfd[s_npfd].events = e;
    s_pfd[s_npfd].revents = 0;
    return s_npfd++;
}
static int cb_get_revents(int idx, void* opaque)
{
    short r;
    int ev = 0;
    (void)opaque;
    if (idx < 0 || idx >= s_npfd)
        return 0;
    r = s_pfd[idx].revents;
    if (r & (POLLRDNORM | POLLHUP)) ev |= SLIRP_POLL_IN;
    if (r & POLLWRNORM) ev |= SLIRP_POLL_OUT;
    if (r & POLLRDBAND) ev |= SLIRP_POLL_PRI;
    if (r & POLLERR) ev |= SLIRP_POLL_ERR;
    if (r & POLLHUP) ev |= SLIRP_POLL_HUP;
    return ev;
}

/* Copies the JSON string value of "key" found at or after p into out; returns past it. */
static const char* json_str(const char* p, const char* key, char* out, size_t out_len)
{
    char pat[32];
    const char* q;
    size_t n = 0;
    sprintf_s(pat, sizeof(pat), "\"%s\"", key);
    if (!(p = strstr(p, pat)) || !(p = strchr(p + strlen(pat), '"')))
        return NULL;
    for (q = p + 1; *q && *q != '"' && n + 1 < out_len; q++)
        out[n++] = *q;
    out[n] = 0;
    return q;
}

static void zone_add(const char* name, const char* type, const char* value)
{
    struct addrinfo hints, *res = NULL;
    uint32_t ip = 0;
    if (s_zone_n >= ZONE_MAX)
        return;
    if (!strcmp(type, "a")) {
        inet_pton(AF_INET, value, &ip);
    } else if (!strcmp(type, "p")) {
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        if (!getaddrinfo(value, NULL, &hints, &res) && res) {
            ip = ((struct sockaddr_in*)res->ai_addr)->sin_addr.s_addr;
            freeaddrinfo(res);
        }
    }
    if (!ip)
        return;
    strncpy_s(s_zone[s_zone_n].name, sizeof(s_zone[0].name), name, _TRUNCATE);
    s_zone[s_zone_n].ip = ip;
    s_zone_n++;
    xbox_log(XBOX_LOG_INFO, "NIC", "zone %s -> %u.%u.%u.%u", name,
             ip & 0xFF, (ip >> 8) & 0xFF, (ip >> 16) & 0xFF, ip >> 24);
}

/* GET https://insignia.live/dns_zones.json: [{"type":"p","name":...,"value":...}, ...] */
static void zones_load(void)
{
    HINTERNET ses, con = NULL, req = NULL;
    char* body = NULL;
    DWORD len = 0, got;
    const char* p;

    ses = WinHttpOpen(L"DOA2U-PC", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, NULL, NULL, 0);
    if (ses) con = WinHttpConnect(ses, L"insignia.live", INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (con) req = WinHttpOpenRequest(con, L"GET", L"/dns_zones.json", NULL, NULL, NULL, WINHTTP_FLAG_SECURE);
    if (req && WinHttpSendRequest(req, NULL, 0, NULL, 0, 0, 0) && WinHttpReceiveResponse(req, NULL)) {
        body = (char*)malloc(65536);
        while (body && len < 65535 && WinHttpReadData(req, body + len, 65535 - len, &got) && got)
            len += got;
    }
    if (body) {
        body[len] = 0;
        for (p = body; (p = strchr(p, '{')) != NULL; p++) {
            char type[8], name[128], value[128];
            const char* end = strchr(p, '}');
            if (!end || !json_str(p, "type", type, sizeof(type)) || !json_str(p, "name", name, sizeof(name)) ||
                !json_str(p, "value", value, sizeof(value)))
                break;
            zone_add(name, type, value);
            p = end;
        }
        free(body);
    }
    if (!s_zone_n)
        xbox_log(XBOX_LOG_WARN, "NIC", "insignia.live/dns_zones.json unavailable: DNS passes through");
    if (req) WinHttpCloseHandle(req);
    if (con) WinHttpCloseHandle(con);
    if (ses) WinHttpCloseHandle(ses);
}

static uint16_t ip_csum(const uint8_t* p, int n)
{
    uint32_t s = 0;
    int i;
    for (i = 0; i + 1 < n; i += 2)
        s += (uint32_t)(p[i] << 8 | p[i + 1]);
    while (s >> 16)
        s = (s & 0xFFFF) + (s >> 16);
    return (uint16_t)~s;
}

/* A guest DNS query to the advertised server for a zone name: reply here (A record, or
 * no answer for other types) and return 1. Anything else returns 0 and goes to slirp. */
static int dns_answer_local(const uint8_t* f, uint32_t len)
{
    const uint8_t *ip = f + 14, *udp, *dns, *q;
    char name[256];
    uint8_t r[600];
    uint32_t ihl, n = 0, qlen, i, hit = (uint32_t)-1, rlen;
    uint16_t qtype, c;

    if (len < 14 + 20 + 8 + 12 || f[12] != 0x08 || f[13] != 0x00 || ip[9] != 17)
        return 0;
    ihl = (ip[0] & 0xF) * 4;
    udp = ip + ihl;
    if (memcmp(ip + 16, &s_dns_ip, 4) || udp[2] != 0 || udp[3] != 53)
        return 0;
    dns = udp + 8;
    for (q = dns + 12; q < f + len && *q; q += 1 + *q) {
        if (*q > 63 || q + 1 + *q > f + len || n + *q + 1 >= sizeof(name))
            return 0;
        if (n) name[n++] = '.';
        memcpy(name + n, q + 1, *q);
        n += *q;
    }
    name[n] = 0;
    if (q + 5 > f + len)
        return 0;
    qtype = (uint16_t)(q[1] << 8 | q[2]);
    qlen = (uint32_t)(q + 5 - (dns + 12));
    for (i = 0; i < (uint32_t)s_zone_n; i++)
        if (!_stricmp(name, s_zone[i].name)) hit = i;
    if (hit == (uint32_t)-1)
        return 0;

    memcpy(r, f + 6, 6);                       /* to the guest */
    memcpy(r + 6, f, 6);                       /* from the gateway MAC it used */
    r[12] = 0x08; r[13] = 0x00;
    memset(r + 14, 0, 20);
    r[14] = 0x45; r[22] = 64; r[23] = 17;
    memcpy(r + 26, &s_dns_ip, 4);
    memcpy(r + 30, ip + 12, 4);
    r[34] = udp[2]; r[35] = udp[3]; r[36] = udp[0]; r[37] = udp[1];
    r[40] = r[41] = 0;                          /* no UDP checksum */
    memcpy(r + 42, dns, 2);                     /* query ID */
    r[44] = 0x81; r[45] = 0x80;                 /* response, RD, RA, NOERROR */
    r[46] = 0; r[47] = 1;
    r[48] = 0; r[49] = (qtype == 1) ? 1 : 0;
    memset(r + 50, 0, 4);
    memcpy(r + 54, dns + 12, qlen);
    rlen = 54 + qlen;
    if (qtype == 1) {
        static const uint8_t ans[12] = { 0xC0, 0x0C, 0, 1, 0, 1, 0, 0, 0x01, 0x2C, 0, 4 };
        memcpy(r + rlen, ans, 12);
        memcpy(r + rlen + 12, &s_zone[hit].ip, 4);
        rlen += 16;
    }
    r[16] = (uint8_t)((rlen - 14) >> 8); r[17] = (uint8_t)(rlen - 14);
    r[38] = (uint8_t)((rlen - 34) >> 8); r[39] = (uint8_t)(rlen - 34);
    c = ip_csum(r + 14, 20);
    r[24] = (uint8_t)(c >> 8); r[25] = (uint8_t)c;
    nic_rx_enqueue(r, rlen);
    return 1;
}

static int net_start(void)
{
    static const SlirpCb cb = {
        .send_packet = cb_send, .guest_error = cb_guest_error, .clock_get_ns = cb_clock_ns,
        .timer_free = cb_timer_free, .timer_mod = cb_timer_mod, .notify = cb_notify,
        .timer_new_opaque = cb_timer_new,
        .register_poll_socket = cb_poll_socket, .unregister_poll_socket = cb_poll_socket,
    };
    SlirpConfig cfg;
    WSADATA wsa;

    /* libslirp-0.dll and its glib runtime live in online\ next to the exe. Loading it by
     * full path here satisfies the delay-load later, and a missing DLL raises no fault. */
    {
        WCHAR path[MAX_PATH], *slash;
        GetModuleFileNameW(NULL, path, MAX_PATH);
        slash = wcsrchr(path, L'\\');
        wcscpy_s(slash ? slash + 1 : path, MAX_PATH - (slash ? (size_t)(slash + 1 - path) : 0), L"online\\libslirp-0.dll");
        if (!LoadLibraryExW(path, NULL, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR | LOAD_LIBRARY_SEARCH_DEFAULT_DIRS)) {
            xbox_log(XBOX_LOG_WARN, "NIC", "online\\libslirp-0.dll not found: network unavailable");
            return 0;
        }
    }
    WSAStartup(MAKEWORD(2, 2), &wsa);
    memset(&cfg, 0, sizeof(cfg));
    cfg.version = SLIRP_CONFIG_VERSION_MAX;
    cfg.in_enabled = true;
    {   /* The guest takes this PC's LAN address so the XNADDR it reports (ina) reaches it from
         * other machines on the LAN; a /30 keeps every other LAN host off-link and routed. */
        uint32_t ip = lan_address(), net, mask, gw;
        if (!ip) ip = 0x0A00020Fu;                                /* 10.0.2.15 without a route */
        /* Smallest block where the guest is neither its first nor its last address. */
        mask = 0xFFFFFFFCu;
        while ((ip & ~mask) == 0 || (ip & ~mask) == ~mask) mask <<= 1;
        net = ip & mask;
        gw = (ip + 1) == (net | ~mask) ? ip - 1 : ip + 1;
        cfg.vnetwork.s_addr = htonl(net); cfg.vnetmask.s_addr = htonl(mask);
        cfg.vhost.s_addr = htonl(gw);     cfg.vdhcp_start.s_addr = htonl(ip);
        s_guest_ip = ip; s_gateway_ip = gw;
    }
    /* Advertised by DHCP; slirp's own DNS proxy is off, so queries go to it as-is. */
    inet_pton(AF_INET, INSIGNIA_DNS, &cfg.vnameserver);
    inet_pton(AF_INET, INSIGNIA_DNS, &s_dns_ip);
    cfg.disable_dns = true;
    zones_load();
    s_slirp = slirp_new(&cfg, &cb, NULL);
    if (!s_slirp) {
        xbox_log(XBOX_LOG_WARN, "NIC", "slirp_new failed");
        return 0;
    }
    /* Xbox Live peer traffic is UDP 3074: the host port is bound to the guest's so other
     * machines reach it, on the LAN and through the gateway (Insignia's NAT guide). */
    {
        struct in_addr any; any.s_addr = INADDR_ANY;
        if (slirp_add_hostfwd(s_slirp, SLIRP_HOSTFWD_UDP, any, 3074, cfg.vdhcp_start, 3074) < 0)
            xbox_log(XBOX_LOG_WARN, "NIC", "UDP 3074 is in use on this PC: other players cannot reach the game");
    }
    xbox_log(XBOX_LOG_INFO, "NIC", "slirp %s up: guest %u.%u.%u.%u, gateway %u.%u.%u.%u, DNS %s",
             slirp_version_string(), s_guest_ip >> 24, (s_guest_ip >> 16) & 255, (s_guest_ip >> 8) & 255,
             s_guest_ip & 255, s_gateway_ip >> 24, (s_gateway_ip >> 16) & 255, (s_gateway_ip >> 8) & 255,
             s_gateway_ip & 255, INSIGNIA_DNS);
    return 1;
}

static DWORD WINAPI net_thread(LPVOID p)
{
    (void)p;
    if (!net_start())
        return 0;
    for (;;) {
        uint32_t timeout = 2;
        int r;

        AcquireSRWLockExclusive(&s_txq_lock);
        while (s_txq_count) {
            pcap_frame(s_txq[s_txq_head].data, s_txq[s_txq_head].len);
            if (!dns_answer_local(s_txq[s_txq_head].data, s_txq[s_txq_head].len))
                slirp_input(s_slirp, s_txq[s_txq_head].data, s_txq[s_txq_head].len);
            s_txq_head = (s_txq_head + 1) % TXQ_MAX;
            s_txq_count--;
        }
        ReleaseSRWLockExclusive(&s_txq_lock);

        if (s_timer.armed && now_ms() >= s_timer.expire_ms) {
            s_timer.armed = 0;
            slirp_handle_timer(s_slirp, s_timer.id, s_timer.cb_opaque);
        }

        s_npfd = 0;
        slirp_pollfds_fill_socket(s_slirp, &timeout, cb_add_poll, NULL);
        if (timeout > 2)
            timeout = 2;                  /* guest frames are picked up every 2 ms */
        if (s_npfd) {
            r = WSAPoll(s_pfd, (ULONG)s_npfd, (INT)timeout);
        } else {
            Sleep(timeout);
            r = 0;
        }
        slirp_pollfds_poll(s_slirp, r < 0, cb_get_revents, NULL);
    }
}

/* Game thread: a frame the guest transmitted. The first one starts the network. */
void nic_net_send(const uint8_t* frame, uint32_t len)
{
    if (!InterlockedExchange(&s_started, 1))
        s_thread = CreateThread(NULL, 0, net_thread, NULL, 0, NULL);
    if (len > sizeof(s_txq[0].data))
        return;
    AcquireSRWLockExclusive(&s_txq_lock);
    if (s_txq_count < TXQ_MAX) {
        int slot = (s_txq_head + s_txq_count) % TXQ_MAX;
        s_txq[slot].len = (uint16_t)len;
        memcpy(s_txq[slot].data, frame, len);
        s_txq_count++;
    }
    ReleaseSRWLockExclusive(&s_txq_lock);
}
