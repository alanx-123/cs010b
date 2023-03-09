#include <iostream>
#include "IntVector.h"

using namespace std;

void printVector(const IntVector &nums);

int main()
{
    IntVector testVector(5, 1);
    IntVector emptyVector(0, 0);

    /*
    cout << "Stage 1:" << endl;
    cout << "Test #1, size of vector: " << testVector.size() << endl;
    cout << "Test #2, capacity of vector: " << testVector.capacity() << endl;

    cout << "Test #3, front of vector: " << testVector.front() << endl;
    cout << "Test #4, back of vector: " << testVector.back() << endl;
    cout << "Test #5, empty vector: " << emptyVector.empty() << endl;

    cout << "Test #6, at function on empty vector: " << emptyVector.at(2) << endl;
    cout << "Test #7, at function on normal vector: " << testVector.at(2) << endl;

    if (testVector.size() != 5) {
        cout << "Test #1 failed" << endl;
    }
    if (testVector.capacity() != 5){
        cout << "Test #2 failed" << endl;
    }
    if (testVector.front() != 1){
        cout << "Test #3 failed" << endl;
    }
    if (testVector.back() != 1){
        cout << "Test #4 failed" << endl;
    }
    if (emptyVector.empty() == false){
        cout << "Test #5 failed" << endl;
    }

    cout << endl;
    */

    cout << "Stage 2: " << endl;
    cout << "Test #1, erase function" << testVector.erase(2) << endl;
    cout << "Vector after using erase: ";
    printVector(testVector);
    cout << endl;
    if (testVector.size() != 4)
    {
        cout << "Test #1 failed, erase function error." << endl;
    }

    cout << "Test #2, push_back function" << endl;
    testVector.push_back(6);
    cout << "Size after push_back function: " << testVector.size() << endl;
    cout << "Vector after using push_back";
    printVector(testVector);
    cout << endl;
    if (testVector.at(5) != 6 || testVector.size() != 6){
        cout << "Test #2 failed, push_back function error." << endl;
    }

    cout << "Test #3, pop_back function" << endl;
    testVector.pop_back();
    cout << "Size after pop_back function" << testVector.size() << endl;
    cout << "Vector after using pop_back function: ";
    printVector(testVector);
    cout << endl;
    if (testVector.size() != 5){
        cout << "Test #3 failed, pop_back function error." << endl;
    }

    cout << "Test #4, resize function, scenario one " << endl;
    testVector.resize(12,5) // edge case #1
    cout << "Vector after using resize function: ";
    printVector(testVector);
    cout << endl;
    if (testVector.capacity() != 12){
        cout << "Test #4.1 failed, resize function" << endl;
    }
    
    cout << "Test #4, resize function, scenario two" << endl;
    testVector.resize(9,5);
    printVector(testVector);
    cout << endl;
    if (testVector.capacity() != 10){
        cout << "Test #4.2 failed, resize function" << endl;
    }

    cout << "Test #5, reserve function, scenario one" << endl;
    testVector.reserve(8);
    cout << "Vector after using reserve function: ";
    printVector(testVector);
    cout << endl;
    if (testVector.capacity() != 9){
        cout << "Test #5.1 failed, reserve function" << endl;
    }

    cout << "Test #5, reserve function, scenario two" << endl;
    testVector.reserve(15);
    cout << "Vector after using reserve function: ";
    printVector(testVector);
    cout << endl;
    if (testVector.capacity() != 15){
        cout << "Test #5.2 failed, reserve function" << endl;
    }

    cout << "Test #6, assign function" << endl;
    testVector.assign(10,2);
    if (testVector.at(2) != 2){
        cout << "Test #6 failed, Assign function test failed." << endl;
    }

    cout << "Test #7, clear function" << endl;
    testVector.clear();
    if (testVector.size() != 0){
        cout << "Test #7 failed, clear function" << endl;
    }



    return 0;
} // g++ main.cpp IntVector.cpp -Wall -Werror -Wuninitialized -o a.out
/*
    void erase(unsigned index);
    void assign(unsigned n, int value);
    void push_back(int value);
    void pop_back();
    void clear();
    void resize(unsigned n, int value = 0);
    void reserve(unsigned n );
*/
void printVector(const IntVector &nums)
{
    for (unsigned int i = 0; i < nums.size(); i++)
    {
        cout << nums.at(i) << " ";
    }
    cout << endl;
}
/*
IntVector(unsigned capacity, int value);
    ~IntVector();
    unsigned size() const;
    unsigned capacity const;
    bool empty() const;
    const int &at(unsigned index) const;
    const int &front() const;
    const int &back() const;
*/
/*
