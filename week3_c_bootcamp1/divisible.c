#include <stdio.h>
int main() {
    int value;

    printf("Enter a value: ");
    scanf("%d",&value);

    if (((value % 4) == 0) && ((value % 5) == 0)) {
        printf("The value %d is divisible by both 4 and 5.\n",value);
    }
    else if ((value % 4) == 0) {
        printf("The value %d is divisible by 4.\n",value);
    }
    else if ((value % 5) == 0) {
        printf("The value %d is divisible by 5.\n",value);
    }
    else {
        printf("The value %d is not divisible by either 4 or 5.\n",value);
    }

    return 0;
}