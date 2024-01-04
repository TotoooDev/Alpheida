#include <config.h>

#ifdef SHRIMP_LINUX

#include <platform/linux/linux_events.h>
#include <platform/input.h>
#include <SDL2/SDL.h>

JoystickAxis linux_get_joystick_axis(int sdl_axis) {
    if (sdl_axis == 0 || sdl_axis == 1)
        return JOYSTICK_TYPE_LEFT;
    if (sdl_axis == 2 || sdl_axis == 3)
        return JOYSTICK_TYPE_RIGHT;
    return -1;
}

void linux_process_events(EventType* event_type, Event* event) {
    SDL_Event sdl_event;
    if (SDL_PollEvent(&sdl_event) == 0) {
        *event_type = EVENT_TYPE_NONE;
        return;
    }

    switch (sdl_event.type) {
    case SDL_QUIT:
        *event_type = EVENT_TYPE_PLATFORM_QUIT;
        break;

    case SDL_KEYDOWN:
        *event_type = EVENT_TYPE_KEY_DOWN;
        ((KeyDownEvent*)event)->key = sdl_event.key.keysym.scancode;
        break;

    case SDL_KEYUP:
        *event_type = EVENT_TYPE_KEY_UP;
        ((KeyUpEvent*)event)->key = sdl_event.key.keysym.scancode;
        break;

    case SDL_JOYBUTTONDOWN:
        *event_type = EVENT_TYPE_BUTTON_DOWN;
        ((ButtonDownEvent*)event)->button = sdl_event.jbutton.button;
        break;

    case SDL_JOYBUTTONUP:
        *event_type = EVENT_TYPE_BUTTON_UP;
        ((ButtonUpEvent*)event)->button = sdl_event.jbutton.button;
        break;

    case SDL_JOYAXISMOTION:
        *event_type = EVENT_TYPE_JOYSTICK_MOTION;
        ((JoystickMotionEvent*)event)->joystick = linux_get_joystick_axis(sdl_event.jaxis.axis);
        ((JoystickMotionEvent*)event)->axis = sdl_event.jaxis.axis % 2; // 0 and 2 are horizontal, 1 and 3 are vertical
        ((JoystickMotionEvent*)event)->value = (float)sdl_event.jaxis.value / (float)INT16_MAX;
        break;
    
    default:
        event_type = EVENT_TYPE_NONE;
        break;
    }
}

#endif
