#ifndef PHYSICS_H
#define PHYSICS_H

#include <stdbool.h>

// forward declaration to avoid recursive inclusion hell
typedef struct Sprite Sprite;

typedef struct PhysicsWorld PhysicsWorld;

typedef struct PhysicsObject {
    bool takes_gravity;
    float forces[2];
    float velocity[2];
    Sprite* sprite;
} PhysicsObject;

PhysicsWorld* physics_new();
void physics_delete(PhysicsWorld* world);

void physics_add_object(PhysicsWorld* world, PhysicsObject* object);
void physics_remove_object(PhysicsWorld* world, PhysicsObject* object);

void physics_set_gravity(PhysicsWorld* world, float* gravity);

void physics_update(PhysicsWorld* world, float timestep);

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite);
void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object);

#endif

