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
    string middle = s.substr(1, s.length() - 2);
    flipString(middle);

    // Swap the first and last characters
    char temp = s[0];
    s[0] = s[s.length() - 1];
    s[s.length() - 1] = temp;

    // Concatenate the reversed middle substring to the swapped first and last characters
    s = s[s.length() - 1] + middle + s[0];
}

