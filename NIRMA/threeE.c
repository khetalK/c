#include <stdio.h>

int main() {
    double classTestMarks = 0, tutorialMarks = 0, sessionalExamMarks = 0,
           labMarks = 0, semEndExamMarks = 0;

    printf("Enter Class Test Marks: ");
    scanf("%lf", &classTestMarks);
    classTestMarks *= 0.12;
    printf("Enter Tutorial Marks:");
    scanf("%lf", &tutorialMarks);
    tutorialMarks *= 0.12;
    printf("Enter Sessional Examination Marks: ");
    scanf("%lf", &sessionalExamMarks);
    sessionalExamMarks *= 0.16;
    printf("Enter Lab and Practical Work Marks: ");
    scanf("%lf", &labMarks);
    labMarks *= 0.2;
    printf("Enter Semester End Examination Marks: ");
    scanf(" %lf", &semEndExamMarks);
    semEndExamMarks *= 0.4;

    double totalMarks = classTestMarks + labMarks + semEndExamMarks +
                        sessionalExamMarks + tutorialMarks;

    printf("Final Grade:");

    if (totalMarks > 90) {
        printf("A+");
    } else if (totalMarks > 80) {
        printf("A");
    } else if (totalMarks > 70) {
        printf("B+");
    } else if (totalMarks > 60) {
        printf("B");
    } else if (totalMarks > 50) {
        printf("C+");
    } else if (totalMarks > 40) {
        printf("C");
    } else {
        printf("Fail");
    }
}
