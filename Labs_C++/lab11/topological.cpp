// This program shows how C-based file I/O works.  It will open a
// file, read in the first two strings, and print them to the screen.

// included so we can use cout
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings
    /**
     * strings s1 and s2 to read in file
     */
    string s1, s2;
    
    /**
     * string vector to hold the first string on each line
     */
    vector<string> a;

     /**
     * string vector to hold the second string on each line
     */
    vector<string> b;

    /**
    * string vector to hold the unrepeated strings
    */
    vector<string> c;

    /**
    * int vector to correspond to string vector c with number of pointers to it
    */
    vector<int> d;

    file.clear();
    file.seekg(0, ios::beg);
    while(true) {
       file >> s1;
       file >> s2;
       if(s1 == "0" || s2 == "0")
	 break;
       a.push_back(s1);
       b.push_back(s2);
    // output those strings
       cout << s1 << " " << s2 << endl;
    // string comparison done with ==, but not shown here
    // close the file before exiting
    }

    /**
     * counter to get number of times each is pointed to
     */
    int count = 0;
    for(int x = 0; x < b.size(); x++) {
      if(find(c.begin(), c.end(), b[x]) != c.end())
	continue;
      count = 0;
      for(int y = x; y < b.size(); y++) {
	if(b[y] == b[x])
	  count++;
      }
      c.push_back(b[x]);
      d.push_back(count);
    }

    for(int x = 0; x < a.size(); x++) {
      if(find(c.begin(), c.end(), a[x]) == c.end()) {
	c.push_back(a[x]);
	d.push_back(0);
      }
    }
    
    /**
     * int used to keep track of minimum value
     */
    int min;
    for(int m = 0; m < c.size(); m++) {
      for(int j = 0; j < c.size(); j++) {
	if(d[j] < d[min])
	  min = j;
      }
      cout << c[min] << endl;
      d[min] = 1000000000;
      for(int n = 0; n < a.size(); n++) {
	if(c[min] == a[n]) 
	  for(int l = 0; l < c.size(); l++)
	    if(b[n] == c[l]) {
	      d[l] = d[l]-1;
	    }
      }
    }
    file.close();
}

