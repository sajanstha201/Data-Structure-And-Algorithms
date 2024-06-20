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
TREE* createleafNode(char c){
    TREE* node=(TREE*)malloc(sizeof(TREE));
    node->data=c;
    node->leftnode=NULL;
    node->rightnode=NULL;
    return node;
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
char prefix[100];
strcpy(prefix,"-++a*bz/deg");
int i;
char c;
for(i=strlen(prefix)-1;i>=0;i--){
    c=prefix[i];
    if('a'<=c&&c<='z'||'A'<=c&&c<='Z'){
        pushnode(createleafNode(c));
    }
    else{
        TREE *node=(TREE*)malloc(sizeof(TREE));
        node->data=c;
        node->leftnode=popnode();
        node->rightnode=popnode();
        pushnode(node);
    }
}
root=popnode();
inorder(root);
printf("\n");
preoder(root);
printf("\n");
postoder(root);
return 0;
}