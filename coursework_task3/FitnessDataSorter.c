#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

FitnessData data[100];
char filename[100];

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
    fclose(input_file);
}

int num_records(){
    int counter = 0;
    int buffer_size = 100;
    char line[buffer_size];

    FILE* input_file = open_file(filename,"r");

    while (fgets(line, buffer_size, input_file)) {
        counter++;
    }

    return counter;
}

int compare_steps(const void* a, const void* b){

    const FitnessData *data_a = (const FitnessData*)a;
    const FitnessData *data_b = (const FitnessData*)b;

    int steps_a = data_a->steps;
    int steps_b = data_b->steps;

    if (steps_b > steps_a) {
        return 1; // steps_b is greater than steps_a
    } else if (steps_a > steps_b) {
        return -1; // steps_a is greater than steps_b
    } else {
        return 0; // if steps_a and steps_b are equal
    }

}

int main() {


    FILE* data_file;
    FILE* output_file;
    int counter;
    char filename_tsv[100] = "";


    printf("Enter Filename: ");
    scanf("%s",filename);

    data_file = open_file(filename, "r");

    if (data_file == NULL) {
        return 1;
    } else {
        read_file();
    }

    counter = num_records();

    fclose(data_file);

    qsort(data, (size_t)counter, sizeof(FitnessData), compare_steps);

    strcpy(filename_tsv,filename);
    strcat(filename_tsv,".tsv");

    output_file = open_file(filename_tsv,"w");

    printf("Data sorted and written to %s\n",filename_tsv);
    for (int i = 0; i<counter; i++){
        fprintf(output_file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(output_file);
    

    return 0;
    
    
}