#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include <engine/scene.h>
#include <game/shrimp.h>
#include <game/enemy.h>
#include <game/life.h>

typedef struct MainScene {
    Scene* scene;
    Shrimp* shrimp;
    Enemy* test_enemy;
    Life* life;

    // temporary
    Sprite* ground;
} MainScene;

MainScene* mainscene_new();
void mainscene_delete(MainScene* scene);

#endif
