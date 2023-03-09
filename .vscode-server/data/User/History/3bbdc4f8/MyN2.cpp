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

    while (head != nullptr)
    {
        IntNode *nextNode = head->next;
        delete head;
        head = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}
IntList::IntList(const IntList &listToCopy)
{
    if (listToCopy.empty())
    {
        head = nullptr;
        return;
    }

    head = new IntNode(listToCopy.head->value); // no push-back variation
    tail = head;

    IntNode *originalNode = listToCopy.head->next;

    while (originalNode != nullptr)
    {
        tail->next = new IntNode(originalNode->value);
        tail = tail->next;
        originalNode = originalNode->next;
    }
}
IntList &IntList::operator=(const IntList &listToCopy)
{
    if (listToCopy.empty())
    {
        head = nullptr;
        return *this;
    }
    if (this == &listToCopy)
    {
        return *this;
    }

    while (head != nullptr)
    {
        IntNode *nextNode = head->next;
        delete head;
        head = nextNode;
    }
    tail = nullptr;

    IntNode *originalNode = listToCopy.head;

    // push_back variation
    while (originalNode != nullptr)
    {
        this->push_back(originalNode->value);
        originalNode = originalNode->next;
    }
    return *this;
}

void IntList::push_front(int value)
{
    IntNode *newNode = new IntNode(value);

    newNode->next = head;
    head = newNode;
    if (tail == nullptr)
    {
        tail = head;
    }
}
void IntList::pop_front()
{
    if (head != nullptr)
    {
        { // default case: at least 1 node in the list
            IntNode *nextNode = head->next;
            delete head;
            head = nextNode;
        }
        if (head == nullptr) // edge case: If we just deleted the last node, head will point to nullptr. therefore, we also need to point tail to nullptr
        {
            tail = nullptr;
        }
    }
}
bool IntList::empty() const
{
    return (head == nullptr);
}
const int &IntList::front() const
{
    return head->value;
}
const int &IntList::back() const
{
    return tail->value;
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
        IntNode* nextNode = curr -> next;
        if (seenValues.find(curr-> value) != seenValues.end()){
            prev -> next = curr -> next;
            if (curr == tail){
                tail = prev;
            }
            delete curr;
            
        }
        else{
            seenValues.insert(curr-> value);
            prev = curr;
        }
        curr = nextNode;
    }
}
/*void IntList::remove_duplicates()
{
    if (head == nullptr)
    {
        return;
    }
    if (head->next == nullptr)
    {
        return;
    }

    unordered_set<int> seenValues;
    IntNode *curr;

    curr = head;
    IntNode *prev = nullptr;

    while (curr != nullptr)
    {
        if (seenValues.find(curr->value) != seenValues.end())
        {
            prev->next = curr->next;
            IntNode *nextNode = curr->next;

            if (curr == tail) // deleting last node
            {
                tail = prev;
            }
            delete curr;
            curr = nextNode;
        }
        else
        {
            seenValues.insert(curr->value);
            prev = curr;
            curr = curr->next;
        }
    }
}
*/
void IntList::push_back(int value)
{
    if (empty()){
        head = new IntNode(value);
        tail = head;
        return;
    }

    IntNode* newNode = new IntNode(value);
    tail -> next = newNode;
    tail = newNode;
    newNode -> next = nullptr;
}

ostream &operator<<(ostream &out, const IntList &list)
{
    IntNode *dummy = list.head;

    if (list.head != nullptr)
    {
        while (dummy->next != nullptr)
        {
            out << dummy->value << " ";
            dummy = dummy->next;
        }
        out << dummy->value;
    }

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
        prev = curr;
        curr = curr -> next;
    }
    if (curr -> value == value){
        return;
    }
    if (prev == tail){
        push_back(value);
        return;
    }
    
    IntNode* newNode = new IntNode(value);
    prev -> next = newNode;
    newNode -> next = curr -> next;
}
void IntList::clear()
{
    while (head != nullptr)
    {
        IntNode *nextNode = head->next;
        delete head;
        head = nextNode;
    }
}
