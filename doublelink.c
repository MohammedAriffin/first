#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = *head;
        if (*head) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    }
}

void insertBack(struct Node** head, int data) {
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
            newNode->prev = current;
        }
    }
}

void deleteByPos(struct Node** head, int pos) {
    if (*head == NULL) {
        return; // List is empty
    }
    
    struct Node* current = *head;
    int count = 0;
    
    while (current != NULL && count != pos) {
        current = current->next;
        count++;
    }
    
    if (current == NULL) {
        return; // Position is out of range
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
}

void display(struct Node* head) {
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
    
    display(head); // Output: 1 2 3
    
    insertBack(&head, 4);
    insertBack(&head, 5);
    
    display(head); // Output: 1 2 3 4 5
    
    deleteByPos(&head, 2); // Deletes the node at position 2 (0-based index)
    
    display(head); // Output: 1 2 4 5
    
    return 0;
}