#include <stdio.h>
#include <stdlib.h>

void rotate(int size,int arr[], int steps, char direction){
    steps = steps % size;
    int *temp = (int*)malloc(size*sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    if (direction=='R' || direction=='r'){
        for (int i = 0; i < size; i++){
            temp[i] = arr[(size-steps+i)%size];
        }
        for (int i = 0; i < size; i++){
            arr[i] = temp[i];
        }
    }
    else if (direction=='l' || direction=='L'){
        for (int i = 0; i < size; i++){
            temp[i] = arr[(steps+i)%size];
        }
        for (int i = 0; i < size; i++){
            arr[i] = temp[i];
        }
    }
    free(temp);
}

int main(){

    // Input array size and create array
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);

    int *arr = (int*)malloc(size*sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    for (int i = 0; i < size; i++){
        printf("Enter element : ");
        scanf("%d",&arr[i]);
    }

    // Input direction of rotation and steps

    int steps;
    char direction;
    printf("Enter number of steps to rotate : ");
    scanf("%d",&steps);
    printf("Enter direction of rotation (R/L) : ");
    scanf(" %c",&direction);

    // Rotate and print result

    rotate(size,arr,steps,direction);

    for (int i = 0; i < size; i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}