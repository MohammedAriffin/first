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
    return newnode;
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
void deletee(struct node** head){
    struct node* current = *head;
    if(current->next==NULL){
        free(head);
        *head==NULL;
        return;
    }
    if(current==NULL){return;}
    while(current->next->next!=NULL){
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
}
void delete_v(struct node** head,int pos){
    if(*head==NULL){return;}
    struct node* temp = *head;
    if(pos==0){
        *head = temp->next;
        free(temp);
        printf("Node at position %d deleted.\n", pos);
        return;
    }
    for(int i=0;temp!=NULL && i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        printf("NULL value encountered\n");
        return;
        }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    printf("Node at position %d deleted.\n", pos);
}
int main(){
    struct node*head=NULL;
    int a;
    printf("Enter highest power:");
    scanf("%d",&a);
    for(int i=0;i<=a;i++){
        int p, c;
        printf("enter %d terms(pow,coff):",i);
        scanf("%d %d",&p,&c);
        insertf(&head,p,c);
    }
    
    display(head);
    deletee(&head);
    display(head);
    deletef(&head);
    display(head);
    delete_v(&head,1);
    display(head);
}