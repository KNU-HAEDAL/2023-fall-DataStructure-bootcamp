// น้มุ 10773น๘
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 1000000

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int num)
{
	stack[++top] = num;
}


void del_stack()
{
	top--;
}


int sum(int arr[])
{
	int sum = 0;
	for (int i = 0; i <= top; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	int k;
	int a;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &a);
		if (a == 0)
		{
			del_stack();
		}
		else
		{
			push(a);
		}
	}

	printf("%d", sum(stack));
}