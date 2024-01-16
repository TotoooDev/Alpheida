#include <engine/graphics/opengl/shader.h>
#include <engine/graphics/config.h>
#include <engine/log.h>
#include <GL/glew.h>
#include <stdlib.h>

typedef struct Shader {
    u32 id;
} Shader;

void shader_compile(Shader* shader, const char* vertex_source, const char* fragment_source) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    u32 success;
    char info_log[1024];

    // vertex shader
    u32 vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_source, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, sizeof(info_log), NULL, info_log);
        log_assert(false, "failed to compile vertex shader! opengl error: %s\n", info_log);
    }

    // fragment shader
    u32 fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, sizeof(info_log), NULL, info_log);
        log_assert(false, "failed to compile fragment shader! opengl error: %s\n", info_log);
    }

    // shader program
    shader->id = glCreateProgram();
    glAttachShader(shader->id, vertex_shader);
    glAttachShader(shader->id, fragment_shader);
    glLinkProgram(shader->id);

    glGetShaderiv(shader->id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader->id, sizeof(info_log), NULL, info_log);
        log_assert(false, "failed to link shader! opengl error: %s\n", info_log);
    }

    // delete the shaders
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
#endif
}

Shader* shader_new(const char* vertex_source, const char* fragment_source) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    Shader* shader = (Shader*)malloc(sizeof(Shader));
    shader_compile(shader, vertex_source, fragment_source);
    return shader;
#endif
}

void shader_delete(Shader* shader) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glDeleteProgram(shader->id);
    free(shader);
#endif
}

void shader_bind(Shader* shader) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glUseProgram(shader->id);
#endif
}

u32 shader_get_id(Shader* shader) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    return shader->id;
#endif
}

void shader_set_i32(Shader* shader, i32 value, const char* name) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glUniform1i(glGetUniformLocation(shader->id, name), value);
#endif
}

void shader_set_f32(Shader* shader, f32 value, const char* name) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glUniform1f(glGetUniformLocation(shader->id, name), value);
#endif
}

void shader_set_vec2(Shader* shader, Vec2 value, const char* name) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glUniform2f(glGetUniformLocation(shader->id, name), value.x, value.y);
#endif
}
