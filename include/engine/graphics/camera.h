#ifndef CAMERA_H
#define CAMERA_H

#include <engine/cglm/cglm.h>
#include <engine/types.h>

/**
 * A simple camera struct.
 * @note The `angle` property is currently unused.
*/
typedef struct Camera {
    vec2 pos;
    f32 angle;
} Camera;

/**
 * Calculates the view matrix of the camera.
 * @param cam The camera to use for the calculations.
 * @param view The matrix in which the view matrix will be inserted.
*/
void camera_get_view_matrix(Camera cam, mat4 view);

#endif
