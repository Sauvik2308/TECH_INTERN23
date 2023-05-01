#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node *new_node(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(struct node **root, int key) {
    if (*root == NULL) {
        *root = new_node(key);
        return;
    }

    if (key < (*root)->key) {
        insert(&(*root)->left, key);
    } else if (key > (*root)->key) {
        insert(&(*root)->right, key);
    }
}

void traverse(struct node *root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d ", root->key);
        traverse(root->right);
    }
}

void tree_sort(int arr[], int n) {
    struct node *root = NULL;

	int i;
    for (i = 0; i < n; i++) {
        insert(&root, arr[i]);
    }

    traverse(root);
}

int main() {
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nSorted array:\n");
    tree_sort(arr, n);

    return 0;
}

