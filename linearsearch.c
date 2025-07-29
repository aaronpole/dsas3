#include <stdio.h>
#include <stdlib.h>

void search(int arr[], int size, int key){
    int flag = 0;
    int index;
    for (int i = 0; i < size; i++){
        if (arr[i] == key){
            flag = 1;
            index = i;
            break;
        }
        else{
            flag = 0;;
        }
    }

    if (flag == 1){
        printf("Element found at index - %d\n",index);
    }
    else{
        printf("Element not found\n");
    }
}

int main(){
    int size;
    printf("Enter array size : ");
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

    int key;
    printf("Enter element to search : ");
    scanf("%d",&key);
    
    search(arr,size,key);

    free(arr);
    return 0;
}