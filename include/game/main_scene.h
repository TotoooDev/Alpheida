#ifndef MAIN_SCENE_H
#define MAIN_SCENE_H

#include <scene.h>
#include <game/shrimp.h>

typedef struct MainScene {
    Scene* scene;
    Shrimp* shrimp;

    // temporary
    Sprite* ground;
} MainScene;

MainScene* mainscene_new();
void mainscene_delete(MainScene* scene);

#endif
