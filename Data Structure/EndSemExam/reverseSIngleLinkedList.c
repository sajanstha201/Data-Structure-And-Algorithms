#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE;
NODE *head;
NODE * createNode(int v){
    NODE * node=(NODE*)malloc(sizeof(NODE));
    node->data=v;
    node->next=NULL;
    return node;
}
void insert(int value){
    if(head==NULL){
        head=createNode(value);
        return;
    }
    NODE *trav=head;
    while(trav->next!=NULL)
        trav=trav->next;
    NODE *node=createNode(value);
    trav->next=node;
}
void delete(){
    if(head==NULL){
        printf("overflow\n");
        return;
    }
    NODE *trav=head;
    while(trav->next->next!=NULL)
        trav=trav->next;
    trav->next=NULL;

}
NODE *reverse(NODE *head){
    NODE *trav=NULL;
    NODE *nexthead=head->next;
    while(1){
        head->next=trav;
        if(nexthead==NULL)
            break;
        trav=head;
        head=nexthead;
        nexthead=nexthead->next;
    }
    return head;
}
void display(NODE *head){
    printf("List: ");
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
NODE* reverse1(NODE *head){
    NODE *nexthead=head->next;
    NODE *prevhead=NULL;
    while(1){
        head->next=prevhead;    
        if(nexthead==NULL)
            break;
         prevhead=head;
        head=nexthead;
        nexthead=nexthead->next;
    }
    return head;
}
void main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display(head);
    head=reverse1(head);
    display(head);
}
