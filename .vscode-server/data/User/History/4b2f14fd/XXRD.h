#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
using namespace std;

struct IntNode
{
    IntNode *next;
    int value;
    IntNode(int value) : value(value), next(nullptr) {}
};


class IntList
{
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    bool empty() const;
    const int & front() const;
    const int & back() const;
    

private:
    IntNode *head;
    IntNode *tail;
};

#endif