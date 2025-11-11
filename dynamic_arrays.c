#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "cell.h"

#define SIZE 5


/*
File that includes the helper functions to remove and append items to an array

Note that these functions only work with an array of cells


*/


void remove_from_array(Cell *array, int index, int *length);
void append_to_array(Cell *array, Cell value, int *length);
void print_cell_array(Cell *array, int size);



int main() {
  

    Cell *array = (Cell*) malloc(SIZE * sizeof(Cell));
    int length = 0;
    int *p_length = &length;
  

    // testing with an array of cells
    for(int i = 0; i < 6; i++) {
        Cell cell;
        cell.id = i;

        append_to_array(array, cell, p_length);
    }

    // checking the size of the array when adding all the elements - should be 6
    printf("The length of the array is: %d\n", length);


    // now checking the size of the array when removeing an element - should be 5
    remove_from_array(array, 3, p_length);
    printf("The length of the array is: %d\n", length);



   
    


    return 0;
}

void remove_from_array(Cell *array, int index, int *length) { 

    // pass an into pointer so that we can change the value of the length

    // shifting all the elements down one, overring a value

    // should throw an error if the index is out of range
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

    if(*length % 5 == 0) {

        // we wanna allocate an extra 5 slots
        array = realloc(array, (*length + 5) * sizeof(Cell));

        // then add the new element
        array[*length] = cell;

    } else {
        array[*length] = cell;
    }


    *length += 1;
    

}

void print_cell_array(Cell *array, int length) {
    for(int i = 0; i < length; i++) {
        Cell *cell = &array[i];
        print_cell(cell);
    }


}