#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "main_functions.h"
#include "helper_functions.h"
#include "cell.h"



int main() {

    // the main loop
    for(;;) {
        main_display(); // printing the menu prompts to the user
        char *user_input = get_user_input("Option: ");
        int choice = atoi(user_input); // convert the input to a number
        
        
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


   
    return 0;
}