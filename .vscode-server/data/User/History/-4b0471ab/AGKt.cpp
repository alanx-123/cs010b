#include <iostream>
#include <fstream>
#include <vector>
// #include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
   
   string inputFile;
   string outputFile;
   int num, avg;
   
   // Assign to inputFile value of 2nd command line argument
    inputFile = argv[1];

   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];

   // Create input stream and open input csv file.
    ifstream inFS;
    inFS.open(inputFile);

   // Verify file opened correctly.  
    
    // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
      cout << argc;
      return 1;
   }
   // Read in integers from input file to vector.
   vector<int> list;

   inFS >> num;
   while (!inFS.eof()) {
      list.push_back(num);
      inFS >> num;
   }

   // Close input stream.
   inFS.close();

   // Get integer average of all values read in.
   avg = num / list.size();

   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < list.size(); i++) {
      list.at(i) = list.at(i) - avg;
   }

   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);

   // Verify file opened or was created correctly.

   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening " << outputFile << endl;
      return 1;
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < list.size() - 1; i++) {
      outFS << list.at(i) << ", ";
   }
   outFS << list.at(list.back());

   // Close output stream.
   outFS.close();

   return 0;
}