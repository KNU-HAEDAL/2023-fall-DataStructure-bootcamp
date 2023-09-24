#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//스택 초기 세팅

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType *s) //스택 초기화
{
	s->top = -1;
}

int is_empty(StackType* s) //스택 비었는지 확인
{
	return (s->top == -1);
}

int is_full(StackType* s) //스택 풀인지 확인
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) { //스택 push 구현
	if (is_full(s)) {
		fprintf(stderr, "스택 포화\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int pop(StackType* s) //스택 pop구현
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) //스택 peek 구현
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백\n");
		exit(1);
	}
	else {
		return s->data[(s->top)];
	}
}

int main(){
	StackType s1;
	init_stack(&s1); //스택 초기화

	int num;
	printf("%s ", "정수를 입력하시오:");
	for (int i = 0; i < 6; i++) { //숫자 6개 받아서 스택에 쌓기
		scanf("%d", &num);
		push(&s1, num);
	}
	printf("%s ", "반전된 정수 배열:");
	for (int i = 0; i < 6; i++) { //스택에서 하나씩 pop해서 출력
		printf("%d ", pop(&s1));
	}

}