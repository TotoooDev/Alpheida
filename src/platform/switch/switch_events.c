#include <platform/config.h>

#ifdef SHRIMP_SWITCH

#include <platform/platform.h>
#include <platform/input.h>
#include <SDL2/SDL.h>

JoystickAxis switch_get_joystick_axis(i32 sdl_axis) {
    if (sdl_axis == 0 || sdl_axis == 1)
        return JOYSTICK_TYPE_LEFT;
    if (sdl_axis == 2 || sdl_axis == 3)
        return JOYSTICK_TYPE_RIGHT;
    return -1;
}

EventType platform_process_events(void* event) {
    SDL_Event sdl_event;
    if (SDL_PollEvent(&sdl_event) == 0) {
        return EVENT_TYPE_NONE;
    }

    switch (sdl_event.type) {
    case SDL_QUIT:
        return EVENT_TYPE_PLATFORM_QUIT;

    case SDL_KEYDOWN:
        ((KeyDownEvent*)event)->key = sdl_event.key.keysym.scancode;
        return EVENT_TYPE_KEY_DOWN;

    case SDL_KEYUP:
        ((KeyUpEvent*)event)->key = sdl_event.key.keysym.scancode;
        return EVENT_TYPE_KEY_UP;

    case SDL_JOYBUTTONDOWN:
        ((ButtonDownEvent*)event)->button = sdl_event.jbutton.button;
        return EVENT_TYPE_BUTTON_DOWN;

    case SDL_JOYBUTTONUP:
        ((ButtonUpEvent*)event)->button = sdl_event.jbutton.button;
        return EVENT_TYPE_BUTTON_UP;

    case SDL_JOYAXISMOTION:
        ((JoystickMotionEvent*)event)->joystick = switch_get_joystick_axis(sdl_event.jaxis.axis);
        ((JoystickMotionEvent*)event)->axis = sdl_event.jaxis.axis % 2; // 0 and 2 are horizontal, 1 and 3 are vertical
        ((JoystickMotionEvent*)event)->value = (f32)sdl_event.jaxis.value / (f32)INT16_MAX;
        return EVENT_TYPE_JOYSTICK_MOTION;
    
    default:
        return EVENT_TYPE_NONE;
    }
}

#endif
