#include <engine/platform/config.h>
#include <engine/graphics/config.h>

#include <engine/graphics/opengl/renderer.h>
#include <engine/graphics/opengl/gl_loader.h>
#include <engine/log.h>
#include <SDL2/SDL.h>

void renderer_init_glad() {
#if defined(SHRIMP_GRAPHICS_OPENGL) && defined(SHRIMP_LINUX)
    int ret = gladLoadGLLoader(SDL_GL_GetProcAddress);
    log_assert(ret != 0, "failed to init glad!\n");
#endif
}

#include <engine/platform/linux/shaders/color_vertex.h>
#include <engine/platform/linux/shaders/color_fragment.h>
#include <engine/platform/linux/shaders/texture_vertex.h>
#include <engine/platform/linux/shaders/texture_fragment.h>
