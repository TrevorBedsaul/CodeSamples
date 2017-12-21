#include <iostream>
using namespace std;

int main() {
  int* i = new int(4);
  cout << "i = " << i << endl;
  cout << "i = " << *i << endl;
  delete i;
  *i = 5;
  cout << "i = " << i << endl;
  cout << "i = " << *i << endl;
}
