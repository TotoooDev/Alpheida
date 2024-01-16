#ifndef GRAPHICS_CONFIG_H
#define GRAPHICS_CONFIG_H

#include <engine/platform/config.h>

#if defined(SHRIMP_LINUX) || defined(SHRIMP_SWITCH)
    #define SHRIMP_GRAPHICS_OPENGL
#elif defined(SHRIMP_WII)
    #define SHRIMP_GRAPHICS_GX
#endif

#endif
