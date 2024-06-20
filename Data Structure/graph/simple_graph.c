#include<stdio.h>
#include<stdlib.h>
typedef struct vertex{
    int num;
    struct vertex *next;
    int visited;
} VERTEX;
typedef struct graph{
    int numV;
    VERTEX **vertices;
}GRAPH;
GRAPH *graph;
void createGraph(int num){
    graph->numV=num;
    graph->vertices=(VERTEX**)malloc(graph->numV*sizeof(VERTEX));
    int i;
    for(i=0;i<graph->numV;i++){
        graph->vertices[i]=(VERTEX*)malloc(sizeof(VERTEX));
        graph->vertices[i]->num=i;
        graph->vertices[i]->next=NULL;
        graph->vertices[i]->visited=0;
    }
}
void insertVertex(int num){
    graph->numV++;
    graph->vertices=(VERTEX**)realloc(graph->vertices,graph->numV*sizeof(VERTEX));
    graph->vertices[graph->numV-1]=(VERTEX*)malloc(sizeof(VERTEX));
    graph->vertices[graph->numV-1]->num=num;
    graph->vertices[graph->numV-1]->next=NULL;
    graph->vertices[graph->numV-1]->visited=0;
}
VERTEX* searchVertex(int x){
    int i;
    for(i=0;i<graph->numV;i++){
        if(graph->vertices[i]->num==x){
            return graph->vertices[i];
        }
    }
    return NULL;
}
void insertEdge(int x,int y){
    VERTEX *v=searchVertex(x);
    VERTEX *w=searchVertex(y);
    VERTEX *vtemp=v;
    VERTEX *wtemp=w;
    while(vtemp->next!=NULL)
        vtemp=vtemp->next;
    while(wtemp->next!=NULL)
        wtemp=wtemp->next;
    vtemp->next=(VERTEX*)malloc(sizeof(VERTEX));
    vtemp->next->num=w->num;
    vtemp->next->next=NULL;
    wtemp->next=(VERTEX*)malloc(sizeof(VERTEX));
    wtemp->next->num=v->num;
    wtemp->next->next=NULL;
}
void deleteEdge(int x,int y){
    VERTEX *v=searchVertex(x);
    VERTEX *w=searchVertex(y);
    VERTEX *vtemp=v;
    VERTEX *wtemp=w;
    while(1){
        if(vtemp->next->num==w->num){
            vtemp=vtemp->next->next;
            break;
        }
        vtemp=vtemp->next;
    }
    while(1){
        if(wtemp->next->num==v->num){
            wtemp=wtemp->next->next;
            break;
        }
        wtemp=wtemp->next;
    }
}
void  adjacent(int vertexNo){
    int i,k=0;
    int *a;
    VERTEX *v;
    for(i=0;i<graph->numV;i++){
        if(graph->vertices[i]->num==vertexNo){
            v=graph->vertices[i];
            break;
        }
    }
    printf("%d :",vertexNo);
    v=v->next;
    while(v!=NULL){
        printf("%d ",v->num);
        v=v->next;
    }
}
void printAllAdj(){
    int i;
    int *a;
    for(i=0;i<graph->numV;i++){
        adjacent(graph->vertices[i]->num);
        printf("\n");
    }
}
void DFS(VERTEX *v){
    v->visited=1;
    printf("%d ",v->num);
    while(v!=NULL){
        if(searchVertex(v->num)->visited==0)
            DFS(searchVertex(v->num));
        v=v->next;
    }
    return;
}
VERTEX *queue[100];
int front=0,rear=-1;
void enqueue(VERTEX *v){
    rear++;
    queue[rear]=v;
}
VERTEX* dequeue(){
    front++;
    return queue[front-1];
}
void BFS(VERTEX *v){
    printf("%d ",v->num);
    v->visited=1;
    while(v!=NULL){
        if(searchVertex(v->num)->visited==0)
            enqueue(searchVertex(v->num));
        v=v->next;
    }
    if(front<rear){
        BFS(dequeue());
    }
    return;
}
int main(){
    graph=(GRAPH*)malloc(sizeof(GRAPH));
    int vertices=7;
    int num=7;
    createGraph(vertices);
    insertEdge(0,4);
    insertEdge(5,6);
    insertEdge(6,4);
    insertEdge(4,1);
    insertEdge(2,6);
    insertEdge(3,0);
    insertEdge(1,2);


    printAllAdj();
    //printf("DFS : ");
    //DFS(searchVertex(0));
    printf("\n");
    BFS(searchVertex(0));
    printf("\nsajan shre\n");

}