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
  double coefficient__xSquare, coefficient__x, coefficient__const;

  printf("Enter the coefficient of x^2 (a): ");
  scanf("%lf", &coefficient__xSquare);

  printf("Enter the coefficient of x (b): ");
  scanf("%lf", &coefficient__x);

  printf("Enter the constant (c): ");
  scanf("%lf", &coefficient__const);

  double discriminator = coefficient__x * coefficient__x -
                         4 * coefficient__xSquare * coefficient__const;

  int numberOfRoots = checkDiscriminator(discriminator);

  double x1, x2;

  if (numberOfRoots == 2) {
    printf("The given Quadratic Equation has 2 roots\n");
    x1 = (-coefficient__x + sqrt(discriminator)) / 2 * coefficient__xSquare;
    x2 = (-coefficient__x - sqrt(discriminator)) / 2 * coefficient__xSquare;
    printf("The Roots of given Quadratic Equation are %.2lf & %.2lf", x1, x2);
  } else if (numberOfRoots == 1) {
    printf("The given Quadratic Equation has 1 root\n");
    x1 = x2 = (-coefficient__x) / 2 * coefficient__xSquare;
    printf("The Root of given Quadratic Equation is %.2lf", x1);
  } else {
    printf("The given Quadratic Equation has NO roots");
  }

  return 0;
}
