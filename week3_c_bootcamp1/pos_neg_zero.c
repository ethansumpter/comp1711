#include <stdio.h>
int main() {
    int value;

    printf("Enter a value: ");
    scanf("%d",&value);

    if (value > 0) {
        printf("The value %d is positive.\n",value);
    } else if (value < 0) {
        printf("The value %d is negative.\n",value);
    } else {
        printf("The value entered is zero.\n");
    }

    return 0;
}