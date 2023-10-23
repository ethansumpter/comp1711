#include <stdio.h>
int square(int num){
    return num*num;
}
int main() {
    char *filename = "squares.dat";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int max;
    printf("Enter a number to use as a maximum: ");
    scanf("%d",&max);

    for (int i=1; i<=max; i++){
        fprintf(file, "%d\n",square(i));
    }

    fclose(file);
    return 0;
}