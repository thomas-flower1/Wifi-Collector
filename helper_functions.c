#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "helper_functions.h"
#include "cell.h"

char* split(char *string, char separator) {

    int index = 0;
    int set = 0;
    
    static char second_half[MAX];
    
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
    /* function that displays a message and returns a string of the user's input*/
    static char user_input[MAX];
    user_input[0] = '\0'; // just clear it every time
    printf("%s", message);
    fgets(user_input, MAX, stdin);
    return user_input;


}
