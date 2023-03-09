#ifndef IntVector_H
#define IntVector_H
#include <iostream>
#include <stdexcept>
using namespace std;

class IntVector {
    IntVector(unsigned capacity, int value);
    ~IntVector();
    unsigned size() const;
    

    private:
        unsigned _size;
        unsigned _capacity;
        int *_data;
};



#endif