#include <sound.h>
#include <log.h>
#include <SDL2/SDL_mixer.h>

typedef struct Sound {
    Mix_Chunk* chunk;
} Sound;

Sound* sound_new(const char* filename) {
    Sound* sound = (Sound*)malloc(sizeof(Sound));

    sound->chunk = Mix_LoadWAV(filename);
    log_assert(sound->chunk != NULL, "failed to load %s! mix error: %s\n", filename, Mix_GetError());

    return sound;
}

void sound_delete(Sound* sound) {
    Mix_FreeChunk(sound->chunk);
}

void sound_play(Sound* sound) {
    int ret = Mix_PlayChannel(-1, sound->chunk, 0);

    // not really a critical function, so it is not in an assertion
    if (ret == -1)
        log_error("failed to play sound! mix error: %s\n", Mix_GetError());
}

