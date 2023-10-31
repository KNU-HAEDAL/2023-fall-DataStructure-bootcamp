#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 100

typedef struct TREE {
	struct TREE* left;
	int data;
	struct TREE* right;
} TREE;
TREE* root = NULL;
TREE* queue[MAX_QUEUE_SIZE];
TREE* tmp;
int front = -1; int rear = -1;
int sum = 0;


void enqueue(TREE** ptr)
{
	queue[++rear] = *ptr;
}


TREE* dequeue()
{
	return queue[++front];
}


void insert_tree(TREE** root, int data)
{
	TREE* p = (TREE*)malloc(sizeof(TREE));
	p->left = NULL;
	p->data = data;
	p->right = NULL;

	if (*root == NULL)
	{
		*root = p;
		enqueue(root);
		tmp = dequeue();
	}
	else
	{
		if (tmp->left == NULL)
		{
			tmp->left = p;
			enqueue(&(tmp->left));
		}
		else if (tmp->right == NULL)
		{
			tmp->right = p;
			enqueue(&(tmp->right));
		}

		if (tmp->right != NULL && tmp->left != NULL)
		{
			tmp = dequeue();
		}
	}
}


void inorder(TREE* root) // 중위 순회
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


void preorder(TREE* root) // 전위 순회
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void postorder(TREE* root) // 후위 순회
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
		sum += root->data;
	}
}


int main()
{
	int data;
	int check = 0;
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		data = rand() % 100 + 1;
		insert_tree(&root, data);
		check += data;
	}

	printf("inorder : ");
	inorder(root);
	printf("\npreorder : ");
	preorder(root);
	printf("\npostorder : ");
	postorder(root);

	printf("\n\n데이터의 합은 %d입니다\n", check);
	printf("노드의 합은 %d입니다\n", sum);

}
