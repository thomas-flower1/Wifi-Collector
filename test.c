#include <stdio.h>
#include <string.h>

#define MAX 80

char* split(char separator, char string[MAX]) {

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


int main() {

    char *string = "Hello world";

    char* s = split(' ', string);

    printf("%s", s);



    
}