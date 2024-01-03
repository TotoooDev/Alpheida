#ifndef EVENT_H
#define EVENT_H

typedef enum EventType {
    EVENT_TYPE_NONE,
    EVENT_TYPE_PLATFORM_QUIT,
    EVENT_TYPE_KEY_DOWN,
    EVENT_TYPE_KEY_UP,
    EVENT_TYPE_BUTTON_DOWN,
    EVENT_TYPE_BUTTON_UP,
    EVENT_TYPE_JOYSTICK_MOTION
} EventType;

typedef enum JoystickType {
    JOYSTICK_TYPE_LEFT,
    JOYSTICK_TYPE_RIGHT
} JoystickType;

typedef enum JoystickAxis {
    JOYSTICK_AXIS_HORIZONTAL,
    JOYSTICK_AXIS_VERTICAL
} JoystickAxis;

typedef struct KeyDownEvent {
    int key;
} KeyDownEvent;

typedef struct KeyUpEvent {
    int key;
} KeyUpEvent;

typedef struct ButtonDownEvent {
    int button;
} ButtonDownEvent;

typedef struct ButtonUpEvent {
    int button;
} ButtonUpEvent;

typedef struct JoystickMotionEvent {
    JoystickType joystick;
    JoystickAxis axis;
    float value;
} JoystickMotionEvent;

typedef void* Event;

typedef void(*EventFunction)(Event* e, EventType event_type, void* user_pointer);

Event* event_new();
void event_delete(Event* event);

void event_update();
void event_add_function(void* user_pointer, EventFunction function);

#endif
