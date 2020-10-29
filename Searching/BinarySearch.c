/*
 * Time Complexity: O(logN)
 * It only works if the array is sorted.
 */

#include<stdio.h>

int binarySearch(int arr[], int element, int size) {
    int low = 0, high = size-1, midValue, mid;
    while(low <= high) {
        mid = (low+high)/2;
        midValue = arr[mid];
        if(midValue < element) {
            low = mid+1;
        } else if(midValue > element) {
            high = mid-1;
        } else {
            return mid;     //element Found
        }
    }
    return -1;      //element not found
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    printf("Index: %d", binarySearch(arr, 6, 6));
    return 0;
}

