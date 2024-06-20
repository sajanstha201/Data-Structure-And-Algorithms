#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coeff,exp;
    struct node *next;
} LIST;
LIST *head1=NULL,*head2=NULL,*head3=NULL;
int count1=0,count2=0;
LIST* searchNode(LIST* head){
    while(head->next!=NULL){
        head=head->next;
    }
    return head;
}
void push(LIST *head,int coeff,int exp){
    LIST *node=(LIST*)malloc(sizeof(LIST));
    node->coeff=coeff;
    node->exp=exp;
    node->next=NULL;
    if(head==NULL){
        if(head==head1)head1=node;
        else if(head==head2)head2=node;
        else head3=node;
    }
    else{
        LIST* lastnode=searchNode(head);
        lastnode->next=node;
    }
}
void display(LIST *trav){
    if(trav==NULL)
        printf("0");
    while(trav->next!=NULL){
        printf("%dx^%d + ",trav->coeff,trav->exp);
        trav=trav->next;
    }
    printf("%dx^%d\n",trav->coeff,trav->exp);
}
void add(){
    LIST *trav1=head1,*trav2=head2;
    while(1){
        if(trav1==NULL||trav2==NULL)
            break;
        if(trav1->exp==trav2->exp){
            push(head3,trav1->coeff+trav2->coeff,trav1->exp);
            trav1=trav1->next;
            trav2=trav2->next;
        }
        else if(trav1->exp>trav2->exp){
            push(head3,trav1->coeff,trav1->exp);
            trav1=trav1->next;
        }
        else if(trav1->exp<trav2->exp){
            push(head3,trav2->coeff,trav2->exp);
            trav2=trav2->next;
        }
    }
    if(trav1==NULL)
        while(trav2!=NULL){
            push(head3,trav2->coeff,trav2->exp);
            trav2=trav2->next;
        }
    if(trav2==NULL)
        while(trav1!=NULL){
            push(head3,trav1->coeff,trav1->exp);
            trav1=trav1->next;
        }
    display(head3);
}

int  main(){
    printf("1. First Polynomial\n2. Second Polynomial\n3.Add\n4.eixt\n");
    int choice,coeff,exp;
    while (1)
    {
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter a coefficient: ");
                scanf("%d",&coeff);
                printf("Enter a exponient: ");
                scanf("%d",&exp);
                push(head1,coeff,exp);
                break;
            case 2:
                printf("Enter a coefficient: ");
                scanf("%d",&coeff);
                printf("Enter a exponient: ");
                scanf("%d",&exp);
                push(head2,coeff,exp);
                break;
            case 3:
                display(head1);
                display(head2);
                add();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice\n");
        }
    }
    
}