#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H


#include "cell.h"

int quit();
void collect(Cell **array, int *length);
void delete_net(Cell *array, int *length);
void display(Cell *array);
void display_all(Cell *array, int length);

#endif