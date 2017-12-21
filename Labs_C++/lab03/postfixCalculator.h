//Trevor Bedsaul
//tdb7mw
//9/10/17
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
using namespace std;

class PostfixCalculator {
 public:
//----------------------------------------------------- Constructors/Destructors
  PostfixCalculator();

//----------------------------------------------------- Operations
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();

//----------------------------------------------------- Other Methods
  void pushNum(int x);
  int getTopValue();
  int pop();
  int size();
  bool isEmpty();
  
 private:
  Stack s;
  int count;
};

#endif
