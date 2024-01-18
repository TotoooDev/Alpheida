#ifndef CAMERA_H
#define CAMERA_H

#include <engine/cglm/cglm.h>
#include <engine/types.h>

typedef struct Camera {
    vec2 pos;
    f32 angle;
} Camera;

void camera_get_view_matrix(Camera cam, mat4 view);

#endif
