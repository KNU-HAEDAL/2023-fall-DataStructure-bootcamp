#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int sum = 0;

typedef struct treenode 
{
    int key;
    struct treenode *left,*right;
}treenode;

treenode* new_node(int data){
    treenode* temp = (treenode*)malloc(sizeof(treenode));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

treenode* insert_node(treenode* node,int key){
    if(node==NULL) return new_node(key);
    if(key>node->key){
        node->right = insert_node(node->right,key);
    }
    else if(key<node->key){
        node->left = insert_node(node->left,key);
    }
    return node;
}

void inorder(treenode* node){
    if(node != NULL){
        inorder(node->left);
        sum += node->key;
        inorder(node->right);
    }
}

int main(){
    treenode* Node = new_node(20);
    insert_node(Node,30);
    insert_node(Node,29);
    insert_node(Node,14);
    insert_node(Node,36);
    inorder(Node);
    printf("노드의 합은 %d입니다.",sum);
}
