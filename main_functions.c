#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#include "main_functions.h"
#include "helper_functions.h"
#include "cell.h"


int quit() {
    // asks the user if they want to quit

    char user_input[MAX];
    for(;;) {
        printf("Are you sure you want to exit? [y/n]: ");

        fgets(user_input, MAX, stdin);

        char choice = toupper(user_input[0]);
        if (choice == 'Y') {
            return 1; // true

        } else if (choice == 'N') {
            return 0;

        }

    }
    
}

void collect() {

    static Cell arr[ARRAY_SIZE]; // an array that will hold all the cells
    static int arr_index = 0; // want this to be a kind of global variable

    for(;;) {

        char *user_input = get_user_input("What cell do you want to collect? (1-21): ");
        int choice = atoi(user_input);
        
        // checking if the choice is valid
        if (choice >= 1 && choice <= 21) {
            
            // convert the number to a string
            char user_number[MAX];
            sprintf(user_number, "%d", choice);

            // getting the filename
            char filename[MAX] = "cells/info_cell_";
            strcat(filename, user_number);
            strcat(filename, ".txt");
            
            // printing the message
            printf("Network read from %s (added to position %d of the array)\n", filename, arr_index);

           

            

            // // then now we need to print and format these cells
            // for(int cell_index = start_index; cell_index < end_index; cell_index++) {
            //     Cell cell = arr[cell_index];
            //     printf("id=[%d] mac=[%s] essid=[\"%s\"] mode=[3 (%s)] channel=[%d] key=[0 (%s)] q=[n1=%d n2=%d]\n\n", cell.cell_number, cell.address, cell.ESSID, cell.mode, cell.channel, cell.encryption_key, cell.quality_1, cell.quality_2);
            // }


            // char access_point[MAX];
            // printf("Do you want to add another access point? [y:N]: ");
            // fgets(access_point, MAX, stdin);

            // char selection = access_point[0];
            // // then check for what character they selected
            // if (selection == 'n') {
            //     return;

            // }



    
        }
          
    }

}


void create_cells_from_file(char *filename, Cell *array, int arr_index) {
    /*
    A function that reads a cell file and creates cell objects and adds them to an array

    Args:
    filename: string name of the file to read from
    array: an array that will hold the cells
    arr_index: the next empty index in which we want to add the cell into

    Returns:

    n/a
    
    */

    // dealing with the file
    FILE *rf = fopen(filename, "r"); 

    // if file doesn't exist just return
    if (rf == NULL){
        return;
    }

    // then we want to read from the given file
    Cell current_cell;
    char current_line[MAX]; // current line we are reading
    int line_number = 1; // will go from 1-9

    // using this to keep track of what cells were just added and hence what we need to display to the console
    int start_index = arr_index; 
    int end_index = -1;

    while(fgets(current_line, MAX, rf) != NULL) {
     
        switch (line_number) {
            case 1:
                // case when it is just the cell name, need to extract the number
                char *cell_num = split(current_line, ' '); // should return the number
                int i_cell_num = atoi(cell_num);
                current_cell.id = i_cell_num;

                break;

            case 2:
                char *address = split(current_line, ' ');
                address[strlen(address)-1] = '\0'; // get rid of the newline character
                strcpy(current_cell.address, address); 
                break;
            
            case 3:
                char *essid = split(current_line, '"');
                essid[strlen(essid)-1] = '\0'; // get rid of the newline character
                strcpy(current_cell.ESSID, essid);
                break;
            
            case 4:
                char *mode = split(current_line, ':');
                mode[strlen(mode)-1] = '\0'; // get rid of the newline character
                current_cell.mode = string_to_mode(mode);
                break;
            
            // case 5:
            //     char *channel = split(current_line, ':');
            //     int i_channel = atoi(channel);
            //     current_cell.channel = i_channel;
            //     break;
            
            // case 6:
            //     // the encryption key
            //     char *encryption_key = split(current_line, ':');
            //     encryption_key[strlen(encryption_key)-1] = '\0'; // get rid of the newline character
            //     strcpy(current_cell.encryption_key, encryption_key);
            //     break;
            
            // case 7:
            //     // quality 
            //     char *quality = split(current_line, '='); // will return a string like 50/90
            //     quality[strlen(quality)-1] = '\0'; // get rid of the newline character
            
            //     char first_num[3]; // need 3 for the null terminating char
            //     char second_num[3];
            //     for (int i = 0; i < 2; i++) {
            //         first_num[i] = quality[i];
            //         second_num[i] = quality[i+3];
            //     }  

            //     int first = atoi(first_num);
            //     int second = atoi(second_num);


            //     current_cell.quality_1 = first;
            //     current_cell.quality_2 = second;
                
            //     break;
            
            // case 8:
            //     char *frequency = split(current_line, ':');
            //     char f[6];
            //     for (int i = 0; i < 5; i++){
            //         f[i] = frequency[i];

            //     }
            //     float freq = atof(f);
            //     current_cell.frequency = freq;
            //     break;
            
            // case 9:
            //     // the signal level
            //     char *signal = split(current_line, '=');

            //     char sig[4];
            //     for(int i = 0; i < 3; i++){
            //         sig[i] = signal[i];
            //     }

            //     sig[3] = '\0';
            //     int s = atoi(sig);
            //     current_cell.signal_level = s;
            default:
                break;
        }


        // if we have finished with the cell in the file
        if (line_number == 9) {
            array[arr_index] = current_cell; // add to the list
            current_cell = (Cell){0}; // reset the cell
            line_number = 1; // reset the cell line
            arr_index++; // increment the index of the arr of cells

            
        }  else {
            line_number ++;
        }


    }

        fclose(rf);
        end_index = arr_index;
}

void main_display() {

    // function that prints the main menu to the users

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
    printf("[10] wificollector_display_all\n");

}


int main() {

    Cell array[100];
    create_cells_from_file("cells/info_cell_9.txt", array, 0);
    printf("%d\n", array[1].mode);


    return 0;
}