#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//스택 초기 세팅

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) //스택 초기화
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

void push(StackType* s, element item) { //스택 push 구현
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

int main()
{
	StackType s1; //cnt 숫자를 담을 스택 생성
	init_stack(&s1);

	char ch[100], c; //입력 받을 문자열을 담을 ch, 문자열에서 하나씩 문자를 가져와서 담을 c 변수 선언
	int cnt = 0; //카운트 변수
	printf("%s", "수식: ");
	scanf("%s", ch); 
	printf("%s", "괄호 수: ");
	int n = strlen(ch); //for문을 위해 입력받은 문자열 크기 세기
	/*
	문자열에서 한글자씩 가져오면서 '([{' 일 경우 카운트 1올리고 출력 후 스택에 담기
	')]}' 일 경우 스택에서 pop으로 카운트 가져와서 출력하기
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