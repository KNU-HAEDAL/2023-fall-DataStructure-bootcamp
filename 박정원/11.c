// 해달 부트캠프 자료구조 <Week 2. Queue>
// p.172 11번 (선택 문제)
// 2021115029 박정원
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

	printf("문자열을 입력하시오: ");
	gets(input);

	//대->소문자 처리
	while (input[i]) {
		if (isupper(input[i]) == true) {
			input[i] = tolower(input[i]);
		}
		i++;
	}

	//큐에 문자열 입력
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] != ',' && input[i] != '.' && input[i] != ' ' && input[i] != NULL) {
			enqueue(&k, input[i]);
		}
	}

	//회문 판정
	while (k.front < k.rear - j) {
		if (k.data[k.rear - j] == dequeue(&k)) {
		}
		else {
			palindrome = false;
		}
		j++;
	}
	
	if (palindrome == true) {
		printf("입력한 문자열은 회문입니다.");
	}
	else {
		printf("입력한 문자열은 회문이 아닙니다.");
	}
}

void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
}

void enqueue(QueueType* q, char item) {
	if (q->rear == MAX_QUEUE_SIZE - 1) {
		printf("큐 포화 에러");
		exit(1);
	}
	q->data[++(q->rear)] = item;
}

char dequeue(QueueType* q) {
	if (q->rear == q->front) {
		printf("큐 공백 에러");
		exit(1);
	}
	return q->data[++(q->front)];
}