//this code is perfect to convert postfix to infix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char *stack[max];
int top=-1;
void push(char *exp){
        top++;
    char *ch=(char*)malloc(strlen(exp));
    int i;
    for(i=0;i<strlen(exp);i++)
        *(ch+i)=*(exp+i);
    stack[top]=ch;
}
char* pop(){
    top--;
    char *ch=(char*)malloc(sizeof(stack[top+1]));
    int i;
    for(i=0;i<strlen(stack[top+1]);i++)
        *(ch+i)=*(stack[top+1]+i);
    return ch;
}
void display(){
    int i;
    for(i=0;i<=top;i++){
        printf("%s ",stack[i]);
    }
    printf("\n");
}
int main(){

char input[100];
printf("Enter postfix expression: ");
scanf("%s",input);
int length=strlen(input);
char *exp=input;
int i=0;
for(i=0;i<length;i++){
    if(*(exp+i)=='*'||*(exp+i)=='/'||*(exp+i)=='+'||*(exp+i)=='-'){
        char *op1=pop();
        char *op2=pop();
        char re[strlen(op1)+strlen(op2)+3];re[0]='(';re[1]='\0';
        strcat(re,op2);
        char opr[2];opr[0]=*(exp+i);opr[1]='\0';
        strcat(re,opr);
        strcat(re,op1);
        strcat(re,")");
        push(re);
    }
    else{
        char* operand=(char*)malloc(1);
        *operand=*(exp+i);
        push(operand);
    }
}
char *result=pop();
printf("The infix expression is :%s\n",result);
}