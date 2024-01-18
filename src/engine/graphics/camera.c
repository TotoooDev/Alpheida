#include <engine/graphics/camera.h>

void camera_get_view_matrix(Camera cam, mat4 view) {
    vec3 eye = { cam.pos[0], cam.pos[1], 0.0f };
    vec3 dir = { 0.0f, 0.0f, -1.0f };
    vec3 up = { 0.0f, 1.0f, 0.0f };
    
    glm_mat4_identity(view);
    glm_look(eye, dir, up, view);
}
