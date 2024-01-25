#ifndef BACKGROUND_FRAGMENT_H
#define BACKGROUND_FRAGMENT_H

const char* background_fragment_shader_source =

"#version 330 es\n"
"precision mediump float;\n"

"out vec4 frag_color;\n"

"in VS_OUT {\n"
"    vec2 tex_coords;\n"
"} vertex_out;\n"

"uniform sampler2D u_texture;\n"

"void main() {\n"
"	frag_color = texture(u_texture, vertex_out.tex_coords);\n"
"}\n"

;

#endif
