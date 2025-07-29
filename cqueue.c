#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];

int front = 0; 
int rear = 0;

void enqueue(int ele){
	if ((rear+1) % MAX == front){
		printf("Queue Full\n");
	}
	else{
			rear = (rear+1)%MAX;
			queue[rear] = ele;
	}
}

void dequeue(){
	if (front == rear){
		printf("Queue Empty\n");
	}
	else{
		front = (front+1)%MAX;
	}
}

void display(){
	if (front == rear){
		printf("Queue Empty\n");
		return;
	}
	
	int i = (front + 1) % MAX;
	while (i != (rear + 1) % MAX){
		printf("%d ", queue[i]);
		i = (i + 1) % MAX;
	}
	printf("\n");
}

int main(){
	while (1){
		printf("\nQueue Operations\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
		int choice;
		printf("Enter Choice : ");
		scanf("%d",&choice);
		printf("\n");
		switch (choice){
			case 1:
				int ele;
				printf("Enter element : ");
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid Input\n");
		}
	}
		printf("\n\n");
		return 0;
}

