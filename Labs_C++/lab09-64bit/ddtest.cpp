#include <iostream>
#include <cstdlib>

using namespace std;

class A {
public:
  virtual void foo() {
    cout << "A method" << endl;
  }
};
class B : public A {
  virtual void foo() {
    cout << "B method" << endl;
  }
};

int main() {
  int which = rand() % 2;
  A *bar;
  if( which )
    bar = new A();
  else
    bar = new B();
  bar->foo();
  return 0;
}
   
    
