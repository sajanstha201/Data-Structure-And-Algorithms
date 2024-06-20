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
    for(i=0;i<strlen(prefix);i++){
        printf("%c",prefix[strlen(prefix)-i-1]);
    }
}
void postfixToInfix(char exp[]){
    top=-1;
    int i;
    for(i=0;i<strlen(exp);i++){
            char* cp=(char*)malloc(sizeof(char));
        *cp=exp[i];
        if('a'<=*cp&&*cp<='z'||'A'<=*cp&&*cp<='Z')
            push(cp);
        else{
            char* o1=pop();
            char* o2=pop();
            char* o=(char*)malloc(sizeof(*o1)+sizeof(*o2)+sizeof(char));
            strcpy(o,"(");
            strcat(o,o2);
            strcat(o,cp);
            strcat(o,o1);
            strcat(o,")");
            push(o);
        }
    }
    printf("\n%s",pop());
}
int main(){
    char exp[]="a+(d+b)*e/f-g";
    char postfix[]="adb+e*f/+";
    infixToPrefix(exp);
    postfixToInfix(postfix);
}