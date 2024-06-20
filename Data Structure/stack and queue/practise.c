#include<stdio.h>
#define max 3
int arr[max],front=-1,rear=-1;
void push(){
    rear=rear+1;
    if(rear==max&&front==0||rear==front){
        printf("OVER FLOW\n");
        rear--;
    }
    else{
        if(front==-1)
            front=0;
        int num;
        printf("Enter number: ");
        scanf("%d",&num);
        rear=rear%max;
        arr[rear]=num;
    }
}
void pop(){
    if(rear==-1&&front==-1)
        printf("UNDER FLOW\n");
    else if(rear==front){
        rear=front=-1;
    }
    else
        front=(++front)%max;
}
void display(){
    int i;
    for(i=front;i!=rear;i++){
        i=i%max;
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[i]);
}
void main(){
printf("1.push\n2.pop\n3.display\n4.exit\n");
while(1){
    int choice;
    printf("Enter a choice: ");
    scanf("%d",&choice);
    switch(choice){
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
            printf("invalid choice\n");
    }
}
}