#ifndef SOUND_H
#define SOUND_H

typedef struct Sound Sound;

Sound* sound_new(const char* filename);
void sound_delete(Sound* sound);

void sound_play(Sound* sound);

#endif

