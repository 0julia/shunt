# include <iostream>
# include "Class.h"
using namespace std;

Class::Class(char c) {
  num = c;
  next =NULL; // stack linked list
  left=NULL; // stack linked list (points to next thing in list)
  right =NULL; // stack linked list
}

Class::~Class(){
}


void push(){
}

void pop(){
}

char peek(){
  return '0';
}

void enqueue(){
}

void dequeue(){
}

