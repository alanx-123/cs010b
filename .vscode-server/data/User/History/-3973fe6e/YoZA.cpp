#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) 
    {
        return nullptr;
    } 
    else if (arrSize == 1) 
    {
        return &arr[0];
    } 
    else 
    {
        const int *minLoc = min(&arr[1], arrSize - 1);
        if (arr[0] < *minLoc) 
        {
            return arr;
        } 
        else 
        {
            return minLoc;
        }
    }
    return 0;
}