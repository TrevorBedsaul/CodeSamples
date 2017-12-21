//Trevor Bedsaul
//tdb7mw
//mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int main () {
  int x, y;
  cout << "Enter int x: ";
  cin >> x;
  cout << "Enter int y: ";
  cin >> y;
  cout << "product(x, y) = " << product(x, y) << endl;
  cout << "power(x, y) = " << power(x, y) << endl;
  return 0;
}
