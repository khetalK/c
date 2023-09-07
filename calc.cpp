#include <cmath>
#include <iostream>


using namespace std;

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

  cout << "Enter the first number: ";
  cin >> firstNum;

  cout << "Enter the second number: ";
  cin >> secondNum;

  cout << "Enter the operation (\n\t+: Add \n\t-: Subtract \n\t*: Multiply "
          "\n\t/: Divide \n\t%%: Divide and give Remainder): ";
  cin >> oper;

  outputVal = calculate(firstNum, secondNum, oper);
  cout << outputVal << endl;

  // continue Or not
  char continueChooser;

  cout << "Continue? (\n\ty -> yes \n\tn -> n\n): " << endl;
  cin >> continueChooser;

  if (continueChooser == 'y' || continueChooser == 'n') {
    switch (continueChooser) {
    case 'y':
      calculatorFn();
      break;

    default:
      cout << "Bye!" << endl;
      break;
    }
  }
}

int main() {
  calculatorFn();
  return 0;
}
