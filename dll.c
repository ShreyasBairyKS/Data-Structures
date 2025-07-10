#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int info;
    struct node *next;
};
struct node *start = NULL;

struct node *getnode(int value) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("No memory allocated\n");
        return NULL;
    }
    p->info = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert(int n, int key) {
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->info == key) {
            struct node *newnode = getnode(n);
            struct node *back = temp->prev;
            if (back == NULL) { // Insert at the start
                newnode->next = start;
                start->prev = newnode;
                start = newnode;
            } else { // Insert in the middle
                back->next = newnode;
                newnode->prev = back;
                newnode->next = temp;
                temp->prev = newnode;
            }
            printf("Node with value %d inserted before %d.\n", n, key);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found.\n", key);
}

void delete(int n) {
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->info == n) {
            if (temp->next == NULL && temp->prev == NULL) { // Only node
                free(temp);
                start = NULL;
            } else if (temp->prev == NULL) { // First node
                start = temp->next;
                start->prev = NULL;
                free(temp);
            } else if (temp->next == NULL) { // Last node
                temp->prev->next = NULL;
                free(temp);
            } else { // Middle node
                struct node *back = temp->prev;
                back->next = temp->next;
                temp->next->prev = back;
                free(temp);
            }
            printf("Node with value %d deleted.\n", n);
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", n);
}

void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter key (insert before this key): ");
                scanf("%d", &key);
                insert(value, key);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
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
