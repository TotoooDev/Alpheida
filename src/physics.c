#include <physics.h>
#include <sprite.h>
#include <array.h>

#define PHYSICS_MAX_SPRITES 128

typedef struct PhysicsWorld {
    Array* objects;

    float gravity[2];
} PhysicsWorld;

PhysicsWorld* physics_new() {
    PhysicsWorld* world = (PhysicsWorld*)malloc(sizeof(PhysicsWorld));

    world->objects = array_new(PHYSICS_MAX_SPRITES);

    world->gravity[0] = 0.0f;
    world->gravity[1] = -9.81f;

    return world;
}

void physics_delete(PhysicsWorld* world) {
    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        physics_remove_physics_object(world, array_get(world->objects, i));
    }

    array_delete(world->objects);
    free(world);
}

void physics_set_gravity(PhysicsWorld* world, float* gravity) {
    world->gravity[0] = gravity[0];
    world->gravity[1] = gravity[1];
}

void physics_update(PhysicsWorld* world, float timestep) {
    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* object = array_get(world->objects, i);

        // detect collisions
        bool collision_detected = false;
        for (unsigned int ii = 0; ii < array_get_num_elements(world->objects); ii++) {
            PhysicsObject* other_object = array_get(world->objects, ii);

            if (object == other_object)
                continue;

            collision_detected = aabb_intersect(object->sprite->aabb, other_object->sprite->aabb);
        }
        
        if (!collision_detected && object->takes_gravity) {
            // apply gravity
            // i have to subtract from the y axis because for some fucking reason the sdl positive y axis is down (?????)
            object->sprite->aabb->x += (int)world->gravity[0];
            object->sprite->aabb->y -= (int)world->gravity[1];
        };
    }
}

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite) {
    PhysicsObject* object = (PhysicsObject*)malloc(sizeof(PhysicsObject));

    object->sprite = sprite;
    sprite->physics_object = object;

    array_add(world->objects, object);

    return object;
}

void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object) {
    array_remove(world->objects, object);
    free(object);
}

