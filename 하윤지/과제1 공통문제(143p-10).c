// 143p 10번 - 배열에 들어있는 정수의 순서를 거꾸로 하는 프로그램(스택)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item);
int pop();
int is_full();
int is_empty();

int main()
{
	int arrSize, n;

	printf("정수 배열의 크기: ");
	scanf("%d", &arrSize);

	printf("정수를 입력하시오: ");
	for (int i = 0; i < arrSize; i++)
	{
		scanf("%d", &n);
		push(n);
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", pop());
	}

	return 0;
}

void push(int item)
{
	if (is_full())
	{
		printf("stack is full\n");
		return;
	}
	stack[++top] = item;
}

int pop()
{
	if (is_empty())
	{
		printf("stack is empty\n");
		exit(1);
	}
	return stack[top--];
}

int is_full()
{
	if (top == MAX_STACK_SIZE - 1)
	{
		return 1;
	}
	return 0;
}

int is_empty()
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}
