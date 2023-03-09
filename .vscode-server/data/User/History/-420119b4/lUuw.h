#ifndef IntVector_H
#define IntVector_H
#include <iostream>
#include <stdexcept>
using namespace std;

class IntVector {
    IntVector(unsigned capacity, int value);
    ~IntVector();
    unsigned size() const;
    unsigned capacity const;
    bool empty() const;
    const int & at(unsigned index) const;
    const int & front() const;
    const int & back() const;

    private:
        unsigned _size;
        unsigned _capacity;
        int *_data;
};



#endif