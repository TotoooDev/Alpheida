#ifndef MUSIC_H
#define MUSIC_H

#include <engine/types.h>

/**
 * A wrapper around everything that makes a music.
*/
typedef struct Music Music;

/**
 * Creates a new music by loading a file.
 * @param filename The name of the file to load.
 * @returns The new music.
*/
Music* music_new(const char* filename);

/**
 * Deletes a music.
 * @param music The music to delete.
*/
void music_delete(Music* music);

/**
 * Plays a music from the beginning.
 * @param music The music to play.
*/
void music_play(Music* music);

/**
 * Plays a music from a certain point in time.
 * @param music The music to play.
 * @param pos_ms The point in time (in milliseconds) to start playing the music.
*/
void music_play_position(Music* music, f64 pos_ms);

/**
 * Plays a music from the beginning with a fade in.
 * @param music The music to play.
 * @param fade The duration of the fade (in milliseconds).
*/
void music_play_fade_in(Music* music, i32 fade);

/**
 * Plays a music from the a certain point in time with a fade in.
 * @param music The music to play.
 * @param fade The duration of the fade (in milliseconds).
 * @param pos_ms The point in time (in milliseconds) to start playing the music.
*/
void music_play_fade_in_position(Music* music, i32 fade, f64 pos_ms);

/**
 * Stops the music.
*/
void music_stop();

/**
 * Pauses the music.
*/
void music_pause();

/**
 * Resumes the music.
*/
void music_resume();

/**
 * Fades out the music.
 * @param fade the duration of the fade (in milliseconds).
*/
void music_fade_out(i32 fade);

/**
 * Sets the number of loops of a music.
 * @param music The music to set the number of loops to.
 * @param loops The number of loops.
 * @note Setting `loops` to -1 will play the music virtually an infinite amount of times.
*/
void music_set_loops(Music* music, i32 loops);

/**
 * Sets the volume of a music.
 * @param music The music to set the volume to.
 * @param volume The volume.
*/
void music_set_volume(Music* music, i32 volume);

/**
 * Returns the volume of a music.
 * @param music The music to get the volume from.
 * @return The volume of the music.
*/
i32 music_get_volume(Music* music);

#endif
