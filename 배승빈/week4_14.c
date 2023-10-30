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

int inorder(TreeNode *root) {
    if (root != NULL) {
        return root->key + inorder(root->left) + inorder(root->right);
    } else {
        return 0;
    }
}

int main() {

    TreeNode* root = NULL;

    for (int i = 1; i <= 10; i++) {
        root = insertNode(root, i);
    }

    int sum = inorder(root);
    printf("노드의 합은 %d입니다.\n", sum);


    return 0;
}

