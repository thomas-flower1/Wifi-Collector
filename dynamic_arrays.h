#ifndef DYNAMIC_ARRAYS_H
#define DYNAMIC_ARRAYS_H

#define SIZE 5
#include "cell.h"

void remove_from_array(Cell *array, int index, int *length);
void append_to_array(Cell *array, Cell value, int *length);
void print_cell_array(Cell *array, int size);



#endif