#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node *leftnode;
    struct node *rightnode;
} TREE;
TREE *root=NULL;
TREE *stacknode[100];
int topnode=-1;
void pushnode(TREE *node){
topnode++;
stacknode[topnode]=node;
}
TREE *popnode(){
    return(stacknode[topnode--]);
}
void displaytree(){
    int i;
    for(i=0;i<=topnode;i++)
        printf("%c ",stacknode[i]->data);
    printf("\n");
}
TREE* createleafNode(char c){
    TREE* node=(TREE*)malloc(sizeof(TREE));
    node->data=c;
    node->leftnode=NULL;
    node->rightnode=NULL;
    return node;
}
int precedence(char c){
    if(c=='*'||c=='/'||c=='%')
        return 10;
    else if(c=='+'||c=='-')
        return 9;
    return 0;
}

char stackoperator[100];
int topoperator=-1;
void pushoperator(char c){
    stackoperator[++topoperator]=c;
}
char popoperator(){
    return(stackoperator[topoperator--]);
}
void dispalyoperator(){
    int i;

}
void inorder(TREE *root){
    if(root==NULL)
        return;
    inorder(root->leftnode);
    printf("%c ",root->data);
    inorder(root->rightnode);
}
void preoder(TREE *root){
    if(root==NULL)
        return;
    printf("%c ",root->data);
    preoder(root->leftnode);
    preoder(root->rightnode);
}
void postoder(TREE *root){
    if(root==NULL)
        return;
    postoder(root->leftnode);
    postoder(root->rightnode);
    printf("%c ",root->data);
}
int main(){
printf("sajan\n");
char infix[100];
strcpy(infix,"a+b*z+d/e-g");
int i;
char c;
for(i=strlen(infix)-1;i>=0;i--){
    c=infix[i];
    if('a'<=c&&c<='z'||'A'<=c&&c<='Z'){
        pushnode(createleafNode(c));
    }
    else{
        while(precedence(c)<precedence(stackoperator[topoperator])){
            TREE *node=(TREE*)malloc(sizeof(TREE));
            node->data=popoperator();
            node->leftnode=popnode();
            node->rightnode=popnode();
            pushnode(node);
        }
        pushoperator(c);
    }
}
while(topoperator!=-1){
    TREE *node=(TREE*)malloc(sizeof(TREE));
    node->data=popoperator();
    node->leftnode=popnode();
    node->rightnode=popnode();
    pushnode(node);
}
root=popnode();
inorder(root);
printf("\n");
preoder(root);
printf("\n");
postoder(root);
printf("\nsajan\n");
return 0;
}