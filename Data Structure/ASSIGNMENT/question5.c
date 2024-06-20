#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
} LIST;
LIST *head=NULL;
void insertBegin(){
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    LIST *node=(LIST*)malloc(sizeof(LIST));
    node->data=value;
    node->next=head;
    node->prev=NULL;
    if(head!=NULL){
        head->prev=node;
    }
    head=node;
}
void insertEnd(){
    int value;
    printf("Enter a number: ");
    scanf("%d",&value);
    LIST *node=(LIST*)malloc(sizeof(LIST));
    node->data=value;
    node->next=NULL;
    LIST *trav=head;
    if(trav!=NULL){
        while(trav->next!=NULL)
            trav=trav->next;
        trav->next=node;
        node->prev=trav;
    }
    else{
        head=node;
        node->prev=NULL;
    }

}
void insertSelected(){
    int nodeNumber,value;
    printf("Enter the Node Number: ");
    scanf("%d",&nodeNumber);
    LIST *trav=head;
    if(trav==NULL||nodeNumber==1){
        insertBegin();
    }
    else{
        printf("Enter a number: ");
        scanf("%d",&value);
        LIST *node=(LIST*)malloc(sizeof(LIST));
        node->data=value;
        int i;
        for(i=1;i<nodeNumber-1;i++)
            trav=trav->next;
        node->next=trav->next;
        node->prev=trav;
        trav->next=node;
        node->next->prev=node;
    }
}
void deleteBegin(){
    if(head==NULL)
        printf("Under flow\n");
    else{
        head=head->next;
        head->prev=NULL;
    }
}
void deleteEnd(){
    if(head==NULL)
        printf("Under flow\n");
    else{
        LIST *trav=head;
        while(trav->next->next!=NULL)
            trav=trav->next;
        trav->next=NULL;
    }
}
void deleteSelected(){
    int nodeNumber;
    printf("Enter the node Number: ");
    scanf("%d",&nodeNumber);
    LIST *trav=head;
    int i;
    for(i=1;i<nodeNumber-1;i++)
        trav=trav->next;
    trav->next=trav->next->next;
    trav->next->prev=trav;
}
void display(LIST *trav){
    if(trav==NULL)
        printf("NO element\n");
    else{
    while(trav!=NULL){
        printf("%d ",trav->data);
        trav=trav->next;
    }
    printf("\n");
    }
}
int isloop(LIST *trav){
    LIST *head1=trav;
    LIST *trav2;
    while(1){
        if(trav==NULL)
            return 0;
        else{
            trav2=head1;
            while(1){
                if(trav2==trav)
                    break;
                if(trav2==trav->next)
                    return 1;
                trav2=trav2->next;
            }
            trav=trav->next;
        }
    }
    return 0;
}
void enterLoop(LIST *trav){
    int nodeNumber;
    printf("Enter the node Number: ");
    scanf("%d",&nodeNumber);
    int i;
    for(i=1;i<nodeNumber;i++)
        trav=trav->next;
    LIST *loop=trav;
    while(trav->next!=NULL)
        trav=trav->next;
    trav->next=loop;
}
int main(){
        printf("1.insert from beginning\n2.insert from end\n3.insert in selected node\n");
        printf("4.delet from beginning \n5.delete from end\n6.delete node after specified location\n");
        printf("7.show\n8.enter a loop to selected node\n9.check loop\n10.exit");
    int choice;
    while(1){
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
    insertSelected();
    break;
case 4:
    deleteBegin();
    break;
case 5:
    deleteEnd();
    break;
case 6:
    deleteSelected();
    break;
case 7:
    display(head);
    break;
case 8:
    enterLoop(head);
    break;
case 9:
    if(isloop(head))
        printf("YES, there is loop\n");
    else
        printf("NO, there is no loop\n");
    break;
case 10:
    return 0;
    }
    }

}