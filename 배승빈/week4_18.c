#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)\
    if ((p = malloc(s)) == NULL) {\
        fprintf(stderr, "Insufficient memory");\
        exit(1);\
    }

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *newNode(int item) {
    TreeNode *temp;
    MALLOC(temp, sizeof(*temp));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insertNode(TreeNode *node, int key) {
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }

    return node;
}

void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {

    int arr[11] = {11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23};
    TreeNode* root = NULL;

    for (int i = 0; i < 11; i++) {
        root = insertNode(root, arr[i]);
    }

    inorder(root);

    return 0;
}

