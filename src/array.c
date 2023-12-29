#include <array.h>
#include <log.h>
#include <stdlib.h>

typedef struct Array {
    void** elements;
    unsigned int num_elements;
    unsigned int max_elements;
} Array;

Array* array_new(unsigned int max_elements) {
    Array* array = (Array*)malloc(sizeof(Array));

    array->elements = (void**)malloc(sizeof(void*) * (size_t)max_elements);
    for (unsigned int i = 0; i < max_elements; i++)
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
    unsigned int element_index = array_get_index(array, element);
    array_remove_index(array, element_index);
}

void array_remove_index(Array* array, unsigned int index) {
    log_assert(index < array->num_elements, "failed to remove index %p from array! the index was unused.\n", index);
    
    for (unsigned int i = index; i < array->num_elements; i++) {
        array->elements[i] = array->elements[i + 1];
    }
    array->elements[array->num_elements] = NULL;

    array->num_elements--;
}

void* array_get(Array* array, unsigned int index) {
    log_assert(index < array->num_elements, "failed to retrieve index %d in array! the index was unused.\n", index);
    return array->elements[index];
}

unsigned int array_get_index(Array* array, void* element) {
    for (unsigned int i = 0; i < array->num_elements; i++) {
        if (array->elements[i] == element) {
            return i;
        }
    }
    log_assert(false, "failed to find element %p in array! it's not in the array.\n", element);
    return 69; // just so gcc is happy;
}

unsigned int array_get_num_elements(Array* array) {
    return array->num_elements;
}

unsigned int array_get_max_elements(Array* array) {
    return array->max_elements;
}

