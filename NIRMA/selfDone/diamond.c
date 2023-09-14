#include <stdio.h>
#include <stdlib.h>

void betterMethod() {
  int widthNum;
  printf("Enter a number: ");
  scanf("%d", &widthNum);

  if (widthNum % 2 != 0) {
    printf("Since the given number was odd, we are incrementing the number by "
           "1...\n");
    widthNum++;
  }

  int widthNumHalf = (widthNum / 2);

  for (int i = 0; i < widthNum + 1; i++) {
    if (i == widthNum / 2) {
      continue;
    } else {
      for (int j = 0; j < widthNum; j++) {
        if (j < abs(widthNumHalf - i) - 1) {
          printf(" ");
        } else if (j == widthNumHalf - i - 1) {
          printf("/");
        } else if (j == i - widthNumHalf - 1) {
          printf("\\");
        } else if (j < widthNum - abs(widthNumHalf - i)) {
          printf(" ");
        } else if (j == widthNumHalf + i) {
          printf("\\");
        } else if (j == (3 * widthNumHalf - i)) {
          printf("/");
        }
      }
      printf("\n");
    }
  }
}

int main() {
  {
    // int widthNum;
    // printf("Enter a number: ");
    // scanf("%d", &widthNum);

    // if (widthNum % 2 == 0) {
    //   widthNum++;
    // }

    // for (int i = 1; i <= widthNum; i++) {
    //   if (i == 5) {
    //     continue;
    //   } else {
    //     {
    //       for (int j = 0; j < abs(i - (widthNum + 1) / 2) % (widthNum + 1) /
    //       2;
    //            j++) {
    //         printf(".");
    //       }
    //     }

    //     {
    //       if (i <= (widthNum - 1) / 2) {
    //         printf("/");
    //       } else {
    //         printf("\\");
    //       }
    //     }

    //     {
    //       for (int j = 0;
    //            j <
    //            2 * (abs((widthNum + 1) / 2 - abs((widthNum + 1) / 2 - i)) -
    //            1); j++) {
    //         printf(".");
    //       }
    //     }

    //     {
    //       if (i <= (widthNum - 1) / 2) {
    //         printf("\\");
    //       } else {
    //         printf("/");
    //       }
    //     }

    //     printf("\n");
    //   }
    // }
  }

  betterMethod();

  return 0;
}
