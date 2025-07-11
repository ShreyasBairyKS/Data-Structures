#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *top = NULL;

void push(int n) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    p->info = n;
    p->next = top;
    top = p;
    printf("Pushed %d\n", n);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
        return;
    }
    struct node *temp = top;
    printf("Popped %d\n", top->info);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;  // Use a temporary pointer to traverse the stack
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
