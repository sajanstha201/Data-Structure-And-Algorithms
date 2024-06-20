#include<stdio.h>
#define size 3
int queue[size],front=-1,rear=-1;
void insertBegin(){

    if((front==0&&rear==size-1)||(front==rear+1))
        printf("OVER FLOW\n");
    else{
        if(front==-1)
            front=0;
        int value;
        printf("Enter number: ");
        scanf("%d",&value);
        if(front==0)
            front=size-1;
        else
            front--;
        queue[front]=value;
    }
}
void insertEnd(){
    if((front==0&&rear==size-1)||(front==rear+1))
        printf("OVER FLOW\n");
    else{
        if(front==-1)
            front=0;
        int value;
        printf("Enter number: ");
        scanf("%d",&value);
        if(rear==size-1)
            rear=0;
        else
            rear++;
        queue[rear]=value;
    }
}
void deleteBegin(){
    if(front==-1&&rear==-1)
        printf("UNDER FLOW\n");
    else{   
        if(rear==front)
            rear=front=-1;
        if(front==size-1)
            front=0;
        else
            front++;
    }
}
void deleteEnd(){
    if(front==-1&&rear==-1)
        printf("UNDER FLOW\n");
    else{   
        if(rear==front)
            rear=front=-1;
        if(rear==0)
            rear=size-1;
        else    
            rear--;
    }
}
void display(){
    int i;
    for(i=front;i!=rear;i++){
        i=i%size;
        if(i==rear)
            break;
        printf("%d ",queue[i]);
    }
    printf("%d\n",queue[i]);
}
int main(){
    printf("1.inset begin\n2.insert end\n3.delete begin\n4.delete end\n5.display\n6.exit\n");
    int choice;
    while(1){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                insertBegin();
                break;
            }
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
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
   
}