#ifndef SWITCH_EVENT_H
#define SWITCH_EVENT_H

#include <engine/types.h>

void event_set_keys_down(u64 keys);
void event_set_keys_up(u64 keys);
void event_set_left_joystick_state(f32 x, f32 y);
void event_set_right_joystick_state(f32 x, f32 y);

#endif
