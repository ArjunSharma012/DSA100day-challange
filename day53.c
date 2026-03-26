#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QNode arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}


struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue q = {{{0}}, 0, 0};

    enqueue(&q, root, 0);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        struct Node* curr = dequeue(&q).node;


        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left, 0);
        }
        i++;


        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right, 0);
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Queue q = {{{0}}, 0, 0};

 
    int map[200][200]; 
    int count[200] = {0}; 

    int offset = 100; 

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QNode temp = dequeue(&q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            enqueue(&q, curr->left, hd - 1);
        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }

   
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}