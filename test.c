#include <stdio.h>
#include <stdlib.h>


#define SIZE 5

typedef struct Cell {
    char *name;
    int id;

} Cell;


void resize(Cell **arr, int *length) {
    *arr = realloc(*arr, sizeof(Cell) * (5 + SIZE));

}




int main(){

    Cell *arr = (Cell*) malloc(SIZE * sizeof(Cell));
    int length = 0;



    for(int i = 0; i < SIZE; i++) {
        Cell *current_cell = &arr[i]; // getting a pointer to the cell
        current_cell -> id = i;
        current_cell -> name = "Hello world";

        length ++;
        


    }

    // lets print the array so far
    for(int i = 0; i < length; i++) {
        printf("Name: %s and the ID: %d\n", arr[i].name, arr[i].id);
    }

    resize(&arr, &length);

    for(int i = length; i < 10; i++) {
        Cell *current_cell = &arr[i]; // getting a pointer to the cell
        current_cell -> id = i;
        current_cell -> name = "Hello world";

        length ++;
        

    }


    free(arr);





    return 0;

}



