//Trevor Bedsaul
//tdb7mw
//8/29/17
//LifeCycle.h

#ifndef LIFECYCLE_H
#define LIFECYCLE_H
#include <string>
using namespace std;
// ---------------------------------------------------  class definition
class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const;
    void setName(const string newName);
    friend ostream & operator<<(ostream& output, const MyObject& obj);

    //Prototypes:
    MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
    int cmpMyObj(const MyObject o1, const MyObject o2);
    void  swapMyObj(MyObject& o1, MyObject& o2);

 private:
    string name;
    int id;
};

#endif
