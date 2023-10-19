#include <stdio.h>

float sphereVol(float rad){
    float pi = 3.14159265359;
    float volume = pi*rad*rad*rad*4/3;
    return volume;
}

int main() {
    float radius = 0;
    printf("Enter a radius: ");
    scanf("%f",&radius);

    printf("The volume of a sphere is %f\n",sphereVol(radius));
    return 0;
}