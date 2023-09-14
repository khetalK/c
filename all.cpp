#include <iostream>

using namespace std;

string divideWatermelon(int w) {

  if (w % 2 == 0) {
    return "YES";
  } else {
    return "NO";
  }
}

int main() {
  int w;
  do {
    cout << "Enter Weight of Watermelon: ";
    cin >> w;
  } while (w > 100);

  cout << divideWatermelon(w) << endl;

  // cout << divideWatermelon(w) << endl;

  return 0;
}
