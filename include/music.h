#ifndef MUSIC_H
#define MUSIC_H

typedef struct Music Music;

Music* music_new(const char* filename);
void music_delete(Music* music);

void music_play(Music* music);
void music_play_position(Music* music, double pos_ms);
void music_play_fade_in(Music* music, int fade);
void music_play_fade_in_position(Music* music, int fade, double pos_ms);

void music_stop();
void music_pause();
void music_resume();
void music_fade_out(int fade);

void music_set_loops(Music* music, int loops);
void music_set_volume(Music* music, int volume);

int music_get_volume(Music* music);

#endif

