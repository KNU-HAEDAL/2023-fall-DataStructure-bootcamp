#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE] = { 10, 20, 30, 40, 50 };
int top = -1;

void qdelete()
{
	top++;
}

void qprint()
{
	for (int i = top + 1; i < MAX_QUEUE_SIZE; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}


int main()
{
	qdelete();
	qdelete();
	qdelete();

	qprint();
}