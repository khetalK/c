#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int correctNum, guessNum;
  srand(time(0));
  correctNum = rand() % 11;
  printf("Guess the number! \nThe number will be in the range of 0 to 10: ");

  while (guessNum != correctNum) {
    printf("Your guess was Incorrect!\n");

    printf("Enter your guess: ");
    scanf("%d", &guessNum);
  }

  printf("Correct! You Win!");

  return 0;
}
