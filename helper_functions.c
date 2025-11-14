#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "helper_functions.h"
#include "cell.h"


void create_cells_from_file(char *filename, Cell **array, int *length) {
    /*

    A function that reads a cells from a file and allocates the values to a predefined empty array of cells.
    The use of a double pointer is to allow us to change the array pointer and not a copy of the array pointer

    Args:
    filename : string name of the file to read from
    array : an array that will hold the cells
    arr_index : the next empty index in which we want to add the cell into

    Returns:
    n/a
    
    */

    // dealing with the file
    FILE *rf = fopen(filename, "r"); 

    // if file doesn't exist just return
    if (rf == NULL){
        return;
    }

    Cell *p_array = *array; // a pointer to the a
    Cell *current_cell = &p_array[*length]; // a pointer to the current cell


    char current_line[MAX]; // current line we are reading
    int line_number = 1; // will go from 1-9

    while(fgets(current_line, MAX, rf) != NULL) {
       

     
        switch (line_number) {
            case 1:
                // case when it is just the cell name, need to extract the number
                char *cell_num = split(current_line, ' '); // should return the number
                int i_cell_num = atoi(cell_num);
                current_cell->id = i_cell_num;

                break;

            case 2:
                char *address = split(current_line, ' ');
                address[strlen(address)-1] = '\0'; // get rid of the newline character
                strcpy(current_cell->address, address); 
                break;
            
            case 3:
                char *essid = split(current_line, '"');
                essid[strlen(essid)-1] = '\0'; // get rid of the newline character
                strcpy(current_cell->ESSID, essid);
                break;
            
            case 4:
                char *mode = split(current_line, ':');
                mode[strlen(mode)-1] = '\0'; // get rid of the newline character
                current_cell->mode = string_to_mode(mode);
                break;
            
            case 5:
                char *channel = split(current_line, ':');
                int i_channel = atoi(channel);
                current_cell->channel = i_channel;
                break;
            
            case 6:
                char *encryption_key = split(current_line, ':');
                encryption_key[strlen(encryption_key) - 1] = '\0';
                current_cell->encryption_key = string_to_encryption_key(encryption_key);
                break;
            
            case 7:
                char *quality = split(current_line, '='); // will return a string like 50/90
                quality[strlen(quality)-1] = '\0'; // get rid of the newline character
            
                char first_num[3]; // need 3 for the null terminating char
                char second_num[3];
                for (int i = 0; i < 2; i++) {
                    first_num[i] = quality[i];
                    second_num[i] = quality[i+3];
                }  


                first_num[2] = '\0';
                second_num[2] = '\0';

                int first = atoi(first_num);
                int second = atoi(second_num);

                current_cell->quality.first = first;
                current_cell->quality.second = second;
                break;
            
            case 8:
                char *frequency = split(current_line, ':');
                char f[6];
                for (int i = 0; i < 5; i++){
                    f[i] = frequency[i];

                }
                float freq = atof(f);
                current_cell->frequency = freq;
                break;
            
            case 9:
                // the signal level
                char *signal = split(current_line, '=');

                char sig[4];
                for(int i = 0; i < 3; i++){
                    sig[i] = signal[i];
                }

                sig[3] = '\0';
                int s = atoi(sig);
                current_cell->signal_level = s;
                break;


            default:
                break;
        }


        // if we have finished with the cell in the file
        if (line_number == 9) {

            line_number = 1; // reset the cell line

            *length += 1;

            if(*length % 5 == 0 && *length != 0) {
                printf("* * * Allocating another 5 positions in the dynamic array * * *\n");

            
               // use the double pointer to redefine the array pointer in the main function
                *array = realloc(*array, (*length + 5) * sizeof(Cell));
                p_array = *array;


            } 

            printf("Network read from %s (added to position %d of the array)\n", filename, *length-1);
            print_cell(current_cell);
            printf("\n");
            

            current_cell = &p_array[*length];
           

        } else {
            line_number ++;
        }


    }
        fclose(rf);


        
}

char* split(char *string, char separator) {
    /*

    A function that takes a string and a char separator and returns the part of the string after the separator.
    Example "hello world" with separator ' ' would return "world"
    
    
    Args:
    *string : the string we want to split
    separator: the char we separate the string on

    Returns:
    char * : the string after the separator

    */

    int index = 0;
    int set = 0;
    
    static char second_half[MAX];
    second_half[0] = '\0';
    
    for(int i = 0; i < strlen(string); i++) {
       
      if(string[i] == separator) {
            set = 1; // true
        
        } else if (set) {
            second_half[index] = string[i];
            index ++;
        }

    }
    second_half[index] = '\0';
    return second_half;

}

char *get_user_input(char *message) {
    /*

    Function that displays a message and returns a string of the user's input

    Args:
    *string : the string we want to display when getting user input

    Returns:
    char* : the string the user entered
    
    */

    static char user_input[MAX];
    user_input[0] = '\0'; // just clear it every time
    printf("%s", message);
    fgets(user_input, MAX, stdin);
    return user_input;


}
