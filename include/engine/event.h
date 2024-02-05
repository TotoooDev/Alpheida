#ifndef EVENT_H
#define EVENT_H

#include <engine/types.h>

/**
 * An enumeration for all the different event types.
*/
typedef enum EventType {
    EVENT_TYPE_NONE,
    EVENT_TYPE_PLATFORM_QUIT,
    EVENT_TYPE_WINDOW_RESIZED,
    EVENT_TYPE_KEY_DOWN,
    EVENT_TYPE_KEY_UP,
    EVENT_TYPE_MOUSE_MOVED,
    EVENT_TYPE_MOUSE_BUTTON_DOWN,
    EVENT_TYPE_MOUSE_BUTTON_UP,
    EVENT_TYPE_BUTTON_DOWN,
    EVENT_TYPE_BUTTON_UP,
    EVENT_TYPE_JOYSTICK_MOTION
} EventType;

typedef enum MouseButton {
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_MIDDLE
} MouseButton;

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
 * An event for when the window is resized.
*/
typedef struct WindowResizedEvent {
    f32 width;
    f32 height;
} WindowResizedEvent;

/**
 * An event for when a key is pressed on the keyboard.
*/
typedef struct KeyDownEvent {
    i32 key; /** The scancode of the key. You can find them in `platform/keyboard.h` */
} KeyDownEvent;

/**
 * An event for when a key is released on the keyboard.
*/
typedef struct KeyUpEvent {
    i32 key; /** The scancode of the key. You can find them in `platform/keyboard.h` */
} KeyUpEvent;

/**
 * An event for when the mouse is moved.
*/
typedef struct MouseMovedEvent {
    f32 x, y; /** The position of the mouse, relative to the window. */
    f32 delta_x, delta_y; /** The movement of the mouse. */
} MouseMovedEvent;

/**
 * An event for when a mouse button is pressed.
*/
typedef struct MouseButtonDownEvent {
    MouseButton button; /** The mouse button that was pressed. */
} MouseButtonDownEvent;

/**
 * An event for when a mouse button is released.
*/
typedef struct MouseButtonUpEvent {
    MouseButton button; /** The mouse button that was released. */
} MouseButtonUpEvent;

/**
 * An event for when a button is pressed.
*/
typedef struct ButtonDownEvent {
    i32 button; /** The ID of the button. You can find them in `platform/input.h` */
} ButtonDownEvent;

/**
 * An event for when a button is released.
*/
typedef struct ButtonUpEvent {
    i32 button; /** The ID of the button. You can find them in `platform/input.h` */
} ButtonUpEvent;

/**
 * An event for when a joystick is moved.
*/
typedef struct JoystickMotionEvent {
    JoystickType joystick; /** The joystick that is moved */
    JoystickAxis axis; /** The axis in which the joystick has moved */
    f32 value; /** The normalized value (ranging from 0.0 to 1.0) of the joystick movement. */
} JoystickMotionEvent;

/**
 * A function pointer type that is called when an event is triggered.
 * @param void* The event that occured.
 * @param EventType The event type that occured.
 * @param void* The user pointer.
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

/**
 * Sends the event in a waiting pool that is processed in the next call of event_update.
 * @param event_type The type of the event.
 * @param event The actual event.
*/
void event_send_event(EventType event_type, void* event);

#endif
