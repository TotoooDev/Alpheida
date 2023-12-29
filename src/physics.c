#include <physics.h>
#include <array.h>

#define PHYSICS_MAX_SPRITES 128

typedef struct PhysicsWorld {
    Array* sprites;

    float gravity[2];
} PhysicsWorld;

PhysicsWorld* physics_new() {
    PhysicsWorld* world = (PhysicsWorld*)malloc(sizeof(PhysicsWorld));

    world->sprites = array_new(PHYSICS_MAX_SPRITES);

    world->gravity[0] = 0.0f;
    world->gravity[1] = -9.81f;

    return world;
}

void physics_delete(PhysicsWorld* world) {
    array_delete(world->sprites);
    free(world);
}

void physics_add_sprite(PhysicsWorld* world, Sprite* sprite) {
    array_add(world->sprites, sprite);
}

void physics_remove_sprite(PhysicsWorld* world, Sprite* sprite) {
    array_remove(world->sprites, sprite);
}

void physics_set_gravity(PhysicsWorld* world, float* gravity) {
    world->gravity[0] = gravity[0];
    world->gravity[1] = gravity[1];
}

void physics_update(PhysicsWorld* world, float timestep) {
    // do things here
}

