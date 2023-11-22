#include <stdio.h>
#include <stdlib.h>

void reverseArr(int arr[], int arrLength) {

    int arrReverse[arrLength];

    for (int i = 0; i < arrLength; i++) {
        arrReverse[i] = arr[arrLength - 1 - i];
    }

    for (int i = 0; i < arrLength; i++) {
        arr[i] = arrReverse[i];
    }
}

void reverseArrPointer(int arr[], int arrLength) {
    int *arrPointer;
    arrPointer = &arr[arrLength - 1];
    int revArr[arrLength];

    for (int i = 0; i < arrLength; i++) {
        revArr[i] = *arrPointer--;
    }

    for (int i = 0; i < arrLength; i++) {
        arr[i] = revArr[i];
    }

    for (int i = 0; i < arrLength; i++) {
        printf("%d", revArr[i]);
    }
}

int findMaxIndex(int arr[], int arrLength) {
    int maxIndex;
    int maxVal = arr[0];

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] > maxVal) {
            maxIndex = i + 1;
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

int main() {

    // int someArr[] = {1, 2, 3, 4, 5};
    // int someArrLength = sizeof(someArr) / sizeof(someArr[0]);

    // generating array with inputs from user
    int someArrLength;
    printf("Enter number of elements in the array: ");
    scanf("%d", &someArrLength);

    int someArr[someArrLength];
    for (int i = 0; i < someArrLength; i++) {
        printf("Enter element number %d: ", i + 1);
        scanf("%d", &someArr[i]);
    }

    // reversing array
    printf("(i) ");
    reverseArr(someArr, someArrLength);
    printf("{");
    for (int i = 0; i < someArrLength; i++) {
        printf("%d", someArr[i]);
        if (i < someArrLength - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    // reverseArrPointer(someArr, someArrLength);

    // finding max value
    printf("(ii) ");
    int maxIndex = findMaxIndex(someArr, someArrLength);
    int *somePointer = &someArr[maxIndex];
    printf("Maximum Value: %d\n", someArr[maxIndex]);
    printf("Location of Max Value: %p\n", somePointer);

    return 0;
}
