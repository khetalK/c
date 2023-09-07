#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int correctNum, guessNum, guessCount = 0, guessLimit = 5;
  srand(time(0));
  correctNum = rand() % 11;
  printf("Guess the number! \nThe number will be in the range of 0 to 10 \nYou "
         "have %d chances left\n",
         guessLimit);

  while (guessNum != correctNum) {
    while (guessCount < guessLimit) {

      if (guessCount > 0) {
        printf("Your guess was Incorrect!\n");
      }

      printf("Enter your guess: ");
      scanf("%d", &guessNum);

      guessCount++;
    }
    break;
  }

  printf("Sorry!\nYou are out of chances!\n");

  return 0;
}
