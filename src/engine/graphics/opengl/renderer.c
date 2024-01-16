#include <engine/graphics/renderer.h>
#include <engine/graphics/opengl/shader.h>
#include <engine/log.h>
#include <GL/glew.h>
#include <stdlib.h>

typedef struct Renderer {
    Shader* shader_color;
    Shader* shader_texture;
} Renderer;

Renderer* renderer_new() {
    // initialize glew
    GLenum result = glewInit();
    log_assert(result == GLEW_OK, "failed to initialize glew! glew error: %s\n", glewGetErrorString(result));

    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    renderer->shader_color = shader_new("", "");
    renderer->shader_texture = shader_new("", "");

    return renderer;
}

void renderer_delete(Renderer* renderer) {
    shader_delete(renderer->shader_color);
    shader_delete(renderer->shader_texture);
    free(renderer);
}
