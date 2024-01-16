#ifndef RENDERER_H
#define RENDERER_H

typedef struct Renderer Renderer;

Renderer* renderer_new();
void renderer_delete(Renderer* renderer);

#endif
