#include<stdio.h>
#define size 3
int arr[size],front=-1,rear=-1;
void push(){
    int num;
    rear++;
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
    if(front==-1)
        front=0;
    }
void pop(){
    if(front==-1&&rear==-1)
        printf("underflow\n");
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else
        front++;
    front=front%size;
}
void display(){
    int i;
    if(front==-1&&rear==-1)
        printf("There is no element\n");
    else{
    for(i=front;i!=rear;i++,i=i%size){
        printf("%d ",arr[i]);
    }

    printf("%d\n",arr[i]);
    }
}
int main(){
    int choice;
    int i;
    int x=1;
    int y=0;
    printf("1.push\n2.pop\n3.display\n4.exit\n");
    while(1){
    printf("%d %d Enter a choice: ",front,rear);
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
        return 0;
    default:
        printf("invalid choice");
        break;
    }
    }

}
