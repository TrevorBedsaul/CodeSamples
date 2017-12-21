//Trevor Bedsaul
//tdb7mw
//9/2/17
//ListItr.cpp

#include <iostream>
#include "ListItr.h"
using namespace std;

//------------------------------------------Default Constructor
ListItr::ListItr() {
  current = new ListNode();
}

//------------------------------------------One parameter cnstructor
ListItr::ListItr(ListNode* theNode) {
  current = theNode;
  current->value = theNode->value;
}

//------------------------------------------Returns true if past end position in list, else false
bool ListItr::isPastEnd() const {
  if (current->next == NULL)
    return true;
  return false;
}

//------------------------------------------Returns true if past first position in list, else false
bool ListItr::isPastBeginning() const {
  if (current->previous == NULL)
    return true;
  return false;
}

//------------------------------------------Advances current to next position in list (unless already past end of list)
void ListItr::moveForward() {
  if(!isPastEnd())
    current = current->next;
}

//------------------------------------------Moves current back to previous position unless already past beginning of list)
void ListItr::moveBackward() {
  if (!isPastBeginning())
    current = current->previous;
}

//------------------------------------------Returns item in current position
int ListItr::retrieve() const {
  return current->value;
}

//------------------------------------------Prints the list forwards when direction is true, backwards when false
void printList(List& source, bool direction) {
  if(direction) {
    ListItr iter(source.first());
    while (!iter.isPastEnd()) {
      cout << iter.retrieve() << " " ;
      iter.moveForward();
    }
  }
  else {
    ListItr iter(source.last());
    while (!iter.isPastBeginning()) {
      cout << iter.retrieve() << " ";
      iter.moveBackward();
    }
  }
}
