#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

int priority(char current);//will need to change to get peek in
void movein(Class*& head, Class*& front, Class*& back, char var);

int main(){
  Class* head = NULL;//top of stack
  Class* front = NULL; // front of queue (add things to front and they become the back)
  Class* back = NULL; // qeueue dunno if i need this yet
  string fulleqn = "6+(9-3*4)^2-6^4/3";
  char eqn;
  cout << "Wellcome. Please insurt a equation: " << endl<<endl;
  //cin >> fulleqn;
  cout<< fulleqn<<endl;
  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    if (head != NULL) {
      cout << "eqn loop: " << var << ". prev: " << n->peek(head) << endl;
    } else {
      cout << "eqn loop: " << var << ". prev: EMPTY" << endl;
    }
    //   cout << "eqn loop: " << var << ". prev: " << head->peek(n) <<endl;

    if(var == ')'){//if you get the close parenthesis...
      while(head != NULL && n->peek(head) != '('){//move stack to queue till u get to the open one
	Class* temp = n->pop(head);
	n->enqueue(front, back, temp);//move it to que
      }
      if(head != NULL){//get rid of the open parenthesis
	if(n->peek(head) == '('){
	  delete n->pop(head);
	}
      }
    } else if(var == '('){
	head = n->pushStack(n,head);
    } else if (var != '*' && var != '/' && var != '+' && var != '-' && var != '^'){
    //queues nums in
      n->enqueue(front,back, n);
      
      //}else if(head== NULL){
      //head = n->pushStack(n,head);
      //cout << head->num;
    }else {
      if(head != NULL){
      movein(head, front, back, var);
      head = n->pushStack(n,head);
      cout << head;
      }else{
	head = n->pushStack(n,head);
	cout << "UHGGGG IM BROKEN!!!" <<endl;}
    }

  }
  //cout << "infanite loop 32";
  Class* current = head;
  cout<<endl<< endl<<fulleqn<<endl<<endl<<"Stack: " <<endl;
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

//make sure the first opperations go straight through
//void movein(Class*& n){
void movein(Class*& head, Class*& front, Class*& back, char var){
  int curprec = priority(head->num);
  int prevprec = priority(head->peek(head));
  
  while (head != NULL && (head->num == '+' || head->num == '-' || head->num == '*' || head->num == '/' || head->num == '^') && priority(head->num) >= priority(var)) {

    Class* temp = head->pop(head);
    head->enqueue(front, back, temp);
  }
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


int priority(char current){
  if (current == '+' || current == '-'){
    return 0;//+ and - get lowest precidence
  }else if(current == '*' || current == '/'){
    return 1;//* and / get mid precedence 
  }
  return 2; // ^ gets high prec
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
  
