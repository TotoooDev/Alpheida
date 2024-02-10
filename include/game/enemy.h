#ifndef ENEMY_H
#define ENEMY_H

#include <game/shrimp.h>
#include <engine/sprite.h>

#define NUM_ENEMY_TYPES 1

typedef enum EnemyType {
    ENEMY_TYPE_OIL
} EnemyType;

typedef struct Enemy {
    Sprite* sprite;
    PhysicsObject* physics;
    Sprite* target;

    EnemyType type;
    float speed;
} Enemy;

Enemy* enemy_new(Scene* scene, Sprite* target, EnemyType enemy_type, vec2 pos, bool has_physics);
void enemy_delete(Enemy* enemy);

#endif
