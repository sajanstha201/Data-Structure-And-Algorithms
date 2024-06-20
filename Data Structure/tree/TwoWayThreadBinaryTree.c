#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
    int rightThread;
    int leftThread;
} TREE;
TREE *root=NULL;
int level;
TREE* insert(int data, TREE* root){
    if(root==NULL){
        TREE* node=(TREE*)malloc(sizeof(TREE));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        node->rightThread=0;
        node->leftThread=0;
        root=node;
    }
    else if(data<root->data){
        if(root->leftThread||root->left==NULL){
            TREE *node=(TREE*)malloc(sizeof(TREE));
            node->data=data;
            node->left=root->left;
            node->right=root;
            if(node->left==NULL)
                node->leftThread=0;
            else
                node->leftThread=1;
            node->rightThread=1;
            root->leftThread=0;
            root->left=node;
        }
        else
            root->left=insert(data,root->left);
    }
    else if(data>root->data){
        if(root->rightThread||root->right==NULL){
            TREE* node=(TREE*)malloc(sizeof(TREE));
            node->data=data;
            node->right=root->right;
            node->left=root;
            if(node->right==NULL)
                node->rightThread=0;
            else
                node->rightThread=1;
            node->leftThread=1;
            root->rightThread=0;
            root->right=node;
        }
        else
            root->right=insert(data,root->right);
    }
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
void inorderTraversalLR(TREE *root){
    while(root->left!=NULL)
        root=root->left;
    while(1){        
        printf("%d ",root->data);
        if(root->rightThread){
            root=root->right;
        }
        else{
            root=root->right;
            while(root->leftThread!=1){
                root=root->left;
            }
        } 
       if(root->right==NULL)
            break;
    }
    printf("%d \n",root->data);
}
void inorderTraversalRL(TREE *root){
    while(root->right!=NULL)
        root=root->right;
    while(1){
        printf("%d ",root->data);
        if(root->leftThread)
            root=root->left;
        else{
            root=root->left;
            while(root->rightThread!=1){
                root=root->right;
            }
        }
        if(root->left==NULL)
            break;
    }
    printf("%d \n",root->data);
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
    root=insert(1,root);
    root=insert(7,root);
    inorderTraversalLR(root);
    inorderTraversalRL(root);
}