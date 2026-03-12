#include <iostream>
#include <cstring>// dunno
#include "class.h"
using namespace std;



int main(){
  string fulleqn;
  char eqn;
  cout << "Welcome. Please insurt An equasion: ";
  cin >> fulleqn;
  for (int i = 0; i < fulleqn.size(); i++){
    Class* n = new Class(fulleqn[i]);
  }
  return 0;
}

/*

void add(const char newvalue[100], Class* &head);
void print(Class* next, Class* head);

int main(){
  Class* head = NULL;




  
  //delete s and n from add()
  Class* next = head;
  while (next != NULL) {
    Class* nextNode = next->getNext();
    delete next->getStudent();
    delete next;
    next = nextNode;
  }
  head = NULL;  // list is now empty
  return 0;
}



void add(char newvalue, node* &head){
  node* next = head;
  if (next == NULL){//if empty list
    //student* s = new student();
    //s->name(newvalue);
    node* n = new node(s);
    head = n;
  } else{ //if theres stuff in the list
    while (next->getNext() != NULL){
      next = next->getNext();
    }
    
    student* s = new student();
    s->name(newvalue);
    node* n = new node(s);
    next->setNext(n);
  }
}



void print(node* next, node* head){
  if(next == head){
    cout << "list: ";
  }
  if(next != NULL){
    cout << next->getStudent()->name() << " ";
    print(next->getNext(), head);
  }
}
*/
