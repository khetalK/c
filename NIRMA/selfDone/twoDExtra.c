#include <math.h>
#include <stdio.h>

void numComparisionWTernary(double x, double y, double z) {
  // x > y
  (x > y)
      ? (z > x)
            // z > x > y
            ? printf("C(%.f) is greater than A(%.f) is greater than B(%.f)", z,
                     x, y)
            : (z < x)
                  ? (z > y)
                        // x > z > y
                        ? printf("A(%.f) is greater than C(%.f) is greater "
                                 "than B(%.f)",
                                 x, z, y)
                        : (y > z)
                              // x > y > z
                              ? printf("A(%.f) is greater than B(%.f) is "
                                       "greater than C(%.f)",
                                       x, y, z)
                              // x > y = z
                              : printf("A(%.f) is greater than B(%.f) is equal "
                                       "to C(%.f)",
                                       x, y, z)
                  // z = x > y
                  : printf("A(%.f) is equal to C(%.f) is greater than B(%.f)",
                           x, z, y)

  // y > x
  : (y > x)
      ? (z > y)
            // z > y > x
            ? printf("C(%.f) is greater than B(%.f) is greater than A(%.f)", z,
                     y, x)
            : (y > z)
                  ? (z > x)
                        // y > z > x
                        ? printf("B(%.f) is greater than C(%.f) is greater "
                                 "than A(%.f)",
                                 y, z, x)
                        : (x > z)
                              // y > x > z
                              ? printf("B(%.f) is greater than A(%.f) is "
                                       "greater than C(%.f)",
                                       y, x, z)
                              // y > x = z
                              : printf("B(%.f) is greater than A(%.f) is equal "
                                       "to C(%.f)",
                                       y, x, z)
                  // z = y > x
                  : printf("B(%.f) is equal to C(%.f) is greater than A(%.f)",
                           y, z, x)
  // x = y
  : (z > x)
      // z > x = y
      ? printf("C(%.f) is greater than A(%.f) is equal to B(%.f)", z, x, y)
      // x = y > z
      : printf("A(%.f) is equal to B(%.f) is greater than C(%.f)", x, y, z);
}

int main() {
  float x, y, z;

  printf("Enter Value of A: ");
  scanf("%f", &x);
  printf("Enter Value of B: ");
  scanf("%f", &y);
  printf("Enter Value of C: ");
  scanf("%f", &z);

  numComparisionWTernary(x, y, z);

  system("pause");
  return 0;
}
