#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int size;
    int arr[MAX];
} MinHeap;

// Helper functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->arr[parent(index)] > heap->arr[index]) {
        swap(&heap->arr[parent(index)], &heap->arr[index]);
        index = parent(index);
    }
}

// Heapify Down
void heapifyDown(MinHeap* heap, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insert(MinHeap* heap, int value) {
    if (heap->size == MAX) {
        printf("Heap full!\n");
        return;
    }
    heap->arr[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Extract minimum element
int extractMin(MinHeap* heap) {
    if (heap->size <= 0) return -1;
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Print heap
void printHeap(MinHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

int main() {
    MinHeap heap;
    heap.size = 0;

    insert(&heap, 30);
    insert(&heap, 20);
    insert(&heap, 10);
    insert(&heap, 40);

    printHeap(&heap);

    printf("Extracted Min: %d\n", extractMin(&heap));
    printHeap(&heap);

    return 0;
}
