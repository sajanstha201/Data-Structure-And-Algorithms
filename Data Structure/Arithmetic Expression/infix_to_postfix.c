#include<stdio.h>
#include<stdlib.h>
char exp[100],post[100],stack[100];
int front=0,rear=-1;
void push(char c){
    rear++;
    stack[rear]=c;
}
char pop(){
    rear--;
    return stack[rear+1];
}
int prd(char c){
    if(c=='('||c==')')
        return 10;
    else if(c=='$')
        return 9;
    else if(c=='/'||c=='*')
        return 8;
    else if(c=='+'||c=='-')
        return 7;
}
void main(){
    int i=0,j,k=0;
    printf("Enter the arithmetic expression: ");
    scanf("%s",exp);
    while(exp[i]!='\0'){
        //printf("%s\n",stack);
        if('a'<=exp[i]&&exp[i]<='z'||'A'<=exp[i]&&exp[i]<='Z'||'0'<=exp[i]&&exp[i]<='9'){
            //printf("%c\n",exp[i]);
            post[k]=exp[i];
            k++;
        }
        else{
            if(rear==-1)
                push(exp[i]);
            else{
                if(exp[i]==')'){
                    for(j=rear;stack[j]!='(';--j){
                        post[k]=pop();
                        k++;
                    }
                    pop();
                }
                else{
                    for(j=rear;j>=0;--j){
                        if(prd(stack[j])<prd(exp[i])||prd(stack[j])==10)
                            break;
                        post[k]=pop();
                        k++;
                    }
                    push(exp[i]);
                }
            }
        }
        i++;
    }
    for(i=rear;i>=0;--i){
        post[k]=pop();
        k++;
    }
    printf("%s",post);
}