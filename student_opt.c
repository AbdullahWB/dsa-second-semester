#include <stdio.h>

struct Student {
    char name[50];
    int student_id;
    float mathGrades;
    float computerGrades;
    float englishGrades;
    float totalGrades;
};

int main() {
    struct Student students[3];
    float maxNumberOfGrades = 0;
    int topStudentIndex = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter student ID: ");
        scanf("%d", &students[i].student_id);
        printf("Enter math grades: ");
        scanf("%f", &students[i].mathGrades);
        printf("Enter computer grades: ");
        scanf("%f", &students[i].computerGrades);
        printf("Enter english grades: ");
        scanf("%f", &students[i].englishGrades);

        students[i].totalGrades = (students[i].mathGrades + students[i].computerGrades + students[i].englishGrades) / 3;

        printf("Average grades: %.2f\n", students[i].totalGrades);

        if (students[i].totalGrades > maxNumberOfGrades) {
            maxNumberOfGrades = students[i].totalGrades;
            topStudentIndex = i; 
        }
    }

    printf("\nStudent with the highest average grades:\n");
    printf("Name: %s\n", students[topStudentIndex].name);
    printf("ID: %d\n", students[topStudentIndex].student_id);
    printf("Total Grade: %.2f\n", students[topStudentIndex].totalGrades);

    return 0;
}
