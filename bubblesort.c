#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    printf("Bubble Sort\n");
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    if (arr==NULL){
        printf("Error in Allocation\n");
        return 0;
    }


    for (int i = 0; i < n; i++){
        printf("Enter number : ");
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}