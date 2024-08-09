#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int studentCount;

    // Ask the user for the number of students
    printf("Enter the number of students: ");
    scanf("%d", &studentCount);

    // Allocate memory for arrays based on the number of students
    int *midterm1 = malloc(studentCount * sizeof(int));
    int *midterm2 = malloc(studentCount * sizeof(int));
    int *final = malloc(studentCount * sizeof(int));
    float *avg = malloc(studentCount * sizeof(float));
    char **names = malloc(studentCount * sizeof(char*));

    // Check if memory allocation was successful
    if (midterm1 == NULL || midterm2 == NULL || final == NULL || avg == NULL || names == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get student names and grades from the user
    for (int i = 0; i < studentCount; i++) {
        // Allocate memory for each student's name
	// Assuming a maximum name length of 100 characters
        names[i] = malloc(100 * sizeof(char));

        // Check if memory allocation was successful
        if (names[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the name of Student %d: ", (i + 1));
        scanf("%s", names[i]);

        printf("Enter the exam-1 grade for %s: ", names[i]);
        scanf("%d", &midterm1[i]);
        printf("Enter the exam-2 grade for %s: ", names[i]);
        scanf("%d", &midterm2[i]);
        printf("Enter the final grade for %s: ", names[i]);
        scanf("%d", &final[i]);
    }

    // Print headers
    printf("\nGrade Point Average(s) for %d Student(s)\n\n", studentCount);
    printf("Name          Exam-1   Exam-2  Final   Average\n");
    printf("***********************************************\n");

    // Calculate and print grades
    for (int i = 0; i < studentCount; i++) {
        avg[i] = ((midterm1[i] * 0.3) + (midterm2[i] * 0.3) + (final[i] * 0.4));
        printf("%-10s %7d %7d %7d %10.2f\n", names[i], midterm1[i], midterm2[i], final[i], avg[i]);

        // Free allocated memory for each student's name
        free(names[i]);
    }

    // Free allocated memory for arrays
    free(midterm1);
    free(midterm2);
    free(final);
    free(avg);
    free(names);

    return 0;
}
