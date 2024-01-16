#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <engine/math/vec2.h>
#include <engine/math/mat4.h>
#include <engine/types.h>

typedef struct Shader Shader;

Shader* shader_new(const char* vertex_source, const char* fragment_source);
void shader_delete(Shader* shader);

void shader_bind(Shader* shader);
u32 shader_get_id(Shader* shader);

void shader_set_i32(Shader* shader, i32 value, const char* name);
void shader_set_f32(Shader* shader, f32 value, const char* name);
void shader_set_vec2(Shader* shader, Vec2 value, const char* name);
void shader_set_mat4(Shader* shader, Mat4 value, const char* name);

#endif
