#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    char name[50];
    int age;
};

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Check if memory allocation was successful
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    // Input student data
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter age of student %d: ", i + 1);
        scanf("%d", &(students[i].age));
    }

    // Display student data
    printf("\nStudent Data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: Name: %s, Age: %d\n", i + 1, students[i].name, students[i].age);
    }

    // Use pointer arithmetic to modify the values of structure members
    // Let's add 1 to the age of the first student using pointer arithmetic
    struct Student* firstStudent = students; // Point to the first element of the array
    firstStudent->age += 1;

    // Display the updated data of the first student
    printf("\nAfter modifying the age of the first student:\n");
    printf("Student 1: Name: %s, Age: %d\n", firstStudent->name, firstStudent->age);

    // free the dynamically allocated memory when it's no longer needed
    free(students);

    return 0;
}
