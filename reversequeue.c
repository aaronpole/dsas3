#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value){
	if (rear == SIZE -1){
		printf("Queue Overflow\n");
		return;
	}
	else if (front == -1){
		front = 0;
		queue[++rear] = value;
	}
	else{
		queue[++rear] = value;
	}
}

int dequeue(){
	if (front == -1 || front > rear){
		printf("Queue Underflow\n");
		return -1;
	}
	return queue[front++];
}

void reversequeue(){
	if (front > rear) return;
	int data = dequeue();
	reversequeue();
	enqueue(data);
}

void displayqueue(){
	if (front == -1 || front > rear){
		printf("Queue is Empty\n");
		return;
	}
	printf("Queue : ");
	for (int i = front; i <= rear; i++){
		printf("%d ",queue[i]);
	} 
	printf("\n");
}

int main() {
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	
	printf("Original ");
	displayqueue();
	
	reversequeue();
	
	printf("Reversed ");
	displayqueue();
	
	return 0;
}


