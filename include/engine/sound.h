#ifndef SOUND_H
#define SOUND_H

#include <engine/types.h>

typedef struct Sound Sound;

Sound* sound_new(const char* filename);
void sound_delete(Sound* sound);

void sound_play(Sound* sound);

void sound_set_loops(Sound* sound, i32 loops);
void sound_set_volume(Sound* sound, i32 volume);

i32 sound_get_volume(Sound* sound);

#endif

