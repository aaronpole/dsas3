#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int val){
    if (top >= MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top]=val;
    printf("%d pushed onto stack\n",val);   
}

void pop(){
    if (top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack\n",stack[top--]);
}

void peek(){
    if (top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d\n",stack[top]);
}

void display(){
    if (top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    int size = sizeof(stack)/sizeof(int);
    for (int i = 0; i < size; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){

    while(1){
        printf("Stack Operations\n\n1. Push\n2. Pop\n3. Peek\n4. Display\n\n");
        int choice;
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int num;
                printf("Enter number: ");
                scanf("%d",&num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice !\n");
        }
        printf("\n\n");
    }

    return 0;
    
}