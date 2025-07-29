#include <stdio.h>
#include <stdlib.h>

#define MAX 10
char string[MAX];
int top=-1;


void push(char ch){
    if (top >= MAX-1){
        printf("Stack OverFlow !\n");
        return;
    }
    string[++top] = ch;
}

char pop(){
    if (top == -1){
        printf("Stack Underflow!\n");
        return '\0';
    }
    return string[top--];
}

void readstring(char str[]){
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF && i < MAX - 1){
        str[i++] = ch;
    }
    str[i] = '\0';
}

int main(){
    char str[MAX];
    printf("Enter a string: ");
    readstring(str);

    int i = 0;
    while(str[i] != '\0'){
        push(str[i]);
        i++;
    }
    printf("Reversed String : ");
    while (top!=-1){
        printf("%c",pop());
    }
    printf("\n");
    return 0;

}
