#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

ostream & operator<<(ostream &out, IntNode *node){
   if (node-> next == nullptr){
      out << node -> value << endl;
      return;
   }
   else{
      out << node -> value << " ";
      
   }
}
bool IntList::exists(int num) const{
   
}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}
