//Trevor Bedsaul
//tdb7mw
//10.13.17
//hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
 public:
  HashTable();
  HashTable(unsigned int size);

  unsigned int hash(string s);
  bool insert(string s);
  int find(string s);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);

 private:
  vector<string> table;
  unsigned int arr[22];
};

#endif
