#include <stdio.h>
int main() {
    int array[5] = {4,5,6,7,8};
    int new_array[5];

    for (int i=0;i<5;i++){
        // Uses the MOD operator to shift array element to the right
        new_array[(i+1)%5] = array[i];
    }

    // Displays array elements of new array for display purposes
    for (int i=0; i<5; i++){
        printf("Array item %d\n",new_array[i]);
    }
    return 0;
}