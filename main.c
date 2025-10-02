#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX 80

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


                break;



                default:
                    break;


            }

           

           
        }
    }


   



    return 0;
}