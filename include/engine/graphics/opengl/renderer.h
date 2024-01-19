#include <engine/graphics/config.h>
#ifdef SHRIMP_GRAPHICS_OPENGL

#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

/**
 * Initilialize GLAD for the correct platform.
 * @note This is defined in a platform-specific file.
*/
void renderer_init_glad();

extern const char* color_vertex_shader_source;
extern const char* color_fragment_shader_source;
extern const char* texture_vertex_shader_source;
extern const char* texture_fragment_shader_source;

#endif

#endif
