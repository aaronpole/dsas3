#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char word[50];
	char meaning[100];
	struct Node *left, *right;
} Node;

// Insert
Node* createNode(char word[], char meaning[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char word[], char meaning[]) {
    if (root == NULL){
        return createNode(word, meaning);
    }
    if (strcmp(word, root->word) < 0){
        root->left = insert(root->left, word, meaning);
    }
    else if (strcmp(word, root->word) > 0){
        root->right = insert(root->right, word, meaning);
    }
    else {
        printf("Word already exists in dictionary.\n");
    }

    return root;
}
// Search
void search(Node* root, char word[]) {
    if (root == NULL) {
        printf("Word not found!\n");
        return;
    }

    if (strcmp(word, root->word) == 0){
        printf("Meaning of '%s' is: %s\n", word, root->meaning);
    }
    else if (strcmp(word, root->word) < 0){
        search(root->left, word);
    }
    else {
        search(root->right, word);
    }
}


// Display
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    
    do {
        printf("1. Insert Word\n2. Search Word\n3. Display Dictionary\n4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter Word: ");
                fgets(word,sizeof(word),stdin);
                word[strcspn(word,"\n")] = '\0';
                printf("Enter Meaning: ");
                fgets(meaning,sizeof(meaning),stdin);
                meaning[strcspn(meaning,"\n")] = '\0';
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter Word to Search: ");
                fgets(word,sizeof(word),stdin);
                word[strcspn(word,"\n")] = '\0';
                search(root, word);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
    
    return 0;
}


