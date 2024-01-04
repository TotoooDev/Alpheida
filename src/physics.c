#include <physics.h>
#include <sprite.h>
#include <array.h>
#include <log.h>
#include <stdlib.h>

#define PHYSICS_MAX_SPRITES 128

typedef struct PhysicsWorld {
    Array* objects;

    float gravity[2];
} PhysicsWorld;

PhysicsWorld* physics_new() {
    PhysicsWorld* world = (PhysicsWorld*)malloc(sizeof(PhysicsWorld));

    world->objects = array_new(PHYSICS_MAX_SPRITES);

    world->gravity[0] = 0.0f;
    world->gravity[1] = -0.981f;

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

bool physics_detect_collisions(PhysicsWorld* world, PhysicsObject* object, PhysicsObject** colliding_object) {
    bool collision_detected = false;

    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* other_object = array_get(world->objects, i);

        if (object == other_object)
            continue;

        collision_detected = aabb_intersect(object->sprite->aabb, other_object->sprite->aabb);
        if (collision_detected) {
            *colliding_object = other_object;
            return true;
        }
    }

    return false;
}

void physics_apply_gravity(PhysicsWorld* world, PhysicsObject* object) {
    if (object->takes_gravity) {
        object->forces[0] += world->gravity[0];
        object->forces[1] += world->gravity[1];
    }
}

void physics_apply_forces(PhysicsObject* object) {
    object->velocity[0] += object->forces[0];
    object->velocity[1] += object->forces[1];
}

void physics_move(PhysicsObject* object) {
    object->sprite->aabb->x += object->velocity[0];
    object->sprite->aabb->y -= object->velocity[1];
}

void physics_reset_forces(PhysicsObject* object) {
    object->forces[0] = 0.0f;
    object->forces[1] = 0.0f;
}

void physics_reset_velocity(PhysicsObject* object) {
    object->velocity[0] = 0.0f;
    object->velocity[1] = 0.0f;
}

void physics_move_intersecting_aabb(AABB* a, AABB* b) {
    IntersectionAxis axis = aabb_get_intersection_axis(a, b);

    switch (axis) {
    case INTERSECTION_AXIS_POSITIVE_Y: {
        float offset = a->y + a->height - b->y;
        a->y -= offset;
        break;
    }

    case INTERSECTION_AXIS_NEGATIVE_Y: {
        float offset = b->y + b->height - a->y;
        a->y += offset;
        break;
    }

    case INTERSECTION_AXIS_POSITIVE_X: {
        float offset = a->x + a->width - b->x;
        a->x -= offset;
        break;
    }

    case INTERSECTION_AXIS_NEGATIVE_X: {
        float offset = b->x + b->width - a->x;
        a->x += offset;
        break;
    }
       
    case INTERSECTION_AXIS_NONE:
        break;
    }
}

void physics_update(PhysicsWorld* world, float timestep) {
    // a really bad """""""physics""""""" simulation
    for (unsigned int i = 0; i < array_get_num_elements(world->objects); i++) {
        PhysicsObject* object = array_get(world->objects, i);
        PhysicsObject* colliding_object = NULL;

        bool collision_detected = physics_detect_collisions(world, object, &colliding_object);

        if (!collision_detected)
            physics_apply_gravity(world, object);

        physics_apply_forces(object);
        physics_move(object);
        physics_reset_forces(object);

        // re-check collisions after moving the objects
        collision_detected |= physics_detect_collisions(world, object, &colliding_object);
        
        if (collision_detected) {
            physics_move_intersecting_aabb(object->sprite->aabb, colliding_object->sprite->aabb);
            physics_reset_velocity(object);
        }
    }
}

PhysicsObject* physics_add_physics_object(PhysicsWorld* world, Sprite* sprite) {
    PhysicsObject* object = (PhysicsObject*)malloc(sizeof(PhysicsObject));

    object->sprite = sprite;
    object->takes_gravity = true;
    object->forces[0] = 0.0f;
    object->forces[1] = 0.0f;
    object->velocity[0] = 0.0f;
    object->velocity[1] = 0.0f;

    sprite->physics_object = object;

    array_add(world->objects, object);

    return object;
}

void physics_remove_physics_object(PhysicsWorld* world, PhysicsObject* object) {
    array_remove(world->objects, object);
    free(object);
}

