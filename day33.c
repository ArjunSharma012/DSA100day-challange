#include <stdio.h>
#include <ctype.h>    
#include <string.h>   
#include <stdbool.h>  

#define MAX 100

char stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(char c) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        return '\0'; 
    }
    return stack[top--];
}

char peek() {
    if (isEmpty()) return '\0';
    return stack[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        if (isalnum(c)) {  
         
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        } else {  
           
            while (!isEmpty() && precedence(peek()) >= precedence(c) &&
                   !(isRightAssociative(c) && precedence(peek()) == precedence(c))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }


    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("%s\n", postfix);

    return 0;
}
