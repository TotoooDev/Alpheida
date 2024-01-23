#ifndef GL_LOADER_H
#define GL_LOADER_H

#include <engine/platform/config.h>

#if defined(SHRIMP_LINUX)
    #include <engine/platform/linux/glad/glad.h>
#elif defined(SHRIMP_SWITCH)
    #include <glad/glad.h>
#endif

void glloader_init_gl();

#endif
