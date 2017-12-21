//Trevor Bedsaul
//tdb7mw
//9/2/17
//List.cpp

#include <iostream>
#include "List.h"
using namespace std;

//------------------------------------------Default Constructor
List::List() {
  count = 0;
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
}

//------------------------------------------Copy Constructor
List::List(const List& source) {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       //deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

//------------------------------------------Destructor
List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

//------------------------------------------Equals Operator
List& List::operator=(const List& source) {
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

//------------------------------------------Checks if empty
bool List::isEmpty() const {
  return (size() == 0) ? true : false;
}

//------------------------------------------Removes everything from list
void List::makeEmpty() {
  if(!isEmpty()) {
    ListItr iter(head->next);
    while (!iter.isPastEnd()) {
      ListItr temp(iter.current);
      iter.moveForward();
      remove(temp.current->value);
    }
    count = 0;
  }
}

//------------------------------------------Returns iterator that points to first list node
ListItr List::first() {
  ListItr iter(head->next);
  return iter;
}

//------------------------------------------Returns iterator that points to last list node
ListItr List::last() {
  ListItr iter(tail->previous);
  return iter;
}

//------------------------------------------Inserts x after current iterator position p
void List::insertAfter(int x, ListItr position) {
  count++;
  ListNode* temp = new ListNode;
  temp->value = x;
  temp->next = position.current->next;
  temp->previous = position.current;
  position.current->next->previous = temp;
  position.current->next = temp;
}

//------------------------------------------Inserts x before current iterator position p
void List::insertBefore(int x, ListItr position) {
  count++;
  ListNode* temp = new ListNode;
  temp->value = x;
  temp->next = position.current;
  temp->previous = position.current->previous;
  (position.current->previous)->next = temp;
  (position.current)->previous = temp;
}

//------------------------------------------Insert x at tail of list
void List::insertAtTail(int x) {
  count++;
  ListNode* temp = new ListNode;
  temp->value = x;
  temp->previous = tail->previous;
  temp->next = tail;
  tail->previous->next = temp;
  tail->previous = temp;
}

//------------------------------------------Removes first occurance of x
void List::remove(int x) {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    if (iter.retrieve() == x) {
      (iter.current->previous)->next = iter.current->next;
      (iter.current->next)->previous = iter.current->previous;
      count--;
      break;
    }
    iter.moveForward();
  }
}

//------------------------------------------Returns an iterator that points to first occurence of x, else returns an iterator to dummy tail node
ListItr List::find(int x) {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    if (iter.retrieve() == x)
      return iter;
    iter.moveForward();
  }
  iter.moveForward();
  return iter;  //returns iterator at tail position
}

//------------------------------------------Returns number of elements in list
int List::size() const {
  return count;
}
