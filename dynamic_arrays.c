#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dynamic_arrays.h"



/*
File that includes the helper functions to remove and append items to an array

Note that these functions only work with an array of cells


*/


void remove_from_array(Cell *array, int index, int *length) { 
    /*
    
    
    */

    
    if(index < 0 || index >= *length) {
        exit(1);
    }




    for(int i = index + 1; i < *length; i++) {
        array[i-1] = array[i];
    }

    // want to set the value of the last element to an empty cell, even though we should not be accessing it
    Cell empty_cell;
    array[*length-1] = empty_cell;
    *length -= 1;

}


void append_to_array(Cell *array, Cell cell, int *length) {
    /*
    Functions that given a cell array will add a new entry
    If the array is full to a multiple of 5 will resize the array to length + 5
    Takes a length pointer to keep track of the array

    args:


    returns:
    n/a
    
    */

    
    
    array[*length] = cell;
    

    *length += 1;


  

}

void print_cell_array(Cell *array, int length) {
    for(int i = 0; i < length; i++) {
        Cell *cell = &array[i];
        print_cell(cell);
    }


}