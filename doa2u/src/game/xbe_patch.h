#pragma once
#include <windows.h>
#include <stddef.h>

/* Builds dst_path (the v261 doa2.xbe) from src_path (the disc DOA2.xbe) and the patch.
 * Returns 1 on success; on failure err holds the reason. */
int doa2u_xbe_patch_apply(const WCHAR *src_path, const WCHAR *patch_path, const WCHAR *dst_path,
                          char *err, size_t errlen);
