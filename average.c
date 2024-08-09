#include <stdio.h>

int main() {
    int exam1, exam2;
    float semester_grade;

    printf("\nEnter midterm grade: "); scanf("%d", &exam1);
    printf("Enter final grade: "); scanf("%d", &exam2);

    semester_grade = exam1*0.4 + exam2*0.6;

    printf("\nGrade point average: %f", semester_grade);
    printf("\n");
}
