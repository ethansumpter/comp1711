#include <stdio.h>
// Includes the math library to use the power function
#include <math.h>

int main(){
    int radius;
    // Includes the value for pi as a constant as it will not need to change during program execution
    const float pi = 3.14159265359;
    printf("Give the radius of a circle: ");
    scanf("%d",&radius);

    // Calculates the area
    double area = pi * pow(radius,2);
    printf("The area of the circle is: %.3f\n",area);
    return 0;
}