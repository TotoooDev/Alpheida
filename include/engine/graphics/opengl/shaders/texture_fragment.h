#ifndef TEXTURE_FRAGMENT_H
#define TEXTURE_FRAGMENT_H

const char* texture_fragment_shader_source =

"#version 330 core\n"

"out vec4 frag_color;\n"

"in VS_OUT {\n"
"	vec3 frag_pos;\n"
"    vec2 tex_coords;\n"
"} output;\n"

"uniform sampler2D u_texture;\n"

"void main() {\n"
"	frag_color = texture(u_texture, output.tex_coords);\n"
"}\n"

;

#endif
