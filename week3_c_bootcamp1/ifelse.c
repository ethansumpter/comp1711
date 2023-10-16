#include <stdio.h>
int main() {
    int mark;
    printf("Enter the mark of your test: ");
    scanf("%d",&mark);

    if (mark >=0 && mark <= 100) {
        if (mark >= 70){
            printf("The mark of %d is a first\n",mark);
        } else if (mark >= 60){
            printf("The mark of %d is a 2:1\n",mark);
        } else if (mark >= 40){
            printf("The mark of %d is a pass\n",mark);
        } else {
            printf("The mark of %d is a fail\n",mark);
        }
    } else {
        printf("The mark entered is invalid.\n");
    }

    return 0;
}