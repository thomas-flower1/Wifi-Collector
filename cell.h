#ifndef CELL_H
#define CELL_H

#define MAX 80
#define ARRAY_SIZE 200 

typedef enum {
    AUTO,
    AD_HOC,
    MANAGED,
    MASTER,
    REPEATER,
    SECONDARY,
    MONITOR,
    UNKNOWN

} Mode;


typedef enum {
   ON,
   OFF
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
    Encryption_key encryption_key;  
    Quality quality;
    double frequency;
    int signal_level;

} Cell;


void print_cell(Cell *cell);
Mode string_to_mode(char *mode);

char* encryption_key_to_string(Encryption_key ek);
Encryption_key string_to_encryption_key(char *ek);

#endif