//Trevor Bedsaul
//tdb7mw
//huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "HuffNode.h"

using namespace std;

void makeTree(HuffNode*& root, char c, string prefix, int x) {
  if(x == prefix.length())
    root = new HuffNode(c);
  else {
    if(root == NULL)
      root = new HuffNode();
    if(prefix.at(x) == '0')
      makeTree(root->left, c, prefix, x+1);
    else
      makeTree(root->right, c, prefix, x+1);
  }
}

char findCharacter(HuffNode* root, string bits) {
  for(int i = 0; i < bits.length(); i++) {
    if(bits.at(i) == '0')
      root = root->left;
    else
      root = root->right;
  }
  return root->c;
}


int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    HuffNode* root = new HuffNode();
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        cout << "character '" << character << "' has prefix code '"
             << prefix << "'" << endl;
	makeTree(root, character[0], prefix, 0);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    string decoded;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
	decoded += findCharacter(root, bits);
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    cout << "All the bits: " << allbits << endl;
    cout << decoded <<  endl;
    // close the file before exiting
    file.close();
}
