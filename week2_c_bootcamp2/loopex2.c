#include <stdio.h>
int main(){
    int a = 11;
    while (a <= 1000) {
        printf("a = %d\n",a);
        a += 11;
    }
    return 0;
}