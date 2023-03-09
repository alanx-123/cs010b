#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string fileName);

int main() {
   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(string fileName){
   ifstream inSS;
   int sum = 0;
   int num;

   inSS.open(fileName);

   if (!inSS.is_open()){
      cout << "Error: file does not exist. Proceeding to exit." << endl;
      exit(1);
   }
   while (!inSS.eof() && !inSS.fail()){
      inSS >> num;
      sum += num;
   }

   return sum;
}