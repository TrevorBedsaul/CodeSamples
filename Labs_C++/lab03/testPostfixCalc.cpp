//Trevor Bedsaul
//tdb7mw
//9/10/17
//testPostfixCalc.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main ( ) {
  PostfixCalculator p;
  cout << "Enter a postfix expression to find the result: " << endl;
  while (cin.good()) {
    string s;
    cin >> s;
    if( isdigit(s[0]) ) {
      p.pushNum(atoi(s.c_str()));
    }
    else if ( s.length() > 1 && isdigit(s[1]) )
      p.pushNum(atoi(s.c_str()));
    else if ( s == "+" )
      p.add();
    else if ( s == "-" )
      p.subtract();
    else if ( s == "/" )
      p.divide();
    else if ( s == "*" )
      p.multiply();
    else if ( s == "~" )
      p.negate();
    else
      cout << s << endl;
  }
  cout << "Top value is: " << p.getTopValue() << endl;
  return 0;
}
