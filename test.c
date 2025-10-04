#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 80

char* split(char string[MAX], char separator) {

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





void collect() {
    Cell arr[100] = {0}; // need to make this global or  sort of static
    static int arr_index = 0; // want this to be a kind of global variable


    char user_input[MAX];
    int choice = 2; // placeholder for now
    
    // checking if the choice is valid
    if (choice >= 1 && choice <= 21) {
        
        char filename[MAX] = "cells/info_cell_2.txt";
       
        printf("Network read from %s (added to position %d of the array)\n", filename, arr_index);

    
        // dealing with the file
        FILE *rf = fopen(filename, "r"); 


        Cell current_cell;
        char current_line[MAX];
        int line_number = 1; // will iterate from 1-9
        
        while(fgets(current_line, MAX, rf) != NULL) {

            // really didn't like this solution, if seek worked like python would've been easier
            switch (line_number) {
                case 1:
                    // case when it is just the cell name, need to extract the number
                    char *cell_num = split(current_line, ' '); // should return the number
                    int i_cell_num = atoi(cell_num);
                    current_cell.cell_number = i_cell_num;
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
                    strcpy(current_cell.mode, mode);
                    break;
                
                case 5:
                    char *channel = split(current_line, ':');
                    int i_channel = atoi(channel);
                    current_cell.channel = i_channel;
                    break;
                
                case 6:
                    // the encryption key
                    char *encryption_key = split(current_line, ':');
                    encryption_key[strlen(encryption_key)-1] = '\0'; // get rid of the newline character
                    strcpy(current_cell.encryption_key, encryption_key);
                    break;
                
                case 7:
                    // quality 
                    char *quality = split(current_line, '='); // will return a string like 50/90
                    quality[strlen(quality)-1] = '\0'; // get rid of the newline character
                 
                    char first_num[3]; // need 3 for the null terminating char
                    char second_num[3];
                    for (int i = 0; i < 2; i++) {
                        first_num[i] = quality[i];
                        second_num[i] = quality[i+3];
                    }  

                    int first = atoi(first_num);
                    int second = atoi(second_num);


                    current_cell.quality_1 = first;
                    current_cell.quality_2 = second;
                    
                    break;
                
                case 8:
                    char *frequency = split(current_line, ':');
                    char f[6];
                    for (int i = 0; i < 5; i++){
                        f[i] = frequency[i];

                    }
                    float freq = atof(f);
                    current_cell.frequency = freq;
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
                    current_cell.signal_level = s;
                default:
                    break;
            }


            // if we have finished with the cell in the file
            if (line_number == 9) {

                arr[arr_index] = current_cell; // add to the list
                current_cell = (Cell){0}; // reset the cell
                line_number = 1; // reset the cell line
                arr_index++; // increment the index of the arr of cells

                
            }  else {
                line_number ++;
            }


        }

        fclose(rf);

        printf("Cell num: %i\n", arr[0].signal_level);

    
    }



}



int main() {
    collect();



    return 0;




    
}