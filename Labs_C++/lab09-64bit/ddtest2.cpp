#include <iostream>
#include <cstdlib>

using namespace std;

class A {
public:
  void foo() {
    cout << "A method" << endl;
  }
};
class B {
public:
  void foo() {
    cout << "B method" << endl;
  }
};

int main() {
  int which = rand() % 2;
  A *bar;
  B *bbar;
  if( which )
    bar = new A();
  else
    bbar = new B();
  bar->foo();
  return 0;
}
   
    
