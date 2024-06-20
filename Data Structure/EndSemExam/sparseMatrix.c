#include<stdio.h>
#include<stdlib.h>
int** sparse(int row,int col,int arr[row][col]){
    int i,j;
    int n=col;
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]!=0)
                count++;
        }
    }
    int **sp;
    sp=(int**)malloc(sizeof(int*)*3);
    int k=0;
    for(i=0;i<3;i++)
        *(sp+i)=(int*)malloc(sizeof(int)*count);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]!=0){
                *(*(sp)+k)=i;
                *(*(sp+1)+k)=j;
                *(*(sp+2)+k)=arr[i][j];
                k++;
            }
        }
    }
    return sp;
}
void main(){
    int arr[5][5]={{0,0,0,0,1},{0,2,0,0,0},{0,0,0,0,0},{0,0,0,0,5},{0,0,1,0,2}};
    int arr2[5][5]={{0,0,0,1,1},{0,2,0,2,0},{0,0,0,4,0},{0,6,0,0,5},{0,0,1,0,2}};
    int i,j;
    int n=5;
    int row=n,col=n;
    int **sp=sparse(row,col,arr);
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]!=0)
                count++;
        }
    }
    for(j=0;j<count;j++){
        printf("%d %d %d \n",*(*(sp)+j),*(*(sp+1)+j),*(*(sp+2)+j));
    }
    while(1){   
        if(*(*sp+col)==0)
        break;
        count++;
    }
}
