#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node{
int data;
struct node *next;} LINK;
int count;
LINK *head=NULL;
LINK *searchNode(int n){
    int i;
    LINK *trav=head;
    for(i=1;i<n;i++)
        trav=trav->next;
    return trav;
}
void push(int num){
    if(count==max-1)
        printf("OVERFLOW\n");
    else{
            LINK *node=(LINK*)malloc(sizeof(LINK));
            node->data=num;
            node->next=NULL;
            if(count==0){
                head=node;
            }
            else{
                LINK *lastnode=searchNode(count);
                lastnode->next=node;
            }
                count++;
    }

}
void pop(){
    if(count==0)
        printf("UNDERFLOW\n");
    else{
        LINK *secondlastnode=searchNode(count-1);
        free(secondlastnode->next);
        secondlastnode->next=NULL;
count--;
    }

}
void display(){
    int i;
    LINK *trav=head;
    for(i=1;i<=count;i++){
        printf("%d ",trav->data);
        trav=trav->next;
    }
    printf("\n");
}
int main(){
    int choice;
printf("1.push\n2.pop\n3.display\n4.exit\n");
while(1){
    printf("Enter a choice: ");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter a number: ");
    int num;
    scanf("%d",&num);
    push(num);
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
    printf("Invalid choice\n");
    }
}
}