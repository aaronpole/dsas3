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
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head){
        temp = temp->next;
	}
    newNode->next = head;
    temp->next = newNode;
    return newNode;  
}

Node* insertBack(Node* head) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter data to insert at back: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}


Node* insertAnywhere(Node* head) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    printf("Enter data to insert: ");
    scanf("%d", &newNode->data);
    printf("Enter position to insert: ");
    int position;
    scanf("%d", &position);

    if (position < 0) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    if (head == NULL) {
        if (position == 0) {
            newNode->next = newNode;
            return newNode;
        } else {
            printf("Position out of bounds\n");
            free(newNode);
            return head;
        }
    }

    if (position == 0) {
        return insertFront(head);
    }

    Node* temp = head;
    for (int i = 0; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && position > 1) {
        printf("Position out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}


Node* deleteFront(Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    Node* tail = head;

    while (tail->next != head)
        tail = tail->next;

    head = head->next;
    tail->next = head;
    free(temp);
    return head;
}


Node* deleteEnd(Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = head;
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
        return deleteFront(head);
    }
    
    if (head->next == head && position > 0) {
    printf("Position out of bounds!\n");
    return head;
}


    Node* temp = head -> next;
    for (int i = 0; i < position - 1 && temp != head; i++) {
        temp = temp->next;
    }

    if (temp == head || temp->next == head) {
        printf("Position out of bounds!\n");
        return head;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}


void freeList(Node* head) {
	if (!head) return;
    Node* temp = head -> next;
    while (temp != head) {
    	Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(head);
}

void numberofNodes(Node* head) {
    if (head == NULL) {
        printf("Number of nodes in the list: 0\n");
        return;
    }

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("Number of nodes in the list: %d\n", count);
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
        printf("8. Display number of nodes\n");
        printf("9. Exit\n");
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
                numberofNodes(head);
                break;
            case 9:
                freeList(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
