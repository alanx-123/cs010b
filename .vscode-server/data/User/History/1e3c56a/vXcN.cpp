#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

ostream & operator<<(ostream &out, const IntList &list){
   if (list.head != nullptr){
      out << list.head;
   }
   return out;
}
ostream & operator<<(ostream &out, IntNode *node){
   if (node-> next == nullptr){
      out << node -> value;
   }
   else{
      out << node -> value << " ";
      out << node -> next;
   }
   return out;
}
bool IntList::exists(int num) const{
   return exists(head, num);
}
bool IntList::exists(IntNode *startNode, int num) const{
   if (startNode == nullptr){
      return false;
   }
   if (startNode -> value == num){
      return true;
   }
   else{
      return exists(startNode -> next, num);
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
