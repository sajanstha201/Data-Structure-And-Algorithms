#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next;} LINK;
LINK *head,*front,*rear;
int count=0;
LINK* create(){
    LINK *p=(LINK*)malloc(sizeof(LINK));
    if(p==NULL)
        printf("Fail to allocate memory");
    else
        return p;
    return NULL;
}
void deletenode(){
    int node,i;
    printf("Enter the node: ");
    scanf("%d",&node);
    LINK* tran;
    for(i=0;i<count;i++){
        if(i==node-2){
            tran->next=(tran->next)->next;
        }
        tran=tran->next;
    }
}
void deleteBegin(){
    if(count==0)
        printf("underflow");
    else
        front=front->next;
    count--;
}
void deleteEnd(){
    if(count==0)
        printf("underflow");
    else{
        int i;
        LINK *tran=front;
        for(i=0;i<count-2;i++)
            tran=tran->next;
        rear=tran;
    }
    count--;
}
void search(){
    printf("Enter the number to search: ");
    int i,num;
    scanf("%d",&num);
    LINK *tran=front;
    for(i=0;i<count;i++){
        if(tran->data==num)
            printf("The node of entered element is %d \n", i+1);
        tran=tran->next;
    }
}
void insertBegin(){
    LINK *p=(LINK*)malloc(sizeof(LINK));
    int num;
    printf("Enter the value: ");
    scanf("%d",&num);
    p->data=num;
    p->next=front;
    front=p;
    if(count==0){
        front=p;
        rear=p;
        p->next=NULL;
    }
        count++;
}
void insertEnd(){
    LINK *p=(LINK*)malloc(sizeof(LINK));
    int num;
    printf("Enter the value: ");
    scanf("%d",&num);
    if(count==0)
        front=rear=p;
    p->data=num;
    p->next=NULL;
    printf("any");
    rear->next=p;
    printf("any");
    rear=p;
    count++;
}
void show(){
int i;
LINK* tran=front;
if(count==0)
    printf("The list is empty\n");
else{
    for(i=0;i<count;i++){
    printf("%d ",tran->data);
    tran=tran->next;
}
printf("\n");
}

}
void main(){
   // struct node *p=create();
    printf("1.insert from beginning\n2.insert from end\n3.delet from beginning \n4.delete from end\n5.delete node after specified location\n6.searching \n7.show\n8.exit\n");
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
    deleteBegin();
    break;
case 4:
    deleteEnd();
    break;
case 5:
    deletenode();
    break;
case 6:
    search();
    break;
case 7:
    show();
    break;
case 8:
    return;
    }
    }

}


