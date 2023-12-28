#ifndef INPUT_H
#define INPUT_H

#include <config.h>

#ifdef TOTO_SWITCH
#include <platform/switch.h>
#endif

#ifdef TOTO_SWITCH
    #define JOY_INVALID       -1
    #define JOY_A             SWITCH_JOY_A
    #define JOY_B             SWITCH_JOY_B
    #define JOY_X             SWITCH_JOY_X
    #define JOY_Y             SWITCH_JOY_X
    #define JOY_LSTICK_BUTTON SWITCH_JOY_X
    #define JOY_RSTICK_BUTTON SWITCH_JOY_X
    #define JOY_L             SWITCH_JOY_X
    #define JOY_R             SWITCH_JOY_X
    #define JOY_L2            SWITCH_JOY_X
    #define JOY_R2            SWITCH_JOY_X
    #define JOY_PLUS          SWITCH_JOY_X
    #define JOY_MINUS         SWITCH_JOY_X
    #define JOY_LEFT          SWITCH_JOY_X
    #define JOY_UP            SWITCH_JOY_X
    #define JOY_RIGHT         SWITCH_JOY_X
    #define JOY_DOWN          SWITCH_JOY_X
    #define JOY_LSTICK_LEFT   SWITCH_JOY_X
    #define JOY_LSTICK_UP     SWITCH_JOY_X
    #define JOY_LSTICK_RIGHT  SWITCH_JOY_X
    #define JOY_LSTCIK_DOWN   SWITCH_JOY_X
    #define JOY_RSTICK_LEFT   SWITCH_JOY_X
    #define JOY_RSTICK_UP     SWITCH_JOY_X
    #define JOY_RSTICK_RIGHT  SWITCH_JOY_X
    #define JOY_RSTICK_DOWN   SWITCH_JOY_X
    #define JOY_LSL           SWITCH_JOY_X
    #define JOY_LSR           SWITCH_JOY_X
    #define JOY_RSL           SWITCH_JOY_X
    #define JOY_RSR           SWITCH_JOY_X
#else
    // toto: investigate how to get more controller input
    #define JOY_INVALID       SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_A             SDL_CONTROLLER_BUTTON_A
    #define JOY_B             SDL_CONTROLLER_BUTTON_B
    #define JOY_X             SDL_CONTROLLER_BUTTON_X
    #define JOY_Y             SDL_CONTROLLER_BUTTON_Y
    #define JOY_LSTICK_BUTTON SDL_CONTROLLER_BUTTON_LEFTSTICK
    #define JOY_RSTICK_BUTTON SDL_CONTROLLER_BUTTON_RIGHTSTICK
    #define JOY_L             SDL_CONTROLLER_BUTTON_LEFTSHOULDER
    #define JOY_R             SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
    #define JOY_L2            SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_R2            SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_PLUS          SDL_CONTROLLER_BUTTON_START
    #define JOY_MINUS         SDL_CONTROLLER_BUTTON_GUIDE
    #define JOY_LEFT          SDL_CONTROLLER_BUTTON_DPAD_LEFT
    #define JOY_UP            SDL_CONTROLLER_BUTTON_DPAD_UP
    #define JOY_RIGHT         SDL_CONTROLLER_BUTTON_DPAD_RIGHT
    #define JOY_DOWN          SDL_CONTROLLER_BUTTON_DPAD_DOWN
    #define JOY_LSTICK_LEFT   SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_LSTICK_UP     SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_LSTICK_RIGHT  SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_LSTCIK_DOWN   SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSTICK_LEFT   SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSTICK_UP     SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSTICK_RIGHT  SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSTICK_DOWN   SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_LSL           SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_LSR           SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSL           SDL_CONTROLLER_BUTTON_INVALID
    #define JOY_RSR           SDL_CONTROLLER_BUTTON_INVALID
#endif

#endif

