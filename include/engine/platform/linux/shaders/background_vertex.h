#ifndef BACKGROUND_VERTEX_H
#define BACKGROUND_VERTEX_H

const char* background_vertex_shader_source =

"#version 330 core\n"

"layout (location = 0) in vec3 a_pos;\n"
"layout (location = 1) in vec2 a_tex_coords;\n"

"out VS_OUT {\n"
"    vec2 tex_coords;\n"
"} vertex_out;\n"

"void main() {\n"
"   vertex_out.tex_coords = a_tex_coords;\n"

"	gl_Position = vec4(a_pos, 1.0);\n"
"}\n"

;

#endif
