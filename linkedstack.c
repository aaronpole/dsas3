#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* push(Node* head){
	Node* newNode = malloc(sizeof(Node));
	
	if (!newNode){
		printf("Memory Allocation Failed\n");
		return head;
	}
	
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	newNode->next = NULL;
	
	if (head==NULL){
		return newNode;
	}	
	Node* temp = head;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* pop(Node* head){
	if (head==NULL){
		printf("Empty list\n");
		return NULL;
	}
	
	if (head->next == NULL){
		free(head);
		return NULL;	
	}
	
	Node* temp = head;
	while (temp->next->next!=NULL){
		temp = temp->next;
	}
	Node* delete = temp->next;
	temp->next = NULL;
	free(delete);
	return head;
}

Node* peek(Node* head){
	if (head==NULL){
		printf("Empty list\n");
		return NULL;
	}
	
	Node* temp = head;
	while (temp->next!=NULL){
		temp = temp->next;
	}
	printf("Stack Top : %d",temp->data);
	return head;	
}

Node* display(Node* head){
	if (head==NULL){
		printf("Empty list\n");
		return NULL;
	}
	Node* temp = head;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	return head;
}

int main(){
	Node* head = NULL;
	int choice;
	
	do {
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		
		printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1: 
        		head = push(head);
        		printf("\n");
        		break;
        	case 2:
        		head = pop(head);
        		printf("\n");
        		break;
        	case 3:
        		head = peek(head);
        		printf("\n");
        		break;
        	case 4:
        		head = display(head);
        		printf("\n");
        		break;
        	case 5:
        		printf("Exiting..\n");
        		printf("\n");
        		exit(0);
        		break;
        	default:
        		printf("Invalid Option !\n");
        		printf("\n");
        		break;
        }
	} while(choice != 5);
	
	return 0;
}
