#include <stdio.h>
int main() {
    int my_array[4] = {3,27,51,2};
    int counter;

    for (counter = 0;counter<4;counter++){
        printf("Element %d is %d\n",counter,my_array[counter]);
    }
    return 0;
}