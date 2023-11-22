#include <stdio.h>

int main() {
  char employee_position;
  int employee__clerk_hourlySalary = 100, employee__teacher_hourlySalary = 200,
      employee__principal_hourlySalary = 400;
  int hoursWorked;
  double overtime__salaryMultiplier = 2;
  int overtime__start = 44;
  int overtime__maxHours = 50;

  printf("Type the position of the employee whose salary you want to calculate "
         "(Clerk(C) / Teacher(T) / Principal(P)): ");
  scanf("%s", &employee_position);

  printf("Enter Number Of Hours Worked: ");
  scanf("%d", &hoursWorked);

  int employee_hourlySalary;

  if (employee_position == 'C' || employee_position == 'c') {
    employee_hourlySalary = employee__clerk_hourlySalary;
  } else if (employee_position == 'T' || employee_position == 't') {
    employee_hourlySalary = employee__teacher_hourlySalary;
  } else if (employee_position == 'P' || employee_position == 'p') {
    employee_hourlySalary = employee__principal_hourlySalary;
  }

  int employee_salary = overtime__start * employee_hourlySalary;

  if (hoursWorked < overtime__start) {
    employee_salary = employee_hourlySalary * hoursWorked;
    printf("%d", employee_salary);
  } else if (hoursWorked < overtime__maxHours) {
    employee_salary += overtime__salaryMultiplier * employee_hourlySalary *
                       (hoursWorked - overtime__start);
    printf("%d", employee_salary);
  } else {
    employee_salary += overtime__salaryMultiplier *
                       (overtime__maxHours - overtime__start) *
                       employee_hourlySalary;
    printf("%d", employee_salary);
  }

  return 0;
}
