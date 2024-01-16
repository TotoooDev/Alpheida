#ifndef COLOR_FRAGMENT_H
#define COLOR_FRAGMENT_H

const char* color_fragment_shader_source =

"#version 330 core\n"

"out vec4 frag_color;\n"

"in VS_OUT {\n"
"	vec3 frag_pos;\n"
"} vertex_out;\n"

"uniform vec4 u_color;\n"

"void main() {\n"
"	frag_color = vec4(1.0, 0.0, 1.0, 1.0);\n"
"}\n"

;

#endif
