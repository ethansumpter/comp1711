#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA data[200];
char filename[200];

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
char display_menu(){
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
    
    opt = getchar();
    while (getchar() != '\n');
    return opt;
}

FILE* open_file(char *filename, char *mode)
{
    FILE *input = fopen(filename, mode);
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return NULL;
    }
    return input;
}

void read_file() {
    FILE* input_file = open_file(filename,"r");
    char date[11];
    char time[6];
    char steps[10];
    int count = 0;
    int buffer_size = 100;
    char line[buffer_size];

    // Reads through the csv file to the 
    while (fgets(line, buffer_size, input_file)) {
        tokeniseRecord(line,",",date,time,steps);

        strcpy(data[count].date,date);
        strcpy(data[count].time,time);
        data[count].steps = atoi(steps);
        count++;
    }

    // fclose(input_file);
}

int num_records(){
    int counter = 0;
    int buffer_size = 100;
    char line[buffer_size];

    FILE* input_file = open_file(filename,"r");

    // Reads through the csv file to the 
    while (fgets(line, buffer_size, input_file)) {
        counter++;
    }

    // fclose(input_file);
    return counter;
}

int fewest_steps(){
    FILE* input_file = open_file(filename,"r");
    int counter = num_records(input_file);
    int min_steps = 0;

    // Loops through each record for steps and checks if the record is smaller than the current smallest
    for (int i = 1; i < counter; i++) {
        if (data[i].steps < data[min_steps].steps) {
            // Sets the min steps variable as the index value
            min_steps = i;
        }
    }

    // Prints the date and time of min steps
    return min_steps;
}

int most_steps(){
    FILE* input_file = open_file(filename,"r");
    int counter = num_records(input_file);
    int max_steps = 0;

    // Loops through each record to check if the num of steps is greater than current maximum
    for (int i = 1; i < counter; i++) {
        if (data[i].steps > data[max_steps].steps) {
            max_steps = i;
        }
    }

    // Prints the date and time of max steps
    return max_steps;
}

float mean_steps(){
    // FILE* input_file = open_file(filename,"r");
    int counter = num_records();
    int total = 0;
    float mean = 0;

    // Loops through each record to total the number of steps
    for (int i = 0; i < counter; i++) {
        total += data[i].steps;
    }

    mean = total / (float)counter;
    return mean;
}

void longest_period(){
    // FILE* input_file = open_file(filename,"r");
    int counter = num_records();
    int start_pos_temp = 0;
    int temp_cont_steps_count = 0;
    int cont_steps_count = 0;
    int start_pos = 0;

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

    int end_pos = start_pos + cont_steps_count - 1;

    printf("Longest period start: %s %s\n", data[start_pos].date, data[start_pos].time);
    printf("Longest period end: %s %s\n",data[start_pos+cont_steps_count].date,data[end_pos].time);
}


// Complete the main function
int main() {
    char chosen_option;
    FILE* data_file;
    int counter = 0;
    int min_steps;
    int max_steps;
    float mean;

    // Repeats the menu until quit is chosen
    while (1){
        // Displays menu on each iteration of the loop
        chosen_option = display_menu();
        

        switch (chosen_option) {
            // A - Accepts filename
            // Handles a filename and loads in the file to the main program
            case 'A':
            case 'a':
                printf("Input filename: ");
                scanf("%s",filename);
                getchar();

                data_file = open_file(filename, "r");
                
                if (data_file == NULL) {
                    return 1;
                } else {
                    read_file();
                }
                break;

            // B - displays how many records
            case 'B':
            case 'b':

                // read_file(data_file);
                counter = num_records();
                
                // Prints total records as required
                printf("Total records: %d\n",counter);
                break;
            
            // C - fewest steps
            case 'C':
            case 'c':
                min_steps = fewest_steps();
                printf("Fewest steps: %s %s\n",data[min_steps].date,data[min_steps].time);
                break;

            // D - most steps
            case 'D':
            case 'd':
                max_steps = most_steps();
                printf("Largest steps: %s %s\n",data[max_steps].date,data[max_steps].time);
                break;

            // E - mean steps
            case 'E':
            case 'e':
                mean = mean_steps();
                printf("Mean step count: %.0f\n",mean);
                break;

            // F - longest period above 500 steps
            case 'F':
            case 'f':
                longest_period();
                break;

            // Q - quit
            case 'Q':
            case 'q':
                fclose(data_file);
                exit(0);
                break;

            // Option for invalid choice
            default:
                printf("Invalid option chosen\n");

        }

    }

    return 0;
    
}