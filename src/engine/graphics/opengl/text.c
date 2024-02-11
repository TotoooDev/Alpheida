#include <engine/graphics/text.h>
#include <engine/log.h>
#include <engine/graphics/opengl/gl_loader.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <stdlib.h>
#include <stdbool.h>

#define FONT_NUM_CHARACTERS 128

typedef struct Font {
    Glyph* characters[128];
    u32 size_pixels;
} Font;

typedef struct Glyph {
    u32 texture_id;
    vec2 size;
    vec2 bearing;
    u32 advance;
} Glyph;

Font* font_new(const char* filename, u32 size_pixels) {
    FT_Library freetype;
    log_assert(FT_Init_FreeType(&freetype) == 0, "failed to init freetype!\n");

    Font* font = (Font*)malloc(sizeof(Font));

    font->size_pixels = size_pixels;

    // from https://learnopengl.com/In-Practice/Text-Rendering
    
    FT_Face face;
    log_assert(FT_New_Face(freetype, filename, 0, &face) == 0, "failed to load font %s!\n", filename);
    FT_Set_Pixel_Sizes(face, 0, size_pixels);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (u8 c = 0; c < FONT_NUM_CHARACTERS; c++) {
        log_assert(FT_Load_Char(face, c, FT_LOAD_RENDER) == 0, "failed to load glyph for character %c!\n", c);

        // generate the texture
        u32 texture;
        
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Glyph* glyph = (Glyph*)malloc(sizeof(Glyph));
        glyph->texture_id = texture;
        glm_vec2_copy((vec2){ face->glyph->bitmap.width, face->glyph->bitmap.rows }, glyph->size);
        glm_vec2_copy((vec2){ face->glyph->bitmap_left, face->glyph->bitmap_top }, glyph->bearing);
        glyph->advance = face->glyph->advance.x;

        font->characters[c] = glyph;
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    FT_Done_Face(face);
    FT_Done_FreeType(freetype);

    return font;
}

void font_delete(Font* font) {
    for (u8 c = 0; c < FONT_NUM_CHARACTERS; c++) {
        glDeleteTextures(1, &font->characters[c]->texture_id);
        free(font->characters[c]);
    }
    free(font);
}

Glyph* font_get_character(Font* font, u8 character) {
    return font->characters[character];
}

void glyph_get_size(Glyph* glyph, vec2 dest) {
    glm_vec2_copy(glyph->size, dest);
}

void glyph_get_bearing(Glyph* glyph, vec2 dest) {
    glm_vec2_copy(glyph->bearing, dest);
}

u32 glyph_get_advance(Glyph* glyph) {
    return glyph->advance;
}

u32 glyph_get_texture_id(Glyph* glyph) {
    return glyph->texture_id;
}
