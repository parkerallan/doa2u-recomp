/*
 * Stubs for burnout3 game-specific symbols referenced by the SHARED nv2a sources
 * (nv2a_pgraph_d3d11.c, nv2a_pb_replay.c), which were written for Burnout 3.
 *
 * DOA3 has neither burnout's RenderWare TXD texture dictionary nor its frontend
 * menu / captured menu push-buffer system, so these are inert:
 *   - no global textures: g_textures_loaded = 0, txd_find() -> NULL
 *     (g_global_txd is only read when g_textures_loaded != 0, and txd_find never
 *      dereferences it, so a zeroed buffer of ample size is sufficient)
 *   - no captured menu push buffer: fe_menu_get_pb_state() -> 0, g_fe_cursor = 0
 *
 * Necessary deviation: the NV2A->D3D11 translator is shared from burnout but its
 * burnout-texture/menu integration hooks don't apply to DOA3. (Mirrors burnout's
 * structure; these symbols would be provided by burnout's txd_loader.c/fe_menu.c.)
 */

unsigned char g_global_txd[131072];   /* opaque storage for burnout's TXD_Dict */
int g_textures_loaded = 0;
int g_fe_cursor = 0;

void *txd_find(const void *dict, const char *name)
{
    (void)dict; (void)name;
    return 0;   /* IDirect3DTexture8* — no global textures in DOA3 */
}

int fe_menu_get_pb_state(void)
{
    return 0;   /* no captured menu push-buffer replay for DOA3 */
}
