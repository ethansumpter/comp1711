#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter the integer value for variable 1: ");
    scanf("%d",&num1);

    printf("Enter the integer value for variable 2: ");
    scanf("%d",&num2);

    printf("Swapping variables...\n");
    int temp = num1;
    num1 = num2;
    num2 = temp;

    printf("The value of variable 1 is now %d and the value of variable 2 is %d\n",num1,num2);
    return 0;
}