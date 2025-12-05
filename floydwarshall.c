#include <stdio.h>

#define INF 99999
#define N 4   
int main() {
    int A[N][N] = {
        {0,   3, INF, 5},
        {2,   0, INF, 4},
        {INF, 1, 0,   INF},
        {INF, INF, 2, 0}
    };

    int i, j, k;

    // Floyd–Warshall Algorithm
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
    printf("Shortest path matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
