#include <iostream>
#ifndef CLASS_H
#define CLASS_H
using namespace std;

class Class{
public:
  Class(char c);
  ~Class();
  //Class* head;
  char num;//the eqn thing ur on rn
  Class* next;
  Class* frontStack;
  Class* backStack;
  
  //stack
  Class* pushStack(Class* n, Class* head);
  void pop(Class* head);
  char peek(Class* head);
  //queue
  void enqueue(Class*& frontStack, Class*& backStack, Class* n);
  void dequeue(Class*& frontStack, Class*& backStack);
  char front();//?
};

#endif


