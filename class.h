#include <iostream>
#ifndef CLASS_H
#define CLASS_H
using namespace std;

class Class{
public:
  Class(char c);
  ~Class();
  char num;//the eqn thing ur on rn
  Class* next;
  Class* left;
  Class* right;
  //still need types for everything
  //stack
  /*push();
  pop();
  peek();
  //queue
  enqueue();
  dequeue();
  */
};

#endif


