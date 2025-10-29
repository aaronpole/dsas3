#include <stdio.h>
#include <string.h>

typedef struct Node{
    char word[50];
    struct Node* next;
} Node;

Node* createNode(char* word){
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(char* head, char* word){
    Node* newNode = createNode(word);
    if (head == NULL){return newNode;}
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void display(char* head){
    Node* temp = head;
    while (temp!=NULL){
        printf("%s ",temp->word);
        temp = temp->next;
    }
    printf("\n");
}

char* findAndReplace(char* head, char* target, char* replacement){
    Node* temp = head;
    while (temp!=NULL){
        if (strcmp(temp->word, target) == 0){
            strcpy(temp->word,replacement);
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    char word[50], target[50], replacement[50];
    char* head = NULL;
    int n;
    printf("Enter sentence (Press Enter to Exit): ");
    while (scanf("%s", word) == 1){
        head = insertNode(head, word);
        char ch = getchar();
        if (ch == '\n'){
            break;
        }
    }
    display(head);
    printf("Enter target word to find: ");
    scanf("%s", target);
    printf("Enter replacement word: ");
    scanf("%s", replacement);
    head = findAndReplace(head, target, replacement);
    printf("Updated list of words:\n");
    display(head);
    return 0;   
}