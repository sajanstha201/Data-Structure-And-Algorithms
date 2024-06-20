#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}TREE;
TREE *root=NULL;
TREE *stack[100];
TREE *stack0[100];
int top=-1,top0=-1;
void push(TREE *s[],TREE *node){
    if(s==stack)
        s[++top]=node;
    else
        s[++top0]=node;
}
TREE* pop(TREE *s[]){
    if(s==stack)
        return s[top--];
    else
        return s[top0--];
}
void dispaly(TREE *s[]){
    int i;
    if(s==stack)
        for(i=0;i<=top;i++)
            printf("%d ",s[i]->data);
    else
        for(i=0;i<=top0;i++)
            printf("%d ",s[i]->data);     
}
void preorder(TREE *root){
    while(1){
        while(root!=NULL){
            push(stack,root);
            printf("%d ",root->data);
            root=root->left;
        }
        if(top==-1)
            break;
        TREE *node=pop(stack);
        root=node->right;

    }
        printf("\n");
}
void inorder(TREE* root){
    while(1){
        while(root!=NULL){
            push(stack,root);
            root=root->left;
        }
        if(top==-1)
            break;
        TREE *node=pop(stack);
        printf("%d ",node->data);
        root=node->right;

    }
    printf("\n");
}
void postorder(TREE *root){
    push(stack,root);
    while(1){
        TREE *node=pop(stack);
        push(stack0,node);
        if(node->left!=NULL)
            push(stack,node->left);
        if(node->right!=NULL)
            push(stack,node->right);
        if(top==-1)
            break;
    }
    int i;
    while(top0!=-1){
        printf("%d ",pop(stack0)->data);
    }
        printf("\n");
}
TREE* insert(TREE *root,int data){
    if(root==NULL){
        TREE *node=(TREE*)malloc(sizeof(TREE));
        node->left=NULL;
        node->right=NULL;
        node->data=data;
        return node;
    }
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}
int stack1[100];
int top1=-1;
TREE* stack2[100];
int top2=-1;
void push1(char c){
    stack1[++top1]=c;
}
void push2(TREE *node){
    stack2[++top2]=node;
}
int pop1(){
    return stack1[top1--];
}
TREE* pop2(){
    return stack2[top2--];
}
void postorder2(TREE *root){
    push2(root);
    TREE *node;
    while(1){
        if(top2==-1)
            break;
        node=pop2();
        push1(node->data);
        if(node->left!=NULL)
            push2(node->left);
        if(node->right!=NULL)
            push2(node->right);
    }
    while(top1!=-1){
        printf("%d ",pop1());
    }
}
int main(){
root=insert(root,20);
root=insert(root,10);
root=insert(root,30);
root=insert(root,25);
root=insert(root,15);
root=insert(root,35);
root=insert(root,5);
printf("Inorder: ");inorder(root);
printf("Preorder:");preorder(root);
printf("Post Order");postorder(root);
printf("MY next postfix: ");
postorder2(root);
printf("\nEnd");
}
