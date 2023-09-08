#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* create(int d){
    struct node* n= (struct node*)malloc(sizeof(struct node));
    if(n){
        n->data=d;
        n->next=NULL;
    }
    return n;
}
void push(struct node** head, int d){
    struct node* n = create(d);
    if(*head==NULL){
        *head=n;
    }
    else{
        struct node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;

        }
        temp->next=n;
    }
}
void pop(struct node** head){
    struct node* temp = *head;
    if(temp == NULL){return;}
    *head=temp->next;
    free(temp);
}
void display(struct node* head){
    struct node* current = head;
    if(current==NULL){return;}
    while(current!=NULL){
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n\n");
}
int main(){
    struct node* head = NULL;
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,70);
    push(&head,10);
    display(head);
    pop(&head);
    pop(&head);
    display(head);
}