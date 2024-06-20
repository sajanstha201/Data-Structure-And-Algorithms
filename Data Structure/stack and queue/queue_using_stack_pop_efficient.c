#include<stdio.h>
#include<stdlib.h>
#define size 10
int *stack1,top1=-1,*stack2,top2=-1;
void pushStack(int *stack,int value){
    (stack==stack1)?++top1:++top2;
    int top=(stack==stack1)?top1:top2;
    *(stack+top)=value;
}
int popStack(int *stack){
    (stack==stack1)?--top1:--top2;
    int top=(stack==stack1)?top1:top2;
    return *(stack+top+1);
}
void displayStack(int *stack){
    int top=(stack==stack1)?top1:top2;
    int i;
    for(i=top;i>=0;i--){
        printf("%d ",*(stack+i));
    }
    printf("\n");
}
void main(){
    stack1=(int*)malloc(size);
    stack2=(int*)malloc(size);
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        printf("Enter a choice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int value;
                printf("Enter number: ");
                scanf("%d",&value);
                int i;
                for(i=top1;i>=0;i--){
                    pushStack(stack2,popStack(stack1));
                }
                pushStack(stack2,value);
                for(i=top2;i>=0;i--){
                    pushStack(stack1,popStack(stack2));
                }
                top2=-1;
                break;
            }
            case 2:{
                popStack(stack1);
                break;
            }
            case 3:{
                displayStack(stack1);
                break;
            }
            case 4:
                return;
            default:
                printf("Invalid choice\n");

        }
    }
}