#include<stdio.h>
#include<stdlib.h>
#define max 100
#define n 4
int queue[max];
int front[n],rear[n];
int boundary[n];
void divideQueue(){
    int i;
    for(i=0;i<n;i++){
        front[i]=(int)max/n*i;
        rear[i]=(int)max/n*i-1;
    }
}
void enqueue(int no,int value){
    if(rear[no]+1==front[no+1]){
        printf("Overflow\n");
        return;
    }
    queue[++rear[no]]=value;
}
void dequeue(int no){
    if(front[no]==rear[no]){
        printf("underflow\n");
        return;
    }
    front[no]++;
}
void display(int no){
    int i;
    printf("%d : ",no);
    for(i=front[no];i<=rear[no];i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void main(){
    divideQueue();
    enqueue(0,1);
    enqueue(0,2);
    enqueue(1,10);
    enqueue(1,20);
    enqueue(2,100);
    enqueue(2,200);
    enqueue(2,300);
    display(0);
    display(1);
    display(2);

}