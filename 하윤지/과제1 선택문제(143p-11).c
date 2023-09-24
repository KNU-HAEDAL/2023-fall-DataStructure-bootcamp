// 143p 11번 - 수식에 있는 괄호의 번호를 출력하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int num);
int pop();
int is_full();
int is_empty();

int main()
{
	char ch;
	int bracketNum[MAX_STACK_SIZE] = { 0 }, num = 0, cnt = 0;

	printf("수식: ");
	while ((ch = getchar()) != '\n')
	{
		if (ch == '(')
		{
			push(++num);
			bracketNum[cnt] = num;
		}
		else if (ch == ')')
		{
			bracketNum[cnt] = pop();
		}
		cnt++;
	}

	printf("괄호 수: ");
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", bracketNum[i]);
	}

	return 0;
}

void push(int num)
{
	if (is_full())
	{
		printf("stack is full\n");
		return;
	}
	stack[++top] = num;
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
