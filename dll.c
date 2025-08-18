#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* insertFront(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (!newNode){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data to insert at front : ");
    scanf("%d",&newNode->data);
    newNode->next = head;
    newNode->prev = NULL;

    if (head!=NULL){
        head->prev = newNode;
    }
    return newNode;
}

Node* insertBack(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (!newNode){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data to insert at back : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;

    if (head == NULL){
        newNode->prev = NULL;
        return newNode;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node* insertAnywhere(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data to insert : ");
    scanf("%d", &newNode->data);
    printf("Enter position to insert at : ");
    int position;
    scanf("%d", &position);
    if (position < 0){
        printf("Invalid position\n");
        free(newNode);
        return head; 
    }
    if (position == 0){
        return insertFront(head);
    }    
    Node* temp = head;
    for(int i = 0; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL){
        temp->next->prev = newNode; 
    }
    temp->next = newNode;
    return head;
}

Node* deleteFront(Node* head){
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* deleteBack(Node* head){
    if (head == NULL) return NULL;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL; 
    }
    free(temp);
    return head;
}

Node* deleteAnywhere(Node* head){
    if (head == NULL) return NULL;
    int position;
    printf("Enter position you want to delete at : ");
    scanf("%d", &position);
    if (position < 0){
        printf("Invalid index!\n");
        return head;
    }

    if (position == 0) {
        return deleteFront(head);
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    free(toDelete);
    
    return head;
}

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next; 
        prev = curr;
        curr = next;
    }
    return prev; 
}

Node* sortList(Node* head) {
    if (!head) return NULL;

    int swapped;
    Node* ptr;
    Node* last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);

    return head;
}


void printList(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head){
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    Node* head = NULL;
    int choice;

    do {
        printf("1. Insert at front\n");
        printf("2. Insert at back\n");
        printf("3. Insert anywhere\n");
        printf("4. Delete from front\n");
        printf("5. Delete from back\n");
        printf("6. Delete from anywhere\n");
        printf("7. Print list\n");
        printf("8. Reverse list\n");
        printf("9. Sort in Ascending order\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertFront(head);
                break;
            case 2:
                head = insertBack(head);
                break;
            case 3:
                head = insertAnywhere(head);
                break;
            case 4:
                head = deleteFront(head);
                break;
            case 5:
                head = deleteBack(head);
                break;
            case 6:
                head = deleteAnywhere(head);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                head = reverseList(head);
                printList(head);
                break;
            case 9:
                head = sortList(head);
                printList(head);
                break;
            case 10:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}