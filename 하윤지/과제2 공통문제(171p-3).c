#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void add(int num);
void delete();
void qprint();

int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };

	for (int i = 0; i < 5; i++)
	{
		add(arr[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		delete();
	}

	qprint();
	
	return 0;
}

void add(int num)
{
	if (rear == MAX_QUEUE_SIZE - 1) // full
	{
		printf("queue is full, not added\n");
	}
	else // add
	{
		queue[++rear] = num;
	}
}

void delete()
{
	if (front == rear) // empty
	{
		printf("queue is empty, cannot delete element.\n");
		exit(1);
	}
	else
	{
		front++;
	}
}

void qprint()
{
	for (int i = front + 1; i <= rear; i++)
	{
		printf("%d\n", queue[i]);
	}
}
