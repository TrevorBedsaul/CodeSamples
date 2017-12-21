//Trevor Bedsaul
//tdb7mw
//9/12/17
//stacknode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class StackNode {
 public:
//----------------------------------------------------- Constructors/Destructors
  StackNode(int x);
  ~StackNode();

//----------------------------------------------------- Methods
 private:
  int value;
  StackNode* next;

  friend class Stack;
};

#endif
