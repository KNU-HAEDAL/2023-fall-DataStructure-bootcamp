#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void initStack(StackType *s) {
    s->top = -1;
}

int isEmpty(StackType *s) {
    return (s->top == -1);
}

int isFull(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
    if (isFull(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1);
    } else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else {
        return s->data[(s->top)--];
    }
}

element peek(StackType *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } else {
        return s->data[(s->top)];
    }
}

int main() {

    StackType stack;
    initStack(&stack);

    printf("정수 배열의 크기: ");
    int n;
    scanf("%d", &n);

    printf("정수를 입력하세요: ");
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        push(&stack, input);
    }

    printf("반전된 정수 배열: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}