#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

ostream & operator<<(ostream &out, const IntList &node){
   out << node;
   return out;
}
ostream & operator<<(ostream &out, IntNode *node){
   if (node-> next == nullptr){
      out << node -> value << endl;
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
   if (startNode -> value == num){
      return true;
   }
   if (startNode == nullptr){
      return false;
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
