// 319p 14번 - 이진트리에서 노드가 가지고 있는 값의 합을 계산
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* TreePtr;
typedef struct Node
{
	int data;
	TreePtr leftChild;
	TreePtr rightChild;
} Node;

int sum = 0;
void inorder(TreePtr nodePtr);

int main()
{
	TreePtr root = NULL, pA, pB, pC, pD, pE;

	pA = malloc(sizeof(*pA));
	pA->data = 12;
	pB = malloc(sizeof(*pB));
	pB->data = 1;
	pC = malloc(sizeof(*pC));
	pC->data = 100;
	pD = malloc(sizeof(*pD));
	pD->data = 11;
	pE = malloc(sizeof(*pE));
	pE->data = 5;

	root = pA;
	pA->leftChild = pB;
	pA->rightChild = pC;
	pB->leftChild = pD;
	pB->rightChild = pE;
	pC->leftChild = pC->rightChild = NULL;
	pD->leftChild = pD->rightChild = NULL;
	pE->leftChild = pE->rightChild = NULL;

	inorder(root);
	printf("sum : %d", sum);

	return 0;
}

void inorder(TreePtr nodePtr)
{
	if (nodePtr != NULL)
	{
		inorder(nodePtr->leftChild);
		sum += nodePtr->data;
		printf("data : %d\n", nodePtr->data);
		inorder(nodePtr->rightChild);
	}
}
