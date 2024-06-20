#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
    int isThread;
} TREE;
TREE *root=NULL;
int level;
TREE* insert(int data, TREE* root){
    if(root==NULL){
        TREE *node=(TREE*)malloc(sizeof(TREE));
            node->data=data;
            node->right=NULL;
            node->left=NULL;
            node->isThread=0;
            root=node;
    }
    if(data<root->data){
        if(root->left==NULL){
            TREE *node=(TREE*)malloc(sizeof(TREE));
            node->right=root;
            node->isThread=1;
            node->left=NULL;
            node->data=data;
            root->left=node;
        }
        else
            root->left=insert(data,root->left);
    }
    else if(data>root->data){
        if(root->isThread){
            TREE *node=(TREE*)malloc(sizeof(TREE));
            node->right=root->right;
            node->isThread=1;
            node->left=NULL;
            node->data=data;
            root->right=node;
            root->isThread=0;
        }
        else
            root->right=insert(data,root->right);
    }
    return root;
}
TREE* searchMax(TREE *root){
    if(root->right==NULL)
        return root;
    else
       return searchMax(root->right);
}
TREE* delete(int data,TREE*root){
    if(root==NULL)
        return root;
    else if(root->data==data){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        else{
            TREE *max=searchMax(root->left);
            root->data=max->data;
            root->left=delete(root->data,root->left);
        }
    }
    else if(data<root->data)
        root->left=delete(data,root->left);
    else if(data>root->data)
        root->right=delete(data,root->right);
    return root;
}
TREE* search(int data,TREE *root){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
        return search(data,root->left);
    }
    else if(root->data<data)
        return search(data,root->right);
    else
        return root;
}
void inorderTraversal(TREE *root){
    while(root->left!=NULL)
        root=root->left;
    while(1){
        printf("%d ",root->data);
        if(root->isThread){
            root=root->right;
        }
        else{
            root=root->right;
            while(root->left!=NULL){
                root=root->left;
            }
        }
        if(root->right==NULL)
            break;
    }
}
int main(){
    root=insert(20,root);
    root=insert(10,root);
    root=insert(30,root);
    root=insert(5,root);
    root=insert(15,root);
    root=insert(25,root);
    root=insert(35,root);                    
    root=insert(23,root);
    root=insert(21,root);
    root=insert(27,root);
    root=insert(17,root);
    root=insert(0,root);
    root=insert(7,root);
    inorderTraversal(root);
}