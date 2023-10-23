#include <stdio.h>
int main(){
    int arr[10];
    int total = 0;
    int i = 0;
    float mean = 0;

    for (int i=0; i<10; i++){
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    printf("Numbers: ");
    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
        total = total + arr[i];
    }

    mean = total / 10;

    printf("\nMean is %f\n",mean);
    return 0;
}