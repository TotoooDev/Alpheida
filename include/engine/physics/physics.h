#ifndef PHYSICS_H
#define PHYSICS_H

#include <engine/physics/aabb.h>
#include <engine/types.h>
#include <engine/cglm/cglm.h>
#include <stdbool.h>

// forward declaration to avoid recursive inclusion hell
typedef struct Sprite Sprite;

typedef struct PhysicsWorld PhysicsWorld;

typedef struct PhysicsObject PhysicsObject;

typedef void(*OnCollisionFunction)(PhysicsObject*, PhysicsObject*, IntersectionAxis);

typedef struct PhysicsObject {
    bool takes_gravity;
    bool moved_by_collision;
    bool is_trigger;
    
    u32 filter;
    u32 trigger_filter;
    vec2 forces;
    vec2 velocity;
    AABB aabb;

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

u32 physics_set_all_filters();
u32 physics_add_filter(u32 num_filter);

#endif

