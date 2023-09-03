#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(int d){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n){
        n->data=d;
        n->next=NULL;
    }
    return n;
}
void insertf(struct node** head,int d){
    struct node* n=create(d);
    if(n){
        if(*head==NULL){
            n->next=n;
        }else{
            struct node* current=*head;
            while(current->next!=*head){
                current=current->next;
            }
            current->next=n;
            n->next=*head;
        }
        *head=n;
    }
}
int delete_pos(struct node** head, int position) {
    if (*head == NULL || position <= 0) {
        return -1; // Invalid input
    }

    struct node* current = *head;
    struct node* prev = NULL;
    int count = 1;

    while (count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (prev == NULL) {
        // Removing the first node
        if (current->next == current) {
            // Only one node left, reset the list
            *head = NULL;
        } else {
            *head = current->next;
            prev = current;
            while (prev->next != current) {
                prev = prev->next;
            }
            prev->next = *head;
        }
    } else {
        prev->next = current->next;
    }

    int removedData = current->data;
    free(current);
    printf("%d removed\n",removedData);
}
void display(struct node* head){
    struct node* current= head;
    do{
        printf("%d -> ",current->data);
        current=current->next;
    }
    while(current!=head);
    printf("%d\n",head->data);
}
int main(){
    struct node* head =NULL;
    insertf(&head,1);
    insertf(&head,2);
    insertf(&head,3);
    insertf(&head,4);
    insertf(&head,5);
    display(head);
    delete_pos(&head,4);
    delete_pos(&head,4);
    display(head);
}