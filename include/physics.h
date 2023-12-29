#ifndef PHYSICS_H
#define PHYSICS_H

#include <sprite.h>

typedef struct PhysicsWorld PhysicsWorld;

PhysicsWorld* physics_new();
void physics_delete(PhysicsWorld* world);

void physics_add_sprite(PhysicsWorld* world, Sprite* sprite);
void physics_remove_sprite(PhysicsWorld* world, Sprite* sprite);

void physics_set_gravity(PhysicsWorld* world, float* gravity);

void physics_update(PhysicsWorld* world, float timestep);

#endif

