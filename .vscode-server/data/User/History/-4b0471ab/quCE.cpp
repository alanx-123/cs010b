#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   string inputFile;
   string outputFile;
   
   inputFile = argv[1];
   outputFile = argv[2]; 
   
   ifstream inSS;
   vector<int> nums;

   inSS.open(inputFile);

   if (!inSS.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }

   istringstream inFS;

   while (inFS{
      if (c != ',' && c != ','){
         nums.push_back(int(c));
      }
   }

   
   inSS.close();
   
   int sum = 0;
   int avg;

   for (int num: nums){
      sum += num;
   }

   avg = sum / nums.size();

   for (unsigned int i = 0; i < nums.size(); i++){
      nums[i] -= avg;
   }
   ofstream outFS;

   outFS.open(outputFile);

   if(!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      exit(1);
   }

   for (unsigned int i = 0; i < nums.size() - 1 ; i++){
      outFS << nums[i] << ",";
   }
   outFS << nums[nums.size() - 1];

   outFS.close();
   
   return 0;
}