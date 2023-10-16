#include <stdio.h>
int main() {
    int value = 0;
    while (value != -1) {
        printf("Enter a value: ");
        scanf("%d",&value);

        if (value >= 0 && value <= 100) {
            printf("The value %d is within range.\n",value);
        } else {
            printf("The value %d is out of range.\n",value);
        }
    }
    printf("The program has now ended.\n");
    return 0;
}