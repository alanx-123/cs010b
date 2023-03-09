/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void remove(int arr[], int &size,int index){
    for (int i = index; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
    size -= 1;
}
void insert(int arr[], int &size,int index){
    size++;
    for (int i = size; i > index; i--){
      arr[i] = arr[i-1];
    } 
}

int main()
{
    int arr[10];
    int size = 5;
    
    for (int i = 0; i < size ; i++){
        arr[i] = i;
        cout << arr[i] << endl;
    }
    remove(arr,size,2);   

    cout << "After erase: " << endl;
    for (int i = 0; i < size ; i++){
        cout << arr[i] << endl;
    }
    
    cout << "After insert: " << endl;

   insert(arr,size,2);   
    for (int i = 0; i < size ; i++){
        cout << arr[i] << endl;
    }
    
    
    
}


