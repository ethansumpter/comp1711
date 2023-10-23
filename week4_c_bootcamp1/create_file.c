#include "utils.h"

int main () {

    char* filename = "data.txt";
    FILE *file = open_file(filename,"w");

    fprintf(file, "Hello world!\n");

    fclose(file);
    return 0;
}