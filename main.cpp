#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

bool priority(char current, char previous);//will need to change to get peek in

int main(){
  Class* head = NULL;//top of stack
  Class* front = NULL; // front of queue (add things to front and they become the back)
  Class* back = NULL; // qeueue dunno if i need this yet
  string fulleqn;
  char eqn;
  cout << "Wellcome. Pleese insurt A equasion: ";
  cin >> fulleqn;
  cout<< " in";
  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    cout << "infanite loop ";
    if(var == ')'){
      if(n->peek(head) != '('){
	n->enqueue(front, back, n->pop(head));
      }
      while(head != NULL && n->peek(head) == '('){
	n->pop(head);
      }
    }      
    else if (var != '*' && var != '/' && var != '+' && var != '-' && var != '(' && var != '^'){
    //queues nums in
      n->enqueue(front,back, n);
      
    } else {
      head = n->pushStack(n,head);
    
      // bool more = precedence(var, head->num);
      //cout << more;
    }

  }
cout << "infanite loop 32";
  Class* current = head;
  cout<<"Stack: " <<endl;
  if(current != NULL){
    do{
      cout << current->num;
      current = current->next;
    }while (current != NULL);
  }

  cout<< endl<<endl<<"Queue: " <<endl;
  current = front;
  if(current != NULL){
    
    do{
      cout << current->dequeue(front, back)->num;
      current = current->next;
    }while (current != NULL);
  }
  

  cout<< "!";
  //cout<<endl<<"-bash: syntax error near unexpected token `5-6'";
  return 0;
}


  /*

  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    head = n->pushStack(n,head);
    cout << n->pop(n)<<" ";
    //head = n->enqueue(n, head);
  }

  Class* current = head;
  do{
    cout << current->num;
    current = current->next;
  }while (current != NULL);
  

  //add everything to queue
  /*

  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    n->enqueue(front,back, n);
    //head = n->enqueue(n, head);
  }
  

  
  Class* current = front;
  do{
    cout << current->dequeue(front, back)->num;
    current = current->next;
  }while (current != NULL);
  
  */


bool priority(char current, char previous){
  int curprec;
  if (current == '+' || current == '-'){
    curprec = 0;
    return false;
  }else if(current == '*' || current == '/'){
    return true;
  }
  return false;
}
  
    //queues everything in
    /*    Class* n = new Class(var);
    n->left = lefty;
    n->right = righty;
    head = n;
    /
    if (var != '*' && var != '/' && var != '+' && var != '-' && var != '(' && var != ')' && var != '^'){
    //stacks everything in
    /*Class* n = new Class(var);
    n->push(n);
    /*n->next = head;
    head = n;
    /
    } else {
      // bool more = precedence(var, head->num);
      //cout << more;
    }
    //    */
  
