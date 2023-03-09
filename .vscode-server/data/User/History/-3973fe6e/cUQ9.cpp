#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    } else if (arrSize == 1) {
        return &arr[0];
    } else {
        const int *min = min(&arr[1], arrSize - 1);
        if (arr[0] < *min) {
            return arr;
        } else {
            return min;
        }
    }
    return 0;
}