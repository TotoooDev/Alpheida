#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array Array;

Array* array_new(unsigned int max_elements);
void array_delete(Array* array);

void array_add(Array* array, void* element);
void array_remove(Array* array, void* element);
void array_remove_index(Array* array, unsigned int index);

void* array_get(Array* array, unsigned int index);
unsigned int array_get_index(Array* array, void* element);

unsigned int array_get_num_elements(Array* array);
unsigned int array_get_max_elements(Array* array);

#endif

