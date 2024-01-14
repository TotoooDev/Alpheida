#ifndef APPLICATION_H
#define APPLICATION_H

#include <window.h>
#include <scene.h>

/**
 * Creates a new application.
 * @param name The name of your application.
 * @note This calls `platform_init` right after initializing the app. On systems that offer a windowing system (Linux, Windows, ...), the title of the window is the name of the application.
*/
void app_create(const char* name);

/**
 * Deletes the app.
 * @note This calls `platform_exit` just before freeing the app.
*/
void app_delete();

/**
 * Returns a pointer to the window associated with the app.
 * @returns The window assocated with the app.
*/
Window* app_get_window();

/**
 * Executes the main loop of the app.
*/
void app_run();

/**
 * Tells the app to stop execution of the main loop.
 * @note Calling `app_run` after `app_quit` is called does not execute the main loop.
*/
void app_quit();

/**
 * Sets the scene to update in the main loop of the app.
 * @param scene The new current scene.
*/
void app_set_current_scene(Scene* scene);

#endif

