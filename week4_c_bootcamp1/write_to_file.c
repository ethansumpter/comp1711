#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    int num_lines = 10;
    int total =0;
    float mean;

    printf("How many lines of numbers to enter? ");
    scanf("%d",&num_lines);
    
    printf("Type %d numbers: ", num_lines);
    
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        total += number;
        fprintf(file, "%d\n", number);

    }

    mean = total/num_lines;
    printf("Mean is %f",mean);

    fclose(file);
    return 0;
}