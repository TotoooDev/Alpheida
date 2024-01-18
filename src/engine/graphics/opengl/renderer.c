#include <engine/graphics/renderer.h>
#include <engine/graphics/opengl/shader.h>
#include <engine/graphics/config.h>
#include <engine/log.h>
#include <engine/cglm/cglm.h>
#include <GL/glew.h>
#include <stdlib.h>

#include <engine/graphics/opengl/shaders/color_vertex.h>
#include <engine/graphics/opengl/shaders/color_fragment.h>
#include <engine/graphics/opengl/shaders/texture_vertex.h>
#include <engine/graphics/opengl/shaders/texture_fragment.h>

typedef struct Renderer {
    Shader* shader_color;
    Shader* shader_texture;

    mat4 view_matrix;

    u32 rect_vao;
    u32 rect_ebo;
} Renderer;

void renderer_setup_vao(Renderer* renderer) {
    float vertices[] = {
        // positions          // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // top left 
    };
    
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    
    u32 vbo;

    glGenVertexArrays(1, &renderer->rect_vao);
    glGenBuffers(1, &renderer->rect_ebo);
    glGenBuffers(1, &vbo);

    glBindVertexArray(renderer->rect_vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->rect_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

Renderer* renderer_new() {
#ifdef SHRIMP_GRAPHICS_OPENGL
    // initialize glew
    GLenum result = glewInit();
    log_assert(result == GLEW_OK, "failed to initialize glew! glew error: %s\n", glewGetErrorString(result));

    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    renderer->shader_color = shader_new(color_vertex_shader_source, color_fragment_shader_source);
    renderer->shader_texture = shader_new(texture_vertex_shader_source, texture_fragment_shader_source);
    renderer_setup_vao(renderer);

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

void renderer_clear(Renderer* renderer, Color color) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
#endif
}

void renderer_set_camera(Renderer* renderer, Camera cam) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    mat4 view;
    camera_get_view_matrix(cam, view);
    glm_mat4_copy(view, renderer->view_matrix);
#endif
}

void renderer_render_texture(Renderer* renderer, Texture* texture, AABB* src, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL

#endif
}

void renderer_render_full_texture(Renderer* renderer, Texture* texture, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    
#endif
}

void renderer_render_color(Renderer* renderer, Color color, AABB* dest) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    mat4 model, projection;
    glm_mat4_identity(model);
    glm_mat4_identity(projection);
    
    vec3 scale = { 100.0f, 100.0f, 0.0f };
    glm_scale(model, scale);
    glm_ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.0f, 100.0f, projection);

    shader_bind(renderer->shader_color);
    shader_set_mat4(renderer->shader_color, model, "u_model");
    shader_set_mat4(renderer->shader_color, renderer->view_matrix, "u_view");
    shader_set_mat4(renderer->shader_color, projection, "u_projection");
    shader_set_color(renderer->shader_color, color, "u_color");

    glBindVertexArray(renderer->rect_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->rect_ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#endif
}
