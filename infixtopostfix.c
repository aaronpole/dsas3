#include <stdio.h>
#define MAX 100
#include <ctype.h>

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int isEmpty(){
    return top == -1;
}

int precedence (char op){
    if (op=='^') return 3;
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return 0;
}

void infixToPostfix(char* exp){
    for (int i = 0; exp[i]; i++){
        char c = exp[i];
        if isalnum(c){
            printf("%c",c);
        }
        else if (c=='('){
            push(c);
        }
        else if (c==')'){
            while(!isEmpty() && peek()!='('){
                printf("%c",pop());
            }
            pop();
        }

        else{
            while (!isEmpty() && precedence(peek())>=precedence(c)){
                printf("%c",pop());
            }
            push(c);
        }
    }
    while(!isEmpty()){
        printf("%c",pop());
    }
}

int main(){
    char exp[100];
    printf("Enter infix expression: ");
    scanf("%s",exp);
    printf("Postfix: ");
    infixToPostfix(exp);
    printf("\n");
    return 0;
}