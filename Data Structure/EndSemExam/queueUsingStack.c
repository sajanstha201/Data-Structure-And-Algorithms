#include<stdio.h>
#include<stdlib.h>
int stack1[100];
int top1=-1;
void push1(int n){
    stack1[++top1]=n;
}
int pop1(){
    return stack1[top1--];
}
int stack2[100];
int top2=-1;
void push2(int n){
    stack2[++top2]=n;
}
int pop2(){
    return stack2[top2--];
}
void enqueue(int n){
    while(top1!=-1){
        push2(pop1());
    }
    push1(n);
    while(top2!=-1)
        push1(pop2());
}
void dequeue(){
    pop1();
}
void display(){
    int i;
    for(i=0;i<=top1;i++)
        printf("%d ",stack1[i]);
}
void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    printf("\n");
    display();

}