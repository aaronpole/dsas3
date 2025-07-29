#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];

int front = -1;
int rear = -1;

int isEmpty(){
	return (front == -1);
}

int isFull(){
	return ((rear+1)%MAX == front);
}

void insertfront(int ele){
	if (isFull()){
		printf("Deque Full\n");
	}
	else if (isEmpty()){
		front = 0;
		rear = 0;
		deque[front] = ele;
	}
	else{
		front = (front - 1 + MAX) % MAX;
		deque[front] = ele;
	}
}

void insertrear(int ele){
	if (isFull()){
		printf("Deque Full\n");
	}
	else if (isEmpty()){
		front = 0;
		rear = 0;
		deque[rear] = ele;
	}
	else{
		rear = (rear+1)%MAX;
		deque[rear] = ele;
	}
}

void deletefront(){
	if (isEmpty()){
		printf("Deque Underflow\n");
	}
	else if (front ==rear){
		front = -1;
		rear = -1;
	}
	else{
		front = (front+1)%MAX;
	}
}

void deleterear(){
	if (isEmpty()){
		printf("Deque Underflow\n");
	}
	else if (front ==rear){
		front = -1;
		rear = -1;
	}
	else{
		rear = (rear-1+MAX)%MAX;
	}
}

void display(){
	if (isEmpty()){
		printf("Queue Empty\n");
		return;
	}
	int i = front;
	while (1) {
		printf("%d ", deque[i]);
		if (i == rear){
			break;
		}
		i = (i + 1) % MAX;
	}
}

int main(){
	while (1){
		printf("\nDeque Operations\n\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n\n");
		int choice;
		printf("Enter Choice : ");
		scanf("%d",&choice);
		printf("\n");
		switch (choice){
			case 1:
				int ele1;
				printf("Enter element : ");
				scanf("%d",&ele1);
				insertfront(ele1);
				break;
			case 2:
				int ele2;
				printf("Enter element : ");
				scanf("%d",&ele2);
				insertrear(ele2);
				break;
			case 3:
				deletefront();
				break;
			case 4:
				deleterear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Invalid Input\n");
		}
	}
		printf("\n\n");
		return 0;
}


