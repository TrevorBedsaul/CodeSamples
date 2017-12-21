//Trevor Bedsaul
//tdb7mw
//9/10/17
//postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
#include <cstdlib>
using namespace std;

PostfixCalculator::PostfixCalculator() {
  count = 0;
}


void PostfixCalculator::add() {
  int a = pop();
  int b = pop();
  pushNum(a+b);
}

void PostfixCalculator::subtract() {
  int a = pop();
  int b = pop();
  pushNum(b-a);
}

void PostfixCalculator::multiply() {
  int a = pop();
  int b = pop();
  pushNum(a*b);
}

void PostfixCalculator::divide() {
  int a = pop();
  int b = pop();
  pushNum(b/a);
}

void PostfixCalculator::negate() {
  int a = pop();
  pushNum(0-a);
}

void PostfixCalculator::pushNum(int x) {
  s.push(x);
  count++;
}

int PostfixCalculator::getTopValue() {
  if(isEmpty())
    exit(-1);
  return s.top();
}

int PostfixCalculator::pop() {
  if(isEmpty())
    exit(-1);
  count--;
  int a = getTopValue();
  s.pop();
  return a;
}

int PostfixCalculator::size() {
  return count;
}
bool PostfixCalculator::isEmpty() {
  return s.empty();
}
