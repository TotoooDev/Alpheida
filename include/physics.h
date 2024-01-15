#ifndef PHYSICS_H
#define PHYSICS_H

#include <aabb.h>
#include <types.h>
#include <stdbool.h>

// forward declaration to avoid recursive inclusion hell
typedef struct Sprite Sprite;

typedef struct PhysicsWorld PhysicsWorld;

typedef struct PhysicsObject PhysicsObject;

typedef void(*OnCollisionFunction)(PhysicsObject*, PhysicsObject*, IntersectionAxis);

typedef struct PhysicsObject {
    bool takes_gravity;
    bool is_trigger;
    f32 forces[2];
    f32 velocity[2];
    Sprite* sprite;

    OnCollisionFunction on_collision;
    void* user_pointer;
} PhysicsObject;

PhysicsWorld* physics_new();
void physics_delete(PhysicsWorld* world);

void physics_set_gravity(PhysicsWorld* world, f32* gravity);

void physics_update(PhysicsWorld* world, f32 timestep);

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite);
void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object);

#endif

