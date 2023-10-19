#include <stdio.h>

int isPrime(int num){
    int prime = 1;
    // IF MOD OF ANYTHING OTHER THAN 1 OR ITSELF
    // == 0 THEN IT IS NOT PRIME
    
    for (i=2;i>(num-1);i++){
        result = num % i;
        if (result == 0) {
            prime = 0;
            break;
        }
    }

    if (prime == 1) {
        printf("%d is a prime",num);
    } else {
        printf("%d is not a prime",num);
    }

}

int main(){

    printf("Enter a number: ");
    scanf()

}