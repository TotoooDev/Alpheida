#ifndef NEW_SCENE_H
#define NEW_SCENE_H

#include <scene.h>

typedef struct NewScene NewScene;

NewScene* newscene_new();
void newscene_delete(NewScene* scene);

Scene* newscene_get_scene(NewScene* scene);

#endif

