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
            node->right=trav;
            trav->left=node;
            if(node->left==NULL)
                node->leftthread=0;
            else
                node->leftthread=1;
            node->rightthread=1;
            trav->leftthread=0;
        }
        trav->left=insert(trav->left,value);
    }
    else if(value>trav->value){
        if(trav->rightthread==1||trav->right==NULL){
            node->right=trav->right;
            node->left=trav;
            trav->right=node;
            if(node->right==NULL)
                node->rightthread=0;
            else
                node->rightthread=1;
            node->leftthread=1;
            trav->rightthread=0;
        }
        trav->right=insert(trav->right,value);
    }
    return trav;
}
NODE* delete(NODE *root,int value){
    if(root==NULL)
        return root;
    else if(root->value==value){
        if((root->leftthread==1||root->left==NULL)&&(root->rightthread==1||root->right==NULL)){
            if(root->left!=NULL&&root->left->right==root){
                root->left->rightthread=1;
                return root->right;
            }
            if(root->right!=NULL&&root->right->left==root){
                root->right->leftthread=1;
                return root->left;
            }
        }
        else if(root->leftthread==1){
            NODE*trav=root->right;
            while(trav->leftthread!=1)
                trav=trav->left;
            trav->left=root->left;

            return trav;
        }
        else if(root->rightthread==1){
            NODE *trav=root->left;
            while(trav->rightthread!=1)
                trav=trav->right;
            trav->right=root->right;
            return trav;
        }
        else{
            NODE *trav=root->right;
            while(trav->leftthread!=1){
                trav=trav->left;
            }
            root->value=trav->value;
            root->right=delete(root->right,root->value);
        }
    }
   else if(value<root->value)
        root->left=delete(root->left,value);
    else if(value>root->value)
        root->right=delete(root->right,value);
    return root;
}
void inorder(NODE* root){
    NODE* trav=root;
    while(trav->left!=NULL){
       
        trav=trav->left;
    }
    while(trav->right!=NULL){
        printf("%d ",trav->value);
        if(trav->rightthread==1){
            trav=trav->right;
        }
        else{
            trav=trav->right;
            while(trav->leftthread!=1)
                trav=trav->left;
        }
    }
    printf("%d \n",trav->value);
}
int main(){
    NODE *root=createNode(20);

    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,10);
    root=insert(root,15);
    root=insert(root,5);
    root=insert(root,25);
    root=insert(root,35);
    root=insert(root,0);
    inorder(root);
    root=delete(root,35);
    printf("deleted\n");
    inorder(root);

}