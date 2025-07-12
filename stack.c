#include <stdio.h>
#define max 5

int a[max];  // Array to hold stack elements
int top = -1; // Initialize stack pointer

// Function to push an element onto the stack
void push(int n) {
    if (top == max - 1) {
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    a[top] = n;
    printf("Pushed %d\n", n); // Print confirmation
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int n = a[top];
    top = top - 1;
    printf("Popped %d\n", n); // Print confirmation
    return n;
}

// Function to peek at the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return a[top]; // Return the top element
}

// Function to display the current state of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
