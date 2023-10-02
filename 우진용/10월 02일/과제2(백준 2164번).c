#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 1000000

int num[MAX_QUEUE_SIZE];
int N;
int front = -1;
int rear;
int value;

int main()
{
	scanf("%d", &N);
	rear = N;

	for (int i = 0; i < N; i++)
	{
		num[i] = i + 1;
	}

	while (1)
	{
		front++;
		if (rear - 1 == front)
		{
			printf("%d", num[front]);
			break;
		}
		value = num[++front];
		num[rear] = value;
		rear++;
	}

	
}