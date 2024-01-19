#include <engine/graphics/renderer.h>
#include <engine/graphics/opengl/renderer.h>
#include <engine/graphics/opengl/shader.h>
#include <engine/graphics/opengl/texture.h>
#include <engine/graphics/config.h>
#include <engine/event.h>
#include <engine/log.h>
#include <engine/cglm/cglm.h>
#include <engine/glad/glad.h>
#include <stdlib.h>

typedef struct Renderer {
    Shader* shader_color;
    Shader* shader_texture;

    mat4 matrix_view;
    mat4 matrix_projection;

    u32 rect_vao;
    u32 rect_ebo;
} Renderer;

void renderer_on_event(void* e, EventType event_type, void* user_pointer) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    if (event_type != EVENT_TYPE_WINDOW_RESIZED)
        return;

    Renderer* renderer = (Renderer*)user_pointer;
    WindowResizedEvent* event = (WindowResizedEvent*)e;

    glViewport(0, 0, event->width, event->height);
    glm_ortho(0.0f, event->width, 0.0f, event->height, 0.0f, 100.0f, renderer->matrix_projection);
#endif
}

void renderer_setup_vao(Renderer* renderer) {
#ifdef SHRIMP_GRAPHICS_OPENGL
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
#endif
}

void renderer_set_matrices(Renderer* renderer, Shader* shader, mat4 model) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    shader_bind(shader);
    shader_set_mat4(shader, model, "u_model");
    shader_set_mat4(shader, renderer->matrix_view, "u_view");
    shader_set_mat4(shader, renderer->matrix_projection, "u_projection");
#endif
}

Renderer* renderer_new() {
#ifdef SHRIMP_GRAPHICS_OPENGL
    // initialize glad
    renderer_init_glad();

    Renderer* renderer = (Renderer*)malloc(sizeof(Renderer));

    renderer->shader_color = shader_new(color_vertex_shader_source, color_fragment_shader_source);
    renderer->shader_texture = shader_new(texture_vertex_shader_source, texture_fragment_shader_source);
    renderer_setup_vao(renderer);

    glm_ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.0f, 100.0f, renderer->matrix_projection);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

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
    glm_mat4_copy(view, renderer->matrix_view);
#endif
}

void renderer_render_texture(Renderer* renderer, Texture* texture, vec2 pos, vec2 scale, f32 angle) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    vec3 pos_3 = { pos[0], pos[1], 0.0f };
    vec3 scale_3 = { scale[0], scale[1], 0.0f };
    vec3 rotation_axis = { 0.0f, 0.0f, 1.0f };

    mat4 model;
    glm_mat4_identity(model);
    // glm_rotate(model, angle, rotation_axis);
    glm_translate(model, pos_3);
    glm_scale(model, scale_3);

    renderer_set_matrices(renderer, renderer->shader_texture, model);

    texture_bind(texture);
    shader_set_i32(renderer->shader_texture, 0, "u_texture");

    glBindVertexArray(renderer->rect_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->rect_ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#endif
}

void renderer_render_color(Renderer* renderer, Color color, vec2 pos, vec2 scale, f32 angle) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    vec3 pos_3 = { pos[0], pos[1], 0.0f };
    vec3 scale_3 = { scale[0], scale[1], 0.0f };
    vec3 rotation_axis = { 0.0f, 0.0f, 1.0f };

    mat4 model;
    glm_mat4_identity(model);
    glm_rotate(model, angle, rotation_axis);
    glm_translate(model, pos_3);
    glm_scale(model, scale_3);

    renderer_set_matrices(renderer, renderer->shader_color, model);
    shader_set_color(renderer->shader_color, color, "u_color");

    glBindVertexArray(renderer->rect_vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer->rect_ebo);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
#endif
}
