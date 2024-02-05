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
    Shrimp* target;

    EnemyType type;
} Enemy;

Enemy* enemy_new(Shrimp* target, EnemyType enemy_type, vec2 pos);
void enemy_delete(Enemy* enemy);

#endif
