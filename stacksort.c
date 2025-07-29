#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr1[MAX];
int arr2[MAX];
int top1 = -1;
int top2 = -1;

void push1(int val){
    if (top1 >= MAX-1){
        return;
    }
    arr1[++top1] = val;
}

void push2(int val){
    if (top2 >= MAX-1){
        return;
    }
    arr2[++top2] = val;
}

int pop1(){
    if (top1 < 0){
        return -1;
    }
    return arr1[top1--];
}

int pop2(){
    if (top2 < 0){
        return -1;
    }
    return arr2[top2--];
}

int peek2(){
    if (top2 < 0){
        return -1;
    }
    return arr2[top2];
}

void sort(){
    int ele = pop1();
    
    while (top2 != -1 && ele > peek2()){
        push1(pop2());
    }

    push2(ele);
}

int main(){
    int ele;
    for (int i = 0; i < 10; i++){
        printf("Enter Element : ");
        scanf("%d",&ele);
        push1(ele);
    }

    
    while (top1 != -1) {
        sort(); 
    }

    printf("\nSorted Elements:\n");
    while (top2 != -1) {
        printf("%d ", pop2()); 
    }
    printf("\n");

    
}