#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct person {
    char *name;
    int age;

} person;


void remove_from_array(int *array, int index, int *length);
void append_to_array(int *array, int value, int *length);
void print_array(int *array, int size);



int main() {

    int length = 0; // we will be updating this throughout the program
    int *p_length = &length;
    int *array = calloc(SIZE, sizeof(int));
    

    for(int i = 0; i < SIZE; i++) {
        length += 1;
        array[i] = i;
    }

    printf("The length of the array is: %d\n", length);
    print_array(array, length);

    printf("\n");

    remove_from_array(array, 1, p_length);
    printf("The length of the array is: %d\n", length);
    print_array(array, length);
    
    printf("\n");
    append_to_array(array, 1, p_length);
    printf("The length of the array is: %d\n", length);
    print_array(array, length);






    


    return 0;
}

void remove_from_array(int *array, int index, int *length) { 

    // pass an into pointer so that we can change the value of the length

    // shifting all the elements down one, overring a value
    for(int i = index + 1; i < *length; i++) {
        array[i-1] = array[i];
    }

    *length -= 1;

}


void append_to_array(int *array, int value, int *length) {

    // since we are passing in the length the index of the next value it the length


    if(*length % 5 == 0) {

        // we wanna allocate an extra 5 slots
        array = realloc(array, *length + 5);

        // then add the new element
        array[*length] = value;

    } else {
        array[*length] = value;
    }


    *length += 1;
    

}

void print_array(int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("The current element is: %d\n", array[i]);
    }


}