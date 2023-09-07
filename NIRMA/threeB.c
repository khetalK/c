#include <stdio.h>

int main() {
  char employeePosition;
  int clerkHourlySalary = 100, teacherHourlySalary = 200,
      principalHourlySalary = 400;
  double hoursWorked;
  double overtimeSalaryMultiplier = 2;
  int overtimeStart = 44, maxHours = 50;

  printf("Type the position of the employee whose salary you want to calculate "
         "(Clerk(C) / Teacher(T) / Principal(P)): ");
  scanf("%s", &employeePosition);

  printf("Enter Number Of Hours Worked: ");
  scanf("%lf", &hoursWorked);

  int employeeHourlySalary;

  if (employeePosition == 'C') {
    employeeHourlySalary = clerkHourlySalary;
  } else if (employeePosition == 'T') {
    employeeHourlySalary = teacherHourlySalary;
  } else if (employeePosition == 'P') {
    employeeHourlySalary = principalHourlySalary;
  }

  int employeeSalary;

  if (hoursWorked < overtimeStart) {
    employeeSalary = employeeHourlySalary * hoursWorked;
    printf("%d", employeeSalary);
  } else if (hoursWorked < maxHours) {
    employeeSalary =
        overtimeSalaryMultiplier * employeeHourlySalary * hoursWorked;
    printf("%d", employeeSalary);
  } else {
    employeeSalary = overtimeSalaryMultiplier * maxHours * employeeHourlySalary;
    printf("%d", employeeSalary);
  }

  return 0;
}
