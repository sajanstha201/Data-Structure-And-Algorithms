#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
} TREE;
TREE *root=NULL;
int level;
TREE* insert(int data, TREE* root){
    if(root==NULL){
        TREE *node=(TREE*)malloc(sizeof(TREE));
        node->data=data;
        node->left=NULL;
        node->right=NULL;
        root=node;
    }
    else if(data<root->data)
        root->left=insert(data,root->left);
    else if(data>root->data)
        root->right=insert(data,root->right);
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
void levelDisplay(int data,TREE *root){
    level++;
if(root->data==data){
    printf("The level is %d.\n",level);
    return;
}
else if(data<root->data){
    levelDisplay(data,root->left);
    level--;
    return;
}
else if(root->data<data){
    levelDisplay(data,root->right);
    level--;
    return;
}
}
TREE* search(int data,TREE *root){
    if(root==NULL){
        return root;
    }
    else if(data<root->data){
    printf("sajan\n");
        return search(data,root->left);
    }
    else if(root->data<data)
        return search(data,root->right);
    else
        return root;
    
}
void inorder(TREE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preoder(TREE *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preoder(root->left);
    preoder(root->right);
}
void postoder(TREE *root){
    if(root==NULL)
        return;
    postoder(root->left);
    postoder(root->right);
    printf("%d ",root->data);
}

void printlevel(TREE *root,int level){
    if(root==NULL){
        return;
    }
    if(level==0){
        printf("%d ",root->data);
        return;
    }
    printlevel(root->left,level-1);
    printlevel(root->right,level-1);
}
int findDepthTree(TREE* root){
    if(root==NULL){
        return -1;
    }
    int left_height=findDepthTree(root->left);
    int right_height=findDepthTree(root->right);
    if(left_height>=right_height)
        return (left_height+1);
    else
        return (right_height+1);
}
void leveltraversal(TREE *root){
    int i;
    int depth_of_tree=findDepthTree(root);
    for(i=1;i<=depth_of_tree+1;i++){
        printlevel(root,i);
        printf("\n");
    }
}
int findDiameter(TREE* root){
    return(findDepthTree(root->left)+findDepthTree(root->right)+2);
}
int findDepthNode(TREE *root,int data){
    if(root->data==data){
        return 0;
    }
    if(root->data>data)
        return (findDepthNode(root->left,data)+1);
    else
        return (findDepthNode(root->right,data)+1);
}
int main(){
    printf("\n\nsajan\n");
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
    inorder(root);
    printf("\nDepth is : %d\n",findDepthTree(root));
    leveltraversal(root);
    printf("Diameter: %d\n",findDiameter(root));
    int data=17;
    printf("Depth of %d is %d \n",data,findDepthNode(root,data));
    printf("Height of %d is %d \n",data,findDepthTree(root)-findDepthNode(root,data));
    printf("Level of %d is %d \n",data,findDepthNode(root,data)+1);
    /*
    printf("1.insertion\n2.deletion\n3.search\n4.display\n5.level Display\n6.exit\n");
    while(1){
    printf("Enter a choice: ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter a number: ");
            int data;
            scanf("%d",&data);
            root=insert(data,root);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d",&data);
            root=delete(data,root);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d",&data);
            if(search(data,root)==NULL)
                printf("Not Found\n");
            else
                printf("%p",search(data,root));
            break;
        case 4:
            printf("preorder: ");
            preoder(root);
            printf("\ninorder: ");
            inorder(root);
            printf("\npostorder: ");
            postoder(root);
            printf("\n");
            break;
        case 5:
            level=0;
            printf("Enter a number: ");
            scanf("%d",&data);
            levelDisplay(data,root);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice.\n");
    }
    }
    */
}