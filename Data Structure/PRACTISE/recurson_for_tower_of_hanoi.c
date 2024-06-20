#include<stdio.h>
void main(){
    tower(4,1,2,3);
}
void tower(int n,int s, int a,int d){
    if(n==1){
        printf("%d to %d \n",s,d);
        return;
    }
    tower(n-1,s,d,a);
    printf("%d to %d \n",s,d);
    tower(n-1,a,s,d);
}