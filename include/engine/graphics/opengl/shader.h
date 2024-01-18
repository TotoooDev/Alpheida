#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <engine/graphics/color.h>
#include <engine/cglm/cglm.h>
#include <engine/types.h>

typedef struct Shader Shader;

Shader* shader_new(const char* vertex_source, const char* fragment_source);
void shader_delete(Shader* shader);

void shader_bind(Shader* shader);
u32 shader_get_id(Shader* shader);

void shader_set_i32(Shader* shader, i32 value, const char* name);
void shader_set_f32(Shader* shader, f32 value, const char* name);
void shader_set_vec2(Shader* shader, vec2 value, const char* name);
void shader_set_mat4(Shader* shader, mat4 value, const char* name);
void shader_set_color(Shader* shader, Color color, const char* name);

#endif
