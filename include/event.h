#ifndef EVENT_H
#define EVENT_H

/**
 * An enumeration for all the different event types.
*/
typedef enum EventType {
    EVENT_TYPE_NONE,
    EVENT_TYPE_PLATFORM_QUIT,
    EVENT_TYPE_KEY_DOWN,
    EVENT_TYPE_KEY_UP,
    EVENT_TYPE_BUTTON_DOWN,
    EVENT_TYPE_BUTTON_UP,
    EVENT_TYPE_JOYSTICK_MOTION
} EventType;

/**
 * An enumeration for the different joystick types. This is used with the `JoystickMotionEvent` event type.
*/
typedef enum JoystickType {
    JOYSTICK_TYPE_LEFT,
    JOYSTICK_TYPE_RIGHT
} JoystickType;

/**
 * An enumeration for the different joystick axis. This is used with the `JoystickMotionEvent` event type.
*/
typedef enum JoystickAxis {
    JOYSTICK_AXIS_HORIZONTAL,
    JOYSTICK_AXIS_VERTICAL
} JoystickAxis;

/**
 * An event for when a key is pressed on the keyboard.
*/
typedef struct KeyDownEvent {
    int key; /** The scancode of the key. You can find them in `platform/keyboard.h` */
} KeyDownEvent;

/**
 * An event for when a key is released on the keyboard.
*/
typedef struct KeyUpEvent {
    int key; /** The scancode of the key. You can find them in `platform/keyboard.h` */
} KeyUpEvent;

/**
 * An event for when a button is pressed.
*/
typedef struct ButtonDownEvent {
    int button; /** The ID of the button. You can find them in `platform/input.h` */
} ButtonDownEvent;

/**
 * An event for when a button is released.
*/
typedef struct ButtonUpEvent {
    int button; /** The ID of the button. You can find them in `platform/input.h` */
} ButtonUpEvent;

/**
 * An event for when a joystick is moved.
*/
typedef struct JoystickMotionEvent {
    JoystickType joystick; /** The joystick that is moved */
    JoystickAxis axis; /** The axis in which the joystick has moved */
    float value; /** The normalized value (ranging from 0.0 to 1.0) of the joystick movement. */
} JoystickMotionEvent;

/**
 * A function pointer type that is called when an event is triggered.
*/
typedef void(*EventFunction)(void*, EventType, void*);

/**
 * Creates a new event.
*/
void* event_new();

/**
 * Deletes an event.
 * @param event The event to delete.
*/
void event_delete(void* event);

/**
 * Updates the event handler.
*/
void event_update();

/**
 * Adds a function that is called when a event occurs.
 * @param user_pointer The user pointer to pass in the function.
 * @param function The function to call when the event occurs.
*/
void event_add_function(void* user_pointer, EventFunction function);

#endif
