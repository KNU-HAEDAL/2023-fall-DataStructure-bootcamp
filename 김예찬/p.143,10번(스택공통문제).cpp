#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//���� �ʱ� ����

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType *s) //���� �ʱ�ȭ
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

void push(StackType *s, element item) { //���� push ����
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

int main(){
	StackType s1;
	init_stack(&s1); //���� �ʱ�ȭ

	int num;
	printf("%s ", "������ �Է��Ͻÿ�:");
	for (int i = 0; i < 6; i++) { //���� 6�� �޾Ƽ� ���ÿ� �ױ�
		scanf("%d", &num);
		push(&s1, num);
	}
	printf("%s ", "������ ���� �迭:");
	for (int i = 0; i < 6; i++) { //���ÿ��� �ϳ��� pop�ؼ� ���
		printf("%d ", pop(&s1));
	}

}