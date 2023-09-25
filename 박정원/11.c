// �ش� ��Ʈķ�� �ڷᱸ�� <Week 1. Stack>
// p.143 11�� (���� ����)
// 2021115029 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;
int num = 1;
void push(int item);
int pop();

int main() {
	char c[10] = "((())(()))";
	//char c[7] = "(((((()";

	printf("����: ((())(()))");
	//printf("����: (((((()");
	printf("\n��ȣ ��: ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		if (c[i] == '(') {
			printf("%d ", num);
			push(num++);
		}
		else if (c[i] == ')') {
			printf("%d ", pop());
		}
		else {
			continue;
		}
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