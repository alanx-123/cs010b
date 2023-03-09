#include "SortedSet.h"
#include <unordered_set>

SortedSet::SortedSet() : IntList() {}
SortedSet::SortedSet(const SortedSet &set) : IntList(set){};
SortedSet::SortedSet(const IntList &set) : IntList(set)
{
    remove_duplicates();
    selection_sort();
}
SortedSet::~SortedSet()
{
    this->IntList::~IntList();
    ;
}
bool SortedSet::in(int value) const
{
    if (head == nullptr){
        return false;
    }
    IntNode *curr = head;
    while (curr != nullptr)
    {
        if (curr->value = value)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
const SortedSet SortedSet::operator|(const SortedSet &rhs) const{
    SortedSet unionSet;
    IntNode* curr = head;
    IntNode* curr2 = rhs.head;

    while (curr != nullptr){
        unionSet.IntList::push_back(curr-> value);
        curr = curr-> next;
    }
    while (curr2 != nullptr){
        unionSet.IntList::push_back(curr2 -> value);
        curr2 = curr2 -> next;
    }
    unionSet.selection_sort();
    return unionSet;
}
const SortedSet SortedSet::operator&(const SortedSet &rhs) const{
    SortedSet intersectionSet;
    unordered_set<int> commonValues;
    IntNode* curr = head;

    while (curr != nullptr){
        commonValues.insert(curr-> value);
        curr = curr-> next;
    }

    IntNode* curr2 = rhs.head;
    while (curr2 != nullptr){
        if (commonValues.find(curr2-> value) != commonValues.end()){
            intersectionSet.IntList::push_back(curr2-> value);
        }
        curr2 = curr2-> next;
    }
    intersectionSet.selection_sort();

    return intersectionSet;
}
void SortedSet::add(int value){
    if(head == nullptr){
        IntList::push_back(value);
        return;
    }
    IntNode * curr = head;

    while (curr -> next != nullptr && curr -> next -> value < value){
        if (curr -> value != value){
            IntNode* nextNode = curr -> next;
            IntNode* newNode = new IntNode(value);
            curr -> next = newNode;
            newNode -> next = nextNode;
            return;
        }
        curr = curr-> next;
    }
    IntList::push_back(value);
    return;
}
void SortedSet::push_front(int value){
    add(value);
}
void SortedSet::push_back(int value){
    add(value);
}
void SortedSet::insert_ordered(int value){
    add(value);
}
SortedSet &SortedSet::operator|=(SortedSet &rhs){
    *this = *this | rhs;
    return *this;
    
}
SortedSet &SortedSet::operator&=(SortedSet &rhs){
    *this =  *this & rhs;
    return *this;
}
