#include <stdio.h>

int main(){
    int fahrenheit;
    float celsius;
    
    printf("Enter a value in fahrenheit: ");
    scanf("%d",&fahrenheit);

    // Calculates the celsius value of the fahrenheit value and gives in 1dp.
    celsius = ((fahrenheit-32) * 5) /9;
    printf("%dF is equivelent to %.1fC\n",fahrenheit,celsius);
    return 0;
}