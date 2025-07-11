#include <stdio.h>
#define MAX 5

int a[MAX];
int front = -1, rear = -1; // Initialize front and rear

// Function to enqueue an element into the queue
void enqueue(int n) {
    // Check if the queue is full
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }

    // If the queue is empty
    if (front == -1) {
        front = 0; // Set front to 0 when the first element is enqueued
    }

    rear = (rear + 1) % MAX; // Move rear to the next position circularly
    a[rear] = n; // Insert the new element
    printf("Enqueued %d\n", n);
}

// Function to dequeue an element from the queue
int dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Underflow\n");
        return -1;
    }

    int n = a[front]; // Get the element from the front
    // If the queue becomes empty after the dequeue
    if (front == rear) {
        front = rear = -1; // Reset the queue
    } else {
        front = (front + 1) % MAX; // Move front to the next position circularly
    }

    return n; // Return the dequeued element
}

// Function to display the elements in the queue
void display() {
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", a[i]);
        if (i == rear) break; // Stop when we reach the rear
        i = (i + 1) % MAX; // Move to the next position
    }
    printf("\n");
}

// Main function to test the queue implementation
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
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
