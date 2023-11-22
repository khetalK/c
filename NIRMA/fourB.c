#include <stdio.h>
#include <stdlib.h>

int main() {
    int inputNum;
    int isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &inputNum);

    for (int i = 2; i < (inputNum / 2); i++) {
        if (inputNum % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if (isPrime == 1) {
        printf("The given number is Prime!");
    } else {
        printf("The given number is not a Prime Number!");
    }

    return 0;
}
