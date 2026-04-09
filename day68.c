#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}


void topoSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

  
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

      
        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }


    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}


int main() {
    int V = 6;

   
    int adj[MAX][MAX] = {0};

    // Graph edges
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    printf("Topological Sort:\n");
    topoSort(V, adj);

    return 0;
}