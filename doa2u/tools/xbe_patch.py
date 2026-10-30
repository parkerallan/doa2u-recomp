#!/usr/bin/env python3
"""Binary delta from the disc DOA2.xbe to the title update's doa2.xbe (applied by src/game/xbe_patch.c).

  make  <source> <target> <patch>
  apply <source> <patch> <target>
"""
import struct
import sys
import zlib

MAGIC = b"DOA2UPCH"
MIN_MATCH = 8


def varint(n):
    out = bytearray()
    while True:
        b = n & 0x7F
        n >>= 7
        if n:
            out.append(b | 0x80)
        else:
            out.append(b)
            return bytes(out)


def read_varint(buf, pos):
    n = shift = 0
    while True:
        b = buf[pos]
        pos += 1
        n |= (b & 0x7F) << shift
        if not b & 0x80:
            return n, pos
        shift += 7


def zigzag(n):
    return (n << 1) ^ (n >> 63)


def unzigzag(n):
    return (n >> 1) ^ -(n & 1)


def match_len(a, s, b, j):
    e = 0
    la, lb = len(a), len(b)
    while s + e < la and j + e < lb and a[s + e] == b[j + e]:
        e += 1
    return e


def make(src, dst):
    idx = {}
    for i in range(len(src) - MIN_MATCH + 1):
        idx.setdefault(src[i:i + MIN_MATCH], i)
    ops = bytearray()
    add = bytearray()
    j = 0
    pending = 0           # add bytes not yet written as an op
    shift = 0             # src - dst offset of the last copy, tried first
    n = len(dst)
    while j < n:
        best_s, best_e = -1, 0
        s = j + shift
        if 0 <= s < len(src):
            e = match_len(src, s, dst, j)
            if e >= MIN_MATCH:
                best_s, best_e = s, e
        if best_e < 64:
            s = idx.get(dst[j:j + MIN_MATCH])
            if s is not None:
                e = match_len(src, s, dst, j)
                if e > best_e:
                    best_s, best_e = s, e
        if best_e < MIN_MATCH:
            add.append(dst[j])
            pending += 1
            j += 1
            continue
        ops += varint(pending) + varint(best_e) + varint(zigzag(best_s - j))
        pending = 0
        shift = best_s - j
        j += best_e
    ops += varint(pending) + varint(0) + varint(0)
    body = zlib.compress(bytes(ops) + bytes(add), 9)
    head = MAGIC + struct.pack("<IIIIIIII", 1, len(src), zlib.crc32(src), len(dst),
                               zlib.crc32(dst), len(ops), len(add), len(body))
    return head + body


def apply(src, patch):
    if patch[:8] != MAGIC:
        raise ValueError("not a DOA2U patch")
    ver, ssz, scrc, dsz, dcrc, ops_len, add_len, zlen = struct.unpack_from("<IIIIIIII", patch, 8)
    if ver != 1 or len(src) != ssz or zlib.crc32(src) != scrc:
        raise ValueError("source file does not match the patch")
    body = zlib.decompress(patch[40:40 + zlen])
    ops, add = body[:ops_len], body[ops_len:]
    out = bytearray()
    p = a = 0
    while p < len(ops):
        al, p = read_varint(ops, p)
        cl, p = read_varint(ops, p)
        d, p = read_varint(ops, p)
        out += add[a:a + al]
        a += al
        if cl:
            s = len(out) + unzigzag(d)
            out += src[s:s + cl]
    if len(out) != dsz or zlib.crc32(out) != dcrc:
        raise ValueError("patched file failed verification")
    return bytes(out)


def main(argv):
    if len(argv) == 4 and argv[0] == "make":
        src = open(argv[1], "rb").read()
        dst = open(argv[2], "rb").read()
        patch = make(src, dst)
        if apply(src, patch) != dst:
            raise SystemExit("self-check failed")
        open(argv[3], "wb").write(patch)
        print(f"{argv[3]}: {len(patch)} bytes")
    elif len(argv) == 4 and argv[0] == "apply":
        src = open(argv[1], "rb").read()
        patch = open(argv[2], "rb").read()
        open(argv[3], "wb").write(apply(src, patch))
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
