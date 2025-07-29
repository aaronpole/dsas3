#include <stdio.h>
#include <stdlib.h>

void insertionsort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(){

    // Enter length
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int *arr = (int*)malloc(size*sizeof(int));

    if (arr==NULL){
        printf("Error allocating memory\n");
        return 1;
    }

    for (int i = 0; i < size; i++){
        printf("Enter element : ");
        scanf("%d",&arr[i]);
    }

    insertionsort(arr,size);

    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}