//Trevor Bedsaul
//tdb7mw
//10.13.17
//hashTable.cpp

#include "hashTable.h"
#include <cmath>

using namespace std;

HashTable::HashTable() {
  table.resize(101);
  for(int i = 0; i < 101; i++)
    table[i] = "";
  arr[0] = 1;
  for(int i = 0; i < 22; i++)
    arr[i] = arr[i-1] * 37;
}

HashTable::HashTable(unsigned int size) {
  size = size * 2; // .50 load factor
  size = getNextPrime(size); //prime size
  table.resize(size);
  for(int i = 0; i < size; i++)
    table[i] = "";
  arr[0] = 1;
  for(int i = 0; i < 22; i++)
    arr[i] = arr[i-1]*37;
}

unsigned int HashTable::hash(string s) {
  unsigned int x = 0;
  for(int i = 0; i < s.length(); i++) {
    x += s.at(i)*arr[i];
  }
  return x;
}

bool HashTable::insert(string s) {
  int a = hash(s)%table.size();
  while(table.at(a) != "")
    a = (a+1)%table.size();  
  table[a] = s;
  return true;
}



int HashTable::find(string s) {
  unsigned int a = hash(s)%table.size();
  while(table.at(a) != s && table.at(a) != "") {
    a = (a+1)%table.size();
  }
  if(table.at(a) == s)
    return a;
  else
    return -1;
}

bool HashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int HashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
