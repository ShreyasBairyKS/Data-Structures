#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    struct node *right;
    int info;
};

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
    } else if (n > root->info) {   // Note: should be greater than for right child
        root->right = insert(root->right, n);
    }
    return root;
}

// Function to perform postorder traversal
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info); // Added space for readability
    }
}

// Function to find the minimum value node in a tree
struct node *findmin(struct node *root) {
    while (root && root->left != NULL) { // Added root check for safety
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct node *delete(struct node *root, int data) {
    if (root == NULL) return root; // Base case: If the tree is empty
    else if (data < root->info) root->left = delete(root->left, data); // Traverse left
    else if (data > root->info) root->right = delete(root->right, data); // Traverse right
    else { // Node with the value found
        // Case 1: Node with no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: Node with only right child
        else if (root->left == NULL) {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        // Case 3: Node with only left child
        else if (root->right == NULL) {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 4: Node with two children
        else {
            struct node *temp = findmin(root->right); // Find the inorder successor
            root->info = temp->info; // Copy the inorder successor's value to this node
            root->right = delete(root->right, temp->info); // Delete the inorder successor
        }
    }
    return root; // Return the (possibly updated) root pointer
}

// Main function to test the binary search tree operations
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Postorder Traversal\n");
        printf("3. Delete a node\n");
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
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
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
