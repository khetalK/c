#include <stdio.h>
#include <stdlib.h>

double calcAddition(double a, double b) { return a + b; }

double calcSubtraction(double a, double b) { return a - b; }

double calcMultiplication(double a, double b) { return a * b; }

double calcDivision(double a, double b) { return a / b; }

double calcModulus(int a, int b) { return a % b; }

double calculate(double a, double b, char c) {
  double outputValue;
  if (c == '+') {
    outputValue = calcAddition(a, b);
  } else if (c == '-') {
    outputValue = calcSubtraction(a, b);
  } else if (c == '*') {
    outputValue = calcMultiplication(a, b);
  } else if (c == '/') {
    outputValue = calcDivision(a, b);
  } else if (c == '%') {
    outputValue = calcModulus(a, b);
  } else {
    printf("\nInvalid Operator!\n");
  }

  return outputValue;
}

void calculatorFn() {

  double firstNum, secondNum, outputVal;
  char oper;

  printf("Enter the first number: ");
  scanf("%lf", &firstNum);

  printf("Enter the second number: ");
  scanf("%lf", &secondNum);

  printf("Enter the operation (\n\t+: Add \n\t-: Subtract \n\t*: Multiply "
         "\n\t/: Divide \n\t%%: Divide and give Remainder): ");

  scanf("%s", &oper);

  outputVal = calculate(firstNum, secondNum, oper);

  printf("%.2f\n", outputVal);

  // continue Or not
  char continueChooser;

  printf("Continue? (\n\ty -> yes \n\tn -> n\n): ");

  scanf("%1s", &continueChooser);

  if (continueChooser == 'y' || continueChooser == 'n') {
    switch (continueChooser) {
    case 'y':
      calculatorFn();
      break;

    default:
      printf("Bye!");
      break;
    }
  }
}

int main() {
  calculatorFn();
  return 0;
}
