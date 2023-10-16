#include <stdio.h>
int main() {
    int temp = 50;
    printf("Enter a temperature: ");
    scanf("%d",&temp);

    if (temp >= -10 && temp <= 40){
        printf("%dC is a valid temperature.\n",temp);
    } else {
        printf("%dC is an invalid temperature.\n",temp);
    }

    return 0;
}