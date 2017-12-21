//Trevor Bedsaul
//tdb7mw
//huffmanenc.cpp

#include "heap.h"
#include "HuffNode.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  if(argc <= 1) {
    cout << "Error: please input a file" << endl;
    exit(-1);
  }

  Heap h;

  //--------------------Read in file-------------------------

  ifstream file(argv[1]);
  if ( !file.is_open() ) {
    cout << "Error reading in file!" << endl;
    exit(-1);
  }
  int x = 0;
  string str;
  int count;
  getline(file, str);
  for(int i = 0; i < str.length()-1; i++) {
    if(str.substr(0, i).find(str[i]) != std::string::npos)
	continue;
    count = 1;
    for(int j = i+1; j < str.length(); j++) {
      if(str[j] == str[i])
	count++;
    }
    h.insert(new HuffNode(count, str[i]));
    x++;
  }
  HuffNode* root = h.heapToTree();
  h.findCodes(root, "");
  string a = h.useCodes(str);
  cout << "------------------------------------------" << endl;
  cout << a << endl;
  cout << "------------------------------------------" << endl;
  cout << "There are a total of " << str.length() << " symbols that are encoded." << endl;
  cout << "There are " << x << " distinct symbols used." << endl;
  cout << "There were " << str.length()*8 << " bits in the original file." << endl;
  cout << "There were " << a.length()-str.length() << " bits in the compressed file." << endl;
  double n = a.length() - str.length();
  double m = str.length()*8;
  cout << "This gives a compression ratio of " << m/n << "." << endl;
  cout << "The cost of the Huffman tree is " << n/m*8 << " bits per character." << endl;
  return 0;
}
