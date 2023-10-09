#include <stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    // Finds the modulus of the number when divided by 2
    if ((num % 2) == 0) {
        printf("The number %d is even\n",num);
    } else {
        printf("The number %d is odd\n",num);
    }

    return 0;
}