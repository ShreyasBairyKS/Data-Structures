#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// Function to enqueue an element into the queue
void enqueue(int n) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    p->info = n;
    p->next = NULL;

    if (rear == NULL) { // If queue is empty
        front = rear = p; // Both front and rear point to the new node
    } else {
        rear->next = p; // Link the new node at the end of the queue
        rear = p; // Move rear to the new node
    }
    printf("Enqueued %d\n", n);
}

// Function to dequeue an element from the queue
void dequeue() {
    if (front == NULL) { // Check for underflow
        printf("Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Dequeued %d\n", front->info);
    front = front->next; // Move front to the next node

    // If the queue is now empty, reset rear to NULL
    if (front == NULL) {
        rear = NULL;
    }
    free(temp); // Free the memory of the dequeued node
}

// Function to display the queue elements
void display() {
    struct node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->info); // Print the element
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Main function to test the queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
