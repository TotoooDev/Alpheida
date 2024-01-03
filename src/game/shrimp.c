#include <game/shrimp.h>
#include <fs.h>
#include <event.h>
#include <platform/input.h>
#include <SDL2/SDL_keycode.h>

void shrimp_on_event(Event* e, EventType event_type, void* user_pointer) {
    Shrimp* shrimp = (Shrimp*)user_pointer;

    if (event_type == EVENT_TYPE_KEY_DOWN) {
        KeyDownEvent* event = (KeyDownEvent*)e;
        switch (event->key)
        {
        case SDL_SCANCODE_A:
            shrimp->sprite->aabb->x--;
            break;

        case SDL_SCANCODE_D:
            shrimp->sprite->aabb->x++;
            break;

        case SDL_SCANCODE_SPACE:
            shrimp->sprite->physics_object->forces[1] += 5.0f;
            break;
        
        default:
            break;
        }
    }

    if (event_type == EVENT_TYPE_BUTTON_DOWN) {
        ButtonDownEvent* event = (ButtonDownEvent*)e;
        switch (event->button)
        {
        case JOY_A:
            shrimp->sprite->physics_object->forces[1] += 5.0f;
            break;
        
        default:
            break;
        }
    }

    if (event_type == EVENT_TYPE_JOYSTICK_MOTION) {
        JoystickMotionEvent* event = (JoystickMotionEvent*)e;
        if (event->joystick == JOYSTICK_TYPE_RIGHT)
            return;
        if (event->axis == JOYSTICK_AXIS_HORIZONTAL)
            shrimp->sprite->aabb->x += event->value;
        if (event->axis == JOYSTICK_AXIS_HORIZONTAL)
            shrimp->sprite->aabb->y += event->value;
    }
}

Shrimp* shrimp_new(Scene* scene) {
    Shrimp* shrimp = (Shrimp*)malloc(sizeof(Shrimp));

    Texture* texture = texture_new(fs_get_path_romfs("images/shrimp.png"));
    shrimp->sprite = sprite_new(0.0f, 0.0f, 64.0f, 64.0f, texture);

    physics_add_physics_object(scene_get_physics_world(scene), shrimp->sprite);

    event_add_function(shrimp, shrimp_on_event);

    return shrimp;
}

void shrimp_delete(Shrimp* shrimp) {
    texture_delete(shrimp->sprite->texture);
    sprite_delete(shrimp->sprite);
    free(shrimp);
}
