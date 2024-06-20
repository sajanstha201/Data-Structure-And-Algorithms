#include<stdio.h>
int pow(int b,int p){
    int r=1;
    for(int i=0;i<p;i++)
        r=r*b;
    return r;
}
void main(){
    int n=4;
    int num=1;
    char s='s',a='a',d='d';
    while(1){
        if(num==pow(2,n))
            break;
        if(num%3==1)
            printf("%c , %c\n",s,d);
        if(num%3==2)
            printf("%c , %c\n",s,a);
        if(num%3==0)
            printf("%c , %c \n",d,a);
        num++;
    }
}