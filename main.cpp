#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

int priority(char current);//will need to change to get peek in
void movein(Class*& n, Class*& head, Class*& front, Class*& back);
void prerecurcive(Class* current);
void inrecurcive(Class* current);
void postrecurcive(Class* current);

char peek(Class* head);

int main(){
  Class* head = NULL;//top of stack
  Class* front = NULL; // front of queue (add things to front and they become the back)
  Class* back = NULL; // qeueue dunno if i need this yet
  Class* tree = NULL;
  string fulleqn = "6+(9-3*4)^2-6^4/3";
  char eqn;
  cout << "Wellcome. Please insurt a equation: " << endl;
  //cin >> fulleqn;


  //infix to postfix
  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    // cout << "eqn loop: " << var << " Next: " << peek(head) << endl;

    //start by getting close parenthesis!!! (and ignoreing spaces)
    if(var == ' '){
      continue;
    }else if (var == ')') {
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


  //print postfix/queue & infix
  cout << "Infix: " << fulleqn << endl;
  cout<<"Postfix: ";
  Class* current = front;
  while (current != NULL){
    cout << current->num;
    current = current->next;
  }



  
  //now turn into a bianary tree
  current = front;
  
  while(current != NULL){
    char val = current->num;//set the num/op that ur working on
    //if number set as leaf? of tree
    if (val != '+' && val != '-' && val != '*' && val != '/' && val != '^') {
      Class* node = new Class(val);
      node->left = NULL;
      node->right = NULL;
      node->next = tree;
      tree = node;
      //if  opperator set as parent? of num leafs
    } else {
      Class* right = tree;
      tree = tree->next;
      Class* left = tree;
      tree = tree->next;
      Class* node = new Class(val);
      node->left = left;
      node->right = right;
      node->next = tree;
      tree = node;
    }
    //go to next node    
    current = current->next;
  }



  

  //now print pre/in/post fix

  string input;
  
  bool valid = false;
  cout<<endl << "how would you likd to print the eqn? (in/pre/post): ";
  cin >> input;

  if(input== "in"){
    cout << "INFIX: ";
    inrecurcive(tree);
  }else if (input == "pre"){
    cout << "PREFIX: " << endl;
    prerecurcive(tree);
  }else if(input == "post"){
    cout << "POSTFIX: " << endl;
      postrecurcive(tree);
  }else{
    cout<< "thats not one of the options, try again ";
      cin >> input;
  }cout << endl;




  
  cout<<endl<<"-bash: syntax error near unexpected token `5-6'";
  return 0;
}

//go down follow the leftmost path and do that diagnolally
void prerecurcive(Class* current){
  if (current == NULL){ //dont break
    return;
  }
  cout << current->num; //print
  //RECURSIVEE!!!!
  prerecurcive(current->left);
  prerecurcive(current->right);
}


//print left, opperator, right
void inrecurcive(Class* current){
  if (current == NULL){ //dont break
    return;
  }
  
  //RECURSIVEE!!!!
  if(current->left != NULL){
    cout << "(";
  }
  inrecurcive(current->left);
  cout << current->num; //print
  inrecurcive(current->right);
  if(current->left != NULL){
    cout << ")";
  }
}

//print left, right, opperator
void postrecurcive(Class* current){
  if (current == NULL){ //dont break
    return;
  }
  
  //RECURSIVEE!!!!
  postrecurcive(current->left);
  postrecurcive(current->right);
  cout << current->num; //print
  
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
