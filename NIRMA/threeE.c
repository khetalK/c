#include <stdio.h>
#include <string.h>

int main() {
  double classTestMarks = 0, tutorialMarks = 0, sessionalExamMarks = 0,
         labMarks = 0, semEndExamMarks = 0;

  // char arrInt[5] = {'a', 'b', 'c', 'd', 'e'};
  // char arrInt[5] = "abcde";

  printf("Enter Class Test Marks: ");
  scanf("%lf", &classTestMarks);
  printf("Enter Tutorial Marks:");
  scanf("%lf", &tutorialMarks);
  printf("Enter Sessional Examination Marks: ");
  scanf("%lf", &sessionalExamMarks);
  printf("Enter Lab and Practical Work Marks: ");
  scanf("%lf", &labMarks);
  printf("Enter Semester End Examination Marks: ");
  scanf(" %lf", &semEndExamMarks);

  double effClassTestMarks = classTestMarks * 0.12,
         effTutorialMarks = tutorialMarks * 0.12,
         effSessionalExamMarks = sessionalExamMarks * 0.16,
         effLabMarks = labMarks * 0.2,
         effSemEndExamMarks = semEndExamMarks * 0.4;

  double totalMarks = effClassTestMarks + effLabMarks + effSemEndExamMarks +
                      effSessionalExamMarks + effTutorialMarks;

  char finalGrade[2];

  if (totalMarks > 90) {
    strcpy(finalGrade, "A+");
  } else if (totalMarks > 80) {
    strcpy(finalGrade, "A");
  } else if (totalMarks > 70) {
    strcpy(finalGrade, "B+");
  } else if (totalMarks > 60) {
    strcpy(finalGrade, "B");
  } else if (totalMarks > 50) {
    strcpy(finalGrade, "C+");
  } else if (totalMarks > 40) {
    strcpy(finalGrade, "C");
  } else {
    strcpy(finalGrade, "F");
  }

  printf("Final Grade:");
  printf(finalGrade);
}
