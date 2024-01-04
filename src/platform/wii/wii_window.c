#include <config.h>

#ifdef SHRIMP_WII

#include <window.h>
#include <log.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#define AUDIO_FREQUENCY 48000
#define NUM_CHANNELS 2

typedef struct Window {
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool is_open;
} Window;

// global varibales (bad practice i know) (number of fucks given: 0)
static unsigned int num_windows = 0;

void window_init_sdl() {
    log_assert(SDL_Init(SDL_INIT_EVERYTHING) == 0, "failed to initialize sdl! sdl error: %s\n", SDL_GetError());
    log_assert(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP) != 0, "failed to initialize sdl image! img error: %s\n", IMG_GetError());
    log_assert(Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS) != 0, "failed to initialize sdl mixer! mix error: %s", Mix_GetError());
    log_assert(Mix_OpenAudio(AUDIO_FREQUENCY, AUDIO_FORMAT, AUDIO_NUM_CHANNELS, AUDIO_CHUNK_SIZE) != -1, "failed to open audio device! mix error: %s\n", Mix_GetError());    

    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_JoystickOpen(0);
}

Window* window_new(const char* title, int width, int height) {
    // Initialize SDL if this is the first window
    if (num_windows <= 0) {
        window_init_sdl();
    }
    
    Window* window = (Window*)malloc(sizeof(Window));

    window->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    log_assert(window->window != NULL, "failed to create window! sdl error: %s\n", SDL_GetError());

    window->renderer = SDL_CreateRenderer(
        window->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    log_assert(window->renderer != NULL, "failed to create renderer! sdl error: %s\n", SDL_GetError());

    window->is_open = true;

    num_windows++;
    return window;
}

void window_delete(Window* window) {
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
    free(window);

    num_windows--;
    
    // If there is no window left, quit SDL
    if (num_windows <= 0) {
        Mix_CloseAudio();
        Mix_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}

void window_clear(Window* window) {
    SDL_SetRenderDrawColor(window->renderer, 0x7F, 0x7F, 0x7F, 0xFF);
    SDL_RenderClear(window->renderer);
}

void window_present(Window* window) {
    SDL_RenderPresent(window->renderer);
}

void window_render_texture(Window* window, Texture* texture, AABB* src, AABB* dest) {
    SDL_Rect src_rect = { (int)src->x, (int)src->y, (int)src->width, (int)src->height };
    SDL_FRect dest_rect = { dest->x, dest->y, dest->width, dest->height };
    SDL_RenderCopyF(window->renderer, texture_get_native_texture(texture), &src_rect, &dest_rect);
}

void window_render_full_texture(Window* window, Texture* texture, AABB* dest) {
    SDL_FRect dest_rect = { dest->x, dest->y, dest->width, dest->height };
    SDL_RenderCopyF(window->renderer, texture_get_native_texture(texture), NULL, &dest_rect);
}

void window_render_color(Window* window, Color color, AABB* dest) {
    SDL_SetRenderDrawColor(window->renderer, color.r, color.g, color.b, color.a);
    SDL_FRect dest_rect = { dest->x, dest->y, dest->width, dest->height };
    SDL_RenderFillRectF(window->renderer, &dest_rect);
}

SDL_Window* window_get_native_window(Window* window) {
    return window->window;
}

SDL_Renderer* window_get_renderer(Window* window) {
    return window->renderer;
}

bool window_is_open(Window* window) {
    return window->is_open;
}

#endif
