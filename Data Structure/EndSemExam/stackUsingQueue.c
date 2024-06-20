#include<stdio.h>
#include<stdlib.h>
int queue1[100];
int front1=0,rear1=-1;
void enqueue1(int n){
    if(front1-1==rear1){
        front1=0;
        rear1=0;
        queue1[rear1]=n;
    }
    else
        queue1[++rear1]=n;
}
int dequeue1(){
    return queue1[front1++];
}
int queue2[100];
int front2=0,rear2=-1;
void enqueue2(int n){
    if(front2-1==rear2){
        front2=0;
        rear2=0;
        queue2[rear2]=n;
    }
    else
        queue2[++rear2]=n;
}
int dequeue2(){
    return queue2[front2++];
}
void push(int n){
    while(front1<=rear1)
        enqueue2(dequeue1());
    enqueue1(n);
    while(front2<=rear2)
        enqueue1(dequeue2());
}
void pop(){
    dequeue1();
}
void display(){
    int i;
    printf("front rear: %d %d \n",front1,rear1);
    for(i=front1;i<=rear1;++i)
        printf("%d ",queue1[i]);
    printf("\n");
}
void main(){
    push(1);
    push(2);
    display();
    push(3);
    push(4);
    display();
    printf("\n");
    pop();
    push(10);
    display();
}