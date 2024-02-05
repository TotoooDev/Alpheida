#include <engine/platform/config.h>
#ifdef SHRIMP_SWITCH

#include <engine/platform/switch/shaders/color_vertex.h>
#include <engine/platform/switch/shaders/color_fragment.h>
#include <engine/platform/switch/shaders/texture_vertex.h>
#include <engine/platform/switch/shaders/texture_fragment.h>
#include <engine/platform/switch/shaders/background_vertex.h>
#include <engine/platform/switch/shaders/background_fragment.h>

void renderer_init_glad() {
#if defined(SHRIMP_GRAPHICS_OPENGL)
    gladLoadGL();
#endif
}

#endif
