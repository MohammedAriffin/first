#include <stdio.h>
// Function to push (enqueue) an element into the queue
void push(int arr[], int data, int *rear, int size) {
    if (*rear == size - 1) {
        printf("Queue is full. Cannot push %d.\n", data);
        return;
    }
    arr[++(*rear)] = data;
    printf("Entered element is: %d\n",data);
}

// Function to pop (dequeue) an element from the front of the queue
void pop(int arr[], int *front, int *rear) {
    if (*front > *rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Popped element: %d\n", arr[(*front)++]);
    }
}
int main() {
    int size = 5;
    int arr[size];
    int front = 0, rear = -1;

    push(arr, 10, &rear, size);
    push(arr, 20, &rear, size);
    push(arr, 30, &rear, size);
    pop(arr,&front,&rear);
    push(arr,235,&rear,size);
    pop(arr,&front,&rear);
}