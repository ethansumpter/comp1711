#include <stdio.h>

int main() {
    float a;
    float b = 4.641;
    float c;

    a = 2.897;
    c = a + b;

    // When a float and a float are added together the value is retuned as an integer yet truncated.
    // The .f will restrict the output to 3 decimal places.
    printf("The sum of %f and %f is %.3f\n", a, b, c);

    return 0;
}