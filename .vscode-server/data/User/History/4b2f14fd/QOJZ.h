#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
using namespace std;

struct IntNode
{
    IntNode* next;
    int value;
    IntNode(int value): value(value) , next(nullptr){}
}

class IntList
{

private:
    IntNode *head;
    IntNode *tail;
}

#endif