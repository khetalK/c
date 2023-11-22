#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char inputString[50], repChars[25];
    int repReps[25];
    printf("Enter the string: ");
    fgets(inputString, 50, stdin);
    int inputStringLength = strlen(inputString);

    int reps = 1, repIndex = 0;

    for (int i = 0; i < inputStringLength; i++) {
        char repChar;

        for (int j = i + 1; j < inputStringLength; j++) {
            if ((inputString[j] == inputString[i]) ||
                (inputString[j] == inputString[i] + 32) ||
                (inputString[j] == inputString[i] - 32)) {
                repChar = inputString[i];
                reps++;
            }
        }
        if (reps > 1) {
            int isPresent = 0;
            for (int k = 0; k < repIndex; k++) {
                if (repChars[k] == repChar) {
                    isPresent = 1;
                }
            }

            if (isPresent == 0) {
                repChars[repIndex] = repChar;
                repReps[repIndex++] = reps;
                reps = 1;
            }
        }
    }

    for (int i = 0; i < repIndex; i++) {
        printf("%c is repeated %d times\n", repChars[i], repReps[i]);
    }

    return 0;
}
