# include <iostream>
# include "Class.h"
using namespace std;

Class::Class(char c) {
  num = c;
  Class* head = NULL;
  next =NULL; // stack linked list
  frontStack=NULL; // stack linked list (points to next thing in list)
  backStack =NULL; // stack linked list
}

Class::~Class(){
}


Class* Class::pushStack(Class* n, Class* head){
  n->next = head;
  head = n;
  return head;
}

//void Class::print(Class*n){}

void pop(Class* head){
}

char peek(Class* head){
  return '0';
}

void Class::enqueue(Class*& frontStack, Class*& backStack, Class* n){
  n->next = NULL;
  if (backStack == NULL){
    frontStack=n;
    backStack=n;
  }else{
    backStack->next = n;
    backStack = n;

  }
}

void dequeue(Class*& frontStack, Class*& backStack){
}

