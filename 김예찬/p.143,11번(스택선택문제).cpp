#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� �ʱ� ����

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) //���� �ʱ�ȭ
{
	s->top = -1;
}

int is_empty(StackType* s) //���� ������� Ȯ��
{
	return (s->top == -1);
}

int is_full(StackType* s) //���� Ǯ���� Ȯ��
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) { //���� push ����
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int pop(StackType* s) //���� pop����
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ����\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) //���� peek ����
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ����\n");
		exit(1);
	}
	else {
		return s->data[(s->top)];
	}
}

int main()
{
	StackType s1; //cnt ���ڸ� ���� ���� ����
	init_stack(&s1);

	char ch[100], c; //�Է� ���� ���ڿ��� ���� ch, ���ڿ����� �ϳ��� ���ڸ� �����ͼ� ���� c ���� ����
	int cnt = 0; //ī��Ʈ ����
	printf("%s", "����: ");
	scanf("%s", ch); 
	printf("%s", "��ȣ ��: ");
	int n = strlen(ch); //for���� ���� �Է¹��� ���ڿ� ũ�� ����
	/*
	���ڿ����� �ѱ��ھ� �������鼭 '([{' �� ��� ī��Ʈ 1�ø��� ��� �� ���ÿ� ���
	')]}' �� ��� ���ÿ��� pop���� ī��Ʈ �����ͼ� ����ϱ�
	*/ 
	for (int i = 0; i < n; i++) {
		c = ch[i];
		if (c == '(' || c == '[' || c == '{')
		{
			cnt += 1;
			printf("%d ", cnt);
			push(&s1, cnt);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			printf("%d ",pop(&s1));
		}
	}
	
}