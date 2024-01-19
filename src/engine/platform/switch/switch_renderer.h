#include <engine/platform/config.h>
#include <engine/graphics/config.h>

#include <engine/graphics/opengl/renderer.h>
#include <engine/glad/glad.h>

void renderer_init_glad() {
#if defined(SHRIMP_GRAPHICS_OPENGL) && defined(SHRIMP_LINUX)
    gladLoadGL();
#endif
}
