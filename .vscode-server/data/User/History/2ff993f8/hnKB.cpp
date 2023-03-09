#include "IntList.h"
#include "SortedSet.h"
#include <iostream>
using namespace std;


int main(){
    SortedSet set1;
    SortedSet set2;

    set1.push_back(3);

    set2 = set1;
    cout << "Testing copy assignment constructor for SortedSet" << endl;
    cout << set2 << endl;

    /*IntList list1;

    cout << "list1 constructor called" << endl;
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);

    cout << "pushing 10,20,30" << endl;
    cout << list1 << endl;

    cout << "front of list: " << endl;
    cout << list1.front();

    cout << "back of list: " << endl;
    cout << list1.back();

    list1.pop_front();
    list1.pop_front();
    list1.pop_front();

    cout << "popping all 3 list elements" << endl;
    cout << list1 << endl;

    cout << "testing empty(): should return 1 " << endl;
    cout << list1.empty() << endl;

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
    
    list1.push_back(3);
    list1.push_back(1);
    cout << "Added additional 1 to end of list" << endl;
    cout << "Removing all duplicates from the list: " << endl;
    list1.remove_duplicates();
    cout << list1 << endl;

    IntList list2 = list1;

    cout << "Testing copy constructor: " << endl;
    cout << list2 << endl;

    cout << "back of list2 (testing tail pointer):  ";
    cout << list2.back() << endl;

    cout << "front of list2: " << list2.front() << endl;

    cout << "Testing copy assignment constructor: " << endl;
    
    IntList list3;
    list3 = list1;

    cout << list3 << endl;
    cout << "back of list3 (testing tail pointer):  ";
    cout << list3.back() << endl;

    cout << "front of list3: " << list3.front() << endl;

    cout << "Clearing the list: " << endl;
    list1.clear();
    cout << list1 << endl;

    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(1);
    cout << "Created new list with 5,4,2,1" << endl;
    cout << list1 << endl;

    cout << "Sorting list" << endl;
    list1.selection_sort();

    cout << list1 << endl;

    cout << "Inserting node with value 3 to make the list 1,2,3,4,5 " << endl;
    list1.insert_ordered(3);

    cout << list1 << endl;

    list1.front() = 2;

    cout << list1 << endl;

    return 0;
    */
}