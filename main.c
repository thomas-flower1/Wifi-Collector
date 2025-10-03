#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define MAX 80
#define ARRAY_SIZE 100




typedef struct {

    int cell_number;
    char address[MAX];
    char ESSID[MAX];
    char mode[MAX];
    int channel;
    char encryption_key[MAX];  // could make an enum
    int quality_1;
    int quality_2;
    double frequency;
    int signal_level;


} Cell;

char* split(char string[MAX], char separator) {

    int index = 0;
    int set = 0;

    static char second_half[MAX];

    for(int i = 0; i < strlen(string); i++) {
       
      

        if(string[i] == separator || set) {
            set = 1; // true
            second_half[index] = string[i];
            index ++;

        }

    }

    return second_half;



}


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

    char user_input[MAX];
    char arr[ARRAY_SIZE][MAX];
    static int index = 0; // want this to be a kind of global variable


    for(;;) {

        printf("What cell do you want to collect? (1-21): ");
        fgets(user_input, MAX, stdin);

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
            printf("Network read from %s (added to position %d of the array)\n", filename, index);

            index ++;


            // dealing with the file
            FILE *rf = fopen(filename, "r"); 

            // if file doesn't exist just return
            if (rf == NULL){
                return;
            }



            // then we want to read from the given file
            char current_line[MAX];
            int line_number = 1;

            Cell current_cell;
            while(fgets(current_line, MAX, rf) != NULL) {

                // really didn't like this solution, if seek worked like python would've been easier
                switch (line_number)
                {
                case 1:
                    // case when it is just the cell name, need to extract the number
                    char *cell_num = split(current_line, ' '); // should return the number
                    int i_cell_num = atoi(cell_num);

                    printf("%d\n", i_cell_num);
                    current_cell.cell_number = i_cell_num;


                    
                    break;
                case 2:

                    // for the address we again can look split on the whitespace
                    char *address = split(current_line, ' ');

                    strcpy(current_cell.address, address);
                    printf("%s\n", current_cell.address);
                    
                    break;
                
                case 3:
                    /* code */
                    break;
                
                case 4:
                    /* code */
                    break;
                
                case 5:
                    /* code */
                    break;
                
                case 6:
                    /* code */
                    break;
                
                case 7:
                    /* code */
                    break;
                
                case 8:
                    /* code */
                    break;
                
                case 9:
                    /* code */
                    break;
                
                default:
                    break;
                }
               
                line_number ++;
                
                if (line_number == 9) {
                    // reset the index and also add the cell to the array
                    line_number = 1;
                }
                
              




            }

            







          

        }




    }
}


int main() {


    char user_input[MAX];


    // the main loop
    for(;;) {
        // print the message to the user
        printf("[2025] SUCEM S.L. Wifi Collector\n\n");

        printf("[1] wificollector_quit\n");
        printf("[2] wificollector_collect");
        printf("[3] wificollector_show_data_one_network\n");
        printf("[4] wificollector_select_best\n");
        printf("[5] wificollector_delete_net\n");
        printf("[6] wificollector_sort\n");
        printf("[7] wificollector_export\n");
        printf("[8] wificollector_import\n");
        printf("[9] wificollector_display\n");
        printf("[10] wificollector_display_all\n");

        printf("Option: ");

        // getting the user input
        fgets(user_input, MAX, stdin);  

        // now checking for valid input
        int choice = atoi(user_input);
        if (choice <= 10 && choice > 0) {

            switch(choice) {
                case 1:
                    int val = quit();

                    // quit early
                    if (val == 1) {
                        printf("Goodbye !\n");

                        return 0;
                    }
                
                break;

                case 2:
                    collect();


                break;



                default:
                    break;


            }

           

           
        }
    }


   



    return 0;
}