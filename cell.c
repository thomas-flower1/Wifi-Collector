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
    if (strcmp(mode, "Ad-Hoc")) {
        return Ad_Hoc;
    } else if(strcmp(mode, "Managed")) {
        return Managed;
    } else if(strcmp(mode, "Master")) {
        return Master;
    } else if(strcmp(mode, "Repeater")){
        return Repeater;
    } else if(strcmp(mode, "Secondary")) {
        return Secondary;
    } else if(strcmp(mode, "Monitor")) {
        return Monitor;
    } else if(strcmp(mode, "Unknown")) {
        return Unknown;
    }
    
    else {
        return Auto;
    }
}

char* encryption_key_to_string(Encryption_key ek) {
    switch (ek){
        case 1:
            return "on";
            
        default:
            return "off";
    }
}


Encryption_key string_to_encryption_key(char *ek){
    if(strcmp(ek, "on")) {
        return on;
    } else {
        return off;
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
