#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *stack[100];
int top=-1;
void push(char *c){
    stack[++top]=c;
}
char* pop(){
    return stack[top--];
}
int precedence(char c){
    if(c=='/')
        return 10;
    if(c=='*')
        return 10;
    if(c=='+')
        return 9;
    if(c=='-')
        return 9;
    return 0;
}

void infixToPrefix(char exp[]){
    top=-1;
    int i,k=0;
    char prefix[strlen(exp)];
    for(i=strlen(exp)-1;i>=0;i--){
 
        char *cp=(char*)malloc(sizeof(char));
        *cp=exp[i];
        if('a'<=*cp&&*cp<='z'||'A'<=*cp&&*cp<='Z'){
            prefix[k++]=*cp;
        }
        else{
                if(*cp==')'){
                    push(cp);
                }
                else if(*cp=='('){
                    while(top!=-1&&*stack[top]!=')'){
                        prefix[k++]=*pop();
                    }
                    pop();
                }
                else{
                    while(top!=-1&&precedence(*cp)<precedence(*stack[top])){
                    prefix[k++]=*pop();
                    }
                    push(cp);
                }
        }
    }

    while(top!=-1){
        prefix[k++]=*pop();
    }
    printf("The prefix expression is :");
    for(i=0;i<strlen(prefix);i++){
        printf("%c",prefix[strlen(prefix)-i-1]);
    }
}
int main(){
    int i,k=0,j;
    char exp[100];
    printf("INFIX TO PREFIX\n");
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    infixToPrefix(exp);
}