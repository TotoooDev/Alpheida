#ifndef SWITCH_WINDOW_H
#define SWITCH_WINDOW_H

#include <engine/graphics/window.h>

/**
 * Updates the resolution of the window: 1280x720 if the console is in handheld mode, 1920x1080 if the console is docked.
 * @param window The window to update.
 * @note To get the dimensions of the window, call `window_get_width` and `window_get_height`.
*/
void window_update_resolution(Window* window);

#endif
