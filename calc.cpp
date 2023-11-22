#include <cmath>
#include <iostream>

using namespace std;

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
        cout << "\nInvalid Operator!\n";
    }

    return outputValue;
}

void calculatorFn() {

    double firstNum, secondNum, outputVal;
    char oper;

    cout << "Enter the operation: ";
    cin >> firstNum;
    cin >> oper;
    cin >> secondNum;

    outputVal = calculate(firstNum, secondNum, oper);
    cout << outputVal << endl;
}

int main() {
    calculatorFn();
    return 0;
}
