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
    ifstream inFS("test.txt");
    ofstream outFS("output.txt");
    Test obj1;
    Test obj2;
    string newString;

    outSS.str(newString);

    int x;
    int y;

    obj1.set(0,2);

    while (!inFS.eof()){
        inFS >> x;
        inFS.ignore();
        inFS >>  y;
        outSS << "( " << x << ", " << y << ")  ";
    }
    if (!inFS.eof()){
        cout << "Error reading file" << endl;
        exit (1);
    }
    cout << outSS.str();


    return 0;
}