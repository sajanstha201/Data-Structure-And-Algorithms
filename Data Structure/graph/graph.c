#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int vertex;
    struct node *next;
} NODE;
typedef struct graph{
    int vertices;
    NODE **list;
} GRAPH;
int visited[5]={0};
NODE* createNode(int v){
    NODE *node=(NODE*)malloc(sizeof(NODE));
    node->vertex=v;
    node->next=NULL;
    return node;
}
GRAPH* createGraph(int vertices){
    GRAPH *graph;
    graph=(GRAPH*)malloc(sizeof(GRAPH));
    graph->vertices=vertices;
    graph->list=(NODE**)malloc(sizeof(NODE)*graph->vertices);
    int i;
    for(i=0;i<graph->vertices;i++){
        *(graph->list+i)=NULL;
    }
    return graph;
}
GRAPH* insertEdge(GRAPH* graph,int v1,int v2){

    NODE *node=createNode(v2);
    node->next=*(graph->list+v1);
    *(graph->list+v1)=node;

    node=createNode(v1);
    node->next=*(graph->list+v2);
    *(graph->list+v2)=node;
return graph;
}
GRAPH* insertVertex(GRAPH* graph,int v){
    return graph;
}
GRAPH* deleteEdge(GRAPH* graph,int v1,int v2){
    return graph;
}
GRAPH* deleteVertex(GRAPH* graph,int v){
    return graph;
}
void adjacent(GRAPH *graph,int v){
    int *adj=(int*)malloc(0);
    NODE *trav=*(graph->list+v);
    int i=0;
    printf("vertex %d:",v);
    while(trav!=NULL){
        printf("%d ",trav->vertex);
        trav=trav->next;
    }
    printf("\n");
}
NODE *stack[100];
int top=-1;
void push(NODE *node){
    stack[++top]=node;
}
NODE* pop(){
    return stack[top--];
}

void DFS(GRAPH *graph,int v){
    visited[v]=1;
    NODE *node=graph->list[v];
    printf("%d ",v);
    while(node!=NULL){
        if(visited[node->vertex]==0)
            DFS(graph,node->vertex);
        node=node->next;
    }
}
void DFS_stack(GRAPH *graph,int v){
    NODE* trav=graph->list[v];
    printf("%d ",v);
    visited[v]=1;
    while(1){
        while(trav!=NULL){
            if(visited[trav->vertex]==0){
                printf("%d ",trav->vertex);
                push(trav);
                visited[trav->vertex]=1;
            }
            trav=trav->next;
        }
        if(top==-1)
            break;
        trav=graph->list[pop()->vertex];
    }
}
NODE *queue[100];
int front=0,rear=-1;
void enqueue(NODE *node){
    queue[++rear]=node;
}
NODE *dequeue(){
    return queue[front++];
}
void BFS(GRAPH *graph,int v){
    printf("%d ",v);
    visited[v]=1;
    NODE* trav=graph->list[v];
    while(1){
        while(trav!=NULL){
            if(visited[trav->vertex]==0){
                printf("%d ",trav->vertex);
                enqueue(trav);
                visited[trav->vertex]=1;
            }
            trav=trav->next;
        }
        if(front>rear)
            break;
        trav=graph->list[dequeue()->vertex];
    }
}
void resetVisited(){
    int i;
    for(i=0;i<5;i++)
        visited[i]=0;
}
int main(){
    GRAPH *graph=createGraph(5);
    graph=insertEdge(graph,0,3);
    graph=insertEdge(graph,1,3);
    graph=insertEdge(graph,4,3);
    graph=insertEdge(graph,0,2);
    graph=insertEdge(graph,2,3);
    int i,j;
    for(i=0;i<5;i++)
        adjacent(graph,i);
    
    printf("DFS: ");
    DFS(graph,1);

    resetVisited();
    printf("\nDFS: ");
    DFS_stack(graph,1);

    resetVisited();
    printf("\nBFS: ");
    BFS(graph,1);
    return 0;
}