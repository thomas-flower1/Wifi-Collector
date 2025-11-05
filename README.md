Systems Architecture project for uc3m

First assignment submission for the "Wifi Collector" Project. 

Group: Thomas Flowers, Jackson Strauss

The project assumes that the file tree looks like this:

Wifi_Collector
├── cell.c
├── cell.h
├── cells
│   ├── info_cell_10.txt
│   ├── info_cell_11.txt
│   ├── info_cell_12.txt
│   ├── info_cell_13.txt
│   ├── info_cell_14.txt
│   ├── info_cell_15.txt
│   ├── info_cell_16.txt
│   ├── info_cell_17.txt
│   ├── info_cell_18.txt
│   ├── info_cell_19.txt
│   ├── info_cell_1.txt
│   ├── info_cell_20.txt
│   ├── info_cell_21.txt
│   ├── info_cell_2.txt
│   ├── info_cell_3.txt
│   ├── info_cell_4.txt
│   ├── info_cell_5.txt
│   ├── info_cell_6.txt
│   ├── info_cell_7.txt
│   ├── info_cell_8.txt
│   └── info_cell_9.txt
├── helper_functions.c
├── helper_functions.h
├── main.c
├── main_functions.c
├── main_functions.h
├── Makefile
├── output_file
└── README.md


Files
main - contains the main loop and calls the main functions
main_functions - contains the implementations of quit, collect, display, display_all
helper_functions - contains functions to help the main functions
cell - contains the cell class and methods associated with it


It can be compiled using 'make' and executed using './main' or alternatively using 'make run' to compile and run. 

The project can also be seen on my GitHub: https://github.com/thomas-flower1/Wifi-Collector

