#include <engine/platform/config.h>
#ifdef SHRIMP_SWITCH

#include <engine/graphics/opengl/gl_loader.h>
#include <engine/log.h>

void glloader_init_gl() {
    int ret = gladLoadGL();
    log_assert(ret != 0, "failed to initialize glad!\n");
}

#endif
