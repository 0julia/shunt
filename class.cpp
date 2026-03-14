# include <iostream>
# include "Class.h"
using namespace std;

Class::Class(char c) {
  num = c;
  head = NULL;
  next =NULL; // stack linked list
  left=NULL; // stack linked list (points to next thing in list)
  right =NULL; // stack linked list
}

Class::~Class(){
}


Class* Class::push(Class* n, Class* head){
  n->next = head;
  head = n;
  return head;
}

//void Class::print(Class*n){}

void pop(){
}

char peek(){
  return '0';
}

void enqueue(){
}

void dequeue(){
}

