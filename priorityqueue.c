#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int category;      // 1 = DA, 2 = SC, 3 = Defence, 4 = Ordinary
    int arrivalOrder;  // Lower = earlier arrival
} Customer;

typedef struct {
    Customer heap[100];
    int size;
} PriorityQueue;

// Compare priorities (return 1 if a has higher priority than b)
int compare(Customer a, Customer b) {
    if (a.category < b.category) return 1;
    if (a.category == b.category && a.arrivalOrder < b.arrivalOrder) return 1;
    return 0;
}

void swap(Customer *a, Customer *b) {
    Customer temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && compare(pq->heap[index], pq->heap[parent])) {
        swap(&pq->heap[index], &pq->heap[parent]);
        heapifyUp(pq, parent);
    }
}

void heapifyDown(PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < pq->size && compare(pq->heap[left], pq->heap[smallest]))
        smallest = left;
    if (right < pq->size && compare(pq->heap[right], pq->heap[smallest]))
        smallest = right;

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

void insertCustomer(PriorityQueue *pq, char *name, int category, int order) {
    Customer c;
    strcpy(c.name, name);
    c.category = category;
    c.arrivalOrder = order;

    pq->heap[pq->size] = c;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

Customer extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue is empty!\n");
        Customer empty = {"", 0, 0};
        return empty;
    }
    Customer min = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return min;
}

void displayQueue(PriorityQueue *pq) {
    printf("\nCurrent Queue (Top = Next to Serve):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%s (Category %d, Order %d)\n",
               pq->heap[i].name,
               pq->heap[i].category,
               pq->heap[i].arrivalOrder);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    pq.size = 0;
    int order = 1;

    int choice;
    char name[50];
    int category;

    while (1) {
        printf("\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter customer name: ");
            scanf("%s", name);
            printf("Enter category (1=DA, 2=SC, 3=Defence, 4=Ordinary): ");
            scanf("%d", &category);
            insertCustomer(&pq, name, category, order++);
        }
        else if (choice == 2) {
            Customer c = extractMin(&pq);
            if (strlen(c.name) != 0)
                printf("Serving: %s (Category %d)\n", c.name, c.category);
        }
        else if (choice == 3) {
            displayQueue(&pq);
        }
        else break;
    }
    return 0;
}
