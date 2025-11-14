#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "main_functions.h"
#include "helper_functions.h"



/*
File that contains all the main functions for the Wifi Collector lab project

For assignment 1 this includes:
main_display() - a function that prints the main menu message
quit() - a function that gets user input and asks if they want to quit the program
collect() - a function that gets uer input and adds the specified cell into the array by reading the cells from a file
display() - a function that, given user input, displays the cells with the matching ID
display_all() - displays all the cells in the array

*/


void main_display() {
    /*

    A function that displays the main menu

    Args:
    n/a

    Returns:
    n/a

    */

    printf("[2025] SUCEM S.L. Wifi Collector\n\n");
    printf("[1] wificollector_quit\n");
    printf("[2] wificollector_collect\n");
    printf("[3] wificollector_show_data_one_network\n");
    printf("[4] wificollector_select_best\n");
    printf("[5] wificollector_delete_net\n");
    printf("[6] wificollector_sort\n");
    printf("[7] wificollector_export\n");
    printf("[8] wificollector_import\n");
    printf("[9] wificollector_display\n");
    printf("[10] wificollector_display_all\n\n");

}


int quit() {
    /*

    Asks the user iif they want to quit - if they want to quit return true(1) or return false(0)

    Args:
    n/a

    Returns:
    bool: integer representation of a bool representing if the user want to quit or stay in the program

    */

    char user_input[MAX];
    for(;;) {
        char *user_input = get_user_input("Are ypu sure you want to exit? [y/N]: ");
        if(tolower(user_input[0]) == 'n') {
            return 0;
        } else{
            return 1;
        }

    }
    
}

void collect(Cell **array, int *length) {
    /*

    A function that takes in the  a double pointer of the cells array and the current index and inserts cells, requested by the user, into the array at the next available cell.
    It gets the contents of these cells by reading from the specific file. THe use of the double pointer is to ensure that the global array is changed and not just a copy


    Args:
    **array : a double pointer to the cells array which we want to add more cells into
    *length : a pointer thats the current length of the array

    Returns:
    n/a

    */

    for(;;) {
        
        // getting user input
        char *user_input = get_user_input("What cell do you want to collect? (1 - 21): ");
        int choice = atoi(user_input);

        printf("\n");
        
        // checking if the choice is valid
        if (choice >= 1 && choice <= 21) {
            
            // convert the number to a string
            char user_number[MAX];
            sprintf(user_number, "%d", choice);

            // getting the filename
            char filename[MAX] = "cells/info_cell_";
            strcat(filename, user_number);
            strcat(filename, ".txt");

        
            create_cells_from_file(filename, array, length);
           
            // see if the user wants to add more cells
            strcpy(user_input, get_user_input("Do you want to add another access point? [y:N]: "));
            if(tolower(user_input[0]) == 'n') {
                return;
            }

            printf("\n");
    
        }
          
    }

}

void display(Cell *array) {
    /*

    A function that asks the user for the integer ID of the cell they want to display. If the cell is in the array it will print the contents. 
    The function uses linear search since the array is unsorted. If the cell is not found then we print an error message

    Args:
    *array : a pointer to the cells array

    Returns:
    n/a
    
    */

    for (;;) {
        
        // getting user input
        char *user_input = get_user_input("Indicate the number of the cell for which you want to know its information (1 - 21): ");
        int choice = atoi(user_input);

        printf("\n");

        int found = 0;

        // using linear search to find the corresponding cell (if it exists) - since unordered cannot use binary search
        for(int i = 0; i < ARRAY_SIZE; i++) { // was struggling to get the size of the array using sizeof - can just use array size - both O(N) anyways
            Cell current_cell = array[i];
            if (current_cell.id == choice) {
                print_cell(&current_cell);
                found = 1;
            }

        }

        // if we did not find the cell we print a message to the user
        if (found == 0) {
            printf("Cell not found\n");

        }

        printf("\n");

        // ask the user if they want to quit or not
        strcpy(user_input, get_user_input("Do you want to print the information of another cell? [y/N]: "));
        if(tolower(user_input[0]) == 'n') {
            return;
        }

        printf("\n");

    }
   
}

void display_all(Cell *array, int array_index) {
    /*
    
    A function that displays all the cells currently in the array

    Args:
    n/a

    Returns:
    n/a
    */

    for(int i = 0; i < array_index; i++) {
        print_cell(&array[i]);
    }

    printf("\n");

}


void delete_net(Cell *array, int *length) {
    /*
    Asks the user for the the ESSID that they want to remove - it then uses linear search to find and remove the cell if it exists
    In doing so we resize the array also

    Args:

    Returns:


    
    */


    // need to fixxxxxx and have the remove from array functions

    char *user_input = get_user_input("Indicate the ESSID (use \"\"): ");
    user_input[strlen(user_input)-1] = '\0';



    // then we just linear search the array for a value
    // given a pointer to the start of the array
    for(int i = 0; i < *length; i++) {

        // need to format the ESSID to have the speech marks
        char first[MAX] = "\"";
        char second[MAX] = "\"";

        strcat(first, array[i].ESSID);
        strcat(first, second);
       
        if(strcmp(first, user_input) == 0){

            // use the remove function and also need to check how the array looks
            remove_from_array(array, i, length);
           
            return;
          
        }
    }



}

