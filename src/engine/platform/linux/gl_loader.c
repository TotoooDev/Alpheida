#include <engine/platform/config.h>

#ifdef SHRIMP_LINUX

#include <engine/log.h>
#include <engine/platform/linux/glad/glad.h>
#include <SDL2/SDL.h>

void glloader_init_gl() {
    int ret = gladLoadGLLoader(SDL_GL_GetProcAddress);
    log_assert(ret != 0, "failed to init glad!\n");
}

#endif
