#include <stdio.h>
int main(){
    float principal, rate;
    int years;

    printf("How much money would you like to invest? £");
    scanf("%f",&principal);

    printf("What is the rate of interest? ");
    scanf("%f",&rate);

    printf("How many years are you investing for? ");
    scanf("%d",&years);

    printf("The ammount of interest after investing for %d years is: £%.2f\n",years,principal*rate*years/100);
    return 0;
}