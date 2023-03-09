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
    istringstream inSS;
    ostringstream outSS;
    ifstream inFS;
    ofstream outFS;
    Test obj1;
    Test obj2;

    obj1.set(0,2);

    obj2 = obj1;

    obj2.print();
}