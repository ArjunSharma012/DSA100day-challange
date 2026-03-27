#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct Queue {
    struct TreeNode* data[1000];
    int front, rear;
};


void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}


struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}


int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}


void rightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&q);

            // If last node of level
            if (i == size - 1) {
                printf("%d ", curr->val);
            }

            if (curr->left)
                enqueue(&q, curr->left);
            if (curr->right)
                enqueue(&q, curr->right);
        }
    }
}