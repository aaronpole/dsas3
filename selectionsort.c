#include <stdio.h>
#include <stdlib.h>

void selection (int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        int maxIndex = i;
        for (int j = i+1; j < size; j++){
            if (arr[j] > arr[maxIndex]){
                maxIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
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

    selection (arr,size);
    
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}