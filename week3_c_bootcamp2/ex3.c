#include <stdio.h>

// int str_len(char str[20]){
//     int len;


    
//     while (str[len] != "\0"){
//         len+=1;
//     }
//     return len;
// }

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);

    for (int i=0;i<4;i++){
        printf("%s\n",str[i]);
    }

    // printf("The length of the string %s is %d characters.",str,str_len(str));
    return 0;
}