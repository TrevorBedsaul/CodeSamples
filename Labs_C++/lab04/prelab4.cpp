//Trevor Bedsaul
//tdb7mw
//9/17/17
//prelab4.cpp

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes" << endl;
  cout << "Size of char: " << sizeof(char) << " byte" << endl;
  cout << "Size of bool: "  << sizeof(bool) << " byte" << endl;
  cout << "Size of int*: " << sizeof(int*) << " bytes" << endl;
  cout << "Size of char*: " << sizeof(char*) << " bytes" << endl;
  cout << "Size of double*: " << sizeof(double*) << " bytes" << endl;
}

void outputBinary(unsigned int x) {
  string str = "";
  int power = 31;
  for(int i = 1; i < 40; i++) {
    if(i%5 == 0) {
      str += " ";
      continue;
    }
    if(x >= pow(2, power)) {
      str += "1";
      x = x - pow(2, power);
    }
    else if(i%5 != 0)
      str += "0";
    power--;
  }
  cout << str << endl;
}

void overflow() {
  unsigned int a = UINT_MAX;
  cout << "Unsigned int max value: " << a << endl;
  a = a + 1;
  cout << "After adding 1 to the max unsigned int value, we get: " << a << endl;
  cout << "This is because once it passes the max value, it essentially loops back around to the opposite end, which is the unsigned int minimum value:  0, and starts over from there." << endl;
}

int main( ) {
  unsigned int x;
  cout << "What number would you like you have output in binary? " << endl;
  cin >> x;
  sizeOfTest();
  outputBinary(x);
  overflow();
  return 0;
}
