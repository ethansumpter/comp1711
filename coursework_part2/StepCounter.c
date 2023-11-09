#include "FitnessDataStruct.h"

char displayMenu(){
    char opt;
    printf("Please select an option from the following menu:\n");
    printf("A: Enter a filename to import from\n");
    printf("B: Display total number of records in the file\n");
    printf("C: Display when the fewest steps were\n");
    printf("D: Display when the most steps were\n");
    printf("E: Show the mean step count\n");
    printf("F: Display longest continuous period when the step count is above 500 steps\n");
    printf("Q: Quit\n\n");
    printf("Chosen option: ");
    scanf("%c",&opt);

    return opt;

}

int main() {

    char chosenOption = displayMenu();

    switch (chosenOption) {
        case 65:
            printf("Chosen option A");
            break;
        case 66:
            printf("Chosen option B");
            break;
        case 67:
            printf("Chosen option C");
            break;
        case 68:
            printf("Chosen option D");
            break;
        case 69:
            printf("Chosen option E");
            break;
        case 70:
            printf("Chosen option F");
            break;
        case 81:
            printf("Chosen option Q");
            break;
        default:
            printf("Incorrect option chosen");

    }
    
    // printf("%c",chosenOption);
    return 0;

}