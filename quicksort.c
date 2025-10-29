#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int hoarePartition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low-1;
    int j = high+1;

    while (1){
        do{
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >=j) {return j;}
        swap(&arr[i],&arr[j]);
    }
}

void printArry(int arr[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[],int low, int high,int size){
    if (low < high){
        int p = hoarePartition(arr,low,high);
        quickSort(arr,low,p,size);
        printArry(arr,size);
        quickSort(arr,p+1,high,size);
        printArry(arr,size);
    }
}

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d",&size);
    int *arr = (int*)malloc(size*sizeof(int));
    if (arr==NULL){
        printf("Error in allocation\n");
        return 0;       
    }
    for (int i = 0; i < size; i++){
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    printArry(arr,size);
    quickSort(arr,0,size-1,size);
}
