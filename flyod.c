#include <stdio.h>

#define INF 99999

void floydWarshall(int graph[][10], int V) {
    int dist[V][V];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, E, u, v, w;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    
    int graph[V][V];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j)
                graph[i][j] = INF;
            else
                graph[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    floydWarshall(graph, V);
    
    return 0;
}
