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
    IntList(const IntList &listToCopy);
    IntList &operator=(const IntList &listToCopy);
    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void remove(int value);
    void removeDuplicates();
    bool isSorted() const;
    bool empty() const;
    const int & front() const;
    const int & back() const;

private:
    IntNode *head;
    IntNode *tail;
    friend ostream & operator<<(ostream &out, const IntList &list);
};

#endif