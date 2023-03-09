#include "IntList.h"
#include <iostream>
using namespace std;


int main(){
    IntList list1;

    cout << "list1 constructor called" << endl;
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);

    cout << "pushing 10,20,30" << endl;
    cout << list1 << endl;

    list1.pop_front();
    list1.pop_front();
    list1.pop_front();

    cout << "popping all 3 list elements" << endl;
    cout << list1 << endl;

    list1.push_front(100);
    list1.push_front(200);
    list1.push_front(300);

    cout << "repopulating list with 3 elements using push_front" << endl;
    cout << list1 << endl;

    list1.pop_back();
    list1.pop_back();
    list1.pop_back();
    
    cout << "pop_back 3 times" << endl;
    cout << list1 << endl;

    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    
    cout << "push_back 3 times with 1,2,3" << endl;
    cout << list1 << endl;

    cout << "isSorted function test with sorted list:  ";
    if (list1.isSorted() == true){
        cout << "The list is sorted." << endl;
    }


    list1.push_back(2);

    cout << "isSorted function test with unsorted list: ";
    if (list1.isSorted() == false){
        cout << "The list is not sorted" << endl;
    }

    cout << "Removing value 3 from the list: " << endl;
    list1.remove(3);
    cout << list1 << endl;

    list1.push_back(3);
    list1.push_back(1);
    cout << "Removing all duplicates from the list: " << endl;
    list1.removeDuplicates();
    cout << list1 << endl;

    IntList list2 = list1;

    cout << "Testing copy constructor: " << endl;
    list2 = list1;

    cout << list2 << endl;


    return 0;
}