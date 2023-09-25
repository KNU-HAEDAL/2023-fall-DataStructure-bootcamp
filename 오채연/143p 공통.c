#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 6

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} Stacktype;

void init_stack(Stacktype* s) {
    s->top = -1;
}

int is_empty(Stacktype* s) {
    return (s->top == -1);
}

int is_full(Stacktype* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(Stacktype* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    s->data[++(s->top)] = item;
}

element pop(Stacktype* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(Stacktype* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    return s->data[s->top];
}

int main(void) {
    Stacktype s;
    init_stack(&s);
    int a[6], i;

    for (i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 6; i++) {
        push(&s, a[i]);
    }

 
    for (i = 0; i < 6; i++) {
        printf("%d ", pop(&s));
    }

    return 0;
}
