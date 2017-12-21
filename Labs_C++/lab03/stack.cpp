//Trevor Bedsaul
//tdb7mw
//9/12/17
//stack.cpp

#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

Stack::Stack() {
  size = 0;
}

Stack::~Stack() {
  delete head;
}

void Stack::pop() {
  size--;
  StackNode* temp = new StackNode(head->value);
  head = head->next;
  delete temp;
}

void Stack::push(int value) {
  size++;
  StackNode* temp = new StackNode(value);
  temp->next = head;
  head = temp;
}

int Stack::top() {
  return head->value;
}

bool Stack::empty() {
  return size == 0;
}
