#include <stdio.h>
// Creates a function to calculate the factorial of an input
int factorial(int num){
    int result = 1;
    // Loops through each number from the value entered to 2 and multiplies them together to get the factorial value
    for (int i=2;i<=num;i++){
        result *= i;
    }
    return result;
}
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    printf("The factorial of %d is %d\n",num,factorial(num));
    return 0;
}