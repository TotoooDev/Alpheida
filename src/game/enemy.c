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

Enemy* enemy_new(Shrimp* target, EnemyType enemy_type, vec2 pos) {
    Enemy* enemy = (Enemy*)malloc(sizeof(Enemy));

    if (first_create) {
        enemy_init_textures();
        first_create = false;
    }

    enemy->sprite = sprite_new(pos, (vec2){ 64.0f, 64.0f }, enemy_textures[enemy_type]);
    enemy->target = target;
    enemy->type = enemy_type;

    return enemy;
}

void enemy_delete(Enemy* enemy) {
    free(enemy);
}
