#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *left,*right;
} BST;
BST *root=NULL;

BST* createNode(int data){
BST* node=(BST*)malloc(sizeof(BST));
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
}
BST* insert(BST *root,int data){
    if(root==NULL){
            return(createNode(data));
    }
    else{
        if(data<root->data)
            root->left=insert(root->left,data);
        else if(data>root->data)
            root->right=insert(root->right,data);
    }
    return root;
}
BST* inorderSuccessor(BST *root){
if(root->left==NULL)
    return root;
else
    return inorderSuccessor(root->left);
}
BST* delete(BST* root,int data){
    if(root==NULL){
        printf("Element is not availabe\n");
    }
    else{
        if(data<root->data)
            root->left=delete(root->left,data);
        else if(data>root->data)
            root->right=delete(root->right,data);
        else{
            if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL)
                return root->left;
            else{
                BST* successor=inorderSuccessor(root->right);
                root->data=successor->data;
                root->right=delete(root->right,successor->data);
            }
        }
    }
    return root;
}
void inorder(BST* root){
if(root==NULL)
    return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
int min(BST *root){
if(root->left==NULL)
    return root->data;
return min(root->left);
}
int max(BST *root){
if(root->right==NULL)
    return root->data;
return max(root->right);
}
void main(){
    printf("1.insert\n2.delete\n3.display\n4.min and max\n5.exit\n");
    int data,choice;
    while(1){
        printf("Enter a choice:");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        printf("Enter a number:");
        scanf("%d",&data);
        root=insert(root,data);
        break;
    case 2:
        printf("Enter a number:");
        scanf("%d",&data);
        root=delete(root,data);
        break;
    case 3:
        if(root==NULL)
            printf("No Element\n");
        else
            inorder(root);
            printf("\n");
        break;
    case 4:
        printf("Minimum value of binary tree is %d \n",min(root));
        printf("Maximum vlaue of binary tree is %d \n",max(root));
        break;
    case 5:
        return;
        }

    }
}