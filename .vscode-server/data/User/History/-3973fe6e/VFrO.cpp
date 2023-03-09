#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0){
        return nullptr;
    }
    if (arrSize == 1){
        return arr;
    }
    else{
        if (arr[arrSize - 1] > arr[arrSize - 2]){
            return min(arr, arrSize - 1);
        }
        else{
            return &arr[arrSize - 1];
        }
    }
}