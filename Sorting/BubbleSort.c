#include<stdio.h>

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 1; j < size -i; j++) {
            if(arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array: \n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[20], size;
    printf("Enter the size of the Array: ");
    scanf("%d", &size);
    if(size > 20) {
        printf("Size Limit Exceeds!!");
        return 0;
    }
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, size);
    return 0;
}

