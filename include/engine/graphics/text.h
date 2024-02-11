#ifndef TEXT_H
#define TEXT_H

#include <engine/types.h>
#include <engine/cglm/cglm.h>

typedef struct Font Font;
typedef struct Glyph Glyph;

Font* font_new(const char* filename, u32 size_pixels);
void font_delete(Font* font);

Glyph* font_get_character(Font* font, u8 character);

void glyph_get_size(Glyph* glyph, vec2 dest);
void glyph_get_bearing(Glyph* glyph, vec2 dest);
u32 glyph_get_advance(Glyph* glyph);

#endif
