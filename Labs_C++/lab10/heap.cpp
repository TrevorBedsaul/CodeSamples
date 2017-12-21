//Trevor Bedsaul
//tdb7mw
//heap.cpp

#include "heap.h"
#include "HuffNode.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

Heap::Heap() {
  counter = 0;
  heap.push_back(new HuffNode());
  heap_size = 1;
}

Heap::~Heap() {
}

void Heap::insert(HuffNode* hN) {
  heap.push_back(hN);
  percolateUp(heap_size++);
}

void Heap::percolateUp(int hole) {
  HuffNode* tmp = heap[hole];
  for( ; hole > 1 && tmp->f < heap[hole/2]->f; hole /= 2) {
    heap[hole] = heap[hole/2];
  }
  heap[hole] = tmp;
}

HuffNode* Heap::deleteMin() {
  if ( heap_size == 0 )
    throw "deleteMin() called on empty heap";
  HuffNode* tmp = heap[1];
  heap_size -= 1;
  heap[1] = heap[heap_size];
  heap.pop_back();
  percolateDown(1);
  return tmp;
}

void Heap::percolateDown(int hole) {
  int x = heap[hole]->f;
  HuffNode* tmp = heap[hole];
  while(hole*2 <= heap_size) {
    int child = hole*2;
    if (child+1 <= heap_size && heap[child+1]->f < heap[child]->f)
      child++;
    if (x > heap[child]->f) {
      heap[hole] = heap[child];
      hole = child;
    } else
      break;
  }
  heap[hole] = tmp;
}

void Heap::printHeap() {
  for(int i = 0; i < heap_size; i++) {
    if(heap[i]->c == ' ')
      cout << "space" << " " << heap[i]->f << endl;
    else
      cout << heap[i]->c << " " << heap[i]->f << endl;
  }
}

HuffNode* Heap::heapToTree() {
  HuffNode* root;
  while(heap_size > 2){
    root = new HuffNode('~');
    root->left = deleteMin();
    root->right = deleteMin();
    root->f = root->left->f + root->right->f;
    insert(root);
  }
  return root;
}

void Heap::findCodes(HuffNode* root, string prefix) {
  if(root->isLeaf()) {
    string s = "";
    if(root->c == ' ')
      cout << "space " << prefix << endl;
    else
      cout << root->c << " " << prefix << endl;
    s.push_back(root->c);
    encr.push_back(s);
    encr.push_back(prefix);
  }
  else {
    findCodes(root->left, prefix + "0");
    findCodes(root->right, prefix + "1");
  }
}

string Heap::useCodes(string str) {
  string ans = "";
  for(int i = 0; i < str.length(); i++) {
    string s = "";
    s.push_back(str.at(i));
    for(int j = 0; j < encr.size(); j++) {
      if(s == encr[j])
	ans += encr[j+1] + " ";
    }
  }
  return ans;
}
