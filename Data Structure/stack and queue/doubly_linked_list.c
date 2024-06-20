#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node{
struct node *prev;
int data;
struct node *next} LINK;
LINK *head;
int count=0;
LINK *searchNode(int n){
    int i;
    LINK *trav=head;
    for(i=1;i<n;i++)
        trav=trav->next;
    return trav;
}
void insertBegin(){
    if(count==max)
        printf("OVER FLOW\n");
    else{
        int data;
        printf("Enter a number:");
        scanf("%d",&data);
        LINK *node=(LINK*)malloc(sizeof(LINK));
        node->prev=NULL;
        node->data=data;
        if(count==0){
            head=node;
            node->next=NULL;
        }
        else{
            head->prev=node;
            node->next=head;
            head=node;
        }
        count++;
    }
}
void insertEnd(){
    if(count==max)
        printf("OVER FLOW\n");
    else{
        int data;
        printf("Enter a number:");
        scanf("%d",&data);
        LINK *node=(LINK*)malloc(sizeof(LINK));
        node->data=data;
        node->next=NULL;
        if(count==0){
            node->prev=NULL;
            head=node;
        }
        else{
            LINK* lastnode=searchNode(count);
            lastnode->next=node;
            node->prev=lastnode;
        }
        count++;
    }
}
void insertMid(){
    if(count==max)
        printf("OVER FLOW\n");
    else{
            if(count==0)
                insertBegin();
            else{
                int data,nodeNumber;
                printf("Enter the node Number:");
                scanf("%d",&nodeNumber);
                printf("Enter a number:");
                scanf("%d",&data);
                LINK *node=(LINK*)malloc(sizeof(LINK));
                node->data=data;
                LINK *prevNode=searchNode(nodeNumber);
                LINK *nextNode=prevNode->next;
                prevNode->next=node;
                node->prev=prevNode;
                nextNode->prev=node;
                node->next=nextNode;
            }
            count++;
    }
}
void deleteBegin(){
    if(count==0)
        printf("UNDER FLOW\n");
    else{
        if(count==1)
            head=NULL;
        else{
            head->next->prev=NULL;
            head=head->next;
        }
        count--;
    }
}
void deleteEnd(){
    if(count==0)
        printf("UNDER FLOW\n");
    else{
        if(count==1)
            head=NULL;
        else{
            LINK *lastnode=searchNode(count);
            lastnode->prev->next=NULL;
            free(lastnode);
            }
        count--;
    }
}
void deleteMid(){
    if(count==0)
        printf("UNDERFLOW\n");
    else{
        int nodeNumber;
        printf("Enter the node number: ");
        scanf("%d",&nodeNumber);
        if(nodeNumber==1)
            deleteBegin();
        else if(nodeNumber==count)
            deleteEnd();
        else{
            printf("sajan\n");
            LINK *node=searchNode(nodeNumber);
            node->prev->next=node->next;
            node->next->prev=node->prev;
            free(node);
            count--;
        }
    }
}
void display(){
    LINK *trav=head;
    int i;
    if(count==0)
        printf("EMPTY\n");
    else{
          for(i=0;i<count;i++){
            printf("%d ",trav->data);
            trav=trav->next;
        }
        printf("\n");
    }

}
void main(){
    printf("1.insert begin\n2.insert end\n3.insert mid\n4.delete begin\n5.delete end\n6.delete mid\n7.display\n8.exit\n");
    while(1){
        int choice;
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insertBegin();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertMid();
            break;
        case 4:
            deleteBegin();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteMid();
            break;
        case 7:
            display();
            break;
        case 8:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}