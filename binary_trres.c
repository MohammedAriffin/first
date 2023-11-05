#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of keys in a node
#define MAX_KEYS 3

// Structure for a B-tree node
struct BTreeNode {
    int keys[MAX_KEYS];
    struct BTreeNode* children[MAX_KEYS + 1];
    int numKeys;
    int isLeaf;
};

// Function to create a new B-tree node
struct BTreeNode* createNode(int isLeaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->numKeys = 0;
    newNode->isLeaf = isLeaf;

    for (int i = 0; i < MAX_KEYS + 1; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Function to search for a key in the B-tree
int searchKey(struct BTreeNode* root, int key) {
    int index = 0;
    while (index < root->numKeys && key > root->keys[index]) {
        index++;
    }
    return index;
}

// Function to split a full child of a node in the B-tree
void splitChild(struct BTreeNode* parent, int index) {
    struct BTreeNode* child = parent->children[index];
    struct BTreeNode* newChild = createNode(child->isLeaf);
    parent->numKeys++;

    // Move the middle key of the full child to the parent
    for (int i = parent->numKeys - 1; i > index; i--) {
        parent->keys[i] = parent->keys[i - 1];
        parent->children[i + 1] = parent->children[i];
    }
    parent->keys[index] = child->keys[MAX_KEYS / 2];

    // Move the second half of the full child's keys to the new child
    newChild->numKeys = MAX_KEYS / 2;
    for (int i = 0; i < newChild->numKeys; i++) {
        newChild->keys[i] = child->keys[MAX_KEYS / 2 + i];
    }

    // Move the second half of the full child's children to the new child
    if (!child->isLeaf) {
        for (int i = 0; i < MAX_KEYS / 2 + 1; i++) {
            newChild->children[i] = child->children[MAX_KEYS / 2 + 1 + i];
            child->children[MAX_KEYS / 2 + 1 + i] = NULL;
        }
    }

    // Update the parent's children
    parent->children[index + 1] = newChild;

    // Update the full child's number of keys
    child->numKeys = MAX_KEYS / 2;
}

// Function to insert a key into the B-tree
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root == NULL) {
        // If the tree is empty, create a new root
        root = createNode(1);
        root->keys[0] = key;
        root->numKeys = 1;
        return root;
    }

    if (root->numKeys == MAX_KEYS) {
        // If the current node is full, split it
        struct BTreeNode* newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        root = newRoot;
    }

    // Find the child to insert the key
    int index = searchKey(root, key);

    // Recursive call to insert in the appropriate child
    root->children[index] = insert(root->children[index], key);

    return root;
}

// Function to display the B-tree
void displayBTree(struct BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numKeys; i++) {
            displayBTree(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        displayBTree(root->children[root->numKeys]);
    }
}

// Function to free the memory allocated for the B-tree
void freeBTree(struct BTreeNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numKeys + 1; i++) {
            freeBTree(root->children[i]);
        }
        free(root);
    }
}

int main() {
    struct BTreeNode* root = NULL;

    // Insert keys into the B-tree
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 5);

    // Display the B-tree
    printf("B-tree: ");
    displayBTree(root);
    printf("\n");

    // Free the memory allocated for the B-tree
    freeBTree(root);

    return 0;
}
