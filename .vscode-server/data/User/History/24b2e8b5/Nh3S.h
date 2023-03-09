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
    private:
        bool in(int value) const;
        
}

#endif