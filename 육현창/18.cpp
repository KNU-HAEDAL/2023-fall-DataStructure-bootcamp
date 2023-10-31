#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int arr[11] = {11,3,4,1,56,5,6,2,98,32,23};

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

void preorder(treenode* node){
    if(node != NULL){
        preorder(node->right);
        printf("%d ",node->key);
        preorder(node->left);
    }
}

void inorder(treenode* node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ",node->key);
        inorder(node->right);
    }
}

int main(){
    treenode* Node;
    for(int i=0;i<=10;i++){
        if(i==0) Node = new_node(arr[i]);
        else
            insert_node(Node,arr[i]);
    }
    inorder(Node);
    printf("\n");
    preorder(Node);
}
