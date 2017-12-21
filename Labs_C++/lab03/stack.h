//Trevor Bedsaul
//tdb7mw
//9/12/17
//stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stacknode.h"
using namespace std;


class Stack {
 public:
//----------------------------------------------------- Constructors/Destructors
  Stack();
  ~Stack();

//----------------------------------------------------- Methods
  
  void pop();
  void push(int value);
  int top();
  bool empty();
  
 private:
  StackNode* head;
  int size;
  friend class StackNode;
};

#endif
