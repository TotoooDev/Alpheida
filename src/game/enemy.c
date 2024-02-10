#include <game/enemy.h>
#include <engine/event.h>
#include <engine/graphics/texture.h>
#include <engine/platform/fs.h>
#include <stdlib.h>

static bool first_create = true;
static Texture* enemy_textures[NUM_ENEMY_TYPES];

void enemy_init_textures() {
    enemy_textures[ENEMY_TYPE_OIL] = texture_new(fs_get_path_romfs("images/oil.png"));
}

void enemy_delete_textures() {
    texture_delete(enemy_textures[ENEMY_TYPE_OIL]);
}

void enemy_on_event(void* e, EventType event_type, void* user_pointer) {
    if (event_type == EVENT_TYPE_PLATFORM_QUIT)
        enemy_delete_textures();
}

void enemy_update(Sprite* sprite, float timestep) {
    Enemy* enemy = (Enemy*)sprite->user_pointer;

    vec2 direction;
    glm_vec2_sub(enemy->target->pos, enemy->sprite->pos, direction);

    enemy->sprite->pos[0] += direction[0] * enemy->speed * timestep;

    if (enemy->physics != NULL)
        enemy->sprite->pos[1] += direction[1] * enemy->speed * timestep;
}

Enemy* enemy_new(Scene* scene, Sprite* target, EnemyType enemy_type, vec2 pos, bool has_physics) {
    Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));

    if (first_create) {
        enemy_init_textures();
        first_create = false;
    }

    enemy->sprite = sprite_new(pos, (vec2){ 64.0f, 64.0f }, enemy_textures[enemy_type]);
    enemy->physics = NULL;
    enemy->target = target;
    enemy->type = enemy_type;
    enemy->speed = 5.0f;

    if (has_physics) {
        enemy->physics = physics_add_physics_object(scene_get_physics_world(scene), enemy->sprite);
        enemy->physics->filter = physics_add_filter(1);
    }

    enemy->sprite->update_function = enemy_update;
    enemy->sprite->user_pointer = enemy;

    event_add_function(NULL, enemy_on_event);

    return enemy;
}

void enemy_delete(Enemy* enemy) {
    free(enemy);
}
