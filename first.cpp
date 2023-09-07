//%d->data;
//%s->string
#include <iostream>

using namespace std;

int main() {
  string characterName;
  cout << "Enter your name: ";
  getline(cin, characterName);

  int characterAge;
  cout << "Enter your age: ";
  cin >> characterAge;

  char gender;
  cout << "Are you Male(M) or Female(F) or Stupid(S)?: ";
  cin >> gender;

  bool isRight = false;
  if (gender == 'M') {
    isRight = true;
  }

  cout << "Your name is " << characterName << "\n"
       << "You are " << characterAge << " years old"
       << "\n"
       << "You are " << isRight << endl;
  return 0;
}
