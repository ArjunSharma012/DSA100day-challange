#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX] = {0};

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    for(int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        for(int j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}