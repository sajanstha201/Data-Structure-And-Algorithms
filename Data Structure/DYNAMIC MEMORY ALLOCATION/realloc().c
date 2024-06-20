#include<stdio.h>
#include<stdlib.h>
void main(){
    int *p=(int*)malloc(10);
    int a=8;
    printf("1..%d\n",p);
    printf("2..%d\n",&p);
    printf("3..%d\n",*p);
    //*p=a;
    printf("1..%d\n",p);
    printf("2..%d\n",&p);
    printf("3..%d\n",*p);
    printf("%d\n",a);
    printf("%d\n",&a);
    int *ptr;
    ptr=realloc(p,8);
    printf("1..%d\n",p);
    printf("2..%d\n",&p);
    printf("3..%d\n",*p);
    printf("ptr\n1..%d\n",ptr);
    printf("2..%d\n",&ptr);
    printf("3..%d\n",*ptr);



}