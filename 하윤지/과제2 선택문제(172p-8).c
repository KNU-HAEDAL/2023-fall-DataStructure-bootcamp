// 172p 8번 - 원형 큐의 요소의 개수 반환 getCount
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct
{
	int num;
}element;

element queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

void add(int num);
void delete();
void qprint();
int getCount();

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 9; i++)
	{
		add(arr[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		delete();
	}
	for (int i = 0; i < 3; i++)
	{
		add(arr[i]);
	}

	qprint();
	printf("%d\n", getCount());


	return 0;
}

void add(int num)
{
	//full
	if (front == (rear + 1) % MAX_QUEUE_SIZE)
	{
		printf("queue is full, not added\n");
	}
	//add
	else
	{
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		queue[rear].num = num;
	}
}

void delete()
{
	if (front == rear) //empty
	{
		printf("queue is empty\n");
		exit(1);
	}
	else
	{
		front = (front + 1) % MAX_QUEUE_SIZE;
	}
}

void qprint()
{
	if (front < rear)
	{
		for (int i = front + 1; i <= rear; i++)
		{
			printf("%d\n", queue[i].num);
		}
	}
	else
	{
		for (int i = front + 1; i < MAX_QUEUE_SIZE; i++)
		{
			printf("%d\n", queue[i].num);
		}
		for (int i = 0; i <= rear; i++)
		{
			printf("%d\n", queue[i].num);
		}
	}

	printf("\n");
}

int getCount()
{
	if (front <= rear)
	{
		return (rear - front);
	}
	else
	{
		return ((MAX_QUEUE_SIZE - 1) - front) + (rear + 1);
	}
}
