//Trevor Bedsaul
//tdb7mw
//9/19/17
//inlab4.cpp

#include <iostream>
#include <climits>
#include <limits>
#include <iomanip>

using namespace std;
void maxVals() {
  int i = INT_MAX;
  unsigned int u = UINT_MAX;
  float f = numeric_limits<float>::max();
  double d = numeric_limits<double>::max();
  char c = numeric_limits<char>::max();
  bool b = 1; //max value for boolean
  int* is = numeric_limits<int*>::max();
  char* cs = numeric_limits<char*>::max();
  double* ds = numeric_limits<double*>::max();
  cout << "---------Max values of each---------" << endl;
  cout << "int max: " << i << endl;
  cout << "unsigned int max: " << u << endl;
  cout << "float max: " << f << endl;
  cout << "double max: " << d << endl;
  cout << "char max: " << c << endl; //debug: 127 '\177'
  cout << "bool max: " << b << endl;
  cout << "int* max: " << &is << endl;
  cout << "char* max: " << &cs << endl;
  cout << "double* max: " << &ds << endl;
}

void storingZeros() {
  int i = 0;
  unsigned int u = 0;
  float f = 0.0;
  double d = 0.0;
  char c = '0';
  bool b = false;
  cout << "---------How zeros are stored---------" << endl;
  cout << hex << "zero stored in int: 0x" << i << endl;
  cout << hex << "zero stored in unsigned int: 0x" << u << endl;
  cout << hex << "zero stored in float: 0x" << f << endl;
  cout << hex << "zero stored in double: 0x" << d << endl;
  cout << hex << "zero stored in char: 0x" << c << endl; //debug: 48 '0'
  cout << hex << "zero stored in bool: 0x" << b << endl; //debug: false
}

void storingOnes() {
  int i = 1;
  unsigned int u = 1;
  float f = 1.0;
  double d = 1.0;
  char c = '1';
  bool b = true;
  cout << "---------How ones are stored---------" << endl;
  cout << hex << "one stored in int: 0x" << i << endl;
  cout << hex << "one stored in unsigned int: 0x" << u << endl;
  cout << hex << "one stored in float: 0x" << f << endl;
  cout << hex << "one stored in double: 0x" << d << endl;
  cout << hex << "one stored in char: 0x" << c << endl; //debug: c = 49 '1'
  cout << hex << "one stored in bool: 0x" << b << endl; //debug: true
}

void storingNulls() {
  int* i = NULL;
  char* c = NULL;
  double* d = NULL;
  cout << "---------How NULLS are stored---------" << endl;
  cout << hex << "NULL stored in int*: 0x" << i << endl;
  // cout << hex << "NULL stored in char*: 0x" << c << endl; terminates the program
  cout << hex << "NULL stored in double*: 0x" << d << endl;
  //debugger sets each to 0x0
}

int main() {
  maxVals();
  storingZeros();
  storingOnes();
  storingNulls();

  cout << "--------------------------------------------------------" << endl;
  cout << "---------------------Arrays Section---------------------" << endl;
  cout << "--------------------------------------------------------" << endl;

  int IntArray[10];
  for(int i = 0; i < 10; i++)
    IntArray[i] = i;
  cout << "IntArray 1st Element Address: " << &(IntArray[0]) << endl;
  
  char CharArray[10];
  for(int i = 0; i < 10; i++)
    CharArray[i] = i;
  cout << "CharArray 1st Element Address: " << (void*) &(CharArray[0]) << endl;
  
  int IntArray2D[6][5];
  for(int i = 0; i < 6; i++)
    for(int x = 0; x < 5; x++)
      IntArray2D[i][x] = x;
  cout << "IntArray2D 1st Element Address: " << &(IntArray2D[0][0]) << endl;
  cout << "IntArray2D 2nd Element Address: " << &(IntArray2D[0][1]) << endl;
  cout << "IntArray2D 6th Element Address: " << &(IntArray2D[1][0]) << endl;

  
  char CharArray2D[6][5];
  for(int i = 0; i < 6; i++)
    for(int x = 0; x < 5; x++)
      CharArray2D[i][x] = x;
  cout << "CharArray2D 1st Element Address: " << (void*) &(CharArray2D[0][0]) << endl;
  

  return 0;
}
