#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  int inputNum, inputNumHalf;
  float inputNumF;
  printf("Enter a number: ");
  scanf("%d", &inputNum);
  inputNumF = inputNum;

  inputNumHalf = ceil(inputNumF / 2);

  if (inputNum % 2 == 0) {

    for (int i = 1; i < inputNum; i++) {
      if (i == inputNumHalf) {
        continue;
      } else {
      }
      for (int j = 0; j < (abs(inputNumHalf - i) % (inputNumHalf)); j++) {

        printf(" ");
      }

      for (int j = 1;
           j <= (inputNumHalf - abs(inputNumHalf - i)) % inputNumHalf; j++) {
        printf("%d ", j);
      }
      printf("\n");
    }

  } else {
    for (int i = 1; i <= inputNum; i++) {

      for (int j = 0; j < (abs(inputNumHalf - i)) % (inputNumHalf); j++) {
        printf(" ");
      }

      for (int j = 1;
           j <= inputNumHalf - (abs(inputNumHalf - i)) % inputNumHalf; j++) {
        printf("%d ", j);
      }
      printf("\n");
    }
  }

  system("pause");
  return 0;
}
