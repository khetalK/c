#include <stdio.h>
#include <stdlib.h>

void alphabetPrinter() {
  int i = 1;
  while (i <= 4) {
    for (int j = 0; j < i; j++) {
      printf("%c ", 65 + j);
    }
    printf("\n");
    i++;
  }
}

void oneOOnePrinter() {
  int i = 1;
  while (i <= 4) {

    for (int j = 0; j < i; j++) {
      printf("%d ", (i + j) % 2);
    }

    printf("\n");

    i++;
  }
}

int main() {
  alphabetPrinter();
  printf("\n");
  oneOOnePrinter();
  return 0;
}
