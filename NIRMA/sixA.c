#include <stdio.h>
#include <string.h>

void removeChar(char *inputString, char deleteChar) {
    int inputStringLength = strlen(inputString);
    for (int i = 0; i < inputStringLength; i++) {
        char salaryName[50];
        if ((inputString[i] == deleteChar) ||
            (inputString[i] == deleteChar + 32) ||
            (inputString[i] == deleteChar - 32)) {
            for (int j = i; j < inputStringLength; j++) {
                inputString[j] = inputString[j + 1];
            }
        }
    }
}

int main() {
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);

    char deleteChar;
    printf("Enter the character to be deleted: ");
    scanf("%c", &deleteChar);

    removeChar(inputString, deleteChar);
    puts(inputString);

    return 0;
}
