/*
 * kernel_crypto.c - Xbox Crypto Functions
 *
 * Implements SHA-1, RC4, HMAC-SHA1, and public key operations.
 *
 * The Xbox uses these for:
 *   - Save game signing (SHA-1 + HMAC)
 *   - Xbox Live authentication (RSA, RC4)
 *   - Content verification (SHA-1)
 *
 * Implementation uses Windows BCrypt API (available since Vista).
 * For save game compatibility, all crypto must produce identical outputs
 * to the original Xbox implementations.
 *
 * Note: RC4 is implemented manually since BCrypt deprecated it in newer
 * Windows versions. The Xbox RC4 is standard RC4 (ARC4).
 */

#include "kernel.h"
#include <bcrypt.h>
#include <string.h>

#pragma comment(lib, "bcrypt.lib")

/* ============================================================================
 * SHA-1
 *
 * Xbox SHA-1 is standard FIPS 180-1 SHA-1. We use BCrypt for correctness.
 * The XBOX_SHA_CONTEXT is our own structure (defined in kernel.h).
 * We store the BCrypt hash handle inside it.
 * ============================================================================ */

/* We use a wrapper since XBOX_SHA_CONTEXT may not be large enough for
 * BCrypt's internal state. Store BCrypt handles in a separate mapping. */

typedef struct _SHA_INTERNAL {
    BCRYPT_ALG_HANDLE  hAlg;
    BCRYPT_HASH_HANDLE hHash;
    UCHAR              hashObject[256]; /* BCrypt hash object buffer */
} SHA_INTERNAL;

/*
 * Since XBOX_SHA_CONTEXT is only 92 bytes (State[5] + Count[2] + Buffer[64]),
 * we can't fit a BCrypt handle in it. We use a simple software SHA-1 instead.
 * This also ensures byte-exact compatibility with the Xbox implementation.
 */

/* Software SHA-1 implementation - matches Xbox/FIPS exactly */

static ULONG sha1_rotate_left(ULONG value, int bits)
{
    return (value << bits) | (value >> (32 - bits));
}

