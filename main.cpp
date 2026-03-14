#include <iostream>
#include <cstring>// dunno
#include "Class.h"
using namespace std;

char precedence();

int main(){
  Class* head = NULL;
  string fulleqn;
  char eqn;
  cout << "Wellcome. Pleese insurt A equasion: ";
  cin >> fulleqn;

  for (int i = 0; i < fulleqn.size(); i++){
    char var=fulleqn[i];

    if (var
    Class* n = new Class(var);
    n->next = head;
    head = n;
  }
  

  Class* current = head;
  for (int i = 0; i < fulleqn.size(); i++){
    cout << current->num << " ";
    current = current->next;
  }
  
  return 0;
}
