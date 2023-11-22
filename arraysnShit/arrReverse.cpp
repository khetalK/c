#include <array>
#include <iostream>

using namespace std;

void reverseArr(int arr[], int arrSize = 5) {
    int arr__reverse[arrSize];
    int *ptr;
    ptr = &arr[arrSize - 1];

    for (int i = 0; i < arrSize; i++) {
        arr__reverse[i] = *ptr--;
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = arr__reverse[i];
    }

    // return arr;
}

int main() {
    int someArray[]{1, 2, 3, 4, 5};
    int someArraySize = size(someArray);

    reverseArr(someArray);

    for (int i = 0; i < someArraySize; i++) {
        cout << someArray[i] << " ";
    }

    return 0;
}
