#include <game/shrimp.h>
#include <fs.h>
#include <event.h>
#include <platform/input.h>
#include <SDL2/SDL_keycode.h>

void shrimp_update(Sprite* sprite, float timestep) {
    Shrimp* shrimp = (Shrimp*)sprite->user_pointer;

    if (shrimp->is_moving[0])
        sprite->aabb->x -= shrimp->speed * shrimp->speed_multiplier;
    if (shrimp->is_moving[1])
        sprite->aabb->x += shrimp->speed * shrimp->speed_multiplier;
}

void shrimp_on_event(Event* e, EventType event_type, void* user_pointer) {
    Shrimp* shrimp = (Shrimp*)user_pointer;

    if (event_type == EVENT_TYPE_KEY_DOWN) {
        KeyDownEvent* event = (KeyDownEvent*)e;
        switch (event->key)
        {
        case SDL_SCANCODE_A:
            shrimp->is_moving[0] = true;
            shrimp->speed_multiplier = 1.0f;
            break;

        case SDL_SCANCODE_D:
            shrimp->is_moving[1] = true;
            shrimp->speed_multiplier = 1.0f;
            break;

        case SDL_SCANCODE_SPACE:
            shrimp->sprite->physics_object->forces[1] += 5.0f;
            break;
        
        default:
            break;
        }
    }

    if (event_type == EVENT_TYPE_KEY_UP) {
        KeyUpEvent* event = (KeyUpEvent*)e;
        switch (event->key)
        {
        case SDL_SCANCODE_A:
            shrimp->is_moving[0] = false;
            shrimp->speed_multiplier = 0.0f;
            break;

        case SDL_SCANCODE_D:
            shrimp->is_moving[1] = false;
            shrimp->speed_multiplier = 0.0f;
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

        if (event->value < 0.05f && event->value > -0.05f) {
            shrimp->is_moving[0] = false;
            shrimp->is_moving[1] = false;
            shrimp->speed_multiplier = 0.0f;
        }

        if (event->axis == JOYSTICK_AXIS_HORIZONTAL) {
            shrimp->speed_multiplier = (float)fabs((double)event->value);
            if (event->value > 0.0f)
                shrimp->is_moving[1] = true;
            else
                shrimp->is_moving[0] = true;
        }
    }
}

Shrimp* shrimp_new(Scene* scene) {
    Shrimp* shrimp = (Shrimp*)malloc(sizeof(Shrimp));

    Texture* texture = texture_new(fs_get_path_romfs("images/shrimp.png"));
    shrimp->sprite = sprite_new(0.0f, 0.0f, 64.0f, 64.0f, texture);
    shrimp->sprite->update_function = shrimp_update;
    shrimp->sprite->user_pointer = (void*)shrimp;

    shrimp->is_moving[0] = false;
    shrimp->is_moving[1] = false;
    shrimp->speed_multiplier = 1.0f;
    shrimp->speed = 5.0f;

    physics_add_physics_object(scene_get_physics_world(scene), shrimp->sprite);

    event_add_function(shrimp, shrimp_on_event);

    return shrimp;
}

void shrimp_delete(Shrimp* shrimp) {
    texture_delete(shrimp->sprite->texture);
    sprite_delete(shrimp->sprite);
    free(shrimp);
}
