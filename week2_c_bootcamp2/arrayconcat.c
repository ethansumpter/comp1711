#include <stdio.h>
int main() {
    int array1[3]={4,5,6};
    int array2[3]={7,8,9};
    int newarray[6];

    for (int i=0;i<3;i++){
        newarray[i] = array1[i];
    }
    for (int i=0;i<3;i++){
        newarray[i+3] = array2[i];
    }
    for (int i=0;i<6;i++){
        printf("%d ",newarray[i]);
    }
    return 0;
}