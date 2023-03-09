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
        if (seenValues.find(curr-> value) != seenValues.end(){
            if (prev == nullptr){
                IntNode* nextNode = curr -> next;
                delete curr;
                head = nextNode;
            }
            else if (curr == tail){
                prev -> next = nullptr;
                prev = tail;
                delete curr;
            }
            else{
                prev -> next = curr -> next;
                delete curr;
            }
        }
        else{
            seenValues.insert(curr-> value);
        }
        prev = curr;
        curr = curr -> next;
    }
}

void IntList::push_back(int value)
{
    if (empty()){
        head = new IntNode(value);
        tail = head;
    }

    IntNode* newNode = new IntNode(value);
    tail -> next = newNode;
    tail = newNode;
    newNode -> next = nullptr;
}

ostream &operator<<(ostream &out, const IntList &list)
{
    IntNode* curr = head;
    IntNode* prev = nullptr;

    while (curr != nullptr){
        out << curr -> value << " ";
        prev = curr;
        curr = curr -> next;
    }

    out << prev -> value << endl;
    return out;
}
void IntList::selection_sort()
{
    IntNode* curr = head;
    IntNode* minValNode;
    IntNode* minValFinder;
    int minVal;

    for (curr = head; curr != nullptr; curr = curr -> next){
        minVal = curr -> value;
        minValNode = curr;
        for (minValFinder = curr -> next; minValFinder != nullptr; minValFinder = minValFinder -> next){
            if (minValFinder -> value < minVal){
                minVal = minValFinder -> value;
                minValNode = minValFinder;
            }
        }
        if (minValNode != curr){
            int temp = minValNode -> value;
            minValNode -> value = curr -> value;
            curr -> value = temp;
        }
    }
}
void IntList::insert_ordered(int value)
{
    if (empty()){
        push_back(value);
    }

    if (head -> next == nullptr){
        if (head -> value > value){
            push_front(value);
        }
        else if (head -> value < value){
            push_back(value);
        }
    }

    IntNode* curr = head;
    IntNode* prev = nullptr;
    while (curr != nullptr && curr -> value > value){
        if (curr -> value == value){
            return;
        }
        
        prev = curr;
        curr = curr -> next;
    }
}
void IntList::clear()
{
    IntNode* curr = head;
    while (curr != nullptr){
        IntNode* nextNode = curr -> next;
        delete curr;
        curr = curr -> next;
    }
}
