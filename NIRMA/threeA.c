#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int checkDiscriminator(int discriminator) {
  if (discriminator > 0) {
    return 2;
  } else if (discriminator == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  double a, b, c;

  printf("Enter the coefficient of x^2 (a): ");
  scanf("%lf", &a);

  printf("Enter the coefficient of x (b): ");
  scanf("%lf", &b);

  printf("Enter the constant (c): ");
  scanf("%lf", &c);

  double discriminator = b * b - 4 * a * c;

  int numberOfRoots = checkDiscriminator(discriminator);

  double x1, x2;

  if (numberOfRoots == 2) {
    printf("The given Quadratic Equation has 2 roots\n");
    x1 = (-b + sqrt(discriminator)) / 2 * a;
    x2 = (-b - sqrt(discriminator)) / 2 * a;
    printf("The Roots of given Quadratic Equation are %lf & %lf", x1, x2);
  } else if (numberOfRoots == 1) {
    printf("The given Quadratic Equation has 1 root\n");
    x1 = x2 = (-b) / 2 * a;
    printf("The Root of given Quadratic Equation is %lf", x1);
  } else {
    printf("The given Quadratic Equation has NO roots");
  }

  return 0;
}
