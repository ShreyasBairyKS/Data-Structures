#include <stdio.h>
#define MAX 5 // Changed to uppercase for constant

int a[MAX];
int front = -1, rear = -1;

// Function to add an element to the queue
void enqueue() {
    int n;
    // Check for overflow
    if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
        return;
    }
    // If queue is empty, set front to 0
    if (front == -1) {
        front = 0;
    }
    printf("Enter element: ");
    scanf("%d", &n); // Get the element to enqueue
    rear = (rear + 1) % MAX; // Update rear index
    a[rear] = n; // Add the new element to the queue
}

// Function to remove an element from the queue
int dequeue() {
    int n;
    // Check for underflow
    if (front == -1) {
        printf("Underflow\n");
        return -1; // Return -1 to indicate failure
    } else if (front == rear) { // If last element is being dequeued
        n = a[front]; // Store the element to return
        front = rear = -1; // Reset queue to empty state
        printf("Last element deleted: %d\n", n);
        return n;
    } else {
        n = a[front]; // Store the element to return
        front = (front + 1) % MAX; // Update front index
    }
    return n; // Return the dequeued element
}

// Function to display the queue elements
void display() {
    int i;
    // Check if the queue is empty
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    i = front; // Start from the front
    while (1) {
        printf("%d ", a[i]); // Print current element
        if (i == rear) {
            break; // Stop if reached the rear
        }
        i = (i + 1) % MAX; // Move to the next index
    }
    printf("\n");
}

// Main function to test the circular queue
int main() {
    int choice;
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
                enqueue(); // Call enqueue function
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue()); // Call dequeue function
                break;
            case 3:
                display(); // Call display function
                break;
            case 4:
                printf("Exiting program.\n");
                return 0; // Exit program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
