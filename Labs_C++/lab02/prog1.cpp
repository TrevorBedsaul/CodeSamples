//Trevor Bedsaul
//tdb7mw
//9/2/17
//prog1.cpp

#include <iostream>
using namespace std;

void my_subroutine() {
    cout << "Hello world" << endl;
}

int main() {
    int x = 4;
    int *p = NULL;
    my_subroutine();
    *p = 3;
    cout << x << ", " << *p << endl;
    return 0;
}
