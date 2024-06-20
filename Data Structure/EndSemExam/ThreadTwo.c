#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *left,*right;
    int leftthread,rightthread;
}NODE;
NODE* createNode(int value){
    NODE *node=(NODE*)malloc(sizeof(NODE));
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    node->leftthread=0;
    node->rightthread=0;
    return node;
}
NODE* insert(NODE *trav,int value){
    NODE* node=createNode(value);
    if(value<trav->value){
        if(trav->leftthread==1||trav->left==NULL){
            node->left=trav->left;
            trav->left=node;
            trav->leftthread=0;
            node->leftthread=1;
        }
        trav->left=insert(trav->left,value);
    }
    else if(value>trav->value){
        if(trav->rightthread==1||trav->right==NULL){
            node->right=trav->right;
            trav->rightthread=0;
            trav->right=node;
            node->rightthread=1;
        }
        trav->right=insert(trav->right,value);
    }
    return trav;
}
int main(){
    printf("sajan\n");
    NODE *root=createNode(20);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,10);
    root=insert(root,15);
    root=insert(root,25);
    root=insert(root,5);
    root=insert(root,35);
    printf("sajan\n");
}