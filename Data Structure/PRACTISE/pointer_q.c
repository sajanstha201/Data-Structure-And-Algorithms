#include<stdio.h>
typedef struct{int a,b;} student;
student *function(student *a){

    student *b=(student *)malloc(80);
    b->a=a->a;
    b->b=a->b;
    return(b);
}
void main(){
int *a[4],i,j;
for(i=0;i<4;i++){
    a[i]=malloc(4);
    for(j=i;j<4;j++){
        *(a[i]+j)=i;
    }
}
for(i=0;i<4;i++){
    for(j=i;j<4;j++){
        printf("%d\t",*(a[i]+j));
    }
    printf("\n");
}
}
