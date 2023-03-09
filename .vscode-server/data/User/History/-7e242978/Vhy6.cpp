#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s){
    if (s.length() <= 1){
        return;
    }
    else{
        char temp = s.back();
        s.back() = s.front();
        s.front() = temp;

        string newStr = s;
        s.erase(s.length() - 1);
        s.erase(0);
        flipString(s);
    }
}

