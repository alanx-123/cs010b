#ifndef IntVector_H
#define IntVector_H
#include <iostream>
#include <stdexcept>
using namespace std;

class IntVector
{
public:
    IntVector();
    IntVector(unsigned capacity, int value = 0);
    ~IntVector();
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int &at(unsigned index) const;
    const int &front() const;
    const int &back() const;
    int &front();
    int & back();
    void erase(unsigned index);
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned n, int value = 0);
    void reserve(unsigned n );

private:
    unsigned _size;
    unsigned _capacity;
    int *_data;
};

#endif