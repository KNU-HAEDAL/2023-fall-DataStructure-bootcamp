#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100	//스택코드 시작

//정수를 입력을 받아서 거꾸로 출력을 해야함

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType* s) {	
	s->top = -1;	//배열 첫 시작 인덱스 0부터 + 초기화는 -1이 되어야 함
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);	//비어있다? top 값 -1이어야 함
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));	//최대 저장 인덱스 값 == 최대 - 1
}

//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;	//다 차 있으면 에러
	}
	else {
		s->data[++(s->top)] = item;
	}
}

//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int main() {
	int size;	//입력받을 정수 배열의 크기
	int item;	//입력받을 정수 나타내는 변수
	StackType s;	//스택을 생성
	init_stack(&s);	//스택의 메모리를 초기화

	printf("정수 배열의 크기: ");
	scanf_s("%d", &size);
	printf("정수를 입력하시오: ");
	for (int i = 0; i < size; i++) {	//입력받은 정수를 순서대로 넣음
		scanf_s("%d", &item);
		push(&s, item);
	}
	printf("반전된 정수 배열: ");
	for (int i = 0; i < size; i++) {	//pop함수로 스택에 있는 자료 꺼내서 printf로 출력 + 삭제
		printf("%d ", pop(&s));
	}
}

