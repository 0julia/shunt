#include <iostream>
#ifndef CLASS_H
#define CLASS_H
using namespace std;

class Class{
public:
  Class(char c);
  ~Class();
  Class* head;
  char num;//the eqn thing ur on rn
  Class* next;
  Class* left;
  Class* right;
  
  //stack
  Class* push(Class* n, Class* head);
  void pop();
  char peek();
  //queue
  void enqueue();
  void dequeue();
  char front();//?
};

#endif


