#ifndef ARRAY_H
#define ARRAY_H

/**
 * A fixed size array structure.
*/
typedef struct Array Array;

/**
 * Creates a new array.
 * @param max_elements The size of the array (the maximum number of elements).
 * @returns The new array.
*/
Array* array_new(unsigned int max_elements);

/**
 * Deletes an array.
 * @param array The array to delete.
*/
void array_delete(Array* array);

/**
 * Adds an element to the array.
 * @param array The array to add the element into.
 * @param element The element to add.
*/
void array_add(Array* array, void* element);

/**
 * Removes an element from the array.
 * @param array The array to remove the element from.
 * @param element The element to remove.
*/
void array_remove(Array* array, void* element);

/**
 * Removes an element from an array based on its index.
 * @param array The array to remove the element from.
 * @param index The index of the element to remove.
*/
void array_remove_index(Array* array, unsigned int index);

/**
 * Returns the element at a certain index.
 * @param array The array to get the element from.
 * @param index The index of the element to get.
*/
void* array_get(Array* array, unsigned int index);

/**
 * Returns the index of an element in the array.
 * @param array The array to get the index from.
 * @param element The element to get the index of.
*/
unsigned int array_get_index(Array* array, void* element);

/**
 * Returns the current number of elements.
 * @param array The array to get the number of elements from.
*/
unsigned int array_get_num_elements(Array* array);

/**
 * Returns the maximum number of elements.
 * @param array The array to get the maximum number of elements from.
*/
unsigned int array_get_max_elements(Array* array);

#endif

