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
  //YAY its party timeeeeeeeeeeeeeeeeeee
}


Class* Class::pushStack(Class* n, Class* head){
  n->next = head;
  //  head = n;
  return head;
}

//returns the node for future movment
Class* Class::pop(Class*& head){
  if (head == NULL){
    return NULL;
  }
  Class* temp = head;
  head = head->next;
  return temp;
}


//jsut look at the top of stack char
char Class::peek(Class* head){
  if (head !=NULL){
    return '\0';
  }
  return head->num;
}


//add smth to queue
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

//returns the thinger u want to get (returns entire class)
Class* Class::dequeue(Class*& frontStack, Class*& backStack){
  if (frontStack == NULL){//if thiers nothing, say so
    return NULL;
  }
  Class* temp = frontStack;
  frontStack = frontStack->next;
  //get rid of end if theres no front
  if(frontStack == NULL){
    backStack=NULL;
  }
  return temp;
}

