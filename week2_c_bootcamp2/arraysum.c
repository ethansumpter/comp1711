#include <stdio.h>
int main() {
    int array[5] = {5,2,6,3,8};
    int count,total =0;

    for (count=0;count<=4;count++){
        total += array[count];
    }

    printf("Total from array: %d\n",total);
    return 0;
}