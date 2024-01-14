#include <platform/config.h>

#ifdef SHRIMP_WII

#include <window.h>
#include <platform/wii/wii_texture.h>
#include <log.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/tpl.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define DEFAULT_FIFO_SIZE (256 * 1024)

typedef struct Window {
    GXRModeObj* video_settings;

    void* framebuffers[2];
    unsigned int framebuffer_index;
} Window;

void wiiwindow_setup_video(Window* window);
void wiiwindow_setup_gx(Window* window);
void* wiiwindow_setup_fifo();
void wiiwindow_setup_gx_parameters(Window* window);
void wiiwindow_set_vertex_attributes();
void wiiwindow_setup_textures();
void wiiwindow_setup_projection();
void wiiwindow_draw_texture(Texture* texture, AABB* dest, float* tex_coords);

Window* window_new(const char* title, int width, int height) {
    Window* window = (Window*)malloc(sizeof(Window));

    VIDEO_Init();

    window->video_settings = VIDEO_GetPreferredMode(NULL);

    // allocate two framebuffers for double buffering
    window->framebuffers[0] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(window->video_settings));
    window->framebuffers[1] = MEM_K0_TO_K1(SYS_AllocateFramebuffer(window->video_settings));
    window->framebuffer_index = 0;

    wiiwindow_setup_video(window);
    wiiwindow_setup_gx(window);
    
    return window;
}

void window_delete(Window* window) {
    free(window);
}

void window_clear(Window* window) {
    GX_SetViewport(0, 0, window->video_settings->fbWidth, window->video_settings->efbHeight, 0, 1);
    GX_InvVtxCache();
    GX_InvalidateTexAll();

    // set the projection matrix
    Mtx modelview;
    guMtxIdentity(modelview);
    GX_LoadPosMtxImm(modelview, GX_PNMTX0);

    GX_SetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	GX_SetTevOp(GX_TEVSTAGE0, GX_REPLACE);
}

void window_present(Window* window) {
    GX_DrawDone();

    GX_SetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    GX_SetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_COPY);
    GX_SetAlphaUpdate(GX_TRUE);
    GX_SetColorUpdate(GX_TRUE);
    GX_CopyDisp(window->framebuffers[window->framebuffer_index], GX_TRUE);

    VIDEO_SetNextFramebuffer(window->framebuffers[window->framebuffer_index]);

    VIDEO_Flush();
    VIDEO_WaitVSync();
    
    // flip framebuffer
    window->framebuffer_index ^= 1;
}

