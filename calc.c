#include <stdio.h>
#include <stdlib.h>

double calculate(double a, double b, char c) {
    double outputValue = 0;
    if (c == '+') {
        outputValue = a + b;
    } else if (c == '-') {
        outputValue = a - b;
    } else if (c == '*') {
        outputValue = a * b;
    } else if (c == '/') {
        outputValue = a / b;
    } else if (c == '%') {
        outputValue = (int)a % (int)b;
    } else {
        printf("\nInvalid Operator!\n");
    }

    return outputValue;
}

void calculatorFn() {

    double firstNum, secondNum, outputVal;
    char oper;

    printf("Enter the operation: ");

    scanf("%lf %c %lf", &firstNum, &oper, &secondNum);

    outputVal = calculate(firstNum, secondNum, oper);

    printf("%.2f\n", outputVal);
}

int main() {
    calculatorFn();
    return 0;
}
