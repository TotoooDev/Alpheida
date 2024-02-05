#include <engine/platform/config.h>

#ifdef SHRIMP_SWITCH

#include <engine/music.h>

Music* music_new(const char* filename) {
    
}

void music_delete(Music* music) {
    
}

void music_play(Music* music) {

}

void music_play_position(Music* music, f64 pos_ms) {
    
}

void music_play_fade_in(Music* music, i32 fade) {

}

void music_play_fade_in_position(Music* music, i32 fade, f64 pos_ms) {

}

void music_stop() {

}

void music_pause() {

}

void musix_resume() {

}

void music_fade_out(i32 fade) {

}

void music_set_loops(Music* music, i32 loops) {

}

void music_set_volume(Music* music, i32 volume) {

}

i32 music_get_volume(Music* music) {

}

#endif
