#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

bool precedence(char current, char previous);//will need to change to get peek in

int main(){
  Class* head = NULL;//top of stack
  Class* lefty = NULL; // front of queue (add things to front and they become the back)
  Class* righty = NULL; // qeueue dunno if i need this yet
  string fulleqn;
  char eqn;
  cout << "Wellcome. Pleese insurt A equasion: ";
  cin >> fulleqn;
  //Class* n = new Class(fulleqn[0]);
  //n->push(n);
  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];
    Class* n = new Class(var);
    head = n->push(n, head);
  }

  
  Class* current = head;
  do{
    cout << current->num << " ";
    current = current->next;
  }while (current != NULL);
  


  cout<< "!";
  return 0;
}

bool precedence(char current, char previous){
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
  
