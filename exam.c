#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>

typedef struct Node{
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

typedef struct Stack {
    Node* items[100];
    int top;
} Stack;

void push(Stack* s, Node* node){
    s->items[++(s->top)] = node;
}

Node* pop(Stack* s){
    return s->items[(s->top)--];
}

Node* buildExpressionTree(char* postfix){
    Stack s;
    s.top = -1;

    for (int i = 0; postfix[i]; i++){
        char ch = postfix[i];
        if (isspace(ch)) continue;

        if (isalnum(ch)){
            push(&s, createNode(ch));
        }
        else{
            Node* node = createNode(ch);
            node->right = pop(&s);
            node->left = pop(&s);
            push(&s, node);
        }
    }
    return pop(&s);
}

int evaluate(Node* root){
    if (!root) return 0;
    if (!root->left && !root-> right)return root->data-'0';

    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch(root->data){
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

void inorder(Node* root){
    if (!root) return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

int main(){
    char postfix[100];
    printf("Enter postfix expression : ");
    fgets(postfix,100,stdin);
    postfix[strcspn(postfix,"\n")] = '\0';

    Node* root = buildExpressionTree(postfix);

    printf("Infix : ");
    inorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("Evaluation Result: %d\n", result);

    return 0;
}