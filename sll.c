#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* insertFront(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data to insert at front: ");
    scanf("%d", &newNode->data);
    newNode -> next = head;
    return newNode;
}

Node* insertBack(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("Enter data to insert at back: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if (head==NULL){
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAnywhere(Node* head){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter data to insert: ");
    scanf("%d", &newNode->data);
    printf("Enter position to insert : ");
    int position;
    scanf("%d", &position);
    if (position < 0){
        printf("Invalid position\n");
        free(newNode);
        return head;
    }
    else if (position == 0){
        newNode->next = head;
        return newNode;
    }
    else{
        Node* temp = head;
        for(int i = 0;i < position-1 && temp != NULL; i++){
            temp = temp-> next;
        }
        if (temp==NULL){
            printf("Position out of bounds\n");
            free(newNode);
            return head;
        }
        newNode -> next = temp->next;
        temp->next = newNode;
        return head;
    }
}

Node* deleteFront(Node* head){
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteEnd(Node* head){
    if (head == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAny(Node* head){
    if (head == NULL) return NULL;
    int position;
    printf("Enter position you want to delete at : ");
    scanf("%d",&position);
    if (position < 0){
        printf("Invalid index!\n");
        return head;
    }

    if (position == 0) {
        Node* toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
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
    free(toDelete);

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void numberofNodes(Node* head){
    int count = 0;
    Node* temp = 0;
    temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Number of nodes in the list: %d\n", count);
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    Node* head = NULL;
    int choice;

    do {
        printf("\n1. Insert at front\n");
        printf("2. Insert at back\n");
        printf("3. Insert anywhere\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete from anywhere\n");
        printf("7. Print list\n");
        printf("8. Reverse list\n");
        printf("9. Display number of nodes\n");
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
                head = deleteEnd(head);
                break;
            case 6:
                head = deleteAny(head);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                head = reverse(head);
                printf("List reversed.\n");
                printList(head);
                break;
            case 9:
                numberofNodes(head);
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