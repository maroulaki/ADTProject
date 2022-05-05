#include <iostream>
using namespace std;

//global-local variables
int x=1000;
void f();

void f()  {
  int x=1;
  cout<<x<<endl;
  cout<<::x<<endl;
}

int main() {
  cout<<x<<endl;
  f();
  cout<<x<<endl;
  return 0;
}


//It is solved by using |extern var| from another .cpp file or ::x


Chain ADT
To access nodes, we use a "current" pointer and assign the node's Link to the next one. So our pointer points to every node.
We start with
ChainNode<T> *current = first;
and then current = current->link;
The last node is NULL

Insert new node
new_node->link=current->link;
current->link=new_node;

Circle List
New location is: loc(i)=(front+1)%maxSize
