static void sha1_transform(ULONG state[5], const UCHAR buffer[64])
{
    ULONG a, b, c, d, e, f, k, temp;
    ULONG w[80];
    int i;

    /* Prepare message schedule */
    for (i = 0; i < 16; i++) {
        w[i] = ((ULONG)buffer[i * 4] << 24)
             | ((ULONG)buffer[i * 4 + 1] << 16)
             | ((ULONG)buffer[i * 4 + 2] << 8)
             | ((ULONG)buffer[i * 4 + 3]);
    }
    for (i = 16; i < 80; i++) {
        w[i] = sha1_rotate_left(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];

    for (i = 0; i < 80; i++) {
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        } else if (i < 40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        } else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        } else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        temp = sha1_rotate_left(a, 5) + f + e + k + w[i];
        e = d;
        d = c;
        c = sha1_rotate_left(b, 30);
        b = a;
        a = temp;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

VOID __stdcall xbox_XcSHAInit(PXBOX_SHA_CONTEXT ShaContext)
{
    if (!ShaContext)
        return;

    ShaContext->State[0] = 0x67452301;
    ShaContext->State[1] = 0xEFCDAB89;
    ShaContext->State[2] = 0x98BADCFE;
    ShaContext->State[3] = 0x10325476;
    ShaContext->State[4] = 0xC3D2E1F0;
    ShaContext->Count[0] = 0;
    ShaContext->Count[1] = 0;
    memset(ShaContext->Buffer, 0, 64);
}

VOID __stdcall xbox_XcSHAUpdate(PXBOX_SHA_CONTEXT ShaContext, const UCHAR* Input, ULONG InputLength)
{
    ULONG i, index, part_len;

    if (!ShaContext || !Input || InputLength == 0)
        return;

    index = (ShaContext->Count[0] >> 3) & 0x3F;

    /* Update bit count */
    ShaContext->Count[0] += (InputLength << 3);
    if (ShaContext->Count[0] < (InputLength << 3))
        ShaContext->Count[1]++;
    ShaContext->Count[1] += (InputLength >> 29);

    part_len = 64 - index;

    if (InputLength >= part_len) {
        memcpy(&ShaContext->Buffer[index], Input, part_len);
        sha1_transform(ShaContext->State, ShaContext->Buffer);

        for (i = part_len; i + 63 < InputLength; i += 64) {
            sha1_transform(ShaContext->State, &Input[i]);
        }

        index = 0;
    } else {
        i = 0;
    }

    memcpy(&ShaContext->Buffer[index], &Input[i], InputLength - i);
}

VOID __stdcall xbox_XcSHAFinal(PXBOX_SHA_CONTEXT ShaContext, UCHAR* Digest)
{
    UCHAR finalcount[8];
    UCHAR pad;
    ULONG i;

    if (!ShaContext || !Digest)
        return;

    /* Store bit count (big-endian) */
    for (i = 0; i < 4; i++) {
        finalcount[i]     = (UCHAR)((ShaContext->Count[1] >> ((3 - i) * 8)) & 0xFF);
        finalcount[i + 4] = (UCHAR)((ShaContext->Count[0] >> ((3 - i) * 8)) & 0xFF);
    }

    /* Pad to 56 mod 64 */
    pad = 0x80;
    xbox_XcSHAUpdate(ShaContext, &pad, 1);
    pad = 0x00;
    while ((ShaContext->Count[0] >> 3) % 64 != 56) {
        xbox_XcSHAUpdate(ShaContext, &pad, 1);
    }

    /* Append length */
    xbox_XcSHAUpdate(ShaContext, finalcount, 8);

    /* Output digest (big-endian) */
    for (i = 0; i < 5; i++) {
        Digest[i * 4]     = (UCHAR)((ShaContext->State[i] >> 24) & 0xFF);
        Digest[i * 4 + 1] = (UCHAR)((ShaContext->State[i] >> 16) & 0xFF);
        Digest[i * 4 + 2] = (UCHAR)((ShaContext->State[i] >> 8) & 0xFF);
        Digest[i * 4 + 3] = (UCHAR)((ShaContext->State[i]) & 0xFF);
    }
}

/* ============================================================================
 * RC4 (ARC4)
 *
 * Standard RC4 stream cipher. Used for Xbox Live encryption and some
 * save game protection. Implemented in software for portability.
 * ============================================================================ */

VOID __stdcall xbox_XcRC4Key(PXBOX_RC4_CONTEXT Rc4Context, ULONG KeyLength, const UCHAR* Key)
{
    UCHAR temp;
    ULONG i;
    UCHAR j = 0;

    if (!Rc4Context || !Key || KeyLength == 0)
        return;

    /* KSA (Key-Scheduling Algorithm) */
    for (i = 0; i < 256; i++)
        Rc4Context->S[i] = (UCHAR)i;

    for (i = 0; i < 256; i++) {
        j = j + Rc4Context->S[i] + Key[i % KeyLength];
        temp = Rc4Context->S[i];
        Rc4Context->S[i] = Rc4Context->S[j];
        Rc4Context->S[j] = temp;
    }

    Rc4Context->i = 0;
    Rc4Context->j = 0;
}

VOID __stdcall xbox_XcRC4Crypt(PXBOX_RC4_CONTEXT Rc4Context, ULONG Length, UCHAR* Data)
{
    UCHAR temp;
    ULONG n;

    if (!Rc4Context || !Data || Length == 0)
        return;

    /* PRGA (Pseudo-Random Generation Algorithm) */
    for (n = 0; n < Length; n++) {
        Rc4Context->i++;
        Rc4Context->j += Rc4Context->S[Rc4Context->i];

        temp = Rc4Context->S[Rc4Context->i];
        Rc4Context->S[Rc4Context->i] = Rc4Context->S[Rc4Context->j];
        Rc4Context->S[Rc4Context->j] = temp;

        Data[n] ^= Rc4Context->S[(UCHAR)(Rc4Context->S[Rc4Context->i] + Rc4Context->S[Rc4Context->j])];
    }
}

/* ============================================================================
 * HMAC-SHA1
 *
 * Standard RFC 2104 HMAC using SHA-1. Used for save game authentication.
 * Xbox XcHMAC takes two data buffers to hash (Data1 and Data2, concatenated).
 * ============================================================================ */

VOID __stdcall xbox_XcHMAC(
    const UCHAR* Key, ULONG KeyLength,
    const UCHAR* Data1, ULONG Data1Length,
    const UCHAR* Data2, ULONG Data2Length,
    UCHAR* Digest)
{
    XBOX_SHA_CONTEXT sha;
    UCHAR key_block[64];
    UCHAR ipad[64];
    UCHAR opad[64];
    UCHAR inner_digest[20];
    ULONG i;

    if (!Key || !Digest)
        return;

    /* If key is longer than block size, hash it first */
    memset(key_block, 0, 64);
    if (KeyLength > 64) {
        xbox_XcSHAInit(&sha);
        xbox_XcSHAUpdate(&sha, Key, KeyLength);
        xbox_XcSHAFinal(&sha, key_block);
    } else {
        memcpy(key_block, Key, KeyLength);
    }

    /* Inner padding */
    for (i = 0; i < 64; i++)
        ipad[i] = key_block[i] ^ 0x36;

    /* Outer padding */
    for (i = 0; i < 64; i++)
        opad[i] = key_block[i] ^ 0x5C;

    /* Inner hash: SHA1(ipad || data1 || data2) */
    xbox_XcSHAInit(&sha);
    xbox_XcSHAUpdate(&sha, ipad, 64);
    if (Data1 && Data1Length > 0)
        xbox_XcSHAUpdate(&sha, Data1, Data1Length);
    if (Data2 && Data2Length > 0)
        xbox_XcSHAUpdate(&sha, Data2, Data2Length);
    xbox_XcSHAFinal(&sha, inner_digest);

    /* Outer hash: SHA1(opad || inner_digest) */
    xbox_XcSHAInit(&sha);
    xbox_XcSHAUpdate(&sha, opad, 64);
    xbox_XcSHAUpdate(&sha, inner_digest, 20);
    xbox_XcSHAFinal(&sha, Digest);

    /* Clean up sensitive data */
    SecureZeroMemory(key_block, sizeof(key_block));
    SecureZeroMemory(ipad, sizeof(ipad));
    SecureZeroMemory(opad, sizeof(opad));
    SecureZeroMemory(inner_digest, sizeof(inner_digest));
}

/* ============================================================================
 * Public Key Operations
 *
 * Used for Xbox Live authentication and content signing verification.
 * These are not needed for PC operation (no Xbox Live), so they're
 * stubbed to return failure/zero.
 * ============================================================================ */

ULONG __stdcall xbox_XcPKGetKeyLen(PVOID PublicKey)
{
    (void)PublicKey;
    return 0;
}

ULONG __stdcall xbox_XcPKDecPrivate(PVOID PrivateKey, PVOID Input, PVOID Output)
{
    (void)PrivateKey;
    (void)Input;
    (void)Output;
    xbox_log(XBOX_LOG_WARN, XBOX_LOG_CRYPTO, "XcPKDecPrivate: stubbed (no Xbox Live)");
    return 0; /* Failure */
}

ULONG __stdcall xbox_XcPKEncPublic(PVOID PublicKey, PVOID Input, PVOID Output)
{
    (void)PublicKey;
    (void)Input;
    (void)Output;
    xbox_log(XBOX_LOG_WARN, XBOX_LOG_CRYPTO, "XcPKEncPublic: stubbed (no Xbox Live)");
    return 0;
}

BOOLEAN __stdcall xbox_XcVerifyPKCS1Signature(PVOID Hash, PVOID PublicKey, PVOID Signature)
{
    (void)Hash;
    (void)PublicKey;
    (void)Signature;
    /* Return TRUE to bypass signature checks */
    return TRUE;
}

/* XcModExp: Result = Base^Exponent mod Modulus, little-endian ULONG arrays of ModulusLength
 * (XNET's DH: 24, Oakley group 1). Montgomery, so the modulus must be odd. */

#define MODEXP_MAX_WORDS 128

/* r = a * b * R^-1 mod m (R = 2^(32n)), m odd, minv = -m^-1 mod 2^32 */
static void mont_mul(uint32_t* r, const uint32_t* a, const uint32_t* b,
                     const uint32_t* m, uint32_t minv, ULONG n)
{
    uint32_t t[MODEXP_MAX_WORDS + 2] = {0};
    ULONG i, j;

    for (i = 0; i < n; i++) {
        uint64_t c = 0;
        uint32_t u;
        for (j = 0; j < n; j++) {
            c += (uint64_t)t[j] + (uint64_t)a[j] * b[i];
            t[j] = (uint32_t)c;
            c >>= 32;
        }
        c += t[n];
        t[n] = (uint32_t)c;
        t[n + 1] = (uint32_t)(c >> 32);

        u = t[0] * minv;
        c = ((uint64_t)t[0] + (uint64_t)u * m[0]) >> 32;
        for (j = 1; j < n; j++) {
            c += (uint64_t)t[j] + (uint64_t)u * m[j];
            t[j - 1] = (uint32_t)c;
            c >>= 32;
        }
        c += t[n];
        t[n - 1] = (uint32_t)c;
        t[n] = t[n + 1] + (uint32_t)(c >> 32);
    }

    /* t < 2m: subtract m once if t >= m */
    {
        int ge = t[n] != 0;
        if (!ge) {
            ge = 1;
            for (j = n; j-- > 0;) {
                if (t[j] != m[j]) { ge = t[j] > m[j]; break; }
            }
        }
        if (ge) {
            int64_t br = 0;
            for (j = 0; j < n; j++) {
                br += (int64_t)t[j] - m[j];
                t[j] = (uint32_t)br;
                br >>= 32;
            }
        }
    }
    memcpy(r, t, n * sizeof(uint32_t));
}

/* r = a * 2^(32n) mod m: feed a's bits then 32n zeros through r = 2r + bit mod m */
static void mont_to(uint32_t* r, const uint32_t* a, const uint32_t* m, ULONG n)
{
    ULONG bit, j;

    memset(r, 0, n * sizeof(uint32_t));
    for (bit = 0; bit < 64 * n; bit++) {
        uint32_t carry = bit < 32 * n ? (a[n - 1 - bit / 32] >> (31 - bit % 32)) & 1 : 0;
        int ge;
        for (j = 0; j < n; j++) {
            uint32_t v = r[j];
            r[j] = (v << 1) | carry;
            carry = v >> 31;
        }
        ge = carry != 0;
        if (!ge) {
            ge = 1;
            for (j = n; j-- > 0;) {
                if (r[j] != m[j]) { ge = r[j] > m[j]; break; }
            }
        }
        if (ge) {
            int64_t br = 0;
            for (j = 0; j < n; j++) {
                br += (int64_t)r[j] - m[j];
                r[j] = (uint32_t)br;
                br >>= 32;
            }
        }
    }
}

ULONG __stdcall xbox_XcModExp(PULONG Result, PULONG Base, PULONG Exponent, PULONG Modulus, ULONG ModulusLength)
{
    uint32_t base_m[MODEXP_MAX_WORDS], acc[MODEXP_MAX_WORDS], one[MODEXP_MAX_WORDS] = {0};
    uint32_t minv = 1;
    ULONG n = ModulusLength, i;
    int bit;

    if (!Result || !Base || !Exponent || !Modulus || n == 0 || n > MODEXP_MAX_WORDS || !(Modulus[0] & 1)) {
        xbox_log(XBOX_LOG_WARN, XBOX_LOG_CRYPTO, "XcModExp: unsupported (n=%u)", n);
        return 0;
    }
    for (i = 0; i < 5; i++)                      /* Newton: m^-1 mod 2^32 */
        minv *= 2 - Modulus[0] * minv;
    minv = (uint32_t)0 - minv;

    one[0] = 1;
    mont_to(base_m, (const uint32_t*)Base, (const uint32_t*)Modulus, n);
    mont_to(acc, one, (const uint32_t*)Modulus, n);
    for (i = n; i-- > 0;) {
        for (bit = 31; bit >= 0; bit--) {
            mont_mul(acc, acc, acc, (const uint32_t*)Modulus, minv, n);
            if ((Exponent[i] >> bit) & 1)
                mont_mul(acc, acc, base_m, (const uint32_t*)Modulus, minv, n);
        }
    }
    mont_mul((uint32_t*)Result, acc, one, (const uint32_t*)Modulus, minv, n);
    return TRUE;
}

/* DES/3DES EDE (FIPS 46-3): cipher 0 = DES, 1 = 3DES; Operation 1 = encrypt. The key table
 * is 16 subkeys per DES (384 bytes for 3DES), the size of the buffers XONLINE passes. */

static const uint8_t des_ip[64] = {
    58,50,42,34,26,18,10,2, 60,52,44,36,28,20,12,4, 62,54,46,38,30,22,14,6, 64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,  59,51,43,35,27,19,11,3, 61,53,45,37,29,21,13,5, 63,55,47,39,31,23,15,7 };
static const uint8_t des_fp[64] = {
    40,8,48,16,56,24,64,32, 39,7,47,15,55,23,63,31, 38,6,46,14,54,22,62,30, 37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28, 35,3,43,11,51,19,59,27, 34,2,42,10,50,18,58,26, 33,1,41,9,49,17,57,25 };
static const uint8_t des_e[48] = {
    32,1,2,3,4,5, 4,5,6,7,8,9, 8,9,10,11,12,13, 12,13,14,15,16,17,
    16,17,18,19,20,21, 20,21,22,23,24,25, 24,25,26,27,28,29, 28,29,30,31,32,1 };
static const uint8_t des_p[32] = {
    16,7,20,21,29,12,28,17, 1,15,23,26,5,18,31,10, 2,8,24,14,32,27,3,9, 19,13,30,6,22,11,4,25 };
static const uint8_t des_pc1[56] = {
    57,49,41,33,25,17,9, 1,58,50,42,34,26,18, 10,2,59,51,43,35,27, 19,11,3,60,52,44,36,
    63,55,47,39,31,23,15, 7,62,54,46,38,30,22, 14,6,61,53,45,37,29, 21,13,5,28,20,12,4 };
static const uint8_t des_pc2[48] = {
    14,17,11,24,1,5, 3,28,15,6,21,10, 23,19,12,4,26,8, 16,7,27,20,13,2,
    41,52,31,37,47,55, 30,40,51,45,33,48, 44,49,39,56,34,53, 46,42,50,36,29,32 };
static const uint8_t des_shifts[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
static const uint8_t des_sbox[8][64] = {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7, 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
     4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0, 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
    {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10, 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
     0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15, 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
    {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8, 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
     13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7, 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
    {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15, 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
     10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4, 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
    {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9, 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
     4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14, 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
    {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11, 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
     9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6, 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
    {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1, 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
     1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2, 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
    {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7, 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
     7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8, 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11} };

/* Bit permutation: output bit i (MSB first, of out_bits) = input bit tbl[i] (1-based of in_bits) */
static uint64_t des_permute(uint64_t in, const uint8_t* tbl, int out_bits, int in_bits)
{
    uint64_t out = 0;
    int i;
    for (i = 0; i < out_bits; i++)
        out = (out << 1) | ((in >> (in_bits - tbl[i])) & 1);
    return out;
}

static void des_key_schedule(uint64_t sub[16], const UCHAR* key)
{
    uint64_t k = 0, cd;
    uint32_t c, dd;
    int i;
    for (i = 0; i < 8; i++)
        k = (k << 8) | key[i];
    cd = des_permute(k, des_pc1, 56, 64);
    c = (uint32_t)(cd >> 28) & 0x0FFFFFFF;
    dd = (uint32_t)cd & 0x0FFFFFFF;
    for (i = 0; i < 16; i++) {
        int s = des_shifts[i];
        c = ((c << s) | (c >> (28 - s))) & 0x0FFFFFFF;
        dd = ((dd << s) | (dd >> (28 - s))) & 0x0FFFFFFF;
        sub[i] = des_permute(((uint64_t)c << 28) | dd, des_pc2, 48, 56);
    }
}

static void des_block(const uint64_t sub[16], UCHAR* out, const UCHAR* in, int encrypt)
{
    uint64_t b = 0;
    uint32_t l, r;
    int i, j;
    for (i = 0; i < 8; i++)
        b = (b << 8) | in[i];
    b = des_permute(b, des_ip, 64, 64);
    l = (uint32_t)(b >> 32);
    r = (uint32_t)b;
    for (i = 0; i < 16; i++) {
        uint64_t x = des_permute(r, des_e, 48, 32) ^ sub[encrypt ? i : 15 - i];
        uint32_t f = 0, t;
        for (j = 0; j < 8; j++) {
            int six = (int)(x >> (42 - 6 * j)) & 0x3F;
            int row = ((six & 0x20) >> 4) | (six & 1);
            f = (f << 4) | des_sbox[j][row * 16 + ((six >> 1) & 0xF)];
        }
        f = (uint32_t)des_permute(f, des_p, 32, 32);
        t = l ^ f;
        l = r;
        r = t;
    }
    b = des_permute(((uint64_t)r << 32) | l, des_fp, 64, 64);
    for (i = 7; i >= 0; i--) {
        out[i] = (UCHAR)b;
        b >>= 8;
    }
}

/* One block with DES or 3DES EDE (encrypt K1,K2,K3 / decrypt K3,K2,K1). */
static void xc_block(ULONG cipher, const uint64_t* table, UCHAR* out, const UCHAR* in, int encrypt)
{
    if (cipher == 0) {
        des_block(table, out, in, encrypt);
    } else if (encrypt) {
        des_block(table, out, in, 1);
        des_block(table + 16, out, out, 0);
        des_block(table + 32, out, out, 1);
    } else {
        des_block(table + 32, out, in, 0);
        des_block(table + 16, out, out, 1);
        des_block(table, out, out, 0);
    }
}

VOID __stdcall xbox_XcDESKeyParity(PUCHAR Key, ULONG KeyLength)
{
    ULONG i;
    for (i = 0; Key && i < KeyLength; i++) {
        UCHAR v = Key[i] & 0xFE, ones = 0, b;
        for (b = v; b; b >>= 1)
            ones += b & 1;
        Key[i] = v | ((ones & 1) ? 0 : 1);       /* odd parity */
    }
}

VOID __stdcall xbox_XcKeyTable(ULONG CipherSelect, PVOID KeyTable, const UCHAR* Key)
{
    uint64_t* table = (uint64_t*)KeyTable;
    if (!table || !Key)
        return;
    des_key_schedule(table, Key);
    if (CipherSelect != 0) {
        des_key_schedule(table + 16, Key + 8);
        des_key_schedule(table + 32, Key + 16);
    }
}

VOID __stdcall xbox_XcBlockCrypt(ULONG CipherSelect, PVOID Output, PVOID Input, PVOID KeyTable, ULONG Operation)
{
    if (Output && Input && KeyTable)
        xc_block(CipherSelect, (const uint64_t*)KeyTable, (UCHAR*)Output, (const UCHAR*)Input, Operation != 0);
}

/* CBC over whole 8-byte blocks; the feedback vector is updated for chaining. */
VOID __stdcall xbox_XcBlockCryptCBC(
    ULONG CipherSelect, ULONG OutputLength, PVOID Output, PVOID Input,
    PVOID KeyTable, ULONG Operation, PVOID FeedbackVector)
{
    UCHAR* out = (UCHAR*)Output;
    const UCHAR* in = (const UCHAR*)Input;
    UCHAR* iv = (UCHAR*)FeedbackVector;
    ULONG off;
    int i;

    if (!out || !in || !KeyTable || !iv)
        return;
    for (off = 0; off + 8 <= OutputLength; off += 8) {
        UCHAR blk[8];
        if (Operation) {
            for (i = 0; i < 8; i++)
                blk[i] = in[off + i] ^ iv[i];
            xc_block(CipherSelect, (const uint64_t*)KeyTable, out + off, blk, 1);
            memcpy(iv, out + off, 8);
        } else {
            UCHAR next_iv[8];
            memcpy(next_iv, in + off, 8);
            xc_block(CipherSelect, (const uint64_t*)KeyTable, blk, in + off, 0);
            for (i = 0; i < 8; i++)
                out[off + i] = blk[i] ^ iv[i];
            memcpy(iv, next_iv, 8);
        }
    }
}

VOID __stdcall xbox_XcCryptService(ULONG Operation, PVOID Param)
{
    (void)Operation;
    (void)Param;
}

VOID __stdcall xbox_XcUpdateCrypto(PVOID Param1, PVOID Param2)
{
    (void)Param1;
    (void)Param2;
}
