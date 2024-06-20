#include<stdio.h>
#include<stdlib.h>
void DFS(int i){
    j=0;
    int A[4][5];
    visited[i]=1;
    while(j<4){
        if(A[i,j]==1){
        if(visited[j]==0)
            DFS(j);
        }
    }
}
void DFS(int i){
    j=0;
    printf("%d ",i);
    visited[i]=1;
    int A[4][5];
    while(1){
        j=0;
        while(1){
            if(visited[j]==0&&A[i,j]==1)
                push(j);
            j++;
            if(j==4)
                break;
        }
        i=pop();
        visited[i]=1;
        if(top==-1)
            break;
    }
}
