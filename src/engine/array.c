#include <engine/array.h>
#include <engine/log.h>
#include <stdlib.h>

typedef struct Array {
    void** elements;
    u32 num_elements;
    u32 max_elements;
} Array;

Array* array_new(u32 max_elements) {
    Array* array = (Array*)malloc(sizeof(Array));

    array->elements = (void**)malloc(sizeof(void*) * (size_t)max_elements);
    for (u32 i = 0; i < max_elements; i++)
        array->elements[i] = NULL;

    array->num_elements = 0;
    array->max_elements = max_elements;

    return array;
}

void array_delete(Array* array) {
    free(array->elements);
    free(array);
}

void array_add(Array* array, void* element) {
    log_assert(array->num_elements < array->max_elements, "failed to add element %p into array! the array limit was reached.\n", element);
    array->elements[array->num_elements] = element;
    array->num_elements++;
}

void array_remove(Array* array, void* element) {
    u32 element_index = array_get_index(array, element);
    array_remove_index(array, element_index);
}

void array_remove_index(Array* array, u32 index) {
    log_assert(index < array->num_elements, "failed to remove index %p from array! the index was unused.\n", index);
    
    for (u32 i = index; i < array->num_elements; i++) {
        array->elements[i] = array->elements[i + 1];
    }
    array->elements[array->num_elements] = NULL;

    array->num_elements--;
}

void* array_get(Array* array, u32 index) {
    log_assert(index < array->num_elements, "failed to retrieve index %d in array! the index was unused.\n", index);
    return array->elements[index];
}

u32 array_get_index(Array* array, void* element) {
    for (u32 i = 0; i < array->num_elements; i++) {
        if (array->elements[i] == element) {
            return i;
        }
    }
    log_assert(false, "failed to find element %p in array! it's not in the array.\n", element);
    return 69; // just so gcc is happy
}

u32 array_get_num_elements(Array* array) {
    return array->num_elements;
}

u32 array_get_max_elements(Array* array) {
    return array->max_elements;
}

