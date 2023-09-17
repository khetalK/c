#include <iostream>
#include <math.h>

using namespace std;

int main() {
  string romanNums[][2] = {{"-M", "--V"}, {"-C", "-D"}, {"-X", "-L"},
                           {"M", "-V"},   {"C", "D"},   {"X", "L"},
                           {"I", "V"}};
  int sizeOfRomanNums = sizeof(romanNums) / sizeof(romanNums[0]);

  int numericalNum;
  cout << "Enter the number: ";
  cin >> numericalNum;

  int individualNums[sizeOfRomanNums];
  for (int i = 0; i < sizeOfRomanNums; i++) {
    individualNums[i] =
        ((int)(numericalNum / pow(10, sizeOfRomanNums - 1 - i))) % 10;
  }

  for (int i = 0; i < sizeOfRomanNums; i++) {

    if (individualNums[i] < 4) {
      for (int j = 0; j < individualNums[i]; j++) {
        cout << romanNums[i][0];
      }
    } else if (individualNums[i] <= 8) {
      for (int j = individualNums[i]; j < 5; j++) {
        cout << romanNums[i][0];
      }
      cout << romanNums[i][1];
      for (int j = 5; j < individualNums[i]; j++) {
        cout << romanNums[i][0];
      }
    } else {
      cout << romanNums[i][0];
      cout << romanNums[i - 1][0];
    }
  }

  return 0;
}
