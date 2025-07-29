#include <stdio.h>
#include <stdlib.h>

void swap (int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void bubblesort(int arr[],int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

float mean(int arr[], int size){
    float sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum/size;
}

int median(int arr[], int size){
    bubblesort(arr,size);
    if (size%2 != 0){
        return arr[size/2];
    }
    else{
        return (arr[size/2]+arr[size/2-1])/2;
    }
}

int mode(int arr[],int size){
    int mode_val = arr[0];
    int max_count = 0;

    for (int i = 0; i < size; i++){
        int count = 0;
        for (int j = i+1; j < size; j++){
            if (arr[i] == arr[j]){
                count++;
            }
            if (count > max_count){
                max_count = count;
                mode_val = arr[i];
            }
        }
    }
    return mode_val;
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

    printf("Mean - %f\n",mean(arr,size));
    printf("Mode - %d\n",mode(arr,size));
    printf("Median - %d\n", median(arr,size));
    printf("\n");
    free(arr);
    return 0;
}
