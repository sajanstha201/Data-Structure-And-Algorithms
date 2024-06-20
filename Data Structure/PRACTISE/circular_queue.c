#include<stdio.h>
#define max 3
int queue[max];
int front=-1,rear=-1;
void enqueue(int data){
    if(front==rear+1||front==0&&rear==max-1){
        printf("overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear=(++rear)%max;
    queue[rear]=data;
        printf("\n%d\t %d\t\n",front,rear);
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
    front=(++front)%max;
            printf("\n%d\t %d\t\n",front,rear);
}
void display(){
int i;
if(front==-1&&rear==-1){
    printf("no element\n");
    return;
}
for(i=front;i!=rear;i++){
    printf("%d ",queue[i]);
    i=i%max;
}
printf("%d \n",queue[i]);
}
int main(){
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    while(1){
        int choice;
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter element: ");
            int data;
            scanf("%d",&data);
            enqueue(data);
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