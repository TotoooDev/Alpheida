#include <engine/platform/config.h>

#ifdef SHRIMP_LINUX

#include <engine/audio/sound.h>
#include <engine/log.h>
#include <SDL2/SDL_mixer.h>

typedef struct Sound {
    Mix_Chunk* chunk;
    i32 num_loops;
} Sound;

Sound* sound_new(const char* filename) {
    Sound* sound = (Sound*)malloc(sizeof(Sound));

    sound->chunk = Mix_LoadWAV(filename);
    log_assert(sound->chunk != NULL, "failed to load %s! mix error: %s\n", filename, Mix_GetError());

    sound->num_loops = 0;

    return sound;
}

void sound_delete(Sound* sound) {
    Mix_FreeChunk(sound->chunk);
}

void sound_play(Sound* sound) {
    i32 ret = Mix_PlayChannel(-1, sound->chunk, 0);

    // not really a critical function, so it is not in an assertion
    if (ret == -1)
        log_error("failed to play sound! mix error: %s\n", Mix_GetError());
}

void sound_set_loops(Sound* sound, i32 loops) {
    sound->num_loops = loops;
}

void sound_set_volume(Sound* sound, i32 volume) {
    Mix_VolumeChunk(sound->chunk, volume);
}

i32 sound_get_volume(Sound* sound) {
    return Mix_VolumeChunk(sound->chunk, -1);
}

#endif
