#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};

// Function to insert a node at the beginning of the list
void insert(struct node **start, int info) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation error\n");
        return;
    }
    newnode->info = info;
    newnode->next = *start;
    *start = newnode;
}

// Function to create a linked list
struct node *getlist() {
    struct node *start = NULL;
    int n, info;

    printf("Enter the number of nodes for the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &info);
        insert(&start, info);
    }
    return start;
}

// Function to concatenate two linked lists
struct node *concate(struct node *list1, struct node *list2) {
    if (!list1) return list2; // If list1 is empty, return list2
    struct node *current = list1;

    while (current->next) {
        current = current->next;
    }
    current->next = list2;
    return list1;
}

// Function to display a linked list
void display(struct node *start) {
    struct node *temp = start;
    while (temp) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to sort a linked list
struct node *sort(struct node *start) {
    struct node *current, *nextN;
    int temp;
    if (start == NULL) {
        return NULL;
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
    return start;
}

// Function to free a linked list
void freeList(struct node *start) {
    struct node *temp;
    while (start) {
        temp = start;
        start = start->next;
        free(temp);
    }
}

int main() {
    struct node *list1 = NULL, *list2 = NULL, *mergedList = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create and merge lists\n");
        printf("2. Display merged list\n");
        printf("3. Sort merged list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter details for List 1:\n");
                list1 = getlist();

                printf("Enter details for List 2:\n");
                list2 = getlist();

                mergedList = concate(list1, list2);
                printf("Lists merged successfully.\n");
                break;

            case 2:
                if (mergedList) {
                    printf("Merged List: ");
                    display(mergedList);
                } else {
                    printf("No merged list to display. Please create lists first.\n");
                }
                break;

            case 3:
                if (mergedList) {
                    mergedList = sort(mergedList);
                    printf("Merged List sorted successfully.\n");
                } else {
                    printf("No merged list to sort. Please create lists first.\n");
                }
                break;

            case 4:
                freeList(mergedList);
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
