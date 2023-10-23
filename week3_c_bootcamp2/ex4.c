#include <stdio.h>

int isPrime(int num){
    int prime,result = 1;
    // IF MOD OF ANYTHING OTHER THAN 1 OR ITSELF
    // == 0 THEN IT IS NOT PRIME
    
    for (int i=2;i>(num-1);i++){
        result = num % i;
        printf("%d MOD %d = Result: %d\n",num,i,result);
        if (result == 0) {
            prime = 0;
        }
    }

    if (prime == 1) {
        printf("%d is a prime\n",num);
    } else {
        printf("%d is not a prime\n",num);
    }

}

int main(){

    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    isPrime(num);

}