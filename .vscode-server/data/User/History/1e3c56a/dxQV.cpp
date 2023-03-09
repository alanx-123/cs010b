#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

ostream & operator<<(ostream &out, IntNode *node){
   if (node-> next == nullptr){
      out << node -> value << endl;
      return out;
   }
   else{
      out << node -> value << " ";
      out <<(out, node -> next);
   }
   return out;
}
bool IntList::exists(int num) const{
   if (curr -> value == num){
      return true;
   }
   IntNode* curr = head;
   curr = curr -> next;
   return exists(num);
  
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
