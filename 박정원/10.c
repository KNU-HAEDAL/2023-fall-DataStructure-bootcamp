// 해달 부트캠프 자료구조 <Week 1. Stack>
// p.143 10번 (공통 문제)
// 2021115029 박정원
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STACK_SIZE 6

int stack[MAX_STACK_SIZE];
int top = -1;
void push(int item);
int pop();

int main() {
	int num[MAX_STACK_SIZE];

	printf("정수 배열의 크기: %d\n", MAX_STACK_SIZE);
	printf("정수를 입력하시오: ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		scanf("%d", &num[i]);
		push(num[i]);
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < MAX_STACK_SIZE; i++) {
		printf("%d ", pop());
	}
}

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1) {
		printf("스택 포화 에러");
		exit(1);
	}
	stack[++top] = item;
}

int pop() {
	if (top == -1) {
		printf("스택 공백 에러");
		exit(1);
	}
	return stack[top--];
}