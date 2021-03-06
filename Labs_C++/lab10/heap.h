//Trevor Bedsaul
//tdb7mw
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HuffNode.h"

using namespace std;

class Heap {
 public:
  Heap();
  ~Heap();
  void  insert(HuffNode* hN);
  void percolateUp(int hole);
  HuffNode* deleteMin();
  void percolateDown(int hole);
  void printHeap();
  HuffNode* heapToTree();
  void findCodes(HuffNode* root, string prefix);
  string useCodes(string str);
  void printTree(HuffNode* p, int indent);
  
 private:
  vector<HuffNode*> heap;
  vector<string> encr;
  int counter;
  int heap_size;
  friend class HuffNode;
};

#endif
