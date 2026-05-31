#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int dest;
    int weight;
    struct node *link;

}node;

typedef struct graph{

    int vertices;
    node **arr;

}graph;

graph *createGraph(int v);
void addEdge(graph *g, int src, int dest, int weight);
void printGraph(graph *g);

int main(){

    int v, e;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    graph *g = createGraph(v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    int src, dest, wt;

    for(int i=0; i<e; i++){

        printf("Enter source destination weight: ");
        scanf("%d %d %d", &src, &dest, &wt);

        addEdge(g, src, dest, wt);
    }

    printGraph(g);

    return 0;
}

graph *createGraph(int v){

    graph *g = (graph *)calloc(1, sizeof(graph));

    g->vertices = v;

    g->arr = (node **)calloc(v, sizeof(node *));

    return g;
}

void addEdge(graph *g, int src, int dest, int weight){

    node *newNode = (node *)calloc(1, sizeof(node));

    newNode->dest = dest;
    newNode->weight = weight;

    newNode->link = g->arr[src];

    g->arr[src] = newNode;
}

void printGraph(graph *g){

    printf("\nAdjacency List:\n");

    for(int i=0; i<g->vertices; i++){

        printf("%d -> ", i);

        node *temp = g->arr[i];

        while(temp != NULL){

            printf("(%d,%d) -> ", temp->dest, temp->weight);

            temp = temp->link;
        }

        printf("NULL\n");
    }
}