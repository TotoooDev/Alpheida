#include <game/controller.h>
#include <sprite.h>
#include <platform/input.h>
#include <log.h>

void controller_on_event(void* user_pointer, SDL_Event event) {
    Sprite* sprite = (Sprite*)user_pointer;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_RIGHT:
            sprite->aabb->x++;
            break;
        case SDL_SCANCODE_LEFT:
            sprite->aabb->x--;
            break;
        case SDL_SCANCODE_UP:
            sprite->aabb->y--;
            break;
        case SDL_SCANCODE_DOWN:
            sprite->aabb->y++;
            break;

        default:
           break;
        }
    }

    if (event.type == SDL_JOYAXISMOTION) {
        if (event.jaxis.value > -3200 && event.jaxis.value < 3200)
            return;

        if (event.jaxis.axis == 0)
            sprite->aabb->x += event.jaxis.value / 1000;
        if (event.jaxis.axis == 1)
            sprite->aabb->y += event.jaxis.value / 1000;
    }
}

