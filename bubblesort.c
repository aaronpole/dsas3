#include <stdio.h>
#include <stdlib.h>

void swap (int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
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

    // Bubble Sort
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] < arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}