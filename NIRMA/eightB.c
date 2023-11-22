#include <stdio.h>
#include <stdlib.h>

struct complexNum {
  double realPart, imaginaryPart;
};

double addingNums(double realParts[2]) {
  int sum = 0;
  for (int i = 0; i < 2; i++) {
    sum += realParts[i];
  }
  return sum;
}

int main() {
  struct complexNum complexNums[2];
  for (int i = 0; i < 2; i++) {
    printf("Enter the real part of complex number no.%d: ", i + 1);
    scanf("%lf", &complexNums[i].realPart);

    printf("Enter the imaginary part of complex number no.%d: ", i + 1);
    scanf("%lf", &complexNums[i].imaginaryPart);
  }

  double realParts[] = {complexNums[0].realPart, complexNums[1].realPart};
  double imaginaryParts[] = {complexNums[0].imaginaryPart,
                             complexNums[1].imaginaryPart};
  struct complexNum sumComplexNum = {
      sumComplexNum.realPart = addingNums(realParts),
      sumComplexNum.imaginaryPart = addingNums(imaginaryParts)};

  printf("the sum is %.2lf + %.2lfi\n", sumComplexNum.realPart,
         sumComplexNum.imaginaryPart);

  return 0;
}
