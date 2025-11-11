#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H


#include "cell.h"

int quit();
void collect();
void main_display();
void display_all(Cell *array, int array_index);
void display(Cell *array);
void delete_net(Cell *array, int *length);

#endif