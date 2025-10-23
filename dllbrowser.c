#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev, *next;
} Node;

Node *current = NULL;

Node* createNode(char *url) {
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void visit(char *url) {
    Node *newNode = createNode(url);
    if (current) {
        // clear forward history
        Node *temp = current->next;
        while (temp) {
            Node *del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = newNode;
        newNode->prev = current;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}

void back() {
    if (current && current->prev) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else printf("No previous page.\n");
}

void forward() {
    if (current && current->next) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else printf("No next page.\n");
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Current page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visit(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                if (current) printf("Current page: %s\n", current->url);
                else printf("No pages visited yet.\n");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
