#ifndef SOUND_H
#define SOUND_H

typedef struct Sound Sound;

Sound* sound_new(const char* filename);
void sound_delete(Sound* sound);

void sound_play(Sound* sound);

void sound_set_loops(Sound* sound, int loops);
void sound_set_volume(Sound* sound, int volume);

int sound_get_volume(Sound* sound);

#endif

