#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
using namespace std;

struct IntNode
{
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};

class IntList
{
public:
    IntList();
    ~IntList();
    IntList(const IntList &listToCopy);
    IntList &operator=(const IntList &listToCopy);
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void selection_sort();
    void insert_ordered(int value);
    void clear();
    void remove_duplicates();
    bool empty() const;
    const int &front() const;
    int& front() const;
    const int &back() const;

protected:
    IntNode *head;
    IntNode *tail;
    friend ostream &operator<<(ostream &out, const IntList &list);
};

#endif