#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];

int isSafe(int v, int graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(int graph[MAX][MAX], int V) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    color[0] = 0;

    for (int u = 1; u < V; u++) {
        for (int c = 0; c < V; c++) {
            if (isSafe(u, graph, color, c, V)) {
                color[u] = c;
                break;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        printf("Vertex %d ---> Color %d\n", i, color[i]);
    }
    return 0;
}

int main() {
    int V, E, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    graphColoring(graph, V);
    return 0;
}
