#include <stdio.h>

#define N 4 

int knows(int M[N][N], int a, int b) {
    return M[a][b];
}

int findCelebrity(int M[N][N], int n) {
    int a = 0;
    int b = n - 1;


    while (a < b) {
        if (knows(M, a, b))
            a++; 
        else
            b--; 
    }

    int candidate = a;

    
    for (int i = 0; i < n; i++) {
        if (i != candidate && (knows(M, candidate, i) || !knows(M, i, candidate)))
            return -1; 
    }

    return candidate;
}

int main() {
    
    int M[N][N] = { {0, 1, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 1, 1, 0} };

    int celeb = findCelebrity(M, N);

    if (celeb == -1)
        printf("No celebrity found.\n");
    else
        printf("Celebrity is person %d\n", celeb);

    return 0;
}