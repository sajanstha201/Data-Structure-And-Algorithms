#include<stdio.h>
void tower(int n,char source,char aux,char destination){
    if(n==1){
        printf("%d %c %c \n",n,source,destination);
        return;
    }
    tower(n-1,source,destination,aux);
    printf("%d %c %c \n",n,source,destination);
    tower(n-1,aux,source,destination);
}
int power(int x,int y){
    if(y==0)
        return 1;
    return x*power(x,y-1);
}
int main(){
    tower(3,'s','a','d');
    printf("\n");
    int n=3;
    int i;
    for(i=1;i<=power(2,n)-1;i++){
    if(n%2==0){
        if(i%3==1)
            printf("s a\n");
        if(i%3==2)
            printf("s d\n");
        if(i%3==0)
            printf("d a\n");
    }
    else{
        if(i%3==1)
            printf("s d\n");
        if(i%3==2)
            printf("s a\n");
        if(i%3==0)
            printf("a d\n");
    }
    }
}