#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int coeff;
    int pow;
    struct node *next;
} NODE;
NODE *p1=NULL;
NODE *p2=NULL;
NODE *p3=NULL;
NODE * createNode(int coeff,int pow){
    NODE *node=(NODE*)malloc(sizeof(NODE));
    node->coeff=coeff;
    node->pow=pow;
    node->next=NULL;
    return node;
}
NODE * add(NODE *p1,NODE *p2){
    NODE *p3=createNode(0,0);
    NODE *trav=p3;
    while(1){
        if(p1==NULL){
            trav->next=p2;
            break;
        }
        else if(p2==NULL){
            trav->next=p1;
            break;
        }
        else if(p1==NULL&&p2==NULL)
            break;
        if(p1->pow==p2->pow){
            trav->next=createNode(p1->coeff+p2->coeff,p1->pow);
            trav=trav->next;
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->pow>p2->pow){
            trav->next=createNode(p2->coeff,p2->pow);
            trav=trav->next;
            p2=p2->next;
        }
        else{
            trav->next=createNode(p1->coeff,p1->pow);
            trav=trav->next;
            p1=p1->next;
        }
    }
    p3=p3->next;
    return p3;
}
NODE*  insert(NODE *p,int coeff,int pow){
    NODE *trav=p;
    if(p==NULL){
        p=createNode(coeff,pow);
        printf("%d %d \n",p->coeff,p->pow);
        return p;
    }
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=createNode(coeff,pow);
 
}
void display(NODE *p){
    printf("Polynomial: ");
    while(p!=NULL){
        printf("%dx^%d +",p->coeff,p->pow);
        p=p->next;
    }
    printf("\n");
}
int main(){
        printf("saja\n");
    p1=insert(p1,1,1);
    insert(p1,1,2);
    insert(p1,1,5);
    insert(p1,1,10);
    p2=insert(p2,1,2);
    insert(p2,1,5);
    insert(p2,1,15);
    display(p1);
    display(p2);
    p3=add(p1,p2);
    display(p3);
}