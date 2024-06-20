#include<stdio.h>
void main(){
    int i;
    int count=0;
    for(i=2;count!=10;i++){
        i=i%3;
        count++;
        printf("%d ",i);
    }
}
