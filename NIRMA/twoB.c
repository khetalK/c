#include <stdio.h>

int main() {
    int basicSalary;
    float netSalary, grossSalary, deduction, dearnessAllowance,
        houseRentAllowance, medical, providentFund, insurance;
    printf("Enter Salary Of Employee: ");
    scanf("%d", &basicSalary);

    dearnessAllowance = 0.5 * basicSalary;
    houseRentAllowance = 0.1 * basicSalary;
    medical = 0.04 * basicSalary;
    grossSalary =
        basicSalary + dearnessAllowance + houseRentAllowance + medical;
    providentFund = 0.05 * grossSalary;
    insurance = 0.07 * grossSalary;
    deduction = insurance + providentFund;
    netSalary = grossSalary - deduction;

    printf("Net Salary is %.2f", netSalary);

    return 0;
}
