#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
} LIST;
LIST *head;
int count=0,max_size=10;


LIST* searchNode(int num){
    int i;
    LIST* trav=head;
    if(num>count||num<=0)
        return NULL;
    else{
        for(i=0;i<num-1;i++)
            trav=trav->next;
        return trav;
    }
}
void searchNodeValue(){
    int num;
    printf("Enter the node number: ");
    scanf("%d",&num);
    int i;
    LIST *trav=head;
    for(i=0;i<num-1;i++){
        trav=trav->next;
    }
    printf("The value of %d node is %d\n",num,trav->data);
}
LIST* createNode(){
    LIST* p=(LIST*)malloc(sizeof(LIST));
    if(p==NULL)
        printf("Memory cannot be allocated\n");
    else
        return p;
    return NULL;
}
void insertBegin(){
    LIST *node=createNode();
    int num;
    if(count==max_size-1)
        printf("OVER FLOW");
    else{
        printf("Enter a number: ");
        scanf("%d",&num);
        node->data=num;
        if(count==0)
            node->next=NULL;
        else
            node->next=head;
        head=node;
        count++;
    }

}
void insertEnd(){
    LIST *node=createNode();
    int n=5;
    if(count==max_size-1)
        printf("OVERFLOW\n");
    else{
        printf("Enter a number :");
       scanf("%d",&n);
        node->data=n;
        node->next=NULL;
        if(count==0)
            head=node;
        else{
            LIST *lastNode=searchNode(count);
            lastNode->next=node;
        }
        count++;
    }

}
void insertMid(){
    LIST *node=createNode();
    if(count==max_size-1)
        printf("OVERFLOW\n");
    else{
        int nodenum,num;
        printf("Enter the node: ");
        scanf("%d",&nodenum);
        printf("Enter a number:");
        scanf("%d",&num);
        LIST *node=createNode();
        LIST *midnode=searchNode(nodenum);
        if(midnode==NULL||node==NULL)
            printf("The entered node is not available\n");
        else{
            node->data=num;
            node->next=midnode->next;
            midnode->next=node;
        }
        count++;
    }

}
void deleteBegin(){
    if(count==0)
        printf("UNDER FLOW\n");
    else{
        LIST *p=head->next;
        free(head);
        head=p;
        count--;
    }

}
void deleteEnd(){
    if(count==0)
        printf("UNDER FLOW\n");
    else{
        LIST *lastnode=searchNode(count);
        free(lastnode);
        LIST *secondlastnode=searchNode(count-1);
        secondlastnode->next=NULL;
        count--;
    }

}
void deleteMid(){
    LIST *postmid;
    if(count==0)
        printf("UNDER FLOW\n");
    else{
        int midnode;
        printf("Enter the node:");
        scanf("%d",&midnode);
        if(count==1)
            head=NULL;
        else{
            postmid=searchNode(midnode-1);
            if(postmid==NULL)
                printf("The entered node not found\n");
            else{
                postmid->next=postmid->next->next;
            }
        }
        count--;
    }

}

void display(){
    int i;
    LIST *trav=head;
    for(i=0;i<count;i++){
        printf("%d ",trav->data);
        trav=trav->next;
    }
    printf("\n");
}

int main(){
    printf("1.insert from beginning\n2.insert from end\n3.insert between node\n4.delet from beginning\n5.delete from end\n6.delete node after specified location\n7.searching \n8.show\n9.exit\n");
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
            searchNodeValue();
            break;
        case 8:
            display();
            break;
        case 9:
            return 0;
            }
    }
}
