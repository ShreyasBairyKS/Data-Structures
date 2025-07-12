#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};
struct node *start = NULL;

void insert() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation error\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &newnode->info);
    newnode->next = start;
    start = newnode;
}

void delete(int position) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        struct node *temp = start;
        start = start->next;
        free(temp);
        return;
    }
    struct node *temp = start;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct node *nextN = temp->next->next;
    free(temp->next);
    temp->next = nextN;
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

void sort() {
    struct node *current, *nextN;
    int temp;
    if (start == NULL) {
        return;
    }
    for (current = start; current != NULL; current = current->next) {
        for (nextN = current->next; nextN != NULL; nextN = nextN->next) {
            if (current->info > nextN->info) {
                temp = current->info;
                current->info = nextN->info;
                nextN->info = temp;
            }
        }
    }
}

int main() {
    int choice, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Sort the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                printf("Enter the position of the node to delete: ");
                scanf("%d", &position);
                delete(position);
                break;

            case 3:
                printf("Current List: ");
                display();
                break;

            case 4:
                sort();
                printf("List sorted successfully.\n");
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
