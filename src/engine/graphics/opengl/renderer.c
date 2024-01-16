#include <engine/graphics/renderer.h>
#include <engine/graphics/opengl/shader.h>
#include <engine/graphics/config.h>
#include <engine/log.h>
#include <GL/glew.h>
#include <stdlib.h>

#include <engine/graphics/opengl/shaders/color_vertex.h>
#include <engine/graphics/opengl/shaders/color_fragment.h>
#include <engine/graphics/opengl/shaders/texture_vertex.h>
#include <engine/graphics/opengl/shaders/texture_fragment.h>

typedef struct Renderer {
    Shader* shader_color;
    Shader* shader_texture;
} Renderer;

Renderer* renderer_new() {
#ifdef SHRIMP_GRAPHICS_OPENGL
    // initialize glew
    GLenum result = glewInit();
    log_assert(result == GLEW_OK, "failed to initialize glew! glew error: %s\n", glewGetErrorString(result));

    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    renderer->shader_color = shader_new(color_vertex_shader_source, color_fragment_shader_source);
    renderer->shader_texture = shader_new(texture_vertex_shader_source, texture_fragment_shader_source);

    return renderer;
#endif
}

void renderer_delete(Renderer* renderer) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    shader_delete(renderer->shader_color);
    shader_delete(renderer->shader_texture);
    free(renderer);
#endif
}

void renderer_clear(Color color) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
#endif
}

void renderer_render_texture(Texture* texture, AABB* src, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL

#endif
}

void renderer_render_full_texture(Texture* texture, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL

#endif
}

void renderer_render_color(Color color, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL

#endif
}

