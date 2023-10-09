#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");

    // Scans for the address of agewhen there is an & symbol in front of the variable.
    scanf("%d", &age);
    printf("Your age is %d\n", &age);

    return 0;
}