#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){ stack[++top] = c; }
char pop(){ return stack[top--]; }
char peek(){ return stack[top]; }
int isEmpty(){ return top == -1; }

int precedence(char op){
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return 0;
}

// ---------- INFIX TO POSTFIX ----------
void infixToPostfix(char* exp, char* postfix){
    int k = 0;
    for (int i = 0; exp[i]; i++){
        char c = exp[i];
        if (isalnum(c)){
            postfix[k++] = c;
        }
        else if (c == '('){
            push(c);
        }
        else if (c == ')'){
            while(!isEmpty() && peek()!='(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else {
            while(!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }
    while(!isEmpty())
        postfix[k++] = pop();
    postfix[k] = '\0';
}

// ---------- POSTFIX EVALUATION ----------
int evalPostfix(char* postfix){
    int valStack[MAX];
    int topv = -1;

    for (int i = 0; postfix[i]; i++){
        char c = postfix[i];

        if (isdigit(c)){
            valStack[++topv] = c - '0'; // convert char to int
        } else {
            int b = valStack[topv--];
            int a = valStack[topv--];
            int res;

            switch(c){
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            valStack[++topv] = res;
        }
    }
    return valStack[topv];
}

// ---------- MAIN ----------
int main(){
    char exp[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evalPostfix(postfix);
    printf("Evaluated result: %d\n", result);

    return 0;
}
