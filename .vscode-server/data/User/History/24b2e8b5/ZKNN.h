#ifndef SORTEDSET_H
#define SORTEDSET_H
#include "IntList.h"
#include <iostream>
using namespace std;

class SortedSet : public IntList
{   
    public:
        SortedSet();
        SortedSet(const SortedSet &set);
        SortedSet(const IntList &set);
        ~SortedSet();
        bool in(int value) const;
        SortedSet &operator|(const SortedSet &rhs) const;
        SortedSet &operator&(const SortedSet &rhs) const;
        void add(int value);
        void push_front(int value) override;
        void push_back(int value) override;
        void insert_ordered(int value) override;
        SortedSet &operator|=(const SortedSet&rhs) const;
        SortedSet &operator&=(const SortedSet&rhs) const;
};

#endif