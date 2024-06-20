#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stack[100];
int front=-1,rear=-1,count=0;
void push(int n){
    rear++;
    if(count==0)
        front=0;
    stack[rear]=n;
}
int pop(){
    rear--;
    return stack[rear+1];
}
int pow(int a,int b){
    int i=0,p=1;
    for(i=0;i<b;i++){
        p=p*a;
    }
    return p;
}
int operation(int a,int b,char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '$':
            return pow(a,b);
        case '%':
            return a%b;
    }
}
void main(){
    char exp[100],i;
    printf("Enter expression: ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='$'){
            int a=pop();
            int b=pop();
            push(operation(b,a,exp[i]));
        }
        else
            push(exp[i]-'0');
    }
    int result=pop();
    printf("The answer is: %d\n",result);
}