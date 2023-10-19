#include <stdio.h>

int str_len(char str[20]){

}

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);

    printf("The length of the string %s is %d characters.",str,str_len(str));
    return 0;
}