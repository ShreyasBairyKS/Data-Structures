#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};
struct node *start = NULL;

void insert(int info, int position) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation error\n");
        return;
    }
    newnode->info = info;
    newnode->next = NULL;

    if (position == 0) {
        newnode->next = start;
        start = newnode;
        return;
    }

    struct node *temp = start;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete() {
    if (start == NULL) {
        printf("Empty list\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    struct node *temp = start;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void reverse() {
    struct node *previous = NULL, *current = start, *nextN;
    while (current != NULL) {
        nextN = current->next;
        current->next = previous;
        previous = current;
        current = nextN;
    }
    start = previous;
}

void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d->", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete the last node\n");
        printf("3. Reverse the list\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &position);
                insert(value, position);
                break;

            case 2:
                delete();
                printf("Last node deleted.\n");
                break;

            case 3:
                reverse();
                printf("List reversed successfully.\n");
                break;

            case 4:
                printf("Current List: ");
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
