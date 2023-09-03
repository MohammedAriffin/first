#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the front
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = *head;
        *head = newNode;
    }
    
}

// Function to insert a node at the middle
void insertMiddle(struct Node* prevNode, int data) {
    if (prevNode == NULL) return;

    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// Function to delete a node at the front
void deleteFront(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the middle
void deleteMiddle(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) return;

    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Function to delete a node at the end
void deleteEnd(struct Node** head) {
    struct Node* current = *head;

    if (current == NULL) {
        return;
    }

    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertFront(&head, 3);
    insertFront(&head, 2);
    insertFront(&head, 1);

    insertMiddle(head->next, 10);

    displayList(head);

    deleteFront(&head);
    deleteMiddle(head);
    deleteEnd(&head);

    displayList(head);

    return 0;
}