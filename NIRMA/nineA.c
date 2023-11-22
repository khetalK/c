#include <stdio.h>
#include <stdlib.h>

void nineAFn(int *arrptr, int len) {
  while (len--) {
    if (len % 2 == 0) {
      arrptr[len]++;
    } else {
      arrptr[len] += 2;
    }
  }
}

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);
  nineAFn(arr, len);

  while (len--) {
    printf("%d\n", arr[len]);
  }

  return 0;
}
