#ifndef SWITCH_EVENT_H
#define SWITCH_EVENT_H

#include <engine/types.h>

/**
 * Sets the buttons that are currently down for this frame. This should be called every frame.
 * @param keys The bitfield of the buttons.
*/
void event_set_keys_down(u64 keys);

/**
 * Sets the buttons that were released this frame. This should be called every frame.
 * @param keys The bitfield of the buttons.
*/
void event_set_keys_up(u64 keys);

/**
 * Sets the state of the left joystick for this frame.
 * @param x The x offset of the left joystick.
 * @param x The y offset of the left joystick.
*/
void event_set_left_joystick_state(f32 x, f32 y);

/**
 * Sets the state of the right joystick for this frame.
 * @param x The x offset of the right joystick.
 * @param x The y offset of the right joystick.
*/
void event_set_right_joystick_state(f32 x, f32 y);

#endif
