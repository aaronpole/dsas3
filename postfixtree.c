#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a tree node
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new tree node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Stack for nodes
typedef struct Stack {
    Node* items[100];
    int top;
} Stack;

// Stack operations
void push(Stack* s, Node* node) {
    s->items[++(s->top)] = node;
}

Node* pop(Stack* s) {
    return s->items[(s->top)--];
}

// Function to build expression tree from postfix
Node* buildExpressionTree(char* postfix) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];

        if (isspace(ch)) continue; // Ignore spaces

        // If operand → create node and push
        if (isdigit(ch)) {
            push(&stack, createNode(ch));
        }
        // If operator → pop two nodes, make them children
        else {
            Node* node = createNode(ch);
            node->right = pop(&stack);
            node->left = pop(&stack);
            push(&stack, node);
        }
    }

    // Top of stack is the root
    return pop(&stack);
}

// Recursive evaluation of the expression tree
int evaluate(Node* root) {
    if (root == NULL)
        return 0;

    // If it's a leaf (operand)
    if (isdigit(root->data))
        return root->data - '0'; // convert char to int

    // Evaluate left and right subtrees
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);

    // Apply the operator
    switch (root->data) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
    }
    return 0;
}

// Inorder traversal (for debugging / visualization)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%[^\n]", postfix); // Read entire line including spaces

    Node* root = buildExpressionTree(postfix);

    printf("\nInorder traversal of expression tree: ");
    inorder(root);

    printf("\n\nResult of evaluation: %d\n", evaluate(root));

    return 0;
}
