/* Rebuilds the title update's doa2.xbe from the disc DOA2.xbe and the patch that
 * ships next to the exe (format: tools/xbe_patch.py). */
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniz.h"
#include "xbe_patch.h"

#define PATCH_MAGIC "DOA2UPCH"
#define PATCH_HEAD  40

static uint8_t *read_file(const WCHAR *path, size_t *size)
{
    FILE *f = _wfopen(path, L"rb");
    long n;
    uint8_t *data;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    data = n > 0 ? malloc((size_t)n) : NULL;
    if (data && fread(data, 1, (size_t)n, f) != (size_t)n) { free(data); data = NULL; }
    fclose(f);
    *size = data ? (size_t)n : 0;
    return data;
}

static int read_varint(const uint8_t *buf, size_t len, size_t *pos, uint64_t *out)
{
    uint64_t n = 0;
    int shift = 0;
    while (*pos < len && shift < 64) {
        uint8_t b = buf[(*pos)++];
        n |= (uint64_t)(b & 0x7F) << shift;
        if (!(b & 0x80)) { *out = n; return 1; }
        shift += 7;
    }
    return 0;
}

static uint32_t rd32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

int doa2u_xbe_patch_apply(const WCHAR *src_path, const WCHAR *patch_path, const WCHAR *dst_path,
                          char *err, size_t errlen)
{
    size_t src_len = 0, patch_len = 0, pos = 0, add_pos, out_len = 0;
    uint8_t *src = read_file(src_path, &src_len), *patch = read_file(patch_path, &patch_len);
    uint8_t *body = NULL, *out = NULL;
    uint32_t dst_len, dst_crc, ops_len, add_len, zlen;
    mz_ulong body_len;
    int ok = 0;
    FILE *f;

    err[0] = 0;
    if (!patch) { snprintf(err, errlen, "patch file missing: %S", patch_path); goto done; }
    if (!src) { snprintf(err, errlen, "disc DOA2.xbe missing: %S", src_path); goto done; }
    if (patch_len < PATCH_HEAD || memcmp(patch, PATCH_MAGIC, 8) != 0 || rd32(patch + 8) != 1) {
        snprintf(err, errlen, "not a DOA2U patch file"); goto done;
    }
    if (rd32(patch + 12) != src_len || rd32(patch + 16) != (uint32_t)mz_crc32(MZ_CRC32_INIT, src, src_len)) {
        snprintf(err, errlen, "the disc DOA2.xbe does not match the patch"); goto done;
    }
    dst_len = rd32(patch + 20); dst_crc = rd32(patch + 24);
    ops_len = rd32(patch + 28); add_len = rd32(patch + 32); zlen = rd32(patch + 36);
    if ((uint64_t)PATCH_HEAD + zlen > patch_len || (uint64_t)ops_len + add_len > 0x10000000) {
        snprintf(err, errlen, "patch file is truncated"); goto done;
    }
    body_len = ops_len + add_len;
    body = malloc(body_len);
    out = malloc(dst_len);
    if (!body || !out || mz_uncompress(body, &body_len, patch + PATCH_HEAD, zlen) != MZ_OK ||
        body_len != (mz_ulong)ops_len + add_len) {
        snprintf(err, errlen, "patch data is damaged"); goto done;
    }

    add_pos = ops_len;
    while (pos < ops_len) {
        uint64_t al, cl, d;
        int64_t off;
        if (!read_varint(body, ops_len, &pos, &al) || !read_varint(body, ops_len, &pos, &cl) ||
            !read_varint(body, ops_len, &pos, &d)) break;
        if (al > add_len - (add_pos - ops_len) || al > dst_len - out_len) break;
        memcpy(out + out_len, body + add_pos, (size_t)al);
        add_pos += (size_t)al; out_len += (size_t)al;
        off = (int64_t)out_len + (int64_t)((d >> 1) ^ -(int64_t)(d & 1));
        if (off < 0 || cl > src_len - (uint64_t)off || cl > dst_len - out_len) break;
        memcpy(out + out_len, src + off, (size_t)cl);
        out_len += (size_t)cl;
    }
    if (out_len != dst_len || (uint32_t)mz_crc32(MZ_CRC32_INIT, out, out_len) != dst_crc) {
        snprintf(err, errlen, "the patched doa2.xbe failed verification"); goto done;
    }

    {   /* Create $U next to the game files and write the result. */
        WCHAR dir[MAX_PATH], *slash;
        wcscpy_s(dir, MAX_PATH, dst_path);
        slash = wcsrchr(dir, L'\\');
        if (slash) { *slash = 0; CreateDirectoryW(dir, NULL); }
    }
    f = _wfopen(dst_path, L"wb");
    if (!f || fwrite(out, 1, out_len, f) != out_len) {
        snprintf(err, errlen, "cannot write %S", dst_path);
        if (f) { fclose(f); DeleteFileW(dst_path); }
        goto done;
    }
    fclose(f);
    ok = 1;

done:
    free(out); free(body); free(src); free(patch);
    return ok;
}
