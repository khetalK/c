#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nineCFn(char *str1, char *str2, char *str3) {
  strcpy(str3, str1);
  strcat(str3, " ");
  strcat(str3, str2);
}

int main() {
  char str1[51], str2[51], str3[101];

  printf("Enter first string: ");
  scanf("%s", str1);

  printf("Enter second string: ");
  scanf("%s", str2);

  nineCFn(str1, str2, str3);

  printf("%s\n", str3);

  return 0;
}
