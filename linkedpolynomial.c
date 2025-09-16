#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int exp;
	int coeff;
	struct Node* next;
} Node;

// Create each term of polynomial
Node* createNode(int coeff, int exp){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->coeff = coeff;
	newNode->exp = exp;
	newNode->next = NULL;
	return newNode;
}

// Create polynomial
Node* insertNode(Node* head, int coeff, int exp){
	Node* newNode = createNode(coeff,exp);
	if (head==NULL || exp > head->exp){
		newNode->next = head;
		return newNode;
	}
	Node* temp = head;
	while (temp->next != NULL && temp->next->exp > exp){
		temp = temp->next;
	}
	if (temp->next != NULL && temp->next->exp == exp){
		temp->next->coeff += coeff;
		free(newNode);
	} else {
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return head;
}

Node* createPolynomial(){
	Node* head = NULL;
	int n, coeff, exp;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++){
		printf("Enter coefficient and exponent : ");
		scanf("%d %d",&coeff,&exp);
		head = insertNode(head,coeff,exp);
	}
	return head;
}

void displayPolynomial(Node* head){
	if (head == NULL){
		printf("0\n");
		return;
	}
	Node* temp = head;
	while (temp != NULL){
		if (temp->coeff > 0 && temp != head) printf(" + ");
		if (temp->exp == 0)printf("%d",temp->coeff);
		else if (temp->exp == 1)printf("%dx",temp->coeff);
		else printf("%dx^%d ",temp->coeff,temp->exp);
		temp = temp->next; 
	}
	printf("\n");
}

// Addition function
Node* addPoly(Node* p1, Node* p2){
	Node* result = NULL;
	while (p1 != NULL && p2 != NULL){
		if (p1->exp == p2->exp){
			result = insertNode(result, p1->coeff+p2->coeff, p1->exp);
			p1 = p1->next;
			p2 = p2->next;
		} else if (p1->exp > p2->exp){
			result = insertNode(result, p1->coeff, p1->exp);
			p1 = p1->next;
		} else{
			result = insertNode(result, p2->coeff, p2->exp);
			p2 = p2->next;
		}
	}
	
	while (p1!=NULL){
		result = insertNode(result, p1->coeff, p1->exp);
		p1 = p1->next;
	}
	while (p2!=NULL){
		result = insertNode(result, p2->coeff, p2->exp);
		p2 = p2->next;
	}
	return result;
}
// Multiplication function
Node* multiplyPoly(Node* p1, Node* p2){
	Node* result = NULL;
	for (Node* t1 = p1; t1 != NULL; t1 = t1->next){
		for (Node* t2 = p2; t2 != NULL; t2 = t2->next){
			result = insertNode(result,t1->coeff * t2->coeff, t1->exp + t2->exp);
		}
	}
	return result;
}
// Input data
int main(){
	Node* p1 = NULL;
	Node* p2 = NULL;
	Node* result = NULL;
	int choice;
	
	printf("Enter first polynomial:\n");
	p1 = createPolynomial();
	printf("Enter second polynomial:\n");
	p2 = createPolynomial();
	
	printf("Polynomial 1 : ");
	displayPolynomial(p1);
	printf("Polynomial 2 : ");
	displayPolynomial(p2);

// Apply chosen operation
	do {
		printf("1. Addition\n");
		printf("2. Multiplication\n");
		printf("3. Exit\n");
		
		int choice;
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch (choice){
			case 1:
				result = addPoly(p1,p2);
				printf("Sum : ");
				displayPolynomial(result);
				break;
			case 2:
				result = multiplyPoly(p1,p2);
				printf("Product : ");
				displayPolynomial(result);
				break;
			case 3:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice!\n");
		}
	} while (choice != 3);
	return 0;
}
