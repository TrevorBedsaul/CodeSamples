//Trevor Bedsaul
//tdb7mw
//9/19/17
//bitCounter.cpp

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int countBits(int x) {
  if(x == 0)
    return 0;
  if(x == 1)
    return 1;
  if(x%2 == 0)
    return countBits(x/2);
  else
    return 1 + countBits(floor(x/2));
}

int main(int argc, char *argv[]) {
  if( argc <= 1 ) {
    cout << "Error: please input a command line parameter" << endl;
    exit(-1);
  }
  int num = atoi(argv[1]);
  cout << "num = " << num << endl;
  cout << countBits(num) << endl;
  
  return 0;
}
