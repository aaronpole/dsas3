#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int precedence(char op){
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	return 0;
}

typedef struct Node{
	char data;
	struct Node *left, *right;
} Node;

typedef struct StackNode{
	void* data;
	struct StackNode* next;
} StackNode;

void push(StackNode** top, void* data){
	StackNode* newNode = malloc(sizeof(StackNode));
	newNode -> data = data;
	newNode -> next = *top;
	*top = newNode;
}

void* pop(StackNode** top){
	if (*top == NULL) return NULL;
	StackNode* temp = *top;
	void* data = temp->data;
	*top = temp->next;
	free(temp);
	return data;
}

void* peek(StackNode* top){
	if (top==NULL) return NULL;
	return top->data;
}

int isEmpty(StackNode* top){
	return top == NULL;
}

Node* createNode(char data){
	Node* newNode = malloc(sizeof(Node));
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}

void makeSubTree(StackNode** operands, char op){
	Node* right = (Node*)pop(operands);
	Node* left = (Node*)pop(operands);
	Node* newNode = createNode(op);
	newNode -> left = left;
	newNode -> right = right;
	push(operands, newNode);
}

Node* buildExpressionTree(char* expr){
	StackNode* operands = NULL;
	StackNode* operators = NULL;
	
	for (int i = 0; expr[i] != '\0'; i++){
		char c = expr[i];
		if (c == ' ') continue;
		
		if (isalnum(c)){
			Node* newNode = createNode(c);
			push(&operands, newNode);
		}
		
		else if (c == '('){
			char* temp = malloc(sizeof(char));
			*temp = c;
			push(&operators, temp);
		}
		else if (c == ')'){
			while (!isEmpty(operators) && *((char*)peek(operators)) != '('){
				char op = *((char*)pop(&operators));
				makeSubTree(&operands, op);
			}
			free(pop(&operators));
		}
		else{
			while (!isEmpty(operators) &&
			precedence (*((char*)peek(operators))) >= precedence(c)){
				char op = *((char*)pop(&operators));
				makeSubTree(&operands, op);
			}
			char* temp = malloc(sizeof(char));
			*temp = c;
			push(&operators, temp);
		}
	}
	while(!isEmpty(operators)){
		char op = *((char*)pop(&operators));
		makeSubTree(&operands, op);
	}
	return (Node*)pop(&operands);
}

void preorder(Node* root){
	if (!root) return;
	printf("%c ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node* root){
	if (!root) return;
	postorder(root->left);
	postorder(root->right);
	printf("%c ",root->data);
}

int main(){
	char expr[100];
	printf("Enter infix expression : ");
	fgets(expr,100,stdin);
	expr[strcspn(expr,"\n")] = '\0';
	
	Node* root = buildExpressionTree(expr);
	
	printf("Prefix : ");
	preorder(root);
	printf("\n");
	
	printf("Postfix : ");
	postorder(root);
	printf("\n");
	return 0;
}
