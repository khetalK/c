#include <array>
#include <iostream>

using namespace std;

int main() {
  int someArray[]{1, 2, 3, 4, 5};
  int someArraySize{size(someArray)};
  int someArray__reverse[someArraySize];
  int *ptr;
  ptr = &someArray[someArraySize - 1];

  for (int i = 0; i < someArraySize; i++) {
    someArray__reverse[i] = *ptr--;
  }

  for (int i = 0; i < someArraySize; i++) {
    someArray[i] = someArray__reverse[i];
  }

  for (int i = 0; i < someArraySize; i++) {
    cout << someArray[i] << " ";
  }

  return 0;
}
