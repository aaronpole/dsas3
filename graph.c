#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph{
    int vertices;
    Node** adjLists;
    int* visited;
} Graph;

typedef struct Queue{
    int items[MAX];
    int front; 
    int rear;
} Queue;


Node* createNode(int v){
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode -> next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
    Graph* graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph -> adjLists = malloc(vertices*sizeof(Node*));
    graph -> visited = malloc(vertices*sizeof(int));
    for (int i = 0; i < vertices; i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    // src to dest
    Node* newNode = createNode(dest);
    newNode-> next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode-> next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}



Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q){
    return q->rear == -1;
}

void enqueue(Queue*q, int value){
    if (q->rear==MAX-1){
        printf("Queue full\n");
    }
    else{
        if (q->front == -1){
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q){
    int item;
    if (!isEmpty(q)){
        item = q->items[q->front++];
        if (q->front > q->rear){
            q->front = q->rear = -1;
        }
        return item;
    }
}





void bfs(Graph* graph, int startVertex){
    Queue* q = createQueue();
    for (int i = 0; i < graph->vertices; i++){
        graph->visited[i] = 0;
    }
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    printf("BFS traversal: ");
    while (!isEmpty(q)){
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        Node* temp = graph->adjLists[currentVertex];
        while (temp){
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsHelper(Graph* graph, int vertex){
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjLists[vertex];
    while (temp){
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0){
            dfsHelper(graph, adjVertex);
        }
        temp = temp->next;
    }
}

void dfs(Graph* graph, int startVertex){
    for (int i = 0; i < graph->vertices; i++){
        graph->visited[i] = 0;
    }
    printf("DFS traversal: ");
    dfsHelper(graph, startVertex);
    printf("\n");
}

void printGraph(Graph* graph, int V){
    for (int v = 0; v < V; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter each edge as: src dest\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Display adjacency list
    printGraph(graph, V);

    bfs(graph, 0);
    printf("\n");
    dfs(graph, 0);
    printf("\n");
    return 0;
}
