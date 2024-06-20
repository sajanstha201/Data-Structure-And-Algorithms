#include<stdio.h>
#include<time.h>
int gcdEcuild(int a,int b){
    int r,opcount=0,i,gcd;
    if(a<b)
        gcdEcuild(b,a);
    for(i=b;i>=1;i--){
        opcount++;
        if(a%i==0&&b%i==0){
            gcd=i;
            break;
        }
    }
    printf("The opcount for this Eculid GCD is %d\n",opcount);
    return gcd;
}
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}
int main(){
    int a,b,gcd;
    double totaltime;
    printf("Enter the value of a: ");
    scanf("%d",&a);
    printf("Enter the value of b: ");
    scanf("%d",&b);
    time_t start,end;
    start=clock();
    gcd=gcdEcuild(a,b);
    end=clock();
    totaltime=(end-start)/CLOCKS_PER_SEC;
    printf("The time taken by this Eculid GCD is %e\n",totaltime);
    printf("The gcd of %d and %d is %d\n",a,b,gcd);
}