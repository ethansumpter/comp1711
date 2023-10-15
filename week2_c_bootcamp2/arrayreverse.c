#include <stdio.h>
int main() {
    int array[5] = {2,4,6,8,10};
    int array_reversed[5];

    for (int i=0; i<5; i++){
        array_reversed[4-i] = array[i];
    }

    for (int i=0; i<5; i++){
        printf("Array item %d\n",array_reversed[i]);
    }
    return 0;
}