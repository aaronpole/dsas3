#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* enqueue(Node* head){
	Node* newNode = malloc(sizeof(Node));
	
	if (!newNode){
		printf("Memory Allocation Failed!\n");
		return NULL;
	}
	
	printf("Enter data : ");
	scanf("%d",&newNode->data);
	newNode->next = head;
	
	if (head == NULL){
		return newNode;
	}
	return newNode;
}

Node* dequeue(Node* head){
	if (!head){
		printf("Empty queue\n");
		return NULL;
	}
	if (!head->next){
		free(head);
		return NULL;
	}
	Node* temp = head;
	while (temp->next->next != NULL){
		temp = temp->next;
	}
	Node* delete = temp->next;
	temp->next = NULL;
	free(delete);
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
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		
		printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1: 
        		head = enqueue(head);
        		printf("\n");
        		break;
        	case 2:
        		head = dequeue(head);
        		printf("\n");
        		break;
        	case 3:
        		head = display(head);
        		printf("\n");
        		break;
        	case 4:
        		printf("Exiting..\n");
        		printf("\n");
        		exit(0);
        		break;
        	default:
        		printf("Invalid Option !\n");
        		printf("\n");
        		break;
        }
	} while(choice != 4);
	
	return 0;
}
