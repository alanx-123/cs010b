#include <iostream>

using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    cout << *p++ << endl;
    cout << *p << endl;
}