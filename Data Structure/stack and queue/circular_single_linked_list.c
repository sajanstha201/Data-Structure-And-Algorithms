#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node* next;
} LIST;
LIST *head=NULL;
int count=0;
LIST* searchNode(int num){
    int i;
    LIST *trav=head;
    for(i=1;i<num;i++)
        trav=trav->next;
    return trav;
}
void insert(){
    LIST *node=(LIST*)malloc(sizeof(LIST));
    printf("Enter number: ");
    int num;
    scanf("%d",&num);
    node->data=num;
    if(count==0){
        head=node;
        node->next=head;
    }
    else{
        LIST *lastnode=searchNode(count);
        lastnode->next=node;
        node->next=head;
        head=node;
    }
}
void delete(){
    LIST *lastnode=searchNode(count-1);
    lastnode->next=head;
    count--;
}
void display(){
    int i;
    LIST *trav=head;
    for(i=0;i<count;i++){
        printf("%d ",trav->data);
        trav=trav->next;
    }
}
void main(){
    int choice;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
    printf(" Enter a choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        return;
    default:
        printf("invalid choice");
        break;
    }
    }

}