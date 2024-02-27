#ifndef ENEMY_H
#define ENEMY_H

#include <game/shrimp.h>
#include <engine/scene/sprite.h>

#define NUM_ENEMY_TYPES 1

typedef enum EnemyType {
    ENEMY_TYPE_OIL
} EnemyType;

typedef struct Enemy {
    Sprite* sprite;
    PhysicsObject* physics;
    Shrimp* target;

    EnemyType type;
    f32 speed;
    f32 last_attack;
    f32 attack_cooldown;
} Enemy;

Enemy* enemy_new(Scene* scene, Shrimp* target, EnemyType enemy_type, vec2 pos, bool has_physics);
void enemy_delete(Enemy* enemy);

#endif
