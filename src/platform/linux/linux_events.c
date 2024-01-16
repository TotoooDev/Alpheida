#include <platform/config.h>

#ifdef SHRIMP_LINUX

#include <platform/platform.h>
#include <platform/input.h>
#include <log.h>
#include <SDL2/SDL.h>

JoystickAxis linux_get_joystick_axis(i32 sdl_axis) {
    if (sdl_axis == 0 || sdl_axis == 1)
        return JOYSTICK_TYPE_LEFT;
    if (sdl_axis == 2 || sdl_axis == 3)
        return JOYSTICK_TYPE_RIGHT;
    return -1;
}

MouseButton linux_get_mouse_button(u8 sdl_button) {
    switch (sdl_button) {
        case SDL_BUTTON_LEFT: return MOUSE_BUTTON_LEFT;
        case SDL_BUTTON_RIGHT: return MOUSE_BUTTON_RIGHT;
        case SDL_BUTTON_MIDDLE: return MOUSE_BUTTON_MIDDLE;
        default: 
            log_error("unknown mouse button %d!\n", sdl_button);
            return MOUSE_BUTTON_LEFT;
    }
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

    case SDL_MOUSEMOTION:
        ((MouseMovedEvent*)event)->x = (f32)sdl_event.motion.x;
        ((MouseMovedEvent*)event)->y = (f32)sdl_event.motion.y;
        ((MouseMovedEvent*)event)->delta_x = (f32)sdl_event.motion.xrel;
        ((MouseMovedEvent*)event)->delta_y = (f32)sdl_event.motion.yrel;
        return EVENT_TYPE_MOUSE_MOVED;

    case SDL_MOUSEBUTTONDOWN:
        ((MouseButtonDownEvent*)event)->button = linux_get_mouse_button(sdl_event.button.button);
        return EVENT_TYPE_MOUSE_BUTTON_DOWN;

    case SDL_MOUSEBUTTONUP:
        ((MouseButtonUpEvent*)event)->button = linux_get_mouse_button(sdl_event.button.button);
        return EVENT_TYPE_MOUSE_BUTTON_UP;

    case SDL_JOYBUTTONDOWN:
        ((ButtonDownEvent*)event)->button = sdl_event.jbutton.button;
        return EVENT_TYPE_BUTTON_DOWN;

    case SDL_JOYBUTTONUP:
        ((ButtonUpEvent*)event)->button = sdl_event.jbutton.button;
        return EVENT_TYPE_BUTTON_UP;

    case SDL_JOYAXISMOTION:
        ((JoystickMotionEvent*)event)->joystick = linux_get_joystick_axis(sdl_event.jaxis.axis);
        ((JoystickMotionEvent*)event)->axis = sdl_event.jaxis.axis % 2; // 0 and 2 are horizontal, 1 and 3 are vertical
        ((JoystickMotionEvent*)event)->value = (f32)sdl_event.jaxis.value / (f32)INT16_MAX;
        return EVENT_TYPE_JOYSTICK_MOTION;
    
    default:
        return EVENT_TYPE_NONE;
    }
}

#endif