void window_render_texture(Window* window, Texture* texture, AABB* src, AABB* dest) {
    float tex_coords[] = {
    	0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    wiiwindow_draw_texture(texture, dest, tex_coords);
}

void window_render_full_texture(Window* window, Texture* texture, AABB* dest) {
    float tex_coords[] = {
    	0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };

    wiiwindow_draw_texture(texture, dest, tex_coords);
}

void window_render_color(Window* window, Color color, AABB* dest) {
    GX_ClearVtxDesc();
    GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
    GX_SetVtxDesc(GX_VA_CLR0, GX_DIRECT);

    GX_Begin(GX_QUADS, GX_VTXFMT0, 4);
    
    GX_Position2f32(dest->x, dest->y);
    GX_Color4u8(color.r, color.g, color.b, color.a);

    GX_Position2f32(dest->x + dest->width, dest->y);
    GX_Color4u8(color.r, color.g, color.b, color.a);

    GX_Position2f32(dest->x + dest->width, dest->y + dest->height);
    GX_Color4u8(color.r, color.g, color.b, color.a);

    GX_Position2f32(dest->x, dest->y + dest->height);
    GX_Color4u8(color.r, color.g, color.b, color.a);
    
    GX_End();
}

void wiiwindow_setup_video(Window* window) {
    VIDEO_Configure(window->video_settings);
    VIDEO_SetNextFramebuffer(window->framebuffers[window->framebuffer_index]);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();

    if (window->video_settings->viTVMode & VI_NON_INTERLACE)
        VIDEO_WaitVSync();

    window->framebuffer_index ^= 1;
}

void wiiwindow_setup_gx(Window* window) {
    void* fifo = wiiwindow_setup_fifo();
    GX_Init(fifo, DEFAULT_FIFO_SIZE);

    // clear the screen
    GXColor background = { 127, 127, 127, 255 };
    GX_SetCopyClear(background, 0x00FFFFFF);

    wiiwindow_setup_gx_parameters(window);
    wiiwindow_set_vertex_attributes();
    wiiwindow_setup_textures();
    wiiwindow_setup_projection();
}

void* wiiwindow_setup_fifo() {
    void* fifo = MEM_K0_TO_K1(memalign(32, DEFAULT_FIFO_SIZE));
    memset(fifo, 0, DEFAULT_FIFO_SIZE);
    return fifo;
}

void wiiwindow_setup_gx_parameters(Window* window) {
    GX_SetViewport(0, 0, window->video_settings->fbWidth, window->video_settings->efbHeight, 0, 1);
    float y_scale = GX_GetYScaleFactor(window->video_settings->efbHeight, window->video_settings->xfbHeight);
    float xfbHeight = GX_SetDispCopyYScale(y_scale);
    GX_SetScissor(0, 0, window->video_settings->fbWidth, window->video_settings->efbHeight);
    GX_SetDispCopySrc(0, 0, window->video_settings->fbWidth, window->video_settings->efbHeight);
    GX_SetDispCopyDst(window->video_settings->fbWidth, xfbHeight);
    GX_SetCopyFilter(window->video_settings->aa, window->video_settings->sample_pattern, GX_TRUE, window->video_settings->vfilter);
    GX_SetFieldMode(window->video_settings->field_rendering, (window->video_settings->viHeight == 2 * window->video_settings->xfbHeight) ? GX_ENABLE : GX_DISABLE);

    if (window->video_settings->aa)
        GX_SetPixelFmt(GX_PF_RGB565_Z16, GX_ZC_LINEAR);
    else
        GX_SetPixelFmt(GX_PF_RGB8_Z24, GX_ZC_LINEAR);

    GX_SetCullMode(GX_CULL_NONE);
    GX_CopyDisp(window->framebuffers[window->framebuffer_index], GX_TRUE);
    GX_SetDispCopyGamma(GX_GM_1_0);
}

void wiiwindow_set_vertex_attributes() {
    // color attributes
    GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XY, GX_F32, 0);
    GX_SetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);

    // texture atributes
    GX_SetVtxAttrFmt(GX_VTXFMT1, GX_VA_POS, GX_POS_XY, GX_F32, 0);
	GX_SetVtxAttrFmt(GX_VTXFMT1, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
}

void wiiwindow_setup_textures() {
    GX_SetNumChans(1);
	GX_SetNumTexGens(1);
    GX_SetTexCoordGen(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);

    GX_InvalidateTexAll();
}

void wiiwindow_setup_projection() {
    Mtx44 perspective;
    guOrtho(perspective,0,479,0,639,0,300);
	GX_LoadProjectionMtx(perspective, GX_ORTHOGRAPHIC);
}

void wiiwindow_draw_texture(Texture* texture, AABB* dest, float* tex_coords) {
    GX_ClearVtxDesc();
    GX_SetVtxDesc(GX_VA_POS, GX_DIRECT);
    GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

    GXTexObj texture_object = wiitexture_get_texture_object(texture);
    GX_LoadTexObj(&texture_object, GX_TEXMAP0);
    
    GX_Begin(GX_QUADS, GX_VTXFMT1, 4);

    GX_Position2f32(dest->x, dest->y);
    GX_TexCoord2f32(tex_coords[0], tex_coords[1]);

    GX_Position2f32(dest->x + dest->width - 1, dest->y);
    GX_TexCoord2f32(tex_coords[2], tex_coords[3]);

    GX_Position2f32(dest->x + dest->width - 1, dest->y + dest->height - 1);
    GX_TexCoord2f32(tex_coords[4], tex_coords[5]);

    GX_Position2f32(dest->x, dest->y + dest->height - 1);
    GX_TexCoord2f32(tex_coords[6], tex_coords[7]);

    GX_End();
}

#endif
