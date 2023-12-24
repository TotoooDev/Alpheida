#include <game/controller.h>
#include <sprite.h>

void controller_on_event(void* user_pointer, SDL_Event event) {
    Sprite* sprite = (Sprite*)user_pointer;

    if (event.type != SDL_KEYDOWN)
        return;

    switch (event.key.keysym.scancode) {
    case SDL_SCANCODE_RIGHT:
        sprite->aabb->x++;
        break;

    default:
        break;
    }
}

