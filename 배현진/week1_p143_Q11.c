#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}
//위에는 스택 함수

int main() {
	StackType s;	
	init_stack(&s);	
	char* data = malloc(sizeof(char) * 100);	//데이터 입력받을 문자열
	int num = 1;	//처음은 1로 시작

	printf("수식: ");
	scanf_s("%s", data, sizeof(char) * MAX_STACK_SIZE);
	printf("괄호 수: ");
	for (int i = 0; data[i] != NULL; i++) {
		// '('이면 num 값을 출력하고 num에 1을 더 함
		// 이러면 num 값은 1이 커진 상태로 저장되어 있음
		if (data[i] == '(') {
			push(&s, num);
			printf("%d ", num);
			num++;
		}
		// 사실상 ')' 인 경우는 매칭되는 왼쪽 괄호의 번호를 출력
		else {
			printf("%d ", pop(&s));
		}
	}
	/* 결론은 '(' 이 괄호는 나올때마다 1씩 더해서 번호가 붙혀진 채로
	* 스택의 밑에서부터 쌓인다는 느낌으로 생각하고 ')' 함수는 제일 마지막 '('과
	* 쌍으로 이루어지니까 그냥 스택에 마지막으로 쌓여있는 num 값을 꺼내서 매칭하고
	* 삭제한다고 생각하면 될 듯 하네요
	*/
}
