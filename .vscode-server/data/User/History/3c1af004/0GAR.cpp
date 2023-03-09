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
    IntNode *curr = head;
    while (curr != nullptr)
    {
        IntNode *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}
IntList::IntList(const IntList &listToCopy)
{
    if (listToCopy.head == nullptr)
    { // empty list to copy
        head = nullptr;
        return;
    }

    head = new IntNode *(listToCopy.head->value);
    tail = head;
    IntNode *origNode = listToCopy.head->next;

    while (origNode != nullptr)
    {
        IntNode *newNode = new IntNode(origNode->value);
        tail->next = newNode;
        tail = newNode;
        origNode = origNode->next;
    }
}
IntList &IntList::operator=(const IntList &listToCopy)
{
    if (listToCopy.head == nullptr)
    {
        IntNode *curr = head;
        while (curr != nullptr)
        {
            IntNode *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        return *this;
    }
    if (this == &listToCopy)
    {
        return *this;
    }
    IntNode *curr = head;
    while (curr != nullptr)
    {
        IntNode *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    IntNode *origNode = listToCopy.head->next;
    head = new IntNode *(listToCopy.head->value);
    tail = head;

    while (origNode != nullptr)
    {
        IntNode *newNode = new IntNode(origNode->value);
        tail->next = newNode;
        tail = newNode;
        origNode = origNode->next;
    }

    return *this;
}
void IntList::push_front(int value)
{
    IntNode* newNode = new IntNode(value);

    if(head == nullptr){
        head = newNode;
        tail = head;
        return;
    }

    newNode -> next = head;
    head = tail;
    newNode = head;
}
void IntList::pop_front()
{
    if (head == nullptr){
        return;
    }

    head = head-> next;
    delete head;
    if (head == nullptr{
        tail = nullptr;
    }

}
bool IntList::empty() const
{
    return head == nullptr;
}
const int &IntList::front() const
{
    return head -> value;
}
const int &IntList::back() const
{
    return tail -> value;
}
void IntList::remove_duplicates()
{
    if (empty()){
        return;
    }
    unordered_set<int>seenValues;

    IntNode* curr = head;
    IntNode* prev = nullptr;

    while (curr != nullptr){
        if ()
    }
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
