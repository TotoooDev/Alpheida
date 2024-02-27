#include <engine/platform/config.h>

#ifdef SHRIMP_LINUX

#include <engine/audio/music.h>
#include <engine/log.h>
#include <SDL2/SDL_mixer.h>

typedef struct Music {
    Mix_Music* music;
    i32 num_loops;
} Music;

Music* music_new(const char* filename) {
    Music* music = (Music*)malloc(sizeof(Music));

    music->music = Mix_LoadMUS(filename);
    log_assert(music->music != NULL, "failed to load music %s! mix error: %s\n", filename, Mix_GetError());

    music->num_loops = 0;

    return music;
}

void music_delete(Music* music) {
    Mix_FreeMusic(music->music);
    free(music);
}

void music_play(Music* music) {
    Mix_PlayMusic(music->music, music->num_loops);
}

void music_play_position(Music* music, f64 pos_ms) {
    Mix_SetMusicPosition(pos_ms * 0.001f);
    music_play(music);
}

void music_play_fade_in(Music* music, i32 fade) {
    Mix_FadeInMusic(music->music, music->num_loops, fade);
}

void music_play_fade_in_position(Music* music, i32 fade, f64 pos_ms) {
    Mix_FadeInMusicPos(music->music, music->num_loops, fade, pos_ms * 0.001f);
}

void music_stop() {
    Mix_HaltMusic();
}

void music_pause() {
    Mix_PauseMusic();
}

void musix_resume() {
    Mix_ResumeMusic();
}

void music_fade_out(i32 fade) {
    Mix_FadeOutMusic(fade);
}

void music_set_loops(Music* music, i32 loops) {
    music->num_loops = loops;
}

void music_set_volume(Music* music, i32 volume) {
    Mix_VolumeMusic(volume);
}

i32 music_get_volume(Music* music) {
    return Mix_VolumeMusic(-1);
}

#endif
