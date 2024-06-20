#include<stdio.h>
void main(int args,char *argv[]){
    int i;
    printf("The command line arguments are: ");
    for(i=1;i<args;i++){
        printf("%s  ",argv[i]);
    }
    int a=5;
    int*p=(int*)malloc(4);
    p=&a;
    free(p);
    printf("\n%d\n",*p);
 //   scanf("%d",p);
    printf("\n%d",a++);
}