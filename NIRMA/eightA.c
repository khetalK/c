#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employeeData {
  char employeeName[50];
  int employeeID;
  double basicSalary, dearnessAllowancePercentage, houseRentAllowancePercentage,
      totalSalary;
};

int main() {
  struct employeeData employeeDatas[3];

  for (int i = 0; i < 3; i++) {
    printf("For Employee no.: %d\n", i + 1);

    printf("Enter the Employee's Name: ");
    fgets(employeeDatas[i].employeeName, 50, stdin);

    printf("Enter the Employee's ID: ");
    scanf("%d", &employeeDatas[i].employeeID);

    printf("Enter the Employee's Basic Salary: ");
    scanf("%lf", &employeeDatas[i].basicSalary);

    printf("Enter the Employee's House Rent Allowance percentage: ");
    scanf("%lf", &employeeDatas[i].houseRentAllowancePercentage);

    printf("Enter the Employee's Dearness Allowance percentage: ");
    scanf("%lf", &employeeDatas[i].dearnessAllowancePercentage);

    employeeDatas[i].totalSalary =
        employeeDatas[i].basicSalary *
        (1 + employeeDatas[i].dearnessAllowancePercentage / 100 +
         employeeDatas[i].houseRentAllowancePercentage / 100);
  }

  printf("(i)\t");

  char salaryName[50];

  printf("Enter the name of the employee whose salary is to be shown: ");
  fgets(salaryName, 50, stdin);

  for (int i = 0; i < 3; i++) {
    if (strcmp(employeeDatas[i].employeeName, salaryName) == 0) {

      printf("Employee's Total Salary: %lf\n", employeeDatas[i].totalSalary);
    }
  }

  printf("(ii)\t");

  printf("The maximum Total Salary is ");
  double maxSal = 0;
  int maxSalIndex;

  for (int i = 0; i < 3; i++) {
    if (employeeDatas[i].totalSalary > maxSal) {

      maxSal = employeeDatas[i].totalSalary;
      maxSalIndex = i;
    }
  }

  printf("Employee no.: %d has the maximum salary of %lf", maxSalIndex, maxSal);

  return 0;
}
