#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {

    struct student new_student = {};

    printf("Enter your name: ");
    // Allows a space within the string input to avoid storing surname in student ID
    scanf("%[^\n]s",new_student.name); 

    printf("Enter your Student ID: ");
    scanf("%s",new_student.student_id);

    printf("Enter your mark: ");
    scanf("%u",&new_student.mark);

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}