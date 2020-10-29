#include<stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid-low+1, n2 = high-mid;
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++) {
        left[i] = arr[i+low];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = arr[i+mid+1];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low+high)>>1;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array Elements: \n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, size-1);
    printf("Sorted Array: \n");
    display(arr, size);
    return 0;
}