#include <game/shrimp.h>
#include <fs.h>

Shrimp* shrimp_new(Scene* scene) {
    Shrimp* shrimp = (Shrimp*)malloc(sizeof(Shrimp));

    Texture* texture = texture_new(fs_get_path_romfs("images/shrimp.png"));
    shrimp->sprite = sprite_new(0.0f, 0.0f, 64.0f, 64.0f, texture);

    physics_add_physics_object(scene_get_physics_world(scene), shrimp->sprite);

    return shrimp;
}

void shrimp_delete(Shrimp* shrimp) {
    texture_delete(shrimp->sprite->texture);
    sprite_delete(shrimp->sprite);
    free(shrimp);
}
