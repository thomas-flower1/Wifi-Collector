#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "cell.h"

char* mode_to_string(Mode mode){
    // given a number will return the string that the mode is associated with
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
    switch (ek){
        case 0:
            return "on";
            
        default:
            return "off";
    }
}


Encryption_key string_to_encryption_key(char *ek){
    if(strcmp(ek, "on")) {
        return ON;
    } else {
        return OFF;
    }
}



void print_cell(Cell *cell) {

    // need to ge the string version of the mode
    char *mode = mode_to_string(cell->mode);

    // need to get the string version of the encryption key also
    char *ek = encryption_key_to_string(cell->encryption_key);


    printf("id=[%d] mac=[%s] essid=[\"%s\"] mode=[%i (%s)] channel=[%d] key=[%d (%s)] q=[n1=%d n2=%d]\n", cell->id, cell->address, cell->ESSID, 
        cell->mode, mode, cell->channel, cell->encryption_key, ek, cell->quality.first, cell->quality.second);
    
}
