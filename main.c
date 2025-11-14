#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "main_functions.h"
#include "helper_functions.h"
#include "cell.h"

#define SIZE 5


int main() {
    Cell *array = malloc(SIZE * sizeof(Cell));
    int length = 0;
    int *p_length = &length;

   
    // the main loop
    for(;;) {


        // display the main message
        main_display(); 

        // getting the user input
        char *user_input = get_user_input("Option: ");
        int choice = atoi(user_input); // convert the input to an int

        printf("\n");
        
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
                collect(&array, p_length);

            break;

            case 4:

            break;

            case 5:
                delete_net(array, p_length);

            break;


            case 6:

            break;

            case 7:

            break;

            case 8:

            break;


            case 9:
                // display(array);
            break;


            case 10:
                display_all(array, length);
            break;



            default:
                break;


        }

      
    }
   
    return 0;
}