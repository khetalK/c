#include <stdio.h>
#include <stdlib.h>

int totalMarksOfAStudent(int marksOfStudent[4]) {

    int totalMarksForStudent = 0;
    for (int j = 0; j < 4; j++) {
        totalMarksForStudent += marksOfStudent[j];
    }

    return totalMarksForStudent;
}

double averageMarksInCProgramming(int marks[][4], int numberOfStudents) {
    double avgInCP;
    int totalMarksInCP = 0;
    for (int i = 0; i < numberOfStudents; i++) {
        totalMarksInCP += marks[i][0];
    }
    avgInCP = (double)totalMarksInCP / numberOfStudents;
    return avgInCP;
}

int main() {
    int numberOfStudents = 5;

    char subjects[][10] = {"CP", "CS", "Maths", "Physics"};

    // int marks[][4] = {{100, 100, 100, 100},
    //                   {100, 100, 100, 100},
    //                   {100, 100, 100, 100},
    //                   {100, 100, 100, 100},
    //                   {100, 100, 100, 100}};

    int marks[numberOfStudents][4];
    for (int i = 0; i < numberOfStudents; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Enter the %s marks of student number %d: ", subjects[j],
                   i + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    //(i)
    int totalMarks[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++) {
        totalMarks[i] = totalMarksOfAStudent(marks[i]);
    }

    //(ii)
    double avgInCP = averageMarksInCProgramming(marks, numberOfStudents);

    for (int i = 0; i < numberOfStudents; i++) {
        printf("Total Marks of Student %d are %d\n", i + 1, totalMarks[i]);
    }

    printf("The average marks in C Programming are %lf", avgInCP);

    return 0;
}
