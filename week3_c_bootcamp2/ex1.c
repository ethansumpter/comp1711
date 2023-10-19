#include <stdio.h>

float circleArea(float rad){
    float pi = 3.14159265359;
    return pi * rad * rad;
}

int main() {
    float radius;
    printf("Enter a radius: ");
    scanf("%f",&radius);

    printf("The area of the circle is %f\n",circleArea(radius));
    return 0;

}