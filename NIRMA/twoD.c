
#include <stdio.h>

int main() {
  int x, y;
  printf("Enter first number: ");
  scanf("%d", &x);

  printf("Enter second number: ");
  scanf("%d", &y);

  (x > y) ? printf("The First Number(%d) is greater than the Second Number(%d)",
                   x, y)
  : (y > x)
      ? printf("The Second Number(%d) is greater than the First Number(%d)", y,
               x)
      : printf("The First Number(%d) is equal to the Second Number(%d)", x, y);

  return 0;
}
