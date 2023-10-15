#include <stdio.h>
int main() {
    int elements[5] = {2,5,7,3,11};
    int i, max = 0;

    for (i=0;i<5;i++){
        if (elements[i] > max){
            max = elements[i];
        }
    }
    printf("The maximum element is %d.\n",max);
    return 0;
}