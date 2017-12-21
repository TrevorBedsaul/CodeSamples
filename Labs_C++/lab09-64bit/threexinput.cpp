//Trevor Bedsaul
//tdb7mw
//threexinput.cpp

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int main() {
  int n, x;
  cout << "Enter int x: ";
  cin >> x;
  cout << "Enter int n: ";
  cin >> n;
  timer t;
  t.start();
  for(int i = 0; i < n; i++)
    threexplusone(x);
  t.stop();
  cout << "Result = " << threexplusone(x) << endl;
  cout << "Average Time = " << t.getTime()/n << endl;
  return 0;
}
