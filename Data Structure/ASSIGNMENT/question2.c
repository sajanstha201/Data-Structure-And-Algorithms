#include<stdio.h>
#include<stdlib.h>
char postfix[100],stack[100];
char infix[100];
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
    else if(c=='/'||c=='*'||c=='%')
        return 8;
    else if(c=='+'||c=='-')
        return 7;
}
int main(){
    int i=0,j,k=0;
    printf("Enter the arithmetic expression: ");
    scanf("%s",infix);
    while(infix[i]!='\0'){
        //printf("%s\n",stack);
        if('a'<=infix[i]&&infix[i]<='z'||'A'<=infix[i]&&infix[i]<='Z'||'0'<=infix[i]&&infix[i]<='9'){
            //printf("%c\n",exp[i]);
            postfix[k]=infix[i];
            k++;
        }
        else{
            if(rear==-1)
                push(infix[i]);
            else{
                if(infix[i]==')'){
                    for(j=rear;stack[j]!='(';--j){
                        postfix[k]=pop();
                        k++;
                    }
                    pop();
                }
                else{
                    for(j=rear;j>=0;--j){
                        if(prd(stack[j])<prd(infix[i])||prd(stack[j])==10)
                            break;
                        postfix[k]=pop();
                        k++;
                    }
                    push(infix[i]);
                }
            }
        }
        i++;
    }
    for(i=rear;i>=0;--i){
        postfix[k]=pop();
        k++;
    }
    printf("%s\n",postfix);
}