#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inFS;
    int num;

    inFS.open("data1.csv");

    while (inFS >> num){
        cout << num << " ";
    }

   /*  while (!inFS.fail()){
        inFS >> num;
        cout << num << " ";
    } */
    cout << endl;
    if (!inFS.eof()){
        cout << "Failure reaching end of file, exiting file." << endl;
    }

    inFS.close();
    return 0;
}