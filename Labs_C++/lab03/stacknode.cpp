//Trevor Bedsaul
//tdb7mw
//9/12/17
//stacknode.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "stacknode.h"

using namespace std;

StackNode::StackNode(int x) {
  value = x;
  next = NULL; 
}

StackNode::~StackNode() {
  // delete next;
  // delete this;
}
