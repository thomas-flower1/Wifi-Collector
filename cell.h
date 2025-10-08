#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#include "main_functions.h"
#include "helper_functions.h"



typedef enum {
    Auto,
    Ad_Hoc,
    Managed,
    Master,
    Repeater,
    Secondary,
    Monitor,
    Unknown

} Mode;


typedef enum {
    off,
    on

} Encryption_key;

typedef struct {
    int first;
    int second;

} Quality;

typedef struct {
    int id;
    char address[MAX];
    char ESSID[MAX];
    Mode mode;
    int channel;
    Encryption_key encryption_key;  // could make an enum
    Quality quality;
    double frequency;
    int signal_level;

} Cell;


void print_cell(Cell *cell);
Mode string_to_mode(char *mode);

char* encryption_key_to_string(Encryption_key ek);
Encryption_key string_to_encryption_key(char *ek);

#endif