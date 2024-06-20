#include<stdio.h>
#include<stdlib.h>
#define max 3
int front=-1,rear=-1;
int queue[max];
void enqueue(){
    if(rear+1==front||front==0&&rear==max-1)
        printf("overflow\n");
    else{
        if(front==-1)
            front=0;
        rear=(rear+1)%max;
        printf("Enter a number: ");
        int value;
        scanf("%d",&value);
        queue[rear]=value;
    }
}
void dequeue(){
    if(front==-1&&rear==-1)
        printf("under flow\n");
    if(front==rear)
        front=rear=-1;
    else{
        front=(front+1)%max;
    }
}
void display(){
    if(front==0&&rear==-1||front==-1&&rear==-1)
        printf("No Element\n");
    else{
        int i=0;
        for(i=front;i!=rear;i=i%max){
            printf("%d ",queue[i]);
            i++;
        }
        printf("%d\n",queue[i]);
}
}
int main(){
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        int choice;
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
