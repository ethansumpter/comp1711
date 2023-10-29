#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line_buffer[100];
    int numbers[200];
    int i = 0;
    int count = 0;

    
    while (fgets(line_buffer, 100, input) != NULL) {
        // Atoi converts a string to an integer
        numbers[i] = atoi(line_buffer);
        i++;
    }

    for (int i=0; i<200; i++){
        printf("%d\n",numbers[i]);
        if (numbers[i] >= 1000) {
            count++;
        }
    }

    fclose(input);

    printf("There are %d lines with numbers over 1000.\n",count);

    return 0;

}