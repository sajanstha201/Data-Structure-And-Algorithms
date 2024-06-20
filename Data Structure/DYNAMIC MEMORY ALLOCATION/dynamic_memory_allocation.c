#include<stdio.h>
#include<stdlib.h>
void main(){
    int num,i;
    printf("Enter the value of num: ");
    scanf("%d",&num);
    int *p=(int*)malloc(num*sizeof(int));
    printf("\nFor malloc\n");
    printf("Enter %d numbers\n",num);
    for(i=0;i<num;i++){
        scanf("%d",p+i);
    }
    printf("address\t value\n");
    for(i=0;i<num;i++){
        printf("%d\t%d\n",p+i,*(p+i));
    }
    //calloc
    int *ptr=(int*)calloc(num,sizeof(int));
    printf("\nFor calloc\n");
        printf("Enter %d numbers\n",num);
    for(i=0;i<num;i++){
        scanf("%d",ptr+i);
    }
    printf("\naddress\t value\n");
    for(i=0;i<num;i++){
        printf("%d\t%d\n",ptr+i,*(ptr+i));
    }
    //realloc
        printf("\nFor realloc\n");
    printf("Enter the number of integer you want to add\n");
    int n,add;
    scanf("%d",&n);
    add=num+n;
    int *pt=realloc(ptr,add);
    printf("\nFor realloc\n");
    printf("Enter %d numbers\n",add);
        for(i=0;i<add;i++){
        scanf("%d",pt+i);
    }
    printf("\naddress\t value\n");
    for(i=0;i<add;i++){
        printf("%d\t%d\n",pt+i,*(pt+i));
    }
    //free
    free(pt);
    printf("After using free in realloc pointer\n");
    printf("\naddress\t value\n");
    for(i=0;i<add;i++){
        printf("%d\t%d\n",pt+i,*(pt+i));
    }
}