#include<stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low-1, j = high+1;
    while(i < j) {
        do {
            i++;
        } while(arr[i] <= pivot);
        do {
            j--;
        } while(arr[j] > pivot);
        if(i < j)
            swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);
        quicksort(arr, pivot+1, high);
    }
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6,5,4,3,2,1};
    partition(arr, 0, 5);
    display(arr, 6);
//    int size;
//    printf("Enter the size: ");
//    scanf("%d", &size);
//    int arr[size];
//    printf("Enter the array elements: \n");
//    for(int i = 0 ; i < size; i++) {
//        scanf("%d", &arr[i]);
//    }
//    quicksort(arr, 0, size-1);
//    printf("Sorted Array: \n");
//    display(arr, size);
//    return 0;
}