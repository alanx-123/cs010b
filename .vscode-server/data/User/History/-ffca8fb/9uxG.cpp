#include <iostream>
#include <sstream>
using namespace std;

int main(){
    ostringstream outSS;

    outSS << "Testing " << endl;

    cout << outSS.str();
}