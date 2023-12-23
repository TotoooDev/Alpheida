#include <window.h>
#include <log.h>
#include <SDL2/SDL_image.h>

#define EVENT_FUNCTIONS_SIZE 64

typedef struct Window {
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool is_open;
} Window;

// global varibales (bad practice i know) (number of fucks given: 0)
static unsigned int num_windows = 0;
static EventFunction event_functions[EVENT_FUNCTIONS_SIZE];
static void* user_pointers[EVENT_FUNCTIONS_SIZE];
static unsigned int num_event_functions = 0;

Window* window_new(const char* title, int width, int height) {
    // Initialize SDL if this is the first window
    if (num_windows <= 0) {
        TOTO_ASSERT_VA(SDL_Init(SDL_INIT_EVERYTHING) == 0, "failed to initialize sdl! sdl error: %s\n", SDL_GetError());
        TOTO_ASSERT_VA(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP) != 0, "failed to initialize sdl image! img error: %s\n", IMG_GetError());
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
    TOTO_ASSERT_VA(window->window != NULL, "failed to create window! sdl error: %s\n", SDL_GetError());

    window->renderer = SDL_CreateRenderer(
        window->window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    TOTO_ASSERT_VA(window->renderer != NULL, "failed to create renderer! sdl error: %s\n", SDL_GetError());

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
    if (num_windows <= 0)
        SDL_Quit();
}

void window_clear(Window* window) {
    SDL_SetRenderDrawColor(window->renderer, 0x7F, 0x7F, 0x7F, 0xFF);
    SDL_RenderClear(window->renderer);
}

void window_present(Window* window) {
    SDL_RenderPresent(window->renderer);
}

void window_poll_events(Window* window) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            window->is_open = false;

        for (unsigned int i = 0; i < num_event_functions; i++)
            event_functions[i](user_pointers[i], event);
    }
}

void window_add_event_function(void* user_pointer, EventFunction event_function) {
    TOTO_ASSERT(num_event_functions < EVENT_FUNCTIONS_SIZE, "failed to add event function! the array is not big enough.");
    event_functions[num_event_functions] = event_function;
    user_pointers[num_event_functions] = user_pointer;
    num_event_functions++;
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

