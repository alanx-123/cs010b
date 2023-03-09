#include <iostream>
#include <fstream>
using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   string fileName = argv[1];
   ifstream inFS;
   // verify file name provided on command line

   // open file and verify it opened
   inFS.open(fileName);
   if (!inFS.is_open()){
      cout << "Error opening " << fileName << endl;
      exit(1);
   }
   // Declare an array of doubles of size ARR_CAP.
   double arr[ARR_CAP];    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   double num;
   int index = 0;
   int arrSize;

   while (inFS >> num){
      arr[index] = num;
      index++;
   }
   arrSize = index;
    
   // Call the mean function passing it this array and output the 
   // value returned.
   cout << "Mean: " <<  mean(arr, arrSize) << endl;
   cout << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Enter index of value to be removed ( 0 to 98): " << endl;
   cin >> index;
   cout << endl;

	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(arr, arrSize);
   cout << endl;
   cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove (arr, arrSize, index);
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(arr, arrSize);
   cout << endl;
   
   // Call the mean function again to get the new mean
   cout << endl;
   cout << "Mean: " <<  mean(arr, ARR_CAP) << endl;
   
	return 0;
}
//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   double sum = 0;
   for (int i = 0; i < arraySize; i++){
      sum += array[i];
   }
   return sum/static_cast<double>(arraySize);
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   for (int i = 0; i < arraySize; i++){
      if (index == i){
         for (int j = i ; j < arraySize-1; j++){
            array[j] = array[j+1];
         }  
      }
   }
   arraySize -= 1;
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for (int i = 0 ; i < arraySize - 1; i++){
      cout << array[i] << ", ";
   }
   cout << array[arraySize-1];
}