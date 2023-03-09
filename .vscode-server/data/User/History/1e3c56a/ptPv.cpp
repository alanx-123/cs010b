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
      out << node -> next;
   }
   return out;
}
bool IntList::exists(int num) const{
   return exists(head, num);
}
 bool exists(IntNode *startNode, int num) const{
   
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
