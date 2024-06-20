#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node LINK;
LINK *create(){
    return (LINK*)malloc(sizeof(LINK));
}
void main(){
    LINK *p=create();
}
