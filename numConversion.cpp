#include <iostream>

using namespace std;

void decToSumn(int decNum, int divisor) {

  int convertedNumRev[32];
  int convertedNum[32];

  int binNumSize = size(convertedNumRev);
  for (int i = 0; i < binNumSize; i++) {
    convertedNumRev[i] = 0;
    convertedNum[i] = 0;
  }

  int remainder = 1;
  int divCount = 0;

  while (decNum != 0) {
    (remainder = decNum % divisor);
    (decNum /= divisor);
    convertedNumRev[divCount] = remainder;
    divCount++;
  }

  for (int i = 0; i < binNumSize; i++) {
    convertedNum[i] = convertedNumRev[binNumSize - i - 1];
  }

  for (int i = 0; i < binNumSize; i++) {
    if (convertedNum[i] > 9) {
      convertedNum[i] += 55;
    }
  }

  bool toCheck = true;
  bool toPrint = false;
  for (int i = 0; i < binNumSize; i++) {
    if (toCheck == 1) {
      if (convertedNum[i] == 0) {
        toPrint = false;
      } else {
        toPrint = true;
        toCheck = false;
      }
    }

    if (toPrint == true) {
      if (convertedNum[i] < 10) {
        cout << convertedNum[i];

      } else {
        cout << (char)convertedNum[i];
      }
    }
  }

  //   return binNum;
}

int main() {

  int inputNum;
  cout << "Enter a number: ";
  cin >> inputNum;

  char finalBaseSystem;
  cout << "Enter the final base system(B: Binary, O: Octal, H: Hexadecimal): ";
  cin >> finalBaseSystem;

  int divisor;
  if (finalBaseSystem == 'B' || finalBaseSystem == 'b') {
    divisor = 2;
  } else if (finalBaseSystem == 'O' || finalBaseSystem == 'o') {
    divisor = 8;
  } else if (finalBaseSystem == 'H' || finalBaseSystem == 'h') {
    divisor = 16;
  }

  decToSumn(inputNum, divisor);

  return 0;
}
