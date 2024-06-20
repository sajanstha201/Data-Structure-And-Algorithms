#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[100];
int front=-1,rear=-1;
void enqueue(int n){
    if(front==0&&rear==max-1||front-1==rear){
        printf("OverFlow\n");
        return;
    }
    if(front==-1&&rear==-1)
        front=0;
    rear=(rear+1)%max;
    queue[rear]=n;
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("underflow\n");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    front=(front+1)%max;
    printf("sajan\n");
}
void display(){
    int i;
    for(i=front;i!=rear;i=(++i)%max){
        printf("%d ",queue[i]);
    }
    printf("%d\n",queue[i]);
}
void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    printf("2:  ");display();
    enqueue(40);
    display();
    dequeue();
    printf("3: ");display();
}