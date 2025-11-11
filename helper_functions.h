#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "cell.h"

char* split(char *string, char separator);
char *get_user_input(char *message);
void create_cells_from_file(char *filename, Cell *array, int *length);


#endif