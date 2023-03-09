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
      return out << node -> next -> value;
   }
}
bool IntList::exists(int num) const{
   if (node -> value == num){
      return true;
   }
   else{
      return exists(num);
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
