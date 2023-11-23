
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

// FILE *open_file(char *filename, char *mode)
// {
//     FILE *input = fopen(filename, mode);
//     if (!input)
//     {
//         printf("Error: File could not be opened\n");
//         return NULL;
//     }
//     return input;
// }

// void read_file(FILE *input_file, FITNESS_DATA[100] data) {
    
// }


#endif // FITNESS_DATA_STRUCT_H