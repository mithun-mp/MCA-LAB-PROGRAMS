#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];  // Graph: adjacency matrix
int visited[MAX];         // Visited array
int queue[MAX];           // Queue for BFS
int front = -1, rear = -1;

// Add an edge to the graph
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // Undirected graph
}

// DFS traversal
void DFS(int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}

// BFS queue functions
void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS traversal
void BFS(int startVertex, int numVertices) {
    for (int i = 0; i < numVertices; i++) visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix to 0
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

    // Read edges from user
    printf("Enter edges (e.g., 0 1 means edge between vertex 0 and 1):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // DFS
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    printf("DFS traversal starting from vertex 0: ");
    DFS(0, vertices);
    printf("\n");

    // BFS
    front = rear = -1; // Reset queue
    printf("BFS traversal starting from vertex 0: ");
    BFS(0, vertices);
    printf("\n");

    return 0;
}
