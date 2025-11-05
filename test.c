#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct person {
    char *name;
    int age;

} person;


void remove_element(int *array, int index_to_remove, int length);
void print_array(int *array, int size);


int main() {

    // person *array = calloc(SIZE, sizeof(person));

    int *array = calloc(SIZE, sizeof(int));
    for(int i = 0; i < SIZE; i++) {
        array[i] = i;
    }

  
    remove_element(array, 2, 5 );


    return 0;
}

void remove_element(int *array, int index_to_remove, int length) { 

    print_array(array, length);

    for(int i = index_to_remove + 1; i < length; i++) {
        array[i-1] = array[i];
    }
    printf("\n");

    print_array(array, length);


}

void print_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("The current element is: %d\n", array[i]);
    }


}