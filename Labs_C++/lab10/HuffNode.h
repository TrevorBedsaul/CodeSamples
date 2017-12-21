//Trevor Bedsaul
//tdb7mw
//HuffNode.h

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <cstdlib>
#include <string>

using namespace std;

class HuffNode {
 public:
  HuffNode();
  HuffNode(const char & a);
  HuffNode(int & val, const char & a);
  bool isLeaf();
  char c;
  int f;
  HuffNode* left;
  HuffNode* right;

 private:

  friend class Heap;
};

#endif
