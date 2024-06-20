#include<stdio.h>
union un{
    int a;
    char b;
};
void main(){
    union un x;
    x.a=5;
    printf("%d\n",x.a);
    printf("%c\n",x.b);
    x.b=67;
    printf("%d\n",x.a);
    printf("%c\n",x.b);
}