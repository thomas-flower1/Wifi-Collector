#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "cell.h"

char* mode_to_string(Mode mode){
    /*

    Function that given the mode(enum) will return the string representation. If not matches will return "Auto" by default

    Args:
    mode : Enum mode which we want to convert

    Returns:
    char * : string representation of the enum
    
    */

    switch (mode)
    {
    case 1:
        return "Ad-Hoc";
    case 2:
        return "Managed";
    case 3:
        return "Master";
    case 4:
        return "Repeater";
    case 5:
        return "Secondary";
    case 6:
        return "Monitor";
    case 7:
        return "Unknown";

    default:
        return "Auto";
    }

}

Mode string_to_mode(char *mode) {
    /*

    Function that given the string representation of the mode will return the mode enum. Note that the function is case sensitive.

    Args:
    *mode : string representation of the mode

    Returns:
    Mode : Mode enum of the inputted string
    
    */

    if (strcmp(mode, "Ad-Hoc") == 0) {
        return AD_HOC;
    } else if(strcmp(mode, "Managed") == 0) {
        return MANAGED;
    } else if(strcmp(mode, "Master") == 0) {
        return MASTER;
    } else if(strcmp(mode, "Repeater")== 0){
        return REPEATER;
    } else if(strcmp(mode, "Secondary") == 0) {
        return SECONDARY;
    } else if(strcmp(mode, "Monitor") == 0) {
        return MONITOR;
    } else if(strcmp(mode, "Unknown")== 0) {
        return UNKNOWN;
    }
    
    else {
        return AUTO;
    }
}

char* encryption_key_to_string(Encryption_key ek) {
    /*

    Function that converts an Encryption Key (Enum) into a string representation
    Note that 0 is on and 1 is off in this version

    Args:
    ek : the Encryption Key Enum which we wish to covert

    Returns:
    char* : string representation of the Enum
    
    */
    switch (ek){
        case 0:
            return "on";
        
        case 1:
            return "off";
            
        default:
            return "off";
    }

}

Encryption_key string_to_encryption_key(char *ek){
    /*

    Function that coverts a string to an Encryption Key Enum. If the string doesn't match will default to OFF. Note that the function is case sensitive.

    Args:
    *ek : string representation of the Encryption Key

    Returns:
    Encryption Key : Encryption Key Enum representation of the string
    
    */


    if(strcmp(ek, "on") == 0) {
        return ON;
    } else {
        return OFF;
    }
}

void print_cell(Cell *cell) {
    /*

    A function that when given a cell will print out its id, address, ESSID, mode, channel, encryption key and quality.
    Note that it will not print the signal and frequency as they were not included in the example output file.

    Args:
    *cell : pointer to the cell object we wish to print

    Returns:
    n/a
    
    */

    // need to ge the string version of the mode
    char *mode = mode_to_string(cell->mode);

    // need to get the string version of the encryption key also
    char *ek = encryption_key_to_string(cell->encryption_key);

    printf("id=[%d] mac=[%s] essid=[\"%s\"] mode=[%i (%s)] channel=[%d] key=[%d (%s)] q=[n1=%d n2=%d]\n", cell->id, cell->address, cell->ESSID, 
        cell->mode, mode, cell->channel, cell->encryption_key, ek, cell->quality.first, cell->quality.second);
    
}
