#include<stdio.h>
int reverse(int n,int rev){
    if(n==0)
        return rev;
    int r;
    r=n%10;
    n=n/10;
    rev=rev*10+r;
    return(reverse(n,rev));
}
void main(){
    printf("Enter a number of reversing\n");
    int num;
    scanf("%d",&num);
    printf("The reverse of %d number is %d\n",num,reverse(num,0));
}