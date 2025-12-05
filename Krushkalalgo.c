#include <stdio.h>
#include <stdlib.h>

// Structure to store an edge
struct Edge {
    int src, dest, weight;
};

// Structure for subset (for Union-Find)
struct Subset {
    int parent;
    int rank;
};

// Find root of element (with path compression)
int find(struct Subset subsets[], int x) {
    if (subsets[x].parent != x)
        subsets[x].parent = find(subsets, subsets[x].parent);
    return subsets[x].parent;
}

// Union two subsets by rank
void unionSet(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Compare function for sorting edges by weight
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(struct Edge edges[], int V, int E) {
    // Sort edges by weight
    qsort(edges, E, sizeof(struct Edge), compare);

    struct Subset subsets[V];
    struct Edge result[V];  // To store MST edges
    int e = 0;  // index of result[]
    int i = 0;  // index of sorted edges

    // Initialize subsets
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Pick edges in increasing weight order
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];

        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            result[e++] = next;
            unionSet(subsets, x, y);
        }
    }

    // Print MST
    printf("Edges in Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d  (weight = %d)\n", result[i].src, result[i].dest, result[i].weight);
        totalWeight += result[i].weight;
    }

    printf("Total Weight of MST = %d\n", totalWeight);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}