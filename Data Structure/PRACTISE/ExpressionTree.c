#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char value;
    struct node *left,*right;
}NODE;
NODE *stack[100];
int top=-1;
NODE *stackop[100];
int topop=-1;
void push(NODE * node){
    stack[++top]=node;
}
NODE * pop(){
    return stack[top--];
}
void pushop(NODE *node){
    stackop[++topop]=node;
}
NODE *popop(){
    return stackop[topop--];
}
NODE * createNode(char c){
    NODE* node=(NODE*)malloc(sizeof(NODE));
    node->value=c;
    node->left=NULL;
    node->right=NULL;
    return node;
}
int precedence(char c){
    if(c=='/'||c=='*'||c=='%')
        return 10;
    if(c=='+'||c=='-')
        return 9;
    return 0;

}
NODE * expressionTreeinorder(char exp[]){
    top=-1;
    topop=-1;
    int i;
    NODE *node,*exp0,*exp1,*exp2;
    for(i=0;i<strlen(exp);i++){
        char *cp=(char*)malloc(sizeof(char));
        *cp=exp[i];
        node=createNode(*cp);
        if('a'<=*cp&&*cp<='z'||'A'<=*cp&&*cp<='Z'){
            push(node);
        }
        else{
            if(node->value=='(')
                pushop(node);
            else if(node->value==')'){
                while(1){
                    exp0=popop();
                    if(exp0->value=='('){
                        break;
                    }
                    exp1=pop();
                    exp2=pop();
                    exp0->left=exp2;
                    exp0->right=exp1;
                    push(exp0);
                }
            }
            else{
                while(topop!=-1&&precedence(node->value)<=precedence(stackop[topop]->value)){
                    exp1=pop();
                    exp2=pop();
                    exp0=popop();
                    exp0->left=exp2;
                    exp0->right=exp1;
                    push(exp0);
                }
                pushop(node);
            }
        }
    }
    while(topop!=-1){
        NODE *op1=pop();
        NODE *op2=pop();
        NODE *op=popop();
        op->left=op2;
        op->right=op1;
        push(op);
    }
    return pop();
}
void inorder(NODE *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%c ",root->value);
    inorder(root->right);

}
void inorderstack(NODE *root){
    top=-1;
    NODE *trav=root;
    while(1){
        while(trav!=NULL){
            push(trav);
            trav=trav->left;
        }
        if(top==-1)
            return;
        trav=pop();
        printf("%c ",trav->value);
        trav=trav->right;
    }
}
char* preorderstack(NODE *root){
    top=-1;
    NODE *trav=root;
    char *ch=(char*)malloc(sizeof(char));
    int k=0;
    while(1){
        while(trav!=NULL){
            push(trav);
            ch=(char*)realloc(ch,(k+1)*sizeof(char));
            *(ch+k)=trav->value;
            k++;
            trav=trav->left;
        }
        if(top==-1)
            break;
        trav=pop();
        trav=trav->right;
    }
    return ch;
}
NODE * expressionTreePreorder(char exp[]){
    int i;
    top=-1;
    topop=-1;
    for(i=strlen(exp)-1;i>=0;i--){
        NODE *node=createNode(exp[i]);
        if('a'<=node->value&&node->value<='z'||'A'<=node->value&&node->value<='Z'){
            push(node);
        }
        else{
            node->left=pop();
            node->right=pop();
            push(node);
        }
    }
    return pop();
    
}
int equalTree(NODE *root1,NODE *root2){
    if(root1==NULL&&root2==NULL)
        return 1;
    if(root1->value!=root2->value)
        return 0;
    if(root1==NULL&&root2!=NULL)
        return 0;
    if(root2==NULL&&root1!=NULL)
        return 0;
    return equalTree(root1->left,root2->left)&&equalTree(root1->right,root2->right);

}
int main(){
    char exp[]="a+b*(c+d)-g";
    NODE *root=expressionTreeinorder(exp);
    printf("%s \n",exp);
    inorder(root);
    printf("\n");
    inorderstack(root);
    printf("\nsajan\n");
    char *preoder=preorderstack(root);
    printf("%s ",preoder);
    char pr[100];
    strcpy(pr,preoder);
    printf("%s ",pr);
    NODE *rootpreoder=expressionTreePreorder(pr);
    printf("inorder:\n");
    inorderstack(rootpreoder);
    printf("saa\n");
    printf("The two tree is %d ",equalTree(root,rootpreoder));
    return 0;
}


