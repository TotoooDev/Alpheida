#ifndef COLOR_FRAGMENT_H
#define COLOR_FRAGMENT_H

const char* color_fragment_shader_source =

"#version 330 core\n"
"precision mediump float;\n"

"out vec4 frag_color;\n"

"in VS_OUT {\n"
"	vec3 frag_pos;\n"
"} vertex_out;\n"

"uniform vec4 u_color;\n"

"void main() {\n"
"	frag_color = u_color;\n"
"}\n"

;

#endif
