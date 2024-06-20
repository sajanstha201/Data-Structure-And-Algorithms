#include<stdio.h>
#include<stdlib.h>
int queue[100];
int front=0,rear=-1;
void enqueue(int n){
    int i;
        rear++;
    for(i=rear;i>=front;i--){
        if(n<queue[i-1]){
            queue[i]=queue[i-1];
            continue;
        }
        queue[i]=n;
        break;
    }
}
void dequeue(int n){
    int i;
    for(i=rear;i>=front;i--){   
        if(n<queue[i])
            continue;
        queue[i]=queue[i-1];
    }
    front++;
}
void display(){
    int i;
    printf("\nqueue: ");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
}
void main(){
    enqueue(40);
    enqueue(20);
    enqueue(30);
    display();
    dequeue(30);
    display();
}