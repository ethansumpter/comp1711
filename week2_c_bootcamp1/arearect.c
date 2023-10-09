#include <stdio.h>

int main(){
    float length, width;

    // Always remember & in front of variable when using scanf
    // Ampersand required to give the address of the variable 
    // Arrays don't require an ampersand before
    printf("Enter the length of a rectangle: ");
    scanf("%f", &length);

    printf("Enter the length of a width: ");
    scanf("%f", &width);

    // Gives area to 3dp
    // Format specifier %g auto formats number to the correct number of dp
    float area = length * width;
    printf("The area of a rectangle is %g\n",area);

    return 0;
}