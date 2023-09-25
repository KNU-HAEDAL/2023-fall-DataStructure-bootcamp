#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
} element;
int top = -1;
int capacity = 1;
int n = 1;

element* stack;

void init_stack()
{
	stack = (element*)malloc(sizeof(element) * capacity);
}


void push()
{
	if (top == capacity - 1)
	{
		capacity++;
		stack = (element*)realloc(stack, sizeof(element) * capacity);
		return push();
	}
	else
	{
		top++;
		stack[top].num = n;
		printf("%d ", stack[top].num);
		n++;
	}
}


void pop()
{
	if (top == -1)
	{
		exit(0);
	}
	else
	{
		printf("%d ", stack[top].num);
		top--;
	}
}


int main()
{
	char in[100];
	int i = 0;
	char c;

	init_stack();
	printf("¼ö½Ä: ");
	scanf("%s", in);

	printf("°ýÈ£ ¼ö: ");
	do
	{
		c = in[i];
		if (c == '(')
		{
			push();
		}
		else if (c == ')')
		{
			pop();
		}
		i++;
	} while (c != '\n');
}
