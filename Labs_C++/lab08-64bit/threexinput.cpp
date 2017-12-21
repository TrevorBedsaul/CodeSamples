//Trevor Bedsaul
//tdb7mw
//threexinput.cpp

#include <iostream>
#include <cstlib>

using namespace std;

extern "C" int threexplusone(int);

int main() {
  int x;
  cout << "Enter int x: ";
  cin >> x;
  cout << "Result = " << threexplusone(x);
  return 0;
}
