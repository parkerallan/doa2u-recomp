"""Extract an XDVDFS (xiso) image. Usage: extract_xiso.py <image.iso> <outdir> [--list]"""
import os, struct, sys

SECTOR = 2048

def main():
    iso, out = sys.argv[1], sys.argv[2]
    list_only = "--list" in sys.argv
    f = open(iso, "rb")
    base = None
    for b in (0, 0x18300000, 0xFD90000):
        f.seek(b + 32 * SECTOR)
        if f.read(20) == b"MICROSOFT*XBOX*MEDIA":
            base = b
            break
    if base is None:
        sys.exit("no XDVDFS volume descriptor")
    root_sec, root_size = struct.unpack("<II", f.read(8))
    total = 0

    def walk(sec, size, path):
        nonlocal total
        f.seek(base + sec * SECTOR)
        data = f.read(size)
        seen = set()
        stack = [0]
        while stack:
            off = stack.pop()
            if off in seen or off + 14 > len(data):
                continue
            seen.add(off)
            l, r, s, sz, attr, nlen = struct.unpack_from("<HHIIBB", data, off)
            if l == 0xFFFF:
                continue
            name = data[off + 14: off + 14 + nlen].decode("latin-1")
            if l: stack.append(l * 4)
            if r: stack.append(r * 4)
            p = os.path.join(path, name)
            if attr & 0x10:
                if not list_only:
                    os.makedirs(os.path.join(out, p), exist_ok=True)
                if sz:
                    walk(s, sz, p)
            else:
                total += sz
                print(f"{sz:12d}  {p}")
                if list_only:
                    continue
                dst = os.path.join(out, p)
                os.makedirs(os.path.dirname(dst) or out, exist_ok=True)
                f.seek(base + s * SECTOR)
                with open(dst, "wb") as o:
                    left = sz
                    while left:
                        chunk = f.read(min(left, 1 << 24))
                        o.write(chunk)
                        left -= len(chunk)

    walk(root_sec, root_size, "")
    print(f"total {total} bytes")

main()
