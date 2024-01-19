#include <engine/graphics/texture.h>
#include <engine/graphics/opengl/texture.h>
#include <engine/graphics/config.h>
#include <engine/log.h>
#include <engine/stb_image/stb_image.h>
#include <engine/graphics/opengl/gl_loader.h>
#include <stdlib.h>

typedef struct Texture {
    u32 id;
} Texture;

void texture_load_from_file(Texture* texture, const char* filename) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    texture_bind(texture);

    // texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    u32 width, height, num_channels;
    u8* data = stbi_load(filename, &width, &height, &num_channels, 0);
    log_assert(data != NULL, "failed to load image %s!", filename);

    GLenum format = GL_RGB;
    if (num_channels == 4)
        format = GL_RGBA;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
#endif
}

Texture* texture_new(const char* filename) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    Texture* texture = (Texture*)malloc(sizeof(Texture));

    glGenTextures(1, &texture->id);
    texture_load_from_file(texture, filename);

    return texture;
#endif
}

void texture_delete(Texture* texture) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glDeleteTextures(1, &texture->id);
    free(texture);
#endif
}

void texture_bind(Texture* texture) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->id);
#endif
}

void texture_bind_active(Texture* texture, u32 active_texture) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    glActiveTexture(GL_TEXTURE0 + active_texture);
    glBindTexture(GL_TEXTURE_2D, texture->id);
#endif
}

u32 texture_get_id(Texture* texture) {
#ifdef SHRIMP_GRAPHICS_OPENGL
    return texture->id;
#endif
}
