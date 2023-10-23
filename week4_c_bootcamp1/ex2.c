#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "squares.dat";
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int total_lines = 0;
    int total = 0;
    float mean = 0;

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total_lines++;
        total += atoi(line_buffer);
    }

    mean = total / total_lines;

    fprintf(file,"%f\n",mean);

    printf("The average of all squares is: %f\n",mean);

    fclose(file);
    return 0;
}