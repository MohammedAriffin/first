#include <stdio.h>
#include <stdlib.h>
struct node{
    int p;
    int c;
    struct node* next;
};
struct node* create(int a , int b){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    if(newnode){
        newnode->p=a;
        newnode->c=b;
        newnode->next=NULL;
    }
}
void insertf(struct node** head,int a,int b){
    struct node* newnode = create(a,b);
    if(newnode){
        newnode->next= *head;
        *head=newnode;
    }
}
void display(struct node* head){
    while(head!=NULL){
        printf("%d power , %d coeff -> ",head->p,head->c);
        head=head->next;
    }
    printf("NULL\n");
}
void deletef(struct node** head) {
    if (*head != NULL) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main(){
    struct node*head=NULL;
    insertf(&head,2,3);
    insertf(&head,1,4);
    insertf(&head,0,5);
    display(head);
    deletef(&head);
    display(head);
}