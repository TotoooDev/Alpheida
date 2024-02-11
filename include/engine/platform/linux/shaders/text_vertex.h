#ifndef TEXT_VERTEX_H
#define TEXT_VERTEX_H

const char* text_vertex_shader_source =

"#version 330 core\n"

"layout (location = 0) in vec4 a_vertex;\n"

"out VS_OUT {\n"
"	vec2 tex_coords;\n"
"} vertex_out;\n"

"uniform mat4 u_projection;\n"

"void main() {\n"
"	vertex_out.tex_coords = a_vertex.zw;\n"
"	gl_Position = u_projection * vec4(a_vertex.xy, 0.0, 1.0);\n"
"}\n"

;

#endif
