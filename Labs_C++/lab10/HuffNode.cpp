//Trevor Bedsaul
//tdb7mw
//HuffNode.cpp

#include "HuffNode.h"
#include <cstdlib>
#include <iostream>

using namespace std;

HuffNode::HuffNode() {
  left = NULL;
  right = NULL;
  c = '~';
}

HuffNode::HuffNode(const char & a) {
  left = NULL;
  right = NULL;
  c = a;
  f = 0;
}

HuffNode::HuffNode(int & val, const char & a) {
  left = NULL;
  right = NULL;
  c = a;
  f = val;
}

bool HuffNode::isLeaf() {
  return this->left == NULL && this->right == NULL;
}

