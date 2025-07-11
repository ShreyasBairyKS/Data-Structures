#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char n) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = n;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return '#'; // Returning '#' as an indicator of an empty stack
    }
    return stack[top];
}

int precedence(char symbol) {
    if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else if (symbol == '(') {
        return 0;
    } else if (symbol == '#') {
        return -1;
    }
    return -1; // Default for unsupported symbols
}

void itop(char infix[], char post[]) {
    int i = 0, j = 0;
    char item;
    char x;

    push('#'); // Push sentinel value

    while ((item = infix[i]) != '\0') {
        if (isdigit(item) || isalpha(item)) {
            post[j++] = item; // Append operands directly to the postfix expression
        } else if (item == '(') {
            push(item); // Push opening parenthesis
        } else if (item == ')') {
            while ((x = pop()) != '(') {
                post[j++] = x; // Pop until '(' is encountered
            }
        } else {
            while (precedence(peek()) >= precedence(item)) {
                post[j++] = pop(); // Pop operators with higher or equal precedence
            }
            push(item); // Push the current operator
        }
        i++;
    }

    while (peek() != '#') {
        post[j++] = pop(); // Pop remaining operators
    }

    post[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[SIZE], post[SIZE];
    printf("Enter infix expression: ");
    fgets(infix, SIZE, stdin); // Use fgets instead of gets for safer input handling

    // Remove the newline character from fgets input
    infix[strcspn(infix, "\n")] = '\0';

    itop(infix, post);

    printf("Postfix expression: ");
    puts(post);

    return 0;
}
