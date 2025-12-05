#include <stdio.h>
#include <limits.h>
struct Edge {
    int src, dest, weight;
};
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int distance[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int V = 5; 
    int E = 8; 

    struct Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, V, E, 0);

    return 0;
}
