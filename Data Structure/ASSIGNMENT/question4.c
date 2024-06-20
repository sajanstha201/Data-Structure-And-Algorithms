#include<stdio.h>
#include<stdlib.h>

typedef struct node{
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
    }
    else{
        head=node;
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
        trav->next=node;
    }
}
void deleteBegin(){
    if(head==NULL)
        printf("Under flow\n");
    else
        head=head->next;
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
void FrontBackSplit(LIST *trav){
    LIST *head1=trav;
    LIST *head2=NULL;
    int count=0;
    while(trav!=NULL){
        trav=trav->next;
        count++;
    }
    int i;
    trav=head1;
    count=(int)count/2+count%2;
    for(i=1;i<=count-1;i++){
        trav=trav->next;
    }
    head2=trav->next;
    trav->next=NULL;
    printf("For Front:\n");
    display(head1);
    printf("For Back:\n");
    display(head2);
}
int main(){
        printf("1.insert from beginning\n2.insert from end\n3.insert in selected node\n");
        printf("4.delet from beginning \n5.delete from end\n6.delete node after specified location\n");
        printf("7.show\n8.Splitting\n9.exit\n");
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
    FrontBackSplit(head);
    break;
case 9:
    return 0;
    }
    }

}