#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *left,*right;
} NODE;
NODE * createNode(int n){
    NODE* node=(NODE*)malloc(sizeof(NODE));
    node->value=n;
    node->left=NULL;
    node->right=NULL;
    return node;
}
NODE *insert(NODE* root,int n){
    if(root==NULL){
        NODE *node=createNode(n);
        return node;
    }
    if(n<root->value)
        root->left=insert(root->left,n);
    else
        root->right=insert(root->right,n);
    return root;
}
NODE *delete(NODE *root,int value){
    if(root->value==value){
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        else{
            NODE *trav;
            trav=root->right;
            while(trav->left!=NULL)
                trav=trav->left;
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
int height(NODE *root){
    if(root==NULL)
        return -1;
    int a=height(root->left);
    int b=height(root->right);
    if(a>b)
        return a+1;
    else
        return b+1;
}
void leveltraversal(NODE *root,int i){
    if(root==NULL)
        return;
    if(i==0)
        printf("%d ",root->value);
    leveltraversal(root->left,i-1);
    leveltraversal(root->right,i-1);
}
void inorder(NODE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->value);
    inorder(root->right);
}
void heightOfNode(NODE *root,int v){
    NODE *trav=root;
    while(trav->value!=v){
        if(v<trav->value)
            trav=trav->left;
        else
            trav=trav->right;
    }
    printf("\nHeight of %d is %d\n",v,height(trav));
}
int depthOfNode(NODE *root,int v){
    NODE *trav=root;
    int depth=0;
    while(trav->value!=v){
        depth++;
        if(v<trav->value)
            trav=trav->left;
        else
            trav=trav->right;
    }
    printf("\nDepth of %d is %d\n",v,depth);
    return depth;
}
NODE *stack1[100];
int top1=-1;
NODE *stack2[100];
int top2=-1;
void push1(NODE *node){
    stack1[++top1]=node;
}
NODE* pop1(){
    return stack1[top1--];
}
void push2(NODE *node){
    stack2[++top2]=node;
}
NODE* pop2(){
    return stack2[top2--];
}
void preorder_stack(NODE *root){
    top1=-1;
    NODE *trav=root;
    while(trav!=NULL){
        push1(trav);
        printf("%d ",trav->value);
        trav=trav->left;
    }
    while(top1!=-1){
        trav=pop1();
        if(trav->right!=NULL){
            trav=trav->right;
            while(1){
                push1(trav);
                printf("%d ",trav->value);
                trav=trav->left;
                if(trav==NULL)
                    break;
            }
        }
    }
}
void inorder_stack(NODE *root){
    top1=-1;
    while(1){
        while(root!=NULL){
            push1(root);
            root=root->left;
        }
        if(top1==-1)
            break;
        root=pop1();
        printf("%d ",root->value);
        root=root->right;
    }
}
void postorder_stack(NODE *root){
    top1=-1;
    top2=-1;
    push1(root);
    while(top1!=-1){
        NODE *node=pop1();
        push2(node);
        if(node->left!=NULL)
            push1(node->left);
        if(node->right!=NULL)
            push1(node->right);
    }
    int i;
    while(top2!=-1){
        printf("%d ",pop2()->value);
    }
    printf("\n");
}
void main(){
    NODE *root=createNode(20);
    root=insert(root,30);
    root=insert(root,10);
    root=insert(root,15);
    root=insert(root,5);
    root=insert(root,25);
    root=insert(root,35);
    root=insert(root,17);
    root=insert(root,12);
    printf("%d ",height(root));
    heightOfNode(root,15);
    depthOfNode(root,15);
    inorder(root);
    int i;
    printf("\nLevel Tranversal:\n");
    for(i=0;i<=height(root);i++){
        leveltraversal(root,i);
        printf("\n");
    }
    printf("\nPost Order: ");
    postorder_stack(root);
    printf("\nInorder: ");
    inorder_stack(root);

}