#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream inSS("output.txt");
    int num;
    string str;
    char c;

    inSS >> num;
    inSS >> str;
    inSS.get(c);
    inSS >> c;
    cout << c;
}