// 아직 미완성...
// 219p 20번 - 다항식을 연결 리스트를 이용하여 나타내고 합 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode* polyPointer;
typedef struct polyNode
{
	int coef; // 계수
	int expon; // 지수
	polyPointer link;
}polyNode;

polyPointer padd(polyPointer a, polyPointer b); // 다항식의 합을 구하는 함수
void attach(int coef, int expon, polyPointer* ptr); // 계수와 지수로 새 노드를 만들고 ptr가 가리키는 노드에 attach
void erase(polyPointer* ptr); 

int main()
{
	polyPointer a = NULL, b = NULL, c = NULL;
	
	attach(3, 6, &a);
	attach(7, 3, &a);
	attach(-2, 2, &a);
	attach(-9, 0, &a);

	attach(-2, 6, &b);
	attach(-4, 4, &b);
	attach(6, 2, &b);
	attach(6, 1, &b);
	attach(1, 0, &b);
	
	c = padd(a, b);
	
	while (c != NULL)
	{
		printf("(%d, %d) ", c->coef, c->expon);
		c = c->link;
	}

	erase(&a);
	erase(&b);
	erase(&c);

	return 0;
}

polyPointer padd(polyPointer a, polyPointer b)
{
	polyPointer c, rear, temp;
	int sum;
	rear = (polyPointer)malloc(sizeof(*rear));
	c = rear;

	while (a != NULL && b != NULL)
	{
		if (a->expon < b->expon)
		{
			attach(b->coef, b->expon, &rear);
			b = b->link;
		}
		else if (a->expon > b->expon)
		{
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
		else
		{
			sum = a->coef + b->coef;
			if (sum != 0)
			{
				attach(sum, a->expon, &rear);
			}
			a = a->link;
			b = b->link;
		}
	}

	for (; a; a = a->link)
	{
		attach(a->coef, a->expon, &rear);
	}
	for (; b; b = b->link)
	{
		attach(b->coef, b->expon, &rear);
	}
	rear->link = NULL;
	temp = c;
	c = c->link;
	free(temp);
	return c;
}

void attach(int coef, int expon, polyPointer* ptr)
{
	polyPointer temp;
	temp = (polyPointer)malloc(sizeof(*temp));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (*ptr == NULL) // 초기 빈 다항식인 경우, 첫 번째 노드로 설정
	{
		*ptr = temp;
	}
	else // 이미 노드가 있는 경우, 현재 노드의 link를 새로운 노드로 설정
	{
		(*ptr)->link = temp;
	}
	*ptr = temp;
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr != NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}
