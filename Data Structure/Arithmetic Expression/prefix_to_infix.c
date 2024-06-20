//there is some error in this code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char* p);
typedef struct node{
    char *data;
    struct node *next;
} LIST;
LIST *head=NULL;
int count=0;
LIST* searchNode(int n){
    LIST *trav=head;
    int i;
    if(count==0)
        return head;
    for(i=1;i<n;i++){
        trav=trav->next;
    }
    return trav;
}
void push(char* p){
    printf("sajan");
    LIST *node=(LIST*)malloc(sizeof(LIST));
    node->data=p;
    node->next=NULL;
    LIST* lastnode=searchNode(count);
    lastnode->next=node;
    count++;
}
char* pop(){
    LIST *lastnode=searchNode(count-1);
    char* num=lastnode->next->data;
    free(lastnode->next);
    lastnode->next=NULL;
    count--;
    return num;
}
char* operation(char* a,char* b,char c){
    char *exp=(char*)malloc((strlen(a)+strlen(b)+3)*sizeof(char));
    strcpy(exp,a);
    switch(c){
        case '+':
            strcat(exp,"+");
            break;
        case '-':
            strcat(exp,"-");
            break;
        case '*':
            strcat(exp,"*");
            break;
        case '/':
            strcat(exp,"/");
            break;
        case '$':
            strcat(exp,"$");
            break;
    }
    strcat(exp,b);
    return exp;
}
int main(){
    char *data=(char*)malloc(sizeof(char)*100);
    int i=0;
    printf("Enter prefix expression: ");
    scanf("%s",data);
    int length=strlen(data);
    for(i=length-1;i>=0;i--){
        char *ptr=(data+i);
        if(*ptr=='+'||*ptr=='-'||*ptr=='*'||*ptr=='/'||*ptr=='$'){
            char* op1=pop();
            char*  op2=pop();
            push(operation(op2,op1,*ptr));
        }
        else{
            char *ch=(char*)malloc(sizeof(char));
            *ch=*(data+i);
            push(ch);
        }
    }
    char *result=pop();
    printf("The infix expression is : %s",result);
    return 0;
}