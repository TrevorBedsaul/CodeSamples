#include "obj.h"

using namespace std;

Obj::Obj() {
  a = 5;
  b = 'A';
  c = true;
  d = 3;
  e = 1;
}

int Obj::getD() {
  return d;
}

int main() {
  Obj o;
  o.getD();
}
