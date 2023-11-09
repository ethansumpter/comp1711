#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

// Function to display menu items and accept the menu choice
char displayMenu(){
    char opt;
    printf("\nMenu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n\n");
    printf("Enter choice: ");
    scanf(" %c",&opt);

    return opt;

}



// Complete the main function
int main() {
    // Defines variables
    char chosenOption,filename[100],date[11],time[6],steps[10];
    FITNESS_DATA data[100];
    int buffer_size = 100,counter=0,min_steps=0,max_steps=0,total=0,start_pos =0,start_pos_temp=0, cont_steps_count = 0, temp_cont_steps_count = 0;
    char line[buffer_size];

    // Repeats the menu until quit is chosen
    do{
        // Displays menu on each iteration of the loop
        chosenOption = displayMenu();
        

        switch (chosenOption) {
            // A - Accepts filename
            // Handles a filename and loads in the file to the main program
            case 65:
                printf("Input filename: ");
                scanf("%s",filename);

                FILE *data_file = fopen(filename, "r");
                if (data_file == NULL) {
                    // Displays an error with the file and quits the program
                    printf("Error: Could not find or open the file.\n");
                    return 1;
                } else{
                    printf("File successfully loaded.\n");
                }

                break;

            // B - displays how many records
            case 66:

                // Reads through the csv file to the 
                while (fgets(line,buffer_size,data_file)) {
                    tokeniseRecord(line,",",date,time,steps);

                    strcpy(data[counter].date,date);
                    strcpy(data[counter].time,time);
                    data[counter].steps = atoi(steps);

                    counter++;
                }
                
                // Prints total records as required
                printf("Total records: %d\n",counter);
                break;
            
            // C - fewest steps
            case 67:

                // Loops through each record for steps and checks if the record is smaller than the current smallest
                for (int i = 1; i < counter; i++) {
                    if (data[i].steps < data[min_steps].steps) {
                        // Sets the min steps variable as the index value
                        min_steps = i;
                    }
                }

                // Prints the date and time of min steps
                printf("Fewest steps: %s %s\n",data[min_steps].date,data[min_steps].time);
                break;

            // D - most steps
            case 68:

                // Loops through each record to check if the num of steps is greater than current maximum
                for (int i = 1; i < counter; i++) {
                    if (data[i].steps > data[max_steps].steps) {
                        max_steps = i;
                    }
                }

                // Prints the date and time of max steps
                printf("Largest steps: %s %s\n",data[max_steps].date,data[max_steps].time);
                break;

                break;

            // E - mean steps
            case 69:

                // Loops through each record to total the number of steps
                for (int i = 0; i < counter; i++) {
                    total += data[i].steps;
                }
                printf("Mean step count: %d\n",total/counter);
                break;

            // F - longest period above 500 steps
            case 70:

                for (int i = 0; i < counter; i++) {
                    if (data[i].steps > 500) {
                        if (data[i-1].steps <= 500) {
                            start_pos_temp = i;
                        }
                        temp_cont_steps_count++;
                        if (temp_cont_steps_count > cont_steps_count) {
                            start_pos = start_pos_temp;
                            cont_steps_count = temp_cont_steps_count;
                        } 

                    } else {
                        temp_cont_steps_count = 0;
                    }

                }

                printf("Longest period start: %s %s\n", data[start_pos].date, data[start_pos].time);
                printf("Longest period end: %s %s\n",data[start_pos+cont_steps_count].date,data[start_pos+cont_steps_count].time);

                break;

            // Q - quit
            case 81:
                exit(0);
                break;

            // Option for invalid choice
            default:
                printf("Invalid option chosen\n");

        }

    // Loops the menu sequence until the user quits
    } while (chosenOption != 81);

    
   
}








