#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string filename, char c);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(string filename, char c){
   ifstream inSS;
   int count = 0;
   char input;

   inSS.open(filename);

   if (!inSS.is_open()){
      cout << "Error opening " << filename << endl;
      exit(1);
   }

   while (inSS.get(input)){ // accounts for spaces
      if (input == c){
         count++;
      }
   }
   inSS.close();
   return count;
}