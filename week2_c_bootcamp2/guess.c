#include <stdio.h>

int main(){
    int ans = 5, num, i;
    int correct = 0;

    while (correct != 1){
        printf("Enter a number between 1 and 20 to guess the right number: ");
        scanf("%d",&num);
        if (num == ans){
            correct = 1;
        }
    }
    printf("Answer is correct!\n");
    return 0;
}