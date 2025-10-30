#include <stdio.h>
#include <stdlib.h>

typedef struct HeapNode {
    int value;
    int arrIndex;
    int elemIndex;
} HeapNode;

typedef struct MinHeap{
    HeapNode* arr;
    int size; 
    int capacity;
} MinHeap;

void swap(HeapNode* a, HeapNode* b){
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(MinHeap* heap, int i){
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < heap-> size && heap->arr[left].value < heap->arr[smallest].value) {smallest = left;}
    if (right < heap-> size && heap->arr[right].value < heap->arr[smallest].value) {smallest = right;}

    if (smallest != i){
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapifyUp(MinHeap* heap, int i){
    int parent = (i-1)/2;
    if (i>0 && heap->arr[i].value < heap->arr[parent].value){
        swap(&heap->arr[i], &heap->arr[parent]);
        heapifyUp(heap, parent);
    }
}

void insertHeap(MinHeap *heap, HeapNode node){
    if (heap->size == heap->capacity){
        printf("Heap full!\n");
        return;
    }
    heap->arr[heap->size] = node;
    heapifyUp(heap, heap->size);
    heap->size++;
}

HeapNode extractMin(MinHeap* heap){
    HeapNode root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// Function to merge k sorted arrays
void mergeKSortedArrays(int** arrays, int* sizes, int k){
    int totalSize = 0;
    for (int i = 0; i < k; i++){
        totalSize += sizes[i];
    }
    int *result = (int*)malloc(totalSize * sizeof(int));
    int resIndex = 0;
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (HeapNode*)malloc(k * sizeof(HeapNode));
    heap->capacity = k;
    heap->size = 0;

    for (int i = 0; i < k; i++){
        if (sizes[i] > 0){
            HeapNode node = {arrays[i][0], i, 0};
            insertHeap(heap, node);
        }
    }

    while (heap->size > 0){
        HeapNode minNode = extractMin(heap);
        result[resIndex++] = minNode.value;

        int nextIndex = minNode.elemIndex+1;
        if (nextIndex < sizes[minNode.arrIndex]){
            HeapNode nextNode = {arrays[minNode.arrIndex][nextIndex], minNode.arrIndex, nextIndex};
            insertHeap(heap, nextNode);
        }
    }

    printf("Merged array: ");
    for (int i = 0; i < totalSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    free(heap->arr);
    free(heap);
}

int main(){
    int k;
    printf("Enter number of arrays to merge: ");
    scanf("%d", &k);

    int** arrays = (int**)malloc(k * sizeof(int*));
    int* sizes = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++){
        printf("Enter size of array %d: ", i+1);
        scanf("%d", &sizes[i]);
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        printf("Enter elements of array %d in sorted order: ", i+1);
        for (int j = 0; j < sizes[i]; j++){
            scanf("%d", &arrays[i][j]);
        }
    }

    mergeKSortedArrays(arrays, sizes, k);
    for (int i = 0; i < k; i++){
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);
    return 0;
}