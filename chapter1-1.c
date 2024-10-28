#include <stdio.h>

struct Student {
    int student_id;
    char name[50];
    float mathGrades;
    float englishGrades;
    float computerGrades;
    float totalGrades;
};

int main() {
    struct Student students[3];
    float maxNumberOfGrades = 0;
    int topStudentIndex = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d%s%f%f%f", &students[i].student_id,students[i].name,&students[i].mathGrades,&students[i].englishGrades,&students[i].computerGrades);
        students[i].totalGrades = (students[i].mathGrades + students[i].computerGrades + students[i].englishGrades) / 3;
        if (students[i].totalGrades > maxNumberOfGrades) {
            maxNumberOfGrades = students[i].totalGrades;
            topStudentIndex = i; 
        }
    }
    printf("%s\n", students[topStudentIndex].name);
    return 0;
}

