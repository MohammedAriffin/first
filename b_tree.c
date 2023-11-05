#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to display the binary tree in inorder traversal
void displayInorder(struct Node* root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

// Function to free the memory allocated for the binary tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;

    // Insert values into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Display the binary tree in inorder traversal
    printf("Inorder Traversal: ");
    displayInorder(root);
    printf("\n");

    // Free the memory allocated for the binary tree
    freeTree(root);

    return 0;
}
