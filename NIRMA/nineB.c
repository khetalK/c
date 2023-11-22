#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);
  int *arrptr;
  arrptr = &arr[9];

  while (len--) {
    printf("%d\n", *arrptr--);
  }

  return 0;
}
