#ifndef TEXT_FRAGMENT_H
#define TEXT_FRAGMENT_H

const char* text_fragment_shader_source =

"#version 330 core\n"

"out vec4 frag_color;\n"

"in VS_OUT {\n"
"	vec2 tex_coords;\n"
"} vertex_out;\n"

"uniform sampler2D text;\n"
"uniform vec4 u_color;\n"

"void main() {\n"
"   vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, vertex_out.tex_coords).r);\n"
"	frag_color = u_color * sampled;\n"
"}\n"

;

#endif
