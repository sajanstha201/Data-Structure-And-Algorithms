#include<stdio.h>
#define size 3
int arr[size],front=-1,rear=-1;
void main(){
    int choice;
    int i;
    int x=1;
    int y=0;
    for(i=x;i!=y;i++,i=i%3){
        printf("%d ",i);
    }
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
        printf("%d %d ",front,rear);
    printf("Enter a choice: ");
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
push(){
    int num;
        rear++;
    if(front==-1)
        front=0;
    if(front==0&&rear==size||front==rear){
        printf("Overflow\n");
        rear--;
    }
    else{
    printf("Enter a number: ");
    scanf("%d",&num);
    rear=rear%size;
    arr[rear]=num;
    }
    }
pop(){
    if(front==rear){
        front=0;
        rear=-1;
    }
    else if(front==0&&rear==-1)
        printf("underflow\n");
    else
        front++;
    front=front%size;
}
display(){
    int i;
    if(front==0&&rear==-1)
        printf("There is no element\n");
    else{
    for(i=front;i!=rear;i++,i=i%size){
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[i]);
    }
}
