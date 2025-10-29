#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size -1;
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter target element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1){
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    free(arr);
    return 0;
}