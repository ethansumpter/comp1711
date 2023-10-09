#include <stdio.h>

int main()
{
    // Creates 15 slots of memory for 15 characters
    char name[15];
    printf("Hello, please enter your name: ");

    // This will get the data from the user as a string format and store it in a variable.
    scanf("%s", name);
    printf("Your name is %s\n", name);

    return 0;
}