#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void addEdge(int u, int v, int vertices) {
    if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
        printf(" Invalid edge: %d - %d (vertex out of range)\n", u, v);
        return;
    }
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf(" Queue overflow! Cannot add more elements.\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i])
            DFS(i, vertices);
    }
}

void BFS(int startVertex, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    enqueue(startVertex);
    visited[startVertex] = 1;

    while (front <= rear) {
        int current = dequeue();
        if (current == -1) break;
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices : ");
    scanf("%d", &vertices);
    if (vertices <= 0 || vertices > MAX) {
        printf(" Invalid number of vertices! Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    if (edges < 0) {
        printf(" Number of edges cannot be negative!\n");
        return 1;
    }

    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

    printf("\nNow, enter the edges ):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v, vertices);
    }

    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    printf("\n DFS Traversal (starting from vertex 0): ");
    DFS(0, vertices);

    front = rear = -1;
    printf("\n BFS Traversal (starting from vertex 0): ");
    BFS(0, vertices);

    printf("\n Traversal complete.\n");
    return 0;
}
