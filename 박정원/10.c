// �ش� ��Ʈķ�� �ڷᱸ�� <Week 1. Stack>
// p.143 10�� (���� ����)
// 2021115029 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 6

int stack[MAX_STACK_SIZE];
int top = -1;
void push(int item);
int pop();

int main() {
	int num[MAX_STACK_SIZE];

	printf("���� �迭�� ũ��: %d\n", MAX_STACK_SIZE);
	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		scanf("%d", &num[i]);
		push(num[i]);
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		printf("%d ", pop());
	}
}

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1) {
		printf("���� ��ȭ ����");
		exit(1);
	}
	stack[++top] = item;
}

int pop() {
	if (top == -1) {
		printf("���� ���� ����");
		exit(1);
	}
	return stack[top--];
}