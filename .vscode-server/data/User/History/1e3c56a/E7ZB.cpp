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
      << ()
   }
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
