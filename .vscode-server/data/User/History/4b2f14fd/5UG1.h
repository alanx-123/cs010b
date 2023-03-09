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
    friend ostream & operator<<(ostream &, const IntList &): Overloads the insertion operator (<<) so that it sends to the output stream (ostream) a single line all of the int values stored in the list, each separated by a space. This function does NOT send a newline or space at the end of the line.

private:
    IntNode *head;
    IntNode *tail;
};

#endif