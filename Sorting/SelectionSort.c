#include<stdio.h>
#include<limits.h>

void swap(int arr[], int i , int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int size) {
    int n = size-1;
    for(int i = 0; i < size; i++) {
        int max = INT_MIN, index = -1;
        for(int j = 0; j < size-i; j++) {
            if(max < arr[j]) {
                max = arr[j];
                index = j;
            }
        }
        swap(arr, index, n);
        n--;
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
    selectionSort(arr, size);
    printf("Sorted Array: \n");
    display(arr, size);
    return 0;
}

