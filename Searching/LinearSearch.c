#include<stdio.h>

//Time Complexity: O(n)
int linearSearch(int *arr, int ele, int size) {

    int i;
    for(i = 0; i < size; i++) {
        if(ele == arr[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    
    int size, i, n, arr[10], ele;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    int index = linearSearch(arr, ele, size);
    (index != -1)? printf("Index is %d", index): printf("Element not found");
    return 0;
}