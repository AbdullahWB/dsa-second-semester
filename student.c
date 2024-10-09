#include <stdio.h>

struct Student
{
    char name[50];
    int student_id;
    float mathGrades;
    float computerGrades;
    float englishGrades;
    float totalGrades;
};

int main()
{
    struct Student students[3];
    for(int i = 0; i < 3; i++){
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
        printf("\n");
        float averageGrades = (students[i].mathGrades + students[i].computerGrades + students[i].englishGrades) / 3;
        students[i].totalGrades = averageGrades;
        printf("Average grades: %.2f\n", students[i].totalGrades);
    }
    float maxNumberOfGrades = 0;
    for(int i = 0; i < 3; i++){
        float totalGrades = (students[i].mathGrades + students[i].computerGrades + students[i].englishGrades) / 3;
        if(totalGrades > maxNumberOfGrades){
            maxNumberOfGrades = totalGrades;
        }
    }
    for(int i = 0; i < 3; i++){
        if(students[i].totalGrades == maxNumberOfGrades){
            printf("Student with the highest average grades: \n name: %s\n id: %d \n total grad: %.2f", students[i].name, students[i].student_id, students[i].totalGrades);
            break;
        }
    }
    return 0;
}