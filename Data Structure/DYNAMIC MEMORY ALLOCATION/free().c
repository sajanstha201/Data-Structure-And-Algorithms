#include<stdio.h>
#include<stdlib.h>
void main()
{
    int a=8;
    int *p=(int*)calloc(4,4);
   printf("1..%d\n",p);
   printf("2..%d\n",&p);
    *p=a;
   printf("4..%d\n",p);
   printf("5..%d\n",*p);
    free(p);
    printf("6..%d\n",p);
      printf("7..%d\n",&p);
    printf("8..%d\n",*p);
    printf("9..%d\n",a);
}