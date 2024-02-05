#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <engine/graphics/color.h>
#include <engine/cglm/cglm.h>
#include <engine/types.h>

/**
 * A wrapper around an OpenGL shader.
*/
typedef struct Shader Shader;

/**
 * Creates a new shader.
 * @param vertex_source The source code of the vertex shader.
 * @param fragment_source The source code of the fragment shader.
 * @return The new shader.
*/
Shader* shader_new(const char* vertex_source, const char* fragment_source);

/**
 * Deletes a shader.
 * @param shader The shader to delete.
*/
void shader_delete(Shader* shader);

/**
 * Binds a shader for later use.
 * @param shader The shader to bind.
*/
void shader_bind(Shader* shader);

/**
 * Returns the OpenGL ID of a shader.
 * @param shader The shader to get the ID from.
 * @return The ID of `shader`.
*/
u32 shader_get_id(Shader* shader);

/**
 * Sets a signed 32-bit int uniform to a shader.
 * @param shader The shader to set the uniform to.
 * @param value The value of the uniform.
 * @param name The name of the uniform.
*/
void shader_set_i32(Shader* shader, i32 value, const char* name);

/**
 * Sets a 32-bit float uniform to a shader.
 * @param shader The shader to set the uniform to.
 * @param value The value of the uniform.
 * @param name The name of the uniform.
*/
void shader_set_f32(Shader* shader, f32 value, const char* name);

/**
 * Sets a 2 components vector uniform to a shader.
 * @param shader The shader to set the uniform to.
 * @param value The value of the uniform.
 * @param name The name of the uniform.
*/
void shader_set_vec2(Shader* shader, vec2 value, const char* name);

/**
 * Sets a 4x4 matrix uniform to a shader.
 * @param shader The shader to set the uniform to.
 * @param value The value of the uniform.
 * @param name The name of the uniform.
*/
void shader_set_mat4(Shader* shader, mat4 value, const char* name);

/**
 * Sets a color uniform to a shader.
 * @param shader The shader to set the uniform to.
 * @param value The value of the uniform.
 * @param name The name of the uniform.
*/
void shader_set_color(Shader* shader, Color color, const char* name);

#endif
