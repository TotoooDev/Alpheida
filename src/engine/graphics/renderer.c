#include <engine/graphics/renderer.h>
#include <GL/glew.h>

typedef struct Renderer {
    int foo;
} Renderer;

Renderer* renderer_new() {
    // initialize glew
    GLenum result = glewInit();
    log_assert(result == GLEW_OK, "failed to initialize glew! glew error: %s\n", glewGetErrorString(result));
}

void renderer_delete(Renderer* renderer) {

}
