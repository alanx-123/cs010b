#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   string inputFile;
   string outputFile;
   int sum = 0;
   vector<int>nums;
   int avg;
   
   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   /*inputFile = argv[1];
   outputFile = argv[2];*/
   cin >> inputFile;
   cin >> outputFile;
   // Create input stream and open input csv file.
   ifstream inSS;

   inSS.open(inputFile);
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inSS.is_open()){
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }
   char c;

   while (inSS >> c){
      nums.push_back(atoi(c));
   }

   inSS.close();
   
   // Read in integers from input file to vector.
   
   // Close input stream.
   
   // Get integer average of all values read in.
   for (int num: nums){
      sum += num;
   }
   avg = sum / nums.size();
   
   // Convert each value within vector to be the difference between the original value and the average.

   for (int &num: nums){
      num -= avg;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;

   outFS.open(outputFile);

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()){
      cout << "Error opening " << outputFile << endl;
      exit(1);
   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < nums.size() - 1; i++){
      outFS << nums[i] << ",";
   }
   outFS << nums[nums.size() - 1];
   // Close output stream.
   outFS.close();
   
   return 0;
}