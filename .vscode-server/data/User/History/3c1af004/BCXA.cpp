#include "IntList.h"
#include "SortedSet.h"
#include <vector>
#include <unordered_set>

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    IntNode * curr = head;
    while (curr != nullptr){
        IntNode* nextNode = curr -> next;
        delete curr;
        curr = nextNode;
    }
}
IntList::IntList(const IntList &listToCopy)
{
    if (listToCopy.head = nullptr){ //empty list to copy
        head = nullptr;
        return;
    }
    
    head = new IntNode* (listToCopy.head -> value);
    tail = head;
    IntNode* origNode = listToCopy.head -> next;

    while (origNode != nullptr){
        IntNode* newNode = new IntNode(origNode -> value);
        tail -> next = newNode;
        tail = newNode;
        origNode = origNode -> next;
    }

}

void IntList::push_front(int value)
{

}
void IntList::pop_front()
{
}
bool IntList::empty() const
{

}
const int &IntList::front() const
{
 
}
const int &IntList::back() const
{

}
void IntList::remove_duplicates()
{
    
}

void IntList::push_back(int value)
{
    
}

ostream &operator<<(ostream &out, const IntList &list)
{
    
}
void IntList::selection_sort()
{
    
}
void IntList::insert_ordered(int value)
{
    
}
void IntList::clear()
{
    
}
