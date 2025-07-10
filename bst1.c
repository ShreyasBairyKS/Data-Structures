#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int info;
};

// Global variable to keep track of the count of leaf nodes
int count = 0;
struct node *root = NULL;

// Function to create a new node
struct node *getnode(int value) {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the entire node
    if (p == NULL) {
        printf("No memory allocated\n");
        return NULL; // Return NULL to indicate failure
    }
    p->info = value;   // Assign value to the info field
    p->left = NULL;    // Initialize left pointer
    p->right = NULL;   // Initialize right pointer
    return p;          // Return the created node
}

// Function to insert a new value into the binary search tree
struct node *insert(struct node *root, int n) {
    if (root == NULL) {
        root = getnode(n);
    } else if (n < root->info) {  // Note: should be less than for left child
        root->left = insert(root->left, n);
    } else {                       // Note: assuming no duplicates for simplicity
        root->right = insert(root->right, n);
    }
    return root;
}

// Function to perform inorder traversal
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

// Function to count leaf nodes
void countleaf(struct node *root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            count++;
        }
        countleaf(root->left);
        countleaf(root->right);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Count Leaf Nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                count = 0; // Reset count before counting
                countleaf(root);
                printf("Number of leaf nodes: %d\n", count);
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
