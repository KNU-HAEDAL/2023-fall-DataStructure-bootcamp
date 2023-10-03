// �ش� ��Ʈķ�� �ڷᱸ�� <Week 2. Queue>
// p.172 11�� (���� ����)
// 2021115029 ������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;
QueueType k;

void init_queue(QueueType* q);
void enqueue(QueueType* q, char item);
char dequeue(QueueType* q);

int main() {
	init_queue(&k);
	char input[MAX_QUEUE_SIZE];
	bool palindrome = true;
	int i = 0;
	int j = 0;

	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(input);

	//��->�ҹ��� ó��
	while (input[i]) {
		if (isupper(input[i]) == true) {
			input[i] = tolower(input[i]);
		}
		i++;
	}

	//ť�� ���ڿ� �Է�
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] != ',' && input[i] != '.' && input[i] != ' ' && input[i] != NULL) {
			enqueue(&k, input[i]);
		}
	}

	//ȸ�� ����
	while (k.front < k.rear - j) {
		if (k.data[k.rear - j] == dequeue(&k)) {
		}
		else {
			palindrome = false;
		}
		j++;
	}
	
	if (palindrome == true) {
		printf("�Է��� ���ڿ��� ȸ���Դϴ�.");
	}
	else {
		printf("�Է��� ���ڿ��� ȸ���� �ƴմϴ�.");
	}
}

void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

void enqueue(QueueType* q, char item) {
	if (q->rear == MAX_QUEUE_SIZE - 1) {
		printf("ť ��ȭ ����");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

char dequeue(QueueType* q) {
	if (q->rear == q->front) {
		printf("ť ���� ����");
		exit(1);
	}
	return q->data[++(q->front)];
}