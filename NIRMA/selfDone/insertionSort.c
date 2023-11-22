#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {5, 3, 6, 7, 2, 4, 8, 1, 9, 0};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrSize; i++) {

        for (int j = i; j < arrSize; j++) {
            if (arr[j + 1] > arr[j]) {
                continue;
            }

            if (arr[j + 1] < arr[j]) {
                int temp = arr[j + 1];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for (int i = 0; i < arrSize; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    for (int i = 0; i < arrSize; i++) {
        printf("%d", arr[i]);
    }

    return 0;
}
