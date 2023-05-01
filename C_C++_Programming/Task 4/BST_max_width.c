#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int maxWidth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int max_width = 1;
    struct Node** queue = (struct Node**) malloc(sizeof(struct Node*) * 10000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int i,size = rear - front;
        max_width = (size > max_width) ? size : max_width;
        for (i = 0; i < size; i++) {
            struct Node* current = queue[front++];
            if (current->left) {
                queue[rear++] = current->left;
            }
            if (current->right) {
                queue[rear++] = current->right;
            }
        }
    }
    free(queue);
    return max_width;
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    printf("Maximum width of the tree: %d\n", maxWidth(root));
    return 0;
}

