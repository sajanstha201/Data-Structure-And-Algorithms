#include<stdio.h>
void main(){
    int num;
    printf("Enter the total number of names: ");
    scanf("%d",&num);
    char *p[num];
    int i,j;
    for(i=0;i<num;i++){
        printf("Enter %d name: ",i+1);
        p[i]=(int*)malloc(100);
        scanf("%s",p[i]);
    }
    char *ptr;
    for(i=0;i<num;i++){
        for(j=i;j<num;j++){
            if(strcmp(*(p+i),*(p+j))>0){
                ptr=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=ptr;

            }
        }
    }
    for(i=0;i<num;i++){
        printf("%s\n",*(p+i));
    }
}