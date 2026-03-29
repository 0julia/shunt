#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

int priority(char current);//will need to change to get peek in
void movein(Class*& n, Class*& head, Class*& front, Class*& back);
//void movein(Class*& head, Class*& front, Class*& back, char var);
char peek(Class* head);

int main(){
  Class* head = NULL;//top of stack
  Class* front = NULL; // front of queue (add things to front and they become the back)
  Class* back = NULL; // qeueue dunno if i need this yet
  string fulleqn = "6+(9-3*4)^2-6^4/3";
  char eqn;
  cout << "Wellcome. Please insurt a equation: " << endl<<endl;
  //cin >> fulleqn;


  //infix to postfix
  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    // cout << "eqn loop: " << var << " Next: " << peek(head) << endl;

    //start by getting close parenthesis!!!
    if (var == ')') {
      //move things in parenthesis into queue
      while (head != NULL && peek(head) != '(') {
	Class* temp = head->pop(head);
	temp->enqueue(front, back, temp);
      }
      //delete open parenthesis
      if (head != NULL && peek(head) == '(') {
	delete head->pop(head);
      }
      delete n; // delete )
      //      continue;
    }

    //pushes ( ritgh into stack
    else if (var == '('){
      head = n->pushStack(n, head);
      //continue;
    } else if (var != '*' && var != '/' && var != '+' && var != ')' && var != '(' && var != '-' && var != '^'){
      //queues nums inf
      n->enqueue(front,back, n);
      
    }//push operators into stac/queue in order
    else {
      movein(n, head, front, back);
      head = n->pushStack(n, head);
    }
  }//end for loop

  //at end put operators into que
  while (head != NULL) {
    Class* temp = head->pop(head);
    temp->enqueue(front, back, temp);
  }
  
  //print stack adn queue
  Class* current = head;
  cout<< endl << fulleqn << endl<<"Stack: " <<endl;
  if(current != NULL){
    do{
      cout << current->num;
      current = current->next;
    }while (current != NULL);
  }
  
  cout<<endl<<"Queue: " <<endl;
  current = front;
  if(current != NULL){
    
    do{
      cout << current->dequeue(front, back)->num;
      current = current->next;
    }while (current != NULL);
  }
  
  //now turn into a bianary tree?? 
  
  //cout<<endl<<"-bash: syntax error near unexpected token `5-6'";
  return 0;
}


void movein(Class*& n, Class*& head, Class*& front, Class*& back){
  while (head != NULL && peek(head) !='(' && priority(n->num) <= priority(peek(head))) {
    Class* temp = n->pop(head);//delete from stack
    n->enqueue(front, back, temp);//enqueue operator
  }
}

int priority(char current){
  if (current == '+' || current == '-'){
    return 1;
  }else if(current == '*' || current == '/'){
    return 2;
  }
  return 3;
}

char peek(Class* head){
  if (head != NULL){
    return head->num;
  }
  return '\0';
}
