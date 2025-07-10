#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int info;
};

// Global variables
struct node *root = NULL;
int leafCount = 0;
int parentCount = 0;

// Function to create a new node
struct node *getnode(int value) {
    struct node *p = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the entire node
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
    } else if (n < root->info) { // Should be less than for left child
        root->left = insert(root->left, n);
    } else if (n > root->info) { // Should be greater than for right child
        root->right = insert(root->right, n);
    }
    return root;
}

// Function for preorder traversal
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}


// Function to count parent nodes
void countParent(struct node *root) {
    if (root == NULL) {
        return; // Base case
    }
    if (root->left != NULL || root->right != NULL) {
        parentCount++;
    }
    countParent(root->left);
    countParent(root->right);
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Count Leaf Nodes\n");
        printf("4. Count Parent Nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                leafCount = 0; // Reset count before counting
                countLeaf(root);
                printf("Leaf nodes: %d\n", leafCount);
                break;

            case 4:
                parentCount = 0; // Reset count before counting
                countParent(root);
                printf("Parent nodes: %d\n", parentCount);
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
