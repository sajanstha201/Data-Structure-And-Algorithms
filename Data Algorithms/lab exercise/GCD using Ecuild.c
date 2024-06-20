#include<stdio.h>
#include<time.h>
int gcdEcuild(int a,int b){
    int r,opcount=0;
    if(a<b)
        gcdEcuild(b,a);
    while(b!=1){
        r=a%b;
        a=b;
        b=r;
        opcount++;
    }
    printf("The opcount for this Eculid GCD is %d\n",opcount);
    return a;
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