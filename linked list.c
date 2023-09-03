#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

int main()
{
    struct node* n1 = NULL; // Initialize pointers to NULL
    struct node* n2 = NULL;

    // Allocate memory for the nodes
    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));

    if (n1 == NULL || n2 == NULL) // Check if memory allocation was successful
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    n1->data = 50;
    n2->data = 30;

    n1->link = n2; // Link the nodes

    // Print the data in the linked nodes
    printf("%d\n", n1->data);
    printf("%d\n", n1->link->data);
    struct node* current = n1; // Start from the first node

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->link; // Move to the next node
    }
    printf("NULL\n");
    // Free the allocated memory
    free(n1);
    free(n2);

    return 0;
}