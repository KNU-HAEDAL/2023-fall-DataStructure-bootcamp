#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() //���� ���� ���� �Լ�
{
	return (top == -1);
}


int is_full() // ��ȭ ���� ���� �Լ�
{
	return (top == (MAX_STACK_SIZE - 1));
}

void push(element item) //�����Լ�
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

element pop() //�����Լ�
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
	}
	else return stack[top];
}


int p1_1()
{
	int a, b, c, d, e, f;

	printf("������ �Է��Ͻÿ� : ");
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	push(a);
	push(b);
	push(c);
	push(d);
	push(e);
	push(f);


	for (int i = 0; i < 6; i++) {
		printf("%d\n", pop());
	}
}




int main() {
	p1_1();


	return 0;

}
