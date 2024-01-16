#ifndef TEXTURE_VERTEX_H
#define TEXTURE_VERTEX_H

const char* texture_vertex_shader_source =

"#version 330 core\n"

"layout (location = 0) in vec3 a_pos;\n"
"layout (location = 1) in vec2 a_tex_coords;\n"

"out VS_OUT {\n"
"	vec3 frag_pos;\n"
"    vec2 tex_coords;\n"
"} output;\n"

"uniform mat4 u_model;\n"
"uniform mat4 u_view;\n"
"uniform mat4 u_projection;\n"

"void main() {\n"
"	output.frag_pos = vec3(u_model * vec4(a_pos, 1.0));\n"
"    output.tex_coords = a_tex_coords;\n"

"	gl_Position = u_projection * u_view * u_model * vec4(a_pos, 1.0);\n"
"}\n"

;

#endif
