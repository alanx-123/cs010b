#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0){
        return nullptr;
    }
    if (arrSize == 1){
        return arr;
    }
    else{
        const int *min = min(&arr[1], arrSize - 1);

        if (arr[0] < *min){
            return &arr[0];
        }
        else{
            return min;
        }
    }
}