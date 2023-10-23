#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Number of characters which will be read per line
    int buffer_size = 100;
    // A string which will hold each line as its read in
    char line_buffer[buffer_size];

    // An arbitary large value
    int numbers[1000];

    int total_lines = 0;

    // While there is still data in the file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
        numbers[total_lines] = atoi(line_buffer);
        total_lines++;
    }

    printf("There were %d lines\n",total_lines);

    fclose(file);
    return 0;
}