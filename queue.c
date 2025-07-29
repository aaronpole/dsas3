#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];

int front = -1; 
int rear = -1;

void enqueue(int ele){
	if (rear == MAX-1){
		printf("Queue Full\n");
	}
	else{
		if (front == -1 && rear == -1){
			front = 0;
			queue[++rear] = ele;
		}
		else{
			queue[++rear] = ele;
		}
	}
}

void dequeue(){
	if (front == -1){
		printf("Queue Empty\n");
	}
	else if (front == rear){
		front = -1;
		rear = -1;
	}
	else {
		front++;
	}
}

void display(){
	if (front == -1){
		printf("Queue Empty\n");
	}
	else{
		for (int i = front; i < rear+1; i++){
			printf("%d ",queue[i]);
		}
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

