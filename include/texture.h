#ifndef TEXTURE_H
#define TEXTURE_H

typedef struct Texture Texture;

Texture* texture_new(const char* filename);
void texture_delete(Texture* texture);

#endif

