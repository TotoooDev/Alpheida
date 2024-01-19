#include <engine/platform/config.h>
#include <engine/config.h>

#ifdef SHRIMP_SWITCH

#include <engine/graphics/window.h>
#include <engine/platform/switch/switch_window.h>
#include <engine/log.h>
#include <switch.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <glad/glad.h>
#include <stdlib.h>

typedef struct Window {
    EGLDisplay display;
    EGLContext context;
    EGLSurface surface;
} Window;

void window_set_debug() {
    // msa logging
    setenv("EGL_LOG_LEVEL", "debug", 1);
    setenv("MESA_VERBOSE", "all", 1);
    setenv("NOUVEAU_MESA_DEBUG", "1", 1);

    // shader debugging
    setenv("NV50_PROG_OPTIMIZE", "0", 1);
    setenv("NV50_PROG_DEBUG", "1", 1);
    setenv("NV50_PROG_CHIPSET", "0x120", 1);
}

void window_init_egl(Window* window) {
    // connect to the default egl display
    window->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    log_assert(window->display != NULL, "failed to connect to display! egl error: %d\n", eglGetError());

    // intialize the egl display connexion
    eglInitialize(window->display, NULL, NULL);
    log_assert(eglBindAPI(EGL_OPENGL_API), "failed to set opengl api! egl error: %d\n", eglGetError());

    // get an appropriate egl framebuffer config
    EGLConfig config;
    EGLint num_configs;
    static const EGLint framebuffer_attributes_list[] = {
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_RED_SIZE,     8,
        EGL_GREEN_SIZE,   8,
        EGL_BLUE_SIZE,    8,
        EGL_ALPHA_SIZE,   8,
        EGL_DEPTH_SIZE,   24,
        EGL_STENCIL_SIZE, 8,
        EGL_NONE
    };
    eglChooseConfig(window->display, framebuffer_attributes_list, &config, 1, &num_configs);
    log_assert(num_configs != 0, "failed to find a config! egl error: %d\n", eglGetError());

    // create an egl window surface
    window->surface = eglCreateWindowSurface(window->display, config, nwindowGetDefault(), NULL);
    log_assert(window->surface != NULL, "failed to create a window surface! egl error: %d\n", eglGetError());

    // create an egl rendering context
    static cont EGLint context_attributes_list[] = {
        EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR,
        EGL_CONTEXT_MAJOR_VERSION_KHR, 4,
        EGL_CONTEXT_MINOR_VERSION_KHR, 3,
        EGL_NONE
    };
    window->context = eglCreateContext(window->display, config, EGL_NO_CONTEXT, context_attributes_list);
    log_assert(window->context != NULL, "failed to create context! egl error: %d\n", eglGetError());
    eglMakeCurrent(window->display, window->surface, window->surface, window->context);
}

Window* window_new(const char* title, i32 width, i32 height) {
    window_set_debug();
    
    Window* window = (Window*)malloc(sizeof(Window));
    window_init_egl(window);
    return window;
}

void window_delete(Window* window) {
    eglMakeCurrent(window->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglDestroyContext(window->context);
    eglDestroySurface(window->surface);
    eglTerminate(window->display);
    free(window);
}

void window_present(Window* window) {
    eglSwapBuffers(window->disaplt, window->surface)
}

#endif
