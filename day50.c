#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


int search(struct Node* root, int val) {
    if (root == NULL) return 0;

    if (root->data == val) return 1;
    else if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

int main() {
    int n, val;
    scanf("%d", &n);

    int x;
    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &val);

    if (search(root, val))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}