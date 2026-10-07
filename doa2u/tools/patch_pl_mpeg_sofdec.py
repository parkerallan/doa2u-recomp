"""
Patch pl_mpeg.h for Sofdec (TMPGEnc XS) MPEG-1: DC sizes 9-11, 11-bit DC on TMPGEXS streams,
no per-picture compaction of fixed memory buffers. Idempotent.
"""
import sys

LUM_OLD = "\t{       0,    8}, {      -1,    0},  //   8: 1111 11x\n};"
LUM_NEW = ("\t{       0,    8}, {  9 << 1,    0},  //   8: 1111 11x\n"
           "\t{       0,    9}, { 10 << 1,    0},  //   9: 1111 111x\n"
           "\t{       0,   10}, {       0,   11},  //  10: 1111 1111x\n};")
CHR_OLD = "\t{       0,    8}, {      -1,    0},  //   8: 1111 111x\n};"
CHR_NEW = ("\t{       0,    8}, {  9 << 1,    0},  //   8: 1111 111x\n"
           "\t{       0,    9}, { 10 << 1,    0},  //   9: 1111 1111x\n"
           "\t{       0,   10}, {       0,   11},  //  10: 1111 1111 1x\n};")

SCAN_FN = '''
// Sofdec/TMPGEnc XS streams tag user data with "\\0TMPGEXS\\0" and code
// intra DC with 11-bit precision while claiming MPEG-1.
static void plm_video_scan_tmpgexs(plm_video_t *self) {
	plm_buffer_t *b = self->buffer;
	size_t start = b->bit_index >> 3;
	size_t end = start + 256;
	if (end > b->length) {
		end = b->length;
	}
	for (size_t i = start; i + 9 <= end; i++) {
		if (memcmp(b->bytes + i, "\\0TMPGEXS\\0", 9) == 0) {
			self->dc_precision = 3;
			return;
		}
	}
}

int plm_video_decode_sequence_header(plm_video_t *self) {'''


def sub(s, old, new, count=1):
    n = s.count(old)
    assert n == count, (old[:60], n)
    return s.replace(old, new)


def patch(path):
    s = open(path, encoding="utf-8").read()
    if "plm_video_scan_tmpgexs" in s:
        print("already patched", path)
        return
    s = sub(s, LUM_OLD, LUM_NEW)
    s = sub(s, CHR_OLD, CHR_NEW)
    s = sub(s, "\tint dc_predictor[3];\n", "\tint dc_predictor[3];\n\tint dc_precision;\n")
    s = sub(s, "int plm_video_decode_sequence_header(plm_video_t *self) {", SCAN_FN)
    s = sub(s, "\tself->has_sequence_header = TRUE;\n",
            "\tself->has_sequence_header = TRUE;\n\tplm_video_scan_tmpgexs(self);\n")
    for i in range(3):
        s = sub(s, "self->dc_predictor[%d] = 128;" % i,
                "self->dc_predictor[%d] = 128 << self->dc_precision;" % i, 3)
    s = sub(s, "\t\tself->block_data[0] <<= (3 + 5);",
            "\t\tself->block_data[0] <<= (3 - self->dc_precision + 5);")
    # Fixed memory buffers: plm_video_decode compacted (memmoved) the whole
    # unread stream once per picture -- ~60 ms a frame on doa2_op.sfd.
    s = sub(s, "\t\tplm_buffer_discard_read_bytes(self->buffer);\n\t\t\n\t\tplm_video_decode_picture(self);",
            "\t\tif (self->buffer->discard_read_bytes) {\n"
            "\t\t\tplm_buffer_discard_read_bytes(self->buffer);\n"
            "\t\t}\n\t\t\n\t\tplm_video_decode_picture(self);")
    open(path, "w", encoding="utf-8", newline="").write(s)
    print("patched", path)


for p in sys.argv[1:]:
    patch(p)
