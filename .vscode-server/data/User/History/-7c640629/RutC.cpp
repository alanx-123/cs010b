#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Test{
    public:
        Test(){x=0;y=0;}
        void set(int x, int y){
            this -> x = x;
            this -> y = y;
        }
    void print(){
        cout << x << endl;
        cout << y << endl;
    }
    private:
        int x;
        int y;
};

int main(){
    istringstream inSS("test.cpp");
    ostringstream outSS("test.cpp");
    ifstream inFS("test.cpp");
    ofstream outFS("test.cpp");
    Test obj1;
    Test obj2;

    obj1.set(0,2);

    while (!)


    return 0;
}